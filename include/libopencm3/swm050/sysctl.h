/** @defgroup sysctl_defines SYSCTL Defines
 *
 * @brief <b>Defined Constants and Types for the SWM050 SYSCTL Registers</b>
 *
 * @ingroup SWM050_defines
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Caleb Szalacinski <contact@skiboy.net>
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

/**@{*/
#ifndef LIBOPENCM3_SYSCTL_H
#define LIBOPENCM3_SYSCTL_H
#include <libopencm3/cm3/common.h>
#include <libopencm3/swm050/memorymap.h>

/** @defgroup sysctl_bit_defs SYSCTL register bit definitions
@{*/
#define SYSCTL_SYS_CFG_2_SLEEP			(1 << 4)
#define SYSCTL_SYS_CFG_1_TIMERSE1		(1 << 17)
#define SYSCTL_SYS_CFG_1_TIMERSE0		(1 << 6)
#define SYSCTL_SYS_CFG_1_WDT			(1 << 4)
/**@}*/

/** @defgroup sysctl_register SYSCTL Registers
 * @note System configuration registers
 * @{*/
/** Clock dividers for TIMERSE and SCLK */
#define SYSCTL_SYS_CFG_0		MMIO32(SYSCTL_BASE + 0x0)
/** TIMERSE0, TIMERSE1, and WDT enable */
#define SYSCTL_SYS_CFG_1		MMIO32(SYSCTL_BASE + 0x4)
/** SCLK multiplier (18Mhz and 36Mhz) */
#define SYSCTL_SYS_DBLF			MMIO32(SYSCTL_BASE + 0x8)
/** MOS Disconnect (Synwit says that this subregister is unused), Sleep Mode,
    and Internal Oscillator Disconnect.  Oscillator Disconnect should probably
    not be used on the SWM050, because it has no external oscillator support */
#define SYSCTL_SYS_CFG_2		MMIO32(SYSCTL_BASE + 0xC)
/*@}*/

#endif
/**@}*/
