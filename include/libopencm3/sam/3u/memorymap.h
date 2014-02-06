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

#ifndef SAM3U_MEMORYMAP_H
#define SAM3U_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- SAM3U peripheral space -------------------------------------------- */
#define HSMCI_BASE			(0x40000000U)
#define SSC_BASE			(0x40004000U)
#define SPI_BASE			(0x40008000U)
#define TC0_BASE			(0x40080000U)
#define TC1_BASE			(0x40080040U)
#define TC2_BASE			(0x40080080U)
#define TWI0_BASE			(0x40084000U)
#define TWI1_BASE			(0x40088000U)
#define PWM_BASE			(0x4008C000U)
#define USART0_BASE			(0x40090000U)
#define USART1_BASE			(0x40094000U)
#define USART2_BASE			(0x40098000U)
#define USART3_BASE			(0x4009C000U)
#define UDPHS_BASE			(0x400A4000U)
#define ADC12B_BASE			(0x400A8000U)
#define ADC_BASE			(0x400AC000U)
#define DMAC_BASE			(0x400B0000U)

/* --- SAM3U system controller space ------------------------------------- */
#define SMC_BASE			(0x400E0000U)
#define MATRIX_BASE			(0x400E0200U)
#define PMC_BASE			(0x400E0400U)
#define UART_BASE			(0x400E0600U)
#define CHIPID_BASE			(0x400E0740U)
#define EEFC0_BASE			(0x400E0800U)
#define EEFC1_BASE			(0x400E0A00U)
#define PIOA_BASE			(0x400E0C00U)
#define PIOB_BASE			(0x400E0E00U)
#define PIOC_BASE			(0x400E1000U)
#define RSTC_BASE			(0x400E1200U)
#define SUPC_BASE			(0x400E1210U)
#define RTT_BASE			(0x400E1230U)
#define WDT_BASE			(0x400E1250U)
#define RTC_BASE			(0x400E1260U)
#define GPBR_BASE			(0x400E1290U)

#endif
