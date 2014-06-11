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

#ifndef LM4F_MEMORYMAP_H
#define LM4F_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

/* --- LM4F specific peripheral definitions ----------------------------- */

#define GPIOA_APB_BASE			(0x40004000U)
#define GPIOB_APB_BASE			(0x40005000U)
#define GPIOC_APB_BASE			(0x40006000U)
#define GPIOD_APB_BASE			(0x40007000U)
#define GPIOE_APB_BASE			(0x40024000U)
#define GPIOF_APB_BASE			(0x40025000U)
#define GPIOG_APB_BASE			(0x40026000U)
#define GPIOH_APB_BASE			(0x40027000U)
#define GPIOJ_APB_BASE			(0x4003D000U)

#define GPIOA_BASE			(0x40058000U)
#define GPIOB_BASE			(0x40059000U)
#define GPIOC_BASE			(0x4005A000U)
#define GPIOD_BASE			(0x4005B000U)
#define GPIOE_BASE			(0x4005C000U)
#define GPIOF_BASE			(0x4005D000U)
#define GPIOG_BASE			(0x4005E000U)
#define GPIOH_BASE			(0x4005F000U)
#define GPIOJ_BASE			(0x40060000U)
#define GPIOK_BASE			(0x40061000U)
#define GPIOL_BASE			(0x40062000U)
#define GPIOM_BASE			(0x40063000U)
#define GPION_BASE			(0x40064000U)
#define GPIOP_BASE			(0x40065000U)
#define GPIOQ_BASE			(0x40066000U)

#define UART0_BASE			(0x4000C000U)
#define UART1_BASE			(0x4000D000U)
#define UART2_BASE			(0x4000E000U)
#define UART3_BASE			(0x4000F000U)
#define UART4_BASE			(0x40010000U)
#define UART5_BASE			(0x40011000U)
#define UART6_BASE			(0x40012000U)
#define UART7_BASE			(0x40013000U)

#define SSI0_BASE			(0x40008000U)
#define SSI1_BASE			(0x40009000U)
#define SSI2_BASE			(0x4000A000U)
#define SSI3_BASE			(0x4000B000U)

#define USB_BASE			(0x40050000U)

#define SYSCTL_BASE			(0x400FE000U)

#endif
