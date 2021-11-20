/*
 * This file is part of the unicore-mx project.
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

#pragma once

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
#include <libopencm3/nrf/periph.h>

/* Timer/Counter */

#define TIMER0			TIMER0_BASE
#define TIMER1			TIMER1_BASE
#define TIMER2			TIMER2_BASE

/* Tasks */

#define TIMER_TASK_START(T)			MMIO32((T) + 0x000)
#define TIMER0_TASK_START			TIMER_TASK_START(TIMER0)
#define TIMER1_TASK_START			TIMER_TASK_START(TIMER1)
#define TIMER2_TASK_START			TIMER_TASK_START(TIMER2)

#define TIMER_TASK_STOP(T)			MMIO32((T) + 0x004)
#define TIMER0_TASK_STOP			TIMER_TASK_STOP(TIMER0)
#define TIMER1_TASK_STOP			TIMER_TASK_STOP(TIMER1)
#define TIMER2_TASK_STOP			TIMER_TASK_STOP(TIMER2)

#define TIMER_TASK_COUNT(T)			MMIO32((T) + 0x008)
#define TIMER0_TASK_COUNT			TIMER_TASK_COUNT(TIMER0)
#define TIMER1_TASK_COUNT			TIMER_TASK_COUNT(TIMER1)
#define TIMER2_TASK_COUNT			TIMER_TASK_COUNT(TIMER2)

#define TIMER_TASK_CLEAR(T)			MMIO32((T) + 0x00C)
#define TIMER0_TASK_CLEAR			TIMER_TASK_CLEAR(TIMER0)
#define TIMER1_TASK_CLEAR			TIMER_TASK_CLEAR(TIMER1)
#define TIMER2_TASK_CLEAR			TIMER_TASK_CLEAR(TIMER2)

#define TIMER_TASK_SHUTDOWN(T)			MMIO32((T) + 0x010)
#define TIMER0_TASK_SHUTDOWN			TIMER_TASK_SHUTDOWN(TIMER0)
#define TIMER1_TASK_SHUTDOWN			TIMER_TASK_SHUTDOWN(TIMER1)
#define TIMER2_TASK_SHUTDOWN			TIMER_TASK_SHUTDOWN(TIMER2)

#define TIMER_TASK_CAPTURE(T, C)			MMIO32((T) + 0x040 + (uint32_t)(0x4 * (C)))
#define TIMER0_TASK_CAPTURE(C)			TIMER_TASK_CAPTURE(TIMER0, C)
#define TIMER1_TASK_CAPTURE(C)			TIMER_TASK_CAPTURE(TIMER1, C)
#define TIMER2_TASK_CAPTURE(C)			TIMER_TASK_CAPTURE(TIMER2, C)

#define TIMER0_TASK_CAPTURE0			TIMER_TASK_CAPTURE(TIMER0, 0)
#define TIMER0_TASK_CAPTURE1			TIMER_TASK_CAPTURE(TIMER0, 1)
#define TIMER0_TASK_CAPTURE2			TIMER_TASK_CAPTURE(TIMER0, 2)
#define TIMER0_TASK_CAPTURE3			TIMER_TASK_CAPTURE(TIMER0, 3)

#define TIMER1_TASK_CAPTURE0			TIMER_TASK_CAPTURE(TIMER1, 0)
#define TIMER1_TASK_CAPTURE1			TIMER_TASK_CAPTURE(TIMER1, 1)
#define TIMER1_TASK_CAPTURE2			TIMER_TASK_CAPTURE(TIMER1, 2)
#define TIMER1_TASK_CAPTURE3			TIMER_TASK_CAPTURE(TIMER1, 3)

#define TIMER2_TASK_CAPTURE0			TIMER_TASK_CAPTURE(TIMER2, 0)
#define TIMER2_TASK_CAPTURE1			TIMER_TASK_CAPTURE(TIMER2, 1)
#define TIMER2_TASK_CAPTURE2			TIMER_TASK_CAPTURE(TIMER2, 2)
#define TIMER2_TASK_CAPTURE3			TIMER_TASK_CAPTURE(TIMER2, 3)

