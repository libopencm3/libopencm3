/** @defgroup STM32L0xx-rcc-file RCC
 *
 * @ingroup STM32L0xx
 *
 * @brief <b>libopencm3 STM32L0xx Reset and Clock Control</b>
 *
 * @version 1.0.0
 *
 * @date November 2014
 *
 * This library supports the Reset and Clock Control System in the STM32F0xx
 * series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Karl Palsson <karlp@tweak.net.au>
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
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency = 2097000;
uint32_t rcc_apb1_frequency = 2097000;
uint32_t rcc_apb2_frequency = 2097000;

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case RCC_MSI:
		RCC_CR |= RCC_CR_MSION;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_HSI48:
		RCC_CRRCR |= RCC_CRRCR_HSI48ON;
		break;
	case RCC_HSI16:
		RCC_CR |= RCC_CR_HSI16ON;
		break;
	case RCC_LSE:
		RCC_CSR |= RCC_CSR_LSEON;
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
	case RCC_MSI:
		RCC_CR &= ~RCC_CR_MSION;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_HSI48:
		RCC_CRRCR &= ~RCC_CRRCR_HSI48ON;
		break;
	case RCC_HSI16:
		RCC_CR &= ~RCC_CR_HSI16ON;
		break;
	case RCC_LSE:
		RCC_CSR &= ~RCC_CSR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	}
}


/*---------------------------------------------------------------------------*/
/** @brief RCC Clear the Oscillator Ready Interrupt Flag
 *
 * Clear the interrupt flag that was set when a clock oscillator became ready
 * to use.
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */
void rcc_osc_ready_int_clear(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CICR |= RCC_CICR_PLLRDYC;
		break;
	case RCC_HSE:
		RCC_CICR |= RCC_CICR_HSERDYC;
		break;
	case RCC_HSI48:
		RCC_CICR |= RCC_CICR_HSI48RDYC;
		break;
	case RCC_HSI16:
		RCC_CICR |= RCC_CICR_HSI16RDYC;
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

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable the Oscillator Ready Interrupt
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */
void rcc_osc_ready_int_enable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIER |= RCC_CIER_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIER |= RCC_CIER_HSERDYIE;
		break;
	case RCC_HSI48:
		RCC_CIER |= RCC_CIER_HSI48RDYIE;
		break;
	case RCC_HSI16:
		RCC_CIER |= RCC_CIER_HSI16RDYIE;
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

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable the Oscillator Ready Interrupt
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */
void rcc_osc_ready_int_disable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIER &= ~RCC_CIER_PLLRDYIE;
		break;
	case RCC_HSE:
		RCC_CIER &= ~RCC_CIER_HSERDYIE;
		break;
	case RCC_HSI48:
		RCC_CIER &= ~RCC_CIER_HSI48RDYIE;
		break;
	case RCC_HSI16:
		RCC_CIER &= ~RCC_CIER_HSI16RDYIE;
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

/*---------------------------------------------------------------------------*/
/** @brief RCC Read the Oscillator Ready Interrupt Flag
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 * @returns int. Boolean value for flag set.
 */
int rcc_osc_ready_int_flag(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return ((RCC_CIFR & RCC_CIFR_PLLRDYF) != 0);
		break;
	case RCC_HSE:
		return ((RCC_CIFR & RCC_CIFR_HSERDYF) != 0);
		break;
	case RCC_HSI48:
		return ((RCC_CIFR & RCC_CIFR_HSI48RDYF) != 0);
		break;
	case RCC_HSI16:
		return ((RCC_CIFR & RCC_CIFR_HSI16RDYF) != 0);
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


bool rcc_is_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return RCC_CR & RCC_CR_PLLRDY;
	case RCC_HSE:
		return RCC_CR & RCC_CR_HSERDY;
	case RCC_HSI16:
		return RCC_CR & RCC_CR_HSI16RDY;
	case RCC_HSI48:
		return RCC_CRRCR & RCC_CRRCR_HSI48RDY;
	case RCC_MSI:
		return RCC_CR & RCC_CR_MSIRDY;
	case RCC_LSE:
		return RCC_CSR & RCC_CSR_LSERDY;
	case RCC_LSI:
		return RCC_CSR & RCC_CSR_LSIRDY;
	}
	return false;
}

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	while (!rcc_is_osc_ready(osc));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set HSI48 clock source to the RC48 (CRS)
 */
