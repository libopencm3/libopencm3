/** @defgroup rcc_defines RCC Defines
 *
 * @ingroup STM32G0xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32G0xx Reset and Clock Control</b>
 *
 * @version 1.0.0
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
 *
 */

/**@{*/

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

#include <libopencm3/stm32/pwr.h>

/** @defgroup rcc_registers Reset and Clock Control Register
@{*/
#define RCC_CR				MMIO32(RCC_BASE + 0x00)
#define RCC_ICSCR			MMIO32(RCC_BASE + 0x04)
#define RCC_CFGR			MMIO32(RCC_BASE + 0x08)
#define RCC_PLLCFGR			MMIO32(RCC_BASE + 0x0c)
#define RCC_CIER			MMIO32(RCC_BASE + 0x18)
#define RCC_CIFR			MMIO32(RCC_BASE + 0x1c)
#define RCC_CICR			MMIO32(RCC_BASE + 0x20)
#define RCC_IOPRSTR_OFFSET			0x24
#define RCC_IOPRSTR					MMIO32(RCC_BASE + RCC_IOPRSTR_OFFSET)
#define RCC_AHBRSTR_OFFSET			0x28
#define RCC_AHBRSTR					MMIO32(RCC_BASE + RCC_AHBRSTR_OFFSET)
#define RCC_APBRSTR1_OFFSET			0x2c
#define RCC_APBRSTR1				MMIO32(RCC_BASE + RCC_APBRSTR1_OFFSET)
#define RCC_APBRSTR2_OFFSET			0x30
#define RCC_APBRSTR2				MMIO32(RCC_BASE + RCC_APBRSTR2_OFFSET)
#define RCC_IOPENR_OFFSET			0x34
#define RCC_IOPENR					MMIO32(RCC_BASE + RCC_IOPENR_OFFSET)
#define RCC_AHBENR_OFFSET			0x38
#define RCC_AHBENR					MMIO32(RCC_BASE + RCC_AHBENR_OFFSET)
#define RCC_APBENR1_OFFSET			0x3c
#define RCC_APBENR1					MMIO32(RCC_BASE + RCC_APBENR1_OFFSET)
#define RCC_APBENR2_OFFSET			0x40
#define RCC_APBENR2					MMIO32(RCC_BASE + RCC_APBENR2_OFFSET)
#define RCC_IOPSMENR_OFFSET			0x44
#define RCC_IOPSMENR				MMIO32(RCC_BASE + RCC_IOPSMENR_OFFSET)
#define RCC_AHBSMENR_OFFSET			0x48
#define RCC_AHBSMENR				MMIO32(RCC_BASE + RCC_AHBSMENR_OFFSET)
#define RCC_APBSMENR1_OFFSET		0x4c
#define RCC_APBSMENR1				MMIO32(RCC_BASE + RCC_APBSMENR1_OFFSET)
#define RCC_APBSMENR2_OFFSET		0x50
#define RCC_APBSMENR2				MMIO32(RCC_BASE + RCC_APBSMENR2_OFFSET)
#define RCC_CCIPR			MMIO32(RCC_BASE + 0x54)
#define RCC_BDCR			MMIO32(RCC_BASE + 0x5c)
#define RCC_CSR				MMIO32(RCC_BASE + 0x60)
/**@}*/

/** @defgroup rcc_cr CR Clock control Register
@{*/
#define RCC_CR_PLLRDY			(1 << 25)
#define RCC_CR_PLLON			(1 << 24)
#define RCC_CR_CSSON			(1 << 19)
#define RCC_CR_HSEBYP			(1 << 18)
#define RCC_CR_HSERDY			(1 << 17)
#define RCC_CR_HSEON			(1 << 16)

#define RCC_CR_HSIDIV_SHIFT		11
#define RCC_CR_HSIDIV_MASK		0x7
/** @defgroup rcc_cr_hsidiv HSI Div
 * @brief Division factor of the HSI16 oscillator to produce HSISYS clock
@sa rcc_cr_hsidiv
@{*/
#define RCC_CR_HSIDIV_DIV1		0
#define RCC_CR_HSIDIV_DIV2		1
#define RCC_CR_HSIDIV_DIV4		2
#define RCC_CR_HSIDIV_DIV8		3
#define RCC_CR_HSIDIV_DIV16		4
#define RCC_CR_HSIDIV_DIV32		5
#define RCC_CR_HSIDIV_DIV64		6
#define RCC_CR_HSIDIV_DIV128	7
/**@}*/

#define RCC_CR_HSIRDY			(1 << 10)
#define RCC_CR_HSIKERON			(1 << 9)
#define RCC_CR_HSION			(1 << 8)
/**@}*/


/** @defgroup rcc_icscr ICSCR Internal Clock Source Calibration Register
@{*/
#define RCC_ICSCR_HSITRIM_SHIFT		8
#define RCC_ICSCR_HSITRIM_MASK		0x1f
#define RCC_ICSCR_HSICAL_SHIFT		0
#define RCC_ICSCR_HSICAL_MASK		0xff
/**@}*/


/** @defgroup rcc_cfgr CFGR Configuration Register
@{*/
#define RCC_CFGR_MCOPRE_SHIFT	    28
#define RCC_CFGR_MCOPRE_MASK	    0x7
/** @defgroup rcc_cfgr_mcopre MCO Pre
 * @brief Division factor of microcontroler clock output
@sa rcc_cfgr_mcopre
@{*/
#define RCC_CFGR_MCOPRE_DIV1	    0
#define RCC_CFGR_MCOPRE_DIV2	    1
#define RCC_CFGR_MCOPRE_DIV4	    2
#define RCC_CFGR_MCOPRE_DIV8	    3
#define RCC_CFGR_MCOPRE_DIV16	    4
#define RCC_CFGR_MCOPRE_DIV32	    5
#define RCC_CFGR_MCOPRE_DIV64	    6
#define RCC_CFGR_MCOPRE_DIV128	    7
/**@}*/

