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

#define HSMCI_BASE			(0x40000000U)
#define SSC_BASE			(0x40004000U)
#define SPI0_BASE			(0x40008000U)
#define SPI1_BASE			(0x4000C000U)
#define TC0_BASE			(0x40080000U)
#define TC1_BASE			(0x40080040U)
#define TC2_BASE			(0x40080080U)
#define TC3_BASE			(0x40084000U)
#define TC4_BASE			(0x40084040U)
#define TC5_BASE			(0x40084080U)
#define TC6_BASE			(0x40088000U)
#define TC7_BASE			(0x40088040U)
#define TC8_BASE			(0x40088080U)
#define TWI0_BASE			(0x4008C000U)
#define TWI1_BASE			(0x40090000U)
#define PWM_BASE			(0x40094000U)
#define USART0_BASE			(0x40098000U)
#define USART1_BASE			(0x4009C000U)
#define USART2_BASE			(0x400A0000U)
#define USART3_BASE			(0x400A4000U)
#define UOTGHS_BASE			(0x400AC000U)
#define EMAC_BASE			(0x400B0000U)
#define CAN0_BASE			(0x400B4000U)
#define CAN1_BASE			(0x400B8000U)
#define TRNG_BASE			(0x400BC000U)
#define ADC_BASE			(0x400C0000U)
#define DMAC_BASE			(0x400C4000U)
#define DACC_BASE			(0x400C8000U)

/* --- SAM3X system controller space ------------------------------------- */
#define SMC_BASE			(0x400E0000U)
#define SDRAM_BASE			(0x400E0200U)
#define MATRIX_BASE			(0x400E0400U)
#define PMC_BASE			(0x400E0600U)
#define UART_BASE			(0x400E0800U)
#define CHIPID_BASE			(0x400E0940U)
#define EEFC0_BASE			(0x400E0A00U)
#define EEFC1_BASE			(0x400E0C00U)
#define PIOA_BASE			(0x400E0E00U)
#define PIOB_BASE			(0x400E1000U)
#define PIOC_BASE			(0x400E1200U)
#define PIOD_BASE			(0x400E1400U)
#define PIOE_BASE			(0x400E1600U)
#define PIOF_BASE			(0x400E1800U)
#define RSTC_BASE			(0x400E1A00U)
#define SUPC_BASE			(0x400E1A10U)
#define RTT_BASE			(0x400E1A30U)
#define WDT_BASE			(0x400E1A50U)
#define RTC_BASE			(0x400E1A60U)
#define GPBR_BASE			(0x400E1A90U)

#endif
