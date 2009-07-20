/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENSTM32_RCC_H
#define LIBOPENSTM32_RCC_H

#include "libopenstm32.h"

/* RCC registers */
/* Note: Registers marked (**) only exist in "connectivity line" STM32s. */
#define RCC_CR				MMIO32(RCC_BASE + 0x00)
#define RCC_CFGR			MMIO32(RCC_BASE + 0x04)
#define RCC_CIR				MMIO32(RCC_BASE + 0x08)
#define RCC_APB2RSTR			MMIO32(RCC_BASE + 0x0c)
#define RCC_APB1RSTR			MMIO32(RCC_BASE + 0x10)
#define RCC_AHBENR			MMIO32(RCC_BASE + 0x14)
#define RCC_APB2ENR			MMIO32(RCC_BASE + 0x18)
#define RCC_APB1ENR			MMIO32(RCC_BASE + 0x1c)
#define RCC_BDCR			MMIO32(RCC_BASE + 0x20)
#define RCC_CSR				MMIO32(RCC_BASE + 0x24)
#define RCC_AHBRSTR			MMIO32(RCC_BASE + 0x28) /* (**) */
#define RCC_CFGR2			MMIO32(RCC_BASE + 0x2c) /* (**) */

/* --- RCC_CR values ------------------------------------------------------- */

/* Note: Bits marked (**) only exist in "connectivity line" STM32s. */
#define HSION				(1 << 0)
#define HSIRDY				(1 << 1)
#define HSEON				(1 << 16)
#define HSERDY				(1 << 17)
#define HSEBYP				(1 << 18)
#define CSSON				(1 << 19)
#define PLLON				(1 << 24)
#define PLLRDY				(1 << 25)
#define PLL2ON				(1 << 26) /* (**) */
#define PLL2RDY				(1 << 27) /* (**) */
#define PLL3ON				(1 << 28) /* (**) */
#define PLL3RDY				(1 << 29) /* (**) */

/* --- RCC_CFGR values ----------------------------------------------------- */

/* SW: System clock switch */
#define SW_SYSCLKSEL_HSICLK		0x0
#define SW_SYSCLKSEL_HSECLK		0x1
#define SW_SYSCLKSEL_PLLCLK		0x2

/* SWS: System clock switch status: Uses same bit definitions as SW. */

/* HPRE: AHB prescaler */
#define HPRE_SYSCLK			0x0
#define HPRE_SYSCLK_DIV2		0x8
#define HPRE_SYSCLK_DIV4		0x9
#define HPRE_SYSCLK_DIV8		0xa
#define HPRE_SYSCLK_DIV16		0xb
#define HPRE_SYSCLK_DIV64		0xc
#define HPRE_SYSCLK_DIV128		0xd
#define HPRE_SYSCLK_DIV256		0xe
#define HPRE_SYSCLK_DIV512		0xf

/* PPRE1: APB low-speed prescaler (APB1) */
#define PPRE1_HCLK			0x0
#define PPRE1_HCLK_DIV2			0x4
#define PPRE1_HCLK_DIV4			0x5
#define PPRE1_HCLK_DIV8			0x6
#define PPRE1_HCLK_DIV16		0x7

/* PPRE2: APB high-speed prescaler (APB2) */
#define PPRE2_HCLK			0x0
#define PPRE2_HCLK_DIV2			0x4
#define PPRE2_HCLK_DIV4			0x5
#define PPRE2_HCLK_DIV8			0x6
#define PPRE2_HCLK_DIV16		0x7

/* ADCPRE: ADC prescaler */
#define ADCPRE_PLCLK2_DIV2		0x0
#define ADCPRE_PLCLK2_DIV4		0x1
#define ADCPRE_PLCLK2_DIV6		0x2
#define ADCPRE_PLCLK2_DIV8		0x3

/* PLLSRC: PLL entry clock source */
#define PLLSRC_HSI_CLKDIV2		0x0
#define PLLSRC_HSE_CLK			0x1

/* PLLXTPRE: HSE divider for PLL entry */
#define PLLXTPRE_HSE_CLK		0x0
#define PLLXTPRE_HSE_CLK_DIV2		0x1

/* PLLMUL: PLL multiplication factor */
#define PLLMUL_PLLCLK_MUL2		0x0
#define PLLMUL_PLLCLK_MUL3		0x1
#define PLLMUL_PLLCLK_MUL4		0x2
#define PLLMUL_PLLCLK_MUL5		0x3
#define PLLMUL_PLLCLK_MUL6		0x4
#define PLLMUL_PLLCLK_MUL7		0x5
#define PLLMUL_PLLCLK_MUL8		0x6
#define PLLMUL_PLLCLK_MUL9		0x7
#define PLLMUL_PLLCLK_MUL10		0x8
#define PLLMUL_PLLCLK_MUL11		0x9
#define PLLMUL_PLLCLK_MUL12		0xa
#define PLLMUL_PLLCLK_MUL13		0xb
#define PLLMUL_PLLCLK_MUL14		0xc
#define PLLMUL_PLLCLK_MUL15		0xd
#define PLLMUL_PLLCLK_MUL16		0xe
// #define PLLMUL_PLLCLK_MUL16		0xf /* Errata? 17? */

