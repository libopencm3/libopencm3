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

void desig_get_unique_id_as_string(char *string, unsigned int string_len)
{
	int i, len;
	uint32_t uid_buf[3];
	uint8_t *uid = (uint8_t *)uid_buf;
	const char chars[] = "0123456789ABCDEF";

	desig_get_unique_id(uid_buf);

	/* Each byte produces two characters */
	len = (2 * sizeof(uid_buf) < string_len) ?
		2 * sizeof(uid_buf) : string_len - 1;

	for (i = 0; i < len; i += 2) {
		string[i]     = chars[(uid[i / 2] >> 4) & 0x0F];
		string[i + 1] = chars[(uid[i / 2] >> 0) & 0x0F];
	}

	string[len] = '\0';
}

void desig_get_unique_id_as_dfu(char *string) {
	uint32_t uid_buf[3];
	uint8_t *uid = (uint8_t *)uid_buf;

	desig_get_unique_id(uid_buf);

	uint8_t serial[6];
	serial[0] = uid[11];
	serial[1] = uid[10] + uid[2];
	serial[2] = uid[9];
	serial[3] = uid[8] + uid[0];
	serial[4] = uid[7];
	serial[5] = uid[6];

	uint8_t *ser = &serial[0];
	uint8_t *end = &serial[6];
	const char hex_digit[] = "0123456789ABCDEF";

	for (; ser < end; ser++) {
		*string++ = hex_digit[(*ser >> 4) & 0x0f];
		*string++ = hex_digit[(*ser >> 0) & 0x0f];
	}
	*string = '\0';
}
