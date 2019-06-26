/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx Reset and Clock
Control</b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Frantisek Burian <BuFran@seznam.cz>
 *
 * @version 1.0.0
 *
 * @date 29 Jun 2013
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

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
#define RCC_AHBRSTR				MMIO32(RCC_BASE + 0x28)
#define RCC_CFGR2				MMIO32(RCC_BASE + 0x2c)
#define RCC_CFGR3				MMIO32(RCC_BASE + 0x30)
#define RCC_CR2					MMIO32(RCC_BASE + 0x34)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_PLLRDY				(1 << 25)
#define RCC_CR_PLLON				(1 << 24)
#define RCC_CR_CSSON				(1 << 19)
#define RCC_CR_HSEBYP				(1 << 18)
#define RCC_CR_HSERDY				(1 << 17)
#define RCC_CR_HSEON				(1 << 16)
#define RCC_CR_HSICAL_SHIFT			8
#define RCC_CR_HSICAL				(0xFF << RCC_CR_HSICAL_SHIFT)
#define RCC_CR_HSITRIM_SHIFT			3
#define RCC_CR_HSITRIM				(0x1F << RCC_CR_HSITRIM_SHIFT)
#define RCC_CR_HSIRDY				(1 << 1)
#define RCC_CR_HSION				(1 << 0)

/* --- RCC_CFGR values ----------------------------------------------------- */

#define RCC_CFGR_PLLNODIV			(1 << 31)

#define RCC_CFGR_MCOPRE_SHIFT			28
#define RCC_CFGR_MCOPRE				(7 << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV1			(0 << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV2			(1 << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV4			(2 << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV8			(3 << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV16			(4 << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV32			(5 << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV64			(6 << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV128			(7 << RCC_CFGR_MCOPRE_SHIFT)

#define RCC_CFGR_MCO_SHIFT			24
#define RCC_CFGR_MCO_MASK			0xf
#define RCC_CFGR_MCO_NOCLK			0
#define RCC_CFGR_MCO_HSI14			1
#define RCC_CFGR_MCO_LSI			2
#define RCC_CFGR_MCO_LSE			3
#define RCC_CFGR_MCO_SYSCLK			4
#define RCC_CFGR_MCO_HSI			5
#define RCC_CFGR_MCO_HSE			6
#define RCC_CFGR_MCO_PLL			7
#define RCC_CFGR_MCO_HSI48			8

#define RCC_CFGR_PLLMUL_SHIFT			18
#define RCC_CFGR_PLLMUL				(0x0F << RCC_CFGR_PLLMUL_SHIFT)
/** @defgroup rcc_cfgr_pmf PLLMUL: PLL multiplication factor
 * @{
 */
#define RCC_CFGR_PLLMUL_MUL2			(0x00 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL3			(0x01 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL4			(0x02 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL5			(0x03 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL6			(0x04 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL7			(0x05 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL8			(0x06 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL9			(0x07 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL10			(0x08 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL11			(0x09 << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL12			(0x0A << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL13			(0x0B << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL14			(0x0C << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL15			(0x0D << RCC_CFGR_PLLMUL_SHIFT)
#define RCC_CFGR_PLLMUL_MUL16			(0x0E << RCC_CFGR_PLLMUL_SHIFT)
/**@}*/

#define RCC_CFGR_PLLXTPRE			(1<<17)
/** @defgroup rcc_cfgr_hsepre PLLXTPRE: HSE divider for PLL source
 * @{
 */
#define RCC_CFGR_PLLXTPRE_HSE_CLK		0x0
#define RCC_CFGR_PLLXTPRE_HSE_CLK_DIV2		0x1
/**@}*/

#define RCC_CFGR_PLLSRC				(1<<16)
/** @defgroup rcc_cfgr_pcs PLLSRC: PLL Clock source
 * @{
 */
