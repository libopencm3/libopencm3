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

void desig_get_unique_id(uint32_t *result)
{
	*result++ = DESIG_UNIQUE_ID2;
	*result++ = DESIG_UNIQUE_ID1;
	*result = DESIG_UNIQUE_ID0;
}

void desig_get_unique_id_as_string(char *string,
				   unsigned int string_len)
{
	int i, len;
	uint32_t dev_id_buf[3];
	uint8_t *device_id = (uint8_t*)dev_id_buf;
	const char chars[] = "0123456789ABCDEF";

	desig_get_unique_id(dev_id_buf);

	/* Each byte produces two characters */
	len = (2 * sizeof(dev_id_buf) < string_len) ?
		2 * sizeof(dev_id_buf) : string_len - 1;

	for (i = 0; i < len; i += 2) {
		string[i]     = chars[(device_id[i / 2] >> 4) & 0x0F];
		string[i + 1] = chars[(device_id[i / 2] >> 0) & 0x0F];
	}

	string[len] = '\0';
}

