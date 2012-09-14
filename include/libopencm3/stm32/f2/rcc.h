/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- RCC registers ------------------------------------------------------- */

#define RCC_CR					MMIO32(RCC_BASE + 0x00)
#define RCC_PLLCFGR				MMIO32(RCC_BASE + 0x04)
#define RCC_CFGR				MMIO32(RCC_BASE + 0x08)
#define RCC_CIR					MMIO32(RCC_BASE + 0x0c)
#define RCC_AHB1RSTR				MMIO32(RCC_BASE + 0x10)
#define RCC_AHB2RSTR				MMIO32(RCC_BASE + 0x14)
#define RCC_AHB3RSTR				MMIO32(RCC_BASE + 0x18)
/* RCC_BASE + 0x1c Reserved */
#define RCC_APB1RSTR				MMIO32(RCC_BASE + 0x20)
#define RCC_APB2RSTR				MMIO32(RCC_BASE + 0x24)
/* RCC_BASE + 0x28 Reserved */
/* RCC_BASE + 0x2c Reserved */
#define RCC_AHB1ENR				MMIO32(RCC_BASE + 0x30)
#define RCC_AHB2ENR				MMIO32(RCC_BASE + 0x34)
#define RCC_AHB3ENR				MMIO32(RCC_BASE + 0x38)
/* RCC_BASE + 0x3c Reserved */
#define RCC_APB1ENR				MMIO32(RCC_BASE + 0x40)
#define RCC_APB2ENR				MMIO32(RCC_BASE + 0x44)
/* RCC_BASE + 0x48 Reserved */
/* RCC_BASE + 0x4c Reserved */
#define RCC_AHB1LPENR				MMIO32(RCC_BASE + 0x50)
#define RCC_AHB2LPENR				MMIO32(RCC_BASE + 0x54)
#define RCC_AHB3LPENR				MMIO32(RCC_BASE + 0x58)
/* RCC_BASE + 0x5c Reserved */
#define RCC_APB1LPENR				MMIO32(RCC_BASE + 0x60)
#define RCC_APB2LPENR				MMIO32(RCC_BASE + 0x64)
/* RCC_BASE + 0x68 Reserved */
/* RCC_BASE + 0x6c Reserved */
#define RCC_BDCR				MMIO32(RCC_BASE + 0x70)
#define RCC_CSR					MMIO32(RCC_BASE + 0x74)
/* RCC_BASE + 0x78 Reserved */
/* RCC_BASE + 0x7c Reserved */
#define RCC_SSCGR				MMIO32(RCC_BASE + 0x80)
#define RCC_PLLI2SCFGR				MMIO32(RCC_BASE + 0x84)

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_PLLI2SRDY			(1 << 27)
#define RCC_CR_PLLI2SON				(1 << 26)
#define RCC_CR_PLLRDY				(1 << 25)
#define RCC_CR_PLLON				(1 << 24)
#define RCC_CR_CSSON				(1 << 19)
#define RCC_CR_HSEBYP				(1 << 18)
#define RCC_CR_HSERDY				(1 << 17)
#define RCC_CR_HSEON				(1 << 16)
/* HSICAL: [15:8] */
/* HSITRIM: [7:3] */
#define RCC_CR_HSIRDY				(1 << 1)
#define RCC_CR_HSION				(1 << 0)

/* --- RCC_PLLCFGR values ------------------------------------------------------- */

/* PLLQ: [27:24] */
#define RCC_PLLCFGR_PLLQ_SHIFT			24
#define RCC_PLLCFGR_PLLSRC			(1 << 22)
/* PLLP: [17:16] */
#define RCC_PLLCFGR_PLLP_SHIFT			16
/* PLLN: [14:6] */
#define RCC_PLLCFGR_PLLN_SHIFT			6
/* PLLM: [5:0] */
#define RCC_PLLCFGR_PLLM_SHIFT			0

/* --- RCC_CFGR values ----------------------------------------------------- */

/* MCO2: Microcontroller clock output 2 */
#define RCC_CFGR_MCO2_SHIFT			30
#define RCC_CFGR_MCO2_SYSCLK			0x0
#define RCC_CFGR_MCO2_PLLI2S			0x1
#define RCC_CFGR_MCO2_HSE			0x2
#define RCC_CFGR_MCO2_PLL			0x3

