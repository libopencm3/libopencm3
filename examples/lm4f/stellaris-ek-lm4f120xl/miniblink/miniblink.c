/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2012-2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

/**
 * \addtogroup Examples
 *
 * Flashes the Red, Green and Blue diodes on the board, in order.
 *
 * RED controlled by PF1
 * Green controlled by PF3
 * Blue controlled by PF2
 */
#include <libopencm3/lm4f/systemcontrol.h>
#include <libopencm3/lm4f/gpio.h>

/* This is how the RGB LED is connected on the stellaris launchpad */
#define RGB_PORT	GPIOF
enum {
	LED_R	= GPIO1,
	LED_G	= GPIO3,
	LED_B	= GPIO2,
};

/*
 * GPIO setup:
 * Enable the pins driving the RGB LED as outputs.
 */
static void gpio_setup(void)
{
	/*
	 * Configure GPIOF
	 * This port is used to control the RGB LED
	 */
	periph_clock_enable(RCC_GPIOF);
	const u32 outpins = (LED_R | LED_G | LED_B);

	GPIO_DIR(RGB_PORT) |= outpins; /* Configure outputs. */
	GPIO_DEN(RGB_PORT) |= outpins; /* Enable digital function on outputs. */
}

#define FLASH_DELAY 800000
static void delay(void)
{
	int i;
	for (i = 0; i < FLASH_DELAY; i++)       /* Wait a bit. */
		__asm__("nop");
}

int main(void)
{
	int i;

	gpio_setup();

	/* Blink each color of the RGB LED in order. */
	while (1) {
		/*
		 * Flash the Red diode
		 */
		gpio_set(RGB_PORT, LED_R);
		delay(); /* Wait a bit. */
		gpio_clear(RGB_PORT, LED_R);
		delay(); /* Wait a bit. */

		/*
		 * Flash the Green diode
		 */
		gpio_set(RGB_PORT, LED_G);
		delay(); /* Wait a bit. */
		gpio_clear(RGB_PORT, LED_G);
		delay(); /* Wait a bit. */

		/*
		 * Flash the Blue diode
		 */
		gpio_set(RGB_PORT, LED_B);
		delay(); /* Wait a bit. */
		gpio_clear(RGB_PORT, LED_B);
		delay(); /* Wait a bit. */
	}

	return 0;
}
