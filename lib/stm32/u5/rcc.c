/** @defgroup rcc_file RCC peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32U5xx Reset and Clock Control</b>
 *
 * @version 1.0.0
 *
 * @date 09 Oct 2024
 *
 * This library supports the Reset and Clock Control System in the STM32U5xx
 * series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
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

#include <stddef.h>
#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/flash.h>

#define HZ_PER_MHZ 1000000UL
#define HZ_PER_KHZ 1000UL

/* Set the default clock frequencies */
#define RCC_DEFAULT_MSIS_FREQUENCY  4000000U
#define RCC_DEFAULT_HSI48_FREQUENCY 48000000U
#define RCC_DEFAULT_SHSI_FREQUENCY  48000000U
#define RCC_DEFAULT_HSI16_FREQUENCY 16000000U
#define RCC_DEFAULT_LSI_FREQUENCY   32000U
#define RCC_DEFAULT_LSE_FREQUENCY   32768U

/* Local private copy of the clock configuration for providing user with clock tree data. */
static struct {
	uint32_t sysclk;
	uint32_t hclk;
	uint32_t msis;
	uint32_t msik;

	uint32_t pclk1; /* APB1 clock. */
	uint32_t pclk2; /* APB2 clock. */
	uint32_t pclk3; /* APB3 clock. */

	struct pll_clocks { /* Each PLL output set of data. */
		uint32_t p;
		uint32_t q;
		uint32_t r;
	} pll1, pll2, pll3;

	uint16_t hse_khz; /* This can't exceed 50MHz */
} rcc_clock_tree = {
	.sysclk = RCC_HSI_BASE_FREQUENCY,
	.hclk = RCC_HSI_BASE_FREQUENCY,
	.msis = RCC_MSI_RANGE_4MHZ,
	.msik = RCC_MSI_RANGE_4MHZ,
	.pclk1 = RCC_HSI_BASE_FREQUENCY,
	.pclk2 = RCC_HSI_BASE_FREQUENCY,
	.pclk3 = RCC_HSI_BASE_FREQUENCY,
};

typedef struct pll_clocks pll_clocks_s;

const struct rcc_clock_scale rcc_hsi16mhz_configs = {
	.hpre = RCC_CFGR2_HPRE_NODIV,
	.ppre1 = RCC_PPRE_NODIV,
	.ppre2 = RCC_PPRE_NODIV,
	.ahb_frequency = RCC_DEFAULT_HSI16_FREQUENCY,
	.apb1_frequency = RCC_DEFAULT_HSI16_FREQUENCY,
	.apb2_frequency = RCC_DEFAULT_HSI16_FREQUENCY,
};

static volatile uint32_t *rcc_pll_cfg_reg(const pll_number_e pll_num)
{
	/* Dispatch, returning the config register for the selected PLL */
	switch (pll_num) {
	case RCC_PLL_NUM_1:
		return &RCC_PLL1CFGR;
	case RCC_PLL_NUM_2:
		return &RCC_PLL2CFGR;
	case RCC_PLL_NUM_3:
		return &RCC_PLL3CFGR;
	}
	/* Turn any other PLL number passed in into UB */
	__builtin_unreachable();
}

static volatile uint32_t *rcc_pll_div_reg(const pll_number_e pll_num)
{
	/* Dispatch, returning the config register for the selected PLL */
	switch (pll_num) {
	case RCC_PLL_NUM_1:
		return &RCC_PLL1DIVR;
	case RCC_PLL_NUM_2:
		return &RCC_PLL2DIVR;
	case RCC_PLL_NUM_3:
		return &RCC_PLL3DIVR;
	}
	/* Turn any other PLL number passed in into UB */
	__builtin_unreachable();
}

static volatile uint32_t *rcc_pll_frac_reg(const pll_number_e pll_num)
{
	/* Dispatch, returning the config register for the selected PLL */
	switch (pll_num) {
	case RCC_PLL_NUM_1:
		return &RCC_PLL1FRACR;
	case RCC_PLL_NUM_2:
		return &RCC_PLL2FRACR;
	case RCC_PLL_NUM_3:
		return &RCC_PLL3FRACR;
	}
	/* Turn any other PLL number passed in into UB */
	__builtin_unreachable();
}

