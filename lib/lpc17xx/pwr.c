/** @defgroup pwr-file PWR

@ingroup LPC17xx

@brief <b>libopencm3 LPC17xx Power Control</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2013 Silvio Gissi <silvio.gissi@outlook.com>

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Silvio Gissi <silvio.gissi@outlook.com>
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

#include <libopencm3/lpc17xx/pwr.h>

void pwr_enable_peripherals(uint32_t peripherals)
{
	PWR_PCONP |= peripherals;
}

void pwr_disable_peripherals(uint32_t peripherals)
{
	PWR_PCONP &= ~peripherals;
}

/**@}*/

