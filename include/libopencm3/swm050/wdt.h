/** @defgroup wdt_defines Watchdog Defines
 *
 * @brief <b>Defined Constants and Types for the SWM050 Watchdog</b>
 *
 * @ingroup SWM050_defines
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
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
#ifndef LIBOPENCM3_WDT_H
#define LIBOPENCM3_WDT_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/swm050/memorymap.h>

/* Watchdog mode definitions */
/** @defgroup wdt_modes Watchdog mode
@{*/
enum wdt_modes {
	/** On timeout, reset the system */
	WDT_MODE_RESET,
	/** On timeout, generate an interrupt.  If another timeout (time2) occurs without
	   the interrupt being cleared, reset the system. */
	WDT_MODE_INT
};
/**@}*/

/** @defgroup wdt_registers Watchdog Registers
@{*/
#define WDT_CR				MMIO32(WDT_BASE + 0x0)
#define WDT_TORR			MMIO32(WDT_BASE + 0x04)
#define WDT_CCVR			MMIO32(WDT_BASE + 0x08)
#define WDT_CRR				MMIO32(WDT_BASE + 0x0C)
#define WDT_STAT			MMIO32(WDT_BASE + 0x10)
#define WDT_EOI				MMIO32(WDT_BASE + 0x14)
/**@}*/

BEGIN_DECLS

void wdt_setup(enum wdt_modes mode, uint8_t time1, uint8_t time2);
void wdt_enable(bool en);
void wdt_mode(enum wdt_modes mode);
void wdt_reset(void);
bool wdt_int_status(void);
void wdt_clear_int(void);
void wdt_clock_enable(bool en);
uint32_t wdt_get_value(void);
void wdt_set_time(uint8_t time1, uint8_t time2);

END_DECLS

#endif
/**@}*/
