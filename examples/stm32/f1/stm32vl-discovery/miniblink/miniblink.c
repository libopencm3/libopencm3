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

#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/gpio.h>

void gpio_setup(void)
{
	/* Enable GPIOC clock. */
	/* Manually: */
	// RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;
	/* Using API functions: */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);

	/* Set GPIO8 (in GPIO port C) to 'output push-pull'. */
	/* Manually: */
	// GPIOC_CRH = (GPIO_CNF_OUTPUT_PUSHPULL << (((8 - 8) * 4) + 2));
	// GPIOC_CRH |= (GPIO_MODE_OUTPUT_2_MHZ << ((8 - 8) * 4));
	/* Using API functions: */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);
}

int main(void)
{
	int i;

	gpio_setup();

	/* Blink the LED (PC8) on the board. */
	while (1) {
		/* Manually: */
		// GPIOC_BSRR = GPIO8;		/* LED off */
		// for (i = 0; i < 800000; i++)	/* Wait a bit. */
		// 	__asm__("nop");
		// GPIOC_BRR = GPIO8;		/* LED on */
		// for (i = 0; i < 800000; i++)	/* Wait a bit. */
		// 	__asm__("nop");

		/* Using API functions gpio_set()/gpio_clear(): */
		// gpio_set(GPIOC, GPIO8);	/* LED off */
		// for (i = 0; i < 800000; i++)	/* Wait a bit. */
		// 	__asm__("nop");
		// gpio_clear(GPIOC, GPIO8);	/* LED on */
		// for (i = 0; i < 800000; i++)	/* Wait a bit. */
		// 	__asm__("nop");

		/* Using API function gpio_toggle(): */
		gpio_toggle(GPIOC, GPIO8);	/* LED on/off */
		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
