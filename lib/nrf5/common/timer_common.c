/** @addtogroup timer_file

@author @htmlonly &copy; @endhtmlonly 2018 
Gerrit Maus <funk@maus.xyz>
Luong Le <novercy@live.com>

This library supports the Timer in the NRF52 series.

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

#include <libopencm3/nrf5/timer.h>


/*---------------------------------------------------------------------------*/
/** @brief Timer Start.

Start Timer

@param[in] timer unsigned 32 bit. Timer block register address base @ref
 timer_reg_base
*/

void timer_start(uint32_t timer)
{
	TIMER_TASKS_START(timer) = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Stop.

Stop Timer

@param[in] timer unsigned 32 bit. Timer block register address base @ref
 timer_reg_base
*/

void timer_stop(uint32_t timer)
{
	TIMER_TASKS_STOP(timer) = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Clear Timer.

CLEAR task takes effect within one clock cycle of the PCLK16M

@param[in] timer unsigned 32 bit. Timer block register address base @ref
 timer_reg_base
*/

void timer_clear(uint32_t timer)
{
	TIMER_TASKS_CLEAR(timer) = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Shutdown.

Shut down Timer

@param[in] timer unsigned 32 bit. Timer block register address base @ref
 timer_reg_base
*/

void timer_shutdown(uint32_t timer)
{
	TIMER_TASKS_SHUTDOWN(timer) = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Enable Capture value.

Every time the CAPTURE[n] task is triggered, the Counter value is copied to 
the CC[n] register.

@param[in] timer unsigned 32 bit. Timer block register address base @ref
 timer_reg_base
@param[in] cc. Capture/Compare Identifiers @ref timer_cc_id
*/

void timer_capture_enable(uint32_t timer, size_t cc)
{
	TIMER_TASKS_CAPTURE(timer)[cc] = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Compare value matched status.

Return 1 if the Counter reached the value specified in capture/compare 
registers

@param[in] timer unsigned 32 bit. Timer block register address base @ref 
timer_reg_base
@param[in] cc. Capture/Compare Identifiers @ref timer_cc_id
@returns unsigned 32 bit data word.
*/

uint32_t timer_compare_matched(uint32_t timer, size_t cc)
{
	return TIMER_EVENTS_COMPARE(timer)[cc];
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Reset Compare event.

Clear Compare register value and ready for the next capture/compare match

@param[in] timer unsigned 32 bit. Timer block register address base @ref 
timer_reg_base
@param[in] cc. Capture/Compare Identifiers @ref timer_cc_id
*/

void timer_compare_reset(uint32_t timer, size_t cc)
{
	TIMER_EVENTS_COMPARE(timer)[cc] = 0;
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Select Timer mode.

The Timer mode can be selected as MODE_TIMER (Timer mode), MODE_COUNTER 
(Counter mode), or MODE_LPC (Low Power Counter mode).

In Timer mode, the TIMER's internal Counter register is incremented by one 
for every tick of the timer frequency: f(Timer) = 16 MHz / (2^PRESCALER).

In counter mode, the TIMER's internal Counter register is incremented by one 
each time the COUNT task is triggered.

@param[in] timer unsigned 32 bit. Timer block register address base @ref
timer_reg_base
@param[in] mode unsigned 32 bit. Timer mode @ref timer_mode
*/

void timer_mode(uint32_t timer, uint32_t mode)
{
	if(mode & MODE_TIMER){TIMER_MODE(timer) = TIMER_MODE_MODE_TIMER;}
	if(mode & MODE_LPC){TIMER_MODE(timer) = TIMER_MODE_MODE_LPC;}
	if(mode & MODE_COUNTER)
	{
		TIMER_MODE(timer) = TIMER_MODE_MODE_COUNTER;
		TIMER_TASKS_COUNT(timer) = 1;
	}
	
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Select Bitmode.

Select the number of bits used by the Timer.
The parameter bitmode can be selected as BITMODE_8 (for 8 bit timer bit width),
BITMODE_16, BITMODE_24, or BITMODE_32

@param[in] timer unsigned 32 bit. Timer block register address base @ref
timer_reg_base
@param[in] bitmode unsigned 32 bit. Timer bitmode @ref timer_bitmode
*/

void timer_bitmode(uint32_t timer, uint32_t bitmode)
{
	TIMER_BITMODE(timer) = bitmode;
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Set Prescaler.

Set prescaler for Timer, this is used only in timer mode.
Prescaler value of NRF52 can be set from 0 to 9.

@param[in] timer unsigned 32 bit. Timer block register address base @ref
timer_reg_base
@param[in] prescaler unsigned 8 bit. Prescaler value
*/

void timer_prescaler(uint32_t timer, uint8_t prescaler)
{
	TIMER_PRESCALER(timer) = TIMER_PRESCALER_PRESCALER(prescaler);
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Set Capture/Compare value.

If TIMER0, TIMER1, or TIMER2 is selected, Capture/Compare cc can be select 
from CC0 (or 0) to CC3 (or 3).
If TIMER3, or TIMER4 is selected, Capture/Compare cc can be select from CC0 
(or 0) to CC5 (or 5).

@param[in] timer unsigned 32 bit. Timer block register address base @ref
timer_reg_base
@param[in] cc. Capture/Compare Identifiers @ref timer_cc_id
@param[in] value unsigned 32 bit. Capture/Compare value
*/

void timer_cc_set(uint32_t timer, size_t cc, uint32_t value)
{	
	TIMER_CC(timer)[cc] = (value);
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Enable interrupt.

Enable interrupt for COMPARE[x] event

@param[in] timer unsigned 32 bit. Timer block register address base @ref
timer_reg_base
@param[in] cc. Capture/Compare Identifiers @ref timer_cc_id
*/

void timer_interrupt_enable(uint32_t timer, size_t cc)
{
	TIMER_INTENSET(timer) |= (1 << (16+cc));
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Disable interrupt.

Disable interrupt for COMPARE[x] event

@param[in] timer unsigned 32 bit. Timer block register address base @ref
timer_reg_base
@param[in] cc. Capture/Compare Identifiers @ref timer_cc_id
*/

void timer_interrupt_disable(uint32_t timer, size_t cc)
{
	TIMER_INTENCLR(timer) |= (1 << (16+cc));
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Get frequency.

Return frequency value

@param[in] timer unsigned 32 bit. Timer block register address base @ref
timer_reg_base
@returns integer.
*/

int timer_get_frequency(uint32_t timer)
{
	int frequency = 16000000 / (1 << TIMER_PRESCALER(timer));	
	return frequency;
}


