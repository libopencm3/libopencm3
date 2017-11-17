/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017 Karl Palsson <karlp@tweak.net.au>
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

/*
 * This file implements some simple busy timers.  They are designed to be
 * portable, not performant.
 * TIM6 is appropriated for usage.
 */
#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>

#include "delay.h"

void delay_setup(void)
{
	/* set up a microsecond free running timer for ... things... */
	rcc_periph_clock_enable(RCC_TIM6);
	/* microsecond counter */
	timer_set_prescaler(TIM6, rcc_apb1_frequency / 1e6 - 1);
	timer_set_period(TIM6, 0xffff);
	timer_one_shot_mode(TIM6);
}

void delay_us(uint16_t us)
{
	TIM_ARR(TIM6) = us;
	TIM_EGR(TIM6) = TIM_EGR_UG;
	TIM_CR1(TIM6) |= TIM_CR1_CEN;
	//timer_enable_counter(TIM6);
	while (TIM_CR1(TIM6) & TIM_CR1_CEN);
}


