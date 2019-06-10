/** @defgroup flash_file FLASH peripheral API
 *
 * @ingroup peripheral_apis
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017 Matthew Lai @m@matthewlai.ca>
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
/** @brief Issue Pipeline Stall

Issue a pipeline stall to make sure all write operations completed.

RM0385: After performing a data write operation and before polling the BSY bit
to be cleared, the software can issue a DSB instruction to guarantee the 
completion of a previous data write operation.

*/

static inline void flash_pipeline_stall(void)
{
	__asm__ volatile("dsb":::"memory");
}

/*---------------------------------------------------------------------------*/
/** @brief Wait until Last Operation has Ended

This loops indefinitely until an operation (write or erase) has completed by
testing the busy flag.
*/
void flash_wait_for_last_operation(void)
{
	flash_pipeline_stall();
	while ((FLASH_SR & FLASH_SR_BSY) == FLASH_SR_BSY);
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Erase Sequence Error Flag

This flag is set when an erase operation is performed with control register has
not been correctly set.
*/
void flash_clear_erserr_flag(void)
{
	FLASH_SR |= FLASH_SR_ERSERR;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear All Status Flags

Program error, end of operation, write protect error.
*/

void flash_clear_status_flags(void)
{
	flash_clear_erserr_flag();
	flash_clear_pgaerr_flag();
	flash_clear_wrperr_flag();
	flash_clear_pgperr_flag();
	flash_clear_eop_flag();
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the ART Cache

*/

void flash_art_enable(void)
{
	FLASH_ACR |= FLASH_ACR_ARTEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Reset the ART Cache

The ART cache must be disabled for this to have effect.
*/

void flash_art_reset(void)
{
	FLASH_ACR |= FLASH_ACR_ARTRST;
}

/**@}*/
