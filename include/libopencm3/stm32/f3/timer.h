/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Modified by 2013 Fernando Cortes <fernando.corcam@gmail.com>
 * Modified by 2013 Guillermo Rivera <memogrg@gmail.com>
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

#ifndef LIBOPENCM3_TIMER_F3_H
#define LIBOPENCM3_TIMER_F3_H

#include <libopencm3/stm32/timer.h>

/* --- Convenience macros -------------------------------------------------- */

/* Timer register base adresses (for convenience) */
/****************************************************************************/
/** @defgroup tim_reg_base Timer register base addresses
@ingroup STM32F_tim_defines

@{*/
#define TIM15				TIM15_BASE
#define TIM16				TIM16_BASE
#define TIM17				TIM17_BASE

/**@}*/

/* --- Timer registers ----------------------------------------------------- */

/* Control register 1 (TIMx_CR1) */
#define TIM15_CR1			TIM_CR1(TIM15)
#define TIM16_CR1			TIM_CR1(TIM16)
#define TIM17_CR1			TIM_CR1(TIM17)


/* Control register 2 (TIMx_CR2) */
#define TIM15_CR2			TIM_CR2(TIM15)
#define TIM16_CR2			TIM_CR2(TIM16)
#define TIM17_CR2			TIM_CR2(TIM17)


/* Slave mode control register (TIMx_SMCR) */
#define TIM15_SMCR			TIM_SMCR(TIM15)


/* DMA/Interrupt enable register (TIMx_DIER) */
#define TIM15_DIER			TIM_DIER(TIM15)
#define TIM16_DIER			TIM_DIER(TIM16)
#define TIM17_DIER			TIM_DIER(TIM17)


/* Status register (TIMx_SR) */
#define TIM15_SR			TIM_SR(TIM15)
#define TIM16_SR			TIM_SR(TIM16)
#define TIM17_SR			TIM_SR(TIM17)


/* Event generation register (TIMx_EGR) */
#define TIM15_EGR			TIM_EGR(TIM15)
#define TIM16_EGR			TIM_EGR(TIM16)
#define TIM17_EGR			TIM_EGR(TIM17)


/* Capture/compare mode register 1 (TIMx_CCMR1) */
#define TIM15_CCMR1			TIM_CCMR1(TIM15)
#define TIM16_CCMR1			TIM_CCMR1(TIM16)
#define TIM17_CCMR1			TIM_CCMR1(TIM17)

/* Capture/compare enable register (TIMx_CCER) */
#define TIM15_CCER			TIM_CCER(TIM15)
#define TIM16_CCER			TIM_CCER(TIM16)
#define TIM17_CCER			TIM_CCER(TIM17)

/* Counter (TIMx_CNT) */
#define TIM15_CNT			TIM_CNT(TIM15)
#define TIM16_CNT			TIM_CNT(TIM16)
#define TIM17_CNT			TIM_CNT(TIM17)


/* Prescaler (TIMx_PSC) */
#define TIM15_PSC			TIM_PSC(TIM15)
#define TIM16_PSC			TIM_PSC(TIM16)
#define TIM17_PSC			TIM_PSC(TIM17)


/* Auto-reload register (TIMx_ARR) */
#define TIM15_ARR			TIM_ARR(TIM15)
#define TIM16_ARR			TIM_ARR(TIM16)
#define TIM17_ARR			TIM_ARR(TIM17)


/* Repetition counter register (TIMx_RCR) */
#define TIM15_RCR			TIM_RCR(TIM15)
#define TIM16_RCR			TIM_RCR(TIM16)
#define TIM17_RCR			TIM_RCR(TIM17)


/* Capture/compare register 1 (TIMx_CCR1) */
#define TIM15_CCR1			TIM_CCR1(TIM15)
#define TIM16_CCR1			TIM_CCR1(TIM16)
#define TIM17_CCR1			TIM_CCR1(TIM17)


/* Capture/compare register 2 (TIMx_CCR2) */
#define TIM15_CCR2			TIM_CCR2(TIM15)

