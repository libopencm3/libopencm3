/** @addtogroup flash_file
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Ken Sarkies <ksarkies@internode.on.net>
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
/** @brief Unlock the Flash Program and Erase Controller

This enables write access to the Flash memory. It is locked by default on
reset.
*/


/*---------------------------------------------------------------------------*/
/** @brief Clear the Programming Error Status Flag

*/

void flash_clear_pgerr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGERR;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Write Protect Error Status Flag

*/

void flash_clear_wrprterr_flag(void)
{
	FLASH_SR |= FLASH_SR_WRPRTERR;
}

/*---------------------------------------------------------------------------*/
/** @brief Wait until Last Operation has Ended

This loops indefinitely until an operation (write or erase) has completed by
testing the busy flag.
*/

void flash_wait_for_last_operation(void)
{
	while ((flash_get_status_flags() & FLASH_SR_BSY) == FLASH_SR_BSY);
}

/*---------------------------------------------------------------------------*/
/** @brief Program a 32 bit Word to FLASH

This performs all operations necessary to program a 32 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

Status bit polling is used to detect end of operation.

@param[in] address Full address of flash word to be programmed.
@param[in] data word to write
*/

void flash_program_word(uint32_t address, uint32_t data)
{
	flash_program_half_word(address, (uint16_t)data);
	flash_program_half_word(address+2, (uint16_t)(data>>16));
}

/*---------------------------------------------------------------------------*/
/** @brief Erase All Option Bytes

This performs all operations necessary to erase the option bytes. These must
first be fully erased before attempting to program them, therefore it is
recommended to check these after an erase attempt.
*/

void flash_erase_option_bytes(void)
{
	flash_wait_for_last_operation();

	if ((FLASH_CR & FLASH_CR_OPTWRE) == 0) {
		flash_unlock_option_bytes();
	}

	FLASH_CR |= FLASH_CR_OPTER;	/* Enable option byte erase. */
	FLASH_CR |= FLASH_CR_STRT;
	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_OPTER;	/* Disable option byte erase. */
}

/*---------------------------------------------------------------------------*/
/** @brief Program the Option Bytes

This performs all operations necessary to program the option bytes.
The write protect error flag should be checked separately for the event that
an option byte had not been properly erased before calling this function.

Only the lower 8 bits of the data is significant.

@param[in] address Address of option byte from @ref flash_options.
@param[in] data value to write
*/

void flash_program_option_bytes(uint32_t address, uint16_t data)
{
	flash_wait_for_last_operation();

	if ((FLASH_CR & FLASH_CR_OPTWRE) == 0) {
		flash_unlock_option_bytes();
	}

	FLASH_CR |= FLASH_CR_OPTPG;	/* Enable option byte programming. */
	MMIO16(address) = data;
	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_OPTPG;	/* Disable option byte programming. */
}

/**@}*/