#define RCC_CFGR_PLLSRC_HSI_CLK_DIV2		0x0
#define RCC_CFGR_PLLSRC_HSE_CLK			0x1
/**@}*/

#define RCC_CFGR_PLLSRC0			(1<<15)
#define RCC_CFGR_ADCPRE				(1<<14)

#define RCC_CFGR_PPRE_SHIFT			8
#define RCC_CFGR_PPRE				(7 << RCC_CFGR_PPRE_SHIFT)
/** @defgroup rcc_cfgr_apb1pre RCC_CFGR APB prescale Factors
@{*/
#define RCC_CFGR_PPRE_NODIV			(0 << RCC_CFGR_PPRE_SHIFT)
#define RCC_CFGR_PPRE_DIV2			(4 << RCC_CFGR_PPRE_SHIFT)
#define RCC_CFGR_PPRE_DIV4			(5 << RCC_CFGR_PPRE_SHIFT)
#define RCC_CFGR_PPRE_DIV8			(6 << RCC_CFGR_PPRE_SHIFT)
#define RCC_CFGR_PPRE_DIV16			(7 << RCC_CFGR_PPRE_SHIFT)
/**@}*/

#define RCC_CFGR_HPRE_SHIFT			4
#define RCC_CFGR_HPRE				(0xf << RCC_CFGR_HPRE_SHIFT)
/** @defgroup rcc_cfgr_ahbpre RCC_CFGR AHB prescale Factors
@{*/
#define RCC_CFGR_HPRE_NODIV			(0x0 << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE_DIV2			(0x8 << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE_DIV4			(0x9 << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE_DIV8			(0xa << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE_DIV16			(0xb << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE_DIV64			(0xc << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE_DIV128			(0xd << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE_DIV256			(0xe << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE_DIV512			(0xf << RCC_CFGR_HPRE_SHIFT)
/**@}*/

#define RCC_CFGR_SWS_SHIFT			2
#define RCC_CFGR_SWS				(3 << RCC_CFGR_SWS_SHIFT)
#define RCC_CFGR_SWS_HSI			(0 << RCC_CFGR_SWS_SHIFT)
#define RCC_CFGR_SWS_HSE			(1 << RCC_CFGR_SWS_SHIFT)
#define RCC_CFGR_SWS_PLL			(2 << RCC_CFGR_SWS_SHIFT)
#define RCC_CFGR_SWS_HSI48			(3 << RCC_CFGR_SWS_SHIFT)

#define RCC_CFGR_SW_SHIFT			0
#define RCC_CFGR_SW				(3 << RCC_CFGR_SW_SHIFT)
#define RCC_CFGR_SW_HSI				(0 << RCC_CFGR_SW_SHIFT)
#define RCC_CFGR_SW_HSE				(1 << RCC_CFGR_SW_SHIFT)
#define RCC_CFGR_SW_PLL				(2 << RCC_CFGR_SW_SHIFT)
#define RCC_CFGR_SW_HSI48			(3 << RCC_CFGR_SW_SHIFT)

/* --- RCC_CIR values ------------------------------------------------------ */

#define RCC_CIR_CSSC				(1 << 23)
#define RCC_CIR_HSI48RDYC			(1 << 22)
#define RCC_CIR_HSI14RDYC			(1 << 21)
#define RCC_CIR_PLLRDYC				(1 << 20)
#define RCC_CIR_HSERDYC				(1 << 19)
#define RCC_CIR_HSIRDYC				(1 << 18)
#define RCC_CIR_LSERDYC				(1 << 17)
#define RCC_CIR_LSIRDYC				(1 << 16)
#define RCC_CIR_HSI48RDYIE			(1 << 14)
#define RCC_CIR_HSI14RDYIE			(1 << 13)
#define RCC_CIR_PLLRDYIE			(1 << 12)
#define RCC_CIR_HSERDYIE			(1 << 11)
#define RCC_CIR_HSIRDYIE			(1 << 10)
#define RCC_CIR_LSERDYIE			(1 << 9)
#define RCC_CIR_LSIRDYIE			(1 << 8)
#define RCC_CIR_CSSF				(1 << 7)
#define RCC_CIR_HSI48RDYF			(1 << 6)
#define RCC_CIR_HSI14RDYF			(1 << 5)
#define RCC_CIR_PLLRDYF				(1 << 4)
#define RCC_CIR_HSERDYF				(1 << 3)
#define RCC_CIR_HSIRDYF				(1 << 2)
#define RCC_CIR_LSERDYF				(1 << 1)
#define RCC_CIR_LSIRDYF				(1 << 0)

