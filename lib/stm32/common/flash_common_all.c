/** @addtogroup flash_file FLASH peripheral API
 * @ingroup peripheral_apis
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

void flash_prefetch_enable(void)
{
	FLASH_ACR |= FLASH_ACR_PRFTEN;
}

void flash_prefetch_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_PRFTEN;
}

void flash_set_ws(uint32_t ws)
{
	uint32_t reg32;

	reg32 = FLASH_ACR;
	reg32 &= ~(FLASH_ACR_LATENCY_MASK << FLASH_ACR_LATENCY_SHIFT);
	reg32 |= (ws << FLASH_ACR_LATENCY_SHIFT);
	FLASH_ACR = reg32;
}

void flash_unlock_option_bytes(void)
{
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY1;
	FLASH_OPTKEYR = FLASH_OPTKEYR_KEY2;
}

/**@}*/
