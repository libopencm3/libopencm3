/** @defgroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@brief <b>libopencm3 STM32F1xx Reset and Clock Control</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

@date 18 August 2012

This library supports the Reset and Clock Control System in the STM32F1xx
series of ARM Cortex Microcontrollers by ST Microelectronics.

@note Full support for connection line devices is not yet provided.

Clock settings and resets for many peripherals are given here rather than in
the corresponding peripheral library.

The library also provides a number of common configurations for the processor
system clock. Not all possible configurations are included.

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
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
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>

const struct rcc_clock_scale rcc_hse_configs[RCC_CLOCK_HSE_END] = {
	{
		/* hse-12, pll to 72 */
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL6,
		.prediv1 = RCC_CFGR2_PREDIV_NODIV,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV6,
		.flash_waitstates = 2,
		.ahb_frequency	= 72000000,
		.apb1_frequency = 36000000,
		.apb2_frequency = 72000000,
	},
	{
		/* hse16, pll to 72 */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL9,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV6,
		.flash_waitstates = 2,
		.prediv1 = RCC_CFGR2_PREDIV_DIV2,
		.ahb_frequency = 72e6,
		.apb1_frequency = 36e6,
		.apb2_frequency = 72e6,
	},
	{
		/* hse25 to 72, this was a f105 config originally! intention preserved */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL9,
		.pll_source = RCC_CFGR_PLLSRC_PREDIV1_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV6,
		.flash_waitstates = 2,
		.prediv1 = RCC_CFGR2_PREDIV_DIV5,
		.prediv1_source = RCC_CFGR2_PREDIV1SRC_PLL2_CLK,
		.pll2_mul = RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8,
		.prediv2 = RCC_CFGR2_PREDIV2_DIV5,
		.usbpre = RCC_CFGR_USBPRE_PLL_VCO_CLK_DIV3,
		.ahb_frequency = 72e6,
		.apb1_frequency = 36e6,
		.apb2_frequency = 72e6,
	},
	{
		/* hse8, pll to 24 (f100 value line max) */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL3,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV2,
		.flash_waitstates = 0,
		.prediv1 = RCC_CFGR2_PREDIV_NODIV,
		.ahb_frequency = 24e6,
		.apb1_frequency = 24e6,
		.apb2_frequency = 24e6,
	},
	{
		/* hse8, pll to 72 */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL9,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV8,
		.flash_waitstates = 2,
		.prediv1 = RCC_CFGR2_PREDIV_NODIV,
		.ahb_frequency = 72e6,
		.apb1_frequency = 36e6,
		.apb2_frequency = 72e6,
	},
};

const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END] = {
	{
		/* hsi to 24Mhz, max for f100 */
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL6,
		.prediv1 = RCC_CFGR2_PREDIV_NODIV,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV2,
		.flash_waitstates = 0,
		.ahb_frequency	= 24e6,
		.apb1_frequency = 24e6,
		.apb2_frequency = 24e6,
	},
	{
		/* hsi to 48Mhz, allows usb, but out of spec */
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL12,
		.prediv1 = RCC_CFGR2_PREDIV_NODIV,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV8,
		.usbpre = RCC_CFGR_USBPRE_PLL_CLK_NODIV,
		.flash_waitstates = 1,
		.ahb_frequency	= 48e6,
		.apb1_frequency = 24e6,
		.apb2_frequency = 48e6,
	},
	{
		/* hsi to 64Mhz, max possible from hsi */
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL16,
		.prediv1 = RCC_CFGR2_PREDIV_NODIV,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV8,
		.flash_waitstates = 2,
		.ahb_frequency	= 64e6,
		.apb1_frequency = 32e6,
		.apb2_frequency = 64e6,
	},
};

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul Unsigned int32. PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll_multiplication_factor(uint32_t mul)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLMUL) |
			(mul << RCC_CFGR_PLLMUL_SHIFT);
}


/*---------------------------------------------------------------------------*/
/** @brief RCC Set the HSE Frequency Divider used as PLL Clock Source.

@note This only has effect when the PLL is disabled.

@param[in] pllxtpre Unsigned int32. HSE division factor @ref rcc_cfgr_hsepre
*/

void rcc_set_pllxtpre(uint32_t pllxtpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLXTPRE) |
			(pllxtpre << 17);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Setup the A/D Clock

The ADC's have a common clock prescale setting.

@param[in] adcpre uint32_t. Prescale divider taken from @ref rcc_cfgr_adcpre
*/

void rcc_set_adcpre(uint32_t adcpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_ADCPRE) |
			(adcpre << RCC_CFGR_ADCPRE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/*
 * These functions are setting up the whole clock system for the most common
 * input clock and output clock configurations.
 */
/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 64MHz from HSI

*/

void rcc_clock_setup_in_hsi_out_64mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);   /* Set. 64MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_DIV8); /* Set.  8MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE_DIV2);    /* Set. 32MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE_NODIV);   /* Set. 64MHz Max. 72MHz */

	/*
	 * Sysclk is running with 64MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set the PLL multiplication factor to 16.
	 * 8MHz (internal) * 16 (multiplier) / 2 (PLLSRC_HSI_CLK_DIV2) = 64MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL16);

	/* Select HSI/2 as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = 64000000;
	rcc_apb1_frequency = 32000000;
	rcc_apb2_frequency = 64000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 48MHz from HSI

*/