/** @defgroup rcc_apb2rstr_rst RCC_APB2RSTR reset values
@{*/
#define RCC_APB2RSTR_DBGMCURST			(1 << 22)
#define RCC_APB2RSTR_TIM17RST			(1 << 18)
#define RCC_APB2RSTR_TIM16RST			(1 << 17)
#define RCC_APB2RSTR_TIM15RST			(1 << 16)
#define RCC_APB2RSTR_USART1RST			(1 << 14)
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_TIM1RST			(1 << 11)
#define RCC_APB2RSTR_ADCRST			(1 << 9)
#define RCC_APB2RSTR_USART8RST			(1 << 7)
#define RCC_APB2RSTR_USART7RST			(1 << 6)
#define RCC_APB2RSTR_USART6RST			(1 << 5)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 0)
/**@}*/


/** @defgroup rcc_apb1rstr_rst RCC_APB1RSTR reset values
@{*/
#define RCC_APB1RSTR_CECRST			(1 << 30)
#define RCC_APB1RSTR_DACRST			(1 << 29)
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_CRSRST			(1 << 27)
#define RCC_APB1RSTR_CANRST			(1 << 25)
#define RCC_APB1RSTR_USBRST			(1 << 23)
#define RCC_APB1RSTR_I2C2RST			(1 << 22)
#define RCC_APB1RSTR_I2C1RST			(1 << 21)
#define RCC_APB1RSTR_USART5RST			(1 << 20)
#define RCC_APB1RSTR_USART4RST			(1 << 19)
#define RCC_APB1RSTR_USART3RST			(1 << 18)
#define RCC_APB1RSTR_USART2RST			(1 << 17)
#define RCC_APB1RSTR_SPI2RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_TIM14RST			(1 << 8)
#define RCC_APB1RSTR_TIM7RST			(1 << 5)
#define RCC_APB1RSTR_TIM6RST			(1 << 4)
#define RCC_APB1RSTR_TIM3RST			(1 << 1)
#define RCC_APB1RSTR_TIM2RST			(1 << 0)
/**@}*/

/** @defgroup rcc_ahbenr_en RCC_APHBENR enable values
@{*/
#define RCC_AHBENR_TSCEN			(1 << 24)
#define RCC_AHBENR_GPIOFEN			(1 << 22)
#define RCC_AHBENR_GPIOEEN			(1 << 21)
#define RCC_AHBENR_GPIODEN			(1 << 20)
#define RCC_AHBENR_GPIOCEN			(1 << 19)
#define RCC_AHBENR_GPIOBEN			(1 << 18)
#define RCC_AHBENR_GPIOAEN			(1 << 17)
#define RCC_AHBENR_CRCEN			(1 << 6)
#define RCC_AHBENR_FLTFEN			(1 << 4)
#define RCC_AHBENR_SRAMEN			(1 << 2)
#define RCC_AHBENR_DMA2EN			(1 << 1)
#define RCC_AHBENR_DMA1EN			(1 << 0)
#define RCC_AHBENR_DMAEN			RCC_AHBENR_DMA1EN /* compatibility alias */
/**@}*/

