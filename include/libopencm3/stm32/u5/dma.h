/** @defgroup dma_defines DMA Defines
 *
 * @ingroup STM32U5xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32U5xx DMA Controller</b>
 *
 * @version 1.0.0
 *
 * @date 03 November 2025
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
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
 */

#ifndef LIBOPENCM3_DMA_H
#define LIBOPENCM3_DMA_H

/**@{*/

/* --- Convenience macros -------------------------------------------------- */

/* DMA controller base addresses (for convenience) */
#define GPDMA1 GPDMA1_BASE
#define LPDMA1 LPDMA1_BASE

/* DMA channel numbers (for API parameters) */
/** @defgroup gpdma_ch_number DMA Channel Number
@ingroup STM32U5xx_dma_defines

@{*/
#define DMA_CHANNEL0  0U
#define DMA_CHANNEL1  1U
#define DMA_CHANNEL2  2U
#define DMA_CHANNEL3  3U
#define DMA_CHANNEL4  4U
#define DMA_CHANNEL5  5U
#define DMA_CHANNEL6  6U
#define DMA_CHANNEL7  7U
#define DMA_CHANNEL8  8U
#define DMA_CHANNEL9  9U
#define DMA_CHANNEL10 10U
#define DMA_CHANNEL11 11U
#define DMA_CHANNEL12 12U
#define DMA_CHANNEL13 13U
#define DMA_CHANNEL14 14U
#define DMA_CHANNEL15 15U
/**@}*/

#define DMA_CHANNEL(periph, n) ((periph) + 0x50U + (0x80U * (uintptr_t)(n)))

/* --- DMA controller registers -------------------------------------------- */

/* --- DMA channel registers ----------------------------------------------- */

/* DMA Channel x Linked-list Base Address Register (DMA_CxLBAR) */
#define DMA_CLBAR(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x00U)
#define GPDMA1_CLBAR(n)      DMA_CLBAR(GPDMA1, (n))
#define LPDMA1_CLBAR(n)      DMA_CLBAR(LPDMA1, (n))

/* DMA Channel x Flag Clear Register (DMA_CxFCR) */
#define DMA_CFCR(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x0cU)
#define GPDMA1_CFCR(n)      DMA_CFCR(GPDMA1, (n))
#define LPDMA1_CFCR(n)      DMA_CFCR(LPDMA1, (n))

/* DMA Channel x Status Register (DMA_CxSR) */
#define DMA_CSR(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x10U)
#define GPDMA1_CSR(n)      DMA_CSR(GPDMA1, (n))
#define LPDMA1_CSR(n)      DMA_CSR(LPDMA1, (n))

/* DMA Channel x Control Register (DMA_CxCR) */
#define DMA_CCR(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x14U)
#define GPDMA1_CCR(n)      DMA_CCR(GPDMA1, (n))
#define LPDMA1_CCR(n)      DMA_CCR(LPDMA1, (n))

/* DMA Channel x Transfer Register 1 (DMA_CxTR1) */
#define DMA_CTR1(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x40U)
#define GPDMA1_CTR1(n)      DMA_CTR1(GPDMA1, (n))
#define LPDMA1_CTR1(n)      DMA_CTR1(LPDMA1, (n))

/* DMA Channel x Transfer Register 2 (DMA_CxTR2) */
#define DMA_CTR2(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x44U)
#define GPDMA1_CTR2(n)      DMA_CTR2(GPDMA1, (n))
#define LPDMA1_CTR2(n)      DMA_CTR2(LPDMA1, (n))

/* DMA Channel x Block Register 1 (DMA_CxBR1) */
#define DMA_CBR1(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x48U)
#define GPDMA1_CBR1(n)      DMA_CBR1(GPDMA1, (n))
#define LPDMA1_CBR1(n)      DMA_CBR1(LPDMA1, (n))

/* DMA Channel x Source Address Register (DMA_CxSAR) */
#define DMA_CSAR(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x4cU)
#define GPDMA1_CSAR(n)      DMA_CSAR(GPDMA1, (n))
#define LPDMA1_CSAR(n)      DMA_CSAR(LPDMA1, (n))

/* DMA Channel x Destination Address Register (DMA_CxDAR) */
#define DMA_CDAR(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x50U)
#define GPDMA1_CDAR(n)      DMA_CDAR(GPDMA1, (n))
#define LPDMA1_CDAR(n)      DMA_CDAR(LPDMA1, (n))

/* DMA Channel x Transfer Register 3 (DMA_CxTR3) */
#define DMA_CTR3(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x54U)
#define GPDMA1_CTR3(n)      DMA_CTR3(GPDMA1, (n))
#define LPDMA1_CTR3(n)      DMA_CTR3(LPDMA1, (n))

