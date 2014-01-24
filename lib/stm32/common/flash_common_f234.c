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

@param[in] uint32_t ws: values from @ref flash_latency.
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
	/* Clear the unlock sequence state. */
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

void flash_clear_pgperr_flag(void)
{
	FLASH_SR |= FLASH_SR_PGPERR;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the End of Operation Status Flag

*/

void flash_clear_eop_flag(void)
{
	FLASH_SR |= FLASH_SR_EOP;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear the Busy Status Flag

*/

void flash_clear_bsy_flag(void)
{
	FLASH_SR &= ~FLASH_SR_BSY;
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