/** @defgroup rcc_apb2enr_en RCC_APPB2ENR enable values
@{*/
#define RCC_APB2ENR_DBGMCUEN			(1 << 22)
#define RCC_APB2ENR_TIM17EN			(1 << 18)
#define RCC_APB2ENR_TIM16EN			(1 << 17)
#define RCC_APB2ENR_TIM15EN			(1 << 16)
#define RCC_APB2ENR_USART1EN			(1 << 14)
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_TIM1EN			(1 << 11)
#define RCC_APB2ENR_ADCEN			(1 << 9)
#define RCC_APB2ENR_USART8EN			(1 << 7)
#define RCC_APB2ENR_USART7EN			(1 << 6)
#define RCC_APB2ENR_USART6EN			(1 << 5)
#define RCC_APB2ENR_SYSCFGCOMPEN		(1 << 0)
/**@}*/

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@{*/
#define RCC_APB1ENR_CECEN			(1 << 30)
#define RCC_APB1ENR_DACEN			(1 << 29)
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_CRSEN			(1 << 27)
#define RCC_APB1ENR_CANEN			(1 << 25)
#define RCC_APB1ENR_USBEN			(1 << 23)
#define RCC_APB1ENR_I2C2EN			(1 << 22)
#define RCC_APB1ENR_I2C1EN			(1 << 21)
#define RCC_APB1ENR_USART5EN			(1 << 20)
#define RCC_APB1ENR_USART4EN			(1 << 19)
#define RCC_APB1ENR_USART3EN			(1 << 18)
#define RCC_APB1ENR_USART2EN			(1 << 17)
#define RCC_APB1ENR_SPI2EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_TIM14EN			(1 << 8)
#define RCC_APB1ENR_TIM7EN			(1 << 5)
#define RCC_APB1ENR_TIM6EN			(1 << 4)
#define RCC_APB1ENR_TIM3EN			(1 << 1)
#define RCC_APB1ENR_TIM2EN			(1 << 0)
/**@}*/

/* --- RCC_BDCR values ----------------------------------------------------- */

#define RCC_BDCR_BDRST				(1 << 16)
#define RCC_BDCR_RTCEN				(1 << 15)
#define RCC_BDCR_RTCSEL_SHIFT			8
#define RCC_BDCR_RTCSEL				(3 << RCC_BDCR_RTCSEL_SHIFT)
#define RCC_BDCR_RTCSEL_NOCLK			(0 << RCC_BDCR_RTCSEL_SHIFT)
#define RCC_BDCR_RTCSEL_LSE			(1 << RCC_BDCR_RTCSEL_SHIFT)
#define RCC_BDCR_RTCSEL_LSI			(2 << RCC_BDCR_RTCSEL_SHIFT)
#define RCC_BDCR_RTCSEL_HSE			(3 << RCC_BDCR_RTCSEL_SHIFT)
#define RCC_BDCR_LSEDRV_SHIFT			3
#define RCC_BDCR_LSEDRV				(3 << RCC_BDCR_LSEDRV_SHIFT)
#define RCC_BDCR_LSEDRV_LOW			(0 << RCC_BDCR_LSEDRV_SHIFT)
#define RCC_BDCR_LSEDRV_MEDLO			(1 << RCC_BDCR_LSEDRV_SHIFT)
#define RCC_BDCR_LSEDRV_MEDHI			(2 << RCC_BDCR_LSEDRV_SHIFT)
#define RCC_BDCR_LSEDRV_HIGH			(3 << RCC_BDCR_LSEDRV_SHIFT)
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
#define RCC_CSR_OBLRSTF				(1 << 25)
#define RCC_CSR_RMVF				(1 << 24)
#define RCC_CSR_RESET_FLAGS	(RCC_CSR_LPWRRSTF | RCC_CSR_WWDGRSTF |\
		RCC_CSR_IWDGRSTF | RCC_CSR_SFTRSTF | RCC_CSR_PORRSTF |\
		RCC_CSR_PINRSTF | RCC_CSR_OBLRSTF)
#define RCC_CSR_V18PWRRSTF			(1 << 23)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)