/* DMA Channel x Linked-List address Register (DMA_CxLLR) */
#define DMA_CLLR(periph, n) MMIO32(DMA_CHANNEL((periph), (n)) + 0x7cU)
#define GPDMA1_CLLR(n)      DMA_CLLR(GPDMA1, (n))
#define LPDMA1_CLLR(n)      DMA_CLLR(LPDMA1, (n))

/* --- DMA_CxSR values ----------------------------------------------------- */

/** Idle Flag */
#define DMA_CxSR_IDLEF (1U << 0U)
/** Transfer Complete Interrupt Flag */
#define DMA_CxSR_TCIF (1U << 8U)
/** Half Transfer Interrupt Flag */
#define DMA_CxSR_HTIF (1U << 9U)
/** Data Transfer Error Interrupt Flag */
#define DMA_CxSR_DTEIF (1U << 10U)
/** Update Link Transfer Error Interrupt Flag */
#define DMA_CxSR_ULEIF (1U << 11U)
/** User Setting Error Interrupt Flag */
#define DMA_CxSR_USEIF (1U << 12U)
/** Completed Suspension Interrupt Flag */
#define DMA_CxSR_SUSPIF (1U << 13U)
/** Trigger Overrun Interrupt Flag */
#define DMA_CxSR_TOIF (1U << 14U)

/* --- DMA Interrupt Flag offset values ------------------------------------- */

/* For API parameters. These are based on every interrupt flag and flag clear
being at the same relative location */
/** @defgroup dma_if_offset DMA Interrupt Flag Offsets within stream flag group.
@ingroup dma_defines

@{*/
/** Transfer Complete Interrupt Flag */
#define DMA_TCIF DMA_CxSR_TCIF
/** Half Transfer Interrupt Flag */
#define DMA_HTIF DMA_CxSR_HTIF
/** Data Transfer Error Interrupt Flag */
#define DMA_DTEIF DMA_CxSR_DTEIF
/** Update Link Transfer Error Interrupt Flag */
#define DMA_ULEIF DMA_CxSR_ULEIF
/** User Setting Error Interrupt Flag */
#define DMA_USEIF DMA_CxSR_USEIF
/** Completed Suspension Interrupt Flag */
#define DMA_SUSPIF DMA_CxSR_SUSPIF
/** Trigger Overrun Interrupt Flag */
#define DMA_TOIF DMA_CxSR_TOIF
/**@}*/

#define DMA_ISR_FLAGS (DMA_TCIF | DMA_HTIF | DMA_DTEIF | DMA_ULEIF | DMA_USEIF | DMA_SUSPIF | DMA_TOIF)

/* --- DMA_CxCR values ----------------------------------------------------- */

/* EN: Channel enable */
#define DMA_CxCR_EN (1U << 0U)
/* RESET: Reset channel */
#define DMA_CxCR_RESET (1U << 1U)
/* SUSP: Suspend channel */
#define DMA_CxCR_SUSP (1U << 2U)

/* PRIO[23:22]: Channel priority level */
/** @defgroup dma_ch_pri DMA Channel Priority Levels
@ingroup dma_defines

@{*/
#define DMA_CxCR_PRIO_LOW       (0U << 22U)
#define DMA_CxCR_PRIO_MEDIUM    (1U << 22U)
#define DMA_CxCR_PRIO_HIGH      (2U << 22U)
#define DMA_CxCR_PRIO_VERY_HIGH (3U << 22U)
/**@}*/
#define DMA_CxCR_PRIO_SHIFT 22U
#define DMA_CxCR_PRIO_MASK  (3U << 22U)

/* --- DMA_CxTR1 values ---------------------------------------------------- */

/* DW_LOG2[1:0]: Data width (log 2) of transfer unit, in bytes */
/** @defgroup dma_ch_dw_log2 DMA Channel Data Width
@ingroup dma_defines

@{*/
#define DMA_CxTR1_DW_BYTE      0U
#define DMA_CxTR1_DW_HALF_WORD 1U
#define DMA_CxTR1_DW_WORD      2U
#define DMA_CxTR1_DW_ERROR     3U
/**@}*/

#define DMA_CxTR1_SDW_SHIFT 0U
#define DMA_CxTR1_SDW_MASK  (0x3U << 0U)
#define DMA_CxTR1_DDW_SHIFT 16U
#define DMA_CxTR1_DDW_MASK  (0x3U << 16U)

