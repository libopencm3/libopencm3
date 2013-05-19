/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef SAM_PIO_H
#define SAM_PIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* --- Convenience macros ------------------------------------------------ */

/* GPIO port base addresses (for convenience) */
#define PIOA				PIOA_BASE
#define PIOB				PIOB_BASE
#define PIOC				PIOC_BASE
#define PIOD				PIOD_BASE
#define PIOE				PIOE_BASE
#define PIOF				PIOF_BASE
#define PIOG				PIOG_BASE
#define PIOH				PIOH_BASE

/* --- PIO registers ----------------------------------------------------- */

#define PIO_PER(port)			MMIO32((port) + 0x0000)
#define PIO_PDR(port)			MMIO32((port) + 0x0004)
#define PIO_PSR(port)			MMIO32((port) + 0x0008)
/* 0x000C - Reserved */
#define PIO_OER(port)			MMIO32((port) + 0x0010)
#define PIO_ODR(port)			MMIO32((port) + 0x0014)
#define PIO_OSR(port)			MMIO32((port) + 0x0018)
/* 0x001C - Reserved */
#define PIO_IFER(port)			MMIO32((port) + 0x0020)
#define PIO_IFDR(port)			MMIO32((port) + 0x0024)
#define PIO_IFSR(port)			MMIO32((port) + 0x0028)
/* 0x002C - Reserved */
#define PIO_SODR(port)			MMIO32((port) + 0x0030)
#define PIO_CODR(port)			MMIO32((port) + 0x0034)
#define PIO_ODSR(port)			MMIO32((port) + 0x0038)
#define PIO_PDSR(port)			MMIO32((port) + 0x003C)
#define PIO_IER(port)			MMIO32((port) + 0x0040)
#define PIO_IDR(port)			MMIO32((port) + 0x0044)
#define PIO_IMR(port)			MMIO32((port) + 0x0048)
#define PIO_ISR(port)			MMIO32((port) + 0x004C)
#define PIO_MDER(port)			MMIO32((port) + 0x0050)
#define PIO_MDDR(port)			MMIO32((port) + 0x0054)
#define PIO_MDSR(port)			MMIO32((port) + 0x0058)
/* 0x005C - Reserved */
#define PIO_PUDR(port)			MMIO32((port) + 0x0060)
#define PIO_PUER(port)			MMIO32((port) + 0x0064)
#define PIO_PUSR(port)			MMIO32((port) + 0x0068)
/* 0x006C - Reserved */
#define PIO_ABSR(port)			MMIO32((port) + 0x0070)
/* 0x0074-0x007C - Reserved */
#define PIO_SCIFSR(port)		MMIO32((port) + 0x0080)
#define PIO_DIFSR(port)			MMIO32((port) + 0x0084)
#define PIO_IFDGSR(port)		MMIO32((port) + 0x0088)
#define PIO_SCDR(port)			MMIO32((port) + 0x008C)
/* 0x0090-0x009C - Reserved */
#define PIO_OWER(port)			MMIO32((port) + 0x00A0)
#define PIO_OWDR(port)			MMIO32((port) + 0x00A4)
#define PIO_OWSR(port)			MMIO32((port) + 0x00A8)
/* 0x00AC - Reserved */
#define PIO_AIMER(port)			MMIO32((port) + 0x00B0)
#define PIO_AIMDR(port)			MMIO32((port) + 0x00B4)
#define PIO_AIMMR(port)			MMIO32((port) + 0x00B8)
/* 0x00BC - Reserved */
#define PIO_ESR(port)			MMIO32((port) + 0x00C0)
#define PIO_LSR(port)			MMIO32((port) + 0x00C4)
#define PIO_ELSR(port)			MMIO32((port) + 0x00C8)
/* 0x00CC - Reserved */
#define PIO_FELLSR(port)		MMIO32((port) + 0x00D0)
#define PIO_REHLSR(port)		MMIO32((port) + 0x00D4)
#define PIO_FRLHSR(port)		MMIO32((port) + 0x00D8)
/* 0x00DC - Reserved */
#define PIO_LOCKSR(port)		MMIO32((port) + 0x00E0)
#define PIO_WPMR(port)			MMIO32((port) + 0x00E4)
#define PIO_WPSR(port)			MMIO32((port) + 0x00E8)
/* 0x00EC-0x0144 - Reserved */

#endif
