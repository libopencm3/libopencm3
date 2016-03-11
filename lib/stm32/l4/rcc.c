/** @defgroup rcc_file RCC
 *
 * @ingroup STM32L4xx
 *
 * @section rcc_f4_api_ex Reset and Clock Control API.
 *
 * @brief <b>libopencm3 STM32L4xx Reset and Clock Control</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran at seznam.cz>
 * @author @htmlonly &copy; @endhtmlonly 2016 Benjamin Levine <benjaminmileslevine@gmail.com>
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
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2016 Benjamin Levine <benjaminmileslevine@gmail.com>
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
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/flash.h>

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency = 16000000;
uint32_t rcc_apb1_frequency = 16000000;
uint32_t rcc_apb2_frequency = 16000000;

const struct rcc_clock_scale rcc_clock_config[RCC_CLOCK_CONFIG_END] = {
	{ /* 48MHz PLL from HSI */
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI16,
		.pllm = 4, /* Input to PLL must be between 4MHz and 16MHz */
		.plln = 24,
		.pllp = RCC_PLLCFGR_PLLP_DIV7,
		.pllq = RCC_PLLCFGR_PLLQ_DIV2,
		.pllr = RCC_PLLCFGR_PLLR_DIV2,
		.hpre = RCC_CFGR_HPRE_DIV2,
		.ppre1 = RCC_CFGR_PPRE1_NODIV,
		.ppre2 = RCC_CFGR_PPRE2_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_config = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_2WS,
		.apb1_frequency = 24000000,
		.apb2_frequency = 24000000,
		.msi_range = RCC_CSR_MSIRANGE_RANGE_4MHz
	},
	{ /* 80MHz PLL from HSI */
		.pll_source = RCC_PLLCFGR_PLLSRC_HSI16,
		.pllm = 4,
		.plln = 40,
		.pllp = RCC_PLLCFGR_PLLP_DIV7,
		.pllq = RCC_PLLCFGR_PLLQ_DIV4,
		.pllr = RCC_PLLCFGR_PLLR_DIV2,
		.hpre = RCC_CFGR_HPRE_DIV4,
		.ppre1 = RCC_CFGR_PPRE1_NODIV,
		.ppre2 = RCC_CFGR_PPRE2_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_config = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_2WS,
		.apb1_frequency = 20000000,
		.apb2_frequency = 20000000,
		.msi_range = RCC_CSR_MSIRANGE_RANGE_4MHz
	},
	{ /* 16MHz HSI raw */
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE1_NODIV,
		.ppre2 = RCC_CFGR_PPRE2_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_config = FLASH_ACR_LATENCY_0WS,
		.apb1_frequency = 16000000,
		.apb2_frequency = 16000000,
		.msi_range = RCC_CSR_MSIRANGE_RANGE_4MHz
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
	}

	cm3_assert_not_reached();
}

void rcc_css_int_clear(void)
{
	RCC_CICR |= RCC_CICR_CSSC;
}

int rcc_css_int_flag(void)
{
	return ((RCC_CIFR & RCC_CIFR_CSSF) != 0);
}

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		while ((RCC_CR & RCC_CR_PLLRDY) == 0);
		break;
	case RCC_HSE:
		while ((RCC_CR & RCC_CR_HSERDY) == 0);
		break;
	case RCC_HSI16:
		while ((RCC_CR & RCC_CR_HSIRDY) == 0);
		break;
	case RCC_MSI:
		while ((RCC_CR & RCC_CR_MSIRDY) == 0);
		break;
	case RCC_LSE:
		while ((RCC_BDCR & RCC_BDCR_LSERDY) == 0);
		break;
	case RCC_LSI:
		while ((RCC_CSR & RCC_CSR_LSIRDY) == 0);
		break;
	}
}

