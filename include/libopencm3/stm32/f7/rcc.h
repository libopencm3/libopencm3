/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F7xx Reset and Clock
 * Control</b>
 *
 * @ingroup STM32F7xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2015
 * Karl Palsson <karlp@tweak.net.au>
 *
 * @date October, 2015
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/stm32/f7/pwr.h>

/* --- RCC registers ------------------------------------------------------- */

#define RCC_CR					MMIO32(RCC_BASE + 0x00)
#define RCC_PLLCFGR				MMIO32(RCC_BASE + 0x04)
#define RCC_CFGR				MMIO32(RCC_BASE + 0x08)
#define RCC_CIR					MMIO32(RCC_BASE + 0x0c)
#define RCC_AHB1RSTR				MMIO32(RCC_BASE + 0x10)
#define RCC_AHB2RSTR				MMIO32(RCC_BASE + 0x14)
#define RCC_AHB3RSTR				MMIO32(RCC_BASE + 0x18)
#define RCC_APB1RSTR				MMIO32(RCC_BASE + 0x20)
#define RCC_APB2RSTR				MMIO32(RCC_BASE + 0x24)
#define RCC_AHB1ENR				MMIO32(RCC_BASE + 0x30)
#define RCC_AHB2ENR				MMIO32(RCC_BASE + 0x34)
#define RCC_AHB3ENR				MMIO32(RCC_BASE + 0x38)
#define RCC_APB1ENR				MMIO32(RCC_BASE + 0x40)
#define RCC_APB2ENR				MMIO32(RCC_BASE + 0x44)
#define RCC_AHB1LPENR				MMIO32(RCC_BASE + 0x50)
#define RCC_AHB2LPENR				MMIO32(RCC_BASE + 0x54)
#define RCC_AHB3LPENR				MMIO32(RCC_BASE + 0x58)
#define RCC_APB1LPENR				MMIO32(RCC_BASE + 0x60)
#define RCC_APB2LPENR				MMIO32(RCC_BASE + 0x64)
#define RCC_BDCR				MMIO32(RCC_BASE + 0x70)
#define RCC_CSR					MMIO32(RCC_BASE + 0x74)
#define RCC_SSCGR				MMIO32(RCC_BASE + 0x80)
#define RCC_PLLI2SCFGR				MMIO32(RCC_BASE + 0x84)
#define RCC_PLLSAICFGR				MMIO32(RCC_BASE + 0x88)
#define RCC_DCKCFGR1				MMIO32(RCC_BASE + 0x8C)
#define RCC_DCKCFGR2				MMIO32(RCC_BASE + 0x90)

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_PLLSAIRDY			(1 << 29)
#define RCC_CR_PLLSAION				(1 << 28)
#define RCC_CR_PLLI2SRDY			(1 << 27)
#define RCC_CR_PLLI2SON				(1 << 26)
#define RCC_CR_PLLRDY				(1 << 25)
#define RCC_CR_PLLON				(1 << 24)
#define RCC_CR_CSSON				(1 << 19)
#define RCC_CR_HSEBYP				(1 << 18)
#define RCC_CR_HSERDY				(1 << 17)
#define RCC_CR_HSEON				(1 << 16)
#define RCC_CR_HSICAL_MASK			0xff
#define RCC_CR_HSICAL_SHIFT			8
#define RCC_CR_HSITRIM_MASK			0x1f
#define RCC_CR_HSITRIM_SHIFT			3
#define RCC_CR_HSIRDY				(1 << 1)
#define RCC_CR_HSION				(1 << 0)

/* --- RCC_PLLCFGR values -------------------------------------------------- */

#define RCC_PLLCFGR_PLLQ_MASK			0xf
#define RCC_PLLCFGR_PLLQ_SHIFT			24
#define RCC_PLLCFGR_PLLSRC			(1 << 22)
#define RCC_PLLCFGR_PLLP_MASK			0x3
#define RCC_PLLCFGR_PLLP_SHIFT			16
#define RCC_PLLCFGR_PLLN_MASK			0x1ff
#define RCC_PLLCFGR_PLLN_SHIFT			6
#define RCC_PLLCFGR_PLLM_MASK			0x3f
#define RCC_PLLCFGR_PLLM_SHIFT			0

/* --- RCC_CFGR values ----------------------------------------------------- */

/* MCO2: Microcontroller clock output 2 */
#define RCC_CFGR_MCO2_MASK			0x3
#define RCC_CFGR_MCO2_SHIFT			30
#define RCC_CFGR_MCO2_SYSCLK			0x0
#define RCC_CFGR_MCO2_PLLI2S			0x1
#define RCC_CFGR_MCO2_HSE			0x2
#define RCC_CFGR_MCO2_PLL			0x3

/* MCO1/2PRE: MCO Prescalers */
#define RCC_CFGR_MCOPRE_MASK			0x7
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
#define RCC_CFGR_MCO1_MASK			0x3
#define RCC_CFGR_MCO1_SHIFT			21
#define RCC_CFGR_MCO1_HSI			0x0
#define RCC_CFGR_MCO1_LSE			0x1
#define RCC_CFGR_MCO1_HSE			0x2
#define RCC_CFGR_MCO1_PLL			0x3
#define RCC_CFGR_MCO_SHIFT			RCC_CFGR_MCO1_SHIFT
#define RCC_CFGR_MCO_MASK			RCC_CFGR_MCO1_MASK

/* RTCPRE: HSE division factor for RTC clock */
#define RCC_CFGR_RTCPRE_SHIFT			16
#define RCC_CFGR_RTCPRE_MASK			0x1f

