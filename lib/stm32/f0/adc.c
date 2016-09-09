/** @defgroup adc_file ADC
 *
 * @ingroup STM32F0xx
 *
 * @brief <b>libopencm3 STM32F0xx Analog to Digital Converters</b>
 *
 * based on F3 file
 *
 * @date 14 July 2013
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

#include <libopencm3/cm3/assert.h>
#include <libopencm3/stm32/adc.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup adc_api_opmode ADC Operation mode API
 * @ingroup adc_file
 *
 * @brief ADC Result API
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Discontinuous Mode for Regular Conversions
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_enable_discontinuous_mode(uint32_t adc)
{
	ADC_CFGR1(adc) |= ADC_CFGR1_DISCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Discontinuous Mode for Regular Conversions
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_disable_discontinuous_mode(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_DISCEN;
}

/*---------------------------------------------------------------------------*/
/** ADC Set operation mode
 *
 * There are some operation modes, common for entire stm32 branch. In the text
 * the braces are describing result to single trigger event. The trigger event
 * is described by character T in the description. The ADC is configured to
 * convert list of inputs [0, 1, 2, 3]. In Grouped modes, there is used group
 * size of 2 conversions in the examples
 *
 * @li @c ADC_MODE_SEQUENTIAL:  T(0) T(1) T(2) T(3)[EOSEQ] T(0) T(1) T(2) ...
 *
 *  In this mode, after the trigger event a single channel is converted and the
 *  next channel in the list is prepared to convert on next trigger edge.
 *
 *  @note This mode can be emulated by ADC_MODE_GROUPED with group size
 *  of 1. @par
 *
 * @li @c ADC_MODE_SCAN:        T(0123)[EOSEQ] T(0123)[EOSEQ] T(0123)[EOSEQ]
 *
 *  In this mode, after the trigger event, all channels will be converted once,
 *  storing results sequentially.
 *
 *  @note The DMA must be configured properly for more than single channel to
 *  convert. @par
 *
 * @li @c ADC_MODE_SCAN_INFINITE: T(0123[EOSEQ]0123[EOSEQ]0123[EOSEQ]...)
 *
 *  In this mode, after the trigger event, all channels from the list are
 *  converted. At the end of list, the conversion continues from the beginning.
 *
 *  @note The DMA must be configured properly to operate in this mode.@par
 *
 * @li @c ADC_MODE_GROUPED:     T(12) T(34)[EOSEQ] T(12) T(34)[EOSEQ] T(12)
 *
 *  In this mode, after the trigger event, a specified group size of channels
 *  are converted. If the end of channel list occurs, the EOSEQ is generated
 *  and on the next trigger it wraps to the beginning.
 *
 *  @note The DMA must be configured properly to operate on more than single
 *  channel conversion groups.@par
 *
 * @warning not all families supports all modes of operation of ADC.
 *
 * @par
 *
 */

/*---------------------------------------------------------------------------*/
/** @brief ADC Set conversion operation mode
 *
 * @note on SEQUENTIAL mode, the trigger event is necessary to start conversion.
 * @par
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] adc ::adc_opmode. ADC operation mode (@ref adc_opmode)
 */

void adc_set_operation_mode(uint32_t adc, enum adc_opmode opmode)
{
	switch (opmode) {
	case ADC_MODE_SEQUENTIAL:
		ADC_CFGR1(adc) &= ~ADC_CFGR1_CONT;
		ADC_CFGR1(adc) |= ADC_CFGR1_DISCEN;
		break;

	case ADC_MODE_SCAN:
		ADC_CFGR1(adc) &= ~(ADC_CFGR1_CONT | ADC_CFGR1_DISCEN);
		break;

	case ADC_MODE_SCAN_INFINITE:
		ADC_CFGR1(adc) &= ~ADC_CFGR1_DISCEN;
		ADC_CFGR1(adc) |= ADC_CFGR1_CONT;
		break;
	}
}

/**@}*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup adc_api_trigger ADC Trigger API
 * @ingroup adc_file
 *
 * @brief ADC Trigger API
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable an External Trigger for Regular Channels
 *
 * This enables an external trigger for set of defined regular channels, and
 * sets the polarity of the trigger event: rising or falling edge or both. Note
 * that if the trigger polarity is zero, triggering is disabled.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] trigger Unsigned int32. Trigger identifier
 * @ref adc_trigger_regular
 * @param[in] polarity Unsigned int32. Trigger polarity @ref
 * adc_trigger_polarity_regular
 */

