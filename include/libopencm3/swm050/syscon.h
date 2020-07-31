/** @defgroup syscon_defines SYSCON Defines
 *
 * @brief <b>Defined Constants and Types for the SWM050 SYSCON peripheral</b>
 *
 * @ingroup SWM050_defines
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
 * Copyright (C) 2019 Caleb Szalacinski <contact@skiboy.net>
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
/**@{*/
#ifndef LIBOPENCM3_SYSCON_H
#define LIBOPENCM3_SYSCON_H
#include <libopencm3/cm3/common.h>
#include <libopencm3/swm050/memorymap.h>

/* SYSCON Registers */
/** @defgroup syscon_registers SYSCON Registers
@{*/
/** SWD Enable register */
#define SYSCON_SWD_SEL				MMIO32(SYSTEM_CON_BASE + 0x30)
/** Pin Alternate function selection register */
#define SYSCON_PORTA_SEL			MMIO32(SYSTEM_CON_BASE + 0x80)
/** Pin Pull up register */
#define SYSCON_PORTA_PULLUP			MMIO32(SYSTEM_CON_BASE + 0x90)
/** Pin Input enable register */
#define SYSCON_PORTA_INEN			MMIO32(SYSTEM_CON_BASE + 0xe0)
/*@}*/

BEGIN_DECLS

void syscon_sel_af(uint16_t gpios, bool af_en);
void syscon_pullup(uint16_t gpios, bool en);
void syscon_input_enable(uint16_t gpios, bool en);
void syscon_sel_swd(bool en);

END_DECLS

#endif
/**@}*/
