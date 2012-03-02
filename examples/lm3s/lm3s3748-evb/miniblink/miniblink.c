/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <libopencm3/lm3s/systemcontrol.h>
#include <libopencm3/lm3s/gpio.h>

void gpio_setup(void)
{
	SYSTEMCONTROL_RCGC2 |= 0x20; /* Enable GPIOF in run mode. */

	GPIO_DIR(GPIOF) |= (1 << 0); /* Configure PF0 as output. */
	GPIO_DEN(GPIOF) |= (1 << 0); /* Enable digital function on PF0. */
}

int main(void)
{
	int i;

	gpio_setup();

	/* Blink STATUS LED (PF0) on the board. */
	while (1) {
		gpio_set(GPIOF, GPIO0);

		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("nop");

		gpio_clear(GPIOF, GPIO0);

		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
