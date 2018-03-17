/** @defgroup STM32F0xx-rcc-file RCC
 *
 * @ingroup STM32F0xx
 *
 * @brief <b>libopencm3 STM32F0xx Reset and Clock Control</b>
 *
 * @version 1.0.0
 *
 * @date 29 Jun 2013
 *
 * This library supports the Reset and Clock Control System in the STM32F0xx
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

#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/i2c.h>

/* Set the default clock frequencies */
uint32_t rcc_ahb_frequency = 8000000; /* 8MHz after reset */
uint32_t rcc_apb1_frequency = 8000000; /* 8MHz after reset */

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
	case RCC_HSI48:
		RCC_CIR |= RCC_CIR_HSI48RDYC;
		break;
	case RCC_HSI14:
		RCC_CIR |= RCC_CIR_HSI14RDYC;
		break;
	case RCC_HSI:
		RCC_CIR |= RCC_CIR_HSIRDYC;
		break;
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYC;
		break;
	case RCC_PLL:
		RCC_CIR |= RCC_CIR_PLLRDYC;
		break;
	case RCC_LSE:
		RCC_CIR |= RCC_CIR_LSERDYC;
		break;
	case RCC_LSI:
		RCC_CIR |= RCC_CIR_LSIRDYC;
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
	case RCC_HSI48:
		RCC_CIR |= RCC_CIR_HSI48RDYIE;
		break;
	case RCC_HSI14:
		RCC_CIR |= RCC_CIR_HSI14RDYIE;
		break;
	case RCC_HSI:
		RCC_CIR |= RCC_CIR_HSIRDYIE;
		break;
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYIE;
		break;
	case RCC_PLL:
		RCC_CIR |= RCC_CIR_PLLRDYIE;
		break;
	case RCC_LSE:
		RCC_CIR |= RCC_CIR_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIR |= RCC_CIR_LSIRDYIE;
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
	case RCC_HSI48:
		RCC_CIR &= ~RCC_CIR_HSI48RDYC;
		break;
	case RCC_HSI14:
		RCC_CIR &= ~RCC_CIR_HSI14RDYC;
		break;
	case RCC_HSI:
		RCC_CIR &= ~RCC_CIR_HSIRDYC;
		break;
	case RCC_HSE:
		RCC_CIR &= ~RCC_CIR_HSERDYC;
		break;
	case RCC_PLL:
		RCC_CIR &= ~RCC_CIR_PLLRDYC;
		break;
	case RCC_LSE:
		RCC_CIR &= ~RCC_CIR_LSERDYC;
		break;
	case RCC_LSI:
		RCC_CIR &= ~RCC_CIR_LSIRDYC;
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
	case RCC_HSI48:
		return (RCC_CIR & RCC_CIR_HSI48RDYF) != 0;
		break;
	case RCC_HSI14:
		return (RCC_CIR & RCC_CIR_HSI14RDYF) != 0;
		break;
	case RCC_HSI:
		return (RCC_CIR & RCC_CIR_HSIRDYF) != 0;
		break;
	case RCC_HSE:
		return (RCC_CIR & RCC_CIR_HSERDYF) != 0;
		break;
	case RCC_PLL:
		return (RCC_CIR & RCC_CIR_PLLRDYF) != 0;
		break;
	case RCC_LSE:
		return (RCC_CIR & RCC_CIR_LSERDYF) != 0;
		break;
	case RCC_LSI:
		return (RCC_CIR & RCC_CIR_LSIRDYF) != 0;
		break;
	}

	cm3_assert_not_reached();
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Clear the Clock Security System Interrupt Flag
*/

