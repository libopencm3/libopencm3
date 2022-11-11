/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the AT32F40x Reset and Clock
 * Control</b>
 *
 * @ingroup AT32F40x_defines
 *
 * @version 1.0.0
 *
 * @date 10 November 2022
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

/* --- RCC registers ------------------------------------------------------- */

#define RCC_CR			MMIO32(RCC_BASE + 0x00)		/* CRM_CTRL */
#define RCC_CFGR		MMIO32(RCC_BASE + 0x04)		/* CRM_CFG */
#define RCC_CIR			MMIO32(RCC_BASE + 0x08)		/* CRM_CLKINT */
#define RCC_APB2RSTR		MMIO32(RCC_BASE + 0x0c)		/* CRM_APB2RST */
#define RCC_APB1RSTR		MMIO32(RCC_BASE + 0x10)		/* CRM_APB1RST */
#define RCC_AHBENR		MMIO32(RCC_BASE + 0x14)		/* CRM_AHBEN */
#define RCC_APB2ENR		MMIO32(RCC_BASE + 0x18)		/* CRM_APB2EN */
#define RCC_APB1ENR		MMIO32(RCC_BASE + 0x1c)		/* CRM_APB1EN */
#define RCC_BDCR		MMIO32(RCC_BASE + 0x20)		/* CRM_BPDC */
#define RCC_CSR			MMIO32(RCC_BASE + 0x24)		/* CRM_CRLSTS */
#define RCC_AHBRSTR		MMIO32(RCC_BASE + 0x28)		/* CRM_AHBRST */
#define RCC_CFGR3		MMIO32(RCC_BASE + 0x30)		/* CRM_MISC1 */
#define RCC_CFGR4		MMIO32(RCC_BASE + 0x50)		/* CRM_MISC2 */
#define RCC_CFGR5		MMIO32(RCC_BASE + 0x54)		/* CRM_MISC3 */
#define RCC_CFGR6		MMIO32(RCC_BASE + 0x5c)		/* CRM_INTMAP */

/* --- RCC_CR (CRM_CTRL) values -------------------------------------------- */

#define RCC_CR_PLLRDY		(1 << 25)			/* PLLSTBL */
#define RCC_CR_PLLON		(1 << 24)			/* PLLEN */
#define RCC_CR_CSSON		(1 << 19)			/* CFDEN */
#define RCC_CR_HSEBYP		(1 << 18)			/* HEXTBYPS */
#define RCC_CR_HSERDY		(1 << 17)			/* HEXTSTBL */
#define RCC_CR_HSEON		(1 << 16)			/* HEXTEN */
/* HSICAL: [15:8] */
/* HSITRIM: [7:3] */
#define RCC_CR_HSIRDY		(1 << 1)			/* HICKSTBL */
#define RCC_CR_HSION		(1 << 0)			/* HICKEN */

/* --- RCC_CFGR (CRM_CFG) values ------------------------------------------- */

#define RCC_CFGR_PLLRANGE	(1 << 31)			/* PLLRANGE */
/* PLLMUL [30:29] */
#define RCC_CFGR_ADCPRE2	(1 << 28)			/* ADCDIV[2] */
#define RCC_CFGR_USBPRE2	(1 << 27)			/* USBDIV[2] */
/* MCO    [26:24] */
/* USBPRE [23:22] */

#define RCC_CFGR_USBPRE_SHIFT	22
#define RCC_CFGR_USBPRE		(3 << RCC_CFGR_USBPRE_SHIFT)	/* USBDIV[0:1] */

#define RCC_CFGR_PLLMULHI_SHIFT	29				/* PLLMULT[5:4] */
#define RCC_CFGR_PLLMUL_SHIFT	18
#define RCC_CFGR_PLLMUL		((7 << RCC_CFGR_PLLMULHI_SHIFT) | \
				(0xF << RCC_CFGR_PLLMUL_SHIFT))

#define RCC_CFGR_PLLXTPRE	(1 << 17)			/* PLLHEXTDIV */
#define RCC_CFGR_PLLSRC		(1 << 16)			/* PLLRCS */

#define RCC_CFGR_ADCPRE_SHIFT	14
#define RCC_CFGR_ADCPRE		(3 << RCC_CFGR_ADCPRE_SHIFT)	/* ADCDIV[0:1] */

#define RCC_CFGR_PPRE2_SHIFT	11
#define RCC_CFGR_PPRE2		(7 << RCC_CFGR_PPRE2_SHIFT)	/* APB2DIV[0:2] */

