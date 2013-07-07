/** @defgroup eventrouter_defines Event Router Defines

@brief <b>Defined Constants and Types for the LPC43xx Event Router</b>

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

#ifndef LPC43XX_EVENTROUTER_H
#define LPC43XX_EVENTROUTER_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Event Router registers ---------------------------------------------- */

/* Level configuration register */
#define EVENTROUTER_HILO                MMIO32(EVENTROUTER_BASE + 0x000)

/* Edge configuration */
#define EVENTROUTER_EDGE                MMIO32(EVENTROUTER_BASE + 0x004)

/* Clear event enable register */
#define EVENTROUTER_CLR_EN              MMIO32(EVENTROUTER_BASE + 0xFD8)

/* Set event enable register */
#define EVENTROUTER_SET_EN              MMIO32(EVENTROUTER_BASE + 0xFDC)

/* Event Status register */
#define EVENTROUTER_STATUS              MMIO32(EVENTROUTER_BASE + 0xFE0)

/* Event Enable register */
#define EVENTROUTER_ENABLE              MMIO32(EVENTROUTER_BASE + 0xFE4)

/* Clear event status register */
#define EVENTROUTER_CLR_STAT            MMIO32(EVENTROUTER_BASE + 0xFE8)

/* Set event status register */
#define EVENTROUTER_SET_STAT            MMIO32(EVENTROUTER_BASE + 0xFEC)

/**@}*/

#endif