/* PPRE1/2: APB high-speed prescalers */
#define RCC_CFGR_PPRE2_SHIFT			13
#define RCC_CFGR_PPRE2_MASK			0x7
#define RCC_CFGR_PPRE1_SHIFT			10
#define RCC_CFGR_PPRE1_MASK			0x7
#define RCC_CFGR_PPRE_DIV_NONE			0x0
#define RCC_CFGR_PPRE_DIV_2			0x4
#define RCC_CFGR_PPRE_DIV_4			0x5
#define RCC_CFGR_PPRE_DIV_8			0x6
#define RCC_CFGR_PPRE_DIV_16			0x7

/* HPRE: AHB high-speed prescaler */
#define RCC_CFGR_HPRE_SHIFT			4
#define RCC_CFGR_HPRE_MASK			0xf
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
#define RCC_CFGR_SWS_MASK			0x3
#define RCC_CFGR_SWS_HSI			0x0
#define RCC_CFGR_SWS_HSE			0x1
#define RCC_CFGR_SWS_PLL			0x2

/* SW: System clock switch */
#define RCC_CFGR_SW_SHIFT			0
#define RCC_CFGR_SW_MASK			0x3
#define RCC_CFGR_SW_HSI				0x0
#define RCC_CFGR_SW_HSE				0x1
#define RCC_CFGR_SW_PLL				0x2

/* --- RCC_CIR values ------------------------------------------------------ */

/* Clock security system interrupt clear bit */
#define RCC_CIR_CSSC				(1 << 23)

/* OSC ready interrupt clear bits */
#define RCC_CIR_PLLSAIRDYC			(1 << 22)
#define RCC_CIR_PLLI2SRDYC			(1 << 21)
#define RCC_CIR_PLLRDYC				(1 << 20)
#define RCC_CIR_HSERDYC				(1 << 19)
#define RCC_CIR_HSIRDYC				(1 << 18)
#define RCC_CIR_LSERDYC				(1 << 17)
#define RCC_CIR_LSIRDYC				(1 << 16)

/* OSC ready interrupt enable bits */
#define RCC_CIR_PLLSAIRDYIE			(1 << 14)
#define RCC_CIR_PLLI2SRDYIE			(1 << 13)
#define RCC_CIR_PLLRDYIE			(1 << 12)
#define RCC_CIR_HSERDYIE			(1 << 11)
#define RCC_CIR_HSIRDYIE			(1 << 10)
#define RCC_CIR_LSERDYIE			(1 << 9)
#define RCC_CIR_LSIRDYIE			(1 << 8)

/* Clock security system interrupt flag bit */
#define RCC_CIR_CSSF				(1 << 7)

/* OSC ready interrupt flag bits */
#define RCC_CIR_PLLSAIRDYF			(1 << 6)
#define RCC_CIR_PLLI2SRDYF			(1 << 5)
#define RCC_CIR_PLLRDYF				(1 << 4)
#define RCC_CIR_HSERDYF				(1 << 3)
#define RCC_CIR_HSIRDYF				(1 << 2)
#define RCC_CIR_LSERDYF				(1 << 1)
#define RCC_CIR_LSIRDYF				(1 << 0)

/* --- RCC_AHB1RSTR values ------------------------------------------------- */

#define RCC_AHB1RSTR_OTGHSRST			(1 << 29)
#define RCC_AHB1RSTR_ETHMACRST			(1 << 25)
#define RCC_AHB1RSTR_DMA2DRST			(1 << 23)
#define RCC_AHB1RSTR_DMA2RST			(1 << 22)
#define RCC_AHB1RSTR_DMA1RST			(1 << 21)
#define RCC_AHB1RSTR_CRCRST			(1 << 12)
#define RCC_AHB1RSTR_GPIOKRST			(1 << 10)
#define RCC_AHB1RSTR_GPIOJRST			(1 << 9)
#define RCC_AHB1RSTR_GPIOIRST			(1 << 8)
#define RCC_AHB1RSTR_GPIOHRST			(1 << 7)
#define RCC_AHB1RSTR_GPIOGRST			(1 << 6)
#define RCC_AHB1RSTR_GPIOFRST			(1 << 5)
#define RCC_AHB1RSTR_GPIOERST			(1 << 4)
#define RCC_AHB1RSTR_GPIODRST			(1 << 3)
#define RCC_AHB1RSTR_GPIOCRST			(1 << 2)
#define RCC_AHB1RSTR_GPIOBRST			(1 << 1)
#define RCC_AHB1RSTR_GPIOARST			(1 << 0)

/* --- RCC_AHB2RSTR values ------------------------------------------------- */

#define RCC_AHB2RSTR_OTGFSRST			(1 << 7)
#define RCC_AHB2RSTR_RNGRST			(1 << 6)
#define RCC_AHB2RSTR_HASHRST			(1 << 5)
#define RCC_AHB2RSTR_CRYPRST			(1 << 4)
#define RCC_AHB2RSTR_DCMIRST			(1 << 0)

/* --- RCC_AHB3RSTR values ------------------------------------------------- */

#define RCC_AHB3RSTR_QSPIRST			(1 << 1)
#define RCC_AHB3RSTR_FSMCRST			(1 << 0)

/* --- RCC_APB1RSTR values ------------------------------------------------- */

#define RCC_APB1RSTR_UART8RST			(1 << 31)
#define RCC_APB1RSTR_UART7RST			(1 << 30)
#define RCC_APB1RSTR_DACRST			(1 << 29)
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_CECRST			(1 << 27)
#define RCC_APB1RSTR_CAN2RST			(1 << 26)
#define RCC_APB1RSTR_CAN1RST			(1 << 25)
#define RCC_APB1RSTR_I2C4RST			(1 << 24)
#define RCC_APB1RSTR_I2C3RST			(1 << 23)
#define RCC_APB1RSTR_I2C2RST			(1 << 22)
#define RCC_APB1RSTR_I2C1RST			(1 << 21)
#define RCC_APB1RSTR_UART5RST			(1 << 20)
#define RCC_APB1RSTR_UART4RST			(1 << 19)
#define RCC_APB1RSTR_UART3RST			(1 << 18)
#define RCC_APB1RSTR_UART2RST			(1 << 17)
#define RCC_APB1RSTR_SPDIFRXRST			(1 << 16)
#define RCC_APB1RSTR_SPI3RST			(1 << 15)
#define RCC_APB1RSTR_SPI2RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_LPTIM1RST			(1 << 9)
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

