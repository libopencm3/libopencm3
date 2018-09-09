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

#ifndef LIBOPENCM3_CM3_TPIU_H
#define LIBOPENCM3_CM3_TPIU_H

/**
 * @defgroup cm_tpiu Cortex-M Trace Port Interface Unit (TPIU)
 * @ingroup CM3_defines
 * @{
 */

/* Those defined only on ARMv7 and above */
#if !defined(__ARM_ARCH_7M__) && !defined(__ARM_ARCH_7EM__)
#error "Trace Port Interface Unit not available in CM0"
#endif

/* --- TPIU registers ------------------------------------------------------ */

/* Supported Synchronous Port Size (TPIU_SSPSR) */
#define TPIU_SSPSR			MMIO32(TPIU_BASE + 0x000)

/* Current Synchronous Port Size (TPIU_CSPSR) */
#define TPIU_CSPSR			MMIO32(TPIU_BASE + 0x004)

/* Asynchronous Clock Prescaler (TPIU_ACPR) */
#define TPIU_ACPR			MMIO32(TPIU_BASE + 0x010)

/* Selected Pin Protocol (TPIU_SPPR) */
#define TPIU_SPPR			MMIO32(TPIU_BASE + 0x0F0)

/* Formatter and Flush Status Register (TPIU_FFSR) */
#define TPIU_FFSR			MMIO32(TPIU_BASE + 0x300)

/* Formatter and Flush Control Register (TPIU_FFCR) */
#define TPIU_FFCR			MMIO32(TPIU_BASE + 0x304)

/* (TPIU_DEVID) */
#define TPIU_DEVID			MMIO32(TPIU_BASE + 0xFC8)

/* CoreSight Lock Status Register for this peripheral */
#define TPIU_LSR			MMIO32(TPIU_BASE + 0xFB4)
/* CoreSight Lock Access Register for this peripheral */
#define TPIU_LAR			MMIO32(TPIU_BASE + 0xFB0)

/* TODO: PID, CID */

/* --- TPIU_ACPR values ---------------------------------------------------- */

/* Bits 31:16 - Reserved */
/* Bits 15:0 - SWO output clock = Asynchronous_Reference_Clock/(value +1) */

/* --- TPIU_SPPR values ---------------------------------------------------- */

/* Bits 31:2 - Reserved */
#define TPIU_SPPR_SYNC			(0x0)
#define TPIU_SPPR_ASYNC_MANCHESTER	(0x1)
#define TPIU_SPPR_ASYNC_NRZ		(0x2)

/* --- TPIU_FFSR values ---------------------------------------------------- */

/* Bits 31:4 - Reserved */
#define TPIU_FFSR_FTNONSTOP		(1 << 3)
#define TPIU_FFSR_TCPRESENT		(1 << 2)
#define TPIU_FFSR_FTSTOPPED		(1 << 1)
#define TPIU_FFSR_FLINPROG		(1 << 0)

/* --- TPIU_FFCR values ---------------------------------------------------- */

/* Bits 31:9 - Reserved */
#define TPIU_FFCR_TRIGIN		(1 << 8)
/* Bits 7:2 - Reserved */
#define TPIU_FFCR_ENFCONT		(1 << 1)
/* Bit 0 - Reserved */

/* --- TPIU_DEVID values ---------------------------------------------------- */
/* Bits 31:16 - Reserved */
/* Bits 15:12 - Implementation defined */
#define TPUI_DEVID_NRZ_SUPPORTED	(1 << 11)
#define TPUI_DEVID_MANCHESTER_SUPPORTED	(1 << 10)
/* Bit 9 - RAZ, indicated that trace data and clock are supported */
#define TPUI_DEVID_FIFO_SIZE_MASK	(7 << 6)
/* Bits 5:0 - Implementation defined */

/**@}*/

#endif
