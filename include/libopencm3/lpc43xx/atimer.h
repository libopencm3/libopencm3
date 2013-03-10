/** @defgroup atimer_defines Alarm Timer Defines

@brief <b>Defined Constants and Types for the LPC43xx Alarm Timer</b>

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

#ifndef LPC43XX_ATIMER_H
#define LPC43XX_ATIMER_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Alarm Timer registers ----------------------------------------------- */

/* Downcounter register */
#define ATIMER_DOWNCOUNTER              MMIO32(ATIMER_BASE + 0x000)

/* Preset value register */
#define ATIMER_PRESET                   MMIO32(ATIMER_BASE + 0x004)

/* Interrupt clear enable register */
#define ATIMER_CLR_EN                   MMIO32(ATIMER_BASE + 0xFD8)

/* Interrupt set enable register */
#define ATIMER_SET_EN                   MMIO32(ATIMER_BASE + 0xFDC)

/* Status register */
#define ATIMER_STATUS                   MMIO32(ATIMER_BASE + 0xFE0)

/* Enable register */
#define ATIMER_ENABLE                   MMIO32(ATIMER_BASE + 0xFE4)

/* Clear register */
#define ATIMER_CLR_STAT                 MMIO32(ATIMER_BASE + 0xFE8)

/* Set register */
#define ATIMER_SET_STAT                 MMIO32(ATIMER_BASE + 0xFEC)

/**@}*/

#endif
