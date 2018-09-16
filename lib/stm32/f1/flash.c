/** @defgroup flash_file FLASH
 *
 * @ingroup STM32F1xx
 *
 * @brief <b>libopencm3 STM32F1xx FLASH Memory</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Thomas Otto <tommi@viadmin.org>
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Mark Butler <mbutler@physics.otago.ac.nz>
 *
 * @date 14 January 2014
 *
 * For the STM32F1xx, accessing FLASH memory is described briefly in
 * section 3.3.3 of the STM32F10x Reference Manual.
 * For detailed programming information see:
 * PM0075 programming manual: STM32F10xxx Flash programming
 * August 2010, Doc ID 17863 Rev 1
 * https://github.com/libopencm3/libopencm3-archive/blob/master/st_micro/CD00283419.pdf
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
 * For the large memory XL series, with two banks of FLASH, the upper bank is
 * accessed with a second set of registers. In principle both banks can be
 * written simultaneously, or one read while the other is written. This module
 * does not support the simultaneous write feature.
 *
 * LGPL License Terms @ref lgpl_license
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

#include <libopencm3/stm32/desig.h>
#include <libopencm3/stm32/flash.h>

/*---------------------------------------------------------------------------*/
/** @brief Enable the FLASH Half Cycle Mode

This mode is used for power saving during read access. It is disabled by default
on reset.

Note carefully the clock restrictions under which the half cycle mode may be
enabled or disabled. This mode may only be used while the clock is running at
8MHz. See the reference manual for details.
*/

void flash_halfcycle_enable(void)
{
	FLASH_ACR |= FLASH_ACR_HLFCYA;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable the FLASH Half Cycle Mode

*/

void flash_halfcycle_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_HLFCYA;
}

/*---------------------------------------------------------------------------*/
/** @brief Unlock the Flash Program and Erase Controller, upper Bank

This enables write access to the upper bank of the Flash memory in XL devices.
It is locked by default on reset.
*/

void flash_unlock_upper(void)
{
	if (DESIG_FLASH_SIZE > 512) {

		/* Clear the unlock state. */
		FLASH_CR2 |= FLASH_CR_LOCK;

		/* Authorize the FPEC access. */
		FLASH_KEYR2 = FLASH_KEYR_KEY1;
		FLASH_KEYR2 = FLASH_KEYR_KEY2;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Lock the Flash Program and Erase Controller, upper Bank

Used to prevent spurious writes to FLASH.
*/

void flash_lock_upper(void)
{
	FLASH_CR2 |= FLASH_CR_LOCK;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Programming Error Status Flag, upper Bank

*/

void flash_clear_pgerr_flag_upper(void)
{
	if (DESIG_FLASH_SIZE > 512) {
		FLASH_SR2 |= FLASH_SR_PGERR;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the End of Operation Status Flag, upper Bank

*/

void flash_clear_eop_flag_upper(void)
{
	if (DESIG_FLASH_SIZE > 512) {
		FLASH_SR2 |= FLASH_SR_EOP;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Write Protect Error Status Flag, upper Bank

*/

void flash_clear_wrprterr_flag_upper(void)
{
	if (DESIG_FLASH_SIZE > 512) {
		FLASH_SR2 |= FLASH_SR_WRPRTERR;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Clear All Status Flags

Program error, end of operation, write protect error, busy. Both banks cleared.
*/

void flash_clear_status_flags(void)
{
	flash_clear_pgerr_flag();
	flash_clear_eop_flag();
	flash_clear_wrprterr_flag();
	if (DESIG_FLASH_SIZE > 512) {
		flash_clear_pgerr_flag_upper();
		flash_clear_eop_flag_upper();
		flash_clear_wrprterr_flag_upper();
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Read All Status Flags

The programming error, end of operation, write protect error and busy flags
are returned in the order of appearance in the status register.

Flags for the upper bank, where appropriate, are combined with those for
the lower bank using bitwise OR, without distinction.

@returns uint32_t. bit 0: busy, bit 2: programming error, bit 4: write protect
error, bit 5: end of operation.
*/

uint32_t flash_get_status_flags(void)
{
	uint32_t flags = (FLASH_SR & (FLASH_SR_PGERR |
			FLASH_SR_EOP |
			FLASH_SR_WRPRTERR |
			FLASH_SR_BSY));
	if (DESIG_FLASH_SIZE > 512) {
		flags |= (FLASH_SR2 & (FLASH_SR_PGERR |
			FLASH_SR_EOP |
			FLASH_SR_WRPRTERR |
			FLASH_SR_BSY));
	}

	return flags;
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

	if ((DESIG_FLASH_SIZE > 512) && (address >= FLASH_BASE+0x00080000)) {
		FLASH_CR2 |= FLASH_CR_PG;
	} else {
		FLASH_CR |= FLASH_CR_PG;
	}

	MMIO16(address) = data;

	flash_wait_for_last_operation();

	if ((DESIG_FLASH_SIZE > 512) && (address >= FLASH_BASE+0x00080000)) {
		FLASH_CR2 &= ~FLASH_CR_PG;
	} else {
		FLASH_CR &= ~FLASH_CR_PG;
	}
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

	if ((DESIG_FLASH_SIZE > 512)
	    && (page_address >= FLASH_BASE+0x00080000)) {
		FLASH_CR2 |= FLASH_CR_PER;
		FLASH_AR2 = page_address;
		FLASH_CR2 |= FLASH_CR_STRT;
	} else  {
		FLASH_CR |= FLASH_CR_PER;
		FLASH_AR = page_address;
		FLASH_CR |= FLASH_CR_STRT;
	}

	flash_wait_for_last_operation();

	if ((DESIG_FLASH_SIZE > 512)
	    && (page_address >= FLASH_BASE+0x00080000)) {
		FLASH_CR2 &= ~FLASH_CR_PER;
	} else {
		FLASH_CR &= ~FLASH_CR_PER;
	}
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

/* Repeat for bank 2 */
	FLASH_CR2 |= FLASH_CR_MER;
	FLASH_CR2 |= FLASH_CR_STRT;

	flash_wait_for_last_operation();
	FLASH_CR2 &= ~FLASH_CR_MER;
}

/**@}*/

