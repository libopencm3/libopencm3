/** @addtogroup timer_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Maxim Sloyko <maxims@google.com>
 * @author @htmlonly &copy; @endhtmlonly 2021 Eduard Drusa <ventyl86 at netkosice dot sk>
 *
 **/

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

/**@{*/
/* Timer/Counter */
/** @addtogroup timer_block
 * @{
 */

#define TIMER0						TIMER0_BASE
#define TIMER1						TIMER1_BASE
#define TIMER2						TIMER2_BASE

/**@}*/

/* Tasks */

#define TIMER_TASK_START(T)			MMIO32((T) + 0x000)
#define TIMER_TASK_STOP(T)			MMIO32((T) + 0x004)
#define TIMER_TASK_COUNT(T)			MMIO32((T) + 0x008)
#define TIMER_TASK_CLEAR(T)			MMIO32((T) + 0x00C)
#define TIMER_TASK_SHUTDOWN(T)			MMIO32((T) + 0x010)
#define TIMER_TASK_CAPTURE(T, C)			MMIO32((T) + 0x040 + (uint32_t)(0x4 * (C)))




/* Events */

#define TIMER_EVENT_COMPARE(T, C)			MMIO32((T) + 0x140 + (uint32_t)(0x4 * (C)))

/* Registers */

#define TIMER_SHORTS(T)			_PERIPH_SHORTS(T)
#define TIMER_INTENSET(T)			_PERIPH_INTENSET(T)
#define TIMER_INTENCLR(T)			_PERIPH_INTENCLR(T)
#define TIMER_MODE(T)			MMIO32((T) + 0x504)
#define TIMER_BITMODE(T)			MMIO32((T) + 0x508)
#define TIMER_PRESCALER(T)			MMIO32((T) + 0x510)
#define TIMER_PRESCALER_MASK			(0xf)

#define TIMER_CC(T, C)			MMIO32((T) + 0x540 + 0x4 * (C))




/* Register Contents */

/** @addtogroup timer_shorts Timer event -> task shortcuts
 * @{
 */

#define TIMER_SHORTS_COMPARE_CLEAR(C)			(1 << (C))
#define TIMER_SHORTS_COMPARE_STOP(C)			(1 << (8 + (C)))
/**@}*/

#define TIMER_INTEN_COMPARE(C)					(1 << (16 + (C)))

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

/**@}*/

BEGIN_DECLS

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


