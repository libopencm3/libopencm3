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
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/usb/dwc/otg_fs.h>

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

#define OTG_GOTGCTL_BVALOVAL		(1U << 7U)
#define OTG_GOTGCTL_BVALOEN		(1U << 6U)

// #include <libopencm3/stm32/u5/pwr.h>
#define PWR_SVMCR		MMIO32(PWR_BASE + 0x10)
#define PWR_SVMSR		MMIO32(PWR_BASE + 0x3C)

#define PWR_SVMCR_USV		(1U << 28U)
#define PWR_SVMCR_UVMEN		(1U << 24U)

#define PWR_SVMSR_VDDUSBRDY		(1U << 24U)

int main(void)
{
	rcc_clock_setup_hsi(&rcc_hsi16mhz_configs);
	rcc_osc_on(RCC_HSI48);
	while (!rcc_is_osc_ready(RCC_HSI48));
	crs_autotrim_usb_enable();
	rcc_periph_clock_enable(RCC_GPIOA);
	//rcc_periph_clock_enable(RCC_OTGFS);

	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO11 | GPIO12);
	gpio_set_af(GPIOA, GPIO_AF10, GPIO11 | GPIO12);

	/* LED to indicate boot process */
	rcc_periph_clock_enable(RCC_GPIOC);
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
	gpio_set(GPIOC, GPIO13);

	/* Remove Vddusb power isolation */
	rcc_periph_clock_enable(RCC_PWR);
	PWR_SVMCR |= PWR_SVMCR_USV;
	uint32_t pwr_svmsr = PWR_SVMSR;
	(void) (pwr_svmsr & PWR_SVMSR_VDDUSBRDY);

	usbd_device *usbd_dev = gadget0_init(&otgfs_usb_driver, "stm32u575-generic");
	/* Disable Vbus detection and override B-session valid */
	uint32_t core_id = OTG_FS_CID;
	if (core_id >= 0x2000) {
		OTG_FS_GCCFG &= ~(OTG_GCCFG_VBDEN);
		OTG_FS_GOTGCTL |= (OTG_GOTGCTL_BVALOEN | OTG_GOTGCTL_BVALOVAL);
		(void) (OTG_FS_GOTGCTL & OTG_GOTGCTL_BSVLD);
	}

	ER_DPRINTF("bootup complete\n");
	gpio_clear(GPIOC, GPIO13);
	while (1) {
		gadget0_run(usbd_dev);
	}

}

