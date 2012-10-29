/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *
 * Dispatcher for the base address definitions, depending on the particular
 * Gecko family.
 *
 * @see tinygecko/memorymap.h
 */

#ifndef LIBOPENCM3_EFM32_MEMORYMAP_H
#define LIBOPENCM3_EFM32_MEMORYMAP_H

#ifdef TINYGECKO
#	include <libopencm3/efm32/tinygecko/memorymap.h>
#else
#	error "efm32 family not defined."
#endif

#endif
