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

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/h7/pwr.h>

/**@{*/

/** @defgroup rcc_registers RCC Registers
@{*/
#define RCC_CR                    MMIO32(RCC_BASE + 0x000)
#define RCC_ICSCR                 MMIO32(RCC_BASE + 0x004)  /* Y-devices only */
#define RCC_HSICFGR               MMIO32(RCC_BASE + 0x004)  /* V-devices only */
#define RCC_CRRCR                 MMIO32(RCC_BASE + 0x008)
#define RCC_CSICFGR               MMIO32(RCC_BASE + 0x00C)  /* V-devices only */
#define RCC_CFGR                  MMIO32(RCC_BASE + 0x010)
#define RCC_D1CFGR                MMIO32(RCC_BASE + 0x018)
#define RCC_D2CFGR                MMIO32(RCC_BASE + 0x01C)
#define RCC_D3CFGR                MMIO32(RCC_BASE + 0x020)
#define RCC_PLLCKSELR             MMIO32(RCC_BASE + 0x028)
#define RCC_PLLCFGR               MMIO32(RCC_BASE + 0x02C)
/* PLLs are 1-based, so reference macros to 1..3, using index 0 will give undefined behavior. */
#define RCC_PLLDIVR(n)            MMIO32(RCC_BASE + 0x030 + (0x08 * ((n) - 1)))
#define RCC_PLLFRACR(n)           MMIO32(RCC_BASE + 0x030 + (0x08 * ((n) - 1)))
#define RCC_PLL1DIVR              RCC_PLLDIVR(1)
#define RCC_PLL1FRACR             RCC_PLLFRACR(1)
#define RCC_PLL2DIVR              RCC_PLLDIVR(2)
#define RCC_PLL2FRACR             RCC_PLLFRACR(2)
#define RCC_PLL3DIVR              RCC_PLLDIVR(3)
#define RCC_PLL3FRACR             RCC_PLLFRACR(3)
#define RCC_D1CCIPR               MMIO32(RCC_BASE + 0x04C)
#define RCC_D2CCIP1R              MMIO32(RCC_BASE + 0x050)
#define RCC_D2CCIP2R              MMIO32(RCC_BASE + 0x054)
#define RCC_D3CCIPR               MMIO32(RCC_BASE + 0x058)
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

/** @defgroup rcc_cr_values RCC_CR Values
 * @ingroup rcc_registers
@{*/
#define RCC_CR_PLL3RDY            BIT29
#define RCC_CR_PLL3ON             BIT28
#define RCC_CR_PLL2RDY            BIT27
#define RCC_CR_PLL2ON             BIT26
#define RCC_CR_PLL1RDY            BIT25
#define RCC_CR_PLL1ON             BIT24
#define RCC_CR_HSECSSON           BIT19
#define RCC_CR_HSEBYP             BIT18
#define RCC_CR_HSERDY             BIT17
#define RCC_CR_HSEON              BIT16
#define RCC_CR_D2CKRDY            BIT15
#define RCC_CR_D1CKRDY            BIT14
#define RCC_CR_HSI48RDY           BIT13
#define RCC_CR_HSI48ON            BIT12
#define RCC_CR_CSIKERON           BIT9
#define RCC_CR_CSIRDY             BIT8
#define RCC_CR_CSION              BIT7
#define RCC_CR_HSIDIVF            BIT5
#define RCC_CR_HSIDIV_MASK        (0x03)
#define RCC_CR_HSIDIV_SHIFT       3
#define RCC_CR_HSIDIV(n)          (((n) & RCC_CR_HSIDIV_MASK) << RCC_CR_HSIDIV_MASK)
#define RCC_CR_HSIRDY             BIT2
#define RCC_CR_HSIKERON           BIT1
#define RCC_CR_HSION              BIT0
/**@}*/