#define RCC_CFGR_PPRE1_SHIFT	8
#define RCC_CFGR_PPRE1		(7 << RCC_CFGR_PPRE1_SHIFT)	/* APB1DIV[0:2] */

#define RCC_CFGR_HPRE_SHIFT	4
#define RCC_CFGR_HPRE		(0xF << RCC_CFGR_HPRE_SHIFT)	/* AHBDIV[0:3] */

#define RCC_CFGR_SWS_SHIFT	2
#define RCC_CFGR_SWS		(3 << RCC_CFGR_SWS_SHIFT)	/* CLKSTS[0:1] */

#define RCC_CFGR_SW_SHIFT	0
#define RCC_CFGR_SW		(3 << RCC_CFGR_SW_SHIFT)	/* CLKSEL[0:1] */

/* MCO: Microcontroller clock output */
/** @defgroup rcc_cfgr_co RCC_CFGR Microcontroller Clock Output Source
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR_MCO_NOCLK	0x0
#define RCC_CFGR_MCO_LSI	0x2
#define RCC_CFGR_MCO_LSE	0x3
#define RCC_CFGR_MCO_SYSCLK	0x4
#define RCC_CFGR_MCO_HSI	0x5
#define RCC_CFGR_MCO_HSE	0x6
#define RCC_CFGR_MCO_PLL_DIV2	0x7
#define RCC_CFGR_MCO_PLL_DIV4	0xc
#define RCC_CFGR_MCO_USB	0xd
#define RCC_CFGR_MCO_ADC	0xe

#define RCC_CFGR_MCO_SHIFT	24
#define RCC_CFGR_MCO_MASK	7
/**@}*/

/* USBPRE: USB prescaler */
/** @defgroup rcc_cfgr_usbpre RCC_CFGR USB prescale Factors
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR_USBPRE_PLL_CLK_DIV1_5		0x0
#define RCC_CFGR_USBPRE_PLL_CLK_NODIV		0x1
#define RCC_CFGR_USBPRE_PLL_CLK_DIV2_5		0x2
#define RCC_CFGR_USBPRE_PLL_CLK_DIV2		0x3
#define RCC_CFGR_USBPRE_PLL_CLK_DIV3_5		0x4
#define RCC_CFGR_USBPRE_PLL_CLK_DIV3		0x5
#define RCC_CFGR_USBPRE_PLL_CLK_DIV4_5		0x6		/* DIV4 ? */
#define RCC_CFGR_USBPRE_PLL_CLK_DIV4		0x7
/**@}*/

/* PLLMUL: PLL multiplication factor */
/** @defgroup rcc_cfgr_pmf RCC_CFGR PLL Multiplication Factor
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL2		0x0
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL3		0x1
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL4		0x2
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL5		0x3
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL6		0x4
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL7		0x5
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL8		0x6
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL9		0x7
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL10		0x8
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL11		0x9
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL12		0xa
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL13		0xb
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL14		0xc
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL15		0xd
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

#define RCC_CFGR_PLLMUL_PLL_CLK_MUL33		0x20
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL34		0x21
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL35		0x22
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL36		0x23
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL37		0x24
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL38		0x25
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL39		0x26
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL40		0x27
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL41		0x28
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL42		0x29
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL43		0x2a
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL44		0x2b
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL45		0x2c
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL46		0x2d
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL47		0x2e
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL48		0x2f

#define RCC_CFGR_PLLMUL_PLL_CLK_MUL49		0x30
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL50		0x31
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL51		0x32
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL52		0x33
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL53		0x34
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL54		0x35
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL55		0x36
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL56		0x37
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL57		0x38
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL58		0x39
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL59		0x3a
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL60		0x3b
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL61		0x3c
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL62		0x3d
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL63		0x3e
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL64		0x3f

#define RCC_CFGR_PLLRANGE_HIGH			0x40

/**@}*/

/* PLLXTPRE: HSE divider for PLL entry */
/** @defgroup rcc_cfgr_hsepre RCC_CFGR HSE Divider for PLL
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR_PLLXTPRE_HSE_CLK		0x0
#define RCC_CFGR_PLLXTPRE_HSE_CLK_PREDIV	0x1
/**@}*/

/* PLLSRC: PLL entry clock source */
/** @defgroup rcc_cfgr_pcs RCC_CFGR PLL Clock Source
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR_PLLSRC_HSI_CLK_DIV2		0x0
#define RCC_CFGR_PLLSRC_HSE_CLK			0x1
/**@}*/

