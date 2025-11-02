/** @defgroup dmamux_defines DMAMUX Defines

@ingroup STM32H7xx_defines

@brief Defined Constants and Types for the STM32H7xx DMAMUX

@version 1.0.0

LGPL License Terms @ref lgpl_license
 */

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
 */

#pragma once

/**@{*/

#include <libopencm3/stm32/common/dmamux_common_all.h>

 /** @defgroup dmamux_reg_base DMAMUX register base addresses
  * @{
  */
#define DMAMUX1				DMAMUX1_BASE
#define DMAMUX2				DMAMUX2_BASE
/**@}*/

/* DMAMUX channel numbers (for API parameters) */
/** @defgroup dmamux_ch_number DMAMUX Channel Number
@ingroup STM32H7xx_dma_defines

@{*/
#define DMAMUX1_CHANNEL0                       1
#define DMAMUX1_CHANNEL1                       2
#define DMAMUX1_CHANNEL2                       3
#define DMAMUX1_CHANNEL3                       4
#define DMAMUX1_CHANNEL4                       5
#define DMAMUX1_CHANNEL5                       6
#define DMAMUX1_CHANNEL6                       7
#define DMAMUX1_CHANNEL7                       8
#define DMAMUX1_CHANNEL8                       9
#define DMAMUX1_CHANNEL9                       10
#define DMAMUX1_CHANNEL10                      11
#define DMAMUX1_CHANNEL11                      12
#define DMAMUX1_CHANNEL12                      13
#define DMAMUX1_CHANNEL13                      14
#define DMAMUX1_CHANNEL14                      15
#define DMAMUX1_CHANNEL15                      16
/**@}*/

/** @defgroup dmamux_rg_channel DMAMUX Request Generator Channel Number
@{*/
#define DMAMUX1_RG_CHANNEL1                     1
#define DMAMUX1_RG_CHANNEL2                     2
#define DMAMUX1_RG_CHANNEL3                     3
#define DMAMUX1_RG_CHANNEL4                     4
#define DMAMUX1_RG_CHANNEL5                     5
#define DMAMUX1_RG_CHANNEL6                     6
#define DMAMUX1_RG_CHANNEL7                     7
#define DMAMUX1_RG_CHANNEL8                     8
/**@}*/

/* --- DMAMUX_CxCR values ------------------------------------ */

/** @defgroup dmamux_cxcr_sync_id SYNCID Synchronization input selected
@{*/
#define DMAMUX1_CxCR_SYNC_ID_DMAMUX1_EVT_CH0    0
#define DMAMUX1_CxCR_SYNC_ID_DMAMUX1_EVT_CH1    1
#define DMAMUX1_CxCR_SYNC_ID_DMAMUX1_EVT_CH2    2
#define DMAMUX1_CxCR_SYNC_ID_LPTIM1_OUT         3
#define DMAMUX1_CxCR_SYNC_ID_LPTIM2_OUT         4
#define DMAMUX1_CxCR_SYNC_ID_LPTIM3_OUT         5
#define DMAMUX1_CxCR_SYNC_ID_EXTIT0             6
#define DMAMUX1_CxCR_SYNC_ID_TIM12_TRGO         7
/**@}*/