/* Break and dead-time register (TIMx_BDTR) */
#define TIM15_BDTR			TIM_BDTR(TIM15)
#define TIM16_BDTR			TIM_BDTR(TIM16)
#define TIM17_BDTR			TIM_BDTR(TIM17)

/* DMA control register (TIMx_DCR) */
#define TIM15_DCR			TIM_DCR(TIM15)
#define TIM16_DCR			TIM_DCR(TIM16)
#define TIM17_DCR			TIM_DCR(TIM17)


/* DMA address for full transfer (TIMx_DMAR) */
#define TIM15_DMAR			TIM_DMAR(TIM15)
#define TIM16_DMAR			TIM_DMAR(TIM16)
#define TIM17_DMAR			TIM_DMAR(TIM17)


/* capture/compare mode register 3 (TIMx_CCMR3) */
#define TIM_CCMR3(tim_base)		MMIO32(tim_base + 0x54)
#define TIM1_CCMR3			TIM_CCMR3(TIM1)
#define TIM8_CCMR3			TIM_CCMR3(TIM8)



/* capture/compare register 5 (TIMx_CCR5) */
#define TIM_CCR5(tim_base)		MMIO32(tim_base + 0x58)
#define TIM1_CCR5			TIM_CCR5(TIM1)
#define TIM8_CCR5			TIM_CCR5(TIM8)


/* capture/compare register 6 (TIMx_CCR6) */
#define TIM_CCR6(tim_base)		MMIO32(tim_base + 0x5C)
#define TIM1_CCR6			TIM_CCR6(TIM1)
#define TIM8_CCR6			TIM_CCR6(TIM8)


/* Timer 1/8/16 option register (TIMx_OR)  */
#define TIM_OR(tim_base)		MMIO32(tim_base + 0x60)
#define TIM1_OR				TIM_OR(TIM1)
#define TIM8_OR				TIM_OR(TIM8)
#define TIM16_OR			TIM_OR(TIM16)


/* --- TIMx_CR1 values ----------------------------------------------------- */

/* UIFREMAP: UIF status bit remapping */
#define TIM_CR1_UIFREMAP		(1 << 11)


/* --- TIMx_CR2 values ----------------------------------------------------- */

/* MMS2[3:0]: Master mode selection 2 */
/* TIMx_CR2 MMS2[23:20]: Master Mode Selection 2 */
#define TIM_CR2_MMS2_RESET		(0x0 << 20)
#define TIM_CR2_MMS2_ENABLE		(0x1 << 20)
#define TIM_CR2_MMS2_UPDATE		(0x2 << 20)
#define TIM_CR2_MMS2_COMPARE_PULSE	(0x3 << 20)
#define TIM_CR2_MMS2_COMPARE_OC1REF	(0x4 << 20)
#define TIM_CR2_MMS2_COMPARE_OC2REF	(0x5 << 20)
#define TIM_CR2_MMS2_COMPARE_OC3REF	(0x6 << 20)
#define TIM_CR2_MMS2_COMPARE_OC4REF	(0x7 << 20)
#define TIM_CR2_MMS2_COMPARE_OC5REF	(0x8 << 20)
#define TIM_CR2_MMS2_COMPARE_OC6REF	(0x9 << 20)
#define TIM_CR2_MMS2_COMPARE_PULSE_OC4REF	(0xA << 20)
#define TIM_CR2_MMS2_COMPARE_PULSE_OC6REF	(0xB << 20)
#define TIM_CR2_MMS2_COMPARE_PULSE_OC4REF_OC6REF_RISING	(0xC << 20)
#define TIM_CR2_MMS2_COMPARE_PULSE_OC4REF_RISING_OC6REF_FALLING	(0xD << 20)
#define TIM_CR2_MMS2_COMPARE_PULSE_OC5REF_OC6REF_RISING	(0xE << 20)
#define TIM_CR2_MMS2_COMPARE_PULSE_OC5REF_RISING_OC6REF_FALLING	(0xF << 20)

/* OIS6:*//** Output idle state 6 (OC6 output) */
#define TIM_CR2_OIS6			(1 << 18)

/* OIS5:*//** Output idle state 5 (OC5 output) */
#define TIM_CR2_OIS5			(1 << 16)


