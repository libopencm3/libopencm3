/** @addtogroup timer_file

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Edward Cheeseman <evbuilder@users.sourceforge.org>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
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

#include <libopencm3/stm32/timer.h>

/*---------------------------------------------------------------------------*/
/** @brief Set Timer Option

Set timer options register on TIM2 or TIM5, used for trigger remapping on TIM2,
and similarly for TIM5 for oscillator calibration purposes.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param option flags TIM2 @ref tim2_opt_trigger_remap or TIM5 @ref tim5_opt_trigger_remap
*/

void timer_set_option(uint32_t timer_peripheral, uint32_t option)
{
	if (timer_peripheral == TIM2) {
		TIM_OR(timer_peripheral) &= ~TIM2_OR_ITR1_RMP_MASK;
		TIM_OR(timer_peripheral) |= option;
	} else if (timer_peripheral == TIM5) {
		TIM_OR(timer_peripheral) &= ~TIM5_OR_TI4_RMP_MASK;
		TIM_OR(timer_peripheral) |= option;
	}
}

/**@}*/


