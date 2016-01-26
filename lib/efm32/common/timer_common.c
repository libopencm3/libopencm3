/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#include <libopencm3/efm32/timer.h>

#define HAS_DEAD_TIME_INSERTION(timer) (timer == TIMER0)

/**
 * Start timer
 * @param[in] timer Timer (use TIMERx)
 */
void timer_start(uint32_t timer)
{
	TIMER_CMD(timer) = TIMER_CMD_START;
}

/**
 * Stop timer
 * @param[in] timer Timer (use TIMERx)
 */
void timer_stop(uint32_t timer)
{
	TIMER_CMD(timer) = TIMER_CMD_STOP;
}

/** Clock division factor
 * @param[in] timer Timer (use TIMERx)
 * @param[in] presc Factor (use TIMER_CTRL_PRESC_DIV*)
 * @note output-clock = input-clock / @a presc
 */
void timer_set_clock_prescaler(uint32_t timer, uint32_t presc)
{
	TIMER_CTRL(timer) = (TIMER_CTRL(timer) & ~TIMER_CTRL_PRESC_MASK)
			    | TIMER_CTRL_PRESC(presc);
}

/**
 * Start timer top value
 * the timer reload after it reaches top value
 * @param[in] timer Timer (use TIMERx)
 * @param[in] top Top value
 */
void timer_set_top(uint32_t timer, uint32_t top)
{
	TIMER_TOP(timer) = top;
}