void rcc_set_hsi48_source_rc48(void)
{
	RCC_CCIPR |= RCC_CCIPR_HSI48SEL;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set HSI48 clock source to the PLL
 */
void rcc_set_hsi48_source_pll(void)
{
	RCC_CCIPR &= ~RCC_CCIPR_HSI48SEL;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the System Clock.
 *
 * @param[in] osc enum ::osc_t. Oscillator ID. Only HSE, HSI16, MSI and PLL have
 * effect.
 */

void rcc_set_sysclk_source(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CFGR |=  RCC_CFGR_SW_PLL;
		break;
	case RCC_HSE:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW_MASK) | RCC_CFGR_SW_HSE;
		break;
	case RCC_HSI16:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW_MASK) | RCC_CFGR_SW_HSI16;
		break;
	case RCC_MSI:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW_MASK) | RCC_CFGR_SW_MSI;
		break;
	case RCC_HSI48:
	case RCC_LSE:
	case RCC_LSI:
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Multiplication Factor.
 *
 * @note This only has effect when the PLL is disabled.
 *
 * @param[in] mul Unsigned int32. PLL multiplication factor @ref rcc_cfgr_pmf
 */

void rcc_set_pll_multiplier(uint32_t factor)
{
	uint32_t reg = RCC_CFGR
		       & ~(RCC_CFGR_PLLMUL_MASK << RCC_CFGR_PLLMUL_SHIFT);
	RCC_CFGR = reg | (factor << RCC_CFGR_PLLMUL_SHIFT);
}


/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Division Factor.
 *
 * @note This only has effect when the PLL is disabled.
 *
 * @param[in] mul Unsigned int32. PLL multiplication factor @ref rcc_cfgr_pdf
 */

void rcc_set_pll_divider(uint32_t factor)
{
	uint32_t reg = RCC_CFGR
		       & ~(RCC_CFGR_PLLDIV_MASK << RCC_CFGR_PLLDIV_SHIFT);
	RCC_CFGR = reg | (factor << RCC_CFGR_PLLDIV_SHIFT);
}

/**
 * Set the pll source.
 * @param pllsrc RCC_CFGR_PLLSRC_HSI16_CLK or RCC_CFGR_PLLSRC_HSE_CLK
 */
void rcc_set_pll_source(uint32_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PLLSRC_HSE_CLK << 16);
	RCC_CFGR = (reg32 | (pllsrc<<16));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB1 Prescale Factor.
 *
 * @note The APB1 clock frequency must not exceed 32MHz.
 *
 * @param[in] ppre1 Unsigned int32. APB prescale factor @ref rcc_cfgr_apb1pre
 */

void rcc_set_ppre1(uint32_t ppre)
{
	uint32_t reg = RCC_CFGR
		       & ~(RCC_CFGR_PPRE1_MASK << RCC_CFGR_PPRE1_SHIFT);
	RCC_CFGR = reg | (ppre << RCC_CFGR_PPRE1_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB2 Prescale Factor.
 *
 * @note The APB2 clock frequency must not exceed 32MHz.
 *
 * @param[in] ppre1 Unsigned int32. APB prescale factor @ref rcc_cfgr_apb2pre
 */

void rcc_set_ppre2(uint32_t ppre)
{
	uint32_t reg = RCC_CFGR
		       & ~(RCC_CFGR_PPRE2_MASK << RCC_CFGR_PPRE2_SHIFT);
	RCC_CFGR = reg | (ppre << RCC_CFGR_PPRE2_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the AHB Prescale Factor.
 *
 * @param[in] hpre Unsigned int32. AHB prescale factor @ref rcc_cfgr_ahbpre
 */

void rcc_set_hpre(uint32_t hpre)
{
	uint32_t reg = RCC_CFGR & ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_SHIFT);
	RCC_CFGR = reg | (hpre << RCC_CFGR_HPRE_SHIFT);
}

/**
 * Set up sysclock with PLL from HSI16
 * @param clock full struct with desired parameters
 */
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{
	/* Turn on the appropriate source for the PLL */
	if (clock->pll_source == RCC_CFGR_PLLSRC_HSE_CLK) {
		rcc_osc_on(RCC_HSE);
		rcc_wait_for_osc_ready(RCC_HSE);
	} else {
		rcc_osc_on(RCC_HSI16);
		rcc_wait_for_osc_ready(RCC_HSI16);
	}

	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(clock->voltage_scale);

	rcc_osc_off(RCC_PLL);
	while (rcc_is_osc_ready(RCC_PLL));

	flash_prefetch_enable();
	flash_set_ws(clock->flash_waitstates);

	/* Set up the PLL */
	rcc_set_pll_multiplier(clock->pll_mul);
	rcc_set_pll_divider(clock->pll_div);
	rcc_set_pll_source(clock->pll_source);

	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);
	rcc_set_sysclk_source(RCC_PLL);

	/* Set the peripheral clock frequencies used. */
	rcc_ahb_frequency = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}

/**@}*/
