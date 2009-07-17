/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef LIBOPENSTM32_COMMON_H
#define LIBOPENSTM32_COMMON_H

#include "libopenstm32.h"

/* Generic memory-mapped I/O accessor functions */
#define MMIO8(addr)		(*(volatile u8 *)(addr))
#define MMIO16(addr)		(*(volatile u16 *)(addr))
#define MMIO32(addr)		(*(volatile u32 *)(addr))

#endif
