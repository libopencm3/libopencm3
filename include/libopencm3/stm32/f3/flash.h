/** @defgroup flash_defines FLASH Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F3xx Flash
 * controller </b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
 *
 * LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H
/**@{*/

#include <libopencm3/stm32/common/flash_common_all.h>
#include <libopencm3/stm32/common/flash_common_f.h>

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
/** Flash Address register */
#define FLASH_AR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)
/** Flash Option Byte register */
#define FLASH_OBR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x1C)
/** Flash Write Protection register */
#define FLASH_WRPR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x20)
/*@}*/

/* --- FLASH_ACR values ---------------------------------------------------- */

#define FLASH_ACR_PRFTBS		(1 << 5)
#define FLASH_ACR_PRFTBE		(1 << 4)
/** Compatibility alias */
#define FLASH_ACR_PRFTEN		FLASH_ACR_PRFTBE
#define FLASH_ACR_HLFCYA		(1 << 3)
#define FLASH_ACR_LATENCY_SHIFT		0
#define FLASH_ACR_LATENCY_MASK		0x0f
/** @defgroup flash_latency FLASH Wait States @{*/
#define FLASH_ACR_LATENCY(w)		((w) & FLASH_ACR_LATENCY_MASK)
/**@}*/

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_SR_BSY			(1 << 0)
#define FLASH_SR_ERLYBSY		(1 << 1)
#define FLASH_SR_PGERR			(1 << 2)
#define FLASH_SR_WRPRTERR		(1 << 4)
#define FLASH_SR_EOP			(1 << 5)

/* --- FLASH_CR values ----------------------------------------------------- */

#define FLASH_CR_OBL_LAUNCH		(1 << 13)
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

/* F3 uses the same keys for option bytes */
#define FLASH_KEYR_KEY1			((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2			((uint32_t)0xcdef89ab)
#define FLASH_OPTKEYR_KEY1		FLASH_KEYR_KEY1
#define FLASH_OPTKEYR_KEY2		FLASH_KEYR_KEY2

BEGIN_DECLS

void flash_clear_pgerr_flag(void);
void flash_clear_wrprterr_flag(void);
void flash_program_half_word(uint32_t address, uint16_t data);
void flash_erase_page(uint32_t page_address);
void flash_erase_all_pages(void);

END_DECLS

/**@}*/

#endif

