/** @addtogroup timer_defines

@author @htmlonly &copy; @endhtmlonly 2011 Fergus Noble <fergusnoble@gmail.com>

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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA TIMER.H
The order of header inclusion is important. timer.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_TIMER_H
/** @endcond */
#ifndef LIBOPENCM3_TIMER_COMMON_F24_H
#define LIBOPENCM3_TIMER_COMMON_F24_H

#include <libopencm3/stm32/common/timer_common_all.h>

/*
 * TIM2 and TIM5 are now 32bit and the following registers are now 32-bit wide:
 * CNT, ARR, CCR1, CCR2, CCR3, CCR4
 */

/* Timer 2/5 option register (TIMx_OR) */
#define TIM_OR(tim_base)		MMIO32((tim_base) + 0x50)
#define TIM2_OR				TIM_OR(TIM2)
#define TIM5_OR				TIM_OR(TIM5)

/* --- TIM2_OR values ---------------------------------------------------- */

/* ITR1_RMP */
/****************************************************************************/
/** @defgroup tim2_opt_trigger_remap TIM2_OR Timer 2 Option Register Internal
Trigger 1 Remap

Only available in F2 and F4 series.
@ingroup timer_defines

@{*/
/** Internal Trigger 1 remapped to timer 8 trigger out */
#define TIM2_OR_ITR1_RMP_TIM8_TRGOU	(0x0 << 10)
/** Internal Trigger 1 remapped to PTP trigger out */
#define TIM2_OR_ITR1_RMP_PTP		(0x1 << 10)
/** Internal Trigger 1 remapped to USB OTG FS SOF */
#define TIM2_OR_ITR1_RMP_OTG_FS_SOF	(0x2 << 10)
/** Internal Trigger 1 remapped to USB OTG HS SOF */
#define TIM2_OR_ITR1_RMP_OTG_HS_SOF	(0x3 << 10)
/**@}*/
#define TIM2_OR_ITR1_RMP_MASK		(0x3 << 10)

/* --- TIM5_OR values ---------------------------------------------------- */

/* ITR4_RMP */
/****************************************************************************/
/** @defgroup tim5_opt_trigger_remap TIM5_OR Timer 5 Option Register Internal Trigger 4 Remap

Only available in F2 and F4 series.
@ingroup timer_defines

@{*/
/** Internal Trigger 4 remapped to GPIO (see reference manual) */
#define TIM5_OR_TI4_RMP_GPIO		(0x0 << 6)
/** Internal Trigger 4 remapped to LSI internal clock */
#define TIM5_OR_TI4_RMP_LSI		(0x1 << 6)
/** Internal Trigger 4 remapped to LSE internal clock */
#define TIM5_OR_TI4_RMP_LSE		(0x2 << 6)
/** Internal Trigger 4 remapped to RTC output event */
#define TIM5_OR_TI4_RMP_RTC		(0x3 << 6)
/**@}*/
#define TIM5_OR_TI4_RMP_MASK		(0x3 << 6)

/** Input Capture input polarity */
enum tim_ic_pol {
	TIM_IC_RISING,
	TIM_IC_FALLING,
	TIM_IC_BOTH,
};

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void timer_set_option(uint32_t timer_peripheral, uint32_t option);
void timer_ic_set_polarity(uint32_t timer, enum tim_ic_id ic,
			   enum tim_ic_pol pol);

END_DECLS

#endif
/** @cond */
#else
#warning "timer_common_f24.h should not be included directly, only via timer.h"
#endif
/** @endcond */

