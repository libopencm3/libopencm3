/** @defgroup rcc_defines RCC Defines
@brief <b>Defined Constants and Types for the STM32H7xx Reset and Clock
Control</b>
@ingroup STM32H7xx_defines
@version 1.0.0
LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Brian Viele <vielster@allocor.tech>
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

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

#include <libopencm3/stm32/h7/pwr.h>

/**@{*/

/* --- RCC registers ------------------------------------------------------- */
#define RCC_CR                    MMIO32(RCC_BASE + 0x000)
#define RCC_CFGR                  MMIO32(RCC_BASE + 0x010)

/** @addtogroup rcc_cr_values RCC_CR_VALUES
 * @ingroup rcc_registers
@{*/
#define RCC_CR_PLL3AIRDY          (1 << 29)
#define RCC_CR_PLL3AION           (1 << 28)
#define RCC_CR_PLL2RDY            (1 << 27)
#define RCC_CR_PLL2ON             (1 << 26)
#define RCC_CR_PLL1RDY            (1 << 25)
#define RCC_CR_PLL1ON             (1 << 24)
#define RCC_CR_HSECSSON           (1 << 19)
#define RCC_CR_HSEBYP             (1 << 18)
#define RCC_CR_HSERDY             (1 << 17)
#define RCC_CR_HSEON              (1 << 16)
#define RCC_CR_D2CKRDY            (1 << 15)
#define RCC_CR_D1CKRDY            (1 << 14)
#define RCC_CR_HSI48RDY           (1 << 13)
#define RCC_CR_HSI48ON            (1 << 12)
#define RCC_CR_CSIKERON           (1 << 9)
#define RCC_CR_CSIRDY             (1 << 8)
#define RCC_CR_CSION              (1 << 7)
#define RCC_CR_HSIDIVF            (1 << 5)
#define RCC_CR_HSIDIV_MASK        (0x03)
#define RCC_CR_HSIDIV_SHIFT       3
#define RCC_CR_HSIDIV(n)          (((n) & RCC_CR_HSIDIV_MASK) << RCC_CR_HSIDIV_MASK)
#define RCC_CR_HSIRDY             (1 << 2)
#define RCC_CR_HSIKERON           (1 << 1)
#define RCC_CR_HSION              (1 << 0)
/**@}*/

/** @addtogroup rcc_rstr_values RCC_RSTR_VALUES
 * @ingroup rcc_registers
@{*/
#define RCC_AHB1RSTR              MMIO32(RCC_BASE + 0x080)
#define RCC_AHB2RSTR              MMIO32(RCC_BASE + 0x084)
#define RCC_AHB3RSTR              MMIO32(RCC_BASE + 0x07C)
#define RCC_AHB4RSTR              MMIO32(RCC_BASE + 0x088)
#define RCC_APB1LRSTR             MMIO32(RCC_BASE + 0x090)
#define RCC_APB1HRSTR             MMIO32(RCC_BASE + 0x094)
#define RCC_APB2RSTR              MMIO32(RCC_BASE + 0x098)
#define RCC_APB3RSTR              MMIO32(RCC_BASE + 0x08C)
#define RCC_APB4RSTR              MMIO32(RCC_BASE + 0x09C)
#define RCC_AHB1ENR               MMIO32(RCC_BASE + 0x0D8)
#define RCC_AHB2ENR               MMIO32(RCC_BASE + 0x0DC)
#define RCC_AHB3ENR               MMIO32(RCC_BASE + 0x0D4)
#define RCC_AHB4ENR               MMIO32(RCC_BASE + 0x0E0)
#define RCC_APB1LENR              MMIO32(RCC_BASE + 0x0E8)
#define RCC_APB1HENR              MMIO32(RCC_BASE + 0x0EC)
#define RCC_APB2ENR               MMIO32(RCC_BASE + 0x0F0)
#define RCC_APB3ENR               MMIO32(RCC_BASE + 0x0E4)
#define RCC_APB4ENR               MMIO32(RCC_BASE + 0x0F4)
#define RCC_AHB1LPENR             MMIO32(RCC_BASE + 0x100)
#define RCC_AHB2LPENR             MMIO32(RCC_BASE + 0x104)
#define RCC_AHB4LPENR             MMIO32(RCC_BASE + 0x108)
#define RCC_APB1LLPENR            MMIO32(RCC_BASE + 0x110)
#define RCC_APB1HLPENR            MMIO32(RCC_BASE + 0x114)
#define RCC_APB2LPENR             MMIO32(RCC_BASE + 0x118)
#define RCC_APB3LPENR             MMIO32(RCC_BASE + 0x10C)
#define RCC_APB4LPENR             MMIO32(RCC_BASE + 0x11C)
#define RCC_BDCR                  MMIO32(RCC_BASE + 0x70)
#define RCC_CSR                   MMIO32(RCC_BASE + 0x74)
#define RCC_SSCGR                 MMIO32(RCC_BASE + 0x80)
#define RCC_PLLI2SCFGR            MMIO32(RCC_BASE + 0x84)
#define RCC_PLLSAICFGR            MMIO32(RCC_BASE + 0x88)
#define RCC_DCKCFGR1              MMIO32(RCC_BASE + 0x8C)
#define RCC_DCKCFGR2              MMIO32(RCC_BASE + 0x90)
/**@}*/

