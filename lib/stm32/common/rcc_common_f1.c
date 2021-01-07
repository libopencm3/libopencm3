/** @addtogroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2009
Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

@date 18 August 2012

LGPL License Terms @ref lgpl_license
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

/** Set the default clock frequencies */
uint32_t rcc_apb1_frequency = 8000000;
uint32_t rcc_apb2_frequency = 8000000;
uint32_t rcc_ahb_frequency = 8000000;

/*---------------------------------------------------------------------------*/
/** @brief RCC Clear the Oscillator Ready Interrupt Flag

Clear the interrupt flag that was set when a clock oscillator became ready to
use.

@param[in] osc Oscillator ID
*/

void rcc_osc_ready_int_clear(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIR |= RCC_CIR_PLLRDYC;
		break;
	case RCC_PLL2:
		RCC_CIR |= RCC_CIR_PLL2RDYC;
		break;
	case RCC_PLL3:
		RCC_CIR |= RCC_CIR_PLL3RDYC;
		break;
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYC;
		break;
	case RCC_HSI:
		RCC_CIR |= RCC_CIR_HSIRDYC;
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

@param osc Oscillator ID
*/

void rcc_osc_ready_int_enable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIR |= RCC_CIR_PLLRDYIE;
		break;
	case RCC_PLL2:
		RCC_CIR |= RCC_CIR_PLL2RDYIE;
		break;
	case RCC_PLL3:
		RCC_CIR |= RCC_CIR_PLL3RDYIE;
		break;
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYIE;
		break;
	case RCC_HSI:
		RCC_CIR |= RCC_CIR_HSIRDYIE;
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

@param[in] osc Oscillator ID
*/

void rcc_osc_ready_int_disable(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CIR &= ~RCC_CIR_PLLRDYIE;
		break;
	case RCC_PLL2:
		RCC_CIR &= ~RCC_CIR_PLL2RDYIE;
		break;
	case RCC_PLL3:
		RCC_CIR &= ~RCC_CIR_PLL3RDYIE;
		break;
	case RCC_HSE:
		RCC_CIR &= ~RCC_CIR_HSERDYIE;
		break;
	case RCC_HSI:
		RCC_CIR &= ~RCC_CIR_HSIRDYIE;
		break;
	case RCC_LSE:
		RCC_CIR &= ~RCC_CIR_LSERDYIE;
		break;
	case RCC_LSI:
		RCC_CIR &= ~RCC_CIR_LSIRDYIE;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Read the Oscillator Ready Interrupt Flag

@param[in] osc Oscillator ID
@returns int. Boolean value for flag set.
*/

int rcc_osc_ready_int_flag(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return ((RCC_CIR & RCC_CIR_PLLRDYF) != 0);
		break;
	case RCC_PLL2:
		return ((RCC_CIR & RCC_CIR_PLL2RDYF) != 0);
		break;
	case RCC_PLL3:
		return ((RCC_CIR & RCC_CIR_PLL3RDYF) != 0);
		break;
	case RCC_HSE:
		return ((RCC_CIR & RCC_CIR_HSERDYF) != 0);
		break;
	case RCC_HSI:
		return ((RCC_CIR & RCC_CIR_HSIRDYF) != 0);
		break;
	case RCC_LSE:
		return ((RCC_CIR & RCC_CIR_LSERDYF) != 0);
		break;
	case RCC_LSI:
		return ((RCC_CIR & RCC_CIR_LSIRDYF) != 0);
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

@returns int. Boolean value for flag set.
*/

int rcc_css_int_flag(void)
{
	return ((RCC_CIR & RCC_CIR_CSSF) != 0);
}

bool rcc_is_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		return RCC_CR & RCC_CR_PLLRDY;
	case RCC_PLL2:
		return RCC_CR & RCC_CR_PLL2RDY;
	case RCC_PLL3:
		return RCC_CR & RCC_CR_PLL3RDY;
	case RCC_HSE:
		return RCC_CR & RCC_CR_HSERDY;
	case RCC_HSI:
		return RCC_CR & RCC_CR_HSIRDY;
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

Enable an oscillator and power on. Each oscillator requires an amount of time
to settle to a usable state. Refer to datasheets for time delay information. A
status flag is available to indicate when the oscillator becomes ready (see
@ref rcc_osc_ready_int_flag and @ref rcc_wait_for_osc_ready).

@note The LSE clock is in the backup domain and cannot be enabled until the
backup domain write protection has been removed (see @ref
pwr_disable_backup_domain_write_protect).

@param[in] osc Oscillator ID
*/

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case RCC_PLL2:
		RCC_CR |= RCC_CR_PLL2ON;
		break;
	case RCC_PLL3:
		RCC_CR |= RCC_CR_PLL3ON;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	}
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
	case RCC_PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case RCC_PLL2:
		RCC_CR &= ~RCC_CR_PLL2ON;
		break;
	case RCC_PLL3:
		RCC_CR &= ~RCC_CR_PLL3ON;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
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

@param[in] clk Unsigned int32. System Clock Selection @ref rcc_cfgr_scs
*/

void rcc_set_sysclk_source(uint32_t clk)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) |
			(clk << RCC_CFGR_SW_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL2 Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul Unsigned int32. PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll2_multiplication_factor(uint32_t mul)
{
	RCC_CFGR2 = (RCC_CFGR2 & ~RCC_CFGR2_PLL2MUL) |
			(mul << RCC_CFGR2_PLL2MUL_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL3 Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul Unsigned int32. PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll3_multiplication_factor(uint32_t mul)
{
	RCC_CFGR2 = (RCC_CFGR2 & ~RCC_CFGR2_PLL3MUL) |
			(mul << RCC_CFGR2_PLL3MUL_SHIFT);
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
/** @brief RCC RTC Clock Enabled Flag

@returns uint32_t. Nonzero if the RTC Clock is enabled.
*/

uint32_t rcc_rtc_clock_enabled_flag(void)
{
	return RCC_BDCR & RCC_BDCR_RTCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable the RTC clock

*/

void rcc_enable_rtc_clock(void)
{
	RCC_BDCR |= RCC_BDCR_RTCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the RTC clock

@param[in] clock_source RTC clock source. Only HSE/128, LSE and LSI.
*/

void rcc_set_rtc_clock_source(enum rcc_osc clock_source)
{
	uint32_t reg32;

	switch (clock_source) {
	case RCC_LSE:
		/* Turn the LSE on and wait while it stabilises. */
		RCC_BDCR |= RCC_BDCR_LSEON;
		while ((reg32 = (RCC_BDCR & RCC_BDCR_LSERDY)) == 0);

		/* Choose LSE as the RTC clock source. */
		RCC_BDCR &= ~((1 << 8) | (1 << 9));
		RCC_BDCR |= (1 << 8);
		break;
	case RCC_LSI:
		/* Turn the LSI on and wait while it stabilises. */
		RCC_CSR |= RCC_CSR_LSION;
		while ((reg32 = (RCC_CSR & RCC_CSR_LSIRDY)) == 0);

		/* Choose LSI as the RTC clock source. */
		RCC_BDCR &= ~((1 << 8) | (1 << 9));
		RCC_BDCR |= (1 << 9);
		break;
	case RCC_HSE:
		/* Turn the HSE on and wait while it stabilises. */
		RCC_CR |= RCC_CR_HSEON;
		while ((reg32 = (RCC_CR & RCC_CR_HSERDY)) == 0);

		/* Choose HSE as the RTC clock source. */
		RCC_BDCR &= ~((1 << 8) | (1 << 9));
		RCC_BDCR |= (1 << 9) | (1 << 8);
		break;
	case RCC_PLL:
	case RCC_PLL2:
	case RCC_PLL3:
	case RCC_HSI:
		/* Unusable clock source, here to prevent warnings. */
		/* Turn off clock sources to RTC. */
		RCC_BDCR &= ~((1 << 8) | (1 << 9));
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB2 Prescale Factor.

@param[in] ppre2 Unsigned int32. APB2 prescale factor @ref rcc_cfgr_apb2pre
*/

void rcc_set_ppre2(uint32_t ppre2)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PPRE2) |
			(ppre2 << RCC_CFGR_PPRE2_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB1 Prescale Factor.

@note The APB1 clock frequency must not exceed 36MHz.

@param[in] ppre1 Unsigned int32. APB1 prescale factor @ref rcc_cfgr_apb1pre
*/

void rcc_set_ppre1(uint32_t ppre1)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PPRE1) |
			(ppre1 << RCC_CFGR_PPRE1_SHIFT);

}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the AHB Prescale Factor.

@param[in] hpre Unsigned int32. AHB prescale factor @ref rcc_cfgr_ahbpre
*/

void rcc_set_hpre(uint32_t hpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_HPRE) |
			(hpre << RCC_CFGR_HPRE_SHIFT);

}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the USB Prescale Factor.

The prescale factor can be set to 1 (no prescale) for use when the PLL clock is
48MHz, or 1.5 to generate the 48MHz USB clock from a 72MHz PLL clock.

@note This bit cannot be reset while the USB clock is enabled.

@param[in] usbpre Unsigned int32. USB prescale factor @ref rcc_cfgr_usbpre
*/

void rcc_set_usbpre(uint32_t usbpre)
{
	if (usbpre) {
		RCC_CFGR |= RCC_CFGR_USBPRE;
	} else {
		RCC_CFGR &= ~RCC_CFGR_USBPRE;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief * Set PLL Source pre-divider
 *
 * @param[in] prediv division by prediv @ref rcc_cfgr2_prediv
 */

void rcc_set_prediv1(uint32_t prediv)
{
	RCC_CFGR2 = (RCC_CFGR2 & ~RCC_CFGR2_PREDIV1) |
			(prediv << RCC_CFGR2_PREDIV1_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief * Set PLL2 and PLL3 Source pre-divider
 *
 * @param[in] prediv division by prediv @ref rcc_cfgr2_prediv
 */

void rcc_set_prediv2(uint32_t prediv)
{
	RCC_CFGR2 = (RCC_CFGR2 & ~RCC_CFGR2_PREDIV2) |
			(prediv << RCC_CFGR2_PREDIV2_SHIFT);
}

void rcc_set_prediv1_source(uint32_t rccsrc)
{
	if (rccsrc) {
		RCC_CFGR2 |= RCC_CFGR2_PREDIV1SRC;
	} else {
		RCC_CFGR2 &= ~RCC_CFGR2_PREDIV1SRC;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Get the System Clock Source.

@returns Unsigned int32. System clock source:
@li 00 indicates HSE
@li 01 indicates LSE
@li 02 indicates PLL
*/

uint32_t rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return (RCC_CFGR & RCC_CFGR_SWS) >> RCC_CFGR_SWS_SHIFT;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Reset the Backup Domain

The backup domain registers are reset to disable RTC controls and clear user
data.
*/

void rcc_backupdomain_reset(void)
{
	/* Set the backup domain software reset. */
	RCC_BDCR |= RCC_BDCR_BDRST;

	/* Clear the backup domain software reset. */
	RCC_BDCR &= ~RCC_BDCR_BDRST;
}

/**@}*/
