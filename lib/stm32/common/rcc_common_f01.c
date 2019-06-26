/** @addtogroup rcc_file
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
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
uint32_t rcc_ahb_frequency = 8000000; /* 8MHz after reset */
uint32_t rcc_apb1_frequency = 8000000; /* 8MHz after reset */
#ifdef RCC_CFGR_PPRE2
uint32_t rcc_apb2_frequency = 8000000; /* 8MHz after reset */
#endif

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
#ifdef RCC_CIR_PLL2RDYC
	case RCC_PLL2:
		RCC_CIR |= RCC_CIR_PLL2RDYC;
		break;
#endif
#ifdef RCC_CIR_PLL3RDYC
	case RCC_PLL3:
		RCC_CIR |= RCC_CIR_PLL3RDYC;
		break;
#endif
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYC;
		break;
	case RCC_HSI:
		RCC_CIR |= RCC_CIR_HSIRDYC;
		break;
#ifdef RCC_CIR_HSI48RDYC
	case RCC_HSI48:
		RCC_CIR |= RCC_CIR_HSI48RDYC;
		break;
#endif
#ifdef RCC_CIR_HSI14RDYC
	case RCC_HSI14:
		RCC_CIR |= RCC_CIR_HSI14RDYC;
		break;
#endif
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
#ifdef RCC_CIR_PLL2RDYIE
	case RCC_PLL2:
		RCC_CIR |= RCC_CIR_PLL2RDYIE;
		break;
#endif
#ifdef RCC_CIR_PLL3RDYIE
	case RCC_PLL3:
		RCC_CIR |= RCC_CIR_PLL3RDYIE;
		break;
#endif
	case RCC_HSE:
		RCC_CIR |= RCC_CIR_HSERDYIE;
		break;
	case RCC_HSI:
		RCC_CIR |= RCC_CIR_HSIRDYIE;
		break;
#ifdef RCC_CIR_HSI48RDYIE
	case RCC_HSI48:
		RCC_CIR |= RCC_CIR_HSI48RDYIE;
		break;
#endif
#ifdef RCC_CIR_HSI14RDYIE
	case RCC_HSI14:
		RCC_CIR |= RCC_CIR_HSI14RDYIE;
		break;
#endif
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
#ifdef RCC_CIR_PLL2RDYIE
	case RCC_PLL2:
		RCC_CIR &= ~RCC_CIR_PLL2RDYIE;
		break;
#endif
#ifdef RCC_CIR_PLL3RDYIE
	case RCC_PLL3:
		RCC_CIR &= ~RCC_CIR_PLL3RDYIE;
		break;
#endif
	case RCC_HSE:
		RCC_CIR &= ~RCC_CIR_HSERDYIE;
		break;
	case RCC_HSI:
		RCC_CIR &= ~RCC_CIR_HSIRDYIE;
		break;
#ifdef RCC_CIR_HSI48RDYIE
	case RCC_HSI48:
		RCC_CIR &= ~RCC_CIR_HSI48RDYC;
		break;
#endif
#ifdef RCC_CIR_HSI14RDYIE
	case RCC_HSI14:
		RCC_CIR &= ~RCC_CIR_HSI14RDYC;
		break;
#endif
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
#ifdef RCC_CIR_PLL2RDYF
	case RCC_PLL2:
		return ((RCC_CIR & RCC_CIR_PLL2RDYF) != 0);
		break;
#endif
#ifdef RCC_CIR_PLL3RDYF
	case RCC_PLL3:
		return ((RCC_CIR & RCC_CIR_PLL3RDYF) != 0);
		break;
#endif
	case RCC_HSE:
		return ((RCC_CIR & RCC_CIR_HSERDYF) != 0);
		break;
	case RCC_HSI:
		return ((RCC_CIR & RCC_CIR_HSIRDYF) != 0);
		break;
#ifdef RCC_CIR_HSI48RDYF
	case RCC_HSI48:
		return (RCC_CIR & RCC_CIR_HSI48RDYF) != 0;
		break;
#endif
#ifdef RCC_CIR_HSI14RDYF
	case RCC_HSI14:
		return (RCC_CIR & RCC_CIR_HSI14RDYF) != 0;
		break;
#endif
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
#ifdef RCC_CR_PLL2RDY
	case RCC_PLL2:
		return RCC_CR & RCC_CR_PLL2RDY;
#endif
#ifdef RCC_CR_PLL3RDY
	case RCC_PLL3:
		return RCC_CR & RCC_CR_PLL3RDY;
