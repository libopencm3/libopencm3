/*
 * This file is part of the libopenstm32 project.
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

#include <libopenstm32.h>

int main(void)
{
	int i;

	/* Enable GPIOC clock. */
	rcc_enable_peripheral_clock(&RCC_APB2ENR, IOPCEN);

	/* Set GPIO12 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);

	/* Blink the LED (PC12) on the board. */
	while (1) {
		gpio_toggle(GPIOC, GPIO12);	/* LED on/off */
		for (i = 0; i < 80000; i++);	/* Wait (needs -O0 CFLAGS). */
	}

	return 0;
}

u32 *vector_table[2] __attribute__ ((section(".vectors"))) = {
	(u32 *)0x20000800,	/* Use 2 KB stack (0x800 bytes). */
	(u32 *)main,		/* Use main() as reset vector for now. */
};
