/** @addtogroup radio_file RADIO peripheral API
 *
 * @brief <b>Access functions for the NRF51 2.4 GHz Radio </b>
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
 */

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

#include <libopencm3/nrf/ficr.h>
#include <libopencm3/nrf/radio.h>

/**@{*/

/** @brief Set radio mode.
 *
 * @details The function also performs all required overrides for BLE and NRF mode.
 *
 * @param[in] mode the new mode.
 * */
void radio_set_mode(enum radio_mode mode)
{
	/* This is alias to memory register, thus volatile */
	volatile uint32_t *override_pos = 0;
	if ((RADIO_MODE_BLE_1MBIT == mode)
			&& (FICR_OVERRIDEEN & ~FICR_OVERRIDEEN_BLE_1MBIT)) {
		/* Need to use Override */
		override_pos = &FICR_BLE_1MBIT0;
	} else if ((RADIO_MODE_NRF_1MBIT == mode)
			&& (FICR_OVERRIDEEN & ~FICR_OVERRIDEEN_NRF_1MBIT)) {
		override_pos = &FICR_NRF_1MBIT0;
	}

	if (override_pos) {
		uint8_t i;
		for (i = 0; i <= 4; ++i, ++override_pos) {
			RADIO_OVERRIDE(i) = *override_pos;
		}

		RADIO_OVERRIDE(4) |= RADIO_OVERRIDE4_ENABLE;
	} else {
		RADIO_OVERRIDE(4) &= ~RADIO_OVERRIDE4_ENABLE;
	}

	RADIO_MODE = mode;
}
/**@}*/

