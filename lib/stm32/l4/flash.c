/** @defgroup flash_file FLASH
 *
 * @ingroup STM32L4xx
 *
 * @brief <b>libopencm3 STM32L4xx FLASH</b>
 *
 * @version 1.0.0
 *
 * Benjamin Levine <benjamin@jesco.karoo.co.uk>
 *
 * @date 12 February 2016
 *
 * This library supports the FLASH memory controller in the STM32L4
 * series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * For the STM32L4xx, accessing FLASH memory is described briefly in
 * section 3 of the STM32L4x6 Reference Manual.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Benjamin Levine <benjamin@jesco.karoo.co.uk>
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

/** @brief Disable the FLASH Prefetch Buffer

Note carefully the clock restrictions under which the prefetch buffer may be
set to disabled. See the reference manual for details.
*/
void flash_prefetch_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_PRFTEN;
}

/** @brief Set the Number of Wait States

Used to match the system clock to the FLASH memory access time. See the
programming manual for more information on clock speed ranges. The latency must
be changed to the appropriate value <b>before</b> any increase in clock
speed, or <b>after</b> any decrease in clock speed.

@param[in] ws values from @ref flash_latency.
*/
void flash_set_ws(uint32_t ws)
{
	uint32_t reg32;

	reg32 = FLASH_ACR;
	reg32 &= ~(FLASH_ACR_LATENCY_MASK << FLASH_ACR_LATENCY_SHIFT);
	reg32 |= (ws << FLASH_ACR_LATENCY_SHIFT);
	FLASH_ACR = reg32;
}

/** @brief Unlock the Flash Program and Erase Controller
 * This enables write access to the Flash memory. It is locked by default on
 * reset.
 */
void flash_unlock(void)
{
	/* Clear the unlock sequence state. */
	FLASH_CR |= FLASH_CR_LOCK;

	/* Authorize the FPEC access. */
	FLASH_KEYR = FLASH_KEYR_KEY1;
	FLASH_KEYR = FLASH_KEYR_KEY2;
}

/** @brief Lock the Flash Program and Erase Controller
 * Used to prevent spurious writes to FLASH.
 */
void flash_lock(void)
{
	FLASH_CR |= FLASH_CR_LOCK;
}

/** @brief Clear the Programming Error Status Flag
 */
void flash_clear_pgperr_flag(void)
{
	FLASH_SR |= FLASH_SR_PROGERR;
}

/** @brief Clear the End of Operation Status Flag
 */
void flash_clear_eop_flag(void)
{
	FLASH_SR |= FLASH_SR_EOP;
}

/** @brief Clear the Busy Status Flag
 */
void flash_clear_bsy_flag(void)
{
	FLASH_SR &= ~FLASH_SR_BSY;
}


/** @brief Wait until Last Operation has Ended
 * This loops indefinitely until an operation (write or erase) has completed
 * by testing the busy flag.
 */
void flash_wait_for_last_operation(void)
{
	while ((FLASH_SR & FLASH_SR_BSY) == FLASH_SR_BSY);
}

/** @brief Enable the Data Cache
 */
void flash_dcache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_DCEN;
}

/** @brief Disable the Data Cache
 */
void flash_dcache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_DCEN;
}

/** @brief Enable the Instruction Cache
 */
void flash_icache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_ICEN;
}

/** @brief Disable the Instruction Cache
 */
void flash_icache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_ICEN;
}


/** @brief Reset the Data Cache
 * The data cache must be disabled for this to have effect.
 */
void flash_dcache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_DCRST;
}

/** @brief Reset the Instruction Cache
 * The instruction cache must be disabled for this to have effect.
 */
void flash_icache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_ICRST;
}

/** @brief Clear the Programming Sequence Error Flag
 * This flag is set when incorrect programming configuration has been made.
 */
void flash_clear_pgserr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGSERR;
}

/** @brief Clear the Programming Alignment Error Flag
 */
void flash_clear_pgaerr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGAERR;
}

/** @brief Clear the Write Protect Error Flag
 */
