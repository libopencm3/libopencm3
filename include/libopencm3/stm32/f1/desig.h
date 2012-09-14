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

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Device Electronic Signature -------------------------------- */

/* Flash size register */
#define DESIG_FLASH_SIZE		MMIO16(DESIG_FLASH_SIZE_BASE + 0x00)

/* Unique ID register (96 bits) */
/* Note: ST says these may be accessed in any width if you choose */
#define DESIG_UID_15_0			MMIO16(DESIG_UNIQUE_ID_BASE + 0x00)
/* Listed as "This field value is also reserved for a future feature" WTH?! */
#define DESIG_UID_31_16			MMIO16(DESIG_UNIQUE_ID_BASE + 0x02)
#define DESIG_UID_63_32			MMIO32(DESIG_UNIQUE_ID_BASE + 0x04)
#define DESIG_UID_95_64			MMIO32(DESIG_UNIQUE_ID_BASE + 0x08)

BEGIN_DECLS

/**
 * Read the onboard flash size
 * @return flash size in KB
 */
u16 desig_get_flash_size(void);

/**
 * Read the full 96 bit unique identifier
 * Note: ST specifies that bits 31..16 are _also_ reserved for future use
 * @param result pointer to at least 3xu32s (96 bits)
 */
void desig_get_unique_id(u32 result[]);

END_DECLS

#endif
