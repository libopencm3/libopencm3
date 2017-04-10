/** @addtogroup adc_file ADC peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

@date 30 August 2012

This library supports the A/D Converter Control System in the STM32 series
of ARM Cortex Microcontrollers by ST Microelectronics.

Devices can have up to three A/D converters each with their own set of
registers.  However all the A/D converters share a common clock which is
prescaled from the APB2 clock by default by a minimum factor of 2 to a maximum
of 8. The ADC resolution can be set to 12, 10, 8 or 6 bits.

Each A/D converter has up to 19 channels:
@li On ADC1 the analog channels 16 is internally connected to the temperature
sensor, channel 17 to V<sub>REFINT</sub>, and channel 18 to V<sub>BAT</sub>.
@li On ADC2 and ADC3 the analog channels 16 - 18 are not used.

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

@section adc_f4_api_ex Basic ADC Handling API.

Example 1: Simple single channel conversion polled. Enable the peripheral clock
and ADC, reset ADC and set the prescaler divider. Set the sample time to a
minimum of 3 cycles. Set multiple mode to independent.

@code
gpio_mode_setup(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO1);
rcc_periph_clock_enable(RCC_ADC1);
adc_set_clk_prescale(ADC_CCR_ADCPRE_BY2);
adc_disable_scan_mode(ADC1);
adc_set_single_conversion_mode(ADC1);
adc_set_sample_time(ADC1, ADC_CHANNEL0, ADC_SMPR_SMP_3CYC);
uint8_t channels[] = ADC_CHANNEL0;
adc_set_regular_sequence(ADC1, 1, channels);
adc_set_multi_mode(ADC_CCR_MULTI_INDEPENDENT);
adc_power_on(ADC1);
adc_start_conversion_regular(ADC1);
while (!adc_eoc(ADC1));
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
/** @brief ADC Power On

If the ADC is in power-down mode then it is powered up. The application needs
to wait a time of about 3 microseconds for stabilization before using the ADC.
If the ADC is already on this function call will have no effect.
 * NOTE Common with L1 and F2

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_power_on(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_ADON;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Clock Prescale

The ADC clock taken from the APB2 clock can be scaled down by 2, 4, 6 or 8.

@param[in] prescale Unsigned int32. Prescale value for ADC Clock @ref
adc_ccr_adcpre
*/

void adc_set_clk_prescale(uint32_t prescale)
{
	uint32_t reg32 = ((ADC_CCR & ~ADC_CCR_ADCPRE_MASK) | prescale);
	ADC_CCR = reg32;
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

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Regular Channels

This enables an external trigger for set of defined regular channels, and sets
the polarity of the trigger event: rising or falling edge or both. Note that if
the trigger polarity is zero, triggering is disabled.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] trigger Unsigned int32. Trigger identifier @ref adc_trigger_regular
@param[in] polarity Unsigned int32. Trigger polarity @ref
adc_trigger_polarity_regular
*/

void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
					 uint32_t polarity)
{
	uint32_t reg32 = ADC_CR2(adc);

	reg32 &= ~(ADC_CR2_EXTSEL_MASK | ADC_CR2_EXTEN_MASK);
	reg32 |= (trigger | polarity);
	ADC_CR2(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Regular Channels

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_external_trigger_regular(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_EXTEN_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Injected Channels

This enables an external trigger for set of defined injected channels, and sets
the polarity of the trigger event: rising or falling edge or both.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] trigger Unsigned int8. Trigger identifier @ref adc_trigger_injected
@param[in] polarity Unsigned int32. Trigger polarity @ref
adc_trigger_polarity_injected
*/

void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger,
					  uint32_t polarity)
{
	uint32_t reg32 = ADC_CR2(adc);

	reg32 &= ~(ADC_CR2_JEXTSEL_MASK | ADC_CR2_JEXTEN_MASK);
	reg32 |= (trigger | polarity);
	ADC_CR2(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Injected Channels

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_external_trigger_injected(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_JEXTEN_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Resolution

ADC Resolution can be reduced from 12 bits to 10, 8 or 6 bits for a
corresponding reduction in conversion time (resolution + 3 ADC clock cycles).

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@param[in] resolution Unsigned int32. Resolution value @ref adc_cr1_res
*/

void adc_set_resolution(uint32_t adc, uint32_t resolution)
{
	uint32_t reg32 = ADC_CR1(adc);

	reg32 &= ~ADC_CR1_RES_MASK;
	reg32 |= resolution;
	ADC_CR1(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable the Overrun Interrupt

The overrun interrupt is generated when data is not read from a result register
before the next conversion is written. If DMA is enabled, all transfers are
terminated and any conversion sequence is aborted.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_enable_overrun_interrupt(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_OVRIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable the Overrun Interrupt

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_disable_overrun_interrupt(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_OVRIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the Overrun Flag

The overrun flag is set when data is not read from a result register before the
next conversion is written. If DMA is enabled, all transfers are terminated and
any conversion sequence is aborted.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@returns Unsigned int32 conversion result.
*/

bool adc_get_overrun_flag(uint32_t adc)
{
	return ADC_SR(adc) & ADC_SR_OVR;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Clear Overrun Flags

The overrun flag is cleared. Note that if an overrun occurs, DMA is terminated.
The flag must be cleared and the DMA stream and ADC reinitialised to resume
conversions (see the reference manual).

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@returns Unsigned int32 conversion result.
*/

void adc_clear_overrun_flag(uint32_t adc)
{
/* need to write zero to clear this */
	ADC_SR(adc) &= ~ADC_SR_OVR;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable an EOC for Each Conversion

The EOC is set after each conversion in a sequence rather than at the end of the
sequence. Overrun detection is enabled only if DMA is enabled.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_eoc_after_each(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_EOCS;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable the EOC for Each Conversion

The EOC is set at the end of each sequence rather than after each conversion in
the sequence. Overrun detection is enabled always.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_eoc_after_group(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_EOCS;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set DMA to Continue

This must be set to allow DMA to continue to operate after the last conversion
in the DMA sequence. This allows DMA to be used in continuous circular mode.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_set_dma_continue(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_DDS;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set DMA to Terminate

This must be set to allow DMA to terminate after the last conversion in the DMA
sequence. This can avoid overrun errors.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
*/

void adc_set_dma_terminate(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_DDS;
}
/*---------------------------------------------------------------------------*/
/** @brief ADC Read the Analog Watchdog Flag

This flag is set when the converted voltage crosses the high or low thresholds.

@param[in] adc Unsigned int32. ADC block register address base @ref adc_reg_base
@returns bool. AWD flag.
*/

bool adc_awd(uint32_t adc)
{
	return ADC_SR(adc) & ADC_SR_AWD;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable The Temperature Sensor

This enables both the sensor and the reference voltage measurements on ADC1
channels 16 and 17. On STM32F42x and STM32F43x, the temperature sensor is
connected to ADC1 channel 18, the same as VBat. If both are enabled, only the
VBat conversion is performed.
*/

void adc_enable_temperature_sensor(void)
{
	ADC_CCR |= ADC_CCR_TSVREFE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable The Temperature Sensor

Disabling this will reduce power consumption from the sensor and the reference
voltage measurements.
*/

void adc_disable_temperature_sensor(void)
{
	ADC_CCR &= ~ADC_CCR_TSVREFE;
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
