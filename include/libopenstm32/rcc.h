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
/* Note: AHBRSTR/CFGR2 only exist in "connectivity line" STM32s. */
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
#define RCC_AHBRSTR			MMIO32(RCC_BASE + 0x28) /* See note */
#define RCC_CFGR2			MMIO32(RCC_BASE + 0x2c) /* See note */

/* RCC_APB2ENR values */
/* Note: IOPFEN/IOPGEN are reserved in "connectivity line" STM32s. */
#define RCC_AFIOEN			(1 << 0)
#define RCC_IOPAEN			(1 << 2)
#define RCC_IOPBEN			(1 << 3)
#define RCC_IOPCEN			(1 << 4)
#define RCC_IOPDEN			(1 << 5)
#define RCC_IOPEEN			(1 << 6)
#define RCC_IOPFEN			(1 << 7) /* N/A in all devices */
#define RCC_IOPGEN			(1 << 8) /* N/A in all devices */
#define RCC_ADC1EN			(1 << 9)
#define RCC_ADC2EN			(1 << 10)
#define RCC_TIM1EN			(1 << 11)
#define RCC_SPI1EN			(1 << 12)
#define RCC_USART1EN			(1 << 14)

/* --- RCC_CFGS values ----------------------------------------------------- */

/* TODO: SW */

/* TODO: SWS */

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
// #define PLLMUL_PLLCLK_MUL16		0xf	/* Errata? 17? */

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

#endif
