/** @defgroup mmap_defines Memory Map
 *
 * @brief <b>Defined Constants for the SWM050 Memory Map</b>
 *
 * @ingroup SWM050_defines
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
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
#ifndef LIBOPENCM3_MEMORYMAP_H
#define LIBOPENCM3_MEMORYMAP_H
#include <libopencm3/cm3/memorymap.h>

/* Memory map for all buses */
/** @defgroup memory_map Memory Map for All Buses
@{*/
#define PERIPH_BASE			(0x40000000U)

#define SYSTEM_CON_BASE			(PERIPH_BASE + 0x0)
#define GPIO_BASE			(PERIPH_BASE + 0x1000)
#define TIMER_SE0_BASE			(PERIPH_BASE + 0x2000)
#define TIMER_SE1_BASE			(PERIPH_BASE + 0x2400)
#define WDT_BASE			(PERIPH_BASE + 0x19000)
#define SYSCTL_BASE			(PERIPH_BASE + 0xf0000)
/*@}*/

#endif
/**@}*/
