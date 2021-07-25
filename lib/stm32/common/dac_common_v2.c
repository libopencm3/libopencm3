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
		DAC_MCR(dac) &= ~DAC_MCR_MODE1_UNBUFFERED;
		break;
	case DAC_CHANNEL2:
		DAC_MCR(dac) &= ~DAC_MCR_MODE2_UNBUFFERED;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_MCR(dac) &= ~(DAC_MCR_MODE1_UNBUFFERED |
				DAC_MCR_MODE2_UNBUFFERED);
		break;
	default:
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
		DAC_MCR(dac) |= DAC_MCR_MODE1_UNBUFFERED;
		break;
	case DAC_CHANNEL2:
		DAC_MCR(dac) |= DAC_MCR_MODE2_UNBUFFERED;
		break;
	case DAC_CHANNEL_BOTH:
		DAC_MCR(dac) |= (DAC_MCR_MODE1_UNBUFFERED
				| DAC_MCR_MODE2_UNBUFFERED);
		break;
	default:
		break;
	}
}

/** @brief DAC Channel Output Mode.

Each DAC channel can be configured in Normal mode or Sample and hold mode. The
output buffer can be enabled to allow a high drive capability. Before enabling
output buffer, the voltage offset needs to be calibrated. This calibration is
performed at the factory (loaded after reset) and can be adjusted by software
during application operation.

@note This must be called before enabling the DAC as the settings will then
become read-only.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] mode Taken from @ref dac_mode2_sel or @ref dac_mode1_sel or
a logical OR of one of each of these to set both channels simultaneously.
*/
void dac_set_mode(uint32_t dac, uint32_t mode)
{
	DAC_MCR(dac) |= mode;
}

/** @brief Check if DAC channel is ready to receive data.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
bool dac_is_ready(uint32_t dac, int channel)
{
	uint32_t mask = 0;
	if (channel & DAC_CHANNEL1) {
		mask |= DAC_SR_DAC1RDY;
	}
	if (channel & DAC_CHANNEL2) {
		mask |= DAC_SR_DAC2RDY;
	}

	return (DAC_SR(dac) & mask) != 0;
}

/** @brief Wait until DAC channel is ready to receive data.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] channel with DAC mask. @ref dac_channel_id
*/
void dac_wait_on_ready(uint32_t dac, int channel)
{
	while (!dac_is_ready(dac, channel));
}

/** @brief High frequency interface mode selection.

If the AHB frequency of the DAC is above 80MHz then this value needs setting
to an appropriate value.

@param[in] dac the base address of the DAC. @ref dac_reg_base
@param[in] hfsel uint32_t with appropriate HFSEL mask.
*/
void dac_set_high_frequency_mode(uint32_t dac, uint32_t hfsel)
{
	uint32_t reg32 = DAC_MCR(dac);
	reg32 &= ~(DAC_MCR_HFSEL_MASK << DAC_MCR_HFSEL_SHIFT);
	reg32 |= hfsel;
	DAC_MCR(dac) = reg32;
}
/**@}*/

