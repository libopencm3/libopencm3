/** @defgroup flash_file FLASH peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32F2xx FLASH</b>
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
 * This library supports the FLASH memory controller in the STM32F2
 * series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * For the STM32F2xx, accessing FLASH memory is described briefly in
 * section 2.3.3 of the STM32F2xx Reference Manual.
 * For detailed programming information see:
 * PM0059 programming manual: STM32F10xxx Flash programming
 * June 2013, Doc ID DocID15687 Rev 5
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

/*---------------------------------------------------------------------------*/
/** @brief Clear the Programming Sequence Error Flag

This flag is set when incorrect programming configuration has been made.
*/

void flash_clear_pgserr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGSERR;
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
}

/**@}*/

