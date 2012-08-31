/** @defgroup STM32F1xx_adc_file ADC

@ingroup STM32F1xx

@brief <b>libopencm3 STM32F1xx Analog to Digital Converters</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009 Edward Cheeseman <evbuilder@users.sourceforge.net>
@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies <ksarkies@internode.on.net>

@date 18 August 2012

This library supports the A/D Converter Control System in the STM32F1xx series
of ARM Cortex Microcontrollers by ST Microelectronics.

Devices can have up to three A/D converters each with their own set of registers.
However all the A/D converters share a common clock which is prescaled from the APB2
clock by default by a minimum factor of 2 to a maximum of 8.

Each A/D converter has up to 18 channels:
@li On ADC1 the analog channels 16 and 17 are internally connected to the temperature
sensor and V<sub>REFINT</sub>, respectively.
@li On ADC2 the analog channels 16 and 17 are internally connected to V<sub>SS</sub>.
@li On ADC3 the analog channels 9, 14, 15, 16 and 17 are internally connected to V<sub>SS</sub>.

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

#include <libopencm3/stm32/f1/adc.h>

void rcc_set_adc_clk(u32 prescaler)
{
	/* TODO */

	/* FIXME: QUICK HACK to prevent compiler warnings. */
	prescaler = prescaler;
}

void adc_set_mode(u32 block, /* TODO */ u8 mode)
{
	/* TODO */

	/* FIXME: QUICK HACK to prevent compiler warnings. */
	block = block;
	mode = mode;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Read from a Conversion Result Register

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] reg Unsigned int8. Register number (1 ... 4).
@returns Unsigned int32 conversion result.
*/

