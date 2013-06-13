/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Karl Palsson <karlp@ŧweak.net.au>
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

#include <libopencm3/stm32/desig.h>

uint16_t desig_get_flash_size(void)
{
	return DESIG_FLASH_SIZE;
}

void desig_get_unique_id(uint32_t result[])
{
	/* Could also just return a pointer to the start? read it as they wish?
	 */
	uint16_t bits15_0 = DESIG_UID_15_0;
	uint32_t bits31_16 = DESIG_UID_31_16;
	uint32_t bits63_32 = DESIG_UID_63_32;
	uint32_t bits95_64 = DESIG_UID_95_64;
	result[0] = bits95_64;
	result[1] = bits63_32;
	result[2] = bits31_16 << 16 | bits15_0;
}

void desig_get_unique_id_as_string(char *string,
				   unsigned int string_len)
{
	int i, len;
	uint8_t device_id[12];
	static const char chars[] = "0123456789ABCDEF";

	desig_get_unique_id((uint32_t *)device_id);

	/* Each byte produces two characters */
	len = (2 * sizeof(device_id) < string_len) ?
		2 * sizeof(device_id) : string_len - 1;

	for (i = 0; i < len; i += 2) {
		string[i]     = chars[(device_id[i / 2] >> 0) & 0x0F];
		string[i + 1] = chars[(device_id[i / 2] >> 4) & 0x0F];
	}

	string[len] = '\0';
}

