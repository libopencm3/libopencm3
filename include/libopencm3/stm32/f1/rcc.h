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

/* Note: Regs/bits marked (**) only exist in "connectivity line" STM32s. */
/* Note: Regs/bits marked (XX) do NOT exist in "connectivity line" STM32s. */

/* --- RCC registers ------------------------------------------------------- */

#define RCC_CR					MMIO32(RCC_BASE + 0x00)
#define RCC_CFGR				MMIO32(RCC_BASE + 0x04)
#define RCC_CIR					MMIO32(RCC_BASE + 0x08)
#define RCC_APB2RSTR				MMIO32(RCC_BASE + 0x0c)
#define RCC_APB1RSTR				MMIO32(RCC_BASE + 0x10)
#define RCC_AHBENR				MMIO32(RCC_BASE + 0x14)
#define RCC_APB2ENR				MMIO32(RCC_BASE + 0x18)
#define RCC_APB1ENR				MMIO32(RCC_BASE + 0x1c)
#define RCC_BDCR				MMIO32(RCC_BASE + 0x20)
#define RCC_CSR					MMIO32(RCC_BASE + 0x24)
#define RCC_AHBRSTR				MMIO32(RCC_BASE + 0x28) /*(**)*/
#define RCC_CFGR2				MMIO32(RCC_BASE + 0x2c) /*(**)*/

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_PLL3RDY				(1 << 29) /* (**) */
#define RCC_CR_PLL3ON				(1 << 28) /* (**) */
#define RCC_CR_PLL2RDY				(1 << 27) /* (**) */
#define RCC_CR_PLL2ON				(1 << 26) /* (**) */
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

/* --- RCC_CFGR values ----------------------------------------------------- */

#define RCC_CFGR_OTGFSPRE			(1 << 22) /* Connectivity line */
#define RCC_CFGR_USBPRE				(1 << 22) /* LD,MD, HD, XL */

#define RCC_CFGR_PLLMUL_SHIFT			18
#define RCC_CFGR_PLLMUL				(0xF << RCC_CFGR_PLLMUL_SHIFT)

#define RCC_CFGR_PLLXTPRE			(1 << 17)
#define RCC_CFGR_PLLSRC				(1 << 16)

#define RCC_CFGR_ADCPRE_SHIFT			14
#define RCC_CFGR_ADCPRE				(3 << RCC_CFGR_ADCPRE_SHIFT)

#define RCC_CFGR_PPRE2_SHIFT			11
#define RCC_CFGR_PPRE2				(7 << RCC_CFGR_PPRE2_SHIFT)

#define RCC_CFGR_PPRE1_SHIFT			8
#define RCC_CFGR_PPRE1				(7 << RCC_CFGR_PPRE1_SHIFT)

#define RCC_CFGR_HPRE_SHIFT			4
#define RCC_CFGR_HPRE				(0xF << RCC_CFGR_HPRE_SHIFT)

#define RCC_CFGR_SWS_SHIFT			2
#define RCC_CFGR_SWS				(3 << RCC_CFGR_SWS_SHIFT)

#define RCC_CFGR_SW_SHIFT			0
#define RCC_CFGR_SW				(3 << RCC_CFGR_SW_SHIFT)

/* MCO: Microcontroller clock output */
/** @defgroup rcc_cfgr_co RCC_CFGR Microcontroller Clock Output Source
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_MCO_SHIFT			24
#define RCC_CFGR_MCO_MASK			0xf
#define RCC_CFGR_MCO_NOCLK			0x0
#define RCC_CFGR_MCO_SYSCLK			0x4
#define RCC_CFGR_MCO_HSICLK			0x5
#define RCC_CFGR_MCO_HSECLK			0x6
#define RCC_CFGR_MCO_PLLCLK_DIV2		0x7
#define RCC_CFGR_MCO_PLL2CLK			0x8 /* (**) */
#define RCC_CFGR_MCO_PLL3CLK_DIV2		0x9 /* (**) */
#define RCC_CFGR_MCO_XT1			0xa /* (**) */
#define RCC_CFGR_MCO_PLL3			0xb /* (**) */
/**@}*/

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

