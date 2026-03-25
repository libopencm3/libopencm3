/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the AT32F43x Reset and Clock
 * Control</b>
 *
 * @ingroup AT32F43x_defines
 *
 * @version 1.0.0
 *
 * @date 16 November 2024
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
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

/* --- RCC registers ------------------------------------------------------- */
/* register names according to at32f435/437 reference manual v2.06 table 4-1 */
#define RCC_CR			MMIO32(RCC_BASE + 0x00)		/* CRM_CTRL */
#define RCC_PLLCFGR		MMIO32(RCC_BASE + 0x04)		/* CRM_PLLCFG */
#define RCC_CFGR		MMIO32(RCC_BASE + 0x08)		/* CRM_CFG */
#define RCC_CIR			MMIO32(RCC_BASE + 0x0c)		/* CRM_CLKINT */
#define RCC_AHB1RTSR		MMIO32(RCC_BASE + 0x10)		/* CRM_AHBRST1 */
#define RCC_AHB2RTSR		MMIO32(RCC_BASE + 0x14)		/* CRM_AHBRST2 */
#define RCC_AHB3RTSR		MMIO32(RCC_BASE + 0x18)		/* CRM_AHBRST3 */
#define RCC_APB1RSTR		MMIO32(RCC_BASE + 0x20)		/* CRM_APB1RST */
#define RCC_APB2RSTR		MMIO32(RCC_BASE + 0x24)		/* CRM_APB2RST */
/* RCC_BASE + 0x28 Reserved */
/* RCC_BASE + 0x2c Reserved */
#define RCC_AHB1ENR		MMIO32(RCC_BASE + 0x30)		/* CRM_AHBEN1 */
#define RCC_AHB2ENR		MMIO32(RCC_BASE + 0x34)		/* CRM_AHBEN2 */
#define RCC_AHB3ENR		MMIO32(RCC_BASE + 0x38)		/* CRM_AHBEN3 */
/* RCC_BASE + 0x3c Reserved */
#define RCC_APB1ENR		MMIO32(RCC_BASE + 0x40)		/* CRM_APB1EN */
#define RCC_APB2ENR		MMIO32(RCC_BASE + 0x44)		/* CRM_APB2EN */
/* RCC_BASE + 0x48 Reserved */
/* RCC_BASE + 0x4c Reserved */
#define RCC_AHB1LPENR		MMIO32(RCC_BASE + 0x50)		/* CRM_AHBLPEN1 */
#define RCC_AHB2LPENR		MMIO32(RCC_BASE + 0x54)		/* CRM_AHBLPEN2 */
#define RCC_AHB3LPENR		MMIO32(RCC_BASE + 0x58)		/* CRM_AHBLPEN3 */
/* RCC_BASE + 0x5c Reserved */
#define RCC_APB1LPENR		MMIO32(RCC_BASE + 0x60)		/* CRM_APB1LPEN */
#define RCC_APB2LPENR		MMIO32(RCC_BASE + 0x64)		/* CRM_APB2LPEN */
/* RCC_BASE + 0x68 Reserved */
/* RCC_BASE + 0x6c Reserved */
#define RCC_BDCR		MMIO32(RCC_BASE + 0x70)		/* CRM_BPDC */
#define RCC_CSR			MMIO32(RCC_BASE + 0x74)		/* CRM_CTRLSTS */
/*  */
#define RCC_CFGR3		MMIO32(RCC_BASE + 0xA0)		/* CRM_MISC1 */
#define RCC_CFGR4		MMIO32(RCC_BASE + 0xA4)		/* CRM_MISC2 */

/* --- RCC_CR (CRM_CTRL) values -------------------------------------------- */

#define RCC_CR_PLLRDY		(1 << 25)			/* PLLSTBL */
#define RCC_CR_PLLON		(1 << 24)			/* PLLEN */
#define RCC_CR_CSSON		(1 << 19)			/* CFDEN */
#define RCC_CR_HSEBYP		(1 << 18)			/* HEXTBYPS */
#define RCC_CR_HSERDY		(1 << 17)			/* HEXTSTBL */
#define RCC_CR_HSEON		(1 << 16)			/* HEXTEN */
/* HSICAL: [15:8] */
/* HSITRIM: [7:2] */
#define RCC_CR_HSIRDY		(1 << 1)			/* HICKSTBL */
#define RCC_CR_HSION		(1 << 0)			/* HICKEN */

/* --- RCC_PLLCFGR (CRM_PLLCFG) values ------------------------------------- */
/* reserved	[31:23] */
#define RCC_PLLCFGR_PLLSRC	(1 << 22)			/* PLLRCS */
/* reserved	[21:19] */
/* PLLP		[18:16] */					/* PLL_FR */
/* reserved	[15:15] */
/* PLLN		[14: 6] */					/* PLL_NS */
/* reserved	[ 5: 4] */
/* PLLM		[ 3: 0] */					/* PLL_MS */

#define RCC_PLLSRC_SHIFT	22
#define RCC_PLLSRC_MASK		1

#define RCC_PLLCFGR_PLLSRC_HSI	0
#define RCC_PLLCFGR_PLLSRC_HSE	1

#define RCC_PLLCFGR_PLLP_SHIFT	16
#define RCC_PLLCFGR_PLLP	(0x7 << RCC_PLLCFGR_PLLP_SHIFT)

#define RCC_PLLCFGR_PLLN_SHIFT	6
#define RCC_PLLCFGR_PLLN	(0x1ff << RCC_PLLCFGR_PLLN_SHIFT)

#define RCC_PLLCFGR_PLLM_SHIFT	0
#define RCC_PLLCFGR_PLLM	(0xf << RCC_PLLCFGR_PLLM_SHIFT)

