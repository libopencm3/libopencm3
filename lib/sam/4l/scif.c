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
	SCIF_OSCCTRL0 = mode | SCIF_OSCCTRL_OSCEN |
		(gain << SCIF_OSCCTRL_GAIN_SHIFT) | (startup << SCIF_OSCCTRL_STARTUP_SHIFT);

	while (!(SCIF_PCLKSR & SCIF_OSC0RDY));
	return 0;
}

/** @brief Configure and enable PLL clock.
 *
 * @param[in] delay uint8_t: Specifies the number of RCSYS clock cycles before
 * 	ISR.PLLLOCKn will be set after PLL has been written, or after PLL has
 *	been automatically re-enabled after exiting a sleep mode.
 * @param[in] mul uint8_t: Multiply factor.
 * @param[in] div uint8_t: Division factor.These fields determine the ratio of
 * 	the PLL output frequency to the source oscillator frequency:
 *	f_vco = (PLLMUL+1)/PLLDIV * f_ref if PLLDIV >0
 *	f_vco = 2*(PLLMUL+1) * f_ref if PLLDIV = 0
 *	Note that the PLLMUL field should always be greater than 1 or the
 *	behavior of the PLL will be undefined.
 * @param[in] pll_opt uint8_t: PLL Options.
 * @param[in] pll_opt uint8_t: PLL Options.
 *
 * @returns zero upon success.
 */
int scif_enable_pll(uint8_t delay, uint8_t mul, uint8_t div, uint8_t pll_opt, enum pll_clk_src source_clock)
{
	// First, PLL needs to be disabled, otherwise the configuration register
	// is unaccessible.
	uint32_t pll_val = SCIF_PLL0;
	if (pll_val & SCIF_PLL0_PLLEN) {
		SCIF_UNLOCK = SCIF_PLL0_KEY;
		SCIF_PLL0 = pll_val & (~SCIF_PLL0_PLLEN);
	}

	if (mul == 0)
		mul = 1;

	pll_val = ((source_clock & SCIF_PLL0_PLLOSC_MASK) << SCIF_PLL0_PLLOSC_SHIFT)
		| ((pll_opt & SCIF_PLL0_PLLOPT_MASK) << SCIF_PLL0_PLLOPT_SHIFT)
		| ((div & SCIF_PLL0_PLLDIV_MASK) << SCIF_PLL0_PLLDIV_SHIFT)
		| ((mul & SCIF_PLL0_PLLMUL_MASK) << SCIF_PLL0_PLLMUL_SHIFT)
		| ((delay & SCIF_PLL0_PLLCOUNT_MASK) << SCIF_PLL0_PLLCOUNT_SHIFT);

	SCIF_UNLOCK = SCIF_PLL0_KEY;
	SCIF_PLL0 = pll_val;

	// Now enable TODO: does this really need to be separate operation?
	SCIF_UNLOCK = SCIF_PLL0_KEY;
	SCIF_PLL0 = pll_val | SCIF_PLL0_PLLEN;

	while(!(SCIF_PCLKSR & SCIF_PLL0LOCK));

	return 0;
}
