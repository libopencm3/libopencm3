/** @defgroup timer_defines Timer Defines

@brief <b>libopencm3 Defined Constants and Types for the STM32U5xx Timers</b>

@ingroup STM32U5xx_defines

@version 1.0.0

@date 20 October 2024

@author @htmlonly &copy; @endhtmlonly 2015 Karl Palsson <karlp@tweak.net.au>

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/stm32/common/timer_common_all.h>

/* Timer input selection register (TIMx_TISEL) */
#define TIM_TISEL(tim_base) MMIO32((tim_base) + 0x5cU)
#define TIM2_TISEL          TIM_TISEL(TIM2)
#define TIM3_TISEL          TIM_TISEL(TIM3)
#define TIM4_TISEL          TIM_TISEL(TIM4)
#define TIM5_TISEL          TIM_TISEL(TIM5)

/* --- TIMx_TISEL values --------------------------------------------------- */
#define TIM_TISEL_TI1SEL_MASK  (0xfU << 0U)
#define TIM_TISEL_TI1SEL_SHIFT 0U
#define TIM_TISEL_TI2SEL_MASK  (0xfU << 8U)
#define TIM_TISEL_TI2SEL_SHIFT 8U
#define TIM_TISEL_TI3SEL_MASK  (0xfU << 16U)
#define TIM_TISEL_TI3SEL_SHIFT 16U
#define TIM_TISEL_TI4SEL_MASK  (0xfU << 24U)
#define TIM_TISEL_TI4SEL_SHIFT 24U

/** Input Capture input polarity */
typedef enum tim_ic_pol {
	TIM_IC_RISING,
	TIM_IC_FALLING,
} tim_ic_pol_e;

/** Input Capture input selection */
typedef enum tim_ic_sel {
	TIM_IC_SEL_IN0,
	TIM_IC_SEL_IN1,
	TIM_IC_SEL_IN2,
	TIM_IC_SEL_IN3,
	TIM_IC_SEL_IN4,
	TIM_IC_SEL_IN5,
	TIM_IC_SEL_IN6,
	TIM_IC_SEL_IN7,
	TIM_IC_SEL_IN8,
	TIM_IC_SEL_IN9,
	TIM_IC_SEL_IN10,
	TIM_IC_SEL_IN11,
	TIM_IC_SEL_IN12,
	TIM_IC_SEL_IN13,
	TIM_IC_SEL_IN14,
	TIM_IC_SEL_IN15,
} tim_ic_sel_e;

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void timer_ic_set_polarity(uintptr_t timer, tim_ic_id_e ic, tim_ic_pol_e pol);
void timer_ic_input_selection(uintptr_t timer, tim_ic_id_e ic, tim_ic_sel_e sel);

END_DECLS