static pll_clocks_s *rcc_pll_clock_tree(const pll_number_e pll_num)
{
	/* Dispatch, returning the clock tree pointer for the selected PLL */
	switch (pll_num) {
	case RCC_PLL_NUM_1:
		return &rcc_clock_tree.pll1;
	case RCC_PLL_NUM_2:
		return &rcc_clock_tree.pll2;
	case RCC_PLL_NUM_3:
		return &rcc_clock_tree.pll3;
	}
	/* Turn any other PLL number passed in into UB */
	__builtin_unreachable();
}

static uint32_t rcc_msi_frequency(const uint8_t range)
{
	switch (range) {
	case RCC_MSI_RANGE_48MHZ:
		return 48000000U;
	case RCC_MSI_RANGE_24MHZ:
		return 24000000U;
	case RCC_MSI_RANGE_16MHZ:
		return 16000000U;
	case RCC_MSI_RANGE_12MHZ:
		return 12000000U;
	case RCC_MSI_RANGE_4MHZ:
		return 4000000U;
	case RCC_MSI_RANGE_2MHZ:
		return 2000000U;
	case RCC_MSI_RANGE_1M33HZ:
		return 1330000U;
	case RCC_MSI_RANGE_1MHZ:
		return 1000000U;
	case RCC_MSI_RANGE_3M072HZ:
		return 3072000U;
	case RCC_MSI_RANGE_1M536HZ:
		return 1536000U;
	case RCC_MSI_RANGE_1M024HZ:
		return 1024000U;
	case RCC_MSI_RANGE_768KHZ:
		return 768000U;
	case RCC_MSI_RANGE_400KHZ:
		return 400000U;
	case RCC_MSI_RANGE_200KHZ:
		return 200000U;
	case RCC_MSI_RANGE_133KHZ:
		return 133000U;
	case RCC_MSI_RANGE_100KHZ:
		return 100000U;
	default:
		/* All possible values are handled, so turn this into UB */
		__builtin_unreachable();
	}
}

static uint32_t rcc_pll_input_frequency(const uint32_t hse_frequency, const uint8_t pll_source)
{
	switch (pll_source) {
	case RCC_PLLCFGR_PLLSRC_MSIS:
		return rcc_clock_tree.msis;
	case RCC_PLLCFGR_PLLSRC_HSI16:
		return RCC_HSI_BASE_FREQUENCY;
	case RCC_PLLCFGR_PLLSRC_HSE:
		return hse_frequency;
	}
	/* Turn any other PLL input source passed in into UB */
	__builtin_unreachable();
}

static void rcc_configure_pll(
	const uint32_t hse_frequency, const pll_config_s *const config, const pll_number_e pll_num)
{
	/* Extract the registers we need to touch to (re)configure this PLL */
	volatile uint32_t *const pll_cfg_reg = rcc_pll_cfg_reg(pll_num);
	volatile uint32_t *const pll_div_reg = rcc_pll_div_reg(pll_num);
	volatile uint32_t *const pll_frac_reg = rcc_pll_frac_reg(pll_num);
	(void)pll_frac_reg; /* For now we don't support the fractional component of this */

	/* Set the PLL source and early return if this PLL is not actually used */
	if (config->pll_source == RCC_PLLCFGR_PLLSRC_NONE) {
		*pll_cfg_reg &= ~(RCC_PLLCFGR_PLLREN | RCC_PLLCFGR_PLLQEN | RCC_PLLCFGR_PLLPEN | RCC_PLLCFGR_PLLSRC);
		return;
	}

	pll_clocks_s *const pll_tree_ptr = rcc_pll_clock_tree(pll_num);

	/* Set up the multiplication factor from the config and route the right clock to the PLL */
	*pll_div_reg = RCC_PLLDIVR_DIVN(config->divn);
	*pll_cfg_reg &= ~(RCC_PLLCFGR_PLLREN | RCC_PLLCFGR_PLLQEN | RCC_PLLCFGR_PLLPEN | RCC_PLLCFGR_PLLM |
		RCC_PLLCFGR_PLLRGE | RCC_PLLCFGR_PLLSRC);
	*pll_cfg_reg |= RCC_PLLCFGR_DIVM(config->divm) | (config->pll_source << RCC_PLLCFGR_PLLSRC_SHIFT);

	/* Set the PLL input frequency range */
	const uint32_t input_frequency = rcc_pll_input_frequency(hse_frequency, config->pll_source);
	uint32_t pll_clk = input_frequency / config->divm;
	if (pll_clk >= (4U * HZ_PER_MHZ) && pll_clk < (8U * HZ_PER_MHZ)) {
		*pll_cfg_reg |= RCC_PLLCFGR_PLLRGE_4_8_MHZ << RCC_PLLCFGR_PLLRGE_SHIFT;
	} else if (pll_clk >= (8U * HZ_PER_MHZ) && pll_clk < (16U * HZ_PER_MHZ)) {
		*pll_cfg_reg |= RCC_PLLCFGR_PLLRGE_8_16_MHZ << RCC_PLLCFGR_PLLRGE_SHIFT;
	}

	/* Enable each output the config asks for */
	uint32_t pll_vco_clk = pll_clk * config->divn;
	if (config->divp > 0U) {
		*pll_div_reg |= RCC_PLLDIVR_DIVP(config->divp);
		*pll_cfg_reg |= RCC_PLLCFGR_PLLPEN;
		pll_tree_ptr->p = pll_vco_clk / config->divp;
	}
	if (config->divq > 0U) {
		*pll_div_reg |= RCC_PLLDIVR_DIVQ(config->divq);
		*pll_cfg_reg |= RCC_PLLCFGR_PLLQEN;
		pll_tree_ptr->q = pll_vco_clk / config->divq;
	}
	if (config->divr > 0U) {
		*pll_div_reg |= RCC_PLLDIVR_DIVR(config->divr);
		*pll_cfg_reg |= RCC_PLLCFGR_PLLREN;
		pll_tree_ptr->r = pll_vco_clk / config->divr;
	}

	/* Attempt to enable and lock PLL. */
	const size_t cr_addshift = 2U * pll_num;
	RCC_CR |= RCC_CR_PLL1ON << cr_addshift;
	while (!(RCC_CR & (RCC_CR_PLL1RDY << cr_addshift)))
		continue;
}

