/** @defgroup rcc_defines RCC Defines
 *
 * @ingroup STM32U5xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32U5xx Reset and Clock
 * Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2015 Karl Palsson <karlp@tweak.net.au>
 *
 * @date 05 October 2024
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
 *
 */

/**@{*/

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

struct rcc_clock_scale {
    uint8_t hpre;                  /* AHB prescaler */
    uint8_t ppre1;                 /* APB1 low-speed prescaler */
    uint8_t ppre2;                 /* APB2 high-speed prescaler */
    uint32_t ahb_frequency;        /* AHB clock frequency */
    uint32_t apb1_frequency;       /* APB1 clock frequency */
    uint32_t apb2_frequency;       /* APB2 clock frequency */
	// enum pwr_vos_scale vos_scale;  /* Dynamic voltage scale */ TODO
};

extern const struct rcc_clock_scale rcc_hsi16mhz_configs;

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define RCC_CR		MMIO32(RCC_BASE + 0x00)
#define RCC_CFGR	MMIO32(RCC_BASE + 0x1c)
#define RCC_CFGR2	MMIO32(RCC_BASE + 0x20)
#define RCC_CFGR3	MMIO32(RCC_BASE + 0x24)
#define RCC_CCIPR1  MMIO32(RCC_BASE + 0xE0)
#define RCC_CCIPR2  MMIO32(RCC_BASE + 0xE4)
#define RCC_CCIPR3  MMIO32(RCC_BASE + 0xE8)



#define RCC_CFGR_SWS_SHIFT			2
#define RCC_CFGR_SWS_MASK			0x3
#define RCC_CFGR_SWS				(0x3 << RCC_CFGR_SWS_SHIFT)
#define RCC_CFGR_SWS_MSIS			0x0
#define RCC_CFGR_SWS_HSI16			0x1
#define RCC_CFGR_SWS_HE				0x2
#define RCC_CFGR_SWS_PLL			0x3

#define RCC_CFGR_SW_SYSCLKSEL_SHIFT	0
#define RCC_CFGR_SW_SYSCLKSEL_MASK	0x3
#define RCC_CFGR_SW_SYSCLKSEL_MSIS	0x0
#define RCC_CFGR_SW_SYSCLKSEL_HSI16	0x1
#define RCC_CFGR_SW_SYSCLKSEL_HSE	0x2
#define RCC_CFGR_SW_SYSCLKSEL_PLL	0x3

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_PLL3RDY		(1 << 29)
#define RCC_CR_PLL3ON		(1 << 28)
#define RCC_CR_PLL2RDY		(1 << 27)
#define RCC_CR_PLL2ON		(1 << 26)
#define RCC_CR_PLL1RDY		(1 << 25)
#define RCC_CR_PLL1ON		(1 << 24)
#define RCC_CR_HSEEXT		(1 << 20)
#define RCC_CR_CSSON		(1 << 19)
#define RCC_CR_HSEBYP		(1 << 18)
#define RCC_CR_HSERDY		(1 << 17)
#define RCC_CR_HSEON		(1 << 16)
#define RCC_CR_SHSIRDY		(1 << 15)
#define RCC_CR_SHSION		(1 << 14)
#define RCC_CR_HSI48RDY		(1 << 13)
#define RCC_CR_HSI48ON		(1 << 12)
#define RCC_CR_HSIRDY		(1 << 10)
#define RCC_CR_HSIKERON		(1 << 9)
#define RCC_CR_HSION		(1 << 8)
#define RCC_CR_MSIPLFAST	(1 << 7)
#define RCC_CR_MSIKRDY		(1 << 5)
#define RCC_CR_MSIKON		(1 << 4)
#define RCC_CR_MSIPLLEN		(1 << 3)
#define RCC_CR_MSISRDY		(1 << 2)
#define RCC_CR_MSIKERON		(1 << 1)
#define RCC_CR_MSISON		(1 << 0)

/* --- RCC_CFGR values ----------------------------------------------------- */

#define RCC_CFGR_MCO_SHIFT	24
#define RCC_CFGR_MCO_MASK	0xf

