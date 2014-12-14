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
 * Copyright (C) 2014 Chuck McManis <cmcmanis@mcmanis.com>
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

/*
 * Clock speeds when the chip comes out of reset.
 */
uint32_t rcc_apb1_frequency = (RCC_MSI_2MHZ & 0xffffff);
uint32_t rcc_apb2_frequency = (RCC_MSI_2MHZ & 0xffffff);
uint32_t rcc_ahb_frequency = (RCC_MSI_2MHZ & 0xffffff);

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case MSI:
		RCC_CR |= RCC_CR_MSION;
		break;
	case HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case HSI48:
		RCC_CRRCR |= RCC_CRRCR_HSI48ON;
		break;
	case HSI4:
	case HSI16:
		RCC_CR |= RCC_CR_HSI16ON;
		break;
	case LSE:
		RCC_CSR |= RCC_CSR_LSEON;
		break;
	case LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	}
}

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case MSI:
		RCC_CR &= ~RCC_CR_MSION;
		break;
	case HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case HSI48:
		RCC_CRRCR &= ~RCC_CRRCR_HSI48ON;
		break;
	case HSI4:
	case HSI16:
		RCC_CR &= ~RCC_CR_HSI16ON;
		break;
	case LSE:
		RCC_CSR &= ~RCC_CSR_LSEON;
		break;
	case LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	}
}