/* PLLMUL: PLL multiplication factor */
/** @defgroup rcc_cfgr_pmf RCC_CFGR PLL Multiplication Factor
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL2		0x0 /* (XX) */
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL3		0x1 /* (XX) */
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL4		0x2
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL5		0x3
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL6		0x4
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL7		0x5
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL8		0x6
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL9		0x7
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL10		0x8 /* (XX) */
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL11		0x9 /* (XX) */
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL12		0xa /* (XX) */
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL13		0xb /* (XX) */
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL14		0xc /* (XX) */
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL15		0xd /* 0xd: PLL x 15 */
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL6_5		0xd /* 0xd: PLL x 6.5 for conn.
						       line */
#define RCC_CFGR_PLLMUL_PLL_CLK_MUL16		0xe /* (XX) */
/* #define PLLMUL_PLL_CLK_MUL16		0xf */ /* (XX) */ /* Errata? 17? */
/**@}*/

/* TODO: conn. line differs. */
/* PLLXTPRE: HSE divider for PLL entry */
/** @defgroup rcc_cfgr_hsepre RCC_CFGR HSE Divider for PLL
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_PLLXTPRE_HSE_CLK		0x0
#define RCC_CFGR_PLLXTPRE_HSE_CLK_DIV2		0x1
/**@}*/

/* PLLSRC: PLL entry clock source */
/** @defgroup rcc_cfgr_pcs RCC_CFGR PLL Clock Source
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_PLLSRC_HSI_CLK_DIV2		0x0
#define RCC_CFGR_PLLSRC_HSE_CLK			0x1
#define RCC_CFGR_PLLSRC_PREDIV1_CLK		0x1 /* On conn. line */
/**@}*/

/* ADCPRE: ADC prescaler */
/****************************************************************************/
/** @defgroup rcc_cfgr_adcpre RCC ADC clock prescaler enable values
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_ADCPRE_PCLK2_DIV2		0x0
#define RCC_CFGR_ADCPRE_PCLK2_DIV4		0x1
#define RCC_CFGR_ADCPRE_PCLK2_DIV6		0x2
#define RCC_CFGR_ADCPRE_PCLK2_DIV8		0x3
/**@}*/

/* PPRE2: APB high-speed prescaler (APB2) */
/** @defgroup rcc_cfgr_apb2pre RCC_CFGR APB2 prescale Factors
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_PPRE2_HCLK_NODIV		0x0
#define RCC_CFGR_PPRE2_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE2_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE2_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE2_HCLK_DIV16		0x7
/**@}*/

/* PPRE1: APB low-speed prescaler (APB1) */
/** @defgroup rcc_cfgr_apb1pre RCC_CFGR APB1 prescale Factors
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_PPRE1_HCLK_NODIV		0x0
#define RCC_CFGR_PPRE1_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE1_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE1_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE1_HCLK_DIV16		0x7
/**@}*/

/* HPRE: AHB prescaler */
/** @defgroup rcc_cfgr_ahbpre RCC_CFGR AHB prescale Factors
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_HPRE_SYSCLK_NODIV		0x0
#define RCC_CFGR_HPRE_SYSCLK_DIV2		0x8
#define RCC_CFGR_HPRE_SYSCLK_DIV4		0x9
#define RCC_CFGR_HPRE_SYSCLK_DIV8		0xa
#define RCC_CFGR_HPRE_SYSCLK_DIV16		0xb
#define RCC_CFGR_HPRE_SYSCLK_DIV64		0xc
#define RCC_CFGR_HPRE_SYSCLK_DIV128		0xd
#define RCC_CFGR_HPRE_SYSCLK_DIV256		0xe
#define RCC_CFGR_HPRE_SYSCLK_DIV512		0xf
/**@}*/

/* SWS: System clock switch status */
#define RCC_CFGR_SWS_SYSCLKSEL_HSICLK		0x0
#define RCC_CFGR_SWS_SYSCLKSEL_HSECLK		0x1
#define RCC_CFGR_SWS_SYSCLKSEL_PLLCLK		0x2

/* SW: System clock switch */
/** @defgroup rcc_cfgr_scs RCC_CFGR System Clock Selection
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_CFGR_SW_SYSCLKSEL_HSICLK		0x0
#define RCC_CFGR_SW_SYSCLKSEL_HSECLK		0x1
#define RCC_CFGR_SW_SYSCLKSEL_PLLCLK		0x2
/**@}*/

