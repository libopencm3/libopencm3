/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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

#include <libopencm3/efm32/tinygecko/gpio.h>
#include <libopencm3/efm32/tinygecko/cmu.h>

void gpio_setup(void);
void led_on(void);
void led_off(void);
bool pb0_get(void);
bool pb1_get(void);

/** @file
 * Example for switching the User LED of the EFM32-TG-STK330 eval board on and
 * off using the buttons.
 */

int main(void)
{
	gpio_setup();

	while(1) {
		if (pb0_get()) led_on();
		if (pb1_get()) led_off();
	};
}

/**
 * Enable GPIO, and set up port D7 as an output pin.
 */

void gpio_setup(void)
{
	// Before GPIO works, according to d0034_efm32tg_reference_manual.pdf
	// note in section 28.3.7, we'll have to enable GPIO in CMU_HFPERCLKEN0
	
	CMU_HFPERCLKEN0 |= CMU_HFPERCLKEN0_GPIO;

	// The User LED is connected to PD7 to the plus side of the LED
	// according to t0011_efm32_tiny_gecko_stk_user_manual.pdf figures 16.2
	// and 16.3 (called UIF_LED0)
	
	gpio_set_mode(GPIO_PD, GPIO_MODE_PUSHPULL, GPIO7);

	// Button PB0 is connected to pin PD8 and pulled low when pushed,
	// Botton PB1 to pin PB11 (sources as for LED). Pullups and debouncing
	// are alreay in place in hardware, so no filtering or pullup is
	// needed.

	gpio_set_mode(GPIO_PD, GPIO_MODE_INPUT, GPIO8);
	gpio_set_mode(GPIO_PB, GPIO_MODE_INPUT, GPIO11);
}

void led_on(void)
{
	gpio_set(GPIO_PD, GPIO7);
}

void led_off(void)
{
	gpio_clear(GPIO_PD, GPIO7);
}

bool pb0_get(void)
{
	return !gpio_get(GPIO_PD, GPIO8);
}

bool pb1_get(void)
{
	return !gpio_get(GPIO_PB, GPIO11);
}
