/** @addtogroup syscfg_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Fergus Noble <fergusnoble@gmail.com>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA SYSCFG.H
The order of header inclusion is important. syscfg.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#if defined(LIBOPENCM3_SYSCFG_H)
/** @endcond */
#ifndef LIBOPENCM3_SYSCFG_COMMON_L1F234_H
#define LIBOPENCM3_SYSCFG_COMMON_L1F234_H

/**@{*/

/* --- SYSCFG registers ---------------------------------------------------- */

#define SYSCFG_MEMRM			MMIO32(SYSCFG_BASE + 0x00)

#define SYSCFG_PMC			MMIO32(SYSCFG_BASE + 0x04)

/* External interrupt configuration registers [0..3] (SYSCFG_EXTICR[1..4]) */
#define SYSCFG_EXTICR(i)		MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1			SYSCFG_EXTICR(0)
#define SYSCFG_EXTICR2			SYSCFG_EXTICR(1)
#define SYSCFG_EXTICR3			SYSCFG_EXTICR(2)
#define SYSCFG_EXTICR4			SYSCFG_EXTICR(3)

#define SYSCFG_CMPCR			MMIO32(SYSCFG_BASE + 0x20)

#endif
/**@}*/

/** @cond */
#else
#warning "syscfg_common_l1f234.h should not be included explicitly,"
#warning "only via syscfg.h"
#endif
/** @endcond */
