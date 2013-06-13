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
 * PM0075 programming manual: STM32F10xxx Flash programming
 * August 2010, Doc ID 17863 Rev 1
 * https://github.com/libopencm3/libopencm3-archive/blob/master/st_micro/CD00283419.pdf
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

#define FLASH_ACR_PRFTBS		(1 << 5)
#define FLASH_ACR_PRFTBE		(1 << 4)
#define FLASH_ACR_HLFCYA		(1 << 3)
#define FLASH_ACR_LATENCY_0WS		0x00
#define FLASH_ACR_LATENCY_1WS		0x01
#define FLASH_ACR_LATENCY_2WS		0x02

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_SR_EOP			(1 << 5)
#define FLASH_SR_WRPRTERR		(1 << 4)
#define FLASH_SR_PGERR			(1 << 2)
#define FLASH_SR_BSY			(1 << 0)

/* --- FLASH_CR values ----------------------------------------------------- */

#define FLASH_CR_EOPIE			(1 << 12)
#define FLASH_CR_ERRIE			(1 << 10)
#define FLASH_CR_OPTWRE			(1 << 9)
#define FLASH_CR_LOCK			(1 << 7)
#define FLASH_CR_STRT			(1 << 6)
#define FLASH_CR_OPTER			(1 << 5)
#define FLASH_CR_OPTPG			(1 << 4)
#define FLASH_CR_MER			(1 << 2)
#define FLASH_CR_PER			(1 << 1)
#define FLASH_CR_PG			(1 << 0)

/* --- FLASH_OBR values ---------------------------------------------------- */

/* FLASH_OBR[25:18]: Data1 */
/* FLASH_OBR[17:10]: Data0 */
#define FLASH_OBR_NRST_STDBY		(1 << 4)
#define FLASH_OBR_NRST_STOP			(1 << 3)
#define FLASH_OBR_WDG_SW			(1 << 2)
#define FLASH_OBR_RDPRT			(1 << 1)
#define FLASH_OBR_OPTERR			(1 << 0)

/* --- FLASH Keys -----------------------------------------------------------*/

#define FLASH_RDP_KEY				((uint16_t)0x00a5)
#define FLASH_KEYR_KEY1			((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2			((uint32_t)0xcdef89ab)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_prefetch_buffer_enable(void);
void flash_prefetch_buffer_disable(void);
void flash_halfcycle_enable(void);
void flash_halfcycle_disable(void);
void flash_set_ws(uint32_t ws);
void flash_unlock(void);
void flash_lock(void);
void flash_clear_pgerr_flag(void);
void flash_clear_eop_flag(void);
void flash_clear_wrprterr_flag(void);
void flash_clear_bsy_flag(void);
void flash_clear_status_flags(void);
uint32_t flash_get_status_flags(void);
void flash_unlock_option_bytes(void);
void flash_erase_all_pages(void);
void flash_erase_page(uint32_t page_address);
void flash_program_word(uint32_t address, uint32_t data);
void flash_program_half_word(uint32_t address, uint16_t data);
void flash_wait_for_last_operation(void);
void flash_erase_option_bytes(void);
void flash_program_option_bytes(uint32_t address, uint16_t data);

END_DECLS

#endif
