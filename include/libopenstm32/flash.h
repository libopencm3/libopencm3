/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENSTM32_FLASH_H
#define LIBOPENSTM32_FLASH_H

#include <libopenstm32.h>

/* --- FLASH registers ----------------------------------------------------- */

#define FLASH_ACR			MMIO32(FLASH_BASE + 0x00)
#define FLASH_KEYR			MMIO32(FLASH_BASE + 0x04)
#define FLASH_OPTKEYR			MMIO32(FLASH_BASE + 0x08)
#define FLASH_SR			MMIO32(FLASH_BASE + 0x0C)
#define FLASH_CR			MMIO32(FLASH_BASE + 0x10)
#define FLASH_AR			MMIO32(FLASH_BASE + 0x14)
#define FLASH_OBR			MMIO32(FLASH_BASE + 0x1C)
#define FLASH_WRPR			MMIO32(FLASH_BASE + 0x20)

/* --- FLASH_ACR values ---------------------------------------------------- */

#define PRFTBS				(1 << 5)
#define PRFTBE				(1 << 4)
#define HLFCYA				(1 << 3)
#define LATENCY_0WS			0x00
#define LATENCY_1WS			0x01
#define LATENCY_2WS			0x02

/* --- FLASH_SR values ----------------------------------------------------- */

#define EOP				(1 << 5)
#define WRPRTERR			(1 << 4)
#define PGERR				(1 << 2)
#define BSY				(1 << 0)

/* --- FLASH_CR values ----------------------------------------------------- */

#define EOPIE				(1 << 12)
#define ERRIE				(1 << 10)
#define OPTWRE				(1 << 9)
#define LOCK				(1 << 7)
#define STRT				(1 << 6)
#define OPTER				(1 << 5)
#define OPTPG				(1 << 4)
#define MER				(1 << 2)
#define PER				(1 << 1)
#define PG				(1 << 0)

/* --- FLASH_OBR values ---------------------------------------------------- */

/* FLASH_OBR[25:18]: Data1 */
/* FLASH_OBR[17:10]: Data0 */
#define NRST_STDBY			(1 << 4)
#define NRST_STOP			(1 << 3)
#define WDG_SW				(1 << 2)
#define RDPRT				(1 << 1)
#define OPTERR				(1 << 0)

/* --- Function prototypes ------------------------------------------------- */

void flash_prefetch_buffer_enable(void);
void flash_prefetch_buffer_disable(void);
void flash_halfcycle_enable(void);
void flash_halfcycle_disable(void);
void flash_set_ws(u32 ws);

#endif
