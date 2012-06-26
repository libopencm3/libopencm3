/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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

#ifndef LIBOPENCM3_SYSTICK_H
#define LIBOPENCM3_SYSTICK_H

#include <libopencm3/lpc43xx/memorymap.h>
#include <libopencm3/cm3/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- SYSTICK registers --------------------------------------------------- */
/* See also libopencm3\cm3\scs.h for details on SysTicks registers */

/* Control and status register (STK_CTRL) */
#define STK_CTRL			MMIO32(SYS_TICK_BASE + 0x00)

/* reload value register (STK_LOAD) */
#define STK_LOAD			MMIO32(SYS_TICK_BASE + 0x04)

/* current value register (STK_VAL) */
#define STK_VAL				MMIO32(SYS_TICK_BASE + 0x08)

/* calibration value register (STK_CALIB) */
#define STK_CALIB			MMIO32(SYS_TICK_BASE + 0x0C)

/* --- STK_CTRL values ----------------------------------------------------- */
/* Bits [31:17] Reserved, must be kept cleared. */
/* COUNTFLAG: */
#define STK_CTRL_COUNTFLAG		(1 << 16)
/* Bits [15:3] Reserved, must be kept cleared. */
/* CLKSOURCE: Clock source selection */
#define STK_CTRL_CLKSOURCE		(1 << 2)
/* TICKINT: SysTick exception request enable */
#define STK_CTRL_TICKINT		(1 << 1)
/* ENABLE: Counter enable */
#define STK_CTRL_ENABLE			(1 << 0)

/* --- STK_LOAD values ----------------------------------------------------- */
/* Bits [31:24] Reserved, must be kept cleared. */
/* RELOAD[23:0]: RELOAD value */

/* --- STK_VAL values ------------------------------------------------------ */
/* Bits [31:24] Reserved, must be kept cleared. */
/* CURRENT[23:0]: Current counter value */

/* --- STK_CALIB values ---------------------------------------------------- */
/* NOREF: NOREF flag */
#define STK_CALIB_NOREF			(1 << 31)
/* SKEW: SKEW flag */
#define STK_CALIB_SKEW			(1 << 30)
/* Bits [29:24] Reserved, must be kept cleared. */
/* TENMS[23:0]: Calibration value */

/* --- Function Prototypes ------------------------------------------------- */

void systick_set_reload(u32 value);
u32 systick_get_value(void);
void systick_set_clocksource(u8 clocksource);
void systick_interrupt_enable(void);
void systick_interrupt_disable(void);
void systick_counter_enable(void);
void systick_counter_disable(void);
u8 systick_get_countflag(void);

u32 systick_get_calib(void);

#endif
