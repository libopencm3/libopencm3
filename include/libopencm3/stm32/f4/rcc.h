/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F4xx Reset and Clock
 * Control</b>
 *
 * @ingroup STM32F4xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Uwe Hermann <uwe@hermann-uwe.de>
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Fergus Noble <fergusnoble@gmail.com>
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Stephen Caudle <scaudle@doceme.com>
 *
 * @date 18 August 2012
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
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

#include <libopencm3/stm32/pwr.h>

/** @defgroup rcc_registers RCC Registers
 * @brief Reset / Clock Control Registers
@{*/
/** Clock control register */
#define RCC_CR					MMIO32(RCC_BASE + 0x00)
/** PLL Configuration register */
#define RCC_PLLCFGR				MMIO32(RCC_BASE + 0x04)
/** Clock Configuration register */
#define RCC_CFGR				MMIO32(RCC_BASE + 0x08)
/** Clock interrupt register */
#define RCC_CIR					MMIO32(RCC_BASE + 0x0c)
/** AHB1 peripheral reset register */
#define RCC_AHB1RSTR				MMIO32(RCC_BASE + 0x10)
/** AHB2 peripheral reset register */
#define RCC_AHB2RSTR				MMIO32(RCC_BASE + 0x14)
/** AHB3 peripheral reset register */
#define RCC_AHB3RSTR				MMIO32(RCC_BASE + 0x18)
/* RCC_BASE + 0x1c Reserved */
/** APB1 peripheral reset register */
#define RCC_APB1RSTR				MMIO32(RCC_BASE + 0x20)
/** APB2 peripheral reset register */
#define RCC_APB2RSTR				MMIO32(RCC_BASE + 0x24)
/* RCC_BASE + 0x28 Reserved */
/* RCC_BASE + 0x2c Reserved */
/** AHB1 peripheral enable register */
#define RCC_AHB1ENR				MMIO32(RCC_BASE + 0x30)
/** AHB2 peripheral enable register */
#define RCC_AHB2ENR				MMIO32(RCC_BASE + 0x34)
/** AHB3 peripheral enable register */
#define RCC_AHB3ENR				MMIO32(RCC_BASE + 0x38)
/* RCC_BASE + 0x3c Reserved */
/** APB1 peripheral enable register */
#define RCC_APB1ENR				MMIO32(RCC_BASE + 0x40)
/** APB2 peripheral enable register */
#define RCC_APB2ENR				MMIO32(RCC_BASE + 0x44)
/* RCC_BASE + 0x48 Reserved */
/* RCC_BASE + 0x4c Reserved */
/** AHB1 peripheral enable in low power register */
#define RCC_AHB1LPENR				MMIO32(RCC_BASE + 0x50)
/** AHB2 peripheral enable in low power register */
#define RCC_AHB2LPENR				MMIO32(RCC_BASE + 0x54)
/** AHB3 peripheral enable in low power register */
#define RCC_AHB3LPENR				MMIO32(RCC_BASE + 0x58)
/* RCC_BASE + 0x5c Reserved */
/** APB1 peripheral enable in low power register */
#define RCC_APB1LPENR				MMIO32(RCC_BASE + 0x60)
/** APB2 peripheral enable in low power register */
#define RCC_APB2LPENR				MMIO32(RCC_BASE + 0x64)
/* RCC_BASE + 0x68 Reserved */
/* RCC_BASE + 0x6c Reserved */
/** Backup Domain control register */
#define RCC_BDCR				MMIO32(RCC_BASE + 0x70)
/** Clock control and status register */
#define RCC_CSR					MMIO32(RCC_BASE + 0x74)
/* RCC_BASE + 0x78 Reserved */
/* RCC_BASE + 0x7c Reserved */
/** Spread spectrum clock generation register */
#define RCC_SSCGR				MMIO32(RCC_BASE + 0x80)
/** PLLI2S configuration register */
#define RCC_PLLI2SCFGR				MMIO32(RCC_BASE + 0x84)
/** PLLSAI configuration register */
#define RCC_PLLSAICFGR				MMIO32(RCC_BASE + 0x88)
/** Dedicated clocks configuration register */
#define RCC_DCKCFGR				MMIO32(RCC_BASE + 0x8C)
/** RCC clocks gated enable register */
#define RCC_CKGATENR				MMIO32(RCC_BASE + 0x90)
/** RCC Dedicated Clocks Configuration Register 2 */
#define RCC_DCKCFGR2				MMIO32(RCC_BASE + 0x94)
/**@}*/

/** @defgroup rcc_cr_values RCC_CR values
 * @ingroup rcc_registers
 * @brief Clock Control register values
@{*/
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
/* HSICAL: [15:8] */
/* HSITRIM: [7:3] */
#define RCC_CR_HSITRIM_SHIFT			3
#define RCC_CR_HSITRIM_MASK			0x1f
#define RCC_CR_HSIRDY				(1 << 1)
#define RCC_CR_HSION				(1 << 0)
/**@}*/

