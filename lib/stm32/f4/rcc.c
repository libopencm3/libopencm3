/** @defgroup rcc_file RCC
 *
 * @ingroup STM32F4xx
 *
 * @section rcc_f4_api_ex Reset and Clock Control API.
 *
 * @brief <b>libopencm3 STM32F4xx Reset and Clock Control</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2013 Frantisek Burian <BuFran at seznam.cz>
 *
 * @date 18 Jun 2013
 *
 * This library supports the Reset and Clock Control System in the STM32 series
 * of ARM Cortex Microcontrollers by ST Microelectronics.
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

#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/flash.h>

/**@{*/

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency = 16000000;
uint32_t rcc_apb1_frequency = 16000000;
uint32_t rcc_apb2_frequency = 16000000;

void rcc_osc_ready_int_clear(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		RCC_CIR |= RCC_CIR_PLLRDYC;
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

void rcc_osc_ready_int_enable(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		RCC_CIR |= RCC_CIR_PLLRDYIE;
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

void rcc_osc_ready_int_disable(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		RCC_CIR &= ~RCC_CIR_PLLRDYIE;
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

int rcc_osc_ready_int_flag(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		return ((RCC_CIR & RCC_CIR_PLLRDYF) != 0);
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

void rcc_css_int_clear(void)
{
	RCC_CIR |= RCC_CIR_CSSC;
}

int rcc_css_int_flag(void)
{
	return ((RCC_CIR & RCC_CIR_CSSF) != 0);
}

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		while ((RCC_CR & RCC_CR_PLLRDY) == 0);
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

void rcc_wait_for_sysclk_status(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		while (((RCC_CFGR >> 2) & 0x3) != RCC_CFGR_SW_PLL);
		break;
	case HSE:
		while (((RCC_CFGR >> 2) & 0x3) != RCC_CFGR_SW_HSE);
		break;
	case HSI:
		while (((RCC_CFGR >> 2) & 0x3) != RCC_CFGR_SW_HSI);
		break;
	default:
		/* Shouldn't be reached. */
		break;
	}
}

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		RCC_CR |= RCC_CR_PLLON;
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

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case PLL:
		RCC_CR &= ~RCC_CR_PLLON;
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

void rcc_css_enable(void)
{
	RCC_CR |= RCC_CR_CSSON;
}

void rcc_css_disable(void)
{
	RCC_CR &= ~RCC_CR_CSSON;
}

void rcc_osc_bypass_enable(enum rcc_osc osc)
{
	switch (osc) {
	case HSE:
		RCC_CR |= RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_BDCR |= RCC_BDCR_LSEBYP;
		break;
	case PLL:
	case HSI:
	case LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

void rcc_osc_bypass_disable(enum rcc_osc osc)
{
	switch (osc) {
	case HSE:
		RCC_CR &= ~RCC_CR_HSEBYP;
		break;
	case LSE:
		RCC_BDCR &= ~RCC_BDCR_LSEBYP;
		break;
	case PLL:
	case HSI:
	case LSI:
		/* Do nothing, only HSE/LSE allowed here. */
		break;
	}
}

/*
 */
void rcc_set_sysclk(enum rcc_osc clk) {
	uint32_t clk_bits = RCC_CFGR_SW_HSI;
	switch (clk) {
		case HSI:
			clk_bits = RCC_CFGR_SW_HSI;
			break;
		case HSE:
			clk_bits = RCC_CFGR_SW_HSE;
			break;
		case PLL:
			clk_bits = RCC_CFGR_SW_PLL;
			break;
		default:
			clk_bits = RCC_CFGR_SW_HSI;
			break;
	}
	RCC_CFGR = (RCC_CFGR & (~RCC_CFGR_SW_MASK)) |
			   (clk_bits & RCC_CFGR_SW_MASK);
	/* wait for the switch */
	while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SW_MASK) != clk_bits) ;
}

enum rcc_osc rcc_get_sysclk(void) {
	uint32_t clk_bits = (RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SW_MASK;
	switch (clk_bits) {
		case 1:
			return HSE;
		case 2:
			return PLL;
		case 3:
			return HSI; // Error not sure what to do here
		default:
			return HSI;
	}
}

void rcc_set_sysclk_source(uint32_t clk)
{
	RCC_CFGR = (RCC_CFGR & (~RCC_CFGR_SW_MASK)) |
		   (clk & RCC_CFGR_SW_MASK);
}

void rcc_set_pll_source(uint32_t pllsrc)
{
	RCC_PLLCFGR = (RCC_PLLCFGR & (~RCC_PLLCFGR_PLLSRC)) |
			  ((pllsrc & RCC_PLLCFGR_PLLSRC_MASK) << RCC_PLLCFGR_PLLSRC_SHIFT);
}

void rcc_set_ppre2(uint32_t ppre2)
{
	RCC_CFGR = (RCC_CFGR & (~(RCC_CFGR_PPRE_MASK << RCC_CFGR_PPRE2_SHIFT))) |
		   ((ppre2 & RCC_CFGR_PPRE_MASK) << RCC_CFGR_PPRE2_SHIFT);
}

void rcc_set_ppre1(uint32_t ppre1)
{
	RCC_CFGR = (RCC_CFGR & (~(RCC_CFGR_PPRE_MASK << RCC_CFGR_PPRE1_SHIFT))) |
		   ((ppre1 & RCC_CFGR_PPRE_MASK) << RCC_CFGR_PPRE1_SHIFT);
}

void rcc_set_hpre(uint32_t hpre)
{
	RCC_CFGR = (RCC_CFGR & (~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_SHIFT))) |
		   ((hpre & RCC_CFGR_HPRE_MASK) << RCC_CFGR_HPRE_SHIFT);
}

void rcc_set_rtcpre(uint32_t rtcpre)
{
	RCC_CFGR = (RCC_CFGR & (~(RCC_CFGR_RTCPRE_MASK << RCC_CFGR_RTCPRE_SHIFT))) |
		   ((rtcpre & RCC_CFGR_RTCPRE_MASK) << RCC_CFGR_RTCPRE_SHIFT);
}

void rcc_set_main_pll_hsi(uint32_t pllm, uint32_t plln, uint32_t pllp,
			  uint32_t pllq)
{
	RCC_PLLCFGR = (pllm << RCC_PLLCFGR_PLLM_SHIFT) |
		(plln << RCC_PLLCFGR_PLLN_SHIFT) |
		(((pllp >> 1) - 1) << RCC_PLLCFGR_PLLP_SHIFT) |
		(pllq << RCC_PLLCFGR_PLLQ_SHIFT);
}

void rcc_set_main_pll_hse(uint32_t pllm, uint32_t plln, uint32_t pllp,
			  uint32_t pllq)
{
	RCC_PLLCFGR = (pllm << RCC_PLLCFGR_PLLM_SHIFT) |
		(plln << RCC_PLLCFGR_PLLN_SHIFT) |
		(((pllp >> 1) - 1) << RCC_PLLCFGR_PLLP_SHIFT) |
		RCC_PLLCFGR_PLLSRC |
		(pllq << RCC_PLLCFGR_PLLQ_SHIFT);
}

uint32_t rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return (RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SW_MASK;
}

/*
 * Simple helper to compute backwards from the PLL setting to the value
 * it will generate if turned on as PLL Clock.
 */
uint32_t rcc_get_pll_frequency(uint32_t hse_frequency) {
	uint32_t pll_freq;
	uint32_t pllreg = RCC_PLLCFGR;

	pll_freq = (pllreg & RCC_PLLCFGR_PLLSRC) ? hse_frequency : RCC_HSI_FREQUENCY;
	pll_freq = (pll_freq / ((pllreg >> RCC_PLLCFGR_PLLM_SHIFT) & RCC_PLLCFGR_PLLM_MASK)) *
				((pllreg >> RCC_PLLCFGR_PLLN_SHIFT) & RCC_PLLCFGR_PLLN_MASK);
	switch ((pllreg >> RCC_PLLCFGR_PLLP_SHIFT)  & RCC_PLLCFGR_PLLP_MASK) {
		default:
		case 0: pll_freq = pll_freq >> 1; 	/* (/2) */
			break;
		case 1: pll_freq = pll_freq >> 2;	/* (/4) */
			break;
		case 2: pll_freq = pll_freq / 6;	/* (/6) */
			break;
		case 3: pll_freq = pll_freq >> 3;	/* (/8) */
			break;
	}
	return pll_freq;
}

/*
 * These for the STM32F411RE, others nominally 84Mhz/42Mhz but they seem 
 * to work.
 */
#define RCC_APB2_MAX_CLOCK		100000000
#define RCC_APB1_MAX_CLOCK		50000000

/* These are the constants used in the table in V8 of the F4 reference manual */
#define FLASH_WS_2V7			30000000
#define FLASH_WS_2V4			24000000
#define FLASH_WS_2V1			22000000
#define FLASH_WS_1V8			20000000

/*--------------------------------------------------------------------*/
/** @brief Configure the F4 HSI Clock
 *
 *	This function will set the chip to using the internal HSI clock
 * as its system clock source. This source is fixed at 16Mhz. It will
 * also set the APB1 and APB2 prescalers to 'none'. 
 */
void rcc_hsi_clock_setup(uint32_t frequency __attribute__((unused)))
{
	if (rcc_get_sysclk() == HSI) {
		return; // nothing to do
	}

	/* First make sure we won't halt, switch to generic HSI mode */
	rcc_osc_on(HSI);
	rcc_wait_for_osc_ready(HSI);

	/* Select HSI as SYSCLK source. Reset APB prescalers */
	rcc_set_sysclk(HSI);

	rcc_set_hpre(RCC_CFGR_HPRE_DIV_NONE);
	rcc_set_ppre1(RCC_CFGR_PPRE_DIV_NONE);
	rcc_set_ppre2(RCC_CFGR_PPRE_DIV_NONE);
	rcc_ahb_frequency = RCC_HSI_FREQUENCY;
	rcc_apb1_frequency = RCC_HSI_FREQUENCY;
	rcc_apb2_frequency = RCC_HSI_FREQUENCY;
}

/**
 * @brief Configure the F4 HSE Clock
 *
 * @param[in] clock_speed Frequency of the external clock in Hz
 *
 * This function configures the chip to run with the external
 * crystal as its system clock. It uses the frequency information
 * provided to set up the APB1 and APB2 clocks. 
 */
void rcc_hse_clock_setup(uint32_t clock_speed)
{
	/* insure we're running on internal clock */
	rcc_hsi_clock_setup(RCC_HSI_FREQUENCY);
	rcc_osc_on(HSE);
	rcc_wait_for_osc_ready(HSE);
	
	rcc_set_sysclk(HSE);
	/* Select the crystal as our clock source */
	rcc_set_hpre(RCC_CFGR_HPRE_DIV_NONE);
	rcc_set_ppre1(RCC_CFGR_PPRE_DIV_NONE);
	rcc_set_ppre2(RCC_CFGR_PPRE_DIV_NONE);
	rcc_ahb_frequency = clock_speed;
	rcc_apb1_frequency = clock_speed;
	rcc_apb2_frequency = clock_speed;
}
	

/**
 * @brief Configure the F4 PLL Clock
 *
 * @param[in] clock_speed A combination of bits put together by the `RCC_PLLCFGR_BITS` macro
 * @param[in] input_freq The frequency of an external clock (if used)
 *
 * This function will configure the PLL to generate a specific output frequency (generally
 * higher than the input frequency) based on a formula in the data sheet. A typical configuration
 * might be `RCC_16MHZ_HSI_168MHZ_PLL` which would configure the PLL to use the internal
 * 16Mhz high speed clock and configure the PLL to clock the CPU at 168Mhz.
 *
 * In addtion to the core clock speed the function also sets the APB1 and APB2 peripheral clocks
 * to their maximum values. This involves changing prescalers to divide down the system clock
 * if it is running faster than the peripheral maximums (50Mhz and 100Mhz respectively).
 *
 * The clock setting code assumes >2.6V operation and assumes you are in
 * "normal" power mode (not power saving). If you are running in low power mode you 
 * will need to increase FLASH wait states. 
 */
void rcc_pll_clock_setup(uint32_t clock_speed, uint32_t input_freq)
{
	uint32_t flash_ws;
	uint32_t apb1_div;

	/* First make sure we won't halt, switch to generic HSI mode */
	rcc_hsi_clock_setup(RCC_HSI_FREQUENCY);

	/* At this point we're running on HSI at RCC_HSI_FREQUENCY clocks */
	
	/* Clear old bits, reset source to HSI, then OR in new bits */
	RCC_PLLCFGR = (RCC_PLLCFGR & ~(RCC_PLLCFGR_PLL_MASK | RCC_PLLCFGR_PLLSRC))
								 | clock_speed;

	/* Check to see if we're using the HSE 8Mhz defines */
	if (clock_speed & RCC_PLLCFGR_PLLSRC) {
		rcc_osc_on(HSE);
		rcc_wait_for_osc_ready(HSE);
	}

	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(PLL);
	rcc_wait_for_osc_ready(PLL);

	/* figure out what frequency we are going to be set too */
	rcc_ahb_frequency = rcc_get_pll_frequency(
		(clock_speed & RCC_PLLCFGR_PLLSRC) ? input_freq : RCC_HSI_FREQUENCY);

	/* Set APB2 and APB1 to maximum frequency possible given this HCLK */
	/* NB: Assumes internal clock < 200Mhz, APB2 max 100Mhz */
	if (rcc_ahb_frequency > RCC_APB2_MAX_CLOCK) {
		rcc_set_ppre2(RCC_CFGR_PPRE_DIV_NONE);
		/* rcc_apb2_frequency = freq; */
		rcc_apb2_frequency = rcc_ahb_frequency;
	} else {
		rcc_set_ppre2(RCC_CFGR_PPRE_DIV_2);
		rcc_apb2_frequency = rcc_ahb_frequency >> 1;
	}

	/* This rounds up to the smallest safe divisor */
	apb1_div = (rcc_ahb_frequency + (RCC_APB1_MAX_CLOCK - 1)) / RCC_APB1_MAX_CLOCK;
	switch (apb1_div) {
		case 1:	rcc_set_ppre1(RCC_CFGR_PPRE_DIV_NONE);
			rcc_apb1_frequency = rcc_ahb_frequency;
			break;
		case 2:	rcc_set_ppre1(RCC_CFGR_PPRE_DIV_2);
			rcc_apb1_frequency = rcc_ahb_frequency >> 1;
			break;
		case 3:	
		case 4:	rcc_set_ppre1(RCC_CFGR_PPRE_DIV_4);
			rcc_apb1_frequency = rcc_ahb_frequency >> 2;
			break;
		default:
			rcc_set_ppre1(RCC_CFGR_PPRE_DIV_8);
			rcc_apb1_frequency = rcc_ahb_frequency >> 3;
			break;
	}

	/* Compute flash wait states (at > 2.6V) */
	flash_ws = ((rcc_ahb_frequency + (FLASH_WS_2V7 - 1)) / FLASH_WS_2V7) & 0x7;
	/* Configure flash settings. */
	flash_set_ws(FLASH_ACR_ICE | FLASH_ACR_DCE | flash_ws);

	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk(PLL);
}

#define warn(n)

static const int pllp_candidates[4] = {2, 4, 6, 8};

uint32_t rcc_compute_pll_bits(int desired_frequency, int input_frequency);

/*
 * This function takes a 'desired' frequency in Hz, and an 'input'
 * frequency in Hz, and computes values for the PLL multipliers on
 * the STM32F4. If 'input' is left at 0, the code assumes you are
 * using the HSI oscillator, if it is provided it assumes you are
 * using an external (HSE) oscillator.
 * 
 * The output is a set of bits suitable for feeding into the rcc_pll_clock_setup().
 */ 
uint32_t
rcc_compute_pll_bits(int desired_frequency, int input_frequency)
{
	uint32_t pllm, plln, pllq, pllp, vco;
	int i, src;

	src = 1;
	if (input_frequency == 0) {
		src = 0;
		input_frequency = RCC_HSI_FREQUENCY;
	}
	pllp = 0;
	for (i = 0; (i < 4) && (pllp == 0); i++) {
		vco = desired_frequency * pllp_candidates[i];
		/* if VCO lands in the "good" range its a winner */
		if ((vco >= 192000000) && (vco <= 433000000)) {
			pllp = pllp_candidates[i];
		}
	}
	if (pllp == 0) {
		return 0; /* can't make that frequency */
	}
	vco = desired_frequency * pllp;
	/*
	 * Compute divisor for closest to 2,000,000 Mhz without going over
	 * later, if this version of pllm doesn't work, we can increment it
	 * by 1 until the division would cause the input frequency to the
	 * PLL to drop below 1MHz.
	 */
	pllm = (input_frequency + 1999999) / 2000000;
	plln = (vco * pllm) / input_frequency;

	/* now check to see if plln is an integral multiplier */
	if (((input_frequency * plln)/pllm) != vco) {
		plln = 0;
		/* if not, try other versions of pllm that might get us there */
		while (((input_frequency / pllm) >= 1000000)  && (plln == 0)) {
			uint32_t tplln;
			tplln = (vco * pllm) / input_frequency;
			if ((input_frequency * tplln) / pllm == vco) {
				/* found one! */
				plln = tplln;
				break;
			}
			pllm++;
		}
		/* no value of PLLM works either, so we're stuck */
		if (plln == 0) {
			return 0; /* Can't get there from here */
		}
        }
	pllq = vco / 48000000;
	if ((pllq * 48000000) != vco) {
		/* not sure what the right answer here is, the chip will work but USB won't */
		warn("won't work for USB\n");
	}
	return (RCC_PLLCFGR_BITS(((pllp / 2) - 1), plln, pllq, pllm, src));
}

/*
 * And now the "do what I want, dammit" function.
 *
 */
void
rcc_clock_setup(uint32_t desired_frequency, uint32_t hse_frequency) {
	if (desired_frequency == hse_frequency) {
		return rcc_hse_clock_setup(desired_frequency);
	} else if ((hse_frequency == 0) && (desired_frequency == RCC_HSI_FREQUENCY)) {
		return rcc_hsi_clock_setup(RCC_HSI_FREQUENCY);
	} else {
		uint32_t cfgr_bits;
		cfgr_bits = rcc_compute_pll_bits(desired_frequency, hse_frequency);
		return rcc_pll_clock_setup(cfgr_bits, hse_frequency);
	}
}

/**@}*/
