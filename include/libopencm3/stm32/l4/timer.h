/** @defgroup timer_defines TIMER defines
 *
 * @brief <b>Defined Constants and Types for the STM32L4xx Timers
 * </b>
 *
 * @ingroup STM32L4xx_defines
 *
 *
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Fergus Noble <fergusnoble@gmail.com>
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Benjamin Levine <benjaminmileslevine@gmail.com>
 *
 * @version 1.0.0
 *
 * @date 19 February 2016
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Copyright (C) 2016 Benjamin Levine <benjaminmileslevine@gmail.com>
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

/**@{*/
#ifndef LIBOPENCM3_TIMER_H
#define LIBOPENCM3_TIMER_H

#include <libopencm3/stm32/common/timer_common_all.h>

/*
 * TIM2 and TIM5 are now 32bit and the following registers are now 32-bit wide:
 * CNT, ARR, CCR1, CCR2, CCR3, CCR4
 */

/* Timer 2/5 option register (TIMx_OR) */
#define TIM_OR1(tim_base)	MMIO32((tim_base) + 0x50)
#define TIM1_OR1			TIM_OR(TIM1)
#define TIM8_OR1			TIM_OR(TIM8)

#define TIM_OR2(tim_base)	MMIO32((tim_base) + 0x60)
#define TIM1_OR2			TIM_OR(TIM1)
#define TIM8_OR2			TIM_OR(TIM8)

#define TIM_OR3(tim_base)	MMIO32((tim_base) + 0x64)
#define TIM1_OR3			TIM_OR(TIM1)
#define TIM8_OR3			TIM_OR(TIM8)

/* Capture/compare mode register 3 (TIMx_CCMR3) */
#define TIM_CCMR3(tim_base)	MMIO32((tim_base) + 0x54)
#define TIM1_CCMR3			TIM_CCMR3(TIM1)
#define TIM2_CCMR3			TIM_CCMR3(TIM2)
#define TIM3_CCMR3			TIM_CCMR3(TIM3)
#define TIM4_CCMR3			TIM_CCMR3(TIM4)
#define TIM5_CCMR3			TIM_CCMR3(TIM5)
#define TIM8_CCMR3			TIM_CCMR3(TIM8)

/* Capture/compare register 5 (TIMx_CCR5) */
#define TIM_CCR5(tim_base)	MMIO32((tim_base) + 0x58)
#define TIM1_CCR5			TIM_CCR5(TIM1)
#define TIM2_CCR5			TIM_CCR5(TIM2)
#define TIM3_CCR5			TIM_CCR5(TIM3)
#define TIM4_CCR5			TIM_CCR5(TIM4)
#define TIM5_CCR5			TIM_CCR5(TIM5)
#define TIM8_CCR5			TIM_CCR5(TIM8)

/* Capture/compare register 6 (TIMx_CCR6) */
#define TIM_CCR6(tim_base)	MMIO32((tim_base) + 0x5C)
#define TIM1_CCR6			TIM_CCR6(TIM1)
#define TIM2_CCR6			TIM_CCR6(TIM2)
#define TIM3_CCR6			TIM_CCR6(TIM3)
#define TIM4_CCR6			TIM_CCR6(TIM4)
#define TIM5_CCR6			TIM_CCR6(TIM5)
#define TIM8_CCR6			TIM_CCR6(TIM8)

/* --- TIM1_OR1 and TIM8_OR1 values ----------------------------------------- */

#define TIM_OR1_TI1_RMP     (1 << 4)

#define TIM_OR1_ETR_ADC3_RMP_SHIFT     2
#define TIM_OR1_ETR_ADC3_RMP_MASK    0x3

/* --- TIM1_OR1 values ---------------------------------------------------- */

#define TIM1_OR1_ETR_ADC1_RMP_SHIFT     0
#define TIM1_OR1_ETR_ADC1_RMP_MASK    0x3

/* --- TIM8_OR1 values ---------------------------------------------------- */

