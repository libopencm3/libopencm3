/*
 * This file is part of the libopencm3 project.
 *
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

/** @file Common definitions used by all lightswitch implementations */

#include <libopencm3/efm32/tinygecko/gpio.h>
#include <libopencm3/efm32/tinygecko/cmu.h>

/** The User LED is connected to PD7 to the plus side of the LED according to
 * t0011_efm32_tiny_gecko_stk_user_manual.pdf figures 16.2 and 16.3 (called
 * UIF_LED0)
 */
#define LED_PORT GPIO_PD
#define LED_PIN GPIO7

#define BUTTON0_PORT GPIO_PD
#define BUTTON0_PORT_EXTIPSEL GPIO_EXTIPSEL_PORTD
#define BUTTON0_PIN_NUMBER 8
#define BUTTON0_PIN GPIO8
#define BUTTON1_PORT GPIO_PB
#define BUTTON1_PORT_EXTIPSEL GPIO_EXTIPSEL_PORTB
#define BUTTON1_PIN_NUMBER 11
#define BUTTON1_PIN GPIO11

void gpio_setup(void);
void led_on(void);
void led_off(void);

bool pb0_get(void);
bool pb1_get(void);

/**
 * Enable GPIO, and set up port D7 as an output pin and D8 and B11 as input.
 */

void gpio_setup(void)
{
	// Before GPIO works, according to d0034_efm32tg_reference_manual.pdf
	// note in section 28.3.7, we'll have to enable GPIO in CMU_HFPERCLKEN0
	
	CMU_HFPERCLKEN0 |= CMU_HFPERCLKEN0_GPIO;
	
	gpio_set_mode(LED_PORT, GPIO_MODE_PUSHPULL, LED_PIN);

	// Button PB0 is connected to pin PD8 and pulled low when pushed,
	// Botton PB1 to pin PB11 (sources as for LED). Pullups and debouncing
	// are alreay in place in hardware, so no filtering or pullup is
	// needed.

	gpio_set_mode(BUTTON0_PORT, GPIO_MODE_INPUT, BUTTON0_PIN);
	gpio_set_mode(BUTTON1_PORT, GPIO_MODE_INPUT, BUTTON1_PIN);
}

void led_on(void)
{
	gpio_set(LED_PORT, LED_PIN);
}

void led_off(void)
{
	gpio_clear(LED_PORT, LED_PIN);
}

bool pb0_get(void)
{
	return !gpio_get(GPIO_PD, GPIO8);
}

bool pb1_get(void)
{
	return !gpio_get(GPIO_PB, GPIO11);
}