/* MCO1/2PRE: MCO Prescalers */
#define RCC_CFGR_MCO2PRE_SHIFT			27
#define RCC_CFGR_MCO1PRE_SHIFT			24
#define RCC_CFGR_MCOPRE_DIV_NONE		0x0
#define RCC_CFGR_MCOPRE_DIV_2			0x4
#define RCC_CFGR_MCOPRE_DIV_3			0x5
#define RCC_CFGR_MCOPRE_DIV_4			0x6
#define RCC_CFGR_MCOPRE_DIV_5			0x7

/* I2SSRC: I2S clock selection */
#define RCC_CFGR_I2SSRC				(1 << 23)

/* MCO1: Microcontroller clock output 1 */
#define RCC_CFGR_MCO1_SHIFT			21
#define RCC_CFGR_MCO1_HSI			0x0
#define RCC_CFGR_MCO1_LSE			0x1
#define RCC_CFGR_MCO1_HSE			0x2
#define RCC_CFGR_MCO1_PLL			0x3

/* RTCPRE: HSE division factor for RTC clock */
#define RCC_CFGR_RTCPRE_SHIFT			21

/* PPRE1/2: APB high-speed prescalers */
#define RCC_CFGR_PPRE2_SHIFT			13
#define RCC_CFGR_PPRE1_SHIFT			10
#define RCC_CFGR_PPRE_DIV_NONE			0x0
#define RCC_CFGR_PPRE_DIV_2			0x4
#define RCC_CFGR_PPRE_DIV_4			0x5
#define RCC_CFGR_PPRE_DIV_8			0x6
#define RCC_CFGR_PPRE_DIV_16			0x7

/* HPRE: AHB high-speed prescaler */
#define RCC_CFGR_HPRE_SHIFT			4
#define RCC_CFGR_HPRE_DIV_NONE			0x0
#define RCC_CFGR_HPRE_DIV_2			(0x8 + 0)
#define RCC_CFGR_HPRE_DIV_4			(0x8 + 1)
#define RCC_CFGR_HPRE_DIV_8			(0x8 + 2)
#define RCC_CFGR_HPRE_DIV_16			(0x8 + 3)
#define RCC_CFGR_HPRE_DIV_64			(0x8 + 4)
#define RCC_CFGR_HPRE_DIV_128			(0x8 + 5)
#define RCC_CFGR_HPRE_DIV_256			(0x8 + 6)
#define RCC_CFGR_HPRE_DIV_512			(0x8 + 7)

/* SWS: System clock switch status */
#define RCC_CFGR_SWS_SHIFT			2
#define RCC_CFGR_SWS_HSI			0x0
#define RCC_CFGR_SWS_HSE			0x1
#define RCC_CFGR_SWS_PLL			0x2

/* SW: System clock switch */
#define RCC_CFGR_SW_SHIFT			0
#define RCC_CFGR_SW_HSI				0x0
#define RCC_CFGR_SW_HSE				0x1
#define RCC_CFGR_SW_PLL				0x2

/* --- RCC_CIR values ------------------------------------------------------ */

/* Clock security system interrupt clear bit */
#define RCC_CIR_CSSC				(1 << 23)

/* OSC ready interrupt clear bits */
#define RCC_CIR_PLLI2SRDYC			(1 << 21)
#define RCC_CIR_PLLRDYC				(1 << 20)
#define RCC_CIR_HSERDYC				(1 << 19)
#define RCC_CIR_HSIRDYC				(1 << 18)
#define RCC_CIR_LSERDYC				(1 << 17)
#define RCC_CIR_LSIRDYC				(1 << 16)

/* OSC ready interrupt enable bits */
#define RCC_CIR_PLLI2SRDYIE			(1 << 13)
#define RCC_CIR_PLLRDYIE			(1 << 12)
#define RCC_CIR_HSERDYIE			(1 << 11)
#define RCC_CIR_HSIRDYIE			(1 << 10)
#define RCC_CIR_LSERDYIE			(1 << 9)
#define RCC_CIR_LSIRDYIE			(1 << 8)

/* Clock security system interrupt flag bit */
#define RCC_CIR_CSSF				(1 << 7)

/* OSC ready interrupt flag bits */
#define RCC_CIR_PLLI2SRDYF			(1 << 5)
#define RCC_CIR_PLLRDYF				(1 << 4)
#define RCC_CIR_HSERDYF				(1 << 3)
#define RCC_CIR_HSIRDYF				(1 << 2)
#define RCC_CIR_LSERDYF				(1 << 1)
#define RCC_CIR_LSIRDYF				(1 << 0)

/* --- RCC_AHB1RSTR values ------------------------------------------------- */

