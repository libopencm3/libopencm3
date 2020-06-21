/*
 * This file is part of the libopencm3 project.
 *
 * Copyright 2020 Lubomir Rintel <lkundrak@v3.sk>
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
/** @defgroup CM3_systick_defines GD32V SysTick Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the GD32V SysTick </b>
 *
 * @ingroup GD32V_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2020 Lubomir Rintel <lkundrak@v3.sk>
 *
 * @date 8 July 2020
 *
 * @see https://doc.nucleisys.com/nuclei_spec/isa/timer.html
 * LGPL License Terms @ref lgpl_license
 */
/**@{*/
#ifndef LIBOPENCM3_SYSTICK_H
#define LIBOPENCM3_SYSTICK_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

#define SYSTICK_TIME		MMIO64(SYSTICK_BASE + 0x0000)
#define SYSTICK_TIME_CMP	MMIO64(SYSTICK_BASE + 0x0008)

#define SYSTICK_TIME_LO		MMIO32(SYSTICK_BASE + 0x0000)
#define SYSTICK_TIME_HI		MMIO32(SYSTICK_BASE + 0x0004)
#define SYSTICK_TIME_CMP_LO	MMIO32(SYSTICK_BASE + 0x0008)
#define SYSTICK_TIME_CMP_HI	MMIO32(SYSTICK_BASE + 0x000c)

#define SYSTICK_SOFT_RESET	MMIO32(SYSTICK_BASE + 0x0ff0)
#define SYSTICK_SOFT_INT	MMIO32(SYSTICK_BASE + 0x0ffc)

#define SYSTICK_AHB_DIVIDER	4

BEGIN_DECLS

void systick_set_reload(uint64_t value);
uint64_t systick_get_reload(void);
void systick_set_value(uint64_t value);
uint64_t systick_get_value(void);
void systick_interrupt_enable(void);
void systick_interrupt_disable(void);

END_DECLS

#endif
/**@}*/