/* ADCPRE: ADC prescaler */
/****************************************************************************/
/** @defgroup rcc_cfgr_adcpre RCC ADC clock prescaler enable values
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR_ADCPRE_DIV2			0x0
#define RCC_CFGR_ADCPRE_DIV4			0x1
#define RCC_CFGR_ADCPRE_DIV6			0x2
#define RCC_CFGR_ADCPRE_DIV8			0x3
#define RCC_CFGR_ADCPRE_DIV12			0x5
#define RCC_CFGR_ADCPRE_DIV16			0x7
/**@}*/

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
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR_HPRE_NODIV			0x0
#define RCC_CFGR_HPRE_DIV2			0x8
#define RCC_CFGR_HPRE_DIV4			0x9
#define RCC_CFGR_HPRE_DIV8			0xa
#define RCC_CFGR_HPRE_DIV16			0xb
#define RCC_CFGR_HPRE_DIV64			0xc
#define RCC_CFGR_HPRE_DIV128			0xd
#define RCC_CFGR_HPRE_DIV256			0xe
#define RCC_CFGR_HPRE_DIV512			0xf
/**@}*/

/* SWS: System clock switch status */
#define RCC_CFGR_SWS_SYSCLKSEL_HSICLK		0x0
#define RCC_CFGR_SWS_SYSCLKSEL_HSECLK		0x1
#define RCC_CFGR_SWS_SYSCLKSEL_PLLCLK		0x2

/* SW: System clock switch */
/** @defgroup rcc_cfgr_scs RCC_CFGR System Clock Selection
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR_SW_SYSCLKSEL_HSICLK		0x0
#define RCC_CFGR_SW_SYSCLKSEL_HSECLK		0x1
#define RCC_CFGR_SW_SYSCLKSEL_PLLCLK		0x2
/**@}*/

/* --- RCC_CIR (CRM_CLKINT) values ----------------------------------------- */

/* Clock security system interrupt clear bit */
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

/* --- RCC_APB2RSTR (CRM_APB2RST) values ----------------------------------- */

/** @defgroup rcc_apb2rstr_rst RCC_APB2RSTR reset values
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_APB2RSTR_UART8RST	(1 << 26)			/* UART8RST */
#define RCC_APB2RSTR_UART7RST	(1 << 25)			/* UART7RST */
#define RCC_APB2RSTR_UART6RST	(1 << 24)			/* UART6RST */
#define RCC_APB2RSTR_I2C3RST	(1 << 23)			/* I2C3RST */
#define RCC_APB2RSTR_CRSRST	(1 << 22)			/* ACCRST */
#define RCC_APB2RSTR_TIM11RST	(1 << 21)			/* TMR11RST */
#define RCC_APB2RSTR_TIM10RST	(1 << 20)			/* TMR10RST */
#define RCC_APB2RSTR_TIM9RST	(1 << 19)			/* TMR9RST */
#define RCC_APB2RSTR_ADC3RST	(1 << 15)			/* ADC3RST */
#define RCC_APB2RSTR_USART1RST	(1 << 14)			/* USART1RST */
#define RCC_APB2RSTR_TIM8RST	(1 << 13)			/* TMR8RST */
#define RCC_APB2RSTR_SPI1RST	(1 << 12)			/* SPI1RST */
#define RCC_APB2RSTR_TIM1RST	(1 << 11)			/* TMR1RST */
#define RCC_APB2RSTR_ADC2RST	(1 << 10)			/* ADC2RST */
#define RCC_APB2RSTR_ADC1RST	(1 << 9)			/* ADC1RST */
#define RCC_APB2RSTR_IOPERST	(1 << 6)			/* GPIOERST */
#define RCC_APB2RSTR_IOPDRST	(1 << 5)			/* GPIODRST */
#define RCC_APB2RSTR_IOPCRST	(1 << 4)			/* GPIOCRST */
#define RCC_APB2RSTR_IOPBRST	(1 << 3)			/* GPIOBRST */
#define RCC_APB2RSTR_IOPARST	(1 << 2)			/* GPIOARST */
#define RCC_APB2RSTR_EXTIRST	(1 << 1)			/* EXINTRST */
#define RCC_APB2RSTR_AFIORST	(1 << 0)			/* IOMUXRST */
/**@}*/

/* --- RCC_APB1RSTR (CRM_APB1RST) values ----------------------------------- */