/* --- TIMx_SMCR values ---------------------------------------------------- */

/* SMS[3] Slave mode selection bit 3 */
#define TIM_SMCR_SMS_BIT3			(1 << 15)

/* OCCS: OCREF clear selection */
#define TIM_SMCR_OCCS			(1 << 3)


/* --- TIMx_SR values ------------------------------------------------------ */

/* C6IF:*//** Compare 6 interrupt flag */
#define TIM_SR_C6IF			(1 << 17)

/* C5IF:*//** Compare 5 interrupt flag */
#define TIM_SR_C5IF			(1 << 16)

/* B2IF:*//** Break 2 interrupt flag */
#define TIM_SR_B2IF			(1 << 8)


/* --- TIMx_EGR values ----------------------------------------------------- */

/* B2G: Break 2 generation */
#define TIM_EGR_B2G			(1 << 8)


/* --- TIMx_CCMR1 values --------------------------------------------------- */

/* --- Output compare mode --- */

/* OC2M[3]: Output Compare 2 mode - bit 3 */
#define TIM_CCMR1_OC2M_BIT3		(1 << 24)

/* OC1M[3]: Output Compare 1 mode - bit 3 */
#define TIM_CCMR1_OC1M_BIT3		(1 << 16)

/* OC1M[2:0]: Output compare 1 mode */
#define TIM_CCMR1_OC1M_FROZEN		(0x0 << 4)
#define TIM_CCMR1_OC1M_ACTIVE		(0x1 << 4)
#define TIM_CCMR1_OC1M_INACTIVE		(0x2 << 4)
#define TIM_CCMR1_OC1M_TOGGLE		(0x3 << 4)
#define TIM_CCMR1_OC1M_FORCE_LOW	(0x4 << 4)
#define TIM_CCMR1_OC1M_FORCE_HIGH	(0x5 << 4)
#define TIM_CCMR1_OC1M_PWM1		(0x6 << 4)
#define TIM_CCMR1_OC1M_PWM2		(0x7 << 4)
#define TIM_CCMR1_OC1M_MASK		(0x7 << 4)

/* CC2S[1:0]:  Capture/Compare 2 selection */
#define TIM_CCMR1_CC2S_OUT		(0x0 << 8)
#define TIM_CCMR1_CC2S_IN_TI2		(0x1 << 8)
#define TIM_CCMR1_CC2S_IN_TI1		(0x2 << 8)
#define TIM_CCMR1_CC2S_IN_TRC		(0x3 << 8)

/* --- TIMx_CCMR2 values --------------------------------------------------- */

/* --- Output compare mode --- */

/* OC4M[3]: Output Compare 4 mode - bit 3 */
#define TIM_CCMR2_OC4M_BIT3		(1 << 24)

/* OC3M[3]: Output Compare 3 mode - bit 3 */
#define TIM_CCMR2_OC3M_BIT3		(1 << 16)

/* --- Input capture mode --- */

/* CC4S[1:0] Capture/Compare 4 selection */
#define TIM_CC4S_OUT			(0x0 << 8)
#define TIM_CC4S_IN_TI4			(0x1 << 8)
#define TIM_CC4S_IN_TI3			(0x2 << 8)
#define TIM_CC4S_IN_TRC			(0x3 << 8)

/* CC3S[1:0] Capture/Compare 3 selection */
#define TIM_CC3S_OUT			(0x0 << 0)
#define TIM_CC3S_IN_TI4			(0x1 << 0)
#define TIM_CC3S_IN_TI3			(0x2 << 0)
#define TIM_CC3S_IN_TRC			(0x3 << 0)

/* --- TIMx_CCER values ---------------------------------------------------- */

/* CC6P: Capture/Compare 6 output polarity */
#define TIM_CCER_CC6P			(1 << 21)

/* CC6E: Capture/Compare 6 output enable */
#define TIM_CCER_CC6E			(1 << 20)

/* CC5P: Capture/Compare 5 output polarity */
#define TIM_CCER_CC5P			(1 << 17)

/* CC5E: Capture/Compare 5 output enable */
#define TIM_CCER_CC5E			(1 << 16)