static void rcc_set_and_enable_plls(const rcc_pll_config_s *const config)
{
	rcc_configure_pll(config->hse_frequency, &config->pll1, RCC_PLL_NUM_1);
	rcc_configure_pll(config->hse_frequency, &config->pll2, RCC_PLL_NUM_2);
	rcc_configure_pll(config->hse_frequency, &config->pll3, RCC_PLL_NUM_3);
}

/* This is a helper to calculate dividers that go 2/4/8/16/64/128/256/512.
 * These dividers also use the top bit as an "enable". */
static uint32_t rcc_prediv_log_skip32_div(uint32_t clk, uint32_t div_val)
{
	if (div_val < 8U) {
		return clk;
	}
	if (div_val <= 11U) {
		return clk >> (div_val - 7U);
	}
	return clk >> (div_val - 6U);
}

/* This is a helper to help calculate simple 3-bit log dividers with top bit
 * used as enable bit. */
static uint32_t rcc_prediv_3bit_log_div(uint32_t clk, uint32_t div_val)
{
	if (div_val < 4U) {
		return clk;
	}
	return clk >> (div_val - 3U);
}

static uint16_t rcc_map_pll_to_epod_div(const uint8_t divm)
{
	if (divm >= 16U)
		return RCC_PLL1CFGR_PLL1MBOOST_DIV16;
	if (divm >= 14U)
		return RCC_PLL1CFGR_PLL1MBOOST_DIV14;
	if (divm >= 12U)
		return RCC_PLL1CFGR_PLL1MBOOST_DIV12;
	if (divm >= 10U)
		return RCC_PLL1CFGR_PLL1MBOOST_DIV10;
	if (divm >= 8U)
		return RCC_PLL1CFGR_PLL1MBOOST_DIV8;
	if (divm >= 6U)
		return RCC_PLL1CFGR_PLL1MBOOST_DIV6;
	if (divm >= 4U)
		return RCC_PLL1CFGR_PLL1MBOOST_DIV4;
	if (divm >= 2U)
		return RCC_PLL1CFGR_PLL1MBOOST_DIV2;
	return RCC_PLL1CFGR_PLL1MBOOST_DIV1;
}

