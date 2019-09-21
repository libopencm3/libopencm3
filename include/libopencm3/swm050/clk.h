/** @defgroup clk_defines Clock Defines
 *
 * @brief <b>Defined Constants and Types for the SWM050 System Clock</b>
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
#ifndef LIBOPENCM3_CLK_H
#define LIBOPENCM3_CLK_H
#include <libopencm3/cm3/common.h>
#include <libopencm3/swm050/memorymap.h>

/* Various Clock Defines */
/** @defgroup clk_misc_defs Various Clock Defines

@{*/
#define DEFAULT_BOOT_FREQ	(9000000U)
#define CYCLES_PER_US		(sclk_freq/1000000)
#define CYCLES_PER_MS		(sclk_freq/1000)
#define M36			(36000000U)
#define M18			(18000000U)
/*@}*/

/* Clock speed definitions */
/** @defgroup clk_speed Base Clock Speeds
@{*/
#define CLK_36MHZ		(0x1)
#define CLK_18MHZ		(0x0)
/*@}*/

BEGIN_DECLS

uint32_t clk_speed(bool mhz, uint16_t div);
uint32_t clk_init(bool mhz, uint16_t div);
//void clk_en(bool en);

END_DECLS

#endif
/**@}*/
