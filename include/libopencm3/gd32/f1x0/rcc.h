/** @defgroup rcc_defines RCC Defines
 *
 * @brief <b>Defined Constants and Types for the GD32F1x0 Reset and Clock
 * Control</b>
 *
 * @ingroup GD32F1x0_defines
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
 * Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
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
#define RCC_AHBRSTR				MMIO32(RCC_BASE + 0x28)
#define RCC_CFGR2				MMIO32(RCC_BASE + 0x2c)
#define RCC_CFGR3				MMIO32(RCC_BASE + 0x30)
#define RCC_CR2					MMIO32(RCC_BASE + 0x34)


/* --- RCC_CR values ------------------------------------------------------- */

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

#define RCC_CFGR_PLLMUL_4_SHIFT			27
#define RCC_CFGR_PLLMUL_4			(1 << RCC_CFGR_PLLMUL_4_SHIFT)

#define RCC_CFGR_MCO_SHIFT			24
#define RCC_CFGR_MCO_MASK			0x7
#define RCC_CFGR_MCO_NOCLK			0
#define RCC_CFGR_MCO_HSI14			1
#define RCC_CFGR_MCO_LSI			2
#define RCC_CFGR_MCO_LSE			3
#define RCC_CFGR_MCO_SYSCLK			4
#define RCC_CFGR_MCO_HSI			5
#define RCC_CFGR_MCO_HSE			6
#define RCC_CFGR_MCO_PLL			7

#define RCC_CFGR_USBPRE_SHIFT			22
#define RCC_CFGR_USBPRE				(3 << RCC_CFGR_USBPRE_SHIFT)

#define RCC_CFGR_PLLMUL_0_3_SHIFT		18
#define RCC_CFGR_PLLMUL_0_3			(0xF << RCC_CFGR_PLLMUL_0_3_SHIFT)

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

/** @defgroup rcc_cfgr_usbpre USBPRE: USB prescaler (RCC_CFGR[23:22])
 * @{
 */
#define RCC_CFGR_USBPRE_PLL_CLK_DIV1_5		0x0
#define RCC_CFGR_USBPRE_PLL_CLK_NODIV		0x1
#define RCC_CFGR_USBPRE_PLL_CLK_DIV2_5		0x2
#define RCC_CFGR_USBPRE_PLL_CLK_DIV2		0x3
/**@}*/

/** @defgroup rcc_cfgr_pmf PLLMUL: PLL multiplication factor
 * @{
 */
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
/**@}*/

/** @defgroup rcc_cfgr_hsepre PLLXTPRE: HSE divider for PLL entry
 * @{
 */
#define RCC_CFGR_PLLXTPRE_HSE_CLK		0x0
#define RCC_CFGR_PLLXTPRE_HSE_CLK_DIV2		0x1
/**@}*/

/** @defgroup rcc_cfgr_pcs PLLSRC: PLL entry clock source
 * @{
 */
#define RCC_CFGR_PLLSRC_HSI_CLK_DIV2		0x0
#define RCC_CFGR_PLLSRC_HSE_CLK			0x1
/**@}*/

/** @defgroup rcc_cfgr_adcpre ADCPRE: ADC prescaler
 * @{
 */
#define RCC_CFGR_ADCPRE_PCLK2_DIV2		0x0
#define RCC_CFGR_ADCPRE_PCLK2_DIV4		0x1
#define RCC_CFGR_ADCPRE_PCLK2_DIV6		0x2
#define RCC_CFGR_ADCPRE_PCLK2_DIV8		0x3
/**@}*/

/** @defgroup rcc_cfgr_apb2pre PPRE2: APB high-speed prescaler (APB2)
 * @{
 */
#define RCC_CFGR_PPRE2_HCLK_NODIV		0x0
#define RCC_CFGR_PPRE2_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE2_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE2_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE2_HCLK_DIV16		0x7
/**@}*/

/** @defgroup rcc_cfgr_apb1pre PPRE1: APB low-speed prescaler (APB1)
 * @{
 */
#define RCC_CFGR_PPRE1_HCLK_NODIV		0x0
#define RCC_CFGR_PPRE1_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE1_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE1_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE1_HCLK_DIV16		0x7
/**@}*/

