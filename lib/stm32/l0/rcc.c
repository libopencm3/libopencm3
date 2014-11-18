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
#include <libopencm3/stm32/rcc.h>

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


/**@}*/