/** @defgroup rcc_apb1rstr_rst RCC_APB1RSTR reset values
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_APB1RSTR_DACRST	(1 << 29)			/* DACRST */
#define RCC_APB1RSTR_PWRRST	(1 << 28)			/* PWCRST */
#define RCC_APB1RSTR_BKPRST	(1 << 27)			/* BPRRST */
#define RCC_APB1RSTR_CAN2RST	(1 << 26)			/* CAN2RST */
#define RCC_APB1RSTR_CAN1RST	(1 << 25)			/* CAN1RST */
#define RCC_APB1RSTR_CANRST	(1 << 25)
#define RCC_APB1RSTR_USBRST	(1 << 23)			/* USBRST */
#define RCC_APB1RSTR_I2C2RST	(1 << 22)			/* I2C2RST */
#define RCC_APB1RSTR_I2C1RST	(1 << 21)			/* I2C1RST */
#define RCC_APB1RSTR_UART5RST	(1 << 20)			/* UART5RST */
#define RCC_APB1RSTR_UART4RST	(1 << 19)			/* UART4RST */
#define RCC_APB1RSTR_USART3RST	(1 << 18)			/* USART3RST */
#define RCC_APB1RSTR_USART2RST	(1 << 17)			/* USART2RST */
#define RCC_APB1RSTR_SPI4RST	(1 << 16)			/* SPI4RST */
#define RCC_APB1RSTR_SPI3RST	(1 << 15)			/* SPI3RST */
#define RCC_APB1RSTR_SPI2RST	(1 << 14)			/* SPI2RST */
#define RCC_APB1RSTR_WWDGRST	(1 << 11)			/* WWDTRST */
#define RCC_APB1RSTR_TIM14RST	(1 << 8)			/* TMR14RST */
#define RCC_APB1RSTR_TIM13RST	(1 << 7)			/* TMR13RST */
#define RCC_APB1RSTR_TIM12RST	(1 << 6)			/* TMR12RST */
#define RCC_APB1RSTR_TIM7RST	(1 << 5)			/* TMR7RST */
#define RCC_APB1RSTR_TIM6RST	(1 << 4)			/* TMR6RST */
#define RCC_APB1RSTR_TIM5RST	(1 << 3)			/* TMR5RST */
#define RCC_APB1RSTR_TIM4RST	(1 << 2)			/* TMR4RST */
#define RCC_APB1RSTR_TIM3RST	(1 << 1)			/* TMR3RST */
#define RCC_APB1RSTR_TIM2RST	(1 << 0)			/* TMR2RST */
/**@}*/

/* --- RCC_AHBENR (CRM_AHBEN) values --------------------------------------- */

/** @defgroup rcc_ahbenr_en RCC_AHBENR enable values
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_AHBENR_ETHMACENPTP	(1 << 28)			/* EMACPTPEN */
#define RCC_AHBENR_ETHMACENRX	(1 << 16)			/* EMACRXEN */
#define RCC_AHBENR_ETHMACENTX	(1 << 15)			/* EMACTXEN */
#define RCC_AHBENR_ETHMACEN	(1 << 14)			/* EMACEN */
#define RCC_AHBENR_SDIO2EN	(1 << 11)			/* SDIO2EN */
#define RCC_AHBENR_SDIO1EN	(1 << 10)			/* SDIO1EN */
#define RCC_AHBENR_SDIOEN	(1 << 10)
#define RCC_AHBENR_FSMCEN	(1 << 8)			/* XMCEN */
#define RCC_AHBENR_CRCEN	(1 << 6)			/* CRCEN */
#define RCC_AHBENR_FLITFEN	(1 << 4)			/* FLASHEN */
#define RCC_AHBENR_SRAMEN	(1 << 2)			/* SRAMEN */
#define RCC_AHBENR_DMA2EN	(1 << 1)			/* DMA2EN */
#define RCC_AHBENR_DMA1EN	(1 << 0)			/* DMA1EN */
/**@}*/

/* --- RCC_APB2ENR (CRM_AHB2EN) values ------------------------------------- */

