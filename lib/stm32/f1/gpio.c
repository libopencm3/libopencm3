/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

/*
 * Basic GPIO handling API.
 *
 * Examples:
 *  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
 *                GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);
 *  gpio_set(GPIOB, GPIO4);
 *  gpio_clear(GPIOG, GPIO2 | GPIO9);
 *  gpio_get(GPIOC, GPIO1);
 *  gpio_toggle(GPIOA, GPIO7 | GPIO8);
 *  reg16 = gpio_port_read(GPIOD);
 *  gpio_port_write(GPIOF, 0xc8fe);
 *
 * TODO:
 *  - GPIO remapping support
 */

#include <libopencm3/stm32/f1/gpio.h>

void gpio_set_mode(u32 gpioport, u8 mode, u8 cnf, u16 gpios)
{
	u16 i, offset = 0;
	u32 crl = 0, crh = 0, tmp32 = 0;

	/*
	 * We want to set the config only for the pins mentioned in gpios,
	 * but keeping the others, so read out the actual config first.
	 */
	crl = GPIO_CRL(gpioport);
	crh = GPIO_CRH(gpioport);

	/* Iterate over all bits, use i as the bitnumber. */
	for (i = 0; i < 16; i++) {
		/* Only set the config if the bit is set in gpios. */
		if (!((1 << i) & gpios))
			continue;

		/* Calculate bit offset. */
		offset = (i < 8) ? (i * 4) : ((i - 8) * 4);

		/* Use tmp32 to either modify crl or crh. */
		tmp32 = (i < 8) ? crl : crh;

		/* Modify bits are needed. */
		tmp32 &= ~(0xf << offset);	/* Clear the bits first. */
		tmp32 |= (mode << offset) | (cnf << (offset + 2));

		/* Write tmp32 into crl or crh, leave the other unchanged. */
		crl = (i < 8) ? tmp32 : crl;
		crh = (i >= 8) ? tmp32 : crh;
	}

	GPIO_CRL(gpioport) = crl;
	GPIO_CRH(gpioport) = crh;
}

/**
 * Set one or more pins of the given GPIO port to 1.
 *
 * @param gpioport The GPIO port to use (GPIOA - GPIOG).
 * @param gpios The GPIO pin(s) to set to 1 (GPIO0 - GPIO15, or GPIO_ALL).
 *              If multiple pins shall be set, use '|' to separate them.
 */
void gpio_set(u32 gpioport, u16 gpios)
{
	GPIO_BSRR(gpioport) = gpios;
}

/**
 * Clear one or more pins of the given GPIO port to 0.
 *
 * @param gpioport The GPIO port to use (GPIOA - GPIOG).
 * @param gpios The GPIO pin(s) to set to 0 (GPIO0 - GPIO15, or GPIO_ALL).
 *              If multiple pins shall be cleared, use '|' to separate them.
 */
void gpio_clear(u32 gpioport, u16 gpios)
{
	GPIO_BRR(gpioport) = gpios;
}

u16 gpio_get(u32 gpioport, u16 gpios)
{
	return gpio_port_read(gpioport) & gpios;
}

/**
 * Toggle one or more pins of the given GPIO port.
 *
 * @param gpioport The GPIO port to use (GPIOA - GPIOG).
 * @param gpios The GPIO pin(s) to toggle (GPIO0 - GPIO15, or GPIO_ALL).
 *              If multiple pins shall be toggled, use '|' to separate them.
 */
void gpio_toggle(u32 gpioport, u16 gpios)
{
	GPIO_ODR(gpioport) ^= gpios;
}

/**
 * Read the current value of the given GPIO port.
 *
 * @param gpioport The GPIO port to read (GPIOA - GPIOG).
 * @return The value of the current GPIO port.
 */
u16 gpio_port_read(u32 gpioport)
{
	return (u16)GPIO_IDR(gpioport);
}

/**
 * Write to the given GPIO port.
 *
 * @param gpioport The GPIO port to write to (GPIOA - GPIOG).
 * @param data The data to write to the specified GPIO port.
 */
void gpio_port_write(u32 gpioport, u16 data)
{
	GPIO_ODR(gpioport) = data;
}

void gpio_port_config_lock(u32 gpioport, u16 gpios)
{
	u32 reg32;

	/* Special "Lock Key Writing Sequence", see datasheet. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	GPIO_LCKR(gpioport) = ~GPIO_LCKK & gpios;	/* Clear LCKK. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK again. */

	/* Tell the compiler the variable is actually used. It will get optimized out anyways. */
	reg32 = reg32; 

	/* If (reg32 & GPIO_LCKK) is true, the lock is now active. */
}
