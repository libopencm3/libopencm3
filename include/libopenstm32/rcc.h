/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENSTM32_RCC_H
#define LIBOPENSTM32_RCC_H

#include <libopenstm32/memorymap.h>
#include <libopenstm32/common.h>

/* Note: Regs/bits marked (**) only exist in "connectivity line" STM32s. */
/* Note: Regs/bits marked (XX) do NOT exist in "connectivity line" STM32s. */

/* --- RCC registers ------------------------------------------------------- */

#define RCC_CR				MMIO32(RCC_BASE + 0x00)
#define RCC_CFGR			MMIO32(RCC_BASE + 0x04)
#define RCC_CIR				MMIO32(RCC_BASE + 0x08)
#define RCC_APB2RSTR			MMIO32(RCC_BASE + 0x0c)
#define RCC_APB1RSTR			MMIO32(RCC_BASE + 0x10)
#define RCC_AHBENR			MMIO32(RCC_BASE + 0x14)
#define RCC_APB2ENR			MMIO32(RCC_BASE + 0x18)
#define RCC_APB1ENR			MMIO32(RCC_BASE + 0x1c)
#define RCC_BDCR			MMIO32(RCC_BASE + 0x20)
#define RCC_CSR				MMIO32(RCC_BASE + 0x24)
#define RCC_AHBRSTR			MMIO32(RCC_BASE + 0x28) /* (**) */
#define RCC_CFGR2			MMIO32(RCC_BASE + 0x2c) /* (**) */

/* --- RCC_CR values ------------------------------------------------------- */

#define PLL3RDY				(1 << 29) /* (**) */
#define PLL3ON				(1 << 28) /* (**) */
#define PLL2RDY				(1 << 27) /* (**) */
#define PLL2ON				(1 << 26) /* (**) */
#define PLLRDY				(1 << 25)
#define PLLON				(1 << 24)
#define CSSON				(1 << 19)
#define HSEBYP				(1 << 18)
#define HSERDY				(1 << 17)
#define HSEON				(1 << 16)
/* HSICAL: [15:8] */
/* HSITRIM: [7:3] */
#define HSIRDY				(1 << 1)
#define HSION				(1 << 0)

/* --- RCC_CFGR values ----------------------------------------------------- */

/* MCO: Microcontroller clock output */
#define MCO_NOCLK			0x0
#define MCO_SYSCLK			0x4
#define MCO_HSICLK			0x5
#define MCO_HSECLK			0x6
#define MCO_PLLCLK_DIV2			0x7
#define MCO_PLL2CLK			0x8 /* (**) */
#define MCO_PLL3CLK_DIV2		0x9 /* (**) */
#define MCO_XT1				0xa /* (**) */
#define MCO_PLL3			0xb /* (**) */

/* USBPRE: USB prescaler (RCC_CFGR[22]) */
#define USBPRE_PLL_CLK_DIV1_5		0x0
#define USBPRE_PLL_CLK_NODIV		0x1

/* OTGFSPRE: USB OTG FS prescaler (RCC_CFGR[22]; only in conn. line STM32s) */
#define USBPRE_PLL_VCO_CLK_DIV3		0x0
#define USBPRE_PLL_VCO_CLK_DIV2		0x1

/* PLLMUL: PLL multiplication factor */
#define PLLMUL_PLL_CLK_MUL2		0x0 /* (XX) */
#define PLLMUL_PLL_CLK_MUL3		0x1 /* (XX) */
#define PLLMUL_PLL_CLK_MUL4		0x2
#define PLLMUL_PLL_CLK_MUL5		0x3
#define PLLMUL_PLL_CLK_MUL6		0x4
#define PLLMUL_PLL_CLK_MUL7		0x5
#define PLLMUL_PLL_CLK_MUL8		0x6
#define PLLMUL_PLL_CLK_MUL9		0x7
#define PLLMUL_PLL_CLK_MUL10		0x8 /* (XX) */
#define PLLMUL_PLL_CLK_MUL11		0x9 /* (XX) */
#define PLLMUL_PLL_CLK_MUL12		0xa /* (XX) */
#define PLLMUL_PLL_CLK_MUL13		0xb /* (XX) */
#define PLLMUL_PLL_CLK_MUL14		0xc /* (XX) */
#define PLLMUL_PLL_CLK_MUL15		0xd /* 0xd: PLL x 15 */
#define PLLMUL_PLL_CLK_MUL6_5		0xd /* 0xd: PLL x 6.5 for conn. line */
#define PLLMUL_PLL_CLK_MUL16		0xe /* (XX) */
// #define PLLMUL_PLL_CLK_MUL16		0xf /* (XX) */ /* Errata? 17? */