#define RCC_CFGR_MCO_SHIFT			24
#define RCC_CFGR_MCO_MASK			0xf

/** @defgroup rcc_cfgr_mcosel MCO Sel
 * @brief Microcontroler clock output selector
@sa rcc_cfgr_mcosel
@{*/
#define RCC_CFGR_MCO_NOCLK			0x0
#define RCC_CFGR_MCO_SYSCLK			0x1
#define RCC_CFGR_MCO_HSI16			0x3
#define RCC_CFGR_MCO_HSE			0x4
#define RCC_CFGR_MCO_PLLRCLK		0x5
#define RCC_CFGR_MCO_LSI			0x6
#define RCC_CFGR_MCO_LSE			0x7
/**@}*/

#define RCC_CFGR_PPRE_MASK		0x7
#define RCC_CFGR_PPRE_SHIFT		12

/** @defgroup rcc_cfgr_ppre PPRE
 * @brief APB Prescaler
@sa rcc_cfgr_ppre
@{*/
#define RCC_CFGR_PPRE_NODIV		0x0
#define RCC_CFGR_PPRE_DIV2		0x4
#define RCC_CFGR_PPRE_DIV4		0x5
#define RCC_CFGR_PPRE_DIV8		0x6
#define RCC_CFGR_PPRE_DIV16		0x7
/**@}*/

#define RCC_CFGR_HPRE_MASK		0xf
#define RCC_CFGR_HPRE_SHIFT		8
/** @defgroup rcc_cfgr_hpre HPRE
 * @brief APB Prescaler
@sa rcc_cfgr_hpre
@{*/
#define RCC_CFGR_HPRE_NODIV		0x0
#define RCC_CFGR_HPRE_DIV2		0x8
#define RCC_CFGR_HPRE_DIV4		0x9
#define RCC_CFGR_HPRE_DIV8		0xa
#define RCC_CFGR_HPRE_DIV16		0xb
#define RCC_CFGR_HPRE_DIV64		0xc
#define RCC_CFGR_HPRE_DIV128	0xd
#define RCC_CFGR_HPRE_DIV256	0xe
#define RCC_CFGR_HPRE_DIV512	0xf
/**@}*/

#define RCC_CFGR_SWS_MASK			0x3
#define RCC_CFGR_SWS_SHIFT			3
/** @defgroup rcc_cfgr_sws SWS
 * @brief System clock switch status
@sa rcc_cfgr_sws
@{*/
#define RCC_CFGR_SWS_HSISYS			0x0
#define RCC_CFGR_SWS_HSE			0x1
#define RCC_CFGR_SWS_PLLRCLK		0x2
#define RCC_CFGR_SWS_LSI			0x3
#define RCC_CFGR_SWS_LSE			0x4
/**@}*/

#define RCC_CFGR_SW_MASK			0x3
#define RCC_CFGR_SW_SHIFT			0
/** @defgroup rcc_cfgr_sw SW
 * @brief System clock switch
@sa rcc_cfgr_sw
@{*/
#define RCC_CFGR_SW_HSISYS			0x0
#define RCC_CFGR_SW_HSE				0x1
#define RCC_CFGR_SW_PLLRCLK			0x2
#define RCC_CFGR_SW_LSI				0x3
#define RCC_CFGR_SW_LSE				0x4
/**@}*/
/**@}*/



/** @defgroup rcc_pllcfgr PLLCFGR PLL Configuration Register
@{*/
#define RCC_PLLCFGR_PLLR_SHIFT		29
#define RCC_PLLCFGR_PLLR_MASK		0x7
/** @defgroup rcc_pllcfgr_pllr PLLR
 * @brief VCO Division factor R for PLLRCLK clock output [2..8]. Frequency must not exceed 64mhz in voltage range 1, or 16mhz in voltage range 2.
@sa rcc_pllcfgr_pllr
@{*/
#define RCC_PLLCFGR_PLLR_DIV(x)		((x)-1)
/**@}*/

#define RCC_PLLCFGR_PLLREN			(1<<28)

#define RCC_PLLCFGR_PLLQ_SHIFT		25
#define RCC_PLLCFGR_PLLQ_MASK		0x7
/** @defgroup rcc_pllcfgr_pllq PLLQ
 * @brief VCO Division factor Q for PLLQCLK clock output [2..8]. Frequency must not exceed 128mhz in voltage range 1, or 32mhz in range 2
@sa rcc_pllcfgr_pllq
@{*/
#define RCC_PLLCFGR_PLLQ_DIV(x)		((x)-1)
/**@}*/

#define RCC_PLLCFGR_PLLQEN		(1 << 24)

#define RCC_PLLCFGR_PLLP_SHIFT		17
#define RCC_PLLCFGR_PLLP_MASK		0x1f
/** @defgroup rcc_pllcfgr_pllp PLLP
 * @brief VCO Division factor P for PLLPCLK clock output [2..32]. Frequency must not exceed 122mhz in voltage range 1, or 40mhz in range 2
@sa rcc_pllcfgr_pllp
@{*/
#define RCC_PLLCFGR_PLLP_DIV(x)		((x)-1)
/**@}*/

#define RCC_PLLCFGR_PLLPEN			(1 << 16)

#define RCC_PLLCFGR_PLLN_SHIFT		0x8
#define RCC_PLLCFGR_PLLN_MASK		0x7f
/** @defgroup rcc_pllcfgr_plln PLLN
 * @brief Multiplication factor N [8..86] for PLL VCO output frequency. Frequency must be between 64mhz and 344mhz.
@{*/
#define RCC_PLLCFGR_PLLN_MUL(x)		(x)
/**@}*/