void adc_enable_external_trigger_regular(uint32_t adc, uint32_t trigger,
				 uint32_t polarity)
{
	ADC_CFGR1(adc) = (ADC_CFGR1(adc) & ~ADC_CFGR1_EXTSEL) | trigger;
	ADC_CFGR1(adc) = (ADC_CFGR1(adc) & ~ADC_CFGR1_EXTEN_MASK) | polarity;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable an External Trigger for Regular Channels
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_disable_external_trigger_regular(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_EXTEN_MASK;
}

/**@}*/


/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup adc_api_interrupts ADC Interrupt configuration API
 * @ingroup adc_file
 *
 * @brief ADC Interrupt configuration API
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog Interrupt
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_enable_watchdog_interrupt(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_AWD1IE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Regular End-Of-Conversion Interrupt
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_disable_watchdog_interrupt(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_AWD1IE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the Analog Watchdog Flag
 *
 * This flag is set when the converted voltage crosses the high or low
 * thresholds.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @returns bool true, if the signal is out of defined analog range.
 */

bool adc_get_watchdog_flag(uint32_t adc)
{
	return ADC_ISR(adc) & ADC_ISR_AWD1;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Clear Analog Watchdog Flag
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_clear_watchdog_flag(uint32_t adc)
{
	ADC_ISR(adc) = ADC_ISR_AWD1;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Regular End-Of-Conversion Sequence Interrupt
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_enable_eoc_sequence_interrupt(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_EOSEQIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Regular End-Of-Conversion Sequence Interrupt
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_disable_eoc_sequence_interrupt(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_EOSEQIE;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Read the Regular End-Of-Conversion Sequence Flag
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

bool adc_get_eoc_sequence_flag(uint32_t adc)
{
	return ADC_ISR(adc) & ADC_ISR_EOSEQ;
}


/**@}*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup adc_api_config ADC Basic configuration API
 * @ingroup adc_file
 *
 * @brief ADC Basic configuration API
 *
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Clock Prescale
 *
 * The ADC clock taken from the many sources.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] prescale Unsigned int32. Prescale value (@ref adc_api_clksource)
 */

void adc_set_clk_source(uint32_t adc, uint32_t source)
{
	ADC_CFGR2(adc) = ((ADC_CFGR2(adc) & ~ADC_CFGR2_CKMODE) | source);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set a Regular Channel Conversion Sequence
 *
 * Define a sequence of channels to be converted as a regular group with a
 * length from 1 to 18 channels. If this is called during conversion, the
 * current conversion is reset and conversion begins again with the newly
 * defined group.
 *
 * @warning This core doesn't support the random order of ADC conversions.
 * The channel list must be ordered by channel number.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] length Unsigned int8. Number of channels in the group.
 * @param[in] channel Unsigned int8[]. Set of channels to convert, integers
 * 0..18.
 */

void adc_set_regular_sequence(uint32_t adc, uint8_t length, uint8_t channel[])
{
	uint32_t reg32 = 0;
	uint8_t i = 0;
	bool stepup = false, stepdn = false;

	if (length == 0) {
		ADC_CHSELR(adc) = 0;
		return;
	}

	reg32 |= (1 << channel[0]);

	for (i = 1; i < length; i++) {
		reg32 |= (1 << channel[i]);
		stepup |= channel[i-1] < channel[i];
		stepdn |= channel[i-1] > channel[i];
	}

	/* Check, if the channel list is in order */
	if (stepup && stepdn) {
		cm3_assert_not_reached();
	}

	/* Update the scan direction flag */
	if (stepdn) {
		ADC_CFGR1(adc) |= ADC_CFGR1_SCANDIR;
	} else {
		ADC_CFGR1(adc) &= ~ADC_CFGR1_SCANDIR;
	}

	ADC_CHSELR(adc) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set the Sample Time for All Channels
 *
 * The sampling time can be selected in ADC clock cycles from 1.5 to 239.5,
 * same for all channels.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] time Unsigned int8. Sampling time selection (@ref adc_api_smptime)
 */

void adc_set_sample_time_on_all_channels(uint32_t adc, uint8_t time)
{
	ADC_SMPR(adc) = time & ADC_SMPR_SMP;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable The VBat Sensor
 *
 * This enables the battery voltage measurements on channel 17.
 */

void adc_enable_vbat_sensor(void)
{
	ADC_CCR(ADC1) |= ADC_CCR_VBATEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable The VBat Sensor
 *
 * Disabling this will reduce power consumption from the battery voltage
 * measurement.
 */

void adc_disable_vbat_sensor(void)
{
	ADC_CCR(ADC1) &= ~ADC_CCR_VBATEN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Start the calibration procedure
 * @deprecated Replaced by adc_calibrate/_async/is_calibrating
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_calibrate_start(uint32_t adc)
{
	ADC_CR(adc) = ADC_CR_ADCAL;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Wait to finish the ADC calibration procedure
 * @deprecated Replaced by adc_calibrate/_async/is_calibrating
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_calibrate_wait_finish(uint32_t adc)
{
	while (ADC_CR(adc) & ADC_CR_ADCAL);
}

/**@}*/

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/**
 * @defgroup adc_api_wdg ADC Analog watchdog API
 * @ingroup adc_file
 *
 * @brief ADC analog watchdog API definitions.
 *
 * The analog watchdog allows the monitoring of an analog signal between two
 * threshold levels. The thresholds must be preset. Analog watchdog is disabled
 * by default.
 *
 * @warning Comparison is done before data alignment takes place, so the
 * thresholds are left-aligned.
 *
 * Example 1: Enable watchdog checking on all channels
 *
 * @code
 * // in configuration
 * adc_enable_analog_watchdog_on_all_channels(ADC1);
 * adc_set_watchdog_high_threshold(ADC1, 0xE00);
 * adc_set_watchdog_low_threshold(ADC1, 0x200);
 *
 * // in the main application thread
 * if (adc_get_watchdog_flag(ADC1)) {
 *     // the converted signal is out of AWD ranges
 *     adc_clear_watchdog_flag(ADC1);
 * }
 * @endcode
 *
 * Example 2: Enable watchdog checking on channel 5
 *
 * @code
 * // in configuration
 * adc_enable_analog_watchdog_on_selected_channel(ADC1,5);
 * adc_set_watchdog_high_threshold(ADC1, 0xE00);
 * adc_set_watchdog_low_threshold(ADC1, 0x200);
 *
 * // in the main application thread
 * if (adc_get_watchdog_flag(ADC1)) {
 *     // the converted signal is out of AWD ranges
 *     adc_clear_watchdog_flag(ADC1);
 * }
 * @endcode
 *@{*/

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for All Channels
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */

void adc_enable_analog_watchdog_on_all_channels(uint32_t adc)
{
	ADC_CFGR1(adc) |= ADC_CFGR1_AWD1EN;
	ADC_CFGR1(adc) &= ~ADC_CFGR1_AWD1SGL;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Enable Analog Watchdog for a Selected Channel
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] chan Unsigned int8. ADC channel number @ref adc_api_channel
 */

void adc_enable_analog_watchdog_on_selected_channel(uint32_t adc, uint8_t chan)
{
	ADC_CFGR1(adc) = (ADC_CFGR1(adc) & ~ADC_CFGR1_AWD1CH) |
			  ADC_CFGR1_AWD1CH_VAL(chan);

	ADC_CFGR1(adc) |= ADC_CFGR1_AWD1EN | ADC_CFGR1_AWD1SGL;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Disable Analog Watchdog
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_disable_analog_watchdog(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_AWD1EN;
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Upper Threshold
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] threshold Unsigned int8. Upper threshold value
 */

void adc_set_watchdog_high_threshold(uint32_t adc, uint8_t threshold)
{
	ADC_TR1(adc) = (ADC_TR1(adc) & ~ADC_TR1_HT) | ADC_TR1_HT_VAL(threshold);
}

/*---------------------------------------------------------------------------*/
/** @brief ADC Set Analog Watchdog Lower Threshold
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] threshold Unsigned int8. Lower threshold value
 */

void adc_set_watchdog_low_threshold(uint32_t adc, uint8_t threshold)
{
	ADC_TR1(adc) = (ADC_TR1(adc) & ~ADC_TR1_LT) | ADC_TR1_LT_VAL(threshold);
}

/**@}*/

/*---------------------------------------------------------------------------*/

/**@}*/
