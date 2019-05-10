/** @addtogroup adc_file ADC peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

@date 30 August 2012

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Ken Sarkies <ksarkies@internode.on.net>
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

#include <libopencm3/stm32/adc.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for a Single Channel

The sampling time can be selected in ADC clock cycles from 1.5 to 239.5.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] channel Unsigned int8. ADC Channel integer 0..18 or from @ref
adc_channel
@param[in] time Unsigned int8. Sampling time selection from @ref adc_sample_rg
 * NOTE Common with f1, f2 and f37x
*/
void adc_set_sample_time(uint32_t adc, uint8_t channel, uint8_t time)
{
	uint32_t reg32;

	if (channel < 10) {
		reg32 = ADC_SMPR2(adc);
		reg32 &= ~(0x7 << (channel * 3));
		reg32 |= (time << (channel * 3));
		ADC_SMPR2(adc) = reg32;
	} else {
		reg32 = ADC_SMPR1(adc);
		reg32 &= ~(0x7 << ((channel - 10) * 3));
		reg32 |= (time << ((channel - 10) * 3));
		ADC_SMPR1(adc) = reg32;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for All Channels

The sampling time can be selected in ADC clock cycles from 1.5 to 239.5, same
for all channels.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] time Unsigned int8. Sampling time selection from @ref adc_sample_rg
 * NOTE Common with f1, f2 and f37x
*/
void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time)
{
	uint8_t i;
	uint32_t reg32 = 0;

	for (i = 0; i <= 9; i++) {
		reg32 |= (time << (i * 3));
	}
	ADC_SMPR2(adc) = reg32;

	for (i = 10; i <= 17; i++) {
		reg32 |= (time << ((i - 10) * 3));
	}
	ADC_SMPR1(adc) = reg32;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Set Dual/Triple Mode

The multiple mode uses ADC1 as master, ADC2 and optionally ADC3 in a slave
arrangement. This setting is applied to ADC1 only.

The various modes possible are described in the reference manual.

@param[in] mode Unsigned int32. Multiple mode selection from @ref adc_multi_mode
*/
void adc_set_multi_mode(uint32_t mode)
{
	ADC_CCR |= mode;
}


/** Enable The VBat Sensor.
 * This enables the battery voltage measurements on ADC1 channel 18. On
 * STM32F42x and STM32F43x, this must be disabled when the temperature sensor
 * is enabled. If both are enabled, only the VBat conversion is performed.
 */
void adc_enable_vbat_sensor(void)
{
	ADC_CCR |= ADC_CCR_VBATE;
}

/** Disable The VBat Sensor.
 * Disabling this will reduce power consumption from the battery voltage
 * measurement.
 */
void adc_disable_vbat_sensor(void)
{
	ADC_CCR &= ~ADC_CCR_VBATE;
}

/**@}*/