#define RCC_PLLCFGR_PLLM_SHIFT		0x4
#define RCC_PLLCFGR_PLLM_MASK		0x7
/** @defgroup rcc_pllcfgr_pllm PLLM
 * @brief Division factor M [1..8] for PLL input clock. Input frequency must be between 4mhz and 16mhz. 
@{*/
#define RCC_PLLCFGR_PLLM_DIV(x)		((x)-1)
/**@}*/

#define RCC_PLLCFGR_PLLSRC_SHIFT	0
#define RCC_PLLCFGR_PLLSRC_MASK		0x3
/** @defgroup rcc_pllcfgr_pllsrc PLLSRC
 * @brief PLL input clock source
@sa rcc_pllcfgr_pllsrc
@{*/
#define RCC_PLLCFGR_PLLSRC_NONE		0
#define RCC_PLLCFGR_PLLSRC_HSI16	2
#define RCC_PLLCFGR_PLLSRC_HSE		3
/**@}*/
/**@}*/

/** @defgroup rcc_cier CIER Clock Interrupt Enable Register
@{*/
#define RCC_CIER_PLLRDYIE			(1 << 5)
#define RCC_CIER_HSERDYIE			(1 << 4)
#define RCC_CIER_HSIRDYIE			(1 << 3)
#define RCC_CIER_LSERDYIE			(1 << 1)
#define RCC_CIER_LSIRDYIE			(1 << 0)
/**@}*/

/** @defgroup rcc_cifr CIFR Clock Interrupt Flag Register
@{*/
#define RCC_CIFR_LSECSSF			(1 << 9)
#define RCC_CIFR_CSSF				(1 << 8)
#define RCC_CIFR_PLLRDYF			(1 << 5)
#define RCC_CIFR_HSERDYF			(1 << 4)
#define RCC_CIFR_HSIRDYF			(1 << 3)
#define RCC_CIFR_LSERDYF			(1 << 1)
#define RCC_CIFR_LSIRDYF			(1 << 0)
/**@}*/

/** @defgroup rcc_cicr CICR Clock Interrupt Clear Register
@{*/
#define RCC_CICR_LSECSSC			(1 << 9)
#define RCC_CICR_CSSC				(1 << 8)
#define RCC_CICR_PLLRDYC			(1 << 5)
#define RCC_CICR_HSERDYC			(1 << 4)
#define RCC_CICR_HSIRDYC			(1 << 3)
#define RCC_CICR_LSERDYC			(1 << 1)
#define RCC_CICR_LSIRDYC			(1 << 0)
/**@}*/

/** @defgroup rcc_ahbrstr_rst RCC_AHBRSTR reset values
@{*/
#define RCC_AHBRSTR_RNGRST			(1 << 18)
#define RCC_AHBRSTR_AESRST			(1 << 16)
#define RCC_AHBRSTR_CRCRST			(1 << 12)
#define RCC_AHBRSTR_FLASHRST		(1 << 8)
#define RCC_AHBRSTR_DMARST			(1 << 0)
/**@}*/

/** @defgroup rcc_apb1rstr_rst RCC_APBRSTRx reset values (full set)
@{*/
/** @defgroup rcc_apbrstr1_rst RCC_APBRSTR1 reset values
@{*/
#define RCC_APBRSTR1_LPTIM1RST			(1 << 31)
#define RCC_APBRSTR1_LPTIM2RST			(1 << 30)
#define RCC_APBRSTR1_DAC1RST			(1 << 29)
#define RCC_APBRSTR1_PWRRST				(1 << 28)
#define RCC_APBRSTR1_DBGRST				(1 << 27)
#define RCC_APBRSTR1_UCPD2RST			(1 << 26)
#define RCC_APBRSTR1_UCPD1RST			(1 << 25)
#define RCC_APBRSTR1_I2C2RST			(1 << 22)
#define RCC_APBRSTR1_I2C1RST			(1 << 21)
#define RCC_APBRSTR1_LPUART1RST			(1 << 20)
#define RCC_APBRSTR1_USART4RST			(1 << 19)
#define RCC_APBRSTR1_USART3RST			(1 << 18)
#define RCC_APBRSTR1_USART2RST			(1 << 17)
#define RCC_APBRSTR1_SPI2RST			(1 << 14)
#define RCC_APBRSTR1_TIM7RST			(1 << 5)
#define RCC_APBRSTR1_TIM6RST			(1 << 4)
#define RCC_APBRSTR1_TIM3RST			(1 << 1)
#define RCC_APBRSTR1_TIM2RST			(1 << 0)
/**@}*/

/** @defgroup rcc_apbrstr2_rst RCC_APBRSTR2 reset values
@{*/
#define RCC_APBRSTR2_ADCRST				(1 << 20)
#define RCC_APBRSTR2_TIM17RST			(1 << 18)
#define RCC_APBRSTR2_TIM16RST			(1 << 17)
#define RCC_APBRSTR2_TIM16RST			(1 << 17)
#define RCC_APBRSTR2_TIM15RST			(1 << 16)
#define RCC_APBRSTR2_TIM14RST			(1 << 15)
#define RCC_APBRSTR2_USART1RST			(1 << 14)
#define RCC_APBRSTR2_SPI1RST			(1 << 12)
#define RCC_APBRSTR2_TIM1RST			(1 << 11)
#define RCC_APBRSTR2_SYSCFGRST			(1 << 0)
/**@}*/
/**@}*/

/** @defgroup rcc_ahbenr_en RCC_AHBENR enable values
@{*/
#define RCC_AHBENR_RNGEN			(1 << 18)
#define RCC_AHBENR_AESEN			(1 << 16)
#define RCC_AHBENR_CRCEN			(1 << 12)
#define RCC_AHBENR_FLASHEN			(1 << 8)
#define RCC_AHBENR_DMAEN			(1 << 0)
/**@}*/

