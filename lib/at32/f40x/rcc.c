/** @defgroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@brief <b>libopencm3 AT32F40x Reset and Clock Control</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>
@author @htmlonly &copy; @endhtmlonly 2022 Sergey Bolshakov \<beefdeadbeef@gmail.com\>

@date 10 November 2022

This library supports the Reset and Clock Control System in the AT32F40x
series of ARM Cortex Microcontrollers by Arterytek.

Clock settings and resets for many peripherals are given here rather than in
the corresponding peripheral library.

The library also provides a number of common configurations for the processor
system clock. Not all possible configurations are included.

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2022 Sergey Bolshakov <beefdeadbeef@gmail.com>
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

@param[in] clk System Clock Selection @ref rcc_cfgr_scs
*/

void rcc_set_sysclk_source(uint32_t clk)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW) |
		(clk << RCC_CFGR_SW_SHIFT);
}

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
/** @brief RCC Set the PLL Clock Source.

@note This only has effect when the PLL is disabled.

@param[in] pllsrc PLL clock source @ref rcc_cfgr_pcs
*/

void rcc_set_pll_source(uint32_t pllsrc)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLSRC) |
		(pllsrc << 16);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC HSE Frequency Divider.

@param[in] xtpre Puts HSE clock thru divider before PLL @ref rcc_cfgr_pllxtpre
*/

void rcc_set_hse_xtpre(uint32_t xtpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PLLXTPRE) |
		(xtpre ? RCC_CFGR_PLLXTPRE : 0);
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
		RCC_BDCR &= ~((1 << 9) | (1 << 8));
		RCC_BDCR |= (1 << 9) | (1 << 8);
		break;
	case RCC_PLL:
	case RCC_HSI:
		/* Unusable clock source, here to prevent warnings. */
		/* Turn off clock sources to RTC. */
		RCC_BDCR &= ~((1 << 8) | (1 << 9));
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Setup the A/D Clock

The ADC's have a common clock prescale setting.

@param[in] adcpre Prescale divider taken from @ref rcc_cfgr_adcpre
*/

void rcc_set_adcpre(uint32_t adcpre)
{
	RCC_CFGR = (RCC_CFGR & ~(RCC_CFGR_ADCPRE2 | RCC_CFGR_ADCPRE)) |
		((adcpre & 0x4) ? RCC_CFGR_ADCPRE2 : 0) |
		((adcpre & 0x3) << RCC_CFGR_ADCPRE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB2 Prescale Factor.

@param[in] ppre2 APB2 prescale factor @ref rcc_cfgr_apb2pre
*/

void rcc_set_ppre2(uint32_t ppre2)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PPRE2) |
		(ppre2 << RCC_CFGR_PPRE2_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB1 Prescale Factor.

@note The APB1 clock frequency must not exceed 36MHz.

@param[in] ppre1 APB1 prescale factor @ref rcc_cfgr_apb1pre
*/

void rcc_set_ppre1(uint32_t ppre1)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PPRE1) |
		(ppre1 << RCC_CFGR_PPRE1_SHIFT);

}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the AHB Prescale Factor.

@param[in] hpre AHB prescale factor @ref rcc_cfgr_ahbpre
*/

void rcc_set_hpre(uint32_t hpre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_HPRE) |
		(hpre << RCC_CFGR_HPRE_SHIFT);

}

/*---------------------------------------------------------------------------*/
/** @brief Set RCC HSI divider.

@param[in] hsidiv HSI divider @ref rcc_cfgr3_hsidiv
*/