static void rcc_setup_epod_boost(const uint8_t pll_source, const uint8_t divm)
{
	/*
	 * Set up PLL1 to support the Embedded Power Distribution (EPOD) booster.
	 * We have one of two paths to take here - either we copy the prescaler for the PLL,
	 * or we have to drive HSI16 to the PLL so it's definitely in the 4-16MHz window required.
	 * Which we do is based on whether PLL1 is actually configured to be used.
	 */
	RCC_PLL1CFGR &= ~(RCC_PLL1CFGR_PLL1MBOOST | RCC_PLLCFGR_PLLSRC_SHIFT);
	if (pll_source != RCC_PLLCFGR_PLLSRC_NONE) {
		/* Copy the source and prescaling settings over for the PLL */
		RCC_PLL1CFGR |=
			(rcc_map_pll_to_epod_div(divm) << RCC_PLL1CFGR_PLL1MBOOST_SHIFT) | (pll_source << RCC_PLLCFGR_PLLSRC_SHIFT);
	} else {
		/* Enable HSI16 and wait for it to become ready */
		RCC_CR |= RCC_CR_HSION;
		while ((RCC_CR & RCC_CR_HSIRDY) == 0U)
			continue;
		/* Route it through to PLL1 w/ no prescaling for the boost clock */
		RCC_PLL1CFGR |= (RCC_PLLCFGR_PLLSRC_HSI16 << RCC_PLLCFGR_PLLSRC_SHIFT) |
			(RCC_PLL1CFGR_PLL1MBOOST_DIV1 << RCC_PLL1CFGR_PLL1MBOOST_SHIFT);
	}
}

static void rcc_clock_setup_sysclk_source(const uint8_t sysclock_source)
{
	/* Figure out what basic source is required for SYSCLK, and bring that up */
	switch (sysclock_source) {
	case RCC_MSIS:
		RCC_CR |= RCC_CR_MSISON;
		while ((RCC_CR & RCC_CR_MSISRDY) == 0U)
			continue;
		break;
	case RCC_HSI16:
		RCC_CR |= RCC_CR_HSION;
		while ((RCC_CR & RCC_CR_HSIRDY) == 0U)
			continue;
		break;
	case RCC_PLLCFGR_PLLSRC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		while ((RCC_CR & RCC_CR_HSERDY) == 0U)
			continue;
		break;
	default:
		break;
	}
}

static void rcc_clock_setup_pll_source(const rcc_osc_e pll_source)
{
	/* Figure out what source is required for this PLL, then bring it up */
	switch (pll_source) {
	case RCC_PLLCFGR_PLLSRC_MSIS:
		RCC_CR |= RCC_CR_MSISON;
		while ((RCC_CR & RCC_CR_MSISRDY) == 0U)
			continue;
		break;
	case RCC_PLLCFGR_PLLSRC_HSI16:
		RCC_CR |= RCC_CR_HSION;
		while ((RCC_CR & RCC_CR_HSIRDY) == 0U)
			continue;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		while ((RCC_CR & RCC_CR_HSERDY) == 0U)
			continue;
		break;
	default:
		break;
	}
}

static void rcc_switch_sysclk_source(const uint8_t sw_source)
{
	/* Set the source we want to switch to */
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) | (sw_source << RCC_CFGR_SW_SHIFT);
	/* Now spin looking for that source to become active */
	while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) != sw_source)
		continue;
}

static void rcc_msis_change_range(const uint8_t msis_range)
{
	/* Bring the LSE up if this config is for the MSIS to be PLL'd */
	if (msis_range & RCC_MSIS_RANGE_PLL) {
		RCC_BDCR |= RCC_BDCR_LSEON;
		while ((RCC_BDCR & RCC_BDCR_LSERDY) == 0)
			continue;
	}

	/* Temporarily bring up the HSI16 and switch to it so we can reconfig the MSIS */
	const bool hsi_off = !(RCC_CR & RCC_CR_HSION);
	RCC_CR |= RCC_CR_HSION;
	while (!(RCC_CR & RCC_CR_HSIRDY))
		continue;
	rcc_switch_sysclk_source(RCC_CFGR_SW_HSI16);

	/* Switch to the requested range */
	const uint8_t range = msis_range & RCC_MSIS_RANGE_MASK;
	RCC_ICSCR1 = (RCC_ICSCR1 & ~RCC_ICSCR1_MSISRANGE) | (range << RCC_ICSCR1_MSISRANGE_SHIFT) | RCC_ICSCR1_MSIRGSEL;
	RCC_CR |= RCC_CR_MSISON;
	/* And wait for it to become ready, switching back to MSIS as source */
	while (!(RCC_CR & RCC_CR_MSISRDY))
		continue;
	rcc_switch_sysclk_source(RCC_CFGR_SW_MSIS);
	/* Turn the HSI16 back off if it's not going to be used */
	if (hsi_off)
		RCC_CR &= ~RCC_CR_HSION;

	/* And then ask the MSI PLL to come up if this config requires it */
	if (msis_range & RCC_MSIS_RANGE_PLL) {
		RCC_CR |= RCC_CR_MSIPLLEN | RCC_CR_MSIPLLSEL;
	}
}

