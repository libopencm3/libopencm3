/** @defgroup rcc_file RCC peripheral API

@ingroup peripheral_apis

@brief <b>libopencm3 STM32L1xx Reset and Clock Control</b>

@version 1.0.0

This library supports the Reset and Clock Control System in the STM32L1xx
series of ARM Cortex Microcontrollers by ST Microelectronics.

Clock settings and resets for many peripherals are given here rather than in
the corresponding peripheral library.

The library also provides a number of common configurations for the processor
system clock. Not all possible configurations are included.
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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
 * Based on the F4 code...
 */
/**@{*/

#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/flash.h>
#include <libopencm3/stm32/pwr.h>

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency = 2097000;
uint32_t rcc_apb1_frequency = 2097000;
uint32_t rcc_apb2_frequency = 2097000;

const struct rcc_clock_scale rcc_clock_config[RCC_CLOCK_CONFIG_END] = {
	{ /* 24MHz PLL from HSI */
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK,
		.pll_mul = RCC_CFGR_PLLMUL_MUL3,
		.pll_div = RCC_CFGR_PLLDIV_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 1,
		.ahb_frequency	= 24000000,
		.apb1_frequency = 24000000,
		.apb2_frequency = 24000000,
	},
	{ /* 32MHz PLL from HSI */
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK,
		.pll_mul = RCC_CFGR_PLLMUL_MUL6,
		.pll_div = RCC_CFGR_PLLDIV_DIV3,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 1,
		.ahb_frequency	= 32000000,
		.apb1_frequency = 32000000,
		.apb2_frequency = 32000000,
	},
	{ /* 16MHz HSI raw */
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 0,
		.ahb_frequency	= 16000000,
		.apb1_frequency = 16000000,
		.apb2_frequency = 16000000,
	},
	{ /* 4MHz HSI raw */
		.hpre = RCC_CFGR_HPRE_DIV4,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 0,
		.ahb_frequency	= 4000000,
		.apb1_frequency = 4000000,
		.apb2_frequency = 4000000,
	},
	{ /* 4MHz MSI raw */
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 0,
		.ahb_frequency	= 4194000,
		.apb1_frequency = 4194000,
		.apb2_frequency = 4194000,
		.msi_range = RCC_ICSCR_MSIRANGE_4MHZ,
	},
	{ /* 2MHz MSI raw */
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_NODIV,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.voltage_scale = PWR_SCALE1,
		.flash_waitstates = 0,
		.ahb_frequency	= 2097000,
		.apb1_frequency = 2097000,
		.apb2_frequency = 2097000,
		.msi_range = RCC_ICSCR_MSIRANGE_2MHZ,
	},
};

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
	case RCC_MSI:
		RCC_CIR |= RCC_CIR_MSIRDYC;
		break;
	}
}

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
	case RCC_MSI:
		RCC_CIR |= RCC_CIR_MSIRDYIE;
		break;
	}
}

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
	case RCC_MSI:
		RCC_CIR &= ~RCC_CIR_MSIRDYIE;
		break;
	}
}

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
	case RCC_MSI:
		return ((RCC_CIR & RCC_CIR_MSIRDYF) != 0);
		break;
	}

	/* Shouldn't be reached. */
	return -1;
}

void rcc_css_int_clear(void)
{
	RCC_CIR |= RCC_CIR_CSSC;
}

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
	case RCC_MSI:
		return RCC_CR & RCC_CR_MSIRDY;
	case RCC_LSE:
		return RCC_CSR & RCC_CSR_LSERDY;
	case RCC_LSI:
		return RCC_CSR & RCC_CSR_LSIRDY;
	}
	return false;
}

void rcc_wait_for_osc_ready(enum rcc_osc osc)
{
	while (!rcc_is_osc_ready(osc));
}

void rcc_wait_for_sysclk_status(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWS_SYSCLKSEL_PLLCLK);
		break;
	case RCC_HSE:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWS_SYSCLKSEL_HSECLK);
		break;
	case RCC_HSI:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWS_SYSCLKSEL_HSICLK);
		break;
	case RCC_MSI:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWS_SYSCLKSEL_MSICLK);
		break;
	default:
		/* Shouldn't be reached. */
		break;
	}
}

