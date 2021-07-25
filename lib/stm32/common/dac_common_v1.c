/** @addtogroup dac_file DAC peripheral API
 * @ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2020 Ben Brewer <ben.brewer@codethink.co.uk>

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Ben Brewer
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

#include <libopencm3/stm32/dac.h>

/** @brief DAC Channel Output Buffer Enable.

Enable a digital to analog converter channel output drive buffer. This is an
optional amplifying buffer that provides additional drive for the output
signal. The buffer is enabled by default after a reset and needs to be
explicitly disabled if required.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_buffer_enable(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_CR(dac) &= ~DAC_CR_BOFF1;
		break;
	case DAC_CHANNEL2:
		DAC_CR(dac) &= ~DAC_CR_BOFF2;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_CR(dac) &= ~(DAC_CR_BOFF1 | DAC_CR_BOFF2);
		break;
	}
}

/** @brief DAC Channel Output Buffer Disable.

Disable a digital to analog converter channel output drive buffer. Disabling
this will reduce power consumption slightly and will increase the output
impedance of the DAC.  The buffers are enabled by default after a reset.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_buffer_disable(uint32_t dac, int channel)
{
	switch (channel) {
	case DAC_CHANNEL1:
		DAC_CR(dac) |= DAC_CR_BOFF1;
		break;
	case DAC_CHANNEL2:
		DAC_CR(dac) |= DAC_CR_BOFF2;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_CR(dac) |= (DAC_CR_BOFF1 | DAC_CR_BOFF2);
		break;
	}
}
/**@}*/