/* SINC: Source incrementing burst */
#define DMA_CxTR1_SINC (1U << 3U)
/* SBL_1[5:0]: Source burst length minus 1 */
#define DMA_CxTR1_SBL_1_MASK  (0x3fU << 4U)
#define DMA_CxTR1_SBL_1_SHIFT 4U
/* SBX: Source byte exchange */
#define DMA_CxTR1_SBX (1U << 13U)
/* SAP: Source allocated port (0 = port 0, 1 = port 1, both AHB) */
#define DMA_CxTR1_SAP (1U << 14U)
/* SSEC: Source secure (0 = NS, 1 = S) */
#define DMA_CxTR1_SSEC (1U << 15U)
/* DINC: Destination incrementing burst */
#define DMA_CxTR1_DINC (1U << 19U)
/* DBL_1[5:0]: Destination burst length minus 1 */
#define DMA_CxTR1_DBL_1_MASK  (0x3fU << 20U)
#define DMA_CxTR1_DBL_1_SHIFT 20U
/* DBX: Destination byte exchange */
#define DMA_CxTR1_DBX (1U << 26U)
/* DHX: Destination half-word exchange */
#define DMA_CxTR1_DHX (1U << 27U)
/* DAP: Destination allocated port (0 = port 0, 1 = port 1, both AHB) */
#define DMA_CxTR1_DAP (1U << 30U)
/* DSEC: Destination secure (0 = NS, 1 = S) */
#define DMA_CxTR1_DSEC (1U << 31U)

#define DMA_CxTR1_DEST_SWAP_NONE          0U
#define DMA_CxTR1_DEST_SWAP_HALF_WORDS    DMA_CxTR1_DHX
#define DMA_CxTR1_DEST_SWAP_BYTE_HALFS    DMA_CxTR1_DBX
#define DMA_CxTR1_DEST_SWAP_ALL_BYTE_WORD (DMA_CxTR1_DHX | DMA_CxTR1_DBX)
#define DMA_CxTR1_DEST_SWAP_MASK          (DMA_CxTR1_DHX | DMA_CxTR1_DBX)

/* --- DMA_CxTR2 values ---------------------------------------------------- */

/* SWREQ: Software request */
#define DMA_CxTR2_SWREQ (1U << 9U)
/* DREQ: Destination hardware request */
#define DMA_CxTR2_DREQ (1U << 10U)
/* BREQ: Block hardware request */
#define DMA_CxTR2_BREQ (1U << 11U)

#define DMA_CxTR2_REQSEL_SHIFT  0U
#define DMA_CxTR2_REQSEL_MASK   (0x3fU << DMA_CxTR2_REQSEL_SHIFT)
#define DMA_CxTR2_TRIGSEL_SHIFT 16U
#define DMA_CxTR2_TRIGSEL_MASK  (0x3fU << DMA_CxTR2_TRIGSEL_SHIFT)
#define DMA_CxTR2_TCEM_SHIFT    30U
#define DMA_CxTR2_TCEM_MASK     (0x3U << DMA_CxTR2_TCEM_SHIFT)