#define RCC_AHB1RSTR_OTGHSRST			(1 << 29)
#define RCC_AHB1RSTR_ETHMACRST			(1 << 25)
#define RCC_AHB1RSTR_DMA2RST			(1 << 22)
#define RCC_AHB1RSTR_DMA1RST			(1 << 21)
#define RCC_AHB1RSTR_CRCRST			(1 << 12)
#define RCC_AHB1RSTR_IOPIRST			(1 << 8)
#define RCC_AHB1RSTR_IOPHRST			(1 << 7)
#define RCC_AHB1RSTR_IOPGRST			(1 << 6)
#define RCC_AHB1RSTR_IOPFRST			(1 << 5)
#define RCC_AHB1RSTR_IOPERST			(1 << 4)
#define RCC_AHB1RSTR_IOPDRST			(1 << 3)
#define RCC_AHB1RSTR_IOPCRST			(1 << 2)
#define RCC_AHB1RSTR_IOPBRST			(1 << 1)
#define RCC_AHB1RSTR_IOPARST			(1 << 0)

/* --- RCC_AHB2RSTR values ------------------------------------------------- */

#define RCC_AHB2RSTR_OTGFSRST			(1 << 7)
#define RCC_AHB2RSTR_RNGRST			(1 << 6)
#define RCC_AHB2RSTR_HASHRST			(1 << 5)
#define RCC_AHB2RSTR_CRYPRST			(1 << 4)
#define RCC_AHB2RSTR_DCMIRST			(1 << 0)

/* --- RCC_AHB3RSTR values ------------------------------------------------- */

#define RCC_AHB3RSTR_FSMCRST			(1 << 0)

/* --- RCC_APB1RSTR values ------------------------------------------------- */

#define RCC_APB1RSTR_DACRST			(1 << 29)
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_CAN2RST			(1 << 26)
#define RCC_APB1RSTR_CAN1RST			(1 << 25)
#define RCC_APB1RSTR_I2C3RST			(1 << 23)
#define RCC_APB1RSTR_I2C2RST			(1 << 22)
#define RCC_APB1RSTR_I2C1RST			(1 << 21)
#define RCC_APB1RSTR_UART5RST			(1 << 20)
#define RCC_APB1RSTR_UART4RST			(1 << 19)
#define RCC_APB1RSTR_USART3RST			(1 << 18)
#define RCC_APB1RSTR_USART2RST			(1 << 17)
#define RCC_APB1RSTR_SPI3RST			(1 << 15)
#define RCC_APB1RSTR_SPI2RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_TIM14RST			(1 << 8)
#define RCC_APB1RSTR_TIM13RST			(1 << 7)
#define RCC_APB1RSTR_TIM12RST			(1 << 6)
#define RCC_APB1RSTR_TIM7RST			(1 << 5)
#define RCC_APB1RSTR_TIM6RST			(1 << 4)
#define RCC_APB1RSTR_TIM5RST			(1 << 3)
#define RCC_APB1RSTR_TIM4RST			(1 << 2)
#define RCC_APB1RSTR_TIM3RST			(1 << 1)
#define RCC_APB1RSTR_TIM2RST			(1 << 0)

/* --- RCC_APB2RSTR values ------------------------------------------------- */

#define RCC_APB2RSTR_TIM11RST			(1 << 18)
#define RCC_APB2RSTR_TIM10RST			(1 << 17)
#define RCC_APB2RSTR_TIM9RST			(1 << 16)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 14)
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_SDIORST			(1 << 11)
#define RCC_APB2RSTR_ADCRST			(1 << 8)
#define RCC_APB2RSTR_USART6RST			(1 << 5)
#define RCC_APB2RSTR_USART1RST			(1 << 4)
#define RCC_APB2RSTR_TIM8RST			(1 << 1)
#define RCC_APB2RSTR_TIM1RST			(1 << 0)

/* --- RCC_AHB1ENR values ------------------------------------------------- */

