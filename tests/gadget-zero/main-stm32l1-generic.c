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

const struct rcc_clock_scale this_clock_config = {
		/* 32MHz PLL from 16MHz HSE, 96MHz for USB on PLL VCO out */
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.pll_mul = RCC_CFGR_PLLMUL_MUL6,
		.pll_div = RCC_CFGR_PLLDIV_DIV3,
		.hpre = RCC_CFGR_HPRE_SYSCLK_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_HCLK_NODIV,
		.ppre2 = RCC_CFGR_PPRE2_HCLK_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 1,
		.ahb_frequency = 32000000,
		.apb1_frequency = 32000000,
		.apb2_frequency = 32000000,
	};


int main(void)
{
	rcc_periph_clock_enable(RCC_GPIOB);
	gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO8|GPIO9);
	gpio_set(GPIOB, GPIO8);
	rcc_clock_setup_pll(&this_clock_config);

	/* Enable built in USB pullup on L1 */
	rcc_periph_clock_enable(RCC_SYSCFG);
	SYSCFG_PMC |= SYSCFG_PMC_USB_PU;

	usbd_device *usbd_dev = gadget0_init(&st_usbfs_v1_usb_driver,
					     "stm32l1-generic", true);

	ER_DPRINTF("bootup complete\n");
	gpio_clear(GPIOB, GPIO8);
	while (1) {
		gpio_set(GPIOB, GPIO9);
		gadget0_run(usbd_dev);
		gpio_clear(GPIOB, GPIO9);
	}

}