/** @addtogroup rcc_cfgr_values RCC_CFGR_VALUES
 * @ingroup rcc_registers
@{*/
/* MCO2: Microcontroller clock output 2 */
#define RCC_CFGR_MCO2_MASK        0x7
#define RCC_CFGR_MCO2_SHIFT       29
#define RCC_CFGR_MCO2_SYSCLK      0x0
#define RCC_CFGR_MCO2_PLL2        0x1
#define RCC_CFGR_MCO2_HSE         0x2
#define RCC_CFGR_MCO2_PLL1        0x3
#define RCC_CFGR_MCO2_CSI         0x4
#define RCC_CFGR_MCO2_LSI         0x5

/* MCO1/2PRE: MCO Prescalers */
#define RCC_CFGR_MCOPRE_MASK      0xf
#define RCC_CFGR_MCO2PRE_SHIFT    25
#define RCC_CFGR_MCO1PRE_SHIFT    18
#define RCC_CFGR_MCOPRE_DIV_NONE  0x0
#define RCC_CFGR_MCOPRE_DIV_BYP   0x1
#define RCC_CFGR_MCOPRE_DIV_2     0x2
#define RCC_CFGR_MCOPRE_DIV_3     0x3
#define RCC_CFGR_MCOPRE_DIV_4     0x4
/* Note: MCOPRE_DIV can go from 1 - 15  */

/* MCO1: Microcontroller clock output 1 */
#define RCC_CFGR_MCO1_MASK        0x7
#define RCC_CFGR_MCO1_SHIFT       22
#define RCC_CFGR_MCO1_HSI         0x0
#define RCC_CFGR_MCO1_LSE         0x1
#define RCC_CFGR_MCO1_HSE         0x2
#define RCC_CFGR_MCO1_PLL1        0x3
#define RCC_CFGR_MCO1_HSI48       0x4
#define RCC_CFGR_MCO_SHIFT        RCC_CFGR_MCO1_SHIFT
#define RCC_CFGR_MCO_MASK         RCC_CFGR_MCO1_MASK

/* RTCPRE: HSE division factor for RTC clock */
#define RCC_CFGR_RTCPRE_SHIFT     8
#define RCC_CFGR_RTCPRE_MASK      0x3f

/* SWS: System clock switch status */
#define RCC_CFGR_SWS_SHIFT        3
#define RCC_CFGR_SWS_MASK         0x7
#define RCC_CFGR_SWS_HSI          0x0
#define RCC_CFGR_SWS_CSI          0x1
#define RCC_CFGR_SWS_HSE          0x2
#define RCC_CFGR_SWS_PLL1         0x3

