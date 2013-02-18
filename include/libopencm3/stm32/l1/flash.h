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
 * All extracted from PM0062 rev2, L15xx and L16xx Flash/EEPROM programming manual
 */

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- FLASH registers ----------------------------------------------------- */

#define FLASH_ACR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)
#define FLASH_PECR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)
#define FLASH_PDKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)
#define FLASH_PEKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C)
#define FLASH_PRGKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10)
#define FLASH_OPTKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)
#define FLASH_SR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x18)
#define FLASH_OBR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x1c)
#define FLASH_WRPR1			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x20)
#define FLASH_WRPR2			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x80)
#define FLASH_WRPR3			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x84)

/* --- FLASH_ACR values ---------------------------------------------------- */

#define FLASH_RUNPD			(1 << 4)
#define FLASH_SLEEPPD			(1 << 3)
#define FLASH_ACC64			(1 << 2)
#define FLASH_PRFTEN			(1 << 1)
#define FLASH_LATENCY_0WS		0x00
#define FLASH_LATENCY_1WS		0x01

/* --- FLASH_PECR values. Program/erase control register */
#define FLASH_OBL_LAUNCH    (1 << 18)
#define FLASH_ERRIE         (1 << 17)
#define FLASH_EOPIE         (1 << 16)
#define FLASH_PARALLBANK    (1 << 15)
#define FLASH_FPRG          (1 << 10)
#define FLASH_ERASE         (1 << 9)
#define FLASH_FTDW          (1 << 8)
#define FLASH_FTDW          (1 << 8)
#define FLASH_DATA          (1 << 4)
#define FLASH_PROG          (1 << 3)
#define FLASH_OPTLOCK       (1 << 2)
#define FLASH_PRGLOCK       (1 << 1)
#define FLASH_PELOCK        (1 << 0)

/* Power down key register (FLASH_PDKEYR) */
#define FLASH_PDKEY1        ((u32)0x04152637)
#define FLASH_PDKEY2        ((u32)0xFAFBFCFD)

/* Program/erase key register (FLASH_PEKEYR) */
#define FLASH_PEKEY1        ((u32)0x89ABCDEF)
#define FLASH_PEKEY2        ((u32)0x02030405)

/* Program memory key register (FLASH_PRGKEYR) */
#define FLASH_PRGKEY1       ((u32)0x8C9DAEBF)
#define FLASH_PRGKEY2       ((u32)0x13141516)

/* Option byte key register (FLASH_OPTKEYR) */
#define FLASH_OPTKEY1       ((u32)0xFBEAD9C8)
#define FLASH_OPTKEY2       ((u32)0x24252627)


/* --- FLASH_SR values ----------------------------------------------------- */
#define FLASH_OPTVERRUSR	(1 << 12)
#define FLASH_OPTVERR		(1 << 11)
#define FLASH_SIZEERR		(1 << 10)
#define FLASH_PGAERR		(1 << 9)
#define FLASH_WRPERR		(1 << 8)
#define FLASH_READY		(1 << 3)
#define FLASH_ENDHV		(1 << 2)
#define FLASH_EOP		(1 << 1)
#define FLASH_BSY		(1 << 0)

/* --- FLASH_OBR values ----------------------------------------------------- */
#define FLASH_BFB2		(1 << 23)
#define FLASH_NRST_STDBY	(1 << 22)
#define FLASH_NRST_STOP		(1 << 21)
#define FLASH_IWDG_SW		(1 << 20)
#define FLASH_BOR_OFF		(0x0 << 16)
#define FLASH_BOR_LEVEL_1	(0x8 << 16)
#define FLASH_BOR_LEVEL_2	(0x9 << 16)
#define FLASH_BOR_LEVEL_3	(0xa << 16)
#define FLASH_BOR_LEVEL_4	(0xb << 16)
#define FLASH_BOR_LEVEL_5	(0xc << 16)
#define FLASH_RDPRT_LEVEL_0	(0xaa)
#define FLASH_RDPRT_LEVEL_1	(0x00)
#define FLASH_RDPRT_LEVEL_2	(0xcc)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_64bit_enable(void);
void flash_64bit_disable(void);
void flash_prefetch_enable(void);
void flash_prefetch_disable(void);
void flash_set_ws(u32 ws);

END_DECLS

#endif