#define GPDMA1_CxTR2_REQSEL_ADC1         0U
#define GPDMA1_CxTR2_REQSEL_ADC4         1U
#define GPDMA1_CxTR2_REQSEL_DAC1_CH1     2U
#define GPDMA1_CxTR2_REQSEL_DAC1_CH2     3U
#define GPDMA1_CxTR2_REQSEL_TIM6_UPD     4U
#define GPDMA1_CxTR2_REQSEL_TIM7_UPD     5U
#define GPDMA1_CxTR2_REQSEL_SPI1_RX      6U
#define GPDMA1_CxTR2_REQSEL_SPI1_TX      7U
#define GPDMA1_CxTR2_REQSEL_SPI2_RX      8U
#define GPDMA1_CxTR2_REQSEL_SPI2_TX      9U
#define GPDMA1_CxTR2_REQSEL_SPI3_RX      10U
#define GPDMA1_CxTR2_REQSEL_SPI3_TX      11U
#define GPDMA1_CxTR2_REQSEL_I2C1_RX      12U
#define GPDMA1_CxTR2_REQSEL_I2C1_TX      13U
#define GPDMA1_CxTR2_REQSEL_I2C1_EVC     14U
#define GPDMA1_CxTR2_REQSEL_I2C2_RX      15U
#define GPDMA1_CxTR2_REQSEL_I2C2_TX      16U
#define GPDMA1_CxTR2_REQSEL_I2C2_EVC     17U
#define GPDMA1_CxTR2_REQSEL_I2C3_RX      18U
#define GPDMA1_CxTR2_REQSEL_I2C3_TX      19U
#define GPDMA1_CxTR2_REQSEL_I2C3_EVC     20U
#define GPDMA1_CxTR2_REQSEL_I2C4_RX      21U
#define GPDMA1_CxTR2_REQSEL_I2C4_TX      22U
#define GPDMA1_CxTR2_REQSEL_I2C4_EVC     23U
#define GPDMA1_CxTR2_REQSEL_USART1_RX    24U
#define GPDMA1_CxTR2_REQSEL_USART1_TX    25U
#define GPDMA1_CxTR2_REQSEL_USART2_RX    26U
#define GPDMA1_CxTR2_REQSEL_USART2_TX    27U
#define GPDMA1_CxTR2_REQSEL_USART3_RX    28U
#define GPDMA1_CxTR2_REQSEL_USART3_TX    29U
#define GPDMA1_CxTR2_REQSEL_UART4_RX     30U
#define GPDMA1_CxTR2_REQSEL_UART4_TX     31U
#define GPDMA1_CxTR2_REQSEL_UART5_RX     32U
#define GPDMA1_CxTR2_REQSEL_UART5_TX     33U
#define GPDMA1_CxTR2_REQSEL_LPUART1_RX   34U
#define GPDMA1_CxTR2_REQSEL_LPUART1_TX   35U
#define GPDMA1_CxTR2_REQSEL_SAI1_A       36U
#define GPDMA1_CxTR2_REQSEL_SAI1_B       37U
#define GPDMA1_CxTR2_REQSEL_SAI2_A       38U
#define GPDMA1_CxTR2_REQSEL_SAI2_B       39U
#define GPDMA1_CxTR2_REQSEL_OCTOSPI1     40U
#define GPDMA1_CxTR2_REQSEL_OCTOSPI2     41U
#define GPDMA1_CxTR2_REQSEL_TIM1_CC1     42U
#define GPDMA1_CxTR2_REQSEL_TIM1_CC2     43U
#define GPDMA1_CxTR2_REQSEL_TIM1_CC3     44U
#define GPDMA1_CxTR2_REQSEL_TIM1_CC4     45U
#define GPDMA1_CxTR2_REQSEL_TIM1_UPD     46U
#define GPDMA1_CxTR2_REQSEL_TIM1_TRG     47U
#define GPDMA1_CxTR2_REQSEL_TIM1_COM     48U
#define GPDMA1_CxTR2_REQSEL_TIM8_CC1     49U
#define GPDMA1_CxTR2_REQSEL_TIM8_CC2     50U
#define GPDMA1_CxTR2_REQSEL_TIM8_CC3     51U
#define GPDMA1_CxTR2_REQSEL_TIM8_CC4     52U
#define GPDMA1_CxTR2_REQSEL_TIM8_UPD     53U
#define GPDMA1_CxTR2_REQSEL_TIM8_TRG     54U
#define GPDMA1_CxTR2_REQSEL_TIM8_COM     55U
#define GPDMA1_CxTR2_REQSEL_TIM2_CC1     56U
#define GPDMA1_CxTR2_REQSEL_TIM2_CC2     57U
#define GPDMA1_CxTR2_REQSEL_TIM2_CC3     58U
#define GPDMA1_CxTR2_REQSEL_TIM2_CC4     59U
#define GPDMA1_CxTR2_REQSEL_TIM2_UPD     60U
#define GPDMA1_CxTR2_REQSEL_TIM3_CC1     61U
#define GPDMA1_CxTR2_REQSEL_TIM3_CC2     62U
#define GPDMA1_CxTR2_REQSEL_TIM3_CC3     63U
#define GPDMA1_CxTR2_REQSEL_TIM3_CC4     64U
#define GPDMA1_CxTR2_REQSEL_TIM3_UPD     65U
#define GPDMA1_CxTR2_REQSEL_TIM3_TRG     66U
#define GPDMA1_CxTR2_REQSEL_TIM4_CC1     67U
#define GPDMA1_CxTR2_REQSEL_TIM4_CC2     68U
#define GPDMA1_CxTR2_REQSEL_TIM4_CC3     69U
#define GPDMA1_CxTR2_REQSEL_TIM4_CC4     70U
#define GPDMA1_CxTR2_REQSEL_TIM4_UPD     71U
#define GPDMA1_CxTR2_REQSEL_TIM5_CC1     72U
#define GPDMA1_CxTR2_REQSEL_TIM5_CC2     73U
#define GPDMA1_CxTR2_REQSEL_TIM5_CC3     74U
#define GPDMA1_CxTR2_REQSEL_TIM5_CC4     75U
#define GPDMA1_CxTR2_REQSEL_TIM5_UPD     76U
#define GPDMA1_CxTR2_REQSEL_TIM5_TRG     77U
#define GPDMA1_CxTR2_REQSEL_TIM15_CC1    78U
#define GPDMA1_CxTR2_REQSEL_TIM15_UPD    79U
#define GPDMA1_CxTR2_REQSEL_TIM15_TRG    80U
#define GPDMA1_CxTR2_REQSEL_TIM15_COM    81U
#define GPDMA1_CxTR2_REQSEL_TIM16_CC1    82U
#define GPDMA1_CxTR2_REQSEL_TIM16_UPD    83U
#define GPDMA1_CxTR2_REQSEL_TIM17_CC1    84U
#define GPDMA1_CxTR2_REQSEL_TIM17_UPD    85U
#define GPDMA1_CxTR2_REQSEL_DCMI_PSSI    86U
#define GPDMA1_CxTR2_REQSEL_AES_IN       87U
#define GPDMA1_CxTR2_REQSEL_AES_OUT      88U
#define GPDMA1_CxTR2_REQSEL_HASH_IN      89U
#define GPDMA1_CxTR2_REQSEL_UCPD1_TX     90U
#define GPDMA1_CxTR2_REQSEL_UCPD1_RX     91U
#define GPDMA1_CxTR2_REQSEL_MDF1_FLT0    92U
#define GPDMA1_CxTR2_REQSEL_MDF1_FLT1    93U
#define GPDMA1_CxTR2_REQSEL_MDF1_FLT2    94U
#define GPDMA1_CxTR2_REQSEL_MDF1_FLT3    95U
#define GPDMA1_CxTR2_REQSEL_MDF1_FLT4    96U
#define GPDMA1_CxTR2_REQSEL_MDF1_FLT5    97U
#define GPDMA1_CxTR2_REQSEL_ADF1_FLT0    98U
#define GPDMA1_CxTR2_REQSEL_FMAC_READ    99U
#define GPDMA1_CxTR2_REQSEL_FMAC_WRITE   100U
#define GPDMA1_CxTR2_REQSEL_CORDIC_READ  101U
#define GPDMA1_CxTR2_REQSEL_CORDIC_WRITE 102U
#define GPDMA1_CxTR2_REQSEL_SAES_IN      103U
#define GPDMA1_CxTR2_REQSEL_SAES_OUT     104U
#define GPDMA1_CxTR2_REQSEL_LPTIM1_IC1   105U
#define GPDMA1_CxTR2_REQSEL_LPTIM1_IC2   106U
#define GPDMA1_CxTR2_REQSEL_LPTIM1_UE    107U
#define GPDMA1_CxTR2_REQSEL_LPTIM2_IC1   108U
#define GPDMA1_CxTR2_REQSEL_LPTIM2_IC2   109U
#define GPDMA1_CxTR2_REQSEL_LPTIM2_UE    110U
#define GPDMA1_CxTR2_REQSEL_LPTIM3_IC1   111U
#define GPDMA1_CxTR2_REQSEL_LPTIM3_IC2   112U
#define GPDMA1_CxTR2_REQSEL_LPTIM3_UE    113U
#define GPDMA1_CxTR2_REQSEL_HSPI1        114U
#define GPDMA1_CxTR2_REQSEL_I2C5_RX      115U
#define GPDMA1_CxTR2_REQSEL_I2C5_TX      116U
#define GPDMA1_CxTR2_REQSEL_I2C5_EVC     117U
#define GPDMA1_CxTR2_REQSEL_I2C6_RX      118U
#define GPDMA1_CxTR2_REQSEL_I2C6_TX      119U
#define GPDMA1_CxTR2_REQSEL_I2C6_EVC     120U
#define GPDMA1_CxTR2_REQSEL_USART6_RX    121U
#define GPDMA1_CxTR2_REQSEL_USART6_TX    122U
#define GPDMA1_CxTR2_REQSEL_ADC2         123U
#define GPDMA1_CxTR2_REQSEL_JPEG_RX      124U
#define GPDMA1_CxTR2_REQSEL_JPEG_TX      125U

