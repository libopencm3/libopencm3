/** @addtogroup adc_file ADC peripheral API
 * @ingroup peripheral_apis
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
 * rcc_periph_clock_enable(RCC_ADC1);
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
	ADC_CFGR1(adc) |= ADC_CFGR1_AWD1EN;
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
	ADC_CFGR1(adc) &= ~ADC_CFGR1_AWD1EN;
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
	ADC_CFGR1(adc) |= ADC_CFGR1_JAWD1EN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog for Injected Conversions
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_analog_watchdog_injected(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_JAWD1EN;
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
	ADC_CFGR1(adc) |= ADC_CFGR1_DISCEN;
	ADC_CFGR1(adc) |= ((length-1) << ADC_CFGR1_DISCNUM_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Regular Conversions
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_discontinuous_mode_regular(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_DISCEN;
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
	ADC_CFGR1(adc) |= ADC_CFGR1_JDISCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Injected Conversions
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_discontinuous_mode_injected(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_JDISCEN;
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
	ADC_CFGR1(adc) |= ADC_CFGR1_JAUTO;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Automatic Injected Conversions
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_disable_automatic_injected_group_conversion(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_JAUTO;
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
	ADC_CFGR1(adc) &= ~ADC_CFGR1_AWD1SGL;
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
	ADC_CFGR1(adc) = (ADC_CFGR1(adc) & ~ADC_CFGR1_AWD1CH) |
			  ADC_CFGR1_AWD1CH_VAL(channel);

	ADC_CFGR1(adc) |= ADC_CFGR1_AWD1EN | ADC_CFGR1_AWD1SGL;
}


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
/** @brief ADC Software Triggered Conversion on Injected Channels
 *
 * This starts conversion on a set of defined injected channels.
 * Depending on the configuration bits JEXTEN, a conversion will start
 * immediately (software trigger configuration) or once an injected hardware
 * trigger event occurs (hardware trigger configuration).
 *
 * @param[in] adc Unsigned int32. ADC block register address base @ref
 * adc_reg_base
 */

void adc_start_conversion_injected(uint32_t adc)
{
	/* Start conversion on injected channels. */
	ADC_CR(adc) |= ADC_CR_JADSTART;
}


/*---------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Upper Threshold
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] threshold. Upper threshold value
 */

void adc_set_watchdog_high_threshold(uint32_t adc, uint16_t threshold)
{
	uint32_t reg32 = 0;
	uint32_t mask = 0xf000ffff;

	reg32 |= (threshold << 16);
	reg32 &= ~mask; /* clear masked bits. */

	ADC_TR1(adc) = (ADC_TR1(adc) & mask) | reg32;
	ADC_TR2(adc) = (ADC_TR2(adc) & mask) | reg32;
	ADC_TR3(adc) = (ADC_TR3(adc) & mask) | reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Lower Threshold
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @param[in] threshold. Lower threshold value
 */

void adc_set_watchdog_low_threshold(uint32_t adc, uint16_t threshold)
{
	uint32_t reg32 = 0;
	uint32_t mask = 0xfffff000;
	reg32 = (uint32_t)threshold;
	reg32 &= ~mask; /* clear masked bits. */

	ADC_TR1(adc) = (ADC_TR1(adc) & mask) | reg32;
	ADC_TR2(adc) = (ADC_TR2(adc) & mask) | reg32;
	ADC_TR3(adc) = (ADC_TR3(adc) & mask) | reg32;
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
/** @brief ADC Set Clock Prescale
 *
 * The ADC clock taken from the APB2 clock can be scaled down by 2, 4, 6 or 8.
 *
 * @param adc peripheral of choice @ref adc_reg_base
 * @param[in] prescale Unsigned int32. Prescale value for ADC Clock @ref
 * adc_ccr_adcpre
 */
void adc_set_clk_prescale(uint32_t adc, uint32_t prescale)
{
	uint32_t reg32 = ((ADC_CCR(adc) & ~ADC_CCR_CKMODE_MASK) | prescale);
	ADC_CCR(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Dual/Triple Mode
 *
 * The multiple mode uses ADC1 as master, ADC2 and optionally ADC3 in a slave
 * arrangement. This setting is applied to ADC1 only.
 *
 * The various modes possible are described in the reference manual.
 *
 * @param adc peripheral of choice @ref adc_reg_base
 * @param[in] mode Unsigned int32. Multiple mode selection from @ref
 * adc_multi_mode
 */
void adc_set_multi_mode(uint32_t adc, uint32_t mode)
{
	ADC_CCR(adc) |= mode;
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
	uint32_t reg32 = ADC_CFGR1(adc);

	reg32 &= ~(ADC_CFGR1_EXTSEL_MASK | ADC_CFGR1_EXTEN_MASK);
	reg32 |= (trigger | polarity);
	ADC_CFGR1(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Regular Channels
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 */

void adc_disable_external_trigger_regular(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_EXTEN_MASK;
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


/**
 * Enable the ADC Voltage regulator
 * Before any use of the ADC, the ADC Voltage regulator must be enabled.
 * You must wait up to 10uSecs afterwards before trying anything else.
 * @param[in] adc ADC block register address base
 * @sa adc_disable_regulator
 */
void adc_enable_regulator(uint32_t adc)
{
	ADC_CR(adc) &= ~ADC_CR_ADVREGEN_MASK;
	ADC_CR(adc) |= ADC_CR_ADVREGEN_ENABLE;
}

/**
 * Disable the ADC Voltage regulator
 * You can disable the adc vreg when not in use to save power
 * @param[in] adc ADC block register address base
 * @sa adc_enable_regulator
 */
void adc_disable_regulator(uint32_t adc)
{
	ADC_CR(adc) &= ~ADC_CR_ADVREGEN_MASK;
	ADC_CR(adc) |= ADC_CR_ADVREGEN_DISABLE;
}

/**@}*/