/** @defgroup rcc_apb2enr_en RCC_APB2ENR enable values
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_APB2ENR_UART8EN	(1 << 26)			/* UART8EN */
#define RCC_APB2ENR_UART7EN	(1 << 25)			/* UART7EN */
#define RCC_APB2ENR_USART6EN	(1 << 24)			/* USART6EN */
#define RCC_APB2ENR_I2C3EN	(1 << 23)			/* I2C3EN */
#define RCC_APB2ENR_CRSEN	(1 << 22)			/* ACCEN */
#define RCC_APB2ENR_TIM11EN	(1 << 21)			/* TMR11EN */
#define RCC_APB2ENR_TIM10EN	(1 << 20)			/* TMR10EN */
#define RCC_APB2ENR_TIM9EN	(1 << 19)			/* TMR9EN */
#define RCC_APB2ENR_ADC3EN	(1 << 15)			/* ADC3EN */
#define RCC_APB2ENR_USART1EN	(1 << 14)			/* USART1EN */
#define RCC_APB2ENR_TIM8EN	(1 << 13)			/* TMR8EN */
#define RCC_APB2ENR_SPI1EN	(1 << 12)			/* SPI1EN */
#define RCC_APB2ENR_TIM1EN	(1 << 11)			/* TMR1EN */
#define RCC_APB2ENR_ADC2EN	(1 << 10)			/* ADC2EN */
#define RCC_APB2ENR_ADC1EN	(1 << 9)			/* ADC1EN */
#define RCC_APB2ENR_IOPEEN	(1 << 6)			/* GPIOEEN */
#define RCC_APB2ENR_IOPDEN	(1 << 5)			/* GPIODEN */
#define RCC_APB2ENR_IOPCEN	(1 << 4)			/* GPIOCEN */
#define RCC_APB2ENR_IOPBEN	(1 << 3)			/* GPIOBEN */
#define RCC_APB2ENR_IOPAEN	(1 << 2)			/* GPIOAEN */
#define RCC_APB2ENR_AFIOEN	(1 << 0)			/* IOMUXEN */
/**@}*/

/* --- RCC_APB1ENR (CRM_AHB1EN) values ------------------------------------- */

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_APB1ENR_DACEN	(1 << 29)			/* DACEN */
#define RCC_APB1ENR_PWREN	(1 << 28)			/* PWCEN */
#define RCC_APB1ENR_BKPEN	(1 << 27)			/* BPREN */
#define RCC_APB1ENR_CAN2EN	(1 << 26)			/* CAN2EN */
#define RCC_APB1ENR_CAN1EN	(1 << 25)			/* CAN1EN */
#define RCC_APB1ENR_CANEN	(1 << 25)
#define RCC_APB1ENR_USBEN	(1 << 23)			/* USBEN */
#define RCC_APB1ENR_I2C2EN	(1 << 22)			/* I2C2EN */
#define RCC_APB1ENR_I2C1EN	(1 << 21)			/* I2C1EN */
#define RCC_APB1ENR_UART5EN	(1 << 20)			/* UART5EN */
#define RCC_APB1ENR_UART4EN	(1 << 19)			/* UART4EN */
#define RCC_APB1ENR_USART3EN	(1 << 18)			/* USART3EN */
#define RCC_APB1ENR_USART2EN	(1 << 17)			/* USART2EN */
#define RCC_APB1ENR_SPI4EN	(1 << 16)			/* SPI4EN */
#define RCC_APB1ENR_SPI3EN	(1 << 15)			/* SPI3EN */
#define RCC_APB1ENR_SPI2EN	(1 << 14)			/* SPI2EN */
#define RCC_APB1ENR_WWDGEN	(1 << 11)			/* WWDTEN */
#define RCC_APB1ENR_TIM14EN	(1 << 8)			/* TMR14EN */
#define RCC_APB1ENR_TIM13EN	(1 << 7)			/* TMR13EN */
#define RCC_APB1ENR_TIM12EN	(1 << 6)			/* TMR12EN */
#define RCC_APB1ENR_TIM7EN	(1 << 5)			/* TMR7EN */
#define RCC_APB1ENR_TIM6EN	(1 << 4)			/* TMR6EN */
#define RCC_APB1ENR_TIM5EN	(1 << 3)			/* TMR5EN */
#define RCC_APB1ENR_TIM4EN	(1 << 2)			/* TMR4EN */
#define RCC_APB1ENR_TIM3EN	(1 << 1)			/* TMR3EN */
#define RCC_APB1ENR_TIM2EN	(1 << 0)			/* TMR2EN */
/**@}*/

/* --- RCC_BDCR (CRM_BPDC) values ------------------------------------------ */

