/** @defgroup rcc_defines RCC Defines
 *
 * @ingroup STM32L0xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32L0xx Reset and Clock
 * Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Karl Palsson <karlp@tweak.net.au>
 *
 * @date 17 November 2014
 *
 * LGPL License Terms @ref lgpl_license
 *  */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Karl Palsson <karlp@tweak.net.au>
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
 *
 */

/**@{*/

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

#include <stdbool.h>
#include <stdint.h>
#include <libopencm3/stm32/pwr.h>

/* --- RCC registers ------------------------------------------------------- */

#define RCC_CR					MMIO32(RCC_BASE + 0x00)
#define RCC_ICSCR				MMIO32(RCC_BASE + 0x04)
#define RCC_CRRCR				MMIO32(RCC_BASE + 0x08)
#define RCC_CFGR				MMIO32(RCC_BASE + 0x0c)
#define RCC_CIER				MMIO32(RCC_BASE + 0x10)
#define RCC_CIFR				MMIO32(RCC_BASE + 0x14)
#define RCC_CICR				MMIO32(RCC_BASE + 0x18)
#define RCC_IOPRSTR				MMIO32(RCC_BASE + 0x1c)
#define RCC_AHBRSTR				MMIO32(RCC_BASE + 0x20)
#define RCC_APB2RSTR				MMIO32(RCC_BASE + 0x24)
#define RCC_APB1RSTR				MMIO32(RCC_BASE + 0x28)
#define RCC_IOPENR				MMIO32(RCC_BASE + 0x2c)
#define RCC_AHBENR				MMIO32(RCC_BASE + 0x30)
#define RCC_APB2ENR				MMIO32(RCC_BASE + 0x34)
#define RCC_APB1ENR				MMIO32(RCC_BASE + 0x38)
#define RCC_IOPSMEN				MMIO32(RCC_BASE + 0x3c)
#define RCC_AHBSMENR				MMIO32(RCC_BASE + 0x40)
#define RCC_APB2SMENR				MMIO32(RCC_BASE + 0x44)
#define RCC_APB1SMENR				MMIO32(RCC_BASE + 0x48)
#define RCC_CCIPR				MMIO32(RCC_BASE + 0x4c)
#define RCC_CSR					MMIO32(RCC_BASE + 0x50)

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_PLLRDY				(1 << 25)
#define RCC_CR_PLLON				(1 << 24)
#define RCC_CR_RTCPRE_SHIFT			20
#define RCC_CR_RTCPRE_MASK			0x3
#define RCC_CR_RTCPRE_DIV2			0
#define RCC_CR_RTCPRE_DIV4			1
#define RCC_CR_RTCPRE_DIV8			2
#define RCC_CR_RTCPRE_DIV16			3
#define RCC_CR_CSSHSEON                         (1 << 19)
#define RCC_CR_HSEBYP				(1 << 18)
#define RCC_CR_HSERDY				(1 << 17)
#define RCC_CR_HSEON				(1 << 16)
#define RCC_CR_MSIRDY				(1 << 9)
#define RCC_CR_MSION				(1 << 8)
#define RCC_CR_HSI16DIVF			(1 << 4)
#define RCC_CR_HSI16DIVEN			(1 << 3)
#define RCC_CR_HSI16RDY				(1 << 2)
#define RCC_CR_HSI16KERON			(1 << 1)
#define RCC_CR_HSI16ON				(1 << 0)


/* --- RCC_ICSCR values ---------------------------------------------------- */

#define RCC_ICSCR_MSITRIM_SHIFT		24
#define RCC_ICSCR_MSITRIM_MASK		0xff
#define RCC_ICSCR_MSICAL_SHIFT		16
#define RCC_ICSCR_MSICAL_MASK		0xff

#define RCC_ICSCR_MSIRANGE_SHIFT	13
#define RCC_ICSCR_MSIRANGE_MASK		0x7
#define RCC_ICSCR_MSIRANGE_65KHZ	0x0
#define RCC_ICSCR_MSIRANGE_131KHZ	0x1
#define RCC_ICSCR_MSIRANGE_262KHZ	0x2
#define RCC_ICSCR_MSIRANGE_524KHZ	0x3
#define RCC_ICSCR_MSIRANGE_1MHZ		0x4
#define RCC_ICSCR_MSIRANGE_2MHZ		0x5
#define RCC_ICSCR_MSIRANGE_4MHZ		0x6

