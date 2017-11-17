/** @addtogroup adc_file

@author @htmlonly &copy; @endhtmlonly
2009 Edward Cheeseman <evbuilder@users.sourceforge.net>
@author @htmlonly &copy; @endhtmlonly
2012 Ken Sarkies <ksarkies@internode.on.net>
@author @htmlonly &copy; @endhtmlonly
2014 Karl Palsson <karlp@tweak.net.au>

This library supports one style of the Analog to Digital Conversion System in
the STM32 series of ARM Cortex Microcontrollers by ST Microelectronics.

The style of ADC Peripheral supported by this code is found in the F1, F2,
F37x, F38x, F4, and L1 series devices (at the time of writing) but is quite
different to the style found on the F0 and F30x and F31x.
Devices can have up to three A/D converters each with their own set of
registers.
However all the A/D converters share a common clock.  On most devices, this is
prescaled from the APB2 clock by default by a minimum factor of 2 to a maximum
of 8, though on the L1 this is always a divider from the HSI. (And therefore HSI
_must_ be enabled before attempting to enable the ADC)

Each A/D converter has up to ADC_MAX_CHANNELS channels:
@li On ADC1 the analog channels 16 and 17 are internally connected to the
temperature sensor and V<sub>REFINT</sub>, respectively.
@li On ADC2 (if available) the analog channels 16 and 17 are internally
connected to V<sub>SS</sub>.
@li On ADC3 (if available) the analog channels 9, 14, 15, 16 and 17 are
internally connected to V<sub>SS</sub>.

The conversions can occur as a one-off conversion whereby the process stops once
conversion is complete. The conversions can also be continuous wherein a new
conversion starts immediately the previous conversion has ended.

Conversion can occur as a single channel conversion or a scan of a group of
channels in either continuous or one-off mode. If more than one channel is
converted in a scan group, DMA must be used to transfer the data as there is
only one result register available. An interrupt can be set to occur at the end
of conversion, which occurs after all channels have been scanned.

A discontinuous mode allows a subgroup of group of a channels to be converted in
bursts of a given length.

Injected conversions allow a second group of channels to be converted separately
from the regular group. An interrupt can be set to occur at the end of
conversion, which occurs after all channels have been scanned.

@section adc_api_ex Basic ADC Handling API.

Example 1: Simple single channel conversion polled. Enable the peripheral clock
and ADC, reset ADC and set the prescaler divider. Set dual mode to independent
(default). Enable triggering for a software trigger.

@code
    rcc_periph_clock_enable(RCC_ADC1);
    adc_power_off(ADC1);
    rcc_periph_reset_pulse(RST_ADC1);
    rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV2);
    adc_set_dual_mode(ADC_CR1_DUALMOD_IND);
    adc_disable_scan_mode(ADC1);
    adc_set_single_conversion_mode(ADC1);
    adc_set_sample_time(ADC1, ADC_CHANNEL0, ADC_SMPR1_SMP_1DOT5CYC);
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
 * Copyright (C) 2014 Karl Palsson <karlp@tweak.net.au>
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

/*---------------------------------------------------------------------------*/
/** @brief ADC Off

Turn off the ADC to reduce power consumption to a few microamps.

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_power_off(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_ADON;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Regular Conversions

The analog watchdog allows the monitoring of an analog signal between two
threshold levels. The thresholds must be preset.

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_enable_analog_watchdog_regular(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Regular Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_disable_analog_watchdog_regular(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Injected Conversions

The analog watchdog allows the monitoring of an analog signal between two
threshold levels. The thresholds must be preset. Comparison is done before data
alignment takes place, so the thresholds are left-aligned.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_analog_watchdog_injected(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_JAWDEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Injected Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_analog_watchdog_injected(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAWDEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Regular Conversions

In this mode the ADC converts, on each trigger, a subgroup of up to 8 of the
defined regular channel group. The subgroup is defined by the number of
consecutive channels to be converted. After a subgroup has been converted
the next trigger will start conversion of the immediately following subgroup
of the same length or until the whole group has all been converted. When the
the whole group has been converted, the next trigger will restart conversion
of the subgroup at the beginning of the whole group.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] length Unsigned int8. Number of channels in the group @ref
adc_cr1_discnum
*/

