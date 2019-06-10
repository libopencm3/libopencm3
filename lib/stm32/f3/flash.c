/** @defgroup flash_file FLASH peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32F3xx FLASH</b>
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
 * This library supports the FLASH memory controller in the STM32F3
 * series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * For the STM32F3xx, accessing FLASH memory is described in
 * section 3 of the STM32F3xx Reference Manual.
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

void flash_wait_for_last_operation(void)
{
	while ((FLASH_SR & FLASH_SR_BSY) == FLASH_SR_BSY);
}

void flash_clear_pgerr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGERR;
}

void flash_clear_wrprterr_flag(void)
{
	FLASH_SR |= FLASH_SR_WRPRTERR;
}

/*---------------------------------------------------------------------------*/

/** @brief Clear All Status Flags

Clears program error, end of operation, busy flags.
 */

void flash_clear_status_flags(void)
{
	flash_clear_pgerr_flag();
	flash_clear_wrprterr_flag();
	flash_clear_eop_flag();
}

void flash_program_half_word(uint32_t address, uint16_t data)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_PG;

	MMIO16(address) = data;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PG;
}

void flash_erase_page(uint32_t page_address)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_PER;
	FLASH_AR = page_address;
	FLASH_CR |= FLASH_CR_STRT;

	flash_wait_for_last_operation();

	FLASH_CR &= ~FLASH_CR_PER;
}

void flash_erase_all_pages(void)
{
	flash_wait_for_last_operation();

	FLASH_CR |= FLASH_CR_MER;
	FLASH_CR |= FLASH_CR_STRT;

	flash_wait_for_last_operation();
	FLASH_CR &= ~FLASH_CR_MER;
}


/**@}*/

