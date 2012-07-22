/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/stm32/l1/rcc.h>
#include <libopencm3/stm32/l1/gpio.h>

#define PORT_LED GPIOB
#define PIN_LED GPIO6

void gpio_setup(void)
{
	/* Enable GPIOB clock. */
	/* Manually: */
	//RCC_AHBENR |= RCC_AHBENR_GPIOBEN;
	/* Using API functions: */
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_GPIOBEN);

	/* Set GPIO6 (in GPIO port B) to 'output push-pull'. */
	/* Using API functions: */
	gpio_mode_setup(PORT_LED, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_LED);
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
		gpio_toggle(PORT_LED, PIN_LED);	/* LED on/off */
		for (i = 0; i < 1000000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
