/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

#ifndef LIBOPENCM3_MEMORYMAP_H
#define LIBOPENCM3_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- VF6xx specific peripheral definitions ----------------------------- */

/* Memory map for all busses */
#define PERIPH_BASE			(0x40000000U)
#define PERIPH_BASE_AIPS0		(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_AIPS1		(PERIPH_BASE + 0x80000)

/* Pheripheral addresses */

/* AIPS0 */
#define MSCM_BASE			(PERIPH_BASE_AIPS0 + 0x01000)

#define SEMA4_BASE			(PERIPH_BASE_AIPS0 + 0x1D000)

#define UART0_BASE			(PERIPH_BASE_AIPS0 + 0x27000)
#define UART1_BASE			(PERIPH_BASE_AIPS0 + 0x28000)
#define UART2_BASE			(PERIPH_BASE_AIPS0 + 0x29000)
#define UART3_BASE			(PERIPH_BASE_AIPS0 + 0x2A000)

#define SPI0_BASE			(PERIPH_BASE_AIPS0 + 0x2C000)
#define SPI1_BASE			(PERIPH_BASE_AIPS0 + 0x2D000)

#define IOMUXC_BASE			(PERIPH_BASE_AIPS0 + 0x48000)
#define PORTA_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x49000)
#define PORTB_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x4A000)
#define PORTC_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x4B000)
#define PORTD_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x4C000)
#define PORTE_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x4D000)

#define ANADIG_BASE			(PERIPH_BASE_AIPS0 + 0x50000)

#define CCM_BASE			(PERIPH_BASE_AIPS0 + 0x6B000)

/* AIPS1 */
#define UART4_BASE			(PERIPH_BASE_AIPS1 + 0x29000)
#define UART5_BASE			(PERIPH_BASE_AIPS1 + 0x2A000)

/* GPIO module */
#define GPIO_BASE			(PERIPH_BASE + 0xff000)

#endif
