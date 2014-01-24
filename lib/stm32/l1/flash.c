/** @defgroup flash_file FLASH
 *
 * @ingroup STM32L1xx
 *
 * @brief <b>libopencm3 STM32L1xx FLASH</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Thomas Otto <tommi@viadmin.org>
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Mark Butler <mbutler@physics.otago.ac.nz>
 * @author @htmlonly &copy; @endhtmlonly 2012
 * Karl Palsson <karlp@tweak.net.au>
 *
 * @date 14 January 2014
 *
 * For the STM32L1xx, accessing FLASH memory is described briefly in
 * section 2.3.3 of the STM32L1xx Reference Manual.
 * For detailed programming information see:
 * PM0062 programming manual: STM32L1xxxx Flash and EEPROM programming
 * March 2012, Doc ID 16024 Rev 5
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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

/*---------------------------------------------------------------------------*/
/** @brief Enable 64 Bit Programming Mode

*/

void flash_64bit_enable(void)
{
	FLASH_ACR |= FLASH_ACR_ACC64;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable 32 Bit Programming Mode

This mode is a low power mode. It must be used at low frequencies and does not
allow prefetch or wait states to be used.
*/

void flash_64bit_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_ACC64;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the FLASH Prefetch Buffer

This buffer is used for instruction fetches and is enabled by default after
reset.

Note carefully the restrictions under which the prefetch buffer may be
enabled or disabled. Prefetch is only available when 64-bit
access is enabled.
*/

void flash_prefetch_enable(void)
{
	FLASH_ACR |= FLASH_ACR_PRFTEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable the FLASH Prefetch Buffer

Note carefully the restrictions under which the prefetch buffer may be
set to disabled. See the reference and programming manuals for details.
*/

void flash_prefetch_disable(void)
{
	FLASH_ACR &= ~FLASH_ACR_PRFTEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Number of Wait States

Used to match the system clock to the FLASH memory access time. See the
programming manual for more information on clock speed and voltage ranges. The
latency must be changed to the appropriate value <b>before</b> any increase in
clock speed, or <b>after</b> any decrease in clock speed. A latency setting of
zero only applies if 64-bit mode is not used.

@param[in] uint32_t ws: values from @ref flash_latency.
*/

void flash_set_ws(uint32_t ws)
{
	uint32_t reg32;

	reg32 = FLASH_ACR;
	reg32 &= ~(1 << 0);
	reg32 |= ws;
	FLASH_ACR = reg32;
}
/**@}*/

