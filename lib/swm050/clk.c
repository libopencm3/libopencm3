/** @defgroup clk_file Clock peripheral API
 * @ingroup peripheral_apis
 * @brief SWM050 Clock API.
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Caleb Szalacinski <contact@skiboy.net>
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Caleb Szalacinski <contact@skiboy.net>
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
/**@{*/
#include <libopencm3/swm050/clk.h>
#include <libopencm3/swm050/sysctl.h>

/*---------------------------------------------------------------------------*/
/** @brief Setup and change the system clock multiplier and divider

Change system clock speed and wait for the clock to stabilize.  The clock only
needs time to stabilize on the first invocation of this function. This should be
run at startup if you want to have a stable clock before doing anything.

@param[in] mhz Base clock speed @ref clk_speeds
	The base clock speed, before the clock divider

@param[in] div Clock divider
	Takes values from 0 to 1023 (in reality the possible values are the even
	numbers from 2 to 1022, as well as the number 1). Anything more than the
	first 10 bits is stripped off of the value.  If the value is 0, it will
	be treated as a 1.  All odd values other than 1 are rounded down to the
	closest even value, due to the fact that all odd values are treated by
	the register as a 1, which would likely be unexpected. A value of 0
	would also normally be treated as a 2, which would also be unexpected
	behavior.
*/
void clk_speed(enum clk_speeds mhz, uint16_t div)
{
	static bool first_run = true;

	if (first_run) {
		first_run = false;
		clk_speed(CLK_18MHZ, 1);

		for (uint16_t i = 0; i < 10000; ++i) {
			__asm__("nop");
		}

		/* The speed doesn't need to be changed
		   a second time if the user wants 18Mhz. */
		if ((mhz == CLK_18MHZ) && (div <= 1)) {
			return;
		}
		if ((mhz == CLK_36MHZ) && (div == 2)) {
			return;
		}
	}

	if (mhz == CLK_36MHZ) {
		SYSCTL_SYS_DBLF |= BIT0;
	} else {
		SYSCTL_SYS_DBLF &= ~BIT0;
	}

	if (div <= 1) {
		SYSCTL_SYS_CFG_0 |= BIT0;
	} else {
		uint32_t masked_reg32 = SYSCTL_SYS_CFG_0 & CLK_MASK;
		SYSCTL_SYS_CFG_0 = masked_reg32 | (div & ~(CLK_MASK | 0x1));
	}
}
/**@}*/