#define RCC_APB2RSTR_LTDCRST			(1 << 26)
#define RCC_APB2RSTR_SAI2RST			(1 << 23)
#define RCC_APB2RSTR_SAI1RST			(1 << 22)
#define RCC_APB2RSTR_SPI6RST			(1 << 21)
#define RCC_APB2RSTR_SPI5RST			(1 << 20)
#define RCC_APB2RSTR_TIM11RST			(1 << 18)
#define RCC_APB2RSTR_TIM10RST			(1 << 17)
#define RCC_APB2RSTR_TIM9RST			(1 << 16)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 14)
#define RCC_APB2RSTR_SPI4RST			(1 << 13)
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_SDMMC1RST			(1 << 11)
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
#define RCC_AHB1ENR_DMA2DEN			(1 << 23)
#define RCC_AHB1ENR_DMA2EN			(1 << 22)
#define RCC_AHB1ENR_DMA1EN			(1 << 21)
#define RCC_AHB1ENR_DTCMRAMEN			(1 << 20)
#define RCC_AHB1ENR_BKPSRAMEN			(1 << 18)
#define RCC_AHB1ENR_CRCEN			(1 << 12)
#define RCC_AHB1ENR_GPIOKEN			(1 << 10)
#define RCC_AHB1ENR_GPIOJEN			(1 << 9)
#define RCC_AHB1ENR_GPIOIEN			(1 << 8)
#define RCC_AHB1ENR_GPIOHEN			(1 << 7)
#define RCC_AHB1ENR_GPIOGEN			(1 << 6)
#define RCC_AHB1ENR_GPIOFEN			(1 << 5)
#define RCC_AHB1ENR_GPIOEEN			(1 << 4)
#define RCC_AHB1ENR_GPIODEN			(1 << 3)
#define RCC_AHB1ENR_GPIOCEN			(1 << 2)
#define RCC_AHB1ENR_GPIOBEN			(1 << 1)
#define RCC_AHB1ENR_GPIOAEN			(1 << 0)

/* --- RCC_AHB2ENR values ------------------------------------------------- */

#define RCC_AHB2ENR_OTGFSEN			(1 << 7)
#define RCC_AHB2ENR_RNGEN			(1 << 6)
#define RCC_AHB2ENR_HASHEN			(1 << 5)
#define RCC_AHB2ENR_CRYPEN			(1 << 4)
#define RCC_AHB2ENR_DCMIEN			(1 << 0)

/* --- RCC_AHB3ENR values ------------------------------------------------- */

#define RCC_AHB3ENR_QSPIEN			(1 << 1)
#define RCC_AHB3ENR_FMCEN			(1 << 0)

/* --- RCC_APB1ENR values ------------------------------------------------- */

#define RCC_APB1ENR_UART8EN			(1 << 31)
#define RCC_APB1ENR_UART7EN			(1 << 30)
#define RCC_APB1ENR_DACEN			(1 << 29)
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_CECEN			(1 << 27)
#define RCC_APB1ENR_CAN2EN			(1 << 26)
#define RCC_APB1ENR_CAN1EN			(1 << 25)
#define RCC_APB1ENR_I2C4EN			(1 << 24)
#define RCC_APB1ENR_I2C3EN			(1 << 23)
#define RCC_APB1ENR_I2C2EN			(1 << 22)
#define RCC_APB1ENR_I2C1EN			(1 << 21)
#define RCC_APB1ENR_UART5EN			(1 << 20)
#define RCC_APB1ENR_UART4EN			(1 << 19)
#define RCC_APB1ENR_USART3EN			(1 << 18)
#define RCC_APB1ENR_USART2EN			(1 << 17)
#define RCC_APB1ENR_SPIDIFRXEN			(1 << 16)
#define RCC_APB1ENR_SPI3EN			(1 << 15)
#define RCC_APB1ENR_SPI2EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_LPTIM1EN			(1 << 9)
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

#define RCC_APB2ENR_LTDCEN			(1 << 26)
#define RCC_APB2ENR_SAI2EN			(1 << 23)
#define RCC_APB2ENR_SAI1EN			(1 << 22)
#define RCC_APB2ENR_SPI6EN			(1 << 21)
#define RCC_APB2ENR_SPI5EN			(1 << 20)
#define RCC_APB2ENR_TIM11EN			(1 << 18)
#define RCC_APB2ENR_TIM10EN			(1 << 17)
#define RCC_APB2ENR_TIM9EN			(1 << 16)
#define RCC_APB2ENR_SYSCFGEN			(1 << 14)
#define RCC_APB2ENR_SPI4EN			(1 << 13)
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_SDMMC1EN			(1 << 11)
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
#define RCC_AHB1LPENR_DMA2DLPEN			(1 << 23)
#define RCC_AHB1LPENR_DMA2LPEN			(1 << 22)
#define RCC_AHB1LPENR_DMA1LPEN			(1 << 21)
#define RCC_AHB1LPENR_DTCMLPEN			(1 << 20)
#define RCC_AHB1LPENR_BKPSRAMLPEN		(1 << 18)
#define RCC_AHB1LPENR_SRAM2LPEN			(1 << 17)
#define RCC_AHB1LPENR_SRAM1LPEN			(1 << 16)
#define RCC_AHB1LPENR_FLITFLPEN			(1 << 15)
#define RCC_AHB1LPENR_AXILPEN			(1 << 13)
#define RCC_AHB1LPENR_CRCLPEN			(1 << 12)
#define RCC_AHB1LPENR_GPIOKLPEN			(1 << 10)
#define RCC_AHB1LPENR_GPIOJLPEN			(1 << 9)
#define RCC_AHB1LPENR_GPIOILPEN			(1 << 8)
#define RCC_AHB1LPENR_GPIOHLPEN			(1 << 7)
#define RCC_AHB1LPENR_GPIOGLPEN			(1 << 6)
#define RCC_AHB1LPENR_GPIOFLPEN			(1 << 5)
#define RCC_AHB1LPENR_GPIOELPEN			(1 << 4)
#define RCC_AHB1LPENR_GPIODLPEN			(1 << 3)
#define RCC_AHB1LPENR_GPIOCLPEN			(1 << 2)
#define RCC_AHB1LPENR_GPIOBLPEN			(1 << 1)
#define RCC_AHB1LPENR_GPIOALPEN			(1 << 0)

