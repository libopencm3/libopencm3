/** @defgroup dmamux_defines DMAMUX Defines
 *
 * @ingroup STM32G0xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Guillaume Revaillot <g.revaillot@gmail.com>
 *
 * @brief Defined Constants and Types for the STM32G0xx DMAMUX DMA request router
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_DMAMUX_H
#define LIBOPENCM3_DMAMUX_H
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
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_EVT0      16
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_EVT1      17
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_EVT2      18
#define DMAMUX_CxCR_SYNC_ID_DMAMUX_EVT3      19
#define DMAMUX_CxCR_SYNC_ID_LPTIM1_OUT       20
#define DMAMUX_CxCR_SYNC_ID_LPTIM2_OUT       21
#define DMAMUX_CxCR_SYNC_ID_TIM14_OC         22
#define DMAMUX_CxCR_SYNC_ID_RESERVED23       23
/**@}*/

/** @defgroup dmamux_cxcr_dmareq_id DMAREQID DMA request line selected
@{*/
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN0  1
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN1  2
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN2  3
#define DMAMUX_CxCR_DMAREQ_ID_DMAMUX_REQ_GEN3  4
#define DMAMUX_CxCR_DMAREQ_ID_ADC              5
#define DMAMUX_CxCR_DMAREQ_ID_AES_IN           6
#define DMAMUX_CxCR_DMAREQ_ID_AES_OUT          7
#define DMAMUX_CxCR_DMAREQ_ID_DAC_Channel1     8
#define DMAMUX_CxCR_DMAREQ_ID_DAC_Channel2     9
#define DMAMUX_CxCR_DMAREQ_ID_I2C1_RX          10
#define DMAMUX_CxCR_DMAREQ_ID_I2C1_TX          11
#define DMAMUX_CxCR_DMAREQ_ID_I2C2_RX          12
#define DMAMUX_CxCR_DMAREQ_ID_I2C2_TX          13
#define DMAMUX_CxCR_DMAREQ_ID_LPUART_RX        14
#define DMAMUX_CxCR_DMAREQ_ID_LPUART_TX        15
#define DMAMUX_CxCR_DMAREQ_ID_SPI1_RX          16
#define DMAMUX_CxCR_DMAREQ_ID_SPI1_TX          17
#define DMAMUX_CxCR_DMAREQ_ID_SPI2_RX          18
#define DMAMUX_CxCR_DMAREQ_ID_SPI2_TX          19
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH1         20
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH2         21
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH3         22
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_CH4         23
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_TRIG_COM    24
#define DMAMUX_CxCR_DMAREQ_ID_TIM1_UP          25
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH1         26
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH2         27
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH3         28
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_CH4         29
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_TRIG        30
#define DMAMUX_CxCR_DMAREQ_ID_TIM2_UP          31
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH1         32
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH2         33
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH3         34
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_CH4         35
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_TRIG        36
#define DMAMUX_CxCR_DMAREQ_ID_TIM3_UP          37
#define DMAMUX_CxCR_DMAREQ_ID_TIM6_UP          38
#define DMAMUX_CxCR_DMAREQ_ID_TIM7_UP          39
#define DMAMUX_CxCR_DMAREQ_ID_TIM15_CH1        40
#define DMAMUX_CxCR_DMAREQ_ID_TIM15_CH2        41
#define DMAMUX_CxCR_DMAREQ_ID_TIM15_TRIG_COM   42
#define DMAMUX_CxCR_DMAREQ_ID_TIM15_UP         43
#define DMAMUX_CxCR_DMAREQ_ID_TIM16_CH1        44
#define DMAMUX_CxCR_DMAREQ_ID_TIM16_TRIG_COM   45
#define DMAMUX_CxCR_DMAREQ_ID_TIM16_UP         46
#define DMAMUX_CxCR_DMAREQ_ID_TIM17_CH1        47
#define DMAMUX_CxCR_DMAREQ_ID_TIM17_TRIG_COM   48
#define DMAMUX_CxCR_DMAREQ_ID_TIM17_UP         49
#define DMAMUX_CxCR_DMAREQ_ID_USART1_RX        50
#define DMAMUX_CxCR_DMAREQ_ID_USART1_TX        51
#define DMAMUX_CxCR_DMAREQ_ID_USART2_RX        52
#define DMAMUX_CxCR_DMAREQ_ID_USART2_TX        53
#define DMAMUX_CxCR_DMAREQ_ID_USART3_RX        54
#define DMAMUX_CxCR_DMAREQ_ID_USART3_TX        55
#define DMAMUX_CxCR_DMAREQ_ID_USART4_RX        56
#define DMAMUX_CxCR_DMAREQ_ID_USART4_TX        57
#define DMAMUX_CxCR_DMAREQ_ID_UCPD1_RX         58
#define DMAMUX_CxCR_DMAREQ_ID_UCPD1_TX         59
#define DMAMUX_CxCR_DMAREQ_ID_UCPD2_RX         60
#define DMAMUX_CxCR_DMAREQ_ID_UCPD2_TX         61
#define DMAMUX_CxCR_DMAREQ_ID_RESERVED62       62
#define DMAMUX_CxCR_DMAREQ_ID_RESERVED63       63
/**@}*/

/* --- DMAMUX_RGxCR values ----------------------------------- */

/** @defgroup dmamux_rgxcr_sig_id SIGID DMA request trigger input selected
@{*/
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE0       0
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE1       1
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE2       2
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE3       3
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE4       4
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE5       5
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE6       6
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE7       7
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE8       8
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE9       9
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE10      10
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE11      11
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE12      12
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE13      13
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE14      14
#define DMAMUX_RGxCR_SIG_ID_EXTI_LINE15      15
#define DMAMUX_RGxCR_SIG_ID_DMAMUX_EVT0      16
#define DMAMUX_RGxCR_SIG_ID_DMAMUX_EVT1      17
#define DMAMUX_RGxCR_SIG_ID_DMAMUX_EVT2      18
#define DMAMUX_RGxCR_SIG_ID_DMAMUX_EVT3      19
#define DMAMUX_RGxCR_SIG_ID_LPTIM1_OUT       20
#define DMAMUX_RGxCR_SIG_ID_LPTIM2_OUT       21
#define DMAMUX_RGxCR_SIG_ID_TIM14_OC         22
#define DMAMUX_RGxCR_SIG_ID_RESERVED         23
/**@}*/

/**@}*/
#endif
