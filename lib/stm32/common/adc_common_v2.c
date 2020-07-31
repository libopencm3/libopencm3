/** @addtogroup adc_file ADC peripheral API
@ingroup peripheral_apis

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
	return ADC_ISR(adc) & ADC_ISR_ADRDY;
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
	if (adc_is_power_off(adc)) {
		return;
	}

	uint32_t checks = ADC_CR_ADSTART;
	uint32_t stops = ADC_CR_ADSTP;
#if defined(ADC_CR_JADSTART)
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
	return !(ADC_CR(adc) & ADC_CR_ADEN);
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
 * Start the ADC calibration and immediately return.
 * @sa adc_calibrate
 * @sa adc_is_calibrating
 * @param adc ADC Block register address base @ref adc_reg_base
 */
void adc_calibrate_async(uint32_t adc)
{
	ADC_CR(adc) |= ADC_CR_ADCAL;
}

/**
 * Is the ADC Calibrating?
 * @param adc ADC Block register address base @ref adc_reg_base
 * @return true if the adc is currently calibrating
 */
bool adc_is_calibrating(uint32_t adc)
{
	return ADC_CR(adc) & ADC_CR_ADCAL;
}

/**
 * Start ADC calibration and wait for it to finish
 * @param adc ADC Block register address base @ref adc_reg_base
 */
void adc_calibrate(uint32_t adc)
{
	adc_calibrate_async(adc);
	while (adc_is_calibrating(adc));
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

/** @brief ADC Set Resolution
 *
 * ADC Resolution can be reduced from 12 bits to 10, 8 or 6 bits for a
 * corresponding reduction in conversion time.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 * @param[in] resolution Unsigned int16. Resolution value (@ref adc_api_res)
 */
void adc_set_resolution(uint32_t adc, uint16_t resolution)
{
	ADC_CFGR1(adc) = (ADC_CFGR1(adc) & ~ADC_CFGR1_RES_MASK) | resolution;
}

/** @brief ADC Set the Data as Left Aligned
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_set_left_aligned(uint32_t adc)
{
	ADC_CFGR1(adc) |= ADC_CFGR1_ALIGN;
}

/** @brief ADC Set the Data as Right Aligned
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_set_right_aligned(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_ALIGN;
}

/** @brief ADC Enable DMA Transfers
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_enable_dma(uint32_t adc)
{
	ADC_CFGR1(adc) |= ADC_CFGR1_DMAEN;
}

/** @brief ADC Disable DMA Transfers
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_disable_dma(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_DMAEN;
}

/** @brief ADC Enable the Overrun Interrupt
 *
 * The overrun interrupt is generated when data is not read from a result
 * register before the next conversion is written. If DMA is enabled, all
 * transfers are terminated and any conversion sequence is aborted.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_enable_overrun_interrupt(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_OVRIE;
}

/** @brief ADC Disable the Overrun Interrupt
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_disable_overrun_interrupt(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_OVRIE;
}

/** @brief ADC Read the Overrun Flag
 *
 * The overrun flag is set when data is not read from a result register before
 * the next conversion is written. If DMA is enabled, all transfers are
 * terminated and any conversion sequence is aborted.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
bool adc_get_overrun_flag(uint32_t adc)
{
	return ADC_ISR(adc) & ADC_ISR_OVR;
}

/** @brief ADC Clear Overrun Flags
 *
 * The overrun flag is cleared. Note that if an overrun occurs, DMA is
 * terminated.
 * The flag must be cleared and the DMA stream and ADC reinitialised to resume
 * conversions (see the reference manual).
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_clear_overrun_flag(uint32_t adc)
{
	ADC_ISR(adc) = ADC_ISR_OVR;
}

/** @brief ADC Enable Regular End-Of-Conversion Interrupt
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_enable_eoc_interrupt(uint32_t adc)
{
	ADC_IER(adc) |= ADC_IER_EOCIE;
}

/** @brief ADC Disable Regular End-Of-Conversion Interrupt
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_disable_eoc_interrupt(uint32_t adc)
{
	ADC_IER(adc) &= ~ADC_IER_EOCIE;
}

/** @brief ADC Read from the Regular Conversion Result Register
 *
 * The result read back is 12 bits, right or left aligned within the first
 * 16 bits.
 *
 * @param[in] adc Unsigned int32. ADC block register address base
 * @ref adc_reg_base
 * @returns Unsigned int32 conversion result.
 */
uint32_t adc_read_regular(uint32_t adc)
{
	return ADC_DR(adc);
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

/** @brief ADC Software Triggered Conversion on Regular Channels
 *
 * This starts conversion on a set of defined regular channels.
 * Depending on the configuration bits EXTEN, a conversion will start
 * immediately (software trigger configuration) or once a regular hardware
 * trigger event occurs (hardware trigger configuration)
 *
 * @param[in] adc ADC block register address base @ref adc_reg_base
 */
void adc_start_conversion_regular(uint32_t adc)
{
	/* Start conversion on regular channels. */
	ADC_CR(adc) |= ADC_CR_ADSTART;
}

/** @brief Enable circular mode for DMA transfers
 *
 * For this to work it needs to be ebabled on the DMA side as well.
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_enable_dma_circular_mode(uint32_t adc)
{
	ADC_CFGR1(adc) |= ADC_CFGR1_DMACFG;
}

/** @brief Disable circular mode for DMA transfers
 *
 * @param[in] adc Unsigned int32. ADC base address (@ref adc_reg_base)
 */
void adc_disable_dma_circular_mode(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_DMACFG;
}

/** Enable Delayed Conversion Mode.
 *
 * @param[in] adc ADC block register address base @ref adc_reg_base
 */
void adc_enable_delayed_conversion_mode(uint32_t adc)
{
	ADC_CFGR1(adc) |= ADC_CFGR1_AUTDLY;
}

/** Enable Delayed Conversion Mode.
 *
 * @param[in] adc ADC block register address base @ref adc_reg_base
 */
void adc_disable_delayed_conversion_mode(uint32_t adc)
{
	ADC_CFGR1(adc) &= ~ADC_CFGR1_AUTDLY;
}

/**@}*/