/* --- RCC_CFGR (CRM_CFG) values ------------------------------------------- */
/* MCO2		[31:30] */					/* CLKOUT2_SEL1 */
/* MCO2_PRE	[29:27] */					/* CLKOUT2DIV1 */
/* MCO1_PRE	[26:24] */					/* CLKOUT1DIV1 */
/* reserved	[23:23] */
/* MCO1		[22:21] */					/* CLKOUT1_SEL */
/* RTCPRE	[20:16] */					/* ERTCDIV */
/* PPRE2	[15:13] */					/* APB2DIV */
/* PPRE1	[12:10] */					/* APB1DIV */
/* reserved	[ 9: 8] */
/* HPRE		[ 7: 4] */					/* AHBDIV */
/* SWS		[ 3: 2] */					/* SCLKSTS */
/* SW		[ 1: 0] */					/* SCLKSEL */

#define RCC_CFGR_MCO2_SHIFT	30
#define RCC_CFGR_MCO2		(3 << RCC_CFGR_MCO2_SHIFT)

#define RCC_CFGR_MCO2_SYSCLK	0x0
#define RCC_CFGR_MCO2_MUX	0x1
#define RCC_CFGR_MCO2_HSE	0x2
#define RCC_CFGR_MCO2_PLL	0x3

#define RCC_CFGR_MCO2PRE_SHIFT	27
#define RCC_CFGR_MCO2PRE	(7 << RCC_CFGR_MCO2PRE_SHIFT)

#define RCC_CFGR_MCO1PRE_SHIFT	24
#define RCC_CFGR_MCO1PRE	(7 << RCC_CFGR_MCO2PRE_SHIFT)

#define RCC_CFGR_MCO1_SHIFT	21
#define RCC_CFGR_MCO1		(3 << RCC_CFGR_MCO1_SHIFT)

#define RCC_CFGR_MCO1_HSI	0x0
#define RCC_CFGR_MCO1_LSE	0x1
#define RCC_CFGR_MCO1_HSE	0x2
#define RCC_CFGR_MCO1_PLL	0x3

#define RCC_CFGR_MCO_SHIFT	RCC_CFGR_MCO1_SHIFT
#define RCC_CFGR_MCO_MASK	3

#define RCC_CFGR_MCOPRE_NODIV	0x0
#define RCC_CFGR_MCOPRE_DIV_2	0x4
#define RCC_CFGR_MCOPRE_DIV_3	0x5
#define RCC_CFGR_MCOPRE_DIV_4	0x6
#define RCC_CFGR_MCOPRE_DIV_5	0x7

#define RCC_CFGR_RTCPRE_SHIFT	16
#define RCC_CFGR_RTCPRE		(0x1f << RCC_CFGR_RTCPRE_SHIFT)

#define RCC_CFGR_PPRE2_SHIFT	13
#define RCC_CFGR_PPRE2		(7 << RCC_CFGR_PPRE2_SHIFT)

#define RCC_CFGR_PPRE1_SHIFT	10
#define RCC_CFGR_PPRE1		(7 << RCC_CFGR_PPRE1_SHIFT)

#define RCC_CFGR_HPRE_SHIFT	4
#define RCC_CFGR_HPRE		(0xF << RCC_CFGR_HPRE_SHIFT)	/* AHBDIV[0:3] */

#define RCC_CFGR_SWS_SHIFT	2
#define RCC_CFGR_SWS		(3 << RCC_CFGR_SWS_SHIFT)	/* SCLKSTS[0:1] */

#define RCC_CFGR_SW_SHIFT	0
#define RCC_CFGR_SW		(3 << RCC_CFGR_SW_SHIFT)	/* SCLKSEL[0:1] */

#define RCC_CFGR_PPRE_NODIV	0x0
#define RCC_CFGR_PPRE_DIV2	0x4
#define RCC_CFGR_PPRE_DIV4	0x5
#define RCC_CFGR_PPRE_DIV8	0x6
#define RCC_CFGR_PPRE_DIV16	0x7

#define RCC_CFGR_HPRE_NODIV	0x0
#define RCC_CFGR_HPRE_DIV2	0x8
#define RCC_CFGR_HPRE_DIV4	0x9
#define RCC_CFGR_HPRE_DIV8	0xa
#define RCC_CFGR_HPRE_DIV16	0xb
#define RCC_CFGR_HPRE_DIV64	0xc
#define RCC_CFGR_HPRE_DIV128	0xd
#define RCC_CFGR_HPRE_DIV256	0xe
#define RCC_CFGR_HPRE_DIV512	0xf

#define RCC_CFGR_SWS_SYSCLKSEL_HSICLK	0x0
#define RCC_CFGR_SWS_SYSCLKSEL_HSECLK	0x1
#define RCC_CFGR_SWS_SYSCLKSEL_PLLCLK	0x2

#define RCC_CFGR_SW_SYSCLKSEL_HSICLK	0x0
#define RCC_CFGR_SW_SYSCLKSEL_HSECLK	0x1
#define RCC_CFGR_SW_SYSCLKSEL_PLLCLK	0x2

/* --- RCC_CIR (CRM_CLKINT) values ----------------------------------------- */

/* CLOCK security system interrupt clear bit */
#define RCC_CIR_CSSC		(1 << 23)			/* CFDFC */

/* OSC ready interrupt clear bits */
#define RCC_CIR_PLLRDYC		(1 << 20)			/* PLLSTBLFC */
#define RCC_CIR_HSERDYC		(1 << 19)			/* HEXTSTBLFC */
#define RCC_CIR_HSIRDYC		(1 << 18)			/* HICKSTBLFC */
#define RCC_CIR_LSERDYC		(1 << 17)			/* LEXTSTBLFC */
#define RCC_CIR_LSIRDYC		(1 << 16)			/* LICKSTBLFC */

/* OSC ready interrupt enable bits */
#define RCC_CIR_PLLRDYIE	(1 << 12)			/* PLLSTBLIEN */
#define RCC_CIR_HSERDYIE	(1 << 11)			/* HEXTSTBLIEN */
#define RCC_CIR_HSIRDYIE	(1 << 10)			/* HICKSTBLIEN */
#define RCC_CIR_LSERDYIE	(1 << 9)			/* LEXTSTBLIEN */
#define RCC_CIR_LSIRDYIE	(1 << 8)			/* LICKSTBLIEN */

