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

#ifndef NRF51_RADIO_H
#define NRF51_RADIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
#include <libopencm3/nrf/periph.h>
#include <libopencm3/nrf/common/radio.h>

enum radio_mode {
	RADIO_MODE_NRF_1MBIT,
	RADIO_MODE_NRF_2MBIT,
	RADIO_MODE_NRF_250KBIT,
	RADIO_MODE_BLE_1MBIT,
};

BEGIN_DECLS

void radio_set_mode(enum radio_mode mode);

END_DECLS

#endif  /* NRF51_RADIO_H */