#define RCC_AHB1ENR_OTGHSULPIEN			(1 << 30)
#define RCC_AHB1ENR_OTGHSEN			(1 << 29)
#define RCC_AHB1ENR_ETHMACPTPEN			(1 << 28)
#define RCC_AHB1ENR_ETHMACRXEN			(1 << 27)
#define RCC_AHB1ENR_ETHMACTXEN			(1 << 26)
#define RCC_AHB1ENR_ETHMACEN			(1 << 25)
#define RCC_AHB1ENR_DMA2EN			(1 << 22)
#define RCC_AHB1ENR_DMA1EN			(1 << 21)
#define RCC_AHB1ENR_BKPSRAMEN			(1 << 18)
#define RCC_AHB1ENR_CRCEN			(1 << 12)
#define RCC_AHB1ENR_IOPIEN			(1 << 8)
#define RCC_AHB1ENR_IOPHEN			(1 << 7)
#define RCC_AHB1ENR_IOPGEN			(1 << 6)
#define RCC_AHB1ENR_IOPFEN			(1 << 5)
#define RCC_AHB1ENR_IOPEEN			(1 << 4)
#define RCC_AHB1ENR_IOPDEN			(1 << 3)
#define RCC_AHB1ENR_IOPCEN			(1 << 2)
#define RCC_AHB1ENR_IOPBEN			(1 << 1)
#define RCC_AHB1ENR_IOPAEN			(1 << 0)

/* --- RCC_AHB2ENR values ------------------------------------------------- */

#define RCC_AHB2ENR_OTGFSEN			(1 << 7)
#define RCC_AHB2ENR_RNGEN			(1 << 6)
#define RCC_AHB2ENR_HASHEN			(1 << 5)
#define RCC_AHB2ENR_CRYPEN			(1 << 4)
#define RCC_AHB2ENR_DCMIEN			(1 << 0)

/* --- RCC_AHB3ENR values ------------------------------------------------- */

#define RCC_AHB3ENR_FSMCEN			(1 << 0)

/* --- RCC_APB1ENR values ------------------------------------------------- */

#define RCC_APB1ENR_DACEN			(1 << 29)
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_CAN2EN			(1 << 26)
#define RCC_APB1ENR_CAN1EN			(1 << 25)
#define RCC_APB1ENR_I2C3EN			(1 << 23)
#define RCC_APB1ENR_I2C2EN			(1 << 22)
#define RCC_APB1ENR_I2C1EN			(1 << 21)
#define RCC_APB1ENR_UART5EN			(1 << 20)
#define RCC_APB1ENR_UART4EN			(1 << 19)
#define RCC_APB1ENR_USART3EN			(1 << 18)
#define RCC_APB1ENR_USART2EN			(1 << 17)
#define RCC_APB1ENR_SPI3EN			(1 << 15)
#define RCC_APB1ENR_SPI2EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_TIM14EN			(1 << 8)
#define RCC_APB1ENR_TIM13EN			(1 << 7)
#define RCC_APB1ENR_TIM12EN			(1 << 6)
#define RCC_APB1ENR_TIM7EN			(1 << 5)
#define RCC_APB1ENR_TIM6EN			(1 << 4)
#define RCC_APB1ENR_TIM5EN			(1 << 3)
#define RCC_APB1ENR_TIM4EN			(1 << 2)
#define RCC_APB1ENR_TIM3EN			(1 << 1)
#define RCC_APB1ENR_TIM2EN			(1 << 0)

/* --- RCC_APB2ENR values ------------------------------------------------- */

#define RCC_APB2ENR_TIM11EN			(1 << 18)
#define RCC_APB2ENR_TIM10EN			(1 << 17)
#define RCC_APB2ENR_TIM9EN			(1 << 16)
#define RCC_APB2ENR_SYSCFGEN			(1 << 14)
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_SDIOEN			(1 << 11)
#define RCC_APB2ENR_ADC3EN			(1 << 10)
#define RCC_APB2ENR_ADC2EN			(1 << 9)
#define RCC_APB2ENR_ADC1EN			(1 << 8)
#define RCC_APB2ENR_USART6EN			(1 << 5)
#define RCC_APB2ENR_USART1EN			(1 << 4)
#define RCC_APB2ENR_TIM8EN			(1 << 1)
#define RCC_APB2ENR_TIM1EN			(1 << 0)

/* --- RCC_AHB1LPENR values ------------------------------------------------- */

