/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef SAM3X_WDT_H
#define SAM3X_WDT_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>


/* --- WDT registers ----------------------------------------------------- */

#define WDT_CR				MMIO32(WDT_BASE + 0x00)
#define WDT_MR				MMIO32(WDT_BASE + 0x04)
#define WDT_SR				MMIO32(WDT_BASE + 0x08)

/* --- WDT_CR values ------------------------------------------------------ */

#define WDT_CR_KEY			(0xA5 << 24)
/* Bits [23:1]: Reserved. */
#define WDT_CR_WDRSTT			(1 << 0)

/* --- WDT_MR values ------------------------------------------------------ */

/* Bits [31:32]: Reserved. */
#define WDT_MR_WDIDLEHLT		(1 << 29)
#define WDT_MR_WDDBGHLT			(1 << 28)
#define WDT_MR_WDD_MASK			(0xFFF << 16)
#define WDT_MR_WDDIS			(1 << 15)
#define WDT_MR_WDRPROC			(1 << 14)
#define WDT_MR_WDRSTEN			(1 << 13)
#define WDT_MR_WDFIEN			(1 << 12)
#define WDT_MR_WDV_MASK			(0xFFF << 0)

/* --- WDT_SR values ------------------------------------------------------ */

/* Bits [31:2]: Reserved. */
#define WDT_SR_WDERR			(1 << 1)
#define WDT_SR_WDUNF			(1 << 0)

#endif
