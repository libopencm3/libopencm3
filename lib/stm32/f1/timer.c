/** @file

@ingroup STM32F1xx

@brief <b>libopencm3 STM32F1xx Timers</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010 Edward Cheeseman <evbuilder@users.sourceforge.org>

@date 8 July 2012

This library supports the General Purpose and Advanced Control Timers for
the STM32F1xx series of ARM Cortex Microcontrollers by ST Microelectronics.

The STM32F1xx series have four general purpose timers (2-5), while some have
an additional two advanced timers (1,8), and some have two basic timers (6,7).
Some of the larger devices have additional general purpose timers (9-14).

@todo Add timer DMA burst settings

@section tim_api_ex Basic TIMER handling API.

Enable the timer clock first. The timer mode sets the clock division ratio,
the count alignment (edge or centred) and count direction. Finally enable the timer.

The timer output compare block produces a signal that can be configured for
output to a pin or passed to other peripherals for use as a trigger. In all cases
the output compare mode must be set to define how the output responds to a compare
match, and the output must be enabled. If output to a pin is required, enable the
appropriate GPIO clock and set the pin to alternate output mode.

Example: Timer 2 with 2x clock divide, edge aligned and up counting.
@code
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_TIM2EN);
	timer_reset(TIM2);
	timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT_MUL_2,
               TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
	...
	timer_set_period(TIM2, 1000);
	timer_enable_counter(TIM2);
@endcode
Example: Timer 1 with PWM output, no clock divide and centre alignment. Set the
Output Compare mode to PWM and enable the output of channel 1. Note that for the
advanced timers the break functionality must be enabled before the signal will
appear at the output, even though break is not being used. This is in addition to
the normal output enable. Enable the alternate function clock (APB2 only) and port A
clock. Set ports A8 and A9 (timer 1 channel 1 compare outputs) to alternate function
push-pull outputs where the PWM output will appear.

@code
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN);
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO8 | GPIO9);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_TIM1EN);
	timer_reset(TIM1);
	timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM2);
	timer_enable_oc_output(TIM1, TIM_OC1);
	timer_enable_break_main_output(TIM1);
	timer_set_oc_value(TIM1, TIM_OC1, 200);
	timer_set_period(TIM1, 1000);
	timer_enable_counter(TIM1);
@endcode

@todo input capture example

*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Edward Cheeseman <evbuilder@users.sourceforge.org>
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

/*
 * Basic TIMER handling API.
 *
 * Examples:
 *  timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT_MUL_2,
 *                 TIM_CR1_CMS_CENTRE_3, TIM_CR1_DIR_UP);
 */

#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/f1/rcc.h>

/*---------------------------------------------------------------------------*/
/** @brief Reset a Timer.

The counter and all its associated configuration registers
are placed in the reset condition. The reset is effected via the RCC peripheral reset
system.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
			(TIM9 .. TIM14 not yet supported here).
*/

void timer_reset(u32 timer_peripheral)
{
	switch (timer_peripheral) {
	case TIM1:
		rcc_peripheral_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM1RST);
		rcc_peripheral_clear_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM1RST);
		break;
	case TIM2:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM2RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM2RST);
		break;
	case TIM3:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM3RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM3RST);
		break;
	case TIM4:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM4RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM4RST);
		break;
	case TIM5:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM5RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM5RST);
		break;
	case TIM6:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM6RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM6RST);
		break;
	case TIM7:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM7RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM7RST);
		break;
	case TIM8:
		rcc_peripheral_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM8RST);
		rcc_peripheral_clear_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM8RST);
		break;
/* These timers are not supported in libopencm3 yet */
/*
	case TIM9:
		rcc_peripheral_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM9RST);
		rcc_peripheral_clear_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM9RST);
		break;
	case TIM10:
		rcc_peripheral_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM10RST);
		rcc_peripheral_clear_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM10RST);
		break;
	case TIM11:
		rcc_peripheral_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM11RST);
		rcc_peripheral_clear_reset(&RCC_APB2RSTR, RCC_APB2RSTR_TIM11RST);
		break;
	case TIM12:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM12RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM12RST);
		break;
	case TIM13:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM13RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM13RST);
		break;
	case TIM14:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM14RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_TIM14RST);
		break;
*/
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Interrupts for a Timer

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] irq Unsigned int32. @ref tim_irq_enable. Logical OR of all interrupt enable bits to be set
*/

void timer_enable_irq(u32 timer_peripheral, u32 irq)
{
	TIM_DIER(timer_peripheral) |= irq;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Interrupts for a Timer.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] irq Unsigned int32. @ref tim_irq_enable. Logical OR of all interrupt enable bits to be cleared
*/

void timer_disable_irq(u32 timer_peripheral, u32 irq)
{
	TIM_DIER(timer_peripheral) &= ~irq;
}

/*---------------------------------------------------------------------------*/
/** @brief Read a Status Flag.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] flag Unsigned int32. Status register flag  @ref tim_sr_values.
@returns boolean: flag set.
*/

