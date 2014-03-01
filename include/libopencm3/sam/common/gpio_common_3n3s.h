/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Gareth McMullin <gareth@blacksphere.co.nz>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA GPIO.H
The order of header inclusion is important. gpio.h includes the device
specific memorymap.h header before including this header file.*/

#if defined(LIBOPENCM3_GPIO_H)

#ifndef LIBOPENCM3_GPIO_COMMON_3N3S_H
#define LIBOPENCM3_GPIO_COMMON_3N3S_H

#include <libopencm3/sam/common/gpio_common_all.h>


/* flags may be or'd together, but only contain one of
 * GPOUTPUT, PERIPHA, PERIPHB, PERIPHC and PERIPHD */
enum gpio_flags {
	GPIO_FLAG_GPINPUT = 0,
	GPIO_FLAG_GPOUTPUT = 1,
	GPIO_FLAG_PERIPHA = 2,
	GPIO_FLAG_PERIPHB = 3,
	GPIO_FLAG_PERIPHC = 4,
	GPIO_FLAG_PERIPHD = 5,
	GPIO_FLAG_OPEN_DRAIN = (1 << 3),
	GPIO_FLAG_PULL_UP = (1 << 4),
};


void gpio_init(uint32_t gpioport, uint32_t pins, enum gpio_flags flags);


#endif

#else
#warning "gpio_common_3n3s.h should not be included explicitly, only via gpio.h"
#endif
