/*
 * This file is part of the libopencm3 project.
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

#ifndef LIBOPENCM3_TIMER_H
#define LIBOPENCM3_TIMER_H

#include <libopencm3/efm32/common/timer_common.h>

/* efm32hg specific registers */

/* TIMER_ROUTE */
#define TIMER_ROUTE_LOCATION_LOC6	TIMER_ROUTE_LOCATION_LOCx(6)

/* TIMER_CCx_CTRL */
#define TIMER_CC_CTRL_PRSCONF		(1 << 28)

#endif
