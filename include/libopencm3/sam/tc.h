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

#ifndef SAM3X_TC_H
#define SAM3X_TC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* --- Timer Counter (TC) registers -------------------------------------- */

#define TC_CCR(x)			MMIO32(TC_BASE + 0x00 + 0x40*(x))
#define TC_CMR(x)			MMIO32(TC_BASE + 0x04 + 0x40*(x))
#define TC_SMMR(x)			MMIO32(TC_BASE + 0x08 + 0x40*(x))
/* 0x0C + 0x40*channel - Reserved */
#define TC_CV(x)			MMIO32(TC_BASE + 0x10 + 0x40*(x))
#define TC_RA(x)			MMIO32(TC_BASE + 0x14 + 0x40*(x))
#define TC_RB(x)			MMIO32(TC_BASE + 0x18 + 0x40*(x))
#define TC_RC(x)			MMIO32(TC_BASE + 0x1C + 0x40*(x))
#define TC_SR(x)			MMIO32(TC_BASE + 0x20 + 0x40*(x))
#define TC_IER(x)			MMIO32(TC_BASE + 0x24 + 0x40*(x))
#define TC_IDR(x)			MMIO32(TC_BASE + 0x28 + 0x40*(x))
#define TC_IMR(x)			MMIO32(TC_BASE + 0x2C + 0x40*(x))
#define TC_BCR				MMIO32(TC_BASE + 0xC0)
#define TC_BMR				MMIO32(TC_BASE + 0xC4)
#define TC_QIER				MMIO32(TC_BASE + 0xC8)
#define TC_QIDR				MMIO32(TC_BASE + 0xCC)
#define TC_QIMR				MMIO32(TC_BASE + 0xD0)
#define TC_QISR				MMIO32(TC_BASE + 0xD4)
#define TC_FMR				MMIO32(TC_BASE + 0xD8)
/* 0x00DC:0x00E0 - Undocumented */
#define TC_WPMR				MMIO32(TC_BASE + 0xE4)
/* 0x00E8:0x00F8 - Undocumented */
/* 0x00FC - Reserved */

#endif
