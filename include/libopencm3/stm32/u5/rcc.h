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
 * @author @htmlonly &copy; @endhtmlonly 2025 Rachel Mant <git@dragonmux.network>
 *
 * @date 05 October 2024
 *
 * LGPL License Terms @ref lgpl_license
 *  */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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

#include <stdint.h>
#include <libopencm3/stm32/pwr.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

struct rcc_clock_scale {
	uint8_t hpre;            /* AHB prescaler */
	uint8_t ppre1;           /* APB1 low-speed prescaler */
	uint8_t ppre2;           /* APB2 high-speed prescaler */
	uint8_t ppre3;           /* APB3 high-speed prescaler */
	uint32_t ahb_frequency;  /* AHB clock frequency */
	uint32_t apb1_frequency; /* APB1 clock frequency */
	uint32_t apb2_frequency; /* APB2 clock frequency */
							 // enum pwr_vos_scale vos_scale;  /* Dynamic voltage scale */ TODO
};

extern const struct rcc_clock_scale rcc_hsi16mhz_configs;

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define RCC_CR        MMIO32(RCC_BASE + 0x000U)
#define RCC_ICSCR1    MMIO32(RCC_BASE + 0x008U)
#define RCC_ICSCR2    MMIO32(RCC_BASE + 0x00cU)
#define RCC_ICSCR3    MMIO32(RCC_BASE + 0x010U)
#define RCC_CRRCR3    MMIO32(RCC_BASE + 0x014U)
#define RCC_CFGR      MMIO32(RCC_BASE + 0x01cU) /* Actually CFGR1, but named this for compat */
#define RCC_CFGR2     MMIO32(RCC_BASE + 0x020U)
#define RCC_CFGR3     MMIO32(RCC_BASE + 0x024U)
#define RCC_PLL1CFGR  MMIO32(RCC_BASE + 0x028U)
#define RCC_PLL2CFGR  MMIO32(RCC_BASE + 0x02cU)
#define RCC_PLL3CFGR  MMIO32(RCC_BASE + 0x030U)
#define RCC_PLL1DIVR  MMIO32(RCC_BASE + 0x034U)
#define RCC_PLL1FRACR MMIO32(RCC_BASE + 0x038U)
#define RCC_PLL2DIVR  MMIO32(RCC_BASE + 0x03cU)
#define RCC_PLL2FRACR MMIO32(RCC_BASE + 0x040U)
#define RCC_PLL3DIVR  MMIO32(RCC_BASE + 0x044U)
#define RCC_PLL3FRACR MMIO32(RCC_BASE + 0x048U)
#define RCC_CIER      MMIO32(RCC_BASE + 0x050U)
#define RCC_CIFR      MMIO32(RCC_BASE + 0x054U)
#define RCC_CICR      MMIO32(RCC_BASE + 0x058U)
#define RCC_CCIPR1    MMIO32(RCC_BASE + 0x0e0U)
#define RCC_CCIPR2    MMIO32(RCC_BASE + 0x0e4U)
#define RCC_CCIPR3    MMIO32(RCC_BASE + 0x0e8U)
#define RCC_BDCR      MMIO32(RCC_BASE + 0x0f0U)
#define RCC_CSR       MMIO32(RCC_BASE + 0x0f4U)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_PLL3RDY   (1U << 29U)
#define RCC_CR_PLL3ON    (1U << 28U)
#define RCC_CR_PLL2RDY   (1U << 27U)
#define RCC_CR_PLL2ON    (1U << 26U)
#define RCC_CR_PLL1RDY   (1U << 25U)
#define RCC_CR_PLL1ON    (1U << 24U)
#define RCC_CR_HSEEXT    (1U << 20U)
#define RCC_CR_CSSON     (1U << 19U)
#define RCC_CR_HSEBYP    (1U << 18U)
#define RCC_CR_HSERDY    (1U << 17U)
#define RCC_CR_HSEON     (1U << 16U)
#define RCC_CR_SHSIRDY   (1U << 15U)
#define RCC_CR_SHSION    (1U << 14U)
#define RCC_CR_HSI48RDY  (1U << 13U)
#define RCC_CR_HSI48ON   (1U << 12U)
#define RCC_CR_HSIRDY    (1U << 10U)
#define RCC_CR_HSIKERON  (1U << 9U)
#define RCC_CR_HSION     (1U << 8U)
#define RCC_CR_MSIPLFAST (1U << 7U)
#define RCC_CR_MSIPLLSEL (1U << 6U)
#define RCC_CR_MSIKRDY   (1U << 5U)
#define RCC_CR_MSIKON    (1U << 4U)
#define RCC_CR_MSIPLLEN  (1U << 3U)
#define RCC_CR_MSISRDY   (1U << 2U)
#define RCC_CR_MSIKERON  (1U << 1U)
#define RCC_CR_MSISON    (1U << 0U)

/* --- RCC_ICSCR1 values -------------------------------------------------- */

/** MSISRANGE[31:28]: MSIS clock ranges */
#define RCC_ICSCR1_MSISRANGE_SHIFT 28U
#define RCC_ICSCR1_MSISRANGE_MASK  0x0fU
#define RCC_ICSCR1_MSISRANGE       (RCC_ICSCR1_MSISRANGE_MASK << RCC_ICSCR1_MSISRANGE_SHIFT)
/** MSIKRANGE[27:24]: MSIK clock ranges */
#define RCC_ICSCR1_MSIKRANGE_SHIFT 24U
#define RCC_ICSCR1_MSIKRANGE_MASK  0x0fU
#define RCC_ICSCR1_MSIKRANGE       (RCC_ICSCR1_MSIKRANGE_MASK << RCC_ICSCR1_MSIKRANGE_SHIFT)

