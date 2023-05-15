/** @defgroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@brief <b>libopencm3 AT32F40x Reset and Clock Control</b>

@version 1.0.0

This library supports the Reset and Clock Control System in the AT32F40x
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

/** Set the default clock frequencies */
uint32_t rcc_apb1_frequency = 8000000;
uint32_t rcc_apb2_frequency = 8000000;
uint32_t rcc_ahb_frequency = 8000000;

const struct rcc_clock_scale rcc_hse_configs[RCC_CLOCK_HSE_END] = {
	{	/* 8->72 MHz */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL9,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.ahb_frequency = 72000000,
		.apb1_frequency = 72000000,
		.apb2_frequency = 72000000,
	},
	{	/* 8->96 MHz */
		.pll_mul = RCC_CFGR_PLLRANGE_HIGH | RCC_CFGR_PLLMUL_PLL_CLK_MUL12,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.ahb_frequency	= 96000000,
		.apb1_frequency = 96000000,
		.apb2_frequency = 96000000,
	},
	{	/* 8->168 MHz */
		.pll_mul = RCC_CFGR_PLLRANGE_HIGH | RCC_CFGR_PLLMUL_PLL_CLK_MUL21,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.ahb_frequency	= 168000000,
		.apb1_frequency = 84000000,
		.apb2_frequency = 84000000,
	},
	{	/* 8->192 MHz */
		.pll_mul = RCC_CFGR_PLLRANGE_HIGH | RCC_CFGR_PLLMUL_PLL_CLK_MUL24,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.ahb_frequency	= 192000000,
		.apb1_frequency = 96000000,
		.apb2_frequency = 96000000,
	},
	{	/* 8->240 MHz */
		.pll_mul = RCC_CFGR_PLLRANGE_HIGH | RCC_CFGR_PLLMUL_PLL_CLK_MUL30,
		.pll_source = RCC_CFGR_PLLSRC_HSE_CLK,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.adcpre = RCC_CFGR_ADCPRE_DIV6,
		.ahb_frequency	= 240000000,
		.apb1_frequency = 120000000,
		.apb2_frequency = 120000000,
	}
};

const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END] = {
	{	/* 4->72 MHz */
		.pll_mul = RCC_CFGR_PLLMUL_PLL_CLK_MUL18,
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.ahb_frequency = 72000000,
		.apb1_frequency = 72000000,
		.apb2_frequency = 72000000,
	},
	{	/* 4->96 MHz */
		.pll_mul = RCC_CFGR_PLLRANGE_HIGH | RCC_CFGR_PLLMUL_PLL_CLK_MUL24,
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.ahb_frequency	= 96000000,
		.apb1_frequency = 96000000,
		.apb2_frequency = 96000000,
	},
	{	/* 4->168 MHz */
		.pll_mul = RCC_CFGR_PLLRANGE_HIGH | RCC_CFGR_PLLMUL_PLL_CLK_MUL42,
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_DIV2,
		.adcpre = RCC_CFGR_ADCPRE_DIV4,
		.ahb_frequency	= 168000000,
		.apb1_frequency = 84000000,
		.apb2_frequency = 84000000,
	}
};

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll_multiplication_factor(uint32_t mul)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLMUL) |
		((mul & 0x70) << (RCC_CFGR_PLLMULHI_SHIFT - 4)) |
		((mul & 0x0f) << RCC_CFGR_PLLMUL_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the HSE Frequency Divider used as PLL Clock Source.

@param[in] prediv HSE prescale factor @ref rcc_cfgr5_hse_div
*/

void rcc_set_hse_prediv(uint32_t prediv)
{
	RCC_CFGR5 = (RCC_CFGR5 & ~RCC_CFGR5_HSE_DIV) |
		(prediv << RCC_CFGR5_HSE_DIV_SHIFT);
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

	rcc_set_pll_multiplication_factor(clock->pll_mul);
	rcc_set_pll_source(clock->pll_source);

	/* xtpre selects HSE divisor, which may be,
	 * depending on part, fixed /2 or programmable
	 */
	rcc_set_hse_xtpre(clock->hse_xtpre);
	if (clock->hse_xtpre && clock->hse_prediv > RCC_CFGR5_HSE_DIV2) {
		rcc_set_hse_prediv(clock->hse_prediv);
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
/** @brief Select alternate USBFS packet buffer
*/

void rcc_usb_alt_pma_enable(void)
{
	RCC_CFGR3 |= RCC_CFGR3_USBBUFSZ;
}

/*---------------------------------------------------------------------------*/
/** @brief Select primary USBFS packet buffer
*/

void rcc_usb_alt_pma_disable(void)
{
	RCC_CFGR3 &= ~RCC_CFGR3_USBBUFSZ;
}

/*---------------------------------------------------------------------------*/
/** @brief Select alternate USBFS interrupt vector
*/

void rcc_usb_alt_isr_enable(void)
{
	RCC_CFGR6 |= RCC_CFGR6_USBFS_INTMAP;
}

/** @brief Select primary USBFS interrupt vectors
*/

void rcc_usb_alt_isr_disable(void)
{
	RCC_CFGR6 &= ~RCC_CFGR6_USBFS_INTMAP;
}

/**@}*/
