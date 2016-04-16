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



#define GPIO_GPER(X)			MMIO32((X) + 0x10 * 0)
#define GPIO_GPERS(X)			MMIO32((X) + 0x10 * 0 + 0x4)
#define GPIO_GPERC(X)			MMIO32((X) + 0x10 * 0 + 0x8)
#define GPIO_GPERT(X)			MMIO32((X) + 0x10 * 0 + 0xc)


#define GPIO_PMR0(X)			MMIO32((X) + 0x10 * 1)
#define GPIO_PMR0S(X)			MMIO32((X) + 0x10 * 1 + 0x4)
#define GPIO_PMR0C(X)			MMIO32((X) + 0x10 * 1 + 0x8)
#define GPIO_PMR0T(X)			MMIO32((X) + 0x10 * 1 + 0xc)


#define GPIO_PMR1(X)			MMIO32((X) + 0x10 * 2)
#define GPIO_PMR1S(X)			MMIO32((X) + 0x10 * 2 + 0x4)
#define GPIO_PMR1C(X)			MMIO32((X) + 0x10 * 2 + 0x8)
#define GPIO_PMR1T(X)			MMIO32((X) + 0x10 * 2 + 0xc)


#define GPIO_PMR2(X)			MMIO32((X) + 0x10 * 3)
#define GPIO_PMR2S(X)			MMIO32((X) + 0x10 * 3 + 0x4)
#define GPIO_PMR2C(X)			MMIO32((X) + 0x10 * 3 + 0x8)
#define GPIO_PMR2T(X)			MMIO32((X) + 0x10 * 3 + 0xc)


#define GPIO_ODER(X)			MMIO32((X) + 0x10 * 4)
#define GPIO_ODERS(X)			MMIO32((X) + 0x10 * 4 + 0x4)
#define GPIO_ODERC(X)			MMIO32((X) + 0x10 * 4 + 0x8)
#define GPIO_ODERT(X)			MMIO32((X) + 0x10 * 4 + 0xc)


#define GPIO_OVR(X)			MMIO32((X) + 0x10 * 5)
#define GPIO_OVRS(X)			MMIO32((X) + 0x10 * 5 + 0x4)
#define GPIO_OVRC(X)			MMIO32((X) + 0x10 * 5 + 0x8)
#define GPIO_OVRT(X)			MMIO32((X) + 0x10 * 5 + 0xc)


#define GPIO_PVR(X)			MMIO32((X) + 0x10 * 6)
#define GPIO_PVRS(X)			MMIO32((X) + 0x10 * 6 + 0x4)
#define GPIO_PVRC(X)			MMIO32((X) + 0x10 * 6 + 0x8)
#define GPIO_PVRT(X)			MMIO32((X) + 0x10 * 6 + 0xc)


#define GPIO_PUER(X)			MMIO32((X) + 0x10 * 7)
#define GPIO_PUERS(X)			MMIO32((X) + 0x10 * 7 + 0x4)
#define GPIO_PUERC(X)			MMIO32((X) + 0x10 * 7 + 0x8)
#define GPIO_PUERT(X)			MMIO32((X) + 0x10 * 7 + 0xc)


#define GPIO_PDER(X)			MMIO32((X) + 0x10 * 8)
#define GPIO_PDERS(X)			MMIO32((X) + 0x10 * 8 + 0x4)
#define GPIO_PDERC(X)			MMIO32((X) + 0x10 * 8 + 0x8)
#define GPIO_PDERT(X)			MMIO32((X) + 0x10 * 8 + 0xc)


#define GPIO_IER(X)			MMIO32((X) + 0x10 * 9)
#define GPIO_IERS(X)			MMIO32((X) + 0x10 * 9 + 0x4)
#define GPIO_IERC(X)			MMIO32((X) + 0x10 * 9 + 0x8)
#define GPIO_IERT(X)			MMIO32((X) + 0x10 * 9 + 0xc)


#define GPIO_IMR0(X)			MMIO32((X) + 0x10 * 10)
#define GPIO_IMR0S(X)			MMIO32((X) + 0x10 * 10 + 0x4)
#define GPIO_IMR0C(X)			MMIO32((X) + 0x10 * 10 + 0x8)
#define GPIO_IMR0T(X)			MMIO32((X) + 0x10 * 10 + 0xc)


#define GPIO_IMR1(X)			MMIO32((X) + 0x10 * 11)
#define GPIO_IMR1S(X)			MMIO32((X) + 0x10 * 11 + 0x4)
#define GPIO_IMR1C(X)			MMIO32((X) + 0x10 * 11 + 0x8)
#define GPIO_IMR1T(X)			MMIO32((X) + 0x10 * 11 + 0xc)


#define GPIO_GFER(X)			MMIO32((X) + 0x10 * 12)
#define GPIO_GFERS(X)			MMIO32((X) + 0x10 * 12 + 0x4)
#define GPIO_GFERC(X)			MMIO32((X) + 0x10 * 12 + 0x8)
#define GPIO_GFERT(X)			MMIO32((X) + 0x10 * 12 + 0xc)


#define GPIO_IFR(X)			MMIO32((X) + 0x10 * 13)
#define GPIO_IFRS(X)			MMIO32((X) + 0x10 * 13 + 0x4)
#define GPIO_IFRC(X)			MMIO32((X) + 0x10 * 13 + 0x8)
#define GPIO_IFRT(X)			MMIO32((X) + 0x10 * 13 + 0xc)


#define GPIO_ODCR0(X)			MMIO32((X) + 0x10 * 14)
#define GPIO_ODCR0S(X)			MMIO32((X) + 0x10 * 14 + 0x4)
#define GPIO_ODCR0C(X)			MMIO32((X) + 0x10 * 14 + 0x8)
#define GPIO_ODCR0T(X)			MMIO32((X) + 0x10 * 14 + 0xc)


#define GPIO_ODCR1(X)			MMIO32((X) + 0x10 * 15)
#define GPIO_ODCR1S(X)			MMIO32((X) + 0x10 * 15 + 0x4)
#define GPIO_ODCR1C(X)			MMIO32((X) + 0x10 * 15 + 0x8)
#define GPIO_ODCR1T(X)			MMIO32((X) + 0x10 * 15 + 0xc)


#define GPIO_OSRR0(X)			MMIO32((X) + 0x10 * 16)
#define GPIO_OSRR0S(X)			MMIO32((X) + 0x10 * 16 + 0x4)
#define GPIO_OSRR0C(X)			MMIO32((X) + 0x10 * 16 + 0x8)
#define GPIO_OSRR0T(X)			MMIO32((X) + 0x10 * 16 + 0xc)


#define GPIO_STER(X)			MMIO32((X) + 0x10 * 17)
#define GPIO_STERS(X)			MMIO32((X) + 0x10 * 17 + 0x4)
#define GPIO_STERC(X)			MMIO32((X) + 0x10 * 17 + 0x8)
#define GPIO_STERT(X)			MMIO32((X) + 0x10 * 17 + 0xc)

#define GPIO_EVER(X)			MMIO32((X) + 0x10 * 18)
#define GPIO_EVERS(X)			MMIO32((X) + 0x10 * 18 + 0x4)
#define GPIO_EVERC(X)			MMIO32((X) + 0x10 * 18 + 0x8)
#define GPIO_EVERT(X)			MMIO32((X) + 0x10 * 18 + 0xc)

#define GPIO_PARAMETER(X)			MMIO32((X) + 0x1f8)
#define GPIO_VERSION(X)			MMIO32((X) + 0x1fc)

#endif