#endif
	case RCC_HSE:
		return RCC_CR & RCC_CR_HSERDY;
	case RCC_HSI:
		return RCC_CR & RCC_CR_HSIRDY;
#ifdef RCC_CR2_HSI48RDY
	case RCC_HSI48:
		return RCC_CR2 & RCC_CR2_HSI48RDY;
#endif
#ifdef RCC_CR2_HSI14RDY
	case RCC_HSI14:
		return RCC_CR2 & RCC_CR2_HSI14RDY;
#endif
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
#ifdef RCC_CR_PLL2ON
	case RCC_PLL2:
		RCC_CR |= RCC_CR_PLL2ON;
		break;
#endif
#ifdef RCC_CR_PLL3ON
	case RCC_PLL3:
		RCC_CR |= RCC_CR_PLL3ON;
		break;
#endif
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
#ifdef RCC_CR2_HSI48ON
	case RCC_HSI48:
		RCC_CR2 |= RCC_CR2_HSI48ON;
		break;
#endif
#ifdef RCC_CR2_HSI14ON
	case RCC_HSI14:
		RCC_CR2 |= RCC_CR2_HSI14ON;
		break;
#endif
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
@ref pwr_disable_backup_domain_write_protect) or the backup domain
has been reset.

@param[in] osc Oscillator ID
*/

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
#ifdef RCC_CR_PLL2ON
	case RCC_PLL2:
		RCC_CR &= ~RCC_CR_PLL2ON;
		break;
#endif
#ifdef RCC_CR_PLL3ON
	case RCC_PLL3:
		RCC_CR &= ~RCC_CR_PLL3ON;
		break;
#endif
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
#ifdef RCC_CR2_HSI48ON
	case RCC_HSI48:
		RCC_CR2 &= ~RCC_CR2_HSI48ON;
		break;
#endif
#ifdef RCC_CR2_HSI14ON
	case RCC_HSI14:
		RCC_CR2 &= ~RCC_CR2_HSI14ON;
		break;
#endif
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
 *
 * @param clk Oscillator ID. Only HSE, LSE and PLL have
 * effect.
 */

void rcc_set_sysclk_source(enum rcc_osc clk)
{
	switch (clk) {
	case RCC_HSI:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) |
			(RCC_CFGR_SW_HSI << RCC_CFGR_SW_SHIFT);
		break;
	case RCC_HSE:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) |
			(RCC_CFGR_SW_HSE << RCC_CFGR_SW_SHIFT);
		break;
	case RCC_PLL:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) |
			(RCC_CFGR_SW_PLL << RCC_CFGR_SW_SHIFT);
		break;
#ifdef RCC_CFGR_SW_HSI48
	case RCC_HSI48:
		RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) |
			(RCC_CFGR_SW_HSI48 << RCC_CFGR_SW_SHIFT);
		break;
#endif
	default:
		/* do nothing */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Get the System Clock Source.
 *
 * @returns current system clock source
 */

enum rcc_osc rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	switch ((RCC_CFGR & RCC_CFGR_SWS) >> RCC_CFGR_SWS_SHIFT) {
	case RCC_CFGR_SWS_HSI:
		return RCC_HSI;
	case RCC_CFGR_SWS_HSE:
		return RCC_HSE;
	case RCC_CFGR_SWS_PLL:
		return RCC_PLL;
#ifdef RCC_CFGR_SWS_HSI48
	case RCC_CFGR_SWS_HSI48:
		return RCC_HSI48;
#endif
	}

	cm3_assert_not_reached();
}

#ifdef RCC_CFGR_PLLMUL_SHIFT
/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul Unsigned int32. PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll_multiplication_factor(uint32_t mul)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLMUL) |
			(mul << RCC_CFGR_PLLMUL_SHIFT);
}
#endif

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
/** @brief RCC RTC Clock Enabled Flag

@returns uint32_t. Nonzero if the RTC Clock is enabled.
*/

uint32_t rcc_rtc_clock_enabled_flag(void)
{
	return RCC_BDCR & RCC_BDCR_RTCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the RTC clock

@param[in] clk RTC clock source. Only HSE/32, LSE and LSI.
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
/** @brief RCC Set the AHB Prescale Factor.

@param[in] hpre Unsigned int32. AHB prescale factor @ref rcc_cfgr_ahbpre
*/

void rcc_set_hpre(uint32_t hpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_HPRE) |
			(hpre << RCC_CFGR_HPRE_SHIFT);

}

/**@}*/

