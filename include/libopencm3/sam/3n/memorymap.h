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

#ifndef SAM3N_MEMORYMAP_H
#define SAM3N_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- SAM3N peripheral space -------------------------------------------- */

#define SPI_BASE			(0x40008000)
#define TC0_BASE			(0x40010000)
#define TC1_BASE			(0x40010040)
#define TC2_BASE			(0x40010080)
#define TC3_BASE			(0x40014000)
#define TC4_BASE			(0x40014040)
#define TC5_BASE			(0x40014080)
#define TWI0_BASE			(0x40018000)
#define TWI1_BASE			(0x4001C000)
#define PWM_BASE			(0x40020000)
#define USART0_BASE			(0x40024000)
#define USART1_BASE			(0x40028000)
#define ADC_BASE			(0x40038000)
#define DACC_BASE			(0x4003C000)

/* --- SAM3N system controller space ------------------------------------- */
#define SMC_BASE			(0x400E0000)
#define MATRIX_BASE			(0x400E0200)
#define PMC_BASE			(0x400E0400)
#define UART0_BASE			(0x400E0600)
#define CHIPID_BASE			(0x400E0740)
#define UART1_BASE			(0x400E0800)
#define EEFC_BASE			(0x400E0A00)
#define PIOA_BASE			(0x400E0E00)
#define PIOB_BASE			(0x400E1000)
#define PIOC_BASE			(0x400E1200)
#define RSTC_BASE			(0x400E1400)
#define SUPC_BASE			(0x400E1410)
#define RTT_BASE			(0x400E1430)
#define WDT_BASE			(0x400E1450)
#define RTC_BASE			(0x400E1460)
#define GPBR_BASE			(0x400E1490)

#endif