/* Clock security system interrupt flag bit */
#define RCC_CIR_CSSF		(1 << 7)			/* CFDF */

/* OSC ready interrupt flag bits */
#define RCC_CIR_PLLRDYF		(1 << 4)			/* PLLSTBLF */
#define RCC_CIR_HSERDYF		(1 << 3)			/* HEXTSTBLF */
#define RCC_CIR_HSIRDYF		(1 << 2)			/* HICKSTBLF */
#define RCC_CIR_LSERDYF		(1 << 1)			/* LEXTSTBLF */
#define RCC_CIR_LSIRDYF		(1 << 0)			/* LICKSTBLF */

/* --- RCC_AHB1RSTR (CRM_AHBRST1) values ----------------------------------- */

#define RCC_AHB1RSTR_OTGFS2RST	(1 << 29)			/* OTGFS2RST */
#define RCC_AHB1RSTR_ETHMACRST	(1 << 25)			/* EMACRST */
#define RCC_AHB1RSTR_DMA2RST	(1 << 24)			/* DMA2RSR */
#define RCC_AHB1RSTR_DMA1RST	(1 << 22)			/* DMA1RST */
#define RCC_AHB1RSTR_DMA0RST	(1 << 21)			/* EDMARST */
#define RCC_AHB1RSTR_CRCRST	(1 << 12)			/* CRCRST */
#define RCC_AHB1RSTR_GPIOHRST	(1 << 7)			/* GPIOHRST */
#define RCC_AHB1RSTR_GPIOGRST	(1 << 6)			/* GPIOGRST */
#define RCC_AHB1RSTR_GPIOFRST	(1 << 5)			/* GPIOFRST */
#define RCC_AHB1RSTR_GPIOERST	(1 << 4)			/* GPIOERST */
#define RCC_AHB1RSTR_GPIODRST	(1 << 3)			/* GPIODRST */
#define RCC_AHB1RSTR_GPIOCRST	(1 << 2)			/* GPIOCRST */
#define RCC_AHB1RSTR_GPIOBRST	(1 << 1)			/* GPIOBRST */
#define RCC_AHB1RSTR_GPIOARST	(1 << 0)			/* GPIOARST */

/* --- RCC_AHB2RSTR (CRM_AHBRST2) values ----------------------------------- */
#define RCC_AHB2RSTR_SDIO1RST	(1 << 15)			/* SDIO1RST */
#define RCC_AHB2RSTR_OTGFS1RST	(1 << 7)			/* OTGFS1RST */
#define RCC_AHB2RSTR_DCMIRST	(1 << 0)			/* DVPRST */

/* --- RCC_AHB3RSTR (CRM_AHBRST3) values ----------------------------------- */
#define RCC_AHB3RSTR_SDIO2RST	(1 << 15)			/* SDIO2RST */
#define RCC_AHB3RSTR_QSPI2RST	(1 << 14)			/* QSPI2RST */
#define RCC_AHB3RSTR_QSPI1RST	(1 << 1)			/* QSPI1RST */
#define RCC_AHB3RSTR_FSMCRST	(1 << 0)			/* XMCRST */

/* --- RCC_APB1RSTR (CRM_APB1RST) values ----------------------------------- */
#define RCC_APB1RSTR_UART7RST	(1 << 30)			/* UART7RST */
#define RCC_APB1RSTR_DACRST	(1 << 29)			/* DACRST */
#define RCC_APB1RSTR_PWRRST	(1 << 28)			/* PWCRST */
/**/
#define RCC_APB1RSTR_CAN2RST	(1 << 26)			/* CAN2RST */
#define RCC_APB1RSTR_CAN1RST	(1 << 25)			/* CAN1RST */
#define RCC_APB1RSTR_CANRST	(1 << 25)
/**/
#define RCC_APB1RSTR_I2C3RST	(1 << 23)			/* I2C3RST */
#define RCC_APB1RSTR_I2C2RST	(1 << 22)			/* I2C2RST */
#define RCC_APB1RSTR_I2C1RST	(1 << 21)			/* I2C1RST */
#define RCC_APB1RSTR_UART5RST	(1 << 20)			/* UART5RST */
#define RCC_APB1RSTR_UART4RST	(1 << 19)			/* UART4RST */
#define RCC_APB1RSTR_USART3RST	(1 << 18)			/* USART3RST */
#define RCC_APB1RSTR_USART2RST	(1 << 17)			/* USART2RST */
/**/
#define RCC_APB1RSTR_SPI3RST	(1 << 15)			/* SPI3RST */
#define RCC_APB1RSTR_SPI2RST	(1 << 14)			/* SPI2RST */
/**/
#define RCC_APB1RSTR_WWDGRST	(1 << 11)			/* WWDTRST */
/**/
#define RCC_APB1RSTR_TIM14RST	(1 << 8)			/* TMR14RST */
#define RCC_APB1RSTR_TIM13RST	(1 << 7)			/* TMR13RST */
#define RCC_APB1RSTR_TIM12RST	(1 << 6)			/* TMR12RST */
#define RCC_APB1RSTR_TIM7RST	(1 << 5)			/* TMR7RST */
#define RCC_APB1RSTR_TIM6RST	(1 << 4)			/* TMR6RST */
#define RCC_APB1RSTR_TIM5RST	(1 << 3)			/* TMR5RST */
#define RCC_APB1RSTR_TIM4RST	(1 << 2)			/* TMR4RST */
#define RCC_APB1RSTR_TIM3RST	(1 << 1)			/* TMR3RST */
#define RCC_APB1RSTR_TIM2RST	(1 << 0)			/* TMR2RST */

