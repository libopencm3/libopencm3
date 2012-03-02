/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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
	/* Set STM32 to 72 MHz. */
	rcc_clock_setup_in_hse_8mhz_out_72mhz();

	/* Enable GPIOA clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);

	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
}

void gpio_setup(void)
{
	/* Set GPIO6 and 7 (in GPIO port A) to 'output push-pull'. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO6 | GPIO7);

	/* Set GPIO0 and 1 (in GPIO port B) to 'output push-pull'. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO0 | GPIO1);
}

int main(void)
{
	int i;

	clock_setup();
	gpio_setup();

	/* Blink the LEDs on the board. */
	while (1) {
		gpio_toggle(GPIOA, GPIO6);	/* LED on/off */
		for (i = 0; i < 8000000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_toggle(GPIOA, GPIO7);	/* LED on/off */
		for (i = 0; i < 8000000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_toggle(GPIOB, GPIO0);	/* LED on/off */
		for (i = 0; i < 8000000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_toggle(GPIOB, GPIO1);	/* LED on/off */
		for (i = 0; i < 8000000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
