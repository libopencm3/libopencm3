/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Matthew Lai <m@matthewlai.ca>
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
	uint32_t* flash_size_base = 0;
	switch (device_id) {
	case 0x0449:
		flash_size_base = (uint32_t*) DESIG_FLASH_SIZE_BASE_449;
		break;
	case 0x0451:
		flash_size_base = (uint32_t*) DESIG_FLASH_SIZE_BASE_451;
		break;
	case 0x0452:
		flash_size_base = (uint32_t*) DESIG_FLASH_SIZE_BASE_452;
		break;
	}

	if (!flash_size_base) {
		/* We don't know the address for this device. Hang here to help debugging. */
		cm3_assert_not_reached();
	}

	return *flash_size_base;
}

void desig_get_unique_id(uint32_t *result)
{
	uint32_t device_id = DBGMCU_IDCODE & DBGMCU_IDCODE_DEV_ID_MASK;
	uint32_t* uid_base = 0;
	switch (device_id) {
	case 0x0449:
		uid_base = (uint32_t*) DESIG_UNIQUE_ID_BASE_449;
		break;
	case 0x0451:
		uid_base = (uint32_t*) DESIG_UNIQUE_ID_BASE_451;
		break;
	case 0x0452:
		uid_base = (uint32_t*) DESIG_UNIQUE_ID_BASE_452;
		break;
	}

	if (!uid_base) {
		/* We don't know the address for this device. Hang here to help debugging. */
		cm3_assert_not_reached();
	}

	result[0] = uid_base[2];
	result[1] = uid_base[1];
	result[2] = uid_base[0];
}