/* --- RCC_APB2RSTR (CRM_APB2RST) values ----------------------------------- */
/**/
#define RCC_APB2RSTR_CRSRST	(1 << 29)			/* ACCRST */
/**/
#define RCC_APB2RSTR_TIM20RST	(1 << 20)			/* TMR20RST */
/**/
#define RCC_APB2RSTR_TIM11RST	(1 << 18)			/* TMR11RST */
#define RCC_APB2RSTR_TIM10RST	(1 << 17)			/* TMR10RST */
#define RCC_APB2RSTR_TIM9RST	(1 << 16)			/* TMR9RST */
/**/
#define RCC_APB2RSTR_SYSCFGRST	(1 << 14)			/* SCFGRST */
#define RCC_APB2RSTR_SPI4RST	(1 << 13)			/* SPI4RST */
#define RCC_APB2RSTR_SPI1RST	(1 << 12)			/* SPI1RST */
/**/
#define RCC_APB2RSTR_ADCRST	(1 << 9)			/* ADCRST */
/**/
#define RCC_APB2RSTR_USART6RST	(1 << 5)			/* USART6RST */
#define RCC_APB2RSTR_USART1RST	(1 << 4)			/* USART1RST */
/**/
#define RCC_APB2RSTR_TIM8RST	(1 << 1)			/* TMR8RST */
#define RCC_APB2RSTR_TIM1RST	(1 << 0)			/* TMR1RST */

/* --- RCC_AHB1ENR (CRM_AHBEN1) values --------------------------------------- */
#define RCC_AHB1ENR_OTGFS2EN	(1 << 29)			/* OTGFS2EN */
#define RCC_AHB1ENR_ETHMACPTPEN	(1 << 28)			/* EMACPTPEN */
#define RCC_AHB1ENR_ETHMACRXEN	(1 << 27)			/* EMACRXEN */
#define RCC_AHB1ENR_ETHMACTXEN	(1 << 26)			/* EMACTXEN */
#define RCC_AHB1ENR_ETHMACEN	(1 << 25)			/* EMACEN */
#define RCC_AHB1ENR_DMA2EN	(1 << 24)			/* DMA2EN */
/**/
#define RCC_AHB1ENR_DMA1EN	(1 << 22)			/* DMA1EN */
#define RCC_AHB1ENR_DMA0EN	(1 << 21)			/* EDMAEN */
/**/
#define RCC_AHB1ENR_CRCEN	(1 << 12)			/* CRCEN */
/**/
#define RCC_AHB1ENR_GPIOHEN	(1 << 7)			/* ditto */
#define RCC_AHB1ENR_GPIOGEN	(1 << 6)
#define RCC_AHB1ENR_GPIOFEN	(1 << 5)
#define RCC_AHB1ENR_GPIOEEN	(1 << 4)
#define RCC_AHB1ENR_GPIODEN	(1 << 3)
#define RCC_AHB1ENR_GPIOCEN	(1 << 2)
#define RCC_AHB1ENR_GPIOBEN	(1 << 1)
#define RCC_AHB1ENR_GPIOAEN	(1 << 0)

/* --- RCC_AHB2ENR (CRM_AHBEN2) values ------------------------------------- */
#define RCC_AHB2ENR_SDIO1EN	(1 << 15)			/* SDIO1EN */
#define RCC_AHB2ENR_OTGFS1EN	(1 << 7)			/* OTGFS1EN */
#define RCC_AHB2ENR_DCMIEN	(1 << 0)			/* DVPEN */

/* --- RCC_AHB3ENR (CRM_AHBEN3) values ------------------------------------- */
#define RCC_AHB2ENR_SDIO2EN	(1 << 15)			/* SDIO2EN */
#define RCC_AHB2ENR_QSPI2EN	(1 << 14)			/* QSPI2EN */
/**/
#define RCC_AHB2ENR_QSPI1EN	(1 << 1)			/* QSPI1EN */
#define RCC_AHB2ENR_FSMCEN	(1 << 0)			/* XMCEN */

/* --- RCC_APB1ENR (CRM_APB1EN) values ------------------------------------- */
#define RCC_APB1ENR_UART8EN	(1 << 31)			/* UART8EN */
#define RCC_APB1ENR_UART7EN	(1 << 30)			/* UART7EN */
#define RCC_APB1ENR_DACEN	(1 << 29)			/* DACEN */
#define RCC_APB1ENR_PWREN	(1 << 28)			/* PWCEN */
/**/
#define RCC_APB1ENR_CAN2EN	(1 << 26)			/* CAC2EN */
#define RCC_APB1ENR_CAN1EN	(1 << 25)			/* CAC1EN */
/**/
#define RCC_APB1ENR_I2C3EN	(1 << 23)			/* I2C3EN */
#define RCC_APB1ENR_I2C2EN	(1 << 22)			/* I2C2EN */
#define RCC_APB1ENR_I2C1EN	(1 << 21)			/* I2C1EN */
#define RCC_APB1ENR_UART5EN	(1 << 20)			/* UART5EN */
#define RCC_APB1ENR_UART4EN	(1 << 19)			/* UART4EN */
#define RCC_APB1ENR_USART3EN	(1 << 18)			/* USART3EN */
#define RCC_APB1ENR_USART2EN	(1 << 17)			/* USART2EN */
/**/
#define RCC_APB1ENR_SPI3EN	(1 << 15)			/* SPI3EN */
#define RCC_APB1ENR_SPI2EN	(1 << 14)			/* SPI2EN */
/**/
#define RCC_APB1ENR_WWDGEN	(1 << 11)			/* WWDTEN */
/**/
#define RCC_APB1ENR_TIM14EN	(1 << 8)			/* TMR14EN */
#define RCC_APB1ENR_TIM13EN	(1 << 7)			/* TMR13EN */
#define RCC_APB1ENR_TIM12EN	(1 << 6)			/* TMR12EN */
#define RCC_APB1ENR_TIM7EN	(1 << 5)			/* TMR7EN */
#define RCC_APB1ENR_TIM6EN	(1 << 4)			/* TMR6EN */
#define RCC_APB1ENR_TIM5EN	(1 << 3)			/* TMR5EN */
#define RCC_APB1ENR_TIM4EN	(1 << 2)			/* TMR4EN */
#define RCC_APB1ENR_TIM3EN	(1 << 1)			/* TMR3EN */
#define RCC_APB1ENR_TIM2EN	(1 << 0)			/* TMR2EN */