/* --- RCC_CIR values ------------------------------------------------------ */

/* Clock security system interrupt clear bit */
#define RCC_CIR_CSSC				(1 << 23)

/* OSC ready interrupt clear bits */
#define RCC_CIR_PLL3RDYC			(1 << 22) /* (**) */
#define RCC_CIR_PLL2RDYC			(1 << 21) /* (**) */
#define RCC_CIR_PLLRDYC				(1 << 20)
#define RCC_CIR_HSERDYC				(1 << 19)
#define RCC_CIR_HSIRDYC				(1 << 18)
#define RCC_CIR_LSERDYC				(1 << 17)
#define RCC_CIR_LSIRDYC				(1 << 16)

/* OSC ready interrupt enable bits */
#define RCC_CIR_PLL3RDYIE			(1 << 14) /* (**) */
#define RCC_CIR_PLL2RDYIE			(1 << 13) /* (**) */
#define RCC_CIR_PLLRDYIE			(1 << 12)
#define RCC_CIR_HSERDYIE			(1 << 11)
#define RCC_CIR_HSIRDYIE			(1 << 10)
#define RCC_CIR_LSERDYIE			(1 << 9)
#define RCC_CIR_LSIRDYIE			(1 << 8)

/* Clock security system interrupt flag bit */
#define RCC_CIR_CSSF				(1 << 7)

/* OSC ready interrupt flag bits */
#define RCC_CIR_PLL3RDYF			(1 << 6) /* (**) */
#define RCC_CIR_PLL2RDYF			(1 << 5) /* (**) */
#define RCC_CIR_PLLRDYF				(1 << 4)
#define RCC_CIR_HSERDYF				(1 << 3)
#define RCC_CIR_HSIRDYF				(1 << 2)
#define RCC_CIR_LSERDYF				(1 << 1)
#define RCC_CIR_LSIRDYF				(1 << 0)

/* --- RCC_APB2RSTR values ------------------------------------------------- */

/** @defgroup rcc_apb2rstr_rst RCC_APB2RSTR reset values
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_APB2RSTR_TIM17RST			(1 << 18)
#define RCC_APB2RSTR_TIM16RST			(1 << 17)
#define RCC_APB2RSTR_TIM15RST			(1 << 16)
#define RCC_APB2RSTR_ADC3RST			(1 << 15) /* (XX) */
#define RCC_APB2RSTR_USART1RST			(1 << 14)
#define RCC_APB2RSTR_TIM8RST			(1 << 13) /* (XX) */
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_TIM1RST			(1 << 11)
#define RCC_APB2RSTR_ADC2RST			(1 << 10)
#define RCC_APB2RSTR_ADC1RST			(1 << 9)
#define RCC_APB2RSTR_IOPGRST			(1 << 8)  /* (XX) */
#define RCC_APB2RSTR_IOPFRST			(1 << 7)  /* (XX) */
#define RCC_APB2RSTR_IOPERST			(1 << 6)
#define RCC_APB2RSTR_IOPDRST			(1 << 5)
#define RCC_APB2RSTR_IOPCRST			(1 << 4)
#define RCC_APB2RSTR_IOPBRST			(1 << 3)
#define RCC_APB2RSTR_IOPARST			(1 << 2)
#define RCC_APB2RSTR_AFIORST			(1 << 0)
/**@}*/

/* --- RCC_APB1RSTR values ------------------------------------------------- */

/** @defgroup rcc_apb1rstr_rst RCC_APB1RSTR reset values
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_APB1RSTR_DACRST			(1 << 29)
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_BKPRST			(1 << 27)
#define RCC_APB1RSTR_CAN2RST			(1 << 26) /* (**) */
#define RCC_APB1RSTR_CAN1RST			(1 << 25) /* (**) */
#define RCC_APB1RSTR_CANRST			(1 << 25) /* (XX) Alias for
							     CAN1RST */
