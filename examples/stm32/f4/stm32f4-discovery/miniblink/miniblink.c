/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
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

#include <libopencm3/stm32/f4/rcc.h>
#include <libopencm3/stm32/f4/gpio.h>

void gpio_setup(void)
{
	/* Enable GPIOD clock. */
	/* Manually: */
	// RCC_AHB1ENR |= RCC_AHB1ENR_IOPDEN;
	/* Using API functions: */
	rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPDEN);

	/* Set GPIO12 (in GPIO port D) to 'output push-pull'. */
	/* Manually: */
	// GPIOD_CRH = (GPIO_CNF_OUTPUT_PUSHPULL << (((8 - 8) * 4) + 2));
	// GPIOD_CRH |= (GPIO_MODE_OUTPUT_2_MHZ << ((8 - 8) * 4));
	/* Using API functions: */
	gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12);
}

int main(void)
{
	int i;

	gpio_setup();

	/* Blink the LED (PC8) on the board. */
	while (1) {
		/* Manually: */
		// GPIOD_BSRR = GPIO12;		/* LED off */
		// for (i = 0; i < 1000000; i++)	/* Wait a bit. */
		// 	__asm__("nop");
		// GPIOD_BRR = GPIO12;		/* LED on */
		// for (i = 0; i < 1000000; i++)	/* Wait a bit. */
		// 	__asm__("nop");

		/* Using API functions gpio_set()/gpio_clear(): */
		// gpio_set(GPIOD, GPIO12);	/* LED off */
		// for (i = 0; i < 1000000; i++)	/* Wait a bit. */
		// 	__asm__("nop");
		// gpio_clear(GPIOD, GPIO12);	/* LED on */
		// for (i = 0; i < 1000000; i++)	/* Wait a bit. */
		// 	__asm__("nop");

		/* Using API function gpio_toggle(): */
		gpio_toggle(GPIOD, GPIO12);	/* LED on/off */
		for (i = 0; i < 1000000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
