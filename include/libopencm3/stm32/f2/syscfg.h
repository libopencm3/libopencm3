/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H

#include <libopencm3/stm32/memorymap.h>

/* --- SYSCFG registers ------------------------------------------------------ */

#define SYSCFG_MEMRM			MMIO32(SYSCFG_BASE + 0x00)

#define SYSCFG_PMC			MMIO32(SYSCFG_BASE + 0x04)

/* External interrupt configuration register 1 (SYSCFG_EXTICR1) */
#define SYSCFG_EXTICR1			MMIO32(SYSCFG_BASE + 0x08)

/* External interrupt configuration register 2 (SYSCFG_EXTICR2) */
#define SYSCFG_EXTICR2			MMIO32(SYSCFG_BASE + 0x0c)

/* External interrupt configuration register 3 (SYSCFG_EXTICR3) */
#define SYSCFG_EXTICR3			MMIO32(SYSCFG_BASE + 0x10)

/* External interrupt configuration register 4 (SYSCFG_EXTICR4) */
#define SYSCFG_EXTICR4			MMIO32(SYSCFG_BASE + 0x14)

#define SYSCFG_CMPCR			MMIO32(SYSCFG_BASE + 0x20)

#endif