/** @defgroup rcc_ahbrstr_rst RCC_AHBRSTR reset values
@{*/
#define RCC_AHBRSTR_TSCRST			(1 << 24)
#define RCC_AHBRSTR_IOPFRST			(1 << 22)
#define RCC_AHBRSTR_IOPERST			(1 << 21)
#define RCC_AHBRSTR_IOPDRST			(1 << 20)
#define RCC_AHBRSTR_IOPCRST			(1 << 19)
#define RCC_AHBRSTR_IOPBRST			(1 << 18)
#define RCC_AHBRSTR_IOPARST			(1 << 17)
/**@}*/


/* --- RCC_CFGR2 values ---------------------------------------------------- */

#define RCC_CFGR2_PREDIV			0xf
/** @defgroup rcc_cfgr2_prediv PLL source predividers
@ingroup rcc_defines
@{*/
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
/**@}*/

/* --- RCC_CFGR3 values ---------------------------------------------------- */

#define RCC_CFGR3_USART2SW_SHIFT		16
#define RCC_CFGR3_USART2SW			(3 << RCC_CFGR3_USART2SW_SHIFT)
#define RCC_CFGR3_USART2SW_PCLK			(0 << RCC_CFGR3_USART2SW_SHIFT)
#define RCC_CFGR3_USART2SW_SYSCLK		(1 << RCC_CFGR3_USART2SW_SHIFT)
#define RCC_CFGR3_USART2SW_LSE			(2 << RCC_CFGR3_USART2SW_SHIFT)
#define RCC_CFGR3_USART2SW_HSI			(3 << RCC_CFGR3_USART2SW_SHIFT)

#define RCC_CFGR3_ADCSW				(1 << 8)
#define RCC_CFGR3_USBSW				(1 << 7)
#define RCC_CFGR3_CECSW				(1 << 6)
#define RCC_CFGR3_I2C1SW			(1 << 4)

#define RCC_CFGR3_USART1SW_SHIFT		0
#define RCC_CFGR3_USART1SW			(3 << RCC_CFGR3_USART1SW_SHIFT)
#define RCC_CFGR3_USART1SW_PCLK			(0 << RCC_CFGR3_USART1SW_SHIFT)
#define RCC_CFGR3_USART1SW_SYSCLK		(1 << RCC_CFGR3_USART1SW_SHIFT)
#define RCC_CFGR3_USART1SW_LSE			(2 << RCC_CFGR3_USART1SW_SHIFT)
#define RCC_CFGR3_USART1SW_HSI			(3 << RCC_CFGR3_USART1SW_SHIFT)

/* --- RCC_CFGR3 values ---------------------------------------------------- */

#define RCC_CR2_HSI48CAL_SHIFT			24
#define RCC_CR2_HSI48CAL			(0xFF << RCC_CR2_HSI48CAL_SHIFT)
#define RCC_CR2_HSI48RDY			(1 << 17)
#define RCC_CR2_HSI48ON				(1 << 16)
#define RCC_CR2_HSI14CAL_SHIFT			8
#define RCC_CR2_HSI14CAL			(0xFF << RCC_CR2_HSI14CAL_SHIFT)
#define RCC_CR2_HSI14TRIM_SHIFT			3
#define RCC_CR2_HSI14TRIM			(31 << RCC_CR2_HSI14TRIM_SHIFT)
#define RCC_CR2_HSI14DIS			(1 << 2)
#define RCC_CR2_HSI14RDY			(1 << 1)
#define RCC_CR2_HSI14ON				(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/* --- Variable definitions ------------------------------------------------ */
extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
/** F0 doens't _realllly_ have apb2, but it has a bunch of things
 * enabled via the "APB2" enable register. Fake it out.
 */
#define rcc_apb2_frequency rcc_apb1_frequency

enum rcc_osc {
	RCC_HSI14, RCC_HSI, RCC_HSE, RCC_PLL, RCC_LSI, RCC_LSE, RCC_HSI48
};

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