/* --- RCC_AHB2LPENR values ------------------------------------------------- */

#define RCC_AHB2LPENR_OTGFSLPEN			(1 << 7)
#define RCC_AHB2LPENR_RNGLPEN			(1 << 6)
#define RCC_AHB2LPENR_HASHLPEN			(1 << 5)
#define RCC_AHB2LPENR_CRYPLPEN			(1 << 4)
#define RCC_AHB2LPENR_DCMILPEN			(1 << 0)

/* --- RCC_AHB3LPENR values ------------------------------------------------- */

#define RCC_AHB3LPENR_QSPILPEN			(1 << 1)
#define RCC_AHB3LPENR_FMCLPEN			(1 << 0)

/* --- RCC_APB1LPENR values ------------------------------------------------- */

#define RCC_APB1LPENR_UART8LPEN			(1 << 31)
#define RCC_APB1LPENR_UART7LPEN			(1 << 30)
#define RCC_APB1LPENR_DACLPEN			(1 << 29)
#define RCC_APB1LPENR_PWRLPEN			(1 << 28)
#define RCC_APB1LPENR_CECLPEN			(1 << 27)
#define RCC_APB1LPENR_CAN2LPEN			(1 << 26)
#define RCC_APB1LPENR_CAN1LPEN			(1 << 25)
#define RCC_APB1LPENR_I2C4LPEN			(1 << 24)
#define RCC_APB1LPENR_I2C3LPEN			(1 << 23)
#define RCC_APB1LPENR_I2C2LPEN			(1 << 22)
#define RCC_APB1LPENR_I2C1LPEN			(1 << 21)
#define RCC_APB1LPENR_UART5LPEN			(1 << 20)
#define RCC_APB1LPENR_UART4LPEN			(1 << 19)
#define RCC_APB1LPENR_USART3LPEN		(1 << 18)
#define RCC_APB1LPENR_USART2LPEN		(1 << 17)
#define RCC_APB1LPENR_SPIDIFRXLPEN		(1 << 16)
#define RCC_APB1LPENR_SPI3LPEN			(1 << 15)
#define RCC_APB1LPENR_SPI2LPEN			(1 << 14)
#define RCC_APB1LPENR_WWDGLPEN			(1 << 11)
#define RCC_APB1LPENR_LPTIM1LPEN		(1 << 9)
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

#define RCC_APB2LPENR_LTDCLPEN			(1 << 26)
#define RCC_APB2LPENR_SAI2LPEN			(1 << 23)
#define RCC_APB2LPENR_SAI1LPEN			(1 << 22)
#define RCC_APB2LPENR_SPI6LPEN			(1 << 21)
#define RCC_APB2LPENR_SPI5LPEN			(1 << 20)
#define RCC_APB2LPENR_TIM11LPEN			(1 << 18)
#define RCC_APB2LPENR_TIM10LPEN			(1 << 17)
#define RCC_APB2LPENR_TIM9LPEN			(1 << 16)
#define RCC_APB2LPENR_SYSCFGLPEN		(1 << 14)
#define RCC_APB2LPENR_SPI4LPEN			(1 << 13)
#define RCC_APB2LPENR_SPI1LPEN			(1 << 12)
#define RCC_APB2LPENR_SDMMC1LPEN		(1 << 11)
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
#define RCC_BDCR_RTCSEL_MASK			0x3
#define RCC_BDCR_RTCSEL_SHIFT			8
#define RCC_BDCR_RTCSEL_NONE			0
#define RCC_BDCR_RTCSEL_LSE			1
#define RCC_BDCR_RTCSEL_LSI			2
#define RCC_BDCR_RTCSEL_HSE			3
#define RCC_BDCR_LSEDRV_MASK			0x3
#define RCC_BDCR_LSEDRV_SHIFT			3
#define RCC_BDCR_LSEDRV_LOW			0
#define RCC_BDCR_LSEDRV_MEDH			1 /* good job st */
#define RCC_BDCR_LSEDRV_MEDL			2
#define RCC_BDCR_LSEDRV_HIGH			3
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
#define RCC_CSR_BORRSTF				(1 << 25)
#define RCC_CSR_RMVF				(1 << 24)
#define RCC_CSR_RESET_FLAGS	(RCC_CSR_LPWRRSTF | RCC_CSR_WWDGRSTF |\
		RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF | RCC_CSR_PORRSTF |\
		RCC_CSR_PINRSTF | RCC_CSR_BORRSTF)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)

/* --- RCC_SSCGR values ---------------------------------------------------- */