/** @defgroup rcc_cfgr_ahbpre HPRE: AHB prescaler
 * @{
 */
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

/** @defgroup rcc_cfgr_scs SW: System clock switch
 * @{
 */
#define RCC_CFGR_SW_SYSCLKSEL_HSICLK		0x0
#define RCC_CFGR_SW_SYSCLKSEL_HSECLK		0x1
#define RCC_CFGR_SW_SYSCLKSEL_PLLCLK		0x2
/**@}*/

/* --- RCC_CIR values ------------------------------------------------------ */

/* Clock security system interrupt clear bit */
#define RCC_CIR_CSSC				(1 << 23)

/* OSC ready interrupt clear bits */
#define RCC_CIR_HSI14RDYC			(1 << 21)
#define RCC_CIR_PLLRDYC				(1 << 20)
#define RCC_CIR_HSERDYC				(1 << 19)
#define RCC_CIR_HSIRDYC				(1 << 18)
#define RCC_CIR_LSERDYC				(1 << 17)
#define RCC_CIR_LSIRDYC				(1 << 16)

/* OSC ready interrupt enable bits */
#define RCC_CIR_HSI14RDYIE			(1 << 13)
#define RCC_CIR_PLLRDYIE			(1 << 12)
#define RCC_CIR_HSERDYIE			(1 << 11)
#define RCC_CIR_HSIRDYIE			(1 << 10)
#define RCC_CIR_LSERDYIE			(1 << 9)
#define RCC_CIR_LSIRDYIE			(1 << 8)

/* Clock security system interrupt flag bit */
#define RCC_CIR_CSSF				(1 << 7)

/* OSC ready interrupt flag bits */
#define RCC_CIR_HSI14RDYF			(1 << 5)
#define RCC_CIR_PLLRDYF				(1 << 4)
#define RCC_CIR_HSERDYF				(1 << 3)
#define RCC_CIR_HSIRDYF				(1 << 2)
#define RCC_CIR_LSERDYF				(1 << 1)
#define RCC_CIR_LSIRDYF				(1 << 0)

/** @defgroup rcc_apb2rstr_rst RCC_APB2RSTR reset values values
@{*/
#define RCC_APB2RSTR_TIM17RST			(1 << 18)
#define RCC_APB2RSTR_TIM16RST			(1 << 17)
#define RCC_APB2RSTR_TIM15RST			(1 << 16)
#define RCC_APB2RSTR_USART1RST			(1 << 14)
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_TIM1RST			(1 << 11)
#define RCC_APB2RSTR_ADCRST			(1 << 9)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 0)
/**@}*/

/** @defgroup rcc_apb1rstr_rst RCC_APB1RSTR reset values values
@{*/
#define RCC_APB1RSTR_CECRST			(1 << 30)
#define RCC_APB1RSTR_DACRST			(1 << 29)
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_USBRST			(1 << 23)
#define RCC_APB1RSTR_I2C2RST			(1 << 22)
#define RCC_APB1RSTR_I2C1RST			(1 << 21)
#define RCC_APB1RSTR_USART2RST			(1 << 17)
#define RCC_APB1RSTR_SPI3RST			(1 << 15)
#define RCC_APB1RSTR_SPI2RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_TIM14RST			(1 << 8)
#define RCC_APB1RSTR_TIM6RST			(1 << 4)
#define RCC_APB1RSTR_TIM3RST			(1 << 1)
#define RCC_APB1RSTR_TIM2RST			(1 << 0)
/**@}*/

/** @defgroup rcc_ahbenr_en RCC_AHBENR enable values
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
#define RCC_AHBENR_DMAEN			(1 << 0)
/**@}*/

