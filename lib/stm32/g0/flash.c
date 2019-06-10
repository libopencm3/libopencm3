/** @defgroup flash_file FLASH peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32G0xx FLASH</b>
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

void flash_icache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_ICEN;
}

void flash_icache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_ICEN;
}

void flash_icache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_ICRST;
}

void flash_unlock_progmem(void)
{
	FLASH_KEYR = FLASH_KEYR_KEY1;
	FLASH_KEYR = FLASH_KEYR_KEY2;
}

void flash_lock_progmem(void)
{
	FLASH_CR |= FLASH_CR_LOCK;
}

void flash_lock_option_bytes(void)
{
	FLASH_CR |= FLASH_CR_OPTLOCK;
}

void flash_unlock(void)
{
	flash_unlock_progmem();
	flash_unlock_option_bytes();
}

void flash_lock(void)
{
	flash_lock_option_bytes();
	flash_lock_progmem();
}

/**@}*/