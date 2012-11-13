/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Piotr Esden-Tempski <piotr@esden.net>
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
	/* Set STM32 to 64 MHz. */
	rcc_clock_setup_in_hsi_out_64mhz();

	/* Enable alternate function peripheral clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_AFIOEN);

	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
}

void gpio_setup(void)
{

	/* Configure PB4 as GPIO. */
	AFIO_MAPR |= AFIO_MAPR_SWJ_CFG_FULL_SWJ_NO_JNTRST;
	
	/* Set GPIO4 and 5 (in GPIO port B) to 'output push-pull'. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO4 | GPIO5);
	
}

int main(void)
{
	int i;

	clock_setup();
	gpio_setup();

	/* Blink the LEDs on the board. */
	while (1) {
		gpio_toggle(GPIOB, GPIO4);	/* LED on/off */
		for (i = 0; i < 8000000; i++)	/* Wait a bit. */
			__asm__("nop");
		gpio_toggle(GPIOB, GPIO5);	/* LED on/off */
		for (i = 0; i < 8000000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