#define RCC_APB1RSTR_USBRST			(1 << 23) /* (XX) */
#define RCC_APB1RSTR_I2C2RST			(1 << 22)
#define RCC_APB1RSTR_I2C1RST			(1 << 21)
#define RCC_APB1RSTR_UART5RST			(1 << 20)
#define RCC_APB1RSTR_UART4RST			(1 << 19)
#define RCC_APB1RSTR_USART3RST			(1 << 18)
#define RCC_APB1RSTR_USART2RST			(1 << 17)
#define RCC_APB1RSTR_SPI3RST			(1 << 15)
#define RCC_APB1RSTR_SPI2RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_TIM7RST			(1 << 5)
#define RCC_APB1RSTR_TIM6RST			(1 << 4)
#define RCC_APB1RSTR_TIM5RST			(1 << 3)
#define RCC_APB1RSTR_TIM4RST			(1 << 2)
#define RCC_APB1RSTR_TIM3RST			(1 << 1)
#define RCC_APB1RSTR_TIM2RST			(1 << 0)
/**@}*/

/* --- RCC_AHBENR values --------------------------------------------------- */

/** @defgroup rcc_ahbenr_en RCC_AHBENR enable values
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_AHBENR_ETHMACENRX			(1 << 16)
#define RCC_AHBENR_ETHMACENTX			(1 << 15)
#define RCC_AHBENR_ETHMACEN			(1 << 14)
#define RCC_AHBENR_OTGFSEN			(1 << 12)
#define RCC_AHBENR_SDIOEN			(1 << 10)
#define RCC_AHBENR_FSMCEN			(1 << 8)
#define RCC_AHBENR_CRCEN			(1 << 6)
#define RCC_AHBENR_FLITFEN			(1 << 4)
#define RCC_AHBENR_SRAMEN			(1 << 2)
#define RCC_AHBENR_DMA2EN			(1 << 1)
#define RCC_AHBENR_DMA1EN			(1 << 0)
/**@}*/

/* --- RCC_APB2ENR values -------------------------------------------------- */

/** @defgroup rcc_apb2enr_en RCC_APB2ENR enable values
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_APB2ENR_TIM17EN			(1 << 17)
#define RCC_APB2ENR_TIM16EN			(1 << 16)
#define RCC_APB2ENR_TIM15EN			(1 << 16)
#define RCC_APB2ENR_ADC3EN			(1 << 15) /* (XX) */
#define RCC_APB2ENR_USART1EN			(1 << 14)
#define RCC_APB2ENR_TIM8EN			(1 << 13) /* (XX) */
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_TIM1EN			(1 << 11)
#define RCC_APB2ENR_ADC2EN			(1 << 10)
#define RCC_APB2ENR_ADC1EN			(1 << 9)
#define RCC_APB2ENR_IOPGEN			(1 << 8)  /* (XX) */
#define RCC_APB2ENR_IOPFEN			(1 << 7)  /* (XX) */
#define RCC_APB2ENR_IOPEEN			(1 << 6)
#define RCC_APB2ENR_IOPDEN			(1 << 5)
#define RCC_APB2ENR_IOPCEN			(1 << 4)
#define RCC_APB2ENR_IOPBEN			(1 << 3)
#define RCC_APB2ENR_IOPAEN			(1 << 2)
#define RCC_APB2ENR_AFIOEN			(1 << 0)
/**@}*/

/* --- RCC_APB1ENR values -------------------------------------------------- */

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_APB1ENR_DACEN			(1 << 29)
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_BKPEN			(1 << 27)
#define RCC_APB1ENR_CAN2EN			(1 << 26) /* (**) */
#define RCC_APB1ENR_CAN1EN			(1 << 25) /* (**) */
#define RCC_APB1ENR_CANEN			(1 << 25) /* (XX) Alias for
							     CAN1EN */
#define RCC_APB1ENR_USBEN			(1 << 23) /* (XX) */
#define RCC_APB1ENR_I2C2EN			(1 << 22)
#define RCC_APB1ENR_I2C1EN			(1 << 21)
#define RCC_APB1ENR_UART5EN			(1 << 20)
#define RCC_APB1ENR_UART4EN			(1 << 19)
#define RCC_APB1ENR_USART3EN			(1 << 18)
#define RCC_APB1ENR_USART2EN			(1 << 17)
#define RCC_APB1ENR_SPI3EN			(1 << 15)
#define RCC_APB1ENR_SPI2EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_TIM7EN			(1 << 5)
#define RCC_APB1ENR_TIM6EN			(1 << 4)
#define RCC_APB1ENR_TIM5EN			(1 << 3)
#define RCC_APB1ENR_TIM4EN			(1 << 2)
#define RCC_APB1ENR_TIM3EN			(1 << 1)
#define RCC_APB1ENR_TIM2EN			(1 << 0)
/**@}*/

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
#define RCC_CSR_RMVF				(1 << 24)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)