#define RCC_MSI_RANGE_48MHZ   0x00U
#define RCC_MSI_RANGE_24MHZ   0x01U
#define RCC_MSI_RANGE_16MHZ   0x02U
#define RCC_MSI_RANGE_12MHZ   0x03U
#define RCC_MSI_RANGE_4MHZ    0x04U
#define RCC_MSI_RANGE_2MHZ    0x05U
#define RCC_MSI_RANGE_1M33HZ  0x06U
#define RCC_MSI_RANGE_1MHZ    0x07U
#define RCC_MSI_RANGE_3M072HZ 0x08U
#define RCC_MSI_RANGE_1M536HZ 0x09U
#define RCC_MSI_RANGE_1M024HZ 0x0aU
#define RCC_MSI_RANGE_768KHZ  0x0bU
#define RCC_MSI_RANGE_400KHZ  0x0cU
#define RCC_MSI_RANGE_200KHZ  0x0dU
#define RCC_MSI_RANGE_133KHZ  0x0eU
#define RCC_MSI_RANGE_100KHZ  0x0fU

/* Special sentinel for the MSIS being off */
#define RCC_MSIS_RANGE_OFF 0xffU
/* Special value for the MSIS being PLLed for better accuracy */
#define RCC_MSIS_RANGE_PLL  0x10U
#define RCC_MSIS_RANGE_MASK 0x0fU

/** MSIRGSEL: MSI clock range selection */
#define RCC_ICSCR1_MSIRGSEL (1U << 23U)

/* --- RCC_CFGR values ---------------------------------------------------- */

#define RCC_CFGR_MCOPRE_SHIFT 28U
#define RCC_CFGR_MCOPRE_MASK  0x7U
#define RCC_CFGR_MCOPRE       (RCC_CFGR_MCOPRE_MASK << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV1  (0U << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV2  (1U << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV4  (2U << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV8  (3U << RCC_CFGR_MCOPRE_SHIFT)
#define RCC_CFGR_MCOPRE_DIV16 (4U << RCC_CFGR_MCOPRE_SHIFT)

#define RCC_CFGR_MCO_SHIFT  24U
#define RCC_CFGR_MCO_MASK   0xfU
#define RCC_CFGR_MCO        (RCC_CFGR_MCO_MASK << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO_SYSCLK (1U << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO_MSIS   (2U << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO_HSI16  (3U << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO_HSE    (4U << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO_PLL1R  (5U << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO_LSI    (6U << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO_LSE    (7U << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO_HSI48  (8U << RCC_CFGR_MCO_SHIFT)
#define RCC_CFGR_MCO_MSIK   (9U << RCC_CFGR_MCO_SHIFT)

#define RCC_CFGR_SWS_SHIFT 2U
#define RCC_CFGR_SWS_MASK  0x3U
#define RCC_CFGR_SWS       (RCC_CFGR_SWS_MASK << RCC_CFGR_SWS_SHIFT)
#define RCC_CFGR_SWS_MSIS  0x0U
#define RCC_CFGR_SWS_HSI16 0x1U
#define RCC_CFGR_SWS_HSE   0x2U
#define RCC_CFGR_SWS_PLL   0x3U

#define RCC_CFGR_SW_SHIFT 0U
#define RCC_CFGR_SW_MASK  0x3U
#define RCC_CFGR_SW       (RCC_CFGR_SW_MASK << RCC_CFGR_SW_SHIFT)
#define RCC_CFGR_SW_MSIS  0x0U
#define RCC_CFGR_SW_HSI16 0x1U
#define RCC_CFGR_SW_HSE   0x2U
#define RCC_CFGR_SW_PLL   0x3U

/* --- RCC_CFGR2 values ---------------------------------------------------- */

/** @defgroup rcc_dpre RCC_CFGR2 DSI PHY prescale factors
 * @{
 */
#define RCC_CFGR2_DPRE_NODIV   0x0U
#define RCC_CFGR2_DPRE_DIV2    0x4U
#define RCC_CFGR2_DPRE_DIV4    0x5U
#define RCC_CFGR2_DPRE_DIV8    0x6U
#define RCC_CFGR2_DPRE_DIV16   0x7U
#define RCC_CFGR2_DPRE_DEFAULT RCC_CFGR2_DPRE_DIV8
/**@}*/

#define RCC_CFGR2_PPRE2_SHIFT 8U
#define RCC_CFGR2_PPRE2_MASK  0x7U
#define RCC_CFGR2_PPRE2       (RCC_CFGR2_PPRE2_MASK << RCC_CFGR2_PPRE2_SHIFT)

#define RCC_CFGR2_PPRE1_SHIFT 4U
#define RCC_CFGR2_PPRE1_MASK  0x7U
#define RCC_CFGR2_PPRE1       (RCC_CFGR2_PPRE1_MASK << RCC_CFGR2_PPRE1_SHIFT)

#define RCC_CFGR2_HPRE_SHIFT 0U
#define RCC_CFGR2_HPRE_MASK  0xfU
#define RCC_CFGR2_HPRE       (RCC_CFGR2_HPRE_MASK << RCC_CFGR2_HPRE_SHIFT)

/** @defgroup rcc_cfgr2_ahbpre RCC_CFGR2 AHB prescale factors
@{*/
#define RCC_CFGR2_HPRE_NODIV  0x0U
#define RCC_CFGR2_HPRE_DIV2   0x8U
#define RCC_CFGR2_HPRE_DIV4   0x9U
#define RCC_CFGR2_HPRE_DIV8   0xaU
#define RCC_CFGR2_HPRE_DIV16  0xbU
#define RCC_CFGR2_HPRE_DIV64  0xcU
#define RCC_CFGR2_HPRE_DIV128 0xdU
#define RCC_CFGR2_HPRE_DIV256 0xeU
#define RCC_CFGR2_HPRE_DIV512 0xfU
/**@}*/

