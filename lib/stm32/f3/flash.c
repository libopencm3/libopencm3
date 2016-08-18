/** @defgroup flash_file FLASH
 *
 * @ingroup STM32F3xx
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

/*---------------------------------------------------------------------------*/
/** @brief Clear All Status Flags

Clears program error, end of operation, busy flags.
*/

void flash_clear_status_flags(void)
{
	flash_clear_pgperr_flag();
	flash_clear_eop_flag();
	flash_clear_bsy_flag();
}
/**@}*/