/** @defgroup rcc_apb1enr_en RCC_APBENRx enable values (full set)
@{*/
/** @defgroup rcc_apbenr1_en RCC_APBENR1 enable values
@{*/
#define RCC_APBENR1_LPTIM1EN		(1 << 31)
#define RCC_APBENR1_LPTIM2EN		(1 << 30)
#define RCC_APBENR1_DAC1EN			(1 << 29)
#define RCC_APBENR1_PWREN			(1 << 28)
#define RCC_APBENR1_DBGEN			(1 << 27)
#define RCC_APBENR1_UCPD2EN			(1 << 26)
#define RCC_APBENR1_UCPD1EN			(1 << 25)
#define RCC_APBENR1_CECEN			(1 << 24)
#define RCC_APBENR1_I2C2EN			(1 << 22)
#define RCC_APBENR1_I2C1EN			(1 << 21)
#define RCC_APBENR1_LPUART1EN		(1 << 20)
#define RCC_APBENR1_USART4EN		(1 << 19)
#define RCC_APBENR1_USART3EN		(1 << 18)
#define RCC_APBENR1_USART2EN		(1 << 17)
#define RCC_APBENR1_SPI2EN			(1 << 14)
#define RCC_APBENR1_WWDGEN			(1 << 11)
#define RCC_APBENR1_RTCAPBEN		(1 << 10)
#define RCC_APBENR1_TIM7EN			(1 << 5)
#define RCC_APBENR1_TIM6EN			(1 << 4)
#define RCC_APBENR1_TIM3EN			(1 << 1)
#define RCC_APBENR1_TIM2EN			(1 << 0)
/**@}*/

/** @defgroup rcc_apbenr2_en RCC_APBENR2 enable values
@{*/
#define RCC_APBENR2_ADCEN			(1 << 20)
#define RCC_APBENR2_TIM17EN			(1 << 18)
#define RCC_APBENR2_TIM16EN			(1 << 17)
#define RCC_APBENR2_TIM16EN			(1 << 17)
#define RCC_APBENR2_TIM15EN			(1 << 16)
#define RCC_APBENR2_TIM14EN			(1 << 15)
#define RCC_APBENR2_USART1EN		(1 << 14)
#define RCC_APBENR2_SPI1EN			(1 << 12)
#define RCC_APBENR2_TIM1EN			(1 << 11)
#define RCC_APBENR2_SYSCFGEN		(1 << 0)
/**@}*/
/**@}*/

/** @defgroup rcc_aphbsmenr_en RCC_AHBSMENR enable in sleep/stop mode values
@{*/
#define RCC_AHBSMENR_RNGSMEN			(1 << 18)
#define RCC_AHBSMENR_AESSMEN			(1 << 16)
#define RCC_AHBSMENR_CRCSMEN			(1 << 12)
#define RCC_AHBSMENR_SRAMSMEN			(1 << 9)
#define RCC_AHBSMENR_FLASHSMEN			(1 << 8)
#define RCC_AHBSMENR_DMASMEN			(1 << 0)
/**@}*/

/** @defgroup rcc_apbsmenr_en RCC_APBSMENR1 enable in sleep/stop mode values
@{*/
#define RCC_APBSMENR1_LPTIM1SMEN		(1 << 31)
#define RCC_APBSMENR1_LPTIM2SMEN		(1 << 30)
#define RCC_APBSMENR1_DAC1SMEN			(1 << 29)
#define RCC_APBSMENR1_PWRSMEN			(1 << 28)
#define RCC_APBSMENR1_DBGSMEN			(1 << 27)
#define RCC_APBSMENR1_UCPD2SMEN			(1 << 26)
#define RCC_APBSMENR1_UCPD1SMEN			(1 << 25)
#define RCC_APBSMENR1_CECSMEN			(1 << 24)
#define RCC_APBSMENR1_I2C2SMEN			(1 << 22)
#define RCC_APBSMENR1_I2C1SMEN			(1 << 21)
#define RCC_APBSMENR1_LPUART1SMEN		(1 << 20)
#define RCC_APBSMENR1_USART4SMEN		(1 << 19)
#define RCC_APBSMENR1_USART3SMEN		(1 << 18)
#define RCC_APBSMENR1_USART2SMEN		(1 << 17)
#define RCC_APBSMENR1_SPI2SMEN			(1 << 14)
#define RCC_APBSMENR1_WWDGSMEN			(1 << 11)
#define RCC_APBSMENR1_RTCAPBSMEN			(1 << 10)
#define RCC_APBSMENR1_TIM7SMEN			(1 << 5)
#define RCC_APBSMENR1_TIM6SMEN			(1 << 4)
#define RCC_APBSMENR1_TIM3SMEN			(1 << 1)
#define RCC_APBSMENR1_TIM2SMEN			(1 << 0)
/**@}*/

/** @defgroup rcc_apbsmenr2_en RCC_APBSMENR2 enable in sleep/stop mode values
@{*/
#define RCC_APBSMENR2_ADCSMEN			(1 << 20)
#define RCC_APBSMENR2_TIM17SMEN			(1 << 18)
#define RCC_APBSMENR2_TIM16SMEN			(1 << 17)
#define RCC_APBSMENR2_TIM16SMEN			(1 << 17)
#define RCC_APBSMENR2_TIM15SMEN			(1 << 16)
#define RCC_APBSMENR2_TIM14SMEN			(1 << 15)
#define RCC_APBSMENR2_USART1SMEN		(1 << 14)
#define RCC_APBSMENR2_SPI1SMEN			(1 << 12)
#define RCC_APBSMENR2_TIM1SMEN			(1 << 11)
#define RCC_APBSMENR2_SYSCFGSMEN		(1 << 0)
/**@}*/