#define GPDMA1_CxTR2_TRIGSEL_EXTI0       0U
#define GPDMA1_CxTR2_TRIGSEL_EXTI1       1U
#define GPDMA1_CxTR2_TRIGSEL_EXTI2       2U
#define GPDMA1_CxTR2_TRIGSEL_EXTI3       3U
#define GPDMA1_CxTR2_TRIGSEL_EXTI4       4U
#define GPDMA1_CxTR2_TRIGSEL_EXTI5       5U
#define GPDMA1_CxTR2_TRIGSEL_EXTI6       6U
#define GPDMA1_CxTR2_TRIGSEL_EXTI7       7U
#define GPDMA1_CxTR2_TRIGSEL_TAM_TRG1    8U
#define GPDMA1_CxTR2_TRIGSEL_TAM_TRG2    9U
#define GPDMA1_CxTR2_TRIGSEL_TAM_TRG3    10U
#define GPDMA1_CxTR2_TRIGSEL_LPTIM1_CH1  11U
#define GPDMA1_CxTR2_TRIGSEL_LPTIM1_CH2  12U
#define GPDMA1_CxTR2_TRIGSEL_LPTIM2_CH1  13U
#define GPDMA1_CxTR2_TRIGSEL_LPTIM2_CH2  14U
#define GPDMA1_CxTR2_TRIGSEL_LPTIM4_OUT  15U
#define GPDMA1_CxTR2_TRIGSEL_COMP1_OUT   16U
#define GPDMA1_CxTR2_TRIGSEL_COMP2_OUT   17U
#define GPDMA1_CxTR2_TRIGSEL_RTC_ALRA    18U
#define GPDMA1_CxTR2_TRIGSEL_RTC_ALRB    19U
#define GPDMA1_CxTR2_TRIGSEL_RTC_WUT     20U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH0  22U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH1  23U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH2  24U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH3  25U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH4  26U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH5  27U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH6  28U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH7  29U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH8  30U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH9  31U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH10 32U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH11 33U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH12 34U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH13 35U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH14 36U
#define GPDMA1_CxTR2_TRIGSEL_GPDMA1_CH15 37U
#define GPDMA1_CxTR2_TRIGSEL_LPDMA1_CH0  38U
#define GPDMA1_CxTR2_TRIGSEL_LPDMA1_CH1  39U
#define GPDMA1_CxTR2_TRIGSEL_LPDMA1_CH2  40U
#define GPDMA1_CxTR2_TRIGSEL_LPDMA1_CH3  41U
#define GPDMA1_CxTR2_TRIGSEL_TIM2_TRGO   42U
#define GPDMA1_CxTR2_TRIGSEL_TIM15_TRGO  43U
#define GPDMA1_CxTR2_TRIGSEL_TIM3_TRGO   44U
#define GPDMA1_CxTR2_TRIGSEL_TIM4_TRGO   45U
#define GPDMA1_CxTR2_TRIGSEL_TIM5_TRGO   46U
#define GPDMA1_CxTR2_TRIGSEL_LTDC_LI     47U
#define GPDMA1_CxTR2_TRIGSEL_DSI_TE      48U
#define GPDMA1_CxTR2_TRIGSEL_DSI_ER      49U
#define GPDMA1_CxTR2_TRIGSEL_DMA2D_TC    50U
#define GPDMA1_CxTR2_TRIGSEL_DMA2D_CTC   51U
#define GPDMA1_CxTR2_TRIGSEL_DMA2D_TW    52U
#define GPDMA1_CxTR2_TRIGSEL_GPU2D_FLAG0 53U
#define GPDMA1_CxTR2_TRIGSEL_GPU2D_FLAG1 54U
#define GPDMA1_CxTR2_TRIGSEL_GPU2D_FLAG2 55U
#define GPDMA1_CxTR2_TRIGSEL_GPU2D_FLAG3 56U
#define GPDMA1_CxTR2_TRIGSEL_ADC4_AWD1   57U
#define GPDMA1_CxTR2_TRIGSEL_ADC1_AWD1   58U
#define GPDMA1_CxTR2_TRIGSEL_GFXTIM_EV4  59U
#define GPDMA1_CxTR2_TRIGSEL_GFXTIM_EV3  60U
#define GPDMA1_CxTR2_TRIGSEL_GFXTIM_EV2  61U
#define GPDMA1_CxTR2_TRIGSEL_GFXTIM_EV1  62U
#define GPDMA1_CxTR2_TRIGSEL_JPEG_EOC    63U
#define GPDMA1_CxTR2_TRIGSEL_JPEG_IFNF   64U
#define GPDMA1_CxTR2_TRIGSEL_JPEG_IFT    65U
#define GPDMA1_CxTR2_TRIGSEL_JPEG_OFNE   66U
#define GPDMA1_CxTR2_TRIGSEL_JPEG_OFT    67U

