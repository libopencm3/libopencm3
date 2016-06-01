/** @defgroup flash_file FLASH
 *
 * @ingroup STM32L0xx
 *
 * @brief <b>libopencm3 STM32L0xx FLASH</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Thomas Otto <tommi@viadmin.org>
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Mark Butler <mbutler@physics.otago.ac.nz>
 * @author @htmlonly &copy; @endhtmlonly 2012
 * Karl Palsson <karlp@tweak.net.au>
 *
 * @date 24 May 2016
 *
 * For the STM32L0xx, accessing FLASH memory is described briefly in
 * section 3.3.4 of the STM32L0xx Reference Manual.
 * For detailed programming information see:
 * PM0062 programming manual: STM32L1xxxx Flash and EEPROM programming
 * March 2012, Doc ID 16024 Rev 5 (applies to L1 though)
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
 * Copyright (C) 2012-13 Karl Palsson <karlp@tweak.net.au>
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
/** @brief Program a (32bit) Word to FLASH

This performs all operations necessary to program a 32 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

Status bit polling is used to detect end of operation.

@param[in] address Full address of flash word to be programmed.
@param[in] data word to write
*/

void flash_program_word(uint32_t address, uint32_t data)
{
	while (FLASH_SR & FLASH_SR_BSY);

	MMIO32(address) = data;

	while (FLASH_SR & FLASH_SR_BSY);

	if ((FLASH_SR & FLASH_SR_EOP) != 0) {
		FLASH_SR = FLASH_SR_EOP;
	} /* else error */
}

/*---------------------------------------------------------------------------*/
/** @brief Program half a page to FLASH

This performs all operations necessary to program half a page of words to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

Status bit polling is used to detect end of operation.

Note that the page sizes differ between devices. See the reference manual or
the FLASH programming manual for details.

Warning: this function MUST be executed from RAM.

@param[in] address First address on the half page to be programmed.
@param[in] data Pointer data to write
*/

void flash_program_half_page(uint32_t address, uint32_t *data, uint16_t page_size)
{
	uint16_t i;

	FLASH_PECR |= FLASH_PECR_PROG | FLASH_PECR_FPRG;

	for (i = 0; i < page_size/2; i+=4, data++) {
		MMIO32(address + i) = *data;
	}

	while (FLASH_SR & FLASH_SR_BSY);

	if ((FLASH_SR & FLASH_SR_EOP) != 0) {
		FLASH_SR = FLASH_SR_EOP;
	} /* else error */

	FLASH_PECR &= ~(FLASH_PECR_PROG | FLASH_PECR_FPRG);
}

/*---------------------------------------------------------------------------*/
/** @brief Erase a Page of FLASH

This performs all operations necessary to erase a page in FLASH memory.
The page should be checked to ensure that it was properly erased. A page must
first be fully erased before attempting to program it.

Note that the page sizes differ between devices. See the reference manual or
the FLASH programming manual for details.

@param[in] address Memory address of the first word on the page to be erased.
*/

void flash_erase_page(uint32_t address)
{
	while (FLASH_SR & FLASH_SR_BSY);

	FLASH_PECR |= FLASH_PECR_ERASE | FLASH_PECR_PROG;

	MMIO32(address) = (uint32_t)0;

	while (FLASH_SR & FLASH_SR_BSY);

	if ((FLASH_SR & FLASH_SR_EOP) != 0) {
		FLASH_SR = FLASH_SR_EOP;
	} /* else error */

	FLASH_PECR &= ~(FLASH_PECR_ERASE | FLASH_PECR_PROG);
}

/*---------------------------------------------------------------------------*/
/** @brief Erase All FLASH

This performs all operations necessary to erase all user pages in the FLASH
memory. The information block is unaffected.

Warning: this function MUST be executed from RAM.
*/

void flash_erase_all_pages(void)
{

	/* (1) Check if the read protection is not level 2 */
	if ((FLASH_OPTR & 0x000000FF) == FLASH_OPTR_RDPRT_LEVEL_2) {
	    /* Error and abort */
		return;
	/* (2) Check if the read protection is not level 1 */
	} else if ((FLASH_OPTR & 0x000000FF) == FLASH_OPTR_RDPRT_LEVEL_0) {
		/* (3) Erase the Option byte containing the read protection */
		flash_erase_option_byte(INFO_BASE);
		/* (4) Reload the Option bytes */
		FLASH_PECR |= FLASH_PECR_OBL_LAUNCH;
		/* The MCU will reset while executing the option bytes reloading */
	}

	/* (5) Program read protection to level 1 by writing 0xAA to start the mass erase */
	flash_program_option_byte(INFO_BASE, 0x00AA);

	/* Should check that the memory was erased here */

	/* (6) Lock the NVM by setting the PELOCK bit */
	flash_lock_pecr();

	/* Infinite loop */
	while (1);
}

/*---------------------------------------------------------------------------*/
/** @brief Erase the Option Bytes

This performs all operations necessary to erase one option byte. These must
first be fully erased before attempting to program them, therefore it is
recommended to check these after an erase attempt.

Warning: this function MUST be executed from RAM.

@param[in] address Address of option byte from @ref flash_options.
*/

void flash_erase_option_byte(uint32_t address)
{
	FLASH_PECR |= FLASH_PECR_ERASE;

	MMIO32(address) = 0;

	while (FLASH_SR & FLASH_SR_BSY);

	if ((FLASH_SR & FLASH_SR_EOP) != 0) {
		FLASH_SR = FLASH_SR_EOP;
	} /* else error */

	FLASH_PECR &= ~(FLASH_PECR_ERASE);
}

/*---------------------------------------------------------------------------*/
/** @brief Program the Option Bytes

This performs all operations necessary to program the option bytes.
The write protect error flag should be checked separately for the event that
an option byte had not been properly erased before calling this function.

Only the lower 8 bits of the data is significant.

Warning: this function MUST be executed from RAM.

@param[in] address Address of option byte from @ref flash_options.
@param[in] data value to write
*/

void flash_program_option_byte(uint32_t address, uint16_t data)
{
	MMIO32(address) = (uint32_t)((~data << 16) | data);

	while (FLASH_SR & FLASH_SR_BSY);

	if ((FLASH_SR & FLASH_SR_EOP) != 0) {
		FLASH_SR = FLASH_SR_EOP;
	} /* else error */
}

/**@}*/
