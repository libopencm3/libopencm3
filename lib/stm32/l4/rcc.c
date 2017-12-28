/** @defgroup rcc_file RCC
 *
 * @ingroup STM32L4xx
 *
 * @section rcc_l4_api_ex Reset and Clock Control API.
 *
 * @brief <b>libopencm3 STM32L4xx Reset and Clock Control</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Karl Palsson <karlp@tweak.net.au>
 *
 * @date 12 Feb 2016
 *
 * This library supports the Reset and Clock Control System in the STM32 series
 * of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Karl Palsson <karlp@tweak.net.au>
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
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/pwr.h>

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency = 4000000;
uint32_t rcc_apb1_frequency = 4000000;
uint32_t rcc_apb2_frequency = 4000000;

const struct rcc_clock_scale rcc_clock_config[] = {
	{ /* 80MHz PLL from HSI */
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI16,
		.pllm = 1,
		.plln = 10,
		.pllp = RCC_PLLCFGR_PLLP_DIV7,
		.pllq = RCC_PLLCFGR_PLLQ_DIV4,
		.pllr = RCC_PLLCFGR_PLLR_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_DIV2,
		.ppre2 = RCC_CFGR_PPRE2_DIV2,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 4,
		.ahb_frequency = 80000000,
		.apb1_frequency = 40000000,
		.apb2_frequency = 40000000
	},
	{ /* 80MHz PLL from 24MHz HSE */
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.pllm = 3,
		.plln = 20,
		.pllp = RCC_PLLCFGR_PLLP_DIV7,
		.pllq = RCC_PLLCFGR_PLLQ_DIV4,
		.pllr = RCC_PLLCFGR_PLLR_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_DIV2,
		.ppre2 = RCC_CFGR_PPRE2_DIV2,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 4,
		.ahb_frequency = 80000000,
		.apb1_frequency = 40000000,
		.apb2_frequency = 40000000
	},
	{ /* 72MHz PLL and 48MHz USB from 24MHz HSE */
		.pll_source = RCC_PLLCFGR_PLLSRC_HSE,
		.pllm = 2,
		.plln = 24,
		.pllp = RCC_PLLCFGR_PLLP_DIV7,
		.pllq = RCC_PLLCFGR_PLLQ_DIV6,
		.pllr = RCC_PLLCFGR_PLLR_DIV4,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_DIV2,
		.ppre2 = RCC_CFGR_PPRE2_DIV2,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 4,
		.ahb_frequency = 72000000,
		.apb1_frequency = 36000000,
		.apb2_frequency = 36000000
	}
};

void rcc_osc_ready_int_clear(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CICR |= RCC_CICR_PLLRDYC;
		break;
	case RCC_HSE:
		RCC_CICR |= RCC_CICR_HSERDYC;
		break;
	case RCC_HSI16:
		RCC_CICR |= RCC_CICR_HSIRDYC;
		break;
	case RCC_MSI:
		RCC_CICR |= RCC_CICR_MSIRDYC;
		break;
	case RCC_LSE:
		RCC_CICR |= RCC_CICR_LSERDYC;
		break;
	case RCC_LSI:
		RCC_CICR |= RCC_CICR_LSIRDYC;
		break;
	case RCC_HSI48:
		RCC_CICR |= RCC_CICR_HSI48RDYC;
		break;
	}
}

void rcc_osc_ready_int_enable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIER |= RCC_CIER_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIER |= RCC_CIER_HSERDYIE;
		break;
	case RCC_HSI16:
		RCC_CIER |= RCC_CIER_HSIRDYIE;
		break;
	case RCC_MSI:
		RCC_CIER |= RCC_CIER_MSIRDYIE;
		break;
	case RCC_LSE:
		RCC_CIER |= RCC_CIER_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIER |= RCC_CIER_LSIRDYIE;
		break;
	case RCC_HSI48:
		RCC_CIER |= RCC_CIER_HSI48RDYIE;
		break;
	}
}

void rcc_osc_ready_int_disable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIER &= ~RCC_CIER_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIER &= ~RCC_CIER_HSERDYIE;
		break;
	case RCC_HSI16:
		RCC_CIER &= ~RCC_CIER_HSIRDYIE;
		break;
	case RCC_MSI:
		RCC_CIER &= ~RCC_CIER_MSIRDYIE;
		break;
	case RCC_LSE:
		RCC_CIER &= ~RCC_CIER_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIER &= ~RCC_CIER_LSIRDYIE;
		break;
	case RCC_HSI48:
		RCC_CIER &= ~RCC_CIER_HSI48RDYIE;
		break;
	}
}