void rcc_clock_setup_pll(const rcc_pll_config_s *const config)
{
	/* First, set system clock to utilize MSIS, then disable all but MSIS. */
	RCC_CR |= RCC_CR_MSISON;
	while ((RCC_CR & RCC_CR_MSISRDY) == 0U)
		continue;
	rcc_switch_sysclk_source(RCC_CFGR_SW_MSIS);
	RCC_CR = RCC_CR_MSISON;

	/* Now we've got known clocking, make sure the PWR block is enabled */
	rcc_periph_clock_enable(RCC_PWR);

	/* Bring up all the sources the user needs for this config */
	rcc_clock_tree.hse_khz = config->hse_frequency / HZ_PER_KHZ;
	rcc_clock_setup_sysclk_source(config->sysclock_source);
	rcc_clock_setup_pll_source(config->pll1.pll_source);
	rcc_clock_setup_pll_source(config->pll2.pll_source);
	rcc_clock_setup_pll_source(config->pll3.pll_source);

	/* Now that we're safely running on MSIS, if we're targeting a >55MHz config, set up PLL1MBOOST */
	if (config->voltage_scale == PWR_VOS_SCALE_1 || config->voltage_scale == PWR_VOS_SCALE_2) {
		rcc_setup_epod_boost(config->pll1.pll_source, config->pll1.divm);
	}
	/* Now let's setup the power system Vcore source and voltage scaling for the target frequency */
	pwr_set_mode(config->power_mode);
	pwr_set_vos_scale(config->voltage_scale);

	/* Set Flash waitstates. U5 doesn't support prefetch, so nothing to do WRT this. */
	flash_set_ws(config->flash_waitstates);

	/* User has specified an external oscillator, make sure we turn it on. */
	if (config->hse_frequency > 0) {
		RCC_CR |= RCC_CR_HSEON;
		while (!(RCC_CR & RCC_CR_HSERDY))
			continue;
	}
	/* User has specified a MSIS frequency */
	else if (config->msis_range != RCC_MSIS_RANGE_OFF)
		rcc_msis_change_range(config->msis_range);
	rcc_clock_tree.msis = rcc_msi_frequency((RCC_ICSCR1 >> RCC_ICSCR1_MSISRANGE_SHIFT) & RCC_ICSCR1_MSISRANGE_MASK);
	rcc_clock_tree.msik = rcc_msi_frequency((RCC_ICSCR1 >> RCC_ICSCR1_MSIKRANGE_SHIFT) & RCC_ICSCR1_MSIKRANGE_MASK);

	/* Set, enable and lock all of the PLLs from the config. */
	rcc_set_and_enable_plls(config);

	/* Set up the AHB and APB dividers so we don't exceed any f(max)'s */
	RCC_CFGR2 = (RCC_CFGR2 & ~(RCC_CFGR2_HPRE | RCC_CFGR2_PPRE1 | RCC_CFGR2_PPRE2)) |
		(config->hpre << RCC_CFGR2_HPRE_SHIFT) | (config->ppre1 << RCC_CFGR2_PPRE1_SHIFT) |
		(config->ppre2 << RCC_CFGR2_HPRE_SHIFT);
	RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_PPRE3) | (config->ppre3 << RCC_CFGR3_PPRE3_SHIFT);

	/* Populate our base sysclk settings for use and switch the clock to the requested source */
	if (config->sysclock_source == RCC_MSIS) {
		/* We're already on the MSIS so just use that as the sysclk directly */
		rcc_clock_tree.sysclk = rcc_clock_tree.msis;
	} else if (config->sysclock_source == RCC_HSI16) {
		/* HSI16 was enabled by rcc_clock_setup_sysclk_source(), so switch to it */
		rcc_switch_sysclk_source(RCC_CFGR_SW_HSI16);
		rcc_clock_tree.sysclk = RCC_HSI_BASE_FREQUENCY;
	} else if (config->sysclock_source == RCC_HSE) {
		/* HSE was enabled by rcc_clock_setup_sysclk_source(), so switch to it */
		rcc_switch_sysclk_source(RCC_CFGR_SW_HSE);
		rcc_clock_tree.sysclk = config->hse_frequency;
	} else {
		/* PLL1R was enabled by rcc_set_and_enable_plls(), so switch to it */
		rcc_switch_sysclk_source(RCC_CFGR_SW_PLL);
		rcc_clock_tree.sysclk = rcc_clock_tree.pll1.r;
	}

	/* Store the running speeds of the divided clock domains now we're on the chosen source for SYSCLK */
	rcc_clock_tree.hclk = rcc_prediv_log_skip32_div(rcc_clock_tree.sysclk, config->hpre);
	rcc_clock_tree.pclk1 = rcc_prediv_3bit_log_div(rcc_clock_tree.hclk, config->ppre1);
	rcc_clock_tree.pclk2 = rcc_prediv_3bit_log_div(rcc_clock_tree.hclk, config->ppre2);
	rcc_clock_tree.pclk3 = rcc_prediv_3bit_log_div(rcc_clock_tree.hclk, config->ppre3);
}

