/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef LM3S_MEMORYMAP_H
#define LM3S_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- LM3S specific peripheral definitions ----------------------------- */

#define GPIOA_APB_BASE			(0x40004000)
#define GPIOB_APB_BASE			(0x40005000)
#define GPIOC_APB_BASE			(0x40006000)
#define GPIOD_APB_BASE			(0x40007000)
#define GPIOE_APB_BASE			(0x40024000)
#define GPIOF_APB_BASE			(0x40025000)
#define GPIOG_APB_BASE			(0x40026000)
#define GPIOH_APB_BASE			(0x40027000)

#define GPIOA_BASE			(0x40058000)
#define GPIOB_BASE			(0x40059000)
#define GPIOC_BASE			(0x4005A000)
#define GPIOD_BASE			(0x4005B000)
#define GPIOE_BASE			(0x4005C000)
#define GPIOF_BASE			(0x4005D000)
#define GPIOG_BASE			(0x4005E000)
#define GPIOH_BASE			(0x4005F000)

#define SYSTEMCONTROL_BASE		(0x400FE000)

#endif
