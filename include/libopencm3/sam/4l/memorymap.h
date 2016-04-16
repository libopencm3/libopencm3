/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Maxim Sloyko <maxim@sloyko.com>
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

#ifndef SAM4L_MEMORYMAP_H
#define SAM4L_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- SAM4L peripheral space -------------------------------------------- */
#define PBA_BASE			(0x40000000U)
#define PBB_BASE			(0x400A0000U)
#define AESA_BASE			(0x400B0000U)
#define PBC_BASE			(0x400E0000U)
#define PBD_BASE			(0x400F0000U)

/* --- SAM4L system controller space ------------------------------------- */
#define SMC_BASE			(0x400E0000U)
#define MATRIX_BASE			(0x400E0200U)
#define PMC_BASE			(0x400E0400U)
#define UART0_BASE			(0x400E0600U)
#define CHIPID_BASE			(0x400E0740U)
#define UART1_BASE			(0x400E0800U)
#define EEFC_BASE			(0x400E0A00U)
#define PIOA_BASE			(0x400E0E00U)
#define PIOB_BASE			(0x400E1000U)
#define PIOC_BASE			(0x400E1200U)
#define RSTC_BASE			(0x400E1400U)
#define SUPC_BASE			(0x400E1410U)
#define RTT_BASE			(0x400E1430U)
#define WDT_BASE			(0x400E1450U)
#define RTC_BASE			(0x400E1460U)
#define GPBR_BASE			(0x400E1490U)

#endif
