/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef LIBOPENCM3_CM3_FPB_H
#define LIBOPENCM3_CM3_FPB_H

/* Cortex-M3 Flash Patch and Breakpoint (FPB) unit */

/* Note: We always use "FPB" as abbreviation, docs sometimes use only "FP". */

/* --- FPB registers ------------------------------------------------------- */

/* Flash Patch Control (FPB_CTRL) */
#define FPB_CTRL		MMIO32(FPB_BASE + 0)

/* Flash Patch Remap (FPB_REMAP) */
#define FPB_REMAP		MMIO32(FPB_BASE + 4)

/* Flash Patch Comparator (FPB_COMPx) */
#define FPB_COMP		(voltile u32 *)(FPB_BASE + 8)

/* TODO: PID, CID */

/* --- FPB_CTRL values ----------------------------------------------------- */

#define FPB_CTRL_ENABLE		0x0001
#define FPB_CTRL_KEY		0x0002
#define FPB_CTRL_NUM_CODE1_MASK	0x00F0
#define FPB_CTRL_NUM_LIT_MASK	0x0F00
#define FPB_CTRL_NUM_CODE2_MASK	0xE000

/* --- FPB_REMAP values ---------------------------------------------------- */

/* TODO */

/* --- FPB_COMPx values ---------------------------------------------------- */

#define FPB_COMP_ENABLE			0x0001
#define FPB_COMP_REPLACE_REMAP		0x0000
#define FPB_COMP_REPLACE_BREAK_LOWER	0x4000
#define FPB_COMP_REPLACE_BREAK_UPPER	0x8000
#define FPB_COMP_REPLACE_BREAK_BOTH	0xC000

#endif