#define RCC_ICSCR_HSI16TRIM_SHIFT	8
#define RCC_ICSCR_HSI16TRIM_MASK	0x1f
#define RCC_ICSCR_HSI16CAL_SHIFT	0
#define RCC_ICSCR_HSI16CAL_MASK		0xff

/* --- RCC_CRRCR register */

#define RCC_CRRCR_HSI48CAL_SHIFT	8
#define RCC_CRRCR_HSI48CAL_MASK		0xff
#define RCC_CRRCR_HSI48RDY		(1<<1)
#define RCC_CRRCR_HSI48ON		(1<<0)

/* --- RCC_CFGR values ----------------------------------------------------- */

/* MCOPRE */
#define RCC_CFGR_MCOPRE_DIV1	    0
#define RCC_CFGR_MCOPRE_DIV2	    1
#define RCC_CFGR_MCOPRE_DIV4	    2
#define RCC_CFGR_MCOPRE_DIV8	    3
#define RCC_CFGR_MCOPRE_DIV16	    4

/* MCO: Microcontroller clock output */
#define RCC_CFGR_MCO_NOCLK			0x0
#define RCC_CFGR_MCO_SYSCLK			0x1
#define RCC_CFGR_MCO_HSI16			0x2
#define RCC_CFGR_MCO_MSI			0x3
#define RCC_CFGR_MCO_HSE			0x4
#define RCC_CFGR_MCO_PLL			0x5
#define RCC_CFGR_MCO_LSI			0x6
#define RCC_CFGR_MCO_LSE			0x7
#define RCC_CFGR_MCO_HSI48			0x8
#define RCC_CFGR_MCO_SHIFT			24
#define RCC_CFGR_MCO_MASK			0xf

/** @defgroup rcc_cfgr_pdf PLLDIV PLL division factor
 @{*/
#define RCC_CFGR_PLLDIV_DIV2	0x1
#define RCC_CFGR_PLLDIV_DIV3	0x2
#define RCC_CFGR_PLLDIV_DIV4	0x3
/**@}*/
#define RCC_CFGR_PLLDIV_SHIFT	22
#define RCC_CFGR_PLLDIV_MASK	0x3

/** @defgroup rcc_cfgr_pmf PLLMUL PLL multiplication factor
 @{*/
#define RCC_CFGR_PLLMUL_MUL3		0x0
#define RCC_CFGR_PLLMUL_MUL4		0x1
#define RCC_CFGR_PLLMUL_MUL6		0x2
#define RCC_CFGR_PLLMUL_MUL8		0x3
#define RCC_CFGR_PLLMUL_MUL12		0x4
#define RCC_CFGR_PLLMUL_MUL16		0x5
#define RCC_CFGR_PLLMUL_MUL24		0x6
#define RCC_CFGR_PLLMUL_MUL32		0x7
#define RCC_CFGR_PLLMUL_MUL48		0x8
/**@}*/
#define RCC_CFGR_PLLMUL_SHIFT		18
#define RCC_CFGR_PLLMUL_MASK		0xf

/* PLLSRC: PLL entry clock source */
#define RCC_CFGR_PLLSRC_HSI16_CLK	0x0
#define RCC_CFGR_PLLSRC_HSE_CLK		0x1

/* Wakeup from stop clock selection */
#define RCC_CFGR_STOPWUCK_MSI		(0<<15)
#define RCC_CFGR_STOPWUCK_HSI16		(1<<15)

#define RCC_CFGR_PPRE2_SHIFT			11
#define RCC_CFGR_PPRE2_MASK			0x7
#define RCC_CFGR_PPRE1_SHIFT			8
#define RCC_CFGR_PPRE1_MASK			0x7
/** @defgroup rcc_cfgr_apbxpre RCC_CFGR APBx prescale factors
 * These can be used for both APB1 and APB2 prescaling
 * @{
 */
#define RCC_CFGR_PPRE_NODIV			0x0
#define RCC_CFGR_PPRE_DIV2			0x4
#define RCC_CFGR_PPRE_DIV4			0x5
#define RCC_CFGR_PPRE_DIV8			0x6
#define RCC_CFGR_PPRE_DIV16			0x7
/**@}*/

/* HPRE: AHB prescaler */
/** @defgroup rcc_cfgr_ahbpre RCC_CFGR AHB prescale Factors
@{*/
#define RCC_CFGR_HPRE_NODIV		0x0
#define RCC_CFGR_HPRE_DIV2		0x8
#define RCC_CFGR_HPRE_DIV4		0x9
#define RCC_CFGR_HPRE_DIV8		0xa
#define RCC_CFGR_HPRE_DIV16		0xb
#define RCC_CFGR_HPRE_DIV64		0xc
#define RCC_CFGR_HPRE_DIV128		0xd
#define RCC_CFGR_HPRE_DIV256		0xe
#define RCC_CFGR_HPRE_DIV512		0xf
/**@}*/
#define RCC_CFGR_HPRE_MASK		0xf
#define RCC_CFGR_HPRE_SHIFT		4

