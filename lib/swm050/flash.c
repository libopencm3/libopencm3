/** @defgroup flash_file Flash peripheral API
 * @ingroup peripheral_apis
 * @brief SWM050 Flash API.
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Caleb Szalacinski <contact@skiboy.net>
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Caleb Szalacinski <contact@skiboy.net>
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
#include <libopencm3/swm050/flash.h>

/* Internal function pointers to the ROM flash API */
#define IAP_WR	(void *)(0x1000AB)
#define IAP_E	(void *)(0x100127)

uint32_t (*iap_write_read)(uint32_t *, uint32_t *, uint8_t, uint8_t) = IAP_WR;
uint32_t (*iap_erase)(void) = IAP_E;

/*---------------------------------------------------------------------------*/
/** @brief Write to the user flash

Writes words to the 0.5k user flash area.
Must be performed only when the system clock is 18Mhz.

@param[in] dest Destination address
	The memory area to copy to.
	From 0x00 - 0x1FC, as long as it is word-aligned

@param[in] src Source address
	The memory area to copy from.

@param[in] cnt Number of words to write
	From 1-128 as long as (dest + (cnt * 4)) < 0x200

@return 1 if successful, 0 if error

*/
uint32_t flash_write(uint32_t *dest, uint32_t *src, uint8_t cnt)
{
	return iap_write_read(dest, src, cnt, 1);
}

/*---------------------------------------------------------------------------*/
/** @brief Read from the user flash

Reads words from the 0.5k user flash area.
Must be performed only when the system clock is 18Mhz.

@param[in] src Source address
	The memory area to copy from.
	From 0x00 - 0x1FC, as long as it is word-aligned

@param[out] dest Destination address
	The memory area to copy to.

@param[in] cnt Number of words to read
	From 1 - 128 as long as (src + (cnt * 4)) < 0x200

@return 1 if successful, 0 if error

*/
uint32_t flash_read(uint32_t *src, uint32_t *dest, uint8_t cnt)
{
	return iap_write_read(src, dest, cnt, 0);
}

/*---------------------------------------------------------------------------*/
/** @brief Erase the user flash

Erases the entire 0.5k user flash area.
Must be performed only when the system clock is 18Mhz.

@return 1 if successful, 0 if error

*/
uint32_t flash_erase(void)
{
	return iap_erase();
}
/**@}*/