#define RCC_CFGR_HPRE_SHIFT		0
#define RCC_CFGR_HPRE			(0xf << RCC_CFGR_HPRE_SHIFT)
#define RCC_CFGR_HPRE_MASK		0xf

/** @defgroup rcc_cfgr_ahbpre RCC_CFGR AHB prescale factors
@{*/
#define RCC_CFGR_HPRE_NODIV		0x0
#define RCC_CFGR_HPRE_DIV2		0x8
#define RCC_CFGR_HPRE_DIV4		0x9
#define RCC_CFGR_HPRE_DIV8		0xA
#define RCC_CFGR_HPRE_DIV16		0xB
#define RCC_CFGR_HPRE_DIV64		0xC
#define RCC_CFGR_HPRE_DIV128	0xD
#define RCC_CFGR_HPRE_DIV256	0xE
#define RCC_CFGR_HPRE_DIV512	0xF
/**@}*/

#define RCC_CFGR_PPRE1_SHIFT	4
#define RCC_CFGR_PPRE1			(0x7 << RCC_CFGR_PPRE1_SHIFT)
#define RCC_CFGR_PPRE1_MASK		0x7
#define RCC_CFGR_PPRE2_SHIFT	8
#define RCC_CFGR_PPRE2			(0x7 << RCC_CFGR_PPRE2_SHIFT)
#define RCC_CFGR_PPRE2_MASK		0x7

/** @defgroup rcc_cfgr_apbxpre RCC_CFGR APBx prescale factors
 * These can be used for both APB1 and APB2 prescaling
 * @{
 */
#define RCC_CFGR_PPRE_NODIV		0x0
#define RCC_CFGR_PPRE_DIV2		0x4
#define RCC_CFGR_PPRE_DIV4		0x5
#define RCC_CFGR_PPRE_DIV8		0x6
#define RCC_CFGR_PPRE_DIV16		0x7
/**@}*/


/* --- RCC_BDCR values ----------------------------------------------------- */

#define RCC_BDCR			MMIO32(RCC_BASE + 0xF0)
#define RCC_BDCR_LSEBYP		(1 << 2)

#define RCC_CCIPR_USARTxSEL_MASK	0x3
#define RCC_CCIPR_I2CxSEL_MASK		0x3

#define RCC_CCIPR_USARTxSEL_PCLKx	0x0
#define RCC_CCIPR_USARTxSEL_SYSCLK	0x1
#define RCC_CCIPR_USARTxSEL_HSI16	0x2
#define RCC_CCIPR_USARTxSEL_LSE		0x3

#define RCC_CCIPR_I2CxSEL_PCLKx		0x0
#define RCC_CCIPR_I2CxSEL_SYSCLK	0x1
#define RCC_CCIPR_I2CxSEL_HSI16		0x2
#define RCC_CCIPR_I2CxSEL_LSE		0x3

/* --- RCC_CCIPR1 values ---------------------------------------------------- */

#define RCC_CCIPR1_USART5SEL_SHIFT	8
#define RCC_CCIPR1_USART4SEL_SHIFT	6
#define RCC_CCIPR1_USART3SEL_SHIFT	4
#define RCC_CCIPR1_USART2SEL_SHIFT	2
#define RCC_CCIPR1_USART1SEL_SHIFT	0

#define RCC_CCIPR1_I2C4SEL_SHIFT	14
#define RCC_CCIPR1_I2C2SEL_SHIFT	12
#define RCC_CCIPR1_I2C1SEL_SHIFT	10

/* --- RCC_CCIPR2 values ---------------------------------------------------- */

#define RCC_CCIPR2_I2C6SEL_SHIFT	26
#define RCC_CCIPR2_I2C5SEL_SHIFT	24

#define RCC_CCIPR2_USART6SEL_SHIFT	16

/* --- RCC_CCIPR3 values ---------------------------------------------------- */

#define RCC_CCIPR3_I2C3SEL_SHIFT	6
/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/* --- Variable definitions ------------------------------------------------ */

extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

