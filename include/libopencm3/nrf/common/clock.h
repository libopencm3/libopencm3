/** @addtogroup clock_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Maxim Sloyko <maxims@google.com>
 * @author @htmlonly &copy; @endhtmlonly 2021 Eduard Drusa <ventyl86 at netkosice dot sk>
 *
 **/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017-2018 Unicore MX project<dev(at)lists(dot)unicore-mx(dot)org>
 * Copyright (C) 2021 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
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

#pragma once

#include <stdbool.h>

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
/**@{*/

/* Clock tasks */
#define CLOCK_TASK_HFCLKSTART       MMIO32(CLOCK_BASE + 0x000)
#define CLOCK_TASK_HFCLKSTOP        MMIO32(CLOCK_BASE + 0x004)
#define CLOCK_TASK_LFCLKSTART       MMIO32(CLOCK_BASE + 0x008)
#define CLOCK_TASK_LFCLKSTOP        MMIO32(CLOCK_BASE + 0x00C)
#define CLOCK_TASK_CAL              MMIO32(CLOCK_BASE + 0x010)
#define CLOCK_TASK_CTSTART          MMIO32(CLOCK_BASE + 0x014)
#define CLOCK_TASK_CTSTOP           MMIO32(CLOCK_BASE + 0x018)

/* Clock events */
#define CLOCK_EVENT_HFCLKSTARTED    MMIO32(CLOCK_BASE + 0x100)
#define CLOCK_EVENT_LFCLKSTARTED    MMIO32(CLOCK_BASE + 0x104)
#define CLOCK_EVENT_DONE            MMIO32(CLOCK_BASE + 0x10C)
#define CLOCK_EVENT_CTTO            MMIO32(CLOCK_BASE + 0x110)

/* Clock registers */
#define CLOCK_INTENSET              MMIO32(CLOCK_BASE + 0x304)
#define CLOCK_INTENCLR              MMIO32(CLOCK_BASE + 0x308)
#define CLOCK_HFCLKRUN              MMIO32(CLOCK_BASE + 0x408)
#define CLOCK_HFCLKSTAT             MMIO32(CLOCK_BASE + 0x40C)
#define CLOCK_LFCLKRUN              MMIO32(CLOCK_BASE + 0x414)
#define CLOCK_LFCLKSTAT             MMIO32(CLOCK_BASE + 0x418)
#define CLOCK_LFCLKSRCCOPY          MMIO32(CLOCK_BASE + 0x41C)
#define CLOCK_LFCLKSRC              MMIO32(CLOCK_BASE + 0x518)
#define CLOCK_CTIV                  MMIO32(CLOCK_BASE + 0x538)

/* Register contents */
#define CLOCK_INTEN_HFCLKSTARTED    (1 << 0)
#define CLOCK_INTEN_LFCLKSTARTED    (1 << 1)
#define CLOCK_INTEN_DONE            (1 << 3)
#define CLOCK_INTEN_CTTO            (1 << 4)

#define CLOCK_HFCLKRUN_STATUS       (1 << 0)

#define CLOCK_HFCLKSTAT_SRC         (1 << 0)
#define CLOCK_HFCLKSTAT_STATE       (1 << 16)

#define CLOCK_LFCLKRUN_STATUS       (1 << 0)

#define CLOCK_LFCLK_SRC_SHIFT       (0)
#define CLOCK_LFCLK_SRC_MASK        (3 << CLOCK_LFCLKSTAT_SRC_SHIFT)
#define CLOCK_LFCLK_SRC_MASKED(V)   (((V) << CLOCK_LFCLKSTAT_SRC_SHIFT) & CLOCK_LFCLKSTAT_SRC_MASK)

#define CLOCK_LFCLKSTAT_STATE       (1 << 16)

enum clock_lfclk_src {
	CLOCK_LFCLK_SRC_RC,
	CLOCK_LFCLK_SRC_XTAL,
	CLOCK_LFCLK_SRC_SYNTH,
};
/**@}*/

BEGIN_DECLS

void clock_start_lfclk(bool wait);
void clock_stop_lfclk(void);
void clock_start_hfclk(bool wait);
void clock_stop_hfclk(void);
void clock_set_lfclk_src(enum clock_lfclk_src lfclk_src);

END_DECLS