#define LPDMA1_CxTR2_REQSEL_LPUART1_RX 0U
#define LPDMA1_CxTR2_REQSEL_LPUART1_TX 1U
#define LPDMA1_CxTR2_REQSEL_SPI3_RX    2U
#define LPDMA1_CxTR2_REQSEL_SPI3_TX    3U
#define LPDMA1_CxTR2_REQSEL_I2C3_RX    4U
#define LPDMA1_CxTR2_REQSEL_I2C3_TX    5U
#define LPDMA1_CxTR2_REQSEL_I2C3_EVC   6U
#define LPDMA1_CxTR2_REQSEL_ADC4       7U
#define LPDMA1_CxTR2_REQSEL_DAC1_CH1   8U
#define LPDMA1_CxTR2_REQSEL_DAC1_CH2   9U
#define LPDMA1_CxTR2_REQSEL_ADF1_FLT0  10U
#define LPDMA1_CxTR2_REQSEL_LPTIM1_IC1 11U
#define LPDMA1_CxTR2_REQSEL_LPTIM1_IC2 12U
#define LPDMA1_CxTR2_REQSEL_LPTIM1_UE  13U
#define LPDMA1_CxTR2_REQSEL_LPTIM3_IC1 14U
#define LPDMA1_CxTR2_REQSEL_LPTIM3_IC2 15U
#define LPDMA1_CxTR2_REQSEL_LPTIM3_UE  16U

