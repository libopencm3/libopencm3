/** @defgroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@brief <b>libopencm3 GD32VF103 Reset and Clock Control</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2020 Lubomir Rintel <lkundrak@v3.sk>

@date 12 July 2020

This library supports the Reset and Clock Control System in the GD32VF103
series of RISC-V Microcontrollers by GigaDevice.

Clock settings and resets for many peripherals are given here rather than in
the corresponding peripheral library.

The library also provides a number of common configurations for the processor
system clock. Not all possible configurations are included.

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Lubomir Rintel <lkundrak@v3.sk>
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

/**@{*/

#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>

const struct rcc_clock_scale rcc_hsi_configs[] = {
	[RCC_CLOCK_HSI_48MHZ] = {
		.pllsrc = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL12,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_NODIV, /* Good Luck. */
		/* Really, use an external crystal. */

		.ahb_frequency  = 48000000,
		.apb1_frequency = 24000000,
		.apb2_frequency = 48000000,
	},
	[RCC_CLOCK_HSI_72MHZ] = {
		.pllsrc = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL18,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV6,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_DIV1_5,

		.ahb_frequency  = 72000000,
		.apb1_frequency = 36000000,
		.apb2_frequency = 72000000,
	},
	[RCC_CLOCK_HSI_108MHZ] = {
		.pllsrc = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL27,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV8,
		/* USB is not going to work. */

		.ahb_frequency  = 108000000,
		.apb1_frequency = 54000000,
		.apb2_frequency = 108000000,
	},
};

const struct rcc_clock_scale rcc_hse8_configs[] = {
	[RCC_CLOCK_HSE8_24MHZ] = {
		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_HSE_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL6,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV2,
		/* USB is not going to work. */

		.ahb_frequency  = 24000000,
		.apb1_frequency = 12000000,
		.apb2_frequency = 24000000,
	},
	[RCC_CLOCK_HSE8_36MHZ] = {
		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_HSE_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL9,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		/* USB is not going to work. */

		.ahb_frequency  = 36000000,
		.apb1_frequency = 18000000,
		.apb2_frequency = 36000000,
	},
	[RCC_CLOCK_HSE8_48MHZ] = {
		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_HSE_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL12,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_NODIV,

		.ahb_frequency  = 48000000,
		.apb1_frequency = 24000000,
		.apb2_frequency = 48000000,
	},
	[RCC_CLOCK_HSE8_56MHZ] = {
		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_HSE_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL14,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		/* USB is not going to work. */

		.ahb_frequency  = 56000000,
		.apb1_frequency = 28000000,
		.apb2_frequency = 56000000,
	},
	[RCC_CLOCK_HSE8_72MHZ] = {
		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_HSE_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL18,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV6,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_DIV1_5,

		.ahb_frequency  = 72000000,
		.apb1_frequency = 36000000,
		.apb2_frequency = 72000000,
	},
	[RCC_CLOCK_HSE8_96MHZ] = {
		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_HSE_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL24,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV8,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_DIV2,

		.ahb_frequency  = 96000000,
		.apb1_frequency = 48000000,
		.apb2_frequency = 96000000,
	},
	[RCC_CLOCK_HSE8_108MHZ] = {
		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_HSE_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL27,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV8,
		/* USB is not going to work. */

		.ahb_frequency  = 108000000,
		.apb1_frequency = 52000000,
		.apb2_frequency = 108000000,
	},
};