/* SWS: System clock switch status */
#define RCC_CFGR_SWS_MSI			0x0
#define RCC_CFGR_SWS_HSI16			0x1
#define RCC_CFGR_SWS_HSE			0x2
#define RCC_CFGR_SWS_PLL			0x3
#define RCC_CFGR_SWS_MASK			0x3
#define RCC_CFGR_SWS_SHIFT			2

/* SW: System clock switch */
#define RCC_CFGR_SW_MSI				0x0
#define RCC_CFGR_SW_HSI16			0x1
#define RCC_CFGR_SW_HSE				0x2
#define RCC_CFGR_SW_PLL				0x3
#define RCC_CFGR_SW_MASK			0x3
#define RCC_CFGR_SW_SHIFT			0

/** Older compatible definitions to ease migration
 * @defgroup rcc_cfgr_deprecated RCC_CFGR Deprecated dividers
 * @deprecated Use _CFGR_xPRE_DIVn form instead, across all families
 * @{
 */
#define RCC_CFGR_PPRE2_NODIV		0x0
#define RCC_CFGR_PPRE2_DIV2		0x4
#define RCC_CFGR_PPRE2_DIV4		0x5
#define RCC_CFGR_PPRE2_DIV8		0x6
#define RCC_CFGR_PPRE2_DIV16		0x7

#define RCC_CFGR_PPRE1_NODIV		0x0
#define RCC_CFGR_PPRE1_DIV2		0x4
#define RCC_CFGR_PPRE1_DIV4		0x5
#define RCC_CFGR_PPRE1_DIV8		0x6
#define RCC_CFGR_PPRE1_DIV16		0x7
/**@}*/

/* --- RCC_CIER - Clock interrupt enable register */

#define RCC_CIER_CSSLSE				(1 << 7)
/* OSC ready interrupt enable bits */
#define RCC_CIER_HSI48RDYIE			(1 << 6)
#define RCC_CIER_MSIRDYIE			(1 << 5)
#define RCC_CIER_PLLRDYIE			(1 << 4)
#define RCC_CIER_HSERDYIE			(1 << 3)
#define RCC_CIER_HSI16RDYIE			(1 << 2)
#define RCC_CIER_LSERDYIE			(1 << 1)
#define RCC_CIER_LSIRDYIE			(1 << 0)

/* --- RCC_CIFR - Clock interrupt flag register */

#define RCC_CIFR_CSSHSEF			(1 << 8)
#define RCC_CIFR_CSSLSEF			(1 << 7)
#define RCC_CIFR_HSI48RDYF			(1 << 6)
#define RCC_CIFR_MSIRDYF			(1 << 5)
#define RCC_CIFR_PLLRDYF			(1 << 4)
#define RCC_CIFR_HSERDYF			(1 << 3)
#define RCC_CIFR_HSI16RDYF			(1 << 2)
#define RCC_CIFR_LSERDYF			(1 << 1)
#define RCC_CIFR_LSIRDYF			(1 << 0)

/* --- RCC_CICR - Clock interrupt clear register */

#define RCC_CICR_CSSHSEC			(1 << 8)
#define RCC_CICR_CSSLSEC			(1 << 7)
#define RCC_CICR_HSI48RDYC			(1 << 6)
#define RCC_CICR_MSIRDYC			(1 << 5)
#define RCC_CICR_PLLRDYC			(1 << 4)
#define RCC_CICR_HSERDYC			(1 << 3)
#define RCC_CICR_HSI16RDYC			(1 << 2)
#define RCC_CICR_LSERDYC			(1 << 1)
#define RCC_CICR_LSIRDYC			(1 << 0)

/* --- RCC_IOPRSTR - GPIO Reset Register */

#define RCC_IOPPRSTR_IOPHRST			(1<<7)
#define RCC_IOPPRSTR_IOPERST			(1<<4)
#define RCC_IOPPRSTR_IOPDRST			(1<<3)
#define RCC_IOPPRSTR_IOPCRST			(1<<2)
#define RCC_IOPPRSTR_IOPBRST			(1<<1)
#define RCC_IOPPRSTR_IOPARST			(1<<0)