/* USBPRE: USB prescaler */
#define USBPRE_PLLCLK_DIV1_5		0x0
#define USBPRE_PLLCLK			0x1

/* MCO: Microcontroller clock output */
#define MCO_NOCLK			0x0
#define MCO_SYSCLK			0x4
#define MCO_HSICLK			0x5
#define MCO_HSECLK			0x6
#define MCO_PLLCLK_DIV2			0x7
#define MCO_PLL2CLK			0x8
#define MCO_PLL3CLK_DIV2		0x9
#define MCO_XT1				0xa
#define MCO_PLL3			0xb

/* --- RCC_CIR values ------------------------------------------------------ */

/* Note: Bits marked (**) only exist in "connectivity line" STM32s. */

/* OSC ready interrupt flag bits */
#define LSIRDYF				(1 << 0)
#define LSERDYF				(1 << 1)
#define HSIRDYF				(1 << 2)
#define HSERDYF				(1 << 3)
#define PLLRDYF				(1 << 4)
#define PLL2RDYF			(1 << 5) /* (**) */
#define PLL3RDYF			(1 << 6) /* (**) */

/* Clock security system interrupt flag bit */
#define CSSF				(1 << 7)

/* OSC ready interrupt enable bits */
#define LSIRDYIE			(1 << 8)
#define LSERDYIE			(1 << 9)
#define HSIRDYIE			(1 << 10)
#define HSERDYIE			(1 << 11)
#define PLLRDYIE			(1 << 12)
#define PLL2RDYIE			(1 << 13) /* (**) */
#define PLL3RDYIE			(1 << 14) /* (**) */

/* OSC ready interrupt clear bits */
#define LSIRDYC				(1 << 16)
#define LSERDYC				(1 << 17)
#define HSIRDYC				(1 << 18)
#define HSERDYC				(1 << 19)
#define PLLRDYC				(1 << 20)
#define PLL2RDYC			(1 << 21) /* (**) */
#define PLL3RDYC			(1 << 22) /* (**) */

/* Clock security system interrupt clear bit */
#define CSSC				(1 << 23)

/* --- RCC_APB2ENR values -------------------------------------------------- */

/* Note: Bits marked (**) are reserved in "connectivity line" STM32s. */
#define AFIOEN				(1 << 0)
#define IOPAEN				(1 << 2)
#define IOPBEN				(1 << 3)
#define IOPCEN				(1 << 4)
#define IOPDEN				(1 << 5)
#define IOPEEN				(1 << 6)
#define IOPFEN				(1 << 7) /* (**) */
#define IOPGEN				(1 << 8) /* (**) */
#define ADC1EN				(1 << 9)
#define ADC2EN				(1 << 10)
#define TIM1EN				(1 << 11)
#define SPI1EN				(1 << 12)
#define USART1EN			(1 << 14)

/* --- RCC_APB1ENR values -------------------------------------------------- */

/* Note: Bit marked (**) are reserved in "connectivity line" STM32s. */
#define TIM2EN				(1 << 0)
#define TIM3EN				(1 << 1)
#define TIM4EN				(1 << 2)
#define TIM5EN				(1 << 3)
#define TIM6EN				(1 << 4)
#define TIM7EN				(1 << 5)
#define WWDGEN				(1 << 11)
#define SPI2EN				(1 << 14)
#define SPI3EN				(1 << 15)
#define USART2EN			(1 << 17)
#define USART3EN			(1 << 18)
#define USART4EN			(1 << 19)
#define USART5EN			(1 << 20)
#define I2C1EN				(1 << 21)
#define I2C2EN				(1 << 22)
#define USBEN				(1 << 23) /* (**) */
#define CANEN				(1 << 25) /* Alias for CAN1EN */
#define CAN1EN				(1 << 25)
#define CAN2EN				(1 << 26) /* (**) */
#define BKPEN				(1 << 27)
#define PWREN				(1 << 28)
#define DACEN				(1 << 29)

/* --- RCC_BDCR values -------------------------------------------------- */

#define LSEON				(1 << 0)
#define LSERDY				(1 << 1)
#define LSEBYP				(1 << 2)
#define RTCEN				(1 << 15)
#define BDRST				(1 << 16)

/* --- RCC_CSR values -------------------------------------------------- */

#define LSION				(1 << 0)
#define LSIRDY				(1 << 1)
#define RMVF				(1 << 24)
#define PINRSTF				(1 << 26)
#define PORRSTF				(1 << 27)
#define SFTRSTF				(1 << 28)
#define IWDGRSTF			(1 << 29)
#define WWDGRSTF			(1 << 30)
#define LPWRRSTF			(1 << 31)

typedef enum {
	PLL, HSE, HSI, LSE, LSI
} osc_t;

#endif
