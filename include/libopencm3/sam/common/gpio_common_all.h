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

#ifndef LIBOPENCM3_GPIO_COMMON_ALL_H
#define LIBOPENCM3_GPIO_COMMON_ALL_H

#include <libopencm3/cm3/common.h>

void gpio_set(uint32_t gpioport, uint32_t gpios);
void gpio_clear(uint32_t gpioport, uint32_t gpios);
void gpio_toggle(uint32_t gpioport, uint32_t gpios);


#endif

#else
#warning "gpio_common_all.h should not be included explicitly, only via gpio.h"
#endif
