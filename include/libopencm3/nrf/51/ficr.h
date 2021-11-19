/*
 * This file is part of the unicore-mx project.
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

#ifndef NRF51_FICR_H
#define NRF51_FICR_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
#include <libopencm3/nrf/common/ficr.h>

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

#endif  /* NRF51_FICR_H */