/* SW: System clock switch */
#define RCC_CFGR_SW_SHIFT         0
#define RCC_CFGR_SW_MASK          0x7
#define RCC_CFGR_SW_HSI           0x0
#define RCC_CFGR_SW_CSI           0x1
#define RCC_CFGR_SW_HSE           0x2
#define RCC_CFGR_SW_PLL1          0x3
/**@}*/


/** @addtogroup rcc_bdcr_values RCC_BDCR_VALUES
 * @ingroup rcc_registers
@{*/
#define RCC_BDCR_BDRST            (1 << 16)
#define RCC_BDCR_RTCEN            (1 << 15)
#define RCC_BDCR_RTCSEL_MASK      0x3
#define RCC_BDCR_RTCSEL_SHIFT     8
#define RCC_BDCR_RTCSEL_NONE      0
#define RCC_BDCR_RTCSEL_LSE       1
#define RCC_BDCR_RTCSEL_LSI       2
#define RCC_BDCR_RTCSEL_HSE       3
#define RCC_BDCR_LSEDRV_MASK      0x3
#define RCC_BDCR_LSEDRV_SHIFT     3
#define RCC_BDCR_LSEDRV_LOW       0
#define RCC_BDCR_LSEDRV_MEDH      1 /* good job st */
#define RCC_BDCR_LSEDRV_MEDL      2
#define RCC_BDCR_LSEDRV_HIGH      3
#define RCC_BDCR_LSEBYP           (1 << 2)
#define RCC_BDCR_LSERDY           (1 << 1)
#define RCC_BDCR_LSEON            (1 << 0)
/**@}*/

/** @addtogroup rcc_bdcr_values RCC_CSR_VALUES
 * @ingroup rcc_registers
@{*/
#define RCC_CSR_LSIRDY            (1 << 1)
#define RCC_CSR_LSION             (1 << 0)
/**@}*/

extern uint32_t rcc_ahb_frequency;
extern uint32_t rcc_apb1_frequency;
extern uint32_t rcc_apb2_frequency;

enum rcc_osc {
  RCC_PLL,
  RCC_HSE,
  RCC_HSI,
  RCC_LSE,
  RCC_LSI
};

#define _REG_BIT(base, bit)       (((base) << 5) + (bit))

enum rcc_periph_clken {
   /* AHB1 peripherals */
  RCC_DMA1        = _REG_BIT(0xD8, 0),
  RCC_DMA2        = _REG_BIT(0xD8, 1),
  RCC_ADC12       = _REG_BIT(0xD8, 5),
  RCC_ETH1MAC     = _REG_BIT(0xD8, 15),
  RCC_ETH1TX      = _REG_BIT(0xD8, 16),
  RCC_ETH1RX      = _REG_BIT(0xD8, 17),
  RCC_USB2OTGHSULPIEN = _REG_BIT(0xD8, 18),
  RCC_USB1OTGHSEN = _REG_BIT(0xD8, 25),
  RCC_USB1OTGHSULPIEN = _REG_BIT(0xD8, 26),
  RCC_USB2OTGHSEN = _REG_BIT(0xD8, 27),

  /* AHB2 peripherals */
  RCC_DCMI        = _REG_BIT(0xDC, 0),
  RCC_CRYP        = _REG_BIT(0xDC, 4),
  RCC_HASH        = _REG_BIT(0xDC, 5),
  RCC_RNG         = _REG_BIT(0xDC, 6),
  RCC_SDMMC2      = _REG_BIT(0xDC, 9),
  RCC_SRAM1       = _REG_BIT(0xDC, 29),
  RCC_SRAM2       = _REG_BIT(0xDC, 30),
  RCC_SRAM3       = _REG_BIT(0xDC, 31),

  /* AHB3 peripherals */
  RCC_MDMA        = _REG_BIT(0xD4, 0),
  RCC_DMA2D       = _REG_BIT(0xD4, 4),
  RCC_JPGDEC      = _REG_BIT(0xD4, 5),
  RCC_FMC         = _REG_BIT(0xD4, 12),
  RCC_QSPI        = _REG_BIT(0xD4, 14),
  RCC_SDMMC1      = _REG_BIT(0xD4, 16),