void adc_read(u32 block, u32 channel)
{
	/* TODO */

	/* FIXME: QUICK HACK to prevent compiler warnings. */
	block = block;
	channel = channel;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Regular Conversions

The analog watchdog allows the monitoring of an analog signal between two threshold
levels. The thresholds must be preset. Comparison is done before data alignment
takes place, so the thresholds are left-aligned.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_analog_watchdog_regular(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Regular Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_analog_watchdog_regular(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Injected Conversions

The analog watchdog allows the monitoring of an analog signal between two threshold
levels. The thresholds must be preset. Comparison is done before data alignment
takes place, so the thresholds are left-aligned.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_analog_watchdog_injected(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JAWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Injected Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_analog_watchdog_injected(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAWDEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Regular Conversions

In this mode the ADC converts, on each trigger, a subgroup of up to 8 of the
defined regular channel group. The subgroup is defined by the number of
consecutive channels to be converted. After a subgroup has been converted
the next trigger will start conversion of the immediately following subgroup
of the same length or until the whole group has all been converted. When the
the whole group has been converted, the next trigger will restart conversion
of the subgroup at the beginning of the whole group.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] length Unsigned int8. Number of channels in the group @ref adc_cr1_discnum
*/

void adc_enable_discontinous_mode_regular(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_DISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Regular Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_discontinous_mode_regular(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_DISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Injected Conversions

In this mode the ADC converts sequentially one channel of the defined group of
injected channels, cycling back to the first channel in the group once the
entire group has been converted.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_discontinous_mode_injected(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JDISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Injected Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_discontinous_mode_injected(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JDISCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Automatic Injected Conversions

The ADC converts a defined injected group of channels immediately after the
regular channels have been converted. The external trigger on the injected
channels is disabled as required.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_automatic_injected_group_conversion(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JAUTO;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Automatic Injected Conversions

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_automatic_injected_group_conversion(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAUTO;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for All Regular and/or Injected Channels

The analog watchdog allows the monitoring of an analog signal between two threshold
levels. The thresholds must be preset. Comparison is done before data alignment
takes place, so the thresholds are left-aligned.

@note The analog watchdog must be enabled for either or both of the regular or
injected channels. If neither are enabled, the analog watchdog feature will be
disabled.
@ref adc_enable_analog_watchdog_injected, @ref adc_enable_analog_watchdog_regular.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_analog_watchdog_on_all_channels(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDSGL;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for a Selected Channel

The analog watchdog allows the monitoring of an analog signal between two threshold
levels. The thresholds must be preset. Comparison is done before data alignment
takes place, so the thresholds are left-aligned.

@note The analog watchdog must be enabled for either or both of the regular or
injected channels. If neither are enabled, the analog watchdog feature will be
disabled. If both are enabled, the same channel number is monitored.
@ref adc_enable_analog_watchdog_injected, @ref adc_enable_analog_watchdog_regular.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] channel Unsigned int8. ADC channel number @ref adc_watchdog_channel
*/

void adc_enable_analog_watchdog_on_selected_channel(u32 adc, u8 channel)
{
	u32 reg32;

	reg32 = (ADC_CR1(adc) & 0xffffffe0); /* Clear bits [4:0]. */
	if (channel < 18)
		reg32 |= channel;
	ADC_CR1(adc) = reg32;
	ADC_CR1(adc) &= ~ADC_CR1_AWDSGL;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set Scan Mode

In this mode a conversion consists of a scan of the predefined set of channels,
regular and injected, each channel conversion immediately following the
previous one. It can use single, continuous or discontinuous mode.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_scan_mode(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_SCAN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Scan Mode

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_scan_mode(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_SCAN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Injected End-Of-Conversion Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_jeoc_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JEOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Injected End-Of-Conversion Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_jeoc_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JEOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_awd_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_awd_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Regular End-Of-Conversion Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_eoc_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_EOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable Regular End-Of-Conversion Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_eoc_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_EOCIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable The Temperature Sensor

This enables both the sensor and the reference voltage measurements on channels
16 and 17.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_temperature_sensor(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_TSVREFE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable The Temperature Sensor

Disabling this will reduce power consumption from the sensor and the reference
voltage measurements.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_temperature_sensor(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_TSVREFE;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Software Triggered Conversion on Regular Channels

This starts conversion on a set of defined regular channels if the ADC trigger
is set to be a software trigger. It is cleared by hardware once conversion
starts.

Note this is a software trigger and requires triggering to be enabled and the
trigger source to be set appropriately otherwise conversion will not start.
This is not the same as the ADC start conversion operation.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
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

This starts conversion on a set of defined injected channels if the ADC trigger
is set to be a software trigger. It is cleared by hardware once conversion
starts.

Note this is a software trigger and requires triggering to be enabled and the
trigger source to be set appropriately otherwise conversion will not start.
This is not the same as the ADC start conversion operation.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
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

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] trigger Unsigned int8. Trigger identifier @ref adc_trigger_regular_12
for ADC1 and ADC2, or @ref adc_trigger_regular_3 for ADC3
*/

void adc_enable_external_trigger_regular(u32 adc, u32 trigger)
{
	u32 reg32;

	reg32 = (ADC_CR2(adc) & ~(ADC_CR2_EXTSEL_MASK));
	if (trigger < 8)
		reg32 |= (trigger);
	ADC_CR2(adc) = reg32;
	ADC_CR2(adc) |= ADC_CR2_EXTTRIG;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Regular Channels

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_external_trigger_regular(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_EXTTRIG;
}

/*-----------------------------------------------------------------------------*/
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

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] trigger Unsigned int8. Trigger identifier @ref adc_trigger_injected_12
for ADC1 and ADC2, or @ref adc_trigger_injected_3 for ADC3
*/

void adc_enable_external_trigger_injected(u32 adc, u32 trigger)
{
	u32 reg32;

	reg32 = (ADC_CR2(adc) & ~(ADC_CR2_JEXTSEL_MASK)); /* Clear bits [12:14]. */
	if (trigger < 8)
		reg32 |= (trigger);
	ADC_CR2(adc) = reg32;
	ADC_CR2(adc) |= ADC_CR2_JEXTTRIG;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Injected Channels

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_external_trigger_injected(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_JEXTTRIG;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Left Aligned

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_set_left_aligned(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_ALIGN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Right Aligned

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_set_right_aligned(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_ALIGN;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable DMA Transfers

Only available for ADC1 through DMA1 channel1, and ADC3 through DMA2 channel5.
ADC2 will use DMA if it is set as slave in dual mode with ADC1 in DMA transfer
mode.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_dma(u32 adc)
{
	if ((adc == ADC1) | (adc == ADC3))
		ADC_CR2(adc) |= ADC_CR2_DMA;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Disable DMA Transfers

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_dma(u32 adc)
{
	if ((adc == ADC1) | (adc == ADC3))
		ADC_CR2(adc) &= ~ADC_CR2_DMA;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Initialize Calibration Registers

This resets the calibration registers. It is not clear if this is required to be
done before every calibration operation.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_reset_calibration(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_RSTCAL;
	while (ADC_CR2(adc) & ADC_CR2_RSTCAL);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Calibration

The calibration data for the ADC is recomputed. The hardware clears the
calibration status flag when calibration is complete. This function does not return
until this happens and the ADC is ready for use.

The ADC must have been powered down for at least 2 ADC clock cycles, then powered on.
before calibration starts

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_calibration(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_CAL;
	while (ADC_CR2(adc) & ADC_CR2_CAL);
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Continuous Conversion Mode

In this mode the ADC starts a new conversion of a single channel or a channel
group immediately following completion of the previous channel group conversion.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_set_continous_conversion_mode(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_CONT;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Enable Single Conversion Mode

In this mode the ADC performs a conversion of one channel or a channel group
and stops.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_set_single_conversion_mode(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_CONT;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Power On

If the ADC is in power-down mode then it is powered up. The application needs
to wait a time of about 3 microseconds for stabilization before using the ADC.
If the ADC is already on this function call will initiate a conversion.

@todo fix this.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_on(u32 adc)
{
	ADC_CR2(adc) |= ADC_CR2_ADON;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Off

Turn off the ADC to reduce power consumption to a few microamps.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_off(u32 adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_ADON;
}

/*-----------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for a Single Channel

The sampling time can be selected in ADC clock cycles from 1.5 to 239.5.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] channel Unsigned int8. ADC Channel integer 0..18 or from @ref adc_channel
@param[in] time Unsigned int8. Sampling time selection from @ref adc_sample_rg
*/

void adc_set_conversion_time(u32 adc, u8 channel, u8 time)
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

The sampling time can be selected in ADC clock cycles from 1.5 to 239.5, same for
all channels.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] time Unsigned int8. Sampling time selection from @ref adc_sample_rg
*/

void adc_set_conversion_time_on_all_channels(u32 adc, u8 time)
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

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
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

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
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

Define a sequence of channels to be converted as a regular group with a length
from 1 to 16 channels. If this is called during conversion, the current conversion
is reset and conversion begins again with the newly defined group.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] length Unsigned int8. Number of channels in the group.
@param[in] channel Unsigned int8[]. Set of channels in sequence, integers 0..18.
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

Defines a sequence of channels to be converted as an injected group with a length
from 1 to 4 channels. If this is called during conversion, the current conversion
is reset and conversion begins again with the newly defined group.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] length Unsigned int8. Number of channels in the group.
@param[in] channel Unsigned int8[]. Set of channels in sequence, integers 0..18
*/

void adc_set_injected_sequence(u32 adc, u8 length, u8 channel[])
{
	u32 reg32 = 0;
	u8 i = 0;

	/* Maximum sequence length is 4 channels. */
	if (length > 4)
		return;

	for (i = 1; i <= length; i++)
		reg32 |= (channel[i - 1] << ((i - 1) * 5));

	reg32 |= ((length - 1) << ADC_JSQR_JL_LSB);

	ADC_JSQR(adc) = reg32;
}

/**@}*/

