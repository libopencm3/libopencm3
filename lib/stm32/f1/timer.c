/** @defgroup timer_file TIMER peripheral API
@ingroup peripheral_apis
@brief <b>libopencm3 STM32F1xx Timers</b>

@version 1.0.0

@date 18 August 2012

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

#include <libopencm3/stm32/timer.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Set Input Polarity

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] ic ::tim_ic_id. Input Capture channel designator.
@param[in] pol ::tim_ic_pol. Input Capture polarity.
*/

void timer_ic_set_polarity(uint32_t timer_peripheral, enum tim_ic_id ic,
			   enum tim_ic_pol pol)
{
	if (pol) {
		TIM_CCER(timer_peripheral) |= (0x2 << (ic * 4));
	} else {
		TIM_CCER(timer_peripheral) &= ~(0x2 << (ic * 4));
	}
}

/**@}*/