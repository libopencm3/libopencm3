/** @defgroup flash_defines FLASH Defines
 * @brief <b>Defined Constants and Types for the STM32H7xx Flash
 * controller</b>
 * @ingroup STM32H7xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Brian Viele <vielster@allocor.tech>
 * @author @htmlonly &copy; @endhtmlonly 2024
 * Rachel Mant <git@dragonmux.network>
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

#include <stdbool.h>
#include <stddef.h>
#include <libopencm3/stm32/common/flash_common_idcache.h>

#define FLASH_FPEC1_BASE (FLASH_MEM_INTERFACE_BASE + 0x000U)
#define FLASH_FPEC2_BASE (FLASH_MEM_INTERFACE_BASE + 0x100U)

/** @defgroup flash_registers Flash Registers
 * @ingroup flash_defines
@{*/
/** Flash Access Control register */
#define FLASH_ACR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00U)
/** Flash Key register */
#define FLASH_KEYR			0x04U
/** Flash Option bytes key register */
#define FLASH_OPTKEYR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08U)
/** Flash Control register */
#define FLASH_CR			0x0CU
/** Flash Status register - NB: Read-only on H7!! */
#define FLASH_SR			0x10U
/** Flash Clear Control register */
#define FLASH_CCR			0x14U
/** Flash Option Control register */
#define FLASH_OPTCR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x18U)
/** Flash Option Status read side register */
#define FLASH_OPTSR_CUR		MMIO32(FLASH_MEM_INTERFACE_BASE + 0x1CU)
/** Flash Option Status write side register */
#define FLASH_OPTSR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x18U)
/**@}*/

/** @defgroup flash_latency FLASH Wait States
@ingroup flash_defines
@{*/
#define FLASH_ACR_LATENCY(w)		((w) & FLASH_ACR_LATENCY_MASK)
#define FLASH_ACR_LATENCY_0WS          FLASH_ACR_LATENCY(0U)
#define FLASH_ACR_LATENCY_1WS          FLASH_ACR_LATENCY(1U)
#define FLASH_ACR_LATENCY_2WS          FLASH_ACR_LATENCY(2U)
#define FLASH_ACR_LATENCY_3WS          FLASH_ACR_LATENCY(3U)
#define FLASH_ACR_LATENCY_4WS          FLASH_ACR_LATENCY(4U)
#define FLASH_ACR_LATENCY_5WS          FLASH_ACR_LATENCY(5U)
#define FLASH_ACR_LATENCY_6WS          FLASH_ACR_LATENCY(6U)
#define FLASH_ACR_LATENCY_7WS          FLASH_ACR_LATENCY(7U)
/**@}*/
#define FLASH_ACR_LATENCY_SHIFT		0U
#define FLASH_ACR_LATENCY_MASK		0x0fU

/** @addtogroup flash_acr_values FLASH_ACR values
 * @ingroup flash_registers
 * @{
 */
#define FLASH_ACR_WRHF_VOS1_70MHZ     (0 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS1_185MHZ    (1 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS1_225MHZ    (2 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS2_55MHZ     (0 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS2_165MHZ    (1 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS2_225MHZ    (2 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS3_45MHZ     (0 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS3_135MHZ    (1 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS3_225MHZ    (2 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS3_275MHZ    (3 << FLASH_ACR_WRHIGHFREQ_SHIFT)
/**@}*/
#define FLASH_ACR_WRHIGHFREQ_MASK     (0x3)
#define FLASH_ACR_WRHIGHFREQ_SHIFT    (0x4)

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_SR_BSY			(1U << 0U)
#define FLASH_SR_WBNE			(1U << 1U)
#define FLASH_SR_QW				(1U << 2U)
#define FLASH_SR_CRC_BUSY		(1U << 3U)
#define FLASH_SR_EOP			(1U << 16U)
#define FLASH_SR_WRPERR			(1U << 17U)
#define FLASH_SR_PGSERR			(1U << 18U)
#define FLASH_SR_STRBERR		(1U << 19U)
#define FLASH_SR_INCERR			(1U << 21U)
#define FLASH_SR_OPERR			(1U << 22U)
#define FLASH_SR_RDPERR			(1U << 23U)
#define FLASH_SR_RDSERR			(1U << 24U)
#define FLASH_SR_SNECCERR		(1U << 25U)
#define FLASH_SR_DBECCERR		(1U << 26U)
#define FLASH_SR_CRCEND			(1U << 27U)
#define FLASH_SR_CRCRDERR		(1U << 28U)

