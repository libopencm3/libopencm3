/** @defgroup flash_defines FLASH Defines
 *
 * @ingroup STM32G0xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32G0xx Flash Control</b>
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 *  */
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

/**@{*/
#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H

#include <libopencm3/stm32/common/flash_common_all.h>

/** @defgroup flash_registers FLASH Registers
@{*/
#define FLASH_ACR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)
#define FLASH_KEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)
#define FLASH_OPTKEYR		MMIO32(FLASH_MEM_INTERFACE_BASE + 0x0c)
#define FLASH_SR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x10)
#define FLASH_CR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)
#define FLASH_ECCR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x18)
#define FLASH_OPTR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x20)
#define FLASH_PCROP1ASR		MMIO32(FLASH_MEM_INTERFACE_BASE + 0x24)
#define FLASH_PCROP1AER		MMIO32(FLASH_MEM_INTERFACE_BASE + 0x28)
#define FLASH_WRP1AR		MMIO32(FLASH_MEM_INTERFACE_BASE + 0x2c)
#define FLASH_WRP1BR		MMIO32(FLASH_MEM_INTERFACE_BASE + 0x30)
#define FLASH_PCROP1BSR		MMIO32(FLASH_MEM_INTERFACE_BASE + 0x34)
#define FLASH_PCROP1BER		MMIO32(FLASH_MEM_INTERFACE_BASE + 0x38)
#define FLASH_SECR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x80)
/**@}*/

/* --- FLASH_ACR values ----------------------------------------------------- */

#define FLASH_ACR_DBG_SWEN		(1 << 18)
#define FLASH_ACR_EMPTY			(1 << 16)
#define FLASH_ACR_ICRST			(1 << 11)
#define FLASH_ACR_ICEN			(1 << 9)
#define FLASH_ACR_PRFTEN		(1 << 8)

#define FLASH_ACR_LATENCY_SHIFT		0
#define FLASH_ACR_LATENCY_MASK		0x7
/** @defgroup flash_latency FLASH Wait States
 * @brief Flash memory access latency. flash HCLK max freq for 0ws is 24mhz (range 1 voltage) / 8mhz (range 0), 48mhz/16mhz for 1ws and 64mhz for 2ws.
@{*/
#define FLASH_ACR_LATENCY_0WS		0x00
#define FLASH_ACR_LATENCY_1WS		0x01
#define FLASH_ACR_LATENCY_2WS		0x02
/**@}*/

/* --- FLASH_KEYR values ---------------------------------------------------- */

#define FLASH_KEYR_KEY1			((uint32_t)0x08192a3b)
#define FLASH_KEYR_KEY2			((uint32_t)0x4c5d6e7f)

#define FLASH_OPTKEYR_KEY1		FLASH_KEYR_KEY1
#define FLASH_OPTKEYR_KEY2		FLASH_KEYR_KEY2

/* --- FLASH_SR values ------------------------------------------------------ */
#define FLASH_SR_CFGBSY			(1 << 18)
#define FLASH_SR_BSY			(1 << 16)
#define FLASH_SR_OPTVERR		(1 << 15)
#define FLASH_SR_RDERR			(1 << 14)
#define FLASH_SR_FASTERR		(1 << 9)
#define FLASH_SR_MISERR			(1 << 8)
#define FLASH_SR_PGSERR			(1 << 7)
#define FLASH_SR_SIZERR			(1 << 6)
#define FLASH_SR_PGAERR			(1 << 5)
#define FLASH_SR_WRPERR			(1 << 4)
#define FLASH_SR_PROGERR		(1 << 3)
#define FLASH_SR_OPERR			(1 << 1)
#define FLASH_SR_EOP			(1 << 0)

/* --- FLASH_CR values ------------------------------------------------------ */

#define FLASH_CR_LOCK			(1 << 31)
#define FLASH_CR_OPTLOCK		(1 << 30)
#define FLASH_CR_SEC_PROT		(1 << 28)
#define FLASH_CR_OBL_LAUNCH		(1 << 27)
#define FLASH_CR_RDERRIE		(1 << 26)
#define FLASH_CR_ERRIE			(1 << 25)
#define FLASH_CR_EOPIE			(1 << 24)
#define FLASH_CR_FSTPG			(1 << 18)
#define FLASH_CR_OPTSTRT		(1 << 17)
#define FLASH_CR_STRT			(1 << 16)