/* --- RCC_CFGR3 values ---------------------------------------------------- */

#define RCC_CFGR3_PPRE3_SHIFT 4U
#define RCC_CFGR3_PPRE3_MASK  0x7U
#define RCC_CFGR3_PPRE3       (RCC_CFGR3_PPRE3_MASK << RCC_CFGR3_PPRE3_SHIFT)

/* --- RCC_PLLL1CFGR values ------------------------------------------------ */

/* PLL1MBOOST[15:12]: Prescaler for EPOD booster input clock */
#define RCC_PLL1CFGR_PLL1MBOOST_SHIFT 12U
#define RCC_PLL1CFGR_PLL1MBOOST_MASK  0x0fU
#define RCC_PLL1CFGR_PLL1MBOOST       (RCC_PLL1CFGR_PLL1MBOOST_MASK << RCC_PLL1CFGR_PLL1MBOOST_SHIFT)

#define RCC_PLL1CFGR_PLL1MBOOST_DIV1  0x0U
#define RCC_PLL1CFGR_PLL1MBOOST_DIV2  0x1U
#define RCC_PLL1CFGR_PLL1MBOOST_DIV4  0x2U
#define RCC_PLL1CFGR_PLL1MBOOST_DIV6  0x3U
#define RCC_PLL1CFGR_PLL1MBOOST_DIV8  0x4U
#define RCC_PLL1CFGR_PLL1MBOOST_DIV10 0x5U
#define RCC_PLL1CFGR_PLL1MBOOST_DIV12 0x6U
#define RCC_PLL1CFGR_PLL1MBOOST_DIV14 0x7U
#define RCC_PLL1CFGR_PLL1MBOOST_DIV16 0x8U

/* --- RCC_PLLxCFGR values ------------------------------------------------- */

#define RCC_PLLCFGR_PLLREN (1U << 18U)
#define RCC_PLLCFGR_PLLQEN (1U << 17U)
#define RCC_PLLCFGR_PLLPEN (1U << 16U)

#define RCC_PLLCFGR_PLLM_SHIFT 8U
#define RCC_PLLCFGR_PLLM_MASK  0x0fU
#define RCC_PLLCFGR_PLLM       (RCC_PLLCFGR_PLLM_MASK << RCC_PLLCFGR_PLLM_SHIFT)
#define RCC_PLLCFGR_DIVM(n)    (((n) - 1U) << RCC_PLLCFGR_PLLM_SHIFT)

#define RCC_PLLCFGR_PLLFRACEN (1U << 4U)

#define RCC_PLLCFGR_PLLRGE_SHIFT 2U
#define RCC_PLLCFGR_PLLRGE_MASK  0x3U
#define RCC_PLLCFGR_PLLRGE       (RCC_PLLCFGR_PLLRGE_MASK << RCC_PLLCFGR_PLLRGE_SHIFT)

#define RCC_PLLCFGR_PLLRGE_4_8_MHZ  0x0U
#define RCC_PLLCFGR_PLLRGE_8_16_MHZ 0x3U

#define RCC_PLLCFGR_PLLSRC_SHIFT 0U
#define RCC_PLLCFGR_PLLSRC_MASK  0x3U
#define RCC_PLLCFGR_PLLSRC       (RCC_PLLCFGR_PLLSRC_MASK << RCC_PLLCFGR_PLLSRC_SHIFT)

#define RCC_PLLCFGR_PLLSRC_NONE  0x0U
#define RCC_PLLCFGR_PLLSRC_MSIS  0x1U
#define RCC_PLLCFGR_PLLSRC_HSI16 0x2U
#define RCC_PLLCFGR_PLLSRC_HSE   0x3U

/* --- RCC_PLLxDIVR values ------------------------------------------------- */

/** @defgroup rcc_plldivr_values RCC_PLLnDIVR Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_PLLDIVR_DIVR_SHIFT 24U
#define RCC_PLLDIVR_DIVQ_SHIFT 16U
#define RCC_PLLDIVR_DIVP_SHIFT 9U
#define RCC_PLLDIVR_DIVN_SHIFT 0U

#define RCC_PLLDIVR_DIVR(n) (((n) - 1U) << RCC_PLLDIVR_DIVR_SHIFT)
#define RCC_PLLDIVR_DIVQ(n) (((n) - 1U) << RCC_PLLDIVR_DIVQ_SHIFT)
#define RCC_PLLDIVR_DIVP(n) (((n) - 1U) << RCC_PLLDIVR_DIVP_SHIFT)
#define RCC_PLLDIVR_DIVN(n) (((n) - 1U) << RCC_PLLDIVR_DIVN_SHIFT)

/* --- RCC_BDCR values ----------------------------------------------------- */

#define RCC_BDCR_LSIPREDIV (1U << 28U)
#define RCC_BDCR_LSIRDY    (1U << 27U)
#define RCC_BDCR_LSION     (1U << 26U)
#define RCC_BDCR_LSEBYP    (1U << 2U)
#define RCC_BDCR_LSERDY    (1U << 1U)
#define RCC_BDCR_LSEON     (1U << 0U)

/* --- RCC_CCIPR1 values --------------------------------------------------- */

