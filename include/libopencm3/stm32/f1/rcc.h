/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F1xx Reset and Clock
 * Control</b>
 *
 * @ingroup STM32F1xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Uwe Hermann <uwe@hermann-uwe.de>
 *
 * @date 18 August 2012
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
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

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

/* --- RCC_CFGR values ----------------------------------------------------- */

#define RCC_CFGR_USBPRE_SHIFT			22
#define RCC_CFGR_OTGFSPRE			(1 << RCC_CFGR_USBPRE_SHIFT) /* Connectivity line */
#define RCC_CFGR_USBPRE				(1 << RCC_CFGR_USBPRE_SHIFT) /* LD,MD, HD, XL */

#define RCC_CFGR_PLLMUL_SHIFT			18
#define RCC_CFGR_PLLMUL				(0xF << RCC_CFGR_PLLMUL_SHIFT)

#define RCC_CFGR_ADCPRE_SHIFT			14
#define RCC_CFGR_ADCPRE				(3 << RCC_CFGR_ADCPRE_SHIFT)

/* USBPRE: USB prescaler (RCC_CFGR[22]) */
/** @defgroup rcc_cfgr_usbpre RCC_CFGR USB prescale Factors
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_USBPRE_PLL_CLK_DIV1_5		0x0
#define RCC_CFGR_USBPRE_PLL_CLK_NODIV		0x1
/**@}*/

/* OTGFSPRE: USB OTG FS prescaler (RCC_CFGR[22]; only in conn. line STM32s) */
#define RCC_CFGR_USBPRE_PLL_VCO_CLK_DIV3	0x0
#define RCC_CFGR_USBPRE_PLL_VCO_CLK_DIV2	0x1

/* --- Function prototypes ------------------------------------------------- */

enum rcc_clock_hsi {
	RCC_CLOCK_HSI_24MHZ,
	RCC_CLOCK_HSI_48MHZ,
	RCC_CLOCK_HSI_64MHZ,
	RCC_CLOCK_HSI_END
};

enum rcc_clock_hse {
	RCC_CLOCK_HSE12_72MHZ,
	RCC_CLOCK_HSE16_72MHZ,
	RCC_CLOCK_HSE25_72MHZ,
	RCC_CLOCK_HSE8_24MHZ,
	RCC_CLOCK_HSE8_72MHZ,
	RCC_CLOCK_HSE_END
};

/* Union of all options for f100 through to f107 */
struct rcc_clock_scale {
	uint8_t pll_mul;
	uint8_t pll_source;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	uint8_t adcpre;
	uint8_t flash_waitstates;
	uint8_t prediv1; /* aka xtpre, only one bit on smaller parts */
	uint8_t prediv1_source;
	uint8_t prediv2;
	uint8_t pll2_mul;
	uint8_t pll3_mul;
	uint8_t usbpre;
	uint32_t ahb_frequency;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END];
extern const struct rcc_clock_scale rcc_hse_configs[RCC_CLOCK_HSE_END];

#include <libopencm3/stm32/common/rcc_common_f1.h>

BEGIN_DECLS

void rcc_set_pllxtpre(uint32_t pllxtpre);
void rcc_clock_setup_in_hsi_out_64mhz(void) LIBOPENCM3_DEPRECATED("use rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ])");
void rcc_clock_setup_in_hsi_out_48mhz(void) LIBOPENCM3_DEPRECATED("use rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_48MHZ])");
void rcc_clock_setup_in_hsi_out_24mhz(void) LIBOPENCM3_DEPRECATED("use rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_24MHZ])");
void rcc_clock_setup_in_hse_8mhz_out_24mhz(void) LIBOPENCM3_DEPRECATED("use rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_24MHZ])");
void rcc_clock_setup_in_hse_8mhz_out_72mhz(void) LIBOPENCM3_DEPRECATED("use rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ])");
void rcc_clock_setup_in_hse_12mhz_out_72mhz(void) LIBOPENCM3_DEPRECATED("use rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE12_72MHZ])");
void rcc_clock_setup_in_hse_16mhz_out_72mhz(void) LIBOPENCM3_DEPRECATED("use rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE16_72MHZ])");
void rcc_clock_setup_in_hse_25mhz_out_72mhz(void) LIBOPENCM3_DEPRECATED("use rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE25_72MHZ])");

uint32_t rcc_get_usart_clk_freq(uint32_t usart);
uint32_t rcc_get_timer_clk_freq(uint32_t timer);
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c);
uint32_t rcc_get_spi_clk_freq(uint32_t spi);
END_DECLS

#endif
/**@}*/