#define RCC_SSCGR_SSCGEN			(1 << 31)
#define RCC_SSCGR_SPREADSEL			(1 << 30)
#define RCC_SSCGR_INCSTEP_MASK			0x7fff
#define RCC_SSCGR_INCSTEP_SHIFT			13
#define RCC_SSCGR_MODPER_MASK			0x1fff
#define RCC_SSCGR_MODPER_SHIFT			0

/* --- RCC_PLLI2SCFGR values ----------------------------------------------- */

/* RCC_PLLI2SCFGR[30:28]: PLLI2SR */
#define RCC_PLLI2SCFGR_PLLI2S_MASK		0x7
#define RCC_PLLI2SCFGR_PLLI2S_SHIFT		28
#define RCC_PLLI2SCFGR_PLLI2SQ_MASK		0xf
#define RCC_PLLI2SCFGR_PLLI2SQ_SHIFT		24
#define RCC_PLLI2SCFGR_PLLI2SP_MASK		0x3
#define RCC_PLLI2SCFGR_PLLI2SP_SHIFT		16
#define RCC_PLLI2SCFGR_PLLI2SN_MASK		0x1ff
#define RCC_PLLI2SCFGR_PLLI2SN_SHIFT		6

/* --- RCC_PLLSAICFGR values ----------------------------------------------- */

#define RCC_PLLSAICFGR_PLLSAIR_MASK		0x7
#define RCC_PLLSAICFGR_PLLSAIR_SHIFT		28
#define RCC_PLLSAICFGR_PLLSAIQ_MASK		0xf
#define RCC_PLLSAICFGR_PLLSAIQ_SHIFT		24
#define RCC_PLLSAICFGR_PLLSAIP_MASK		0x3
#define RCC_PLLSAICFGR_PLLSAIP_SHIFT		16
#define RCC_PLLSAICFGR_PLLSAIN_MASK		0x1FF
#define RCC_PLLSAICFGR_PLLSAIN_SHIFT		6

/* --- RCC_DCKCFGR1 values -------------------------------------------------- */

#define RCC_DCKCFGR1_TIMPRE			(1<<24)
#define RCC_DCKCFGR1_SAI2SEL_MASK		0x3
#define RCC_DCKCFGR1_SAI2SEL_SHIFT		22
#define RCC_DCKCFGR1_SAI1SEL_MASK		0x3
#define RCC_DCKCFGR1_SAI1SEL_SHIFT		20
#define RCC_DCKCFGR1_PLLSAIDIVR_MASK		0x3
#define RCC_DCKCFGR1_PLLSAIDIVR_SHIFT		16
#define RCC_DCKCFGR1_PLLSAIDIVR_DIVR_2		0
#define RCC_DCKCFGR1_PLLSAIDIVR_DIVR_4		1
#define RCC_DCKCFGR1_PLLSAIDIVR_DIVR_8		2
#define RCC_DCKCFGR1_PLLSAIDIVR_DIVR_16		3
#define RCC_DCKCFGR1_PLLSAIDIVQ_MASK		0x1f
#define RCC_DCKCFGR1_PLLSAIDIVQ_SHIFT		8
#define RCC_DCKCFGR1_PLLI2SDIVQ_MASK		0x1f
#define RCC_DCKCFGR1_PLLI2SDIVQ_SHIFT		0

/* --- RCC_DCKCFGR2 values -------------------------------------------------- */

#define RCC_DCKCFGR2_SDMMCSEL			(1<<28)
#define RCC_DCKCFGR2_CK48MSEL			(1<<27)
#define RCC_DCKCFGR2_CECSEL			(1<<26)
#define RCC_DCKCFGR2_LPTIM1SEL_MASK		0x3
#define RCC_DCKCFGR2_LPTIM1SEL_SHIFT		24
#define RCC_DCKCFGR2_I2C4SEL_MASK		0x3
#define RCC_DCKCFGR2_I2C4SEL_SHIFT		22
#define RCC_DCKCFGR2_I2C3SEL_MASK		0x3
#define RCC_DCKCFGR2_I2C3SEL_SHIFT		20
#define RCC_DCKCFGR2_I2C2SEL_MASK		0x3
#define RCC_DCKCFGR2_I2C2SEL_SHIFT		18
#define RCC_DCKCFGR2_I2C1SEL_MASK		0x3
#define RCC_DCKCFGR2_I2C1SEL_SHIFT		16
#define RCC_DCKCFGR2_UART8SEL_MASK		0x3
#define RCC_DCKCFGR2_UART8SEL_SHIFT		14
#define RCC_DCKCFGR2_UART7SEL_MASK		0x3
#define RCC_DCKCFGR2_UART7SEL_SHIFT		12
#define RCC_DCKCFGR2_USART6SEL_MASK		0x3
#define RCC_DCKCFGR2_USART6SEL_SHIFT		10
#define RCC_DCKCFGR2_UART5SEL_MASK		0x3
#define RCC_DCKCFGR2_UART5SEL_SHIFT		8
#define RCC_DCKCFGR2_UART4SEL_MASK		0x3
#define RCC_DCKCFGR2_UART4SEL_SHIFT		6
#define RCC_DCKCFGR2_UART3SEL_MASK		0x3
#define RCC_DCKCFGR2_UART3SEL_SHIFT		4
#define RCC_DCKCFGR2_UART2SEL_MASK		0x3
#define RCC_DCKCFGR2_UART2SEL_SHIFT		2
#define RCC_DCKCFGR2_UART1SEL_MASK		0x3
#define RCC_DCKCFGR2_UART1SEL_SHIFT		0

extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

enum rcc_clock_3v3 {
	RCC_CLOCK_3V3_216MHZ,
	RCC_CLOCK_3V3_END
};

