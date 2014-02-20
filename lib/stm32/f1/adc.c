/** @defgroup adc_file ADC

@ingroup STM32F1xx

@brief <b>libopencm3 STM32F1xx Analog to Digital Converters</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Edward Cheeseman <evbuilder@users.sourceforge.net>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

@date 18 August 2012

This library supports the A/D Converter Control System in the STM32F1xx series
of ARM Cortex Microcontrollers by ST Microelectronics.

Devices can have up to three A/D converters each with their own set of
registers.  However all the A/D converters share a common clock which is
prescaled from the APB2 clock by default by a minimum factor of 2 to a maximum
of 8.

Each A/D converter has up to 18 channels:
@li On ADC1 the analog channels 16 and 17 are internally connected to the
temperature
sensor and V<sub>REFINT</sub>, respectively.
@li On ADC2 the analog channels 16 and 17 are internally connected to
V<sub>SS</sub>.
@li On ADC3 the analog channels 9, 14, 15, 16 and 17 are internally connected
to V<sub>SS</sub>.

The conversions can occur as a one-off conversion whereby the process stops
once conversion is complete. The conversions can also be continuous wherein a
new conversion starts immediately the previous conversion has ended.

Conversion can occur as a single channel conversion or a scan of a group of
channels in either continuous or one-off mode. If more than one channel is
converted in a scan group, DMA must be used to transfer the data as there is
only one result register available. An interrupt can be set to occur at the end
of conversion, which occurs after all channels have been scanned.

A discontinuous mode allows a subgroup of group of a channels to be converted
in bursts of a given length.

Injected conversions allow a second group of channels to be converted
separately from the regular group. An interrupt can be set to occur at the end
of conversion, which occurs after all channels have been scanned.

@section adc_api_ex Basic ADC Handling API.

Example 1: Simple single channel conversion polled. Enable the peripheral clock
and ADC, reset ADC and set the prescaler divider. Set dual mode to independent
(default). Enable triggering for a software trigger.

@code
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_ADC1EN);
	adc_off(ADC1);
	rcc_peripheral_reset(&RCC_APB2RSTR, RCC_APB2RSTR_ADC1RST);
	rcc_peripheral_clear_reset(&RCC_APB2RSTR, RCC_APB2RSTR_ADC1RST);
	rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV2);
	adc_set_dual_mode(ADC_CR1_DUALMOD_IND);
	adc_disable_scan_mode(ADC1);
	adc_set_single_conversion_mode(ADC1);
	adc_set_sample_time(ADC1, ADC_CHANNEL0, ADC_SMPR1_SMP_1DOT5CYC);
	adc_set_single_channel(ADC1, ADC_CHANNEL0);
	adc_enable_trigger(ADC1, ADC_CR2_EXTSEL_SWSTART);
	adc_power_on(ADC1);
	adc_reset_calibration(ADC1);
	adc_calibration(ADC1);
	adc_start_conversion_regular(ADC1);
	while (! adc_eoc(ADC1));
	reg16 = adc_read_regular(ADC1);
@endcode

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Edward Cheeseman <evbuilder@users.sourceforge.net>
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

/*
 * Basic ADC handling API.
 *
 * Examples:
 *  rcc_peripheral_enable_clock(&RCC_APB2ENR, ADC1EN);
 *  rcc_peripheral_disable_clock(&RCC_APB2ENR, ADC1EN);
 *  rcc_peripheral_reset(&RCC_APB2RSTR, ADC1RST);
 *  rcc_peripheral_clear_reset(&RCC_APB2RSTR, ADC1RST);
 *
 *  rcc_set_adc_clk(ADC_PRE_PLCK2_DIV2);
 *  adc_set_dual_mode(ADC1, TODO);
 *  reg16 = adc_read(ADC1, ADC_CH_0);
 */

/**@{*/

#include <libopencm3/stm32/adc.h>

/*---------------------------------------------------------------------------*/
/** @brief ADC Power On

If the ADC is in power-down mode then it is powered up. The application needs
to wait a time of about 3 microseconds for stabilization before using the ADC.
If the ADC is already on this function call has no effect.
 * NOTE Common with F37x

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_power_on(uint32_t adc)
{
	if (!(ADC_CR2(adc) & ADC_CR2_ADON)) {
		ADC_CR2(adc) |= ADC_CR2_ADON;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Start a Conversion Without Trigger

This initiates a conversion by software without a trigger. The ADC needs to be
powered on before this is called, otherwise this function has no effect.

Note that this is not available in other STM32F families. To ensure code
compatibility, enable triggering and use a software trigger source @see
adc_start_conversion_regular.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_start_conversion_direct(uint32_t adc)
{
	if (ADC_CR2(adc) & ADC_CR2_ADON) {
		ADC_CR2(adc) |= ADC_CR2_ADON;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Dual A/D Mode

The dual mode uses ADC1 as master and ADC2 in a slave arrangement. This setting
is applied to ADC1 only. Start of conversion when triggered can cause
simultaneous conversion with ADC2, or alternate conversion. Regular and
injected conversions can be configured, each one being separately simultaneous
or alternate.

Fast interleaved mode starts ADC1 immediately on trigger, and ADC2 seven clock
cycles later.

Slow interleaved mode starts ADC1 immediately on trigger, and ADC2 fourteen
clock cycles later, followed by ADC1 fourteen cycles later again. This can only
be used on a single channel.

Alternate trigger mode must occur on an injected channel group, and alternates
between the ADCs on each trigger.

Note that sampling must not overlap between ADCs on the same channel.

Dual A/D converter modes possible:

@li IND: Independent mode.
@li CRSISM: Combined regular simultaneous + injected simultaneous mode.
@li CRSATM: Combined regular simultaneous + alternate trigger mode.
@li CISFIM: Combined injected simultaneous + fast interleaved mode.
@li CISSIM: Combined injected simultaneous + slow interleaved mode.
@li ISM: Injected simultaneous mode only.
@li RSM: Regular simultaneous mode only.
@li FIM: Fast interleaved mode only.
@li SIM: Slow interleaved mode only.
@li ATM: Alternate trigger mode only.

@param[in] mode Unsigned int32. Dual mode selection from @ref adc_cr1_dualmod
*/

