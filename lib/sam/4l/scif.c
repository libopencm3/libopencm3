/** @addtogroup scif
 *
 * @brief <b>Access functions for the SAM4 System Controf Interface (SCIF)</b>
 * @ingroup SAM4
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxim@sloyko.com>
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Maxim Sloyko <maxim@sloyko.com>
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

#include <libopencm3/sam/scif.h>

/** @brief Enable external oscillator.
 *
 * @param[in] mode enum osc_mode: Oscillator mode (which pins oscillator connected to).
 * @param[in] freq uint32_t: External Oscillator frequency, in Hertz. Must be 0.6MHz - 30MHz
 * @param[in] startup enum osc_startup: Oscillator start time in RCSYS clock cycles.
 *
 * @returns zero upon success.
 */
int scif_osc_enable(enum osc_mode mode, uint32_t freq, enum osc_startup startup)
{
	uint8_t gain;
#define MHz	*1000000
#define kHz *1000
	if (freq > 600 kHz && freq <= 2 MHz) {
		gain = 0;
	} else if (freq > 2 MHz && freq <= 4 MHz) {
		gain = 1;
	} else if (freq > 4 MHz && freq <= 8 MHz) {
		gain = 2;
	} else if (freq > 8 MHz && freq <= 16 MHz) {
		gain = 3;
	} else if (freq > 16 MHz && freq <= 30 MHz) {
		gain = 4;
	} else {
		return -1;
	}
#undef MHz
#undef kHz

	SCIF_UNLOCK = SCIF_OSCCTRL0_KEY;
	SCIF_OSCCTRL0 = mode | (1 << SCIF_OSCCTRL_OSCEN_SHIFT) |
		(gain << SCIF_OSCCTRL_GAIN_SHIFT) | (startup << SCIF_OSCCTRL_STARTUP_SHIFT);

	while (!(SCIF_PCLKSR & (1 << SCIF_OSC0RDY_SHIFT)));
	return 0;
}