#define RCC_BDCR_BDRST		(1 << 16)			/* BPDRST */
#define RCC_BDCR_RTCEN		(1 << 15)			/* RTCEN */
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
#define RCC_CSR_RESET_FLAGS	(RCC_CSR_LPWRRSTF | RCC_CSR_WWDGRSTF |\
		RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF | RCC_CSR_PORRSTF |\
		RCC_CSR_PINRSTF)
#define RCC_CSR_LSIRDY		(1 << 1)			/* LICKSTBL */
#define RCC_CSR_LSION		(1 << 0)			/* LICKEN */

/* --- RCC_AHBRSTR (CRM_AHBRST) values ------------------------------------- */

/** @defgroup rcc_ahbrstr_rst RCC_AHBRSTR reset values
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_AHBRSTR_ETHMACRST	(1 << 14)			/* EMACRST */
/**@}*/

/* --- RCC_CFGR3 (CRM_MISC1) values ---------------------------------------- */
/* MCO_DIV [31:28] */
#define RCC_CFGR3_HSIDIV	(1 << 25)			/* HICKDIV */
#define RCC_CFGR3_USBBUFSZ	(1 << 24)			/* USBBUFS */
#define RCC_CFGR3_MCO3		(1 << 16)			/* CLKOUT_SEL[3] */

/* HSIDIV: HSI divider */
/** @defgroup rcc_cfgr3_hsidiv RCC_CFGR3 HSI Divider
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR3_HSIDIV_DIV6	0
#define RCC_CFGR3_HSIDIV_NODIV	1
/**@}*/

#define RCC_CFGR3_MCO_DIV1	0x0
#define RCC_CFGR3_MCO_DIV2	0x8
#define RCC_CFGR3_MCO_DIV4	0x9
#define RCC_CFGR3_MCO_DIV8	0xa
#define RCC_CFGR3_MCO_DIV16	0xb
#define RCC_CFGR3_MCO_DIV64	0xc
#define RCC_CFGR3_MCO_DIV128	0xd
#define RCC_CFGR3_MCO_DIV256	0xe
#define RCC_CFGR3_MCO_DIV512	0xf
#define RCC_CFGR3_MCO_DIV_SHIFT	28
#define RCC_CFGR3_MCO_DIV	(0xF << RCC_CFGR3_MCO_DIV_SHIFT)

/* --- RCC_CFGR4 (CRM_MISC2) values ---------------------------------------- */
#define RCC_CFGR4_MCO_TIM10	(1 << 16)			/* CLK_TO_TMR */

/* --- RCC_CFGR5 (CRM_MISC3) values ---------------------------------------- */
#define RCC_CFGR5_MAC_PPS_SEL	(1 << 15)			/* EMAC_PPS_SEL */
/* HSE_DIV [13:12] */
#define RCC_CFGR5_HSI_SCLK	(1 << 9)			/* HICK_TO_SCLK */
#define RCC_CFGR5_HSI_USB_SRC	(1 << 8)			/* HICK_TO_USB */

#define RCC_CFGR5_HSE_DIV2	0x0
#define RCC_CFGR5_HSE_DIV3	0x1
#define RCC_CFGR5_HSE_DIV4	0x2
#define RCC_CFGR5_HSE_DIV5	0x3
#define RCC_CFGR5_HSE_DIV_SHIFT	12
#define RCC_CFGR5_HSE_DIV	(0x3 << RCC_CFGR5_HSE_DIV_SHIFT)

/* HSI_SCLK: HSI SYSCLK selector */
/** @defgroup rcc_cfgr5_hsi_sclk RCC_CFGR5 HSI SYSCLK selector
@ingroup AT32F40x_rcc_defines

@{*/
#define RCC_CFGR5_HSI_SCLK_FIXED	0
#define RCC_CFGR5_HSI_SCLK_HSIDIV	1
/**@}*/

