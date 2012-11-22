/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

/**
 * \addtogroup Examples
 *
 * Flashes the Red, Green and Blue diodes on the board, in order.
 *
 * RED controlled by PF1
 * Green controlled by PF3
 * Blue controlled by PF2
 */

#include <libopencm3/lm4f/systemcontrol.h>
#include <libopencm3/lm4f/gpio.h>

void gpio_setup(void)
{
	SYSTEMCONTROL_RCGC2 |= 0x20; /* Enable GPIOF in run mode. */
	const u32 outpins = ((1<<3) | (1<<2) | (1<<1));

	GPIO_DIR(GPIOF) |= outpins; /* Configure outputs. */
	GPIO_DEN(GPIOF) |= outpins; /* Enable digital function on outputs. */
}

#define FLASH_DELAY 800000
int main(void)
{
	int i;

	gpio_setup();

	/* Blink STATUS LED (PF0) on the board. */
	while (1) {
		/*
		 * Flash the Red diode
		 */
		gpio_set(GPIOF, GPIO1);

		for (i = 0; i < FLASH_DELAY; i++)	/* Wait a bit. */
			__asm__("nop");

		gpio_clear(GPIOF, GPIO1);

		for (i = 0; i < FLASH_DELAY; i++)	/* Wait a bit. */
			__asm__("nop");

		/*
		 * Flash the Green diode
		 */
		gpio_set(GPIOF, GPIO3);

		for (i = 0; i < FLASH_DELAY; i++)	/* Wait a bit. */
			__asm__("nop");

		gpio_clear(GPIOF, GPIO3);

		for (i = 0; i < FLASH_DELAY; i++)	/* Wait a bit. */
			__asm__("nop");

		/*
		 * Flash the Blue diode
		 */
		gpio_set(GPIOF, GPIO2);

		for (i = 0; i < FLASH_DELAY; i++)	/* Wait a bit. */
			__asm__("nop");

		gpio_clear(GPIOF, GPIO2);

		for (i = 0; i < FLASH_DELAY; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
