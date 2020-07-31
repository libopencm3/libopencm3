/** @addtogroup wdog_defines
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#pragma once

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/**@{*/

#define WDOG_CTRL			MMIO32(WDOG_BASE + 0x000)
#define WDOG_CMD			MMIO32(WDOG_BASE + 0x004)
#define WDOG_SYNCBUSY			MMIO32(WDOG_BASE + 0x008)

/* WDOG_CTRL */
#define WDOG_CTRL_CLKSEL_SHIFT		(12)
#define WDOG_CTRL_CLKSEL_MASK		(0x3 << WDOG_CTRL_CLKSEL_SHIFT)
#define WDOG_CTRL_CLKSEL(v)		\
	(((v) << WDOG_CTRL_CLKSEL_SHIFT) & WDOG_CTRL_CLKSEL_MASK)
#define WDOG_CTRL_CLKSEL_ULFRCO		0
#define WDOG_CTRL_CLKSEL_LFRCO		1
#define WDOG_CTRL_CLKSEL_LFXO		2

#define WDOG_CTRL_PERSEL_SHIFT		(8)
#define WDOG_CTRL_PERSEL_MASK		(0xF << WDOG_CTRL_PERSEL_SHIFT)
#define WDOG_CTRL_PERSEL(v)				\
	(((v) << WDOG_CTRL_PERSEL_SHIFT) & WDOG_CTRL_PERSEL_MASK)
#define WDOG_CTRL_PERSEL_9CYCLES	0
#define WDOG_CTRL_PERSEL_17CYCLES	1
#define WDOG_CTRL_PERSEL_33CYCLES	2
#define WDOG_CTRL_PERSEL_65CYCLES	3
#define WDOG_CTRL_PERSEL_129CYCLES	4
#define WDOG_CTRL_PERSEL_257CYCLES	5
#define WDOG_CTRL_PERSEL_513CYCLES	6
#define WDOG_CTRL_PERSEL_1KCYCLES	7
#define WDOG_CTRL_PERSEL_2KCYCLES	8
#define WDOG_CTRL_PERSEL_4KCYCLES	9
#define WDOG_CTRL_PERSEL_8KCYCLES	10
#define WDOG_CTRL_PERSEL_16KCYCLES	11
#define WDOG_CTRL_PERSEL_32KCYCLES	12
#define WDOG_CTRL_PERSEL_64KCYCLES	13
#define WDOG_CTRL_PERSEL_128KCYCLES	14
#define WDOG_CTRL_PERSEL_256KCYCLES	15

#define WDOG_CTRL_SWOSCBLOCK		(1 << 6)
#define WDOG_CTRL_EM4BLOCK		(1 << 5)
#define WDOG_CTRL_LOCK			(1 << 4)
#define WDOG_CTRL_EM3RUN		(1 << 3)
#define WDOG_CTRL_EM2RUN		(1 << 2)
#define WDOG_CTRL_DEBUGRUN		(1 << 1)
#define WDOG_CTRL_EN			(1 << 0)

/* WDOG_CMD */
#define WDOG_CMD_CLEAR			(1 << 0)

/* WDOG_SYNCBUSY */
#define WDOG_SYNCBUSY_CMD		(1 << 1)
#define WDOG_SYNCBUSY_CTRL		(1 << 0)

/**@}*/