/** @addtogroup adc_file ADC peripheral API
 * @ingroup peripheral_apis
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#include <libopencm3/efm32/adc.h>

/**@{*/

/**
 * Set ADC over sampling
 * @param[in] adc ADC (use ADCx)
 * @param[in] oversamp Oversampling (use ADC_CTRL_OVERSEL_Xx)
 */
void adc_set_oversampling(uint32_t adc, uint32_t oversamp)
{
	ADC_CTRL(adc) = (ADC_CTRL(adc) & ~ADC_CTRL_OVERSEL_MASK) | oversamp;
}

/**
 * Set ADC warm up
 * @param[in] adc ADC (use ADCx)
 * @param[in] clocks Clock cycles (1 - 128)
 * @note warm-up-time = (@a clocks / HFPERCLK)
 */
void adc_set_warm_up(uint32_t adc, uint8_t clocks)
{
	uint32_t timebase = ADC_CTRL_TIMEBASE(clocks - 1);
	ADC_CTRL(adc) = (ADC_CTRL(adc) & ~ADC_CTRL_TIMEBASE_MASK) | timebase;
}

/** Clock division factor
 * @param[in] adc ADC (use ADCx)
 * @param[in] factor Factor (1 - 128)
 * @note output-clock = input-clock / @a factor
 */
void adc_set_clock_prescaler(uint32_t adc, uint8_t factor)
{
	uint32_t presc = ADC_CTRL_PRESC(factor - 1);
	ADC_CTRL(adc) = (ADC_CTRL(adc) & ~ADC_CTRL_PRESC_MASK) | presc;
}

/**
 * Set low pass filter mode
 * @param[in] adc ADC (use ADCx)
 * @param[in] lpfmode Low pass filter mode (use ADC_CTRL_LPFMODE_*)
 */
void adc_set_lowpass_filter(uint32_t adc, uint32_t lpfmode)
{
	ADC_CTRL(adc) = (ADC_CTRL(adc) & ~ADC_CTRL_LPFMODE_MASK) | lpfmode;
}

/**
 * Enable tail gating
 * @param[in] adc ADC (use ADCx)
 */
void adc_enable_tailgating(uint32_t adc)
{
	ADC_CTRL(adc) |= ADC_CTRL_TAILGATE;
}

/**
 * Disable tail gating
 * @param[in] adc ADC (use ADCx)
 */
void adc_disable_tailgating(uint32_t adc)
{
	ADC_CTRL(adc) &= ~ADC_CTRL_TAILGATE;
}

/**
 * Set warm up mode
 * @param[in] adc ADC (use ADCx)
 * @param[in] warmupmode Warm Up Mode (use ADC_CTRL_WARMUPMODE_*)
 */
void adc_set_warm_up_mode(uint32_t adc, uint32_t warmupmode)
{
	ADC_CTRL(adc) = (ADC_CTRL(adc) & ~ADC_CTRL_WARMUPMODE_MASK)
			| warmupmode;
}

/**
 * Start ADC in single acquisition
 * @param[in] adc ADC (use ADCx)
 */
void adc_single_start(uint32_t adc)
{
	ADC_CMD(adc) = ADC_CMD_SINGLESTART;
}

/**
 * Stop ADC in single acquisition
 * @param[in] adc ADC (use ADCx)
 */
void adc_single_stop(uint32_t adc)
{
	ADC_CMD(adc) = ADC_CMD_SINGLESTOP;
}

/**
 * Start ADC in scan acquisition
 * @param[in] adc ADC (use ADCx)
 */
void adc_scan_start(uint32_t adc)
{
	ADC_CMD(adc) = ADC_CMD_SCANSTART;
}

/**
 * Stop ADC in scan acquisition
 * @param[in] adc ADC (use ADCx)
 */
void adc_scan_stop(uint32_t adc)
{
	ADC_CMD(adc) = ADC_CMD_SCANSTOP;
}

/* Single ----------------------------------------------------------- */
/**
 * Set single PRS trigger
 * @param[in] adc ADC (use ADCx)
 * @param[in] prssel PRS Selected (use PRS_CHx)
 */
