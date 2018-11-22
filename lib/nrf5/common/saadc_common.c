/** @addtogroup saadc_file

@author @htmlonly &copy; @endhtmlonly 2018 
Gerrit Maus <funk@maus.xyz>
Luong Le <novercy@live.com>

This library supports the SAADC in the NRF52 series.

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Gerrit Maus <funk@maus.xyz>
 * Copyright (C) 2018 Luong Le <novercy@live.com>
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

#include <libopencm3/nrf5/saadc.h>

/*---------------------------------------------------------------------------*/
/** @brief SAADC Select positive Pin.

Up to eight analog input channels can be configured.
Input positive pin pselp can be selected as NC (Not Connected), AIN0, ...,AIN8
and VDD.
If more than one of the CH[n].PSELP registers is set, the device enters scan 
mode.

@param[in] channel unsigned 8 bit. ADC channel selection
@param[in] pselp unsigned 32 bit. Pin identifiers @ref saadc_pin_id
*/

void saadc_pin_pos(uint8_t channel, uint32_t pselp)
{
	SAADC_CH[channel].PSELP = pselp;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Select negative Pin.

Input negative pin pseln can be selected as NC (Not Connected), AIN0, ...,AIN8
and VDD.
In scan mode, CH[n].PSELN is only used if the particular scan channel is 
specified as differential.

@param[in] channel unsigned 8 bit. ADC channel selection
@param[in] pseln unsigned 32 bit. Pin identifiers @ref saadc_pin_id
*/

void saadc_pin_neg(uint8_t channel, uint32_t pseln)
{
	SAADC_CH[channel].PSELN = pseln;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Set resistor for positive input.

Positive channel resistor can be selected as RESP_BYPASS for bypass resistor
ladder, RESP_PULLDOWN, RESP_PULLUP for pull-down to GND or pull-up to VDD, and
RESP_VDD1_2 for setting up input at VDD/2.

@param[in] channel unsigned 8 bit. ADC channel selection
@param[in] resp unsigned 32 bit. Resistor ladder @ref saadc_ch_config
*/

void saadc_resistor_pos(uint8_t channel, uint32_t resp)
{
	SAADC_CH[channel].CONFIG |= resp;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Set resistor for negative input.

Negative channel resistor can be selected as RESN_BYPASS for bypass resistor
ladder, RESN_PULLDOWN, RESN_PULLUP for pull-down to GND or pull-up to VDD, and
RESN_VDD1_2 for setting up input at VDD/2.

@param[in] channel unsigned 8 bit. ADC channel selection
@param[in] resn unsigned 32 bit. Resistor ladder @ref saadc_ch_config
*/

void saadc_resistor_neg(uint8_t channel, uint32_t resn)
{
	SAADC_CH[channel].CONFIG |= resn;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Gain control.

Gain can be selected as GAIN1_6, GAIN1_5, GAIN1_4, GAIN1_3, GAIN1_2, GAIN1, 
GAIN2, GAIN4

@param[in] channel unsigned 8 bit. ADC channel selection
@param[in] gain unsigned 32 bit. Gain control @ref saadc_ch_config
*/

void saadc_gain(uint8_t channel, uint32_t gain)
{
	SAADC_CH[channel].CONFIG |= gain;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Reference control.

refsel can be selected as REFSEL_INTERNAL for internal reference (±0.6 V), 
or REFSEL_VDD1_4 for VDD as reference (±VDD/4 on the ADC core).
Input rance = (± 0.6V or ± VDD/4) / Gain.

@param[in] channel unsigned 8 bit. ADC channel selection
@param[in] refsel unsigned 32 bit. Reference control @ref saadc_ch_config
*/

void saadc_set_reference(uint8_t channel, uint32_t refsel)
{
	SAADC_CH[channel].CONFIG |= refsel;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Set acquisition time.

Set acquisition time, the time the ADC uses to sample the input
tacq can be set as TACQ_3US (for an acquisition time of 3us), TACQ_5US, 
TACQ_10US, TACQ_15US, TACQ_20US, or TACQ_40US

@param[in] channel unsigned 8 bit. ADC channel selection
@param[in] tacq unsigned 32 bit. Acquisition time @ref saadc_ch_config
*/

void saadc_acquisition_time(uint8_t channel, uint32_t tacq)
{
	SAADC_CH[channel].CONFIG |= tacq;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Select mode.

Select reference mode. Mode can be selected as MODE_DIFF (Differential) or 
MODE_SE (Singe ended, PSELN will be ignored, negative input to ADC shorted to 
GND)

@param[in] channel unsigned 8 bit. ADC channel selection
@param[in] mode unsigned 32 bit. Reference mode @ref saadc_ch_config
*/

void saadc_differential_mode(uint8_t channel, uint32_t mode)
{
	SAADC_CH[channel].CONFIG |= mode;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Enable burst mode.

If Burst mode enabled, SAADC will takes 2^OVERSAMPLE number of samples as 
fast as it can, and sends the average to Data RAM.

@param[in] channel unsigned 8 bit. ADC channel selection
*/

void saadc_burst_enable(uint8_t channel)
{
	SAADC_CH[channel].CONFIG |= SAADC_CH_CONFIG_BURST_ENABLED;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Set limit.

Set high and low limit for event monitoring a channel.
Each limit can be set from -32768 to +32767

@param[in] channel unsigned 8 bit. ADC channel selection
@param[in] low signed 16 bit. Low limit @ref saadc_ch_limit
@param[in] high signed 16 bit. High limit @ref saadc_ch_limit
*/

void saadc_limit(uint8_t channel, int16_t low, int16_t high)
{
	SAADC_CH[channel].LIMIT |= SAADC_CH_LIMIT_LOW(low) |
	                           SAADC_CH_LIMIT_HIGH(high);
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Set resolution.

Resolution can be set as 8, 10, 12 or 14 bit.

@param[in] res unsigned 8 bit. ADC Resolution @ref saadc_resolution
*/

void saadc_resolution(uint8_t res)
{
	SAADC_RESOLUTION = SAADC_RESOLUTION_VAL(res);
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Oversample configuration.

Oversample should not be combined with scan mode.
The parameter oversample can be selected as BYPASS (for bypass oversampling), 
OVER2X (oversample 2x), OVER4X, OVER8X, OVER16X, OVER32X, OVER64X, OVER128X, 
OVER256X

@param[in] oversample unsigned 32 bit. Oversample @ref saadc_oversample
*/

void saadc_oversample(uint32_t oversample)
{
	SAADC_OVERSAMPLE = oversample;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Set capture/compare and sample rate.

CC value can be set from 80 to 2047. Sample rate is 16MHz/CC.
Sample rate mode can be selected as MODE_TASK or MODE_TIMERS. If Task mode 
enabled, the Rate will be controlled from SAMPLE task. If Timer mode enabled, 
the Rate will be controlled from local timer.
The timer mode cannot be combined with scan mode.

@param[in] cc unsigned 16 bit. Capture/Compare value
@param[in] oversample unsigned 32 bit. SAMPLERATE mode @ref saadc_samplerate
*/

void saadc_samplerate(uint16_t cc, uint32_t mode)
{
	SAADC_SAMPLERATE |= SAADC_SAMPLERATE_CC(cc) | mode;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Address pointer and size for Result buffer configuration.

Since EasyDMA is used to store results in a Result buffer in RAM, the Result 
buffer address and size should be configured before start ADC.
The RESULT.PTR register is double-buffered and it can be updated and prepared 
for the next START task immediately.

@param[in] *ptr unsigned 8 bit. Address pointer of Result buffer
@param[in] maxcnt unsigned 16 bit. Maximum number of buffer words to transfer
*/

void saadc_result_buffer(uint32_t *ptr, uint16_t maxcnt)
{
	SAADC_RESULT.PTR = (uint32_t) ptr;
	SAADC_RESULT.MAXCNT = (uint32_t) maxcnt;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Enable ADC.

Enable ADC
*/

void saadc_enable(void)
{
	SAADC_ENABLE = SAADC_ENABLE_ENABLE_ENABLED;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Disable ADC.

Disable ADC
*/

void saadc_disable(void)
{
	SAADC_ENABLE = SAADC_ENABLE_ENABLE_DISABLED;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Start sampling.

Start sampling process and block until the ADC has filled uo the Result buffer
*/

void saadc_sample_start(void)
{
	SAADC_TASKS_SAMPLE = 1;
	while(SAADC_EVENTS_END == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Start ADC.

Start ADC and block until the ADC has started
*/

void saadc_start(void)
{
	SAADC_TASKS_START = 1;
	while(SAADC_EVENTS_STARTED == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Stop ADC.

Stop ADC and block until the ADC has stopped
*/

void saadc_stop(void)
{
	SAADC_TASKS_STOP = 1;
	while(SAADC_EVENTS_STOPPED == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC High limit status.

Return 1 if the result reached high limit

@param[in] channel unsigned 8 bit. ADC channel selection
@returns unsigned 32 bit data word.
*/

uint32_t saadc_limit_high(uint8_t channel)
{
	return SAADC_EVENTS_CH_LIMITH[channel];
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Low limit status.

Return 1 if the result reached low limit

@param[in] channel unsigned 8 bit. ADC channel selection
@returns unsigned 32 bit data word.
*/

uint32_t saadc_limit_low(uint8_t channel)
{
	return SAADC_EVENTS_CH_LIMITL[channel];
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Reset limit events.

Clear high/low limit event

@param[in] channel unsigned 8 bit. ADC channel selection
*/

void saadc_limit_reset(uint8_t channel)
{
	SAADC_EVENTS_CH_LIMITH[channel] = 0;
	SAADC_EVENTS_CH_LIMITL[channel] = 0;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC Sampling process status.

Return 1 if the sampling process is done and the ADC has filled up the Result
buffer.

@returns unsigned 32 bit data word.
*/

uint32_t saadc_sample_end(void)
{
	return SAADC_EVENTS_END;
}

/*---------------------------------------------------------------------------*/
/** @brief SAADC ADC status.

Return 1 if ADC is budy, conversion in progress.

@returns unsigned 32 bit data word.
*/

uint32_t saadc_status(void)
{
	return SAADC_STATUS;
}


/**@}*/