#define RCC_CCIPR1_TIMICSEL_SHIFT   29U
#define RCC_CCIPR1_TIMICSEL_MASK    0x7U
#define RCC_CCIPR1_ICLKSEL_SHIFT    26U
#define RCC_CCIPR1_ICLKSEL_MASK     0x3U
#define RCC_CCIPR1_FDCAN1SEL_SHIFT  24U
#define RCC_CCIPR1_FDCAN1SEL_MASK   0x3U
#define RCC_CCIPR1_SYSTICKSEL_SHIFT 22U
#define RCC_CCIPR1_SYSTICKSEL_MASK  0x3U
#define RCC_CCIPR1_SPI1SEL_SHIFT    20U
#define RCC_CCIPR1_SPI1SEL_MASK     0x3U
#define RCC_CCIPR1_LPTIM2SEL_SHIFT  18U
#define RCC_CCIPR1_LPTIM2SEL_MASK   0x3U
#define RCC_CCIPR1_SPI2SEL_SHIFT    16U
#define RCC_CCIPR1_SPI2SEL_MASK     0x3U
#define RCC_CCIPR1_I2C4SEL_SHIFT    14U
#define RCC_CCIPR1_I2C2SEL_SHIFT    12U
#define RCC_CCIPR1_I2C1SEL_SHIFT    10U
#define RCC_CCIPR1_I2CxSEL_MASK     0x3U
#define RCC_CCIPR1_UART5SEL_SHIFT   8U
#define RCC_CCIPR1_UART4SEL_SHIFT   6U
#define RCC_CCIPR1_USART3SEL_SHIFT  4U
#define RCC_CCIPR1_USART2SEL_SHIFT  2U
#define RCC_CCIPR1_USART1SEL_SHIFT  0U
#define RCC_CCIPR1_USARTxSEL_MASK   0x3U

/** @defgroup rcc_ccipr1_values RCC_CCIPR1 Values
 * @ingroup rcc_registers
 * @{*/
#define RCC_CCIPR1_TIMICSEL_DISABLE                           0x0U
#define RCC_CCIPR1_TIMICSEL_HSI_DIV256_MSIS_DIV1024_MSIS_DIV4 0x4U
#define RCC_CCIPR1_TIMICSEL_HSI_DIV256_MSIS_DIV1024_MSIK_DIV4 0x5U
#define RCC_CCIPR1_TIMICSEL_HSI_DIV256_MSIK_DIV1024_MSIS_DIV4 0x6U
#define RCC_CCIPR1_TIMICSEL_HSI_DIV256_MSIK_DIV1024_MSIK_DIV4 0x7U
#define RCC_CCIPR1_ICLKSEL_HSI48                              0x0U
#define RCC_CCIPR1_ICLKSEL_PLL2Q                              0x1U
#define RCC_CCIPR1_ICLKSEL_PLL1Q                              0x2U
#define RCC_CCIPR1_ICLKSEL_MSIK                               0x3U
#define RCC_CCIPR1_FDCAN1SEL_HSE                              0x0U
#define RCC_CCIPR1_FDCAN1SEL_PLL1Q                            0x1U
#define RCC_CCIPR1_FDCAN1SEL_PLL2P                            0x2U
#define RCC_CCIPR1_SYSTICKSEL_HCLK_DIV8                       0x0U
#define RCC_CCIPR1_SYSTICKSEL_LSI                             0x1U
#define RCC_CCIPR1_SYSTICKSEL_LSE                             0x2U
#define RCC_CCIPR1_SPI1SEL_PCLK2                              0x0U
#define RCC_CCIPR1_SPI1SEL_SYSCLK                             0x1U
#define RCC_CCIPR1_SPI1SEL_HSI16                              0x2U
#define RCC_CCIPR1_SPI1SEL_MSIK                               0x3U
#define RCC_CCIPR1_LPTIM2SEL_PCLK1                            0x0U
#define RCC_CCIPR1_LPTIM2SEL_LSI                              0x1U
#define RCC_CCIPR1_LPTIM2SEL_HSI16                            0x2U
#define RCC_CCIPR1_LPTIM2SEL_LSE                              0x3U
#define RCC_CCIPR1_SPI2SEL_PCLK1                              0x0U
#define RCC_CCIPR1_SPI2SEL_SYSCLK                             0x1U
#define RCC_CCIPR1_SPI2SEL_HSI16                              0x2U
#define RCC_CCIPR1_SPI2SEL_MSIK                               0x3U
#define RCC_CCIPR1_I2CxSEL_PCLK1                              0x0U
#define RCC_CCIPR1_I2CxSEL_SYSCLK                             0x1U
#define RCC_CCIPR1_I2CxSEL_HSI16                              0x2U
#define RCC_CCIPR1_I2CxSEL_MSIK                               0x3U
#define RCC_CCIPR1_UARTxSEL_PCLK1                             0x0U
#define RCC_CCIPR1_UARTxSEL_SYSCLK                            0x1U
#define RCC_CCIPR1_UARTxSEL_HSI16                             0x2U
#define RCC_CCIPR1_UARTxSEL_LSE                               0x3U
#define RCC_CCIPR1_USARTxSEL_PCLK1                            0x0U
#define RCC_CCIPR1_USARTxSEL_SYSCLK                           0x1U
#define RCC_CCIPR1_USARTxSEL_HSI16                            0x2U
#define RCC_CCIPR1_USARTxSEL_LSE                              0x3U
#define RCC_CCIPR1_USART1SEL_PCLK2                            0x0U
#define RCC_CCIPR1_USART1SEL_SYSCLK                           0x1U
#define RCC_CCIPR1_USART1SEL_HSI16                            0x2U
#define RCC_CCIPR1_USART1SEL_LSE                              0x3U
/**@}*/

/* --- RCC_CCIPR2 values --------------------------------------------------- */

#define RCC_CCIPR2_I2C6SEL_SHIFT 26U
#define RCC_CCIPR2_I2C5SEL_SHIFT 24U
#define RCC_CCIPR2_I2CxSEL_MASK  0x3U