void adc_set_dual_mode(uint32_t mode)
{
	ADC1_CR1 |= mode;
}



/*---------------------------------------------------------------------------*/
/** @brief ADC Enable The Temperature Sensor

This enables both the sensor and the reference voltage measurements on channels
16 and 17.

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_enable_temperature_sensor(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_TSVREFE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable The Temperature Sensor

Disabling this will reduce power consumption from the sensor and the reference
voltage measurements.

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_disable_temperature_sensor(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_TSVREFE;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Regular Channels

This enables an external trigger for set of defined regular channels.

For ADC1 and ADC2
@li Timer 1 CC1 event
@li Timer 1 CC2 event
@li Timer 1 CC3 event
@li Timer 2 CC2 event
@li Timer 3 TRGO event
@li Timer 4 CC4 event
@li EXTI (TIM8_TRGO is also possible on some devices, see datasheet)
@li Software Start

For ADC3
@li Timer 3 CC1 event
@li Timer 2 CC3 event
@li Timer 1 CC3 event
@li Timer 8 CC1 event
@li Timer 8 TRGO event
@li Timer 5 CC1 event
@li Timer 5 CC3 event
@li Software Start

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
@param[in] trigger Unsigned int8. Trigger identifier @ref adc_trigger_regular_12
for ADC1 and ADC2, or @ref adc_trigger_regular_3 for ADC3.
*/

void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger)
{
	uint32_t reg32;

	reg32 = (ADC_CR2(adc) & ~(ADC_CR2_EXTSEL_MASK));
	reg32 |= (trigger);
	ADC_CR2(adc) = reg32;
	ADC_CR2(adc) |= ADC_CR2_EXTTRIG;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Regular Channels

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_disable_external_trigger_regular(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_EXTTRIG;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Injected Channels

This enables an external trigger for set of defined injected channels.

For ADC1 and ADC2
@li Timer 1 TRGO event
@li Timer 1 CC4 event
@li Timer 2 TRGO event
@li Timer 2 CC1 event
@li Timer 3 CC4 event
@li Timer 4 TRGO event
@li EXTI (TIM8 CC4 is also possible on some devices, see datasheet)
@li Software Start

For ADC3
@li Timer 1 TRGO event
@li Timer 1 CC4 event
@li Timer 4 CC3 event
@li Timer 8 CC2 event
@li Timer 8 CC4 event
@li Timer 5 TRGO event
@li Timer 5 CC4 event
@li Software Start

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
@param[in] trigger Unsigned int8. Trigger identifier @ref
adc_trigger_injected_12 for ADC1 and ADC2, or @ref adc_trigger_injected_3 for
ADC3.
*/
void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger)
{
	uint32_t reg32;

	reg32 = (ADC_CR2(adc) & ~(ADC_CR2_JEXTSEL_MASK)); /* Clear bits [12:14]
							   */
	reg32 |= (trigger);
	ADC_CR2(adc) = reg32;
	ADC_CR2(adc) |= ADC_CR2_JEXTTRIG;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Injected Channels

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_disable_external_trigger_injected(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_JEXTTRIG;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Initialize Calibration Registers

This resets the calibration registers. It is not clear if this is required to be
done before every calibration operation.

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_reset_calibration(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_RSTCAL;
	while (ADC_CR2(adc) & ADC_CR2_RSTCAL);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Calibration

The calibration data for the ADC is recomputed. The hardware clears the
calibration status flag when calibration is complete. This function does not
return until this happens and the ADC is ready for use.

The ADC must have been powered down for at least 2 ADC clock cycles, then
powered on.  before calibration starts

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_calibration(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_CAL;
	while (ADC_CR2(adc) & ADC_CR2_CAL);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Power On

If the ADC is in power-down mode then it is powered up. The application needs
to wait a time of about 3 microseconds for stabilization before using the ADC.
If the ADC is already on this function call will initiate a conversion.

@deprecated to be removed in a later release

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_on(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_ADON;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for a Single Channel

The sampling time can be selected in ADC clock cycles from 1.5 to 239.5.

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
@param[in] channel Unsigned int8. ADC Channel integer 0..18 or from @ref
adc_channel.
@param[in] time Unsigned int8. Sampling time selection from @ref adc_sample_rg.
 *  * NOTE Common with f2 and f37x and f4
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

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
@param[in] time Unsigned int8. Sampling time selection from @ref adc_sample_rg.
 *  * NOTE Common with f2 and f37x and f4
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

/**@}*/