void rcc_osc_on(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR |= RCC_CR_PLLON;
		break;
	case RCC_MSI:
		RCC_CR |= RCC_CR_MSION;
		break;
	case RCC_HSE:
		RCC_CR |= RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR |= RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_CSR |= RCC_CSR_LSEON;
		break;
	case RCC_LSI:
		RCC_CSR |= RCC_CSR_LSION;
		break;
	}
}

void rcc_osc_off(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		RCC_CR &= ~RCC_CR_PLLON;
		break;
	case RCC_MSI:
		RCC_CR &= ~RCC_CR_MSION;
		break;
	case RCC_HSE:
		RCC_CR &= ~RCC_CR_HSEON;
		break;
	case RCC_HSI:
		RCC_CR &= ~RCC_CR_HSION;
		break;
	case RCC_LSE:
		RCC_CSR &= ~RCC_CSR_LSEON;
		break;
	case RCC_LSI:
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

/**
 * Set the range of the MSI oscillator
 * @param range desired range @ref rcc_icscr_msirange
 */
void rcc_set_msi_range(uint32_t range)
{
	uint32_t reg = RCC_ICSCR;
	reg &= ~(RCC_ICSCR_MSIRANGE_MASK << RCC_ICSCR_MSIRANGE_SHIFT);
	reg |= (range << RCC_ICSCR_MSIRANGE_SHIFT);
	RCC_ICSCR = reg;
}

void rcc_set_sysclk_source(uint32_t clk)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT);
	RCC_CFGR = (reg32 | clk << RCC_CFGR_SW_SHIFT);
}

void rcc_set_pll_configuration(uint32_t source, uint32_t multiplier,
			       uint32_t divisor)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PLLDIV_MASK << RCC_CFGR_PLLDIV_SHIFT);
	reg32 &= ~(RCC_CFGR_PLLMUL_MASK << RCC_CFGR_PLLMUL_SHIFT);
	reg32 &= ~(1 << 16);
	reg32 |= (source << 16);
	reg32 |= (multiplier << RCC_CFGR_PLLMUL_SHIFT);
	reg32 |= (divisor << RCC_CFGR_PLLDIV_SHIFT);
	RCC_CFGR = reg32;
}

void rcc_set_pll_source(uint32_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(1 << 16);
	RCC_CFGR = (reg32 | (pllsrc << 16));
}

void rcc_set_ppre2(uint32_t ppre2)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE2_MASK << RCC_CFGR_PPRE2_SHIFT);
	RCC_CFGR = (reg32 | (ppre2 << RCC_CFGR_PPRE2_SHIFT));
}

void rcc_set_ppre1(uint32_t ppre1)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PPRE1_MASK << RCC_CFGR_PPRE1_SHIFT);
	RCC_CFGR = (reg32 | (ppre1 << RCC_CFGR_PPRE1_SHIFT));
}

void rcc_set_hpre(uint32_t hpre)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_HPRE_MASK << RCC_CFGR_HPRE_SHIFT);
	RCC_CFGR = (reg32 | (hpre << RCC_CFGR_HPRE_SHIFT));
}

void rcc_set_rtcpre(uint32_t rtcpre)
{
	uint32_t reg32;

	reg32 = RCC_CR;
	reg32 &= ~(RCC_CR_RTCPRE_MASK << RCC_CR_RTCPRE_SHIFT);
	RCC_CR = (reg32 | (rtcpre << RCC_CR_RTCPRE_SHIFT));
}

uint32_t rcc_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return (RCC_CFGR & 0x000c) >> 2;
}

void rcc_rtc_select_clock(uint32_t clock)
{
	RCC_CSR &= ~(RCC_CSR_RTCSEL_MASK << RCC_CSR_RTCSEL_SHIFT);
	RCC_CSR |= (clock << RCC_CSR_RTCSEL_SHIFT);
}