  /* AHB4 peripherals*/
  RCC_GPIOA       = _REG_BIT(0xE0, 0),
  RCC_GPIOB       = _REG_BIT(0xE0, 1),
  RCC_GPIOC       = _REG_BIT(0xE0, 2),
  RCC_GPIOD       = _REG_BIT(0xE0, 3),
  RCC_GPIOE       = _REG_BIT(0xE0, 4),
  RCC_GPIOF       = _REG_BIT(0xE0, 5),
  RCC_GPIOG       = _REG_BIT(0xE0, 6),
  RCC_GPIOH       = _REG_BIT(0xE0, 7),
  RCC_GPIOI       = _REG_BIT(0xE0, 8),
  RCC_GPIOJ       = _REG_BIT(0xE0, 9),
  RCC_GPIOK       = _REG_BIT(0xE0, 10),
  RCC_CRC         = _REG_BIT(0xE0, 19),
  RCC_BDMA        = _REG_BIT(0xE0, 21),
  RCC_ADC3        = _REG_BIT(0xE0, 24),
  RCC_HSEM        = _REG_BIT(0xE0, 25),
  RCC_BKPSRAM     = _REG_BIT(0xE0, 28),

  /* APB1L peripherals*/
  RCC_TIM2        = _REG_BIT(0xE8, 0),
  RCC_TIM3        = _REG_BIT(0xE8, 1),
  RCC_TIM4        = _REG_BIT(0xE8, 2),
  RCC_TIM5        = _REG_BIT(0xE8, 3),
  RCC_TIM6        = _REG_BIT(0xE8, 4),
  RCC_TIM7        = _REG_BIT(0xE8, 5),
  RCC_TIM12       = _REG_BIT(0xE8, 6),
  RCC_TIM13       = _REG_BIT(0xE8, 7),
  RCC_TIM14       = _REG_BIT(0xE8, 8),
  RCC_LPTIM1      = _REG_BIT(0xE8, 9),
  RCC_SPI2        = _REG_BIT(0xE8, 14),
  RCC_SPI3        = _REG_BIT(0xE8, 15),
  RCC_SPDIFRX     = _REG_BIT(0xE8, 16),
  RCC_USART2      = _REG_BIT(0xE8, 17),
  RCC_USART3      = _REG_BIT(0xE8, 18),
  RCC_UART4       = _REG_BIT(0xE8, 19),
  RCC_UART5       = _REG_BIT(0xE8, 20),
  RCC_I2C1        = _REG_BIT(0xE8, 21),
  RCC_I2C2        = _REG_BIT(0xE8, 22),
  RCC_I2C3        = _REG_BIT(0xE8, 23),
  RCC_CEC         = _REG_BIT(0xE8, 27),
  RCC_DAC         = _REG_BIT(0xE8, 29),
  RCC_UART7       = _REG_BIT(0xE8, 30),
  RCC_UART8       = _REG_BIT(0xE8, 31),

  /* APB1H peripherals*/
  RCC_CRS         = _REG_BIT(0xEC, 1),
  RCC_SWP         = _REG_BIT(0xEC, 2),
  RCC_OPAMP       = _REG_BIT(0xEC, 4),
  RCC_MDIO        = _REG_BIT(0xEC, 5),
  RCC_FDCAN       = _REG_BIT(0xEC, 8),

  /* APB2 peripherals */
  RCC_TIM1        = _REG_BIT(0xF0, 0),
  RCC_TIM8        = _REG_BIT(0xF0, 1),
  RCC_USART1      = _REG_BIT(0xF0, 4),
  RCC_USART6      = _REG_BIT(0xF0, 5),
  RCC_SPI1        = _REG_BIT(0xF0, 12),
  RCC_SPI4        = _REG_BIT(0xF0, 13),
  RCC_TIM15       = _REG_BIT(0xF0, 16),
  RCC_TIM16       = _REG_BIT(0xF0, 17),
  RCC_TIM17       = _REG_BIT(0xF0, 18),
  RCC_SPI5        = _REG_BIT(0xF0, 20),
  RCC_SAI1        = _REG_BIT(0xF0, 22),
  RCC_SAI2        = _REG_BIT(0xF0, 23),
  RCC_SAI3        = _REG_BIT(0xF0, 24),
  RCC_DFSDM       = _REG_BIT(0xF0, 28),
  RCC_HRTIM       = _REG_BIT(0xF0, 29),