void rcc_wait_for_sysclk_status(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_MSI:
		while ((RCC_CFGR & (RCC_CFGR_SWS_MASK << RCC_CFGR_SWS_SHIFT)) != (RCC_CFGR_SWS_MSI << RCC_CFGR_SWS_SHIFT));
		break;
	case RCC_PLL:
		while ((RCC_CFGR & (RCC_CFGR_SWS_MASK << RCC_CFGR_SWS_SHIFT)) != (RCC_CFGR_SWS_PLL << RCC_CFGR_SWS_SHIFT));
		break;
	case RCC_HSE:
		while ((RCC_CFGR & (RCC_CFGR_SWS_MASK << RCC_CFGR_SWS_SHIFT)) != (RCC_CFGR_SWS_HSE << RCC_CFGR_SWS_SHIFT));
		break;
	case RCC_HSI16:
		while ((RCC_CFGR & (RCC_CFGR_SWS_MASK << RCC_CFGR_SWS_SHIFT)) != (RCC_CFGR_SWS_HSI16 << RCC_CFGR_SWS_SHIFT));
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

void rcc_osc_bypass_enable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEBYP;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEBYP;
		break;
	case RCC_PLL:
	case RCC_HSI16:
	case RCC_MSI:
	case RCC_LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

void rcc_osc_bypass_disable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEBYP;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEBYP;
		break;
	case RCC_PLL:
	case RCC_HSI16:
	case RCC_MSI:
	case RCC_LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

void rcc_set_sysclk_source(uint8_t clk)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT);
	RCC_CFGR = (reg32 | (clk << RCC_CFGR_SW_SHIFT));
}

void rcc_set_pll_source(uint8_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_PLLCFGR;
	reg32 &= ~(RCC_PLLCFGR_PLLSRC_MASK << RCC_PLLCFGR_PLLSRC_SHIFT);
	RCC_PLLCFGR = (reg32 | (pllsrc << RCC_PLLCFGR_PLLSRC_SHIFT));
}

void rcc_set_ppre2(uint8_t ppre2)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE2_MASK << RCC_CFGR_PPRE2_SHIFT);
	RCC_CFGR = (reg32 | (ppre2 << RCC_CFGR_PPRE2_SHIFT));
}

void rcc_set_ppre1(uint8_t ppre1)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE1_MASK << RCC_CFGR_PPRE1_SHIFT);
	RCC_CFGR = (reg32 | (ppre1 << RCC_CFGR_PPRE1_SHIFT));
}

void rcc_set_hpre(uint8_t hpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_SHIFT);
	RCC_CFGR = (reg32 | (hpre << RCC_CFGR_HPRE_SHIFT));
}

void rcc_set_main_pll(uint8_t source, uint8_t pllm, uint8_t plln, uint8_t pllp,
			  uint8_t pllq, uint8_t pllr)
{
	RCC_PLLCFGR = (pllm << RCC_PLLCFGR_PLLM_SHIFT) |
		(plln << RCC_PLLCFGR_PLLN_SHIFT) |
		(pllp << RCC_PLLCFGR_PLLP_SHIFT) |
		(source << RCC_PLLCFGR_PLLSRC_SHIFT) |
		(pllq << RCC_PLLCFGR_PLLQ_SHIFT) |
		(pllr << RCC_PLLCFGR_PLLR_SHIFT) | RCC_PLLCFGR_PLLREN;
}

uint8_t rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return RCC_CFGR_SWS_MASK & ((RCC_CFGR & (RCC_CFGR_SWS_MASK << RCC_CFGR_SWS_SHIFT)) >> RCC_CFGR_SWS_SHIFT);
}

void rcc_set_msi_range(uint8_t msi_range)
{
	uint32_t reg32;

	reg32 = RCC_CSR;
	reg32 &= ~(RCC_CSR_MSIRANGE_MASK << RCC_CSR_MSIRANGE_SHIFT);
	RCC_CSR = (reg32 | (msi_range << RCC_CSR_MSIRANGE_SHIFT));
}

void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI16);
	rcc_wait_for_osc_ready(RCC_HSI16);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI16);

	/* Wait for HSI16 clock to be selected. */
	rcc_wait_for_sysclk_status(RCC_HSI16);

	/* Enable/disable high performance mode */
	pwr_set_vos_range(clock->voltage_scale);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_set_main_pll(clock->pll_source, clock->pllm, clock->plln,
			clock->pllp, clock->pllq, clock->pllr);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Configure flash settings. */
	flash_set_ws(clock->flash_config);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_PLL);

	/* Wait for PLL clock to be selected. */
	rcc_wait_for_sysclk_status(RCC_PLL);

	/* Set the peripheral clock frequencies used. */
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;

	rcc_set_msi_range(clock->msi_range);
}

void rcc_clock_setup_hsi16(const struct rcc_clock_scale *clock)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI16);
	rcc_wait_for_osc_ready(RCC_HSI16);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI16);

	/* Enable/disable high performance mode */
	pwr_set_vos_range(clock->voltage_scale);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);


	/* Configure flash settings. */
	flash_set_ws(clock->flash_config);

	/* Set the peripheral clock frequencies used. */
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;

	rcc_set_msi_range(clock->msi_range);
}

/**@}*/