#define RCC_AHB1LPENR_OTGHSULPILPEN		(1 << 30)
#define RCC_AHB1LPENR_OTGHSLPEN			(1 << 29)
#define RCC_AHB1LPENR_ETHMACPTPLPEN		(1 << 28)
#define RCC_AHB1LPENR_ETHMACRXLPEN		(1 << 27)
#define RCC_AHB1LPENR_ETHMACTXLPEN		(1 << 26)
#define RCC_AHB1LPENR_ETHMACLPEN		(1 << 25)
#define RCC_AHB1LPENR_DMA2LPEN			(1 << 22)
#define RCC_AHB1LPENR_DMA1LPEN			(1 << 21)
#define RCC_AHB1LPENR_BKPSRAMLPEN		(1 << 18)
#define RCC_AHB1LPENR_SRAM2LPEN			(1 << 17)
#define RCC_AHB1LPENR_SRAM1LPEN 		(1 << 16)
#define RCC_AHB1LPENR_FLITFLPEN 		(1 << 15)
#define RCC_AHB1LPENR_CRCLPEN			(1 << 12)
#define RCC_AHB1LPENR_IOPILPEN			(1 << 8)
#define RCC_AHB1LPENR_IOPHLPEN			(1 << 7)
#define RCC_AHB1LPENR_IOPGLPEN			(1 << 6)
#define RCC_AHB1LPENR_IOPFLPEN			(1 << 5)
#define RCC_AHB1LPENR_IOPELPEN			(1 << 4)
#define RCC_AHB1LPENR_IOPDLPEN			(1 << 3)
#define RCC_AHB1LPENR_IOPCLPEN			(1 << 2)
#define RCC_AHB1LPENR_IOPBLPEN			(1 << 1)
#define RCC_AHB1LPENR_IOPALPEN			(1 << 0)

/* --- RCC_AHB2LPENR values ------------------------------------------------- */

#define RCC_AHB2LPENR_OTGFSLPEN			(1 << 7)
#define RCC_AHB2LPENR_RNGLPEN			(1 << 6)
#define RCC_AHB2LPENR_HASHLPEN			(1 << 5)
#define RCC_AHB2LPENR_CRYPLPEN			(1 << 4)
#define RCC_AHB2LPENR_DCMILPEN			(1 << 0)

/* --- RCC_AHB3LPENR values ------------------------------------------------- */

#define RCC_AHB3LPENR_FSMCLPEN			(1 << 0)

/* --- RCC_APB1LPENR values ------------------------------------------------- */

#define RCC_APB1LPENR_DACLPEN			(1 << 29)
#define RCC_APB1LPENR_PWRLPEN			(1 << 28)
#define RCC_APB1LPENR_CAN2LPEN			(1 << 26)
#define RCC_APB1LPENR_CAN1LPEN			(1 << 25)
#define RCC_APB1LPENR_I2C3LPEN			(1 << 23)
#define RCC_APB1LPENR_I2C2LPEN			(1 << 22)
#define RCC_APB1LPENR_I2C1LPEN			(1 << 21)
#define RCC_APB1LPENR_UART5LPEN			(1 << 20)
#define RCC_APB1LPENR_UART4LPEN			(1 << 19)
#define RCC_APB1LPENR_USART3LPEN		(1 << 18)
#define RCC_APB1LPENR_USART2LPEN		(1 << 17)
#define RCC_APB1LPENR_SPI3LPEN			(1 << 15)
#define RCC_APB1LPENR_SPI2LPEN			(1 << 14)
#define RCC_APB1LPENR_WWDGLPEN			(1 << 11)
#define RCC_APB1LPENR_TIM14LPEN			(1 << 8)
#define RCC_APB1LPENR_TIM13LPEN			(1 << 7)
#define RCC_APB1LPENR_TIM12LPEN			(1 << 6)
#define RCC_APB1LPENR_TIM7LPEN			(1 << 5)
#define RCC_APB1LPENR_TIM6LPEN			(1 << 4)
#define RCC_APB1LPENR_TIM5LPEN			(1 << 3)
#define RCC_APB1LPENR_TIM4LPEN			(1 << 2)
#define RCC_APB1LPENR_TIM3LPEN			(1 << 1)
#define RCC_APB1LPENR_TIM2LPEN			(1 << 0)

/* --- RCC_APB2LPENR values ------------------------------------------------- */

#define RCC_APB2LPENR_TIM11LPEN			(1 << 18)
#define RCC_APB2LPENR_TIM10LPEN			(1 << 17)
#define RCC_APB2LPENR_TIM9LPEN			(1 << 16)
#define RCC_APB2LPENR_SYSCFGLPEN		(1 << 14)
#define RCC_APB2LPENR_SPI1LPEN			(1 << 12)
#define RCC_APB2LPENR_SDIOLPEN			(1 << 11)
#define RCC_APB2LPENR_ADC3LPEN			(1 << 10)
#define RCC_APB2LPENR_ADC2LPEN			(1 << 9)
#define RCC_APB2LPENR_ADC1LPEN			(1 << 8)
#define RCC_APB2LPENR_USART6LPEN		(1 << 5)
#define RCC_APB2LPENR_USART1LPEN		(1 << 4)
#define RCC_APB2LPENR_TIM8LPEN			(1 << 1)
#define RCC_APB2LPENR_TIM1LPEN			(1 << 0)