/** @defgroup rcc_cfgr_values RCC_CFGR Values
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

/** @defgroup rcc_d1cfgr_values RCC_D1CFGR Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_D1CFGR_D1CPRE_BYP       0x0
#define RCC_D1CFGR_D1CPRE_DIV2      0x8
#define RCC_D1CFGR_D1CPRE_DIV4      0x9
#define RCC_D1CFGR_D1CPRE_DIV8      0xA
#define RCC_D1CFGR_D1CPRE_DIV16     0xB
#define RCC_D1CFGR_D1CPRE_DIV64     0xC
#define RCC_D1CFGR_D1CPRE_DIV128    0xD
#define RCC_D1CFGR_D1CPRE_DIV256    0xE
#define RCC_D1CFGR_D1CPRE_DIV512    0xF
#define RCC_D1CFGR_D1PPRE_BYP       0x0
#define RCC_D1CFGR_D1PPRE_DIV2      0x4
#define RCC_D1CFGR_D1PPRE_DIV4      0x5
#define RCC_D1CFGR_D1PPRE_DIV8      0x6
#define RCC_D1CFGR_D1PPRE_DIV16     0x7
#define RCC_D1CFGR_D1HPRE_BYP       0x0
#define RCC_D1CFGR_D1HPRE_DIV2      0x8
#define RCC_D1CFGR_D1HPRE_DIV4      0x9
#define RCC_D1CFGR_D1HPRE_DIV8      0xA
#define RCC_D1CFGR_D1HPRE_DIV16     0xB
#define RCC_D1CFGR_D1HPRE_DIV64     0xC
#define RCC_D1CFGR_D1HPRE_DIV128    0xD
#define RCC_D1CFGR_D1HPRE_DIV256    0xE
#define RCC_D1CFGR_D1HPRE_DIV512    0xF

#define RCC_D1CFGR_D1CPRE_SHIFT     8
#define RCC_D1CFGR_D1PPRE_SHIFT     4
#define RCC_D1CFGR_D1CPRE(cpre)     (cpre << RCC_D1CFGR_D1CPRE_SHIFT)
#define RCC_D1CFGR_D1PPRE(ppre)     (ppre << RCC_D1CFGR_D1PPRE_SHIFT)
#define RCC_D1CFGR_D1HPRE(hpre)     (hpre)
/**@}*/

/** @defgroup rcc_d2cfgr_values RCC_D2CFGR Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_D2CFGR_D2PPRE_BYP       0x0
#define RCC_D2CFGR_D2PPRE_DIV2      0x4
#define RCC_D2CFGR_D2PPRE_DIV4      0x5
#define RCC_D2CFGR_D2PPRE_DIV8      0x6
#define RCC_D2CFGR_D2PPRE_DIV16     0x7

#define RCC_D2CFGR_D2PPRE2_SHIFT    8
#define RCC_D2CFGR_D2PPRE1_SHIFT    4
#define RCC_D2CFGR_D2PPRE2(ppre)    (ppre << RCC_D2CFGR_D2PPRE2_SHIFT)
#define RCC_D2CFGR_D2PPRE1(ppre)    (ppre << RCC_D2CFGR_D2PPRE1_SHIFT)
/**@}*/

/** @defgroup rcc_d3cfgr_values RCC_D3CFGR Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_D3CFGR_D3PPRE_BYP       0x0
#define RCC_D3CFGR_D3PPRE_DIV2      0x4
#define RCC_D3CFGR_D3PPRE_DIV4      0x5
#define RCC_D3CFGR_D3PPRE_DIV8      0x6
#define RCC_D3CFGR_D3PPRE_DIV16     0x7
#define RCC_D3CFGR_D3PPRE_SHIFT     4
#define RCC_D3CFGR_D3PPRE(ppre)     (ppre << RCC_D3CFGR_D3PPRE_SHIFT)
/**@}*/

/** @defgroup rcc_pllckselr_values RCC_PLLCKSELR Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_PLLCKSELR_PLLSRC_HSI    0x0
#define RCC_PLLCKSELR_PLLSRC_CSI    0x1
#define RCC_PLLCKSELR_PLLSRC_HSE    0x2
#define RCC_PLLCKSELR_PLLSRC_NONE   0x3
#define RCC_PLLCKSELR_DIVM_DIS      0
#define RCC_PLLCKSELR_DIVM_BYP      1
#define RCC_PLLCKSELR_DIVM_MASK     0x3f

#define RCC_PLLCKSELR_DIVM3_SHIFT   20
#define RCC_PLLCKSELR_DIVM2_SHIFT   12
#define RCC_PLLCKSELR_DIVM1_SHIFT   4

#define RCC_PLLCKSELR_DIVM3(n)      ((n) << RCC_PLLCKSELR_DIVM3_SHIFT)
#define RCC_PLLCKSELR_DIVM2(n)      ((n) << RCC_PLLCKSELR_DIVM2_SHIFT)
#define RCC_PLLCKSELR_DIVM1(n)      ((n) << RCC_PLLCKSELR_DIVM1_SHIFT)
/**@}*/