void rcc_clock_setup_msi(const struct rcc_clock_scale *clock)
{
	/* Enable internal multi-speed oscillator. */
	rcc_set_msi_range(clock->msi_range);
	rcc_osc_on(RCC_MSI);
	rcc_wait_for_osc_ready(RCC_MSI);

	/* Select MSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_MSICLK);

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(clock->voltage_scale);

	/* I guess this should be in the settings? */
	flash_64bit_enable();
	flash_prefetch_enable();
	flash_set_ws(clock->flash_waitstates);

	/* Set the peripheral clock frequencies used. */
	rcc_ahb_frequency  = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
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
	rcc_periph_clock_enable(RCC_PWR);

	/* I guess this should be in the settings? */
	flash_64bit_enable();
	flash_prefetch_enable();

	/* Don't try and go to fast for a voltage range! */
	if (clock->ahb_frequency > rcc_ahb_frequency) {
		/* Going up, power up first */
		pwr_set_vos_scale(clock->voltage_scale);
		rcc_set_hpre(clock->hpre);
		rcc_set_ppre1(clock->ppre1);
		rcc_set_ppre2(clock->ppre2);
		flash_set_ws(clock->flash_waitstates);
	} else {
		/* going down, slow down before cutting power */
		rcc_set_hpre(clock->hpre);
		rcc_set_ppre1(clock->ppre1);
		rcc_set_ppre2(clock->ppre2);
		flash_set_ws(clock->flash_waitstates);
		pwr_set_vos_scale(clock->voltage_scale);
	}

	rcc_wait_for_osc_ready(RCC_HSI);
	while (PWR_CSR & PWR_CSR_VOSF) {
		;
	}
	rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

	/* Set the peripheral clock frequencies used. */
	rcc_ahb_frequency  = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}

void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{
	/* Turn on the appropriate source for the PLL */
	if (clock->pll_source == RCC_CFGR_PLLSRC_HSE_CLK) {
		rcc_osc_on(RCC_HSE);
		rcc_wait_for_osc_ready(RCC_HSE);
	} else {
		rcc_osc_on(RCC_HSI);
		rcc_wait_for_osc_ready(RCC_HSI);
	}

	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre1(clock->ppre1);
	rcc_set_ppre2(clock->ppre2);

	rcc_periph_clock_enable(RCC_PWR);
	pwr_set_vos_scale(clock->voltage_scale);

	/* I guess this should be in the settings? */
	flash_64bit_enable();
	flash_prefetch_enable();
	flash_set_ws(clock->flash_waitstates);

	/* Disable PLL oscillator before changing its configuration. */
	rcc_osc_off(RCC_PLL);

	/* Configure the PLL oscillator. */
	rcc_set_pll_configuration(clock->pll_source, clock->pll_mul,
				  clock->pll_div);

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
/** @brief Get the peripheral clock speed for the USART at base specified.
 * @param usart  Base address of USART to get clock frequency for.
 */
uint32_t rcc_get_usart_clk_freq(uint32_t usart)
{
	if (usart == USART1_BASE) {
		return rcc_apb2_frequency;
	} else {
		return rcc_apb1_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the Timer at base specified.
 * @param timer  Base address of TIM to get clock frequency for.
 */
uint32_t rcc_get_timer_clk_freq(uint32_t timer)
{
	/* Handle APB1 timers, and apply multiplier if necessary. */
	if (timer >= TIM2_BASE && timer <= TIM7_BASE) {
		uint8_t ppre1 = (RCC_CFGR >> RCC_CFGR_PPRE1_SHIFT) & RCC_CFGR_PPRE1_MASK;
		return (ppre1 == RCC_CFGR_PPRE1_HCLK_NODIV) ? rcc_apb1_frequency
			: 2 * rcc_apb1_frequency;
	} else {
		uint8_t ppre2 = (RCC_CFGR >> RCC_CFGR_PPRE2_SHIFT) & RCC_CFGR_PPRE2_MASK;
		return (ppre2 == RCC_CFGR_PPRE2_HCLK_NODIV) ? rcc_apb2_frequency
			: 2 * rcc_apb2_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the I2C device at base specified.
 * @param i2c  Base address of I2C to get clock frequency for.
 */
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c __attribute__((unused)))
{
		return rcc_apb1_frequency;
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the SPI device at base specified.
 * @param spi  Base address of SPI device to get clock frequency for (e.g. SPI1_BASE).
 */
uint32_t rcc_get_spi_clk_freq(uint32_t spi) {
	if (spi == SPI1_BASE) {
		return rcc_apb2_frequency;
	} else {
		return rcc_apb1_frequency;
	}
}
/**@}*/
