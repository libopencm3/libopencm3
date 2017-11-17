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

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/crs.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/syscfg.h>

#include <stdio.h>
#include "usb-gadget0.h"

/* no trace on cm0 #define ER_DEBUG */
#ifdef ER_DEBUG
#define ER_DPRINTF(fmt, ...) \
	do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define ER_DPRINTF(fmt, ...) \
	do { } while (0)
#endif

#include "trace.h"
void trace_send_blocking8(int stimulus_port, char c)
{
	(void)stimulus_port;
	(void)c;
}

int main(void)
{
	/* LED for boot progress */
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
	gpio_set(GPIOA, GPIO5);

	/* PLL from HSI16, just to exercise that code */
	struct rcc_clock_scale myclock = {
		.ahb_frequency = 32e6,
		.apb1_frequency = 32e6,
		.apb2_frequency = 32e6,
		.flash_waitstates = 1,
		.pll_source = RCC_CFGR_PLLSRC_HSI16_CLK, /* not even sure there's hse on l053 disco */
		/* .msi_range  doesn't matter */
		.pll_mul = RCC_CFGR_PLLMUL_MUL4,
		.pll_div = RCC_CFGR_PLLDIV_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_NODIV,
		.ppre2 = RCC_CFGR_PPRE2_NODIV,
	};
	rcc_clock_setup_pll(&myclock);

	/* HSI48 needs the vrefint turned on */
	rcc_periph_clock_enable(RCC_SYSCFG);
	SYSCFG_CFGR3 |= SYSCFG_CFGR3_ENREF_HSI48 | SYSCFG_CFGR3_EN_VREFINT;
	while (!(SYSCFG_CFGR3 & SYSCFG_CFGR3_REF_HSI48_RDYF));

	/* For USB, but can't use HSI48 as a sysclock on L0 */
	crs_autotrim_usb_enable();
	rcc_set_hsi48_source_rc48();

	rcc_osc_on(RCC_HSI48);
	rcc_wait_for_osc_ready(RCC_HSI48);

	usbd_device *usbd_dev = gadget0_init(&st_usbfs_v2_usb_driver,
					     "stm32l053disco");

	ER_DPRINTF("bootup complete\n");
	gpio_clear(GPIOA, GPIO5);
	while (1) {
		gadget0_run(usbd_dev);
	}

}