#define RCC_CCIPR2_USART6SEL_SHIFT 16U
#define RCC_CCIPR2_USART6SEL_MASK  0x3U

/* --- RCC_CCIPR3 values --------------------------------------------------- */

#define RCC_CCIPR3_LPTIM1SEL_SHIFT  10U
#define RCC_CCIPR3_LPTIM1SEL_MASK   0x3U
#define RCC_CCIPR3_LPTIM34SEL_SHIFT 8U
#define RCC_CCIPR3_LPTIM34SEL_MASK  0x3U
#define RCC_CCIPR3_I2C3SEL_SHIFT    6U
#define RCC_CCIPR3_I2C3SEL_MASK     0x3U

/* --- RCC_CCIPR common values --------------------------------------------- */

#define RCC_CCIPR_USARTxSEL_MASK   0x3U
#define RCC_CCIPR_USARTxSEL_PCLKx  0x0U
#define RCC_CCIPR_USARTxSEL_SYSCLK 0x1U
#define RCC_CCIPR_USARTxSEL_HSI16  0x2U
#define RCC_CCIPR_USARTxSEL_LSE    0x3U

#define RCC_CCIPR_LPTIMxSEL_PER_TIMER_SRC 0x0U
#define RCC_CCIPR_LPTIMxSEL_LSI           0x1U
#define RCC_CCIPR_LPTIMxSEL_HSI16         0x2U
#define RCC_CCIPR_LPTIMxSEL_LSE           0x3U

#define RCC_CCIPR_I2CxSEL_PCLKx  0x0U
#define RCC_CCIPR_I2CxSEL_SYSCLK 0x1U
#define RCC_CCIPR_I2CxSEL_HSI16  0x2U
#define RCC_CCIPR_I2CxSEL_MSIK   0x3U

/* --- RCC_CSR values ------------------------------------------------------ */

/** MSISRANGE[31:28]: MSIS clock ranges */
#define RCC_CSR_MSISSRANGE_SHIFT 12U
#define RCC_CSR_MSISSRANGE_MASK  0x0fU

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/** @defgroup rcc_apbxpre RCC_CFGRx APBx prescale factors
 * These can be used for APB1, APB2 and APB3 prescaling
 * @{
 */
#define RCC_PPRE_NODIV 0x0U
#define RCC_PPRE_DIV2  0x4U
#define RCC_PPRE_DIV4  0x5U
#define RCC_PPRE_DIV8  0x6U
#define RCC_PPRE_DIV16 0x7U
/**@}*/

/* --- Variable definitions ------------------------------------------------ */

#define RCC_HSI_BASE_FREQUENCY   16000000UL
#define RCC_HSI48_BASE_FREQUENCY 48000000UL
#define RCC_LSI_BASE_FREQUENCY   32000UL
#define RCC_LSE_BASE_FREQUENCY   32768UL

/** Enumerations for core system/bus clocks for user/driver/system access to base bus clocks
 * not directly associated with a peripheral.
 */
typedef enum rcc_clock_source {
	RCC_CPUCLK,
	RCC_SYSTICKCLK,
	RCC_MSISCLK,
	RCC_MSIKCLK,
	RCC_ICLK,
	RCC_SYSCLK,
	RCC_HCLK,
	RCC_AHBCLK,  /* AHB1, 2 and 3 all use the same clock */
	RCC_APB1CLK, /* Note: APB1 and PCLK1 in manual */
	RCC_APB2CLK, /* Note: APB2 and PCLK2 in manual */
	RCC_APB3CLK, /* Note: APB3 and PCLK3 in manual */
} rcc_clock_source_e;

typedef enum rcc_osc {
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
} rcc_osc_e;

/** PLL Configuration structure. */
typedef struct rcc_pll_config {
	enum rcc_osc sysclock_source; /**< SYSCLK source input selection. */
	uint32_t hse_frequency;       /**< User specified HSE frequency, 0 if none. */
	uint8_t msis_range;           /**< User specified MSIS frequency range, RCC_MSIS_RANGE_OFF if undesired. */

	struct pll_config {
		uint8_t pll_source; /**< RCC_PLLCFGR_PLLSRC_xxx value. */
		uint8_t divm;       /**< Pre-divider value for each PLL. 0-64 integers. */
		uint16_t divn;      /**< Multiplier, 0-512 integer. */
		uint8_t divp;       /**< Post divider for PLLP clock. */
		uint8_t divq;       /**< Post divider for PLLQ clock. */
		uint8_t divr;       /**< Post divider for PLLR clock. */
	} pll1, pll2, pll3;     /**< PLL1-PLL3 configurations. */

	uint8_t hpre;                     /**< HCLK & AHB prescaler */
	uint8_t ppre1;                    /**< APB1 Peripheral prescaler */
	uint8_t ppre2;                    /**< APB2 Peripheral prescaler */
	uint8_t ppre3;                    /**< APB3 Peripheral prescaler */
	uint8_t dpre;                     /**< DSI PHY prescaler */
	uint8_t flash_waitstates;         /**< Latency Value to set for Flash. */
	enum pwr_vos_scale voltage_scale; /**< LDO/SMPS Dynamic Voltage scale used for this frequency. */
	enum pwr_sys_mode power_mode;     /**< LDO/SMPS configuration for device. */
} rcc_pll_config_s;

typedef struct pll_config pll_config_s;

typedef enum pll_number {
	RCC_PLL_NUM_1,
	RCC_PLL_NUM_2,
	RCC_PLL_NUM_3,
} pll_number_e;

#define _REG_BIT(base, bit) (((base) << 5U) + (bit))

