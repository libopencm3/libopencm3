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


/** @defgroup flash_acr ACR Access control register
@{*/

/** FLASH_ACR_DBG_SWEN Debug access software enable **/
#define FLASH_ACR_DBG_SWEN		(1 << 18)
/** FLASH_ACR_EMPTY Flash User area empty **/
#define FLASH_ACR_EMPTY		(1 << 16)
/** FLASH_ACR_ICRST Instruction cache reset **/
#define FLASH_ACR_ICRST		(1 << 11)
/** FLASH_ACR_ICEN Instruction cache enable **/
#define FLASH_ACR_ICEN		(1 << 9)
/** FLASH_ACR_PRFTEN Prefetch enable **/
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

/**@}*/

/** @defgroup flash_keyr KEYR Flash key register
@{*/

/** FLASH_KEYR_KEY1 Flash key 1 **/
#define FLASH_KEYR_KEY1			((uint32_t)0x45670123)
/** FLASH_KEYR_KEY2 Flash key 2 **/
#define FLASH_KEYR_KEY2			((uint32_t)0xcdef89ab)

/**@}*/

/** @defgroup flash_optkeyr OPTKEYR Option byte key register
@{*/

/** FLASH_OPTKEYR_KEY1 Option key 1 **/
#define FLASH_OPTKEYR_KEY1		((uint32_t)0x08192a3b)
/** FLASH_OPTKEYR_KEY2 Option key 2 **/
#define FLASH_OPTKEYR_KEY2		((uint32_t)0x4c5d6e7f)

/**@}*/

/** @defgroup flash_sr SR Status register
@{*/

/** FLASH_SR_CFGBSY Programming or erase configuration busy. **/
#define FLASH_SR_CFGBSY			(1 << 18)
/** FLASH_SR_BSY Busy **/
#define FLASH_SR_BSY			(1 << 16)
/** FLASH_SR_OPTVERR Option and Engineering bits loading validity error **/
#define FLASH_SR_OPTVERR		(1 << 15)
/** FLASH_SR_RDERR PCROP read error **/
#define FLASH_SR_RDERR			(1 << 14)
/** FLASH_SR_FASTERR Fast programming error **/
#define FLASH_SR_FASTERR		(1 << 9)
/** FLASH_SR_MISERR Fast programming data miss error **/
#define FLASH_SR_MISERR			(1 << 8)
/** FLASH_SR_PGSERR Programming sequence error **/
#define FLASH_SR_PGSERR			(1 << 7)
/** FLASH_SR_SIZERR Size error **/
#define FLASH_SR_SIZERR			(1 << 6)
/** FLASH_SR_PGAERR Programming alignment error **/
#define FLASH_SR_PGAERR			(1 << 5)
/** FLASH_SR_WRPERR Write protected error **/
#define FLASH_SR_WRPERR			(1 << 4)
/** FLASH_SR_PROGERR Programming error **/
#define FLASH_SR_PROGERR		(1 << 3)
/** FLASH_SR_OPERR Operation error **/
#define FLASH_SR_OPERR			(1 << 1)
/** FLASH_SR_EOP End of operation **/
#define FLASH_SR_EOP			(1 << 0)

/**@}*/

/** @defgroup flash_cr CR Flash control register
@{*/

/** FLASH_CR_LOCK FLASH_CR Lock **/
#define FLASH_CR_LOCK			(1 << 31)
/** FLASH_CR_OPTLOCK Options Lock **/
#define FLASH_CR_OPTLOCK		(1 << 30)
/** FLASH_CR_SEC_PROT Securable memory area protection enable **/
#define FLASH_CR_SEC_PROT		(1 << 28)
/** FLASH_CR_OBL_LAUNCH Force the option byte loading **/
#define FLASH_CR_OBL_LAUNCH		(1 << 27)
/** FLASH_CR_RDERRIE PCROP read error interrupt enable **/
#define FLASH_CR_RDERRIE		(1 << 26)
/** FLASH_CR_ERRIE Error interrupt enable **/
#define FLASH_CR_ERRIE			(1 << 25)
/** FLASH_CR_EOPIE End of operation interrupt enable **/
#define FLASH_CR_EOPIE			(1 << 24)
/** FLASH_CR_FSTPG Fast programming **/
#define FLASH_CR_FSTPG			(1 << 18)
/** FLASH_CR_OPTSTRT Options modification start **/
#define FLASH_CR_OPTSTRT		(1 << 17)
/** FLASH_CR_STRT Start **/
#define FLASH_CR_STRT		(1 << 16)

