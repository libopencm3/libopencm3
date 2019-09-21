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

/* Clock speed definitions */
/** @defgroup clk_speeds Base Clock Speeds
@{*/
enum clk_speeds {
	CLK_18MHZ,
	CLK_36MHZ
};
/*@}*/

/* Clock divider mask */
/** @defgroup clk_mask Mask used to set the clock divider
@{*/
#define CLK_MASK 0xFFFFFC00
/*@}*/

BEGIN_DECLS

void clk_speed(enum clk_speeds mhz, uint16_t div);

END_DECLS

#endif
/**@}*/