#define LPDMA1_CxTR2_TRIGSEL_EXTI0       0U
#define LPDMA1_CxTR2_TRIGSEL_EXTI1       1U
#define LPDMA1_CxTR2_TRIGSEL_EXTI2       2U
#define LPDMA1_CxTR2_TRIGSEL_EXTI3       3U
#define LPDMA1_CxTR2_TRIGSEL_EXTI4       4U
#define LPDMA1_CxTR2_TRIGSEL_TAMP_TRG1   5U
#define LPDMA1_CxTR2_TRIGSEL_TAMP_TRG2   6U
#define LPDMA1_CxTR2_TRIGSEL_TAMP_TRG3   7U
#define LPDMA1_CxTR2_TRIGSEL_TIM1_CH1    8U
#define LPDMA1_CxTR2_TRIGSEL_TIM1_CH2    9U
#define LPDMA1_CxTR2_TRIGSEL_TIM3_CH1    10U
#define LPDMA1_CxTR2_TRIGSEL_TIM4_OUT    11U
#define LPDMA1_CxTR2_TRIGSEL_COMP1_OUT   12U
#define LPDMA1_CxTR2_TRIGSEL_COMP2_OUT   13U
#define LPDMA1_CxTR2_TRIGSEL_RTC_ALRA    14U
#define LPDMA1_CxTR2_TRIGSEL_RTC_ALRB    15U
#define LPDMA1_CxTR2_TRIGSEL_RTC_WUT     16U
#define LPDMA1_CxTR2_TRIGSEL_ADC4_AWD1   17U
#define LPDMA1_CxTR2_TRIGSEL_LPDMA1_CH0  18U
#define LPDMA1_CxTR2_TRIGSEL_LPDMA1_CH1  19U
#define LPDMA1_CxTR2_TRIGSEL_LPDMA1_CH2  20U
#define LPDMA1_CxTR2_TRIGSEL_LPDMA1_CH3  21U
#define LPDMA1_CxTR2_TRIGSEL_GPDMA1_CH0  22U
#define LPDMA1_CxTR2_TRIGSEL_GPDMA1_CH1  23U
#define LPDMA1_CxTR2_TRIGSEL_GPDMA1_CH4  24U
#define LPDMA1_CxTR2_TRIGSEL_GPDMA1_CH5  25U
#define LPDMA1_CxTR2_TRIGSEL_GPDMA1_CH6  26U
#define LPDMA1_CxTR2_TRIGSEL_GPDMA1_CH7  27U
#define LPDMA1_CxTR2_TRIGSEL_GPDMA1_CH12 28U
#define LPDMA1_CxTR2_TRIGSEL_GPDMA1_CH13 29U
#define LPDMA1_CxTR2_TRIGSEL_TIM2_TRGO   30U
#define LPDMA1_CxTR2_TRIGSEL_TIM15_TRGO  31U

typedef enum dma_transfer_complete_mode {
	DMA_TRANSFER_COMPLETE_MODE_BLOCK = 0U,
	DMA_TRANSFER_COMPLETE_MODE_2D_BLOCK = 1U,
	DMA_TRANSFER_COMPLETE_MODE_LLI = 2U,
	DMA_TRANSFER_COMPLETE_MODE_CHANNEL = 3U,
} dma_transfer_complete_mode_e;

/* --- DMA_CxTR3 values ---------------------------------------------------- */

/* DAO[28:16]: Destination address offset (stride) */
/** @defgroup dma_ch_dao DMA Channel Destination Address Offset
@ingroup dma_defines

@{*/
#define DMA_CxTR3_DAO_MASK  0x1fff0000U
#define DMA_CxTR3_DAO_SHIFT 16U
/**@}*/

