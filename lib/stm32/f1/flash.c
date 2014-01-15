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

#include <libopencm3/stm32/flash.h>

/*---------------------------------------------------------------------------*/
/** @brief Enable the FLASH Prefetch Buffer

This buffer is used for instruction fetches and is enabled by default after
reset.

Note carefully the clock restrictions under which the prefetch buffer may be
enabled or disabled. Changes are normally made while the clock is running in
the power-on low frequency mode before being set to a higher speed mode.
See the reference manual for details.
*/

void flash_prefetch_buffer_enable(void)
{
	FLASH_ACR |= FLASH_ACR_PRFTBE;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable the FLASH Prefetch Buffer

Note carefully the clock restrictions under which the prefetch buffer may be
set to disabled. See the reference manual for details.
*/

void flash_prefetch_buffer_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_PRFTBE;
}

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
/** @brief Set the Number of Wait States

Used to match the system clock to the FLASH memory access time. See the
reference manual for more information on clock speed ranges for each wait state.
The latency must be changed to the appropriate value <b>before</b> any increase
in clock speed, or <b>after</b> any decrease in clock speed.


@param[in] uint32_t ws: values 0, 1 or 2 only.
*/

void flash_set_ws(uint32_t ws)
{
	uint32_t reg32;

	reg32 = FLASH_ACR;
	reg32 &= ~((1 << 0) | (1 << 1) | (1 << 2));
	reg32 |= ws;
	FLASH_ACR = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief Unlock the Flash Program and Erase Controller

This enables write access to the Flash memory. It is locked by default on
reset.
*/

void flash_unlock(void)
{
	/* Clear the unlock state. */
	FLASH_CR |= FLASH_CR_LOCK;

	/* Authorize the FPEC access. */
	FLASH_KEYR = FLASH_KEYR_KEY1;
	FLASH_KEYR = FLASH_KEYR_KEY2;
}

/*---------------------------------------------------------------------------*/
/** @brief Lock the Flash Program and Erase Controller

Used to prevent spurious writes to FLASH.
*/

void flash_lock(void)
{
	FLASH_CR |= FLASH_CR_LOCK;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Programming Error Status Flag

*/

void flash_clear_pgerr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGERR;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the End of Operation Status Flag

*/

void flash_clear_eop_flag(void)
{
	FLASH_SR |= FLASH_SR_EOP;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Write Protect Error Status Flag

*/

void flash_clear_wrprterr_flag(void)
{
	FLASH_SR |= FLASH_SR_WRPRTERR;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Busy Status Flag

*/

void flash_clear_bsy_flag(void)
{
	FLASH_SR &= ~FLASH_SR_BSY;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear All Status Flags

Program error, end of operation, write protect error, busy.
*/

void flash_clear_status_flags(void)
{
	flash_clear_pgerr_flag();
	flash_clear_eop_flag();
	flash_clear_wrprterr_flag();
	flash_clear_bsy_flag();
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
	return FLASH_SR &= (FLASH_SR_PGERR |
			FLASH_SR_EOP |
			FLASH_SR_WRPRTERR |
			FLASH_SR_BSY);
}

/*---------------------------------------------------------------------------*/
/** @brief Unlock the Option Byte Access

This enables write access to the option bytes. It is locked by default on
reset.
*/

void flash_unlock_option_bytes(void)
{
	/* F1 uses same keys for flash and option */
	FLASH_OPTKEYR = FLASH_KEYR_KEY1;
	FLASH_OPTKEYR = FLASH_KEYR_KEY2;
}

/*---------------------------------------------------------------------------*/
/** @brief Wait until Last Operation has Ended

This loops indefinitely until an operation (write or erase) has completed by
testing the busy flag.
*/

void flash_wait_for_last_operation(void)
{
	while ((FLASH_SR & FLASH_SR_BSY) == FLASH_SR_BSY);
}

/*---------------------------------------------------------------------------*/
/** @brief Program a 32 bit Word to FLASH

This performs all operations necessary to program a 32 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

@param[in] uint32_t address. Full address of flash word to be programmed.
@param[in] uint32_t data.
*/

void flash_program_word(uint32_t address, uint32_t data)
{
	/* Ensure that all flash operations are complete. */
	flash_wait_for_last_operation();

	/* Enable writes to flash. */
	FLASH_CR |= FLASH_CR_PG;

	/* Program the first half of the word. */
	MMIO16(address) = (uint16_t)data;

	/* Wait for the write to complete. */
	flash_wait_for_last_operation();

	/* Enable writes to flash. */
	FLASH_CR |= FLASH_CR_PG;

	/* Program the second half of the word. */
	MMIO16(address + 2) = data >> 16;

	/* Wait for the write to complete. */
	flash_wait_for_last_operation();
}

/*---------------------------------------------------------------------------*/
/** @brief Program a Half Word to FLASH

This performs all operations necessary to program a 16 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

@param[in] uint32_t address. Full address of flash half word to be programmed.
@param[in] uint16_t data.
*/

void flash_program_half_word(uint32_t address, uint16_t data)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_PG;

	MMIO16(address) = data;

	flash_wait_for_last_operation();
}

/*---------------------------------------------------------------------------*/
/** @brief Erase a Page of FLASH

This performs all operations necessary to erase a page in FLASH memory.
The page should be checked to ensure that it was properly erased. A page must
first be fully erased before attempting to program it.

Note that the page sizes differ between devices. See the reference manual or
the FLASH programming manual for details.

@param[in] uint32_t page_address. Full address of flash psge to be erased.
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

/*---------------------------------------------------------------------------*/
/** @brief Erase All Option Bytes

This performs all operations necessary to erase the option bytes. These must
first be fully erased before attempting to program them.
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
an option byte was not properly erased.

@param[in] uint32_t address. Full address of option byte to program.
@param[in] uint16_t data.
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

