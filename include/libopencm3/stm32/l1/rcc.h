/** @defgroup rcc_defines RCC Defines
 *
 * @ingroup STM32L1xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32L1xx Reset and Clock
 * Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
 * @author @htmlonly &copy; @endhtmlonly 2009
 * Uwe Hermann <uwe@hermann-uwe.de>
 * @author @htmlonly &copy; @endhtmlonly 2012
 * Karl Palsson <karlp@tweak.net.au>
 *
 * @date 11 November 2012
 *
 * LGPL License Terms @ref lgpl_license
 *  */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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
 * Originally based on the F1 code, as it seemed most similar to the L1
 * TODO: very incomplete still!
 */

/**@{*/

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

#include <libopencm3/stm32/pwr.h>

/* --- RCC registers ------------------------------------------------------- */

#define RCC_CR					MMIO32(RCC_BASE + 0x00)
#define RCC_ICSCR				MMIO32(RCC_BASE + 0x04)
#define RCC_CFGR				MMIO32(RCC_BASE + 0x08)
#define RCC_CIR					MMIO32(RCC_BASE + 0x0c)
#define RCC_AHBRSTR				MMIO32(RCC_BASE + 0x10)
#define RCC_APB2RSTR				MMIO32(RCC_BASE + 0x14)
#define RCC_APB1RSTR				MMIO32(RCC_BASE + 0x18)
#define RCC_AHBENR				MMIO32(RCC_BASE + 0x1c)
#define RCC_APB2ENR				MMIO32(RCC_BASE + 0x20)
#define RCC_APB1ENR				MMIO32(RCC_BASE + 0x24)
#define RCC_AHBLPENR				MMIO32(RCC_BASE + 0x28)
#define RCC_APB2LPENR				MMIO32(RCC_BASE + 0x2c)
#define RCC_APB1LPENR				MMIO32(RCC_BASE + 0x30)
#define RCC_CSR					MMIO32(RCC_BASE + 0x34)

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_RTCPRE_SHIFT			29
#define RCC_CR_RTCPRE_MASK			0x3
#define RCC_CR_CSSON				(1 << 28)
#define RCC_CR_PLLRDY				(1 << 25)
#define RCC_CR_PLLON				(1 << 24)
#define RCC_CR_HSEBYP				(1 << 18)
#define RCC_CR_HSERDY				(1 << 17)
#define RCC_CR_HSEON				(1 << 16)
#define RCC_CR_MSIRDY				(1 << 9)
#define RCC_CR_MSION				(1 << 8)
#define RCC_CR_HSIRDY				(1 << 1)
#define RCC_CR_HSION				(1 << 0)

#define RCC_CR_RTCPRE_DIV2	0
#define RCC_CR_RTCPRE_DIV4	1
#define RCC_CR_RTCPRE_DIV8	2
#define RCC_CR_RTCPRE_DIV16	3
#define RCC_CR_RTCPRE_SHIFT	29
#define RCC_CR_RTCPRE_MASK	0x3

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

#define RCC_ICSCR_HSITRIM_SHIFT		8
#define RCC_ICSCR_HSITRIM_MASK		0x1f
#define RCC_ICSCR_HSICAL_SHIFT		0
#define RCC_ICSCR_HSICAL_MASK		0xff

/* --- RCC_CFGR values ----------------------------------------------------- */

/* MCOPRE */
#define RCC_CFGR_MCOPRE_DIV1	    0
#define RCC_CFGR_MCOPRE_DIV2	    1
#define RCC_CFGR_MCOPRE_DIV4	    2
#define RCC_CFGR_MCOPRE_DIV8	    3
#define RCC_CFGR_MCOPRE_DIV16	    4
#define RCC_CFGR_MCOPRE_SHIFT       28
#define RCC_CFGR_MCOPRE             (0x7 << RCC_CFGR_MCOPRE_SHIFT)

/* MCO: Microcontroller clock output */
#define RCC_CFGR_MCO_NOCLK			0x0
#define RCC_CFGR_MCO_SYSCLK			0x1
#define RCC_CFGR_MCO_HSICLK			0x2
#define RCC_CFGR_MCO_MSICLK			0x3
#define RCC_CFGR_MCO_HSECLK			0x4
#define RCC_CFGR_MCO_PLLCLK			0x5
#define RCC_CFGR_MCO_LSICLK			0x6
#define RCC_CFGR_MCO_LSECLK			0x7
#define RCC_CFGR_MCO_SHIFT			24
#define RCC_CFGR_MCO_MASK			0x7