/** @defgroup rcc_ahbrstr_rst RCC_AHBRSTR reset values
@{*/
#define RCC_AHBRSTR_CRYPRST			(1 << 24)
#define RCC_AHBRSTR_RNGRST			(1 << 20)
#define RCC_AHBRSTR_TSCRST			(1 << 16)
#define RCC_AHBRSTR_CRCRST			(1 << 12)
#define RCC_AHBRSTR_MIFRST			(1 << 8)
#define RCC_AHBRSTR_DMARST			(1 << 0)
/**@}*/

/** @defgroup rcc_apb2rstr_rst RCC_APB2RSTR reset values
@{*/
#define RCC_APB2RSTR_DBGRST			(1 << 22)
#define RCC_APB2RSTR_USART1RST			(1 << 14)
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_ADC1RST			(1 << 9)
#define RCC_APB2RSTR_TIM22RST			(1 << 5)
#define RCC_APB2RSTR_TIM21RST			(1 << 2)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 0)
/**@}*/

/** @defgroup rcc_apb1rstr_rst RCC_APB1RSTR reset values
@{*/
#define RCC_APB1RSTR_LPTIM1RST			(1 << 31)
#define RCC_APB1RSTR_I2C3RST			(1 << 30)
#define RCC_APB1RSTR_DACRST			(1 << 29)
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_CRSRST			(1 << 27)
#define RCC_APB1RSTR_USBRST			(1 << 23)
#define RCC_APB1RSTR_I2C2RST			(1 << 22)
#define RCC_APB1RSTR_I2C1RST			(1 << 21)
#define RCC_APB1RSTR_USART5RST			(1 << 20)
#define RCC_APB1RSTR_USART4RST			(1 << 19)
#define RCC_APB1RSTR_LPUART1RST			(1 << 18)
#define RCC_APB1RSTR_USART2RST			(1 << 17)
#define RCC_APB1RSTR_SPI2RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_LCDRST			(1 << 9)
#define RCC_APB1RSTR_TIM7RST			(1 << 5)
#define RCC_APB1RSTR_TIM6RST			(1 << 4)
#define RCC_APB1RSTR_TIM3RST			(1 << 1)
#define RCC_APB1RSTR_TIM2RST			(1 << 0)
/**@}*/

/* --- RCC_IOPENR - GPIO clock enable register */

#define RCC_IOPENR_IOPHEN			(1<<7)
#define RCC_IOPENR_IOPEEN			(1<<4)
#define RCC_IOPENR_IOPDEN			(1<<3)
#define RCC_IOPENR_IOPCEN			(1<<2)
#define RCC_IOPENR_IOPBEN			(1<<1)
#define RCC_IOPENR_IOPAEN			(1<<0)

/** @defgroup rcc_ahbenr_en RCC_APHBENR enable values
@{*/
#define RCC_AHBENR_CRYPEN			(1 << 24)
#define RCC_AHBENR_RNGEN			(1 << 20)
#define RCC_AHBENR_TSCEN			(1 << 16)
#define RCC_AHBENR_CRCEN			(1 << 12)
#define RCC_AHBENR_MIFEN			(1 << 8)
#define RCC_AHBENR_DMAEN			(1 << 0)
/**@}*/

