/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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

/* "generic" could be any L1 board, but this file is pre-configured for the
 * libopencm3-tests "hw1" board, with an stm32l151c8-A part.
 */

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/syscfg.h>

#include <stdio.h>
#include "usb-gadget0.h"

#define ER_DEBUG
#ifdef ER_DEBUG
#define ER_DPRINTF(fmt, ...) \
	do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define ER_DPRINTF(fmt, ...) \
	do { } while (0)
#endif

int main(void)
{
	rcc_periph_clock_enable(RCC_GPIOE);
	gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO11|GPIO12);
	gpio_set(GPIOE, GPIO12);
	rcc_clock_setup_pll(&rcc_hse8mhz_configs[RCC_CLOCK_HSE8_72MHZ]);

	rcc_periph_clock_enable(RCC_GPIOA);
	/*
	 * Vile hack to reenumerate, physically _drag_ d+ low.
	 * do NOT do this if you're board has proper usb pull up control!
	 * (need at least 2.5us to trigger usb disconnect)
	 */
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12);
	gpio_clear(GPIOA, GPIO12);
	for (unsigned int i = 0; i < 800000; i++) {
		__asm__("nop");
	}
	/* now return PA11/PA12 to usb AF */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO11|GPIO12);
	gpio_set_af(GPIOA, GPIO_AF14, GPIO11|GPIO12);

	usbd_device *usbd_dev = gadget0_init(&st_usbfs_v1_usb_driver,
					     "stm32f3-disco");

	ER_DPRINTF("bootup complete\n");
	gpio_clear(GPIOE, GPIO12);
	static int i = 0;
	while (1) {
		gadget0_run(usbd_dev);
	}

}

