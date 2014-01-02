/** @defgroup STM32F1xx-rcc-file RCC

@ingroup STM32F1xx

@brief <b>libopencm3 STM32F1xx Reset and Clock Control</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

@date 18 August 2012

This library supports the Reset and Clock Control System in the STM32F1xx
series of ARM Cortex Microcontrollers by ST Microelectronics.

@note Full support for connection line devices is not yet provided.

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

#include <errno.h>
#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/flash.h>

/** Default ppre1 peripheral clock frequency after reset. */
uint32_t rcc_ppre1_frequency = 8000000;
/** Default ppre2 peripheral clock frequency after reset. */
uint32_t rcc_ppre2_frequency = 8000000;

/*---------------------------------------------------------------------------*/
/** @brief RCC Clear the Oscillator Ready Interrupt Flag

Clear the interrupt flag that was set when a clock oscillator became ready to
use.

@param[in] osc enum ::osc_t. Oscillator ID
*/

void rcc_osc_ready_int_clear(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CIR |= RCC_CIR_PLLRDYC;
		break;
	case PLL2:
		RCC_CIR |= RCC_CIR_PLL2RDYC;
		break;
	case PLL3:
		RCC_CIR |= RCC_CIR_PLL3RDYC;
		break;
	case HSE:
		RCC_CIR |= RCC_CIR_HSERDYC;
		break;
	case HSI:
		RCC_CIR |= RCC_CIR_HSIRDYC;
		break;
	case LSE:
		RCC_CIR |= RCC_CIR_LSERDYC;
		break;
	case LSI:
		RCC_CIR |= RCC_CIR_LSIRDYC;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable the Oscillator Ready Interrupt

@param[in] osc enum ::osc_t. Oscillator ID
*/

void rcc_osc_ready_int_enable(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CIR |= RCC_CIR_PLLRDYIE;
		break;
	case PLL2:
		RCC_CIR |= RCC_CIR_PLL2RDYIE;
		break;
	case PLL3:
		RCC_CIR |= RCC_CIR_PLL3RDYIE;
		break;
	case HSE:
		RCC_CIR |= RCC_CIR_HSERDYIE;
		break;
	case HSI:
		RCC_CIR |= RCC_CIR_HSIRDYIE;
		break;
	case LSE:
		RCC_CIR |= RCC_CIR_LSERDYIE;
		break;
	case LSI:
		RCC_CIR |= RCC_CIR_LSIRDYIE;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable the Oscillator Ready Interrupt

@param[in] osc enum ::osc_t. Oscillator ID
*/

void rcc_osc_ready_int_disable(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CIR &= ~RCC_CIR_PLLRDYIE;
		break;
	case PLL2:
		RCC_CIR &= ~RCC_CIR_PLL2RDYIE;
		break;
	case PLL3:
		RCC_CIR &= ~RCC_CIR_PLL3RDYIE;
		break;
	case HSE:
		RCC_CIR &= ~RCC_CIR_HSERDYIE;
		break;
	case HSI:
		RCC_CIR &= ~RCC_CIR_HSIRDYIE;
		break;
	case LSE:
		RCC_CIR &= ~RCC_CIR_LSERDYIE;
		break;
	case LSI:
		RCC_CIR &= ~RCC_CIR_LSIRDYIE;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Read the Oscillator Ready Interrupt Flag

@param[in] osc enum ::osc_t. Oscillator ID
@returns int. Boolean value for flag set.
*/

int rcc_osc_ready_int_flag(osc_t osc)
{
	switch (osc) {
	case PLL:
		return ((RCC_CIR & RCC_CIR_PLLRDYF) != 0);
		break;
	case PLL2:
		return ((RCC_CIR & RCC_CIR_PLL2RDYF) != 0);
		break;
	case PLL3:
		return ((RCC_CIR & RCC_CIR_PLL3RDYF) != 0);
		break;
	case HSE:
		return ((RCC_CIR & RCC_CIR_HSERDYF) != 0);
		break;
	case HSI:
		return ((RCC_CIR & RCC_CIR_HSIRDYF) != 0);
		break;
	case LSE:
		return ((RCC_CIR & RCC_CIR_LSERDYF) != 0);
		break;
	case LSI:
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

/*---------------------------------------------------------------------------*/
/** @brief RCC Wait for Oscillator Ready.

@param[in] osc enum ::osc_t. Oscillator ID
*/

void rcc_wait_for_osc_ready(osc_t osc)
{
	switch (osc) {
	case PLL:
		while ((RCC_CR & RCC_CR_PLLRDY) == 0);
		break;
	case PLL2:
		while ((RCC_CR & RCC_CR_PLL2RDY) == 0);
		break;
	case PLL3:
		while ((RCC_CR & RCC_CR_PLL3RDY) == 0);
		break;
	case HSE:
		while ((RCC_CR & RCC_CR_HSERDY) == 0);
		break;
	case HSI:
		while ((RCC_CR & RCC_CR_HSIRDY) == 0);
		break;
	case LSE:
		while ((RCC_BDCR & RCC_BDCR_LSERDY) == 0);
		break;
	case LSI:
		while ((RCC_CSR & RCC_CSR_LSIRDY) == 0);
		break;
	}
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

@param[in] osc enum ::osc_t. Oscillator ID
*/

void rcc_osc_on(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case PLL2:
		RCC_CR |= RCC_CR_PLL2ON;
		break;
	case PLL3:
		RCC_CR |= RCC_CR_PLL3ON;
		break;
	case HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case LSI:
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

@param[in] osc enum ::osc_t. Oscillator ID
*/

void rcc_osc_off(osc_t osc)
{
	switch (osc) {
	case PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case PLL2:
		RCC_CR &= ~RCC_CR_PLL2ON;
		break;
	case PLL3:
		RCC_CR &= ~RCC_CR_PLL3ON;
		break;
	case HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case LSI:
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
/** @brief RCC Enable Bypass.

Enable an external clock to bypass the internal clock (high speed and low speed
clocks only). The external clock must be enabled (see @ref rcc_osc_on) and the
internal clock must be disabled (see @ref rcc_osc_off) for this to have effect.

@note The LSE clock is in the backup domain and cannot be bypassed until the
backup domain write protection has been removed (see @ref
pwr_disable_backup_domain_write_protect).

@param[in] osc enum ::osc_t. Oscillator ID. Only HSE and LSE have effect.
*/

void rcc_osc_bypass_enable(osc_t osc)
{
	switch (osc) {
	case HSE:
		RCC_CR |= RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_BDCR |= RCC_BDCR_LSEBYP;
		break;
	case PLL:
	case PLL2:
	case PLL3:
	case HSI:
	case LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable Bypass.

Re-enable the internal clock (high speed and low speed clocks only). The
internal clock must be disabled (see @ref rcc_osc_off) for this to have effect.

@note The LSE clock is in the backup domain and cannot have bypass removed
until the backup domain write protection has been removed (see @ref
pwr_disable_backup_domain_write_protect) or the backup domain has been reset
(see @ref rcc_backupdomain_reset).

@param[in] osc enum ::osc_t. Oscillator ID. Only HSE and LSE have effect.
*/

void rcc_osc_bypass_disable(osc_t osc)
{
	switch (osc) {
	case HSE:
		RCC_CR &= ~RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEBYP;
		break;
	case PLL:
	case PLL2:
	case PLL3:
	case HSI:
	case LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Enable Peripheral Clocks.

Enable the clock on particular peripherals. There are three registers involved,
each one controlling the enabling of clocks associated with the AHB, APB1 and
APB2 respectively. Several peripherals could be enabled simultaneously <em>only
if they are controlled by the same register</em>.

@param[in] *reg Unsigned int32. Pointer to a Clock Enable Register
			 (either RCC_AHBENR, RCC_APB1ENR or RCC_APB2ENR)
@param[in] en Unsigned int32. Logical OR of all enables to be set
@li If register is RCC_AHBER, from @ref rcc_ahbenr_en
@li If register is RCC_APB1ENR, from @ref rcc_apb1enr_en
@li If register is RCC_APB2ENR, from @ref rcc_apb2enr_en
*/

void rcc_peripheral_enable_clock(volatile uint32_t *reg, uint32_t en)
{
	*reg |= en;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable Peripheral Clocks.

Enable the clock on particular peripherals. There are three registers involved,
each one controlling the enabling of clocks associated with the AHB, APB1 and
APB2 respectively. Several peripherals could be disabled simultaneously
<em>only if they are controlled by the same register</em>.

@param[in] *reg Unsigned int32. Pointer to a Clock Enable Register
			 (either RCC_AHBENR, RCC_APB1ENR or RCC_APB2ENR)
@param[in] en Unsigned int32. Logical OR of all enables to be used for
disabling.
@li If register is RCC_AHBER, from @ref rcc_ahbenr_en
@li If register is RCC_APB1ENR, from @ref rcc_apb1enr_en
@li If register is RCC_APB2ENR, from @ref rcc_apb2enr_en
*/

void rcc_peripheral_disable_clock(volatile uint32_t *reg, uint32_t en)
{
	*reg &= ~en;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Reset Peripherals.

Reset particular peripherals. There are three registers involved, each one
controlling reset of peripherals associated with the AHB, APB1 and APB2
respectively. Several peripherals could be reset simultaneously <em>only if
they are controlled by the same register</em>.

@param[in] *reg Unsigned int32. Pointer to a Reset Register
			 (either RCC_AHBENR, RCC_APB1ENR or RCC_APB2ENR)
@param[in] reset Unsigned int32. Logical OR of all resets.
@li If register is RCC_AHBRSTR, from @ref rcc_ahbrstr_rst
@li If register is RCC_APB1RSTR, from @ref rcc_apb1rstr_rst
@li If register is RCC_APB2RSTR, from @ref rcc_apb2rstr_rst
*/

void rcc_peripheral_reset(volatile uint32_t *reg, uint32_t reset)
{
	*reg |= reset;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Remove Reset on Peripherals.

Remove the reset on particular peripherals. There are three registers
involved, each one controlling reset of peripherals associated with the AHB,
APB1 and APB2 respectively. Several peripherals could have the reset removed
simultaneously <em>only if they are controlled by the same register</em>.

@param[in] *reg Unsigned int32. Pointer to a Reset Register
			 (either RCC_AHBENR, RCC_APB1ENR or RCC_APB2ENR)
@param[in] clear_reset Unsigned int32. Logical OR of all resets to be removed:
@li If register is RCC_AHBRSTR, from @ref rcc_ahbrstr_rst
@li If register is RCC_APB1RSTR, from @ref rcc_apb1rstr_rst
@li If register is RCC_APB2RSTR, from @ref rcc_apb2rstr_rst
*/

void rcc_peripheral_clear_reset(volatile uint32_t *reg, uint32_t clear_reset)
{
	*reg &= ~clear_reset;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the System Clock.

@param[in] clk Unsigned int32. System Clock Selection @ref rcc_cfgr_scs
*/

void rcc_set_sysclk_source(uint32_t clk)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 1) | (1 << 0));
	RCC_CFGR = (reg32 | clk);
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul Unsigned int32. PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll_multiplication_factor(uint32_t mul)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 21) | (1 << 20) | (1 << 19) | (1 << 18));
	RCC_CFGR = (reg32 | (mul << 18));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL2 Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul Unsigned int32. PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll2_multiplication_factor(uint32_t mul)
{
	uint32_t reg32;

	reg32 = RCC_CFGR2;
	reg32 &= ~((1 << 11) | (1 << 10) | (1 << 9) | (1 << 8));
	RCC_CFGR2 = (reg32 | (mul << 8));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL3 Multiplication Factor.

@note This only has effect when the PLL is disabled.

@param[in] mul Unsigned int32. PLL multiplication factor @ref rcc_cfgr_pmf
*/

void rcc_set_pll3_multiplication_factor(uint32_t mul)
{
	uint32_t reg32;

	reg32 = RCC_CFGR2;
	reg32 &= ~((1 << 15) | (1 << 14) | (1 << 13) | (1 << 12));
	RCC_CFGR2 = (reg32 | (mul << 12));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the PLL Clock Source.

@note This only has effect when the PLL is disabled.

@param[in] pllsrc Unsigned int32. PLL clock source @ref rcc_cfgr_pcs
*/

void rcc_set_pll_source(uint32_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(1 << 16);
	RCC_CFGR = (reg32 | (pllsrc << 16));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the HSE Frequency Divider used as PLL Clock Source.

@note This only has effect when the PLL is disabled.

@param[in] pllxtpre Unsigned int32. HSE division factor @ref rcc_cfgr_hsepre
*/

void rcc_set_pllxtpre(uint32_t pllxtpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(1 << 17);
	RCC_CFGR = (reg32 | (pllxtpre << 17));
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Setup the A/D Clock

The ADC's have a common clock prescale setting.

@param[in] adcpre uint32_t. Prescale divider taken from @ref rcc_cfgr_adcpre
*/

void rcc_set_adcpre(uint32_t adcpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 14) | (1 << 15));
	RCC_CFGR = (reg32 | (adcpre << 14));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB2 Prescale Factor.

@param[in] ppre2 Unsigned int32. APB2 prescale factor @ref rcc_cfgr_apb2pre
*/

void rcc_set_ppre2(uint32_t ppre2)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 11) | (1 << 12) | (1 << 13));
	RCC_CFGR = (reg32 | (ppre2 << 11));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the APB1 Prescale Factor.

@note The APB1 clock frequency must not exceed 36MHz.

@param[in] ppre1 Unsigned int32. APB1 prescale factor @ref rcc_cfgr_apb1pre
*/

void rcc_set_ppre1(uint32_t ppre1)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 8) | (1 << 9) | (1 << 10));
	RCC_CFGR = (reg32 | (ppre1 << 8));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the AHB Prescale Factor.

@param[in] hpre Unsigned int32. AHB prescale factor @ref rcc_cfgr_ahbpre
*/

void rcc_set_hpre(uint32_t hpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));
	RCC_CFGR = (reg32 | (hpre << 4));
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the USB Prescale Factor.

The prescale factor can be set to 1 (no prescale) for use when the PLL clock is
48MHz, or 1.5 to generate the 48MHz USB clock from a 64MHz PLL clock.

@note This bit cannot be reset while the USB clock is enabled.

@param[in] usbpre Unsigned int32. USB prescale factor @ref rcc_cfgr_usbpre
*/

void rcc_set_usbpre(uint32_t usbpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(1 << 22);
	RCC_CFGR = (reg32 | (usbpre << 22));
}

void rcc_set_prediv1(uint32_t prediv)
{
	uint32_t reg32;
	reg32 = RCC_CFGR2;
	reg32 &= ~(1 << 3) | (1 << 2) | (1 << 1) | (1 << 0);
	RCC_CFGR2 |= (reg32 | prediv);
}

void rcc_set_prediv2(uint32_t prediv)
{
	uint32_t reg32;
	reg32 = RCC_CFGR2;
	reg32 &= ~(1 << 7) | (1 << 6) | (1 << 5) | (1 << 4);
	RCC_CFGR2 |= (reg32 | (prediv << 4));
}

void rcc_set_prediv1_source(uint32_t rccsrc)
{
	RCC_CFGR2 &= ~(1 << 16);
	RCC_CFGR2 |= (rccsrc << 16);
}

void rcc_set_mco(uint32_t mcosrc)
{
	uint32_t reg32;
	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 27) | (1 << 26) | (1 << 25) | (1 << 24));
	RCC_CFGR |= (reg32 | (mcosrc << 24));
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
	return (RCC_CFGR & 0x000c) >> 2;
}

/*---------------------------------------------------------------------------*/
/*
 * These functions are setting up the whole clock system for the most common
 * input clock and output clock configurations.
 */
/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 64MHz from HSI

*/

void rcc_clock_setup_in_hsi_out_64mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(HSI);
	rcc_wait_for_osc_ready(HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);   /* Set. 64MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV8); /* Set.  8MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_DIV2);    /* Set. 32MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);   /* Set. 64MHz Max. 72MHz */

	/*
	 * Sysclk is running with 64MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set the PLL multiplication factor to 16.
	 * 8MHz (internal) * 16 (multiplier) / 2 (PLLSRC_HSI_CLK_DIV2) = 64MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL16);

	/* Select HSI/2 as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ppre1_frequency = 32000000;
	rcc_ppre2_frequency = 64000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 48MHz from HSI

*/

void rcc_clock_setup_in_hsi_out_48mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(HSI);
	rcc_wait_for_osc_ready(HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);	/*Set.48MHz Max.72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV8);	/*Set. 6MHz Max.14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_DIV2);	/*Set.24MHz Max.36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);	/*Set.48MHz Max.72MHz */
	rcc_set_usbpre(RCC_CFGR_USBPRE_PLL_CLK_NODIV);  /*Set.48MHz Max.48MHz */

	/*
	 * Sysclk runs with 48MHz -> 1 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_1WS);

	/*
	 * Set the PLL multiplication factor to 12.
	 * 8MHz (internal) * 12 (multiplier) / 2 (PLLSRC_HSI_CLK_DIV2) = 48MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL12);

	/* Select HSI/2 as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ppre1_frequency = 24000000;
	rcc_ppre2_frequency = 48000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 24MHz from HSI

*/

void rcc_clock_setup_in_hsi_out_24mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(HSI);
	rcc_wait_for_osc_ready(HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV); /* Set. 24MHz Max. 24MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV2); /* Set. 12MHz Max. 12MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_NODIV); /* Set. 24MHz Max. 24MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV); /* Set. 24MHz Max. 24MHz */

	/*
	 * Sysclk is (will be) running with 24MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	/*
	 * Set the PLL multiplication factor to 6.
	 * 8MHz (internal) * 6 (multiplier) / 2 (PLLSRC_HSI_CLK_DIV2) = 24MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL6);

	/* Select HSI/2 as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ppre1_frequency = 24000000;
	rcc_ppre2_frequency = 24000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 24MHz from HSE at 8MHz

*/

void rcc_clock_setup_in_hse_8mhz_out_24mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(HSI);
	rcc_wait_for_osc_ready(HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/* Enable external high-speed oscillator 8MHz. */
	rcc_osc_on(HSE);
	rcc_wait_for_osc_ready(HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);    /* Set. 24MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV2);  /* Set. 12MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_NODIV);    /* Set. 24MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);    /* Set. 24MHz Max. 72MHz */

	/*
	 * Sysclk runs with 24MHz -> 0 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_0WS);

	/*
	 * Set the PLL multiplication factor to 3.
	 * 8MHz (external) * 3 (multiplier) = 24MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL3);

	/* Select HSE as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

	/*
	 * External frequency undivided before entering PLL
	 * (only valid/needed for HSE).
	 */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ppre1_frequency = 24000000;
	rcc_ppre2_frequency = 24000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 72MHz from HSE at 8MHz

*/

void rcc_clock_setup_in_hse_8mhz_out_72mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(HSI);
	rcc_wait_for_osc_ready(HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/* Enable external high-speed oscillator 8MHz. */
	rcc_osc_on(HSE);
	rcc_wait_for_osc_ready(HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);    /* Set. 72MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV8);  /* Set.  9MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_DIV2);     /* Set. 36MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);    /* Set. 72MHz Max. 72MHz */

	/*
	 * Sysclk runs with 72MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set the PLL multiplication factor to 9.
	 * 8MHz (external) * 9 (multiplier) = 72MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL9);

	/* Select HSE as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

	/*
	 * External frequency undivided before entering PLL
	 * (only valid/needed for HSE).
	 */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ppre1_frequency = 36000000;
	rcc_ppre2_frequency = 72000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 24MHz from HSE at 12MHz

*/

void rcc_clock_setup_in_hse_12mhz_out_72mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(HSI);
	rcc_wait_for_osc_ready(HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/* Enable external high-speed oscillator 16MHz. */
	rcc_osc_on(HSE);
	rcc_wait_for_osc_ready(HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);    /* Set. 72MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV6);  /* Set. 12MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_DIV2);     /* Set. 36MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);    /* Set. 72MHz Max. 72MHz */

	/*
	 * Sysclk runs with 72MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set the PLL multiplication factor to 9.
	 * 12MHz (external) * 6 (multiplier) / 1 (PLLXTPRE_HSE_CLK) = 72MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL6);

	/* Select HSI as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

	/*
	 * Divide external frequency by 2 before entering PLL
	 * (only valid/needed for HSE).
	 */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ppre1_frequency = 36000000;
	rcc_ppre2_frequency = 72000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 24MHz from HSE at 16MHz

*/

void rcc_clock_setup_in_hse_16mhz_out_72mhz(void)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(HSI);
	rcc_wait_for_osc_ready(HSI);

	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/* Enable external high-speed oscillator 16MHz. */
	rcc_osc_on(HSE);
	rcc_wait_for_osc_ready(HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);    /* Set. 72MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV6);  /* Set. 12MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_DIV2);     /* Set. 36MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);    /* Set. 72MHz Max. 72MHz */

	/*
	 * Sysclk runs with 72MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set the PLL multiplication factor to 9.
	 * 16MHz (external) * 9 (multiplier) / 2 (PLLXTPRE_HSE_CLK_DIV2) = 72MHz
	 */
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL9);

	/* Select HSI as PLL source. */
	rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

	/*
	 * Divide external frequency by 2 before entering PLL
	 * (only valid/needed for HSE).
	 */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK_DIV2);

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ppre1_frequency = 36000000;
	rcc_ppre2_frequency = 72000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set System Clock PLL at 72MHz from HSE at 25MHz

*/

void rcc_clock_setup_in_hse_25mhz_out_72mhz(void)
{
	/* Enable external high-speed oscillator 25MHz. */
	rcc_osc_on(HSE);
	rcc_wait_for_osc_ready(HSE);
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);

	/*
	 * Sysclk runs with 72MHz -> 2 waitstates.
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	flash_set_ws(FLASH_ACR_LATENCY_2WS);

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);    /* Set. 72MHz Max. 72MHz */
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV6);  /* Set. 12MHz Max. 14MHz */
	rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_DIV2);     /* Set. 36MHz Max. 36MHz */
	rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);    /* Set. 72MHz Max. 72MHz */

	/* Set pll2 prediv and multiplier */
	rcc_set_prediv2(RCC_CFGR2_PREDIV2_DIV5);
	rcc_set_pll2_multiplication_factor(RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8);

	/* Enable PLL2 oscillator and wait for it to stabilize */
	rcc_osc_on(PLL2);
	rcc_wait_for_osc_ready(PLL2);

	/* Set pll1 prediv/multiplier, prediv1 src, and usb predivider */
	rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);
	rcc_set_prediv1_source(RCC_CFGR2_PREDIV1SRC_PLL2_CLK);
	rcc_set_prediv1(RCC_CFGR2_PREDIV_DIV5);
	rcc_set_pll_multiplication_factor(RCC_CFGR_PLLMUL_PLL_CLK_MUL9);
	rcc_set_pll_source(RCC_CFGR_PLLSRC_PREDIV1_CLK);
	rcc_set_usbpre(RCC_CFGR_USBPRE_PLL_VCO_CLK_DIV3);

	/* enable PLL1 and wait for it to stabilize */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);

	/* Set the peripheral clock frequencies used */
	rcc_ppre1_frequency = 36000000;
	rcc_ppre2_frequency = 72000000;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Reset the backup domain

The backup domain register is reset to disable all controls.
*/

void rcc_backupdomain_reset(void)
{
	/* Set the backup domain software reset. */
	RCC_BDCR |= RCC_BDCR_BDRST;

	/* Clear the backup domain software reset. */
	RCC_BDCR &= ~RCC_BDCR_BDRST;
}




static void rcc_set_ahb_prescaler(u16 div)
{
	u32 hpre;

	switch (div) {
	case 1:
		hpre = RCC_CFGR_HPRE_SYSCLK_NODIV;
	case 2:
		hpre = RCC_CFGR_HPRE_SYSCLK_DIV2;
		break;
	case 4:
		hpre = RCC_CFGR_HPRE_SYSCLK_DIV4;
		break;
	case 8:
		hpre = RCC_CFGR_HPRE_SYSCLK_DIV8;
		break;
	case 16:
		hpre = RCC_CFGR_HPRE_SYSCLK_DIV16;
		break;
	case 64:
		hpre = RCC_CFGR_HPRE_SYSCLK_DIV64;
		break;
	case 128:
		hpre = RCC_CFGR_HPRE_SYSCLK_DIV128;
		break;
	case 256:
		hpre = RCC_CFGR_HPRE_SYSCLK_DIV256;
		break;
	case 512:
		hpre = RCC_CFGR_HPRE_SYSCLK_DIV512;
		break;
	default:
		return;
	}

	rcc_set_hpre(hpre);
}

static void rcc_set_apb_prescaler(abp_t apb, u8 div)
{
	u32 ppre;

	switch (div) {
	case 1:
		ppre = RCC_CFGR_PPRE1_HCLK_NODIV;
		break;
	case 2:
		ppre = RCC_CFGR_PPRE1_HCLK_DIV2;
		break;
	case 4:
		ppre = RCC_CFGR_PPRE1_HCLK_DIV4;
		break;
	case 8:
		ppre = RCC_CFGR_PPRE1_HCLK_DIV8;
		break;
	case 16:
		ppre = RCC_CFGR_PPRE1_HCLK_DIV16;
		break;
	default:
		return;
	}

	switch (apb) {
	case APB1:
		rcc_set_ppre1(ppre);
		break;
	case APB2:
		rcc_set_ppre2(ppre);
		break;
	}
}

static void rcc_set_adc_prescaler(u8 div)
{
	u8 adcpre;
	switch (div) {
	case 2:
		adcpre = RCC_CFGR_ADCPRE_PCLK2_DIV2;
		break;
	case 4:
		adcpre = RCC_CFGR_ADCPRE_PCLK2_DIV4;
		break;
	case 6:
		adcpre = RCC_CFGR_ADCPRE_PCLK2_DIV6;
		break;
	case 8:
		adcpre = RCC_CFGR_ADCPRE_PCLK2_DIV8;
		break;
	default:
		return;
	}

	rcc_set_adcpre(adcpre);
}

static void rcc_non_cl_set_pll_multiplier(u8 mul)
{
	u32 pllmul;

	switch (mul) {
	case 2:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL2;
		break;
	case 3:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL3;
		break;
	case 4:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL4;
		break;
	case 5:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL5;
		break;
	case 6:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL6;
		break;
	case 7:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL7;
		break;
	case 8:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL8;
		break;
	case 9:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL9;
		break;
	case 10:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL10;
		break;
	case 11:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL11;
		break;
	case 12:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL12;
		break;
	case 13:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL13;
		break;
	case 14:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL14;
		break;
	case 15:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL15;
		break;
	case 16:
		pllmul = RCC_CFGR_PLLMUL_PLL_CLK_MUL16;
		break;
	default:
		return;
	}

	rcc_set_pll_multiplication_factor(pllmul);
}

/*-----------------------------------------------------------------------------*/
/** @brief Setup clock tree for non connectivity line devices

@param[in] clk struct ::rcc_non_cl_clock_tree. Clock tree setup
*/
void rcc_non_cl_init_clock_tree(const struct rcc_non_cl_clock_tree *clk)
{
	int sysclk = -EINVAL;
	int pllclk = -EINVAL;
	bool hsi_is_used = false;

	/*
	   HSE oscillator must have input within the 4-16Mhz range
	 */
	if ((clk->crystal > 0) &&
	    (clk->crystal < 4000000 || sysclk > 16000000))
		return;

	switch (clk->tree.pllclk.parent) {
	case HSE:
		switch (clk->div.pllxtpre) {
		case 1:
			pllclk = clk->crystal * clk->mul.pll;
			break;
		case 2:
			pllclk = clk->crystal * clk->mul.pll / 2;
			break;
		}
		break;
	case HSI:
		pllclk = 4000000 * clk->mul.pll;
		/* When running from HSI frequency cannot
		 * exceed 64Mhz */
		if (pllclk > 64000000)
			return;

		hsi_is_used = true;
		break;
	}

	switch (clk->tree.sysclk.parent) {
	case HSE:
		sysclk = clk->crystal;
		break;
	case HSI:
		sysclk = 8000000;
		hsi_is_used = true;
		break;
	case PLL:
		sysclk = pllclk;
		break;
	}

	if (sysclk < 0)
		return;

	if (clk->tree.pllclk.parent == HSE ||
	    clk->tree.sysclk.parent == HSE) {
		rcc_osc_on(HSE);
		rcc_wait_for_osc_ready(HSE);
		rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);
	} else {
		rcc_osc_on(HSI);
		rcc_wait_for_osc_ready(HSI);
		rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);
	}

	/*
	 * Set prescalers for AHB, ADC, ABP1, ABP2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_ahb_prescaler(clk->div.ahb);
	rcc_set_adc_prescaler(clk->div.adc);
	rcc_set_apb_prescaler(APB1, clk->div.apb1);
	rcc_set_apb_prescaler(APB2, clk->div.apb2);

	/*
	 * 0WS from 0-24MHz
	 * 1WS from 24-48MHz
	 * 2WS from 48-72MHz
	 */
	if (sysclk <= 24000000)
		flash_set_ws(FLASH_ACR_LATENCY_0WS);
	else if (sysclk <= 48000000)
		flash_set_ws(FLASH_ACR_LATENCY_1WS);
	else if (sysclk <= 72000000)
		flash_set_ws(FLASH_ACR_LATENCY_2WS);

	if (clk->tree.pllclk.parent != -EINVAL) {
		rcc_non_cl_set_pll_multiplier(clk->mul.pll);

		switch (clk->tree.pllclk.parent) {
		case HSE:
			rcc_set_pll_source(RCC_CFGR_PLLSRC_HSE_CLK);

			switch (clk->div.pllxtpre) {
			case 1:
				rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK);
				break;
			case 2:
				rcc_set_pllxtpre(RCC_CFGR_PLLXTPRE_HSE_CLK_DIV2);
				break;
			}
			break;
		case HSI:
			rcc_set_pll_source(RCC_CFGR_PLLSRC_HSI_CLK_DIV2);
			break;
		}

		rcc_osc_on(PLL);
		rcc_wait_for_osc_ready(PLL);
	}

	switch (clk->tree.sysclk.parent) {
	case HSE:
		rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSECLK);
		break;
	case PLL:
		rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_PLLCLK);
		break;
	}

	switch (clk->tree.mcoclk.parent) {
	case PLL:
		rcc_set_mco(RCC_CFGR_MCO_PLLCLK_DIV2);
		break;
	case HSI:
		rcc_set_mco(RCC_CFGR_MCO_HSICLK);
		break;
	case HSE:
		rcc_set_mco(RCC_CFGR_MCO_HSECLK);
		break;
	case SYSCLK:
		rcc_set_mco(RCC_CFGR_MCO_SYSCLK);
		break;
	default:
		rcc_set_mco(RCC_CFGR_MCO_NOCLK);
		break;
	}

	/* Set the peripheral clock frequencies used */
	rcc_ppre1_frequency = sysclk / (clk->div.apb1 * clk->div.ahb);
	rcc_ppre2_frequency = sysclk / (clk->div.apb2 * clk->div.ahb);

	if (!hsi_is_used && !clk->leave_hsi_running)
		rcc_osc_off(HSI);
}

/**@}*/
