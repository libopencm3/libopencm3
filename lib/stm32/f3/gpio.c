/** @defgroup gpio_file GPIO
 *
 * @ingroup STM32F3xx
 *
 * @brief <b>libopencm3 STM32F3xx General Purpose I/O</b>
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Modified by 2013 Fernando Cortes <fernando.corcam@gmail.com> (stm32f3)
 * Modified by 2013 Guillermo Rivera <memogrg@gmail.com> (stm32f3)
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

#include <libopencm3/stm32/gpio.h>

void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
		     uint16_t gpios)
{
	uint16_t i;
	uint32_t moder, pupd;

	/*
	 * We want to set the config only for the pins mentioned in gpios,
	 * but keeping the others, so read out the actual config first.
	 */
	moder = GPIO_MODER(gpioport);
	pupd = GPIO_PUPDR(gpioport);

	for (i = 0; i < 16; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}

		moder &= ~GPIO_MODE_MASK(i);
		moder |= GPIO_MODE(i, mode);
		pupd &= ~GPIO_PUPD_MASK(i);
		pupd |= GPIO_PUPD(i, pull_up_down);
	}

	/* Set mode and pull up/down control registers. */
	GPIO_MODER(gpioport) = moder;
	GPIO_PUPDR(gpioport) = pupd;
}

void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
			     uint16_t gpios)
{
	uint16_t i;
	uint32_t ospeedr;

	if (otype == 0x1) {
		GPIO_OTYPER(gpioport) |= gpios;
	} else {
		GPIO_OTYPER(gpioport) &= ~gpios;
	}

	ospeedr = GPIO_OSPEEDR(gpioport);

	for (i = 0; i < 16; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}
		ospeedr &= ~GPIO_OSPEED_MASK(i);
		ospeedr |= GPIO_OSPEED(i, speed);
	}

	GPIO_OSPEEDR(gpioport) = ospeedr;
}

void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios)
{
	uint16_t i;
	uint32_t afrl, afrh;

	afrl = GPIO_AFRL(gpioport);
	afrh = GPIO_AFRH(gpioport);

	for (i = 0; i < 8; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}
		afrl &= ~GPIO_AFR_MASK(i);
		afrl |= GPIO_AFR(i, alt_func_num);
	}

	for (i = 8; i < 16; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}
		afrl &= ~GPIO_AFR_MASK(i - 8);
		afrh |= GPIO_AFR(i - 8, alt_func_num);
	}

	GPIO_AFRL(gpioport) = afrl;
	GPIO_AFRH(gpioport) = afrh;
}

void gpio_set(uint32_t gpioport, uint16_t gpios)
{
	GPIO_BSRR(gpioport) = gpios;
}

void gpio_clear(uint32_t gpioport, uint16_t gpios)
{
	GPIO_BSRR(gpioport) = gpios << 16;
}

uint16_t gpio_get(uint32_t gpioport, uint16_t gpios)
{
	return gpio_port_read(gpioport) & gpios;
}

void gpio_toggle(uint32_t gpioport, uint16_t gpios)
{
	GPIO_ODR(gpioport) ^= gpios;
}

uint16_t gpio_port_read(uint32_t gpioport)
{
	return (uint16_t)GPIO_IDR(gpioport);
}

void gpio_port_write(uint32_t gpioport, uint16_t data)
{
	GPIO_ODR(gpioport) = data;
}

void gpio_port_config_lock(uint32_t gpioport, uint16_t gpios)
{
	uint32_t reg32;

	/* Special "Lock Key Writing Sequence", see datasheet. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	GPIO_LCKR(gpioport) = ~GPIO_LCKK & gpios;	/* Clear LCKK. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK again. */

	/*
	 * Tell the compiler the variable is actually used.
	 * It will get optimized out anyways.
	 */
	reg32 = reg32;

	/* If (reg32 & GPIO_LCKK) is true, the lock is now active. */
}
