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
@returns Unsigned int32. Option flags TIM2: @ref tim2_opt_trigger_remap, TIM5: @ref tim5_opt_trigger_remap.
*/

void timer_set_option(u32 timer_peripheral, u32 option)
{
	if (timer_peripheral == TIM2) {
		TIM_OR(timer_peripheral) &= ~TIM2_OR_ITR1_RMP_MASK;
		TIM_OR(timer_peripheral) |= option;
	} else if (timer_peripheral == TIM5) {
		TIM_OR(timer_peripheral) &= ~TIM5_OR_TI4_RMP_MASK;
		TIM_OR(timer_peripheral) |= option;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Set Input Polarity

The timer channel must be set to input capture mode.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] ic ::tim_ic_id. Input Capture channel designator.
@param[in] pol ::tim_ic_pol. Input Capture polarity control.
*/

void timer_ic_set_polarity(u32 timer_peripheral, enum tim_ic_id ic, enum tim_ic_pol pol)
{
/* Clear CCxP and CCxNP to zero. For both edge trigger both fields are set. Case 10 is invalid. */
    TIM_CCER(timer_peripheral) &= ~(0x6 << (ic * 4));
    switch (pol)
    {
    case    TIM_IC_RISING:  /* 00 */
        break;
    case    TIM_IC_BOTH:    /* 11 */
        TIM_CCER(timer_peripheral) |= (0x6 << (ic * 4));
        break;
    case 	TIM_IC_FALLING: /* 01 */
        TIM_CCER(timer_peripheral) |= (0x2 << (ic * 4));
    }
}
/**@}*/


