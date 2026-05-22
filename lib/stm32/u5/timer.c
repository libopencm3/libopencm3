/** @defgroup timer_file TIMER peripheral API
@ingroup peripheral_apis
@brief <b>libopencm3 STM32U5xx Timers</b>

@version 1.0.0

@date 16 November 2025

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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

@param[in] timer Unsigned intptr. Timer register address base
@param[in] ic ::tim_ic_id. Input Capture channel designator.
@param[in] pol ::tim_ic_pol. Input Capture polarity.
*/

void timer_ic_set_polarity(const uintptr_t timer, const tim_ic_id_e ic, const tim_ic_pol_e pol)
{
	switch (ic) {
		case TIM_IC1:
			if (pol) {
				TIM_CCER(timer) |= TIM_CCER_CC1P;
			} else {
				TIM_CCER(timer) &= ~TIM_CCER_CC1P;
			}
			break;
		case TIM_IC2:
			if (pol) {
				TIM_CCER(timer) |= TIM_CCER_CC2P;
			} else {
				TIM_CCER(timer) &= ~TIM_CCER_CC2P;
			}
			break;
		case TIM_IC3:
			if (pol) {
				TIM_CCER(timer) |= TIM_CCER_CC3P;
			} else {
				TIM_CCER(timer) &= ~TIM_CCER_CC3P;
			}
			break;
		case TIM_IC4:
			if (pol) {
				TIM_CCER(timer) |= TIM_CCER_CC4P;
			} else {
				TIM_CCER(timer) &= ~TIM_CCER_CC4P;
			}
			break;
	}
}

void timer_ic_input_selection(const uintptr_t timer, const tim_ic_id_e ic, const tim_ic_sel_e sel)
{
	switch (ic) {
		case TIM_IC1:
			TIM_TISEL(timer) &= ~TIM_TISEL_TI1SEL_MASK;
			TIM_TISEL(timer) |= sel << TIM_TISEL_TI1SEL_SHIFT;
			break;
		case TIM_IC2:
			TIM_TISEL(timer) &= ~TIM_TISEL_TI2SEL_MASK;
			TIM_TISEL(timer) |= sel << TIM_TISEL_TI2SEL_SHIFT;
			break;
		case TIM_IC3:
			TIM_TISEL(timer) &= ~TIM_TISEL_TI3SEL_MASK;
			TIM_TISEL(timer) |= sel << TIM_TISEL_TI3SEL_SHIFT;
			break;
		case TIM_IC4:
			TIM_TISEL(timer) &= ~TIM_TISEL_TI4SEL_MASK;
			TIM_TISEL(timer) |= sel << TIM_TISEL_TI4SEL_SHIFT;
			break;
	}
}

/**@}*/