/* --- RCC_AHBRSTR values -------------------------------------------------- */

/** @defgroup rcc_ahbrstr_rst RCC_AHBRSTR reset values
@ingroup STM32F1xx_rcc_defines

@{*/
#define RCC_AHBRSTR_ETHMACRST			(1 << 14)
#define RCC_AHBRSTR_OTGFSRST			(1 << 12)
/**@}*/

/* --- RCC_CFGR2 values ---------------------------------------------------- */

/* I2S3SRC: I2S3 clock source */
#define RCC_CFGR2_I2S3SRC_SYSCLK		0x0
#define RCC_CFGR2_I2S3SRC_PLL3_VCO_CLK		0x1

/* I2S2SRC: I2S2 clock source */
#define RCC_CFGR2_I2S2SRC_SYSCLK		0x0
#define RCC_CFGR2_I2S2SRC_PLL3_VCO_CLK		0x1
#define RCC_CFGR2_I2S2SRC			(1 << 17)

/* PREDIV1SRC: PREDIV1 entry clock source */
#define RCC_CFGR2_PREDIV1SRC_HSE_CLK		0x0
#define RCC_CFGR2_PREDIV1SRC_PLL2_CLK		0x1
#define RCC_CFGR2_PREDIV1SRC			(1 << 16)

#define RCC_CFGR2_PLL3MUL_SHIFT			12
#define RCC_CFGR2_PLL3MUL			(0xF << RCC_CFGR2_PLL3MUL_SHIFT)

#define RCC_CFGR2_PLL2MUL_SHIFT			8
#define RCC_CFGR2_PLL2MUL			(0xF << RCC_CFGR2_PLL2MUL_SHIFT)

#define RCC_CFGR2_PREDIV2_SHIFT			4
#define RCC_CFGR2_PREDIV2			(0xF << RCC_CFGR2_PREDIV2_SHIFT)

#define RCC_CFGR2_PREDIV1_SHIFT			0
#define RCC_CFGR2_PREDIV1			(0xF << RCC_CFGR2_PREDIV1_SHIFT)

/* PLL3MUL: PLL3 multiplication factor */
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL8		0x6
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL9		0x7
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL10	0x8
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL11	0x9
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL12	0xa
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL13	0xb
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL14	0xc
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL16	0xe
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL20	0xf

/* PLL2MUL: PLL2 multiplication factor */
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8		0x6
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL9		0x7
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL10	0x8
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL11	0x9
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL12	0xa
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL13	0xb
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL14	0xc
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL16	0xe
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL20	0xf

/* PREDIV: PREDIV division factor */
#define RCC_CFGR2_PREDIV_NODIV			0x0
#define RCC_CFGR2_PREDIV_DIV2			0x1
#define RCC_CFGR2_PREDIV_DIV3			0x2
#define RCC_CFGR2_PREDIV_DIV4			0x3
#define RCC_CFGR2_PREDIV_DIV5			0x4
#define RCC_CFGR2_PREDIV_DIV6			0x5
#define RCC_CFGR2_PREDIV_DIV7			0x6
#define RCC_CFGR2_PREDIV_DIV8			0x7
#define RCC_CFGR2_PREDIV_DIV9			0x8
#define RCC_CFGR2_PREDIV_DIV10			0x9
#define RCC_CFGR2_PREDIV_DIV11			0xa
#define RCC_CFGR2_PREDIV_DIV12			0xb
#define RCC_CFGR2_PREDIV_DIV13			0xc
#define RCC_CFGR2_PREDIV_DIV14			0xd
#define RCC_CFGR2_PREDIV_DIV15			0xe
#define RCC_CFGR2_PREDIV_DIV16			0xf

