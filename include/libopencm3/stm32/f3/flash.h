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
 * PM0081 Programming manual: STM32F30xxx and STM32F31xxx Flash programming
 * September 2011, Doc ID 018520 Rev 1
 * http://www.st.com/internet/com/TECHNICAL_RESOURCES/TECHNICAL_LITERATURE/PROGRAMMING_MANUAL/DM00023388.pdf
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
#define FLASH_AR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)
#define FLASH_OBR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x1C)
#define FLASH_WRPR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x20)

/* --- FLASH_ACR values ---------------------------------------------------- */

#define FLASH_LATENCY_0WS		0x00
#define FLASH_LATENCY_1WS		0x01
#define FLASH_LATENCY_2WS		0x02
#define FLASH_LATENCY_3WS		0x03
#define FLASH_LATENCY_4WS		0x04
#define FLASH_LATENCY_5WS		0x05
#define FLASH_LATENCY_6WS		0x06
#define FLASH_LATENCY_7WS		0x07
#define FLASH_PRFTBS			(1 << 5)
#define FLASH_PRFTBE			(1 << 4)
#define FLASH_HLFCYA			(1 << 3)

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_BSY			(1 << 0)
#define FLASH_ERLYBSY			(1 << 1)
#define FLASH_PGPERR			(1 << 2)
#define FLASH_WRPRTERR			(1 << 4)
#define FLASH_EOP			(1 << 5)


/* --- FLASH_CR values ----------------------------------------------------- */

#define FLASH_OBL_LAUNCH		(1 << 13)
#define FLASH_EOPIE			(1 << 12)
#define FLASH_ERRIE			(1 << 10)
#define FLASH_OPTWRE			(1 << 9)
#define FLASH_LOCK			(1 << 7)
#define FLASH_STRT			(1 << 6)
#define FLASH_OPTER			(1 << 5)
#define FLASH_OPTPG			(1 << 4)
#define FLASH_MER			(1 << 2)
#define FLASH_PER			(1 << 1)
#define FLASH_PG			(1 << 0)

/* --- FLASH_OBR values ----------------------------------------------------- */

#define FLASH_OPTERR			(1 << 0)
#define FLASH_RDPRT1			(1 << 1)
#define FLASH_RDPRT2			(1 << 2)
#define FLASH_WDG_SW			(1 << 8)
#define FLASH_NRST_STOP			(1 << 9)
#define FLASH_NRST_STDBY		(1 << 10)
#define FLASH_NBOOT1			(1 << 12)
#define FLASH_VDDA_MONITOR		(1 << 13)
#define FLASH_SRAM_PE			(1 << 14)

/* --- FLASH Keys -----------------------------------------------------------*/

#define FLASH_KEY1			((uint32_t)0x45670123)
#define FLASH_KEY2			((uint32_t)0xcdef89ab)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_set_ws(uint32_t ws);
void flash_unlock(void);
void flash_lock(void);
void flash_clear_pgperr_flag(void);
void flash_clear_eop_flag(void);
void flash_clear_bsy_flag(void);
void flash_clear_status_flags(void);
void flash_erase_all_pages(uint32_t program_size);
void flash_erase_page(uint32_t page, uint32_t program_size);
void flash_program_double_word(uint32_t address, uint64_t data, uint32_t program_size);
void flash_program_word(uint32_t address, uint32_t data, uint32_t program_size);
void flash_program_half_word(uint32_t address, uint16_t data, uint32_t program_size);
void flash_program_byte(uint32_t address, uint8_t data, uint32_t program_size);
void flash_wait_for_last_operation(void);
void flash_program_option_bytes(uint32_t data);

END_DECLS

#endif