/** @defgroup rcc_pllcfgr_values RCC_PLLCFGR Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_PLLCFGR_PLLRGE_1_2MHZ   0
#define RCC_PLLCFGR_PLLRGE_2_4MHZ   1
#define RCC_PLLCFGR_PLLRGE_4_8MHZ   2
#define RCC_PLLCFGR_PLLRGE_8_16MHZ  3

#define RCC_PLLCFGR_DIVR3EN         BIT24
#define RCC_PLLCFGR_DIVQ3EN         BIT23
#define RCC_PLLCFGR_DIVP3EN         BIT22
#define RCC_PLLCFGR_DIVR2EN         BIT21
#define RCC_PLLCFGR_DIVQ2EN         BIT20
#define RCC_PLLCFGR_DIVP2EN         BIT19
#define RCC_PLLCFGR_DIVR1EN         BIT18
#define RCC_PLLCFGR_DIVQ1EN         BIT17
#define RCC_PLLCFGR_DIVP1EN         BIT16
#define RCC_PLLCFGR_PLL3RGE_SHIFT   10
#define RCC_PLLCFGR_PLL3VCO_WIDE    0       /* 192 - 836MHz base output. */
#define RCC_PLLCFGR_PLL3VCO_MED     BIT9    /* 150 - 420MHz base output. */
#define RCC_PLLCFGR_PLL3FRACEN      BIT8
#define RCC_PLLCFGR_PLL2RGE_SHIFT   6
#define RCC_PLLCFGR_PLL2VCO_WIDE    0       /* 192 - 836MHz base output. */
#define RCC_PLLCFGR_PLL2VCO_MED     BIT5    /* 150 - 420MHz base output. */
#define RCC_PLLCFGR_PLL2FRACEN      BIT4
#define RCC_PLLCFGR_PLL1RGE_SHIFT   2
#define RCC_PLLCFGR_PLL1VCO_WIDE    0       /* 192 - 836MHz base output. */
#define RCC_PLLCFGR_PLL1VCO_MED     BIT1    /* 150 - 420MHz base output. */
#define RCC_PLLCFGR_PLL1FRACEN      BIT0
/**@}*/

/** @defgroup rcc_plldivr_values RCC_PLLnDIVR Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_PLLNDIVR_DIVR_SHIFT     24
#define RCC_PLLNDIVR_DIVQ_SHIFT     16
#define RCC_PLLNDIVR_DIVP_SHIFT     9
#define RCC_PLLNDIVR_DIVN_SHIFT     0

/* Need to preserve reserved bits, so give easy mask shortcut. */
#define RCC_PLLNDIVR_DIVR(n)        (((n) - 1) << RCC_PLLNDIVR_DIVR_SHIFT)
#define RCC_PLLNDIVR_DIVQ(n)        (((n) - 1) << RCC_PLLNDIVR_DIVQ_SHIFT)
#define RCC_PLLNDIVR_DIVP(n)        (((n) - 1) << RCC_PLLNDIVR_DIVP_SHIFT)
#define RCC_PLLNDIVR_DIVN(n)        (((n) - 1) << RCC_PLLNDIVR_DIVN_SHIFT)
/**@}*/

/** @defgroup rcc_bdcr_values RCC_BDCR Values
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

/** @defgroup rcc_csr_values RCC_CSR Values.
 * @ingroup rcc_registers
@{*/
#define RCC_CSR_LSIRDY            (1 << 1)
#define RCC_CSR_LSION             (1 << 0)
/**@}*/

