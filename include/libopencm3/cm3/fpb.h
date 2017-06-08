/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef LIBOPENCM3_CM3_FPB_H
#define LIBOPENCM3_CM3_FPB_H

/* Cortex-M3 Flash Patch and Breakpoint (FPB) unit */

/* Those defined only on ARMv7 and above */
#if !defined(__ARM_ARCH_7M__) && !defined(__ARM_ARCH_7EM__)
#error "Flash Patch and Breakpoint not available in CM0"
#endif

/* Note: We always use "FPB" as abbreviation, docs sometimes use only "FP". */

/* --- FPB registers ------------------------------------------------------- */

/* Flash Patch Control (FPB_CTRL) */
#define FPB_CTRL			MMIO32(FPB_BASE + 0)

/* Flash Patch Remap (FPB_REMAP) */
#define FPB_REMAP			MMIO32(FPB_BASE + 4)

/* Flash Patch Comparator (FPB_COMPx) */
#define FPB_COMP			(&MMIO32(FPB_BASE + 8))

/* CoreSight Lock Status Register for this peripheral */
#define FPB_LSR				MMIO32(FPB_BASE + 0xFB4)
/* CoreSight Lock Access Register for this peripheral */
#define FPB_LAR				MMIO32(FPB_BASE + 0xFB0)


/* TODO: PID, CID */

/* --- FPB_CTRL values ----------------------------------------------------- */

/* Bits [31:15]: Reserved, read as zero, writes ignored */

#define FPB_CTRL_NUM_CODE2_MASK		(0x7 << 12)

#define FPB_CTRL_NUM_LIT_MASK		(0xf << 8)

#define FPB_CTRL_NUM_CODE1_MASK		(0xf << 4)

/* Bits [3:2]: Reserved */

#define FPB_CTRL_KEY			(1 << 1)

#define FPB_CTRL_ENABLE			(1 << 0)

/* --- FPB_REMAP values ---------------------------------------------------- */

/* TODO */

/* --- FPB_COMPx values ---------------------------------------------------- */

#define FPB_COMP_REPLACE_REMAP		(0x0 << 30)
#define FPB_COMP_REPLACE_BREAK_LOWER	(0x1 << 30)
#define FPB_COMP_REPLACE_BREAK_UPPER	(0x2 << 30)
#define FPB_COMP_REPLACE_BREAK_BOTH	(0x3 << 30)
#define FPB_COMP_REPLACE_MASK		(0x3 << 30)

/* Bit 29: Reserved */

/* TODO */

/* Bit 1: Reserved */

#define FPB_COMP_ENABLE			(1 << 0)

#endif