/* PLL Output division selection */
#define RCC_CFGR_PLLDIV_DIV2	0x1
#define RCC_CFGR_PLLDIV_DIV3	0x2
#define RCC_CFGR_PLLDIV_DIV4	0x3
#define RCC_CFGR_PLLDIV_SHIFT	22
#define RCC_CFGR_PLLDIV_MASK	0x3

/* PLLMUL: PLL multiplication factor */
#define RCC_CFGR_PLLMUL_MUL3		0x0
#define RCC_CFGR_PLLMUL_MUL4		0x1
#define RCC_CFGR_PLLMUL_MUL6		0x2
#define RCC_CFGR_PLLMUL_MUL8		0x3
#define RCC_CFGR_PLLMUL_MUL12		0x4
#define RCC_CFGR_PLLMUL_MUL16		0x5
#define RCC_CFGR_PLLMUL_MUL24		0x6
#define RCC_CFGR_PLLMUL_MUL32		0x7
#define RCC_CFGR_PLLMUL_MUL48		0x8
#define RCC_CFGR_PLLMUL_SHIFT		18
#define RCC_CFGR_PLLMUL_MASK		0xf

/* PLLSRC: PLL entry clock source */
#define RCC_CFGR_PLLSRC_HSI_CLK		0x0
#define RCC_CFGR_PLLSRC_HSE_CLK		0x1

/* PPRE2: APB high-speed prescaler (APB2) */
#define RCC_CFGR_PPRE2_HCLK_NODIV		0x0
#define RCC_CFGR_PPRE2_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE2_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE2_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE2_HCLK_DIV16		0x7

/* PPRE1: APB low-speed prescaler (APB1) */
#define RCC_CFGR_PPRE1_HCLK_NODIV		0x0
#define RCC_CFGR_PPRE1_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE1_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE1_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE1_HCLK_DIV16		0x7

/* HPRE: AHB prescaler */
#define RCC_CFGR_HPRE_SYSCLK_NODIV		0x0
#define RCC_CFGR_HPRE_SYSCLK_DIV2		0x8
#define RCC_CFGR_HPRE_SYSCLK_DIV4		0x9
#define RCC_CFGR_HPRE_SYSCLK_DIV8		0xa
#define RCC_CFGR_HPRE_SYSCLK_DIV16		0xb
#define RCC_CFGR_HPRE_SYSCLK_DIV64		0xc
#define RCC_CFGR_HPRE_SYSCLK_DIV128		0xd
#define RCC_CFGR_HPRE_SYSCLK_DIV256		0xe
#define RCC_CFGR_HPRE_SYSCLK_DIV512		0xf

/* SWS: System clock switch status */
#define RCC_CFGR_SWS_SYSCLKSEL_MSICLK		0x0
#define RCC_CFGR_SWS_SYSCLKSEL_HSICLK		0x1
#define RCC_CFGR_SWS_SYSCLKSEL_HSECLK		0x2
#define RCC_CFGR_SWS_SYSCLKSEL_PLLCLK		0x3

/* SW: System clock switch */
#define RCC_CFGR_SW_SYSCLKSEL_MSICLK		0x0
#define RCC_CFGR_SW_SYSCLKSEL_HSICLK		0x1
#define RCC_CFGR_SW_SYSCLKSEL_HSECLK		0x2
#define RCC_CFGR_SW_SYSCLKSEL_PLLCLK		0x3

/* --- RCC_CIR values ------------------------------------------------------ */

/* Clock security system interrupt clear bit */
#define RCC_CIR_CSSC				(1 << 23)

/* OSC ready interrupt clear bits */
#define RCC_CIR_MSIRDYC				(1 << 21)
#define RCC_CIR_PLLRDYC				(1 << 20)
#define RCC_CIR_HSERDYC				(1 << 19)
#define RCC_CIR_HSIRDYC				(1 << 18)
#define RCC_CIR_LSERDYC				(1 << 17)
#define RCC_CIR_LSIRDYC				(1 << 16)

