/** @defgroup timer_defines Timer Defines

@brief <b>libopencm3 Defined Constants and Types for the STM32L1xx Timers</b>

@ingroup STM32L1xx_defines

@version 1.0.0

@date 8 March 2013

@author @htmlonly &copy; @endhtmlonly 2011 Fergus Noble <fergusnoble@gmail.com>

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

/*
 * TIM2 and TIM5 are now 32bit and the following registers are now 32-bit wide:
 * CNT, ARR, CCR1, CCR2, CCR3, CCR4
 */

/* Timer 2/3 option register (TIMx_OR) */
#define TIM_OR(tim_base)		MMIO32(tim_base + 0x50)
#define TIM2_OR				TIM_OR(TIM2)
#define TIM3_OR				TIM_OR(TIM3)

/* --- TIMx_OR values ---------------------------------------------------- */

/* ITR1_RMP */
/****************************************************************************/
/** @defgroup tim2_opt_trigger_remap TIM2_OR Timer 2 Option Register Internal
Trigger 1 Remap
@ingroup timer_defines

@{*/
/** Internal Trigger 1 remapped to timer 10 output compare */
#define TIM2_OR_ITR1_RMP_TIM10_OC	(0x0 << 0)
/** Internal Trigger 1 remapped to timer 5 TGO */
#define TIM2_OR_ITR1_RMP_TIM5_TGO	(0x1 << 0)
/**@}*/
#define TIM3_OR_ITR1_RMP_MASK		(0x1 << 0)

/* --- TIMx_OR values ---------------------------------------------------- */

/* ITR2_RMP */
/****************************************************************************/
/** @defgroup tim3_opt_trigger_remap TIM3_OR Timer 3 Option Register Internal Trigger 2 Remap
@ingroup timer_defines

@{*/
/** Internal Trigger 1 remapped to timer 11 output compare */
#define TIM3_OR_ITR2_RMP_TIM8_TRGOU	(0x0 << 0)
/** Internal Trigger 1 remapped to timer 5 TGO */
#define TIM3_OR_ITR2_RMP_PTP		(0x1 << 0)
/**@}*/
#define TIM3_OR_ITR2_RMP_MASK		(0x1 << 0)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void timer_set_option(uint32_t timer_peripheral, uint32_t option);

END_DECLS

#endif
