/** @defgroup rcc_file RCC peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32F3xx Reset and Clock Control</b>
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Modified by 2013 Fernando Cortes <fernando.corcam@gmail.com> (stm32f3)
 * Modified by 2013 Guillermo Rivera <memogrg@gmail.com> (stm32f3)
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

/* Set the default clock frequencies after reset. */
uint32_t rcc_ahb_frequency = 8000000;
uint32_t rcc_apb1_frequency = 8000000;
uint32_t rcc_apb2_frequency = 8000000;

const struct rcc_clock_scale rcc_hsi_configs[] = {
	{ /* 48MHz */
		.pllmul = RCC_CFGR_PLLMUL_MUL12,
		.pllsrc = RCC_CFGR_PLLSRC_HSI_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.flash_waitstates = 1,
		.ahb_frequency	= 48000000,
		.apb1_frequency = 24000000,
		.apb2_frequency = 48000000,
	},
	{ /* 64MHz */
		.pllmul = RCC_CFGR_PLLMUL_MUL16,
		.pllsrc = RCC_CFGR_PLLSRC_HSI_DIV2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.flash_waitstates = 2,
		.ahb_frequency	= 64000000,
		.apb1_frequency = 32000000,
		.apb2_frequency = 64000000,
	}
};

const struct rcc_clock_scale rcc_hse8mhz_configs[] = {
	{
		.pllsrc = RCC_CFGR_PLLSRC_HSE_PREDIV,
		.pllmul = RCC_CFGR_PLLMUL_MUL9,
		.plldiv = RCC_CFGR2_PREDIV_NODIV,
		.usbdiv1 = false,
		.flash_waitstates = 2,
		.hpre = RCC_CFGR_HPRE_NODIV,
		.ppre1 = RCC_CFGR_PPRE_DIV2,
		.ppre2 = RCC_CFGR_PPRE_NODIV,
		.ahb_frequency = 72e6,
		.apb1_frequency = 36e6,
		.apb2_frequency = 72e6,
	}
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


void rcc_wait_for_osc_not_ready(enum rcc_osc osc)
{
	while (rcc_is_osc_ready(osc));
}

void rcc_wait_for_sysclk_status(enum rcc_osc osc)
{
	switch (osc) {
	case RCC_PLL:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWS_PLL);
		break;
	case RCC_HSE:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWS_HSE);
		break;
	case RCC_HSI:
		while (((RCC_CFGR >> RCC_CFGR_SWS_SHIFT) & RCC_CFGR_SWS_MASK) !=
			RCC_CFGR_SWS_HSI);
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

void rcc_css_enable(void)
{
	RCC_CR |= RCC_CR_CSSON;
}

void rcc_css_disable(void)
{
	RCC_CR &= ~RCC_CR_CSSON;
}

void rcc_set_sysclk_source(uint32_t clk)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~((1 << 1) | (1 << 0));
	RCC_CFGR = (reg32 | clk);
}

void rcc_set_pll_source(uint32_t pllsrc)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~RCC_CFGR_PLLSRC;
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

/**
 * Set PLL Source pre-divider **CAUTION**.
 * On some F3 devices, prediv only applies to HSE source. On others,
 * this is _after_ source selection. See also f0.
 * @param[in] prediv division by prediv+1 @ref rcc_cfgr2_prediv
 */
void rcc_set_prediv(uint32_t prediv)
{
	RCC_CFGR2 = (RCC_CFGR2 & ~RCC_CFGR2_PREDIV) | prediv;
}

void rcc_set_pll_multiplier(uint32_t pll)
{
	uint32_t reg32;

	reg32 = RCC_CFGR;
	reg32 &= ~(RCC_CFGR_PLLMUL_MASK << RCC_CFGR_PLLMUL_SHIFT);
	RCC_CFGR = (reg32 | (pll << RCC_CFGR_PLLMUL_SHIFT));
}


uint32_t rcc_get_system_clock_source(void)
{
	/* Return the clock source which is used as system clock. */
	return (RCC_CFGR & 0x000c) >> 2;
}

