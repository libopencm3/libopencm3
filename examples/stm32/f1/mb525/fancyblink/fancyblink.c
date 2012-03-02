/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>,
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
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

void clock_setup(void)
{
	rcc_clock_setup_in_hse_8mhz_out_72mhz();

	/* Enable GPIOC clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);
}

void gpio_setup(void)
{
	/* Set GPIO6/7/8/9 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO6 | GPIO7 | GPIO8 | GPIO9);
}

int main(void)
{
	int i;

	clock_setup();
	gpio_setup();

	/* Blink the LEDs on the board. */
	gpio_set(GPIOC, GPIO6);
	while (1) {
		gpio_toggle(GPIOC, GPIO6);	/* LED on/off */
		gpio_toggle(GPIOC, GPIO7);	/* LED on/off */
		for (i = 0; i < 4000000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_toggle(GPIOC, GPIO7);	/* LED on/off */
		gpio_toggle(GPIOC, GPIO8);	/* LED on/off */
		for (i = 0; i < 4000000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_toggle(GPIOC, GPIO8);	/* LED on/off */
		gpio_toggle(GPIOC, GPIO9);	/* LED on/off */
		for (i = 0; i < 4000000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_toggle(GPIOC, GPIO8);	/* LED on/off */
		gpio_toggle(GPIOC, GPIO9);	/* LED on/off */
		for (i = 0; i < 4000000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_toggle(GPIOC, GPIO7);	/* LED on/off */
		gpio_toggle(GPIOC, GPIO8);	/* LED on/off */
		for (i = 0; i < 4000000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_toggle(GPIOC, GPIO6);	/* LED on/off */
		gpio_toggle(GPIOC, GPIO7);	/* LED on/off */
		for (i = 0; i < 4000000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