/* --- RCC_CFGR6 (CRM_INTMAP) values --------------------------------------- */
#define RCC_CFGR6_USBFS_INTMAP	(1 << 0)			/* USBINTMAP */

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

	/* AHB peripherals */
	RCC_DMA1	= _REG_BIT(0x14, 0),
	RCC_DMA2	= _REG_BIT(0x14, 1),
	RCC_SRAM	= _REG_BIT(0x14, 2),
	RCC_FLTF	= _REG_BIT(0x14, 4),
	RCC_CRC		= _REG_BIT(0x14, 6),
	RCC_FSMC	= _REG_BIT(0x14, 8),
	RCC_SDIO	= _REG_BIT(0x14, 10),
	RCC_SDIO1	= _REG_BIT(0x14, 10),
	RCC_SDIO2	= _REG_BIT(0x14, 11),
	RCC_ETHMAC	= _REG_BIT(0x14, 14),
	RCC_ETHMACTX	= _REG_BIT(0x14, 15),
	RCC_ETHMACRX	= _REG_BIT(0x14, 16),
	RCC_ETHMACPTP	= _REG_BIT(0x14, 28),

	/* APB2 peripherals */
	RCC_AFIO	= _REG_BIT(0x18, 0),
	RCC_GPIOA	= _REG_BIT(0x18, 2),
	RCC_GPIOB	= _REG_BIT(0x18, 3),
	RCC_GPIOC	= _REG_BIT(0x18, 4),
	RCC_GPIOD	= _REG_BIT(0x18, 5),
	RCC_GPIOE	= _REG_BIT(0x18, 6),
	RCC_ADC1	= _REG_BIT(0x18, 9),
	RCC_ADC2	= _REG_BIT(0x18, 10),
	RCC_TIM1	= _REG_BIT(0x18, 11),
	RCC_SPI1	= _REG_BIT(0x18, 12),
	RCC_TIM8	= _REG_BIT(0x18, 13),
	RCC_USART1	= _REG_BIT(0x18, 14),
	RCC_ADC3	= _REG_BIT(0x18, 15),
	RCC_TIM9	= _REG_BIT(0x18, 19),
	RCC_TIM10	= _REG_BIT(0x18, 20),
	RCC_TIM11	= _REG_BIT(0x18, 21),
	RCC_CRS		= _REG_BIT(0x18, 22),
	RCC_I2C3	= _REG_BIT(0x18, 23),
	RCC_USART6	= _REG_BIT(0x18, 24),
	RCC_UART7	= _REG_BIT(0x18, 25),
	RCC_UART8	= _REG_BIT(0x18, 26),

	/* APB1 peripherals */
	RCC_TIM2	= _REG_BIT(0x1C, 0),
	RCC_TIM3	= _REG_BIT(0x1C, 1),
	RCC_TIM4	= _REG_BIT(0x1C, 2),
	RCC_TIM5	= _REG_BIT(0x1C, 3),
	RCC_TIM6	= _REG_BIT(0x1C, 4),
	RCC_TIM7	= _REG_BIT(0x1C, 5),
	RCC_TIM12	= _REG_BIT(0x1C, 6),
	RCC_TIM13	= _REG_BIT(0x1C, 7),
	RCC_TIM14	= _REG_BIT(0x1C, 8),
	RCC_WWDG	= _REG_BIT(0x1C, 11),
	RCC_SPI2	= _REG_BIT(0x1C, 14),
	RCC_SPI3	= _REG_BIT(0x1C, 15),
	RCC_SPI4	= _REG_BIT(0x1C, 16),
	RCC_USART2	= _REG_BIT(0x1C, 17),
	RCC_USART3	= _REG_BIT(0x1C, 18),
	RCC_UART4	= _REG_BIT(0x1C, 19),
	RCC_UART5	= _REG_BIT(0x1C, 20),
	RCC_I2C1	= _REG_BIT(0x1C, 21),
	RCC_I2C2	= _REG_BIT(0x1C, 22),
	RCC_USB		= _REG_BIT(0x1C, 23),
	RCC_CAN		= _REG_BIT(0x1C, 25),
	RCC_CAN1	= _REG_BIT(0x1C, 25),
	RCC_CAN2	= _REG_BIT(0x1C, 26),
	RCC_BKP		= _REG_BIT(0x1C, 27),
	RCC_PWR		= _REG_BIT(0x1C, 28),
	RCC_DAC		= _REG_BIT(0x1C, 29),
};

enum rcc_periph_rst {

	/* AHB peripherals */
	RST_ETHMAC	= _REG_BIT(0x28, 14),