/** @defgroup rcc_pllcfgr_values RCC_PLLCFGR values
 * @ingroup rcc_registers
 * @brief PLL Configuration register values
@{*/
/* PLLR: [30:28] */
#define RCC_PLLCFGR_PLLR_SHIFT			28
#define RCC_PLLCFGR_PLLR_MASK			0x7
/* PLLQ: [27:24] */
#define RCC_PLLCFGR_PLLQ_SHIFT			24
#define RCC_PLLCFGR_PLLQ_MASK			0xf
#define RCC_PLLCFGR_PLLSRC			(1 << 22)
/* PLLP: [17:16] */
#define RCC_PLLCFGR_PLLP_SHIFT			16
#define RCC_PLLCFGR_PLLP_MASK			0x3
/* PLLN: [14:6] */
#define RCC_PLLCFGR_PLLN_SHIFT			6
#define RCC_PLLCFGR_PLLN_MASK			0x1ff
/* PLLM: [5:0] */
#define RCC_PLLCFGR_PLLM_SHIFT			0
#define RCC_PLLCFGR_PLLM_MASK			0x3f
/**@}*/

/** @defgroup rcc_cfgr_values RCC_CFGR values
 * @ingroup rcc_registers
 * @brief Clock Configuration register values
@{*/
/* MCO2: Microcontroller clock output 2 */
#define RCC_CFGR_MCO2_SHIFT			30
#define RCC_CFGR_MCO2_MASK			0x3
#define RCC_CFGR_MCO2_SYSCLK			0x0
#define RCC_CFGR_MCO2_PLLI2S			0x1
#define RCC_CFGR_MCO2_HSE			0x2
#define RCC_CFGR_MCO2_PLL			0x3

/* MCO1/2PRE: MCO Prescalers */
#define RCC_CFGR_MCO2PRE_SHIFT			27
#define RCC_CFGR_MCO2PRE_MASK			0x7
#define RCC_CFGR_MCO1PRE_SHIFT			24
#define RCC_CFGR_MCO1PRE_MASK			0x7
#define RCC_CFGR_MCOPRE_DIV_NONE		0x0
#define RCC_CFGR_MCOPRE_DIV_2			0x4
#define RCC_CFGR_MCOPRE_DIV_3			0x5
#define RCC_CFGR_MCOPRE_DIV_4			0x6
#define RCC_CFGR_MCOPRE_DIV_5			0x7

/* PLLSRC: PLL entry clock source */
#define RCC_CFGR_PLLSRC_HSI_CLK			0x0
#define RCC_CFGR_PLLSRC_HSE_CLK			0x1

/* I2SSRC: I2S clock selection */
#define RCC_CFGR_I2SSRC				(1 << 23)

/* MCO1: Microcontroller clock output 1 */
#define RCC_CFGR_MCO1_SHIFT			21
#define RCC_CFGR_MCO1_MASK			0x3
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
#define RCC_CFGR_SW_HSI				0x0
#define RCC_CFGR_SW_HSE				0x1
#define RCC_CFGR_SW_PLL				0x2
/**@}*/

/** @defgroup rcc_cir_values RCC_CIR values
 * @ingroup rcc_registers
 * @brief Clock Interrupt register values
@{*/
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
/**@}*/

/** @defgroup rcc_ahbrstr_rst RCC_AHBxRSTR reset values (full set)
@{*/
/** @defgroup rcc_ahb1rstr_rst RCC_AHB1RSTR reset values
@{*/
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
/**@}*/

/** @addtogroup deprecated_201802_rcc Deprecated 2018
 * @deprecated replace zzz_IOPxRST with zzz_GPIOxRST
 * @{
 */
#define RCC_AHB1RSTR_IOPKRST	RCC_AHB1RSTR_GPIOKRST
#define RCC_AHB1RSTR_IOPJRST	RCC_AHB1RSTR_GPIOJRST
#define RCC_AHB1RSTR_IOPIRST	RCC_AHB1RSTR_GPIOIRST
#define RCC_AHB1RSTR_IOPHRST	RCC_AHB1RSTR_GPIOHRST
#define RCC_AHB1RSTR_IOPGRST	RCC_AHB1RSTR_GPIOGRST
#define RCC_AHB1RSTR_IOPFRST	RCC_AHB1RSTR_GPIOFRST
#define RCC_AHB1RSTR_IOPERST	RCC_AHB1RSTR_GPIOERST
#define RCC_AHB1RSTR_IOPDRST	RCC_AHB1RSTR_GPIODRST
#define RCC_AHB1RSTR_IOPCRST	RCC_AHB1RSTR_GPIOCRST
#define RCC_AHB1RSTR_IOPBRST	RCC_AHB1RSTR_GPIOBRST
#define RCC_AHB1RSTR_IOPARST	RCC_AHB1RSTR_GPIOARST
/**@}*/