#define FLASH_CR_PNB_SHIFT		3
#define FLASH_CR_PNB_MASK		0x3f

#define FLASH_CR_MER			(1 << 2)
#define FLASH_CR_PER			(1 << 1)
#define FLASH_CR_PG				(1 << 0)

/* --- FLASH_ECCR values ---------------------------------------------------- */

#define FLASH_ECCR_ECCD				(1 << 31)
#define FLASH_ECCR_ECCC				(1 << 30)
#define FLASH_ECCR_ECCIE			(1 << 24)
#define FLASH_ECCR_SYSF_ECC			(1 << 20)
#define FLASH_ECCR_ADDR_ECC_SHIFT	0
#define FLASH_ECCR_ADDR_ECC_MASK	0x3fff
/* --- FLASH_OPTR values ---------------------------------------------------- */

#define FLASH_OPTR_IRHEN			(1 << 29)

#define FLASH_OPTR_NRST_MODE_SHIFT	27
#define FLASH_OPTR_NRST_MODE_MASK	0x03
/** @defgroup flash_optr_nrst_mode NRST MODE
* @brief NRST_MODE
@{*/
#define FLASH_OPTR_NRST_MODE_RESET	1
#define FLASH_OPTR_NRST_MODE_GPIO	2
#define FLASH_OPTR_NRST_MODE_BIDIR	3
/**@}*/

#define FLASH_OPTR_nBOOT0			(1 << 26)
#define FLASH_OPTR_nBOOT1			(1 << 25)
#define FLASH_OPTR_nBOOT_SEL		(1 << 24)
#define FLASH_OPTR_RAM_PARITY_CHECK	(1 << 22)
#define FLASH_OPTR_WWDG_SW			(1 << 19)
#define FLASH_OPTR_IWDG_STDBY		(1 << 18)
#define FLASH_OPTR_IWDG_STOP		(1 << 17)
#define FLASH_OPTR_IDWG_SW			(1 << 16)
#define FLASH_OPTR_nRSTS_HDW		(1 << 15)
#define FLASH_OPTR_nRST_STDBY		(1 << 14)
#define FLASH_OPTR_nRST_STOP		(1 << 13)

#define FLASH_OPTR_BORR_LEV_SHIFT	11
#define FLASH_OPTR_BORR_LEV_MASK	0x03
/** @defgroup flash_optr_borr_lev BORR LEV
* @brief These bits contain the VDD supply level threshold that releases the reset.
@{*/
#define FLASH_OPTR_BORR_LEV_2V1		0
#define FLASH_OPTR_BORR_LEV_2V3		1
#define FLASH_OPTR_BORR_LEV_2V6		2
#define FLASH_OPTR_BORR_LEV_2V9		3
/**@}*/

#define FLASH_OPTR_BORF_LEV_SHIFT	9
#define FLASH_OPTR_BORF_LEV_MASK	0x03
/** @defgroup flash_optr_borf_lev BOR FLEV
* @brief These bits contain the VDD supply level threshold that activates the reset
@{*/
#define FLASH_OPTR_BORF_LEV_2V0		0
#define FLASH_OPTR_BORF_LEV_2V2		1
#define FLASH_OPTR_BORF_LEV_2V5		2
#define FLASH_OPTR_BORF_LEV_2V8		3
/**@}*/

#define FLASH_OPTR_BOREN			(1 << 8)

#define FLASH_OPTR_RDP_SHIFT		0
#define FLASH_OPTR_RDP_MASK			0xff
/** @defgroup flash_optr_rdp RDP
* @brief Read protection level
@{*/
#define FLASH_OPTR_RDP_LEVEL_0		0xAA
#define FLASH_OPTR_RDP_LEVEL_1		0xBB
#define FLASH_OPTR_RDP_LEVEL_2		0xCC /* or any other value. */
/**@}*/

BEGIN_DECLS

/** Enable instruction cache */
void flash_icache_enable(void);
/** Disable instruction cache */
void flash_icache_disable(void);
/** Reset instruction cache */
void flash_icache_reset(void);

/** Unlock program memory */
void flash_unlock_progmem(void);
/** lock program memory */
void flash_lock_progmem(void);

/** Lock Option Byte Access */
void flash_lock_option_bytes(void);

END_DECLS

#endif
/**@}*/
