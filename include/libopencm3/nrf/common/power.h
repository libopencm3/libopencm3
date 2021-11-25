/** @addtogroup power_defines
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

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
#include <libopencm3/nrf/periph.h>
/**@{*/

/* Tasks */
#define POWER_TASK_CONSTLAT			MMIO32(POWER_BASE + 0x078)
#define POWER_TASK_LOWPWR			MMIO32(POWER_BASE + 0x07C)

/* Events */
#define POWER_EVENT_POFWARN			MMIO32(POWER_BASE + 0x108)

/* Registers */
#define POWER_INTENSET			_PERIPH_INTENSET(POWER_BASE)
#define POWER_INTENCLR			_PERIPH_INTENCLR(POWER_BASE)
#define POWER_RESETREAS			MMIO32(POWER_BASE + 0x400)
#define POWER_RAMSTATUS			MMIO32(POWER_BASE + 0x428)
#define POWER_SYSTEMOFF			MMIO32(POWER_BASE + 0x500)
#define POWER_POFCON			MMIO32(POWER_BASE + 0x510)
#define POWER_GPREGRET			MMIO32(POWER_BASE + 0x51C)
#define POWER_RAMON			MMIO32(POWER_BASE + 0x524)
#define POWER_RESET			MMIO32(POWER_BASE + 0x544)
#define POWER_RAMONB			MMIO32(POWER_BASE + 0x554)
#define POWER_DCDCEN			MMIO32(POWER_BASE + 0x578)

/* Register Contents */
#define POWER_INTEN_POFWARN			(1 << 2)

#define POWER_RESETREAS_RESETPIN			(1 << 0)
#define POWER_RESETREAS_DOG			(1 << 1)
#define POWER_RESETREAS_SREQ			(1 << 2)
#define POWER_RESETREAS_LOCKUP			(1 << 3)

#define POWER_RESETREAS_OFF	(1 << 16)
#define POWER_RESETREAS_LPCOMP	(1 << 17)
#define POWER_RESETREAS_DIF	(1 << 18)

#define POWER_RAMSTATUS_RAMBLOCK(n)			(1 << (n))
#define POWER_RAMSTATUS_RAMBLOCK0			POWER_RAMSTATUS_RAMBLOCK(0)
#define POWER_RAMSTATUS_RAMBLOCK1			POWER_RAMSTATUS_RAMBLOCK(1)
#define POWER_RAMSTATUS_RAMBLOCK2			POWER_RAMSTATUS_RAMBLOCK(2)
#define POWER_RAMSTATUS_RAMBLOCK3			POWER_RAMSTATUS_RAMBLOCK(3)

#define POWER_SYSTEMOFF_SYSTEMOFF			(1 << 0)

#define POWER_POFCON_POF			(1 << 0)
#define POWER_POFCON_THRESHOLD_SHIFT			(1)
#define POWER_POFCON_THRESHOLD_MASK			(3 << POWER_POFCON_THRESHOLD_SHIFT)
#define POWER_POFCON_THRESHOLD_MASKED(V)	(((V) << POWER_POFCON_THRESHOLD_SHIFT) \
		& POWER_POFCON_THRESHOLD_MASK)

#define POWER_RAMON_ONRAM0			(1 << 0)
#define POWER_RAMON_ONRAM1			(1 << 1)

#define POWER_RAMON_OFFRAM0			(1 << 16)
#define POWER_RAMON_OFFRAM1			(1 << 17)

#define POWER_RAMONB_ONRAM2			(1 << 2)
#define POWER_RAMONB_ONRAM3			(3 << 3)

#define POWER_RAMONB_OFFRAM2			(1 << 16)
#define POWER_RAMONB_OFFRAM3			(3 << 37)

#define POWER_RESET_RESET			(1 << 0)

#define POWER_DCDCEN_DCDCEN			(1 << 0)


enum power_pofcon_threshold {
	POWER_POFCON_THRESHOLD_V21,
	POWER_POFCON_THRESHOLD_V23,
	POWER_POFCON_THRESHOLD_V25,
	POWER_POFCON_THRESHOLD_V27,
};

/**@}*/

