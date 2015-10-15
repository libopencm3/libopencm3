/** @defgroup timer_defines Timer Defines

@brief <b>libopencm3 Defined Constants and Types for the STM32L0xx Timers</b>

@ingroup STM32L0xx_defines

@version 1.0.0

@date 17 May 2015

@author @htmlonly &copy; @endhtmlonly 2015 Robin Kreis <r.kreis@uni-bremen.de>

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Robin Kreis <r.kreis@uni-bremen.de>
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

#ifndef LIBOPENCM3_TIMER_H
#define LIBOPENCM3_TIMER_H

#include <libopencm3/stm32/common/timer_common_all.h>

/* Timer 2/21/22 option register (TIMx_OR) */

#define TIM_OR(tim_base)		MMIO32((tim_base) + 0x50)
#define TIM2_OR				TIM_OR(TIM2)
#define TIM21_OR			TIM_OR(TIM21)
#define TIM22_OR			TIM_OR(TIM22)

#define TIM2_OR_ETR_RMP_SHIFT		0
#define TIM2_OR_ETR_RMP			(7 << TIM2_OR_ETR_RMP_SHIFT)
#define TIM2_OR_ETR_RMP_GPIO		(0 << TIM2_OR_ETR_RMP_SHIFT)
#define TIM2_OR_ETR_RMP_HSI48		(4 << TIM2_OR_ETR_RMP_SHIFT)
#define TIM2_OR_ETR_RMP_LSE		(5 << TIM2_OR_ETR_RMP_SHIFT)
#define TIM2_OR_ETR_RMP_COMP2_OUT	(6 << TIM2_OR_ETR_RMP_SHIFT)
#define TIM2_OR_ETR_RMP_COMP1_OUT	(7 << TIM2_OR_ETR_RMP_SHIFT)

#define TIM2_OR_TI4_RMP_SHIFT		3
#define TIM2_OR_TI4_RMP			(3 << TIM2_OR_TI4_RMP_SHIFT)
#define TIM2_OR_TI4_RMP_GPIO		(0 << TIM2_OR_TI4_RMP_GPIO)
#define TIM2_OR_TI4_RMP_COMP2_OUT	(1 << TIM2_OR_TI4_RMP_GPIO)
#define TIM2_OR_TI4_RMP_COMP1_OUT	(2 << TIM2_OR_TI4_RMP_GPIO)

#define TIM21_OR_ETR_RMP_SHIFT		0
#define TIM21_OR_ETR_RMP		(3 << TIM21_OR_ETR_RMP_SHIFT)
#define TIM21_OR_ETR_RMP_GPIO		(0 << TIM21_OR_ETR_RMP_SHIFT)
#define TIM21_OR_ETR_RMP_COMP2_OUT	(1 << TIM21_OR_ETR_RMP_SHIFT)
#define TIM21_OR_ETR_RMP_COMP1_OUT	(2 << TIM21_OR_ETR_RMP_SHIFT)
#define TIM21_OR_ETR_RMP_LSE		(3 << TIM21_OR_ETR_RMP_SHIFT)

#define TIM21_OR_TI1_RMP_SHIFT		2
#define TIM21_OR_TI1_RMP		(7 << TIM21_OR_TI1_RMP_SHIFT)
#define TIM21_OR_TI1_RMP_GPIO		(0 << TIM21_OR_TI1_RMP_SHIFT)
#define TIM21_OR_TI1_RMP_RTC_WAKEUP	(1 << TIM21_OR_TI1_RMP_SHIFT)
#define TIM21_OR_TI1_RMP_HSE_RTC	(2 << TIM21_OR_TI1_RMP_SHIFT)
#define TIM21_OR_TI1_RMP_MSI		(3 << TIM21_OR_TI1_RMP_SHIFT)
#define TIM21_OR_TI1_RMP_LSE		(4 << TIM21_OR_TI1_RMP_SHIFT)
#define TIM21_OR_TI1_RMP_LSI		(5 << TIM21_OR_TI1_RMP_SHIFT)
#define TIM21_OR_TI1_RMP_COMP1_OUT	(6 << TIM21_OR_TI1_RMP_SHIFT)
#define TIM21_OR_TI1_RMP_MCO		(7 << TIM21_OR_TI1_RMP_SHIFT)