void adc_set_single_prs_trigger(uint32_t adc, uint8_t prssel)
{
	ADC_SINGLECTRL(adc) =
		(ADC_SINGLECTRL(adc) & ~ADC_SINGLECTRL_PRSSEL_MASK) |
		(ADC_SINGLECTRL_PRSSEL_PRSCHx(prssel));
}

/**
 * Enable single PRS Triggering
 * @param[in] adc ADC (use ADCx)
 */
void adc_enable_single_prs_trigger(uint32_t adc)
{
	ADC_SINGLECTRL(adc) |= ADC_SINGLECTRL_PRSEN;
}

/**
 * Disable single PRS Triggering
 * @param[in] adc ADC (use ADCx)
 */
void adc_disable_single_prs_trigger(uint32_t adc)
{
	ADC_SINGLECTRL(adc) &= ~ADC_SINGLECTRL_PRSEN;
}

/**
 * Set single acquisition cycle
 * @param[in] adc ADC (use ADCx)
 * @param[in] at Acquisition time (use ADC_SINGLECTRL_AT_x)
 */
void adc_set_single_acquisition_cycle(uint32_t adc, uint32_t at)
{
	ADC_SINGLECTRL(adc) =
		(ADC_SINGLECTRL(adc) & ~ADC_SINGLECTRL_AT_MASK) | at;
}

/**
 * Set single reference for acquisition
 * @param[in] adc ADC (use ADCx)
 * @param[in] ref Reference (use ADC_SINGLECTRL_REF_x)
 */
void adc_set_single_reference(uint32_t adc, uint32_t ref)
{
	ADC_SINGLECTRL(adc) =
		(ADC_SINGLECTRL(adc) & ~ADC_SINGLECTRL_REF_MASK) | ref;
}

/**
 * Set single channel
 * @param[in] adc ADC (use ADCx)
 * @param[in] ch Channel (use ADC_CHx and ADC_CH_*)
 */
void adc_set_single_channel(uint32_t adc, uint8_t ch)
{
	ADC_SINGLECTRL(adc) =
		(ADC_SINGLECTRL(adc) & ~ADC_SINGLECTRL_INPUTSEL_MASK) |
		ADC_SINGLECTRL_INPUTSEL(ch);
}

/**
 * Set single resolution of conversion
 * @param[in] adc ADC (use ADCx)
 * @param[in] res Resolution (use ADC_SINGLECTRL_RES_*)
 */
void adc_set_single_resolution(uint32_t adc, uint32_t res)
{
	ADC_SINGLECTRL(adc) =
		(ADC_SINGLECTRL(adc) & ~ADC_SINGLECTRL_RES_MASK) | res;
}

/**
 * Set single left aligned output
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_single_left_aligned(uint32_t adc)
{
	ADC_SINGLECTRL(adc) |= ADC_SINGLECTRL_ADJ;
}

/**
 * Set single right aligned output
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_single_right_aligned(uint32_t adc)
{
	ADC_SINGLECTRL(adc) &= ~ADC_SINGLECTRL_ADJ;
}

/**
 * Set single single-ended conversion
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_single_single_ended(uint32_t adc)
{
	ADC_SINGLECTRL(adc) &= ~ADC_SINGLECTRL_DIFF;
}

/**
 * Set single differential conversion
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_single_differential(uint32_t adc)
{
	ADC_SINGLECTRL(adc) |= ADC_SINGLECTRL_DIFF;
}

/**
 * Enable single channel repeated conversion
 * @param[in] adc ADC (use ADCx)
 */
void adc_enable_single_repeat_conv(uint32_t adc)
{
	ADC_SINGLECTRL(adc) |= ADC_SINGLECTRL_REP;
}

/**
 * Disable single repeated conversion
 * @param[in] adc ADC (use ADCx)
 */
void adc_disable_single_repeat_conv(uint32_t adc)
{
	ADC_SINGLECTRL(adc) &= ~ADC_SINGLECTRL_REP;
}

/* Scan ------------------------------------------------------------- */
/**
 * Set scan PRS trigger
 * @param[in] adc ADC (use ADCx)
 * @param[in] prssel PRS Selected (use PRS_CHx)
 */
