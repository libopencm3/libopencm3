/** @addtogroup flash_file FLASH peripheral API
 * @ingroup peripheral_apis
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2024 Rachel Mant <git@dragonmux.network>
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

#include <string.h>
#include <libopencm3/stm32/flash.h>

#define REBASE(x)        MMIO32((x) + (bank_base_address))
#define MIN(x, y)         ((x) < (y) ? (x) : (y))
#define DBGMCU_IDCODE    (DBGMCU_BASE + 0x000U)

/** @brief Set the Program Parallelism Size
 *
 * Set the programming parallelism width. Note carefully the power supply voltage
 * restrictions under which the different word sizes may be used. See the
 * programming manual for more information.
 * @param[in] psize The programming word width one of: @ref flash_cr_program_width
*/
static inline void flash_set_program_size(const uintptr_t bank_base_address, const uint32_t psize)
{
	REBASE(FLASH_CR) &= ~(FLASH_CR_PROGRAM_MASK << FLASH_CR_PROGRAM_SHIFT);
	REBASE(FLASH_CR) |= psize << FLASH_CR_PROGRAM_SHIFT;
}

/** @brief Translate a bank number to its FPEC base address */
static inline uintptr_t flash_bank_address(const enum flash_bank bank)
{
	switch (bank) {
		case FLASH_BANK_1:
			return FLASH_FPEC1_BASE;
		case FLASH_BANK_2:
			return FLASH_FPEC2_BASE;
	}
	/* We should never be able to reach this point */
	__builtin_unreachable();
}

static inline enum flash_bank flash_bank_from_address(const uintptr_t address)
{
	/* Make it undefined behaviour to call this function with an address below the Flash range start */
	if (address < FLASH_BASE)
		__builtin_unreachable();
	/* Check if the addres falls in the first bank */
	if (address < FLASH_BASE + FLASH_BANK_MAX_SIZE)
		return FLASH_BANK_1;
	/* Check if the address falls in the second */
	if (address < FLASH_BASE + (FLASH_BANK_MAX_SIZE << 1U))
		return FLASH_BANK_2;
	/* Turn any other addresses passed in into UB too */
	__builtin_unreachable();
}

static inline enum device_variant mcu_variant(void)
{
	/* Read the device DBGMCU ID code out */
	const uint32_t idcode = DBGMCU_IDCODE;
	/* Mask out and return the device ID component */
	return idcode & 0xfffU;
}

void flash_set_ws(const uint32_t wait_states)
{
	/* Read the current ACR value and mask out the wait states component */
	const uint32_t reg32 = FLASH_ACR & ~(FLASH_ACR_LATENCY_MASK << FLASH_ACR_LATENCY_SHIFT);
	/* Write back the new value, with the new wait states shifted in to place */
	FLASH_ACR = reg32 | (wait_states << FLASH_ACR_LATENCY_SHIFT);
}

bool flash_is_busy(const enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	/*
	 * Read back the current status register value and check for there still
	 * being items in the queue, and the EOP flag not yet being set.
	 */
	const uint32_t status = REBASE(FLASH_SR);
	return !(status & FLASH_SR_EOP) && (status & FLASH_SR_QW);
}

void flash_clear_eop_flag(const enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	/*
	 * The H7 uses a special clear register for the control bits related
	 * to errors and operation completion, which clears the *status* bits.
	 * The status register is strictly read-only on this part.
	 */
	REBASE(FLASH_CCR) = FLASH_SR_EOP;
}

void flash_clear_status_flags(const enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	REBASE(FLASH_CCR) = FLASH_SR_ERROR_MASK | FLASH_SR_EOP;
}

uint32_t flash_get_status_flags(enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	return REBASE(FLASH_SR) & FLASH_SR_ERROR_MASK;
}

bool flash_wait_for_last_operation(const enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	/* Wait in a busy loop while the controller says we're busy */
	while (flash_is_busy(bank))
		continue;
	/* Pull back if any errors occured and return accordingly */
	return !(REBASE(FLASH_SR) & FLASH_SR_ERROR_MASK);
}

bool flash_is_locked(const enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	return REBASE(FLASH_CR) & FLASH_CR_LOCK;
}

void flash_unlock(const enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	/* Authorize the FPEC access. */
	REBASE(FLASH_KEYR) = FLASH_KEYR_KEY1;
	REBASE(FLASH_KEYR) = FLASH_KEYR_KEY2;
}

void flash_lock(const enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	REBASE(FLASH_CR) |= FLASH_CR_LOCK;
}

void flash_erase_sector(const enum flash_bank bank, const uint8_t sector, const uint8_t operation_parallelism)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	const enum device_variant variant = mcu_variant();
	/* Reset the bottom control register bits ready for the new operation */
	REBASE(FLASH_CR) &= ~FLASH_CR_OP_MASK;
	/* H7Bx does not have write parallelism bits */
	if (variant != STM32H7Bx)
		flash_set_program_size(bank_base_address, operation_parallelism);
	/*
	 * The control register layout is dependant on the variant.
	 * Set up the sector erase operation and then kick it off.
	 */
	switch (variant) {
	case STM32H7Bx:
		REBASE(FLASH_CR) |= FLASH_CR_SER | (sector << FLASH_CR_H7Bx_SNB_SHIFT);
		REBASE(FLASH_CR) |= FLASH_CR_H7Bx_STRT;
		break;
	default:
		REBASE(FLASH_CR) |= FLASH_CR_SER | (sector << FLASH_CR_SNB_SHIFT);
		REBASE(FLASH_CR) |= FLASH_CR_STRT;
		break;
	}
}