/* TODO: conn. line differs. */
/* PLLXTPRE: HSE divider for PLL entry */
#define PLLXTPRE_HSE_CLK		0x0
#define PLLXTPRE_HSE_CLK_DIV2		0x1

/* PLLSRC: PLL entry clock source */
#define PLLSRC_HSI_CLK_DIV2		0x0
#define PLLSRC_HSE_CLK			0x1
#define PLLSRC_PREDIV1_CLK		0x1 /* On conn. line */

/* ADCPRE: ADC prescaler */
/* TODO: Datasheet says "PLCK2". Typo? Should be "PCLK2"? */
#define ADCPRE_PLCK2_DIV2		0x0
#define ADCPRE_PLCK2_DIV4		0x1
#define ADCPRE_PLCK2_DIV6		0x2
#define ADCPRE_PLCK2_DIV8		0x3

/* PPRE2: APB high-speed prescaler (APB2) */
#define PPRE2_HCLK_NODIV		0x0
#define PPRE2_HCLK_DIV2			0x4
#define PPRE2_HCLK_DIV4			0x5
#define PPRE2_HCLK_DIV8			0x6
#define PPRE2_HCLK_DIV16		0x7

/* PPRE1: APB low-speed prescaler (APB1) */
#define PPRE1_HCLK_NODIV		0x0
#define PPRE1_HCLK_DIV2			0x4
#define PPRE1_HCLK_DIV4			0x5
#define PPRE1_HCLK_DIV8			0x6
#define PPRE1_HCLK_DIV16		0x7

/* HPRE: AHB prescaler */
#define HPRE_SYSCLK_NODIV		0x0
#define HPRE_SYSCLK_DIV2		0x8
#define HPRE_SYSCLK_DIV4		0x9
#define HPRE_SYSCLK_DIV8		0xa
#define HPRE_SYSCLK_DIV16		0xb
#define HPRE_SYSCLK_DIV64		0xc
#define HPRE_SYSCLK_DIV128		0xd
#define HPRE_SYSCLK_DIV256		0xe
#define HPRE_SYSCLK_DIV512		0xf

/* SWS: System clock switch status */
#define SWS_SYSCLKSEL_HSICLK		0x0
#define SWS_SYSCLKSEL_HSECLK		0x1
#define SWS_SYSCLKSEL_PLLCLK		0x2

/* SW: System clock switch */
#define SW_SYSCLKSEL_HSICLK		0x0
#define SW_SYSCLKSEL_HSECLK		0x1
#define SW_SYSCLKSEL_PLLCLK		0x2

/* --- RCC_CIR values ------------------------------------------------------ */

/* Clock security system interrupt clear bit */
#define CSSC				(1 << 23)

/* OSC ready interrupt clear bits */
#define PLL3RDYC			(1 << 22) /* (**) */
#define PLL2RDYC			(1 << 21) /* (**) */
#define PLLRDYC				(1 << 20)
#define HSERDYC				(1 << 19)
#define HSIRDYC				(1 << 18)
#define LSERDYC				(1 << 17)
#define LSIRDYC				(1 << 16)

/* OSC ready interrupt enable bits */
#define PLL3RDYIE			(1 << 14) /* (**) */
#define PLL2RDYIE			(1 << 13) /* (**) */
#define PLLRDYIE			(1 << 12)
#define HSERDYIE			(1 << 11)
#define HSIRDYIE			(1 << 10)
#define LSERDYIE			(1 << 9)
#define LSIRDYIE			(1 << 8)

/* Clock security system interrupt flag bit */
#define CSSF				(1 << 7)

/* OSC ready interrupt flag bits */
#define PLL3RDYF			(1 << 6) /* (**) */
#define PLL2RDYF			(1 << 5) /* (**) */
#define PLLRDYF				(1 << 4)
#define HSERDYF				(1 << 3)
#define HSIRDYF				(1 << 2)
#define LSERDYF				(1 << 1)
#define LSIRDYF				(1 << 0)

/* --- RCC_APB2RSTR values ------------------------------------------------- */

