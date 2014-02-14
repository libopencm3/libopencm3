/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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

#ifndef LIBOPENCM3_DESIG_H
#define LIBOPENCM3_DESIG_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define DESIG				DESIG_BASE

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#if defined(STM32L1)
#define DESIG_FLASH_SIZE(base)		MMIO16((base) + 0x0C)
#define DESIG_UNIQUE_ID0(base)		MMIO32((base) + 0x10 + 0)
#define DESIG_UNIQUE_ID1(base)		MMIO32((base) + 0x10 + 4)
#define DESIG_UNIQUE_ID2(base)		MMIO32((base) + 0x10 + 0x14)
#endif

#if defined(STM32F1)
#define DESIG_FLASH_SIZE(base)		MMIO16((base) + 0x00)
#define DESIG_UNIQUE_ID0(base)		MMIO32((base) + 0x08 + 0)
#define DESIG_UNIQUE_ID1(base)		MMIO32((base) + 0x08 + 4)
#define DESIG_UNIQUE_ID2(base)		MMIO32((base) + 0x08 + 8)
#endif

#if defined(STM32F0) || defined(STM32F3)
#define DESIG_FLASH_SIZE(base)		MMIO16((base) + 0x2C)
#define DESIG_UNIQUE_ID0(base)		MMIO32((base) + 0x0C + 0)
#define DESIG_UNIQUE_ID1(base)		MMIO32((base) + 0x0C + 4)
#define DESIG_UNIQUE_ID2(base)		MMIO32((base) + 0x0C + 8)
#endif

#if defined(STM32F2) || defined(STM32F4)
#define DESIG_FLASH_SIZE(base)		MMIO16((base) + 0x12)
#define DESIG_UNIQUE_ID0(base)		MMIO32((base) + 0x00 + 0)
#define DESIG_UNIQUE_ID1(base)		MMIO32((base) + 0x00 + 4)
#define DESIG_UNIQUE_ID2(base)		MMIO32((base) + 0x00 + 8)
#endif

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

/**
 * Read the on board flash size
 * @return flash size in KB
 */
uint16_t desig_get_flash_size(uint32_t base);

/**
 * Read the full 96 bit unique identifier
 * Note: ST specifies that bits 31..16 are _also_ reserved for future use
 * @param result pointer to at least 3xuint32_ts (96 bits)
 */
void desig_get_unique_id(uint32_t base, uint32_t result[]);

/**
 * Read the full 96 bit unique identifier and return it as a
 * zero-terminated string
 * @param string memory region to write the result to
 * @param string_len the size of string in bytes
 */
void desig_get_unique_id_as_string(uint32_t base, char *string,
				   unsigned int string_len);

END_DECLS

#endif
