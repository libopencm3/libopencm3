/** @addtogroup adc_file

@author @htmlonly &copy; @endhtmlonly
2015 Karl Palsson <karlp@tweak.net.au>

This library supports one style of the Analog to Digital Conversion System in
the STM32 series of ARM Cortex Microcontrollers by ST Microelectronics.

The style of ADC Peripheral supported by this code is found in the F0, L0 and
F30x series devices (at the time of writing)

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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

/**
 * Turn on the ADC (async)
 * @sa adc_wait_power_on
 * @param adc ADC Block register address base @ref adc_reg_base
 */
void adc_power_on_async(uint32_t adc)
{
	ADC_CR(adc) |= ADC_CR_ADEN;
}

/**
 * Is the ADC powered up and ready?
 * @sa adc_power_on_async
 * @param adc ADC Block register address base @ref adc_reg_base
 * @return true if adc is ready for use
 */
bool adc_is_power_on(uint32_t adc)
{
	return (ADC_ISR(adc) & ADC_ISR_ADRDY);
}

/**
 * Turn on the ADC
 * @sa adc_power_on_async
 * @param adc ADC Block register address base @ref adc_reg_base
 */
void adc_power_on(uint32_t adc)
{
	adc_power_on_async(adc);
	while (!adc_is_power_on(adc));
}

/**
 * Turn off the ADC (async)
 * This will actually block if it needs to turn off a currently running
 * conversion, as per ref man. (Handles injected on hardware that supports
 * injected conversions.
 * @sa adc_wait_power_off
 * @param adc ADC Block register address base @ref adc_reg_base
 */
void adc_power_off_async(uint32_t adc)
{
	uint32_t checks = ADC_CR_ADSTART;
	uint32_t stops = ADC_CR_ADSTP;
#if defined (ADC_CR_JADSTART)
	checks |= ADC_CR_JADSTART;
	stops |= ADC_CR_JADSTP;
#endif
	if (ADC_CR(adc) & checks) {
		ADC_CR(adc) |= stops;
		while (ADC_CR(adc) & checks);
	}
	ADC_CR(adc) |= ADC_CR_ADDIS;
}

/**
 * Is the ADC powered down?
 * @sa adc_power_off_async
 * @param adc ADC Block register address base @ref adc_reg_base
 */
bool adc_is_power_off(uint32_t adc)
{
	return (!(ADC_CR(adc) & ADC_CR_ADEN));
}

/**
 * Turn off the ADC
 * This will actually block if it needs to turn off a currently running
 * conversion, as per ref man.
 * @sa adc_power_off_async
 * @param adc ADC Block register address base @ref adc_reg_base
 */
void adc_power_off(uint32_t adc)
{
	adc_power_off_async(adc);
	while (!adc_is_power_off(adc));
}

/**
 * Enable Continuous Conversion Mode
 * In this mode the ADC starts a new conversion of a single channel or a channel
 * group immediately following completion of the previous channel group
 * conversion.
 *
 * @param[in] adc ADC block register address base @ref adc_reg_base
 */
void adc_set_continuous_conversion_mode(uint32_t adc)
{
	ADC_CFGR1(adc) |= ADC_CFGR1_CONT;
}

/**
 * Enable Single Conversion Mode
 * In this mode the ADC performs a conversion of one channel or a channel group
 * and stops.
 *
 * @param[in] adc ADC block register address base @ref adc_reg_base
 */
void adc_set_single_conversion_mode(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_CONT;
}

/**
 * Enable the temperature sensor (only)
 * The channel this is available on is unfortunately not
 * consistent, even though the bit used to enable it is.
 * @sa adc_disable_temperature_sensor
 */
void adc_enable_temperature_sensor(void)
{
	ADC_CCR(ADC1) |= ADC_CCR_TSEN;
}

/**
 * Disable the temperature sensor (only)
 * @sa adc_enable_temperature_sensor
 */
void adc_disable_temperature_sensor(void)
{
	ADC_CCR(ADC1) &= ~ADC_CCR_TSEN;
}

/**
 * Enable the internal voltage reference (only)
 * The channel this is available on is unfortunately not
 * consistent, even though the bit used to enable it is.
 * FIXME - on f3, you can actually have it on ADC34 as well!
 * @sa adc_disable_vrefint
 */
void adc_enable_vrefint(void)
{
	ADC_CCR(ADC1) |= ADC_CCR_VREFEN;
}

/**
 * Disable the internal voltage reference (only)
 * @sa adc_enable_vrefint
 */
void adc_disable_vrefint(void)
{
	ADC_CCR(ADC1) &= ~ADC_CCR_VREFEN;
}
