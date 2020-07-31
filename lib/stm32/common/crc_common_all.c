/** @addtogroup crc_file CRC peripheral API
@ingroup peripheral_apis

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

void crc_reset(void)
{
	CRC_CR |= CRC_CR_RESET;
}

uint32_t crc_calculate(uint32_t data)
{
	CRC_DR = data;
	/* Data sheet says this blocks until it's ready.... */
	return CRC_DR;
}

uint32_t crc_calculate_block(uint32_t *datap, int size)
{
	int i;

	for (i = 0; i < size; i++) {
		CRC_DR = datap[i];
	}

	return CRC_DR;
}
/**@}*/