/* Events */

#define TIMER_EVENT_COMPARE(T, C)			MMIO32((T) + 0x140 + (uint32_t)(0x4 * (C)))
#define TIMER0_EVENT_COMPARE(C)			TIMER_EVENT_COMPARE(TIMER0, C)
#define TIMER1_EVENT_COMPARE(C)			TIMER_EVENT_COMPARE(TIMER1, C)
#define TIMER2_EVENT_COMPARE(C)			TIMER_EVENT_COMPARE(TIMER2, C)

#define TIMER_EVENT_COMPARE0(T)			TIMER_EVENT_COMPARE(T, 0)
#define TIMER_EVENT_COMPARE1(T)			TIMER_EVENT_COMPARE(T, 1)
#define TIMER_EVENT_COMPARE2(T)			TIMER_EVENT_COMPARE(T, 2)
#define TIMER_EVENT_COMPARE3(T)			TIMER_EVENT_COMPARE(T, 3)

#define TIMER0_EVENT_COMPARE0			TIMER_EVENT_COMPARE(TIMER0, 0)
#define TIMER0_EVENT_COMPARE1			TIMER_EVENT_COMPARE(TIMER0, 1)
#define TIMER0_EVENT_COMPARE2			TIMER_EVENT_COMPARE(TIMER0, 2)
#define TIMER0_EVENT_COMPARE3			TIMER_EVENT_COMPARE(TIMER0, 3)

#define TIMER1_EVENT_COMPARE0			TIMER_EVENT_COMPARE(TIMER1, 0)
#define TIMER1_EVENT_COMPARE1			TIMER_EVENT_COMPARE(TIMER1, 1)
#define TIMER1_EVENT_COMPARE2			TIMER_EVENT_COMPARE(TIMER1, 2)
#define TIMER1_EVENT_COMPARE3			TIMER_EVENT_COMPARE(TIMER1, 3)

#define TIMER2_EVENT_COMPARE0			TIMER_EVENT_COMPARE(TIMER2, 0)
#define TIMER2_EVENT_COMPARE1			TIMER_EVENT_COMPARE(TIMER2, 1)
#define TIMER2_EVENT_COMPARE2			TIMER_EVENT_COMPARE(TIMER2, 2)
#define TIMER2_EVENT_COMPARE3			TIMER_EVENT_COMPARE(TIMER2, 3)

/* Registers */

#define TIMER_SHORTS(T)			periph_shorts(T)
#define TIMER0_SHORTS			TIMER_SHORTS(TIMER0)
#define TIMER1_SHORTS			TIMER_SHORTS(TIMER1)
#define TIMER2_SHORTS			TIMER_SHORTS(TIMER2)

#define TIMER_INTENSET(T)			periph_intenset(T)
#define TIMER0_INTENSET			TIMER_INTENSET(TIMER0)
#define TIMER1_INTENSET			TIMER_INTENSET(TIMER1)
#define TIMER2_INTENSET			TIMER_INTENSET(TIMER2)

#define TIMER_INTENCLR(T)			periph_intenclr(T)
#define TIMER0_INTENCLR			TIMER_INTENCLR(TIMER0)
#define TIMER1_INTENCLR			TIMER_INTENCLR(TIMER1)
#define TIMER2_INTENCLR			TIMER_INTENCLR(TIMER2)

#define TIMER_MODE(T)			MMIO32((T) + 0x504)
#define TIMER0_MODE			TIMER_MODE(TIMER0)
#define TIMER1_MODE			TIMER_MODE(TIMER1)
#define TIMER2_MODE			TIMER_MODE(TIMER2)

#define TIMER_BITMODE(T)			MMIO32((T) + 0x508)
#define TIMER0_BITMODE			TIMER_BITMODE(TIMER0)
#define TIMER1_BITMODE			TIMER_BITMODE(TIMER1)
#define TIMER2_BITMODE			TIMER_BITMODE(TIMER2)

