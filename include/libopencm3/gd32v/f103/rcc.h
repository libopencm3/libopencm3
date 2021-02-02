/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the GD32VF103 Reset and Clock
 * Control</b>
 *
 * @ingroup STM32F_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2020
 * Lubomir Rintel <lkundrak@v3.sk>
 *
 * @date 12 July 2020
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Lubomir Rintel <lkundrak@v3.sk>
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

#define RCC_CFGR_PLLMUL_4_SHIFT			29
#define RCC_CFGR_PLLMUL_4			(1 << RCC_CFGR_PLLMUL_4_SHIFT)

#define RCC_CFGR_ADCPRE_2_SHIFT			28
#define RCC_CFGR_ADCPRE_2			(1 << RCC_CFGR_ADCPRE_2_SHIFT)

#define RCC_CFGR_USBPRE_SHIFT			22
#define RCC_CFGR_USBPRE				(3 << RCC_CFGR_USBPRE_SHIFT)

#define RCC_CFGR_PLLMUL_0_3_SHIFT		18
#define RCC_CFGR_PLLMUL_0_3			(0xf << RCC_CFGR_PLLMUL_0_3_SHIFT)


#define RCC_CFGR_ADCPRE_0_1_SHIFT		14
#define RCC_CFGR_ADCPRE_0_1			(3 << RCC_CFGR_ADCPRE_0_1_SHIFT)

/** @defgroup rcc_cfgr_usbpre USBPRE: USB prescaler (RCC_CFGR[23:22])
 * @{
 */
#define RCC_CFGR_USBPRE_PLL_CLK_DIV1_5		0x0
#define RCC_CFGR_USBPRE_PLL_CLK_NODIV		0x1
#define RCC_CFGR_USBPRE_PLL_CLK_DIV2_5		0x2
#define RCC_CFGR_USBPRE_PLL_CLK_DIV2		0x3
/**@}*/

/** @addtogroup rcc_cfgr_pmf PLLMUL: PLL multiplication factor
 * @{
 */

#define RCC_CFGR_PLLMUL_PLL_CLK_MUL16		0xe
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL17		0x10
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL18		0x11
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL19		0x12
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL20		0x13
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL21		0x14
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL22		0x15
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL23		0x16
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL24		0x17
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL25		0x18
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL26		0x19
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL27		0x1a
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL28		0x1b
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL29		0x1c
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL30		0x1d
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL31		0x1e
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL32		0x1f

/**@}*/

/** @addtogroup rcc_cfgr_adcpre ADCPRE: ADC prescaler
 * @{
 */
#define RCC_CFGR_ADCPRE_PCLK2_DIV12		0x5
#define RCC_CFGR_ADCPRE_PCLK2_DIV16		0x7
/**@}*/

/* --- RCC_DSVR values ---------------------------------------------------- */

/* DSVSEL: Deep sleep voltage select */
#define RCC_DSVR_DSVSEL_1_2V			0x0
#define RCC_DSVR_DSVSEL_1_1V			0x1
#define RCC_DSVR_DSVSEL_1_0V			0x2
#define RCC_DSVR_DSVSEL_0_9V			0x3
#define RCC_DSVR_DSVSEL				(3 << 0)

/* --- Function prototypes ------------------------------------------------- */

enum rcc_clock_hsi {
	RCC_CLOCK_HSI_48MHZ,
	RCC_CLOCK_HSI_72MHZ,
	RCC_CLOCK_HSI_108MHZ,
	RCC_CLOCK_HSI_END
};

enum rcc_clock_hse8 {
	RCC_CLOCK_HSE8_24MHZ,
	RCC_CLOCK_HSE8_36MHZ,
	RCC_CLOCK_HSE8_48MHZ,
	RCC_CLOCK_HSE8_56MHZ,
	RCC_CLOCK_HSE8_72MHZ,
	RCC_CLOCK_HSE8_96MHZ,
	RCC_CLOCK_HSE8_108MHZ,
	RCC_CLOCK_HSE8_END
};

enum rcc_clock_hse25 {
	RCC_CLOCK_HSE25_24MHZ,
	RCC_CLOCK_HSE25_36MHZ,
	RCC_CLOCK_HSE25_48MHZ,
	RCC_CLOCK_HSE25_56MHZ,
	RCC_CLOCK_HSE25_72MHZ,
	RCC_CLOCK_HSE25_96MHZ,
	RCC_CLOCK_HSE25_108MHZ,
	RCC_CLOCK_HSE25_END
};

struct rcc_clock_scale {
	/* PLL2 is used when a 25 MHz HSE is supplied. */
	uint8_t pll_prediv2;
	uint8_t pll_mul2;

	/* PLL pre-diviser is used when a HSE is used */
	uint8_t pll_prediv1src;
	uint8_t pll_prediv1;

	uint8_t pllsrc;
	uint8_t pllmul;

	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;

	uint8_t adcpre;
	uint8_t usbpre;

	uint32_t ahb_frequency;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END];
extern const struct rcc_clock_scale rcc_hse8_configs[RCC_CLOCK_HSE8_END];
extern const struct rcc_clock_scale rcc_hse25_configs[RCC_CLOCK_HSE25_END];

#include <libopencm3/stm32/common/rcc_common_f1.h>

BEGIN_DECLS

void rcc_wait_for_sysclk_source(uint32_t clk);

END_DECLS

#endif
/**@}*/
