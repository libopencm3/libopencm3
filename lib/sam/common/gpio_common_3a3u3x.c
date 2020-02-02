/** @addtogroup gpio_defines
 *
 * @brief <b>Access functions for the SAM3A/U/X I/O Controller</b>
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


/** @brief Initialize GPIO pins
 *
 * @param[in] port uint32_t: GPIO Port base address
 * @param[in] pins uint32_t bitfield of pins to initialize
 * @param[in] flags enum gpio_flags
 */
void gpio_init(uint32_t port, uint32_t pins, enum gpio_flags flags)
{
	switch (flags & 0x7) {
	case GPIO_FLAG_GPINPUT:
		PIO_ODR(port) = pins;
		PIO_PER(port) = pins;
		break;
	case GPIO_FLAG_GPOUTPUT:
		PIO_OER(port) = pins;
		PIO_PER(port) = pins;
		break;
	case GPIO_FLAG_PERIPHA:
		PIO_ABSR(port) &= ~pins;
		PIO_PDR(port) = pins;
		break;
	case GPIO_FLAG_PERIPHB:
		PIO_ABSR(port) |= pins;
		PIO_PDR(port) = pins;
	}

	if (flags & GPIO_FLAG_OPEN_DRAIN) {
		PIO_MDER(port) = pins;
	} else {
		PIO_MDDR(port) = pins;
	}

	if (flags & GPIO_FLAG_PULL_UP) {
		PIO_PUER(port) = pins;
	} else {
		PIO_PUDR(port) = pins;
	}
}
