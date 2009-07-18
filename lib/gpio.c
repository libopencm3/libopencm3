/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

/*
 * Basic GPIO handling API.
 *
 * Examples:
 *  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
 *                GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);
 *  gpio_set(GPIOB, GPIO4);
 *  gpio_clear(GPIOG, GPIO2 | GPIO9);
 *  gpio_toggle(GPIOA, GPIO7);
 *  reg16 = gpio_port_read(GPIOD);
 *  gpio_port_write(GPIOF, 0xc8fe);
 *
 * TODO:
 *  - GPIO remapping support
 */

#include "libopenstm32.h"

void gpio_set_mode(u32 gpioport, u8 mode, u8 cnf, u16 gpios)
{
	u16 i, movingbit = 1, offset = 0;
	u32 crl = 0, crh = 0;

	for (i = 0; i < 16; i++) {
		if ((movingbit & gpios) != movingbit) {
			movingbit <<= 1;
			continue;
		}
		offset = (i < 8) ? (i * 4) : ((i - 8) * 4);
		if (i < 8)
			crl |= (mode << offset) | (cnf << (offset + 2));
		else
			crh |= (mode << offset) | (cnf << (offset + 2));
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

/* TODO: Should work for multiple GPIOs? */
void gpio_toggle(u32 gpioport, u16 gpio)
{
	if ((gpio_port_read(gpioport) & gpio) == gpio)
		gpio_clear(gpioport, gpio);
	else
		gpio_set(gpioport, gpio);
}

u16 gpio_port_read(u32 gpioport)
{
	return (u16)GPIO_IDR(gpioport);
}

void gpio_port_write(u32 gpioport, u16 data)
{
	GPIO_ODR(gpioport) = data;
}