/** @defgroup rcc_ccipr CCIPR Peripherals Independent Clock Config Register
@{*/
#define RCC_CCIPR_ADCSEL_MASK		0x3
#define RCC_CCIPR_ADCSEL_SHIFT		30
/** @defgroup rcc_ccipr_adcsel ADCSEL
@{*/
#define RCC_CCIPR_ADCSEL_SYSCLK		0
#define RCC_CCIPR_ADCSEL_PLLPCLK	1
#define RCC_CCIPR_ADCSEL_HSI16		2
/**@}*/

#define RCC_CCIPR_RNGDIV_MASK		0x3
#define RCC_CCIPR_RNGDIV_SHIFT		28
/** @defgroup rcc_ccipr_rngdiv RNGDIV
@{*/
#define RCC_CCIPR_RNGDIV_1		0
#define RCC_CCIPR_RNGDIV_2 		1
#define RCC_CCIPR_RNGDIV_4		2
#define RCC_CCIPR_RNGDIV_8		3
/**@}*/

#define RCC_CCIPR_RNGSEL_MASK		0x3
#define RCC_CCIPR_RNGSEL_SHIFT		26
/** @defgroup rcc_ccipr_rngsel RNGSEL
@{*/
#define RCC_CCIPR_RNGSEL_NONE		0
#define RCC_CCIPR_RNGSEL_HSI16 		1
#define RCC_CCIPR_RNGSEL_SYSCLK		2
#define RCC_CCIPR_RNGSEL_PLLQCLK	3
/**@}*/

#define RCC_CCIPR_TIM15SEL_MASK		0x1
#define RCC_CCIPR_TIM15SEL_SHIFT	24
/** @defgroup rcc_ccipr_tim15sel TIM15SEL
@{*/
#define RCC_CCIPR_TIM15SEL_TIMPCLK		0
#define RCC_CCIPR_TIM15SEL_PLLQCLK 		1
/**@}*/

#define RCC_CCIPR_TIM1SEL_MASK		0x1
#define RCC_CCIPR_TIM1SEL_SHIFT		20
/** @defgroup rcc_ccipr_tim1sel TIM1SEL
@{*/
#define RCC_CCIPR_TIM1SEL_TIMPCLK		0
#define RCC_CCIPR_TIM1SEL_PLLQCLK 		1
/**@}*/

#define RCC_CCIPR_LPTIM2SEL_MASK		0x3
#define RCC_CCIPR_LPTIM2SEL_SHIFT		20
/** @defgroup rcc_ccipr_lptim2sel LPTIM2SEL LPTIM2 Clock source selection
@{*/
#define RCC_CCIPR_LPTIM2SEL_PCLK		0
#define RCC_CCIPR_LPTIM2SEL_LSI		 	1
#define RCC_CCIPR_LPTIM2SEL_HSI16 		2
#define RCC_CCIPR_LPTIM2SEL_LSE			3
/**@}*/

#define RCC_CCIPR_LPTIM1SEL_MASK		0x3
#define RCC_CCIPR_LPTIM1SEL_SHIFT		18
/** @defgroup rcc_ccipr_lptim1sel LPTIM1SEL LPTIM1 Clock source selection
@{*/
#define RCC_CCIPR_LPTIM1SEL_PCLK		0
#define RCC_CCIPR_LPTIM1SEL_LSI			1
#define RCC_CCIPR_LPTIM1SEL_HSI16 		2
#define RCC_CCIPR_LPTIM1SEL_LSE			3
/**@}*/

#define RCC_CCIPR_I2S1SEL_MASK		0x3
#define RCC_CCIPR_I2S1SEL_SHIFT		14
/** @defgroup rcc_ccipr_i2s1sel I2S1SEL I2S1 Clock source selection
@{*/
#define RCC_CCIPR_I2S1SEL_SYSCLK		0
#define RCC_CCIPR_I2S1SEL_PLLPLCK		1
#define RCC_CCIPR_I2S1SEL_HSI16 		2
#define RCC_CCIPR_I2S1SEL_I2S_CKIN 		2
/**@}*/

#define RCC_CCIPR_I2C1SEL_MASK		0x3
#define RCC_CCIPR_I2C1SEL_SHIFT		12
/** @defgroup rcc_ccipr_i2c1sel I2C1SEL I2C1 Clock source selection
@{*/
#define RCC_CCIPR_I2C1SEL_PCLK			0
#define RCC_CCIPR_I2C1SEL_SYSCLK		1
#define RCC_CCIPR_I2C1SEL_HSI16 		2
/**@}*/

#define RCC_CCIPR_LPUART1SEL_MASK		0x3
#define RCC_CCIPR_LPUART1SEL_SHIFT		10
/** @defgroup rcc_ccipr_lpuart1sel LPUART1SEL LPUART1 Clock source selection
@{*/
#define RCC_CCIPR_LPUART1SEL_PCLK			0
#define RCC_CCIPR_LPUART1SEL_SYSCLK			1
#define RCC_CCIPR_LPUART1SEL_HSI16 			2
#define RCC_CCIPR_LPUART1SEL_LSE			3
/**@}*/

#define RCC_CCIPR_CECSEL_MASK			0x1
#define RCC_CCIPR_CECSEL_SHIFT			6
/** @defgroup rcc_ccipr_cecsel CECSEL CEC Clock souce selection
@{*/
#define RCC_CCIPR_CECSEL_HSI16			0
#define RCC_CCIPR_CECSEL_LSE 			1
/**@}*/

#define RCC_CCIPR_USART2SEL_MASK		0x3
#define RCC_CCIPR_USART2SEL_SHIFT		2
/** @defgroup rcc_ccipr_usart2sel USART2SEL USART2 Clock source selection
@{*/
#define RCC_CCIPR_USART2SEL_PCLK		0
#define RCC_CCIPR_USART2SEL_SYSCLK	 	1
#define RCC_CCIPR_USART2SEL_HSI16 		2
#define RCC_CCIPR_USART2SEL_LSE			3
/**@}*/

