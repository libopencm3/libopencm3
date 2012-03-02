/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/efm32/tinygecko/gpio.h>
#include <libopencm3/efm32/tinygecko/cmu.h>

void led_setup(void);
void led_toggle(void);

/** @file
 * Minimal example for making the User LED of the EFM32-TG-STK330 eval board blink.
 */

/**
 * Toggle the User LED in an infinite loop, with time between the toggling
 * determined by a busy loop stupidly counting up.
 */

int main(void)
{
	int x;

	led_setup();

	while(1) {
		for(x = 0; x < 200000; ++x) asm("mov r0,r0"); /* no-op, prevent compiler from optimizing this away */
		led_toggle();
	};
}

/**
 * Enable GPIO, and set up port D7 as an output pin.
 */

void led_setup(void)
{
	// Before GPIO works, according to d0034_efm32tg_reference_manual.pdf
	// note in section 28.3.7, we'll have to enable GPIO in CMU_HFPERCLKEN0
	
	CMU_HFPERCLKEN0 |= CMU_HFPERCLKEN0_GPIO;

	// The User LED is connected to PD7 to the plus side of the LED
	// according to t0011_efm32_tiny_gecko_stk_user_manual.pdf figures 16.2
	// and 16.3 (called UIF_LED0)
	
	gpio_set_mode(GPIO_PD, GPIO_MODE_PUSHPULL, GPIO7);
	// GPIO_PD_MODEL = GPIO_MODE_PUSHPULL<<(7*4);
}

void led_toggle(void)
{
	gpio_toggle(GPIO_PD, GPIO7);
	// GPIO_PD_DOUTTGL = 1<<7;
}