enum rcc_periph_rst {
	/* AHB1 peripherals */
	RST_GPDMA1 = _REG_BIT(0x60U, 0U),
	RST_CORDIC = _REG_BIT(0x60U, 1U),
	RST_FMAC = _REG_BIT(0x60U, 2U),
	RST_MDF1 = _REG_BIT(0x60U, 3U),
	RST_CRC = _REG_BIT(0x60U, 12U),
	RST_JPEG = _REG_BIT(0x60U, 15U),
	RST_TSC = _REG_BIT(0x60U, 16U),
	RST_RAMCFG = _REG_BIT(0x60U, 17U),
	RST_DMA2D = _REG_BIT(0x60U, 18U),
	RST_GFXMMU = _REG_BIT(0x60U, 19U),
	RST_GPU2D = _REG_BIT(0x60U, 20U),

	/* AHB2 peripherals */
	RST_GPIOA = _REG_BIT(0x64U, 0U),
	RST_GPIOB = _REG_BIT(0x64U, 1U),
	RST_GPIOC = _REG_BIT(0x64U, 2U),
	RST_GPIOD = _REG_BIT(0x64U, 3U),
	RST_GPIOE = _REG_BIT(0x64U, 4U),
	RST_GPIOF = _REG_BIT(0x64U, 5U),
	RST_GPIOG = _REG_BIT(0x64U, 6U),
	RST_GPIOH = _REG_BIT(0x64U, 7U),
	RST_GPIOI = _REG_BIT(0x64U, 8U),
	RST_GPIOJ = _REG_BIT(0x64U, 9U),
	RST_ADC1_2 = _REG_BIT(0x64U, 10U),
	RST_DCMI_PSSI = _REG_BIT(0x64U, 12U),
	RST_OTG = _REG_BIT(0x64U, 14U),
	RST_AES = _REG_BIT(0x64U, 16U),
	RST_HASH = _REG_BIT(0x64U, 17U),
	RST_RNG = _REG_BIT(0x64U, 18U),
	RST_PKA = _REG_BIT(0x64U, 19U),
	RST_SAES = _REG_BIT(0x64U, 20U),
	RST_OCTOSPIM = _REG_BIT(0x64U, 21U),
	RST_OTFDEC1 = _REG_BIT(0x64U, 23U),
	RST_OTFDEC2 = _REG_BIT(0x64U, 24U),
	RST_SDMMC1 = _REG_BIT(0x64U, 27U),
	RST_SDMMC2 = _REG_BIT(0x64U, 28U),

	RST_FSMC = _REG_BIT(0x68U, 0U),
	RST_OCTOSPI1 = _REG_BIT(0x68U, 4U),
	RST_OCTOSPI2 = _REG_BIT(0x68U, 8U),
	RST_HSPI1 = _REG_BIT(0x68U, 12U),

	/* AHB3 peripherals */
	RST_LPGIO1 = _REG_BIT(0x6cU, 0U),
	RST_ADC4 = _REG_BIT(0x6cU, 5U),
	RST_DAC1 = _REG_BIT(0x6cU, 6U),
	RST_LPDMA1 = _REG_BIT(0x6cU, 9U),
	RST_ADF1 = _REG_BIT(0x6cU, 10U),

	/* APB1 peripherals */
	RST_TIM2 = _REG_BIT(0x74U, 0U),
	RST_TIM3 = _REG_BIT(0x74U, 1U),
	RST_TIM4 = _REG_BIT(0x74U, 2U),
	RST_TIM5 = _REG_BIT(0x74U, 3U),
	RST_TIM6 = _REG_BIT(0x74U, 4U),
	RST_TIM7 = _REG_BIT(0x74U, 5U),
	RST_SPI2 = _REG_BIT(0x74U, 14U),
	RST_USART2 = _REG_BIT(0x74U, 17U),
	RST_USART3 = _REG_BIT(0x74U, 18U),
	RST_UART4 = _REG_BIT(0x74U, 19U),
	RST_UART5 = _REG_BIT(0x74U, 20U),
	RST_I2C1 = _REG_BIT(0x74U, 21U),
	RST_I2C2 = _REG_BIT(0x74U, 22U),
	RST_CRS = _REG_BIT(0x74U, 24U),
	RST_USART6 = _REG_BIT(0x74U, 25U),

	RST_I2C4 = _REG_BIT(0x78U, 1U),
	RST_LPTIM2 = _REG_BIT(0x78U, 5U),
	RST_I2C5 = _REG_BIT(0x78U, 6U),
	RST_I2C6 = _REG_BIT(0x78U, 7U),
	RST_FDCAN1 = _REG_BIT(0x78U, 9U),
	RST_UCPD1 = _REG_BIT(0x78U, 23U),

	/* APB2 peripherals*/
	RST_TIM1 = _REG_BIT(0x7cU, 11U),
	RST_SPI1 = _REG_BIT(0x7cU, 12U),
	RST_TIM8 = _REG_BIT(0x7cU, 13U),
	RST_USART1 = _REG_BIT(0x7cU, 14U),
	RST_TIM15 = _REG_BIT(0x7cU, 16U),
	RST_TIM16 = _REG_BIT(0x7cU, 17U),
	RST_TIM17 = _REG_BIT(0x7cU, 18U),
	RST_SAI1 = _REG_BIT(0x7cU, 21U),
	RST_SAI2 = _REG_BIT(0x7cU, 22U),
	RST_USB = _REG_BIT(0x7cU, 24U),
	RST_GFXTIM = _REG_BIT(0x7cU, 25U),
	RST_LTDC = _REG_BIT(0x7cU, 26U),
	RST_DSI = _REG_BIT(0x7cU, 27U),