bool timer_get_flag(u32 timer_peripheral, u32 flag)
{
	if ((TIM_SR(timer_peripheral) & flag) != 0) {
		return true;
	}

	return false;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear a Status Flag.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] flag Unsigned int32. @ref tim_sr_values. Status register flag.
*/

void timer_clear_flag(u32 timer_peripheral, u32 flag)
{
	TIM_SR(timer_peripheral) &= ~flag;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Timer Mode.

The modes are:

@li Clock divider ratio (to form the sampling clock for the input filters,
and the dead-time clock in the advanced timers 1 and 8)
@li Edge/centre alignment
@li Count direction

The alignment and count direction are effective only for timers 1 to 5 and 8
while the clock divider ratio is effective for all timers except 6,7
The remaining timers are limited hardware timers which do not support these mode
settings.

@note: When center alignment mode is selected, count direction is controlled by
hardware and cannot be written. The count direction setting has no effect
in this case.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base (TIM1, TIM2 ... TIM5, TIM8)
@param[in] clock_div Unsigned int32. Clock Divider Ratio in bits 8,9: @ref tim_x_cr1_cdr
@param[in] alignment Unsigned int32. Alignment bits in 5,6: @ref tim_x_cr1_cms
@param[in] direction Unsigned int32. Count direction in bit 4,: @ref tim_x_cr1_dir
*/

void timer_set_mode(u32 timer_peripheral, u32 clock_div,
		    u32 alignment, u32 direction)
{
	u32 cr1;

	cr1 = TIM_CR1(timer_peripheral);

	cr1 &= ~(TIM_CR1_CKD_CK_INT_MASK | TIM_CR1_CMS_MASK | TIM_CR1_DIR_DOWN);

	cr1 |= clock_div | alignment | direction;

	TIM_CR1(timer_peripheral) = cr1;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Input Filter and Dead-time Clock Divider Ratio.

This forms the sampling clock for the input filters and the dead-time clock
in the advanced timers 1 and 8, by division from the timer clock.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] clock_div Unsigned int32. Clock Divider Ratio in bits 8,9: @ref tim_x_cr1_cdr
*/

void timer_set_clock_division(u32 timer_peripheral, u32 clock_div)
{
	clock_div &= TIM_CR1_CKD_CK_INT_MASK;
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_CKD_CK_INT_MASK;
	TIM_CR1(timer_peripheral) |= clock_div;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Auto-Reload Buffering.

During counter operation this causes the counter to be loaded from its
auto-reload register only at the next update event.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_enable_preload(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_ARPE;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Auto-Reload Buffering.

This causes the counter to be loaded immediately with a new count value when the
auto-reload register is written, so that the new value becomes effective for the
current count cycle rather than for the cycle following an update event.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_disable_preload(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_ARPE;
}

/*---------------------------------------------------------------------------*/
/** @brief Specify the counter alignment mode.

The mode can be edge aligned or centered.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] alignment Unsigned int32. Alignment bits in 5,6: @ref tim_x_cr1_cms
*/

void timer_set_alignment(u32 timer_peripheral, u32 alignment)
{
	alignment &= TIM_CR1_CMS_MASK;
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_CMS_MASK;
	TIM_CR1(timer_peripheral) |= alignment;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Timer to Count Up.

This has no effect if the timer is set to center aligned.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_direction_up(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_DIR_DOWN;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Timer to Count Down.

This has no effect if the timer is set to center aligned.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_direction_down(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_DIR_DOWN;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the Timer for One Cycle and Stop.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_one_shot_mode(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_OPM;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the Timer to Run Continuously.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_continuous_mode(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_OPM;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Timer to Generate Update IRQ or DMA on any Event.

The events which will generate an interrupt or DMA request can be 
@li a counter underflow/overflow,
@li a forced update,
@li an event from the slave mode controller.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_update_on_any(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_URS;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Timer to Generate Update IRQ or DMA only from Under/Overflow Events.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_update_on_overflow(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_URS;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Timer Update Events.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_enable_update_event(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_UDIS;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Timer Update Events.

Update events are not generated and the shadow registers keep their values.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_disable_update_event(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_UDIS;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the timer to start counting.

This should be called after the timer initial configuration has been completed.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_enable_counter(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_CEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Stop the timer from counting.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_disable_counter(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_CEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Timer Output Idle States High.

This determines the value of the timer output compare when it enters idle state.

@sa @ref timer_set_oc_idle_state_set

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] outputs Unsigned int32. Timer Output Idle State Controls @ref tim_x_cr2_ois.
If several settings are to be made, use the logical OR of the output control values.
*/

void timer_set_output_idle_state(u32 timer_peripheral, u32 outputs)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
    	TIM_CR2(timer_peripheral) |= outputs & TIM_CR2_OIS_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Timer Output Idle States Low.

This determines the value of the timer output compare when it enters idle state.

@sa @ref timer_set_oc_idle_state_unset

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] outputs Unsigned int32. Timer Output Idle State Controls @ref tim_x_cr2_ois
*/

void timer_reset_output_idle_state(u32 timer_peripheral, u32 outputs)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
    	TIM_CR2(timer_peripheral) &= ~(outputs & TIM_CR2_OIS_MASK);
}

/*---------------------------------------------------------------------------*/
/** @brief Set Timer 1 Input to XOR of Three Channels.

The first timer capture input is formed from the XOR of the first three timer input
channels 1, 2, 3.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_set_ti1_ch123_xor(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) |= TIM_CR2_TI1S;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Timer 1 Input to Channel 1.

The first timer capture input is taken from the timer input channel 1 only.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_set_ti1_ch1(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) &= ~TIM_CR2_TI1S;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Master Mode

This sets the Trigger Output TRGO for synchronizing with slave timers or passing as
an internal trigger to the ADC or DAC.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] mode Unsigned int32. Master Mode @ref tim_mastermode
*/

void timer_set_master_mode(u32 timer_peripheral, u32 mode)
{
	TIM_CR2(timer_peripheral) &= ~TIM_CR2_MMS_MASK;
	TIM_CR2(timer_peripheral) |= mode;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Timer DMA Requests on Capture/Compare Events.

Capture/compare events will cause DMA requests to be generated.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_set_dma_on_compare_event(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) &= ~TIM_CR2_CCDS;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Timer DMA Requests on Update Events.

Update events will cause DMA requests to be generated.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_set_dma_on_update_event(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) |= TIM_CR2_CCDS;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Timer Capture/Compare Control Update with Trigger.

If the capture/compare control bits CCxE, CCxNE and OCxM are set to be
preloaded, they are updated by software setting the COM bit (@ref ) or when a
rising edge occurs on the trigger input TRGI.

@note This setting is only valid for the advanced timer channels with complementary
outputs.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_enable_compare_control_update_on_trigger(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
    	TIM_CR2(timer_peripheral) |= TIM_CR2_CCUS;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Timer Capture/Compare Control Update with Trigger.

If the capture/compare control bits CCxE, CCxNE and OCxM are set to be
preloaded, they are updated by software setting the COM bit (@ref ).

@note This setting is only valid for the advanced timer channels with complementary
outputs.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_disable_compare_control_update_on_trigger(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
    	TIM_CR2(timer_peripheral) &= ~TIM_CR2_CCUS;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Timer Capture/Compare Control Preload.

The capture/compare control bits CCxE, CCxNE and OCxM are set to be preloaded
when a COM event occurs.

@note This setting is only valid for the advanced timer channels with complementary
outputs.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_enable_preload_complementry_enable_bits(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
    	TIM_CR2(timer_peripheral) |= TIM_CR2_CCPC;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Timer Capture/Compare Control Preload.

The capture/compare control bits CCxE, CCxNE and OCxM preload is disabled.

@note This setting is only valid for the advanced timer channels with complementary
outputs.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
*/

void timer_disable_preload_complementry_enable_bits(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
    	TIM_CR2(timer_peripheral) &= ~TIM_CR2_CCPC;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Value for the Timer Prescaler.

The timer clock is prescaled by the 16 bit scale value plus 1.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] value Unsigned int32. Prescaler values 0...0xFFFF.
*/

void timer_set_prescaler(u32 timer_peripheral, u32 value)
{
	TIM_PSC(timer_peripheral) = value;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the Value for the Timer Repetition Counter.

A timer update event is generated only after the specified number of repeat
count cycles have been completed.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] value Unsigned int32. Repetition values 0...0xFF.
*/

void timer_set_repetition_counter(u32 timer_peripheral, u32 value)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_RCR(timer_peripheral) = value;
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Set Period

Specify the timer period in the auto-reload register.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] period Unsigned int32. Period in counter clock ticks.
*/

void timer_set_period(u32 timer_peripheral, u32 period)
{
	TIM_ARR(timer_peripheral) = period;
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Enable the Output Compare Clear Function

When this is enabled, the output compare signal is cleared when a high is detected
on the external trigger input. This works in the output compare and PWM modes only
(not forced mode).
The output compare signal remains off until the next update event.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (no action taken)
*/

void timer_enable_oc_clear(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1CE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2CE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3CE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4CE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as oc clear enable only applies to the whole channel. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Disable the Output Compare Clear Function

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (no action taken)
*/

void timer_disable_oc_clear(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC1CE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC2CE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC3CE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC4CE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as oc clear enable only applies to the whole channel. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Enable the Output Compare Fast Mode

When this is enabled, the output compare signal is forced to the compare state
by a trigger input, independently of the compare match. This speeds up the
setting of the output compare to 3 clock cycles as opposed to at least 5 in the
slow mode. This works in the PWM1 and PWM2 modes only.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (no action taken)
*/

void timer_set_oc_fast_mode(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1FE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2FE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3FE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4FE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as fast enable only applies to the whole channel. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Enable the Output Compare Slow Mode

This disables the fast compare mode and the output compare depends on the
counter and compare register values.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (no action taken)
*/

void timer_set_oc_slow_mode(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC1FE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC2FE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC3FE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC4FE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Set Output Compare Mode

Specifies how the comparator output will respond to a compare match. The mode can be:
@li Frozen - the output does not respond to a match.
@li Active - the output assumes the active state on the first match.
@li Inactive - the output assumes the inactive state on the first match.
@li Toggle - The output switches between active and inactive states on each match.
@li Force inactive. The output is forced low regardless of the compare state.
@li Force active. The output is forced high regardless of the compare state.
@li PWM1 - The output is active when the counter is less than the compare register contents
and inactive otherwise.
@li PWM2 - The output is inactive when the counter is less than the compare register contents
and active otherwise.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (no action taken)
@param[in] oc_mode enum ::tim_oc_mode. OC mode designators.
		TIM_OCM_FROZEN, TIM_OCM_ACTIVE, TIM_OCM_INACTIVE, TIM_OCM_TOGGLE,
		TIM_OCM_FORCE_LOW, TIM_OCM_FORCE_HIGH, TIM_OCM_PWM1, TIM_OCM_PWM2
*/

void timer_set_oc_mode(u32 timer_peripheral, enum tim_oc_id oc_id,
		       enum tim_oc_mode oc_mode)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_CC1S_MASK;
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_CC1S_OUT;
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC1M_MASK;
		switch (oc_mode) {
		case TIM_OCM_FROZEN:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1M_FROZEN;
			break;
		case TIM_OCM_ACTIVE:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1M_ACTIVE;
			break;
		case TIM_OCM_INACTIVE:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1M_INACTIVE;
			break;
		case TIM_OCM_TOGGLE:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1M_TOGGLE;
			break;
		case TIM_OCM_FORCE_LOW:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1M_FORCE_LOW;
			break;
		case TIM_OCM_FORCE_HIGH:
			TIM_CCMR1(timer_peripheral) |=
			    TIM_CCMR1_OC1M_FORCE_HIGH;
			break;
		case TIM_OCM_PWM1:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1M_PWM1;
			break;
		case TIM_OCM_PWM2:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1M_PWM2;
			break;
		}
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_CC2S_MASK;
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_CC2S_OUT;
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC2M_MASK;
		switch (oc_mode) {
		case TIM_OCM_FROZEN:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2M_FROZEN;
			break;
		case TIM_OCM_ACTIVE:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2M_ACTIVE;
			break;
		case TIM_OCM_INACTIVE:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2M_INACTIVE;
			break;
		case TIM_OCM_TOGGLE:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2M_TOGGLE;
			break;
		case TIM_OCM_FORCE_LOW:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2M_FORCE_LOW;
			break;
		case TIM_OCM_FORCE_HIGH:
			TIM_CCMR1(timer_peripheral) |=
			    TIM_CCMR1_OC2M_FORCE_HIGH;
			break;
		case TIM_OCM_PWM1:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2M_PWM1;
			break;
		case TIM_OCM_PWM2:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2M_PWM2;
			break;
		}
		break;
	case TIM_OC3:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR2_CC3S_MASK;
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR2_CC3S_OUT;
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC3M_MASK;
		switch (oc_mode) {
		case TIM_OCM_FROZEN:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3M_FROZEN;
			break;
		case TIM_OCM_ACTIVE:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR2_OC3M_ACTIVE;
			break;
		case TIM_OCM_INACTIVE:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3M_INACTIVE;
			break;
		case TIM_OCM_TOGGLE:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3M_TOGGLE;
			break;
		case TIM_OCM_FORCE_LOW:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3M_FORCE_LOW;
			break;
		case TIM_OCM_FORCE_HIGH:
			TIM_CCMR2(timer_peripheral) |=
			    TIM_CCMR2_OC3M_FORCE_HIGH;
			break;
		case TIM_OCM_PWM1:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3M_PWM1;
			break;
		case TIM_OCM_PWM2:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3M_PWM2;
			break;
		}
		break;
	case TIM_OC4:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR2_CC4S_MASK;
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR2_CC4S_OUT;
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC4M_MASK;
		switch (oc_mode) {
		case TIM_OCM_FROZEN:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4M_FROZEN;
			break;
		case TIM_OCM_ACTIVE:
			TIM_CCMR1(timer_peripheral) |= TIM_CCMR2_OC4M_ACTIVE;
			break;
		case TIM_OCM_INACTIVE:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4M_INACTIVE;
			break;
		case TIM_OCM_TOGGLE:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4M_TOGGLE;
			break;
		case TIM_OCM_FORCE_LOW:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4M_FORCE_LOW;
			break;
		case TIM_OCM_FORCE_HIGH:
			TIM_CCMR2(timer_peripheral) |=
			    TIM_CCMR2_OC4M_FORCE_HIGH;
			break;
		case TIM_OCM_PWM1:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4M_PWM1;
			break;
		case TIM_OCM_PWM2:
			TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4M_PWM2;
			break;
		}
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Enable the Output Compare Preload Register

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators 
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (no action taken)
*/

void timer_enable_oc_preload(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1PE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2PE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3PE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4PE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Disable the Output Compare Preload Register

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators 
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (no action)
*/

void timer_disable_oc_preload(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC1PE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC2PE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC3PE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC4PE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Set the Output Polarity High

The polarity of the channel output is set active high.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators 
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3  (only for advanced timers 1 and 8)
*/

void timer_set_oc_polarity_high(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC1P;
		break;
	case TIM_OC2:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC2P;
		break;
	case TIM_OC3:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC3P;
		break;
	case TIM_OC4:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC4P;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to TIM1 and TIM8 only. */
		break;
	}

	/* Acting for TIM1 and TIM8 only from here onwards. */
	if ((timer_peripheral != TIM1) && (timer_peripheral != TIM8))
		return;

	switch (oc_id) {
	case TIM_OC1N:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC1NP;
		break;
	case TIM_OC2N:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC2NP;
		break;
	case TIM_OC3N:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC3NP;
		break;
	case TIM_OC1:
	case TIM_OC2:
	case TIM_OC3:
	case TIM_OC4:
		/* Ignoring as this option was already set above. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Set the Output Polarity Low

The polarity of the channel output is set active low.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators 
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (only for advanced timers 1 and 8)
*/

void timer_set_oc_polarity_low(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC1P;
		break;
	case TIM_OC2:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC2P;
		break;
	case TIM_OC3:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC3P;
		break;
	case TIM_OC4:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC4P;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to TIM1 and TIM8 only. */
		break;
	}

	/* Acting for TIM1 and TIM8 only from here onwards. */
	if ((timer_peripheral != TIM1) && (timer_peripheral != TIM8))
		return;

	switch (oc_id) {
	case TIM_OC1N:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC1NP;
		break;
	case TIM_OC2N:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC2NP;
		break;
	case TIM_OC3N:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC3NP;
		break;
	case TIM_OC1:
	case TIM_OC2:
	case TIM_OC3:
	case TIM_OC4:
		/* Ignoring as this option was already set above. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Enable the Output Compare

The channel output compare functionality is enabled.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators 
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (only for advanced timers 1 and 8)
*/

void timer_enable_oc_output(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC1E;
		break;
	case TIM_OC2:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC2E;
		break;
	case TIM_OC3:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC3E;
		break;
	case TIM_OC4:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC4E;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to TIM1 and TIM8 only. */
		break;
	}

	/* Acting for TIM1 and TIM8 only from here onwards. */
	if ((timer_peripheral != TIM1) && (timer_peripheral != TIM8))
		return;

	switch (oc_id) {
	case TIM_OC1N:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC1NE;
		break;
	case TIM_OC2N:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC2NE;
		break;
	case TIM_OC3N:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC3NE;
		break;
	case TIM_OC1:
	case TIM_OC2:
	case TIM_OC3:
	case TIM_OC4:
		/* Ignoring as this option was already set above. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Disable the Output Compare

The channel output compare functionality is disabled.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators 
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (only for advanced timers 1 and 8)
*/

void timer_disable_oc_output(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC1E;
		break;
	case TIM_OC2:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC2E;
		break;
	case TIM_OC3:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC3E;
		break;
	case TIM_OC4:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC4E;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to TIM1 and TIM8 only. */
		break;
	}

	/* Acting for TIM1 and TIM8 only from here onwards. */
	if ((timer_peripheral != TIM1) && (timer_peripheral != TIM8))
		return;

	switch (oc_id) {
	case TIM_OC1N:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC1NE;
		break;
	case TIM_OC2N:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC2NE;
		break;
	case TIM_OC3N:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC3NE;
		break;
	case TIM_OC1:
	case TIM_OC2:
	case TIM_OC3:
	case TIM_OC4:
		/* Ignoring as this option was already set above. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer set Output Compare Idle State High

@sa Similar function suitable for multiple OC idle state settings
@ref timer_set_output_idle_state

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators 
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (only for advanced timers 1 and 8)
*/

void timer_set_oc_idle_state_set(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	/* Acting for TIM1 and TIM8 only. */
	if ((timer_peripheral != TIM1) && (timer_peripheral != TIM8))
		return;

	switch (oc_id) {
	case TIM_OC1:
		TIM_CR2(timer_peripheral) |= TIM_CR2_OIS1;
		break;
	case TIM_OC1N:
		TIM_CR2(timer_peripheral) |= TIM_CR2_OIS1N;
		break;
	case TIM_OC2:
		TIM_CR2(timer_peripheral) |= TIM_CR2_OIS2;
		break;
	case TIM_OC2N:
		TIM_CR2(timer_peripheral) |= TIM_CR2_OIS2N;
		break;
	case TIM_OC3:
		TIM_CR2(timer_peripheral) |= TIM_CR2_OIS3;
		break;
	case TIM_OC3N:
		TIM_CR2(timer_peripheral) |= TIM_CR2_OIS3N;
		break;
	case TIM_OC4:
		TIM_CR2(timer_peripheral) |= TIM_CR2_OIS4;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Set Output Compare Idle State Low

@sa Similar function suitable for multiple OC idle state settings
@ref timer_reset_output_idle_state

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
@param[in] oc_id enum ::tim_oc_id OC channel designators 
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (only for advanced timers 1 and 8)
*/

void timer_set_oc_idle_state_unset(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	/* Acting for TIM1 and TIM8 only. */
	if ((timer_peripheral != TIM1) && (timer_peripheral != TIM8))
		return;

	switch (oc_id) {
	case TIM_OC1:
		TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS1;
		break;
	case TIM_OC1N:
		TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS1N;
		break;
	case TIM_OC2:
		TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS2;
		break;
	case TIM_OC2N:
		TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS2N;
		break;
	case TIM_OC3:
		TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS3;
		break;
	case TIM_OC3N:
		TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS3N;
		break;
	case TIM_OC4:
		TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS4;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Timer Set Output Compare Value

This is a convenience function to set the OC preload register value for loading
to the compare register.

@param[in] timer_peripheral Unsigned int32. Timer register address base @ref tim_reg_base
			(TIM9 .. TIM14 not yet supported here).
@param[in] oc_id enum ::tim_oc_id OC channel designators 
		TIM_OCx where x=1..4, TIM_OCxN where x=1..3 (no action taken)
@param[in] value Unsigned int32. Compare value.
*/

void timer_set_oc_value(u32 timer_peripheral, enum tim_oc_id oc_id, u32 value)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCR1(timer_peripheral) = value;
		break;
	case TIM_OC2:
		TIM_CCR2(timer_peripheral) = value;
		break;
	case TIM_OC3:
		TIM_CCR3(timer_peripheral) = value;
		break;
	case TIM_OC4:
		TIM_CCR4(timer_peripheral) = value;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Output in Break

Enables the output in the Break feature of an advanced timer. This does not
enable the break functionality itself but only sets the Master Output Enable in
the Break and Deadtime Register.

@note This setting is only valid for the advanced timers.

@note It is necessary to call this function to enable the output on an advanced
timer <b>even if break or deadtime features are not being used<\b>.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_enable_break_main_output(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) |= TIM_BDTR_MOE;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Output in Break

Disables the output in the Break feature of an advanced timer. This clears
the Master Output Enable in the Break and Deadtime Register.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_disable_break_main_output(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) &= ~TIM_BDTR_MOE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Automatic Output in Break

Enables the automatic output feature of the Break function of an advanced
timer so that the output is re-enabled at the next update event following a
break event. 

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_enable_break_automatic_output(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) |= TIM_BDTR_AOE;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Automatic Output in Break

Disables the automatic output feature of the Break function of an advanced
timer so that the output is re-enabled at the next update event following a
break event. 

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_disable_break_automatic_output(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) &= ~TIM_BDTR_AOE;
}

/*---------------------------------------------------------------------------*/
/** @brief Activate Break when Input High

Sets the break function to activate when the break input becomes high.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_set_break_polarity_high(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) |= TIM_BDTR_BKP;
}

/*---------------------------------------------------------------------------*/
/** @brief Activate Break when Input Low

Sets the break function to activate when the break input becomes low.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_set_break_polarity_low(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) &= ~TIM_BDTR_BKP;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Break

Enables the break function of an advanced timer.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_enable_break(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) |= TIM_BDTR_BKE;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Break

Disables the break function of an advanced timer.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_disable_break(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) &= ~TIM_BDTR_BKE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Off-State in Run Mode

Enables the off-state in run mode for the break function of an advanced
timer in which the complementary outputs have been configured. It has no effect
if no complementary output is present. When the capture-compare output is
disabled while the complementary output is enabled, the output is set to its
inactive level as defined by the output polarity.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_set_enabled_off_state_in_run_mode(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) |= TIM_BDTR_OSSR;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Off-State in Run Mode

Disables the off-state in run mode for the break function of an advanced
timer in which the complementary outputs have been configured. It has no effect
if no complementary output is present. When the capture-compare output is
disabled, the output is also disabled.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_set_disabled_off_state_in_run_mode(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) &= ~TIM_BDTR_OSSR;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Off-State in Idle Mode

Enables the off-state in idle mode for the break function of an advanced
timer. When the master output is disabled the output is set to its
inactive level as defined by the output polarity.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_set_enabled_off_state_in_idle_mode(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) |= TIM_BDTR_OSSI;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Off-State in Idle Mode

Disables the off-state in idle mode for the break function of an advanced
timer. When the master output is disabled the output is also disabled.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
*/

void timer_set_disabled_off_state_in_idle_mode(u32 timer_peripheral)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) &= ~TIM_BDTR_OSSI;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Lock Bits

Set the lock bits for an advanced timer. Three levels of lock providing
protection against software errors. Once written they cannot be changed until a
timer reset has occurred.

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
@param[in] lock Unsigned int32. Lock specification @ref tim_lock
*/

void timer_set_break_lock(u32 timer_peripheral, u32 lock)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) |= lock;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Deadtime

The deadtime and sampling clock (DTSC) is set in the clock division ratio part of the
timer mode settings. The deadtime count is an 8 bit value defined in terms of the
number of DTSC cycles:

@li Bit 7 = 0, deadtime = bits(6:0)
@li Bits 7:6 = 10, deadtime = 2x(64+bits(5:0))
@li Bits 7:5 = 110, deadtime = 8x(32+bits(5:0))
@li Bits 7:5 = 111, deadtime = 16x(32+bits(5:0))

@note This setting is only valid for the advanced timers.

@param[in] timer_peripheral Unsigned int32. Timer register address base TIM1 or TIM8
@param[in] deadtime Unsigned int32. Deadtime count specification as defined above.
*/

void timer_set_deadtime(u32 timer_peripheral, u32 deadtime)
{
	if ((timer_peripheral == TIM1) || (timer_peripheral == TIM8))
		TIM_BDTR(timer_peripheral) |= deadtime;
}

/*---------------------------------------------------------------------------*/
/** @brief Force generate a timer event.

The event specification consists of 8 possible events that can be forced on the
timer. The forced events are automatically cleared by hardware. The UG event is
useful to cause shadow registers to be preloaded before the timer is started to
avoid uncertainties in the first cycle in case an update event may never be
generated.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] event Unsigned int32. Event specification @ref tim_event_gen
*/

void timer_generate_event(u32 timer_peripheral, u32 event)
{
	TIM_EGR(timer_peripheral) |= event;
}

/*---------------------------------------------------------------------------*/
/** @brief Read Counter

Read back the value of a timer's counter register contents

@param[in] timer_peripheral Unsigned int32. Timer register address base
@returns Unsigned int32. Counter value.
*/

u32 timer_get_counter(u32 timer_peripheral)
{
	return TIM_CNT(timer_peripheral);
}

/*---------------------------------------------------------------------------*/
/** @brief Set Input Capture Filter Parameters

Set the input filter parameters for an input channel, specifying:
@li the frequency of sampling from the Deadtime and Sampling clock
(@see @ref timer_set_clock_division)
@li the number of events that must occur before a transition is considered valid.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] ic ::tim_ic_id. Input Capture channel designator.
@param[in] flt ::tim_ic_filter. Input Capture Filter identifier.
*/

void timer_ic_set_filter(u32 timer, enum tim_ic_id ic, enum tim_ic_filter flt)
{
	switch (ic) {
	case TIM_IC1:
		TIM_CCMR1(timer) &= ~TIM_CCMR1_IC1F_MASK;
		TIM_CCMR1(timer) |= flt << 4;
		break;
	case TIM_IC2:
		TIM_CCMR1(timer) &= ~TIM_CCMR1_IC2F_MASK;
		TIM_CCMR1(timer) |= flt << 12;
		break;
	case TIM_IC3:
		TIM_CCMR2(timer) &= ~TIM_CCMR2_IC3F_MASK;
		TIM_CCMR2(timer) |= flt << 4;
		break;
	case TIM_IC4:
		TIM_CCMR2(timer) &= ~TIM_CCMR2_IC4F_MASK;
		TIM_CCMR2(timer) |= flt << 12;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Set Input Capture Prescaler

Set the number of events between each capture.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] ic ::tim_ic_id. Input Capture channel designator.
@param[in] psc ::tim_ic_psc. Input Capture sample clock prescaler.
*/

void timer_ic_set_prescaler(u32 timer, enum tim_ic_id ic, enum tim_ic_psc psc)
{
	switch (ic) {
	case TIM_IC1:
		TIM_CCMR1(timer) &= ~TIM_CCMR1_IC1PSC_MASK;
		TIM_CCMR1(timer) |= psc << 2;
		break;
	case TIM_IC2:
		TIM_CCMR1(timer) &= ~TIM_CCMR1_IC2PSC_MASK;
		TIM_CCMR1(timer) |= psc << 10;
		break;
	case TIM_IC3:
		TIM_CCMR2(timer) &= ~TIM_CCMR2_IC3PSC_MASK;
		TIM_CCMR2(timer) |= psc << 4;
		break;
	case TIM_IC4:
		TIM_CCMR2(timer) &= ~TIM_CCMR2_IC4PSC_MASK;
		TIM_CCMR2(timer) |= psc << 10;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Set Capture/Compare Channel Direction/Input

The Capture/Compare channel is defined as output (compare) or input with the input
mapping specified:

@li channel is configured as output
@li channel is configured as input and mapped on corresponding input
@li channel is configured as input and mapped on alternate input
(TI2 for channel 1, TI1 for channel 2, TI4 for channel 3, TI3 for channel 4)
@li channel is configured as input and is mapped on TRC (requires an
internal trigger input selected through TS bit

@note not all combinations of the input and channel are valid, see datasheets.
@note these parameters are writable only when the channel is off.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] ic ::tim_ic_id. Input Capture channel designator.
@param[in] in ::tim_ic_input. Input Capture channel direction and source input.
*/

void timer_ic_set_input(u32 timer, enum tim_ic_id ic, enum tim_ic_input in)
{
	in &= 3;

	if (((ic == TIM_IC2) || (ic == TIM_IC4)) &&
	    ((in == TIM_IC_IN_TI1) || (in = TIM_IC_IN_TI2))) {
		/* Input select bits are flipped for these combinations */
		in ^= 3;
	}
	
	switch (ic) {
	case TIM_IC1:
		TIM_CCMR1(timer) &= ~TIM_CCMR1_CC1S_MASK;
		TIM_CCMR1(timer) |= in;
		break;
	case TIM_IC2:
		TIM_CCMR1(timer) &= ~TIM_CCMR1_CC2S_MASK;
		TIM_CCMR1(timer) |= in << 8;
		break;
	case TIM_IC3:
		TIM_CCMR2(timer) &= ~TIM_CCMR2_CC3S_MASK;
		TIM_CCMR2(timer) |= in;
		break;
	case TIM_IC4:
		TIM_CCMR2(timer) &= ~TIM_CCMR2_CC4S_MASK;
		TIM_CCMR2(timer) |= in << 8;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Set Input Polarity

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] ic ::tim_ic_id. Input Capture channel designator.
@param[in] pol ::tim_ic_pol. Input Capture polarity.
*/

void timer_ic_set_polarity(u32 timer, enum tim_ic_id ic, enum tim_ic_pol pol)
{
	if (pol)
		TIM_CCER(timer) |= (0x2 << (ic * 4));
	else
		TIM_CCER(timer) &= ~(0x2 << (ic * 4));
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Timer Input Capture

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] ic ::tim_ic_id. Input Capture channel designator.
*/

void timer_ic_enable(u32 timer, enum tim_ic_id ic)
{
	TIM_CCER(timer) |= (0x1 << (ic * 4));
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Timer Input Capture

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] ic ::tim_ic_id. Input Capture channel designator.
*/

void timer_ic_disable(u32 timer, enum tim_ic_id ic)
{
	TIM_CCER(timer) &= ~(0x1 << (ic * 4));
}

/*---------------------------------------------------------------------------*/
/** @brief Set External Trigger Filter Parameters for Slave

Set the input filter parameters for the external trigger, specifying:
@li the frequency of sampling from the Deadtime and Sampling clock
(@see @ref timer_set_clock_division)
@li the number of events that must occur before a transition is considered valid.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] flt ::tim_ic_filter. Input Capture Filter identifier.
*/

void timer_slave_set_filter(u32 timer, enum tim_ic_filter flt)
{
	TIM_SMCR(timer) &= ~TIM_SMCR_ETF_MASK;
	TIM_SMCR(timer) |= flt << 8;
}

/*---------------------------------------------------------------------------*/
/** @brief Set External Trigger Prescaler for Slave

Set the external trigger frequency division ratio.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] psc ::tim_ic_psc. Input Capture sample clock prescaler.
*/

void timer_slave_set_prescaler(u32 timer, enum tim_ic_psc psc)
{
	TIM_SMCR(timer) &= ~TIM_SMCR_ETPS_MASK;
	TIM_SMCR(timer) |= psc << 12;
}

/*---------------------------------------------------------------------------*/
/** @brief Set External Trigger Polarity for Slave

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] pol ::tim_ic_pol. Input Capture polarity.
*/

void timer_slave_set_polarity(u32 timer, enum tim_ic_pol pol)
{
	if (pol)
		TIM_SMCR(timer) |= TIM_SMCR_ETP;
	else
		TIM_SMCR(timer) &= ~TIM_SMCR_ETP;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Slave Mode

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] mode Unsigned int8. Slave mode @ref tim_sms
*/

void timer_slave_set_mode(u32 timer, u8 mode)
{
	TIM_SMCR(timer) &= ~TIM_SMCR_SMS_MASK;
	TIM_SMCR(timer) |= mode;
}

/*---------------------------------------------------------------------------*/
/** @brief Set Slave Trigger Source

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] trigger Unsigned int8. Slave trigger source @ref tim_ts
*/

void timer_slave_set_trigger(u32 timer, u8 trigger)
{
	TIM_SMCR(timer) &= ~TIM_SMCR_TS_MASK;
	TIM_SMCR(timer) |= trigger;
}

/*---------------------------------------------------------------------------*/
/** @brief Force Timer Event

A number of events can be forced by software action. All events are cleared by
hardware on completion.

@param[in] timer_peripheral Unsigned int32. Timer register address base
@param[in] event Unsigned int8. Event identifier @ref tim_event_gen.
More than one event can be forced at the same time by logical OR of the event
identifiers.
*/

void timer_force_event(u32 timer, u8 event)
{
	TIM_EGR(timer) = event;
}

/* TODO Timer DMA burst */