/* --- RCC_APB2ENR (CRM_APB2EN) values ------------------------------------- */
#define RCC_APB2ENR_CRSEN	(1 << 29)			/* ACCEN */
#define RCC_APB2ENR_TIM20EN	(1 << 20)			/* TMR20EN */
#define RCC_APB2ENR_TIM11EN	(1 << 18)			/* TMR11EN */
#define RCC_APB2ENR_TIM10EN	(1 << 17)			/* TMR10EN */
#define RCC_APB2ENR_TIM9EN	(1 << 16)			/* TMR9EN */
#define RCC_APB2ENR_SYSCFGEN	(1 << 14)			/* SCFGEN */
#define RCC_APB2ENR_SPI4EN	(1 << 13)			/* SPI4EN */
#define RCC_APB2ENR_SPI1EN	(1 << 12)			/* SPI1EN */
/**/
#define RCC_APB2ENR_ADC3EN	(1 << 10)			/* ADC3EN */
#define RCC_APB2ENR_ADC2EN	(1 << 9)			/* ADC2EN */
#define RCC_APB2ENR_ADC1EN	(1 << 8)			/* ADC1EN */
/**/
#define RCC_APB2ENR_USART6EN	(1 << 5)			/* USART6EN */
#define RCC_APB2ENR_USART1EN	(1 << 4)			/* USART1EN */
/**/
#define RCC_APB2ENR_TIM8EN	(1 << 1)			/* TMR8EN */
#define RCC_APB2ENR_TIM1EN	(1 << 0)			/* TMR1EN */

/* --- RCC_AHB1LPENR (CRM_AHBLPEN1) values --------------------------------- */
#define RCC_AHB1LPENR_OTGFS2LPEN	(1 << 29)		/* OTGFS2LPEN*/
#define RCC_AHB1LPENR_ETHMACPTPLPEN	(1 << 28)		/* EMACPTPLEN */
#define RCC_AHB1LPENR_ETHMACRXLPEN	(1 << 27)		/* EMACRXLPEN */
#define RCC_AHB1LPENR_ETHMACTXLPEN	(1 << 26)		/* EMACTXLPEN */
#define RCC_AHB1LPENR_ETHMACLPEN	(1 << 25)		/* EMACLPEN */
#define RCC_AHB1LPENR_DMA2LPEN		(1 << 24)		/* DMA2LPEN */
/**/
#define RCC_AHB1LPENR_DMA1LPEN		(1 << 22)		/* DMA1LPEN */
#define RCC_AHB1LPENR_DMA0LPEN		(1 << 21)		/* EDMALPEN */
/**/
#define RCC_AHB1LPENR_SRAM2LPEN		(1 << 17)		/* SRAM2LPEN */
#define RCC_AHB1LPENR_SRAM1LPEN		(1 << 16)		/* SRAM1LPEN */
#define RCC_AHB1LPENR_FLITFLPEN		(1 << 15)		/* FLASHLPEN */
/**/
#define RCC_AHB1LPENR_CRCLPEN		(1 << 12)		/* CRCLPEN */
/**/
#define RCC_AHB1LPENR_GPIOHLPEN		(1 << 7)		/* GPIOHLPEN */
#define RCC_AHB1LPENR_GPIOGLPEN		(1 << 6)		/* GPIOGLPEN */
#define RCC_AHB1LPENR_GPIOFLPEN		(1 << 5)		/* GPIOFLPEN */
#define RCC_AHB1LPENR_GPIOELPEN		(1 << 4)		/* GPIOELPEN */
#define RCC_AHB1LPENR_GPIODLPEN		(1 << 3)		/* GPIODLPEN */
#define RCC_AHB1LPENR_GPIOCLPEN		(1 << 2)		/* GPIOCLPEN */
#define RCC_AHB1LPENR_GPIOBLPEN		(1 << 1)		/* GPIOBLPEN */
#define RCC_AHB1LPENR_GPIOALPEN		(1 << 0)		/* GPIOALPEN */

/* --- RCC_AHB2LPENR (CRM_AHBLPEN2) values --------------------------------- */
#define RCC_AHB2LPENR_SDIO1LPEN		(1 << 15)		/* SDIO1LPEN */
#define RCC_AHB2LPENR_OTGFS1LPEN	(1 << 7)		/* OTGFS1LPEN */
#define RCC_AHB2LPENR_DCMILPEN		(1 << 0)		/* DVPLPEN */

/* --- RCC_AHB3LPENR (CRM_AHBLPEN3) values --------------------------------- */
#define RCC_AHB3LPENR_SDIO2LPEN		(1 << 15)		/* SDIO2LPEN */
#define RCC_AHB3LPENR_QSPI2LPEN		(1 << 14)		/* QSPI2LPEN */
#define RCC_AHB3LPENR_QSPI1LPEN		(1 << 1)		/* QSPI1LPEN */
#define RCC_AHB3LPENR_FSMCSLPEN		(1 << 0)		/* XMCLPEN */