#define FLASH_SR_READ_ERROR_MASK \
	(FLASH_SR_RDPERR | FLASH_SR_RDSERR | FLASH_SR_SNECCERR | FLASH_SR_DBECCERR)

#define FLASH_SR_ERROR_MASK (                                       \
		FLASH_SR_WRPERR | FLASH_SR_PGSERR | FLASH_SR_STRBERR |      \
		FLASH_SR_INCERR | FLASH_SR_OPERR | FLASH_SR_READ_ERROR_MASK \
	)

/* --- FLASH_CR values ----------------------------------------------------- */

#define FLASH_CR_LOCK			(1U << 0U)
#define FLASH_CR_PG				(1U << 1U)
#define FLASH_CR_SER			(1U << 2U)
#define FLASH_CR_BER			(1U << 3U)
#define FLASH_CR_PROGRAM_MASK	0x3U
#define FLASH_CR_PROGRAM_SHIFT	(4U)
#define FLASH_CR_FW				(1U << 6U)
#define FLASH_CR_STRT			(1U << 7U)
#define FLASH_CR_H7Bx_FW		(1U << 4U)
#define FLASH_CR_H7Bx_STRT		(1U << 5U)
#define FLASH_CR_SNB_SHIFT		(8U)
#define FLASH_CR_SNB_MASK		(0x3U << FLASH_CR_SNB_SHIFT)
#define FLASH_CR_H7Bx_SNB_SHIFT	(6U)
#define FLASH_CR_H7Bx_SNB_MASK	(0x3U << FLASH_CR_H7Bx_SNB_SHIFT)
#define FLASH_CR_CRC_EN			(1U << 15U)
#define FLASH_CR_EOPIE			(1U << 16U)
#define FLASH_CR_WRPERRIE		(1U << 17U)
#define FLASH_CR_PGSERRIE		(1U << 18U)
#define FLASH_CR_STRBERRIE		(1U << 19U)
#define FLASH_CR_INCERRIE		(1U << 21U)
#define FLASH_CR_OPERRIE		(1U << 22U)
#define FLASH_CR_RDPERRIE		(1U << 23U)
#define FLASH_CR_RDSERRIE		(1U << 24U)
#define FLASH_CR_SNECCERRIE		(1U << 25U)
#define FLASH_CR_DBECCERRIE		(1U << 26U)
#define FLASH_CR_CRCENDIE		(1U << 27U)
#define FLASH_CR_CRCRDERRIE		(1U << 28U)
/* The operation control bits are all in the lower half the register */
#define FLASH_CR_OP_MASK        (0x0000ffffU)

/** @defgroup flash_cr_program_width Flash programming width
@ingroup flash_group

@{*/
#define FLASH_CR_PROGRAM_X8			0U
#define FLASH_CR_PROGRAM_X16		1U
#define FLASH_CR_PROGRAM_X32		2U
#define FLASH_CR_PROGRAM_X64		3U
/**@}*/

/* --- FLASH_OPTCR values -------------------------------------------------- */

#define FLASH_OPTCR_OPTLOCK		(1U << 0U)
#define FLASH_OPTCR_OPTSTRT		(1U << 1U)

/* --- Flash Keys -----------------------------------------------------------*/

#define FLASH_KEYR_KEY1			(0x45670123U)
#define FLASH_KEYR_KEY2			(0xcdef89abU)

#define FLASH_OPTKEYR_KEY1		(0x08192a3bU)
#define FLASH_OPTKEYR_KEY2		(0x4c5d6e7fU)

/* --- Flash Bank access constants ----------------------------------------- */

#define FLASH_BANK_MAX_SIZE     (0x00100000U)
#define FLASH_WRITE_BLOCK_SIZE  (32U)
#define FLASH_WRITE_BLOCK_MASK  (0x0000001FU)

enum flash_bank {
	FLASH_BANK_1 = 1,
	FLASH_BANK_2,
};

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

/** Set the Number of Wait States.
 *
 * Used to match the system clock to the FLASH memory access time. See the
 * programming manual for more information on clock speed ranges. The latency must
 * be changed to the appropriate value <b>before</b> any increase in clock
 * speed, or <b>after</b> any decrease in clock speed.
 *
 * @param[in] wait_states values from @ref flash_latency.
 */
