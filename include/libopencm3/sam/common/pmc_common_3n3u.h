/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Felix Held <felix-libopencm3@felixheld.de>
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

#if defined(LIBOPENCM3_PMC_H)

#ifndef LIBOPENCM3_PMC_COMMON_3N3U_H
#define LIBOPENCM3_PMC_COMMON_3N3U_H

/* Peripheral Clock Enable Register */
#define PMC_PCER			MMIO32(PMC_BASE + 0x0010)

/* Peripheral Clock Disable Register */
#define PMC_PCDR			MMIO32(PMC_BASE + 0x0014)

/* Peripheral Clock Status Register */
#define PMC_PCSR			MMIO32(PMC_BASE + 0x0018)


#endif

#else
#warning "pmc_common_3n3u.h should not be included explicitly, only via pmc.h"
#endif