/** @defgroup rcc_ahb2rstr_rst RCC_AHB2RSTR reset values
@{*/
#define RCC_AHB2RSTR_OTGFSRST			(1 << 7)
#define RCC_AHB2RSTR_RNGRST			(1 << 6)
#define RCC_AHB2RSTR_HASHRST			(1 << 5)
#define RCC_AHB2RSTR_CRYPRST			(1 << 4)
#define RCC_AHB2RSTR_DCMIRST			(1 << 0)
/**@}*/

/** @defgroup rcc_ahb3rstr_rst RCC_AHB3RSTR reset values
@{*/
#define RCC_AHB3RSTR_QSPIRST			(1 << 1)
#define RCC_AHB3RSTR_FSMCRST			(1 << 0)
/**@}*/
/**@}*/

/** @defgroup rcc_apb1rstr_rst RCC_APB1RSTR reset values
@{*/
#define RCC_APB1RSTR_UART8RST			(1 << 31)
#define RCC_APB1RSTR_UART7RST			(1 << 30)
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
/**@}*/

/** @defgroup rcc_apb2rstr_rst RCC_APB2RSTR reset values
@{*/
#define RCC_APB2RSTR_DSIRST			(1 << 27)
#define RCC_APB2RSTR_LTDCRST			(1 << 26)
#define RCC_APB2RSTR_SAI1RST			(1 << 22)
#define RCC_APB2RSTR_SPI6RST			(1 << 21)
#define RCC_APB2RSTR_SPI5RST			(1 << 20)
#define RCC_APB2RSTR_TIM11RST			(1 << 18)
#define RCC_APB2RSTR_TIM10RST			(1 << 17)
#define RCC_APB2RSTR_TIM9RST			(1 << 16)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 14)
#define RCC_APB2RSTR_SPI4RST			(1 << 13)
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_SDIORST			(1 << 11)
#define RCC_APB2RSTR_ADCRST			(1 << 8)
#define RCC_APB2RSTR_USART6RST			(1 << 5)
#define RCC_APB2RSTR_USART1RST			(1 << 4)
#define RCC_APB2RSTR_TIM8RST			(1 << 1)
#define RCC_APB2RSTR_TIM1RST			(1 << 0)
/**@}*/

/** @defgroup rcc_ahbenr_en RCC_AHBxENR enable values (full set)
@{*/
/** @defgroup rcc_ahb1enr_en RCC_AHB1ENR enable values
@{*/
#define RCC_AHB1ENR_OTGHSULPIEN			(1 << 30)
#define RCC_AHB1ENR_OTGHSEN			(1 << 29)
#define RCC_AHB1ENR_ETHMACPTPEN			(1 << 28)
#define RCC_AHB1ENR_ETHMACRXEN			(1 << 27)
#define RCC_AHB1ENR_ETHMACTXEN			(1 << 26)
#define RCC_AHB1ENR_ETHMACEN			(1 << 25)
#define RCC_AHB1ENR_DMA2DEN			(1 << 23)
#define RCC_AHB1ENR_DMA2EN			(1 << 22)
#define RCC_AHB1ENR_DMA1EN			(1 << 21)
#define RCC_AHB1ENR_CCMDATARAMEN		(1 << 20)
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
/**@}*/

/** @addtogroup deprecated_201802_rcc Deprecated 2018
 * @deprecated replace zzz_IOPxEN with zzz_GPIOxEN
 * @{
 */
#define RCC_AHB1ENR_IOPKEN	RCC_AHB1ENR_GPIOKEN
#define RCC_AHB1ENR_IOPJEN	RCC_AHB1ENR_GPIOJEN
#define RCC_AHB1ENR_IOPIEN	RCC_AHB1ENR_GPIOIEN
#define RCC_AHB1ENR_IOPHEN	RCC_AHB1ENR_GPIOHEN
#define RCC_AHB1ENR_IOPGEN	RCC_AHB1ENR_GPIOGEN
#define RCC_AHB1ENR_IOPFEN	RCC_AHB1ENR_GPIOFEN
#define RCC_AHB1ENR_IOPEEN	RCC_AHB1ENR_GPIOEEN
#define RCC_AHB1ENR_IOPDEN	RCC_AHB1ENR_GPIODEN
#define RCC_AHB1ENR_IOPCEN	RCC_AHB1ENR_GPIOCEN
#define RCC_AHB1ENR_IOPBEN	RCC_AHB1ENR_GPIOBEN
#define RCC_AHB1ENR_IOPAEN	RCC_AHB1ENR_GPIOAEN
/**@}*/