void rcc_clock_setup_in_hsi_out_48mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);	/*Set.48MHz Max.72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_DIV8);	/*Set. 6MHz Max.14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE_DIV2);	/*Set.24MHz Max.36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE_NODIV);	/*Set.48MHz Max.72MHz */
	rcc_set_usbpre(RCC_CFGR_USBPRE_PLL_CLK_NODIV);  /*Set.48MHz Max.48MHz */

	/*
	 * Sysclk runs with 48MHz -> 1 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_1WS);

	/*
	 * Set the PLL multiplication factor to 12.
	 * 8MHz (internal) * 12 (multiplier) / 2 (PLLSRC_HSI_CLK_DIV2) = 48MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL12);

	/* Select HSI/2 as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = 48000000;
	rcc_apb1_frequency = 24000000;
	rcc_apb2_frequency = 48000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 24MHz from HSI

*/

void rcc_clock_setup_in_hsi_out_24mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV); /* Set. 24MHz Max. 24MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_DIV2); /* Set. 12MHz Max. 12MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE_NODIV); /* Set. 24MHz Max. 24MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE_NODIV); /* Set. 24MHz Max. 24MHz */

	/*
	 * Sysclk is (will be) running with 24MHz -> 0 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	/*
	 * Set the PLL multiplication factor to 6.
	 * 8MHz (internal) * 6 (multiplier) / 2 (PLLSRC_HSI_CLK_DIV2) = 24MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL6);

	/* Select HSI/2 as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = 24000000;
	rcc_apb1_frequency = 24000000;
	rcc_apb2_frequency = 24000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 24MHz from HSE at 8MHz

*/

void rcc_clock_setup_in_hse_8mhz_out_24mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/* Enable external high-speed oscillator 8MHz. */
	rcc_osc_on(RCC_HSE);
	rcc_wait_for_osc_ready(RCC_HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);    /* Set. 24MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_DIV2);  /* Set. 12MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE_NODIV);    /* Set. 24MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE_NODIV);    /* Set. 24MHz Max. 72MHz */

	/*
	 * Sysclk runs with 24MHz -> 0 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	/*
	 * Set the PLL multiplication factor to 3.
	 * 8MHz (external) * 3 (multiplier) = 24MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL3);

	/* Select HSE as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

	/*
	 * External frequency undivided before entering PLL
	 * (only valid/needed for HSE).
	 */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = 24000000;
	rcc_apb1_frequency = 24000000;
	rcc_apb2_frequency = 24000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 72MHz from HSE at 8MHz

*/

void rcc_clock_setup_in_hse_8mhz_out_72mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/* Enable external high-speed oscillator 8MHz. */
	rcc_osc_on(RCC_HSE);
	rcc_wait_for_osc_ready(RCC_HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);    /* Set. 72MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_DIV8);  /* Set.  9MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE_DIV2);     /* Set. 36MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE_NODIV);    /* Set. 72MHz Max. 72MHz */

	/*
	 * Sysclk runs with 72MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set the PLL multiplication factor to 9.
	 * 8MHz (external) * 9 (multiplier) = 72MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL9);

	/* Select HSE as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

	/*
	 * External frequency undivided before entering PLL
	 * (only valid/needed for HSE).
	 */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = 72000000;
	rcc_apb1_frequency = 36000000;
	rcc_apb2_frequency = 72000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 72MHz from HSE at 12MHz

*/

void rcc_clock_setup_in_hse_12mhz_out_72mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/* Enable external high-speed oscillator 16MHz. */
	rcc_osc_on(RCC_HSE);
	rcc_wait_for_osc_ready(RCC_HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);    /* Set. 72MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_DIV6);  /* Set. 12MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE_DIV2);     /* Set. 36MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE_NODIV);    /* Set. 72MHz Max. 72MHz */

	/*
	 * Sysclk runs with 72MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set the PLL multiplication factor to 9.
	 * 12MHz (external) * 6 (multiplier) / 1 (PLLXTPRE_HSE_CLK) = 72MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL6);

	/* Select HSI as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

	/*
	 * Divide external frequency by 2 before entering PLL
	 * (only valid/needed for HSE).
	 */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = 72000000;
	rcc_apb1_frequency = 36000000;
	rcc_apb2_frequency = 72000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 72MHz from HSE at 16MHz

*/

void rcc_clock_setup_in_hse_16mhz_out_72mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/* Enable external high-speed oscillator 16MHz. */
	rcc_osc_on(RCC_HSE);
	rcc_wait_for_osc_ready(RCC_HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);    /* Set. 72MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_DIV6);  /* Set. 12MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE_DIV2);     /* Set. 36MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE_NODIV);    /* Set. 72MHz Max. 72MHz */

	/*
	 * Sysclk runs with 72MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set the PLL multiplication factor to 9.
	 * 16MHz (external) * 9 (multiplier) / 2 (PLLXTPRE_HSE_CLK_DIV2) = 72MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL9);

	/* Select HSI as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

	/*
	 * Divide external frequency by 2 before entering PLL
	 * (only valid/needed for HSE).
	 */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = 72000000;
	rcc_apb1_frequency = 36000000;
	rcc_apb2_frequency = 72000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 72MHz from HSE at 25MHz

