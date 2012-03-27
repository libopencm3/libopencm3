/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopencm3/lpc17xx/gpio.h>

void gpio_setup(void)
{
	GPIO1_DIR |= (1 << 29); /* Configure P1_29 as output. */
}

int main(void)
{
	int i;

	gpio_setup();

	/* Blink LED0 (P3_0) on the board. */
	while (1) {
		/* Manually: */
		//GPIO1_SET = (1 << 29);		/* LED on */
		//for (i = 0; i < 800000; i++)	/* Wait a bit. */
		//	__asm__("nop");
		//GPIO1_CLR = (1 << 29);	/* LED off */
		//for (i = 0; i < 800000; i++)	/* Wait a bit. */
		//	__asm__("nop");
                
		gpio_set(GPIO1, GPIOPIN29); /* LED on */
		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_clear(GPIO1, GPIOPIN29); /* LED off */
		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