/**
 * Setup clocks to run from PLL.
 * The arguments provide the pll source, multipliers, dividers, all that's
 * needed to establish a system clock.
 * @param clock clock information structure
 */
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock)
{
	if (clock->pllsrc == RCC_CFGR_PLLSRC_HSE_PREDIV) {
		rcc_osc_on(RCC_HSE);
		rcc_wait_for_osc_ready(RCC_HSE);
	} else {
		rcc_osc_on(RCC_HSI);
		rcc_wait_for_osc_ready(RCC_HSI);
	}
	rcc_osc_off(RCC_PLL);
	rcc_usb_prescale_1_5();
	if (clock->usbdiv1) {
		rcc_usb_prescale_1();
	}
	rcc_wait_for_osc_not_ready(RCC_PLL);
	rcc_set_pll_source(clock->pllsrc);
	rcc_set_pll_multiplier(clock->pllmul);
	rcc_set_prediv(clock->plldiv);
	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);

	/* Configure flash settings. */
	flash_prefetch_enable();
	flash_set_ws(clock->flash_waitstates);

	rcc_set_hpre(clock->hpre);
	rcc_set_ppre2(clock->ppre2);
	rcc_set_ppre1(clock->ppre1);
	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_PLL);
	/* Wait for PLL clock to be selected. */
	rcc_wait_for_sysclk_status(RCC_PLL);

	/* Set the peripheral clock frequencies used. */
	rcc_ahb_frequency  = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}


void __attribute__((deprecated)) rcc_clock_setup_hsi(const struct rcc_clock_scale *clock)
{
	/* Enable internal high-speed oscillator. */
	rcc_osc_on(RCC_HSI);
	rcc_wait_for_osc_ready(RCC_HSI);
	/* Select HSI as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_HSI); /* XXX: se cayo */
	rcc_wait_for_sysclk_status(RCC_HSI);

	rcc_osc_off(RCC_PLL);
	rcc_wait_for_osc_not_ready(RCC_PLL);
	rcc_set_pll_source(clock->pllsrc);
	rcc_set_pll_multiplier(clock->pllmul);
	/* Enable PLL oscillator and wait for it to stabilize. */
	rcc_osc_on(RCC_PLL);
	rcc_wait_for_osc_ready(RCC_PLL);
	/*
	 * Set prescalers for AHB, ADC, APB1, APB2.
	 * Do this before touching the PLL (TODO: why?).
	 */
	rcc_set_hpre(clock->hpre);
	rcc_set_ppre2(clock->ppre2);
	rcc_set_ppre1(clock->ppre1);
	/* Configure flash settings. */
	flash_set_ws(clock->flash_waitstates);
	/* Select PLL as SYSCLK source. */
	rcc_set_sysclk_source(RCC_CFGR_SW_PLL); /* XXX: se cayo */
	/* Wait for PLL clock to be selected. */
	rcc_wait_for_sysclk_status(RCC_PLL);

	/* Set the peripheral clock frequencies used. */
	rcc_ahb_frequency  = clock->ahb_frequency;
	rcc_apb1_frequency = clock->apb1_frequency;
	rcc_apb2_frequency = clock->apb2_frequency;
}


void rcc_backupdomain_reset(void)
{
	/* Set the backup domain software reset. */
	RCC_BDCR |= RCC_BDCR_BDRST;

	/* Clear the backup domain software reset. */
	RCC_BDCR &= ~RCC_BDCR_BDRST;
}

void rcc_set_i2c_clock_hsi(uint32_t i2c)
{
	if (i2c == I2C1) {
		RCC_CFGR3 &= ~RCC_CFGR3_I2C1SW;
	}
	if (i2c == I2C2) {
		RCC_CFGR3 &= ~RCC_CFGR3_I2C2SW;
	}
}

void rcc_set_i2c_clock_sysclk(uint32_t i2c)
{
	if (i2c == I2C1) {
		RCC_CFGR3 |= RCC_CFGR3_I2C1SW;
	}
	if (i2c == I2C2) {
		RCC_CFGR3 |= RCC_CFGR3_I2C2SW;
	}
}

uint32_t rcc_get_i2c_clocks(void)
{
	return RCC_CFGR3 & (RCC_CFGR3_I2C1SW | RCC_CFGR3_I2C2SW);
}

void rcc_usb_prescale_1_5(void)
{
	RCC_CFGR &= ~RCC_CFGR_USBPRES;
}

void rcc_usb_prescale_1(void)
{
	RCC_CFGR |= RCC_CFGR_USBPRES;
}

