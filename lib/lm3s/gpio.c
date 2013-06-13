/** @defgroup gpio_file General Purpose I/O

@brief <b>LM3S General Purpose I/O</b>

@ingroup LM3Sxx

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2011
Gareth McMullin <gareth@blacksphere.co.nz>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <libopencm3/lm3s/gpio.h>

void gpio_set(uint32_t gpioport, uint8_t gpios)
{
	/* ipaddr[9:2] mask the bits to be set, hence the array index */
	GPIO_DATA(gpioport)[gpios] = 0xff;
}

void gpio_clear(uint32_t gpioport, uint8_t gpios)
{
	GPIO_DATA(gpioport)[gpios] = 0;
}

/**@}*/