void rcc_clock_setup_hsi48(void)
{
	RCC_CR |= RCC_CR_HSI48ON;
	while (!(RCC_CR & RCC_CR_HSI48RDY))
		continue;
}

/**
 * Switch sysclock to HSI with the given parameters.
 * This should be usable from any point in time, but only if you have used
 * library functions to manage clocks.  It relies on the global
 * @ref rcc_ahb_frequency to ensure that it reliably scales voltage up or down
 * as appropriate.
 * @param clock full struct with desired parameters
 */
void rcc_clock_setup_hsi(const struct rcc_clock_scale *clock)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);

	RCC_CFGR2 = (RCC_CFGR2 & ~(RCC_CFGR2_HPRE | RCC_CFGR2_PPRE1 | RCC_CFGR2_PPRE2)) |
		(clock->hpre << RCC_CFGR2_HPRE_SHIFT) | (clock->ppre1 << RCC_CFGR2_PPRE1_SHIFT) |
		(clock->ppre2 << RCC_CFGR2_HPRE_SHIFT);
	RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_PPRE3) | (clock->ppre3 << RCC_CFGR3_PPRE3_SHIFT);

	rcc_wait_for_osc_ready(RCC_HSI);
	rcc_set_sysclk_source(RCC_HSI16);

	/* Set the peripheral clock frequencies used. */
	rcc_clock_tree.hclk = clock->ahb_frequency;
	rcc_clock_tree.pclk1 = clock->apb1_frequency;
	rcc_clock_tree.pclk2 = clock->apb2_frequency;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Get the System Clock Source.
 *  @returns Unsigned int32. System clock source:
 *  @li 00 indicates MSIS
 *  @li 01 indicates HSI16
 *  @li 02 indicates HSE
 *  @li 03 indicates PLL
 */
uint32_t rcc_system_clock_source(void)
{
	return (RCC_CFGR & RCC_CFGR_SWS) >> RCC_CFGR_SWS_SHIFT;
}

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	while (!rcc_is_osc_ready(osc))
		continue;
}

void rcc_css_enable(void)
{
	RCC_CR |= RCC_CR_CSSON;
}