#define RCC_CCIPR_USART1SEL_MASK		0x3
#define RCC_CCIPR_USART1SEL_SHIFT		0
/** @defgroup rcc_ccipr_usart1sel USART1SEL USART1 Clock source selection
@{*/
#define RCC_CCIPR_USART1SEL_PCLK		0
#define RCC_CCIPR_USART1SEL_SYSCLK		1
#define RCC_CCIPR_USART1SEL_HSI16 		2
#define RCC_CCIPR_USART1SEL_LSE			3
/**@}*/
/**@}*/

/** @defgroup rcc_bdcr BDCR Backup Domain Control Register
@{*/
#define RCC_BDCR_LSCOSEL		(1 << 25)
#define RCC_BDCR_LSCOEN			(1 << 24)
#define RCC_BDCR_BDRST			(1 << 16)
#define RCC_BDCR_RTCEN			(1 << 15)

#define RCC_BDCR_RTCSEL_SHIFT		8
#define RCC_BDCR_RTCSEL_MASK		0x3
/** @defgroup rcc_bdcr_rtcsel RTCSEL RTC Clock source selection
@{*/
#define RCC_BDCR_RTCSEL_NONE		0
#define RCC_BDCR_RTCSEL_LSE		1
#define RCC_BDCR_RTCSEL_LSI		2
#define RCC_BDCR_RTCSEL_HSE_DIV32	3
/**@}*/

#define RCC_BDCR_LSEDRV_SHIFT		3
#define RCC_BDCR_LSEDRV_MASK		0x3
/** @defgroup rcc_bdcr_lsedrv LSEDRV LSE Oscillator drive capacity
@{*/
#define RCC_BDCR_LSEDRV_LOW			0
#define RCC_BDCR_LSEDRV_MEDLOW		1
#define RCC_BDCR_LSEDRV_MEDHIGH		2
#define RCC_BDCR_LSEDRV_HIGH		3
/**@}*/

#define RCC_BDCR_LSEBYP				(1 << 2)
#define RCC_BDCR_LSERDY				(1 << 1)
#define RCC_BDCR_LSEON				(1 << 0)
/**@}*/

/** @defgroup rcc_csr CSR Control and Status Register
@{*/
#define RCC_CSR_LPWRRSTF			(1 << 31)
#define RCC_CSR_WWDGRSTF			(1 << 30)
#define RCC_CSR_IWDGRSTF			(1 << 29)
#define RCC_CSR_SFTRSTF				(1 << 28)
#define RCC_CSR_PWRSTF				(1 << 27)
#define RCC_CSR_PINRSTF				(1 << 26)
#define RCC_CSR_OBLRSTF				(1 << 25)
#define RCC_CSR_RMVF				(1 << 23)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)
/**@}*/

/* --- Variable definitions ------------------------------------------------ */

extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
/*
 * as done for F0, fake out apb2_frequency as the device does not really have
 * apb2 clock.
 */
#define rcc_apb2_frequency rcc_apb1_frequency

/* --- Function prototypes ------------------------------------------------- */
 
#define _REG_BIT(offset, bit)            (((offset) << 5) + (bit))

enum rcc_osc {
	RCC_HSI,
	RCC_HSE,
	RCC_PLL,
	RCC_LSE,
	RCC_LSI,
};

enum rcc_periph_clken {
	RCC_GPIOF = _REG_BIT(RCC_IOPENR_OFFSET, 5),
	RCC_GPIOE = _REG_BIT(RCC_IOPENR_OFFSET, 4),
	RCC_GPIOD = _REG_BIT(RCC_IOPENR_OFFSET, 3),
	RCC_GPIOC = _REG_BIT(RCC_IOPENR_OFFSET, 2),
	RCC_GPIOB = _REG_BIT(RCC_IOPENR_OFFSET, 1),
	RCC_GPIOA = _REG_BIT(RCC_IOPENR_OFFSET, 0),

	RCC_RNG = _REG_BIT(RCC_AHBENR_OFFSET, 18),
	RCC_AES = _REG_BIT(RCC_AHBENR_OFFSET, 16),
	RCC_CRC = _REG_BIT(RCC_AHBENR_OFFSET, 12),
	RCC_FLASH = _REG_BIT(RCC_AHBENR_OFFSET, 8),
	RCC_DMA = _REG_BIT(RCC_AHBENR_OFFSET, 0),
	RCC_DMA1 = _REG_BIT(RCC_AHBENR_OFFSET, 0), /* Compatibility */

	RCC_LPTIM1 = _REG_BIT(RCC_APBENR1_OFFSET, 31),
	RCC_LPTIM2 = _REG_BIT(RCC_APBENR1_OFFSET, 30),
	RCC_DAC1 = _REG_BIT(RCC_APBENR1_OFFSET, 29),
	RCC_PWR = _REG_BIT(RCC_APBENR1_OFFSET, 28),
	RCC_DBG = _REG_BIT(RCC_APBENR1_OFFSET, 27),
	RCC_UCPD1 = _REG_BIT(RCC_APBENR1_OFFSET, 26),
	RCC_UCPD2 = _REG_BIT(RCC_APBENR1_OFFSET, 25),
	RCC_CEC = _REG_BIT(RCC_APBENR1_OFFSET, 24),
	RCC_I2C2 = _REG_BIT(RCC_APBENR1_OFFSET, 22),
	RCC_I2C1 = _REG_BIT(RCC_APBENR1_OFFSET, 21),
	RCC_LPUART1 = _REG_BIT(RCC_APBENR1_OFFSET, 20),
	RCC_USART4 = _REG_BIT(RCC_APBENR1_OFFSET, 19),
	RCC_USART3 = _REG_BIT(RCC_APBENR1_OFFSET, 18),
	RCC_USART2 = _REG_BIT(RCC_APBENR1_OFFSET, 17),
	RCC_SPI2 = _REG_BIT(RCC_APBENR1_OFFSET, 14),
	RCC_TIM7 = _REG_BIT(RCC_APBENR1_OFFSET, 5),
	RCC_TIM6 = _REG_BIT(RCC_APBENR1_OFFSET, 4),
	RCC_TIM3 = _REG_BIT(RCC_APBENR1_OFFSET, 1),
	RCC_TIM2 = _REG_BIT(RCC_APBENR1_OFFSET, 0),

