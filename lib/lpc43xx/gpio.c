/** @defgroup gpio_file GPIO

@ingroup LPC43xx

@brief <b>libopencm3 LPC43xx General Purpose I/O</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopencm3/lpc43xx/gpio.h>

void gpio_set(uint32_t gpioport, uint32_t gpios)
{
	GPIO_SET(gpioport) = gpios;
}

void gpio_clear(uint32_t gpioport, uint32_t gpios)
{
	GPIO_CLR(gpioport) = gpios;
}

void gpio_toggle(uint32_t gpioport, uint32_t gpios)
{
	GPIO_NOT(gpioport) = gpios;
}

/**@}*/

