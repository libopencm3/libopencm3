/** @defgroup adc_file ADC
 *
 * @ingroup STM32F3xx
 *
 * @brief <b>libopencm3 STM32F3xx Analog to Digital Converters</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2012
 * Ken Sarkies <ksarkies@internode.on.net>
 *
 * @date 30 August 2012
 *
 * This library supports the A/D Converter Control System in the STM32 series
 * of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * Devices can have up to three A/D converters each with their own set of
 * registers.  However all the A/D converters share a common clock which is
 * prescaled from the APB2 clock by default by a minimum factor of 2 to a
 * maximum of 8. The ADC resolution can be set to 12, 10, 8 or 6 bits.
 *
 * Each A/D converter has up to 19 channels:
 * @li On ADC1 the analog channels 16 is internally connected to the
 * temperature sensor, channel 17 to V<sub>REFINT</sub>, and channel 18
 * to V<sub>BATT</sub>.
 * @li On ADC2 and ADC3 the analog channels 16 - 18 are not used.
 *
 * The conversions can occur as a one-off conversion whereby the process stops
 * once conversion is complete. The conversions can also be continuous wherein
 * a new conversion starts immediately the previous conversion has ended.
 *
 * Conversion can occur as a single channel conversion or a scan of a group of
 * channels in either continuous or one-off mode. If more than one channel is
 * converted in a scan group, DMA must be used to transfer the data as there is
 * only one result register available. An interrupt can be set to occur at the
 * end*
 * of conversion, which occurs after all channels have been scanned.
 *
 * A discontinuous mode allows a subgroup of group of a channels to be
 * converted in bursts of a given length.
 *
 * Injected conversions allow a second group of channels to be converted
 * separately from the regular group. An interrupt can be set to occur at the
 * end of conversion, which occurs after all channels have been scanned.
 *
 * @section adc_f3_api_ex Basic ADC Handling API.
 *
 * Example 1: Simple single channel conversion polled. Enable the peripheral
 * clock and ADC, reset ADC and set the prescaler divider. Set multiple mode to
 * independent.
 *
 * @code
 * gpio_mode_setup(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO1);
 * rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_ADC1EN);
 * adc_set_clk_prescale(RCC_CFGR_ADCPRE_BY2);
 * adc_disable_scan_mode(ADC1);
 * adc_set_single_conversion_mode(ADC1);
 * adc_set_sample_time(ADC1, ADC_CHANNEL0, ADC_SMPR1_SMP_1DOT5CYC);
 * uint8_t channels[] = ADC_CHANNEL0;
 * adc_set_regular_sequence(ADC1, 1, channels);
 * adc_set_multi_mode(ADC_CCR_MULTI_INDEPENDENT);
 * adc_power_on(ADC1);
 * adc_start_conversion_regular(ADC1);
 * while (! adc_eoc(ADC1));
 * reg16 = adc_read_regular(ADC1);
 * @endcode
 *
 * LGPL License Terms @ref lgpl_license
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
/** @brief ADC Off
 *
 * Turn off the ADC to reduce power consumption to a few microamps.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
*/