void flash_set_ws(uint32_t wait_states);

/** Check if the FPEC is currently busy with an operation */
bool flash_is_busy(enum flash_bank bank);
/** Clear the End of OPeration flag. */
void flash_clear_eop_flag(enum flash_bank bank);
/** Clear all status flags. */
void flash_clear_status_flags(enum flash_bank bank);
/** Get back the status flags for a bank. */
uint32_t flash_get_status_flags(enum flash_bank bank);
/** Wait until Last Operation has Ended.
 * This loops indefinitely until an operation (write or erase) has completed by
 * testing for EOP and nothing being left in the queue.
 *
 * Returns whether the operation was a success or not
 */
bool flash_wait_for_last_operation(enum flash_bank bank);

/** Check if the FPEC is currently locked for writes. */
bool flash_is_locked(enum flash_bank bank);
/** Unlock the Flash Program and Erase Controller.
 * This enables write access to the Flash memory. It is locked by default on
 * reset.
 */
void flash_unlock(enum flash_bank bank);
/** Lock the Flash Program and Erase Controller.
 * Used to prevent spurious writes to FLASH.
 */
void flash_lock(enum flash_bank bank);

/** Erases a sector of a bank of Flash.
 *
 * NB: The second bank is not always valid on all STM32H7 parts. Check your part datasheet
 * to determine if it exists and is valid before using this function with FLASH_BANK_2.
 *
 * @param[in] bank one of the FLASH_BANK_* constants indicating which bank to erase
 * @param[in] sector the sector number in the bank to erase
 * @param[in] operation_parallelism the write parallelism to use for the erase -
 *            one of the PROGRAM_SIZE_* constants
 */
void flash_erase_sector(enum flash_bank bank, uint8_t sector, uint8_t operation_parallelism);
/** Erases a whole bank of Flash.
 *
 * Which banks are valid depends on your part as follows:
 * - H72x/H73x: Flash Bank 1 **only**
 * - H74x/H75x:
 *   - H75xB: Flash Bank 1 **only** with 128kiB of Flash total
 *   - H74xG: Both banks, split at 512kiB for 1MiB total
 *   - H7xxI: Both banks, split at 1MiB for 2MiB total
 * - H7Bx:
 *   - H7B0xB: Flash Bank 1 **only** with 128kiB of Flash total
 *   - H7A3xG: Flash Bank 1 **only** for 1MiB total
 *   - H7x3xI: Both banks, split at 1MiB for 2MiB total
 *
 * @param[in] bank one of the FLASH_BANK_* constants indicating which bank to erase
 * @param[in] operation_parallelism the write parallelism to use for the erase -
 *            one of the PROGRAM_SIZE_* constants
 */
void flash_erase_bank(enum flash_bank bank, uint8_t operation_parallelism);

/** Enable writing the Flash in a bank and set the operation parallelism */
void flash_program_enable(enum flash_bank bank, uint8_t operation_parallelism);
/** Disable writing the Flash in a bank*/
void flash_program_disable(enum flash_bank bank);
/** Program one u8 to Flash (forced) */
bool flash_program_byte(uintptr_t address, uint8_t data);
/** Program one u16 to Flash (forced) */
bool flash_program_half_word(uintptr_t address, uint16_t data);
/** Program one u32 to Flash (forced) */
bool flash_program_word(uintptr_t address, uint32_t data);
/** Program one u64 to Flash (forced) */
bool flash_program_double_word(uintptr_t address, uint64_t data);
/** Program a block of data to Flash (forced) */
bool flash_program(uintptr_t address, const uint8_t *data, size_t len);
/** Force the write operation - required to flush out a non-full block of data to the Flash
 *
 * NB: This must be called only *after* setting up the operation with the above functions.
 */
void flash_program_force(enum flash_bank bank);

/** Unlock the Option Byte Access.
 * This enables write access to the option bytes. It is locked by default on
 * reset.
 */
void flash_unlock_option_bytes(void);
/** Lock the Option Byte Access.
 * This disables write access to the option bytes.
 */
void flash_lock_option_bytes(void);
/** Program the Option Bytes.
 * Write
 */
void flash_program_option_bytes(uint32_t data);

END_DECLS
/**@}*/

#endif
