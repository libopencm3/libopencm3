/** @addtogroup clk_file Clock peripheral API
 * @ingroup peripheral_apis
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
/** @brief Change the system clock multiplier and divider

Change system clock speed.

@param[in] mhz Base clock speed @ref clk_speed
	     The base clock speed, before the clock divider

@param[in] div Clock divider
	     Takes values from 0 to 1023 (in reality the possible values are the
             even numbers from 2 to 1022, as well as the number 1).
             Anything more than the first 10 bits is
             stripped off of the value.  If the value is 0, it will be treated
             as a 1.  All odd values other than 1 are rounded down to their
             the closest even value, due to the fact that all odd values are
             treated by the register as a 1, which would likely be unexpected.
             A value of 0 would also normally be treated as a 2, which would
             also be unexpected behavior.

@return The current clock value in Hz.

*/
uint32_t clk_speed(bool mhz, uint16_t div)
{
	uint32_t sclk_tmp;
	if (mhz) {
		SYS_DBLF |= BIT0;
		sclk_tmp = M36;
	} else {
		SYS_DBLF &= ~BIT0;
		sclk_tmp = M18;
	}
	
	if (div <= 1) {
		SYS_CFG_0 |= BIT0;
	} else {
		uint32_t div_masked = (div & ~0xFFFFFC01);
		SYS_CFG_0 = (SYS_CFG_0 & 0xFFFFFC00) | div_masked;
		sclk_tmp /= div_masked;
	}

	return sclk_tmp;
}


/*---------------------------------------------------------------------------*/
/** @brief Setup the internal oscillator and system clock

Change system clock speed and wait for the clock to stabilize.
This should be run at startup if you want to have a stable clock before doing
anything 

@param[in] mhz Base clock speed @ref clk_speed
	     Passes value to mhz in @ref clk_setupr

@param[in] div Clock divider
	     Passes value to div in @ref clk_setup

@return The current clock value in Hz.

*/
uint32_t clk_init(bool mhz, uint16_t div)
{
	clk_speed(CLK_18MHZ, 1);

	for (uint16_t i = 0; i < 10000; ++i) {
		__asm__("nop");
	}

	/* clk_speed() doesn't need to be called
	   a second time ifthe user wants 18Mhz. */
	if ((mhz == CLK_18MHZ) && (div <= 1)) {
		return M18;
	}	

	return clk_speed(mhz, div);
}

/* Function should not be used on the SWM050, but can be used
         on other Synwit ARM MCUs that support external oscillators.
	 Disables the internal oscillator. */
/*
void clk_en(bool en)
{
	SYS_CFG_2 = en ? (SYS_CFG_2 & ~BIT0) : (SYS_CFG_2 | BIT0);
}
*/
/**@}*/