void rcc_css_int_clear(void)
{
	RCC_CIR |= RCC_CIR_CSSC;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Read the Clock Security System Interrupt Flag
 *
 * @returns int. Boolean value for flag set.
 */

int rcc_css_int_flag(void)
{
	return ((RCC_CIR & RCC_CIR_CSSF) != 0);
}

bool rcc_is_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		return RCC_CR2 & RCC_CR2_HSI48RDY;
	case RCC_HSI14:
		return RCC_CR2 & RCC_CR2_HSI14RDY;
	case RCC_HSI:
		return RCC_CR & RCC_CR_HSIRDY;
	case RCC_HSE:
		return RCC_CR & RCC_CR_HSERDY;
	case RCC_PLL:
		return RCC_CR & RCC_CR_PLLRDY;
	case RCC_LSE:
		return RCC_BDCR & RCC_BDCR_LSERDY;
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
/** @brief RCC Turn on an Oscillator.
 *
 * Enable an oscillator and power on. Each oscillator requires an amount of
 * time to settle to a usable state. Refer to datasheets for time delay
 * information. A status flag is available to indicate when the oscillator
 * becomes ready (see @ref rcc_osc_ready_int_flag and @ref
 * rcc_wait_for_osc_ready).
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		RCC_CR2 |= RCC_CR2_HSI48ON;
		break;
	case RCC_HSI14:
		RCC_CR2 |= RCC_CR2_HSI14ON;
		break;
	case RCC_HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	case RCC_PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Turn off an Oscillator.
 *
 * Disable an oscillator and power off.
 *
 * @note An oscillator cannot be turned off if it is selected as the system
 * clock.
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_HSI48:
		RCC_CR2 &= ~RCC_CR2_HSI48ON;
		break;
	case RCC_HSI14:
		RCC_CR2 &= ~RCC_CR2_HSI14ON;
		break;
	case RCC_HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	case RCC_PLL:
		/* don't do anything */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable the Clock Security System.
 */

void rcc_css_enable(void)
{
	RCC_CR |= RCC_CR_CSSON;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable the Clock Security System.
 */

void rcc_css_disable(void)
{
	RCC_CR &= ~RCC_CR_CSSON;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the System Clock.
 *
 * @param[in] osc enum ::osc_t. Oscillator ID. Only HSE, LSE and PLL have
 * effect.
 */

void rcc_set_sysclk_source(enum rcc_osc clk)
{
	switch (clk) {
	case RCC_HSI:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_HSI;
		break;
	case RCC_HSE:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_HSE;
		break;
	case RCC_PLL:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_PLL;
		break;
	case RCC_HSI48:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_HSI48;
		break;
	case RCC_LSI:
	case RCC_LSE:
	case RCC_HSI14:
		/* do nothing */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the USB Clock.
 *
 * @param[in] osc enum ::osc_t. Oscillator ID. Only HSI48 or PLL have
 * effect.
 */
void rcc_set_usbclk_source(enum rcc_osc clk)
{
	switch (clk) {
	case RCC_PLL:
		RCC_CFGR3 |= RCC_CFGR3_USBSW;
		break;
	case RCC_HSI48:
		RCC_CFGR3 &= ~RCC_CFGR3_USBSW;
		break;
	case RCC_HSI:
	case RCC_HSE:
	case RCC_LSI:
	case RCC_LSE:
	case RCC_HSI14:
		/* do nothing */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable the RTC clock

*/

void rcc_enable_rtc_clock(void)
{
	RCC_BDCR |= RCC_BDCR_RTCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable the RTC clock

*/

void rcc_disable_rtc_clock(void)
{
	RCC_BDCR &= ~RCC_BDCR_RTCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the RTC clock

@param[in] clock_source ::rcc_osc. RTC clock source. Only HSE/32, LSE and LSI.
*/

void rcc_set_rtc_clock_source(enum rcc_osc clk)
{
	switch (clk) {
	case RCC_HSE:
		RCC_BDCR = (RCC_BDCR & ~RCC_BDCR_RTCSEL) | RCC_BDCR_RTCSEL_HSE;
		break;
	case RCC_LSE:
		RCC_BDCR = (RCC_BDCR & ~RCC_BDCR_RTCSEL) | RCC_BDCR_RTCSEL_LSE;
		break;
	case RCC_LSI:
		RCC_BDCR = (RCC_BDCR & ~RCC_BDCR_RTCSEL) | RCC_BDCR_RTCSEL_LSI;
		break;
	default:
		/* do nothing */
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

void rcc_set_pll_multiplication_factor(uint32_t mul)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLMUL) | mul;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Clock Source.

@note This only has effect when the PLL is disabled.

@param[in] pllsrc Unsigned int32. PLL clock source @ref rcc_cfgr_pcs
*/

void rcc_set_pll_source(uint32_t pllsrc)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLSRC) |
			(pllsrc << 16);
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
/** @brief RCC Set the APB Prescale Factor.
 *
 * @param[in] ppre1 Unsigned int32. APB prescale factor @ref rcc_cfgr_apb1pre
 */

void rcc_set_ppre(uint32_t ppre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PPRE) | ppre;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the AHB Prescale Factor.
 *
 * @param[in] hpre Unsigned int32. AHB prescale factor @ref rcc_cfgr_ahbpre
 */

void rcc_set_hpre(uint32_t hpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_HPRE) | hpre;
}

/**
 * Set PLL Source pre-divider **CAUTION**.
 * On F03x and F05, prediv only applies to HSE source. On others, this
 * is _after_ source selection. See also f3.
 * @param[in] prediv division by prediv+1 @ref rcc_cfgr2_prediv
 */
void rcc_set_prediv(uint32_t prediv)
{
	RCC_CFGR2 = (RCC_CFGR2 & ~RCC_CFGR2_PREDIV) | prediv;
}


/*---------------------------------------------------------------------------*/
/** @brief RCC Get the System Clock Source.
 *
 * @returns ::osc_t System clock source:
 */

enum rcc_osc rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	switch (RCC_CFGR & RCC_CFGR_SWS) {
	case RCC_CFGR_SWS_HSI:
		return RCC_HSI;
	case RCC_CFGR_SWS_HSE:
		return RCC_HSE;
	case RCC_CFGR_SWS_PLL:
		return RCC_PLL;
	case RCC_CFGR_SWS_HSI48:
		return RCC_HSI48;
	}

	cm3_assert_not_reached();
}

void rcc_set_i2c_clock_hsi(uint32_t i2c)
{
	if (i2c == I2C1) {
		RCC_CFGR3 &= ~RCC_CFGR3_I2C1SW;
	}
}

void rcc_set_i2c_clock_sysclk(uint32_t i2c)
{
	if (i2c == I2C1) {
		RCC_CFGR3 |= RCC_CFGR3_I2C1SW;
	}
}

uint32_t rcc_get_i2c_clocks(void)
{
	return RCC_CFGR3 & RCC_CFGR3_I2C1SW;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Get the USB Clock Source.
 *
 * @returns ::osc_t USB clock source:
 */

enum rcc_osc rcc_usb_clock_source(void)
{
	return (RCC_CFGR3 & RCC_CFGR3_USBSW) ? RCC_PLL : RCC_HSI48;
}

/**
 * Set System Clock PLL at 48MHz from HSE at 8MHz.
 */
void rcc_clock_setup_in_hse_8mhz_out_48mhz(void)
{
	rcc_osc_on(RCC_HSE);
	rcc_wait_for_osc_ready(RCC_HSE);
	rcc_set_sysclk_source(RCC_HSE);

	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);
	rcc_set_ppre(RCC_CFGR_PPRE_NODIV);

	flash_prefetch_enable();
	flash_set_ws(FLASH_ACR_LATENCY_024_048MHZ);

	/* PLL: 8MHz * 6 = 48MHz */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_MUL6);
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);

	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);
	rcc_set_sysclk_source(RCC_PLL);

	rcc_apb1_frequency = 48000000;
	rcc_ahb_frequency = 48000000;
}

/**
 * Set System Clock PLL at 48MHz from HSI
 */
void rcc_clock_setup_in_hsi_out_48mhz(void)
{
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);
	rcc_set_sysclk_source(RCC_HSI);

	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);
	rcc_set_ppre(RCC_CFGR_PPRE_NODIV);

	flash_prefetch_enable();
	flash_set_ws(FLASH_ACR_LATENCY_024_048MHZ);

	/* 8MHz * 12 / 2 = 48MHz */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_MUL12);
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_CLK_DIV2);

	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);
	rcc_set_sysclk_source(RCC_PLL);

	rcc_apb1_frequency = 48000000;
	rcc_ahb_frequency = 48000000;
}

/**
 * Set System Clock HSI48 at 48MHz
 */
void rcc_clock_setup_in_hsi48_out_48mhz(void)
{
	rcc_osc_on(RCC_HSI48);
	rcc_wait_for_osc_ready(RCC_HSI48);

	rcc_set_hpre(RCC_CFGR_HPRE_NODIV);
	rcc_set_ppre(RCC_CFGR_PPRE_NODIV);

	flash_prefetch_enable();
	flash_set_ws(FLASH_ACR_LATENCY_024_048MHZ);

	rcc_set_sysclk_source(RCC_HSI48);

	rcc_apb1_frequency = 48000000;
	rcc_ahb_frequency = 48000000;
}
/**@}*/