/** @defgroup rcc_apb2enr_en RCC_APB2ENR enable values
@{*/
#define RCC_APB2ENR_TIM17EN			(1 << 18)
#define RCC_APB2ENR_TIM16EN			(1 << 17)
#define RCC_APB2ENR_TIM15EN			(1 << 16)
#define RCC_APB2ENR_USART1EN			(1 << 14)
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_TIM1EN			(1 << 11)
#define RCC_APB2ENR_ADCEN			(1 << 9)
#define RCC_APB2ENR_SYSCFGCOMPEN		(1 << 0)
/**@}*/

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@{*/
#define RCC_APB1ENR_CECEN			(1 << 30)
#define RCC_APB1ENR_DACEN			(1 << 29)
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_USBEN			(1 << 23)
#define RCC_APB1ENR_I2C2EN			(1 << 22)
#define RCC_APB1ENR_I2C1EN			(1 << 21)
#define RCC_APB1ENR_USART2EN			(1 << 17)
#define RCC_APB1ENR_SPI3EN			(1 << 15)
#define RCC_APB1ENR_SPI2EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_TIM14EN			(1 << 8)
#define RCC_APB1ENR_TIM6EN			(1 << 4)
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

/** @defgroup rcc_ahbrstr_rst RCC_AHBRSTR reset values values
@{*/
#define RCC_AHBRSTR_ETHMACRST			(1 << 14)
#define RCC_AHBRSTR_OTGFSRST			(1 << 12)
/**@}*/

/* --- RCC_CFGR2 values ---------------------------------------------------- */

#define RCC_CFGR2_PREDIV			0xf
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

/* --- RCC_CFGR3 values ---------------------------------------------------- */

#define RCC_CFGR3_USART2SW_SHIFT		16
#define RCC_CFGR3_USART2SW			(3 << RCC_CFGR3_USART2SW_SHIFT)
#define RCC_CFGR3_USART2SW_PCLK			(0 << RCC_CFGR3_USART2SW_SHIFT)
#define RCC_CFGR3_USART2SW_SYSCLK		(1 << RCC_CFGR3_USART2SW_SHIFT)
#define RCC_CFGR3_USART2SW_LSE			(2 << RCC_CFGR3_USART2SW_SHIFT)
#define RCC_CFGR3_USART2SW_HSI			(3 << RCC_CFGR3_USART2SW_SHIFT)

#define RCC_CFGR3_ADCSW				(1 << 8)
#define RCC_CFGR3_CECSW				(1 << 6)

/* --- Variable definitions ------------------------------------------------ */
extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

/* --- Function prototypes ------------------------------------------------- */

enum rcc_clock_hsi {
	RCC_CLOCK_HSI_48MHZ,
	RCC_CLOCK_HSI_64MHZ,
	RCC_CLOCK_HSI_END
};

enum rcc_clock_hse8 {
	RCC_CLOCK_HSE8_72MHZ,
	RCC_CLOCK_HSE8_END
};

struct rcc_clock_scale {
	uint8_t pllmul;
	uint8_t hpre;
	uint8_t ppre1;
	uint8_t ppre2;
	uint8_t adcpre;
	uint8_t usbpre; /* Only valid if HSE used */
	bool use_hse; /* PLL source is HSE if set, HSI/2 if unset */
	uint8_t pll_hse_prediv; /* Only valid if HSE used */
	uint32_t ahb_frequency;
	uint32_t apb1_frequency;
	uint32_t apb2_frequency;
};

extern const struct rcc_clock_scale rcc_hsi_configs[RCC_CLOCK_HSI_END];
extern const struct rcc_clock_scale rcc_hse8_configs[RCC_CLOCK_HSE8_END];

enum rcc_osc {
	RCC_PLL, RCC_HSE, RCC_HSI, RCC_LSE, RCC_LSI
};

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

/* V = value line F100
 * N = standard line F101, F102, F103
 * C = communication line F105, F107
 */
enum rcc_periph_clken {

	/* AHB peripherals */
	RCC_DMA		= _REG_BIT(0x14, 0),
	RCC_SRAM	= _REG_BIT(0x14, 2),
	RCC_FLTF	= _REG_BIT(0x14, 4),
	RCC_CRC		= _REG_BIT(0x14, 6),
	RCC_GPIOA	= _REG_BIT(0x14, 17),
	RCC_GPIOB	= _REG_BIT(0x14, 18),
	RCC_GPIOC	= _REG_BIT(0x14, 19),
	RCC_GPIOD	= _REG_BIT(0x14, 20),
	RCC_GPIOF	= _REG_BIT(0x14, 22),
	RCC_TSC		= _REG_BIT(0x14, 24),

	/* APB2 peripherals */
	RCC_SYSCFG_COMP	= _REG_BIT(0x18, 0),
	RCC_ADC		= _REG_BIT(0x18, 9),
	RCC_TIM1	= _REG_BIT(0x18, 11),
	RCC_SPI1	= _REG_BIT(0x18, 12),
	RCC_USART1	= _REG_BIT(0x18, 14),
	RCC_TIM15	= _REG_BIT(0x18, 16),
	RCC_TIM16	= _REG_BIT(0x18, 17),
	RCC_TIM17	= _REG_BIT(0x18, 18),

	/* APB1 peripherals */
	RCC_TIM2	= _REG_BIT(0x1C, 0),
	RCC_TIM3	= _REG_BIT(0x1C, 1),
	RCC_TIM6	= _REG_BIT(0x1C, 4),
	RCC_TIM14	= _REG_BIT(0x1C, 8),
	RCC_WWDG	= _REG_BIT(0x1C, 11),
	RCC_SPI2	= _REG_BIT(0x1C, 14),
	RCC_SPI3	= _REG_BIT(0x1C, 15),
	RCC_USART2	= _REG_BIT(0x1C, 17),
	RCC_I2C1	= _REG_BIT(0x1C, 21),
	RCC_I2C2	= _REG_BIT(0x1C, 22),
	RCC_USB		= _REG_BIT(0x1C, 23),
	RCC_PWR		= _REG_BIT(0x1C, 28),
	RCC_DAC		= _REG_BIT(0x1C, 29),
	RCC_CEC		= _REG_BIT(0x1C, 30),
};

enum rcc_periph_rst {

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

	/* APB2 peripherals */
	RST_SYSCFG	= _REG_BIT(0x0C, 0),
	RST_ADC		= _REG_BIT(0x0C, 9),
	RST_TIM1	= _REG_BIT(0x0C, 11),
	RST_SPI1	= _REG_BIT(0x0C, 12),
	RST_USART1	= _REG_BIT(0x0C, 14),
	RST_TIM15	= _REG_BIT(0x0C, 16),
	RST_TIM16	= _REG_BIT(0x0C, 17),
	RST_TIM17	= _REG_BIT(0x0C, 18),

	/* APB1 peripherals */
	RST_TIM2	= _REG_BIT(0x10, 0),
	RST_TIM3	= _REG_BIT(0x10, 1),
	RST_TIM6	= _REG_BIT(0x10, 4),
	RST_TIM14	= _REG_BIT(0x10, 8),
	RST_WWDG	= _REG_BIT(0x10, 11),
	RST_SPI2	= _REG_BIT(0x10, 14),
	RST_SPI3	= _REG_BIT(0x10, 15),
	RST_USART2	= _REG_BIT(0x10, 17),
	RST_I2C1	= _REG_BIT(0x10, 21),
	RST_I2C2	= _REG_BIT(0x10, 22),
	RST_USB		= _REG_BIT(0x10, 23),
	RST_PWR		= _REG_BIT(0x10, 28),
	RST_DAC		= _REG_BIT(0x10, 29),
	RST_CEC		= _REG_BIT(0x10, 30),
};

#include <libopencm3/stm32/common/rcc_common_all.h>

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
void rcc_set_pllxtpre(uint32_t pllxtpre);
uint32_t rcc_rtc_clock_enabled_flag(void);
void rcc_enable_rtc_clock(void);
void rcc_set_rtc_clock_source(enum rcc_osc clock_source);
void rcc_set_adcpre(uint32_t adcpre);
void rcc_set_ppre2(uint32_t ppre1);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
void rcc_set_usbpre(uint32_t usbpre);
void rcc_set_prediv(uint32_t prediv);
uint32_t rcc_system_clock_source(void);
void rcc_clock_setup_pll(const struct rcc_clock_scale *clock);
void rcc_backupdomain_reset(void);

END_DECLS

#endif
/**@}*/

