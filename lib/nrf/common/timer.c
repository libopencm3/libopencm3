/** @addtogroup timer_file TIMER peripheral API
 *
 * @brief <b>Access functions for the Timer/Counter </b>
 *
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017-2018 Unicore MX project<dev(at)lists(dot)unicore-mx(dot)org>
 * Copyright (C) 2021 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.	If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/nrf/timer.h>
#include <libopencm3/nrf/clock.h>
/**@{*/

/** @brief Get timer ticks
 *
 * @param[in] timer uint32_t timer base
 * @returns current ticks value
 */
uint32_t timer_get_ticks(uint32_t timer)
{
	uint32_t ticks;
	uint32_t cc;

	/* TODO: Check WTF is this doing? */
	cc = TIMER_CC(0, 0);
	TIMER_TASK_CAPTURE(timer, 0) = 1;
	ticks = TIMER_CC(timer, 0);
	TIMER_CC(timer, 0) = cc;
	return ticks;
}

/** @brief Set timer mode (counter/timer)
 *
 * @param[in] timer uint32_t timer base
 * @param[in] mode enum timer_mode
 */
void timer_set_mode(uint32_t timer, enum timer_mode mode)
{
	TIMER_MODE(timer) = mode;
}

/** @brief Set timer bit mode (width)
 *
 * @param[in] timer uint32_t timer base
 * @param[in] bitmode enum timer_bitmode
 */
void timer_set_bitmode(uint32_t timer, enum timer_bitmode bitmode)
{
	TIMER_BITMODE(timer) = bitmode;
}

/** @brief Start the timer
 *
 * @param[in] timer uint32_t timer base
 */
void timer_start(uint32_t timer)
{
	PERIPH_TRIGGER_TASK(TIMER_TASK_START(timer));
}

/** @brief Stop the timer
 *
 * @param[in] timer uint32_t timer base
 */
void timer_stop(uint32_t timer)
{
	PERIPH_TRIGGER_TASK(TIMER_TASK_STOP(timer));
}

/** @brief Clear the timer
 *
 * @param[in] timer uint32_t timer base
 */
void timer_clear(uint32_t timer)
{
	PERIPH_TRIGGER_TASK(TIMER_TASK_CLEAR(timer));
}

/** @brief Set prescaler value
 *
 * @param[in] timer uint32_t timer base
 * @param[in] presc uint8_t prescaler value
 */
void timer_set_prescaler(uint32_t timer, uint8_t presc)
{
	TIMER_PRESCALER(timer) = presc & TIMER_PRESCALER_MASK;
}

/** @brief Set compare register
 *
 * @param[in] timer uint32_t timer base
 * @param[in] compare_num uint8_t compare number (0-3)
 * @param[in] compare_val uint32_t compare value
 */
void timer_set_compare(uint32_t timer, uint8_t compare_num, uint32_t compare_val)
{
	if (compare_num > 3) {
		return;
	}

	TIMER_CC(timer, compare_num) = compare_val;
}

/** @brief Get the timer tick frequency
 *
 * @param[in] timer uint32_t timer base
 * @returns frequency of ticking
 */
uint32_t timer_get_freq(uint32_t timer)
{
	return CLOCK_PCLK/(1<<TIMER_PRESCALER(timer));
}

/** @brief Get compare register
 *
 * @param[in] timer uint32_t timer base
 * @param[in] compare_num uint8_t compare number (0-3)
 * @returns compare register value
 */
uint32_t timer_get_cc(uint32_t timer, uint8_t compare_num)
{
	return TIMER_CC(timer, compare_num);
}
/**@}*/