	RCC_ADC = _REG_BIT(RCC_APBENR2_OFFSET, 20),
	RCC_TIM17 = _REG_BIT(RCC_APBENR2_OFFSET, 18),
	RCC_TIM16 = _REG_BIT(RCC_APBENR2_OFFSET, 17),
	RCC_TIM15 = _REG_BIT(RCC_APBENR2_OFFSET, 16),
	RCC_TIM14 = _REG_BIT(RCC_APBENR2_OFFSET, 15),
	RCC_USART1 = _REG_BIT(RCC_APBENR2_OFFSET, 14),
	RCC_SPI1 = _REG_BIT(RCC_APBENR2_OFFSET, 12),
	RCC_TIM1 = _REG_BIT(RCC_APBENR2_OFFSET, 11),
	RCC_SYSCFG = _REG_BIT(RCC_APBENR2_OFFSET, 0),

	SCC_GPIOF = _REG_BIT(RCC_IOPSMENR_OFFSET, 5),
	SCC_GPIOE = _REG_BIT(RCC_IOPSMENR_OFFSET, 4),
	SCC_GPIOD = _REG_BIT(RCC_IOPSMENR_OFFSET, 3),
	SCC_GPIOC = _REG_BIT(RCC_IOPSMENR_OFFSET, 2),
	SCC_GPIOB = _REG_BIT(RCC_IOPSMENR_OFFSET, 1),
	SCC_GPIOA = _REG_BIT(RCC_IOPSMENR_OFFSET, 0),

	SCC_RNG = _REG_BIT(RCC_AHBSMENR_OFFSET, 18),
	SCC_AES = _REG_BIT(RCC_AHBSMENR_OFFSET, 16),
	SCC_CRC = _REG_BIT(RCC_AHBSMENR_OFFSET, 12),
	SCC_FLASH = _REG_BIT(RCC_AHBSMENR_OFFSET, 8),
	SCC_DMA = _REG_BIT(RCC_AHBSMENR_OFFSET, 0),
	SCC_DMA1 = _REG_BIT(RCC_AHBSMENR_OFFSET, 0), /* Compatibility */

	SCC_LPTIM1 = _REG_BIT(RCC_APBSMENR1_OFFSET, 31),
	SCC_LPTIM2 = _REG_BIT(RCC_APBSMENR1_OFFSET, 30),
	SCC_DAC1 = _REG_BIT(RCC_APBSMENR1_OFFSET, 29),
	SCC_PWR = _REG_BIT(RCC_APBSMENR1_OFFSET, 28),
	SCC_DBG = _REG_BIT(RCC_APBSMENR1_OFFSET, 27),
	SCC_UCPD1 = _REG_BIT(RCC_APBSMENR1_OFFSET, 26),
	SCC_UCPD2 = _REG_BIT(RCC_APBSMENR1_OFFSET, 25),
	SCC_CEC = _REG_BIT(RCC_APBSMENR1_OFFSET, 24),
	SCC_I2C2 = _REG_BIT(RCC_APBSMENR1_OFFSET, 22),
	SCC_I2C1 = _REG_BIT(RCC_APBSMENR1_OFFSET, 21),
	SCC_LPUART1 = _REG_BIT(RCC_APBSMENR1_OFFSET, 20),
	SCC_USART4 = _REG_BIT(RCC_APBSMENR1_OFFSET, 19),
	SCC_USART3 = _REG_BIT(RCC_APBSMENR1_OFFSET, 18),
	SCC_USART2 = _REG_BIT(RCC_APBSMENR1_OFFSET, 17),
	SCC_SPI2 = _REG_BIT(RCC_APBSMENR1_OFFSET, 14),
	SCC_TIM7 = _REG_BIT(RCC_APBSMENR1_OFFSET, 5),
	SCC_TIM6 = _REG_BIT(RCC_APBSMENR1_OFFSET, 4),
	SCC_TIM3 = _REG_BIT(RCC_APBSMENR1_OFFSET, 1),
	SCC_TIM2 = _REG_BIT(RCC_APBSMENR1_OFFSET, 0),

	SCC_ADC = _REG_BIT(RCC_APBSMENR2_OFFSET, 20),
	SCC_TIM17 = _REG_BIT(RCC_APBSMENR2_OFFSET, 18),
	SCC_TIM16 = _REG_BIT(RCC_APBSMENR2_OFFSET, 17),
	SCC_TIM15 = _REG_BIT(RCC_APBSMENR2_OFFSET, 16),
	SCC_TIM14 = _REG_BIT(RCC_APBSMENR2_OFFSET, 15),
	SCC_USART1 = _REG_BIT(RCC_APBSMENR2_OFFSET, 14),
	SCC_SPI1 = _REG_BIT(RCC_APBSMENR2_OFFSET, 12),
	SCC_TIM1 = _REG_BIT(RCC_APBSMENR2_OFFSET, 11),
	SCC_SYSCFG = _REG_BIT(RCC_APBSMENR2_OFFSET, 0),
};

enum rcc_periph_rst {
	RST_GPIOF = _REG_BIT(RCC_IOPRSTR_OFFSET, 5),
	RST_GPIOE = _REG_BIT(RCC_IOPRSTR_OFFSET, 4),
	RST_GPIOD = _REG_BIT(RCC_IOPRSTR_OFFSET, 3),
	RST_GPIOC = _REG_BIT(RCC_IOPRSTR_OFFSET, 2),
	RST_GPIOB = _REG_BIT(RCC_IOPRSTR_OFFSET, 1),
	RST_GPIOA = _REG_BIT(RCC_IOPRSTR_OFFSET, 0),

