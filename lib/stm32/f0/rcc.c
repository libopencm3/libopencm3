/** @defgroup rcc_file RCC peripheral API
 *
 * @ingroup peripheral_apis
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

/*---------------------------------------------------------------------------*/
/** @brief RCC Set the Source for the USB Clock.
 *
 * @param clk Oscillator ID. Only HSI48 or PLL have
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
/** @brief RCC Set the APB Prescale Factor.
 *
 * @param[in] ppre Unsigned int32. APB prescale factor @ref rcc_cfgr_apb1pre
 */

void rcc_set_ppre(uint32_t ppre)
{
	RCC_CFGR = (RCC_CFGR & ~RCC_CFGR_PPRE) | ppre;
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
 * @returns Currently selected USB clock source
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

