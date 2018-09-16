/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/lm4f/gpio.h>
#include <libopencm3/lm4f/rcc.h>
#include <libopencm3/lm4f/systemcontrol.h>

#include <stdio.h>
#include "delay.h"
#include "usb-gadget0.h"

#define ER_DEBUG
#ifdef ER_DEBUG
#define ER_DPRINTF(fmt, ...) \
	do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define ER_DPRINTF(fmt, ...) \
	do { } while (0)
#endif


/* FIXME - implement delay functionality for better test coverage */
void delay_setup(void) {
}

void delay_us(uint16_t us) {
	(void)us;
}

int main(void)
{
	gpio_enable_ahb_aperture();
#define PLL_DIV_80MHZ           5
	rcc_sysclk_config(OSCSRC_MOSC, XTAL_16M, PLL_DIV_80MHZ);
	periph_clock_enable(RCC_GPIOD);
	gpio_mode_setup(GPIOD, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO4 | GPIO5);

	/* blue LED on board */
        periph_clock_enable(RCC_GPIOF);
	gpio_mode_setup(GPIOF, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO2);
	gpio_set_output_config(GPIOF, GPIO_OTYPE_PP, GPIO_DRIVE_2MA, GPIO2);

	usbd_device *usbd_dev = gadget0_init(&lm4f_usb_driver, "tilm4f120xl");

	ER_DPRINTF("bootup complete\n");
	while (1) {
		gpio_set(GPIOF, GPIO2);
		gadget0_run(usbd_dev);
		gpio_clear(GPIOF, GPIO2);
	}

}

