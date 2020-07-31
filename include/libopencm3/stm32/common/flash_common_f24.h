/** @addtogroup flash_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Thomas Otto <tommi@viadmin.org>
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Mark Butler <mbutler@physics.otago.ac.nz>
 *
 */
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
 * PM0081 Programming manual: STM32F40xxx and STM32F41xxx Flash programming
 * September 2011, Doc ID 018520 Rev 1
 * https://github.com/libopencm3/libopencm3-archive/blob/master/st_micro/DM00023388.pdf
 */

/** @cond */
#ifdef LIBOPENCM3_FLASH_H
/** @endcond */
#ifndef LIBOPENCM3_FLASH_COMMON_F24_H
#define LIBOPENCM3_FLASH_COMMON_F24_H
/**@{*/

#include <libopencm3/stm32/common/flash_common_idcache.h>

/** @defgroup flash_registers Flash Registers
 * @ingroup flash_defines
@{*/
/** Flash Access Control register */
#define FLASH_ACR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)
/** Flash Key register */
#define FLASH_KEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)
/** Flash Option bytes key register */
#define FLASH_OPTKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)
/** Flash Status register*/
#define FLASH_SR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C)
/** Flash Control register */
#define FLASH_CR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10)
/** Flash Option Control register */
#define FLASH_OPTCR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)
/** Flash Option Control register 1 (bank 2) */
#define FLASH_OPTCR1			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x18)
/*@}*/

/** @defgroup flash_latency FLASH Wait States
@ingroup flash_defines
@{*/
#define FLASH_ACR_LATENCY(w)		((w) & FLASH_ACR_LATENCY_MASK)
#define FLASH_ACR_LATENCY_0WS          0x00
#define FLASH_ACR_LATENCY_1WS          0x01
#define FLASH_ACR_LATENCY_2WS          0x02
#define FLASH_ACR_LATENCY_3WS          0x03
#define FLASH_ACR_LATENCY_4WS          0x04
#define FLASH_ACR_LATENCY_5WS          0x05
#define FLASH_ACR_LATENCY_6WS          0x06
#define FLASH_ACR_LATENCY_7WS          0x07
/*@}*/
#define FLASH_ACR_LATENCY_SHIFT		0
#define FLASH_ACR_LATENCY_MASK		0x0f

/** @defgroup flash_acr_values FLASH_ACR values
 * @ingroup flash_registers
 * @brief Access Control register values
 * @{*/
#define FLASH_ACR_PRFTEN		(1 << 8)
/**@}*/

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_SR_BSY			(1 << 16)
#define FLASH_SR_PGPERR			(1 << 6)
#define FLASH_SR_PGAERR			(1 << 5)
#define FLASH_SR_WRPERR			(1 << 4)
#define FLASH_SR_OPERR			(1 << 1)
#define FLASH_SR_EOP			(1 << 0)

/* --- FLASH_CR values ----------------------------------------------------- */

#define FLASH_CR_LOCK			(1 << 31)
#define FLASH_CR_ERRIE			(1 << 25)
#define FLASH_CR_EOPIE			(1 << 24)
#define FLASH_CR_STRT			(1 << 16)
#define FLASH_CR_MER			(1 << 2)
#define FLASH_CR_SER			(1 << 1)
#define FLASH_CR_PG			(1 << 0)
#define FLASH_CR_SNB_SHIFT		3
#define FLASH_CR_SNB_MASK		0x1f
#define FLASH_CR_PROGRAM_MASK		0x3
#define FLASH_CR_PROGRAM_SHIFT		8
/** @defgroup flash_cr_program_width Flash programming width
@ingroup flash_group

@{*/
#define FLASH_CR_PROGRAM_X8		0
#define FLASH_CR_PROGRAM_X16		1
#define FLASH_CR_PROGRAM_X32		2
#define FLASH_CR_PROGRAM_X64		3
/**@}*/

/* --- FLASH_OPTCR values -------------------------------------------------- */

/* FLASH_OPTCR[27:16]: nWRP */
/* FLASH_OBR[15:8]: RDP */
#define FLASH_OPTCR_NRST_STDBY		(1 << 7)
#define FLASH_OPTCR_NRST_STOP		(1 << 6)
#define FLASH_OPTCR_OPTSTRT		(1 << 1)
#define FLASH_OPTCR_OPTLOCK		(1 << 0)
#define FLASH_OPTCR_BOR_LEVEL_3		(0x00 << 2)
#define FLASH_OPTCR_BOR_LEVEL_2		(0x01 << 2)
#define FLASH_OPTCR_BOR_LEVEL_1		(0x02 << 2)
#define FLASH_OPTCR_BOR_OFF		(0x03 << 2)

/* --- FLASH_OPTCR1 values ------------------------------------------------- */
/* Only on some devices */
/* FLASH_OPTCR1[27:16]: nWRP bank 2 */

/* --- FLASH Keys -----------------------------------------------------------*/

#define FLASH_KEYR_KEY1			((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2			((uint32_t)0xcdef89ab)

#define FLASH_OPTKEYR_KEY1		((uint32_t)0x08192a3b)
#define FLASH_OPTKEYR_KEY2		((uint32_t)0x4c5d6e7f)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_lock_option_bytes(void);
void flash_clear_pgperr_flag(void);
void flash_clear_wrperr_flag(void);
void flash_clear_pgaerr_flag(void);
void flash_erase_all_sectors(uint32_t program_size);
void flash_erase_sector(uint8_t sector, uint32_t program_size);
void flash_program_double_word(uint32_t address, uint64_t data);
void flash_program_word(uint32_t address, uint32_t data);
void flash_program_half_word(uint32_t address, uint16_t data);
void flash_program_byte(uint32_t address, uint8_t data);
void flash_program(uint32_t address, const uint8_t *data, uint32_t len);
void flash_program_option_bytes(uint32_t data);

END_DECLS
/**@}*/

#endif
/** @cond */
#else
#warning "flash_common_f24.h should not be included direcitly,"
#warning "only via flash.h"
#endif
/** @endcond */