	/* APB3 peripherals */
	RST_SYSCFG = _REG_BIT(0x80U, 1U),
	RST_SPI3 = _REG_BIT(0x80U, 5U),
	RST_LPUART1 = _REG_BIT(0x80U, 6U),
	RST_I2C3 = _REG_BIT(0x80U, 7U),
	RST_LPTIM1 = _REG_BIT(0x80U, 11U),
	RST_LPTIM3 = _REG_BIT(0x80U, 12U),
	RST_LPTIM4 = _REG_BIT(0x80U, 13U),
	RST_OPAMP = _REG_BIT(0x80U, 14U),
	RST_COMP = _REG_BIT(0x80U, 15U),
	RST_VREF = _REG_BIT(0x80U, 20U),
};

enum rcc_periph_clken {
	/* AHB1 peripherals */
	RCC_GPDMA1 = _REG_BIT(0x88U, 0U),
	RCC_CORDIC = _REG_BIT(0x88U, 1U),
	RCC_FMAC = _REG_BIT(0x88U, 2U),
	RCC_MDF1 = _REG_BIT(0x88U, 3U),
	RCC_FLASH = _REG_BIT(0x88U, 8U),
	RCC_CRC = _REG_BIT(0x88U, 12U),
	RCC_JPEG = _REG_BIT(0x88U, 15U),
	RCC_TSC = _REG_BIT(0x88U, 16U),
	RCC_RAMCFG = _REG_BIT(0x88U, 17U),
	RCC_DMA2D = _REG_BIT(0x88U, 18U),
	RCC_GFXMMU = _REG_BIT(0x88U, 19U),
	RCC_GPU2D = _REG_BIT(0x88U, 20U),
	RCC_DCACHE2 = _REG_BIT(0x88U, 21U),
	RCC_GTZC1 = _REG_BIT(0x88U, 24U),
	RCC_BKPSRAM = _REG_BIT(0x88U, 28U),
	RCC_DCACHE1 = _REG_BIT(0x88U, 30U),
	RCC_SRAM1 = _REG_BIT(0x88U, 31U),

	/* AHB2 peripherals */
	RCC_GPIOA = _REG_BIT(0x8cU, 0U),
	RCC_GPIOB = _REG_BIT(0x8cU, 1U),
	RCC_GPIOC = _REG_BIT(0x8cU, 2U),
	RCC_GPIOD = _REG_BIT(0x8cU, 3U),
	RCC_GPIOE = _REG_BIT(0x8cU, 4U),
	RCC_GPIOF = _REG_BIT(0x8cU, 5U),
	RCC_GPIOG = _REG_BIT(0x8cU, 6U),
	RCC_GPIOH = _REG_BIT(0x8cU, 7U),
	RCC_GPIOI = _REG_BIT(0x8cU, 8U),
	RCC_GPIOJ = _REG_BIT(0x8cU, 9U),
	RCC_ADC1_2 = _REG_BIT(0x8cU, 10U),
	RCC_DCMI_PSS = _REG_BIT(0x8cU, 12U),
	RCC_OTGFS = _REG_BIT(0x8cU, 14U),
	RCC_OTGHS = _REG_BIT(0x8cU, 14U),
	RCC_OTGHSPHY = _REG_BIT(0x8cU, 15U),
	RCC_AES = _REG_BIT(0x8cU, 16U),
	RCC_HASH = _REG_BIT(0x8cU, 17U),
	RCC_RNG = _REG_BIT(0x8cU, 18U),
	RCC_PKA = _REG_BIT(0x8cU, 19U),
	RCC_SAES = _REG_BIT(0x8cU, 20U),
	RCC_OCTOSPIM = _REG_BIT(0x8cU, 21U),
	RCC_OTFDEC1 = _REG_BIT(0x8cU, 23U),
	RCC_OTFDEC2 = _REG_BIT(0x8cU, 24U),
	RCC_SDMMC1 = _REG_BIT(0x8cU, 27U),
	RCC_SDMMC2 = _REG_BIT(0x8cU, 28U),
	RCC_SRAM2 = _REG_BIT(0x8cU, 30U),
	RCC_SRAM3 = _REG_BIT(0x8cU, 31U),

	RCC_FSMC = _REG_BIT(0x90U, 0U),
	RCC_OCTOSPI1 = _REG_BIT(0x90U, 4U),
	RCC_OCTOSPI2 = _REG_BIT(0x90U, 8U),
	RCC_HSPI1 = _REG_BIT(0x90U, 12U),
	RCC_SRAM6 = _REG_BIT(0x90U, 30U),
	RCC_SRAM5 = _REG_BIT(0x90U, 31U),

	/* AHB3 peripherals */
	RCC_LPGPIO1 = _REG_BIT(0x94U, 0U),
	RCC_PWR = _REG_BIT(0x94U, 2U),
	RCC_ADC4 = _REG_BIT(0x94U, 5U),
	RCC_DAC1 = _REG_BIT(0x94U, 6U),
	RCC_LPDMA1 = _REG_BIT(0x94U, 9U),
	RCC_ADF1 = _REG_BIT(0x94U, 10U),
	RCC_GTZC2 = _REG_BIT(0x94U, 12U),
	RCC_SRAM4 = _REG_BIT(0x94U, 31U),

	/* APB1 peripherals */
	RCC_TIM2 = _REG_BIT(0x9cU, 0U),
	RCC_TIM3 = _REG_BIT(0x9cU, 1U),
	RCC_TIM4 = _REG_BIT(0x9cU, 2U),
	RCC_TIM5 = _REG_BIT(0x9cU, 3U),
	RCC_TIM6 = _REG_BIT(0x9cU, 4U),
	RCC_TIM7 = _REG_BIT(0x9cU, 5U),
	RCC_WWDG = _REG_BIT(0x9cU, 11U),
	RCC_SPI2 = _REG_BIT(0x9cU, 14U),
	RCC_USART2 = _REG_BIT(0x9cU, 17U),
	RCC_USART3 = _REG_BIT(0x9cU, 18U),
	RCC_UART4 = _REG_BIT(0x9cU, 19U),
	RCC_UART5 = _REG_BIT(0x9cU, 20U),
	RCC_I2C1 = _REG_BIT(0x9cU, 21U),
	RCC_I2C2 = _REG_BIT(0x9cU, 22U),
	RCC_CRS = _REG_BIT(0x9cU, 24U),
	RCC_USART6 = _REG_BIT(0x9cU, 25U),

