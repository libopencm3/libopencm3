/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Owen Kirby <oskirby@gmail.com>
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

#ifndef SAM3X_RSTC_H
#define SAM3X_RSTC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>


/* --- RSTC registers ---------------------------------------------------- */

#define RSTC_CR				MMIO32(RSTC_BASE + 0x00)
#define RSTC_SR				MMIO32(RSTC_BASE + 0x04)
#define RSTC_MR				MMIO32(RSTC_BASE + 0x08)

/* --- RSTC_CR values ----------------------------------------------------- */

#define RSTC_CR_KEY			(0xA5 << 24)
/* Bits 1 and [23:4]: Reserved. */
#define RSTC_CR_PROCRST			(1 << 0)
#define RSTC_CR_PERRST			(1 << 2)
#define RSTC_CR_EXTRST			(1 << 3)

/* --- RSTC_SR values ----------------------------------------------------- */

/* Bits [31:18]: Reserved. */
#define RSTC_SR_SRCMP			(1 << 17)
#define RSTC_SR_NRSTL			(1 << 16)
/* Bits [15:11]: Reserved. */
#define RSTC_SR_RSTTYP_MASK		(0x7 << 8)
#define RSTC_SR_RSTTYP_GENERAL	(0x0 << 8)
#define RSTC_SR_RSTTYP_BACKUP	(0x1 << 8)
#define RSTC_SR_RSTTYP_WATCHDOG	(0x2 << 8)
#define RSTC_SR_RSTTYP_SOFTWARE	(0x3 << 8)
#define RSTC_SR_RSTTYP_USER		(0x4 << 8)
/* Bits [7:1]: Reserved. */
#define RSTC_SR_URSTS			(1 << 0)

/* --- RSTC_MR values ------------------------------------------------------ */

#define RSTC_MR_KEY			(0xA5 << 24)
/* Bits [23:12]: Reserved. */
#define RSTC_MR_ERSTL_MASK		(0xF << 8)
/* Bits [7:5]: Reserved. */
#define RSTC_MR_URSTIEN			(1 << 4)
/* Bits [3:1]: Reserved. */
#define RSTC_MR_URSTEN			(1 << 0)

#endif