void rcc_adc_prescale(uint32_t prescale1, uint32_t prescale2)
{
	uint32_t clear_mask = (RCC_CFGR2_ADCxPRES_MASK
			       << RCC_CFGR2_ADC12PRES_SHIFT)
			      | (RCC_CFGR2_ADCxPRES_MASK
				 << RCC_CFGR2_ADC34PRES_SHIFT);
	uint32_t set = (prescale1 << RCC_CFGR2_ADC12PRES_SHIFT) |
		(prescale2 << RCC_CFGR2_ADC34PRES_SHIFT);
	RCC_CFGR2 &= ~(clear_mask);
	RCC_CFGR2 |= (set);
}

static uint32_t rcc_get_usart_clksel_freq(uint32_t apb_clk, uint8_t shift) {
	uint8_t clksel = (RCC_CFGR3 >> shift) & RCC_CFGR3_UARTxSW_MASK;
	uint8_t hpre = (RCC_CFGR >> RCC_CFGR_HPRE_SHIFT) & RCC_CFGR_HPRE_MASK;
	switch (clksel) {
	case RCC_CFGR3_UARTxSW_PCLK:
		return apb_clk;
	case RCC_CFGR3_UARTxSW_SYSCLK:
		return rcc_ahb_frequency * rcc_get_div_from_hpre(hpre);
	case RCC_CFGR3_UARTxSW_LSE:
		return 32768;
	case RCC_CFGR3_UARTxSW_HSI:
		return 8000000U;
	}
	cm3_assert_not_reached();
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the USART at base specified.
 * @param usart  Base address of USART to get clock frequency for.
 */
uint32_t rcc_get_usart_clk_freq(uint32_t usart)
{
	/* Handle values with selectable clocks. */
	if (usart == USART1_BASE) {
		return rcc_get_usart_clksel_freq(rcc_apb2_frequency, RCC_CFGR3_UART1SW_SHIFT);
	} else if (usart == USART2_BASE) {
		return rcc_get_usart_clksel_freq(rcc_apb1_frequency, RCC_CFGR3_UART2SW_SHIFT);
	} else if (usart == USART3_BASE) {
		return rcc_get_usart_clksel_freq(rcc_apb1_frequency, RCC_CFGR3_UART3SW_SHIFT);
	} else if (usart == UART4_BASE) {
		return rcc_get_usart_clksel_freq(rcc_apb1_frequency, RCC_CFGR3_UART4SW_SHIFT);
	} else {  /* UART5 */
		return rcc_get_usart_clksel_freq(rcc_apb1_frequency, RCC_CFGR3_UART5SW_SHIFT);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the Timer at base specified.
 * @param timer  Base address of TIM to get clock frequency for.
 */
uint32_t rcc_get_timer_clk_freq(uint32_t timer)
{
	/* Handle APB1 timer clocks. */
	if (timer >= TIM2_BASE && timer <= TIM7_BASE) {
		uint8_t ppre1 = (RCC_CFGR >> RCC_CFGR_PPRE1_SHIFT) & RCC_CFGR_PPRE1_MASK;
		return (ppre1 == RCC_CFGR_PPRE1_DIV_NONE) ? rcc_apb1_frequency
			: 2 * rcc_apb1_frequency;
	} else {
		uint8_t ppre2 = (RCC_CFGR >> RCC_CFGR_PPRE2_SHIFT) & RCC_CFGR_PPRE2_MASK;
		return (ppre2 == RCC_CFGR_PPRE2_DIV_NONE) ? rcc_apb2_frequency
			: 2 * rcc_apb2_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the I2C device at base specified.
 * @param i2c  Base address of I2C to get clock frequency for.
 */
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c)
{
	if (i2c == I2C1_BASE) {
		if (RCC_CFGR3 & RCC_CFGR3_I2C1SW) {
			uint8_t hpre = (RCC_CFGR >> RCC_CFGR_HPRE_SHIFT) & RCC_CFGR_HPRE_MASK;
			return rcc_ahb_frequency * rcc_get_div_from_hpre(hpre);
		} else {
			return 8000000U;
		}
	} else {
		return rcc_apb1_frequency;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Get the peripheral clock speed for the SPI device at base specified.
 * @param spi  Base address of SPI device to get clock frequency for (e.g. SPI1_BASE).
 */
uint32_t rcc_get_spi_clk_freq(uint32_t spi) {
	if (spi == SPI1_BASE || spi == SPI4_BASE) {
		return rcc_apb2_frequency;
	} else {
		return rcc_apb1_frequency;
	}
}
/**@}*/

