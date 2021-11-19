/** @addtogroup uicr_defines
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

/**@{*/
/* User Information Configuration Register */

#define UICR_CLENR0			MMIO32(UICR_BASE + 0x000)
#define UICR_RBPCONF			MMIO32(UICR_BASE + 0x004)
#define UICR_XTALFREQ			MMIO32(UICR_BASE + 0x008)
#define UICR_FWID			MMIO32(UICR_BASE + 0x010)
#define UICR_BOOTLOADERADDR			MMIO32(UICR_BASE + 0x014)

/* Reserved for Nordic firmware design, n = 1..14 */
#define UICR_NRFFW(n)			MMIO32(UICR_BASE + 0x014 + 0x4 * (n))

/* Reserved for Nordic hardware design, n = 0..11 */
#define UICR_NRFHW(n)			MMIO32(UICR_BASE + 0x050 + 0x4 * (n))

/* Reserved for customer n = 0..31 */
#define UICR_CUSTOMER(n)			MMIO32(UICR_BASE + 0x080 + 0x4 * (n))


/**@}*/