*/

void rcc_clock_setup_in_hse_25mhz_out_72mhz(void)
{
	/* Enable external high-speed oscillator 25MHz. */
	rcc_osc_on(RCC_HSE);
	rcc_wait_for_osc_ready(RCC_HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Sysclk runs with 72MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);    /* Set. 72MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_DIV6);  /* Set. 12MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE_DIV2);     /* Set. 36MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE_NODIV);    /* Set. 72MHz Max. 72MHz */

	/* Set pll2 prediv and multiplier */
	rcc_set_prediv2(RCC_CFGR2_PREDIV2_DIV5);
	rcc_set_pll2_multiplication_factor(RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8);

	/* Enable PLL2 oscillator and wait for it to stabilize */
	rcc_osc_on(RCC_PLL2);
	rcc_wait_for_osc_ready(RCC_PLL2);

	/* Set pll1 prediv/multiplier, prediv1 src, and usb predivider */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);
	rcc_set_prediv1_source(RCC_CFGR2_PREDIV1SRC_PLL2_CLK);
	rcc_set_prediv1(RCC_CFGR2_PREDIV_DIV5);
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL9);
	rcc_set_pll_source(RCC_CFGR_PLLSRC_PREDIV1_CLK);
	rcc_set_usbpre(RCC_CFGR_USBPRE_PLL_VCO_CLK_DIV3);

	/* enable PLL1 and wait for it to stabilize */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = 72000000;
	rcc_apb1_frequency = 36000000;
	rcc_apb2_frequency = 72000000;
}

void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{
	if (clock->pll_source == RCC_CFGR_PLLSRC_HSE_CLK) {
		rcc_osc_on(RCC_HSE);
		rcc_wait_for_osc_ready(RCC_HSE);
	} else {
		rcc_osc_on(RCC_HSI);
		rcc_wait_for_osc_ready(RCC_HSI);
	}
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);
	rcc_set_adcpre(clock->adcpre);
	rcc_set_usbpre(clock->usbpre);
	flash_set_ws(clock->flash_waitstates);

	rcc_set_pll_multiplication_factor(clock->pll_mul);
	rcc_set_pll_source(clock->pll_source);

	/*
	 * Magically handle F105/7 parts too.
	 * xtpre == prediv1 bit 0.
	 */
	if (clock->prediv1 > RCC_CFGR2_PREDIV_DIV2) {
		rcc_set_prediv1(clock->prediv1);
	} else {
		rcc_set_pllxtpre(clock->prediv1);
	}
	if (clock->prediv1_source) {
		rcc_set_prediv1_source(clock->prediv1_source);
	}

	/*
	 * Magically handle other plls/prescalers on other parts
	 */
	if (clock->prediv2) {
		rcc_set_prediv2(clock->prediv2);
	}
	if (clock->pll2_mul) {
		rcc_set_pll2_multiplication_factor(clock->pll2_mul);
		rcc_osc_on(RCC_PLL2);
		rcc_wait_for_osc_ready(RCC_PLL2);
	}
	if (clock->pll3_mul) {
		rcc_set_pll3_multiplication_factor(clock->pll3_mul);
		rcc_osc_on(RCC_PLL3);
		rcc_wait_for_osc_ready(RCC_PLL3);
	}

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used. */
	rcc_ahb_frequency  = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the USART at base specified.
 * @param usart  Base address of USART to get clock frequency for.
 */
uint32_t rcc_get_usart_clk_freq(uint32_t usart)
{
	if (usart == USART1_BASE) {
		return rcc_apb2_frequency;
	} else {
		return rcc_apb1_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the Timer at base specified.
 * @param timer  Base address of TIM to get clock frequency for.
 */
uint32_t rcc_get_timer_clk_freq(uint32_t timer)
{
	/* Handle APB1 timer clocks. */
	if (timer >= TIM2_BASE && timer <= TIM14_BASE) {
		uint8_t ppre1 = (RCC_CFGR >> RCC_CFGR_PPRE1_SHIFT) & RCC_CFGR_PPRE1_MASK;
		return (ppre1 == RCC_CFGR_PPRE1_HCLK_NODIV) ? rcc_apb1_frequency
			: 2 * rcc_apb1_frequency;
	} else {
		uint8_t ppre2 = (RCC_CFGR >> RCC_CFGR_PPRE2_SHIFT) & RCC_CFGR_PPRE2_MASK;
		return (ppre2 == RCC_CFGR_PPRE2_HCLK_NODIV) ? rcc_apb2_frequency
			: 2 * rcc_apb2_frequency;
	}
	cm3_assert_not_reached();
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the I2C device at base specified.
 * @param i2c  Base address of I2C to get clock frequency for.
 */
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c __attribute__((unused)))
{
	return rcc_apb1_frequency;
}
/**@}*/

