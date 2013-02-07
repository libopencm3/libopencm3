/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Damjan Marion <damjan.marion@gmail.com>
 * Copyright (C) 2011 Mark Panajotovic <marko@electrontube.org>
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

#include <libopencm3/stm32/f3/rcc.h>
#include <libopencm3/stm32/gpio.h>

/* Set STM32 to 64 MHz. */
void clock_setup(void)
{
	rcc_clock_setup_hsi(&hsi_8mhz[CLOCK_64MHZ]);

	/* Enable GPIOE clock. */
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_IOPEEN);
}

void gpio_setup(void)
{
	/* Set GPIO8-11 (in GPIO port E) to 'output push-pull'. */
	gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT,
			GPIO_PUPD_NONE, GPIO8 | GPIO9 | GPIO10 | GPIO11);
}

int main(void)
{
	int i;

	clock_setup();
	gpio_setup();

	/* Set two LEDs for wigwag effect when toggling. */
	gpio_set(GPIOE, GPIO8 | GPIO10);

	/* Blink the LEDs (PD8, PD9, PD10 and PD11) on the board. */
	while (1) {
		/* Toggle LEDs. */
		gpio_toggle(GPIOE, GPIO8 | GPIO9 | GPIO10 | GPIO11);
		for (i = 0; i < 1000000; i++) /* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
