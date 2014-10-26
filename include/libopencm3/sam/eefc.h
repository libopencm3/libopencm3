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

#ifndef SAM3X_EEFC_H
#define SAM3X_EEFC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* --- Convenience macros ------------------------------------------------ */
#define EEFC				EEFC_BASE
#define EEFC0				EEFC0_BASE
#define EEFC1				EEFC1_BASE

/* --- Enhanced Embedded Flash Controller (EEFC) registers --------------- */
#define EEFC_FMR(port)			MMIO32((port) + 0x00)
#define EEFC_FCR(port)			MMIO32((port) + 0x04)
#define EEFC_FSR(port)			MMIO32((port) + 0x08)
#define EEFC_FRR(port)			MMIO32((port) + 0x0C)
/* 0x0010 - Reserved */


/* EEFC Flash Mode Register (EEFC_FMR) */
/* Bit [31:25] - Reserved */
#define EEFC_FMR_FAM			(0x01 << 24)
/* Bit [23:12] - Reserved */
#define EEFC_FMR_FWS_MASK		(0x0F << 8)
/* Bit [7:1] - Reserved */
#define EEFC_FMR_FRDY			(0x01 << 0)

/* EEFC Flash Command Register (EEFC_FCR) */
#define EEFC_FCR_FKEY			(0x5A << 24)
#define EEFC_FCR_FARG_MASK		(0xFFFF << 8)
#define EEFC_FCR_FCMD_MASK		(0xFF << 0)
#define EEFC_FCR_FCMD_GETD		(0x00 << 0)
#define EEFC_FCR_FCMD_WP		(0x01 << 0)
#define EEFC_FCR_FCMD_WPL		(0x02 << 0)
#define EEFC_FCR_FCMD_EWP		(0x03 << 0)
#define EEFC_FCR_FCMD_EWPL		(0x04 << 0)
#define EEFC_FCR_FCMD_EA		(0x05 << 0)
#define EEFC_FCR_FCMD_SLB		(0x08 << 0)
#define EEFC_FCR_FCMD_CLB		(0x09 << 0)
#define EEFC_FCR_FCMD_GLB		(0x0A << 0)
#define EEFC_FCR_FCMD_SGPB		(0x0B << 0)
#define EEFC_FCR_FCMD_CGPB		(0x0C << 0)
#define EEFC_FCR_FCMD_GGPB		(0x0D << 0)
#define EEFC_FCR_FCMD_STUI		(0x0E << 0)
#define EEFC_FCR_FCMD_SPUI		(0x0F << 0)

/* EEFC Flash Status Register (EEFC_FSR) */
/* Bit [31:3] - Reserved */
#define EEFC_FSR_FLOCKE			(0x01 << 2)
#define EEFC_FSR_FCMDE			(0x01 << 1)
#define EEFC_FSR_FRDY			(0x01 << 0)

static inline void eefc_set_latency(uint8_t wait)
{
#if defined(SAM3A) || defined(SAM3U) || defined(SAM3X)
	EEFC_FMR(EEFC0) = (EEFC_FMR(EEFC0) & ~EEFC_FMR_FWS_MASK) | (wait << 8);
	EEFC_FMR(EEFC1) = (EEFC_FMR(EEFC1) & ~EEFC_FMR_FWS_MASK) | (wait << 8);
#elif defined(SAM3N) || defined(SAM3S)
	EEFC_FMR(EEFC) = (EEFC_FMR(EEFC) & ~EEFC_FMR_FWS_MASK) | (wait << 8);
#endif
}

#endif

