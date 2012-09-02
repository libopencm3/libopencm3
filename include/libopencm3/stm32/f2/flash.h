/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
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
 * For details see:
 * PM0059 Programming manual: STM32F205xx, STM32F207xx, STM32F215xx, STM32F217xx
 * Flash programming
 * May 2011, Doc ID 15687 Rev 4
 * http://www.st.com/internet/com/TECHNICAL_RESOURCES/TECHNICAL_LITERATURE/PROGRAMMING_MANUAL/CD00233952.pdf
 */

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- FLASH registers ----------------------------------------------------- */

#define FLASH_ACR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)
#define FLASH_KEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)
#define FLASH_OPTKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)
#define FLASH_SR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C)
#define FLASH_CR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10)
#define FLASH_OPTCR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)

/* --- FLASH_ACR values ---------------------------------------------------- */

#define FLASH_DCRST			(1 << 12)
#define FLASH_ICRST			(1 << 11)
#define FLASH_DCE			(1 << 10)
#define FLASH_ICE			(1 << 9)
#define FLASH_PRFTEN			(1 << 8)
#define FLASH_LATENCY_0WS		0x00
#define FLASH_LATENCY_1WS		0x01
#define FLASH_LATENCY_2WS		0x02
#define FLASH_LATENCY_3WS		0x03
#define FLASH_LATENCY_4WS		0x04
#define FLASH_LATENCY_5WS		0x05
#define FLASH_LATENCY_6WS		0x06
#define FLASH_LATENCY_7WS		0x07

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_BSY			(1 << 16)
#define FLASH_PGSERR			(1 << 7)
#define FLASH_PGPERR			(1 << 6)
#define FLASH_PGAERR			(1 << 5)
#define FLASH_WRPERR			(1 << 4)
#define FLASH_OPERR			(1 << 1)
#define FLASH_EOP			(1 << 0)

/* --- FLASH_CR values ----------------------------------------------------- */

#define FLASH_LOCK			(1 << 31)
#define FLASH_ERRIE			(1 << 25)
#define FLASH_EOPIE			(1 << 24)
#define FLASH_STRT			(1 << 16)
#define FLASH_MER			(1 << 2)
#define FLASH_SER			(1 << 1)
#define FLASH_PG			(1 << 0)
#define FLASH_SECTOR_0			(0x00 << 3)
#define FLASH_SECTOR_1			(0x01 << 3)
#define FLASH_SECTOR_2			(0x02 << 3)
#define FLASH_SECTOR_3			(0x03 << 3)
#define FLASH_SECTOR_4			(0x04 << 3)
#define FLASH_SECTOR_5			(0x05 << 3)
#define FLASH_SECTOR_6			(0x06 << 3)
#define FLASH_SECTOR_7			(0x07 << 3)
#define FLASH_SECTOR_8			(0x08 << 3)
#define FLASH_SECTOR_9			(0x09 << 3)
#define FLASH_SECTOR_10			(0x0a << 3)
#define FLASH_SECTOR_11			(0x0b << 3)
#define FLASH_PROGRAM_X8		(0x00 << 8)
#define FLASH_PROGRAM_X16		(0x01 << 8)
#define FLASH_PROGRAM_X32		(0x02 << 8)
#define FLASH_PROGRAM_X64		(0x03 << 8)

/* --- FLASH_OPTCR values -------------------------------------------------- */

/* FLASH_OPTCR[27:16]: nWRP */
/* FLASH_OBR[15:8]: RDP */
#define FLASH_NRST_STDBY		(1 << 7)
#define FLASH_NRST_STOP			(1 << 6)
#define FLASH_WDG_SW			(1 << 5)
#define FLASH_OPTSTRT			(1 << 1)
#define FLASH_OPTLOCK			(1 << 0)
#define FLASH_BOR_LEVEL_3		(0x00 << 2)
#define FLASH_BOR_LEVEL_2		(0x01 << 2)
#define FLASH_BOR_LEVEL_1		(0x02 << 2)
#define FLASH_BOR_OFF			(0x03 << 2)

/* --- FLASH Keys -----------------------------------------------------------*/

#define FLASH_KEY1			((u32)0x45670123)
#define FLASH_KEY2			((u32)0xcdef89ab)
#define FLASH_OPTKEY1			((u32)0x08192a3b)
#define FLASH_OPTKEY2			((u32)0x4c5d6e7f)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_dcache_enable(void);
void flash_dcache_disable(void);
void flash_icache_enable(void);
void flash_icache_disable(void);
void flash_prefetch_enable(void);
void flash_prefetch_disable(void);
void flash_dcache_reset(void);
void flash_icache_reset(void);
void flash_set_ws(u32 ws);
void flash_unlock(void);
void flash_lock(void);
void flash_clear_pgserr_flag(void);
void flash_clear_pgperr_flag(void);
void flash_clear_pgaerr_flag(void);
void flash_clear_eop_flag(void);
void flash_clear_wrperr_flag(void);
void flash_clear_bsy_flag(void);
void flash_clear_status_flags(void);
void flash_unlock_option_bytes(void);
void flash_lock_option_bytes(void);
void flash_erase_all_sectors(u32 program_size);
void flash_erase_sector(u32 sector, u32 program_size);
void flash_program_double_word(u32 address, u64 data, u32 program_size);
void flash_program_word(u32 address, u32 data, u32 program_size);
void flash_program_half_word(u32 address, u16 data, u32 program_size);
void flash_program_byte(u32 address, u8 data, u32 program_size);
void flash_wait_for_last_operation(void);
void flash_program_option_bytes(u32 data);

END_DECLS

#endif