#define FLASH_CR_PNB_SHIFT		3
#define FLASH_CR_PNB_MASK		0x3f

/** FLASH_CR_MER Mass erase **/
#define FLASH_CR_MER			(1 << 2)
/** FLASH_CR_PER Page erase **/
#define FLASH_CR_PER			(1 << 1)
/** FLASH_CR_PG Programming **/
#define FLASH_CR_PG			(1 << 0)

/**@}*/

/** @defgroup flash_eccr ECCR Flash ECC register
@{*/
/** FLASH_ECCR_ECCD ECC detection **/
#define FLASH_ECCR_ECCD				(1 << 31)
/** FLASH_ECCR_ECCC ECC correction **/
#define FLASH_ECCR_ECCC				(1 << 30)
/** FLASH_ECCR_ECCIE ECC correction interrupt enable **/
#define FLASH_ECCR_ECCIE			(1 << 24)
/** FLASH_ECCR_SYSF_ECC ECC fail for Corrected ECC Error or Double ECC Error in info block **/
#define FLASH_ECCR_SYSF_ECC			(1 << 20)

#define FLASH_ECCR_ADDR_ECC_SHIFT	0
#define FLASH_ECCR_ADDR_ECC_MASK	0x3fff

/**@}*/

/** @defgroup flash_optr OPTR Flash option register
@{*/

/** FLASH_OPTR_IRHEN Internal reset holder enable bit **/
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

/** FLASH_OPTR_nBOOT0 nBOOT0 option bit **/
#define FLASH_OPTR_nBOOT0			(1 << 26)
/** FLASH_OPTR_nBOOT1 Boot configuration **/
#define FLASH_OPTR_nBOOT1			(1 << 25)
/** FLASH_OPTR_nBOOT_SEL nBOOT_SEL **/
#define FLASH_OPTR_nBOOT_SEL			(1 << 24)
/** FLASH_OPTR_RAM_PARITY_CHECK SRAM parity check control **/
#define FLASH_OPTR_RAM_PARITY_CHECK		(1 << 22)
/** FLASH_OPTR_WWDG_SW Window watchdog selection **/
#define FLASH_OPTR_WWDG_SW			(1 << 19)
/** FLASH_OPTR_IWDG_STDBY Independent watchdog counter freeze in Standby mode **/
#define FLASH_OPTR_IWDG_STDBY			(1 << 18)
/** FLASH_OPTR_IWDG_STOP Independent watchdog counter freeze in Stop mode **/
#define FLASH_OPTR_IWDG_STOP			(1 << 17)
/** FLASH_OPTR_IDWG_SW Independent watchdog selection **/
#define FLASH_OPTR_IDWG_SW			(1 << 16)
/** FLASH_OPTR_nRSTS_HDW nRSTS_HDW **/
#define FLASH_OPTR_nRSTS_HDW			(1 << 15)
/** FLASH_OPTR_nRST_STDBY nRST_STDBY **/
#define FLASH_OPTR_nRST_STDBY			(1 << 14)
/** FLASH_OPTR_nRST_STOP nRST_STOP **/
#define FLASH_OPTR_nRST_STOP			(1 << 13)

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

/** FLASH_OPTR_BOREN BOR reset Level **/
#define FLASH_OPTR_BOREN			(1 << 8)

#define FLASH_OPTR_RDP_SHIFT		0
#define FLASH_OPTR_RDP_MASK			0xff
/** @defgroup flash_optr_rdp RDP
* @brief Read protection level
@{*/
#define FLASH_OPTR_RDP_LEVEL_0		0xAA
#define FLASH_OPTR_RDP_LEVEL_1		0xBB /* or any other value. */
#define FLASH_OPTR_RDP_LEVEL_2		0xCC
/**@}*/

/**@}*/

BEGIN_DECLS

void flash_clear_progerr_flag(void);
void flash_clear_pgserr_flag(void);
void flash_clear_size_flag(void);
void flash_clear_pgaerr_flag(void);
void flash_clear_wrperr_flag(void);
void flash_clear_operr_flag(void);
void flash_clear_eop_flag(void);

void flash_clear_status_flags(void);

void flash_wait_for_last_operation(void);

void flash_program_double_word(uint32_t address, uint64_t data);
void flash_program(uint32_t address, uint8_t *data, uint32_t len);

void flash_erase_page(uint32_t page);
void flash_erase_all_pages(void);

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