enum rcc_periph_clken {
	/* AHB peripherals */
	RCC_DMA		= _REG_BIT(0x14, 0),
	RCC_DMA1	= _REG_BIT(0x14, 0), /* Compatibility alias */
	RCC_DMA2	= _REG_BIT(0x14, 1),
	RCC_SRAM	= _REG_BIT(0x14, 2),
	RCC_FLTIF	= _REG_BIT(0x14, 4),
	RCC_CRC		= _REG_BIT(0x14, 6),
	RCC_GPIOA	= _REG_BIT(0x14, 17),
	RCC_GPIOB	= _REG_BIT(0x14, 18),
	RCC_GPIOC	= _REG_BIT(0x14, 19),
	RCC_GPIOD	= _REG_BIT(0x14, 20),
	RCC_GPIOE	= _REG_BIT(0x14, 21),
	RCC_GPIOF	= _REG_BIT(0x14, 22),
	RCC_TSC		= _REG_BIT(0x14, 24),

	/* APB2 peripherals */
	RCC_SYSCFG_COMP	= _REG_BIT(0x18, 0),
	RCC_USART6	= _REG_BIT(0x18, 5),
	RCC_USART7	= _REG_BIT(0x18, 6),
	RCC_USART8	= _REG_BIT(0x18, 7),
	RCC_ADC		= _REG_BIT(0x18, 9),
	RCC_ADC1	= _REG_BIT(0x18, 9), /* Compatibility alias */
	RCC_TIM1	= _REG_BIT(0x18, 11),
	RCC_SPI1	= _REG_BIT(0x18, 12),
	RCC_USART1	= _REG_BIT(0x18, 14),
	RCC_TIM15	= _REG_BIT(0x18, 16),
	RCC_TIM16	= _REG_BIT(0x18, 17),
	RCC_TIM17	= _REG_BIT(0x18, 18),
	RCC_DBGMCU	= _REG_BIT(0x18, 22),

	/* APB1 peripherals */
	RCC_TIM2	= _REG_BIT(0x1C, 0),
	RCC_TIM3	= _REG_BIT(0x1C, 1),
	RCC_TIM6	= _REG_BIT(0x1C, 4),
	RCC_TIM7	= _REG_BIT(0x1C, 5),
	RCC_TIM14	= _REG_BIT(0x1C, 8),
	RCC_WWDG	= _REG_BIT(0x1C, 11),
	RCC_SPI2	= _REG_BIT(0x1C, 14),
	RCC_USART2	= _REG_BIT(0x1C, 17),
	RCC_USART3	= _REG_BIT(0x1C, 18),
	RCC_USART4	= _REG_BIT(0x1C, 19),
	RCC_USART5	= _REG_BIT(0x1C, 20),
	RCC_I2C1	= _REG_BIT(0x1C, 21),
	RCC_I2C2	= _REG_BIT(0x1C, 22),
	RCC_USB		= _REG_BIT(0x1C, 23),
	RCC_CAN		= _REG_BIT(0x1C, 25),
	RCC_CAN1	= _REG_BIT(0x1C, 25), /* Compatibility alias */
	RCC_CRS		= _REG_BIT(0x1C, 27),
	RCC_PWR		= _REG_BIT(0x1C, 28),
	RCC_DAC		= _REG_BIT(0x1C, 29),
	RCC_DAC1	= _REG_BIT(0x1C, 29), /* Compatibility alias */
	RCC_CEC		= _REG_BIT(0x1C, 30),

	/* Advanced peripherals */
	RCC_RTC		= _REG_BIT(0x20, 15),/* BDCR[15] */
};