/* TODO easy target for shared code */
void rcc_osc_bypass_enable(enum rcc_osc osc)
{
	switch (osc) {
	case HSE:
		RCC_CR |= RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_CSR |= RCC_CSR_LSEBYP;
		break;
	default:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

/* TODO easy target for shared code */
void rcc_osc_bypass_disable(enum rcc_osc osc)
{
	switch (osc) {
	case HSE:
		RCC_CR &= ~RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_CSR &= ~RCC_CSR_LSEBYP;
		break;
	default:
		/* Do nothing, only HSE/LSE allowed here. */
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
	case PLL:
		RCC_CICR |= RCC_CICR_PLLRDYC;
		break;
	case HSE:
		RCC_CICR |= RCC_CICR_HSERDYC;
		break;
	case HSI48:
		RCC_CICR |= RCC_CICR_HSI48RDYC;
		break;
	case HSI4:
	case HSI16:
		RCC_CICR |= RCC_CICR_HSI16RDYC;
		break;
	case MSI:
		RCC_CICR |= RCC_CICR_MSIRDYC;
		break;
	case LSE:
		RCC_CICR |= RCC_CICR_LSERDYC;
		break;
	case LSI:
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
	case PLL:
		RCC_CIER |= RCC_CIER_PLLRDYIE;
		break;
	case HSE:
		RCC_CIER |= RCC_CIER_HSERDYIE;
		break;
	case HSI48:
		RCC_CIER |= RCC_CIER_HSI48RDYIE;
		break;
	case HSI4:
	case HSI16:
		RCC_CIER |= RCC_CIER_HSI16RDYIE;
		break;
	case MSI:
		RCC_CIER |= RCC_CIER_MSIRDYIE;
		break;
	case LSE:
		RCC_CIER |= RCC_CIER_LSERDYIE;
		break;
	case LSI:
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
	case PLL:
		RCC_CIER &= ~RCC_CIER_PLLRDYIE;
		break;
	case HSE:
		RCC_CIER &= ~RCC_CIER_HSERDYIE;
		break;
	case HSI48:
		RCC_CIER &= ~RCC_CIER_HSI48RDYIE;
		break;
	case HSI4:
	case HSI16:
		RCC_CIER &= ~RCC_CIER_HSI16RDYIE;
		break;
	case MSI:
		RCC_CIER &= ~RCC_CIER_MSIRDYIE;
		break;
	case LSE:
		RCC_CIER &= ~RCC_CIER_LSERDYIE;
		break;
	case LSI:
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
	case PLL:
		return ((RCC_CIFR & RCC_CIFR_PLLRDYF) != 0);
		break;
	case HSE:
		return ((RCC_CIFR & RCC_CIFR_HSERDYF) != 0);
		break;
	case HSI48:
		return ((RCC_CIFR & RCC_CIFR_HSI48RDYF) != 0);
		break;
	case HSI4:
	case HSI16:
		return ((RCC_CIFR & RCC_CIFR_HSI16RDYF) != 0);
		break;
	case MSI:
		return ((RCC_CIFR & RCC_CIFR_MSIRDYF) != 0);
		break;
	case LSE:
		return ((RCC_CIFR & RCC_CIFR_LSERDYF) != 0);
		break;
	case LSI:
		return ((RCC_CIFR & RCC_CIFR_LSIRDYF) != 0);
		break;
	}

	cm3_assert_not_reached();
}


/*---------------------------------------------------------------------------*/
/** @brief RCC Wait for Oscillator Ready.
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */
void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		while ((RCC_CR & RCC_CR_PLLRDY) == 0);
		break;
	case HSE:
		while ((RCC_CR & RCC_CR_HSERDY) == 0);
		break;
	case HSI4:
		while ((RCC_CR & RCC_CR_HSI16DIVF) == 0);
		while ((RCC_CR & RCC_CR_HSI16RDY) == 0);
		break;
		
	case HSI16:
		while ((RCC_CR & RCC_CR_HSI16RDY) == 0);
		break;
	case HSI48:
		while ((RCC_CRRCR & RCC_CRRCR_HSI48RDY) == 0);
		break;
	case MSI:
		while ((RCC_CR & RCC_CR_MSIRDY) == 0);
		break;
	case LSE:
		while ((RCC_CSR & RCC_CSR_LSERDY) == 0);
		break;
	case LSI:
		while ((RCC_CSR & RCC_CSR_LSIRDY) == 0);
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the System Clock source.
 *
 */
enum rcc_osc rcc_get_sysclk(void) {
	uint32_t	clk;
	clk = (RCC_CFGR >> 2) & 0x3;
	switch (clk) {
	case 0:
		return MSI;
	case 1:
		return (RCC_CR & RCC_CR_HSI16DIVF) ? HSI4 : HSI16;
	case 2:
		return HSE;
	case 3:
		return PLL;
	}
	return MSI;	/* not reached */
}

/*
 * Written this way to save code space on the L0, this func
 * generic for ppre1 or ppre2
 */
static void rcc_set_ppre(uint32_t *freq, uint32_t shift, uint32_t div_factor) {
	uint32_t	reg;
	reg = RCC_CFGR = (RCC_CFGR & ~(0x7 << shift));
	switch (div_factor) {
	case RCC_PPRE_DIV_2:
		*freq = rcc_ahb_frequency >> 1;
		reg |= (div_factor & 0x7) << shift;
		break;
	case RCC_PPRE_DIV_4:
		*freq = rcc_ahb_frequency >> 2;
		reg |= (div_factor & 0x7) << shift;
		break;
	case RCC_PPRE_DIV_8:
		*freq = rcc_ahb_frequency >> 3;
		reg |= (div_factor & 0x7) << shift;
		break;
	case RCC_PPRE_DIV_16:
		*freq = rcc_ahb_frequency >> 4;
		reg |= (div_factor & 0x7) << shift;
		break;
	default:
		/* captures DIV_NONE and illegal values */
		*freq = rcc_ahb_frequency;
		break;
	}
	RCC_CFGR = reg;
}

void rcc_set_ppre1(uint32_t div_factor) {
	rcc_set_ppre(&rcc_apb1_frequency, RCC_CFGR_PPRE1_SHIFT, div_factor);
}

void rcc_set_ppre2(uint32_t div_factor) {
	rcc_set_ppre(&rcc_apb2_frequency, RCC_CFGR_PPRE2_SHIFT, div_factor);
}

void rcc_set_hpre(uint32_t div_factor) {
	RCC_CFGR = (RCC_CFGR & ~0xf0) | ((div_factor << 4) & 0xf0);
}

/*---------------------------------------------------------------------------*/
/** @brief Set the System Clock to source.
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */
void rcc_set_sysclk(enum rcc_osc osc) {
	uint32_t	clk_bits;
	switch (osc) {
	case PLL:
		clk_bits = RCC_CFGR_SW_PLL;
		break;
	case MSI:
		clk_bits = RCC_CFGR_SW_MSI;
		break;
	case HSE:
		clk_bits = RCC_CFGR_SW_HSE;
		break;
	case HSI16:
		clk_bits = RCC_CFGR_SW_HSI16;
		break;
	case HSI4:
		clk_bits = RCC_CFGR_SW_HSI16;
		break;
	default:
		/* it is an error but this allows to continue */
		clk_bits = RCC_CFGR_SW_MSI;
		break;
	}
	/* set clock selection*/
	RCC_CFGR = (RCC_CFGR & (~0x3)) | clk_bits;
	/* wait for it to be realized */
	while (((RCC_CFGR >> 2) & 0x3) != clk_bits) ;
	/* for 'fake' HSI4 clock, turn on divider */
	if (osc == HSI4) {
		RCC_CR = RCC_CR | RCC_CR_HSI16DIVEN;
		while (! (RCC_CR & RCC_CR_HSI16DIVF)) ;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Set up and select the HSI16 System Clock source.
 *
 */
void rcc_hsi16_clock_setup(void) {
	rcc_osc_on(HSI16);
	while (! (RCC_CR & RCC_CR_HSI16RDY)) ;
	rcc_set_sysclk(HSI16);
	rcc_set_ppre1(RCC_PPRE_DIV_NONE);
	rcc_set_ppre2(RCC_PPRE_DIV_NONE);
	rcc_ahb_frequency = 16000000;
	rcc_apb1_frequency = 16000000;
	rcc_apb2_frequency = 16000000;
}

/*---------------------------------------------------------------------------*/
/** @brief Set up and select the HSI4 System Clock source.
 *
 * This is a "fake" clock in that it is simply the HSI16 clock divided by
 * 4, but other than the divider it looks to the chip like an HSI4 clock.
 */
void rcc_hsi4_clock_setup(void) {
	rcc_osc_on(HSI16);
	while (! (RCC_CR & RCC_CR_HSI16RDY)) ;
	rcc_set_sysclk(HSI4);
	rcc_set_ppre1(RCC_PPRE_DIV_NONE);
	rcc_set_ppre2(RCC_PPRE_DIV_NONE);
	rcc_ahb_frequency = 4000000;
	rcc_apb1_frequency = 4000000;
	rcc_apb2_frequency = 4000000;
}

void rcc_msi_clock_setup(uint32_t msi_frequency) {
	/* Check to see if we're already set to the MSI and correct
	 * frequency as the system clock */
	if ((RCC_CR & RCC_CR_MSIRDY) &&
	    (((RCC_ICSCR & (RCC_ICSCR_MSIRANGE_MASK << RCC_ICSCR_MSIRANGE_SHIFT)) ==
	     (msi_frequency & 0x0f000000) >> 11)) &&
	    (rcc_get_sysclk() == MSI)) {
		return;
	}
	rcc_osc_on(MSI);
	RCC_ICSCR = (RCC_ICSCR & ~(RCC_ICSCR_MSIRANGE_MASK << RCC_ICSCR_MSIRANGE_SHIFT)) |
		    ((msi_frequency >> 11) & 0xe000);
	while (! (RCC_CR & RCC_CR_MSIRDY)) ;
	rcc_set_sysclk(MSI);
	rcc_set_ppre1(RCC_PPRE_DIV_NONE);
	rcc_set_ppre2(RCC_PPRE_DIV_NONE);
	rcc_ahb_frequency = msi_frequency & 0x00ffffff;
	rcc_apb1_frequency = msi_frequency & 0x00ffffff;
	rcc_apb2_frequency = msi_frequency & 0x00ffffff;
}

void rcc_hse_clock_setup(uint32_t hse_frequency) {
	/* insure it is enabled */
	rcc_osc_on(HSE);
	while (! (RCC_CR & RCC_CR_HSERDY)) ;
	/* switch to it */
	rcc_set_sysclk(HSE);
	rcc_set_hpre(0);
	rcc_set_ppre1(RCC_PPRE_DIV_NONE);
	rcc_set_ppre2(RCC_PPRE_DIV_NONE);
	rcc_ahb_frequency = hse_frequency;
	rcc_apb1_frequency = hse_frequency;
	rcc_apb2_frequency = hse_frequency;
}

void rcc_pll_clock_setup(uint32_t pll_frequency, uint32_t base_frequency) {
	if (rcc_get_sysclk() == PLL) {
		/* switch to a known good clock (also the reset clock) */
		rcc_msi_clock_setup(RCC_MSI_2MHZ);
	}
	rcc_osc_off(PLL);
	
}

/**@}*/