/* PREDIV2: PREDIV2 division factor */
#define RCC_CFGR2_PREDIV2_NODIV			0x0
#define RCC_CFGR2_PREDIV2_DIV2			0x1
#define RCC_CFGR2_PREDIV2_DIV3			0x2
#define RCC_CFGR2_PREDIV2_DIV4			0x3
#define RCC_CFGR2_PREDIV2_DIV5			0x4
#define RCC_CFGR2_PREDIV2_DIV6			0x5
#define RCC_CFGR2_PREDIV2_DIV7			0x6
#define RCC_CFGR2_PREDIV2_DIV8			0x7
#define RCC_CFGR2_PREDIV2_DIV9			0x8
#define RCC_CFGR2_PREDIV2_DIV10			0x9
#define RCC_CFGR2_PREDIV2_DIV11			0xa
#define RCC_CFGR2_PREDIV2_DIV12			0xb
#define RCC_CFGR2_PREDIV2_DIV13			0xc
#define RCC_CFGR2_PREDIV2_DIV14			0xd
#define RCC_CFGR2_PREDIV2_DIV15			0xe
#define RCC_CFGR2_PREDIV2_DIV16			0xf

/* --- Variable definitions ------------------------------------------------ */
extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

/* --- Function prototypes ------------------------------------------------- */

enum rcc_osc {
	RCC_PLL, RCC_PLL2, RCC_PLL3, RCC_HSE, RCC_HSI, RCC_LSE, RCC_LSI
};

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

/* V = value line F100
 * N = standard line F101, F102, F103
 * C = communication line F105, F107
 */
enum rcc_periph_clken {

	/* AHB peripherals */
	RCC_DMA1	= _REG_BIT(0x14, 0),/*VNC*/
	RCC_DMA2	= _REG_BIT(0x14, 1),/*VNC*/
	RCC_SRAM	= _REG_BIT(0x14, 2),/*VNC*/
	RCC_FLTF	= _REG_BIT(0x14, 4),/*VNC*/
	RCC_CRC		= _REG_BIT(0x14, 6),/*VNC*/
	RCC_FSMC	= _REG_BIT(0x14, 8),/*VN-*/
	RCC_SDIO	= _REG_BIT(0x14, 10),/*-N-*/
	RCC_OTGFS	= _REG_BIT(0x14, 12),/*--C*/
	RCC_ETHMAC	= _REG_BIT(0x14, 14),/*--C*/
	RCC_ETHMACTX	= _REG_BIT(0x14, 15),/*--C*/
	RCC_ETHMACRX	= _REG_BIT(0x14, 16),/*--C*/

	/* APB2 peripherals */
	RCC_AFIO	= _REG_BIT(0x18, 0),/*VNC*/
	RCC_GPIOA	= _REG_BIT(0x18, 2),/*VNC*/
	RCC_GPIOB	= _REG_BIT(0x18, 3),/*VNC*/
	RCC_GPIOC	= _REG_BIT(0x18, 4),/*VNC*/
	RCC_GPIOD	= _REG_BIT(0x18, 5),/*VNC*/
	RCC_GPIOE	= _REG_BIT(0x18, 6),/*VNC*/
	RCC_GPIOF	= _REG_BIT(0x18, 7),/*VN-*/
	RCC_GPIOG	= _REG_BIT(0x18, 8),/*VN-*/
	RCC_ADC1	= _REG_BIT(0x18, 9),/*VNC*/
	RCC_ADC2	= _REG_BIT(0x18, 10),/*-NC*/
	RCC_TIM1	= _REG_BIT(0x18, 11),/*VNC*/
	RCC_SPI1	= _REG_BIT(0x18, 12),/*VNC*/
	RCC_TIM8	= _REG_BIT(0x18, 13),/*-N-*/
	RCC_USART1	= _REG_BIT(0x18, 14),/*VNC*/
	RCC_ADC3	= _REG_BIT(0x18, 15),/*-N-*/
	RCC_TIM15	= _REG_BIT(0x18, 16),/*V--*/
	RCC_TIM16	= _REG_BIT(0x18, 17),/*V--*/
	RCC_TIM17	= _REG_BIT(0x18, 18),/*V--*/
	RCC_TIM9	= _REG_BIT(0x18, 19),/*-N-*/
	RCC_TIM10	= _REG_BIT(0x18, 20),/*-N-*/
	RCC_TIM11	= _REG_BIT(0x18, 21),/*-N-*/

