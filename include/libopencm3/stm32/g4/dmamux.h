/** @defgroup dmamux_defines DMAMUX Defines

@ingroup STM32G4xx_defines

@brief Defined Constants and Types for the STM32G4xx DMAMUX

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
#define DMAMUX1				DMAMUX_BASE
/**@}*/

/* --- DMAMUX_CxCR values ------------------------------------ */

/** @defgroup dmamux_cxcr_sync_id SYNCID Synchronization input selected
@{*/
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE0       0
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE1       1
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE2       2
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE3       3
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE4       4
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE5       5
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE6       6
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE7       7
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE8       8
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE9       9
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE10      10
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE11      11
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE12      12
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE13      13
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE14      14
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE15      15
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH0_EVT   16
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH1_EVT   17
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH2_EVT   18
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH3_EVT   19
#define DMAMUX_CxCR_SYNC_ID_LPTIM1_OUT       20
/**@}*/


/** @defgroup dmamux_cxcr_dmareq_id DMAREQID DMA request line selected
@{*/
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN0  1
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN1  2
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN2  3
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN3  4
#define DMAMUX_CxCR_DMAREQ_ID_ADC1             5
#define DMAMUX_CxCR_DMAREQ_ID_DAC1_CH1         6
#define DMAMUX_CxCR_DMAREQ_ID_DAC1_CH2         7
#define DMAMUX_CxCR_DMAREQ_ID_TIM6_UP          8
#define DMAMUX_CxCR_DMAREQ_ID_TIM7_UP          9
#define DMAMUX_CxCR_DMAREQ_ID_SPI1_RX          10
#define DMAMUX_CxCR_DMAREQ_ID_SPI1_TX          11
#define DMAMUX_CxCR_DMAREQ_ID_SPI2_RX          12
#define DMAMUX_CxCR_DMAREQ_ID_SPI2_TX          13
#define DMAMUX_CxCR_DMAREQ_ID_SPI3_RX          14
#define DMAMUX_CxCR_DMAREQ_ID_SPI3_TX          15
#define DMAMUX_CxCR_DMAREQ_ID_I2C1_RX          16
#define DMAMUX_CxCR_DMAREQ_ID_I2C1_TX          17
#define DMAMUX_CxCR_DMAREQ_ID_I2C2_RX          18
#define DMAMUX_CxCR_DMAREQ_ID_I2C2_TX          19
#define DMAMUX_CxCR_DMAREQ_ID_I2C3_RX          20
#define DMAMUX_CxCR_DMAREQ_ID_I2C3_TX          21
#define DMAMUX_CxCR_DMAREQ_ID_I2C4_RX          22
#define DMAMUX_CxCR_DMAREQ_ID_I2C4_TX          23
#define DMAMUX_CxCR_DMAREQ_ID_UART1_RX         24
#define DMAMUX_CxCR_DMAREQ_ID_UART1_TX         25
#define DMAMUX_CxCR_DMAREQ_ID_UART2_RX         26
#define DMAMUX_CxCR_DMAREQ_ID_UART2_TX         27
#define DMAMUX_CxCR_DMAREQ_ID_UART3_RX         28
#define DMAMUX_CxCR_DMAREQ_ID_UART3_TX         29
#define DMAMUX_CxCR_DMAREQ_ID_UART4_RX         30
#define DMAMUX_CxCR_DMAREQ_ID_UART4_TX         31
#define DMAMUX_CxCR_DMAREQ_ID_UART5_RX         32
#define DMAMUX_CxCR_DMAREQ_ID_UART5_TX         33
#define DMAMUX_CxCR_DMAREQ_ID_LPUART1_RX       34
#define DMAMUX_CxCR_DMAREQ_ID_LPUART1_TX       35
#define DMAMUX_CxCR_DMAREQ_ID_ADC2             36
#define DMAMUX_CxCR_DMAREQ_ID_ADC3             37
#define DMAMUX_CxCR_DMAREQ_ID_ADC4             38
#define DMAMUX_CxCR_DMAREQ_ID_ADC5             39
#define DMAMUX_CxCR_DMAREQ_ID_QUADSPI          40
#define DMAMUX_CxCR_DMAREQ_ID_DAC2_CH1         41
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH1         42
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH2         43
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH3         44
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH4         45
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_UP          46
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_TRIG        47
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_COM         48
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_CH1         49
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_CH2         50
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_CH3         51
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_CH4         52
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_UP          53
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_TRIG        54
#define DMAMUX_CxCR_DMAREQ_ID_TIM8_COM         55
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH1         56
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH2         57
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH3         58
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH4         59
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_UP          60
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH1         61
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH2         62
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH3         63
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH4         64
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_UP          65
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_TRIG        66
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_CH1         67
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_CH2         68
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_CH3         69
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_CH4         70
#define DMAMUX_CxCR_DMAREQ_ID_TIM4_UP          71
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_CH1         72
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_CH2         73
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_CH3         74
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_CH4         75
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_UP          76
#define DMAMUX_CxCR_DMAREQ_ID_TIM5_TRIG        77
#define DMAMUX_CxCR_DMAREQ_ID_TIM15_CH1        78
#define DMAMUX_CxCR_DMAREQ_ID_TIM15_UP         79
#define DMAMUX_CxCR_DMAREQ_ID_TIM15_TRIG       80
#define DMAMUX_CxCR_DMAREQ_ID_TIM15_COM        81
#define DMAMUX_CxCR_DMAREQ_ID_TIM16_CH1        82
#define DMAMUX_CxCR_DMAREQ_ID_TIM16_UP         83
#define DMAMUX_CxCR_DMAREQ_ID_TIM17_CH1        84
#define DMAMUX_CxCR_DMAREQ_ID_TIM17_UP         85
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_CH1        86
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_CH2        87
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_CH3        88
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_CH4        89
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_UP         90
#define DMAMUX_CxCR_DMAREQ_ID_AES_IN           91
#define DMAMUX_CxCR_DMAREQ_ID_AES_OUT          92
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_TRIG       93
#define DMAMUX_CxCR_DMAREQ_ID_TIM20_COM        94
#define DMAMUX_CxCR_DMAREQ_ID_HRTIM_MASTER     95
#define DMAMUX_CxCR_DMAREQ_ID_HRTIM_TIMA       96
#define DMAMUX_CxCR_DMAREQ_ID_HRTIM_TIMB       97
#define DMAMUX_CxCR_DMAREQ_ID_HRTIM_TIMC       98
#define DMAMUX_CxCR_DMAREQ_ID_HRTIM_TIMD       99
#define DMAMUX_CxCR_DMAREQ_ID_HRTIM_TIME       100
#define DMAMUX_CxCR_DMAREQ_ID_HRTIM_TIMF       101
#define DMAMUX_CxCR_DMAREQ_ID_DAC3_CH1         102
#define DMAMUX_CxCR_DMAREQ_ID_DAC3_CH2         103
#define DMAMUX_CxCR_DMAREQ_ID_DAC4_CH1         104
#define DMAMUX_CxCR_DMAREQ_ID_DAC4_CH2         105
#define DMAMUX_CxCR_DMAREQ_ID_SPI4_RX          106
#define DMAMUX_CxCR_DMAREQ_ID_SPI4_TX          107
#define DMAMUX_CxCR_DMAREQ_ID_SAI1_A           108
#define DMAMUX_CxCR_DMAREQ_ID_SAI1_B           109
#define DMAMUX_CxCR_DMAREQ_ID_FMAC_READ        110
#define DMAMUX_CxCR_DMAREQ_ID_FMAC_WRITE       111
#define DMAMUX_CxCR_DMAREQ_ID_CORDIC_READ      112
#define DMAMUX_CxCR_DMAREQ_ID_CORDIC_WRITE     113
#define DMAMUX_CxCR_DMAREQ_ID_UCPD1_RX         114
#define DMAMUX_CxCR_DMAREQ_ID_UCPD1_TX         115

/**@}*/

/* --- DMAMUX_RGxCR values ----------------------------------- */

/** @defgroup dmamux_rgxcr_sig_id SIGID DMA request trigger input selected
@{*/
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE0       0
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE1       1
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE2       2
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE3       3
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE4       4
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE5       5
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE6       6
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE7       7
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE8       8
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE9       9
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE10      10
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE11      11
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE12      12
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE13      13
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE14      14
#define DMAMUX_CxCR_SYNC_ID_EXTI_LINE15      15
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH0_EVT   16
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH1_EVT   17
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH2_EVT   18
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_CH3_EVT   19
#define DMAMUX_CxCR_SYNC_ID_LPTIM1_OUT       20
/**@}*/

/**@}*/
