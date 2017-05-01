/** @addtogroup flash_defines
 *
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

/** @cond */
#ifdef LIBOPENCM3_FLASH_H
/** @endcond */
#ifndef LIBOPENCM3_FLASH_COMMON_L01_H
#define LIBOPENCM3_FLASH_COMMON_L01_H
/**@{*/

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

/* --- FLASH_ACR values ---------------------------------------------------- */
#define FLASH_ACR_RUNPD			(1 << 4)
#define FLASH_ACR_SLEEPPD		(1 << 3)
#define FLASH_ACR_PRFTEN		(1 << 1)
/** @defgroup flash_latency FLASH Wait States
@ingroup flash_defines
@{*/
#define FLASH_ACR_LATENCY_0WS		0x00
#define FLASH_ACR_LATENCY_1WS		0x01
/**@}*/

/* --- FLASH_PECR values. Program/erase control register */
#define FLASH_PECR_OBL_LAUNCH		(1 << 18)
#define FLASH_PECR_ERRIE		(1 << 17)
#define FLASH_PECR_EOPIE		(1 << 16)
#define FLASH_PECR_PARALLBANK		(1 << 15)
#define FLASH_PECR_FPRG			(1 << 10)
#define FLASH_PECR_ERASE		(1 << 9)
#define FLASH_PECR_FTDW			(1 << 8)
#define FLASH_PECR_DATA			(1 << 4)
#define FLASH_PECR_PROG			(1 << 3)
#define FLASH_PECR_OPTLOCK		(1 << 2)
#define FLASH_PECR_PRGLOCK		(1 << 1)
#define FLASH_PECR_PELOCK		(1 << 0)

/* Power down key register (FLASH_PDKEYR) */
#define FLASH_PDKEYR_PDKEY1		((uint32_t)0x04152637)
#define FLASH_PDKEYR_PDKEY2		((uint32_t)0xFAFBFCFD)

/* Program/erase key register (FLASH_PEKEYR) */
#define FLASH_PEKEYR_PEKEY1		((uint32_t)0x89ABCDEF)
#define FLASH_PEKEYR_PEKEY2		((uint32_t)0x02030405)

/* Program memory key register (FLASH_PRGKEYR) */
#define FLASH_PRGKEYR_PRGKEY1		((uint32_t)0x8C9DAEBF)
#define FLASH_PRGKEYR_PRGKEY2		((uint32_t)0x13141516)

/* Option byte key register (FLASH_OPTKEYR) */
#define FLASH_OPTKEYR_OPTKEY1		((uint32_t)0xFBEAD9C8)
#define FLASH_OPTKEYR_OPTKEY2		((uint32_t)0x24252627)

/* --- FLASH_SR values ----------------------------------------------------- */
#define FLASH_SR_OPTVERR		(1 << 11)
#define FLASH_SR_SIZEERR		(1 << 10)
#define FLASH_SR_PGAERR			(1 << 9)
#define FLASH_SR_WRPERR			(1 << 8)
#define FLASH_SR_READY			(1 << 3)
#define FLASH_SR_ENDHV			(1 << 2)
#define FLASH_SR_EOP			(1 << 1)
#define FLASH_SR_BSY			(1 << 0)

/* --- FLASH_OBR values ----------------------------------------------------- */
#define FLASH_OBR_BFB2			(1 << 23)
#define FLASH_OBR_NRST_STDBY		(1 << 22)
#define FLASH_OBR_NRST_STOP		(1 << 21)
#define FLASH_OBR_IWDG_SW		(1 << 20)
#define FLASH_OBR_BOR_OFF		(0x0 << 16)
#define FLASH_OBR_BOR_LEVEL_1		(0x8 << 16)
#define FLASH_OBR_BOR_LEVEL_2		(0x9 << 16)
#define FLASH_OBR_BOR_LEVEL_3		(0xa << 16)
#define FLASH_OBR_BOR_LEVEL_4		(0xb << 16)
#define FLASH_OBR_BOR_LEVEL_5		(0xc << 16)
#define FLASH_OBR_RDPRT_LEVEL_0		(0xaa)
#define FLASH_OBR_RDPRT_LEVEL_1		(0x00)
#define FLASH_OBR_RDPRT_LEVEL_2		(0xcc)

BEGIN_DECLS

void flash_prefetch_enable(void);
void flash_prefetch_disable(void);
void flash_set_ws(uint32_t ws);
void flash_unlock_pecr(void);
void flash_lock_pecr(void);
void flash_unlock_progmem(void);
void flash_lock_progmem(void);
void flash_unlock_option_bytes(void);
void flash_lock_option_bytes(void);
void flash_unlock(void);
void flash_lock(void);

void eeprom_program_word(uint32_t address, uint32_t data);
void eeprom_program_words(uint32_t address, uint32_t *data, int length_in_words);

END_DECLS
/**@}*/

#endif
/** @cond */
#else
#error "flash_common_l01.h should not be included directly, only via flash.h"
#endif
/** @endcond */