/* OSC ready interrupt enable bits */
#define RCC_CIR_MSIRDYIE			(1 << 13)
#define RCC_CIR_PLLRDYIE			(1 << 12)
#define RCC_CIR_HSERDYIE			(1 << 11)
#define RCC_CIR_HSIRDYIE			(1 << 10)
#define RCC_CIR_LSERDYIE			(1 << 9)
#define RCC_CIR_LSIRDYIE			(1 << 8)

/* Clock security system interrupt flag bit */
#define RCC_CIR_CSSF				(1 << 7)

/* OSC ready interrupt flag bits */
#define RCC_CIR_MSIRDYF				(1 << 5) /* (**) */
#define RCC_CIR_PLLRDYF				(1 << 4)
#define RCC_CIR_HSERDYF				(1 << 3)
#define RCC_CIR_HSIRDYF				(1 << 2)
#define RCC_CIR_LSERDYF				(1 << 1)
#define RCC_CIR_LSIRDYF				(1 << 0)

/* --- RCC_AHBRSTR values ------------------------------------------------- */
#define RCC_AHBRSTR_DMA1RST			(1 << 24)
#define RCC_AHBRSTR_FLITFRST			(1 << 15)
#define RCC_AHBRSTR_CRCRST			(1 << 12)
#define RCC_AHBRSTR_GPIOHRST			(1 << 5)
#define RCC_AHBRSTR_GPIOERST			(1 << 4)
#define RCC_AHBRSTR_GPIODRST			(1 << 3)
#define RCC_AHBRSTR_GPIOCRST			(1 << 2)
#define RCC_AHBRSTR_GPIOBRST			(1 << 1)
#define RCC_AHBRSTR_GPIOARST			(1 << 0)

/* --- RCC_APB2RSTR values ------------------------------------------------- */

#define RCC_APB2RSTR_USART1RST			(1 << 14)
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_ADC1RST			(1 << 9)
#define RCC_APB2RSTR_TIM11RST			(1 << 4)
#define RCC_APB2RSTR_TIM10RST			(1 << 3)
#define RCC_APB2RSTR_TIM9RST			(1 << 2)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 0)

/* --- RCC_APB1RSTR values ------------------------------------------------- */

#define RCC_APB1RSTR_COMPRST			(1 << 31)
#define RCC_APB1RSTR_DACRST			(1 << 29)
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_USBRST			(1 << 23)
#define RCC_APB1RSTR_I2C2RST			(1 << 22)
#define RCC_APB1RSTR_I2C1RST			(1 << 21)
#define RCC_APB1RSTR_USART3RST			(1 << 18)
#define RCC_APB1RSTR_USART2RST			(1 << 17)
#define RCC_APB1RSTR_SPI2RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_LCDRST			(1 << 9)
#define RCC_APB1RSTR_TIM7RST			(1 << 5)
#define RCC_APB1RSTR_TIM6RST			(1 << 4)
#define RCC_APB1RSTR_TIM5RST			(1 << 3)
#define RCC_APB1RSTR_TIM4RST			(1 << 2)
#define RCC_APB1RSTR_TIM3RST			(1 << 1)
#define RCC_APB1RSTR_TIM2RST			(1 << 0)

/* --- RCC_AHBENR values --------------------------------------------------- */

/** @defgroup rcc_ahbenr_en RCC_AHBENR enable values
@ingroup STM32L1xx_rcc_defines

@{*/
#define RCC_AHBENR_DMA1EN			(1 << 24)
#define RCC_AHBENR_FLITFEN			(1 << 15)
#define RCC_AHBENR_CRCEN			(1 << 12)
#define RCC_AHBENR_GPIOHEN			(1 << 5)
#define RCC_AHBENR_GPIOEEN			(1 << 4)
#define RCC_AHBENR_GPIODEN			(1 << 3)
#define RCC_AHBENR_GPIOCEN			(1 << 2)
#define RCC_AHBENR_GPIOBEN			(1 << 1)
#define RCC_AHBENR_GPIOAEN			(1 << 0)
/*@}*/

/* --- RCC_APB2ENR values -------------------------------------------------- */