void rcc_css_disable(void)
{
	RCC_CR &= ~RCC_CR_CSSON;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Turn off an Oscillator.

Disable an oscillator and power off.

@note An oscillator cannot be turned off if it is selected as the system clock.
@note The LSE clock is in the backup domain and cannot be disabled until the
backup domain write protection has been removed (see
@ref pwr_disable_backup_domain_write_protect) or the backup domain has been
(see reset @ref rcc_backupdomain_reset).

@param[in] osc Oscillator ID
*/

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL3:
		RCC_CR &= ~RCC_CR_PLL3ON;
		break;
	case RCC_PLL2:
		RCC_CR &= ~RCC_CR_PLL2ON;
		break;
	case RCC_PLL1:
		RCC_CR &= ~RCC_CR_PLL1ON;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_SHSI:
		RCC_CR &= ~RCC_CR_SHSION;
		break;
	case RCC_HSI48:
		RCC_CR &= ~RCC_CR_HSI48ON;
		break;
	case RCC_HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case RCC_MSI:
		RCC_CR &= ~RCC_CR_MSIKON;
		break;
	//  TODO: Should we add MSIKER?
	case RCC_MSIS:
		RCC_CR &= ~RCC_CR_MSISON;
		break;
	default:
		cm3_assert_not_reached();
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Turn on an Oscillator.
 *
 * Enable an oscillator and power on. Each oscillator requires an amount of
 * time to settle to a usable state. Refer to datasheets for time delay
 * information. A status flag is available to indicate when the oscillator
 * becomes ready (see @ref rcc_osc_ready_int_flag and @ref
 * rcc_wait_for_osc_ready).
 *
 * @param osc Oscillator ID
 */

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL3:
		RCC_CR |= RCC_CR_PLL3ON;
		break;
	case RCC_PLL2:
		RCC_CR |= RCC_CR_PLL2ON;
		break;
	case RCC_PLL1:
		RCC_CR |= RCC_CR_PLL1ON;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_SHSI:
		RCC_CR |= RCC_CR_SHSION;
		break;
	case RCC_HSI48:
		RCC_CR |= RCC_CR_HSI48ON;
		break;
	case RCC_HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case RCC_MSI:
		RCC_CR |= RCC_CR_MSIKON;
		break;
	//  TODO: Should we add MSIKER?
	case RCC_MSIS:
		RCC_CR |= RCC_CR_MSISON;
		break;
	default:
		cm3_assert_not_reached();
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Returns if the oscillator is ready.
 *
 * @param osc Oscillator ID
 */
bool rcc_is_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL3:
		return RCC_CR & RCC_CR_PLL3RDY;
	case RCC_PLL2:
		return RCC_CR & RCC_CR_PLL2RDY;
	case RCC_PLL1:
		return RCC_CR & RCC_CR_PLL1RDY;
	case RCC_HSE:
		return RCC_CR & RCC_CR_HSERDY;
	case RCC_SHSI:
		return RCC_CR & RCC_CR_SHSIRDY;
	case RCC_HSI48:
		return RCC_CR & RCC_CR_HSI48RDY;
	case RCC_HSI:
		return RCC_CR & RCC_CR_HSIRDY;
	case RCC_MSI:
		return RCC_CR & RCC_CR_MSIKRDY;
	case RCC_MSIS:
		return RCC_CR & RCC_CR_MSISRDY;
	default:
		break;
	}

	return false;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the System Clock.
 *
 * @param clk Oscillator ID.
 */
void rcc_set_sysclk_source(enum rcc_osc clk)
{
	uint32_t sw = 0x0;

	switch (clk) {
	case RCC_MSIS:
		sw = RCC_CFGR_SW_MSIS;
		break;
	case RCC_HSI16:
		sw = RCC_CFGR_SW_HSI16;
		break;
	case RCC_HSE:
		sw = RCC_CFGR_SW_HSE;
		break;
	case RCC_PLL1:
		sw = RCC_CFGR_SW_PLL;
		break;
	default:
		cm3_assert_not_reached();
		break;
	}

	sw <<= RCC_CFGR_SW_SHIFT;
	RCC_CFGR = (RCC_CFGR & ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT)) | sw;
}

/**
 * @brief Set the peripheral clock source
 * @param periph peripheral of choice, eg XXX_BASE
 * @param sel periphral clock source
 */
