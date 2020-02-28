/**
 * @ingroup PAC55xx_gpio
 * @brief <b>PAC55xxxx General-Purpose Input/Output (GPIO)</b>
 * @author @htmlonly &copy; @endhtmlonly 2019 Brian Viele <vielster@allocor.tech>
 * @date December 1, 2019
 *
 * This library supports the GPIO module in the PAC55xx SoC from Qorvo.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <libopencm3/pac55xx/gpio.h>

static uint32_t get_ccs_port_base(uint32_t gpioport) {
	switch (gpioport) {
		case GPIOA:
			return CCS_PORTA;
		case GPIOB:
			return CCS_PORTB;
		case GPIOC:
			return CCS_PORTC;
		case GPIOD:
			return CCS_PORTD;
		case GPIOE:
			return CCS_PORTE;
		case GPIOF:
			return CCS_PORTF;
		case GPIOG:
			return CCS_PORTG;
		default:
			return 0U;
	}
}

void gpio_mode_setup(uint32_t gpioport, gpio_mode_t mode,
		     ccs_pull_updown_t pull_up_down, uint16_t gpios) {
	/* Read the current value of the register. */
	uint32_t reg = GPIO_MODER(gpioport);
	uint32_t port = get_ccs_port_base(gpioport);

	/* Loop through only set bits, utilize built-ins for optimized assembly. */
	int ffs = __builtin_ffs(gpios);
	while (ffs) {
		const int pin = ffs - 1;
		const int bit = (1 << pin);

		/* Update the cached mode value by clearing then setting values. */
		reg &= ~GPIO_MODER_MASK_PIN(pin);
		reg |= GPIO_MODER_MODE(pin, mode);

		/* Set the pinmux configurations for the pull-up / pull-down. */
		if (pull_up_down == CCS_IO_PULL_UP) {
			CCS_PDENR(port) &= ~bit;
			CCS_PUENR(port) |= bit;
		} else if (pull_up_down == CCS_IO_PULL_DOWN) {
			CCS_PUENR(port) &= ~bit;
			CCS_PDENR(port) |= bit;
		} else {
			CCS_PDENR(port) &= ~bit;
			CCS_PUENR(port) &= ~bit;
		}
		gpios ^= bit; /* Clear the bit we just serviced. */
		ffs = __builtin_ffs(gpios);
	}
	GPIO_MODER(gpioport) = reg;
}

void gpio_set_outmask(uint32_t gpioport, bool enable, uint16_t gpios) {
	uint32_t reg = GPIO_OUTMASKR(gpioport);
	if (enable) {
		reg |= gpios;
	} else {
		reg &= ~gpios;
	}
	GPIO_OUTMASKR(gpioport) = reg;
}

void gpio_set(uint32_t gpioport, uint16_t gpios) {
	GPIO_DOSETR(gpioport) = gpios;
}

void gpio_clear(uint32_t gpioport, uint16_t gpios) {
	GPIO_DOCLEARR(gpioport) = gpios;
}

uint16_t gpio_get(uint32_t gpioport, uint16_t gpios) {
	return GPIO_INR(gpioport) & gpios;
}

void gpio_set_af(uint32_t gpioport, ccs_muxsel_func_t muxsel, uint16_t gpios) {
	uint32_t port = get_ccs_port_base(gpioport);

	/* Update each of the pin configs. */
	uint32_t reg = CCS_MUXSELR(port);
	int ffs = __builtin_ffs(gpios);
	while (ffs) {
		const int pin = ffs - 1;

		reg &= ~CCS_MUXSELR_MASK_PIN(pin);
		reg |= CCS_MUXSELR_VAL(pin, muxsel);

		/* Set the pinmux configurations for the pull-up / pull-down. */
		gpios ^= (1 << pin); /* Clear the bit we just serviced. */
		ffs = __builtin_ffs(gpios);
	}
	CCS_MUXSELR(port) = reg;
}

void gpio_set_output_options(uint32_t gpioport, ccs_drive_strength_t strength,
			     uint16_t gpios) {
	uint32_t port = get_ccs_port_base(gpioport);

	/* Update each of the pin configs. */
	uint32_t reg = CCS_DSR(port);
	int ffs = __builtin_ffs(gpios);
	while (ffs) {
		const int pin = ffs - 1;

		reg &= ~CCS_DSR_MASK_PIN(pin);
		reg |= CCS_DSR_DS_VAL(pin, strength);

		/* Set the pinmux configurations for the pull-up / pull-down. */
		gpios ^= (1 << pin); /* Clear the bit we just serviced. */
		ffs = __builtin_ffs(gpios);
	}
	CCS_DSR(port) = reg;
}

void gpio_set_schmidt_trigger(uint32_t gpioport, bool enable, uint16_t gpios) {
	uint32_t port = get_ccs_port_base(gpioport);

	/* Update each of the pin configs. */
	uint32_t reg = CCS_DSR(port);
	int ffs = __builtin_ffs(gpios);
	while (ffs) {
		const int pin = ffs - 1;
		if (enable) {
			reg |= CCS_DSR_SCHMIDT_PIN(pin);
		} else {
			reg &= ~CCS_DSR_SCHMIDT_PIN(pin);
		}

		/* Set the pinmux configurations for the pull-up / pull-down. */
		gpios ^= (1 << pin); /* Clear the bit we just serviced. */
		ffs = __builtin_ffs(gpios);
	}
	CCS_DSR(port) = reg;
}