void flash_erase_bank(const enum flash_bank bank, const uint8_t operation_parallelism)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	const enum device_variant variant = mcu_variant();
	/* Reset the bottom control register bits ready for the new operation */
	REBASE(FLASH_CR) &= ~FLASH_CR_OP_MASK;
	/* H7Bx does not have write parallelism bits */
	if (variant != STM32H7Bx)
		flash_set_program_size(bank_base_address, operation_parallelism);
	/*
	 * The control register layout is dependant on the variant.
	 * Set up the bank erase operation and then kick it off.
	 * NB: per §4.3.10 "Standard flash bank erase sequence" of RM0433 rev8, pg166
	 *   setting BER and start can be merged.
	 */
	switch (variant) {
	case STM32H7Bx:
		REBASE(FLASH_CR) |= FLASH_CR_BER | FLASH_CR_H7Bx_STRT;
		break;
	default:
		REBASE(FLASH_CR) |= FLASH_CR_BER | FLASH_CR_STRT;
		break;
	}
}

void flash_program_enable(const enum flash_bank bank, const uint8_t operation_parallelism)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	const enum device_variant variant = mcu_variant();
	/* Reset the bottom control register bits ready for the new operation */
	REBASE(FLASH_CR) &= ~FLASH_CR_OP_MASK;
	/* H7Bx does not have write parallelism bits */
	if (variant != STM32H7Bx)
		flash_set_program_size(bank_base_address, operation_parallelism);
	REBASE(FLASH_CR) |= FLASH_CR_PG;
}

void flash_program_disable(const enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	REBASE(FLASH_CR) &= ~FLASH_CR_PG;
}

bool flash_program_byte(const uintptr_t address, const uint8_t data)
{
	const enum flash_bank bank = flash_bank_from_address(address);
	flash_program_enable(bank, FLASH_CR_PROGRAM_X8);
	MMIO8(address) = data;
	flash_program_force(bank);
	return flash_wait_for_last_operation(bank);
}

bool flash_program_half_word(const uintptr_t address, const uint16_t data)
{
	const enum flash_bank bank = flash_bank_from_address(address);
	flash_program_enable(bank, FLASH_CR_PROGRAM_X16);
	MMIO16(address) = data;
	flash_program_force(bank);
	return flash_wait_for_last_operation(bank);
}

bool flash_program_word(const uintptr_t address, const uint32_t data)
{
	const enum flash_bank bank = flash_bank_from_address(address);
	flash_program_enable(bank, FLASH_CR_PROGRAM_X32);
	MMIO32(address) = data;
	flash_program_force(bank);
	return flash_wait_for_last_operation(bank);
}

bool flash_program_double_word(const uintptr_t address, const uint64_t data)
{
	const enum flash_bank bank = flash_bank_from_address(address);
	flash_program_enable(bank, FLASH_CR_PROGRAM_X64);
	MMIO64(address) = data;
	flash_program_force(bank);
	return flash_wait_for_last_operation(bank);
}

bool flash_program(const uintptr_t address, const uint8_t *const data, const size_t len)
{
	/* Begin operations */
	const enum flash_bank bank = flash_bank_from_address(address);
	const uintptr_t bank_base_address = flash_bank_address(bank);
	const enum device_variant variant = mcu_variant();
	flash_program_enable(bank, FLASH_CR_PROGRAM_X64);
	/* If the address to write does not start on a write block boundary, write out what we have and force write it */
	size_t offset = address & FLASH_WRITE_BLOCK_MASK;
	if (offset != 0U) {
		/* Figure out the amount of data that needs written to complete the block */
		const size_t amount = MIN(len, FLASH_WRITE_BLOCK_SIZE - offset);
		memcpy((void *)address, data, amount);
		flash_program_force(bank);
		if (!flash_wait_for_last_operation(bank))
			return false;
		offset = amount;
		/* Having completed the forced write, reset the FW bit */
		switch (variant) {
		case STM32H7Bx:
			REBASE(FLASH_CR) &= FLASH_CR_H7Bx_FW;
			break;
		default:
			REBASE(FLASH_CR) &= FLASH_CR_FW;
			break;
		}
	}
	/* Now write out as many complete blocks as we have */
	for (; len - offset >= FLASH_WRITE_BLOCK_SIZE; offset += FLASH_WRITE_BLOCK_SIZE) {
		memcpy((void *)(address + offset), data + offset, FLASH_WRITE_BLOCK_SIZE);
		if (!flash_wait_for_last_operation(bank))
			return false;
	}
	/* Finally, figure out if we've got anything left to write, and flush that out too */
	const size_t amount = len - offset;
	if (amount != 0U) {
		memcpy((void *)(address + offset), data + offset, amount);
		flash_program_force(bank);
		if (!flash_wait_for_last_operation(bank))
			return false;
		/* Having completed the forced write, reset the FW bit */
		switch (variant) {
		case STM32H7Bx:
			REBASE(FLASH_CR) &= FLASH_CR_H7Bx_FW;
			break;
		default:
			REBASE(FLASH_CR) &= FLASH_CR_FW;
			break;
		}
	}
	/* We're done, clean up the enable bit and return success */
	flash_program_disable(bank);
	return true;
}

void flash_program_force(const enum flash_bank bank)
{
	const uintptr_t bank_base_address = flash_bank_address(bank);
	const enum device_variant variant = mcu_variant();
	/*
	 * The control register layout is dependant on the variant.
	 * Set the FW bit appropriately to force the write operation that's already been set up.
	 */
	switch (variant) {
	case STM32H7Bx:
		REBASE(FLASH_CR) |= FLASH_CR_H7Bx_FW;
		break;
	default:
		REBASE(FLASH_CR) |= FLASH_CR_FW;
		break;
	}
}

void flash_unlock_option_bytes(void)
{
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY1;
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY2;
}

void flash_lock_option_bytes(void)
{
	FLASH_OPTCR |= FLASH_OPTCR_OPTLOCK;
}