/** @defgroup rcc_apb2enr_en RCC_APPB2ENR enable values
@{*/
#define RCC_APB2ENR_DBGEN			(1 << 22)
#define RCC_APB2ENR_USART1EN			(1 << 14)
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_ADC1EN			(1 << 9)
#define RCC_APB2ENR_MIFEN			(1 << 7)
#define RCC_APB2ENR_TIM22EN			(1 << 5)
#define RCC_APB2ENR_TIM21EN			(1 << 2)
#define RCC_APB2ENR_SYSCFGEN			(1 << 0)
/**@}*/

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@{*/
#define RCC_APB1ENR_LPTIM1EN			(1 << 31)
#define RCC_APB1ENR_DACEN			(1 << 29)
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_CRSEN			(1 << 27)
#define RCC_APB1ENR_USBEN			(1 << 23)
#define RCC_APB1ENR_I2C2EN			(1 << 22)
#define RCC_APB1ENR_I2C1EN			(1 << 21)
#define RCC_APB1ENR_USART5EN			(1 << 20)
#define RCC_APB1ENR_USART4EN			(1 << 19)
#define RCC_APB1ENR_LPUART1EN			(1 << 18)
#define RCC_APB1ENR_USART2EN			(1 << 17)
#define RCC_APB1ENR_SPI2EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_LCDEN			(1 << 9)
#define RCC_APB1ENR_TIM7EN			(1 << 5)
#define RCC_APB1ENR_TIM6EN			(1 << 4)
#define RCC_APB1ENR_TIM3EN			(1 << 1)
#define RCC_APB1ENR_TIM2EN			(1 << 0)
/**@}*/

/* --- RCC_IOPSMENR - GPIO Clock enable in sleep mode */

#define RCC_IOPSMENR_IOPHSMEN			(1<<7)
#define RCC_IOPSMENR_IOPESMEN			(1<<4)
#define RCC_IOPSMENR_IOPDSMEN			(1<<3)
#define RCC_IOPSMENR_IOPCSMEN			(1<<2)
#define RCC_IOPSMENR_IOPBSMEN			(1<<1)
#define RCC_IOPSMENR_IOPASMEN			(1<<0)

/* --- RCC_AHBSMENR - AHB periph clock in sleep mode */

#define RCC_AHBSMENR_CRYPSMEN			(1 << 24)
#define RCC_AHBSMENR_RNGSMEN			(1 << 20)
#define RCC_AHBSMENR_TSCSMEN			(1 << 16)
#define RCC_AHBSMENR_CRCSMEN			(1 << 12)
#define RCC_AHBSMENR_MIFSMEN			(1 << 8)
#define RCC_AHBSMENR_DMASMEN			(1 << 0)

/* --- RCC_APB2SMENR - APB2 periph clock in sleep mode */

#define RCC_APB2SMENR_DBGSMEN			(1 << 22)
#define RCC_APB2SMENR_USART1SMEN		(1 << 14)
#define RCC_APB2SMENR_SPI1SMEN			(1 << 12)
#define RCC_APB2SMENR_ADC1SMEN			(1 << 9)
#define RCC_APB2SMENR_MIFSMEN			(1 << 7)
#define RCC_APB2SMENR_TIM22SMEN			(1 << 5)
#define RCC_APB2SMENR_TIM21SMEN			(1 << 2)
#define RCC_APB2SMENR_SYSCFGSMEN		(1 << 0)

/* --- RCC_APB1SMENR - APB1 periph clock in sleep mode */

#define RCC_APB1SMENR_LPTIM1SMEN	(1 << 31)
#define RCC_APB1SMENR_I2C3SMEN		(1 << 30)
#define RCC_APB1SMENR_DACSMEN		(1 << 29)
#define RCC_APB1SMENR_PWRSMEN		(1 << 28)
#define RCC_APB1SMENR_CRSSMEN		(1 << 27)
#define RCC_APB1SMENR_USBSMEN		(1 << 23)
#define RCC_APB1SMENR_I2C2SMEN		(1 << 22)
#define RCC_APB1SMENR_I2C1SMEN		(1 << 21)
#define RCC_APB1SMENR_USART5SMEN	(1 << 20)
#define RCC_APB1SMENR_USART4SMEN	(1 << 19)
#define RCC_APB1SMENR_LPUART1SMEN	(1 << 18)
#define RCC_APB1SMENR_USART2SMEN	(1 << 17)
#define RCC_APB1SMENR_SPI2SMEN		(1 << 14)
#define RCC_APB1SMENR_WWDGSMEN		(1 << 11)
#define RCC_APB1SMENR_LCDSMEN		(1 << 9)
#define RCC_APB1SMENR_TIM7SMEN		(1 << 5)
#define RCC_APB1SMENR_TIM6SMEN		(1 << 4)
#define RCC_APB1SMENR_TIM3SMEN		(1 << 1)
#define RCC_APB1SMENR_TIM2SMEN		(1 << 0)

/* --- RCC_CCIPR - Clock config register */

#define RCC_CCIPR_HSI48SEL		(1<<26)

#define RCC_CCIPR_LPTIM1SEL_APB		0
#define RCC_CCIPR_LPTIM1SEL_LSI		1
#define RCC_CCIPR_LPTIM1SEL_HSI16	2
#define RCC_CCIPR_LPTIM1SEL_LSE		3
#define RCC_CCIPR_LPTIM1SEL_SHIFT	18
#define RCC_CCIPR_LPTIM1SEL_MASK	0x3

#define RCC_CCIPR_I2C3SEL_APB		0
#define RCC_CCIPR_I2C3SEL_SYS		1
#define RCC_CCIPR_I2C3SEL_HSI16		2
#define RCC_CCIPR_I2C3SEL_SHIFT		16
#define RCC_CCIPR_I2C3SEL_MASK		0x3

#define RCC_CCIPR_I2C1SEL_APB		0
#define RCC_CCIPR_I2C1SEL_SYS		1
#define RCC_CCIPR_I2C1SEL_HSI16		2
#define RCC_CCIPR_I2C1SEL_SHIFT		12
#define RCC_CCIPR_I2C1SEL_MASK		0x3

#define RCC_CCIPR_LPUART1SEL_APB	0
#define RCC_CCIPR_LPUART1SEL_SYS	1
#define RCC_CCIPR_LPUART1SEL_HSI16	2
#define RCC_CCIPR_LPUART1SEL_LSE	3
#define RCC_CCIPR_LPUART1SEL_SHIFT	10
#define RCC_CCIPR_LPUART1SEL_MASK	0x3

#define RCC_CCIPR_USART2SEL_APB		0
#define RCC_CCIPR_USART2SEL_SYS		1
#define RCC_CCIPR_USART2SEL_HSI16	2
#define RCC_CCIPR_USART2SEL_LSE		3
#define RCC_CCIPR_USART2SEL_SHIFT	2
#define RCC_CCIPR_USART2SEL_MASK	0x3

#define RCC_CCIPR_USART1SEL_APB		0
#define RCC_CCIPR_USART1SEL_SYS		1
#define RCC_CCIPR_USART1SEL_HSI16	2
#define RCC_CCIPR_USART1SEL_LSE		3
#define RCC_CCIPR_USART1SEL_SHIFT	0
#define RCC_CCIPR_USART1SEL_MASK	0x3

/* --- RCC_CSRT - Control/Status register */

#define RCC_CSR_LPWRRSTF			(1 << 31)
#define RCC_CSR_WWDGRSTF			(1 << 30)
#define RCC_CSR_IWDGRSTF			(1 << 29)
#define RCC_CSR_SFTRSTF				(1 << 28)
#define RCC_CSR_PORRSTF				(1 << 27)
#define RCC_CSR_PINRSTF				(1 << 26)
#define RCC_CSR_OBLRSTF				(1 << 25)
#define RCC_CSR_FWRSTF				(1 << 24)
#define RCC_CSR_RMVF				(1 << 23)
#define RCC_CSR_RESET_FLAGS	(RCC_CSR_LPWRRSTF | RCC_CSR_WWDGRSTF |\
		RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF | RCC_CSR_PORRSTF |\
		RCC_CSR_PINRSTF | RCC_CSR_OBLRSTF | RCC_CSR_FWRSTF)
