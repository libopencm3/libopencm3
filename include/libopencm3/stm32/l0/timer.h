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

/**@{*/

/** Timer 2/21/22 option register (TIMx_OR) */

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

/**@}*/

#endif

/**@}*/
