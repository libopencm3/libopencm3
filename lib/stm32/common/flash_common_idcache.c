/** @addtogroup flash_file
 *
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
#include <libopencm3/stm32/common/flash_common_idcache.h>

void flash_dcache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_DCEN;
}

void flash_dcache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_DCEN;
}

void flash_icache_enable(void)
{
	FLASH_ACR |= FLASH_ACR_ICEN;
}

void flash_icache_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_ICEN;
}


void flash_dcache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_DCRST;
}

void flash_icache_reset(void)
{
	FLASH_ACR |= FLASH_ACR_ICRST;
}

/**@}*/