#define RCC_CSR_RTCRST				(1 << 19)
#define RCC_CSR_RTCEN				(1 << 18)
#define RCC_CSR_RTCSEL_SHIFT			(16)
#define RCC_CSR_RTCSEL_MASK			(0x3)
#define RCC_CSR_RTCSEL_NONE			(0x0)
#define RCC_CSR_RTCSEL_LSE			(0x1)
#define RCC_CSR_RTCSEL_LSI			(0x2)
#define RCC_CSR_RTCSEL_HSE			(0x3)
#define RCC_CSR_CSSLSED				(1 << 14)
#define RCC_CSR_CSSLSEON			(1 << 13)
#define RCC_CSR_LSEDRV_SHIFT			11
#define RCC_CSR_LSEDRV_MASK			0x3
#define RCC_CSR_LSEDRV_LOWEST			0
#define RCC_CSR_LSEDRV_MLOW			1
#define RCC_CSR_LSEDRV_MHIGH			2
#define RCC_CSR_LSEDRV_HIGHEST			3
#define RCC_CSR_LSEBYP				(1 << 10)
#define RCC_CSR_LSERDY				(1 << 9)
#define RCC_CSR_LSEON				(1 << 8)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)

struct rcc_clock_scale {
	uint8_t pll_mul;
	uint16_t pll_div;
	uint8_t pll_source;
	uint8_t flash_waitstates;
	enum pwr_vos_scale voltage_scale;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	// FIXME enum pwr_vos_scale voltage_scale;
	uint32_t ahb_frequency;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
	uint8_t msi_range;
};

/* --- Variable definitions ------------------------------------------------ */
extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

/* --- Function prototypes ------------------------------------------------- */

enum rcc_osc {
	RCC_PLL, RCC_HSE, RCC_HSI48, RCC_HSI16, RCC_MSI, RCC_LSE, RCC_LSI
};


#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