void adc_off(uint32_t adc)
{
	ADC_CR(adc) &= ~ADC_CR_ADEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Regular Conversions
 *
 * The analog watchdog allows the monitoring of an analog signal between two
 * threshold levels. The thresholds must be preset. Comparison is done before
 * data alignment takes place, so the thresholds are left-aligned.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_analog_watchdog_regular(uint32_t adc)
{
	ADC_CFGR(adc) |= ADC_CFGR_AWD1EN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Regular Conversions
 *
 * The analog watchdog allows the monitoring of an analog signal between two
 * threshold levels. The thresholds must be preset. Comparison is done before
 * data alignment takes place, so the thresholds are left-aligned.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */
void adc_disable_analog_watchdog_regular(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_AWD1EN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for Injected Conversions
 *
 * The analog watchdog allows the monitoring of an analog signal between two
 * threshold levels. The thresholds must be preset. Comparison is done before
 * data alignment takes place, so the thresholds are left-aligned.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_analog_watchdog_injected(uint32_t adc)
{
	ADC_CFGR(adc) |= ADC_CFGR_JAWD1EN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Injected Conversions
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_analog_watchdog_injected(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_JAWD1EN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Regular Conversions
 *
 * In this mode the ADC converts, on each trigger, a subgroup of up to 8 of the
 * defined regular channel group. The subgroup is defined by the number of
 * consecutive channels to be converted. After a subgroup has been converted
 * the next trigger will start conversion of the immediately following subgroup
 * of the same length or until the whole group has all been converted. When the
 * whole group has been converted, the next trigger will restart conversion of
 * the subgroup at the beginning of the whole group.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base @param[in] length Unsigned int8. Number of channels in the
 * group @ref adc_cr1_discnum
 */

void adc_enable_discontinuous_mode_regular(uint32_t adc, uint8_t length)
{
	if ((length-1) > 7) {
		return;
	}
	ADC_CFGR(adc) |= ADC_CFGR_DISCEN;
	ADC_CFGR(adc) |= ((length-1) << ADC_CFGR_DISCNUM_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Regular Conversions
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_discontinuous_mode_regular(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_DISCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Injected Conversions
 *
 * In this mode the ADC converts sequentially one channel of the defined group
 * of injected channels, cycling back to the first channel in the group once
 * the entire group has been converted.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_discontinuous_mode_injected(uint32_t adc)
{
	ADC_CFGR(adc) |= ADC_CFGR_JDISCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Injected Conversions
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_discontinuous_mode_injected(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_JDISCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Automatic Injected Conversions
 *
 * The ADC converts a defined injected group of channels immediately after the
 * regular channels have been converted. The external trigger on the injected
 * channels is disabled as required.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_automatic_injected_group_conversion(uint32_t adc)
{
	adc_disable_external_trigger_injected(adc);
	ADC_CFGR(adc) |= ADC_CFGR_JAUTO;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Automatic Injected Conversions
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_automatic_injected_group_conversion(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_JAUTO;
}
/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for All Regular and/or Injected Channels
 *
 * The analog watchdog allows the monitoring of an analog signal between two
 * threshold levels. The thresholds must be preset. Comparison is done before
 * data alignment takes place, so the thresholds are left-aligned.
 *
 * @note The analog watchdog must be enabled for either or both of the regular
 * or injected channels. If neither are enabled, the analog watchdog feature
 * will be disabled.
 *
 * @ref adc_enable_analog_watchdog_injected, @ref
 * adc_enable_analog_watchdog_regular.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_analog_watchdog_on_all_channels(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_AWD1SGL;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for a Selected Channel
 *
 * The analog watchdog allows the monitoring of an analog signal between two
 * threshold levels. The thresholds must be preset. Comparison is done before
 * data alignment takes place, so the thresholds are left-aligned.
 *
 * @note The analog watchdog must be enabled for either or both of the regular
 * or injected channels. If neither are enabled, the analog watchdog feature
 * will be disabled. If both are enabled, the same channel number is monitored
 * @ref adc_enable_analog_watchdog_injected, @ref
 * adc_enable_analog_watchdog_regular.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 * @param[in] channel Unsigned int8. ADC channel numbe
 * @ref adc_watchdog_channel
 */

void adc_enable_analog_watchdog_on_selected_channel(uint32_t adc,
						    uint8_t channel)
{
	uint32_t reg32;

	reg32 = (ADC_CFGR(adc) & ~ADC_CFGR_AWD1CH_MASK); /* Clear bit [4:0]. */
	if (channel < 18) {
		reg32 |= channel;
	}
	ADC_CFGR(adc) = reg32;
	ADC_CFGR(adc) |= ADC_CFGR_AWD1SGL;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Scan Mode
 *
 * In this mode a conversion consists of a scan of the predefined set of
 * channels, regular and injected, each channel conversion immediately
 * following the previous one. It can use single, continuous or discontinuous
 * mode.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

/*
void adc_enable_scan_mode(uint32_t adc)
{
	ADC_CR1(adc) |= ADC_CR1_SCAN;
}
*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Scan Mode
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

/*
void adc_disable_scan_mode(uint32_t adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_SCAN;
}
*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Injected End-Of-Conversion Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_eoc_interrupt_injected(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_JEOCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Injected End-Of-Conversion Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_eoc_interrupt_injected(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_JEOCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Injected End-Of-Sequence Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_eos_interrupt_injected(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_JEOSIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Injected End-Of-Sequence Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_eos_interrupt_injected(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_JEOSIE;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_all_awd_interrupt(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_AWD1IE;
	ADC_IER(adc) |= ADC_IER_AWD2IE;
	ADC_IER(adc) |= ADC_IER_AWD3IE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_all_awd_interrupt(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_AWD1IE;
	ADC_IER(adc) &= ~ADC_IER_AWD2IE;
	ADC_IER(adc) &= ~ADC_IER_AWD3IE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Regular End-Of-Conversion Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_eoc_interrupt(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_EOCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Regular End-Of-Conversion Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_eoc_interrupt(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_EOCIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Regular End-Of-Sequence Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_eos_interrupt(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_EOSIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Regular End-Of-Sequence Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_eos_interrupt(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_EOSIE;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Software Triggered Conversion on Regular Channels
 *
 * This starts conversion on a set of defined regular channels. It is cleared
 * by hardware once conversion starts.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_start_conversion_regular(uint32_t adc)
{
	/* Start conversion on regular channels. */
	ADC_CR(adc) |= ADC_CR_ADSTART;

	/* Wait until the ADC starts the conversion. */
	while (ADC_CR(adc) & ADC_CR_ADSTART);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Software Triggered Conversion on Injected Channels
 *
 * This starts conversion on a set of defined injected channels. It is cleared
 * by hardware once conversion starts.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_start_conversion_injected(uint32_t adc)
{
	/* Start conversion on injected channels. */
	ADC_CR(adc) |= ADC_CR_JADSTART;

	/* Wait until the ADC starts the conversion. */
	while (ADC_CR(adc) & ADC_CR_JADSTART);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Left Aligned
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_set_left_aligned(uint32_t adc)
{
	ADC_CFGR(adc) |= ADC_CFGR_ALIGN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Data as Right Aligned
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_set_right_aligned(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_ALIGN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable DMA Transfers
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 */

void adc_enable_dma(uint32_t adc)
{
	ADC_CFGR(adc) |= ADC_CFGR_DMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable DMA Transfers
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 */

void adc_disable_dma(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_DMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Continuous Conversion Mode
 *
 * In this mode the ADC starts a new conversion of a single channel or a channel
 * group immediately following completion of the previous channel group
 * conversion.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 */

void adc_set_continuous_conversion_mode(uint32_t adc)
{
	ADC_CFGR(adc) |= ADC_CFGR_CONT;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Single Conversion Mode
 *
 * In this mode the ADC performs a conversion of one channel or a channel group
 * and stops.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 */

void adc_set_single_conversion_mode(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_CONT;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for a Single Channel
 *
 * The sampling time can be selected in ADC clock cycles from 1.5 to 239.5.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] channel Unsigned int8. ADC Channel integer 0..18 or from
 * @ref adc_channel
 * @param[in] time Unsigned int8. Sampling time selection from
 * @ref adc_sample_rg
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
 *
 * The sampling time can be selected in ADC clock cycles from 1.5 to 239.5,
 * same for all channels.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] time Unsigned int8. Sampling time selection from
 * @ref adc_sample_rg
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
/** @brief ADC Set Analog Watchdog Upper Threshold
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] threshold Unsigned int8. Upper threshold value
 */

void adc_set_watchdog_high_threshold(uint32_t adc, uint8_t threshold)
{
	uint32_t reg32 = 0;

	reg32 |= (threshold << 16);
	reg32 &= ~0xff00ffff; /* Clear all bits above 8. */
	ADC_TR1(adc) = reg32;
	ADC_TR2(adc) = reg32;
	ADC_TR3(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Lower Threshold
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] threshold Unsigned int8. Lower threshold value
 */

void adc_set_watchdog_low_threshold(uint32_t adc, uint8_t threshold)
{
	uint32_t reg32 = 0;

	reg32 = (uint32_t)threshold;
	reg32 &= ~0xffffff00; /* Clear all bits above 8. */
	ADC_TR1(adc) = reg32;
	ADC_TR2(adc) = reg32;
	ADC_TR3(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set a Regular Channel Conversion Sequence
 *
 * Define a sequence of channels to be converted as a regular group with a
 * length from 1 to 16 channels. If this is called during conversion, the
 * current conversion is reset and conversion begins again with the newly
 * defined group.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] length Unsigned int8. Number of channels in the group.
 * @param[in] channel Unsigned int8[]. Set of channels in sequence, integers
 * 0..18.
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
	reg32_1 |= ((length - 1) << ADC_SQR1_L_LSB);

	ADC_SQR1(adc) = reg32_1;
	ADC_SQR2(adc) = reg32_2;
	ADC_SQR3(adc) = reg32_3;
	ADC_SQR4(adc) = reg32_4;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set an Injected Channel Conversion Sequence
 *
 * Defines a sequence of channels to be converted as an injected group with a
 * length from 1 to 4 channels. If this is called during conversion, the current
 * conversion is reset and conversion begins again with the newly defined group.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] length Unsigned int8. Number of channels in the group.
 * @param[in] channel Unsigned int8[]. Set of channels in sequence, integers
 * 0..18
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

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Conversion Flag
 *
 * This flag is set by hardware at the end of each regular conversion of a
 * channel when a new data is available in the ADCx_DR register.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @returns bool. End of conversion flag.
 */

bool adc_eoc(uint32_t adc)
{
	return ADC_ISR(adc) & ADC_ISR_EOC;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Conversion Flag for Injected Conversion
 *
 * This flag is set by hardware at the end of each injected conversion of a
 * channel when a new data is available in the corresponding ADCx_JDRy register.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @returns bool. End of conversion flag.
 */

bool adc_eoc_injected(uint32_t adc)
{
	return ADC_ISR(adc) & ADC_ISR_JEOC;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Sequence Flag for Regular Conversions
 *
 * This flag is set after all channels of an regular group have been
 * converted.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @returns bool. End of conversion flag.
 */
bool adc_eos(uint32_t adc)
{
	return ADC_ISR(adc) & ADC_ISR_EOS;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the End-of-Sequence Flag for Injected Conversions
 *
 * This flag is set after all channels of an injected group have been
 * converted.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @returns bool. End of conversion flag.
 */
bool adc_eos_injected(uint32_t adc)
{
	return ADC_ISR(adc) & ADC_ISR_JEOS;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Read from the Regular Conversion Result Register
 *
 * The result read back is 12 bits, right or left aligned within the first
 * 16 bits. For ADC1 only, the higher 16 bits will hold the result from ADC2 if
 * an appropriate dual mode has been set @see adc_set_dual_mode.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @returns Unsigned int32 conversion result.
 */

uint32_t adc_read_regular(uint32_t adc)
{
	return ADC_DR(adc);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read from an Injected Conversion Result Register
 *
 * The result read back from the selected injected result register (one of four)
 * is 12 bits, right or left aligned within the first 16 bits. The result can
 * have a negative value if the injected channel offset has been set @see
 * adc_set_injected_offset.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 * @param[in] reg Unsigned int8. Register number (1 ... 4).
 * @returns Unsigned int32 conversion result.
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
/** @brief ADC Set the Injected Channel Data Offset
 *
 * This value is subtracted from the injected channel results after conversion
 * is complete, and can result in negative results. A separate value can be
 * specified for each injected data register.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] reg Unsigned int8. Register number (1 ... 4).
 * @param[in] offset Unsigned int32.
*/

void adc_set_injected_offset(uint32_t adc, uint8_t reg, uint32_t offset)
{
	switch (reg) {
	case 1:
		ADC_OFR1(adc) |= ADC_OFR1_OFFSET1_EN;
		ADC_OFR1(adc) |= offset;
		break;
	case 2:
		ADC_OFR2(adc) |= ADC_OFR2_OFFSET2_EN;
		ADC_OFR2(adc) |= offset;
		break;
	case 3:
		ADC_OFR3(adc) |= ADC_OFR3_OFFSET3_EN;
		ADC_OFR3(adc) |= offset;
		break;
	case 4:
		ADC_OFR4(adc) |= ADC_OFR4_OFFSET4_EN;
		ADC_OFR4(adc) |= offset;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Power On
 *
 * If the ADC is in power-down mode then it is powered up. The application
 * needs to wait a time of about 3 microseconds for stabilization before using
 * the ADC. If the ADC is already on this function call will have no effect.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_power_on(uint32_t adc)
{
	ADC_CR(adc) |= ADC_CR_ADEN;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Set Clock Prescale
 *
 * The ADC clock taken from the APB2 clock can be scaled down by 2, 4, 6 or 8.
 *
 * @param[in] prescale Unsigned int32. Prescale value for ADC Clock @ref
 * adc_ccr_adcpre
*/

void adc_set_clk_prescale(uint32_t prescale)
{
	uint32_t reg32 = ((ADC_CCR & ~ADC_CCR_CKMODE_MASK) | prescale);
	ADC_CCR = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Dual/Triple Mode
 *
 * The multiple mode uses ADC1 as master, ADC2 and optionally ADC3 in a slave
 * arrangement. This setting is applied to ADC1 only.
 *
 * The various modes possible are described in the reference manual.
 *
 * @param[in] mode Unsigned int32. Multiple mode selection from @ref
 * adc_multi_mode
*/

void adc_set_multi_mode(uint32_t mode)
{
	ADC_CCR |= mode;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Regular Channels
 *
 * This enables an external trigger for set of defined regular channels, and
 * sets the polarity of the trigger event: rising or falling edge or both. Note
 * that if the trigger polarity is zero, triggering is disabled.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 * @param[in] trigger Unsigned int32. Trigger identifier
 * @ref adc_trigger_regular
 * @param[in] polarity Unsigned int32. Trigger polarity @ref
 * adc_trigger_polarity_regular
 */

void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
					 uint32_t polarity)
{
	uint32_t reg32 = ADC_CFGR(adc);

	reg32 &= ~(ADC_CFGR_EXTSEL_MASK | ADC_CFGR_EXTEN_MASK);
	reg32 |= (trigger | polarity);
	ADC_CFGR(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Regular Channels
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 */

void adc_disable_external_trigger_regular(uint32_t adc)
{
	ADC_CFGR(adc) &= ~ADC_CFGR_EXTEN_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Injected Channels
 *
 * This enables an external trigger for set of defined injected channels, and
 * sets the polarity of the trigger event: rising or falling edge or both.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] trigger Unsigned int8. Trigger identifier
 * @ref adc_trigger_injected
 * @param[in] polarity Unsigned int32. Trigger polarity
 * @ref adc_trigger_polarity_injected
*/

void adc_enable_external_trigger_injected(uint32_t adc, uint32_t trigger,
					  uint32_t polarity)
{
	uint32_t reg32 = ADC_JSQR(adc);

	reg32 &= ~(ADC_JSQR_JEXTSEL_MASK | ADC_JSQR_JEXTEN_MASK);
	reg32 |= (trigger | polarity);
	ADC_JSQR(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Injected Channels
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_external_trigger_injected(uint32_t adc)
{
	ADC_JSQR(adc) &= ~ADC_JSQR_JEXTEN_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Resolution
 *
 * ADC Resolution can be reduced from 12 bits to 10, 8 or 6 bits for a
 * corresponding reduction in conversion time (resolution + 3 ADC clock cycles).
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 * @param[in] resolution Unsigned int8. Resolution value @ref adc_cr1_res
 */

void adc_set_resolution(uint32_t adc, uint16_t resolution)
{
	uint32_t reg32 = ADC_CFGR(adc);

	reg32 &= ~ADC_CFGR_RES_MASK;
	reg32 |= resolution;
	ADC_CFGR(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable the Overrun Interrupt
 *
 * The overrun interrupt is generated when data is not read from a result
 * register before the next conversion is written. If DMA is enabled, all
 * transfers are terminated and any conversion sequence is aborted.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_overrun_interrupt(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_OVRIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable the Overrun Interrupt
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_overrun_interrupt(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_OVRIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the Overrun Flag
 *
 * The overrun flag is set when data is not read from a result register before
 * the next conversion is written. If DMA is enabled, all transfers are
 * terminated and any conversion sequence is aborted.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 * @returns Unsigned int32 conversion result.
 */

bool adc_get_overrun_flag(uint32_t adc)
{
	return ADC_ISR(adc) & ADC_ISR_OVR;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Clear Overrun Flags
 *
 * The overrun flag is cleared. Note that if an overrun occurs, DMA is
 * terminated.
 * The flag must be cleared and the DMA stream and ADC reinitialised to resume
 * conversions (see the reference manual).
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @returns Unsigned int32 conversion result.
 */

void adc_clear_overrun_flag(uint32_t adc)
{
	/* r_w1 bit */
	ADC_ISR(adc) |= ADC_ISR_OVR;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set DMA to Continue
 *
 * This must be set to allow DMA to continue to operate after the last
 * conversion in the DMA sequence. This allows DMA to be used in continuous
 * circular mode.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

/*
void adc_set_dma_continue(uint32_t adc)
{
	ADC_CR2(adc) |= ADC_CR2_DDS;
}
*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Set DMA to Terminate
 *
 * This must be set to allow DMA to terminate after the last conversion in the
 * DMA sequence. This can avoid overrun errors.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 */

/*
void adc_set_dma_terminate(uint32_t adc)
{
	ADC_CR2(adc) &= ~ADC_CR2_DDS;
}
*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the Analog Watchdog Flag
 *
 * This flag is set when the converted voltage crosses the high or low
 * thresholds.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @returns bool. AWD flag.
 */

bool adc_awd(uint32_t adc)
{
	return (ADC_ISR(adc) & ADC_ISR_AWD1) &&
	       (ADC_ISR(adc) & ADC_ISR_AWD2) &&
	       (ADC_ISR(adc) & ADC_ISR_AWD3);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable The Temperature Sensor
 *
 * This enables both the sensor and the reference voltage measurements on
 * channels
 * 16 and 17. These are only available on ADC1 channel 16 and 17 respectively.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_enable_temperature_sensor()
{
	ADC_CCR |= ADC_CCR_TSEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable The Temperature Sensor
 *
 * Disabling this will reduce power consumption from the sensor and the
 * reference voltage measurements.
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_temperature_sensor()
{
	ADC_CCR &= ~ADC_CCR_TSEN;
}

/*---------------------------------------------------------------------------*/

/**@}*/