enum rcc_periph_rst {
	/* APB2 peripherals */
	RST_SYSCFG	= _REG_BIT(0x0C, 0),
	RST_ADC		= _REG_BIT(0x0C, 9),
	RST_ADC1	= _REG_BIT(0x0C, 9), /* Compatibility alias */
	RST_TIM1	= _REG_BIT(0x0C, 11),
	RST_SPI1	= _REG_BIT(0x0C, 12),
	RST_USART1	= _REG_BIT(0x0C, 14),
	RST_TIM15	= _REG_BIT(0x0C, 16),
	RST_TIM16	= _REG_BIT(0x0C, 17),
	RST_TIM17	= _REG_BIT(0x0C, 18),
	RST_DBGMCU	= _REG_BIT(0x0C, 22),

	/* APB1 peripherals */
	RST_TIM2	= _REG_BIT(0x10, 0),
	RST_TIM3	= _REG_BIT(0x10, 1),
	RST_TIM6	= _REG_BIT(0x10, 4),
	RST_TIM7	= _REG_BIT(0x10, 5),
	RST_TIM14	= _REG_BIT(0x10, 8),
	RST_WWDG	= _REG_BIT(0x10, 11),
	RST_SPI2	= _REG_BIT(0x10, 14),
	RST_USART2	= _REG_BIT(0x10, 17),
	RST_USART3	= _REG_BIT(0x10, 18),
	RST_USART4	= _REG_BIT(0x10, 19),
	RST_I2C1	= _REG_BIT(0x10, 21),
	RST_I2C2	= _REG_BIT(0x10, 22),
	RST_USB		= _REG_BIT(0x10, 23),
	RST_CAN		= _REG_BIT(0x10, 25),
	RST_CAN1	= _REG_BIT(0x10, 25), /* Compatibility alias */
	RST_CRS		= _REG_BIT(0x10, 27),
	RST_PWR		= _REG_BIT(0x10, 28),
	RST_DAC		= _REG_BIT(0x10, 29),
	RST_DAC1	= _REG_BIT(0x10, 29), /* Compatibility alias */
	RST_CEC		= _REG_BIT(0x10, 30),

	/* Advanced peripherals */
	RST_BACKUPDOMAIN = _REG_BIT(0x20, 16),/* BDCR[16] */

	/* AHB peripherals */
	RST_GPIOA	= _REG_BIT(0x28, 17),
	RST_GPIOB	= _REG_BIT(0x28, 18),
	RST_GPIOC	= _REG_BIT(0x28, 19),
	RST_GPIOD	= _REG_BIT(0x28, 20),
	RST_GPIOE	= _REG_BIT(0x28, 21),
	RST_GPIOF	= _REG_BIT(0x28, 22),
	RST_TSC		= _REG_BIT(0x28, 24),
};
#undef _REG_BIT

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS

void rcc_osc_ready_int_clear(enum rcc_osc osc);
void rcc_osc_ready_int_enable(enum rcc_osc osc);
void rcc_osc_ready_int_disable(enum rcc_osc osc);
int rcc_osc_ready_int_flag(enum rcc_osc osc);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_set_sysclk_source(enum rcc_osc clk);
void rcc_set_usbclk_source(enum rcc_osc clk);
void rcc_set_rtc_clock_source(enum rcc_osc clk);
void rcc_enable_rtc_clock(void);
void rcc_disable_rtc_clock(void);
void rcc_set_pll_multiplication_factor(uint32_t mul);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_pllxtpre(uint32_t pllxtpre);
void rcc_set_ppre(uint32_t ppre);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_prediv(uint32_t prediv);
enum rcc_osc rcc_system_clock_source(void);
void rcc_set_i2c_clock_hsi(uint32_t i2c);
void rcc_set_i2c_clock_sysclk(uint32_t i2c);
uint32_t rcc_get_i2c_clocks(void);
enum rcc_osc rcc_usb_clock_source(void);
void rcc_clock_setup_in_hse_8mhz_out_48mhz(void);
void rcc_clock_setup_in_hsi_out_48mhz(void);
void rcc_clock_setup_in_hsi48_out_48mhz(void);

END_DECLS

#endif
/**@}*/