enum rcc_osc {
	RCC_PLL3,
	RCC_PLL2,
	RCC_PLL1,
	RCC_SHSI,
	RCC_HSE,
	RCC_HSI,
	RCC_HSI16,
	RCC_MSIS,
	RCC_MSI,
	RCC_LSI,
	RCC_LSE,
	RCC_HSI48,
};

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

enum rcc_periph_rst {
	/* AHB1 peripherals */
	RST_GPDMA	= _REG_BIT(0x60, 0),
	RST_CORDIC	= _REG_BIT(0x60, 1),
	RST_FMAC	= _REG_BIT(0x60, 2),
	RST_MDF1	= _REG_BIT(0x60, 3),
	RST_CRC		= _REG_BIT(0x60, 12),
	RST_JPEG	= _REG_BIT(0x60, 15),
	RST_TSCRS	= _REG_BIT(0x60, 16),
	RST_RAMCFG	= _REG_BIT(0x60, 17),
	RST_DMA2D	= _REG_BIT(0x60, 18),
	RST_GFXMMU	= _REG_BIT(0x60, 19),
	RST_GPU2D	= _REG_BIT(0x60, 20),


	/* AHB2 peripherals */
	RST_GPIOA	= _REG_BIT(0x64, 0),
	RST_GPIOB	= _REG_BIT(0x64, 1),
	RST_GPIOC	= _REG_BIT(0x64, 2),
	RST_GPIOD	= _REG_BIT(0x64, 3),
	RST_GPIOE	= _REG_BIT(0x64, 4),
	RST_GPIOF	= _REG_BIT(0x64, 5),
	RST_GPIOG	= _REG_BIT(0x64, 6),
	RST_GPIOH	= _REG_BIT(0x64, 7),
	RST_GPIOI	= _REG_BIT(0x64, 8),
	RST_GPIOJ	= _REG_BIT(0x64, 9),
	RST_ADC12	= _REG_BIT(0x64, 10),
	RST_DCMI	= _REG_BIT(0x64, 12),
	RST_OTG		= _REG_BIT(0x64, 14),
	RST_AES		= _REG_BIT(0x64, 16),
	RST_HASH	= _REG_BIT(0x64, 17),
	RST_RNG		= _REG_BIT(0x64, 18),
	RST_PKA		= _REG_BIT(0x64, 19),
	RST_SAES	= _REG_BIT(0x64, 20),
	RST_OTFDEC1 = _REG_BIT(0x64, 23),
	RST_OTFDEC2 = _REG_BIT(0x64, 24),
	RST_SDMMC1	= _REG_BIT(0x64, 27),
	RST_SDMMC2	= _REG_BIT(0x64, 28),

	RST_FSMC		= _REG_BIT(0x68, 0),
	RST_OCTOSPI1	= _REG_BIT(0x68, 4),
	RST_OCTOSPI2	= _REG_BIT(0x68, 8),
	RST_HSPI1		= _REG_BIT(0x68, 12),

	/* AHB3 peripherals */
	RST_LPGIO1	= _REG_BIT(0x6C, 0),
	RST_ADC4	= _REG_BIT(0x6C, 5),
	RST_LPDMA1	= _REG_BIT(0x6C, 9),
	RST_ADF1	= _REG_BIT(0x6C, 10),

	/* APB1 peripherals */
	RST_TIM2	= _REG_BIT(0x74, 0),
	RST_TIM3	= _REG_BIT(0x74, 1),
	RST_TIM4	= _REG_BIT(0x74, 2),
	RST_TIM5	= _REG_BIT(0x74, 3),
	RST_TIM6	= _REG_BIT(0x74, 4),
	RST_TIM7	= _REG_BIT(0x74, 5),
	RST_SPI2	= _REG_BIT(0x74, 14),
	RST_USART2	= _REG_BIT(0x74, 17),
	RST_USART3	= _REG_BIT(0x74, 18),
	RST_USART4	= _REG_BIT(0x74, 19),
	RST_USART5	= _REG_BIT(0x74, 20),
	RST_I2C1	= _REG_BIT(0x74, 21),
	RST_I2C2	= _REG_BIT(0x74, 22),
	RST_CRS		= _REG_BIT(0x74, 24),
	RST_USART6	= _REG_BIT(0x74, 25),
	RST_I2C4	= _REG_BIT(0x78, 1),
	RST_LPTIM2	= _REG_BIT(0x78, 5),
	RST_I2C5	= _REG_BIT(0x78, 6),
	RST_I2C6	= _REG_BIT(0x78, 7),
	RST_FDCAN1	= _REG_BIT(0x78, 9),
	RST_UCPD1	= _REG_BIT(0x78, 23),