  /* APB3 peripherals */
  RCC_LTDCEN      = _REG_BIT(0xE4, 3),
  RCC_WWDG1EN     = _REG_BIT(0xE4, 6),

  /* APB4 peripherals */
  RCC_SYSCFG      = _REG_BIT(0xF4, 1),
  RCC_LPUART1     = _REG_BIT(0xF4, 3),
  RCC_SPI6        = _REG_BIT(0xF4, 5),
  RCC_I2C4        = _REG_BIT(0xF4, 7),
  RCC_LPTIM2      = _REG_BIT(0xF4, 9),
  RCC_LPTIM3      = _REG_BIT(0xF4, 10),
  RCC_LPTIM4      = _REG_BIT(0xF4, 11),
  RCC_LPTIM5      = _REG_BIT(0xF4, 12),
  RCC_COMP12      = _REG_BIT(0xF4, 14),
  RCC_VREF        = _REG_BIT(0xF4, 15),
  RCC_RTCAPB      = _REG_BIT(0xF4, 16),
  RCC_SAI4        = _REG_BIT(0xF4, 21),
};

enum rcc_periph_rst {
   /* AHB1 peripherals */
  RST_DMA1        = _REG_BIT(0x80, 0),
  RST_DMA2        = _REG_BIT(0x80, 1),
  RST_ADC12       = _REG_BIT(0x80, 5),
  RST_ETH1MAC     = _REG_BIT(0x80, 15),
  RST_USB1OTGRST  = _REG_BIT(0x80, 25),
  RST_USB2OTGRST  = _REG_BIT(0x80, 27),

  /* AHB2 peripherals */
  RST_DCMI        = _REG_BIT(0xDC, 0),
  RST_CRYP        = _REG_BIT(0xDC, 4),
  RST_HASH        = _REG_BIT(0xDC, 5),
  RST_RNG         = _REG_BIT(0xDC, 6),
  RST_SDMMC2      = _REG_BIT(0xDC, 9),

  /* AHB3 peripherals */
  RST_MDMA        = _REG_BIT(0x7C, 0),
  RST_DMA2D       = _REG_BIT(0x7C, 4),
  RST_JPGDEC      = _REG_BIT(0x7C, 5),
  RST_FMC         = _REG_BIT(0x7C, 12),
  RST_QSPI        = _REG_BIT(0x7C, 14),
  RST_SDMMC1      = _REG_BIT(0x7C, 16),

  /* AHB4 peripherals*/
  RST_GPIOA       = _REG_BIT(0x88, 0),
  RST_GPIOB       = _REG_BIT(0x88, 1),
  RST_GPIOC       = _REG_BIT(0x88, 2),
  RST_GPIOD       = _REG_BIT(0x88, 3),
  RST_GPIOE       = _REG_BIT(0x88, 4),
  RST_GPIOF       = _REG_BIT(0x88, 5),
  RST_GPIOG       = _REG_BIT(0x88, 6),
  RST_GPIOH       = _REG_BIT(0x88, 7),
  RST_GPIOI       = _REG_BIT(0x88, 8),
  RST_GPIOJ       = _REG_BIT(0x88, 9),
  RST_GPIOK       = _REG_BIT(0x88, 10),
  RST_CRC         = _REG_BIT(0x88, 19),
  RST_BDMA        = _REG_BIT(0x88, 21),
  RST_ADC3        = _REG_BIT(0x88, 24),
  RST_HSEM        = _REG_BIT(0x88, 25),