enum rcc_periph_clken {
	/* GPIO peripherals  */
	RCC_GPIOA = _REG_BIT(0x2c, 0),
	RCC_GPIOB = _REG_BIT(0x2c, 1),
	RCC_GPIOC = _REG_BIT(0x2c, 2),
	RCC_GPIOD = _REG_BIT(0x2c, 3),
	RCC_GPIOE = _REG_BIT(0x2c, 4),
	RCC_GPIOH = _REG_BIT(0x2c, 7),

	/* AHB peripherals */
	RCC_DMA = _REG_BIT(0x30, 0),
	RCC_MIF = _REG_BIT(0x30, 8),
	RCC_CRC = _REG_BIT(0x30, 12),
	RCC_TSC = _REG_BIT(0x30, 16),
	RCC_RNG = _REG_BIT(0x30, 20),
	RCC_CRYPT = _REG_BIT(0x30, 24),

	/* APB2 peripherals */
	RCC_SYSCFG = _REG_BIT(0x34, 0),
	RCC_TIM21 = _REG_BIT(0x34, 2),
	RCC_TIM22 = _REG_BIT(0x34, 5),
	RCC_FW = _REG_BIT(0x34, 7),
	RCC_ADC1 = _REG_BIT(0x34, 9),
	RCC_SPI1 = _REG_BIT(0x34, 12),
	RCC_USART1 = _REG_BIT(0x34, 14),
	RCC_DBG = _REG_BIT(0x34, 22),

	/* APB1 peripherals */
	RCC_TIM2 = _REG_BIT(0x38, 0),
	RCC_TIM3 = _REG_BIT(0x38, 1),
	RCC_TIM6 = _REG_BIT(0x38, 4),
	RCC_TIM7 = _REG_BIT(0x38, 5),
	RCC_LCD = _REG_BIT(0x38, 9),
	RCC_WWDG = _REG_BIT(0x38, 11),
	RCC_SPI2 = _REG_BIT(0x38, 14),
	RCC_USART2 = _REG_BIT(0x38, 17),
	RCC_LPUART1 = _REG_BIT(0x38, 18),
	RCC_USART4 = _REG_BIT(0x38, 19),
	RCC_USART5 = _REG_BIT(0x38, 20),
	RCC_I2C1 = _REG_BIT(0x38, 21),
	RCC_I2C2 = _REG_BIT(0x38, 22),
	RCC_USB = _REG_BIT(0x38, 23),
	RCC_CRS = _REG_BIT(0x38, 27),
	RCC_PWR = _REG_BIT(0x38, 28),
	RCC_DAC = _REG_BIT(0x38, 29),
	RCC_I2C3 = _REG_BIT(0x38, 30),
	RCC_LPTIM1 = _REG_BIT(0x38, 31),

	/* GPIO peripherals in sleep mode */
	SCC_GPIOA = _REG_BIT(0x3c, 0),
	SCC_GPIOB = _REG_BIT(0x3c, 1),
	SCC_GPIOC = _REG_BIT(0x3c, 2),
	SCC_GPIOD = _REG_BIT(0x3c, 3),
	SCC_GPIOE = _REG_BIT(0x3c, 4),
	SCC_GPIOH = _REG_BIT(0x3c, 7),

	/* AHB peripherals in sleep mode */
	SCC_DMA = _REG_BIT(0x40, 0),
	SCC_MIF = _REG_BIT(0x40, 8),
	SCC_SRAM = _REG_BIT(0x40, 12),
	SCC_CRC = _REG_BIT(0x40, 12),
	SCC_TSC = _REG_BIT(0x40, 16),
	SCC_RNG = _REG_BIT(0x40, 20),
	SCC_CRYPT = _REG_BIT(0x40, 24),

	/* APB2 peripherals in sleep mode */
	SCC_SYSCFG = _REG_BIT(0x44, 0),
	SCC_TIM21 = _REG_BIT(0x44, 2),
	SCC_TIM22 = _REG_BIT(0x44, 5),
	SCC_ADC1 = _REG_BIT(0x44, 9),
	SCC_SPI1 = _REG_BIT(0x44, 12),
	SCC_USART1 = _REG_BIT(0x44, 14),
	SCC_DBG = _REG_BIT(0x44, 22),

