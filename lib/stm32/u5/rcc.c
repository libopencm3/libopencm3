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

#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>

/* Set the default clock frequencies */
#define RCC_DEFAULT_MSIS_FREQUENCY	4000000U
#define RCC_DEFAULT_HSI48_FREQUENCY	48000000U
#define RCC_DEFAULT_SHSI_FREQUENCY	48000000U
#define RCC_DEFAULT_HSI16_FREQUENCY	16000000U
#define RCC_DEFAULT_LSI_FREQUENCY	32000U
#define RCC_DEFAULT_LSE_FREQUENCY	32768U

uint32_t rcc_ahb_frequency = RCC_DEFAULT_MSIS_FREQUENCY;
uint32_t rcc_apb1_frequency = RCC_DEFAULT_MSIS_FREQUENCY;
uint32_t rcc_apb2_frequency = RCC_DEFAULT_MSIS_FREQUENCY;


const struct rcc_clock_scale rcc_hsi16mhz_configs = {
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.ahb_frequency = RCC_DEFAULT_HSI16_FREQUENCY,
		.apb1_frequency = RCC_DEFAULT_HSI16_FREQUENCY,
		.apb2_frequency = RCC_DEFAULT_HSI16_FREQUENCY,
};

void rcc_set_ppre2(uint32_t ppre2)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~RCC_CFGR_PPRE2;
	RCC_CFGR = (reg32 | (ppre2 << RCC_CFGR_PPRE2_SHIFT));
}

void rcc_set_ppre1(uint32_t ppre1)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~RCC_CFGR_PPRE1;
	RCC_CFGR = (reg32 | (ppre1 << RCC_CFGR_PPRE1_SHIFT));
}

void rcc_set_hpre(uint32_t hpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~RCC_CFGR_HPRE;
	RCC_CFGR = (reg32 | (hpre << RCC_CFGR_HPRE_SHIFT));
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
	/* Don't try and go to fast for a voltage range! */
	if (clock->ahb_frequency > rcc_ahb_frequency) {
		/* Going up, power up first */
		// pwr_set_vos_scale(clock->voltage_scale); TODO
		rcc_set_hpre(clock->hpre);
		rcc_set_ppre1(clock->ppre1);
		rcc_set_ppre2(clock->ppre2);
	} else {
		/* going down, slow down before cutting power */
		rcc_set_hpre(clock->hpre);
		rcc_set_ppre1(clock->ppre1);
		rcc_set_ppre2(clock->ppre2);
		// pwr_set_vos_scale(clock->voltage_scale); TODO
	}

	rcc_wait_for_osc_ready(RCC_HSI);
	rcc_set_sysclk_source(RCC_HSI16);

	/* Set the peripheral clock frequencies used. */
	rcc_ahb_frequency  = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
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
	while (!rcc_is_osc_ready(osc));
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
		sw = RCC_CFGR_SW_SYSCLKSEL_MSIS;
		break;
	case RCC_HSI16:
		sw = RCC_CFGR_SW_SYSCLKSEL_HSI16;
		break;
	case RCC_HSE:
		sw = RCC_CFGR_SW_SYSCLKSEL_HSE;
		break;
	case RCC_PLL1:
		sw = RCC_CFGR_SW_SYSCLKSEL_PLL;
		break;
	default:
		cm3_assert_not_reached();
		break;
	}

	sw <<= RCC_CFGR_SW_SYSCLKSEL_SHIFT;
	RCC_CFGR = (RCC_CFGR & ~(RCC_CFGR_SW_SYSCLKSEL_MASK << RCC_CFGR_SW_SYSCLKSEL_SHIFT)) | sw;
}

/**
 * @brief Set the peripheral clock source
 * @param periph peripheral of choice, eg XXX_BASE
 * @param sel periphral clock source
 */
void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t sel) {

	volatile uint32_t *reg32;
	uint32_t shift;
	uint32_t mask;

	switch (periph)	{
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

static uint32_t rcc_get_usart_clksel_freq(uint32_t usart, uint8_t shift) {
	uint8_t clksel;
	if(usart == USART6_BASE) {
		clksel = (RCC_CCIPR2 >> shift) & RCC_CCIPR_USARTxSEL_MASK;
	} else {
		clksel = (RCC_CCIPR1 >> shift) & RCC_CCIPR_USARTxSEL_MASK;
	}

	switch (clksel) {
	case RCC_CCIPR_USARTxSEL_PCLKx:
		if(usart == USART1_BASE) {
			return rcc_apb2_frequency;
		}
		return rcc_apb1_frequency;
	case RCC_CCIPR_USARTxSEL_SYSCLK:
		return rcc_ahb_frequency;
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
	switch (usart)
	{
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

