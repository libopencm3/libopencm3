/** @defgroup ficr_defines FICR Defines
 *
 * @brief <b>Defined Constants and Types for the NRF51xx Factory information
 * configuration registers</b>
 *
 * @ingroup NRF51xx_defines
 *
 * @version 1.0.0
 *
 * @date Nov 2021
 *
 *LGPL License Terms @ref lgpl_license
 */
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
#include <libopencm3/nrf/common/ficr.h>

/* Deprecated by Nordic */
#define FICR_CLENR0         MMIO32(FICR_BASE + 0x028)
/* Deprecated by Nordic */
#define FICR_PPFC           MMIO32(FICR_BASE + 0x02C)

#define FICR_NUMRAMBLOCK    MMIO32(FICR_BASE + 0x034)
#define FICR_SIZERAMBLOCKS  MMIO32(FICR_BASE + 0x038)

/* Deprecated by Nordic */
#define FICR_SIZERAMBLOCK(n)    MMIO32(FICR_BASE + 0x038 + 0x4 * (n))

#define FICR_CONFIGID           MMIO32(FICR_BASE + 0x05C)

#define FICR_OVERRIDEEN         MMIO32(FICR_BASE + 0x0AC)

/* Override values for Nordic Semi proprietary NRF 1Mbit mode */
#define FICR_NRF_1MBIT(n)       MMIO32(FICR_BASE + 0x0B0 + 0x4 * (n))
#define FICR_NRF_1MBIT0         FICR_NRF_1MBIT(0)
#define FICR_NRF_1MBIT1         FICR_NRF_1MBIT(1)
#define FICR_NRF_1MBIT2         FICR_NRF_1MBIT(2)
#define FICR_NRF_1MBIT3         FICR_NRF_1MBIT(3)
#define FICR_NRF_1MBIT4         FICR_NRF_1MBIT(4)

/* Override values for BLE 1Mbit mode */
#define FICR_BLE_1MBIT(n)       MMIO32(FICR_BASE + 0x0EC + 0x4 * (n))
#define FICR_BLE_1MBIT0         FICR_BLE_1MBIT(0)
#define FICR_BLE_1MBIT1         FICR_BLE_1MBIT(1)
#define FICR_BLE_1MBIT2         FICR_BLE_1MBIT(2)
#define FICR_BLE_1MBIT3         FICR_BLE_1MBIT(3)
#define FICR_BLE_1MBIT4         FICR_BLE_1MBIT(4)

#define FICR_OVERRIDEEN_NRF_1MBIT           (1 << 0)
#define FICR_OVERRIDEEN_BLE_1MBIT           (1 << 3)

