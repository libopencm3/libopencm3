/** @defgroup crc_defines CRC Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F3xx CRC Generator </b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 18 August 2012
 *
 * LGPL License Terms @ref lgpl_license
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

#include <libopencm3/stm32/common/crc_common_all.h>

/* --- CRC registers ------------------------------------------------------- */

/* Initial CRC value (CRC_INIT) */
#define CRC_INIT			MMIO32(CRC_BASE + 0x10)

/* CRC polynomial (CRC_POL) */
#define CRC_POL				MMIO32(CRC_BASE + 0x14)

/* --- CRC_CR values ------------------------------------------------------- */

/* REV_OUT: Reverse output data */
#define CRC_CR_REV_OUT			(1 << 7)

/* REV_IN[1:0]: Reverse input data */
#define CRC_CR_REV_IN_NOT_AFFECTED	(0x0 << 5)
#define CRC_CR_REV_IN_BYTE		(0x1 << 5)
#define CRC_CR_REV_IN_HALF_WORD		(0x2 << 5)
#define CRC_CR_REV_IN_WORD		(0x3 << 5)

/* POLYSIZE[1:0]: Polynomial size */
#define CRC_CR_POLYSIZE_32		(0x0 << 3)
#define CRC_CR_POLYSIZE_16		(0x1 << 3)
#define CRC_CR_POLYSIZE_8		(0x2 << 3)
#define CRC_CR_POLYSIZE_7		(0x3 << 3)

/* --- CRC_INIT values ----------------------------------------------------- */

/* Bits 31:0 CRC_INIT: Programmable initial CRC value */

/* --- CRC_POL values ------------------------------------------------------ */

/* Bits 31:0 POL[31:0]: Programmable polynomial */

#endif
