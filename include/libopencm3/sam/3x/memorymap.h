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

#ifndef SAM3X_MEMORYMAP_H
#define SAM3X_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- SAM3X peripheral space -------------------------------------------- */

#define HSMCI_BASE			(0x40000000)
#define SSC_BASE			(0x40004000)
#define SPI0_BASE			(0x40008000)
#define SPI1_BASE			(0x4000C000)
#define TC0_BASE			(0x40080000)
#define TC1_BASE			(0x40080040)
#define TC2_BASE			(0x40080080)
#define TC3_BASE			(0x40084000)
#define TC4_BASE			(0x40084040)
#define TC5_BASE			(0x40084080)
#define TC6_BASE			(0x40088000)
#define TC7_BASE			(0x40088040)
#define TC8_BASE			(0x40088080)
#define TWI0_BASE			(0x4008C000)
#define TWI1_BASE			(0x40090000)
#define PWM_BASE			(0x40094000)
#define USART0_BASE			(0x40098000)
#define USART1_BASE			(0x4009C000)
#define USART2_BASE			(0x400A0000)
#define USART3_BASE			(0x400A4000)
#define UOTGHS_BASE			(0x400AC000)
#define EMAC_BASE			(0x400B0000)
#define CAN0_BASE			(0x400B4000)
#define CAN1_BASE			(0x400B8000)
#define TRNG_BASE			(0x400BC000)
#define ADC_BASE			(0x400C0000)
#define DMAC_BASE			(0x400C4000)

/* --- SAM3X system controller space ------------------------------------- */
#define SMC_BASE			(0x400E0000)
#define SDRAM_BASE			(0x400E0200)
#define MATRIX_BASE			(0x400E0400)
#define PMC_BASE			(0x400E0600)
#define UART_BASE			(0x400E0800)
#define CHIPID_BASE			(0x400E0940)
#define EEFC0_BASE			(0x400E0A00)
#define EEFC1_BASE			(0x400E0C00)
#define PIOA_BASE			(0x400E0E00)
#define PIOB_BASE			(0x400E1000)
#define PIOC_BASE			(0x400E1200)
#define PIOD_BASE			(0x400E1400)
#define PIOE_BASE			(0x400E1600)
#define PIOF_BASE			(0x400E1800)
#define RSTC_BASE			(0x400E1A00)
#define SUPC_BASE			(0x400E1A10)
#define RTT_BASE			(0x400E1A30)
#define WDT_BASE			(0x400E1A50)
#define RTC_BASE			(0x400E1A60)
#define GPBR_BASE			(0x400E1A90)
#define RTC_BASE			(0x400E1A60)

#endif