#define TIM21_OR_TI2_RMP_SHIFT		5
#define TIM21_OR_TI2_RMP		(1 << TIM21_OR_TI2_RMP_SHIFT)
#define TIM21_OR_TI2_RMP_GPIO		(0 << TIM21_OR_TI2_RMP_SHIFT)
#define TIM21_OR_TI2_RMP_COMP2_OUT	(1 << TIM21_OR_TI2_RMP_SHIFT)

#define TIM22_OR_ETR_RMP_SHIFT		0
#define TIM22_OR_ETR_RMP		(3 << TIM22_OR_ETR_RMP_SHIFT)
#define TIM22_OR_ETR_GPIO		(0 << TIM22_OR_ETR_RMP_SHIFT)
#define TIM22_OR_ETR_COMP2_OUT		(1 << TIM22_OR_ETR_RMP_SHIFT)
#define TIM22_OR_ETR_COMP1_OUT		(2 << TIM22_OR_ETR_RMP_SHIFT)
#define TIM22_OR_ETR_LSE		(3 << TIM22_OR_ETR_RMP_SHIFT)

#define TIM22_OR_TI1_RMP_SHIFT		2
#define TIM22_OR_TI1_RMP		(3 << TIM22_OR_TI1_RMP_SHIFT)
#define TIM22_OR_TI1_RMP_GPIO		(0 << TIM22_OR_TI1_RMP_SHIFT)
#define TIM22_OR_TI1_RMP_COMP2_OUT	(1 << TIM22_OR_TI1_RMP_SHIFT)
#define TIM22_OR_TI1_RMP_COMP1_OUT	(2 << TIM22_OR_TI1_RMP_SHIFT)

/* --- LPTIM (low power timer) ------------------------------------------- */

#define LPTIM_ISR(tim_base)		MMIO32((tim_base) + 0x00)
#define LPTIM_ICR(tim_base)		MMIO32((tim_base) + 0x04)
#define LPTIM_IER(tim_base)		MMIO32((tim_base) + 0x08)
#define LPTIM_CFGR(tim_base)		MMIO32((tim_base) + 0x0C)
#define LPTIM_CR(tim_base)		MMIO32((tim_base) + 0x10)
#define LPTIM_CMP(tim_base)		MMIO32((tim_base) + 0x14)
#define LPTIM_ARR(tim_base)		MMIO32((tim_base) + 0x18)
#define LPTIM_CNT(tim_base)		MMIO32((tim_base) + 0x1C)

#define LPTIM1_ISR			LPTIM_ISR(LPTIM1_BASE)
#define LPTIM1_ICR			LPTIM_ICR(LPTIM1_BASE)
#define LPTIM1_IER			LPTIM_IER(LPTIM1_BASE)
#define LPTIM1_CFGR			LPTIM_CFGR(LPTIM1_BASE)
#define LPTIM1_CR			LPTIM_CR(LPTIM1_BASE)
#define LPTIM1_CMP			LPTIM_CMP(LPTIM1_BASE)
#define LPTIM1_ARR			LPTIM_ARR(LPTIM1_BASE)
#define LPTIM1_CNT			LPTIM_CNT(LPTIM1_BASE)

#define LPTIM_ISR_CMPM			(1 << 0)
#define LPTIM_ISR_ARRM			(1 << 1)
#define LPTIM_ISR_EXTTRIG		(1 << 2)
#define LPTIM_ISR_CMPOK			(1 << 3)
#define LPTIM_ISR_ARROK			(1 << 4)
#define LPTIM_ISR_UP			(1 << 5)
#define LPTIM_ISR_DOWN			(1 << 6)

#define LPTIM_ICR_CMPMCF		(1 << 0)
#define LPTIM_ICR_ARRMCF		(1 << 1)
#define LPTIM_ICR_EXTTRIGCF		(1 << 2)
#define LPTIM_ICR_CMPOKCF		(1 << 3)
#define LPTIM_ICR_ARROKCF		(1 << 4)
#define LPTIM_ICR_UPCF			(1 << 5)
#define LPTIM_ICR_DOWNCF		(1 << 6)