/** @defgroup rcc_d1ccipr_values RCC_D1CCIP1R Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_D1CCIPR_CKPERSEL_HSI       0
#define RCC_D1CCIPR_CKPERSEL_CSI       1
#define RCC_D1CCIPR_CKPERSEL_HSE       2
#define RCC_D1CCIPR_CKPERSEL_DISABLE   3
/**@}*/
#define RCC_D1CCIPR_CKPERSEL_SHIFT     28
#define RCC_D1CCIPR_CKPERSEL_MASK      3

#define RCC_D2CCIP1R_SWPSEL_SHIFT       31
#define RCC_D2CCIP1R_FDCANSEL_SHIFT     28
#define RCC_D2CCIP1R_FDCANSEL_MASK      0x3
#define RCC_D2CCIP1R_DFSDM1SEL_SHIFT    24
#define RCC_D2CCIP1R_SPDIFSEL_SHIFT     20
#define RCC_D2CCIP1R_SPI45SEL_SHIFT     16
#define RCC_D2CCIP1R_SPI45SEL_MASK      0x7
#define RCC_D2CCIP1R_SPI123SEL_SHIFT    12
#define RCC_D2CCIP1R_SPI123SEL_MASK     0x7
#define RCC_D2CCIP1R_SAI23SEL_SHIFT     6
#define RCC_D2CCIP1R_SAISEL_MASK        0x7

/** @defgroup rcc_d2ccip1r_values RCC_D2CCIP1R Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_D2CCIP1R_SWPSEL_PCLK        0x0
#define RCC_D2CCIP1R_SWPSEL_HSI         0x1
#define RCC_D2CCIP1R_FDCANSEL_HSE       0x0
#define RCC_D2CCIP1R_FDCANSEL_PLL1Q     0x1
#define RCC_D2CCIP1R_FDCANSEL_PLL2Q     0x2
#define RCC_D2CCIP1R_DFSDM1SEL_PCLK2    0x0
#define RCC_D2CCIP1R_DFSDM1SEL_SYSCLK   0x1
#define RCC_D2CCIP1R_SPDIFSEL_PLL1Q     0x0
#define RCC_D2CCIP1R_SPDIFSEL_PLL2R     0x1
#define RCC_D2CCIP1R_SPDIFSEL_PLL3R     0x2
#define RCC_D2CCIP1R_SPDIFSEL_HSI       0x3
#define RCC_D2CCIP1R_SPI45SEL_APB4      0x0
#define RCC_D2CCIP1R_SPI45SEL_PLL2Q     0x1
#define RCC_D2CCIP1R_SPI45SEL_PLL3Q     0x2
#define RCC_D2CCIP1R_SPI45SEL_HSI       0x3
#define RCC_D2CCIP1R_SPI45SEL_CSI       0x4
#define RCC_D2CCIP1R_SPI45SEL_HSE       0x5
#define RCC_D2CCIP1R_SPI123SEL_PLL1Q    0x0
#define RCC_D2CCIP1R_SPI123SEL_PLL2P    0x1
#define RCC_D2CCIP1R_SPI123SEL_PLL3P    0x2
#define RCC_D2CCIP1R_SPI123SEL_I2SCKIN  0x3
#define RCC_D2CCIP1R_SPI123SEL_PERCK    0x4
#define RCC_D2CCIP1R_SAISEL_PLL1Q       0x0
#define RCC_D2CCIP1R_SAISEL_PLL2P       0x1
#define RCC_D2CCIP1R_SAISEL_PLL3P       0x2
#define RCC_D2CCIP1R_SAISEL_I2SCKIN     0x3
#define RCC_D2CCIP1R_SAISEL_PERCK       0x4
/**@}*/

#define RCC_D2CCIP2R_LPTIM1SEL_SHIFT        28
#define RCC_D2CCIP2R_CECSEL_SHIFT           22
#define RCC_D2CCIP2R_USBSEL_SHIFT           20
#define RCC_D2CCIP2R_I2C123SEL_SHIFT        12
#define RCC_D2CCIP2R_RNGSEL_MASK            0x3
#define RCC_D2CCIP2R_RNGSEL_SHIFT           8
#define RCC_D2CCIP2R_USART16SEL_SHIFT       3
#define RCC_D2CCIP2R_USART234578SEL_SHIFT   0
#define RCC_D2CCIP2R_USARTSEL_MASK          7