int rcc_osc_ready_int_flag(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return ((RCC_CIFR & RCC_CIFR_PLLRDYF) != 0);
		break;
	case RCC_HSE:
		return ((RCC_CIFR & RCC_CIFR_HSERDYF) != 0);
		break;
	case RCC_HSI16:
		return ((RCC_CIFR & RCC_CIFR_HSIRDYF) != 0);
		break;
	case RCC_MSI:
		return ((RCC_CIFR & RCC_CIFR_MSIRDYF) != 0);
		break;
	case RCC_LSE:
		return ((RCC_CIFR & RCC_CIFR_LSERDYF) != 0);
		break;
	case RCC_LSI:
		return ((RCC_CIFR & RCC_CIFR_LSIRDYF) != 0);
		break;
	case RCC_HSI48:
		return ((RCC_CIFR & RCC_CIFR_HSI48RDYF) != 0);
		break;
	}
	return false;

}

void rcc_css_int_clear(void)
{
	RCC_CICR |= RCC_CICR_CSSC;
}

int rcc_css_int_flag(void)
{
	return ((RCC_CIFR & RCC_CIFR_CSSF) != 0);
}

bool rcc_is_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return RCC_CR & RCC_CR_PLLRDY;
	case RCC_HSE:
		return RCC_CR & RCC_CR_HSERDY;
	case RCC_HSI16:
		return RCC_CR & RCC_CR_HSIRDY;
	case RCC_MSI:
		return RCC_CR & RCC_CR_MSIRDY;
	case RCC_LSE:
		return RCC_BDCR & RCC_BDCR_LSERDY;
	case RCC_LSI:
		return RCC_CSR & RCC_CSR_LSIRDY;
	case RCC_HSI48:
		return RCC_CRRCR & RCC_CRRCR_HSI48RDY;
	}
	return false;
}

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	while (!rcc_is_osc_ready(osc));
}

void rcc_wait_for_sysclk_status(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK)
			!= RCC_CFGR_SWS_PLL);
		break;
	case RCC_HSE:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK)
			!= RCC_CFGR_SWS_HSE);
		break;
	case RCC_HSI16:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK)
			!= RCC_CFGR_SWS_HSI16);
		break;
	case RCC_MSI:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK)
			!= RCC_CFGR_SWS_MSI);
		break;
	default:
		/* Shouldn't be reached. */
		break;
	}
}

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_HSI16:
		RCC_CR |= RCC_CR_HSION;
		break;
	case RCC_MSI:
		RCC_CR |= RCC_CR_MSION;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	case RCC_HSI48:
		RCC_CRRCR |= RCC_CRRCR_HSI48ON;
		break;
	}
}

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_HSI16:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case RCC_MSI:
		RCC_CR &= ~RCC_CR_MSION;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	case RCC_HSI48:
		RCC_CRRCR &= ~RCC_CRRCR_HSI48ON;
		break;
	}
}

void rcc_css_enable(void)
{
	RCC_CR |= RCC_CR_CSSON;
}

void rcc_css_disable(void)
{
	RCC_CR &= ~RCC_CR_CSSON;
}

void rcc_set_sysclk_source(uint32_t clk)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT);
	RCC_CFGR = (reg32 | (clk << RCC_CFGR_SW_SHIFT));
}

void rcc_set_pll_source(uint32_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_PLLCFGR;
	reg32 &= ~(RCC_PLLCFGR_PLLSRC_MASK << RCC_PLLCFGR_PLLSRC_SHIFT);
	RCC_PLLCFGR = (reg32 | (pllsrc << RCC_PLLCFGR_PLLSRC_SHIFT));
}

void rcc_set_ppre2(uint32_t ppre2)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE2_MASK << RCC_CFGR_PPRE2_SHIFT);
	RCC_CFGR = (reg32 | (ppre2 << RCC_CFGR_PPRE2_SHIFT));
}

void rcc_set_ppre1(uint32_t ppre1)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE1_MASK << RCC_CFGR_PPRE1_SHIFT);
	RCC_CFGR = (reg32 | (ppre1 << RCC_CFGR_PPRE1_SHIFT));
}

void rcc_set_hpre(uint32_t hpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_SHIFT);
	RCC_CFGR = (reg32 | (hpre << RCC_CFGR_HPRE_SHIFT));
}

void rcc_set_main_pll(uint32_t source, uint32_t pllm, uint32_t plln, uint32_t pllp,
	uint32_t pllq, uint32_t pllr)
{
	RCC_PLLCFGR = (RCC_PLLCFGR_PLLM(pllm) << RCC_PLLCFGR_PLLM_SHIFT) |
		(plln << RCC_PLLCFGR_PLLN_SHIFT) |
		(pllp) |
		(source << RCC_PLLCFGR_PLLSRC_SHIFT) |
		(pllq << RCC_PLLCFGR_PLLQ_SHIFT) |
		(pllr << RCC_PLLCFGR_PLLR_SHIFT) | RCC_PLLCFGR_PLLREN;
}

