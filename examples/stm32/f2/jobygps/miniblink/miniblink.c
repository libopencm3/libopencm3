/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#include <libopencm3/stm32/f2/rcc.h>
#include <libopencm3/stm32/f2/gpio.h>

void gpio_setup(void)
{
	/* Enable GPIOC clock. */
	rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPCEN);

	/* Set GPIO3 and GPIO4 (in GPIO port C) to 'output push-pull'. */
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO3 | GPIO4);
}

int main(void)
{
	int i;

	gpio_setup();

	gpio_set(GPIOC, GPIO3);
	gpio_clear(GPIOC, GPIO4);

	/* Blink the LEDs (PC3, PC4) on the board. */
	while (1) {
		/* Using API function gpio_toggle(): */
		gpio_toggle(GPIOC, GPIO3);
		gpio_toggle(GPIOC, GPIO4);
		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