  /* APB1L peripherals*/
  RST_TIM2        = _REG_BIT(0x90, 0),
  RST_TIM3        = _REG_BIT(0x90, 1),
  RST_TIM4        = _REG_BIT(0x90, 2),
  RST_TIM5        = _REG_BIT(0x90, 3),
  RST_TIM6        = _REG_BIT(0x90, 4),
  RST_TIM7        = _REG_BIT(0x90, 5),
  RST_TIM12       = _REG_BIT(0x90, 6),
  RST_TIM13       = _REG_BIT(0x90, 7),
  RST_TIM14       = _REG_BIT(0x90, 8),
  RST_LPTIM1      = _REG_BIT(0x90, 9),
  RST_SPI2        = _REG_BIT(0x90, 14),
  RST_SPI3        = _REG_BIT(0x90, 15),
  RST_SPDIFRX     = _REG_BIT(0x90, 16),
  RST_USART2      = _REG_BIT(0x90, 17),
  RST_USART3      = _REG_BIT(0x90, 18),
  RST_UART4       = _REG_BIT(0x90, 19),
  RST_UART5       = _REG_BIT(0x90, 20),
  RST_I2C1        = _REG_BIT(0x90, 21),
  RST_I2C2        = _REG_BIT(0x90, 22),
  RST_I2C3        = _REG_BIT(0x90, 23),
  RST_CEC         = _REG_BIT(0x90, 27),
  RST_DAC         = _REG_BIT(0x90, 29),
  RST_UART7       = _REG_BIT(0x90, 30),
  RST_UART8       = _REG_BIT(0x90, 31),

  /* APB1H peripherals*/
  RST_CRS         = _REG_BIT(0x94, 1),
  RST_SWP         = _REG_BIT(0x94, 2),
  RST_OPAMP       = _REG_BIT(0x94, 4),
  RST_MDIO        = _REG_BIT(0x94, 5),
  RST_FDCAN       = _REG_BIT(0x94, 8),

  /* APB2 peripherals */
  RST_TIM1        = _REG_BIT(0x98, 0),
  RST_TIM8        = _REG_BIT(0x98, 1),
  RST_USART1      = _REG_BIT(0x98, 4),
  RST_USART6      = _REG_BIT(0x98, 5),
  RST_SPI1        = _REG_BIT(0x98, 12),
  RST_SPI4        = _REG_BIT(0x98, 13),
  RST_TIM15       = _REG_BIT(0x98, 16),
  RST_TIM16       = _REG_BIT(0x98, 17),
  RST_TIM17       = _REG_BIT(0x98, 18),
  RST_SPI5        = _REG_BIT(0x98, 20),
  RST_SAI1        = _REG_BIT(0x98, 22),
  RST_SAI2        = _REG_BIT(0x98, 23),
  RST_SAI3        = _REG_BIT(0x98, 24),
  RST_DFSDM       = _REG_BIT(0x98, 28),
  RST_HRTIM       = _REG_BIT(0x98, 29),

  /* APB3 peripherals */
  RST_LTDCRST     = _REG_BIT(0x8C, 3),

  /* APB4 peripherals */
  RST_SYSCFG      = _REG_BIT(0x9C, 1),
  RST_LPUART1     = _REG_BIT(0x9C, 3),
  RST_SPI6        = _REG_BIT(0x9C, 5),
  RST_I2C4        = _REG_BIT(0x9C, 7),
  RST_LPTIM2      = _REG_BIT(0x9C, 9),
  RST_LPTIM3      = _REG_BIT(0x9C, 10),
  RST_LPTIM4      = _REG_BIT(0x9C, 11),
  RST_LPTIM5      = _REG_BIT(0x9C, 12),
  RST_COMP12      = _REG_BIT(0x9C, 14),
  RST_VREF        = _REG_BIT(0x9C, 15),
  RST_SAI4        = _REG_BIT(0x9C, 21),
};

#undef _REG_BIT

#include <libopencm3/stm32/common/rcc_common_all.h>

/**@}*/

#endif