#define ADC3RST				(1 << 15) /* (XX) */
#define USART1RST			(1 << 14)
#define TIM8RST				(1 << 13) /* (XX) */
#define SPI1RST				(1 << 12)
#define TIM1RST				(1 << 11)
#define ADC2RST				(1 << 10)
#define ADC1RST				(1 << 9)
#define IOPGRST				(1 << 8)  /* (XX) */
#define IOPFRST				(1 << 7)  /* (XX) */
#define IOPERST				(1 << 6)
#define IOPDRST				(1 << 5)
#define IOPCRST				(1 << 4)
#define IOPBRST				(1 << 3)
#define IOPARST				(1 << 2)
#define AFIORST				(1 << 0)

/* --- RCC_APB1RSTR values ------------------------------------------------- */

#define DACRST				(1 << 29)
#define PWRRST				(1 << 28)
#define BKPRST				(1 << 27)
#define CAN2RST				(1 << 26) /* (**) */
#define CAN1RST				(1 << 25) /* (**) */
#define CANRST				(1 << 25) /* (XX) Alias for CAN1RST */
#define USBRST				(1 << 23) /* (XX) */
#define I2C2RST				(1 << 22)
#define I2C1RST				(1 << 21)
#define USART5RST			(1 << 20)
#define USART4RST			(1 << 19)
#define USART3RST			(1 << 18)
#define USART2RST			(1 << 17)
#define SPI3RST				(1 << 15)
#define SPI2RST				(1 << 14)
#define WWDGRST				(1 << 11)
#define TIM7RST				(1 << 5)
#define TIM6RST				(1 << 4)
#define TIM5RST				(1 << 3)
#define TIM4RST				(1 << 2)
#define TIM3RST				(1 << 1)
#define TIM2RST				(1 << 0)

/* --- RCC_AHBENR values --------------------------------------------------- */

#define SDIOEN				(1 << 10)
#define FSMCEN				(1 << 8)
#define CRCEN				(1 << 6)
#define FLITFEN				(1 << 4)
#define SRAMEN				(1 << 2)
#define DMA2EN				(1 << 1)
#define DMA1EN				(1 << 0)

/* --- RCC_APB2ENR values -------------------------------------------------- */

#define ADC3EN				(1 << 15) /* (XX) */
#define USART1EN			(1 << 14)
#define TIM8EN				(1 << 13) /* (XX) */
#define SPI1EN				(1 << 12)
#define TIM1EN				(1 << 11)
#define ADC2EN				(1 << 10)
#define ADC1EN				(1 << 9)
#define IOPGEN				(1 << 8)  /* (XX) */
#define IOPFEN				(1 << 7)  /* (XX) */
#define IOPEEN				(1 << 6)
#define IOPDEN				(1 << 5)
#define IOPCEN				(1 << 4)
#define IOPBEN				(1 << 3)
#define IOPAEN				(1 << 2)
#define AFIOEN				(1 << 0)

/* --- RCC_APB1ENR values -------------------------------------------------- */

#define DACEN				(1 << 29)
#define PWREN				(1 << 28)
#define BKPEN				(1 << 27)
#define CAN2EN				(1 << 26) /* (**) */
#define CAN1EN				(1 << 25) /* (**) */
#define CANEN				(1 << 25) /* (XX) Alias for CAN1EN */
#define USBEN				(1 << 23) /* (XX) */
#define I2C2EN				(1 << 22)
#define I2C1EN				(1 << 21)
#define USART5EN			(1 << 20)
#define USART4EN			(1 << 19)
#define USART3EN			(1 << 18)
#define USART2EN			(1 << 17)
#define SPI3EN				(1 << 15)
#define SPI2EN				(1 << 14)
#define WWDGEN				(1 << 11)
#define TIM7EN				(1 << 5)
#define TIM6EN				(1 << 4)
#define TIM5EN				(1 << 3)
#define TIM4EN				(1 << 2)
#define TIM3EN				(1 << 1)
#define TIM2EN				(1 << 0)

/* --- RCC_BDCR values ----------------------------------------------------- */

#define BDRST				(1 << 16)
#define RTCEN				(1 << 15)
/* RCC_BDCR[9:8]: RTCSEL */
#define LSEBYP				(1 << 2)
#define LSERDY				(1 << 1)
#define LSEON				(1 << 0)

/* --- RCC_CSR values ------------------------------------------------------ */

#define LPWRRSTF			(1 << 31)
#define WWDGRSTF			(1 << 30)
#define IWDGRSTF			(1 << 29)
#define SFTRSTF				(1 << 28)
#define PORRSTF				(1 << 27)
#define PINRSTF				(1 << 26)
#define RMVF				(1 << 24)
#define LSIRDY				(1 << 1)
#define LSION				(1 << 0)

