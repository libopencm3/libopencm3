/** @addtogroup pwm_file

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

#include <libopencm3/nrf5/pwm.h>
#include <libopencm3/nrf5/gpio.h>


/*---------------------------------------------------------------------------*/
/** @brief PWM Stop.

Stop PWM on all channel and sequence playback

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
*/

void pwm_stop(uint32_t pwm)
{
	PWM_TASKS_STOP(pwm) = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Start sequence.

Loads the first PWM value on all enabled channels from a sequence and
start playing.
Sequence can be selected as SEQ0 (or 0) or SEQ1 (or 1)

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] seq boolean. Sequence identifiers @ref pwm_seq_id
*/

void pwm_start_seq(uint32_t pwm, bool seq)
{
	PWM_TASKS_SEQSTART(pwm)[seq] = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Start Nextstep.

Steps by one value in the current sequence, can be triggered only if Nextstep
mode was selected in DECODER register

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
*/

void pwm_nextstep(uint32_t pwm)
{
	if(PWM_DECODER(pwm) |= MODE_NEXTSTEP){PWM_TASKS_NEXTSTEP(pwm) = 1;}
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Set prescaler.

Prescaler can be selected as DIV_1, DIV_2, DIV_4...DIV_128 for a divide of 
16 MHz by 1,2,4...128 respectively

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] prescaler unsigned 32 bit. Set prescaler @ref pwm_prescaler
*/

void pwm_prescaler(uint32_t pwm, uint32_t prescaler)
{
	PWM_PRESCALER(pwm) = prescaler;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Set countertop value.

countertop value can be set from 3 to 32767

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] countertop unsigned 16 bit. Set countertop @ref pwm_countertop
*/

void pwm_counter_top(uint32_t pwm, uint16_t countertop)
{
	PWM_COUNTERTOP(pwm) = (uint32_t)countertop;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Set operating mode.

Selects MODE_UP or MODE_UPANDDOWN as wave counter mode.
In mode UP, PWM period = T(PWM_CLK) * COUNTERTOP.
In mode UP and Down, PWM period = T(PWM_CLK) * COUNTERTOP * 2.

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] mode unsigned 32 bit. Operating mode @ref pwm_mode
*/

void pwm_counter_mode(uint32_t pwm, uint32_t mode)
{
	PWM_MODE(pwm) = mode;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Decoder configuration.

Configurates how a sequence is read from RAM through "load" parameter. 
All 4 PWM can be enabled with LOAD_COMMON, LOAD_GROUPED and LOAD_INDIVIDUAL.
Only 3 PWM channels (0,1,2) can be enabled with LOAD_WAVEFORM.

Selects source for advancing the active sequence though "mode" parameter.
This can be selected as MODE_REFRESHCOUNT or MODE_NEXTSTEP

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] load unsigned 32 bit. Read mode from RAM @ref pwm_decoder
@param[in] mode unsigned 32 bit. Source mode @ref pwm_decoder
*/

void pwm_decoder(uint32_t pwm, uint32_t load, uint32_t mode)
{
	PWM_DECODER(pwm) |= load | mode;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Set loop.

Set amount of playback of pattern cycles.
Loop can be disabled if set to 0.

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] loop unsigned 16 bit. Set amount of playback of a loop @ref pwm_loop
*/

void pwm_loop(uint32_t pwm, uint16_t loop)
{
	PWM_LOOP(pwm) = PWM_LOOP_CNT(loop);
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Sequence configuration.

Flexible and complete configuration for a sequence. 
Configurates beginning address in Data RAM of the sequence, set amount of
values (set 0 if disable sequence), set amount of additional pwm periods
between samples loads into compare (set 0 or REFRESH_CONTINUOUS if updating 
every pwm period), and set time added after the sequence (enddelay).

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] seq boolean. Sequence identifiers @ref pwm_seq_id
@param[in] *ptr unsigned 16 bit. Beginning address in Data RAM of the sequence
@param[in] maxcnt unsigned 16 bit. Amount of duty cycles in the sequence @ref
pwm_seq_cnt
@param[in] refresh unsigned 32 bit. Amount of additional PWM periodes between
samples @ref pwm_seq_refresh
@param[in] enddelay unsigned 32 bit. Time added after the sequence @ref 
pwm_seq_enddelay
*/

/*
refresh and enddelay are ignored at the end of a complex sequence, indicated 
by a LOOPSDONE event. The reason for this is that the last value loaded from
RAM is maintained until further action from software (restarting a new 
sequence, or stopping PWM generation).
*/

void pwm_sequence_config(uint32_t pwm, bool seq, uint16_t *ptr, uint16_t cnt, 
	uint32_t refresh, uint32_t enddelay)
{
	if(seq == 0)
	{
		PWM_SEQ0_PTR(pwm) = (uint32_t)ptr;
		PWM_SEQ0_CNT (pwm) = (uint32_t) PWM_SEQ_CNT_CNT(cnt);
		PWM_SEQ0_REFRESH(pwm) = PWM_SEQ_REFRESH_CNT(refresh);
		PWM_SEQ0_ENDDELAY(pwm) = enddelay;
	}
	if(seq == 1)
	{
		PWM_SEQ1_PTR(pwm) = (uint32_t)ptr;
		PWM_SEQ1_CNT (pwm) = cnt;
		PWM_SEQ1_REFRESH(pwm) = refresh;
		PWM_SEQ1_ENDDELAY(pwm) = enddelay;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Set output pin.

Select output pin for pwm channel and set connect as CONNECT_CONNECTED or
CONNECT_DISCONNECTED
Every pwm channel can be set up to 4 outputs (0..3)

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] output unsigned 8 bit. Output number identifiers @ref pwm_output_id
@param[in] pin unsigned 8 bit. Pin identifiers @ref gpio_pin_id
@param[in] connect unsigned 32 bit. Output pin configuration @ref pwm_psel
*/

void pwm_output_pin(uint32_t pwm, uint8_t output, uint8_t pin,	
	uint32_t connect)
{
	GPIO_DIRSET = (uint32_t)(1 << pin);
	PWM_PSEL_OUT(pwm)[output] = PWM_PSEL_OUT_PIN(pin) | connect;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Enable PWM.

Enable PWM channel

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
*/

void pwm_enable(uint32_t pwm)
{
	PWM_ENABLE(pwm) = PWM_ENABLE_ENABLE_ENABLED;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Disable.

Disable PWM channel

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
*/

void pwm_disable(uint32_t pwm)
{
	PWM_ENABLE(pwm) = PWM_ENABLE_ENABLE_DISABLED;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Enable interrupt.

Enable interrupt for one or more events. Events can be selected as STOPPED,
SEQSTARTED0, SEQSTARTED1, SEQEND0, SEQEND1, PWMPERIODEND, or LOOPSDONE.

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] events unsigned 32 bit. predetermined event names @ref 
pwm_events_interrupt
*/

void pwm_interrupt_enable(uint32_t pwm, uint32_t events)
{
	PWM_INTENSET(pwm) |= events;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Disable interrupt.

Disable interrupt for one or more events. Events can be selected as STOPPED,
SEQSTARTED0, SEQSTARTED1, SEQEND0, SEQEND1, PWMPERIODEND, or LOOPSDONE.

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] events unsigned 32 bit. predetermined event names @ref 
pwm_events_interrupt
*/

void pwm_interrupt_disable(uint32_t pwm, uint32_t events)
{
	PWM_INTENCLR(pwm) |= events;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM End of sequence status.

Emitted at end of every sequence. Return 1 if when last value from RAM has 
been applied to wave counter

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] seq boolean. Sequence identifiers @ref pwm_seq_id
@returns unsigned 32 bit data word
*/

uint32_t pwm_sequence_end(uint32_t pwm, bool seq)
{
	return PWM_EVENTS_SEQEND(pwm)[seq];
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Reset END event.

Clear value of SEQEND[seq] event register

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
@param[in] seq boolean. Sequence identifiers @ref pwm_seq_id
*/

void pwm_sequence_end_reset(uint32_t pwm, bool seq)
{
	PWM_EVENTS_SEQEND(pwm)[seq] = 0;
}

/*---------------------------------------------------------------------------*/
/** @brief PWM End of loop concatenated sequence status.

Return 1 if concatenated sequences have been played the amount of times 
defined in LOOP.CNT

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
*/

uint32_t pwm_loop_done(uint32_t pwm)
{
	return PWM_EVENTS_LOOPSDONE(pwm);
}

/*---------------------------------------------------------------------------*/
/** @brief PWM Reset LOOPSDONE event.

Clear value of LOOPDONES event register and ready to emit after amount of the 
next loop has been played. 

@param[in] pwm unsigned 32 bit. PWM block register address base @ref
pwm_reg_base
*/

void pwm_loop_done_reset(uint32_t pwm)
{
	PWM_EVENTS_LOOPSDONE(pwm) = 0;
}

