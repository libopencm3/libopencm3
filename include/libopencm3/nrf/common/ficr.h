/** @addtogroup ficr_defines
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

/* Factory Information Configuration Register */

#define FICR_CODEPAGESIZE   MMIO32(FICR_BASE + 0x010)
#define FICR_CODESIZE       MMIO32(FICR_BASE + 0x014)

#define FICR_DEVICEID0          MMIO32(FICR_BASE + 0x060)
#define FICR_DEVICEID1          MMIO32(FICR_BASE + 0x064)

/* Encryption Root */
#define FICR_ER(n)          MMIO32(FICR_BASE + 0x080 + 0x4 * (n))
/* Identity Root */
#define FICR_IR(n)          MMIO32(FICR_BASE + 0x090 + 0x4 * (n))
#define FICR_DEVICEADDRTYPE         MMIO32(FICR_BASE + 0x0A0)
#define FICR_DEVICEADDR0            MMIO32(FICR_BASE + 0x0A4)
#define FICR_DEVICEADDR1            MMIO32(FICR_BASE + 0x0A8)


/**@}*/

