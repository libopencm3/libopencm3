/** @defgroup wwdt_defines Windowed Watchdog Timer

@brief <b>Defined Constants and Types for the LPC43xx Windowed Watchdog
Timer</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#ifndef LPC43XX_WWDT_H
#define LPC43XX_WWDT_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Windowed Watchdog Timer (WWDT) registers ---------------------------- */

/* Watchdog mode register */
#define WWDT_MOD                        MMIO32(WWDT_BASE + 0x000)

/* Watchdog timer constant register */
#define WWDT_TC                         MMIO32(WWDT_BASE + 0x004)

/* Watchdog feed sequence register */
#define WWDT_FEED                       MMIO32(WWDT_BASE + 0x008)

/* Watchdog timer value register */
#define WWDT_TV                         MMIO32(WWDT_BASE + 0x00C)

/* Watchdog warning interrupt register */
#define WWDT_WARNINT                    MMIO32(WWDT_BASE + 0x014)

/* Watchdog timer window register */
#define WWDT_WINDOW                     MMIO32(WWDT_BASE + 0x018)

/**@}*/

#endif