/** @defgroup rcc_d2ccip2r_values RCC_D2CCIP2R Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_D2CCIP2R_RNGSEL_HSI48           0
#define RCC_D2CCIP2R_RNGSEL_PLL1Q           1
#define RCC_D2CCIP2R_RNGSEL_LSE             2
#define RCC_D2CCIP2R_RNGSEL_LSI             3
#define RCC_D2CCIP2R_USART16SEL_PCLK2       0
#define RCC_D2CCIP2R_USART234578SEL_PCLK1   0
#define RCC_D2CCIP2R_USARTSEL_PCLK          0
#define RCC_D2CCIP2R_USARTSEL_PLL2Q         1
#define RCC_D2CCIP2R_USARTSEL_PLL3Q         2
#define RCC_D2CCIP2R_USARTSEL_HSI           3
#define RCC_D2CCIP2R_USARTSEL_CSI           4
#define RCC_D2CCIP2R_USARTSEL_LSE           5
/**@}*/


#define RCC_HSI_BASE_FREQUENCY              64000000UL

/** Enumerations for core system/bus clocks for user/driver/system access to base bus clocks
  * not directly associated with a peripheral. */
enum rcc_clock_source {
  RCC_CPUCLK,
  RCC_SYSCLK,
  RCC_PERCLK,
  RCC_SYSTICKCLK,
  RCC_HCLK3,
  RCC_AHBCLK,           /* AHB1,2,4 all share base HCLK. */
  RCC_APB1CLK,          /* Note: APB1 and PCLK1 in manual */
  RCC_APB2CLK,          /* Note: APB2 and PCLK2 in manual */
  RCC_APB3CLK,          /* Note: APB3 and PCLK3 in manual */
  RCC_APB4CLK,          /* Note: APB4 and PCLK4 in manual */
};

enum rcc_osc {
  RCC_PLL,
  RCC_HSE,
  RCC_HSI,
  RCC_LSE,
  RCC_LSI
};

