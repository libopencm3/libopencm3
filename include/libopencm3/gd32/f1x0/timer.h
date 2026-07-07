/** @defgroup timer_defines TIMER Defines
 *
 * @brief <b>Defined Constants and Types for the GD32F1x0 Timer</b>
 *
 * @ingroup GD32F1x0_defines
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

#ifndef LIBOPENCM3_TIMER_H
#define LIBOPENCM3_TIMER_H

/* GD32F1x0 timers are register-compatible with STM32F0 / STM32F1 advanced
 * and general-purpose timers. Empirically validated by regtrace v0.1
 * (decisions/v0.1/TIMER.md): TIM1 final-state register-write trace matches
 * stm32/f0 across the canonical center-aligned PWM init pattern.
 */
#include <libopencm3/stm32/common/timer_common_all.h>
#include <libopencm3/stm32/common/timer_common_f24.h>

#endif
