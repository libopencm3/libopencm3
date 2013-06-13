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

#include <libopencm3/sam/pio.h>

/* flags may be or'd together, but only contain one of
 * GPOUTPUT, PERIPHA and PERIPHB */
enum gpio_flags {
	GPIO_FLAG_GPINPUT = 0,
	GPIO_FLAG_GPOUTPUT = 1,
	GPIO_FLAG_PERIPHA = 2,
	GPIO_FLAG_PERIPHB = 3,
	GPIO_FLAG_OPEN_DRAIN = 4,
	GPIO_FLAG_PULL_UP = 8,
};

void gpio_init(uint32_t gpioport, uint32_t pins, enum gpio_flags flags);

static inline void gpio_set(uint32_t gpioport, uint32_t gpios)
{
	PIO_SODR(gpioport) = gpios;
}

static inline void gpio_clear(uint32_t gpioport, uint32_t gpios)
{
	PIO_CODR(gpioport) = gpios;
}

void gpio_toggle(uint32_t gpioport, uint32_t gpios);

#endif

