/** @addtogroup adc_file

@author @htmlonly &copy; @endhtmlonly
2016 Karl Palsson <karlp@tweak.net.au>

This provides the "multi" extensions to the "v2" ADC peripheral.  This is those
devices that support injected channels and per channel sampling times.
At the time of writing, this is the STM32F30x and the STM32L4x

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/stm32/adc.h>


/** @brief ADC Set the Sample Time for a Single Channel
 *
 * The sampling time can be selected in ADC clock cycles, exact values
 * depend on the device.
 *
 * @param[in] adc ADC block register address base @ref adc_reg_base
 * @param[in] channel ADC Channel integer @ref adc_channel
 * @param[in] time Sampling time selection from @ref adc_sample
 */
void adc_set_sample_time(uint32_t adc, uint8_t channel, uint8_t time)
{
	uint32_t reg32;

	if (channel < 10) {
		reg32 = ADC_SMPR1(adc);
		reg32 &= ~(0x7 << (channel * 3));
		reg32 |= (time << (channel * 3));
		ADC_SMPR1(adc) = reg32;
	} else {
		reg32 = ADC_SMPR2(adc);
		reg32 &= ~(0x7 << ((channel - 10) * 3));
		reg32 |= (time << ((channel - 10) * 3));
		ADC_SMPR2(adc) = reg32;
	}
}

/** @brief ADC Set the Sample Time for All Channels
 *
 * The sampling time can be selected in ADC clock cycles, exact values
 * depend on the device.
 *
 * @param[in] adc ADC block register address base @ref adc_reg_base
 * @param[in] time Sampling time selection from @ref adc_sample
 */
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time)
{
	uint8_t i;
	uint32_t reg32 = 0;

	for (i = 0; i <= 9; i++) {
		reg32 |= (time << (i * 3));
	}
	ADC_SMPR1(adc) = reg32;

	for (i = 10; i <= 17; i++) {
		reg32 |= (time << ((i - 10) * 3));
	}
	ADC_SMPR2(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set a Regular Channel Conversion Sequence
 *
 * Define a sequence of channels to be converted as a regular group with a
 * length from 1 to 16 channels. If this is called during conversion, the
 * current conversion is reset and conversion begins again with the newly
 * defined group.
 *
 * @param[in] adc ADC block register address base @ref adc_reg_base
 * @param[in] length Number of channels in the group, range 0..16
 * @param[in] channel Set of channels in sequence, range @ref adc_channel
 */
void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
	uint32_t reg32_1 = 0, reg32_2 = 0, reg32_3 = 0, reg32_4 = 0;
	uint8_t i = 0;

	/* Maximum sequence length is 16 channels. */
	if (length > 16) {
		return;
	}

	for (i = 1; i <= length; i++) {
		if (i <= 4) {
			reg32_1 |= (channel[i - 1] << (i * 6));
		}
		if ((i > 4) & (i <= 9)) {
			reg32_2 |= (channel[i - 1] << ((i - 4 - 1) * 6));
		}
		if ((i > 9) & (i <= 14)) {
			reg32_3 |= (channel[i - 1] << ((i - 9 - 1) * 6));
		}
		if ((i > 14) & (i <= 16)) {
			reg32_4 |= (channel[i - 1] << ((i - 14 - 1) * 6));
		}
	}
	reg32_1 |= ((length - 1) << ADC_SQR1_L_SHIFT);

	ADC_SQR1(adc) = reg32_1;
	ADC_SQR2(adc) = reg32_2;
	ADC_SQR3(adc) = reg32_3;
	ADC_SQR4(adc) = reg32_4;
}

/**@}*/