/* --- RCC_APB1LPENR (CRM_APB1LPEN) values --------------------------------- */
#define RCC_APB1LPENR_UART8EN		(1 << 31)		/* UART8LPEN */
#define RCC_APB1LPENR_UART7EN		(1 << 30)		/* UART7LPEN */
#define RCC_APB1LPENR_DACLPEN		(1 << 29)		/* DACLPEN */
#define RCC_APB1LPENR_PWRLPEN		(1 << 28)		/* PWCLPEN */
/**/
#define RCC_APB1LPENR_CAN2LPEN		(1 << 26)		/* CAN2LPEN */
#define RCC_APB1LPENR_CAN1LPEN		(1 << 25)		/* CAN1LPEN */
/**/
#define RCC_APB1LPENR_I2C3LPEN		(1 << 23)		/* I2C3LPEN */
#define RCC_APB1LPENR_I2C2LPEN		(1 << 22)		/* I2C2LPEN */
#define RCC_APB1LPENR_I2C1LPEN		(1 << 21)		/* I2C1LPEN */
#define RCC_APB1LPENR_UART5LPEN		(1 << 20)		/* UART5LPEN */
#define RCC_APB1LPENR_UART4LPEN		(1 << 19)		/* UART4LPEN */
#define RCC_APB1LPENR_USART3LPEN	(1 << 18)		/* UART3LPEN */
#define RCC_APB1LPENR_USART2LPEN	(1 << 17)		/* UART2LPEN */
/**/
#define RCC_APB1LPENR_SPI3LPEN		(1 << 15)		/* SPI3LPEN */
#define RCC_APB1LPENR_SPI2LPEN		(1 << 14)		/* SPI2LPEN */
/**/
#define RCC_APB1LPENR_WWDGLPEN		(1 << 11)		/* WWDTLPEN */
/**/
#define RCC_APB1LPENR_TIM14LPEN		(1 << 8)		/* TMR14LPEN */
#define RCC_APB1LPENR_TIM13LPEN		(1 << 7)		/* TMR13LPEN */
#define RCC_APB1LPENR_TIM12LPEN		(1 << 6)		/* TMR12LPEN */
#define RCC_APB1LPENR_TIM7LPEN		(1 << 5)		/* TMR7LPEN */
#define RCC_APB1LPENR_TIM6LPEN		(1 << 4)		/* TMR6LPEN */
#define RCC_APB1LPENR_TIM5LPEN		(1 << 3)		/* TMR5LPEN */
#define RCC_APB1LPENR_TIM4LPEN		(1 << 2)		/* TMR4LPEN */
#define RCC_APB1LPENR_TIM3LPEN		(1 << 1)		/* TMR3LPEN */
#define RCC_APB1LPENR_TIM2LPEN		(1 << 0)		/* TMR2LPEN */

/* --- RCC_APB2LPENR (CRM_APB2LPEN) values --------------------------------- */
#define RCC_APB2LPENR_CRSLPEN		(1 << 27)		/* ACCLPEN */
/**/
#define RCC_APB2LPENR_TIM20LPEN		(1 << 20)		/* TMR20LPEN */
/**/
#define RCC_APB2LPENR_TIM11LPEN		(1 << 18)		/* TMR11LPEN */
#define RCC_APB2LPENR_TIM10LPEN		(1 << 17)		/* TMR10LPEN */
#define RCC_APB2LPENR_TIM9LPEN		(1 << 16)		/* TMR9LPEN */
/**/
#define RCC_APB2LPENR_SYSCFGLPEN	(1 << 14)		/* SCFGLPEN */
#define RCC_APB2LPENR_SPI4LPEN		(1 << 13)		/* SPI4LPEN */
#define RCC_APB2LPENR_SPI1LPEN		(1 << 12)		/* SPI1LPEN */
/**/
#define RCC_APB2LPENR_ADC3LPEN		(1 << 10)		/* ADC3LPEN */
#define RCC_APB2LPENR_ADC2LPEN		(1 << 9)		/* ADC2LPEN */
#define RCC_APB2LPENR_ADC1LPEN		(1 << 8)		/* ADC1LPEN */
/**/
#define RCC_APB2LPENR_USART6LPEN	(1 << 5)		/* USART6LPEN */
#define RCC_APB2LPENR_USART1LPEN	(1 << 4)		/* USART1LPEN */
#define RCC_APB2LPENR_TIM8LPEN		(1 << 1)		/* TMR8LPEN */
#define RCC_APB2LPENR_TIM1LPEN		(1 << 0)		/* TMR1LPEN */

/* --- RCC_BDCR (CRM_BPDC) values ------------------------------------------ */
#define RCC_BDCR_BDRST		(1 << 16)			/* BPDRST */
#define RCC_BDCR_RTCEN		(1 << 15)			/* ERTCEN */
/* RCC_BDCR[9:8]: RTCSEL */
#define RCC_BDCR_LSEBYP		(1 << 2)			/* LEXTBYPS */
#define RCC_BDCR_LSERDY		(1 << 1)			/* LEXTSTBL */
#define RCC_BDCR_LSEON		(1 << 0)			/* LEXTEN */

/* --- RCC_CSR (CRM_CTRLSTS) values ---------------------------------------- */
#define RCC_CSR_LPWRRSTF	(1 << 31)			/* LPRSTF */
#define RCC_CSR_WWDGRSTF	(1 << 30)			/* WWDTRSTF */
#define RCC_CSR_IWDGRSTF	(1 << 29)			/* WDTRSTF */
#define RCC_CSR_SFTRSTF		(1 << 28)			/* SWRSTF */
#define RCC_CSR_PORRSTF		(1 << 27)			/* PORRSTF */
#define RCC_CSR_PINRSTF		(1 << 26)			/* NRSTF */
#define RCC_CSR_RMVF		(1 << 24)			/* RSTFC */
#define RCC_CSR_LSIRDY		(1 << 1)			/* LICKSTBL */
#define RCC_CSR_LSION		(1 << 0)			/* LICKEN */

#define RCC_CSR_RESET_FLAGS	(RCC_CSR_LPWRRSTF | RCC_CSR_WWDGRSTF |\
				 RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF  |\
				 RCC_CSR_PORRSTF  | RCC_CSR_PINRSTF)

/* --- RCC_CFGR3 (CRM_MISC1) values ---------------------------------------- */
/* MCO2_DIV [31:28] */
/* MCO1_DIV [27:24] */
/* MCO2_MUX [19:16] */
#define RCC_CFGR3_HSI_SCLK	(1 << 14)			/* HICK_TO_SCLK */
#define RCC_CFGR3_HSI_USB_SRC	(1 << 13)			/* HICK_TO_USB */
#define RCC_CFGR3_HSIDIV	(1 << 12)			/* HICKDIV */
/* HSICAL   [ 7: 0] */