	/* APB2 peripherals*/
	RST_TIM1	= _REG_BIT(0x7C, 11),
	RST_SPI1	= _REG_BIT(0x7C, 12),
	RST_TIM8	= _REG_BIT(0x7C, 13),
	RST_USART1	= _REG_BIT(0x7C, 14),
	RST_TIM15	= _REG_BIT(0x7C, 16),
	RST_TIM16	= _REG_BIT(0x7C, 17),
	RST_TIM17	= _REG_BIT(0x7C, 18),
	RST_SAI1	= _REG_BIT(0x7C, 21),
	RST_SAI2	= _REG_BIT(0x7C, 22),
	RST_USB		= _REG_BIT(0x7C, 24),
	RST_GFXTIM	= _REG_BIT(0x7C, 25),
	RST_LTDCR	= _REG_BIT(0x7C, 26),
	RST_DSI 	= _REG_BIT(0x7C, 27),

	/* APB3 peripherals */
	RST_SYSCFG	= _REG_BIT(0x80, 1),
	RST_SPI3	= _REG_BIT(0x80, 5),
	RST_LPUART1	= _REG_BIT(0x80, 6),
	RST_I2C3	= _REG_BIT(0x80, 7),
	RST_LPTIM1	= _REG_BIT(0x80, 11),
	RST_LPTIM3	= _REG_BIT(0x80, 12),
	RST_LPTIM4	= _REG_BIT(0x80, 13),
	RST_OPAMP	= _REG_BIT(0x80, 14),
	RST_COMP	= _REG_BIT(0x80, 15),
	RST_VREF	= _REG_BIT(0x80, 20),

};


enum rcc_periph_clken {
	/* AHB1 peripherals */
	RCC_GPDMA	= _REG_BIT(0x88, 0),
	RCC_CORDIC	= _REG_BIT(0x88, 1),
	RCC_FMAC	= _REG_BIT(0x88, 2),
	RCC_MDF1	= _REG_BIT(0x88, 3),
	RCC_FLASH	= _REG_BIT(0x88, 8),
	RCC_CRCS	= _REG_BIT(0x88, 12),
	RCC_JPEG	= _REG_BIT(0x88, 15),
	RCC_TSCR	= _REG_BIT(0x88, 16),
	RCC_RAMCFG	= _REG_BIT(0x88, 17),
	RCC_DMA2D	= _REG_BIT(0x88, 18),
	RCC_GFXMMU	= _REG_BIT(0x88, 19),
	RCC_GPU2D	= _REG_BIT(0x88, 20),
	RCC_DCACHE2	= _REG_BIT(0x88, 21),
	RCC_GTZC1	= _REG_BIT(0x88, 24),
	RCC_BKPSRAM = _REG_BIT(0x88, 28),
	RCC_DCACHE1	= _REG_BIT(0x88, 30),
	RCC_SRAM1	= _REG_BIT(0x88, 31),

	/* AHB2 peripherals */
	RCC_GPIOA	= _REG_BIT(0x8C, 0),
	RCC_GPIOB	= _REG_BIT(0x8C, 1),
	RCC_GPIOC	= _REG_BIT(0x8C, 2),
	RCC_GPIOD	= _REG_BIT(0x8C, 3),
	RCC_GPIOE	= _REG_BIT(0x8C, 4),
	RCC_GPIOF	= _REG_BIT(0x8C, 5),
	RCC_GPIOG	= _REG_BIT(0x8C, 6),
	RCC_GPIOH	= _REG_BIT(0x8C, 7),
	RCC_GPIOI	= _REG_BIT(0x8C, 8),
	RCC_GPIOJ	= _REG_BIT(0x8C, 9),
	RCC_OTGFS	= _REG_BIT(0x8C, 14),
	RCC_OTGHS	= _REG_BIT(0x8C, 14),

