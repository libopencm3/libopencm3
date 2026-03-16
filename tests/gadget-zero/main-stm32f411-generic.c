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

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/dbgmcu.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/scs.h>
#include <libopencm3/cm3/tpiu.h>
#include <libopencm3/cm3/dwt.h>
#include <libopencm3/cm3/itm.h>
#include <libopencm3/usb/dwc/otg_fs.h>

#include <stdio.h>
#include "usb-gadget0.h"

#define ER_DEBUG
#ifdef ER_DEBUG
#define ER_DPRINTF(fmt, ...)        \
	do {                            \
		printf(fmt, ##__VA_ARGS__); \
	} while (0)
#else
#define ER_DPRINTF(fmt, ...) \
	do {                     \
	} while (0)
#endif

#define SWO_BAUDRATE          115200U
#define ARM_LAR_ACCESS_ENABLE 0xc5acce55U

static void swo_setup(void);

int main(void)
{
	rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_96MHZ]);
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_OTGFS);

	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO11 | GPIO12);
	gpio_set_af(GPIOA, GPIO_AF10, GPIO11 | GPIO12);

	/* LED to indicate boot process */
	rcc_periph_clock_enable(RCC_GPIOC);
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
	gpio_set(GPIOC, GPIO13);

	/* Bring SWO up so we can be heard */
	swo_setup();

	/* https://github.com/libopencm3/libopencm3/pull/1256#issuecomment-779424001 */
	OTG_FS_GCCFG |= OTG_GCCFG_NOVBUSSENS | OTG_GCCFG_PWRDWN;
	OTG_FS_GCCFG &= ~(OTG_GCCFG_VBUSBSEN | OTG_GCCFG_VBUSASEN);

	usbd_device *usbd_dev = gadget0_init(&otgfs_usb_driver, "stm32f411-generic");

	ER_DPRINTF("bootup complete\n");
	gpio_clear(GPIOC, GPIO13);
	while (true) {
		gadget0_run(usbd_dev);
	}
}

static void swo_setup(void)
{
	/* Enable tracing in DEMCR */
	SCS_DEMCR |= SCS_DEMCR_TRCENA;

	/* Get the active clock frequency of the core and use that to calculate a divisor */
	const uint32_t clock_frequency = rcc_ahb_frequency;
	const uint32_t divisor = (clock_frequency / SWO_BAUDRATE) - 1U;
	/* And configure the TPIU for 1-bit async trace (SWO) in Manchester coding */
	TPIU_LAR = ARM_LAR_ACCESS_ENABLE;
	TPIU_CSPSR = 1U; /* 1-bit mode */
	TPIU_ACPR = divisor;
	TPIU_SPPR = TPIU_SPPR_ASYNC_NRZ; //TPIU_SPPR_ASYNC_MANCHESTER;
	/* Ensure that TPIU framing is off */
	TPIU_FFCR &= ~TPIU_FFCR_ENFCONT;

	/* Configure the DWT to provide the sync source for the ITM */
	DWT_LAR = ARM_LAR_ACCESS_ENABLE;
	DWT_CTRL |= 0x000003feU;
	/* Enable access to the ITM registers and configure tracing output from the first stimulus port */
	ITM_LAR = ARM_LAR_ACCESS_ENABLE;
	/* User-level access to the first 8 ports */
	ITM_TPR = 0x0000000fU;
	ITM_TCR = ITM_TCR_ITMENA | ITM_TCR_SYNCENA | ITM_TCR_TXENA | ITM_TCR_SWOENA | (1U << 16U);
	ITM_TER[0] = 1U;
	ITM_TER[1] = 1U;
	ITM_TER[2] = 1U;

	/* Now tell the DBGMCU that we want trace enabled and mapped as SWO */
	DBGMCU_CR &= ~DBGMCU_CR_TRACE_MODE_MASK;
	DBGMCU_CR |= DBGMCU_CR_TRACE_IOEN | DBGMCU_CR_TRACE_MODE_ASYNC;
}
