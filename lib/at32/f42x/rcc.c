/** @defgroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@brief <b>libopencm3 AT32F42x Reset and Clock Control</b>

@version 1.0.0

This library supports the Reset and Clock Control System in the AT32F42x
series of ARM Cortex Microcontrollers by Arterytek.

Clock settings and resets for many peripherals are given here rather than in
the corresponding peripheral library.

The library also provides a number of common configurations for the processor
system clock. Not all possible configurations are included.
 */
/*
 * This file is part of the libopencm3 project.
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

/** Set the default clock frequencies */
uint32_t rcc_apb1_frequency = 8000000;
uint32_t rcc_apb2_frequency = 8000000;
uint32_t rcc_ahb_frequency = 8000000;

const struct rcc_clock_scale rcc_hse_configs[RCC_CLOCK_HSE_END] = {
	{	/* 8->48 MHz */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL6,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV2,
		.flash_waitstates = FLASH_ACR_LATENCY_032_064MHZ,
		.ahb_frequency = 48000000,
		.apb1_frequency = 48000000,
		.apb2_frequency = 48000000,
	},
	{	/* 8->72 MHz */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL9,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.flash_waitstates = FLASH_ACR_LATENCY_064_096MHZ,
		.ahb_frequency = 72000000,
		.apb1_frequency = 72000000,
		.apb2_frequency = 72000000,
	},
	{	/* 8->96 MHz */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL12,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.flash_waitstates = FLASH_ACR_LATENCY_064_096MHZ,
		.ahb_frequency	= 96000000,
		.apb1_frequency = 96000000,
		.apb2_frequency = 96000000,
	},
	{	/* 8->120 MHz */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL15,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV6,
		.flash_waitstates = FLASH_ACR_LATENCY_096_120MHZ,
		.ahb_frequency	= 120000000,
		.apb1_frequency = 120000000,
		.apb2_frequency = 120000000,
	}
};

const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END] = {
	{	/* 4->48 MHz */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL12,
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV2,
		.flash_waitstates = FLASH_ACR_LATENCY_032_064MHZ,
		.ahb_frequency = 48000000,
		.apb1_frequency = 48000000,
		.apb2_frequency = 48000000,
	},
	{	/* 4->72 MHz */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL18,
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.flash_waitstates = FLASH_ACR_LATENCY_064_096MHZ,
		.ahb_frequency = 72000000,
		.apb1_frequency = 72000000,
		.apb2_frequency = 72000000,
	},
	{	/* 4->96 MHz */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL24,
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.flash_waitstates = FLASH_ACR_LATENCY_064_096MHZ,
		.ahb_frequency	= 96000000,
		.apb1_frequency = 96000000,
		.apb2_frequency = 96000000,
	}
};

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL input frequency range.

@note This only has effect when the PLL is disabled.

@param[in] range PLL input frequency range @ref rcc_pllcfgr_range
*/

void rcc_set_pll_input_range(uint32_t range)
{
	RCC_PLLCFGR = (RCC_PLLCFGR & ~(RCC_PLLCFGR_PLLEN |
				       RCC_PLLCFGR_RANGE_MASK)) |
		(range << RCC_PLLCFGR_RANGE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Setup the PLL in integer mode.

@note This only has effect when the PLL is disabled.

@param[in] range PLL input frequency range @ref rcc_pllcfgr_range
@param[in] mul PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll_int(uint32_t range, uint32_t mul)
{
	rcc_set_pll_input_range(range);
	rcc_set_pll_multiplication_factor(mul);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Setup the PLL in fractional mode.

@note This only has effect when the PLL is disabled.

@param pllm Divider for the PLL input clock
@param plln PLL multiplication factor for VCO
@param pllp PLL post divider for main system clock
*/

void rcc_set_pll_fraq(uint32_t pllm, uint32_t plln, uint32_t pllp)
{
	pllp = 0x7 & (31 - __builtin_clz(pllp));
	RCC_PLLCFGR = (RCC_CFGR & ~(RCC_PLLCFGR_PLLM_MASK |
				    RCC_PLLCFGR_PLLN_MASK |
				    RCC_PLLCFGR_PLLP_MASK)) |
		RCC_PLLCFGR_PLLEN |
                (pllm << RCC_PLLCFGR_PLLM_SHIFT) |
                (plln << RCC_PLLCFGR_PLLN_SHIFT) |
                (pllp << RCC_PLLCFGR_PLLP_SHIFT);
}

/*---------------------------------------------------------------------------*/
/**
 * Setup clocks to run from PLL.
 * The arguments provide the pll source, multipliers, dividers, all that's
 * needed to establish a system clock.
 * @param clock clock information structure
 */
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
	flash_set_ws(clock->flash_waitstates);

	if (clock->pll_mode) {
		rcc_set_pll_fraq(clock->pllm, clock->plln, clock->pllp);
	} else {
		rcc_set_pll_int(clock->pll_range, clock->pll_mul);
	}

	rcc_set_pll_source(clock->pll_source);
	rcc_set_hse_xtpre(clock->hse_xtpre);

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

/**@}*/