struct rcc_clock_scale {
	uint8_t pllm;
	uint16_t plln;
	uint8_t pllp;
	uint8_t pllq;
	uint32_t flash_config;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	enum pwr_vos_scale vos_scale;
	uint8_t overdrive;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_END];

enum rcc_osc {
	RCC_PLL,
	RCC_HSE,
	RCC_HSI,
	RCC_LSE,
	RCC_LSI
};

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

enum rcc_periph_clken {
	/* AHB1 peripherals*/
	RCC_GPIOA	= _REG_BIT(0x30, 0),
	RCC_GPIOB	= _REG_BIT(0x30, 1),
	RCC_GPIOC	= _REG_BIT(0x30, 2),
	RCC_GPIOD	= _REG_BIT(0x30, 3),
	RCC_GPIOE	= _REG_BIT(0x30, 4),
	RCC_GPIOF	= _REG_BIT(0x30, 5),
	RCC_GPIOG	= _REG_BIT(0x30, 6),
	RCC_GPIOH	= _REG_BIT(0x30, 7),
	RCC_GPIOI	= _REG_BIT(0x30, 8),
	RCC_GPIOJ	= _REG_BIT(0x30, 9),
	RCC_GPIOK	= _REG_BIT(0x30, 10),
	RCC_CRC		= _REG_BIT(0x30, 12),
	RCC_BKPSRAM	= _REG_BIT(0x30, 18),
	RCC_DTCMRAM	= _REG_BIT(0x30, 20),
	RCC_DMA1	= _REG_BIT(0x30, 21),
	RCC_DMA2	= _REG_BIT(0x30, 22),
	RCC_DMA2D	= _REG_BIT(0x30, 23),
	RCC_ETHMAC	= _REG_BIT(0x30, 25),
	RCC_ETHMACTX	= _REG_BIT(0x30, 26),
	RCC_ETHMACRX	= _REG_BIT(0x30, 27),
	RCC_ETHMACPTP	= _REG_BIT(0x30, 28),
	RCC_OTGHS	= _REG_BIT(0x30, 29),
	RCC_OTGHSULPI	= _REG_BIT(0x30, 30),

	/* AHB2 peripherals */
	RCC_DCMI	= _REG_BIT(0x34, 0),
	RCC_CRYP	= _REG_BIT(0x34, 4),
	RCC_HASH	= _REG_BIT(0x34, 5),
	RCC_RNG		= _REG_BIT(0x34, 6),
	RCC_OTGFS	= _REG_BIT(0x34, 7),

	/* AHB3 peripherals */
	RCC_QSPI	= _REG_BIT(0x38, 1),
	RCC_FMC		= _REG_BIT(0x38, 0),

	/* APB1 peripherals*/
	RCC_TIM2	= _REG_BIT(0x40, 0),
	RCC_TIM3	= _REG_BIT(0x40, 1),
	RCC_TIM4	= _REG_BIT(0x40, 2),
	RCC_TIM5	= _REG_BIT(0x40, 3),
	RCC_TIM6	= _REG_BIT(0x40, 4),
	RCC_TIM7	= _REG_BIT(0x40, 5),
	RCC_TIM12	= _REG_BIT(0x40, 6),
	RCC_TIM13	= _REG_BIT(0x40, 7),
	RCC_TIM14	= _REG_BIT(0x40, 8),
	RCC_LPTIM1	= _REG_BIT(0x40, 9),
	RCC_WWDG	= _REG_BIT(0x40, 11),
	RCC_SPI2	= _REG_BIT(0x40, 14),
	RCC_SPI3	= _REG_BIT(0x40, 15),
	RCC_SPDIFRX	= _REG_BIT(0x40, 16),
	RCC_USART2	= _REG_BIT(0x40, 17),
	RCC_USART3	= _REG_BIT(0x40, 18),
	RCC_UART4	= _REG_BIT(0x40, 19),
	RCC_UART5	= _REG_BIT(0x40, 20),
	RCC_I2C1	= _REG_BIT(0x40, 21),
	RCC_I2C2	= _REG_BIT(0x40, 22),
	RCC_I2C3	= _REG_BIT(0x40, 23),
	RCC_I2C4	= _REG_BIT(0x40, 24),
	RCC_CAN1	= _REG_BIT(0x40, 25),
	RCC_CAN2	= _REG_BIT(0x40, 26),
	RCC_CEC		= _REG_BIT(0x40, 27),
	RCC_PWR		= _REG_BIT(0x40, 28),
	RCC_DAC		= _REG_BIT(0x40, 29),
	RCC_SPI7	= _REG_BIT(0x40, 30),
	RCC_SPI8	= _REG_BIT(0x40, 31),

	/* APB2 peripherals */
	RCC_TIM1	= _REG_BIT(0x44, 0),
	RCC_TIM8	= _REG_BIT(0x44, 1),
	RCC_USART1	= _REG_BIT(0x44, 4),
	RCC_USART6	= _REG_BIT(0x44, 5),
	RCC_ADC1	= _REG_BIT(0x44, 8),
	RCC_ADC2	= _REG_BIT(0x44, 9),
	RCC_ADC3	= _REG_BIT(0x44, 10),
	RCC_SDMMC1	= _REG_BIT(0x44, 11),
	RCC_SPI1	= _REG_BIT(0x44, 12),
	RCC_SPI4	= _REG_BIT(0x44, 13),
	RCC_SYSCFG	= _REG_BIT(0x44, 14),
	RCC_TIM9	= _REG_BIT(0x44, 16),
	RCC_TIM10	= _REG_BIT(0x44, 17),
	RCC_TIM11	= _REG_BIT(0x44, 18),
	RCC_SPI5	= _REG_BIT(0x44, 20),
	RCC_SPI6	= _REG_BIT(0x44, 21),
	RCC_SAI1EN	= _REG_BIT(0x44, 22),
	RCC_SAI2EN	= _REG_BIT(0x44, 23),
	RCC_LTDC	= _REG_BIT(0x44, 26),


