/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_CRC_H
#define LIBOPENCM3_CRC_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- CRC registers ------------------------------------------------------- */

/* Data register (CRC_DR) */
#define CRC_DR				MMIO32(CRC_BASE + 0x00)

/* Independent data register (CRC_IDR) */
#define CRC_IDR				MMIO32(CRC_BASE + 0x04)

/* Control register (CRC_CR) */
#define CRC_CR				MMIO32(CRC_BASE + 0x08)

/* --- CRC_DR values ------------------------------------------------------- */

/* Bits[31:0] Data register */

/* --- CRC_IDR values ------------------------------------------------------ */

/* Bits[7:0] General-purpose 8-bit data register bits */

/* --- CRC_CR values ------------------------------------------------------- */

/* RESET bit */
#define CRC_CR_RESET			(1 << 0)

/* --- CRC function prototypes --------------------------------------------- */

#endif