/* SAO[12:0]: Source address offset (stride) */
/** @defgroup dma_ch_sao DMA Channel Source Address Offset
@ingroup dma_defines

@{*/
#define DMA_CxTR3_SAO_MASK  0x00001fffU
#define DMA_CxTR3_SAO_SHIFT 0U
/**@}*/

/* --- DMA_CxLLR values ---------------------------------------------------- */

/** ULL: Update LLR from memory */
#define DMA_CxLLR_ULL (1U << 16U)
/** UDA: Update DAR from memory */
#define DMA_CxLLR_UDA (1U << 27U)
/** USA: Update SAR from memory */
#define DMA_CxLLR_USA (1U << 28U)
/** UB1: Update BR1 from memory */
#define DMA_CxLLR_UB1 (1U << 29U)
/** UT2: Update TR2 from memory */
#define DMA_CxLLR_UT2 (1U << 30U)
/** UT1: Update TR1 from memory */
#define DMA_CxLLR_UT1 (1U << 31U)

BEGIN_DECLS

void dma_channel_reset(uintptr_t dma, uint8_t channel);
void dma_clear_interrupt_flags(uintptr_t dma, uint8_t channel, uint32_t interrupts);
bool dma_get_interrupt_flag(uintptr_t dma, uint8_t channel, uint32_t interrupt);
void dma_enable_interrupts(uintptr_t dma, uint8_t channel, uint32_t interrupts);
void dma_disable_interrupts(uintptr_t dma, uint8_t channel, uint32_t interrupts);
void dma_set_priority(uintptr_t dma, uint8_t channel, uint32_t prio);
void dma_set_source_width(uintptr_t dma, uint8_t channel, uint8_t width);
void dma_set_destination_width(uintptr_t dma, uint8_t channel, uint8_t width);
void dma_enable_source_increment_mode(uintptr_t dma, uint8_t channel);
void dma_disable_source_increment_mode(uintptr_t dma, uint8_t channel);
void dma_enable_destination_increment_mode(uintptr_t dma, uint8_t channel);
void dma_disable_destination_increment_mode(uintptr_t dma, uint8_t channel);
void dma_setup_linked_list(uintptr_t dma, uint8_t channel, const uintptr_t *linked_list, uint32_t flags);

void dma_request_select(uintptr_t dma, uint8_t channel, uint8_t request);
void dma_trigger_select(uintptr_t dma, uint8_t channel, uint8_t trigger);
void dma_set_transfer_complete_mode(uintptr_t dma, uint8_t channel, dma_transfer_complete_mode_e mode);
bool dma_set_source_burst(uintptr_t dma, uint8_t channel, uint8_t burst);
bool dma_set_destination_burst(uintptr_t dma, uint8_t channel, uint8_t burst);
void dma_set_source_stride(uintptr_t dma, uint8_t channel, uint16_t stride);
void dma_set_destination_stride(uintptr_t dma, uint8_t channel, uint16_t stride);
void dma_set_source_secure(uintptr_t dma, uint8_t channel, bool secure);
void dma_set_destination_secure(uintptr_t dma, uint8_t channel, bool secure);
void dma_set_source_byte_swap(uintptr_t dma, uint8_t channel, bool swap);
void dma_set_destination_swapping(uintptr_t dma, uint8_t channel, uint32_t swap_mode);
bool dma_set_source_port(uintptr_t dma, uint8_t channel, uint8_t port);
bool dma_set_destination_port(uintptr_t dma, uint8_t channel, uint8_t port);
// XXX: Deal with CxTR1 PAM bits

void dma_set_block_flow_control(uintptr_t dma, uint8_t channel);
void dma_set_burst_flow_control(uintptr_t dma, uint8_t channel);
void dma_set_source_flow_control(uintptr_t dma, uint8_t channel);
void dma_set_destination_flow_control(uintptr_t dma, uint8_t channel);
void dma_set_software_request(uintptr_t dma, uint8_t channel);
void dma_set_hardware_request(uintptr_t dma, uint8_t channel);

void dma_enable_channel(uintptr_t dma, uint8_t channel);
void dma_disable_channel(uintptr_t dma, uint8_t channel);
void dma_set_source_address(uintptr_t dma, uint8_t channel, uintptr_t address);
void dma_set_destination_address(uintptr_t dma, uint8_t channel, uintptr_t address);
uint16_t dma_get_number_of_data(uintptr_t dma, uint8_t channel);
void dma_set_number_of_data(uintptr_t dma, uint8_t channel, uint16_t number);

END_DECLS
/**@}*/
#endif
