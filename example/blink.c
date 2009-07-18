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

#include <libopenstm32.h>

int main(void)
{
	int i;

	/* GPIO setup: Enable GPIOC clock, set GPIO12 to 'output push-pull'. */
	RCC_APB2ENR = RCC_IOPCEN;
	GPIOC_CRH = (GPIO_CNF_OUTPUT_PUSHPULL << (((12 - 8) * 4) + 2));
	GPIOC_CRH |= (GPIO_MODE_OUTPUT_2_MHZ << ((12 - 8) * 4));

	/* Blink the LED (PC12) on the board. */
	while (1) {
		GPIOC_BSRR = GPIO12;		/* LED off */
		for (i = 0; i < 80000; i++);	/* Wait (needs -O0 CFLAGS). */
		GPIOC_BRR = GPIO12;		/* LED on */
		for (i = 0; i < 80000; i++);	/* Wait (needs -O0 CFLAGS). */
	}

	return 0;
}

u32 *vector_table[2] __attribute__ ((section(".vectors"))) = {
	(u32 *)0x20000800,	/* Use 2 KB stack (0x800 bytes). */
	(u32 *)main,		/* Use main() as reset vector for now. */
};