/* CC4NP: Capture/Compare 4 complementary output polarity */
#define TIM_CCER_CC4NP			(1 << 15)

/* --- TIMx_CNT values ----------------------------------------------------- */

/* UIFCPY: UIF copy */
#define TIM_CNT_UIFCPY			(1 << 31)

/* --- TIMx_BDTR values ---------------------------------------------------- */

/*  BK2P: Break 2 polarity */
#define TIM_BDTR_BK2P			(1 << 25)

/*  BK2E: Break 2 enable */
#define TIM_BDTR_BK2E			(1 << 24)

/* BK2F[3:0]: Break 2 filter */
#define TIM_BDTR_BK2F_OFF		(0x0 << 20)
#define TIM_BDTR_BK2F_CK_INT_N_2	(0x1 << 20)
#define TIM_BDTR_BK2F_CK_INT_N_4	(0x2 << 20)
#define TIM_BDTR_BK2F_CK_INT_N_8	(0x3 << 20)
#define TIM_BDTR_BK2F_DTS_DIV_2_N_6	(0x4 << 20)
#define TIM_BDTR_BK2F_DTS_DIV_2_N_8	(0x5 << 20)
#define TIM_BDTR_BK2F_DTS_DIV_4_N_6	(0x6 << 20)
#define TIM_BDTR_BK2F_DTS_DIV_4_N_8	(0x7 << 20)
#define TIM_BDTR_BK2F_DTS_DIV_8_N_6	(0x8 << 20)
#define TIM_BDTR_BK2F_DTS_DIV_8_N_8	(0x9 << 20)
#define TIM_BDTR_BK2F_DTS_DIV_16_N_5	(0xA << 20)
#define TIM_BDTR_BK2F_DTS_DIV_16_N_6	(0xB << 20)
#define TIM_BDTR_BK2F_DTS_DIV_16_N_8	(0xC << 20)
#define TIM_BDTR_BK2F_DTS_DIV_32_N_5	(0xD << 20)
#define TIM_BDTR_BK2F_DTS_DIV_32_N_6	(0xE << 20)
#define TIM_BDTR_BK2F_DTS_DIV_32_N_8	(0xF << 20)

/* BKF[3:0]: Break filter */
#define TIM_BDTR_BKF_OFF		(0x0 << 16)
#define TIM_BDTR_BKF_CK_INT_N_2		(0x1 << 16)
#define TIM_BDTR_BKF_CK_INT_N_4		(0x2 << 16)
#define TIM_BDTR_BKF_CK_INT_N_8		(0x3 << 16)
#define TIM_BDTR_BKF_DTS_DIV_2_N_6	(0x4 << 16)
#define TIM_BDTR_BKF_DTS_DIV_2_N_8	(0x5 << 16)
#define TIM_BDTR_BKF_DTS_DIV_4_N_6	(0x6 << 16)
#define TIM_BDTR_BKF_DTS_DIV_4_N_8	(0x7 << 16)
#define TIM_BDTR_BKF_DTS_DIV_8_N_6	(0x8 << 16)
#define TIM_BDTR_BKF_DTS_DIV_8_N_8	(0x9 << 16)
#define TIM_BDTR_BKF_DTS_DIV_16_N_5	(0xA << 16)
#define TIM_BDTR_BKF_DTS_DIV_16_N_6	(0xB << 16)
#define TIM_BDTR_BKF_DTS_DIV_16_N_8	(0xC << 16)
#define TIM_BDTR_BKF_DTS_DIV_32_N_5	(0xD << 16)
#define TIM_BDTR_BKF_DTS_DIV_32_N_6	(0xE << 16)
#define TIM_BDTR_BKF_DTS_DIV_32_N_8	(0xF << 16)

/* --- TIMx_CCMR3 values ---------------------------------------------------- */

/* OC6M[3]: Output Compare 6 mode - bit 3 */
#define TIM_CCMR3_OC6M_BIT3		(1 << 24)

/* OC5M[3]: Output Compare 5 mode - bit 3 */
#define TIM_CCMR3_OC5M_BIT3		(1 << 16)