	/* BDCR */
	RCC_RTC		= _REG_BIT(0x70, 15),

	/* AHB1 peripherals*/
	SCC_GPIOA	= _REG_BIT(0x50, 0),
	SCC_GPIOB	= _REG_BIT(0x50, 1),
	SCC_GPIOC	= _REG_BIT(0x50, 2),
	SCC_GPIOD	= _REG_BIT(0x50, 3),
	SCC_GPIOE	= _REG_BIT(0x50, 4),
	SCC_GPIOF	= _REG_BIT(0x50, 5),
	SCC_GPIOG	= _REG_BIT(0x50, 6),
	SCC_GPIOH	= _REG_BIT(0x50, 7),
	SCC_GPIOI	= _REG_BIT(0x50, 8),
	SCC_GPIOJ	= _REG_BIT(0x50, 9),
	SCC_GPIOK	= _REG_BIT(0x50, 10),
	SCC_CRC		= _REG_BIT(0x50, 12),
	SCC_AXI		= _REG_BIT(0x50, 13),
	SCC_FLTIF	= _REG_BIT(0x50, 15),
	SCC_SRAM1	= _REG_BIT(0x50, 16),
	SCC_SRAM2	= _REG_BIT(0x50, 17),
	SCC_BKPSRAM	= _REG_BIT(0x50, 18),
	SCC_DTCM	= _REG_BIT(0x50, 20),
	SCC_DMA1	= _REG_BIT(0x50, 21),
	SCC_DMA2	= _REG_BIT(0x50, 22),
	SCC_DMA2D	= _REG_BIT(0x50, 23),
	SCC_ETHMAC	= _REG_BIT(0x50, 25),
	SCC_ETHMACTX	= _REG_BIT(0x50, 26),
	SCC_ETHMACRX	= _REG_BIT(0x50, 27),
	SCC_ETHMACPTP	= _REG_BIT(0x50, 28),
	SCC_OTGHS	= _REG_BIT(0x50, 29),
	SCC_OTGHSULPI	= _REG_BIT(0x50, 30),

	/* AHB2 peripherals */
	SCC_DCMI	= _REG_BIT(0x54, 0),
	SCC_CRYP	= _REG_BIT(0x54, 4),
	SCC_HASH	= _REG_BIT(0x54, 5),
	SCC_RNG		= _REG_BIT(0x54, 6),
	SCC_OTGFS	= _REG_BIT(0x54, 7),

	/* AHB3 peripherals */
	SCC_QSPI	= _REG_BIT(0x58, 1),
	SCC_FMC		= _REG_BIT(0x58, 0),

	/* APB1 peripherals*/
	SCC_TIM2	= _REG_BIT(0x60, 0),
	SCC_TIM3	= _REG_BIT(0x60, 1),
	SCC_TIM4	= _REG_BIT(0x60, 2),
	SCC_TIM5	= _REG_BIT(0x60, 3),
	SCC_TIM6	= _REG_BIT(0x60, 4),
	SCC_TIM7	= _REG_BIT(0x60, 5),
	SCC_TIM12	= _REG_BIT(0x60, 6),
	SCC_TIM13	= _REG_BIT(0x60, 7),
	SCC_TIM14	= _REG_BIT(0x60, 8),
	SCC_LPTIM1	= _REG_BIT(0x60, 9),
	SCC_WWDG	= _REG_BIT(0x60, 11),
	SCC_SPI2	= _REG_BIT(0x60, 14),
	SCC_SPI3	= _REG_BIT(0x60, 15),
	SCC_SPDIFRX	= _REG_BIT(0x60, 16),
	SCC_USART2	= _REG_BIT(0x60, 17),
	SCC_USART3	= _REG_BIT(0x60, 18),
	SCC_UART4	= _REG_BIT(0x60, 19),
	SCC_UART5	= _REG_BIT(0x60, 20),
	SCC_I2C1	= _REG_BIT(0x60, 21),
	SCC_I2C2	= _REG_BIT(0x60, 22),
	SCC_I2C3	= _REG_BIT(0x60, 23),
	SCC_I2C4	= _REG_BIT(0x60, 24),
	SCC_CAN1	= _REG_BIT(0x60, 25),
	SCC_CAN2	= _REG_BIT(0x60, 26),
	SCC_CEC		= _REG_BIT(0x60, 27),
	SCC_PWR		= _REG_BIT(0x60, 28),
	SCC_DAC		= _REG_BIT(0x60, 29),
	SCC_UART7	= _REG_BIT(0x60, 30),
	SCC_UART8	= _REG_BIT(0x60, 31),

	/* APB2 peripherals */
	SCC_TIM1	= _REG_BIT(0x64, 0),
	SCC_TIM8	= _REG_BIT(0x64, 1),
	SCC_USART1	= _REG_BIT(0x64, 4),
	SCC_USART6	= _REG_BIT(0x64, 5),
	SCC_ADC1	= _REG_BIT(0x64, 8),
	SCC_ADC2	= _REG_BIT(0x64, 9),
	SCC_ADC3	= _REG_BIT(0x64, 10),
	SCC_SDMMC1	= _REG_BIT(0x64, 11),
	SCC_SPI1	= _REG_BIT(0x64, 12),
	SCC_SPI4	= _REG_BIT(0x64, 13),
	SCC_SYSCFG	= _REG_BIT(0x64, 14),
	SCC_TIM9	= _REG_BIT(0x64, 16),
	SCC_TIM10	= _REG_BIT(0x64, 17),
	SCC_TIM11	= _REG_BIT(0x64, 18),
	SCC_SPI5	= _REG_BIT(0x64, 20),
	SCC_SPI6	= _REG_BIT(0x64, 21),
	SCC_SAI1	= _REG_BIT(0x64, 22),
	SCC_SAI2	= _REG_BIT(0x64, 23),
	SCC_LTDC	= _REG_BIT(0x64, 26),
};

