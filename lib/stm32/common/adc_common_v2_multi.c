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