void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t sel)
{
	volatile uint32_t *reg32;
	uint32_t shift;
	uint32_t mask;

	switch (periph) {
	case USART1_BASE:
		reg32 = &RCC_CCIPR1;
		shift = RCC_CCIPR1_USART1SEL_SHIFT;
		mask = RCC_CCIPR_USARTxSEL_MASK;
		break;
	case USART2_BASE:
		reg32 = &RCC_CCIPR1;
		shift = RCC_CCIPR1_USART2SEL_SHIFT;
		mask = RCC_CCIPR_USARTxSEL_MASK;
		break;
	case USART3_BASE:
		reg32 = &RCC_CCIPR1;
		shift = RCC_CCIPR1_USART3SEL_SHIFT;
		mask = RCC_CCIPR_USARTxSEL_MASK;
		break;
	case USART4_BASE:
		reg32 = &RCC_CCIPR1;
		shift = RCC_CCIPR1_USART4SEL_SHIFT;
		mask = RCC_CCIPR_USARTxSEL_MASK;
		break;
	case USART5_BASE:
		reg32 = &RCC_CCIPR1;
		shift = RCC_CCIPR1_USART5SEL_SHIFT;
		mask = RCC_CCIPR_USARTxSEL_MASK;
		break;
	case USART6_BASE:
		reg32 = &RCC_CCIPR2;
		shift = RCC_CCIPR2_USART6SEL_SHIFT;
		mask = RCC_CCIPR_USARTxSEL_MASK;
		break;
	case I2C1_BASE:
		reg32 = &RCC_CCIPR1;
		shift = RCC_CCIPR1_I2C1SEL_SHIFT;
		mask = RCC_CCIPR_I2CxSEL_MASK;
		break;
	case I2C2_BASE:
		reg32 = &RCC_CCIPR1;
		shift = RCC_CCIPR1_I2C2SEL_SHIFT;
		mask = RCC_CCIPR_I2CxSEL_MASK;
		break;
	case I2C3_BASE:
		reg32 = &RCC_CCIPR3;
		shift = RCC_CCIPR3_I2C3SEL_SHIFT;
		mask = RCC_CCIPR_I2CxSEL_MASK;
		break;
	case I2C4_BASE:
		reg32 = &RCC_CCIPR1;
		shift = RCC_CCIPR1_I2C4SEL_SHIFT;
		mask = RCC_CCIPR_I2CxSEL_MASK;
		break;
	case I2C5_BASE:
		reg32 = &RCC_CCIPR2;
		shift = RCC_CCIPR2_I2C5SEL_SHIFT;
		mask = RCC_CCIPR_I2CxSEL_MASK;
		break;
	case I2C6_BASE:
		reg32 = &RCC_CCIPR2;
		shift = RCC_CCIPR2_I2C6SEL_SHIFT;
		mask = RCC_CCIPR_I2CxSEL_MASK;
		break;
	default:
		cm3_assert_not_reached();
		break;
	}

	mask <<= shift;
	sel <<= shift;
	(*reg32) = ((*reg32) & ~mask) | sel;
}

static uint32_t rcc_get_usart_clksel_freq(uint32_t usart, uint8_t shift)
{
	uint8_t clksel;
	if (usart == USART6_BASE) {
		clksel = (RCC_CCIPR2 >> shift) & RCC_CCIPR_USARTxSEL_MASK;
	} else {
		clksel = (RCC_CCIPR1 >> shift) & RCC_CCIPR_USARTxSEL_MASK;
	}

	switch (clksel) {
	case RCC_CCIPR_USARTxSEL_PCLKx:
		if (usart == USART1_BASE) {
			return rcc_clock_tree.pclk2;
		}
		return rcc_clock_tree.pclk1;
	case RCC_CCIPR_USARTxSEL_SYSCLK:
		return rcc_clock_tree.hclk;
	case RCC_CCIPR_USARTxSEL_HSI16:
		return RCC_DEFAULT_HSI16_FREQUENCY;
	case RCC_CCIPR_USARTxSEL_LSE:
		return RCC_DEFAULT_LSE_FREQUENCY;
	default:
		cm3_assert_not_reached();
		break;
	}
	return 0;
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the USART at base specified.
 * @param usart  Base address of USART to get clock frequency for.
 */
uint32_t rcc_get_usart_clk_freq(uint32_t usart)
{
	switch (usart) {
	case USART1_BASE:
		return rcc_get_usart_clksel_freq(usart, RCC_CCIPR1_USART1SEL_SHIFT);
	case USART2_BASE:
		return rcc_get_usart_clksel_freq(usart, RCC_CCIPR1_USART2SEL_SHIFT);
	case USART3_BASE:
		return rcc_get_usart_clksel_freq(usart, RCC_CCIPR1_USART3SEL_SHIFT);
	case USART4_BASE:
		return rcc_get_usart_clksel_freq(usart, RCC_CCIPR1_USART4SEL_SHIFT);
	case USART5_BASE:
		return rcc_get_usart_clksel_freq(usart, RCC_CCIPR1_USART5SEL_SHIFT);
	case USART6_BASE:
		return rcc_get_usart_clksel_freq(usart, RCC_CCIPR2_USART6SEL_SHIFT);
	default:
		break;
	}
	cm3_assert_not_reached();
	return 0;
}

/**@}*/