void adc_set_scan_prs_trigger(uint32_t adc, uint8_t prssel)
{
	ADC_SCANCTRL(adc) =
		(ADC_SCANCTRL(adc) & ~ADC_SCANCTRL_PRSSEL_MASK) |
		ADC_SCANCTRL_PRSSEL_PRSCHx(prssel);
}

/**
 * Enable scan PRS Triggering
 * @param[in] adc ADC (use ADCx)
 */
void adc_enable_scan_prs_trigger(uint32_t adc)
{
	ADC_SCANCTRL(adc) |= ADC_SCANCTRL_PRSEN;
}

/**
 * Disable scan PRS Triggering
 * @param[in] adc ADC (use ADCx)
 */
void adc_disable_scan_prs_trigger(uint32_t adc)
{
	ADC_SCANCTRL(adc) &= ~ADC_SCANCTRL_PRSEN;
}

/**
 * Set scan acquisition cycle
 * @param[in] adc ADC (use ADCx)
 * @param[in] at Acquisition time (use ADC_SCANCTRL_AT_x)
 */
void adc_set_scan_acquisition_cycle(uint32_t adc, uint32_t at)
{
	ADC_SCANCTRL(adc) =
		(ADC_SCANCTRL(adc) & ~ADC_SCANCTRL_AT_MASK) | at;
}

/**
 * Set scan reference for acquisition
 * @param[in] adc ADC (use ADCx)
 * @param[in] ref Reference (use ADC_SCANCTRL_REF_x)
 */
void adc_set_scan_reference(uint32_t adc, uint32_t ref)
{
	ADC_SCANCTRL(adc) =
		(ADC_SCANCTRL(adc) & ~ADC_SCANCTRL_REF_MASK) | ref;
}

/**
 * Set scan channel list
 * @param[in] adc ADC (use ADCx)
 * @param[in] length Length of @a channel
 * @param[in] channel channel list (use ADC_CHx)
 * @note channel[0] is used as single acuqisition
 */
void adc_set_scan_channel(uint32_t adc, uint8_t length, uint8_t channel[])
{
	unsigned i;
	uint32_t val = 0;

	for (i = 0; i < length; i++) {
		val |= 1 << (channel[i] + ADC_SCANCTRL_INPUTSEL_SHIFT);
	}

	ADC_SCANCTRL(adc) =
		(ADC_SCANCTRL(adc) & ~ADC_SCANCTRL_INPUTSEL_MASK) |
		(val & ADC_SCANCTRL_INPUTSEL_MASK);
}

/**
 * Set scan resolution of conversion
 * @param[in] adc ADC (use ADCx)
 * @param[in] res Resolution (use ADC_SCANCTRL_RES_*)
 */
void adc_set_scan_resolution(uint32_t adc, uint32_t res)
{
	ADC_SCANCTRL(adc) =
		(ADC_SCANCTRL(adc) & ~ADC_SCANCTRL_RES_MASK) | res;
}

/**
 * Set scan left aligned output
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_scan_left_aligned(uint32_t adc)
{
	ADC_SCANCTRL(adc) |= ADC_SCANCTRL_ADJ;
}

/**
 * Set scan right aligned output
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_scan_right_aligned(uint32_t adc)
{
	ADC_SCANCTRL(adc) &= ~ADC_SCANCTRL_ADJ;
}

/**
 * Set scan single ended conversion
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_scan_single_ended(uint32_t adc)
{
	ADC_SCANCTRL(adc) &= ~ADC_SCANCTRL_DIFF;
}

/**
 * Set scan differential conversion
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_scan_differential(uint32_t adc)
{
	ADC_SCANCTRL(adc) |= ADC_SCANCTRL_DIFF;
}

/**
 * Enable scan repeated conversion
 * @param[in] adc ADC (use ADCx)
 * @note In SINGLE mode, channel is repeated
 * @note In SCAN mode, channel sequence is repeated
 */
void adc_enable_scan_repeat_conv(uint32_t adc)
{
	ADC_SCANCTRL(adc) |= ADC_SCANCTRL_REP;
}

