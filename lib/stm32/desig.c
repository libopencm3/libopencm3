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
	uint8_t *device_id = (uint8_t *)dev_id_buf;
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

/**
 * Generate a serial number from the unique id registers as the DFU bootloader.
 * This document: http://www.usb.org/developers/docs/devclass_docs/usbmassbulk_10.pdf
 * says that the serial number has to be at least 12 digits long and that
 * the last 12 digits need to be unique. It also stipulates that the valid
 * character set is that of upper-case hexadecimal digits.
 * The onboard DFU bootloader produces a 12-digit serial based on the
 * 96-bit unique ID. Show the serial with ```dfu-util -l``` while the
 * MCU is in DFU mode.
 * @see https://my.st.com/52d187b7 for the algorithim used.
 * @param string pointer to store serial in, must be at least 13 bytes
 */
void desig_get_unique_id_as_dfu(char *string) {
	uint8_t *id = (uint8_t *)DESIG_UNIQUE_ID_BASE;

	uint8_t serial[6];
	serial[0] = id[11];
	serial[1] = id[10] + id[2];
	serial[2] = id[9];
	serial[3] = id[8] + id[0];
	serial[4] = id[7];
	serial[5] = id[6];

	uint8_t *ser = &serial[0];
	uint8_t *end = &serial[6];
	const char hex_digit[] = "0123456789ABCDEF";

	for (; ser < end; ser++) {
		*string++ = hex_digit[(*ser >> 4) & 0x0f];
		*string++ = hex_digit[(*ser >> 0) & 0x0f];
	}
	*string = '\0';
}
