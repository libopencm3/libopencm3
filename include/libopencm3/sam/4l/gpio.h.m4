m4_divert(-1)
m4_define(`GPIOREG', `
`#'define GPIO_$1(X)			MMIO32((X) + $2)
`#'define GPIO_$1S(X)			MMIO32((X) + $2 + 0x4)
`#'define GPIO_$1C(X)			MMIO32((X) + $2 + 0x8)
`#'define GPIO_$1T(X)			MMIO32((X) + $2 + 0xc)')
m4_define(`GPIOPORT', `m4_ifelse(`$#', `2', `GPIOREG($2, 0x10 * $1)', `
GPIOREG($2, 0x10 * $1)
GPIOPORT(m4_incr($1), m4_shift(m4_shift($@)))')')
m4_divert(0)m4_dnl
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Maxim Sloyko <maxim@sloyko.com>
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

#ifndef LIBOPENCM3_GPIO_H
#define LIBOPENCM3_GPIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>
#include <libopencm3/sam/common/gpio_common_all.h>

#define GPIOA	(GPIO_BASE)
#define GPIOB	(GPIO_BASE + 0x200)
#define GPIOC	(GPIO_BASE + 0x400)

GPIOPORT(0, GPER,
		PMR0, PMR1, PMR2,
		ODER, OVR, PVR,
		PUER, PDER,
		IER, IMR0, IMR1,
		GFER, IFR,
		ODCR0, ODCR1,
		OSRR0, STER, EVER)

#define GPIO_PARAMETER(X)			MMIO32((X) + 0x1f8)
#define GPIO_VERSION(X)			MMIO32((X) + 0x1fc)

#endif
