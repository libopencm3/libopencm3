/** @defgroup STM32F4xx_adc_file ADC

@ingroup STM32F4xx

@brief <b>libopencm3 STM32F4xx Analog to Digital Converters</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies <ksarkies@internode.on.net>

@date 30 August 2012

This library supports the A/D Converter Control System in the STM32F4xx series
of ARM Cortex Microcontrollers by ST Microelectronics.

Devices can have up to three A/D converters each with their own set of registers.
However all the A/D converters share a common clock which is prescaled from the APB2
clock by default by a minimum factor of 2 to a maximum of 8. The ADC resolution
can be set to 12, 10, 8 or 6 bits.

Each A/D converter has up to 19 channels:
@li On ADC1 the analog channels 16 is internally connected to the temperature
sensor, channel 17 to V<sub>REFINT</sub>, and channel 18 to V<sub>BATT</sub>.
@li On ADC2 and ADC3 the analog channels 16 - 18 are not used.

The conversions can occur as a one-off conversion whereby the process stops once
conversion is complete. The conversions can also be continuous wherein a new
conversion starts immediately the previous conversion has ended.

Conversion can occur as a single channel conversion or a scan of a group of
channels in either continuous or one-off mode. If more than one channel is converted
in a scan group, DMA must be used to transfer the data as there is only one
result register available. An interrupt can be set to occur at the end of
conversion, which occurs after all channels have been scanned.

A discontinuous mode allows a subgroup of group of a channels to be converted in
bursts of a given length.

Injected conversions allow a second group of channels to be converted separately
from the regular group. An interrupt can be set to occur at the end of
conversion, which occurs after all channels have been scanned.

@section adc_api_ex Basic ADC Handling API.

Example 1: Simple single channel conversion polled. Enable the peripheral clock
and ADC, reset ADC and set the prescaler divider. Set dual mode to independent.

@code
    rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_ADC1EN);
    adc_power_on(ADC1);
    adc_calibration(ADC1);
    rcc_peripheral_reset(&RCC_APB2RSTR, RCC_APB2RSTR_ADC1RST);
    rcc_peripheral_clear_reset(&RCC_APB2RSTR, RCC_APB2RSTR_ADC1RST);
    rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV2);
    adc_set_dual_mode(ADC_CR1_DUALMOD_IND);
    adc_disable_scan_mode(ADC1);
    adc_set_single_conversion_mode(ADC1);
    adc_set_sample_time(ADC1, ADC_CHANNEL0, ADC_SMPR1_SMP_1DOT5CYC);
    adc_set_single_channel(ADC1, ADC_CHANNEL0);
    adc_start_conversion_regular(ADC1);
    while (! adc_eoc(ADC1));
    reg16 = adc_read_regular(ADC1);
@endcode

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

#include <libopencm3/stm32/f4/adc.h>

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Clock Prescale
DONE
The ADC clock taken from the APB2 clock can be scaled down by 2, 4, 6 or 8.

@param[in] prescale Unsigned int32. Prescale value for ADC Clock @ref adcf4_ccr_adcpre
*/

void adc_set_clk(u32 prescale)
{
	ADC_CCR = ((ADC_CCR & ~ADC_CCR_ADCPRE_MASK) | prescale);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Dual/Triple Mode

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] reg Unsigned int8. Register number (1 ... 4).
*/

