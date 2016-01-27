/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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
 * @see efm32tg/memorymap.h
 * @see efm32lg/memorymap.h
 */

#if defined(EFM32TG)
#	include <libopencm3/efm32/tg/memorymap.h>
#elif defined(EFM32LG)
#	include <libopencm3/efm32/lg/memorymap.h>
#else
#	error "efm32 family not defined."
#endif