	/* APB1 peripherals */
	RCC_TIM2	= _REG_BIT(0x1C, 0),/*VNC*/
	RCC_TIM3	= _REG_BIT(0x1C, 1),/*VNC*/
	RCC_TIM4	= _REG_BIT(0x1C, 2),/*VNC*/
	RCC_TIM5	= _REG_BIT(0x1C, 3),/*VNC*/
	RCC_TIM6	= _REG_BIT(0x1C, 4),/*VNC*/
	RCC_TIM7	= _REG_BIT(0x1C, 5),/*VNC*/
	RCC_TIM12	= _REG_BIT(0x1C, 6),/*VN-*/
	RCC_TIM13	= _REG_BIT(0x1C, 7),/*VN-*/
	RCC_TIM14	= _REG_BIT(0x1C, 8),/*VN-*/
	RCC_WWDG	= _REG_BIT(0x1C, 11),/*VNC*/
	RCC_SPI2	= _REG_BIT(0x1C, 14),/*VNC*/
	RCC_SPI3	= _REG_BIT(0x1C, 15),/*VNC*/
	RCC_USART2	= _REG_BIT(0x1C, 17),/*VNC*/
	RCC_USART3	= _REG_BIT(0x1C, 18),/*VNC*/
	RCC_UART4	= _REG_BIT(0x1C, 19),/*VNC*/
	RCC_UART5	= _REG_BIT(0x1C, 20),/*VNC*/
	RCC_I2C1	= _REG_BIT(0x1C, 21),/*VNC*/
	RCC_I2C2	= _REG_BIT(0x1C, 22),/*VNC*/
	RCC_USB		= _REG_BIT(0x1C, 23),/*-N-*/
	RCC_CAN		= _REG_BIT(0x1C, 25),/*-N-*/
	RCC_CAN1	= _REG_BIT(0x1C, 25),/*--C*/
	RCC_CAN2	= _REG_BIT(0x1C, 26),/*--C*/
	RCC_BKP		= _REG_BIT(0x1C, 27),/*VNC*/
	RCC_PWR		= _REG_BIT(0x1C, 28),/*VNC*/
	RCC_DAC		= _REG_BIT(0x1C, 29),/*VNC*/
	RCC_CEC		= _REG_BIT(0x1C, 30),/*V--*/
};

enum rcc_periph_rst {

	/* AHB peripherals */
	RST_OTGFS	= _REG_BIT(0x28, 12),/*--C*/
	RST_ETHMAC	= _REG_BIT(0x28, 14),/*--C*/

	/* APB2 peripherals */
	RST_AFIO	= _REG_BIT(0x0c, 0),/*VNC*/
	RST_GPIOA	= _REG_BIT(0x0c, 2),/*VNC*/
	RST_GPIOB	= _REG_BIT(0x0c, 3),/*VNC*/
	RST_GPIOC	= _REG_BIT(0x0c, 4),/*VNC*/
	RST_GPIOD	= _REG_BIT(0x0c, 5),/*VNC*/
	RST_GPIOE	= _REG_BIT(0x0c, 6),/*VNC*/
	RST_GPIOF	= _REG_BIT(0x0c, 7),/*VN-*/
	RST_GPIOG	= _REG_BIT(0x0c, 8),/*VN-*/
	RST_ADC1	= _REG_BIT(0x0c, 9),/*VNC*/
	RST_ADC2	= _REG_BIT(0x0c, 10),/*-NC*/
	RST_TIM1	= _REG_BIT(0x0c, 11),/*VNC*/
	RST_SPI1	= _REG_BIT(0x0c, 12),/*VNC*/
	RST_TIM8	= _REG_BIT(0x0c, 13),/*-N-*/
	RST_USART1	= _REG_BIT(0x0c, 14),/*VNC*/
	RST_ADC3	= _REG_BIT(0x0c, 15),/*-N-*/
	RST_TIM15	= _REG_BIT(0x0c, 16),/*V--*/
	RST_TIM16	= _REG_BIT(0x0c, 17),/*V--*/
	RST_TIM17	= _REG_BIT(0x0c, 18),/*V--*/
	RST_TIM9	= _REG_BIT(0x0c, 19),/*-N-*/
	RST_TIM10	= _REG_BIT(0x0c, 20),/*-N-*/
	RST_TIM11	= _REG_BIT(0x0c, 21),/*-N-*/

