/** @addtogroup crc_file

@author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@remake.is>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Karl Palsson <karlp@remake.is>
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

#include <libopencm3/stm32/crc.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief CRC Reset.

Reset the CRC unit and forces the data register to all 1s.

*/

void crc_reset(void)
{
	CRC_CR |= CRC_CR_RESET;
}

/*---------------------------------------------------------------------------*/
/** @brief CRC Calculate.

Writes a data word to the register, the write operation stalling until the
computation is complete.

@param[in] data Unsigned int32.
@returns int32 Computed CRC result
*/

uint32_t crc_calculate(uint32_t data)
{
	CRC_DR = data;
	/* Data sheet says this blocks until it's ready.... */
	return CRC_DR;
}

/*---------------------------------------------------------------------------*/
/** @brief CRC Calculate of a Block of Data.

Writes data words consecutively to the register, the write operation stalling
until the computation of each word is complete.

@param[in] datap Unsigned int32. pointer to an array of 32 bit data words.
@param[in] size int. Size of the array.
@returns int32 Final computed CRC result
*/

uint32_t crc_calculate_block(uint32_t *datap, int size)
{
	int i;

	for (i = 0; i < size; i++) {
		CRC_DR = datap[i];
	}

	return CRC_DR;
}
/**@}*/

