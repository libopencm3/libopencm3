/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
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

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/* Set STM32 to 72 MHz. */
void clock_setup(void)
{
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
		for (i = 0; i < 800000; i++);	/* Wait (needs -O0 CFLAGS). */
		gpio_toggle(GPIOA, GPIO7);	/* LED on/off */
		for (i = 0; i < 800000; i++);	/* Wait (needs -O0 CFLAGS). */
		gpio_toggle(GPIOB, GPIO0);	/* LED on/off */
		for (i = 0; i < 800000; i++);	/* Wait (needs -O0 CFLAGS). */
		gpio_toggle(GPIOB, GPIO1);	/* LED on/off */
		for (i = 0; i < 800000; i++);	/* Wait (needs -O0 CFLAGS). */
	}

	return 0;
}
