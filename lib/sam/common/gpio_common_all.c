/** @addtogroup gpio_defines
 *
 * @brief <b>Access functions for the SAM3 I/O Controller</b>
 * @ingroup SAM3_defines
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2012
 * Gareth McMullin <gareth@blacksphere.co.nz>
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Felix Held <felix-libopencm3@felixheld.de>
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2014 Felix Held <felix-libopencm3@felixheld.de>
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

#include <libopencm3/sam/gpio.h>

/** @brief Atomic set output
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_set(uint32_t gpioport, uint32_t gpios)
{
	PIO_SODR(gpioport) = gpios;
}

/** @brief Atomic clear output
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_clear(uint32_t gpioport, uint32_t gpios)
{
	PIO_CODR(gpioport) = gpios;
}

/** @brief Toggle output
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_toggle(uint32_t gpioport, uint32_t gpios)
{
	uint32_t odsr = PIO_ODSR(gpioport);
	PIO_CODR(gpioport) = odsr & gpios;
	PIO_SODR(gpioport) = ~odsr & gpios;
}