	/* APB1 peripherals in sleep mode */
	SCC_TIM2 = _REG_BIT(0x48, 0),
	SCC_TIM3 = _REG_BIT(0x48, 1),
	SCC_TIM6 = _REG_BIT(0x48, 4),
	SCC_TIM7 = _REG_BIT(0x48, 5),
	SCC_LCD = _REG_BIT(0x48, 9),
	SCC_WWDG = _REG_BIT(0x48, 11),
	SCC_SPI2 = _REG_BIT(0x48, 14),
	SCC_USART2 = _REG_BIT(0x48, 17),
	SCC_LPUART1 = _REG_BIT(0x48, 18),
	SCC_USART4 = _REG_BIT(0x48, 19),
	SCC_USART5 = _REG_BIT(0x48, 20),
	SCC_I2C1 = _REG_BIT(0x48, 21),
	SCC_I2C2 = _REG_BIT(0x48, 22),
	SCC_USB = _REG_BIT(0x48, 23),
	SCC_CRS = _REG_BIT(0x48, 27),
	SCC_PWR = _REG_BIT(0x48, 28),
	SCC_DAC = _REG_BIT(0x48, 29),
	SCC_I2C3 = _REG_BIT(0x48, 30),
	SCC_LPTIM1 = _REG_BIT(0x48, 31),
};

enum rcc_periph_rst {
	/* GPIO peripherals */
	RST_GPIOA = _REG_BIT(0x1c, 0),
	RST_GPIOB = _REG_BIT(0x1c, 1),
	RST_GPIOC = _REG_BIT(0x1c, 2),
	RST_GPIOD = _REG_BIT(0x1c, 3),
	RST_GPIOE = _REG_BIT(0x1c, 4),
	RST_GPIOH = _REG_BIT(0x1c, 7),

	/* AHB peripherals  */
	RST_DMA = _REG_BIT(0x20, 0),
	RST_MIF = _REG_BIT(0x20, 8),
	RST_CRC = _REG_BIT(0x20, 12),
	RST_TSC = _REG_BIT(0x20, 16),
	RST_RNG = _REG_BIT(0x20, 20),
	RST_CRYPT = _REG_BIT(0x20, 24),

	/* APB2 peripherals */
	RST_SYSCFG = _REG_BIT(0x24, 0),
	RST_TIM21 = _REG_BIT(0x24, 2),
	RST_TIM22 = _REG_BIT(0x24, 5),
	RST_ADC1 = _REG_BIT(0x24, 9),
	RST_SPI1 = _REG_BIT(0x24, 12),
	RST_USART1 = _REG_BIT(0x24, 14),
	RST_DBG = _REG_BIT(0x24, 22),

	/* APB1 peripherals*/
	RST_TIM2 = _REG_BIT(0x28, 0),
	RST_TIM3 = _REG_BIT(0x28, 1),
	RST_TIM6 = _REG_BIT(0x28, 4),
	RST_TIM7 = _REG_BIT(0x28, 5),
	RST_LCD = _REG_BIT(0x28, 9),
	RST_WWDG = _REG_BIT(0x28, 11),
	RST_SPI2 = _REG_BIT(0x28, 14),
	RST_USART2 = _REG_BIT(0x28, 17),
	RST_LPUART1 = _REG_BIT(0x28, 18),
	RST_USART4 = _REG_BIT(0x28, 19),
	RST_USART5 = _REG_BIT(0x28, 20),
	RST_I2C1 = _REG_BIT(0x28, 21),
	RST_I2C2 = _REG_BIT(0x28, 22),
	RST_USB = _REG_BIT(0x28, 23),
	RST_CRS = _REG_BIT(0x28, 27),
	RST_PWR = _REG_BIT(0x28, 28),
	RST_DAC = _REG_BIT(0x28, 29),
	RST_I2C3 = _REG_BIT(0x28, 30),
	RST_LPTIM1 = _REG_BIT(0x28, 31),
};
#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS

void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_set_hsi48_source_rc48(void);
void rcc_set_hsi48_source_pll(void);
void rcc_set_sysclk_source(enum rcc_osc osc);
void rcc_set_pll_multiplier(uint32_t factor);
void rcc_set_pll_divider(uint32_t factor);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);

void rcc_set_msi_range(uint32_t msi_range);

void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t sel);
void rcc_set_lptim1_sel(uint32_t lptim1_sel);
void rcc_set_lpuart1_sel(uint32_t lpupart1_sel);
void rcc_set_usart1_sel(uint32_t usart1_sel);
void rcc_set_usart2_sel(uint32_t usart2_sel);
uint32_t rcc_get_usart_clk_freq(uint32_t usart);
uint32_t rcc_get_timer_clk_freq(uint32_t timer);
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c);
uint32_t rcc_get_spi_clk_freq(uint32_t spi);

END_DECLS

/**@}*/

#endif