#define TIM8_OR1_ETR_ADC2_RMP_SHIFT     0
#define TIM8_OR1_ETR_ADC2_RMP_MASK    0x3

/* --- TIM1_OR2 and TIM8_OR2 values --------------------------------------- */

#define TIM_OR2_ETRSEL_SHIFT     14
#define TIM_OR2_ETRSEL_MASK     0x7

#define TIM_OR2_BKCMP2P     (1 << 11)
#define TIM_OR2_BKCMP1P     (1 << 10)
#define TIM_OR2_BKINP       (1 << 9)
#define TIM_OR2_BKCMP2E     (1 << 2)
#define TIM_OR2_BKCMP1E     (1 << 1)
#define TIM_OR2_BKINE       (1 << 0)

/* --- TIM1_OR2 values ---------------------------------------------------- */

#define TIM1_OR2_BKDFBK0E    (1 << 8)

/* --- TIM8_OR2 values ---------------------------------------------------- */

#define TIM_OR2_BKDFBK2E    (1 << 8)

/* --- TIM1_OR3 and TIM8_OR3 values -------------------------------------- */

#define TIM_OR3_BK2CMP2P    (1 << 11)
#define TIM_OR3_BK2CMP1P    (1 << 10)
#define TIM_OR3_BK2INP      (1 << 9)
#define TIM_OR3_BK2CMP2E    (1 << 2)
#define TIM_OR3_BK2CMP1E    (1 << 1)
#define TIM_OR3_BK2INE      (1 << 0)

/* --- TIM1_OR3 values ---------------------------------------------------- */

#define TIM1_OR3_BK2DFBK1E  (1 << 8)

/* --- TIM8_OR3 values ---------------------------------------------------- */

#define TIM8_OR3_BK2DFBK3E  (1 << 8)

/* --- TIMx_CR1 values ---------------------------------------------------- */

#define TIM_CR1_UIFREMAP	(1 << 11)

/* --- TIMx_CR2 values ---------------------------------------------------- */

#define TIM_CR2_MMS2_SHIFT       20
#define TIM_CR2_MMS2_MASK        0xf

#define TIM_CR2_OIS6            (1 << 18)
#define TIM_CR2_OIS5            (1 << 16)

/* --- TIMx_CR3 values ---------------------------------------------------- */

#define TIM_CR3_OCCS            (1 << 3)
#define TIM_SMCR_SMS_BIT3		(1 << 16)
#define TIM_SMCR_SMS_BIT2		(1 << 2)
#define TIM_SMCR_SMS_BIT1		(1 << 1)
#define TIM_SMCR_SMS_BIT0		(1 << 0)

/* --- TIMx_SR values ---------------------------------------------------- */

#define TIM_SR_CBIF		    (1 << 13)
#define TIM_SR_CC5IF		(1 << 16)
#define TIM_SR_CC6IF		(1 << 17)

/* --- TIMx_SR values ---------------------------------------------------- */

#define TIM_EGR_B2G		    (1 << 8)

/* --- TIMx_CCMR1 values --------------------------------------------------- */

/* --- Output compare mode --- */
#define TIM_CCMR1_OC2M_BIT3     (1 << 24)
#define TIM_CCMR1_OC2M_BIT2     (1 << 14)
#define TIM_CCMR1_OC2M_BIT1     (1 << 13)
#define TIM_CCMR1_OC2M_BIT0     (1 << 12)

#define TIM_CCMR1_OC1M_BIT3     (1 << 16)
#define TIM_CCMR1_OC1M_BIT2     (1 << 6)
#define TIM_CCMR1_OC1M_BIT1     (1 << 5)
#define TIM_CCMR1_OC1M_BIT0     (1 << 4)

/* --- TIMx_CCMR2 values --------------------------------------------------- */