	/* APB2 peripherals */
	RST_AFIO	= _REG_BIT(0x0c, 0),
	RST_GPIOA	= _REG_BIT(0x0c, 2),
	RST_GPIOB	= _REG_BIT(0x0c, 3),
	RST_GPIOC	= _REG_BIT(0x0c, 4),
	RST_GPIOD	= _REG_BIT(0x0c, 5),
	RST_GPIOE	= _REG_BIT(0x0c, 6),
	RST_ADC1	= _REG_BIT(0x0c, 9),
	RST_ADC2	= _REG_BIT(0x0c, 10),
	RST_TIM1	= _REG_BIT(0x0c, 11),
	RST_SPI1	= _REG_BIT(0x0c, 12),
	RST_TIM8	= _REG_BIT(0x0c, 13),
	RST_USART1	= _REG_BIT(0x0c, 14),
	RST_ADC3	= _REG_BIT(0x0c, 15),
	RST_TIM9	= _REG_BIT(0x0c, 19),
	RST_TIM10	= _REG_BIT(0x0c, 20),
	RST_TIM11	= _REG_BIT(0x0c, 21),
	RST_CRS		= _REG_BIT(0x0c, 22),
	RST_I2C3	= _REG_BIT(0x0c, 23),
	RST_USART6	= _REG_BIT(0x0c, 24),
	RST_UART7	= _REG_BIT(0x0c, 25),
	RST_UART8	= _REG_BIT(0x0c, 26),

	/* APB1 peripherals */
	RST_TIM2	= _REG_BIT(0x10, 0),
	RST_TIM3	= _REG_BIT(0x10, 1),
	RST_TIM4	= _REG_BIT(0x10, 2),
	RST_TIM5	= _REG_BIT(0x10, 3),
	RST_TIM6	= _REG_BIT(0x10, 4),
	RST_TIM7	= _REG_BIT(0x10, 5),
	RST_TIM12	= _REG_BIT(0x10, 6),
	RST_TIM13	= _REG_BIT(0x10, 7),
	RST_TIM14	= _REG_BIT(0x10, 8),
	RST_WWDG	= _REG_BIT(0x10, 11),
	RST_SPI2	= _REG_BIT(0x10, 14),
	RST_SPI3	= _REG_BIT(0x10, 15),
	RST_SPI4	= _REG_BIT(0x10, 16),
	RST_USART2	= _REG_BIT(0x10, 17),
	RST_USART3	= _REG_BIT(0x10, 18),
	RST_UART4	= _REG_BIT(0x10, 19),
	RST_UART5	= _REG_BIT(0x10, 20),
	RST_I2C1	= _REG_BIT(0x10, 21),
	RST_I2C2	= _REG_BIT(0x10, 22),
	RST_USB		= _REG_BIT(0x10, 23),
	RST_CAN		= _REG_BIT(0x10, 25),
	RST_CAN1	= _REG_BIT(0x10, 25),
	RST_CAN2	= _REG_BIT(0x10, 26),
	RST_BKP		= _REG_BIT(0x10, 27),
	RST_PWR		= _REG_BIT(0x10, 28),
	RST_DAC		= _REG_BIT(0x10, 29),
};

#include <libopencm3/stm32/common/rcc_common_all.h>

enum rcc_clock_hsi {
	RCC_CLOCK_HSI_72MHZ,
	RCC_CLOCK_HSI_96MHZ,
	RCC_CLOCK_HSI_168MHZ,
	RCC_CLOCK_HSI_END
};

enum rcc_clock_hse {
	RCC_CLOCK_HSE_72MHZ,
	RCC_CLOCK_HSE_96MHZ,
	RCC_CLOCK_HSE_168MHZ,
	RCC_CLOCK_HSE_192MHZ,
	RCC_CLOCK_HSE_240MHZ,
	RCC_CLOCK_HSE_END
};

struct rcc_clock_scale {
	uint8_t pll_mul;
	uint8_t pll_source;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	uint8_t adcpre;
	uint8_t hse_xtpre;	/* nonzero puts hse thru divider */
	uint8_t hse_prediv;	/* actual divider value */
	uint32_t ahb_frequency;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END];
extern const struct rcc_clock_scale rcc_hse_configs[RCC_CLOCK_HSE_END];

BEGIN_DECLS

void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_set_sysclk_source(uint32_t clk);
void rcc_set_pll_multiplication_factor(uint32_t mul);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_hse_xtpre(uint32_t xtpre);
void rcc_set_hse_prediv(uint32_t prediv);
uint32_t rcc_rtc_clock_enabled_flag(void);
void rcc_enable_rtc_clock(void);
void rcc_set_rtc_clock_source(enum rcc_osc clock_source);
void rcc_set_adcpre(uint32_t adcpre);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_hsi_div(uint32_t hsidiv);
void rcc_set_hsi_sclk(uint32_t hsisclk);
void rcc_set_usb_clock_source(enum rcc_osc osc);
void rcc_set_usbpre(uint32_t usbpre);
void rcc_set_mco_source(uint32_t src);
void rcc_set_mcodiv(uint32_t mcodiv);
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
