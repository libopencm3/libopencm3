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

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- EXTI registers ------------------------------------------------------ */

#define EXTI_IMR			MMIO32(EXTI_BASE + 0x00)
#define EXTI_EMR			MMIO32(EXTI_BASE + 0x04)
#define EXTI_RTSR			MMIO32(EXTI_BASE + 0x08)
#define EXTI_FTSR			MMIO32(EXTI_BASE + 0x0c)
#define EXTI_SWIER			MMIO32(EXTI_BASE + 0x10)
#define EXTI_PR				MMIO32(EXTI_BASE + 0x14)

/* EXTI number definitions */
#define EXTI0				(1 << 0)
#define EXTI1				(1 << 1)
#define EXTI2				(1 << 2)
#define EXTI3				(1 << 3)
#define EXTI4				(1 << 4)
#define EXTI5				(1 << 5)
#define EXTI6				(1 << 6)
#define EXTI7				(1 << 7)
#define EXTI8				(1 << 8)
#define EXTI9				(1 << 9)
#define EXTI10				(1 << 10)
#define EXTI11				(1 << 11)
#define EXTI12				(1 << 12)
#define EXTI13				(1 << 13)
#define EXTI14				(1 << 14)
#define EXTI15				(1 << 15)
#define EXTI16				(1 << 16)
#define EXTI17				(1 << 17)
#define EXTI18				(1 << 18)
#define EXTI19				(1 << 19)
#define EXTI20				(1 << 20)
#define EXTI21				(1 << 21)
#define EXTI22				(1 << 22)

/* Trigger types */
typedef enum trigger_e {
	EXTI_TRIGGER_RISING,
	EXTI_TRIGGER_FALLING,
	EXTI_TRIGGER_BOTH,
} exti_trigger_type;

BEGIN_DECLS

void exti_set_trigger(u32 extis, exti_trigger_type trig);
void exti_enable_request(u32 extis);
void exti_disable_request(u32 extis);
void exti_reset_request(u32 extis);
void exti_select_source(u32 exti, u32 gpioport);

END_DECLS

#endif