	/* AHB3 peripherals */
	RCC_PWR		= _REG_BIT(0x94, 2),
	RCC_ADC4	= _REG_BIT(0x94, 5),
	RCC_DAC1	= _REG_BIT(0x94, 6),

	/* APB1 peripherals */
	RCC_TIM2	= _REG_BIT(0x9C, 0),
	RCC_TIM3	= _REG_BIT(0x9C, 1),
	RCC_TIM4	= _REG_BIT(0x9C, 2),
	RCC_TIM5	= _REG_BIT(0x9C, 3),
	RCC_TIM6	= _REG_BIT(0x9C, 4),
	RCC_TIM7	= _REG_BIT(0x9C, 5),
	RCC_WWDG	= _REG_BIT(0x9C, 11),
	RCC_SPI2	= _REG_BIT(0x9C, 14),
	RCC_USART2	= _REG_BIT(0x9C, 17),
	RCC_USART3	= _REG_BIT(0x9C, 18),
	RCC_USART4	= _REG_BIT(0x9C, 19),
	RCC_USART5	= _REG_BIT(0x9C, 20),
	RCC_I2C1	= _REG_BIT(0x9C, 21),
	RCC_I2C2	= _REG_BIT(0x9C, 22),
	RCC_CRS		= _REG_BIT(0x9C, 24),
	RCC_USART6	= _REG_BIT(0x9C, 25),
	RCC_I2C4	= _REG_BIT(0x9C, 1),
	RCC_LPTIM2	= _REG_BIT(0x9C, 5),
	RCC_I2C5	= _REG_BIT(0x9C, 6),
	RCC_I2C6	= _REG_BIT(0x9C, 7),
	RCC_FDCAN1	= _REG_BIT(0x9C, 9),
	RCC_UCPD1	= _REG_BIT(0x9C, 23),

	/* APB2 peripherals */
	RCC_TIM1	= _REG_BIT(0xA4, 11),
	RCC_SPI1	= _REG_BIT(0xA4, 12),
	RCC_TIM8	= _REG_BIT(0xA4, 13),
	RCC_USART1	= _REG_BIT(0xA4, 14),
	RCC_TIM15	= _REG_BIT(0xA4, 16),
	RCC_TIM16	= _REG_BIT(0xA4, 17),
	RCC_TIM17	= _REG_BIT(0xA4, 18),
	RCC_SAI1	= _REG_BIT(0xA4, 21),
	RCC_SAI2	= _REG_BIT(0xA4, 22),
	RCC_USB		= _REG_BIT(0xA4, 24),
	RCC_GFXTIM	= _REG_BIT(0xA4, 25),
	RCC_LTDCR	= _REG_BIT(0xA4, 26),
	RCC_DSI 	= _REG_BIT(0xA4, 27),

	/* APB3 peripherals */
	RCC_SYSCFG	= _REG_BIT(0xA8, 1),
	RCC_SPI3	= _REG_BIT(0xA8, 5),
	RCC_LPUART1	= _REG_BIT(0xA8, 6),
	RCC_I2C3	= _REG_BIT(0xA8, 7),
	RCC_LPTIM1	= _REG_BIT(0xA8, 11),
	RCC_LPTIM3	= _REG_BIT(0xA8, 12),
	RCC_LPTIM4	= _REG_BIT(0xA8, 13),
	RCC_OPAMP	= _REG_BIT(0xA8, 14),
	RCC_COMP	= _REG_BIT(0xA8, 15),
	RCC_VREF	= _REG_BIT(0xA8, 20),
};
#undef _REG_BIT

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS
uint32_t rcc_get_usart_clk_freq(uint32_t usart);
void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_set_sysclk_source(enum rcc_osc clk);
uint32_t rcc_system_clock_source(void);
void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t sel);
void rcc_clock_setup_hsi(const struct rcc_clock_scale *clock);
void rcc_set_ppre2(uint32_t ppre1);
void rcc_set_ppre1(uint32_t ppre1);
void rcc_set_hpre(uint32_t hpre);
END_DECLS

/**@}*/

#endif