void adc_enable_discontinuous_mode_regular(uint32_t adc, uint8_t length)
{
	if ((length-1) > 7) {
		return;
	}
	ADC_CR1(adc) |= ADC_CR1_DISCEN;
	ADC_CR1(adc) |= ((length-1) << ADC_CR1_DISCNUM_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Regular Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_discontinuous_mode_regular(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_DISCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Injected Conversions

In this mode the ADC converts sequentially one channel of the defined group of
injected channels, cycling back to the first channel in the group once the
entire group has been converted.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_discontinuous_mode_injected(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_JDISCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Injected Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_discontinuous_mode_injected(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JDISCEN;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Automatic Injected Conversions

The ADC converts a defined injected group of channels immediately after the
regular channels have been converted. The external trigger on the injected
channels is disabled as required.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_automatic_injected_group_conversion(uint32_t adc)
{
	adc_disable_external_trigger_injected(adc);
	ADC_CR1(adc) |= ADC_CR1_JAUTO;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Automatic Injected Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_automatic_injected_group_conversion(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAUTO;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for All Regular and/or Injected Channels

The analog watchdog allows the monitoring of an analog signal between two
threshold levels. The thresholds must be preset. Comparison is done before data
alignment takes place, so the thresholds are left-aligned.

@note The analog watchdog must be enabled for either or both of the regular or
injected channels. If neither are enabled, the analog watchdog feature will be
disabled.
@ref adc_enable_analog_watchdog_injected, @ref
adc_enable_analog_watchdog_regular.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_analog_watchdog_on_all_channels(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDSGL;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for a Selected Channel

The analog watchdog allows the monitoring of an analog signal between two
threshold levels. The thresholds must be preset. Comparison is done before data
alignment takes place, so the thresholds are left-aligned.

@note The analog watchdog must be enabled for either or both of the regular or
injected channels. If neither are enabled, the analog watchdog feature will be
disabled. If both are enabled, the same channel number is monitored.
@ref adc_enable_analog_watchdog_injected, @ref
adc_enable_analog_watchdog_regular.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] channel Unsigned int8. ADC channel number @ref adc_watchdog_channel
*/

void adc_enable_analog_watchdog_on_selected_channel(uint32_t adc,
						    uint8_t channel)
{
	uint32_t reg32;

	reg32 = (ADC_CR1(adc) & ~ADC_CR1_AWDCH_MASK); /* Clear bits [4:0]. */
	if (channel <= ADC_CR1_AWDCH_MAX) {
		reg32 |= channel;
	}
	ADC_CR1(adc) = reg32;
	ADC_CR1(adc) |= ADC_CR1_AWDSGL;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Scan Mode

In this mode a conversion consists of a scan of the predefined set of channels,
regular and injected, each channel conversion immediately following the
previous one. It can use single, continuous or discontinuous mode.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_scan_mode(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_SCAN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Scan Mode

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_scan_mode(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_SCAN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Injected End-Of-Conversion Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_eoc_interrupt_injected(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_JEOCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Injected End-Of-Conversion Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_eoc_interrupt_injected(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JEOCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_awd_interrupt(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_awd_interrupt(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDIE;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Regular End-Of-Conversion Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_eoc_interrupt(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_EOCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Regular End-Of-Conversion Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_eoc_interrupt(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_EOCIE;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Left Aligned

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_set_left_aligned(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_ALIGN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Right Aligned

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_set_right_aligned(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_ALIGN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Conversion Flag

This flag is set after all channels of a regular or injected group have been
converted.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@returns bool. End of conversion flag.
*/

bool adc_eoc(uint32_t adc)
{
	return (ADC_SR(adc) & ADC_SR_EOC) != 0;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Conversion Flag for Injected Conversion

This flag is set after all channels of an injected group have been converted.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@returns bool. End of conversion flag.
*/

bool adc_eoc_injected(uint32_t adc)
{
	return (ADC_SR(adc) & ADC_SR_JEOC) != 0;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read from the Regular Conversion Result Register

The result read back is 12 bits, right or left aligned within the first 16 bits.
For ADC1 only, the higher 16 bits will hold the result from ADC2 if
an appropriate dual mode has been set @see adc_set_dual_mode.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@returns Unsigned int32 conversion result.
*/

uint32_t adc_read_regular(uint32_t adc)
{
	return ADC_DR(adc);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read from an Injected Conversion Result Register

The result read back from the selected injected result register (one of four)
is 12 bits, right or left aligned within the first 16 bits. The result can have
a negative value if the injected channel offset has been set @see
adc_set_injected_offset.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] reg Unsigned int8. Register number (1 ... 4).
@returns Unsigned int32 conversion result.
*/

uint32_t adc_read_injected(uint32_t adc, uint8_t reg)
{
	switch (reg) {
	case 1:
		return ADC_JDR1(adc);
	case 2:
		return ADC_JDR2(adc);
	case 3:
		return ADC_JDR3(adc);
	case 4:
		return ADC_JDR4(adc);
	}
	return 0;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Continuous Conversion Mode

In this mode the ADC starts a new conversion of a single channel or a channel
group immediately following completion of the previous channel group conversion.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_set_continuous_conversion_mode(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_CONT;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Single Conversion Mode

In this mode the ADC performs a conversion of one channel or a channel group
and stops.

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_set_single_conversion_mode(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_CONT;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Upper Threshold

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] threshold Upper threshold value, 12bit right aligned.
*/

void adc_set_watchdog_high_threshold(uint32_t adc, uint16_t threshold)
{
	uint32_t reg32 = 0;

	reg32 = (uint32_t)threshold;
	reg32 &= ADC_HT_MSK;
	ADC_HTR(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Lower Threshold

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] threshold Lower threshold value, 12bit right aligned.
*/

void adc_set_watchdog_low_threshold(uint32_t adc, uint16_t threshold)
{
	uint32_t reg32 = 0;

	reg32 = (uint32_t)threshold;
	reg32 &= ADC_LT_MSK;
	ADC_LTR(adc) = reg32;
}

/*---------------------------------------------------------------------------*/

/** @brief ADC Set a Regular Channel Conversion Sequence

Define a sequence of channels to be converted as a regular group with a length
from 1 to ADC_REGULAR_SEQUENCE_MAX channels. If this is called during
conversion, the current conversion is reset and conversion begins again with
the newly defined group.

@param[in] adc Unsigned int32. ADC block base address @ref adc_reg_base.
@param[in] length Unsigned int8. Number of channels in the group.
@param[in] channel Unsigned int8[]. Set of channels in sequence, integers 0..31.
 */

void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
	uint32_t fifth6 = 0;
	uint32_t fourth6 = 0;
	uint32_t third6 = 0;
	uint32_t second6 = 0;
	uint32_t first6 = 0;
	uint8_t i = 0;

	if (length > ADC_SQR_MAX_CHANNELS_REGULAR) {
		return;
	}

	for (i = 1; i <= length; i++) {
		if (i <= 6) {
			first6 |= (channel[i - 1] << ((i - 1) * 5));
		}
		if ((i > 6) & (i <= 12)) {
			second6 |= (channel[i - 1] << ((i - 6 - 1) * 5));
		}
		if ((i > 12) & (i <= 18)) {
			third6 |= (channel[i - 1] << ((i - 12 - 1) * 5));
		}
		if ((i > 18) & (i <= 24)) {
			fourth6 |= (channel[i - 1] << ((i - 18 - 1) * 5));
		}
		if ((i > 24) & (i <= 28)) {
			fifth6 |= (channel[i - 1] << ((i - 24 - 1) * 5));
		}
	}
#if defined(ADC_SQR5)
	ADC_SQR1(adc) = fifth6 | ((length - 1) << ADC_SQR1_L_LSB);
	ADC_SQR2(adc) = fourth6;
	ADC_SQR3(adc) = third6;
	ADC_SQR4(adc) = second6;
	ADC_SQR5(adc) = first6;
#else
	ADC_SQR1(adc) = third6 | ((length - 1) << ADC_SQR1_L_LSB);
	ADC_SQR2(adc) = second6;
	ADC_SQR3(adc) = first6;
#endif
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Set an Injected Channel Conversion Sequence

Defines a sequence of channels to be converted as an injected group with a
length from 1 to 4 channels. If this is called during conversion, the current
conversion is reset and conversion begins again with the newly defined group.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] length Unsigned int8. Number of channels in the group.
@param[in] channel Unsigned int8[]. Set of channels in sequence, integers 0..18
*/

void adc_set_injected_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
	uint32_t reg32 = 0;
	uint8_t i = 0;

	/* Maximum sequence length is 4 channels. Minimum sequence is 1.*/
	if ((length - 1) > 3) {
		return;
	}

	for (i = 0; i < length; i++) {
		reg32 |= ADC_JSQR_JSQ_VAL(4 - i, channel[length - i - 1]);
	}

	reg32 |= ADC_JSQR_JL_VAL(length);

	ADC_JSQR(adc) = reg32;
}


/*----------------------------------------------------------------------------*/
/** @brief ADC Set the Injected Channel Data Offset

This value is subtracted from the injected channel results after conversion is
complete, and can result in negative results. A separate value can be specified
for each injected data register.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] reg Unsigned int8. Register number (1 ... 4).
@param[in] offset Unsigned int32.
*/

void adc_set_injected_offset(uint32_t adc, uint8_t reg, uint32_t offset)
{
	switch (reg) {
	case 1:
		ADC_JOFR1(adc) = offset;
		break;
	case 2:
		ADC_JOFR2(adc) = offset;
		break;
	case 3:
		ADC_JOFR3(adc) = offset;
		break;
	case 4:
		ADC_JOFR4(adc) = offset;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Software Triggered Conversion on Regular Channels

This starts conversion on a set of defined regular channels if the ADC trigger
is set to be a software trigger. It is cleared by hardware once conversion
starts.

Special F1 Note this is a software trigger and requires triggering to be
enabled and the trigger source to be set appropriately otherwise conversion
will not start. This is not the same as the ADC start conversion operation.

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_start_conversion_regular(uint32_t adc)
{
	/* Start conversion on regular channels. */
	ADC_CR2(adc) |= ADC_CR2_SWSTART;

	/* Wait until the ADC starts the conversion. */
	while (ADC_CR2(adc) & ADC_CR2_SWSTART);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Software Triggered Conversion on Injected Channels

This starts conversion on a set of defined injected channels if the ADC trigger
is set to be a software trigger. It is cleared by hardware once conversion
starts.

Special F1 Note this is a software trigger and requires triggering to be
enabled and the trigger source to be set appropriately otherwise conversion
will not start. This is not the same as the ADC start conversion operation.

@param[in] adc Unsigned int32. ADC block register address base @ref
adc_reg_base.
*/

void adc_start_conversion_injected(uint32_t adc)
{
	/* Start conversion on injected channels. */
	ADC_CR2(adc) |= ADC_CR2_JSWSTART;

	/* Wait until the ADC starts the conversion. */
	while (ADC_CR2(adc) & ADC_CR2_JSWSTART);
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Enable DMA Transfers

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_dma(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_DMA;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable DMA Transfers

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_dma(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_DMA;
}



/**@}*/
