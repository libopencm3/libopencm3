/** @defgroup pwr_file Power/Sleep API
 * @brief SWM050 Power API.
 * @ingroup peripheral_apis
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
#include <libopencm3/swm050/sysctl.h>
#include <libopencm3/swm050/pwr.h>

/*---------------------------------------------------------------------------*/
/** @brief Go into sleep mode

Goes to sleep and wakes up on when GPIO pin 9 is pulled low.  Please give
yourself enough time to connect the debugger before calling this, in order to
not get locked out of the MCU.

*/
void pwr_sleep(void)
{
	SYSCTL_SYS_CFG_2 |= SYSCTL_SYS_CFG_2_SLEEP;
}
/**@}*/
