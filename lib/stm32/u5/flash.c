/** @addtogroup flash_file FLASH peripheral API
 * @ingroup peripheral_apis
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

#define FLASH_WRITE_BLOCK_SIZE 16U

void flash_lock(void)
{
	FLASH_NSCR |= FLASH_NSCR_LOCK;
}

void flash_unlock(void)
{
	FLASH_NSKEYR = FLASH_NSKEYR_KEY1;
	FLASH_NSKEYR = FLASH_NSKEYR_KEY2;
}

void flash_lock_option_bytes(void)
{
	FLASH_NSCR |= FLASH_NSCR_OPTLOCK;
}

bool flash_is_busy(void)
{
	return (FLASH_NSSR & FLASH_NSSR_EOP) != 0U;
}

void flash_clear_eop_flag(void)
{
	/* NSSR clearable status bits are all W1C */
	FLASH_NSSR = FLASH_NSSR_EOP;
}

bool flash_wait_for_last_operation(void)
{
	/* Wait in a busy loop while the controller says we're busy */
	while (flash_is_busy())
		continue;
	/* Pull back any errors that occured and return accordingly */
	return (FLASH_NSSR & FLASH_NSSR_ERROR_MASK) != 0U;
}

void flash_erase_page(const flash_bank_e bank, const uint8_t page)
{
	/* Reset the bottom control bits ready for the new operation */
	FLASH_NSCR &= ~FLASH_NSCR_OP_MASK;
	/* Set up the control register for the erase, and then set the erase going */
	FLASH_NSCR |= (bank == FLASH_BANK_1 ? 0U : FLASH_NSCR_BKER) | (page << FLASH_NSCR_PNB_SHIFT) | FLASH_NSCR_PER;
	FLASH_NSCR |= FLASH_NSCR_STRT;
}

void flash_erase_bank(const flash_bank_e bank)
{
	/* Reset the bottom control bits ready for the new operation */
	FLASH_NSCR &= ~FLASH_NSCR_OP_MASK;
	/* Set up the mass erase operation for the requested bank, and then set it running */
	if (bank == FLASH_BANK_1) {
		FLASH_NSCR |= FLASH_NSCR_MER1;
	} else {
		FLASH_NSCR |= FLASH_NSCR_MER2;
	}
	FLASH_NSCR |= FLASH_NSCR_STRT;
}

static void flash_program_enable(void)
{
	while (FLASH_NSSR & FLASH_NSSR_BSY)
		continue;
	/* Reset the bottom control register bits ready for the new operation */
	FLASH_NSCR &= ~FLASH_NSCR_OP_MASK;
	/* Set up for Flash programming */
	FLASH_NSCR |= FLASH_NSCR_PG;
}

static void flash_program_disable(void)
{
	FLASH_NSSR = FLASH_NSSR_EOP;
	FLASH_NSCR &= ~FLASH_NSCR_PG;
}

bool flash_program(const uintptr_t address, const uint8_t *const data, const size_t len)
{
	/* Enable Flash programming */
	flash_program_enable();

	/* Turn the starting destination address into an aligned pointer to the first u128 to write */
	volatile uint32_t *dest = (uint32_t *)(address & ~(FLASH_WRITE_BLOCK_SIZE - 1U));
	/* Figure out how misaligned the first block is and handle that */
	uintptr_t alignment = address & (FLASH_WRITE_BLOCK_SIZE - 1U);

	for (size_t offset = 0U; offset < len;) {
		/* Start with the block to write all in erase state */
		uint32_t block[4];
		memset(block, 0xffU, sizeof(block));
		/* Compute how many bytes we get to consume this iteration and copy those in */
		const size_t amount = FLASH_WRITE_BLOCK_SIZE - alignment;
		memcpy(((uint8_t *)block) + alignment, data + offset, amount);
		/* Copy the 4 u32's to their destination in Flash and wait for programming to complete */
		for (size_t i = 0; i < ARRAY_LENGTH(block); ++i) {
			dest[i] = block[i];
		}
		while (FLASH_NSSR & FLASH_NSSR_BSY)
			continue;
		/* Check for errors and bomb out if there are any */
		if (FLASH_NSSR & FLASH_NSSR_ERROR_MASK)
			return false;
		/* Update where we are in the input buffer and with what alignment */
		offset += amount;
		alignment = 0U;
		dest += ARRAY_LENGTH(block);
	}

	/* We're done, clean up the enable bit and return success */
	flash_program_disable();
	return true;
}