uint32_t rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return (RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK;
}

/**
 * Set the msi run time range.
 * Can only be called when MSI is either OFF, or when MSI is on _and_
 * ready. (RCC_CR_MSIRDY bit).  @sa rcc_set_msi_range_standby
 * @param msi_range range number @ref rcc_cr_msirange
 */
void rcc_set_msi_range(uint32_t msi_range)
{
	uint32_t reg = RCC_CR;
	reg &= ~(RCC_CR_MSIRANGE_MASK << RCC_CR_MSIRANGE_SHIFT);
	reg |= msi_range << RCC_CR_MSIRANGE_SHIFT;
	RCC_CR = reg | RCC_CR_MSIRGSEL;
}

/**
 * Set the msi range after reset/standby.
 * Until MSIRGSEl bit is set, this defines the MSI range.
 * Note that not all MSI range values are allowed here!
 * @sa rcc_set_msi_range
 * @param msi_range range number valid for post standby @ref rcc_csr_msirange
 */
void rcc_set_msi_range_standby(uint32_t msi_range)
{
	uint32_t reg = RCC_CSR;
	reg &= ~(RCC_CSR_MSIRANGE_MASK << RCC_CSR_MSIRANGE_SHIFT);
	reg |= msi_range << RCC_CSR_MSIRANGE_SHIFT;
	RCC_CSR = reg;
}

/** Enable PLL Output
 *
 *	- P (RCC_PLLCFGR_PLLPEN)
 *	- Q (RCC_PLLCFGR_PLLQEN)
 *	- R (RCC_PLLCFGR_PLLREN)
 *
 * @param pllout One or more of the definitions above
 */
void rcc_pll_output_enable(uint32_t pllout)
{
	RCC_PLLCFGR |= pllout;
}

/** Set clock source for 48MHz clock
 *
 * The 48 MHz clock is derived from one of the four following sources:
 *	- main PLL VCO (RCC_CCIPR_CLK48SEL_PLL)
 *	- PLLSAI1 VCO (RCC_CCIPR_CLK48SEL_PLLSAI1Q)
 *	- MSI clock (RCC_CCIPR_CLK48SEL_MSI)
 *	- HSI48 internal oscillator (RCC_CCIPR_CLK48SEL_HSI48)
 *
 * @param clksel One of the definitions above
 */
void rcc_set_clock48_source(uint32_t clksel)
{
	RCC_CCIPR &= ~(RCC_CCIPR_CLK48SEL_MASK << RCC_CCIPR_CLK48SEL_SHIFT);
	RCC_CCIPR |= (clksel << RCC_CCIPR_CLK48SEL_SHIFT);
}

void rcc_clock_setup_hsi16(void)
{
	/* Enable internal high-speed oscillator */
	rcc_osc_on(RCC_HSI16);
	rcc_wait_for_osc_ready(RCC_HSI16);

	/* Select HSI as SYSCLK source */
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI16);

	/* Enable high performance mode */
	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(PWR_SCALE1);

	/* Set prescalers for AHB, ABP1, ABP2 */
	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);
	rcc_set_ppre1(RCC_CFGR_PPRE1_NODIV);
	rcc_set_ppre2(RCC_CFGR_PPRE2_NODIV);

	/* Configure flash wait states */
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = 16000000;
	rcc_apb1_frequency = 16000000;
	rcc_apb2_frequency = 16000000;
}

void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{
	/* Enable selected high-speed oscillator */
	if (clock->pll_source == RCC_PLLCFGR_PLLSRC_HSE) {
		rcc_osc_on(RCC_HSE);
		rcc_wait_for_osc_ready(RCC_HSE);
	} else if (clock->pll_source == RCC_PLLCFGR_PLLSRC_HSI16) {
		rcc_osc_on(RCC_HSI16);
		rcc_wait_for_osc_ready(RCC_HSI16);
	}

	/* Set performance mode */
	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(clock->voltage_scale);

	/* Set prescalers for AHB, ABP1, ABP2 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	/* Configure PLL */
	rcc_set_main_pll(clock->pll_source, clock->pllm, clock->plln,
			 clock->pllp, clock->pllq, clock->pllr);

	/* Enable PLL and wait for it to stabilize */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Configure flash wait states */
	flash_set_ws(clock->flash_waitstates);

	/* Select PLL as SYSCLK source and wait for it to be selected */
	rcc_set_sysclk_source(RCC_CFGR_SW_PLL);
	rcc_wait_for_sysclk_status(RCC_PLL);

	/* Set the peripheral clock frequencies used */
	rcc_ahb_frequency = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}

/**@}*/