/** @defgroup rcc_ahb2enr_en RCC_AHB2ENR enable values
@{*/
#define RCC_AHB2ENR_OTGFSEN			(1 << 7)
#define RCC_AHB2ENR_RNGEN			(1 << 6)
#define RCC_AHB2ENR_HASHEN			(1 << 5)
#define RCC_AHB2ENR_CRYPEN			(1 << 4)
#define RCC_AHB2ENR_DCMIEN			(1 << 0)
/**@}*/

/** @defgroup rcc_ahb3enr_en RCC_AHB3ENR enable values
@{*/
#define RCC_AHB3ENR_QSPIEN			(1 << 1)
#define RCC_AHB3ENR_FSMCEN			(1 << 0)
/* Alternate now that F429 has DRAM controller as well */
#define RCC_AHB3ENR_FMCEN			(1 << 0)
/**@}*/
/**@}*/

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@{*/
#define RCC_APB1ENR_UART8EN			(1 << 31)
#define RCC_APB1ENR_UART7EN			(1 << 30)
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
/**@}*/

/** @defgroup rcc_apb2enr_en RCC_APB2ENR enable values
@{*/
#define RCC_APB2ENR_DSIEN			(1 << 27)
#define RCC_APB2ENR_LTDCEN			(1 << 26)
#define RCC_APB2ENR_SAI1EN			(1 << 22)
#define RCC_APB2ENR_SPI6EN			(1 << 21)
#define RCC_APB2ENR_SPI5EN			(1 << 20)
#define RCC_APB2ENR_TIM11EN			(1 << 18)
#define RCC_APB2ENR_TIM10EN			(1 << 17)
#define RCC_APB2ENR_TIM9EN			(1 << 16)
#define RCC_APB2ENR_SYSCFGEN			(1 << 14)
#define RCC_APB2ENR_SPI4EN			(1 << 13)
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_SDIOEN			(1 << 11)
#define RCC_APB2ENR_ADC3EN			(1 << 10)
#define RCC_APB2ENR_ADC2EN			(1 << 9)
#define RCC_APB2ENR_ADC1EN			(1 << 8)
#define RCC_APB2ENR_USART6EN			(1 << 5)
#define RCC_APB2ENR_USART1EN			(1 << 4)
#define RCC_APB2ENR_TIM8EN			(1 << 1)
#define RCC_APB2ENR_TIM1EN			(1 << 0)
/**@}*/

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
#define RCC_AHB1LPENR_SRAM3LPEN			(1 << 19)
#define RCC_AHB1LPENR_BKPSRAMLPEN		(1 << 18)
#define RCC_AHB1LPENR_SRAM2LPEN			(1 << 17)
#define RCC_AHB1LPENR_SRAM1LPEN			(1 << 16)
#define RCC_AHB1LPENR_FLITFLPEN			(1 << 15)
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

/** @addtogroup deprecated_201802_rcc Deprecated 2018
 * @deprecated replace zzz_IOPxLPEN with zzz_GPIOxLPEN
 * @{
 */
#define RCC_AHB1LPENR_IOPKLPEN	RCC_AHB1LPENR_GPIOKLPEN
#define RCC_AHB1LPENR_IOPJLPEN	RCC_AHB1LPENR_GPIOJLPEN
#define RCC_AHB1LPENR_IOPILPEN	RCC_AHB1LPENR_GPIOILPEN
#define RCC_AHB1LPENR_IOPHLPEN	RCC_AHB1LPENR_GPIOHLPEN
#define RCC_AHB1LPENR_IOPGLPEN	RCC_AHB1LPENR_GPIOGLPEN
#define RCC_AHB1LPENR_IOPFLPEN	RCC_AHB1LPENR_GPIOFLPEN
#define RCC_AHB1LPENR_IOPELPEN	RCC_AHB1LPENR_GPIOELPEN
#define RCC_AHB1LPENR_IOPDLPEN	RCC_AHB1LPENR_GPIODLPEN
#define RCC_AHB1LPENR_IOPCLPEN	RCC_AHB1LPENR_GPIOCLPEN
#define RCC_AHB1LPENR_IOPBLPEN	RCC_AHB1LPENR_GPIOBLPEN
#define RCC_AHB1LPENR_IOPALPEN	RCC_AHB1LPENR_GPIOALPEN
/**@}*/

/* --- RCC_AHB2LPENR values ------------------------------------------------- */

#define RCC_AHB2LPENR_OTGFSLPEN			(1 << 7)
#define RCC_AHB2LPENR_RNGLPEN			(1 << 6)
#define RCC_AHB2LPENR_HASHLPEN			(1 << 5)
#define RCC_AHB2LPENR_CRYPLPEN			(1 << 4)
#define RCC_AHB2LPENR_DCMILPEN			(1 << 0)

/* --- RCC_AHB3LPENR values ------------------------------------------------- */

#define RCC_AHB3LPENR_QSPIEN			(1 << 1)
#define RCC_AHB3LPENR_FSMCLPEN			(1 << 0)
#define RCC_AHB3LPENR_FMCLPEN			(1 << 0)

/* --- RCC_APB1LPENR values ------------------------------------------------- */

/** @defgroup rcc_apblpenr_en RCC_APBxLPENR enable values (full set)
@{*/
#define RCC_APB1LPENR_UART8EN			(1 << 31)
#define RCC_APB1LPENR_UART7EN			(1 << 30)
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

#define RCC_APB2LPENR_DSILPEN			(1 << 27)
#define RCC_APB2LPENR_LTDCLPEN			(1 << 26)
#define RCC_APB2LPENR_SAI1LPEN			(1 << 22)
#define RCC_APB2LPENR_SPI6LPEN			(1 << 21)
#define RCC_APB2LPENR_SPI5LPEN			(1 << 20)
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
/**@}*/

/** @defgroup rcc_bdcr_values RCC_BDCR values
 * @ingroup rcc_registers
 * @brief Backup Domain control register values
@{*/
#define RCC_BDCR_BDRST				(1 << 16)
#define RCC_BDCR_RTCEN				(1 << 15)
/* RCC_BDCR[9:8]: RTCSEL */
#define RCC_BDCR_RTCSEL_SHIFT			8
#define RCC_BDCR_RTCSEL_MASK			0x3
#define RCC_BDCR_RTCSEL_NONE			0
#define RCC_BDCR_RTCSEL_LSE			1
#define RCC_BDCR_RTCSEL_LSI			2
#define RCC_BDCR_RTCSEL_HSE			3
#define RCC_BDCR_LSEMOD				(1 << 3)
#define RCC_BDCR_LSEBYP				(1 << 2)
#define RCC_BDCR_LSERDY				(1 << 1)
#define RCC_BDCR_LSEON				(1 << 0)
/**@}*/

/** @defgroup rcc_csr_values RCC_CSR values
 * @ingroup rcc_registers
 * @brief Clock control and status register values
@{*/
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
/**@}*/

/** @defgroup rcc_sscgr_values RCC_SSCGR values
 * @ingroup rcc_registers
 * @brief Spread spectrum clock generation register values
@{*/
/* PLL spread spectrum clock generation documented in Datasheet. */

#define RCC_SSCGR_SSCGEN			(1 << 31)
#define RCC_SSCGR_SPREADSEL			(1 << 30)
/* RCC_SSCGR[27:13]: INCSTEP */
#define RCC_SSCGR_INCSTEP_SHIFT			13
#define RCC_SSCGR_INCSTEP_MASK			0x7fff
/* RCC_SSCGR[15:0]: MODPER */
#define RCC_SSCGR_MODPER_SHIFT			0
#define RCC_SSCGR_MODPER_MASK			0x1fff
/**@}*/

/** @defgroup rcc_pllded_values RCC_PLLxxx/DCKy values
 * @ingroup rcc_registers
 * @brief PLL and other dedicated clock register values
@{*/
/* --- RCC_PLLI2SCFGR values ----------------------------------------------- */

/* RCC_PLLI2SCFGR[30:28]: PLLI2SR */
#define RCC_PLLI2SCFGR_PLLI2SR_SHIFT		28
#define RCC_PLLI2SCFGR_PLLI2SR_MASK		0x7
/* RCC_PLLI2SCFGR[27:24] PLLI2SQ */
#define RCC_PLLI2SCFGR_PLLI2SQ_SHIFT		24
#define RCC_PLLI2SCFGR_PLLI2SQ_MASK		0xf
/* RCC_PLLI2SCFGR[14:6]: PLLI2SN */
#define RCC_PLLI2SCFGR_PLLI2SN_SHIFT		6
#define RCC_PLLI2SCFGR_PLLI2SN_MASK		0x1ff

/* --- RCC_PLLSAICFGR values ----------------------------------------------- */

/* RCC_PLLSAICFGR[30:28]: PLLSAIR */
#define RCC_PLLSAICFGR_PLLSAIR_SHIFT		28
#define RCC_PLLSAICFGR_PLLSAIR_MASK		0x7

/* RCC_PLLSAICFGR[27:24]: PLLSAIQ */
#define RCC_PLLSAICFGR_PLLSAIQ_SHIFT		24
#define RCC_PLLSAICFGR_PLLSAIQ_MASK		0xF

/* RCC_PLLSAICFGR[18:16]: PLLSAIP */
#define RCC_PLLSAICFGR_PLLSAIP_SHIFT		16
#define RCC_PLLSAICFGR_PLLSAIP_MASK		0x3
/** @defgroup rcc_pllsaicfgr_pllsaip PLLSAICFGR PLLSAIP values
@ingroup rcc_defines
@{*/
#define RCC_PLLSAICFGR_PLLSAIP_DIV2		0x0
#define RCC_PLLSAICFGR_PLLSAIP_DIV4		0x1
#define RCC_PLLSAICFGR_PLLSAIP_DIV6		0x2
#define RCC_PLLSAICFGR_PLLSAIP_DIV8		0x3
/**@}*/

/* RCC_PLLSAICFGR[14:6]: PLLSAIN */
#define RCC_PLLSAICFGR_PLLSAIN_SHIFT		6
#define RCC_PLLSAICFGR_PLLSAIN_MASK		0x1FF


/* --- RCC_DCKCFGR values -------------------------------------------------- */
#define RCC_DCKCFGR_DSISEL			(1 << 29)
#define RCC_DCKCFGR_SDMMCSEL			(1 << 28)
#define RCC_DCKCFGR_48MSEL			(1 << 27)
#define RCC_DCKCFGR_TIMPRE			(1 << 24)

#define RCC_DCKCFGR_SAI1BSRC_SHIFT		22
#define RCC_DCKCFGR_SAI1BSRC_MASK		0x3

#define RCC_DCKCFGR_SAI1ASRC_SHIFT		20
#define RCC_DCKCFGR_SAI1ASRC_MASK		0x3

/* Values for the BSRC and ASRC fields */
#define RCC_DCKCFGR_SAI1SRC_SAIQ		0x0
#define RCC_DCKCFGR_SAI1SRC_I2SQ		0x1
#define RCC_DCKCFGR_SAI1SRC_ALT			0x2
#define RCC_DCKCFGR_SAI1SRC_ERROR		0x3

#define RCC_DCKCFGR_PLLSAIDIVR_SHIFT		16
#define RCC_DCKCFGR_PLLSAIDIVR_MASK		0x3
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_2		0x0
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_4		0x1
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_8		0x2
#define RCC_DCKCFGR_PLLSAIDIVR_DIVR_16		0x3

#define RCC_DCKCFGR_PLLSAIDIVQ_SHIFT		8
#define RCC_DCKCFGR_PLLSAIDIVQ_MASK		0x1f

#define RCC_DCKCFGR_PLLI2SDIVQ_SHIFT		0
#define RCC_DCKCFGR_PLLI2SDIVQ_MASK		0x1f
/**@}*/

/** @defgroup rcc_ckgatenr_values RCC_CKGATENR bits
 * @ingroup rcc_registers
 * @brief Allows to enable or disable the clock gating for the specified IPs.
@{*/
#define RCC_CKGATENR_EVTCL_CKEN			(1<<7)
#define RCC_CKGATENR_RCC_CKEN			(1<<6)
#define RCC_CKGATENR_FLITF_CKEN			(1<<5)
#define RCC_CKGATENR_SRAM_CKEN			(1<<4)
#define RCC_CKGATENR_SPARE_CKEN			(1<<3)
#define RCC_CKGATENR_CM4DBG_CKEN		(1<<2)
#define RCC_CKGATENR_AHB2APB2_CKEN		(1<<1)
#define RCC_CKGATENR_AHB2APB1_CKEN		(1<<0)
/**@}*/

/* --- Variable definitions ------------------------------------------------ */
extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

/* --- Function prototypes ------------------------------------------------- */

enum rcc_clock_3v3 {
	RCC_CLOCK_3V3_84MHZ,
	RCC_CLOCK_3V3_168MHZ,
	RCC_CLOCK_3V3_180MHZ,
	RCC_CLOCK_3V3_END
};

struct rcc_clock_scale {
	uint8_t pllm;
	uint16_t plln;
	uint8_t pllp;
	uint8_t pllq;
	uint8_t pllr;
	uint8_t pll_source;
	uint32_t flash_config;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	enum pwr_vos_scale voltage_scale;
	uint32_t ahb_frequency;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_12mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_16mhz_3v3[RCC_CLOCK_3V3_END];
extern const struct rcc_clock_scale rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_END];

enum rcc_osc {
	RCC_PLL,
	RCC_PLLSAI,
	RCC_PLLI2S,
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
	RCC_CCMDATARAM	= _REG_BIT(0x30, 20),
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
	RCC_FSMC	= _REG_BIT(0x38, 0),
	RCC_FMC		= _REG_BIT(0x38, 0),
	RCC_QUADSPI	= _REG_BIT(0x38, 1),

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
	RCC_WWDG	= _REG_BIT(0x40, 11),
	RCC_SPI2	= _REG_BIT(0x40, 14),
	RCC_SPI3	= _REG_BIT(0x40, 15),
	RCC_USART2	= _REG_BIT(0x40, 17),
	RCC_USART3	= _REG_BIT(0x40, 18),
	RCC_UART4	= _REG_BIT(0x40, 19),
	RCC_UART5	= _REG_BIT(0x40, 20),
	RCC_I2C1	= _REG_BIT(0x40, 21),
	RCC_I2C2	= _REG_BIT(0x40, 22),
	RCC_I2C3	= _REG_BIT(0x40, 23),
	RCC_CAN1	= _REG_BIT(0x40, 25),
	RCC_CAN2	= _REG_BIT(0x40, 26),
	RCC_PWR		= _REG_BIT(0x40, 28),
	RCC_DAC		= _REG_BIT(0x40, 29),
	RCC_UART7	= _REG_BIT(0x40, 30),/* F2xx, F3xx */
	RCC_UART8	= _REG_BIT(0x40, 31),/* F2xx, F3xx */

	/* APB2 peripherals */
	RCC_TIM1	= _REG_BIT(0x44, 0),
	RCC_TIM8	= _REG_BIT(0x44, 1),
	RCC_USART1	= _REG_BIT(0x44, 4),
	RCC_USART6	= _REG_BIT(0x44, 5),
	RCC_ADC1	= _REG_BIT(0x44, 8),
	RCC_ADC2	= _REG_BIT(0x44, 9),
	RCC_ADC3	= _REG_BIT(0x44, 10),
	RCC_SDIO	= _REG_BIT(0x44, 11),
	RCC_SPI1	= _REG_BIT(0x44, 12),
	RCC_SPI4	= _REG_BIT(0x44, 13),/* F2xx, F3xx */
	RCC_SYSCFG	= _REG_BIT(0x44, 14),
	RCC_TIM9	= _REG_BIT(0x44, 16),
	RCC_TIM10	= _REG_BIT(0x44, 17),
	RCC_TIM11	= _REG_BIT(0x44, 18),
	RCC_SPI5	= _REG_BIT(0x44, 20),/* F2xx, F3xx */
	RCC_SPI6	= _REG_BIT(0x44, 21),/* F2xx, F3xx */
	RCC_SAI1EN	= _REG_BIT(0x44, 22),/* F42x, F43x */
	RCC_LTDC	= _REG_BIT(0x44, 26),/* F42x, F43x */
	RCC_DSI		= _REG_BIT(0x44, 27),/* F4x9, F4x9 */


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
	SCC_FLTIF	= _REG_BIT(0x50, 15),
	SCC_SRAM1	= _REG_BIT(0x50, 16),
	SCC_SRAM2	= _REG_BIT(0x50, 17),
	SCC_BKPSRAM	= _REG_BIT(0x50, 18),
	SCC_SRAM3	= _REG_BIT(0x50, 19),/* F2xx, F3xx */
	SCC_DMA1	= _REG_BIT(0x50, 21),
	SCC_DMA2	= _REG_BIT(0x50, 22),
	SCC_DMA2D	= _REG_BIT(0x50, 23), /* F4x9 */
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
	SCC_QSPIC	= _REG_BIT(0x58, 1),
	SCC_FMC		= _REG_BIT(0x58, 0),
	SCC_FSMC	= _REG_BIT(0x58, 0),

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
	SCC_WWDG	= _REG_BIT(0x60, 11),
	SCC_SPI2	= _REG_BIT(0x60, 14),
	SCC_SPI3	= _REG_BIT(0x60, 15),
	SCC_USART2	= _REG_BIT(0x60, 17),
	SCC_USART3	= _REG_BIT(0x60, 18),
	SCC_UART4	= _REG_BIT(0x60, 19),
	SCC_UART5	= _REG_BIT(0x60, 20),
	SCC_I2C1	= _REG_BIT(0x60, 21),
	SCC_I2C2	= _REG_BIT(0x60, 22),
	SCC_I2C3	= _REG_BIT(0x60, 23),
	SCC_CAN1	= _REG_BIT(0x60, 25),
	SCC_CAN2	= _REG_BIT(0x60, 26),
	SCC_PWR		= _REG_BIT(0x60, 28),
	SCC_DAC		= _REG_BIT(0x60, 29),
	SCC_UART7	= _REG_BIT(0x60, 30),/* F2xx, F3xx */
	SCC_UART8	= _REG_BIT(0x60, 31),/* F2xx, F3xx */

	/* APB2 peripherals */
	SCC_TIM1	= _REG_BIT(0x64, 0),
	SCC_TIM8	= _REG_BIT(0x64, 1),
	SCC_USART1	= _REG_BIT(0x64, 4),
	SCC_USART6	= _REG_BIT(0x64, 5),
	SCC_ADC1	= _REG_BIT(0x64, 8),
	SCC_ADC2	= _REG_BIT(0x64, 9),
	SCC_ADC3	= _REG_BIT(0x64, 10),
	SCC_SDIO	= _REG_BIT(0x64, 11),
	SCC_SPI1	= _REG_BIT(0x64, 12),
	SCC_SPI4	= _REG_BIT(0x64, 13),/* F2xx, F3xx */
	SCC_SYSCFG	= _REG_BIT(0x64, 14),
	SCC_TIM9	= _REG_BIT(0x64, 16),
	SCC_TIM10	= _REG_BIT(0x64, 17),
	SCC_TIM11	= _REG_BIT(0x64, 18),
	SCC_SPI5	= _REG_BIT(0x64, 20),/* F2xx, F3xx */
	SCC_SPI6	= _REG_BIT(0x64, 21),/* F2xx, F3xx */
	SCC_SAI1	= _REG_BIT(0x64, 22),/* F4x9 */
	SCC_LTDC	= _REG_BIT(0x64, 26),/* F4x9 */
	SCC_DSI		= _REG_BIT(0x64, 27),/* F4x9 */
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
	RST_QSPI	= _REG_BIT(0x18, 1), /* F4x9 */
	RST_FSMC	= _REG_BIT(0x18, 0),
	RST_FMC		= _REG_BIT(0x18, 0), /* F4x9 */

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
	RST_WWDG	= _REG_BIT(0x20, 11),
	RST_SPI2	= _REG_BIT(0x20, 14),
	RST_SPI3	= _REG_BIT(0x20, 15),
	RST_USART2	= _REG_BIT(0x20, 17),
	RST_USART3	= _REG_BIT(0x20, 18),
	RST_UART4	= _REG_BIT(0x20, 19),
	RST_UART5	= _REG_BIT(0x20, 20),
	RST_I2C1	= _REG_BIT(0x20, 21),
	RST_I2C2	= _REG_BIT(0x20, 22),
	RST_I2C3	= _REG_BIT(0x20, 23),
	RST_CAN1	= _REG_BIT(0x20, 25),
	RST_CAN2	= _REG_BIT(0x20, 26),
	RST_PWR		= _REG_BIT(0x20, 28),
	RST_DAC		= _REG_BIT(0x20, 29),
	RST_UART7	= _REG_BIT(0x20, 30),/* F2xx, F3xx */
	RST_UART8	= _REG_BIT(0x20, 31),/* F2xx, F3xx */

	/* APB2 peripherals */
	RST_TIM1	= _REG_BIT(0x24, 0),
	RST_TIM8	= _REG_BIT(0x24, 1),
	RST_USART1	= _REG_BIT(0x24, 4),
	RST_USART6	= _REG_BIT(0x24, 5),
	RST_ADC		= _REG_BIT(0x24, 8),
	RST_SDIO	= _REG_BIT(0x24, 11),
	RST_SPI1	= _REG_BIT(0x24, 12),
	RST_SPI4	= _REG_BIT(0x24, 13),/* F2xx, F3xx */
	RST_SYSCFG	= _REG_BIT(0x24, 14),
	RST_TIM9	= _REG_BIT(0x24, 16),
	RST_TIM10	= _REG_BIT(0x24, 17),
	RST_TIM11	= _REG_BIT(0x24, 18),
	RST_SPI5	= _REG_BIT(0x24, 20),/* F2xx, F3xx */
	RST_SPI6	= _REG_BIT(0x24, 21),/* F2xx, F3xx */
	RST_SAI1RST	= _REG_BIT(0x24, 22),/* F42x, F43x */
	RST_LTDC	= _REG_BIT(0x24, 26),/* F42x, F43x */
	RST_DSI		= _REG_BIT(0x24, 27),/* F42x, F43x */
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
void rcc_plli2s_config(uint16_t n, uint8_t r);
void rcc_pllsai_config(uint16_t n, uint16_t p, uint16_t q, uint16_t r);
void rcc_pllsai_postscalers(uint8_t q, uint8_t r);
void rcc_set_sysclk_source(uint32_t clk);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_rtcpre(uint32_t rtcpre);
void rcc_set_main_pll_hsi(uint32_t pllm, uint32_t plln, uint32_t pllp,
			  uint32_t pllq, uint32_t pllr);
void rcc_set_main_pll_hse(uint32_t pllm, uint32_t plln, uint32_t pllp,
			  uint32_t pllq, uint32_t pllr);
uint32_t rcc_system_clock_source(void);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);
void __attribute__((deprecated("Use rcc_clock_setup_pll as direct replacement"))) rcc_clock_setup_hse_3v3(const struct rcc_clock_scale *clock);

END_DECLS

#endif
/**@}*/