void rcc_set_hsi_div(uint32_t hsidiv)
{
	RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_HSIDIV) |
		(hsidiv ? RCC_CFGR3_HSIDIV : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief Set RCC HSI to SYSCLK selector.

@param[in] hsisclk HSI to SYSCLK selector @ref rcc_cfgr5_hsi_sclk
*/

void rcc_set_hsi_sclk(uint32_t hsisclk)
{
	RCC_CFGR5 = (RCC_CFGR5 & ~RCC_CFGR5_HSI_SCLK) |
		(hsisclk ? RCC_CFGR5_HSI_SCLK : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the USB Clock Source.

@note This only has effect when the USB is disabled.

@param[in] ocs USB clock source, PLL or HSI. @ref rcc_cfgr5_usb_src
*/

void rcc_set_usb_clock_source(enum rcc_osc osc)
{
	RCC_CFGR5 = (RCC_CFGR5 & ~RCC_CFGR5_HSI_USB_SRC) |
		(osc == RCC_HSI ? RCC_CFGR5_HSI_USB_SRC : 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the USB Prescale Factor.

@note These bits cannot be reset while the USB clock is enabled.

@param[in] usbpre USB prescale factor @ref rcc_cfgr_usbpre
*/

void rcc_set_usbpre(uint32_t usbpre)
{
	RCC_CFGR = (RCC_CFGR & ~(RCC_CFGR_USBPRE2 | RCC_CFGR_USBPRE)) |
		((usbpre & 0x4) ? RCC_CFGR_USBPRE2 : 0) |
		((usbpre & 0x3) << RCC_CFGR_USBPRE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the MCO Clock Source.

@param[in] mcosrc MCO clock source. @ref rcc_cfgr_mco
*/

void rcc_set_mco_source(uint32_t mcosrc)
{
	/* MCO[3] lives here */
	RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_MCO3) |
		((mcosrc & 0x8) ? RCC_CFGR3_MCO3 : 0);
	/* feed MCO[2:0] to common code */
	rcc_set_mco(mcosrc & RCC_CFGR_MCO_MASK);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the MCO Clock Divider.

@param[in] mcodiv MCO clock divider. @ref rcc_cfgr_mco
*/

void rcc_set_mcodiv(uint32_t mcodiv)
{
	RCC_CFGR3 = (RCC_CFGR3 & ~RCC_CFGR3_MCO_DIV) |
		(mcodiv < RCC_CFGR3_MCO_DIV_SHIFT);
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

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the USART at base specified.
 * @param usart Base address of USART to get clock frequency for.
 */
uint32_t rcc_get_usart_clk_freq(uint32_t usart)
{
	if (usart >= USART2_BASE && usart <= UART5_BASE) {
		return rcc_apb1_frequency;
	} else {
		return rcc_apb2_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the Timer at base specified.
 * @param timer Base address of TIM to get clock frequency for.
 */
uint32_t rcc_get_timer_clk_freq(uint32_t timer)
{
	/* Handle APB1 timer clocks. */
	if (timer >= TIM2_BASE && timer <= TIM14_BASE) {
		uint8_t ppre1 = (RCC_CFGR >> RCC_CFGR_PPRE1_SHIFT) & RCC_CFGR_PPRE1_MASK;
		return (ppre1 == RCC_CFGR_PPRE_NODIV) ? rcc_apb1_frequency
			: 2 * rcc_apb1_frequency;
	} else {
		uint8_t ppre2 = (RCC_CFGR >> RCC_CFGR_PPRE2_SHIFT) & RCC_CFGR_PPRE2_MASK;
		return (ppre2 == RCC_CFGR_PPRE_NODIV) ? rcc_apb2_frequency
			: 2 * rcc_apb2_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the I2C device at base specified.
 * @param i2c  Base address of I2C to get clock frequency for.
 */
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c)
{
	if (i2c == I2C3_BASE) {
		return rcc_apb2_frequency;
	} else {
		return rcc_apb1_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the SPI device at base specified.
 * @param spi  Base address of SPI device to get clock frequency for.
 */
uint32_t rcc_get_spi_clk_freq(uint32_t spi) {
        if (spi == SPI1_BASE) {
                return rcc_apb2_frequency;
        } else {
                return rcc_apb1_frequency;
        }
}
/**@}*/