/** @defgroup dmamux_cxcr_dmareq_id DMAREQID DMA request line selected
@{*/
#define DMAMUX1_CxCR_DMAREQ_ID_NULL             0
#define DMAMUX1_CxCR_DMAREQ_ID_DMAMUX1_REQ_GEN0 1
#define DMAMUX1_CxCR_DMAREQ_ID_DMAMUX1_REQ_GEN1 2
#define DMAMUX1_CxCR_DMAREQ_ID_DMAMUX1_REQ_GEN2 3
#define DMAMUX1_CxCR_DMAREQ_ID_DMAMUX1_REQ_GEN3 4
#define DMAMUX1_CxCR_DMAREQ_ID_DMAMUX1_REQ_GEN4 5
#define DMAMUX1_CxCR_DMAREQ_ID_DMAMUX1_REQ_GEN5 6
#define DMAMUX1_CxCR_DMAREQ_ID_DMAMUX1_REQ_GEN6 7
#define DMAMUX1_CxCR_DMAREQ_ID_DMAMUX1_REQ_GEN7 8
#define DMAMUX1_CxCR_DMAREQ_ID_ADC1_DMA         9
#define DMAMUX1_CxCR_DMAREQ_ID_ADC2_DMA         10
#define DMAMUX1_CxCR_DMAREQ_ID_TIM1_CH1         11
#define DMAMUX1_CxCR_DMAREQ_ID_TIM1_CH2         12
#define DMAMUX1_CxCR_DMAREQ_ID_TIM1_CH3         13
#define DMAMUX1_CxCR_DMAREQ_ID_TIM1_CH4         14
#define DMAMUX1_CxCR_DMAREQ_ID_TIM1_UP          15
#define DMAMUX1_CxCR_DMAREQ_ID_TIM1_TRIG        16
#define DMAMUX1_CxCR_DMAREQ_ID_TIM1_COM         17
#define DMAMUX1_CxCR_DMAREQ_ID_TIM2_CH1         18
#define DMAMUX1_CxCR_DMAREQ_ID_TIM2_CH2         19
#define DMAMUX1_CxCR_DMAREQ_ID_TIM2_CH3         20
#define DMAMUX1_CxCR_DMAREQ_ID_TIM2_CH4         21
#define DMAMUX1_CxCR_DMAREQ_ID_TIM2_UP          22
#define DMAMUX1_CxCR_DMAREQ_ID_TIM3_CH1         23
#define DMAMUX1_CxCR_DMAREQ_ID_TIM3_CH2         24
#define DMAMUX1_CxCR_DMAREQ_ID_TIM3_CH3         25
#define DMAMUX1_CxCR_DMAREQ_ID_TIM3_CH4         26
#define DMAMUX1_CxCR_DMAREQ_ID_TIM3_UP          27
#define DMAMUX1_CxCR_DMAREQ_ID_TIM3_TRIG        28
#define DMAMUX1_CxCR_DMAREQ_ID_TIM4_CH1         29
#define DMAMUX1_CxCR_DMAREQ_ID_TIM4_CH2         30
#define DMAMUX1_CxCR_DMAREQ_ID_TIM4_CH3         31
#define DMAMUX1_CxCR_DMAREQ_ID_TIM4_UP          32
#define DMAMUX1_CxCR_DMAREQ_ID_I2C1_RX_DMA      33
#define DMAMUX1_CxCR_DMAREQ_ID_I2C1_TX_DMA      34
#define DMAMUX1_CxCR_DMAREQ_ID_I2C2_RX_DMA      35
#define DMAMUX1_CxCR_DMAREQ_ID_I2C2_TX_DMA      36
#define DMAMUX1_CxCR_DMAREQ_ID_SPI1_RX_DMA      37
#define DMAMUX1_CxCR_DMAREQ_ID_SPI1_TX_DMA      38
#define DMAMUX1_CxCR_DMAREQ_ID_SPI2_RX_DMA      39
#define DMAMUX1_CxCR_DMAREQ_ID_SPI2_TX_DMA      40
#define DMAMUX1_CxCR_DMAREQ_ID_USART1_RX_DMA    41
#define DMAMUX1_CxCR_DMAREQ_ID_USART1_TX_DMA    42
#define DMAMUX1_CxCR_DMAREQ_ID_USART2_RX_DMA    43
#define DMAMUX1_CxCR_DMAREQ_ID_USART2_TX_DMA    44
#define DMAMUX1_CxCR_DMAREQ_ID_USART3_RX_DMA    45
#define DMAMUX1_CxCR_DMAREQ_ID_USART3_TX_DMA    46
#define DMAMUX1_CxCR_DMAREQ_ID_TIM8_CH1         47
#define DMAMUX1_CxCR_DMAREQ_ID_TIM8_CH2         48
#define DMAMUX1_CxCR_DMAREQ_ID_TIM8_CH3         49
#define DMAMUX1_CxCR_DMAREQ_ID_TIM8_CH4         50
#define DMAMUX1_CxCR_DMAREQ_ID_TIM8_UP          51
#define DMAMUX1_CxCR_DMAREQ_ID_TIM8_TRIG        52
#define DMAMUX1_CxCR_DMAREQ_ID_TIM8_COM         53
#define DMAMUX1_CxCR_DMAREQ_ID_TIM5_CH1         55
#define DMAMUX1_CxCR_DMAREQ_ID_TIM5_CH2         56
#define DMAMUX1_CxCR_DMAREQ_ID_TIM5_CH3         57
#define DMAMUX1_CxCR_DMAREQ_ID_TIM5_CH4         58
#define DMAMUX1_CxCR_DMAREQ_ID_TIM5_UP          59
#define DMAMUX1_CxCR_DMAREQ_ID_TIM5_TRIG        60
#define DMAMUX1_CxCR_DMAREQ_ID_SPI3_RX_DMA      61
#define DMAMUX1_CxCR_DMAREQ_ID_SPI3_TX_DMA      62
#define DMAMUX1_CxCR_DMAREQ_ID_UART4_RX_DMA     63
#define DMAMUX1_CxCR_DMAREQ_ID_UART4_TX_DMA     64
#define DMAMUX1_CxCR_DMAREQ_ID_UART5_RX_DMA     65
#define DMAMUX1_CxCR_DMAREQ_ID_UART5_TX_DMA     66
#define DMAMUX1_CxCR_DMAREQ_ID_DAC_CH1_DMA      67
#define DMAMUX1_CxCR_DMAREQ_ID_DAC_CH2_DMA      68
#define DMAMUX1_CxCR_DMAREQ_ID_TIM6_UP          69
#define DMAMUX1_CxCR_DMAREQ_ID_TIM7_UP          70
#define DMAMUX1_CxCR_DMAREQ_ID_USART6_RX_DMA    71
#define DMAMUX1_CxCR_DMAREQ_ID_USART6_TX_DMA    72
#define DMAMUX1_CxCR_DMAREQ_ID_I2C3_RX_DMA      73
#define DMAMUX1_CxCR_DMAREQ_ID_I2C3_TX_DMA      74
#define DMAMUX1_CxCR_DMAREQ_ID_DCMI_DMA         75
#define DMAMUX1_CxCR_DMAREQ_ID_CRYPT_IN_DMA     76
#define DMAMUX1_CxCR_DMAREQ_ID_CRYPT_OUT_DMA    77
#define DMAMUX1_CxCR_DMAREQ_ID_HASH_IN_DMA      78
#define DMAMUX1_CxCR_DMAREQ_ID_UART7_RX_DMA     79
#define DMAMUX1_CxCR_DMAREQ_ID_UART7_TX_DMA     80
#define DMAMUX1_CxCR_DMAREQ_ID_UART8_RX_DMA     81
#define DMAMUX1_CxCR_DMAREQ_ID_UART8_TX_DMA     82
#define DMAMUX1_CxCR_DMAREQ_ID_SPI4_RX_DMA      83
#define DMAMUX1_CxCR_DMAREQ_ID_SPI4_TX_DMA      84
#define DMAMUX1_CxCR_DMAREQ_ID_SPI5_RX_DMA      85
#define DMAMUX1_CxCR_DMAREQ_ID_SPI5_TX_DMA      86
#define DMAMUX1_CxCR_DMAREQ_ID_SAI1A_DMA        87
#define DMAMUX1_CxCR_DMAREQ_ID_SAI1B_DMA        88
#define DMAMUX1_CxCR_DMAREQ_ID_SWPMI_RX_DMA     91
#define DMAMUX1_CxCR_DMAREQ_ID_SWPMI_TX_DMA     92
#define DMAMUX1_CxCR_DMAREQ_ID_SPDIFRX_DAT_DMA  93
#define DMAMUX1_CxCR_DMAREQ_ID_SPDIFRX_CTRL_DMA 94
#define DMAMUX1_CxCR_DMAREQ_ID_DFSDM1_DMA0      101
#define DMAMUX1_CxCR_DMAREQ_ID_DFSDM1_DMA1      102
#define DMAMUX1_CxCR_DMAREQ_ID_DFSDM1_DMA2      103
#define DMAMUX1_CxCR_DMAREQ_ID_DFSDM1_DMA3      104
#define DMAMUX1_CxCR_DMAREQ_ID_TIM15_CH1        105
#define DMAMUX1_CxCR_DMAREQ_ID_TIM15_UP         106
#define DMAMUX1_CxCR_DMAREQ_ID_TIM15_TRIG       107
#define DMAMUX1_CxCR_DMAREQ_ID_TIM15_COM        108
#define DMAMUX1_CxCR_DMAREQ_ID_TIM16_CH1        109
#define DMAMUX1_CxCR_DMAREQ_ID_TIM16_UP         110
#define DMAMUX1_CxCR_DMAREQ_ID_TIM17_CH1        111
#define DMAMUX1_CxCR_DMAREQ_ID_TIM17_UP         112
#define DMAMUX1_CxCR_DMAREQ_ID_ADC3_DMA         115
#define DMAMUX1_CxCR_DMAREQ_ID_UART9_RX_DMA     116
#define DMAMUX1_CxCR_DMAREQ_ID_UART9_TX_DMA     117
#define DMAMUX1_CxCR_DMAREQ_ID_UART10_RX_DMA    118
#define DMAMUX1_CxCR_DMAREQ_ID_UART10_TX_DMA    119
#define DMAMUX1_CxCR_DMAREQ_ID_FMAC_RD          120
#define DMAMUX1_CxCR_DMAREQ_ID_FMAC_WR          121
#define DMAMUX1_CxCR_DMAREQ_ID_CORDIC_RD        122
#define DMAMUX1_CxCR_DMAREQ_ID_CORDIC_WR        123
#define DMAMUX1_CxCR_DMAREQ_ID_I2C5_RX_DMA      124
#define DMAMUX1_CxCR_DMAREQ_ID_I2C5_TX_DMA      125
#define DMAMUX1_CxCR_DMAREQ_ID_TIM23_CH1        126
#define DMAMUX1_CxCR_DMAREQ_ID_TIM23_CH2        127
#define DMAMUX1_CxCR_DMAREQ_ID_TIM23_CH3        128
#define DMAMUX1_CxCR_DMAREQ_ID_TIM23_CH4        129
#define DMAMUX1_CxCR_DMAREQ_ID_TIM23_UP         130
#define DMAMUX1_CxCR_DMAREQ_ID_TIM23_TRIG       131
#define DMAMUX1_CxCR_DMAREQ_ID_TIM24_CH1        132
#define DMAMUX1_CxCR_DMAREQ_ID_TIM24_CH2        133
#define DMAMUX1_CxCR_DMAREQ_ID_TIM24_CH3        134
#define DMAMUX1_CxCR_DMAREQ_ID_TIM24_CH4        135
#define DMAMUX1_CxCR_DMAREQ_ID_TIM24_UP         136
#define DMAMUX1_CxCR_DMAREQ_ID_TIM24_TRIG       137
/**@}*/

/* --- DMAMUX_RGxCR values ----------------------------------- */

/** @defgroup dmamux_rgxcr_sig_id SIGID DMA request trigger input selected
@{*/
#define DMAMUX1_RGxCR_SIG_ID_DMAMUX1_EVT_CH0    0
#define DMAMUX1_RGxCR_SIG_ID_DMAMUX1_EVT_CH1    1
#define DMAMUX1_RGxCR_SIG_ID_DMAMUX1_EVT_CH2    2
#define DMAMUX1_RGxCR_SIG_ID_LPTIM1_OUT         3
#define DMAMUX1_RGxCR_SIG_ID_LPTIM2_OUT         4
#define DMAMUX1_RGxCR_SIG_ID_LPTIM3_OUT         5
#define DMAMUX1_RGxCR_SIG_ID_EXTIT0             6
#define DMAMUX1_RGxCR_SIG_ID_TIM12_TRGO         7
/**@}*/

/**@}*/