#define LPTIM_IER_CMPMIE		(1 << 0)
#define LPTIM_IER_ARRMIE		(1 << 1)
#define LPTIM_IER_EXTTRIGIE		(1 << 2)
#define LPTIM_IER_CMPOKIE		(1 << 3)
#define LPTIM_IER_ARROKIE		(1 << 4)
#define LPTIM_IER_UPIE			(1 << 5)
#define LPTIM_IER_DOWNIE		(1 << 6)

#define LPTIM_CFGR_CKSEL		(1 << 0)

#define LPTIM_CFGR_CKPOL_SHIFT		1
#define LPTIM_CFGR_CKPOL		(3 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_RISING		(0 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_FALLING	(1 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_BOTH		(2 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_ENC_1		(0 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_ENC_2		(1 << LPTIM_CFGR_CKPOL_SHIFT)
#define LPTIM_CFGR_CKPOL_ENC_3		(2 << LPTIM_CFGR_CKPOL_SHIFT)

#define LPTIM_CFGR_CKFLT_SHIFT		3
#define LPTIM_CFGR_CKFLT		(3 << LPTIM_CFGR_CKFLT_SHIFT)
#define LPTIM_CFGR_CKFLT_2		(1 << LPTIM_CFGR_CKFLT_SHIFT)
#define LPTIM_CFGR_CKFLT_4		(2 << LPTIM_CFGR_CKFLT_SHIFT)
#define LPTIM_CFGR_CKFLT_8		(3 << LPTIM_CFGR_CKFLT_SHIFT)

#define LPTIM_CFGR_TRGFLT_SHIFT		6
#define LPTIM_CFGR_TRGFLT		(3 << LPTIM_CFGR_TRGFLT_SHIFT)
#define LPTIM_CFGR_TRGFLT_2		(1 << LPTIM_CFGR_TRGFLT_SHIFT)
#define LPTIM_CFGR_TRGFLT_4		(2 << LPTIM_CFGR_TRGFLT_SHIFT)
#define LPTIM_CFGR_TRGFLT_8		(3 << LPTIM_CFGR_TRGFLT_SHIFT)

#define LPTIM_CFGR_PRESC_SHIFT		9
#define LPTIM_CFGR_PRESC		(7 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_1		(0 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_2		(1 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_4		(2 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_8		(3 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_16		(4 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_32		(5 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_64		(6 << LPTIM_CFGR_PRESC_SHIFT)
#define LPTIM_CFGR_PRESC_128		(7 << LPTIM_CFGR_PRESC_SHIFT)

#define LPTIM_CFGR_TRIGSEL_SHIFT	13
#define LPTIM_CFGR_TRIGSEL		(7 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG0	(0 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG1	(1 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG2	(2 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG3	(3 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG4	(4 << LPTIM_CFGR_TRIGSEL_SHIFT)
/* 5 is reserved */
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG6	(6 << LPTIM_CFGR_TRIGSEL_SHIFT)
#define LPTIM_CFGR_TRIGSEL_EXT_TRIG7	(7 << LPTIM_CFGR_TRIGSEL_SHIFT)

#define LPTIM_CFGR_TRIGEN_SHIFT		17
#define LPTIM_CFGR_TRIGEN		(3 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_SW		(0 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_RISING	(1 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_FALLING	(2 << LPTIM_CFGR_TRIGEN_SHIFT)
#define LPTIM_CFGR_TRIGEN_BOTH		(3 << LPTIM_CFGR_TRIGEN_SHIFT)

#define LPTIM_CFGR_TIMOUT		(1 << 19)

#define LPTIM_CFGR_WAVE			(1 << 20)

#define LPTIM_CFGR_WAVPOL		(1 << 21)

#define LPTIM_CFGR_PRELOAD		(1 << 22)

#define LPTIM_CFGR_COUNTMODE		(1 << 23)

#define LPTIM_CFGR_ENC			(1 << 24)

#define LPTIM_CR_ENABLE			(1 << 0)

#define LPTIM_CR_SNGSTRT		(1 << 1)

#define LPTIM_CR_CNTSTRT		(1 << 2)

#endif
