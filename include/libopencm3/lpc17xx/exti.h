/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
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

#ifndef LIBOPENCM3_EXTI_H
#define LIBOPENCM3_EXTI_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc17xx/memorymap.h>

#define EXTINT          MMIO32(SYSCON_BASE + 0x140)
#define EXTMODE     MMIO32(SYSCON_BASE + 0x148)
#define EXTPOLAR   MMIO32(SYSCON_BASE + 0x14C)

#define EXTI0   0
#define EXTI1   1
#define EXTI2   2
#define EXTI3   3


enum exti_trigger_type {
	EXTI_TRIGGER_RISING,
	EXTI_TRIGGER_FALLING,
	EXTI_TRIGGER_HIGH,
        EXTI_TRIGGER_LOW
};

void exti_set_trigger(uint32_t extis, enum exti_trigger_type trig);
void exti_clear_flag(uint32_t extis);

#endif

