/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#ifndef LIBOPENCM3_WWDG_H
#define LIBOPENCM3_WWDG_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

/* --- WWDG registers ------------------------------------------------------ */

/* Control register (WWDG_CR) */
#define WWDG_CR				MMIO32(WWDG_BASE + 0x00)

/* Configuration register (WWDG_CFR) */
#define WWDG_CFR			MMIO32(WWDG_BASE + 0x04)

/* Status register (WWDG_SR) */
#define WWDG_SR				MMIO32(WWDG_BASE + 0x08)

/* --- WWDG_CR values ------------------------------------------------------ */

/* Bits [31:8]: Reserved */

/* WDGA: Activation bit */
#define WWDG_CR_WDGA			(1 << 7)

/* T[6:0]: 7-bit counter (MSB to LSB) */
#define WWDG_CR_T_LSB			0
#define WWDG_CR_T0			(1 << 0)
#define WWDG_CR_T1			(1 << 1)
#define WWDG_CR_T2			(1 << 2)
#define WWDG_CR_T3			(1 << 3)
#define WWDG_CR_T4			(1 << 4)
#define WWDG_CR_T5			(1 << 5)
#define WWDG_CR_T6			(1 << 6)

/* --- WWDG_CFR values ----------------------------------------------------- */

/* Bits [31:10]: Reserved */

/* EWI: Early wakeup interrupt */
#define WWDG_CFR_EWI			(1 << 9)

/* WDGTB[8:7]: Timer base */
#define WWDG_CFR_WDGTB_LSB		7
#define WWDG_CFR_WDGTB_CK_DIV1		0x0
#define WWDG_CFR_WDGTB_CK_DIV2		0x1
#define WWDG_CFR_WDGTB_CK_DIV4		0x2
#define WWDG_CFR_WDGTB_CK_DIV8		0x3

/* W[6:0]: 7-bit window value */
#define WWDG_CFG_W_LSB			0
#define WWDG_CFG_W			(1 << 0)

/* --- WWDG_SR values ------------------------------------------------------ */

/* Bits [31:1]: Reserved */

/* EWIF: Early wakeup interrupt flag */
#define WWDG_SR_EWIF			(1 << 0)

/* --- WWDG function prototypes---------------------------------------------- */

/* TODO */

#endif
