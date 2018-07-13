/** @addtogroup flash_file
 *
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
/** @brief Set the Number of Wait States

Used to match the system clock to the FLASH memory access time. See the
programming manual for more information on clock speed ranges. The latency must
be changed to the appropriate value <b>before</b> any increase in clock
speed, or <b>after</b> any decrease in clock speed.

@param[in] ws values from @ref flash_latency.
*/
void flash_set_ws(uint32_t ws)
{
	uint32_t reg32;
	reg32 = FLASH_ACR & ~(FLASH_ACR_LATENCY_MASK);
	reg32 |= ws & FLASH_ACR_LATENCY_MASK;
	FLASH_ACR = reg32;
}


/*---------------------------------------------------------------------------*/
/** @brief Clear the Programming Error Status Flag

*/

void flash_clear_pgperr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGPERR;
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
/**@}*/
