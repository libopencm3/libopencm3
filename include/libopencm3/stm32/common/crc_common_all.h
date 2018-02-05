/** @addtogroup crc_defines

@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA CRC.H
The order of header inclusion is important. crc.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_CRC_H
/** @endcond */
#ifndef LIBOPENCM3_CRC_COMMON_ALL_H
#define LIBOPENCM3_CRC_COMMON_ALL_H

/**@{*/

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

/** CRC_DR Data register */
#define CRC_DR				MMIO32(CRC_BASE + 0x00)

/** CRC_IDR Independent data register */
#define CRC_IDR				MMIO32(CRC_BASE + 0x04)

/** CRC_CR Control register */
#define CRC_CR				MMIO32(CRC_BASE + 0x08)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- CRC_DR values ------------------------------------------------------- */

/* Bits [31:0]: Data register */

/* --- CRC_IDR values ------------------------------------------------------ */

/* Bits [31:8]: Reserved */

/* Bits [7:0]: General-purpose 8-bit data register bits */


/** @defgroup crc_cr_values CRC_CR values
 @{*/
/** CRC_CR_RESET reset the CRC peripheral */
#define CRC_CR_RESET			(1 << 0)
/**@}*/

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

/* TODO */

/**
 * Reset the CRC calculator to initial values.
 */
void crc_reset(void);

/**
 * Add a word to the CRC calculator and return the result.
 * @param data new word to add to the CRC calculator
 * @return final CRC calculator value
 */
uint32_t crc_calculate(uint32_t data);

/**
 * Add a block of data to the CRC calculator and return the final result
 * @param datap pointer to the start of a block of 32bit data words
 * @param size length of data, in 32bit increments
 * @return final CRC calculator value
 */
uint32_t crc_calculate_block(uint32_t *datap, int size);

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "crc_common_all.h should not be included explicitly, only via crc.h"
#endif
/** @endcond */

