/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Seb Holzapfel <schnommus@gmail.com>
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

#include <stdint.h>
#include <libopencm3/efm32/cmu.h>
#include <libopencm3/efm32/timer.h>

#include "delay.h"

extern const uint32_t ahb_frequency;

void delay_setup(void)
{
	cmu_periph_clock_enable(CMU_TIMER2);
	/* efm32hg doesn't support a nice 1us prescaler */
	timer_start(TIMER2);
}

void delay_us(uint16_t us)
{
	volatile uint16_t time_now = 0;
	/* Convert microseconds into timer ticks */
	uint16_t delay_ahb_cycles = us * (ahb_frequency / 1000000);

	TIMER2_CNT = 0;
	while (time_now < delay_ahb_cycles) {
		time_now = TIMER2_CNT;
	}
}
