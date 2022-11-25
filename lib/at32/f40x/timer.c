/** @defgroup timer_file TIMER peripheral API
@ingroup peripheral_apis
@brief <b>libopencm3 AT32F40x Timers</b>

@version 1.0.0

@date 25 November 2022

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

#include <libopencm3/stm32/timer.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Enable Plus Mode

Enable 32-bit mode for TIMx_CNT, TIMx_ARR and TIMx_CCR[1-4] registers.
TIM[2-5] only.

@param[in] timer_peripheral. Timer register address base
*/

void timer_enable_plus_mode(uint32_t timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_PMEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Plus Mode

Disable 32-bit mode for TIMx_CNT, TIMx_ARR and TIMx_CCR[1-4] registers.
TIM[2-5] only.

@param[in] timer_peripheral. Timer register address base
*/

void timer_disable_plus_mode(uint32_t timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_PMEN;
}

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
