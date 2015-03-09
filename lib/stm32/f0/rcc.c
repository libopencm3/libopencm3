/** @defgroup STM32F0xx-rcc-file RCC
 *
 * @ingroup STM32F0xx
 *
 * @brief <b>libopencm3 STM32F0xx Reset and Clock Control</b>
 *
 * @version 1.1.0
 *
 * @date 22 Dec 2014
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

/* Set the default clock frequencies */
uint32_t rcc_ahb_frequency = 8000000; /* 8MHz after reset */
uint32_t rcc_apb1_frequency = 8000000; /* 8MHz after reset */
uint32_t rcc_lse_frequency = 32768; /* LSE frequency */

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
	case HSI48:
		RCC_CIR |= RCC_CIR_HSI48RDYC;
		break;
	case HSI14:
		RCC_CIR |= RCC_CIR_HSI14RDYC;
		break;
	case HSI:
		RCC_CIR |= RCC_CIR_HSIRDYC;
		break;
	case HSE:
		RCC_CIR |= RCC_CIR_HSERDYC;
		break;
	case PLL:
		RCC_CIR |= RCC_CIR_PLLRDYC;
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
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */

void rcc_osc_ready_int_enable(enum rcc_osc osc)
{
	switch (osc) {
	case HSI48:
		RCC_CIR |= RCC_CIR_HSI48RDYIE;
		break;
	case HSI14:
		RCC_CIR |= RCC_CIR_HSI14RDYIE;
		break;
	case HSI:
		RCC_CIR |= RCC_CIR_HSIRDYIE;
		break;
	case HSE:
		RCC_CIR |= RCC_CIR_HSERDYIE;
		break;
	case PLL:
		RCC_CIR |= RCC_CIR_PLLRDYIE;
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
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */

void rcc_osc_ready_int_disable(enum rcc_osc osc)
{
	switch (osc) {
	case HSI48:
		RCC_CIR &= ~RCC_CIR_HSI48RDYC;
		break;
	case HSI14:
		RCC_CIR &= ~RCC_CIR_HSI14RDYC;
		break;
	case HSI:
		RCC_CIR &= ~RCC_CIR_HSIRDYC;
		break;
	case HSE:
		RCC_CIR &= ~RCC_CIR_HSERDYC;
		break;
	case PLL:
		RCC_CIR &= ~RCC_CIR_PLLRDYC;
		break;
	case LSE:
		RCC_CIR &= ~RCC_CIR_LSERDYC;
		break;
	case LSI:
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
	case HSI48:
		return (RCC_CIR & RCC_CIR_HSI48RDYF) != 0;
		break;
	case HSI14:
		return (RCC_CIR & RCC_CIR_HSI14RDYF) != 0;
		break;
	case HSI:
		return (RCC_CIR & RCC_CIR_HSIRDYF) != 0;
		break;
	case HSE:
		return (RCC_CIR & RCC_CIR_HSERDYF) != 0;
		break;
	case PLL:
		return (RCC_CIR & RCC_CIR_PLLRDYF) != 0;
		break;
	case LSE:
		return (RCC_CIR & RCC_CIR_LSERDYF) != 0;
		break;
	case LSI:
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

/*---------------------------------------------------------------------------*/
/** @brief RCC Wait for Oscillator Ready.
 *
 * @param[in] osc enum ::osc_t. Oscillator ID
 */

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case HSI48:
		while ((RCC_CIR & RCC_CIR_HSI48RDYF) != 0);
		break;
	case HSI14:
		while ((RCC_CIR & RCC_CIR_HSI14RDYF) != 0);
		break;
	case HSI:
		while ((RCC_CIR & RCC_CIR_HSIRDYF) != 0);
		break;
	case HSE:
		while ((RCC_CIR & RCC_CIR_HSERDYF) != 0);
		break;
	case PLL:
		while ((RCC_CIR & RCC_CIR_PLLRDYF) != 0);
		break;
	case LSE:
		while ((RCC_CIR & RCC_CIR_LSERDYF) != 0);
		break;
	case LSI:
		while ((RCC_CIR & RCC_CIR_LSIRDYF) != 0);
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
 * @param[in] osc enum ::osc_t. Oscillator ID
 */

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case HSI48:
		RCC_CR2 |= RCC_CR2_HSI48ON;
		break;
	case HSI14:
		RCC_CR2 |= RCC_CR2_HSI14ON;
		break;
	case HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case LSE:
		RCC_BDCR |= RCC_BDCR_LSEON;
		break;
	case LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	case PLL:
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
	case HSI48:
		RCC_CR2 &= ~RCC_CR2_HSI48ON;
		break;
	case HSI14:
		RCC_CR2 &= ~RCC_CR2_HSI14ON;
		break;
	case HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEON;
		break;
	case LSI:
		RCC_CSR &= ~RCC_CSR_LSION;
		break;
	case PLL:
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
/** @brief RCC Enable Bypass.
 *
 * Enable an external clock to bypass the internal clock (high speed and low
 * speed clocks only). The external clock must be enabled (see @ref rcc_osc_on)
 * and the internal clock must be disabled (see @ref rcc_osc_off) for this to
 * have effect.
 *
 * @param[in] osc enum ::osc_t. Oscillator ID. Only HSE and LSE have effect.
 */

void rcc_osc_bypass_enable(enum rcc_osc osc)
{
	switch (osc) {
	case HSE:
		RCC_CR |= RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_BDCR |= RCC_BDCR_LSEBYP;
		break;
	case HSI48:
	case HSI14:
	case HSI:
	case LSI:
	case PLL:
		/* Do nothing */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Disable Bypass.
 *
 * Re-enable the internal clock (high speed and low speed clocks only). The
 * internal clock must be disabled (see @ref rcc_osc_off) for this to have
 * effect.
 *
 *
 * @param[in] osc enum ::osc_t. Oscillator ID. Only HSE and LSE have effect.
 */

void rcc_osc_bypass_disable(enum rcc_osc osc)
{
	switch (osc) {
	case HSE:
		RCC_CR &= ~RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEBYP;
		break;
	case HSI48:
	case HSI14:
	case PLL:
	case HSI:
	case LSI:
		/* Do nothing */
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
	case PLL:
		RCC_CFGR3 |= RCC_CFGR3_USBSW;
		break;
	case HSI48:
		RCC_CFGR3 &= ~RCC_CFGR3_USBSW;
		break;
	default:
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
/** @brief RCC Set the APB Prescale Factor.
 *
 * @note The APB1 clock frequency must not exceed 36MHz.
 *
 * @param[in] ppre1 APB prescale factor
 *
 * Note this will set `rcc_apb1_frequency` correctly
 * the first time you use it, but if you use it multiple times you will confuse 
 * the library about the frequency of the clocks.
 *
 * If you must call it multiple times, after initially setting up the clocks
 * save the values of the AHB and APB frequencies, and then restore them each
 * time before you call this function.
 */
void rcc_set_ppre(uint32_t ppre)
{
	int div;

	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PPRE) |
		   ((ppre & RCC_CFGR_PPRE_MASK) << RCC_CFGR_PPRE_SHIFT);
	div = ((ppre & RCC_CFGR_PPRE_MASK) < 4) ? 1 : 1 << ((ppre & 0x3) + 1);
	rcc_apb1_frequency = rcc_ahb_frequency / div;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the AHB Prescale Factor.
 *
 * @param[in] hpre Unsigned int32. AHB prescale factor @ref rcc_cfgr_ahbpre
 *
 * Note this will set `rcc_ahb_frequency` and `rcc_apb1_frequency` correctly
 * the first time you use it, but if you use it multiple times you will confuse 
 * the library about the frequency of the clocks.
 *
 * If you must call it multiple times, after initially setting up the clocks
 * save the values of the AHB and APB frequencies, and then restore them each
 * time before you call this function.
 */

void rcc_set_hpre(uint32_t hpre)
{
	int div;

	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_HPRE) | 
		   ((hpre & RCC_CFGR_HPRE_MASK) << RCC_CFGR_HPRE_SHIFT);
	div = hpre & RCC_CFGR_HPRE_MASK;
	if (div > 7) {
		div = div & 0x7; // Lower 3 bits
		if (div < 4) {
			rcc_ahb_frequency = rcc_ahb_frequency / (1 << (div + 1));
		} else {
			rcc_ahb_frequency = rcc_ahb_frequency / (1 << (div + 6));
		}
		div = (RCC_CFGR >> RCC_CFGR_PPRE_SHIFT) & RCC_CFGR_PPRE_MASK;
		div = (div < 4) ? 1 : 1 << ((div & 0x3) + 1);
		rcc_apb1_frequency = rcc_ahb_frequency / div;
	}
}

/*
 * Note calling this will confuse the library about the values of the clocks.
 */
void rcc_set_prediv(uint32_t prediv)
{
	RCC_CFGR2 = (RCC_CFGR2 & ~RCC_CFGR2_PREDIV_MASK) | prediv;
}


void rcc_set_mco(uint32_t mcosrc)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_MCO) | mcosrc;
}

/*---------------------------------------------------------------------------*/
/** @brief RCC Get the USB Clock Source.
 *
 * @returns ::osc_t USB clock source:
 */
 
enum rcc_osc rcc_usb_clock_source(void)
{
	return (RCC_CFGR3 & RCC_CFGR3_USBSW) ? PLL : HSI48;
}

/*---------------------------------------------------------------------------*/
/** @brief Compute frequency the PLL will generate. 
 *
 * @param[in] hse_frequency
 *
 * @returns frequency
 *
 * This function looks at the PREDIV value, the PLL flags and multiplier
 * and then computes the frequency the PLL will generate. If the source is
 * HSE it requires the crystal frequency in order to make an accurate calculation.
 *
 */
uint32_t rcc_get_pll_frequency(uint32_t hse_frequency) {
	uint32_t pll_freq;
	uint32_t	prediv;

	prediv = ((RCC_CFGR2 >> RCC_CFGR2_PREDIV_SHIFT) & RCC_CFGR2_PREDIV_MASK) + 1;
	
	switch ((RCC_CFGR >> RCC_CFGR_PLLSRC_SHIFT) & RCC_CFGR_PLLSRC_MASK) {
		case 0: pll_freq = (RCC_HSI_FREQUENCY >> 1); // HSI/2
			break;
		case 1: pll_freq = RCC_HSI_FREQUENCY / prediv;
			break;
		case 2: pll_freq = hse_frequency / prediv;
			break;
		case 3: pll_freq = RCC_HSI48_FREQUENCY / prediv;
			break;
	}

	pll_freq = pll_freq * (((RCC_CFGR >> RCC_CFGR_PLLMUL_SHIFT) & RCC_CFGR_PLLMUL_MASK) + 2);
	return pll_freq;
}

/*---------------------------------------------------------------------------*/
/** 
 * @brief RCC Set the System Clock Source.
 *
 * @param[in] clk_src A `rcc_osc` value for the desired clock source
 *
 * This function will set the system clock to the desired clock source
 * and wait for that setting to take effect. Valid values for the clock
 * source are `HSI`, `HSE`, `PLL`, and `HSI48`. 
 */

void rcc_set_sysclk(enum rcc_osc clk_src)
{
	uint32_t	clk = RCC_CFGR_SW_HSI;

	switch (clk_src) {
	case HSI:
		clk = RCC_CFGR_SW_HSI;
		break;
	case HSE:
		clk = RCC_CFGR_SW_HSE;
		break;
	case PLL:
		clk = RCC_CFGR_SW_PLL;
		break;
	case HSI48:
		clk = RCC_CFGR_SW_HSI48;
		break;
	default:
		/* do nothing */
		return;
	}
	/* select the clock, and then wait for it to take effect */
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_SW_MASK) | clk;
	while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) != clk) ;
}

/*---------------------------------------------------------------------------*/
/**
 * @brief Return the current system clock
 *
 * This function queries the configuration register for the current system
 * clock and then returns the `rcc_osc` equivalent value.
 *
 * @returns system clock
 */
enum rcc_osc rcc_get_sysclk(void) {
	uint32_t clk_bits = (RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK;

	switch (clk_bits) {
		case 1:
			return HSE;
		case 2:
			return PLL;
		case 3:
			return HSI48;
		default:
			return HSI;
	}
}


/*---------------------------------------------------------------------------*/
/**
 * @brief Configure the F0 HSI Clock
 *
 * @param[in] freq frequency, (either 8000000 or 48000000)
 *
 * This function sets the chip to use the HSI (internal) clock for
 * the system clock. It checks to see if its already set so you can
 * call it "just in case" if you want to be sure you will have a clock
 * running when you fiddle with the osciallators.
 * 
 * You have the choice of the 8Mhz HSI clock or the 48Mhz HSI48 clock.
 */
void rcc_hsi_clock_setup(uint32_t freq) {
	enum rcc_osc target = HSI;
	if (freq == RCC_HSI48_FREQUENCY) {
		target = HSI48;
	}
	if (rcc_get_sysclk() == target) {
		return; /* already running on HSI */
	}
	rcc_osc_on(target);
	rcc_wait_for_osc_ready(target);
	/* need a 1WS for flash if running at 48Mhz */
	flash_set_ws((target == HSI48) ? 1 : 0);

	rcc_set_sysclk(target);
	rcc_set_hpre(RCC_CFGR_HPRE_DIV_NONE);
	rcc_set_ppre(RCC_CFGR_PPRE_DIV_NONE);
	rcc_ahb_frequency = (target == HSI) ? RCC_HSI_FREQUENCY : RCC_HSI48_FREQUENCY;
	rcc_apb1_frequency = rcc_ahb_frequency;
}

/*---------------------------------------------------------------------------*/
/**
 * @brief Configure the F0 HSE Clock
 *
 * @param[in] frequency This is the frequency of the external clock
 *
 * Set the system clock to an HSE source. Also sets the APB clock for
 * the peripheral routines.
 */
void rcc_hse_clock_setup(uint32_t frequency) {
	/* Switch to HSI if not there */
	rcc_hsi_clock_setup(RCC_HSI_FREQUENCY);
	rcc_osc_on(HSE);
	rcc_wait_for_osc_ready(HSE);

	/* need a 1WS for flash if running > 24Mhz */
	flash_set_ws((frequency > 24000000) ? 1 : 0);

	rcc_set_sysclk(HSE);
	rcc_set_hpre(RCC_CFGR_HPRE_DIV_NONE);
	rcc_set_ppre(RCC_CFGR_PPRE_DIV_NONE);
	rcc_ahb_frequency = frequency;
	rcc_apb1_frequency = frequency;
}

/*---------------------------------------------------------------------------*/
/**
 * @brief Configure the F0 PLL Clock
 *
 * @param[in] pllbits These bits provide information about how the clock should be set up
 * @param[in] base_freq This is the frequency of the source clock to the PLL
 *
 * This function will set the PLL register to generate a clock and set the system clock to
 * the PLL. This is typically used when you want to run the chip at a faster internal clock
 * rate than either the 8Mhz HSI or an external crystal provides. Note that `pllbits` is
 * an encoded value using the `RCC_CFGR_PLLBITS` macro.
 */

void rcc_pll_clock_setup(uint32_t pllbits, uint32_t base_freq) {

	uint32_t	freq;

	/* Switch to HSI only for now */
	rcc_hsi_clock_setup(RCC_HSI_FREQUENCY);

	/* Turn off the PLL */
	rcc_osc_off(PLL);

	/* Configure source as HSE/HSI/HSI48, multiplier is as passed */
	RCC_CFGR &= ~(RCC_CFGR_PLLBITS_MASK);
	RCC_CFGR |= (pllbits & RCC_CFGR_PLLBITS_MASK);

	RCC_CFGR2 &= ~RCC_CFGR2_PREDIV_MASK;
	RCC_CFGR2 |= pllbits & RCC_CFGR2_PREDIV_MASK;

	/* Figure out what the frequency will be */
	freq = rcc_get_pll_frequency(base_freq);
	/* Add a flash wait state if clock is > 24Mhz */
	flash_set_ws((freq > 24000000) ? 1 : 0);

	/* If PLL input is HSE, then turn it on first */
	switch ((pllbits >> RCC_CFGR_PLLSRC_SHIFT) & RCC_CFGR_PLLSRC_MASK) {
		case 1:
			rcc_osc_on(HSE);
			rcc_wait_for_osc_ready(HSE);
			break;
		case 3:
			rcc_osc_on(HSI48);
			rcc_wait_for_osc_ready(HSI48);
			break;
		default:
			break;
	}

	/* Now turn on the PLL and wait for it to spin up */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);
	rcc_set_sysclk(PLL);
	rcc_ahb_frequency = rcc_get_pll_frequency(base_freq);
	rcc_apb1_frequency = rcc_ahb_frequency;
}

/* Deprecated */
void rcc_clock_setup_in_hsi_out_8mhz(void)
{
	rcc_pll_clock_setup(RCC_8MHZ_HSI_8MHZ_PLL, RCC_HSI_FREQUENCY);
}

void rcc_clock_setup_in_hsi_out_16mhz(void)
{
	rcc_pll_clock_setup(RCC_8MHZ_HSI_16MHZ_PLL, RCC_HSI_FREQUENCY);
}

void rcc_clock_setup_in_hsi_out_24mhz(void)
{
	rcc_pll_clock_setup(RCC_8MHZ_HSI_24MHZ_PLL, RCC_HSI_FREQUENCY);
}

void rcc_clock_setup_in_hsi_out_32mhz(void)
{
	rcc_pll_clock_setup(RCC_8MHZ_HSI_32MHZ_PLL, RCC_HSI_FREQUENCY);
}

void rcc_clock_setup_in_hsi_out_40mhz(void)
{
	rcc_pll_clock_setup(RCC_8MHZ_HSI_40MHZ_PLL, RCC_HSI_FREQUENCY);
}

void rcc_clock_setup_in_hsi_out_48mhz(void)
{
	rcc_pll_clock_setup(RCC_8MHZ_HSI_48MHZ_PLL, RCC_HSI_FREQUENCY);
}

/**@}*/

