/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENSTM32_SYSTICK_H
#define LIBOPENSTM32_SYSTICK_H

#include <libopenstm32/memorymap.h>
#include <libopenstm32/common.h>

/* --- SYSTICK registers --------------------------------------------------- */

/* Control and status register (STK_CTRL) */
#define STK_CTRL			MMIO32(SYSTICK_BASE + 0x00)

/* reload value register (STK_LOAD) */
#define STK_LOAD			MMIO32(SYSTICK_BASE + 0x04)

/* current value register (STK_VAL) */
#define STK_VAL				MMIO32(SYSTICK_BASE + 0x08)

/* calibration value register (STK_CALIB) */
#define STK_CALIB			MMIO32(SYSTICK_BASE + 0x0C)

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

#endif
