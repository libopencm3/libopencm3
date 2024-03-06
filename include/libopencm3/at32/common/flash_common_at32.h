/** @addtogroup flash_defines
 *
 */
/*
 * This file is part of the libopencm3 project.
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
#ifndef LIBOPENCM3_FLASH_COMMON_AT32_H
#define LIBOPENCM3_FLASH_COMMON_AT32_H
/**@{*/

/* --- FLASH registers ----------------------------------------------------- */

#define FLASH_ACR	MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)	/* FLASH_PSR */
#define FLASH_KEYR	MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)	/* FLASH_UNLOCK */
#define FLASH_OPTKEYR	MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08) /* FLASH_USD_UNLOCK */
#define FLASH_SR	MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0C) /* FLASH_STS */
#define FLASH_CR	MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10) /* FLASH_CTRL */
#define FLASH_AR	MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14) /* FLASH_ADDR */
#define FLASH_OBR	MMIO32(FLASH_MEM_INTERFACE_BASE + 0x1C) /* FLASH_USD */
#define FLASH_WRPR	MMIO32(FLASH_MEM_INTERFACE_BASE + 0x20) /* FLASH_EPPS */

/* --- FLASH_OPTION bytes -------------------------------------------------- */

#define FLASH_OPTION_BYTE(i)		MMIO16(INFO_BASE+0x0800 + (i)*2)

/* --- FLASH_SR (FLASH_STS) values ----------------------------------------- */

#define FLASH_SR_EOP			(1 << 5)	/* ODF */
#define FLASH_SR_WRPRTERR		(1 << 4)	/* EPPERR */
#define FLASH_SR_PGERR			(1 << 2)	/* PRGMERR */
#define FLASH_SR_BSY			(1 << 0)	/* OBF */

/* --- FLASH_CR (FLASH_CTRL) values ---------------------------------------- */

#define FLASH_CR_EOPIE			(1 << 12)	/* ODFIE */
#define FLASH_CR_ERRIE			(1 << 10)	/* ERRIE */
#define FLASH_CR_OPTWRE			(1 << 9)	/* USDULKS */
#define FLASH_CR_LOCK			(1 << 7)	/* OPLK */
#define FLASH_CR_STRT			(1 << 6)	/* ERSTR */
#define FLASH_CR_OPTER			(1 << 5)	/* USDERS */
#define FLASH_CR_OPTPG			(1 << 4)	/* USDPRGM */
#define FLASH_CR_MER			(1 << 2)	/* BANKERS */
#define FLASH_CR_PER			(1 << 1)	/* SECERS */
#define FLASH_CR_PG			(1 << 0)	/* FPRGM */

/* --- FLASH_OBR values ---------------------------------------------------- */

/* FLASH_OBR[25:18]: Data1 */
/* FLASH_OBR[17:10]: Data0 */
#define FLASH_OBR_NBOOT1		(1 << 6)	/* nBOOT1 */
#define FLASH_OBR_NRST_STDBY		(1 << 4)	/* nSTDBY_RST */
#define FLASH_OBR_NRST_STOP		(1 << 3)	/* nDEPSLP_RST */
#define FLASH_OBR_WDG_SW		(1 << 2)	/* nWDT_ATO_EN */
#define FLASH_OBR_RDPRT_EN		(1 << 1)	/* must not FAP */
#define FLASH_OBR_OPTERR		(1 << 0)	/* USDERR */

/* --- FLASH Keys -----------------------------------------------------------*/

#define FLASH_KEYR_KEY1			((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2			((uint32_t)0xcdef89ab)

#define FLASH_OPTKEYR_KEY1		FLASH_KEYR_KEY1
#define FLASH_OPTKEYR_KEY2		FLASH_KEYR_KEY2

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_clear_pgerr_flag(void);
void flash_clear_wrprterr_flag(void);
uint32_t flash_get_status_flags(void);
void flash_program_word(uint32_t address, uint32_t data);
void flash_program_half_word(uint32_t address, uint16_t data);
void flash_erase_page(uint32_t page_address);
void flash_erase_all_pages(void);
void flash_erase_option_bytes(void);
void flash_program_option_bytes(uint32_t address, uint16_t data);

END_DECLS
/**@}*/

#endif
/** @cond */
#else
#warning "flash_common_at32.h should not be included directly,"
#warning "only via flash.h"
#endif
/** @endcond */

