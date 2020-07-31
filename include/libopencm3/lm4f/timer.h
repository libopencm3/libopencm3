/** @defgroup timer_defines General Purpose Timers
 *
 * @brief <b>Defined Constants and Types for the LM4F General Purpose Timers</b>
 *
 * @ingroup LM4Fxx_defines
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright 2018 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/cm3/common.h>
#include <libopencm3/lm4f/memorymap.h>

/**@{*/

/** @defgroup timer_registers GP Timer registers
 * Unless otherwise specified, these registers are RW
 *@{*/

/** Configuration */
#define GPTMCFG(tim_base)	MMIO32((tim_base) + 0)
/** Timer A mode */
#define GPTMTAMR(tim_base)	MMIO32((tim_base) + 0x4)
/** Timer B mode */
#define GPTMTBMR(tim_base)	MMIO32((tim_base) + 0x8)
/** Control */
#define GPTMCTL(tim_base)	MMIO32((tim_base) + 0xc)
/** Synchronize */
#define GPTMSYNC(tim_base)	MMIO32((tim_base) + 0x10)
/** Interrupt mask */
#define GPTMIMR(tim_base)	MMIO32((tim_base) + 0x18)
/** Raw interrupt status (RO) */
#define GPTMRIS(tim_base)	MMIO32((tim_base) + 0x1c)
/** Masked interrupt status (RO) */
#define GPTMMIS(tim_base)	MMIO32((tim_base) + 0x20)
/** Interrupt clear (W1C) */
#define GPTMICR(tim_base)	MMIO32((tim_base) + 0x24)
/** Timer A Interval load */
#define GPTMTAILR(tim_base)	MMIO32((tim_base) + 0x28)
/** Timer B Interval load */
#define GPTMTBILR(tim_base)	MMIO32((tim_base) + 0x2c)
/** Timer A match */
#define GPTMTAMATCHR(tim_base)	MMIO32((tim_base) + 0x30)
/** Timer B match */
#define GPTMTBMATCHR(tim_base)	MMIO32((tim_base) + 0x34)
/** Timer A prescale */
#define GPTMTAPR(tim_base)	MMIO32((tim_base) + 0x38)
/** Timer B prescale */
#define GPTMTBPR(tim_base)	MMIO32((tim_base) + 0x3c)
/** Timer A prescale match */
#define GPTMTAPMR(tim_base)	MMIO32((tim_base) + 0x40)
/** Timer A prescale match */
#define GPTMTBPMR(tim_base)	MMIO32((tim_base) + 0x44)
/* Timer A (RO) */
#define GPTMTAR(tim_base)	MMIO32((tim_base) + 0x48)
/* Timer B (RO) */
#define GPTMTBR(tim_base)	MMIO32((tim_base) + 0x4c)
/* Timer A value */
#define GPTMTAV(tim_base)	MMIO32((tim_base) + 0x50)
/* Timer B value */
#define GPTMTBV(tim_base)	MMIO32((tim_base) + 0x54)
/** RTC Predivide (RO) */
#define GPTMRTCPD(tim_base)	MMIO32((tim_base) + 0x58)
/** Timer A prescale snapshot (RO) */
#define GPTMTAPS(tim_base)	MMIO32((tim_base) + 0x5c)
/** Timer B prescale snapshot (RO) */
#define GPTMTBPS(tim_base)	MMIO32((tim_base) + 0x60)
/** Timer A prescale value (RO) */
#define GPTMTAPV(tim_base)	MMIO32((tim_base) + 0x64)
/** Timer B prescale value (RO) */
#define GPTMTBPV(tim_base)	MMIO32((tim_base) + 0x68)
/** Peripheral properties (RO) */
#define GPTMPP(tim_base)	MMIO32((tim_base) + 0xfc0)

/**@}*/

/**@}*/