/* --- RCC_BDCR values ----------------------------------------------------- */

#define RCC_BDCR_BDRST				(1 << 16)
#define RCC_BDCR_RTCEN				(1 << 15)
/* RCC_BDCR[9:8]: RTCSEL */
#define RCC_BDCR_LSEBYP				(1 << 2)
#define RCC_BDCR_LSERDY				(1 << 1)
#define RCC_BDCR_LSEON				(1 << 0)

/* --- RCC_CSR values ------------------------------------------------------ */

#define RCC_CSR_LPWRRSTF			(1 << 31)
#define RCC_CSR_WWDGRSTF			(1 << 30)
#define RCC_CSR_IWDGRSTF			(1 << 29)
#define RCC_CSR_SFTRSTF				(1 << 28)
#define RCC_CSR_PORRSTF				(1 << 27)
#define RCC_CSR_PINRSTF				(1 << 26)
#define RCC_CSR_BORRSTF				(1 << 26)
#define RCC_CSR_RMVF				(1 << 24)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)

/* --- RCC_SSCGR values ---------------------------------------------------- */

/* PLL spread spectrum clock generation documented in Datasheet. */

#define RCC_SSCGR_SSCGEN			(1 << 31)
#define RCC_SSCGR_SPREADSEL			(1 << 30)
/* RCC_SSCGR[27:16]: INCSTEP */
#define RCC_SSCGR_INCSTEP_SHIFT			16
/* RCC_SSCGR[15:0]: MODPER */
#define RCC_SSCGR_MODPER_SHIFT			15

/* --- RCC_PLLI2SCFGR values ----------------------------------------------- */

/* RCC_PLLI2SCFGR[30:28]: PLLI2SR */
#define RCC_PLLI2SCFGR_PLLI2SR_SHIFT		28
/* RCC_PLLI2SCFGR[14:6]: PLLI2SN */
#define RCC_PLLI2SCFGR_PLLI2SN_SHIFT		6

/* --- Variable definitions ------------------------------------------------ */
extern u32 rcc_ppre1_frequency;
extern u32 rcc_ppre2_frequency;

/* --- Function prototypes ------------------------------------------------- */

typedef enum {
	CLOCK_3V3_120MHZ,
	CLOCK_3V3_END
} clock_3v3_t;

typedef struct {
	uint8_t pllm;
	uint16_t plln;
	uint8_t pllp;
	uint8_t pllq;
	uint32_t flash_config;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
} clock_scale_t;

extern const clock_scale_t hse_8mhz_3v3[CLOCK_3V3_END];

typedef enum {
	PLL, HSE, HSI, LSE, LSI
} osc_t;

BEGIN_DECLS

void rcc_osc_ready_int_clear(osc_t osc);
void rcc_osc_ready_int_enable(osc_t osc);
void rcc_osc_ready_int_disable(osc_t osc);
int rcc_osc_ready_int_flag(osc_t osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_wait_for_osc_ready(osc_t osc);
void rcc_wait_for_sysclk_status(osc_t osc);
void rcc_osc_on(osc_t osc);
void rcc_osc_off(osc_t osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_osc_bypass_enable(osc_t osc);
void rcc_osc_bypass_disable(osc_t osc);
void rcc_peripheral_enable_clock(volatile u32 *reg, u32 en);
void rcc_peripheral_disable_clock(volatile u32 *reg, u32 en);
void rcc_peripheral_reset(volatile u32 *reg, u32 reset);
void rcc_peripheral_clear_reset(volatile u32 *reg, u32 clear_reset);
void rcc_set_sysclk_source(u32 clk);
void rcc_set_pll_source(u32 pllsrc);
void rcc_set_ppre2(u32 ppre2);
void rcc_set_ppre1(u32 ppre1);
void rcc_set_hpre(u32 hpre);
void rcc_set_rtcpre(u32 rtcpre);
void rcc_set_main_pll_hsi(u32 pllm, u32 plln, u32 pllp, u32 pllq);
void rcc_set_main_pll_hse(u32 pllm, u32 plln, u32 pllp, u32 pllq);
u32 rcc_get_system_clock_source(int i);
void rcc_clock_setup_hse_3v3(const clock_scale_t *clock);
void rcc_backupdomain_reset(void);

END_DECLS

#endif