/** @defgroup rcc_apb2enr_en RCC_APB2ENR enable values
@ingroup STM32L1xx_rcc_defines

@{*/
#define RCC_APB2ENR_USART1EN			(1 << 14)
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_ADC1EN			(1 << 9)
#define RCC_APB2ENR_TIM11EN			(1 << 4)
#define RCC_APB2ENR_TIM10EN			(1 << 3)
#define RCC_APB2ENR_TIM9EN			(1 << 2)
#define RCC_APB2ENR_SYSCFGEN			(1 << 0)
/*@}*/

/* --- RCC_APB1ENR values -------------------------------------------------- */

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@ingroup STM32L1xx_rcc_defines

@{*/
#define RCC_APB1ENR_COMPEN			(1 << 31)
#define RCC_APB1ENR_DACEN			(1 << 29)
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_USBEN			(1 << 23)
#define RCC_APB1ENR_I2C2EN			(1 << 22)
#define RCC_APB1ENR_I2C1EN			(1 << 21)
#define RCC_APB1ENR_USART3EN			(1 << 18)
#define RCC_APB1ENR_USART2EN			(1 << 17)
#define RCC_APB1ENR_SPI2EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_LCDEN			(1 << 9)
#define RCC_APB1ENR_TIM7EN			(1 << 5)
#define RCC_APB1ENR_TIM6EN			(1 << 4)
#define RCC_APB1ENR_TIM4EN			(1 << 2)
#define RCC_APB1ENR_TIM3EN			(1 << 1)
#define RCC_APB1ENR_TIM2EN			(1 << 0)
/*@}*/

/* --- RCC_AHBLPENR -------------------------------------------------------- */
#define RCC_AHBLPENR_DMA1LPEN			(1 << 24)
#define RCC_AHBLPENR_SRAMLPEN			(1 << 16)
#define RCC_AHBLPENR_FLITFLPEN			(1 << 15)
#define RCC_AHBLPENR_CRCLPEN			(1 << 12)
#define RCC_AHBLPENR_GPIOHLPEN			(1 << 5)
#define RCC_AHBLPENR_GPIOELPEN			(1 << 4)
#define RCC_AHBLPENR_GPIODLPEN			(1 << 3)
#define RCC_AHBLPENR_GPIOCLPEN			(1 << 2)
#define RCC_AHBLPENR_GPIOBLPEN			(1 << 1)
#define RCC_AHBLPENR_GPIOALPEN			(1 << 0)

#define RCC_APB2LPENR_USART1LPEN		(1 << 14)
#define RCC_APB2LPENR_SPI1LPEN			(1 << 12)
#define RCC_APB2LPENR_ADC1LPEN			(1 << 9)
#define RCC_APB2LPENR_TIM11LPEN			(1 << 4)
#define RCC_APB2LPENR_TIM10LPEN			(1 << 3)
#define RCC_APB2LPENR_TIM9LPEN			(1 << 2)
#define RCC_APB2LPENR_SYSCFGLPEN		(1 << 0)

#define RCC_APB1LPENR_COMPLPEN			(1 << 31)
#define RCC_APB1LPENR_DACLPEN			(1 << 29)
#define RCC_APB1LPENR_PWRLPEN			(1 << 28)
#define RCC_APB1LPENR_USBLPEN			(1 << 23)
#define RCC_APB1LPENR_I2C2LPEN			(1 << 22)
#define RCC_APB1LPENR_I2C1LPEN			(1 << 21)
#define RCC_APB1LPENR_USART3LPEN		(1 << 18)
#define RCC_APB1LPENR_USART2LPEN		(1 << 17)
#define RCC_APB1LPENR_SPI2LPEN			(1 << 14)
#define RCC_APB1LPENR_WWDGLPEN			(1 << 11)
#define RCC_APB1LPENR_LCDLPEN			(1 << 9)
#define RCC_APB1LPENR_TIM7LPEN			(1 << 5)
#define RCC_APB1LPENR_TIM6LPEN			(1 << 4)
#define RCC_APB1LPENR_TIM4LPEN			(1 << 2)
#define RCC_APB1LPENR_TIM3LPEN			(1 << 1)
#define RCC_APB1LPENR_TIM2LPEN			(1 << 0)


/* --- RCC_CSR values ------------------------------------------------------ */

#define RCC_CSR_LPWRRSTF			(1 << 31)
#define RCC_CSR_WWDGRSTF			(1 << 30)
#define RCC_CSR_IWDGRSTF			(1 << 29)
#define RCC_CSR_SFTRSTF				(1 << 28)
#define RCC_CSR_PORRSTF				(1 << 27)
#define RCC_CSR_PINRSTF				(1 << 26)
#define RCC_CSR_OBLRSTF				(1 << 25)
#define RCC_CSR_RMVF				(1 << 24)
#define RCC_CSR_RTCRST				(1 << 23)
#define RCC_CSR_RTCEN				(1 << 22)
#define RCC_CSR_RTCSEL_SHIFT			(16)
#define RCC_CSR_RTCSEL_MASK			(0x3)
#define RCC_CSR_RTCSEL_NONE			(0x0)
#define RCC_CSR_RTCSEL_LSE			(0x1)
#define RCC_CSR_RTCSEL_LSI			(0x2)
#define RCC_CSR_RTCSEL_HSI			(0x3)
#define RCC_CSR_LSECSSD				(1 << 12)
#define RCC_CSR_LSECSSON			(1 << 11)
#define RCC_CSR_LSEBYP				(1 << 10)
#define RCC_CSR_LSERDY				(1 << 9)
#define RCC_CSR_LSEON				(1 << 8)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)

struct rcc_clock_scale {
	uint8_t pll_mul;
	uint16_t pll_div;
	uint8_t pll_source;
	uint32_t flash_config;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	enum pwr_vos_scale voltage_scale;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
	uint8_t msi_range;
};

enum rcc_clock_config_entry {
	RCC_CLOCK_VRANGE1_HSI_PLL_24MHZ,
	RCC_CLOCK_VRANGE1_HSI_PLL_32MHZ,
	RCC_CLOCK_VRANGE1_HSI_RAW_16MHZ,
	RCC_CLOCK_VRANGE1_HSI_RAW_4MHZ,
	RCC_CLOCK_VRANGE1_MSI_RAW_4MHZ,
	RCC_CLOCK_VRANGE1_MSI_RAW_2MHZ,
	RCC_CLOCK_CONFIG_END
};

extern const struct rcc_clock_scale rcc_clock_config[RCC_CLOCK_CONFIG_END];


/* --- Variable definitions ------------------------------------------------ */
extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

/* --- Function prototypes ------------------------------------------------- */

enum rcc_osc {
	RCC_PLL, RCC_HSE, RCC_HSI, RCC_MSI, RCC_LSE, RCC_LSI
};

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

enum rcc_periph_clken {
	/* AHB peripherals  */
	RCC_GPIOA	= _REG_BIT(0x1c, 0),
	RCC_GPIOB	= _REG_BIT(0x1c, 1),
	RCC_GPIOC	= _REG_BIT(0x1c, 2),
	RCC_GPIOD	= _REG_BIT(0x1c, 3),
	RCC_GPIOE	= _REG_BIT(0x1c, 4),
	RCC_GPIOH	= _REG_BIT(0x1c, 5),
	RCC_GPIOF	= _REG_BIT(0x1c, 6),
	RCC_GPIOG	= _REG_BIT(0x1c, 7),
	RCC_CRC		= _REG_BIT(0x1c, 12),
	RCC_FLITF	= _REG_BIT(0x1c, 15),
	RCC_DMA1	= _REG_BIT(0x1c, 24),
	RCC_DMA2	= _REG_BIT(0x1c, 25),
	RCC_AES		= _REG_BIT(0x1c, 27),
	RCC_FSMC	= _REG_BIT(0x1c, 30),

	/* APB2 peripherals */
	RCC_SYSCFG	= _REG_BIT(0x20, 0),
	RCC_TIM9	= _REG_BIT(0x20, 2),
	RCC_TIM10	= _REG_BIT(0x20, 3),
	RCC_TIM11	= _REG_BIT(0x20, 4),
	RCC_ADC1	= _REG_BIT(0x20, 9),
	RCC_SDIO	= _REG_BIT(0x20, 11),
	RCC_SPI1	= _REG_BIT(0x20, 12),
	RCC_USART1	= _REG_BIT(0x20, 14),

	/* APB1 peripherals*/
	RCC_TIM2	= _REG_BIT(0x24, 0),
	RCC_TIM3	= _REG_BIT(0x24, 1),
	RCC_TIM4	= _REG_BIT(0x24, 2),
	RCC_TIM5	= _REG_BIT(0x24, 3),
	RCC_TIM6	= _REG_BIT(0x24, 4),
	RCC_TIM7	= _REG_BIT(0x24, 5),
	RCC_LCD		= _REG_BIT(0x24, 9),
	RCC_WWDG	= _REG_BIT(0x24, 11),
	RCC_SPI2	= _REG_BIT(0x24, 14),
	RCC_SPI3	= _REG_BIT(0x24, 15),
	RCC_USART2	= _REG_BIT(0x24, 17),
	RCC_USART3	= _REG_BIT(0x24, 18),
	RCC_UART4	= _REG_BIT(0x24, 19),
	RCC_UART5	= _REG_BIT(0x24, 20),
	RCC_I2C1	= _REG_BIT(0x24, 21),
	RCC_I2C2	= _REG_BIT(0x24, 22),
	RCC_USB		= _REG_BIT(0x24, 23),
	RCC_PWR		= _REG_BIT(0x24, 28),
	RCC_DAC		= _REG_BIT(0x24, 29),
	RCC_COMP	= _REG_BIT(0x24, 31),

	/* AHB peripherals  */
	SCC_GPIOA	= _REG_BIT(0x28, 0),
	SCC_GPIOB	= _REG_BIT(0x28, 1),
	SCC_GPIOC	= _REG_BIT(0x28, 2),
	SCC_GPIOD	= _REG_BIT(0x28, 3),
	SCC_GPIOE	= _REG_BIT(0x28, 4),
	SCC_GPIOH	= _REG_BIT(0x28, 5),
	SCC_GPIOF	= _REG_BIT(0x28, 6),
	SCC_GPIOG	= _REG_BIT(0x28, 7),
	SCC_CRC		= _REG_BIT(0x28, 12),
	SCC_FLITF	= _REG_BIT(0x28, 15),
	SCC_SRAM	= _REG_BIT(0x28, 16),
	SCC_DMA1	= _REG_BIT(0x28, 24),
	SCC_DMA2	= _REG_BIT(0x28, 25),
	SCC_AES		= _REG_BIT(0x28, 27),
	SCC_FSMC	= _REG_BIT(0x28, 30),

	/* APB2 peripherals */
	SCC_SYSCFG	= _REG_BIT(0x2c, 0),
	SCC_TIM9	= _REG_BIT(0x2c, 2),
	SCC_TIM10	= _REG_BIT(0x2c, 3),
	SCC_TIM11	= _REG_BIT(0x2c, 4),
	SCC_ADC1	= _REG_BIT(0x2c, 9),
	SCC_SDIO	= _REG_BIT(0x2c, 11),
	SCC_SPI1	= _REG_BIT(0x2c, 12),
	SCC_USART1	= _REG_BIT(0x2c, 14),

	/* APB1 peripherals*/
	SCC_TIM2	= _REG_BIT(0x24, 0),
	SCC_TIM3	= _REG_BIT(0x24, 1),
	SCC_TIM4	= _REG_BIT(0x24, 2),
	SCC_TIM5	= _REG_BIT(0x24, 3),
	SCC_TIM6	= _REG_BIT(0x24, 4),
	SCC_TIM7	= _REG_BIT(0x24, 5),
	SCC_LCD		= _REG_BIT(0x24, 9),
	SCC_WWDG	= _REG_BIT(0x24, 11),
	SCC_SPI2	= _REG_BIT(0x24, 14),
	SCC_SPI3	= _REG_BIT(0x24, 15),
	SCC_USART2	= _REG_BIT(0x24, 17),
	SCC_USART3	= _REG_BIT(0x24, 18),
	SCC_UART4	= _REG_BIT(0x24, 19),
	SCC_UART5	= _REG_BIT(0x24, 20),
	SCC_I2C1	= _REG_BIT(0x24, 21),
	SCC_I2C2	= _REG_BIT(0x24, 22),
	SCC_USB		= _REG_BIT(0x24, 23),
	SCC_PWR		= _REG_BIT(0x24, 28),
	SCC_DAC		= _REG_BIT(0x24, 29),
	SCC_COMP	= _REG_BIT(0x24, 31),
};

enum rcc_periph_rst {
	/* AHB peripherals  */
	RST_GPIOA	= _REG_BIT(0x10, 0),
	RST_GPIOB	= _REG_BIT(0x10, 1),
	RST_GPIOC	= _REG_BIT(0x10, 2),
	RST_GPIOD	= _REG_BIT(0x10, 3),
	RST_GPIOE	= _REG_BIT(0x10, 4),
	RST_GPIOH	= _REG_BIT(0x10, 5),
	RST_GPIOF	= _REG_BIT(0x10, 6),
	RST_GPIOG	= _REG_BIT(0x10, 7),
	RST_CRC		= _REG_BIT(0x10, 12),
	RST_FLITF	= _REG_BIT(0x10, 15),
	RST_DMA1	= _REG_BIT(0x10, 24),
	RST_DMA2	= _REG_BIT(0x10, 25),
	RST_AES		= _REG_BIT(0x10, 27),
	RST_FSMC	= _REG_BIT(0x10, 30),

	/* APB2 peripherals */
	RST_SYSCFG	= _REG_BIT(0x14, 0),
	RST_TIM9	= _REG_BIT(0x14, 2),
	RST_TIM10	= _REG_BIT(0x14, 3),
	RST_TIM11	= _REG_BIT(0x14, 4),
	RST_ADC1	= _REG_BIT(0x14, 9),
	RST_SDIO	= _REG_BIT(0x14, 11),
	RST_SPI1	= _REG_BIT(0x14, 12),
	RST_USART1	= _REG_BIT(0x14, 14),

	/* APB1 peripherals*/
	RST_TIM2	= _REG_BIT(0x18, 0),
	RST_TIM3	= _REG_BIT(0x18, 1),
	RST_TIM4	= _REG_BIT(0x18, 2),
	RST_TIM5	= _REG_BIT(0x18, 3),
	RST_TIM6	= _REG_BIT(0x18, 4),
	RST_TIM7	= _REG_BIT(0x18, 5),
	RST_LCD		= _REG_BIT(0x18, 9),
	RST_WWDG	= _REG_BIT(0x18, 11),
	RST_SPI2	= _REG_BIT(0x18, 14),
	RST_SPI3	= _REG_BIT(0x18, 15),
	RST_USART2	= _REG_BIT(0x18, 17),
	RST_USART3	= _REG_BIT(0x18, 18),
	RST_UART4	= _REG_BIT(0x18, 19),
	RST_UART5	= _REG_BIT(0x18, 20),
	RST_I2C1	= _REG_BIT(0x18, 21),
	RST_I2C2	= _REG_BIT(0x18, 22),
	RST_USB		= _REG_BIT(0x18, 23),
	RST_PWR		= _REG_BIT(0x18, 28),
	RST_DAC		= _REG_BIT(0x18, 29),
	RST_COMP	= _REG_BIT(0x18, 31),
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
void rcc_wait_for_sysclk_status(enum rcc_osc osc);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_osc_bypass_enable(enum rcc_osc osc);
void rcc_osc_bypass_disable(enum rcc_osc osc);
void rcc_set_sysclk_source(uint32_t clk);
void rcc_set_pll_configuration(uint32_t source, uint32_t multiplier,
			       uint32_t divisor);
void rcc_set_pll_source(uint32_t pllsrc);
void rcc_set_adcpre(uint32_t adcpre);
void rcc_set_ppre2(uint32_t ppre2);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_usbpre(uint32_t usbpre);
void rcc_set_rtcpre(uint32_t rtcpre);
uint32_t rcc_system_clock_source(void);
void rcc_rtc_select_clock(uint32_t clock);
void rcc_clock_setup_msi(const struct rcc_clock_scale *clock);
void rcc_clock_setup_hsi(const struct rcc_clock_scale *clock);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);
void rcc_backupdomain_reset(void);

END_DECLS

/**@}*/

#endif
