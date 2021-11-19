/** @addtogroup clock_file CLOCK peripheral API
 *
 * @brief <b>Access functions for the NRF51 Clock Controller </b>
 *
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Roel Postelmans
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

#include <libopencm3/nrf/clock.h>
#include <libopencm3/nrf/periph.h>
/**@{*/

/** @brief Select nominal frequency of external crystal for HFCLK.
 *
 * @details This register has to match the actual crystal used in design to
 * enable correct behaviour.
 *
 * @param[in] freq enum clock_xtal_freq
 * */
void clock_set_xtal_freq(enum clock_xtal_freq freq)
{
	CLOCK_XTALFREQ = freq;
}
/**@}*/