	/* APB1 peripherals */
	RST_TIM2	= _REG_BIT(0x10, 0),/*VNC*/
	RST_TIM3	= _REG_BIT(0x10, 1),/*VNC*/
	RST_TIM4	= _REG_BIT(0x10, 2),/*VNC*/
	RST_TIM5	= _REG_BIT(0x10, 3),/*VNC*/
	RST_TIM6	= _REG_BIT(0x10, 4),/*VNC*/
	RST_TIM7	= _REG_BIT(0x10, 5),/*VNC*/
	RST_TIM12	= _REG_BIT(0x10, 6),/*VN-*/
	RST_TIM13	= _REG_BIT(0x10, 7),/*VN-*/
	RST_TIM14	= _REG_BIT(0x10, 8),/*VN-*/
	RST_WWDG	= _REG_BIT(0x10, 11),/*VNC*/
	RST_SPI2	= _REG_BIT(0x10, 14),/*VNC*/
	RST_SPI3	= _REG_BIT(0x10, 15),/*VNC*/
	RST_USART2	= _REG_BIT(0x10, 17),/*VNC*/
	RST_USART3	= _REG_BIT(0x10, 18),/*VNC*/
	RST_UART4	= _REG_BIT(0x10, 19),/*VNC*/
	RST_UART5	= _REG_BIT(0x10, 20),/*VNC*/
	RST_I2C1	= _REG_BIT(0x10, 21),/*VNC*/
	RST_I2C2	= _REG_BIT(0x10, 22),/*VNC*/
	RST_USB		= _REG_BIT(0x10, 23),/*-N-*/
	RST_CAN		= _REG_BIT(0x10, 24),/*-N-*/
	RST_CAN1	= _REG_BIT(0x10, 24),/*--C*/
	RST_CAN2	= _REG_BIT(0x10, 25),/*--C*/
	RST_BKP		= _REG_BIT(0x10, 27),/*VNC*/
	RST_PWR		= _REG_BIT(0x10, 28),/*VNC*/
	RST_DAC		= _REG_BIT(0x10, 29),/*VNC*/
	RST_CEC		= _REG_BIT(0x10, 30),/*V--*/
};

#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS

void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_wait_for_osc_ready(enum rcc_osc osc);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_osc_bypass_enable(enum rcc_osc osc);
void rcc_osc_bypass_disable(enum rcc_osc osc);
void rcc_set_sysclk_source(uint32_t clk);
void rcc_set_pll_multiplication_factor(uint32_t mul);
void rcc_set_pll2_multiplication_factor(uint32_t mul);
void rcc_set_pll3_multiplication_factor(uint32_t mul);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_pllxtpre(uint32_t pllxtpre);
uint32_t rcc_rtc_clock_enabled_flag(void);
void rcc_enable_rtc_clock(void);
void rcc_set_rtc_clock_source(enum rcc_osc clock_source);
void rcc_set_adcpre(uint32_t adcpre);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_usbpre(uint32_t usbpre);
void rcc_set_prediv1(uint32_t prediv);
void rcc_set_prediv2(uint32_t prediv);
void rcc_set_prediv1_source(uint32_t rccsrc);
uint32_t rcc_system_clock_source(void);
void rcc_clock_setup_in_hsi_out_64mhz(void);
void rcc_clock_setup_in_hsi_out_48mhz(void);
void rcc_clock_setup_in_hsi_out_24mhz(void);
void rcc_clock_setup_in_hse_8mhz_out_24mhz(void);
void rcc_clock_setup_in_hse_8mhz_out_72mhz(void);
void rcc_clock_setup_in_hse_12mhz_out_72mhz(void);
void rcc_clock_setup_in_hse_16mhz_out_72mhz(void);
void rcc_clock_setup_in_hse_25mhz_out_72mhz(void);
void rcc_backupdomain_reset(void);

END_DECLS

#endif
/**@}*/

