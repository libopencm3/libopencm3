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

#ifndef SAM3S_MEMORYMAP_H
#define SAM3S_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- SAM3S peripheral space -------------------------------------------- */
#define HSMCI_BASE			(0x40000000U)
#define SSC_BASE			(0x40004000U)
#define SPI_BASE			(0x40008000U)
#define TC0_BASE			(0x40010000U)
#define TC1_BASE			(0x40010040U)
#define TC2_BASE			(0x40010080U)
#define TC3_BASE			(0x40014000U)
#define TC4_BASE			(0x40014040U)
#define TC5_BASE			(0x40014080U)
#define TWI0_BASE			(0x40018000U)
#define TWI1_BASE			(0x4001C000U)
#define PWM_BASE			(0x40020000U)
#define USART0_BASE			(0x40024000U)
#define USART1_BASE			(0x40028000U)
#define USART2_BASE			(0x4002C000U)
#define UDP_BASE			(0x40034000U)
#define ADC_BASE			(0x40038000U)
#define DACC_BASE			(0x4003C000U)
#define ACC_BASE			(0x40040000U)
#define CRCCU_BASE			(0x40044000U)

/* --- SAM3S system controller space ------------------------------------- */
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