#define RCC_CFGR3_MCO2_DIV_SHIFT	28
#define RCC_CFGR3_MCO2_DIV		(0xf << RCC_CFGR3_MCO2_DIV_SHIFT)
#define RCC_CFGR3_MCO1_DIV_SHIFT	24
#define RCC_CFGR3_MCO1_DIV		(0xf << RCC_CFGR3_MCO1_DIV_SHIFT)

#define RCC_CFGR3_MCO_DIV1		0
#define RCC_CFGR3_MCO_DIV2		8
#define RCC_CFGR3_MCO_DIV4		9
#define RCC_CFGR3_MCO_DIV8		10
#define RCC_CFGR3_MCO_DIV16		11
#define RCC_CFGR3_MCO_DIV64		12
#define RCC_CFGR3_MCO_DIV128		13
#define RCC_CFGR3_MCO_DIV256		14
#define RCC_CFGR3_MCO_DIV512		15

#define RCC_CFGR3_MCO2_MUX_USB		0
#define RCC_CFGR3_MCO2_MUX_ADC		1
#define RCC_CFGR3_MCO2_MUX_HSI		2
#define RCC_CFGR3_MCO2_MUX_LSI		3
#define RCC_CFGR3_MCO2_MUX_LSE		4

#define RCC_CFGR3_MCO2_MUX_SHIFT	16
#define RCC_CFGR3_MCO2_MUX		(0xf << RCC_CFGR3_MCO2_SEL_SHIFT)

#define RCC_CFGR3_HSIDIV_DIV6	0
#define RCC_CFGR3_HSIDIV_NODIV	1

/* --- RCC_CFGR4 (CRM_MISC2) values ---------------------------------------- */
/* USBPRE   [15:12] */
#define RCC_CFGR4_MAC_PPS_SEL	(1 << 9)			/* EMAC_PPS_SEL */
#define RCC_CFGR4_MCO1_TIM10	(1 << 8)			/* CLK1_TO_TMR */
/* AUTO_STEP_EN [5:4] */

#define RCC_CFGR4_USBPRE_PLL_CLK_DIV1_5		0x0
#define RCC_CFGR4_USBPRE_PLL_CLKNODIV		0x1
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV2_5		0x2
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV2		0x3
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV3_5		0x4
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV3		0x5
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV4_5		0x6
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV4		0x7
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV5_5		0x8
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV5		0x9
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV6_5		0xa
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV6		0xb
#define RCC_CFGR4_USBPRE_PLL_CLK_DIV7		0xc

#define RCC_CFGR4_USBPRE_SHIFT			12
#define RCC_CFGR4_USBPRE			(0xf << RCC_CFGR4_USBPRE_SHIFT)

#define RCC_CFGR4_AUTO_STEP_DIS		0
#define RCC_CFGR4_AUTO_STEP_EN		3
#define RCC_CFGR4_AUTO_STEP_SHIFT	4
#define RCC_CFGR4_AUTO_STEP_MASK	3

/* --- Variable definitions ------------------------------------------------ */
extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

/* --- Function prototypes ------------------------------------------------- */

enum rcc_osc {
	RCC_PLL, RCC_HSE, RCC_HSI, RCC_LSE, RCC_LSI
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
	RCC_CRC		= _REG_BIT(0x30, 12),
	RCC_DMA0	= _REG_BIT(0x30, 21),
	RCC_DMA1	= _REG_BIT(0x30, 22),
	RCC_DMA2	= _REG_BIT(0x30, 24),
	RCC_ETHMAC	= _REG_BIT(0x30, 25),
	RCC_ETHMACTX	= _REG_BIT(0x30, 26),
	RCC_ETHMACRX	= _REG_BIT(0x30, 27),
	RCC_ETHMACPTP	= _REG_BIT(0x30, 28),
	RCC_OTGFS2	= _REG_BIT(0x30, 29),

	/* AHB2 peripherals */
	RCC_DCMI	= _REG_BIT(0x34, 0),
	RCC_OTGFS1	= _REG_BIT(0x34, 7),
	RCC_SDIO1	= _REG_BIT(0x34, 15),

	/* AHB3 peripherals */
	RCC_FSMC	= _REG_BIT(0x38, 0),
	RCC_QSPI1	= _REG_BIT(0x38, 1),
	RCC_QSPI2	= _REG_BIT(0x38, 14),
	RCC_SDIO2	= _REG_BIT(0x38, 15),

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
	RCC_UART7	= _REG_BIT(0x40, 30),
	RCC_UART8	= _REG_BIT(0x40, 31),

	/* APB2 peripherals */
	RCC_TIM1	= _REG_BIT(0x44, 0),
	RCC_TIM8	= _REG_BIT(0x44, 1),
	RCC_USART1	= _REG_BIT(0x44, 4),
	RCC_USART6	= _REG_BIT(0x44, 5),
	RCC_ADC1	= _REG_BIT(0x44, 8),
	RCC_ADC2	= _REG_BIT(0x44, 9),
	RCC_ADC3	= _REG_BIT(0x44, 10),
	RCC_SPI1	= _REG_BIT(0x44, 12),
	RCC_SPI4	= _REG_BIT(0x44, 13),
	RCC_SYSCFG	= _REG_BIT(0x44, 14),
	RCC_TIM9	= _REG_BIT(0x44, 16),
	RCC_TIM10	= _REG_BIT(0x44, 17),
	RCC_TIM11	= _REG_BIT(0x44, 18),
	RCC_TIM20	= _REG_BIT(0x44, 20),
	RCC_CRS		= _REG_BIT(0x44, 29),

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
	SCC_CRC		= _REG_BIT(0x50, 12),
	SCC_FLTIF	= _REG_BIT(0x50, 15),
	SCC_SRAM1	= _REG_BIT(0x50, 16),
	SCC_SRAM2	= _REG_BIT(0x50, 17),
	SCC_DMA0	= _REG_BIT(0x50, 21),
	SCC_DMA1	= _REG_BIT(0x50, 22),
	SCC_DMA2	= _REG_BIT(0x50, 24),
	SCC_ETHMAC	= _REG_BIT(0x50, 25),
	SCC_ETHMACTX	= _REG_BIT(0x50, 26),
	SCC_ETHMACRX	= _REG_BIT(0x50, 27),
	SCC_ETHMACPTP	= _REG_BIT(0x50, 28),
	SCC_OTGHS	= _REG_BIT(0x50, 29),