/**
 * Disable scan repeated conversion
 * @param[in] adc ADC (use ADCx)
 */
void adc_disable_scan_repeat_conv(uint32_t adc)
{
	ADC_SCANCTRL(adc) &= ~ADC_SCANCTRL_REP;
}

/**
 * Enable single result overflow interrupt
 * @param[in] adc ADC (use ADCx)
 */
void adc_enable_single_result_overflow_interrupt(uint32_t adc)
{
	ADC_IEN(adc) |= ADC_IEN_SINGLEOF;
}

/**
 * Disable single result overflow interrupt
 * @param[in] adc ADC (use ADCx)
 */
void adc_disable_single_result_overflow_interrupt(uint32_t adc)
{
	ADC_IEN(adc) &= ~ADC_IEN_SINGLEOF;
}

/**
 * Enable single conversion complete interrupt
 * @param[in] adc ADC (use ADCx)
 */
void adc_enable_single_conversion_complete_interrupt(uint32_t adc)
{
	ADC_IEN(adc) |= ADC_IEN_SINGLE;
}

/**
 * Disable single conversion complete interrupt
 * @param[in] adc ADC (use ADCx)
 */
void adc_disable_single_conversion_complete_interrupt(uint32_t adc)
{
	ADC_IEN(adc) &= ~ADC_IEN_SINGLE;
}

/**
 * Enable scan result overflow interrupt
 * @param[in] adc ADC (use ADCx)
 */
void adc_enable_scan_result_overflow_interrupt(uint32_t adc)
{
	ADC_IEN(adc) |= ADC_IEN_SCANOF;
}

/**
 * Disable scan result overflow interrupt
 * @param[in] adc ADC (use ADCx)
 */
void adc_disable_scan_result_overflow_interrupt(uint32_t adc)
{
	ADC_IEN(adc) &= ~ADC_IEN_SCANOF;
}

/**
 * Disable scan conversion complete interrupt
 * @param[in] adc ADC (use ADCx)
 */
void adc_enable_scan_conversion_complete_interrupt(uint32_t adc)
{
	ADC_IEN(adc) |= ADC_IEN_SCAN;
}

/**
 * Disable scan conversion complete interrupt
 * @param[in] adc ADC (use ADCx)
 */
void adc_disable_scan_conversion_complete_interrupt(uint32_t adc)
{
	ADC_IEN(adc) &= ~ADC_IEN_SCAN;
}

/**
 * Get single result overflow flag
 * @param[in] adc ADC (use ADCx)
 * @retval true if flag set
 * @retval false if flag is not set
 */
bool adc_get_single_result_overflow_flag(uint32_t adc)
{
	return (ADC_IF(adc) & ADC_IF_SCANOF) != 0;
}

/**
 * Get single conversion complete flag
 * @param[in] adc ADC (use ADCx)
 * @retval true if flag set
 * @retval false if flag is not set
 */
bool adc_get_single_conversion_complete_flag(uint32_t adc)
{
	return (ADC_IF(adc) & ADC_IF_SINGLE) != 0;
}

/**
 * Get scan result overflow flag
 * @param[in] adc ADC (use ADCx)
 * @retval true if flag set
 * @retval false if flag is not set
 */
bool adc_get_scan_result_overflow_flag(uint32_t adc)
{
	return (ADC_IF(adc) & ADC_IF_SCANOF) != 0;
}

/**
 * Get scan conversion complete flag
 * @param[in] adc ADC (use ADCx)
 * @retval true if flag is set
 * @retval false if flag is not set
 */
bool adc_get_scan_conversion_complete_flag(uint32_t adc)
{
	return (ADC_IF(adc) & ADC_IF_SCAN) != 0;
}

/**
 * Set single result overflow flag
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_single_result_overflow_flag(uint32_t adc)
{
	ADC_IFS(adc) = ADC_IFS_SINGLEOF;
}

/**
 * Set single conversion complete flag
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_single_conversion_complete_flag(uint32_t adc)
{
	ADC_IFS(adc) = ADC_IFS_SINGLE;
}

/**
 * Set scan result overflow flag
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_scan_result_overflow_flag(uint32_t adc)
{
	ADC_IFS(adc) = ADC_IFS_SCANOF;
}

/**
 * Set scan conversion complete flag
 * @param[in] adc ADC (use ADCx)
 */
