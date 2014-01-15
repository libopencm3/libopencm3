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
/** @brief Set the Number of Wait States

Used to match the system clock to the FLASH memory access time. See the
reference manual for more information on clock speed ranges for each wait state.
The latency must be changed to the appropriate value <b>before</b> any increase
in clock speed, or <b>after</b> any decrease in clock speed.

@param[in] uint32_t ws: values 0 or 1 only.
*/

void flash_set_ws(uint32_t ws)
{
	FLASH_ACR = (FLASH_ACR & ~FLASH_ACR_LATENCY) | ws;
}

/*---------------------------------------------------------------------------*/
/** @brief Wait for Busy Flag

This loops indefinitely until the busy flag is clear.
*/

void flash_wait_busy(void)
{
	while ((FLASH_SR & FLASH_SR_BSY) != 0);
}

/*---------------------------------------------------------------------------*/
/** @brief Program a 32 bit Word to FLASH

This performs all operations necessary to program a 32 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

@param[in] uint32_t address. Full address of flash word to be programmed.
@param[in] uint32_t data.
*/

void flash_program_u32(uint32_t address, uint32_t data)
{
	flash_wait_busy();

	FLASH_CR |= FLASH_CR_PG;

	MMIO16(address) = (uint16_t)data;

	flash_wait_busy();

	MMIO16(address + 2) = data >> 16;

	flash_wait_busy();

	FLASH_CR &= ~FLASH_CR_PG;
}

/*---------------------------------------------------------------------------*/
/** @brief Program a Half Word to FLASH

This performs all operations necessary to program a 16 bit word to FLASH memory.
The program error flag should be checked separately for the event that memory
was not properly erased.

@param[in] uint32_t address Full address of flash half word to be programmed.
@param[in] uint16_t data.
*/

void flash_program_u16(uint32_t address, uint16_t data)
{
	flash_wait_busy();

	FLASH_CR |= FLASH_CR_PG;

	MMIO16(address) = data;

	flash_wait_busy();

	FLASH_CR &= ~FLASH_CR_PG;
}

/*---------------------------------------------------------------------------*/
/** @brief Erase a Page of FLASH

This performs all operations necessary to erase a page in FLASH memory.
The page should be checked to ensure that it was properly erased. A page must
first be fully erased before attempting to program it.

Note that the page sizes differ between devices. See the reference manual or
the FLASH programming manual for details.

@param[in] uint32_t page_address. Full address of flash page to be erased.
*/

void flash_erase_page(uint32_t page_address)
{
	flash_wait_busy();

	FLASH_CR |= FLASH_CR_PER;
	FLASH_AR = page_address;
	FLASH_CR |= FLASH_CR_STRT;

	flash_wait_busy();
	FLASH_CR &= ~FLASH_CR_PER;
}

/*---------------------------------------------------------------------------*/
/** @brief Erase All FLASH

This performs all operations necessary to erase all user pages in the FLASH
memory. The information block is unaffected.
*/

void flash_erase_all_pages(void)
{
	flash_wait_busy();

	FLASH_CR |= FLASH_CR_MER;		/* Enable mass erase. */
	FLASH_CR |= FLASH_CR_STRT;		/* Trigger the erase. */

	flash_wait_busy();
	FLASH_CR &= ~FLASH_CR_MER;		/* Disable mass erase. */
}
/**@}*/