	RCC_I2C4 = _REG_BIT(0xa0U, 1U),
	RCC_LPTIM2 = _REG_BIT(0xa0U, 5U),
	RCC_I2C5 = _REG_BIT(0xa0U, 6U),
	RCC_I2C6 = _REG_BIT(0xa0U, 7U),
	RCC_FDCAN1 = _REG_BIT(0xa0U, 9U),
	RCC_UCPD1 = _REG_BIT(0xa0U, 23U),

	/* APB2 peripherals */
	RCC_TIM1 = _REG_BIT(0xa4U, 11U),
	RCC_SPI1 = _REG_BIT(0xa4U, 12U),
	RCC_TIM8 = _REG_BIT(0xa4U, 13U),
	RCC_USART1 = _REG_BIT(0xa4U, 14U),
	RCC_TIM15 = _REG_BIT(0xa4U, 16U),
	RCC_TIM16 = _REG_BIT(0xa4U, 17U),
	RCC_TIM17 = _REG_BIT(0xa4U, 18U),
	RCC_SAI1 = _REG_BIT(0xa4U, 21U),
	RCC_SAI2 = _REG_BIT(0xa4U, 22U),
	RCC_USB = _REG_BIT(0xa4U, 24U),
	RCC_GFXTIM = _REG_BIT(0xa4U, 25U),
	RCC_LTDCR = _REG_BIT(0xa4U, 26U),
	RCC_DSI = _REG_BIT(0xa4U, 27U),

	/* APB3 peripherals */
	RCC_SYSCFG = _REG_BIT(0xa8U, 1U),
	RCC_SPI3 = _REG_BIT(0xa8U, 5U),
	RCC_LPUART1 = _REG_BIT(0xa8U, 6U),
	RCC_I2C3 = _REG_BIT(0xa8U, 7U),
	RCC_LPTIM1 = _REG_BIT(0xa8U, 11U),
	RCC_LPTIM3 = _REG_BIT(0xa8U, 12U),
	RCC_LPTIM4 = _REG_BIT(0xa8U, 13U),
	RCC_OPAMP = _REG_BIT(0xa8U, 14U),
	RCC_COMP = _REG_BIT(0xa8U, 15U),
	RCC_VREF = _REG_BIT(0xa8U, 20U),
	RCC_RTCAPB = _REG_BIT(0xa8U, 21U),
};

#undef _REG_BIT

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS

/**
 * Setup the base PLLs and clock domains for the STM32U5. This function will
 * utilize the users input parameters to configure all 3 PLLs, as well as the
 * core clock domains (namely SYSCLK, CPU, HCLK, AHB, PCLK1-4) with the
 * specified dividers. Given the dividers, the RCC module will track the
 * the configured frequency for each of these clock domains.
 *
 *   Note: If clock sources, configs, divider, etc. are modified outside of
 *         this module, the frequency tracking may be undefined.
 *   Note: Clock tree is fairly complex, see RM0456 Section 11
 *         for details.
 * @param[in] config  Input config structure defining desired setup.
 */
void rcc_clock_setup_pll(const struct rcc_pll_config *config);

/**
 * Setup and bring up the HSI48 for use by the USB controller.
 *
 * Note: Should be used with the CRS for stability
 */
void rcc_clock_setup_hsi48(void);

/**
 * Get the clock rate (in Hz) of the specified clock source. There are
 * numerous clock sources and configurations on the H7, so rates for each
 * configured peripheral clock are aimed to be discoverd/calculated by this
 * module such that the user does not need to know how the MCU is configured
 * in order to utilize a peripheral clock.
 * @param[in] source  Clock source desired to be fetched.
 * @return Clock rate in Hz for the specified clock. 0 if undefined or error.
 */
uint32_t rcc_get_bus_clk_freq(rcc_clock_source_e source);

/**
 * Get the peripheral clock speed for the USART at the base specified.
 * @param usart  Base address of USART to get clock frequency for (e.g. USART1_BASE).
 */
uint32_t rcc_get_usart_clk_freq(uintptr_t usart);

/**
 * Get the peripheral clock speed for the timer block at the base specified.
 * @param timer  Base address of timer block to get clock frequency for (e.g. TIM1_BASE).
 */
uint32_t rcc_get_timer_clk_freq(uintptr_t timer);

/**
 * Get the peripheral clock speed for the I²C interface at the base specified.
 * @param i2c  Base address of I²C interface to get clock frequency for (e.g. I2C1_BASE).
 */
uint32_t rcc_get_i2c_clk_freq(uintptr_t i2c);

void rcc_osc_on(enum rcc_osc osc);
void rcc_osc_off(enum rcc_osc osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
uint32_t rcc_system_clock_source(void);

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
void rcc_set_peripheral_clk_sel(uintptr_t periph, uint32_t sel);

void rcc_set_sysclk_source(enum rcc_osc clk) LIBOPENCM3_DEPRECATED("see rcc_clock_setup_pll");
void rcc_clock_setup_hsi(const struct rcc_clock_scale *clock) LIBOPENCM3_DEPRECATED("see rcc_clock_setup_pll");

END_DECLS

/**@}*/

#endif
