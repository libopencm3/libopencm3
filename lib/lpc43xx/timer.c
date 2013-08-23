/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Ben Gamari <bgamari@physics.umass.edu>
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
 *
 * This provides the code for the "next gen" EXTI block provided in F2/F4/L1
 * devices.  (differences only in the source selection)
 */

#include <libopencm3/lpc43xx/timer.h>

void timer_reset(uint32_t timer_peripheral)
{
	TIMER_TCR(timer_peripheral) |= TIMER_TCR_CRST;
	TIMER_TCR(timer_peripheral) &= ~TIMER_TCR_CRST;
}

void timer_enable_counter(uint32_t timer_peripheral)
{
	TIMER_TCR(timer_peripheral) |= TIMER_TCR_CEN;
}

void timer_disable_counter(uint32_t timer_peripheral)
{
	TIMER_TCR(timer_peripheral) &= ~TIMER_TCR_CEN;
}

void timer_set_counter(uint32_t timer_peripheral, uint32_t count)
{
	TIMER_TC(timer_peripheral) = count;
}

uint32_t timer_get_counter(uint32_t timer_peripheral)
{
	return TIMER_TC(timer_peripheral);
}

uint32_t timer_get_prescaler(uint32_t timer_peripheral)
{
	return TIMER_PR(timer_peripheral);
}

void timer_set_prescaler(uint32_t timer_peripheral, uint32_t prescaler)
{
	TIMER_PR(timer_peripheral) = prescaler;
}

void timer_set_mode(uint32_t timer_peripheral, uint32_t mode)
{
	TIMER_CTCR(timer_peripheral) = mode |
		(TIMER_CTCR(timer_peripheral) & TIMER_CTCR_MODE_MASK);
}

void timer_set_count_input(uint32_t timer_peripheral, uint32_t input)
{
	TIMER_CTCR(timer_peripheral) = input |
		(TIMER_CTCR(timer_peripheral) & TIMER_CTCR_CINSEL_MASK);
}