/* OC6CE: Output compare 6 clear enable */
#define TIM_CCMR3_OC6CE			(1 << 15)

/* OC6M[2:0]: Output compare 6 mode */

/* OC6PE: Output compare 6 preload enable */
#define TIM_CCMR3_OC6PE			(1 << 11)

/* OC6FE: Output compare 6 fast enable */
#define TIM_CCMR3_OC6FE			(1 << 10)

/* OC5CE: Output compare 5 clear enable */
#define TIM_CCMR3_OC5CE			(1 << 7)

/* OC5M[2:0]: Output compare 5 mode */

/* OC5PE: Output compare 5 preload enable */
#define TIM_CCMR3_OC5PE			(1 << 3)

/* OC5FE: Output compare 5 fast enable */
#define TIM_CCMR3_OC5FE			(1 << 2)

/* --- TIMx_CCR5 values ---------------------------------------------------- */

/* GC5C3: Group Channel 5 and Channel 3 */
#define TIM_CCR5_GC5C3			(1 << 31)

/* GC5C2: Group Channel 5 and Channel 2 */
#define TIM_CCR5_GC5C2			(1 << 30)

/* GC5C1: Group Channel 5 and Channel 1 */
#define TIM_CCR5_GC5C1			(1 << 29)

/* CCR5[15:0]: Capture/Compare 5 value */

/* --- TIMx_CCR6 values ---------------------------------------------------- */

/* CCR6[15:0]: Capture/Compare 6 value */

/* --- Timer 1/8 option register (TIMx_OR) values ---------------------------------------------------- */

/* TIM1_ETR_ADC4_RMP[1:0]: TIM1_ETR_ADC4 remapping capability */
#define TIM_OR_TIM1_ETR_ADC4_OFF	(0x0 << 2)
#define TIM_OR_TIM1_ETR_ADC4_AWD1	(0x1 << 2)
#define TIM_OR_TIM1_ETR_ADC4_AWD2	(0x2 << 2)
#define TIM_OR_TIM1_ETR_ADC4_AWD3	(0x3 << 2)

/* TIM8_ETR_ADC3_RMP[1:0]: TIM8_ETR_ADC3 remapping capability */
#define TIM_OR_TIM8_ETR_ADC3_OFF	(0x0 << 2)
#define TIM_OR_TIM8_ETR_ADC3_AWD1	(0x1 << 2)
#define TIM_OR_TIM8_ETR_ADC3_AWD2	(0x2 << 2)
#define TIM_OR_TIM8_ETR_ADC3_AWD3	(0x3 << 2)

/* TIM1_ETR_ADC1_RMP[1:0]: TIM1_ETR_ADC1 remapping capability */
#define TIM_OR_TIM1_ETR_ADC1_OFF	(0x0 << 0)
#define TIM_OR_TIM1_ETR_ADC1_AWD1	(0x1 << 0)
#define TIM_OR_TIM1_ETR_ADC1_AWD2	(0x2 << 0)
#define TIM_OR_TIM1_ETR_ADC1_AWD3	(0x3 << 0)

/* TIM8_ETR_ADC2_RMP[1:0]: TIM8_ETR_ADC2 remapping capability */
#define TIM_OR_TIM8_ETR_ADC2_OFF	(0x0 << 2)
#define TIM_OR_TIM8_ETR_ADC2_AWD1	(0x1 << 2)
#define TIM_OR_TIM8_ETR_ADC2_AWD2	(0x2 << 2)
#define TIM_OR_TIM8_ETR_ADC2_AWD3	(0x3 << 2)

/* --- TIM16_OR values ---------------------------------------------------- */

/* TI1_RMP: Timer 16 input 1 connection */
#define TIM16_OR_TI1_RMP_GPIO		(0x0 << 0) 
#define TIM16_OR_TI1_RMP_RTC_CLK	(0x1 << 0) 
#define TIM16_OR_TI1_RMP_HSE_32		(0x2 << 0) 
#define TIM16_OR_TI1_RMP_MCO		(0x3 << 0) 


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

//void timer_set_option(u32 timer_peripheral, u32 option);

END_DECLS

#endif
