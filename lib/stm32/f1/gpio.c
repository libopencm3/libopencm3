/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
		tmp32 &= ~(0b1111 << offset); /* Clear the bits first. */
		tmp32 |= (mode << offset) | (cnf << (offset + 2));

		/* Write tmp32 into crl or crh, leave the other unchanged. */
		crl = (i < 8) ? tmp32 : crl;
		crh = (i >= 8) ? tmp32 : crh;
	}

	GPIO_CRL(gpioport) = crl;
	GPIO_CRH(gpioport) = crh;
}

void gpio_set(u32 gpioport, u16 gpios)
{
	GPIO_BSRR(gpioport) = gpios;
}

void gpio_clear(u32 gpioport, u16 gpios)
{
	GPIO_BRR(gpioport) = gpios;
}

u16 gpio_get(u32 gpioport, u16 gpios)
{
	return gpio_port_read(gpioport) & gpios;
}

void gpio_toggle(u32 gpioport, u16 gpios)
{
	GPIO_ODR(gpioport) ^= gpios;
}

u16 gpio_port_read(u32 gpioport)
{
	return (u16)GPIO_IDR(gpioport);
}

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
	
	/* If (reg32 & GPIO_LCKK) is true, the lock is now active. */
}