/* --- RCC_AHBRSTR values -------------------------------------------------- */

#define ETHMACRST			(1 << 14)
#define OTGFSRST			(1 << 12)

/* --- RCC_CFGR2 values ---------------------------------------------------- */

/* I2S3SRC: I2S3 clock source */
#define I2S3SRC_SYSCLK			0x0
#define I2S3SRC_PLL3_VCO_CLK		0x1

/* I2S2SRC: I2S2 clock source */
#define I2S2SRC_SYSCLK			0x0
#define I2S2SRC_PLL3_VCO_CLK		0x1

/* PREDIV1SRC: PREDIV1 entry clock source */
#define PREDIV1SRC_HSE_CLK		0x0
#define PREDIV1SRC_PLL2_CLK		0x1

#define PLL2MUL				(1 << 0)
#define PREDIV2				(1 << 0)
#define PREDIV1				(1 << 0)

/* PLL3MUL: PLL3 multiplication factor */
#define PLL3MUL_PLL3_CLK_MUL8		0x6
#define PLL3MUL_PLL3_CLK_MUL9		0x7
#define PLL3MUL_PLL3_CLK_MUL10		0x8
#define PLL3MUL_PLL3_CLK_MUL11		0x9
#define PLL3MUL_PLL3_CLK_MUL12		0xa
#define PLL3MUL_PLL3_CLK_MUL13		0xb
#define PLL3MUL_PLL3_CLK_MUL14		0xc
#define PLL3MUL_PLL3_CLK_MUL16		0xe
#define PLL3MUL_PLL3_CLK_MUL20		0xf

/* PLL2MUL: PLL2 multiplication factor */
#define PLL2MUL_PLL2_CLK_MUL8		0x6
#define PLL2MUL_PLL2_CLK_MUL9		0x7
#define PLL2MUL_PLL2_CLK_MUL10		0x8
#define PLL2MUL_PLL2_CLK_MUL11		0x9
#define PLL2MUL_PLL2_CLK_MUL12		0xa
#define PLL2MUL_PLL2_CLK_MUL13		0xb
#define PLL2MUL_PLL2_CLK_MUL14		0xc
#define PLL2MUL_PLL2_CLK_MUL16		0xe
#define PLL2MUL_PLL2_CLK_MUL20		0xf

/* PREDIV2: PREDIV2 division factor */
#define PREDIV2_NODIV			0x0
#define PREDIV2_DIV2			0x1
#define PREDIV2_DIV3			0x2
#define PREDIV2_DIV4			0x3
#define PREDIV2_DIV5			0x4
#define PREDIV2_DIV6			0x5
#define PREDIV2_DIV7			0x6
#define PREDIV2_DIV8			0x7
#define PREDIV2_DIV9			0x8
#define PREDIV2_DIV10			0x9
#define PREDIV2_DIV11			0xa
#define PREDIV2_DIV12			0xb
#define PREDIV2_DIV13			0xc
#define PREDIV2_DIV14			0xd
#define PREDIV2_DIV15			0xe
#define PREDIV2_DIV16			0xf

/* --- Function prototypes ------------------------------------------------- */

typedef enum {
	PLL, HSE, HSI, LSE, LSI
} osc_t;

void rcc_osc_ready_int_clear(osc_t osc);
void rcc_osc_ready_int_enable(osc_t osc);
void rcc_osc_ready_int_disable(osc_t osc);
int rcc_osc_ready_int_flag(osc_t osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_wait_for_osc_ready(osc_t osc);
void rcc_osc_on(osc_t osc);
void rcc_osc_off(osc_t osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_osc_bypass_enable(osc_t osc);
void rcc_osc_bypass_disable(osc_t osc);
void rcc_peripheral_enable_clock(volatile u32 *reg, u32 en);
void rcc_peripheral_disable_clock(volatile u32 *reg, u32 en);
void rcc_peripheral_reset(volatile u32 *reg, u32 reset);
void rcc_peripheral_clear_reset(volatile u32 *reg, u32 clear_reset);
void rcc_set_sysclk_source(u32 clk);
void rcc_set_pll_multiplication_factor(u32 mul);
void rcc_set_pll_source(u32 pllsrc);
void rcc_set_pllxtpre(u32 pllxtpre);
void rcc_set_adcpre(u32 adcpre);
void rcc_set_ppre2(u32 ppre2);
void rcc_set_ppre1(u32 ppre1);
void rcc_set_hpre(u32 hpre);
u32 rcc_get_system_clock_source(int i);

#endif
