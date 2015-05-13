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

#ifndef SAM3X_PDC_H
#define SAM3X_PDC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>


/* --- PDC registers ----------------------------------------------------- */

#define PDC_RPR(x)			MMIO32((x) + 0x100)
#define PDC_RCR(x)			MMIO32((x) + 0x104)
#define PDC_TPR(x)			MMIO32((x) + 0x108)
#define PDC_TCR(x)			MMIO32((x) + 0x10C)
#define PDC_RNPR(x)			MMIO32((x) + 0x110)
#define PDC_RNCR(x)			MMIO32((x) + 0x114)
#define PDC_TNPR(x)			MMIO32((x) + 0x118)
#define PDC_TNCR(x)			MMIO32((x) + 0x11C)
#define PDC_PTCR(x)			MMIO32((x) + 0x120)
#define PDC_PTSR(x)			MMIO32((x) + 0x124)

/* --- PDC counter values ------------------------------------------------ */

/* Bits [31:16]: Reserved. */
#define PDC_COUNTER_MASK			(0xFFFF << 0)

/* --- PDC_PTCR values --------------------------------------------------- */

/* Bits [31:10]: Reserved. */
#define PDC_PTCR_TXTDIS			(1 << 9)
#define PDC_PTCR_TXTEN			(1 << 8)
/* Bits [7:2]: Reserved. */
#define PDC_PTCR_RXTDIS			(1 << 1)
#define PDC_PTCR_RXTEN			(1 << 0)

/* --- PDC_PTSR values --------------------------------------------------- */

/* Bits [31:9]: Reserved. */
#define PDC_PTSR_TXTEN			(1 << 8)
/* Bits [7:1]: Reserved. */
#define PDC_PTSR_RXTEN			(1 << 0)

#endif