void flash_clear_wrperr_flag(void)
{
	FLASH_SR |= FLASH_SR_WRPERR;
}

/** @brief Clear All Status Flags
 * Program error, end of operation, write protect error, busy.
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

/** @brief Unlock the Option Byte Access
 * This enables write access to the option bytes. It is locked by default on
 * reset.
 */
void flash_unlock_option_bytes(void)
{
	/* Clear the unlock state. */
	FLASH_CR |= FLASH_CR_OPTLOCK;

	/* Unlock option bytes. */
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY1;
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY2;
}

/** @brief Lock the Option Byte Access
 * This disables write access to the option bytes. It is locked by default on
 * reset.
 */
void flash_lock_option_bytes(void)
{
	FLASH_CR |= FLASH_CR_OPTLOCK;
}

/** @brief Program a 32 bit Word to FLASH
 * This performs all operations necessary to program a 32 bit word to FLASH
 * memory. The program error flag should be checked separately for the event
 * that memory was not properly erased.
 *
 * @param[in] address Starting address in Flash.
 * @param[in] data word to write
 */
void flash_program_word(uint32_t address, uint32_t data)
{
	/* Ensure that all flash operations are complete. */
	flash_wait_for_last_operation();

	/* Enable writes to flash. */
	FLASH_CR |= FLASH_CR_PG;

	/* Program the word. */
	MMIO32(address) = data;

	/* Wait for the write to complete. */
	flash_wait_for_last_operation();

	/* Disable writes to flash. */
	FLASH_CR &= ~FLASH_CR_PG;
}

/** @brief Program a Data Block to FLASH
 * This programs an arbitrary length data block to FLASH memory.
 * The program error flag should be checked separately for the event that
 * memory was not properly erased.
 * @param[in] address Starting address in Flash.
 * @param[in] data Pointer to start of data block.
 * @param[in] len Length of data block.
 */
void flash_program(uint32_t address, uint8_t *data, uint32_t len)
{
	/* TODO: Use dword and word size program operations where possible for
	 * turbo speed.
	 */
	uint32_t i;
	for (i = 0; i < len; i++) {
		flash_program_word(address+i, data[i]);
	}
}

/** @brief Erase a Sector of FLASH
 * This performs all operations necessary to erase a sector in FLASH memory.
 * The page should be checked to ensure that it was properly erased. A sector
 * must first be fully erased before attempting to program it.
 * See the reference manual or the FLASH programming manual for details.
 * @param[in] sector (0 - 11 for some parts, 0-23 on others)
 */
void flash_erase_sector(uint8_t sector)
{
	flash_wait_for_last_operation();

	FLASH_CR &= ~(FLASH_CR_PNB_MASK << FLASH_CR_PNB_SHIFT);
	FLASH_CR |= (sector & FLASH_CR_PNB_MASK) << FLASH_CR_PNB_SHIFT;
	FLASH_CR |= FLASH_CR_PER;
	FLASH_CR |= FLASH_CR_START;

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_PER;
	FLASH_CR &= ~(FLASH_CR_PNB_MASK << FLASH_CR_PNB_SHIFT);
}

/** @brief Erase All FLASH
 * This performs all operations necessary to erase all sectors in the FLASH
 * memory.
 */
void flash_erase_all_sectors(void)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_MER1 | FLASH_CR_MER2;
	FLASH_CR |= FLASH_CR_START;

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_MER1 & ~FLASH_CR_MER2;
}

/** @brief Program the Option Bytes
 * This performs all operations necessary to program the option bytes.
 * The option bytes do not need to be erased first.
 * @param[in] data value to be programmed.
 */
void flash_program_option_bytes(uint32_t data)
{
	flash_wait_for_last_operation();

	if (FLASH_CR & FLASH_CR_OPTLOCK) {
		flash_unlock_option_bytes();
	}

	FLASH_OPTR = data & ~0x3;
	FLASH_OPTR |= FLASH_CR_OPTSTRT;
	flash_wait_for_last_operation();
}
/**@}*/

