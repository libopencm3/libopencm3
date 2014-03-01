/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2014 Felix Held <felix-libopencm3@felixheld.de>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA PIO.H
The order of header inclusion is important. pio.h includes the device
specific memorymap.h header before including this header file.*/

#if defined(LIBOPENCM3_PIO_H)

#ifndef LIBOPENCM3_PIO_COMMON_ALL_H
#define LIBOPENCM3_PIO_COMMON_ALL_H

#include <libopencm3/cm3/common.h>

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

/* PIO Enable Register */
#define PIO_PER(port)			MMIO32((port) + 0x0000)

/* PIO Disable Register */
#define PIO_PDR(port)			MMIO32((port) + 0x0004)

/* PIO Status Register */
#define PIO_PSR(port)			MMIO32((port) + 0x0008)

/* Output Enable Register */
#define PIO_OER(port)			MMIO32((port) + 0x0010)

/* Output Disable Register */
#define PIO_ODR(port)			MMIO32((port) + 0x0014)

/* Output Status Register */
#define PIO_OSR(port)			MMIO32((port) + 0x0018)

/* Glitch Input Filter Enable Register */
#define PIO_IFER(port)			MMIO32((port) + 0x0020)

/* Glitch Input Filter Disable Register */
#define PIO_IFDR(port)			MMIO32((port) + 0x0024)

/* Glitch Input Filter Status Register */
#define PIO_IFSR(port)			MMIO32((port) + 0x0028)

/* Set Output Data Register */
#define PIO_SODR(port)			MMIO32((port) + 0x0030)

/* Clear Output Data Register */
#define PIO_CODR(port)			MMIO32((port) + 0x0034)

/* Output Data Status Register */
#define PIO_ODSR(port)			MMIO32((port) + 0x0038)

/* Pin Data Status Register */
#define PIO_PDSR(port)			MMIO32((port) + 0x003C)

/* Interrupt Enable Register */
#define PIO_IER(port)			MMIO32((port) + 0x0040)

/* Interrupt Disable Register */
#define PIO_IDR(port)			MMIO32((port) + 0x0044)

/* Interrupt Mask Register */
#define PIO_IMR(port)			MMIO32((port) + 0x0048)

/* Interrupt Status Register */
#define PIO_ISR(port)			MMIO32((port) + 0x004C)

/* Multi-driver Enable Register */
#define PIO_MDER(port)			MMIO32((port) + 0x0050)

/* Multi-driver Disable Register */
#define PIO_MDDR(port)			MMIO32((port) + 0x0054)

/* Multi-driver Status Register */
#define PIO_MDSR(port)			MMIO32((port) + 0x0058)

/* Pull-up Disable Register */
#define PIO_PUDR(port)			MMIO32((port) + 0x0060)

/* Pull-up Enable Register */
#define PIO_PUER(port)			MMIO32((port) + 0x0064)

/* Pad Pull-up Status Register */
#define PIO_PUSR(port)			MMIO32((port) + 0x0068)

/* Slow Clock Divider Debouncing Register */
#define PIO_SCDR(port)			MMIO32((port) + 0x008C)

/* Output Write Enable */
#define PIO_OWER(port)			MMIO32((port) + 0x00A0)

/* Output Write Disable */
#define PIO_OWDR(port)			MMIO32((port) + 0x00A4)

/* Output Write Status Register */
#define PIO_OWSR(port)			MMIO32((port) + 0x00A8)

/* Additional Interrupt Modes Enable Register */
#define PIO_AIMER(port)			MMIO32((port) + 0x00B0)

/* Additional Interrupt Modes Disables Register */
#define PIO_AIMDR(port)			MMIO32((port) + 0x00B4)

/* Additional Interrupt Modes Mask Register */
#define PIO_AIMMR(port)			MMIO32((port) + 0x00B8)

/* Edge Select Register */
#define PIO_ESR(port)			MMIO32((port) + 0x00C0)

/* Level Select Register */
#define PIO_LSR(port)			MMIO32((port) + 0x00C4)

/* Edge/Level Status Register */
#define PIO_ELSR(port)			MMIO32((port) + 0x00C8)

/* Falling Edge/Low Level Select Register */
#define PIO_FELLSR(port)		MMIO32((port) + 0x00D0)

/* Rising Edge/High Level Select Register */
#define PIO_REHLSR(port)		MMIO32((port) + 0x00D4)

/* Fall/Rise - Low/High Status Register */
#define PIO_FRLHSR(port)		MMIO32((port) + 0x00D8)

/* Lock Status */
#define PIO_LOCKSR(port)		MMIO32((port) + 0x00E0)

/* Write Protect Mode Register */
#define PIO_WPMR(port)			MMIO32((port) + 0x00E4)

/* Write Protect Status Register */
#define PIO_WPSR(port)			MMIO32((port) + 0x00E8)


#endif

#else
#warning "pio_common_all.h should not be included explicitly, only via pio.h"
#endif
