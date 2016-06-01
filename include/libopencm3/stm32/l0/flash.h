/** @defgroup flash_defines FLASH Defines
 *
 * @ingroup STM32L0xx_defines
 *
 * @brief Defined Constants and Types for the STM32L0xx FLASH Memory
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2016
 * flabbergast <s3+flabbergast@sdfeu.org>
 *
 * @date 23 May 2016
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
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

/*
 * All extracted from RM0376 rev 3, STM32L0x2 reference manual.
 */

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H
/**@{*/

#include <libopencm3/stm32/common/flash_common_l01.h>

/* --- FLASH registers ----------------------------------------------------- */

/* FLASH_OPTR is the new name for FLASH_OBR */
/* FLASH_WRPROTn are the new names for FLASH_WRPRn */
#define FLASH_OPTR				MMIO32(FLASH_MEM_INTERFACE_BASE + 0x1c)
#define FLASH_WRPROT1			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x20)
#define FLASH_WRPROT2			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x80)

/* --- FLASH_OBR values ----------------------------------------------------- */
/* most of these can be also referred to as FLASH_OBR_* */
#define FLASH_OPTR_NBOOT1		(1 << 31)
#define FLASH_OPTR_BFB2			(1 << 23)
#define FLASH_OPTR_NRST_STBY	(1 << 22)
#define FLASH_OPTR_NRST_STOP	(1 << 21)
#define FLASH_OPTR_WDG_SW		(1 << 20)
#define FLASH_OPTR_BOR_OFF		(0x0 << 16)
#define FLASH_OPTR_BOR_LEVEL_1	(0x8 << 16)
#define FLASH_OPTR_BOR_LEVEL_2	(0x9 << 16)
#define FLASH_OPTR_BOR_LEVEL_3	(0xa << 16)
#define FLASH_OPTR_BOR_LEVEL_4	(0xb << 16)
#define FLASH_OPTR_BOR_LEVEL_5	(0xc << 16)
#define FLASH_OPTR_RDPRT_LEVEL_0	(0xaa)
#define FLASH_OPTR_RDPRT_LEVEL_1	(0x00)
#define FLASH_OPTR_RDPRT_LEVEL_2	(0xcc)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

/* TODO (DISAB_BUF, PRE_READ) */

void flash_program_word(uint32_t address, uint32_t data);
void flash_program_half_page(uint32_t address, uint32_t *data, uint16_t page_size);
void flash_erase_page(uint32_t address);
void flash_erase_all_pages(void);
void flash_erase_option_byte(uint32_t address);
void flash_program_option_byte(uint32_t address, uint16_t data);

END_DECLS
/**@}*/

#endif
