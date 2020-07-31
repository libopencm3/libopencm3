/** @defgroup timer_defines Timer Defines
 *
 * @ingroup STM32G0xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32G0xx Timers</b>
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Guillaume Revaillot <g.revaillot@gmail.com>
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

/**@{*/

/* Option Register (TIMx_OR1) */
#define TIM_OR1(tim_base)		MMIO32((tim_base) + 0x50)
#define TIM2_OR1			TIM_OR1(TIM2)
#define TIM3_OR1			TIM_OR1(TIM3)

/* Alternate Function (TIMx_AF1) */
#define TIM_AF1(tim_base)		MMIO32((tim_base) + 0x60)
#define TIM2_AF1			TIM_AF1(TIM2)
#define TIM3_AF1			TIM_AF1(TIM3)
#define TIM16_AF1			TIM_AF1(TIM16)
#define TIM17_AF1			TIM_AF1(TIM17)

/* Input Selection Register (TIMx_TISEL) */
#define TIM_TISEL(tim_base)		MMIO32((tim_base) + 0x68)
#define TIM2_TISEL			TIM_TISEL(TIM2)
#define TIM3_TISEL			TIM_TISEL(TIM3)
#define TIM14_TISEL			TIM_TISEL(TIM14)
#define TIM16_TISEL			TIM_TISEL(TIM16)
#define TIM17_TISEL			TIM_TISEL(TIM17)

/* --- TIMx_OR1 values ---------------------------------------------------- */

/* OCREF_CLR: ocref_clr Source Selection */
#define TIM_OR1_OCREF_CLR			(1 << 0)

/** @defgroup tim_or1_ocref_clr TIM_OR1_OCREF_CLR Source Selection
@{*/
#define TIM_OR1_OCREF_CLR_COMP1			(0)
#define TIM_OR1_OCREF_CLR_COMP2			(1)
/**@}*/

BEGIN_DECLS

END_DECLS

/**@}*/

#endif