/* --- Output compare mode --- */
#define TIM_CCMR2_OC4M_BIT3     (1 << 24)
#define TIM_CCMR2_OC4M_BIT2     (1 << 14)
#define TIM_CCMR2_OC4M_BIT1     (1 << 13)
#define TIM_CCMR2_OC4M_BIT0     (1 << 12)

#define TIM_CCMR2_OC3M_BIT3     (1 << 16)
#define TIM_CCMR2_OC3M_BIT2     (1 << 6)
#define TIM_CCMR2_OC3M_BIT1     (1 << 5)
#define TIM_CCMR2_OC3M_BIT0     (1 << 4)

/* --- TIMx_CCER values ---------------------------------------------------- */

#define TIM_CCER_CC4NP			(1 << 15)
#define TIM_CCER_CC5E			(1 << 16)
#define TIM_CCER_CC5P			(1 << 17)
#define TIM_CCER_CC6E			(1 << 20)
#define TIM_CCER_CC6P			(1 << 21)

/* --- TIMx_CNT values ----------------------------------------------------- */

#define TIM_CNT_UIFCPY          (1 << 31)
#define TIM_CNT_CNT_SHIFT       0
#define TIM_CNT_CNT_MASK        0xffff

/* --- TIMx_BDTR values ---------------------------------------------------- */

#define TIM_BDTR_BK2P			(1 << 25)
#define TIM_BDTR_BK2E			(1 << 24)

#define TIM_BDTR_BK2F_SHIFT		20
#define TIM_BDTR_BK2F_MASK		0xf

#define TIM_BDTR_BKF_SHIFT		16
#define TIM_BDTR_BKF_MASK		0xf

/* --- TIMx_CCMR3 values --------------------------------------------------- */

#define TIM_CCMR3_OC6CE			(1 << 15)
#define TIM_CCMR3_OC6PE			(1 << 11)
#define TIM_CCMR3_OC6FE			(1 << 10)
#define TIM_CCMR3_OC5CE			(1 << 7)
#define TIM_CCMR3_OC5PE			(1 << 3)
#define TIM_CCMR3_OC5FE			(1 << 2)

#define TIM_CCMR3_OC6M_BIT3		(1 << 24)
#define TIM_CCMR3_OC6M_BIT2     (1 << 14)
#define TIM_CCMR3_OC6M_BIT1     (1 << 13)
#define TIM_CCMR3_OC6M_BIT0     (1 << 12)

#define TIM_CCMR1_OC6M_MASK     (TIM_CCMR3_OC6M_BIT0 | TIM_CCMR3_OC6M_BIT1 \
							| TIM_CCMR3_OC6M_BIT2 | TIM_CCMR3_OC6M_BIT3)

#define TIM_CCMR3_OC5M_BIT3		(1 << 16)
#define TIM_CCMR3_OC5M_BIT2     (1 << 6)
#define TIM_CCMR3_OC5M_BIT1     (1 << 5)
#define TIM_CCMR3_OC5M_BIT0     (1 << 4)

#define TIM_CCMR1_OC5M_MASK     (TIM_CCMR3_OC5M_BIT0 | TIM_CCMR3_OC5M_BIT1 \
							| TIM_CCMR3_OC5M_BIT2 | TIM_CCMR3_OC5M_BIT3)

/* --- TIMx_CCR5 values ---------------------------------------------------- */

#define TIM_CCR5_GC5C3			(1 << 31)
#define TIM_CCR5_GC5C2			(1 << 30)
#define TIM_CCR5_GC5C1			(1 << 29)

#define TIM_CCR5_CCR5_SHIFT     0
#define TIM_CCR5_CCR5_MASK      0xffff

/* --- TIMx_CCR6 values ---------------------------------------------------- */

#define TIM_CCR5_CCR6_SHIFT     0
#define TIM_CCR5_CCR6_MASK      0xffff

/** Input Capture input polarity */
enum tim_ic_pol {
	TIM_IC_RISING,
	TIM_IC_FALLING,
	TIM_IC_BOTH,
};

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

END_DECLS

#endif
/**@}*/

