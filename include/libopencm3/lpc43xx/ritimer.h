/** @defgroup ritimer_defines Repetitive Interrupt Timer Defines

@brief <b>Defined Constants and Types for the LPC43xx Repetitive Interrupt
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

#ifndef LPC43XX_RITIMER_H
#define LPC43XX_RITIMER_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc43xx/memorymap.h>

/* --- Repetitive Interrupt Timer registers -------------------------------- */

/* Compare register */
#define RITIMER_COMPVAL                 MMIO32(RITIMER_BASE + 0x000)

/* Mask register */
#define RITIMER_MASK                    MMIO32(RITIMER_BASE + 0x004)

/* Control register */
#define RITIMER_CTRL                    MMIO32(RITIMER_BASE + 0x008)

/* 32-bit counter */
#define RITIMER_COUNTER                 MMIO32(RITIMER_BASE + 0x00C)

/**@}*/

#endif
