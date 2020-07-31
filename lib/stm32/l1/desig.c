/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/dbgmcu.h>
#include <libopencm3/stm32/desig.h>

uint16_t desig_get_flash_size(void)
{
	uint32_t device_id = DBGMCU_IDCODE & DBGMCU_IDCODE_DEV_ID_MASK;
	switch (device_id) {
	case 0x416:
	case 0x429:
		return *(uint32_t*)DESIG_FLASH_SIZE_BASE_CAT12;
	case 0x427:
	case 0x436:
	case 0x437:
		return *(uint32_t*)DESIG_FLASH_SIZE_BASE_CAT3456;
	}

	cm3_assert_not_reached();
}

void desig_get_unique_id(uint32_t *result)
{
	uint32_t device_id = DBGMCU_IDCODE & DBGMCU_IDCODE_DEV_ID_MASK;
	uint32_t* uid_base = 0;
	switch (device_id) {
	case 0x416:
	case 0x429:
		uid_base = (uint32_t*)DESIG_UNIQUE_ID_BASE_CAT12;
		break;
	case 0x427:
	case 0x436:
	case 0x437:
		uid_base = (uint32_t*)DESIG_UNIQUE_ID_BASE_CAT3456;
		break;
	}

	if (!uid_base) {
		/* We don't know the address for this device. Hang here to help debugging. */
		cm3_assert_not_reached();
	}

	/* yes, careful with offsets here */
	result[0] = uid_base[5];
	result[1] = uid_base[1];
	result[2] = uid_base[0];
}
