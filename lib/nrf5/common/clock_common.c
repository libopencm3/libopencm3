/** @addtogroup clock_file

@author @htmlonly &copy; @endhtmlonly 2018 
Gerrit Maus <funk@maus.xyz>
Luong Le <novercy@live.com>

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

#include <libopencm3/nrf5/clock.h>

/*---------------------------------------------------------------------------*/
/** @brief Clock Start HFCLK.

Start HFCLK crystal oscillator and blocking until HFCLK has been started
*/

void clock_hfclk_start(void)
{
	CLOCK_TASKS_HFCLKSTART = 1;
	while(CLOCK_EVENTS_HFCLKSTARTED == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Stop HFCLK.

Stop HFCLK crystal oscillator
*/

void clock_hfclk_stop(void)
{
	CLOCK_TASKS_HFCLKSTOP = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Start LFCLK.

Start LFCLK crystal oscillator and blocking until LFCLK has been started
*/

void clock_lfclk_start(void)
{
	CLOCK_TASKS_LFCLKSTART = 1;
	while(CLOCK_EVENTS_LFCLKSTARTED == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Stop LFCLK.

Stop LFCLK crystal oscillator. The LFCLKSTOP task can only be triggered after 
the STATE field in register LFCLKSTAT indicates a 'LFCLK running' state
*/

void clock_lfclk_stop(void)
{
	if(CLOCK_LFCLKSTAT &= CLOCK_LFCLKSTAT_STATE_RUNNING)
		{CLOCK_TASKS_LFCLKSTOP = 1;}
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Set Calibration timer interval.

Calibration timer interval in multiple of 0.25 seconds.
Range: 0.25 seconds to 31.75 seconds

@param[in] interval unsigned 8 bit. Calibration timer interval in seconds
*/

void clock_cal_interval(uint8_t interval)
{
	CLOCK_CTIV = CLOCK_CTIV_CTIV(interval);
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Start Calibration.

Start calibration of LFRC oscillator
*/

void clock_cal_start(void)
{
	if(CLOCK_EVENTS_LFCLKSTARTED == 1)
	{
		CLOCK_TASKS_CAL = 1;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Calibration complete event status.

Return 1 if Calibration of LFCLK RX oscillator completed

@returns unsigned 32 bit data word.
*/

uint32_t clock_cal_done(void)
{
	return CLOCK_EVENTS_DONE;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Reset Calibration complete event.

Clear Calibration complete event register
*/

void clock_cal_reset(void)
{
	CLOCK_EVENTS_DONE = 0;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Start calibration timer.

*/

void clock_ct_start(void)
{
	CLOCK_TASKS_CTSTART = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Stop calibration timer.

*/

void clock_ct_stop(void)
{
	CLOCK_TASKS_CTSTOP = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Calibration timer timeout status.

Return 1 if the calibration timer reached 0

@returns unsigned 32 bit data word.
*/

uint32_t clock_ct_timeout(void)
{
	return CLOCK_EVENTS_CTTO;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Reset Calibration timer timeout.

Clear Calibration timer timeout register and ready to indicates status of the 
next counting
*/

void clock_ct_timeout_reset(void)
{
	CLOCK_EVENTS_CTTO = 0;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock HFCLK triggering status.

Status indicating that HFCLKSTART task has been triggered

@returns unsigned 32 bit data word.
*/

uint32_t clock_hfclk_trigger_status(void)
{
	return CLOCK_HFCLKRUN;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock LFCLK triggering status.

Status indicating that LFCLKSTART task has been triggered

@returns unsigned 32 bit data word.
*/

uint32_t clock_lfclk_trigger_status(void)
{
	return CLOCK_LFCLKRUN;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock HFCLK source status.

Status indicating which source of HFCLK was selected.
Return 0 if 64MHz internal oscillator (RC) and 1 if 64MHz crystal oscillator
(Xtal)

@returns unsigned 32 bit data word.
*/

uint16_t clock_hfclk_run_status(void)
{
	return (CLOCK_HFCLKSTAT >> 16);
}

/*---------------------------------------------------------------------------*/
/** @brief Clock LFCLK source status.

Status indicating which source of LFCLK was selected.
Return 0 if 32.768 kHz RC oscillator (RC), 1 if 32.768 kHz crystal oscillator
(Xtal) and 2 if 32.768 kHz synthesized from HFCLK

@returns unsigned 32 bit data word.
*/

uint16_t clock_lfclk_run_status(void)
{
	return (CLOCK_LFCLKSTAT >> 16);
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Select Source for LFCLK.

Select Clock source for the LFCLK. source can be selected as RC, XTAL, or
SYNTH.

@param[in] source unsigned 32 bit. predetermined source names @ref 
clock_lfclksrc
*/

void clock_lfclk_source(char source)
{
	if(source & RC){CLOCK_LFCLKSRC |= CLOCK_LFCLKSRC_SRC_RC;}
	else if(source & XTAL){CLOCK_LFCLKSRC |= CLOCK_LFCLKSRC_SRC_XTAL;}
	else if(source & SYNTH){CLOCK_LFCLKSRC |= CLOCK_LFCLKSRC_SRC_SYNTH;}
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Enable bypass of LFCLK with external source.

If Bypass enabled, LFCLK crystal oscillator will use rail-to-rail external
source
*/

void clock_lfclk_extsource_bypass(void)
{
	CLOCK_LFCLKSRC |= CLOCK_LFCLKSRC_BYPASS_ENABLED;
}

/*---------------------------------------------------------------------------*/
/** @brief Clock Enable LFCLK external source.

*/

void clock_lfclk_extsource_enable(void)
{
	CLOCK_LFCLKSRC |= CLOCK_LFCLKSRC_EXTERNAL_ENABLED;
}


/**@}*/
