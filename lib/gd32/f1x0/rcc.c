/** @defgroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@brief <b>libopencm3 GD32F1x0 Reset and Clock Control</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

@date 18 August 2012

This library supports the Reset and Clock Control System in the GD32F1x0
series of ARM Cortex Microcontrollers by GigaDevice.

@note Full support for F170 and F190 devices is not yet provided.

Clock settings and resets for many peripherals are given here rather than in
the corresponding peripheral library.

The library also provides a number of common configurations for the processor
system clock. Not all possible configurations are included.

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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
#include <libopencm3/gd32/rcc.h>
#include <libopencm3/gd32/flash.h>

const struct rcc_clock_scale rcc_hsi_configs[] = {
	{ /* 48MHz */
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL12,
		.hpre = RCC_CFGR_HPRE_SYSCLK_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_HCLK_DIV2,
		.ppre2 = RCC_CFGR_PPRE2_HCLK_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_PCLK2_DIV8,
		.use_hse = false,
		.ahb_frequency	= 48000000,
		.apb1_frequency = 24000000,
		.apb2_frequency = 48000000,
	},
	{ /* 64MHz */
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL16,
		.hpre = RCC_CFGR_HPRE_SYSCLK_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_HCLK_DIV2,
		.ppre2 = RCC_CFGR_PPRE2_HCLK_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_PCLK2_DIV8,
		.use_hse = false,
		.ahb_frequency	= 64000000,
		.apb1_frequency = 32000000,
		.apb2_frequency = 64000000,
	}
};

const struct rcc_clock_scale rcc_hse8_configs[] = {
	{ /* 72MHz */
		.pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL9,
		.hpre = RCC_CFGR_HPRE_SYSCLK_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_HCLK_DIV2,
		.ppre2 = RCC_CFGR_PPRE2_HCLK_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_PCLK2_DIV8,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_DIV1_5,
		.use_hse = true,
		.pll_hse_prediv = RCC_CFGR2_PREDIV_NODIV,
		.ahb_frequency	= 72000000,
		.apb1_frequency = 36000000,
		.apb2_frequency = 72000000,
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
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_ADCPRE) |
			(adcpre << RCC_CFGR_ADCPRE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB2 Prescale Factor.

@param[in] ppre2 APB2 prescale factor @ref rcc_cfgr_apb2pre
*/

void rcc_set_ppre2(uint32_t ppre2)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PPRE2) |
			(ppre2 << RCC_CFGR_PPRE2_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB1 Prescale Factor.

@note The APB1 clock frequency must not exceed 36MHz.

@param[in] ppre1 APB1 prescale factor @ref rcc_cfgr_apb1pre
*/

void rcc_set_ppre1(uint32_t ppre1)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PPRE1) |
			(ppre1 << RCC_CFGR_PPRE1_SHIFT);

}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the USB Prescale Factor.

The prescale factor can be set to 1 (no prescale) for use when the PLL clock is
48MHz, or 1.5 to generate the 48MHz USB clock from a 64MHz PLL clock.

@note This bit cannot be reset while the USB clock is enabled.

@param[in] usbpre USB prescale factor @ref rcc_cfgr_usbpre
*/

void rcc_set_usbpre(uint32_t usbpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_USBPRE) | usbpre;
}

/**
 * Set PLL Source pre-divider **CAUTION**.
 * On F1x0, prediv only applies to HSE source.
 * @param[in] prediv division by prediv+1 @ref rcc_cfgr2_prediv
 */
void rcc_set_prediv(uint32_t prediv)
{
	RCC_CFGR2 = (RCC_CFGR2 & ~RCC_CFGR2_PREDIV) | prediv;
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
	if (clock->use_hse) {
		/* Enable external high-speed oscillator. */
		rcc_osc_on(RCC_HSE);
		rcc_wait_for_osc_ready(RCC_HSE);
		rcc_set_sysclk_source(RCC_HSE);
	} else {
		/* Enable internal high-speed oscillator. */
		rcc_osc_on(RCC_HSI);
		rcc_wait_for_osc_ready(RCC_HSI);
		rcc_set_sysclk_source(RCC_HSI);
	}

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2 and USB.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_set_adcpre(clock->adcpre);
	if (clock->use_hse)
		rcc_set_usbpre(clock->usbpre);

	/* Set the PLL multiplication factor. */
	rcc_set_pll_multiplication_factor(clock->pllmul);

	if (clock->use_hse) {
		/* Select HSE as PLL source. */
		rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

		/*
		 * External frequency undivided before entering PLL
		 * (only valid/needed for HSE).
		 */
		rcc_set_prediv(clock->pll_hse_prediv);
	} else {
		/* Select HSI/2 as PLL source. */
		rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_CLK_DIV2);
	}

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_PLL);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}

/**@}*/