enum rcc_periph_rst {
	/* AHB1 peripherals*/
	RST_GPIOA	= _REG_BIT(0x10, 0),
	RST_GPIOB	= _REG_BIT(0x10, 1),
	RST_GPIOC	= _REG_BIT(0x10, 2),
	RST_GPIOD	= _REG_BIT(0x10, 3),
	RST_GPIOE	= _REG_BIT(0x10, 4),
	RST_GPIOF	= _REG_BIT(0x10, 5),
	RST_GPIOG	= _REG_BIT(0x10, 6),
	RST_GPIOH	= _REG_BIT(0x10, 7),
	RST_GPIOI	= _REG_BIT(0x10, 8),
	RST_GPIOJ	= _REG_BIT(0x10, 9),
	RST_GPIOK	= _REG_BIT(0x10, 10),
	RST_CRC		= _REG_BIT(0x10, 12),
	RST_DMA1	= _REG_BIT(0x10, 21),
	RST_DMA2	= _REG_BIT(0x10, 22),
	RST_DMA2D	= _REG_BIT(0x10, 23),
	RST_ETHMAC	= _REG_BIT(0x10, 25),
	RST_OTGHS	= _REG_BIT(0x10, 29),

	/* AHB2 peripherals */
	RST_DCMI	= _REG_BIT(0x14, 0),
	RST_CRYP	= _REG_BIT(0x14, 4),
	RST_HASH	= _REG_BIT(0x14, 5),
	RST_RNG		= _REG_BIT(0x14, 6),
	RST_OTGFS	= _REG_BIT(0x14, 7),

	/* AHB3 peripherals */
	RST_QSPI	= _REG_BIT(0x18, 1),
	RST_FMC		= _REG_BIT(0x18, 0),

	/* APB1 peripherals*/
	RST_TIM2	= _REG_BIT(0x20, 0),
	RST_TIM3	= _REG_BIT(0x20, 1),
	RST_TIM4	= _REG_BIT(0x20, 2),
	RST_TIM5	= _REG_BIT(0x20, 3),
	RST_TIM6	= _REG_BIT(0x20, 4),
	RST_TIM7	= _REG_BIT(0x20, 5),
	RST_TIM12	= _REG_BIT(0x20, 6),
	RST_TIM13	= _REG_BIT(0x20, 7),
	RST_TIM14	= _REG_BIT(0x20, 8),
	RST_LPTIM1	= _REG_BIT(0x20, 9),
	RST_WWDG	= _REG_BIT(0x20, 11),
	RST_SPI2	= _REG_BIT(0x20, 14),
	RST_SPI3	= _REG_BIT(0x20, 15),
	RST_SPDIFRX	= _REG_BIT(0x20, 16),
	RST_UART2	= _REG_BIT(0x20, 17),
	RST_UART3	= _REG_BIT(0x20, 18),
	RST_UART4	= _REG_BIT(0x20, 19),
	RST_UART5	= _REG_BIT(0x20, 20),
	RST_I2C1	= _REG_BIT(0x20, 21),
	RST_I2C2	= _REG_BIT(0x20, 22),
	RST_I2C3	= _REG_BIT(0x20, 23),
	RST_I2C4	= _REG_BIT(0x20, 24),
	RST_CAN1	= _REG_BIT(0x20, 25),
	RST_CAN2	= _REG_BIT(0x20, 26),
	RST_CEC		= _REG_BIT(0x20, 27),
	RST_PWR		= _REG_BIT(0x20, 28),
	RST_DAC		= _REG_BIT(0x20, 29),
	RST_UART7	= _REG_BIT(0x20, 30),
	RST_UART8	= _REG_BIT(0x20, 31),

	/* APB2 peripherals */
	RST_TIM1	= _REG_BIT(0x24, 0),
	RST_TIM8	= _REG_BIT(0x24, 1),
	RST_USART1	= _REG_BIT(0x24, 4),
	RST_USART6	= _REG_BIT(0x24, 5),
	RST_ADC		= _REG_BIT(0x24, 8),
	RST_SDMMC1	= _REG_BIT(0x24, 11),
	RST_SPI1	= _REG_BIT(0x24, 12),
	RST_SPI4	= _REG_BIT(0x24, 13),
	RST_SYSCFG	= _REG_BIT(0x24, 14),
	RST_TIM9	= _REG_BIT(0x24, 16),
	RST_TIM10	= _REG_BIT(0x24, 17),
	RST_TIM11	= _REG_BIT(0x24, 18),
	RST_SPI5	= _REG_BIT(0x24, 20),
	RST_SPI6	= _REG_BIT(0x24, 21),
	RST_SAI1RST	= _REG_BIT(0x24, 22),
	RST_SAI2RST	= _REG_BIT(0x24, 23),
	RST_LTDC	= _REG_BIT(0x24, 26),
};

#undef _REG_BIT

#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS
void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_wait_for_sysclk_status(enum rcc_osc osc);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_set_sysclk_source(uint32_t clk);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_rtcpre(uint32_t rtcpre);
void rcc_set_main_pll_hsi(uint32_t pllm, uint32_t plln, uint32_t pllp,
			  uint32_t pllq);
void rcc_set_main_pll_hse(uint32_t pllm, uint32_t plln, uint32_t pllp,
			  uint32_t pllq);
uint32_t rcc_system_clock_source(void);
void rcc_clock_setup_hse_3v3(const struct rcc_clock_scale *clock);
END_DECLS

#endif
