/*
 * This file is part of the unicore-mx project.
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

#pragma once

#include <stdbool.h>

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
#include <libopencm3/nrf/common/clock.h>

/* Clock registers */
#define CLOCK_TRACECONFIG       MMIO32(CLOCK_BASE + 0x55C)

#define CLOCK_PCLK              32000000