	/* AHB2 peripherals */
	SCC_DCMI	= _REG_BIT(0x54, 0),
	SCC_OTGFS1	= _REG_BIT(0x54, 7),
	SCC_SDIO1	= _REG_BIT(0x54, 15),

	/* AHB3 peripherals */
	SCC_SDIO2	= _REG_BIT(0x58, 15),
	SCC_QSPI2	= _REG_BIT(0x58, 14),
	SCC_QSPI1	= _REG_BIT(0x58, 1),
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
	SCC_SPI1	= _REG_BIT(0x64, 12),
	SCC_SPI4	= _REG_BIT(0x64, 13),
	SCC_SYSCFG	= _REG_BIT(0x64, 14),
	SCC_TIM9	= _REG_BIT(0x64, 16),
	SCC_TIM10	= _REG_BIT(0x64, 17),
	SCC_TIM11	= _REG_BIT(0x64, 18),
	SCC_TIM20	= _REG_BIT(0x64, 20),
	SCC_CRS		= _REG_BIT(0x64, 27),
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
	RST_CRC		= _REG_BIT(0x10, 12),
	RST_DMA0	= _REG_BIT(0x10, 21),
	RST_DMA1	= _REG_BIT(0x10, 22),
	RST_DMA2	= _REG_BIT(0x10, 24),
	RST_ETHMAC	= _REG_BIT(0x10, 25),
	RST_OTGFS2	= _REG_BIT(0x10, 29),

	/* AHB2 peripherals */
	RST_DCMI	= _REG_BIT(0x14, 0),
	RST_OTGFS	= _REG_BIT(0x14, 7),
	RST_SDIO1	= _REG_BIT(0x14, 15),

	/* AHB3 peripherals */
	RST_FSMC	= _REG_BIT(0x18, 0),
	RST_QSPI1	= _REG_BIT(0x18, 1),
	RST_QSPI2	= _REG_BIT(0x18, 14),
	RST_SDIO2	= _REG_BIT(0x18, 15),

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
	RST_UART7	= _REG_BIT(0x20, 30),

	/* APB2 peripherals */
	RST_TIM1	= _REG_BIT(0x24, 0),
	RST_TIM8	= _REG_BIT(0x24, 1),
	RST_USART1	= _REG_BIT(0x24, 4),
	RST_USART6	= _REG_BIT(0x24, 5),
	RST_ADC		= _REG_BIT(0x24, 8),
	RST_SPI1	= _REG_BIT(0x24, 12),
	RST_SPI4	= _REG_BIT(0x24, 13),
	RST_SYSCFG	= _REG_BIT(0x24, 14),
	RST_TIM9	= _REG_BIT(0x24, 16),
	RST_TIM10	= _REG_BIT(0x24, 17),
	RST_TIM11	= _REG_BIT(0x24, 18),
	RST_TIM20	= _REG_BIT(0x24, 20),
	RST_CRS		= _REG_BIT(0x24, 29),

	/* Backup domain control */
	RST_BDCR	= _REG_BIT(0x70, 16),
};

#include <libopencm3/stm32/common/rcc_common_all.h>

enum rcc_clock_hsi {
	RCC_CLOCK_HSI_84MHZ,
	RCC_CLOCK_HSI_96MHZ,
	RCC_CLOCK_HSI_168MHZ,
	RCC_CLOCK_HSI_192MHZ,
	RCC_CLOCK_HSI_END
};

enum rcc_clock_hse {
	RCC_CLOCK_HSE_84MHZ,
	RCC_CLOCK_HSE_96MHZ,
	RCC_CLOCK_HSE_168MHZ,
	RCC_CLOCK_HSE_192MHZ,
	RCC_CLOCK_HSE_240MHZ,
	RCC_CLOCK_HSE_288MHZ,
	RCC_CLOCK_HSE_END
};

enum rcc_mco { MCO1, MCO2 };

struct rcc_clock_scale {
	uint8_t pllm;
	uint16_t plln;
	uint8_t pllp;
	uint8_t pll_source;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	enum pwr_vos_scale voltage_scale;
	uint32_t ahb_frequency;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END];
extern const struct rcc_clock_scale rcc_hse_configs[RCC_CLOCK_HSE_END];

BEGIN_DECLS

int  rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);

int  rcc_css_int_flag(void);
void rcc_css_int_clear(void);
void rcc_css_enable(void);
void rcc_css_disable(void);

void rcc_set_sysclk_source(uint32_t clk);
void rcc_wait_for_sysclk_status(enum rcc_osc osc);

void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_pll_fract(uint32_t pllm, uint32_t plln, uint32_t pllp);

void rcc_set_rtc_clock_source(enum rcc_osc clock_source);
void rcc_set_rtcpre(uint32_t rtcpre);
void rcc_enable_rtc_clock(void);
uint32_t rcc_rtc_clock_enabled_flag(void);

void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);

void rcc_set_hsi_div(uint32_t hsidiv);
void rcc_set_hsi_sclk(uint32_t hsisclk);

void rcc_set_usb_clock_source(enum rcc_osc osc);
void rcc_set_usbpre(uint32_t usbpre);

void rcc_set_mco_source(enum rcc_mco mco, uint32_t mcosrc);
void rcc_set_mcopre(enum rcc_mco mco, uint32_t mcopre);
void rcc_set_mcodiv(enum rcc_mco mco, uint32_t mcodiv);

uint32_t rcc_system_clock_source(void);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);

void rcc_backupdomain_reset(void);

uint32_t rcc_get_usart_clk_freq(uint32_t usart);
uint32_t rcc_get_timer_clk_freq(uint32_t timer);
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c);
uint32_t rcc_get_spi_clk_freq(uint32_t spi);

END_DECLS

#endif
/**@}*/