#define TIMER_PRESCALER(T)			MMIO32((T) + 0x510)
#define TIMER0_PRESCALER			TIMER_PRESCALER(TIMER0)
#define TIMER1_PRESCALER			TIMER_PRESCALER(TIMER1)
#define TIMER2_PRESCALER			TIMER_PRESCALER(TIMER2)
#define TIMER_PRESCALER_MASK			(0xf)

#define TIMER_CC(T, C)			MMIO32((T) + 0x540 + 0x4 * (C))
#define TIMER0_CC(C)			TIMER_CC(TIMER0, C)
#define TIMER1_CC(C)			TIMER_CC(TIMER1, C)
#define TIMER2_CC(C)			TIMER_CC(TIMER2, C)

#define TIMER0_CC0			TIMER_CC(TIMER0, 0)
#define TIMER0_CC1			TIMER_CC(TIMER0, 1)
#define TIMER0_CC2			TIMER_CC(TIMER0, 2)
#define TIMER0_CC3			TIMER_CC(TIMER0, 3)

#define TIMER1_CC0			TIMER_CC(TIMER1, 0)
#define TIMER1_CC1			TIMER_CC(TIMER1, 1)
#define TIMER1_CC2			TIMER_CC(TIMER1, 2)
#define TIMER1_CC3			TIMER_CC(TIMER1, 3)

#define TIMER2_CC0			TIMER_CC(TIMER2, 0)
#define TIMER2_CC1			TIMER_CC(TIMER2, 1)
#define TIMER2_CC2			TIMER_CC(TIMER2, 2)
#define TIMER2_CC3			TIMER_CC(TIMER2, 3)

/* Register Contents */

#define TIMER_SHORTS_COMPARE0_CLEAR			(1 << 0)
#define TIMER_SHORTS_COMPARE1_CLEAR			(1 << 1)
#define TIMER_SHORTS_COMPARE2_CLEAR			(1 << 2)
#define TIMER_SHORTS_COMPARE3_CLEAR			(1 << 3)
#define TIMER_SHORTS_COMPARE_CLEAR(C)			(1 << (C))

#define TIMER_SHORTS_COMPARE0_STOP			(1 << 8)
#define TIMER_SHORTS_COMPARE1_STOP			(1 << 9)
#define TIMER_SHORTS_COMPARE2_STOP			(1 << 10)
#define TIMER_SHORTS_COMPARE3_STOP			(1 << 11)
#define TIMER_SHORTS_COMPARE_STOP(C)			(1 << (8 + (C)))

#define TIMER_INTEN_COMPARE0			(1 << 16)
#define TIMER_INTEN_COMPARE1			(1 << 17)
#define TIMER_INTEN_COMPARE2			(1 << 18)
#define TIMER_INTEN_COMPARE3			(1 << 19)
#define TIMER_INTEN_COMPARE(C)			(1 << (16 + (C)))

#define TIMER_MODE_SELECT			(1 << 0)

enum timer_mode {
	TIMER_MODE_TIMER,
	TIMER_MODE_COUNTER,
};

enum timer_bitmode {
	TIMER_BITMODE_16BIT,
	TIMER_BITMODE_08BIT,
	TIMER_BITMODE_24BIT,
	TIMER_BITMODE_32BIT,
};


BEGIN_DECLS

#define timer_enable_shorts			periph_enable_shorts
#define timer_disable_shorts			periph_disable_shorts
#define timer_enable_interrupts			periph_enable_interrupts
#define timer_disable_interrupts			periph_disable_interrupts

uint32_t timer_get_ticks(uint32_t timer);
void timer_set_mode(uint32_t timer, enum timer_mode mode);
void timer_set_bitmode(uint32_t timer, enum timer_bitmode bitmode);
void timer_start(uint32_t timer);
void timer_stop(uint32_t timer);
void timer_clear(uint32_t timer);
void timer_set_prescaler(uint32_t timer, uint8_t presc);
void timer_set_compare(uint32_t timer, uint8_t compare_num, uint32_t compare_val);
uint32_t timer_get_cc(uint32_t timer, uint8_t compare_num);
uint32_t timer_get_freq(uint32_t timer);

END_DECLS

