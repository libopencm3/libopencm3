/** @addtogroup flash_file
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

/**@{*/

#include <libopencm3/stm32/flash.h>

/*---------------------------------------------------------------------------*/
/** @brief Set the Program Parallelism Size

Set the programming word width. Note carefully the power supply voltage
restrictions under which the different word sizes may be used. See the
programming manual for more information.
@param[in] psize The programming word width one of: @ref flash_cr_program_width
*/

static inline void flash_set_program_size(uint32_t psize)
{
	FLASH_CR &= ~(FLASH_CR_PROGRAM_MASK << FLASH_CR_PROGRAM_SHIFT);
	FLASH_CR |= psize << FLASH_CR_PROGRAM_SHIFT;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the Data Cache

*/

void flash_dcache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_DCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable the Data Cache

*/

void flash_dcache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_DCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the Instruction Cache

*/

void flash_icache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_ICEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable the Instruction Cache

*/

void flash_icache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_ICEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the FLASH Prefetch Buffer

This buffer is used for instruction fetches and is enabled by default after
reset.

Note carefully the clock restrictions under which the prefetch buffer may be
enabled or disabled. Changes are normally made while the clock is running in
the power-on low frequency mode before being set to a higher speed mode.
See the reference manual for details.
*/

void flash_prefetch_enable(void)
{
	FLASH_ACR |= FLASH_ACR_PRFTEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable the FLASH Prefetch Buffer

Note carefully the clock restrictions under which the prefetch buffer may be
set to disabled. See the reference manual for details.
*/

void flash_prefetch_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_PRFTEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Reset the Data Cache

The data cache must be disabled for this to have effect.
*/

void flash_dcache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_DCRST;
}

/*---------------------------------------------------------------------------*/
/** @brief Reset the Instruction Cache

The instruction cache must be disabled for this to have effect.
*/

void flash_icache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_ICRST;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Programming Sequence Error Flag

This flag is set when incorrect programming configuration has been made.
*/

void flash_clear_pgserr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGSERR;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Programming Alignment Error Flag

*/

void flash_clear_pgaerr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGAERR;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Write Protect Error Flag

*/

void flash_clear_wrperr_flag(void)
{
	FLASH_SR |= FLASH_SR_WRPERR;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear All Status Flags

Program error, end of operation, write protect error, busy.
*/

void flash_clear_status_flags(void)
{
	flash_clear_pgserr_flag();
	flash_clear_pgaerr_flag();
	flash_clear_wrperr_flag();
	flash_clear_pgperr_flag();
	flash_clear_eop_flag();
	flash_clear_bsy_flag();
}

/*---------------------------------------------------------------------------*/
/** @brief Unlock the Option Byte Access

This enables write access to the option bytes. It is locked by default on
reset.
*/

void flash_unlock_option_bytes(void)
{
	/* Clear the unlock state. */
	FLASH_OPTCR |= FLASH_OPTCR_OPTLOCK;

	/* Unlock option bytes. */
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY1;
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY2;
}

/*---------------------------------------------------------------------------*/
/** @brief Lock the Option Byte Access

This disables write access to the option bytes. It is locked by default on
reset.
*/

void flash_lock_option_bytes(void)
{
	FLASH_OPTCR |= FLASH_OPTCR_OPTLOCK;
}

/*---------------------------------------------------------------------------*/
/** @brief Program a 64 bit Word to FLASH

This performs all operations necessary to program a 64 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

@param[in] address Starting address in Flash.
@param[in] data Double word to write
*/

void flash_program_double_word(uint32_t address, uint64_t data)
{
	/* Ensure that all flash operations are complete. */
	flash_wait_for_last_operation();
	flash_set_program_size(FLASH_CR_PROGRAM_X64);

	/* Enable writes to flash. */
	FLASH_CR |= FLASH_CR_PG;

	/* Program the double_word. */
	MMIO64(address) = data;

	/* Wait for the write to complete. */
	flash_wait_for_last_operation();

	/* Disable writes to flash. */
	FLASH_CR &= ~FLASH_CR_PG;
}

/*---------------------------------------------------------------------------*/
/** @brief Program a 32 bit Word to FLASH

This performs all operations necessary to program a 32 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

@param[in] address Starting address in Flash.
@param[in] data word to write
*/

void flash_program_word(uint32_t address, uint32_t data)
{
	/* Ensure that all flash operations are complete. */
	flash_wait_for_last_operation();
	flash_set_program_size(FLASH_CR_PROGRAM_X32);

	/* Enable writes to flash. */
	FLASH_CR |= FLASH_CR_PG;

	/* Program the word. */
	MMIO32(address) = data;

	/* Wait for the write to complete. */
	flash_wait_for_last_operation();

	/* Disable writes to flash. */
	FLASH_CR &= ~FLASH_CR_PG;
}

/*---------------------------------------------------------------------------*/
/** @brief Program a Half Word to FLASH

This performs all operations necessary to program a 16 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

@param[in] address Starting address in Flash.
@param[in] data half word to write
*/

void flash_program_half_word(uint32_t address, uint16_t data)
{
	flash_wait_for_last_operation();
	flash_set_program_size(FLASH_CR_PROGRAM_X16);

	FLASH_CR |= FLASH_CR_PG;

	MMIO16(address) = data;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PG;		/* Disable the PG bit. */
}

/*---------------------------------------------------------------------------*/
/** @brief Program an 8 bit Byte to FLASH

This performs all operations necessary to program an 8 bit byte to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

@param[in] address Starting address in Flash.
@param[in] data byte to write
*/

void flash_program_byte(uint32_t address, uint8_t data)
{
	flash_wait_for_last_operation();
	flash_set_program_size(FLASH_CR_PROGRAM_X8);

	FLASH_CR |= FLASH_CR_PG;

	MMIO8(address) = data;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PG;		/* Disable the PG bit. */
}

/*---------------------------------------------------------------------------*/
/** @brief Program a Data Block to FLASH

This programs an arbitrary length data block to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

@param[in] address Starting address in Flash.
@param[in] data Pointer to start of data block.
@param[in] len Length of data block.
*/

void flash_program(uint32_t address, uint8_t *data, uint32_t len)
{
	/* TODO: Use dword and word size program operations where possible for
	 * turbo speed.
	 */
	uint32_t i;
	for (i = 0; i < len; i++) {
		flash_program_byte(address+i, data[i]);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Erase a Sector of FLASH

This performs all operations necessary to erase a sector in FLASH memory.
The page should be checked to ensure that it was properly erased. A sector must
first be fully erased before attempting to program it.

See the reference manual or the FLASH programming manual for details.

@param[in] sector (0 - 11 for some parts, 0-23 on others)
@param program_size: 0 (8-bit), 1 (16-bit), 2 (32-bit), 3 (64-bit)
*/

void flash_erase_sector(uint8_t sector, uint32_t program_size)
{
	flash_wait_for_last_operation();
	flash_set_program_size(program_size);

	FLASH_CR &= ~(FLASH_CR_SNB_MASK << FLASH_CR_SNB_SHIFT);
	FLASH_CR |= (sector & FLASH_CR_SNB_MASK) << FLASH_CR_SNB_SHIFT;
	FLASH_CR |= FLASH_CR_SER;
	FLASH_CR |= FLASH_CR_STRT;

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_SER;
	FLASH_CR &= ~(FLASH_CR_SNB_MASK << FLASH_CR_SNB_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief Erase All FLASH

This performs all operations necessary to erase all sectors in the FLASH
memory.

@param program_size: 0 (8-bit), 1 (16-bit), 2 (32-bit), 3 (64-bit)
*/

void flash_erase_all_sectors(uint32_t program_size)
{
	flash_wait_for_last_operation();
	flash_set_program_size(program_size);

	FLASH_CR |= FLASH_CR_MER;		/* Enable mass erase. */
	FLASH_CR |= FLASH_CR_STRT;		/* Trigger the erase. */

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_MER;		/* Disable mass erase. */
}

/*---------------------------------------------------------------------------*/
/** @brief Program the Option Bytes

This performs all operations necessary to program the option bytes.
The option bytes do not need to be erased first.

@param[in] data value to be programmed.
*/

void flash_program_option_bytes(uint32_t data)
{
	flash_wait_for_last_operation();

	if (FLASH_OPTCR & FLASH_OPTCR_OPTLOCK) {
		flash_unlock_option_bytes();
	}

	FLASH_OPTCR = data & ~0x3;
	FLASH_OPTCR |= FLASH_OPTCR_OPTSTRT;  /* Enable option byte prog. */
	flash_wait_for_last_operation();
}
/**@}*/