void adc_set_scan_conversion_complete_flag(uint32_t adc)
{
	ADC_IFS(adc) = ADC_IFS_SCAN;
}

/**
 * Clear single result overflow flag
 * @param[in] adc ADC (use ADCx)
 */
void adc_clear_single_result_overflow_flag(uint32_t adc)
{
	ADC_IFC(adc) = ADC_IFC_SINGLEOF;
}

/**
 * Clear single conversion complete flag
 * @param[in] adc ADC (use ADCx)
 */
void adc_clear_single_conversion_complete_flag(uint32_t adc)
{
	ADC_IFC(adc) = ADC_IFC_SINGLE;
}

/**
 * Clear scan result overflow flag
 * @param[in] adc ADC (use ADCx)
 */
void adc_clear_scan_result_overflow_flag(uint32_t adc)
{
	ADC_IFC(adc) = ADC_IFC_SCANOF;
}

/**
 * Clear scan conversion complete flag
 * @param[in] adc ADC (use ADCx)
 */
void adc_clear_scan_conversion_complete_flag(uint32_t adc)
{
	ADC_IFC(adc) = ADC_IFC_SCAN;
}

/**
 * Get result from last scan conversion
 * @param[in] adc ADC (use ADCx)
 * @return result
 */
uint32_t adc_single_data(uint32_t adc)
{
	return ADC_SINGLEDATA(adc);
}

/**
 * Get result from last scan conversion
 * @param[in] adc ADC (use ADCx)
 * @return result
 */
uint32_t adc_scan_data(uint32_t adc)
{
	return ADC_SCANDATA(adc);
}

/**
 * Get result from last single conversion (peak)
 * Reading result using this function will not clear
 *   SINGLEDV in ADC_STATUS or SINGLE DMA request.
 * @param[in] adc ADC (use ADCx)
 * @return result
 */
uint32_t adc_single_data_peak(uint32_t adc)
{
	return ADC_SINGLEDATAP(adc);
}

/**
 * Get result from last scan conversion (peak)
 * Reading result using this function will not clear
 *   SCANDV in ADC_STATUS or SCAN DMA request.
 * @param[in] adc ADC (use ADCx)
 * @return result
 */
uint32_t adc_scan_data_peak(uint32_t adc)
{
	return ADC_SCANDATAP(adc);
}

/**
 * Set ADC scan gain calibration
 * @param[in] adc ADC (use ADCx)
 * @param scan_gain calibration of gain for internal ref
 */
void adc_set_calibration_scan_gain(uint32_t adc, uint8_t scan_gain)
{
	ADC_CAL(adc) = (ADC_CAL(adc) & ADC_CAL_SCANGAIN_MASK) | scan_gain;
}

/**
 * Set ADC scan offset calibration
 * @param[in] adc ADC (use ADCx)
 * @param scan_offset calibration of offset for internal ref
 */
void adc_set_calibration_scan_offset(uint32_t adc, uint8_t scan_offset)
{
	ADC_CAL(adc) = (ADC_CAL(adc) & ADC_CAL_SCANOFF_MASK) | scan_offset;
}

/**
 * Set ADC single gain calibration
 * @param[in] adc ADC (use ADCx)
 * @param single_gain calibration of gain for internal ref
 */
void adc_set_calibration_single_gain(uint32_t adc, uint8_t single_gain)
{
	ADC_CAL(adc) = (ADC_CAL(adc) & ADC_CAL_SINGLEGAIN_MASK) | single_gain;
}

/**
 * Set ADC single offset calibration
 * @param[in] adc ADC (use ADCx)
 * @param single_offset calibration of offset for internal ref
 */
void adc_set_calibration_single_offset(uint32_t adc, uint8_t single_offset)
{
	ADC_CAL(adc) = (ADC_CAL(adc) & ADC_CAL_SINGLEOFF_MASK) | single_offset;
}

/**@}*/