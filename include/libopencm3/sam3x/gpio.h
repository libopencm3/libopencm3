/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef SAM3X_GPIO_H
#define SAM3X_GPIO_H

#include <libopencm3/sam3x/pio.h>

static inline void gpio_set(u32 gpioport, u32 gpios)
{
	PIO_SODR(gpioport) = gpios;
}

void gpio_clear(u32 gpioport, u32 gpios)
{
	PIO_CODR(gpioport) = gpios;
}

void gpio_toggle(u32 gpioport, u32 gpios);

#endif