/** PLL Configuration structure. */
struct rcc_pll_config {
  enum rcc_osc sysclock_source;     /**< SYSCLK source input selection. */
  uint8_t pll_source;               /**< RCC_PLLCKSELR_PLLSRC_xxx value. */
  uint32_t hse_frequency;           /**< User specified HSE frequency, 0 if none. */
  struct pll_config {
    uint8_t divm;                   /**< Pre-divider value for each PLL. 0-64 integers. */
    uint16_t divn;                  /**< Multiplier, 0-512 integer. */
    uint8_t divp;                   /**< Post divider for PLLP clock. */
    uint8_t divq;                   /**< Post divider for PLLQ clock. */
    uint8_t divr;                   /**< Post divider for PLLR clock. */
  } pll1, pll2, pll3;               /**< PLL1-PLL3 configurations. */
  uint8_t core_pre;                 /**< Core prescaler  note: domain 1. */
  uint8_t hpre;                     /**< HCLK3 prescaler note: domain 1. */
  uint8_t ppre1;                    /**< APB1 Peripheral prescaler note: domain 2. */
  uint8_t ppre2;                    /**< APB2 Peripheral prescaler note: domain 2. */
  uint8_t ppre3;                    /**< APB3 Peripheral prescaler note: domain 1. */
  uint8_t ppre4;                    /**< APB4 Peripheral prescaler note: domain 3. */
  uint8_t flash_waitstates;         /**< Latency Value to set for flahs. */
  enum pwr_vos_scale voltage_scale; /**< LDO Voltage scale used for this frequency. */
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
/**@}*/


/** @defgroup rcc_file RCC peripheral API
 *
 * @ingroup peripheral_apis
 * @{
 */
#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS

/**
 * Setup the base PLLs and clock domains for the STM32H7. This function will
 * utilize the users input parameters to configure all 3 PLLs, as well as the
 * core clock domains (namely SYSCLK, CPU, HCLK, AHB, PCLK1-4) with the
 * specified dividers. Given the dividers, the RCC module will track the
 * the configured frequency for each of these clock domains.
 *
 *   Note: If clock sources, configs, divider, etc. are modified outside of
 *         this module, the frequency tracking may be undefined.
 *   Note: Clock tree is fairly complex, see RM0433 Section 7
 *         for details.
 * @param[in] config  Input config structure defining desired setup.
 */
void rcc_clock_setup_pll(const struct rcc_pll_config *config);

/**
 * Get the clock rate (in Hz) of the specified clock source. There are
 * numerous clock sources and configurations on the H7, so rates for each
 * configured peripheral clock are aimed to be discoverd/calculated by this
 * module such that the user does not need to know how the MCU is configured
 * in order to utilize a peripheral clock.
 * @param[in] source  Clock source desired to be fetched.
 * @return Clock rate in Hz for the specified clock. 0 if undefined or error.
 */
uint32_t rcc_get_bus_clk_freq(enum rcc_clock_source source);

/**
 * Get the peripheral clock speed for the USART at base specified.
 * @param usart  Base address of USART to get clock frequency for (e.g. USART1_BASE).
 */
uint32_t rcc_get_usart_clk_freq(uint32_t usart);

/**
 * Get the peripheral clock speed for the Timer at base specified.
 * @param timer  Base address of TIMER to get clock frequency for (e.g. TIM1_BASE).
 */
uint32_t rcc_get_timer_clk_freq(uint32_t timer);

/**
 * Get the peripheral clock speed for the I2C device at base specified.
 * @param i2c  Base address of I2C to get clock frequency for (e.g. I2C1_BASE).
 */
uint32_t rcc_get_i2c_clk_freq(uint32_t i2c);

/**
 * Get the peripheral clock speed for the SPI device at base specified.
 * @param spi  Base address of SPI device to get clock frequency for (e.g. SPI1_BASE).
 */
uint32_t rcc_get_spi_clk_freq(uint32_t spi);

/**
 * Get the peripheral clock speed for the FDCAN device at base specified.
 * @param fdcan  Base address of FDCAN to get clock frequency for (e.g. FDCAN1_BASE).
 */
uint32_t rcc_get_fdcan_clk_freq(uint32_t fdcan);

/**
 * Set the clksel value for the specified peripheral. This code will determine
 * the appropriate register, shift and mask values to apply to the selection to
 * and set the values appropriately.
 *
 * Peripheral specific clksels functions are also available,
 * eg rcc_set_<periph>_clksel. These provide the same functionality, you only
 * need one of them. for instance @ref rcc_set_fdcan_clksel or
 * @ref rcc_set_spi123_clksel
 * @param[in] periph Base address of the peripheral to set the clock sel for
 * @param[in] clksel Raw, unshifted selection value for the clock, depending
 * on peripheral, see @ref rcc_d1ccipr_values or @ref rcc_d2ccip1r_values or
 * @ref rcc_d2ccip2r_values
 */
void rcc_set_peripheral_clk_sel(uint32_t periph, uint32_t clksel);

/**
 * Set the clock select for the FDCAN devices.
 * @param[in] clksel  Clock source to configure for, @ref rcc_d2ccip1r_values
 * appropriate for the FDCAN peripherals, eg RCC_D2CCIP1R_FDCANSEL_XXX
 * @sa rcc_set_peripheral_clk_sel for equivalent generic functionality
 */
void rcc_set_fdcan_clksel(uint8_t clksel);

/**
 * Set the clock select for the SPI 1/2/3 devices.
 * @param[in] clksel  Clock source to configure for, @ref rcc_d2ccip1r_values
 * appropriate for the SPI1/2/3 peripherals, eg RCC_D2CCIP1R_SPI123_XXX
 * @sa rcc_set_peripheral_clk_sel for equivalent generic functionality
 */
void rcc_set_spi123_clksel(uint8_t clksel);

/**
 * Set the clock select for the SPI 4/5 devices.
 * @param[in] clksel  Clock source to configure for. @ref rcc_d2ccip1r_values
 * @sa rcc_set_peripheral_clk_sel for equivalent generic functionality
 */
void rcc_set_spi45_clksel(uint8_t clksel);

/**
 * Set the clock select for the RNG device.
 * @param[in] clksel  Clock source to configure for. @ref rcc_d2ccip2r_values
 * @sa rcc_set_peripheral_clk_sel for equivalent generic functionality
 */
void rcc_set_rng_clksel(uint8_t clksel);

END_DECLS
/**@}*/
/**@}*/

#endif
