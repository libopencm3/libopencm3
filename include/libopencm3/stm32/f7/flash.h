#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H

/** @addtogroup flash_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2017
 * Matthew Lai <m@matthewlai.ca>
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Thomas Otto <tommi@viadmin.org>
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Mark Butler <mbutler@physics.otago.ac.nz>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017 Matthew Lai <m@matthewlai.ca>
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

#include <libopencm3/stm32/common/flash_common_all.h>
#include <libopencm3/stm32/common/flash_common_f.h>
/*
 * For details see:
 * PM0081 Programming manual: STM32F40xxx and STM32F41xxx Flash programming
 * September 2011, Doc ID 018520 Rev 1
 * https://github.com/libopencm3/libopencm3-archive/blob/master/st_micro/DM00023388.pdf
 */

/*
 * Differences between F7 and F4:
 * 1. 	icache and dcache are now combined into a unified ART cache. The CPU has
 * 	its own d/i-caches, but those are unrelated to this. They are on the
 *	AXIM bus.
 * 2. 	There's an OPTCR1 is now used for boot addresses. Write protect bits
 * 	are in OPTCR. Why does F4 have 2 copies of nWRP?
 * 3. 	Latency field in FLASH_ACR is now 4 bits. Some CPU frequencies supported
 * 	by F7 require more than 7 wait states.
 * 4. 	FLASH_SR_PGSERR (programming sequence error) is now FLASH_SR_ERSERR (
 *	erase sequence error).
 * 6. 	There are now two watchdogs - IWDG (independent watchdog) and WWDG (
 * 	window watchdog).
 */

/**@{*/
/* --- FLASH registers ----------------------------------------------------- */

#define FLASH_ACR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)
#define FLASH_KEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)
#define FLASH_OPTKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)
#define FLASH_SR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C)
#define FLASH_CR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10)
#define FLASH_OPTCR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)
#define FLASH_OPTCR1			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x18)

/* --- FLASH Keys -----------------------------------------------------------*/

#define FLASH_KEYR_KEY1			0x45670123UL
#define FLASH_KEYR_KEY2			0xcdef89abUL
#define FLASH_OPTKEYR_KEY1		0x08192a3bUL
#define FLASH_OPTKEYR_KEY2		0x4c5d6e7fUL

/* --- FLASH_ACR values ---------------------------------------------------- */

#define FLASH_ACR_ARTRST		(1 << 11)
#define FLASH_ACR_ARTEN			(1 << 9)
#define FLASH_ACR_PRFTEN		(1 << 8)

#define FLASH_ACR_LATENCY_SHIFT		0
#define FLASH_ACR_LATENCY_MASK		0x0f

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_SR_BSY			(1 << 16)
#define FLASH_SR_ERSERR			(1 << 7)
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

#define FLASH_CR_SNB_SHIFT		3
#define FLASH_CR_SNB_MASK		0x1f

#define FLASH_CR_MER			(1 << 2)
#define FLASH_CR_SER			(1 << 1)
#define FLASH_CR_PG			(1 << 0)

/* --- FLASH_OPTCR values -------------------------------------------------- */

#define FLASH_OPTCR_IWDG_STOP		(1 << 31)
#define FLASH_OPTCR_IWDG_STDBY		(1 << 30)

#define FLASH_OPTCR_NWRP_SHIFT		16
#define FLASH_OPTCR_NWRP_MASK		0xff

#define FLASH_OPTCR_RDP_SHIFT		8
#define FLASH_OPTCR_RDP_MASK		0xff

#define FLASH_OPTCR_NRST_STDBY		(1 << 7)
#define FLASH_OPTCR_NRST_STOP		(1 << 6)
#define FLASH_OPTCR_IWDG_SW		(1 << 5)
#define FLASH_OPTCR_WWDG_SW		(1 << 4)

#define FLASH_OPTCR_BOR_LEV_MASK	3
#define FLASH_OPTCR_BOR_LEV_SHIFT	2
#define FLASH_OPTCR_BOR_LEV_3		0x00
#define FLASH_OPTCR_BOR_LEV_2		0x01
#define FLASH_OPTCR_BOR_LEV_1		0x02
#define FLASH_OPTCR_BOR_OFF		0x03

#define FLASH_OPTCR_OPTSTRT		(1 << 1)
#define FLASH_OPTCR_OPTLOCK		(1 << 0)

/* --- FLASH_OPTCR1 values ------------------------------------------------- */
#define FLASH_OPTCR1_BOOT_ADD1_MASK	0xffff
#define FLASH_OPTCR1_BOOT_ADD1_SHIFT	16
#define FLASH_OPTCR1_BOOT_ADD0_MASK	0xffff
#define FLASH_OPTCR1_BOOT_ADD0_SHIFT	0

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_clear_pgperr_flag(void);
void flash_wait_for_last_operation(void);

void flash_unlock_option_bytes(void);
void flash_lock_option_bytes(void);
void flash_clear_erserr_flag(void);
void flash_clear_wrperr_flag(void);
void flash_clear_pgaerr_flag(void);
void flash_art_enable(void);
void flash_art_disable(void);
void flash_art_reset(void);
void flash_clear_status_flags(void);
void flash_erase_all_sectors(uint32_t program_size);
void flash_erase_sector(uint8_t sector, uint32_t program_size);
void flash_program_double_word(uint32_t address, uint64_t data);
void flash_program_word(uint32_t address, uint32_t data);
void flash_program_half_word(uint32_t address, uint16_t data);
void flash_program_byte(uint32_t address, uint8_t data);
void flash_program(uint32_t address, uint8_t *data, uint32_t len);
void flash_program_option_bytes(uint32_t data);

END_DECLS
/**@}*/

#endif

