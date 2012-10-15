/** @defgroup crc_defines CRC Defines

@brief <b>libopencm3 Defined Constants and Types for the STM32F CRC Generator </b>

@ingroup STM32F_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

@date 18 August 2012

LGPL License Terms @ref lgpl_license
 */
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

/* Bits [31:0]: Data register */

/* --- CRC_IDR values ------------------------------------------------------ */

/* Bits [31:8]: Reserved */

/* Bits [7:0]: General-purpose 8-bit data register bits */

/* --- CRC_CR values ------------------------------------------------------- */

/* Bits [31:1]: Reserved */

/* RESET bit */
#define CRC_CR_RESET			(1 << 0)

/* --- CRC function prototypes --------------------------------------------- */

BEGIN_DECLS

/* TODO */

/**
 * Reset the CRC calculator to initial values.
 */
void crc_reset(void);

/**
 * Add a word to the crc calculator and return the result.
 * @param data new word to add to the crc calculator
 * @return final crc calculator value
 */
u32 crc_calculate(u32 data);

/**
 * Add a block of data to the CRC calculator and return the final result
 * @param datap pointer to the start of a block of 32bit data words
 * @param size length of data, in 32bit increments
 * @return final CRC calculator value
 */
u32 crc_calculate_block(u32 *datap, int size);

END_DECLS

#endif
