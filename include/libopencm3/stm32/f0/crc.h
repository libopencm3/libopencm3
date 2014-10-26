/** @defgroup crc_defines CRC Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32F1xx CRC
 * Generator </b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @version 1.0.0
 *
 * @date 29 Jun 2013
 *
 *LGPL License Terms @ref lgpl_license
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
/**@{*/

#include <libopencm3/stm32/common/crc_common_all.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

/* Initial CRC Value */
#define CRC_INIT			MMIO32(CRC_BASE + 0x10)

/* CRC Polynomial */
#define CRC_POL				MMIO32(CRC_BASE + 0x14)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

#define CRC_CR_REV_OUT			(1 << 7)

#define CRC_CR_REV_IN_SHIFT		5
#define CRC_CR_REV_IN			(3 << CRC_CR_REV_IN_SHIFT)
#define CRC_CR_REV_IN_NONE		(0 << CRC_CR_REV_IN_SHIFT)
#define CRC_CR_REV_IN_BYTE		(1 << CRC_CR_REV_IN_SHIFT)
#define CRC_CR_REV_IN_HALF		(2 << CRC_CR_REV_IN_SHIFT)
#define CRC_CR_REV_IN_WORD		(3 << CRC_CR_REV_IN_SHIFT)

#define CRC_CR_POLYSIZE_SHIFT		3
#define CRC_CR_POLYSIZE			(3 << CRC_CR_POLYSIZE_SHIFT)
#define CRC_CR_POLYSIZE_32BIT		(0 << CRC_CR_POLYSIZE_SHIFT)
#define CRC_CR_POLYSIZE_16BIT		(1 << CRC_CR_POLYSIZE_SHIFT)
#define CRC_CR_POLYSIZE_8BIT		(2 << CRC_CR_POLYSIZE_SHIFT)
#define CRC_CR_POLYSIZE_7BIT		(3 << CRC_CR_POLYSIZE_SHIFT)

/* Default polynomial */
#define CRC_POL_DEFAULT			0x04C11DB7

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS
/**@}*/

#endif