	RST_RNG = _REG_BIT(RCC_AHBRSTR_OFFSET, 18),
	RST_AES = _REG_BIT(RCC_AHBRSTR_OFFSET, 16),
	RST_CRC = _REG_BIT(RCC_AHBRSTR_OFFSET, 12),
	RST_FLASH = _REG_BIT(RCC_AHBRSTR_OFFSET, 8),
	RST_DMA = _REG_BIT(RCC_AHBRSTR_OFFSET, 0),
	RST_DMA1 = _REG_BIT(RCC_AHBRSTR_OFFSET, 0), /* Compatibility */

	RST_LPTIM1 = _REG_BIT(RCC_APBRSTR1_OFFSET, 31),
	RST_LPTIM2 = _REG_BIT(RCC_APBRSTR1_OFFSET, 30),
	RST_DAC1 = _REG_BIT(RCC_APBRSTR1_OFFSET, 29),
	RST_PWR = _REG_BIT(RCC_APBRSTR1_OFFSET, 28),
	RST_DBG = _REG_BIT(RCC_APBRSTR1_OFFSET, 27),
	RST_UCPD1 = _REG_BIT(RCC_APBRSTR1_OFFSET, 26),
	RST_UCPD2 = _REG_BIT(RCC_APBRSTR1_OFFSET, 25),
	RST_CEC = _REG_BIT(RCC_APBRSTR1_OFFSET, 24),
	RST_I2C2 = _REG_BIT(RCC_APBRSTR1_OFFSET, 22),
	RST_I2C1 = _REG_BIT(RCC_APBRSTR1_OFFSET, 21),
	RST_LPUART1 = _REG_BIT(RCC_APBRSTR1_OFFSET, 20),
	RST_USART4 = _REG_BIT(RCC_APBRSTR1_OFFSET, 19),
	RST_USART3 = _REG_BIT(RCC_APBRSTR1_OFFSET, 18),
	RST_USART2 = _REG_BIT(RCC_APBRSTR1_OFFSET, 17),
	RST_SPI2 = _REG_BIT(RCC_APBRSTR1_OFFSET, 14),
	RST_TIM7 = _REG_BIT(RCC_APBRSTR1_OFFSET, 5),
	RST_TIM6 = _REG_BIT(RCC_APBRSTR1_OFFSET, 4),
	RST_TIM3 = _REG_BIT(RCC_APBRSTR1_OFFSET, 1),
	RST_TIM2 = _REG_BIT(RCC_APBRSTR1_OFFSET, 0),

	RST_ADC = _REG_BIT(RCC_APBRSTR2_OFFSET, 20),
	RST_TIM17 = _REG_BIT(RCC_APBRSTR2_OFFSET, 18),
	RST_TIM16 = _REG_BIT(RCC_APBRSTR2_OFFSET, 17),
	RST_TIM15 = _REG_BIT(RCC_APBRSTR2_OFFSET, 16),
	RST_TIM14 = _REG_BIT(RCC_APBRSTR2_OFFSET, 15),
	RST_USART1 = _REG_BIT(RCC_APBRSTR2_OFFSET, 14),
	RST_SPI1 = _REG_BIT(RCC_APBRSTR2_OFFSET, 12),
	RST_TIM1 = _REG_BIT(RCC_APBRSTR2_OFFSET, 11),
	RST_SYSCFG = _REG_BIT(RCC_APBRSTR2_OFFSET, 0),
};

struct rcc_clock_scale {
	enum rcc_osc sysclock_source;
		
	/* PLL as sysclock source cfg */
	uint8_t pll_source;
	uint8_t pll_div;
	uint8_t pll_mul;
	uint8_t pllp_div;
	uint8_t pllq_div;
	uint8_t pllr_div;

	/* HSI as sysclock source cfg */
	uint8_t hsisys_div;

	uint8_t hpre;
	uint8_t ppre;
	uint8_t flash_waitstates;
	enum pwr_vos_scale voltage_scale;
	uint32_t ahb_frequency;
	uint32_t apb_frequency;
};

enum rcc_clock {
	RCC_CLOCK_CONFIG_LSI_32KHZ,
	RCC_CLOCK_CONFIG_HSI_4MHZ,
	RCC_CLOCK_CONFIG_HSI_16MHZ,
	RCC_CLOCK_CONFIG_HSI_PLL_32MHZ,
	RCC_CLOCK_CONFIG_HSI_PLL_64MHZ,
	RCC_CLOCK_CONFIG_HSE_12MHZ_PLL_64MHZ,
	RCC_CLOCK_CONFIG_END
};

extern const struct rcc_clock_scale rcc_clock_config[RCC_CLOCK_CONFIG_END];

#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS

void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);

void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);

void rcc_set_sysclk_source(enum rcc_osc osc);
void rcc_wait_for_sysclk_status(enum rcc_osc osc);
enum rcc_osc rcc_system_clock_source(void);

void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_main_pll(uint32_t source, uint32_t pllm, uint32_t plln, uint32_t pllp, uint32_t pllq, uint32_t pllr);
void rcc_enable_pllp(bool enable);
void rcc_enable_pllq(bool enable);
void rcc_enable_pllr(bool enable);

void rcc_set_ppre(uint32_t ppre);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_hsisys_div(uint32_t hsidiv);
void rcc_set_mcopre(uint32_t mcopre);

void rcc_clock_setup(const struct rcc_clock_scale *clock);

void rcc_set_rng_clk_div(uint32_t rng_div);
void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t sel);

END_DECLS

/**@}*/

#endif
