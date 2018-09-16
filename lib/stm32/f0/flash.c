/** @defgroup flash_file FLASH
 *
 * @ingroup STM32F0xx
 *
 * @brief <b>libopencm3 STM32F05x FLASH</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Frantisek Burian <BuFran@seznam.cz>
 *
 * @date 14 January 2014
 *
 * For the STM32F05x, accessing FLASH memory is described in
 * section 3 of the STM32F05x Reference Manual.
 *
 * FLASH memory may be used for data storage as well as code, and may be
 * programmatically modified. Note that for firmware upload the STM32F1xx
 * provides a built-in bootloader in system memory that can be entered from a
 * running program.
 *
 * FLASH must first be unlocked before programming. In this module a write to
 * FLASH is a blocking operation until the end-of-operation flag is asserted.
 *
 * @note: don't forget to lock it again when all operations are complete.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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
/** @brief Clear All Status Flags

Program error, end of operation, write protect error, busy.
*/

void flash_clear_status_flags(void)
{
	flash_clear_pgerr_flag();
	flash_clear_eop_flag();
	flash_clear_wrprterr_flag();
}

/*---------------------------------------------------------------------------*/
/** @brief Read All Status Flags

The programming error, end of operation, write protect error and busy flags
are returned in the order of appearance in the status register.

@returns uint32_t. bit 0: busy, bit 2: programming error, bit 4: write protect
error, bit 5: end of operation.
*/

uint32_t flash_get_status_flags(void)
{
	return FLASH_SR & (FLASH_SR_PGERR |
			FLASH_SR_EOP |
			FLASH_SR_WRPRTERR |
			FLASH_SR_BSY);
}

/*---------------------------------------------------------------------------*/
/** @brief Program a Half Word to FLASH

This performs all operations necessary to program a 16 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

Status bit polling is used to detect end of operation.

@param[in] address Full address of flash half word to be programmed.
@param[in] data half word to write
*/

void flash_program_half_word(uint32_t address, uint16_t data)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_PG;

	MMIO16(address) = data;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PG;
}

/*---------------------------------------------------------------------------*/
/** @brief Erase a Page of FLASH

This performs all operations necessary to erase a page in FLASH memory.
The page should be checked to ensure that it was properly erased. A page must
first be fully erased before attempting to program it.

Note that the page sizes differ between devices. See the reference manual or
the FLASH programming manual for details.

@param[in] page_address Full address of flash page to be erased.
*/

void flash_erase_page(uint32_t page_address)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_PER;
	FLASH_AR = page_address;
	FLASH_CR |= FLASH_CR_STRT;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PER;
}

/*---------------------------------------------------------------------------*/
/** @brief Erase All FLASH

This performs all operations necessary to erase all user pages in the FLASH
memory. The information block is unaffected.
*/

void flash_erase_all_pages(void)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_MER;		/* Enable mass erase. */
	FLASH_CR |= FLASH_CR_STRT;		/* Trigger the erase. */

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_MER;		/* Disable mass erase. */

}

/**@}*/