const struct rcc_clock_scale rcc_hse25_configs[] = {
	[RCC_CLOCK_HSE25_24MHZ] = {
		.pll_prediv2 = RCC_CFGR2_PREDIV_DIV5,
		.pll_mul2 = RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8,

		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_PLL2_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL6,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV2,
		/* USB is not going to work. */

		.ahb_frequency  = 24000000,
		.apb1_frequency = 12000000,
		.apb2_frequency = 24000000,
	},
	[RCC_CLOCK_HSE25_36MHZ] = {
		.pll_prediv2 = RCC_CFGR2_PREDIV_DIV5,
		.pll_mul2 = RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8,

		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_PLL2_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL9,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		/* USB is not going to work. */

		.ahb_frequency  = 36000000,
		.apb1_frequency = 18000000,
		.apb2_frequency = 36000000,
	},
	[RCC_CLOCK_HSE25_48MHZ] = {
		.pll_prediv2 = RCC_CFGR2_PREDIV_DIV5,
		.pll_mul2 = RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8,

		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_PLL2_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL12,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_NODIV,

		.ahb_frequency  = 48000000,
		.apb1_frequency = 24000000,
		.apb2_frequency = 48000000,
	},
	[RCC_CLOCK_HSE25_56MHZ] = {
		.pll_prediv2 = RCC_CFGR2_PREDIV_DIV5,
		.pll_mul2 = RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8,

		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_PLL2_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL14,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		/* USB is not going to work. */

		.ahb_frequency  = 56000000,
		.apb1_frequency = 28000000,
		.apb2_frequency = 56000000,
	},
	[RCC_CLOCK_HSE25_72MHZ] = {
		.pll_prediv2 = RCC_CFGR2_PREDIV_DIV5,
		.pll_mul2 = RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8,

		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_PLL2_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL18,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV6,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_DIV1_5,

		.ahb_frequency  = 72000000,
		.apb1_frequency = 36000000,
		.apb2_frequency = 72000000,
	},
	[RCC_CLOCK_HSE25_96MHZ] = {
		.pll_prediv2 = RCC_CFGR2_PREDIV_DIV5,
		.pll_mul2 = RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8,

		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_PLL2_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL24,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV8,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_DIV2,

		.ahb_frequency  = 96000000,
		.apb1_frequency = 48000000,
		.apb2_frequency = 96000000,
	},
	[RCC_CLOCK_HSE25_108MHZ] = {
		.pll_prediv2 = RCC_CFGR2_PREDIV_DIV5,
		.pll_mul2 = RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8,

		.pll_prediv1src = RCC_CFGR2_PREDIV1SRC_PLL2_CLK,
		.pll_prediv1 = RCC_CFGR2_PREDIV_DIV2,

		.pllsrc = RCC_CFGR_PLLSRC_HSE_CLK,
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL27,

		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,

		.adcpre = RCC_CFGR_ADCPRE_DIV8,
		/* USB is not going to work. */

		.ahb_frequency  = 108000000,
		.apb1_frequency = 52000000,
		.apb2_frequency = 108000000,
	},
};

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll_multiplication_factor(uint32_t mul)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLMUL_0_3 & ~RCC_CFGR_PLLMUL_4) |
			((mul & 0xf) << RCC_CFGR_PLLMUL_0_3_SHIFT) |
			((!!(mul & 0x10)) << RCC_CFGR_PLLMUL_4_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Setup the A/D Clock

The ADC's have a common clock prescale setting.

@param[in] adcpre Prescale divider taken from @ref rcc_cfgr_adcpre
*/

void rcc_set_adcpre(uint32_t adcpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_ADCPRE_0_1 & ~RCC_CFGR_ADCPRE_2) |
			((adcpre & 0x3) << RCC_CFGR_ADCPRE_0_1_SHIFT) |
			((!!(adcpre & 0x4)) << RCC_CFGR_ADCPRE_2_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Wait for System Clock Ready.

@param[in] clk System Clock Selection @ref rcc_cfgr_scs
*/

void rcc_wait_for_sysclk_source(uint32_t clk)
{
	while (rcc_system_clock_source() != clk);
}

/*---------------------------------------------------------------------------*/
/*
 * These functions are setting up the whole clock system for the most common
 * input clock and output clock configurations.
 */
/*---------------------------------------------------------------------------*/
/**
 * Setup clocks to run from PLL.
 * The arguments provide the pll source, multipliers, dividers, all that's
 * needed to establish a system clock.
 * @param clock clock information structure
 */
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{
	if (clock->pllsrc == RCC_CFGR_PLLSRC_HSE_CLK) {
		/* Enable external high-speed oscillator. */
		rcc_osc_on(RCC_HSE);
		rcc_wait_for_osc_ready(RCC_HSE);
	} else if (clock->pllsrc == RCC_CFGR_PLLSRC_HSI_CLK_DIV2) {
		/* Enable internal high-speed oscillator. */
		rcc_osc_on(RCC_HSI);
		rcc_wait_for_osc_ready(RCC_HSI);
	}

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2 and USB.
	 * This bits need to be set before PLL is running.
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_set_adcpre(clock->adcpre);
	rcc_set_usbpre(clock->usbpre);

	/* Set the PLL multiplication factor. */
	rcc_set_pll_multiplication_factor(clock->pllmul);

	/* Set the PLL source. */
	rcc_set_pll_source(clock->pllsrc);

	if (clock->pllsrc == RCC_CFGR_PLLSRC_HSE_CLK) {
		rcc_set_prediv1(clock->pll_prediv1);
		rcc_set_prediv1_source(clock->pll_prediv1src);

		if (clock->pll_prediv1src == RCC_CFGR2_PREDIV1SRC_PLL2_CLK) {
			rcc_set_prediv2(clock->pll_prediv2);
			rcc_set_pll2_multiplication_factor(clock->pll_mul2);
			rcc_osc_on(RCC_PLL2);
			rcc_wait_for_osc_ready(RCC_PLL2);
		}
	}

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);
	rcc_wait_for_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}

/**@}*/
