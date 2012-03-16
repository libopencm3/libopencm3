/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LIBOPENCM3_CM3_COMMON_H
#define LIBOPENCM3_CM3_COMMON_H

#include <stdint.h>
#include <stdbool.h>

/* Type definitions for shorter and nicer code */
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

/* Generic memory-mapped I/O accessor functions */
#define MMIO8(addr)		(*(volatile u8 *)(addr))
#define MMIO16(addr)		(*(volatile u16 *)(addr))
#define MMIO32(addr)		(*(volatile u32 *)(addr))
#define MMIO64(addr)		(*(volatile u64 *)(addr))

/* Main page for the doxygen-generated documentation: */

/**
 * @mainpage libopencm3 Developer Documentation
 *
 * The libopencm3 project (previously known as libopenstm32) aims to create
 * a free/libre/open-source (GPL v3, or later) firmware library for various
 * ARM Cortex-M3 microcontrollers, including ST STM32, Toshiba TX03,
 * Atmel SAM3U, NXP LPC1000 and others.
 *
 * @par ""
 *
 * See the <a href="http://www.libopencm3.org">libopencm3 wiki</a> for
 * more information.
 */

#endif
