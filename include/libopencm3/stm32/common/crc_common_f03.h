/** @addtogroup crc_defines

 @author @htmlonly &copy; @endhtmlonly 2016 Cem Basoglu <cem.basoglu@web.de>

 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Cem Basoglu <cem.basoglu@web.de
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
#ifndef LIBOPENCM3_CRC_COMMON_F03_H
#define LIBOPENCM3_CRC_COMMON_F03_H

/**@{*/

#include <libopencm3/stm32/common/crc_common_all.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

/* Data register (CRC_DR) */
#define CRC_DR8 					MMIO8(CRC_BASE + 0x00)
#define CRC_DR16					MMIO16(CRC_BASE + 0x00)

/* Initial CRC Value */
#define CRC_INIT					MMIO32(CRC_BASE + 0x10)

/* CRC Polynomial */
#define CRC_POL						MMIO32(CRC_BASE + 0x14)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

#define CRC_CR_REV_OUT				(1 << 7)

#define CRC_CR_REV_IN_SHIFT			5
#define CRC_CR_REV_IN				(3 << CRC_CR_REV_IN_SHIFT)
#define CRC_CR_REV_IN_NONE			(0 << CRC_CR_REV_IN_SHIFT)
#define CRC_CR_REV_IN_BYTE			(1 << CRC_CR_REV_IN_SHIFT)
#define CRC_CR_REV_IN_HALF			(2 << CRC_CR_REV_IN_SHIFT)
#define CRC_CR_REV_IN_WORD			(3 << CRC_CR_REV_IN_SHIFT)

#define CRC_CR_POLYSIZE_SHIFT		3
#define CRC_CR_POLYSIZE				(3 << CRC_CR_POLYSIZE_SHIFT)
#define CRC_CR_POLYSIZE_32BIT		(0 << CRC_CR_POLYSIZE_SHIFT)
#define CRC_CR_POLYSIZE_16BIT		(1 << CRC_CR_POLYSIZE_SHIFT)
#define CRC_CR_POLYSIZE_8BIT		(2 << CRC_CR_POLYSIZE_SHIFT)
#define CRC_CR_POLYSIZE_7BIT		(3 << CRC_CR_POLYSIZE_SHIFT)

/* Default polynomial */
#define CRC_POL_DEFAULT				0x04C11DB7

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void crc_reverse_output_enable(void);
void crc_reverse_output_disable(void);

void crc_set_reverse_input(uint32_t reverse_in);
void crc_set_polysize(uint32_t polysize);

void crc_set_polynomial(uint32_t polynomial);
void crc_set_initial(uint32_t initial);

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "crc_common_f03.h should not be included explicitly, only via crc.h"
#endif
/** @endcond */