void adc_set_mode(u32 block, /* TODO */ u8 mode)
{
	/* TODO */

	/* FIXME: QUICK HACK to prevent compiler warnings. */
	block = block;
	mode = mode;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Regular Conversions
DONE
The analog watchdog allows the monitoring of an analog signal between two threshold
levels. The thresholds must be preset. Comparison is done before data alignment
takes place, so the thresholds are left-aligned.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_analog_watchdog_regular(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Regular Conversions
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_analog_watchdog_regular(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Injected Conversions
DONE
The analog watchdog allows the monitoring of an analog signal between two threshold
levels. The thresholds must be preset. Comparison is done before data alignment
takes place, so the thresholds are left-aligned.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_analog_watchdog_injected(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JAWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Injected Conversions
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_analog_watchdog_injected(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Regular Conversions
DONE
In this mode the ADC converts, on each trigger, a subgroup of up to 8 of the
defined regular channel group. The subgroup is defined by the number of
consecutive channels to be converted. After a subgroup has been converted
the next trigger will start conversion of the immediately following subgroup
of the same length or until the whole group has all been converted. When the
the whole group has been converted, the next trigger will restart conversion
of the subgroup at the beginning of the whole group.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] length Unsigned int8. Number of channels in the group @ref adcf4_cr1_discnum
*/

void adc_enable_discontinous_mode_regular(u32 adc, u8 length)
{
    if ( length > 8 ) return;
	ADC_CR1(adc) |= ADC_CR1_DISCEN;	
    ADC_CR2(adc) |= ((length+1) << ADC_CR1_DISCNUM_SHIFT);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Regular Conversions
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_discontinous_mode_regular(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_DISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Injected Conversions
DONE
In this mode the ADC converts sequentially one channel of the defined group of
injected channels, cycling back to the first channel in the group once the
entire group has been converted.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_discontinous_mode_injected(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JDISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Injected Conversions
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_discontinous_mode_injected(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JDISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Automatic Injected Conversions
DONE
The ADC converts a defined injected group of channels immediately after the
regular channels have been converted. The external trigger on the injected
channels is disabled as required.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_automatic_injected_group_conversion(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JAUTO;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Automatic Injected Conversions
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_automatic_injected_group_conversion(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAUTO;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for All Regular and/or Injected Channels
DONE
The analog watchdog allows the monitoring of an analog signal between two threshold
levels. The thresholds must be preset. Comparison is done before data alignment
takes place, so the thresholds are left-aligned.

@note The analog watchdog must be enabled for either or both of the regular or
injected channels. If neither are enabled, the analog watchdog feature will be
disabled.
@ref adcf4_enable_analog_watchdog_injected, @ref adcf4_enable_analog_watchdog_regular.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_analog_watchdog_on_all_channels(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDSGL;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for a Selected Channel
DONE
The analog watchdog allows the monitoring of an analog signal between two threshold
levels. The thresholds must be preset. Comparison is done before data alignment
takes place, so the thresholds are left-aligned.

@note The analog watchdog must be enabled for either or both of the regular or
injected channels. If neither are enabled, the analog watchdog feature will be
disabled. If both are enabled, the same channel number is monitored.
@ref adcf4_enable_analog_watchdog_injected, @ref adcf4_enable_analog_watchdog_regular.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] channel Unsigned int8. ADC channel number @ref adcf4_watchdog_channel
*/

void adc_enable_analog_watchdog_on_selected_channel(u32 adc, u8 channel)
{
	u32 reg32;

	reg32 = (ADC_CR1(adc) & ~ADC_CR1_AWDCH_MASK);
	if (channel < 18)
		reg32 |= channel;
	ADC_CR1(adc) = reg32;
	ADC_CR1(adc) |= ADC_CR1_AWDSGL;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Scan Mode
DONE
In this mode a conversion consists of a scan of the predefined set of channels,
regular and injected, each channel conversion immediately following the
previous one. It can use single, continuous or discontinuous mode.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_scan_mode(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_SCAN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Scan Mode
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_scan_mode(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_SCAN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Injected End-Of-Conversion Interrupt
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_jeoc_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JEOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Injected End-Of-Conversion Interrupt
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_jeoc_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JEOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog Interrupt
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_awd_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog Interrupt
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_awd_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Regular End-Of-Conversion Interrupt
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_eoc_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_EOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Regular End-Of-Conversion Interrupt
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_eoc_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_EOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable The Temperature Sensor
DONE
This enables both the sensor and the reference voltage measurements on channels
16 and 17.

*/

void adc_enable_temperature_sensor(void)
{
	ADC_CCR |= ADC_CCR_TSVREFE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable The Temperature Sensor
DONE
Disabling this will reduce power consumption from the sensor and the reference
voltage measurements.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_temperature_sensor(void)
{
	ADC_CCR &= ~ADC_CCR_TSVREFE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Start Conversion on Regular Channels
DONE
This starts conversion on a set of defined regular channels. It is cleared by
hardware once conversion starts.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_start_conversion_regular(u32 adc)
{
	/* Start conversion on regular channels. */
	ADC_CR2(adc) |= ADC_CR2_SWSTART;

	/* Wait until the ADC starts the conversion. */
	while (ADC_CR2(adc) & ADC_CR2_SWSTART);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Software Triggered Conversion on Injected Channels
DONE
This starts conversion on a set of defined injected channels. It is cleared by
hardware once conversion starts.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_start_conversion_injected(u32 adc)
{
	/* Start conversion on injected channels. */
	ADC_CR2(adc) |= ADC_CR2_JSWSTART;

	/* Wait until the ADC starts the conversion. */
	while (ADC_CR2(adc) & ADC_CR2_JSWSTART);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Regular Channels
DONE
This enables an external trigger for set of defined regular channels, and sets the
polarity of the trigger event: rising or falling edge or both.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] trigger Unsigned int32. Trigger identifier @ref adcf4_trigger_regular
@param[in] polarity Unsigned int32. Trigger polarity @ref adcf4_trigger_polarity_regular
*/

void adc_enable_external_trigger_regular(u32 adc, u32 trigger, u32 polarity)
{
	u32 reg32;

	reg32 = (ADC_CR2(adc) & ~(ADC_CR2_EXTSEL_MASK) & ~(ADC_CR2_EXTEN_MASK));
	ADC_CR2(adc) |= (reg32 | trigger | polarity);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Regular Channels
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_external_trigger_regular(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_EXTEN_MASK;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Injected Channels
DONE
This enables an external trigger for set of defined injected channels, and sets the
polarity of the trigger event: rising or falling edge or both.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] trigger Unsigned int8. Trigger identifier @ref adcf4_trigger_injected
@param[in] polarity Unsigned int32. Trigger polarity @ref adcf4_trigger_polarity_injected
*/

void adc_enable_external_trigger_injected(u32 adc, u32 trigger, u32 polarity)
{
	u32 reg32;

	reg32 = (ADC_CR2(adc) & ~(ADC_CR2_JEXTSEL_MASK) & ~(ADC_CR2_JEXTEN_MASK));
	ADC_CR2(adc) |= (reg32 | trigger | polarity);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Injected Channels
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_external_trigger_injected(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_JEXTEN_MASK;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Left Aligned
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_set_left_aligned(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_ALIGN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Right Aligned
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_set_right_aligned(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_ALIGN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable DMA Transfers

DMA transfers are used after each conversion. Overrun is enabled, and conversions
and transfers will abort if overrun occurs.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_dma(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_DMA;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable DMA Transfers
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_dma(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_DMA;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Continuous Conversion Mode
DONE
In this mode the ADC starts a new conversion of a single channel or a channel
group immediately following completion of the previous channel group conversion.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_set_continous_conversion_mode(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_CONT;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Single Conversion Mode
DONE
In this mode the ADC performs a conversion of one channel or a channel group
and stops.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_set_single_conversion_mode(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_CONT;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Power On
DONE
If the ADC is in power-down mode then it is powered up. The application needs
to wait a time of about 3 microseconds for stabilization before using the ADC.
If the ADC is already on this function call will have no effect.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_power_on(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_ADON;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Off

Turn off the ADC to reduce power consumption to a few microamps.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_power_off(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_ADON;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for a Single Channel
DONE
The sampling time can be selected in ADC clock cycles from 1.5 to 239.5.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] channel Unsigned int8. ADC Channel integer 0..18 or from @ref adcf4_channel
@param[in] time Unsigned int8. Sampling time selection from @ref adcf4_sample_rg
*/

void adc_set_sample_time(u32 adc, u8 channel, u8 time)
{
	u32 reg32;

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

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for All Channels
DONE
The sampling time can be selected in ADC clock cycles from 1.5 to 239.5, same for
all channels.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] time Unsigned int8. Sampling time selection from @ref adcf4_sample_rg
*/

void adc_set_sample_time_on_all_channels(u32 adc, u8 time)
{
	u8 i;
	u32 reg32 = 0;

	for (i = 0; i <= 9; i++)
		reg32 |= (time << (i * 3));
	ADC_SMPR2(adc) = reg32;

	for (i = 10; i <= 17; i++)
		reg32 |= (time << ((i - 10) * 3));
	ADC_SMPR1(adc) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Upper Threshold
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] threshold Unsigned int8. Upper threshold value
*/

void adc_set_watchdog_high_threshold(u32 adc, u16 threshold)
{
	u32 reg32 = 0;

	reg32 = (u32)threshold;
	reg32 &= ~0xfffff000; /* Clear all bits above 11. */
	ADC_HTR(adc) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Lower Threshold
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] threshold Unsigned int8. Lower threshold value
*/

void adc_set_watchdog_low_threshold(u32 adc, u16 threshold)
{
	u32 reg32 = 0;

	reg32 = (u32)threshold;
	reg32 &= ~0xfffff000; /* Clear all bits above 11. */
	ADC_LTR(adc) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set a Regular Channel Conversion Sequence
DONE
Define a sequence of channels to be converted as a regular group with a length
from 1 to 16 channels. If this is called during conversion, the current conversion
is reset and conversion begins again with the newly defined group.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] length Unsigned int8. Number of channels in the group 1...16.
@param[in] channel Unsigned int8[]. Set of channels in sequence, integers 0...18.
*/

void adc_set_regular_sequence(u32 adc, u8 length, u8 channel[])
{
	u32 reg32_1 = 0, reg32_2 = 0, reg32_3 = 0;
	u8 i = 0;

	/* Maximum sequence length is 16 channels. */
	if (length > 16)
		return;

	for (i = 1; i <= length; i++) {
		if (i <= 6)
			reg32_3 |= (channel[i - 1] << ((i - 1) * 5));
		if ((i > 6) & (i <= 12))
			reg32_2 |= (channel[i - 1] << ((i - 6 - 1) * 5));
		if ((i > 12) & (i <= 16))
			reg32_1 |= (channel[i - 1] << ((i - 12 - 1) * 5));
	}
	reg32_1 |= ((length -1) << ADC_SQR1_L_LSB);

	ADC_SQR1(adc) = reg32_1;
	ADC_SQR2(adc) = reg32_2;
	ADC_SQR3(adc) = reg32_3;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set an Injected Channel Conversion Sequence
DONE
Defines a sequence of channels to be converted as an injected group with a length
from 1 to 4 channels. If this is called during conversion, the current conversion
is reset and conversion begins again with the newly defined group.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] length Unsigned int8. Number of channels in the group 1...4.
@param[in] channel Unsigned int8[]. Set of channels in sequence, integers 0...18
*/

void adc_set_injected_sequence(u32 adc, u8 length, u8 channel[])
{
	u32 reg32 = 0;
	u8 i = 0;

	/* Maximum sequence length is 4 channels. */
	if ((length-1) > 3)
		return;

	for (i = 1; i <= length; i++)
		reg32 |= (channel[4 - i] << ((4 - i) * 5));

	reg32 |= ((length - 1) << ADC_JSQR_JL_LSB);

	ADC_JSQR(adc) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Resolution
DONE
ADC Resolution can be reduced from 12 bits to 10, 8 or 6 bits for a corresponding
reduction in conversion time (resolution + 3 ADC clock cycles).

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] resolution Unsigned int8. Resolution value @ref adcf4_cr1_res
*/

void adc_set_resolution(u32 adc, u16 resolution)
{
	ADC_CR1(adc) = ((ADC_CR1(adc) & ~ADC_CR1_RES_MASK) | resolution);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable the Overrun Interrupt
DONE
The overrun interrupt is generated when data is not read from a result register
before the next conversion is written. If DMA is enabled, all transfers are
terminated and any conversion sequence is aborted.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_enable_overrun_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_OVRIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable the Overrun Interrupt
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_disable_overrun_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_OVRIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read the Overrun Flag
DONE
The overrun flag is set when data is not read from a result register before the next
conversion is written. If DMA is enabled, all transfers are terminated and any
conversion sequence is aborted.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@returns Unsigned int32 conversion result.
*/

bool adc_get_overrun(u32 adc)
{
	return (ADC_SR(adc) & ADC_SR_OVR);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Conversion Flag
DONE
This flag is set after all channels of a regular or injected group have been
converted, or if the EOC selection bit is set, after each channel conversion.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@returns bool. End of conversion flag.
*/

bool adc_eoc(u32 adc)
{
    return (ADC_SR(adc) & ADC_SR_EOC);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Conversion Flag for Injected Conversion
DONE
This flag is set after all channels of an injected group has been converted.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@returns bool. End of conversion flag.
*/

bool adc_eoc_injected(u32 adc)
{
    return (ADC_SR(adc) & ADC_SR_JEOC);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read the Analog Watchdog Flag
DONE
This flag is set when the converted voltage crosses the high or low thresholds.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@returns bool. AWD flag.
*/

bool adc_awd(u32 adc)
{
    return (ADC_SR(adc) & ADC_SR_AWD);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read from a Regular Conversion Result Register
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@returns Unsigned int32 conversion result.
*/

u32 adc_read_regular(u32 adc)
{
    return ADC_DR(adc);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read from an Injected Conversion Result Register
DONE
@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] reg Unsigned int8. Register number (1 ... 4).
@returns Unsigned int32 conversion result.
*/

u32 adc_read_injected(u32 adc, u8 reg)
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

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable the EOC for Each Conversion
DONE
The EOC is set after each conversion in a sequence rather than at the end of the
sequence. Overrun detection is enabled.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_eoc_after_each(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR2_EOCS;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable the EOC for Each Conversion
DONE
The EOC is set at the end of each sequence rather than after each conversion in the
 sequence. Overrun detection is enabled only if DMA is enabled.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_eoc_after_group(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR2_EOCS;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set DMA Disable Selection

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_set_dma_disable(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR2_DDS;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Clear DMA Disable Selection

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
*/

void adc_clear_dma_disable(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR2_DDS;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Injected Channel Data Offset

This 12-bit value is subtracted from the injected channel results after conversion
is complete, and can result in negative results. A separate value can be specified
for each injected data register.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] reg Unsigned int8. Register number (1 ... 4).
@param[in] offset Unsigned int32.
*/

void adc_set_injected_offset(u32 adc, u8 reg, u32 offset)
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

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set a Single Channel for Conversion
DONE
Define a channel to be converted. This sets up a channel group with only one
channel defined in location 0.

If this is called during a conversion, the conversion is reset and a new
conversion begins.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] channel Unsigned int8. ADC Channel integer 0..18 or from @ref adcf4_channel
*/

void adc_set_single_channel(u32 adc, u8 channel)
{
	ADC_SQR1(adc) = 0;
	ADC_SQR3(adc) = channel;
}
/*-----------------------------------------------------------------------------*/
/** @brief ADC Change a Single Channel in Regular Group
DONE
This can be used to add to or change a regular group of channels by specifying
the location of the channel in the group.

If this is called during a conversion, the conversion is reset and a new
conversion begins.

@param[in] adc Unsigned int32. ADC block register address base @ref adcf4_reg_base
@param[in] channel Unsigned int8. ADC Channel integer 0..18 or from @ref adcf4_channel
@param[in] location Unsigned int8. Position of the channel in a regular group.
*/

void adc_change_single_channel(u32 adc, u8 channel, u8 location)
{
	u32 reg32_1 = 0, reg32_2 = 0, reg32_3 = 0;
    u32 length = ((ADC_SQR1(adc) & ADC_SQR1_L_MSK) >> ADC_SQR1_L_LSB);

	/* Maximum sequence length is 16 channels. */
	if (length > 16)
		return;

	if (location <= 6)
		reg32_3 |= (channel << ((location - 1) * 5));
	if ((location > 6) & (location <= 12))
		reg32_2 |= (channel << ((location - 6 - 1) * 5));
	if ((location > 12) & (location <= 16))
		reg32_1 |= (channel << ((location - 12 - 1) * 5));
	reg32_1 |= ((length -1) << ADC_SQR1_L_LSB);

	ADC_SQR1(adc) = reg32_1;
	ADC_SQR2(adc) = reg32_2;
	ADC_SQR3(adc) = reg32_3;
}

/**@}*/

