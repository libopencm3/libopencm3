/** @defgroup timer_file Timer peripheral API
 * @brief SWM050 Timer API.
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2020
 * Caleb Szalacinski <contact@skiboy.net>
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Caleb Szalacinski <contact@skiboy.net>
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
#include <libopencm3/swm050/timer.h>
#include <libopencm3/swm050/sysctl.h>
#include <libopencm3/swm050/syscon.h>

/**
 * Internal function for timer setup.
 * @param timer Select timer @ref timer_select
 * @param timer_int_en Passed to @ref timer_int_enable()
 * @param op_mode Passed to @ref timer_operation_mode()
 * @param edge_mode Passed to @ref timer_edge_mode()
 * @param loop_mode Passed to @ref timer_loop_mode()
 * @param clk_src Passed to @ref timer_clock_source()
 * @param output_mode Passed to @ref timer_output_mode()
 * @param output_level Passed to @ref timer_output_level()
 */
static void timer_setup_internal(uint32_t timer,
				 bool timer_int_en,
				 enum timer_operation_modes op_mode,
				 enum timer_edge_modes edge_mode,
				 enum timer_loop_modes loop_mode,
				 enum timer_clk_src clk_src,
				 enum timer_output_modes output_mode,
				 enum timer_level output_level)
{
	timer_enable(timer, false);

	/* Conserve power by shutting off the unneeded clock */
	timer_clock_enable(timer, (clk_src == TIMER_CLK_INTERNAL));

	timer_loop_mode(timer, loop_mode);
	timer_output_mode(timer, output_mode);
	timer_output_level(timer, output_level);
	timer_clock_source(timer, clk_src);
	timer_operation_mode(timer, op_mode);
	timer_edge_mode(timer, edge_mode);
	timer_int_enable(timer, timer_int_en);
	timer_int_mask(timer, TIMER_UNMASKED);
}

/**
 * Setup the timer in counter mode.
 * @note Call @ref timer_enable() when you are ready to start the timer.
 * @note Be sure to set the alternate functions of the timer pins
 *	with @ref syscon_sel_af() and disable SWD on those pins
 *	with @ref syscon_sel_swd() as needed.
 * @note If interrupts are enabled here, the interrupt should also be enabled
 *	using the NVIC before enabling the timer.
 * @param timer Select timer @ref timer_select
 * @param timer_int_en Passed to @ref timer_int_enable()
 * @param edge_mode Passed to @ref timer_edge_mode()
 * @param loop_mode Passed to @ref timer_loop_mode()
 * @param clk_src Passed to @ref timer_clock_source()
 * @param output_mode Passed to @ref timer_output_mode()
 * @param output_level Passed to @ref timer_output_level()
 * @param target Passed to @ref timer_counter_target_value()
 */
void timer_counter_setup(uint32_t timer,
			 bool timer_int_en,
			 enum timer_edge_modes edge_mode,
			 enum timer_loop_modes loop_mode,
			 enum timer_clk_src clk_src,
			 enum timer_output_modes output_mode,
			 enum timer_level output_level,
			 uint32_t target)
{
	timer_setup_internal(timer, timer_int_en, TIMER_MODE_COUNTER, edge_mode,
			     loop_mode, clk_src, output_mode, output_level);
	timer_counter_target_value(timer, target);
}

/**
 * Setup the timer in PWM mode.
 * @note Call @ref timer_enable() when you are ready to start the timer.
 * @note Be sure to set the alternate functions of the timer pins
 *	with @ref syscon_sel_af() and disable SWD on those pins
 *	with @ref syscon_sel_swd() as needed.
 * @note If interrupts are enabled here, the interrupt should also be enabled
 *	using the NVIC before enabling the timer.
 * @param timer Select timer @ref timer_select
 * @param timer_int_en Passed to @ref timer_int_enable()
 * @param edge_mode Passed to @ref timer_edge_mode()
 * @param clk_src Passed to @ref timer_clock_source()
 * @param output_level Passed to @ref timer_output_level()
 * @param period0 Passed to @ref timer_pwm_target_value()
 * @param period1 Passed to @ref timer_pwm_target_value()
 */
void timer_pwm_setup(uint32_t timer,
		     bool timer_int_en,
		     enum timer_edge_modes edge_mode,
		     enum timer_clk_src clk_src,
		     enum timer_level output_level,
		     uint16_t period0,
		     uint16_t period1)
{
	timer_setup_internal(timer, timer_int_en, TIMER_MODE_PWM, edge_mode,
			     TIMER_LOOP_MODE, clk_src, TIMER_OUTPUT_NONE,
			     output_level);
	timer_pwm_target_value(timer, period0, period1);
}

/**
 * Setup the timer in pulse capture mode.
 * @note Call @ref timer_enable() when you are ready to start the timer.
 * @note Be sure to set the alternate functions of the timer pins
 *	with @ref syscon_sel_af() and disable SWD on those pins
 *	with @ref syscon_sel_swd() as needed.
 * @note If interrupts are enabled here, the interrupt should also be enabled
 *	using the NVIC before enabling the timer.
 * @param timer Select timer @ref timer_select
 * @param timer_int_en Passed to @ref timer_int_enable()
 * @param edge_mode Passed to @ref timer_edge_mode()
 * @param loop_mode Passed to @ref timer_loop_mode()
 */
void timer_pulse_capture_setup(uint32_t timer,
			       bool timer_int_en,
			       enum timer_edge_modes edge_mode,
			       enum timer_loop_modes loop_mode)
{
	timer_setup_internal(timer, timer_int_en, TIMER_MODE_PULSE_CAPTURE,
			     edge_mode, loop_mode, TIMER_CLK_INTERNAL,
			     TIMER_OUTPUT_NONE, TIMER_LEVEL_LOW);
}

/**
 * Setup the timer in duty cycle capture mode.
 * @note Call @ref timer_enable() when you are ready to start the timer.
 * @note Be sure to set the alternate functions of the timer pins
 *	with @ref syscon_sel_af() and disable SWD on those pins
 *	with @ref syscon_sel_swd() as needed.
 * @note If interrupts are enabled here, the interrupt should also be enabled
 *	using the NVIC before enabling the timer.
 * @param timer Select timer @ref timer_select
 * @param timer_int_en Passed to @ref timer_int_enable()
 * @param edge_mode Passed to @ref timer_edge_mode()
 * @param loop_mode Passed to @ref timer_loop_mode()
 */
void timer_duty_cycle_capture_setup(uint32_t timer,
				    bool timer_int_en,
				    enum timer_edge_modes edge_mode,
				    enum timer_loop_modes loop_mode)
{
	timer_setup_internal(timer, timer_int_en, TIMER_MODE_DUTY_CYCLE_CAPTURE,
			     edge_mode, loop_mode, TIMER_CLK_INTERNAL,
			     TIMER_OUTPUT_NONE, TIMER_LEVEL_LOW);
}

/**
 * Set the timer clock divider, based off of the 18MHz oscillator
 * @param div Timer clock divider. Only the 6 least-significant bits are used,
 *	Takes values from 0 to 63 (in reality the possible values are the even
 *	numbers from 2 to 62, as well as the number 1). Anything after the 6
 *	least-significant bits are stripped off of the value. If the value is 0,
 *	it will be treated as a 1.  All odd values other than 1 are rounded down
 *	to the closest even value, due to the fact that all odd values are
 *	treated by the register as a 1, which would likely be unexpected. A
 *	value of 0 would also normally be treated as a 2, which would also be
 *	unexpected behavior.
 */
void timer_clock_div(uint8_t div)
{
	/* If the value is 0 or 1, make it odd, meaning no divide. */
	/* Otherwise, drop div to the closest even value. */
	div = (div <= 1) ? 1 : (div & ~0x1);
	SYSCTL_SYS_CFG_0 = (~TIMER_DIV_MASK & SYSCTL_SYS_CFG_0) | (div << 16);
}

/**
 * Enables or disables the timer.
 * @param timer Select timer @ref timer_select
 * @param en Enable or disable the timer
 */
void timer_enable(uint32_t timer, bool en)
{
	if (en) {
		TIMER_CTRL(timer) |= TIMER_CTRL_EN;
	} else {
		TIMER_CTRL(timer) &= ~TIMER_CTRL_EN;
	}
}

/**
 * Enables or disables the timer's internal clock.
 * @param timer Select timer @ref timer_select
 * @param en Enable or disable the internal clock
 */
void timer_clock_enable(uint32_t timer, bool en)
{
	if (timer == TIMER_SE1) {
		if (en) {
			SYSCTL_SYS_CFG_1 |= SYSCTL_SYS_CFG_1_TIMERSE1;
		} else {
			SYSCTL_SYS_CFG_1 &= ~SYSCTL_SYS_CFG_1_TIMERSE1;
		}
	} else {
		if (en) {
			SYSCTL_SYS_CFG_1 |= SYSCTL_SYS_CFG_1_TIMERSE0;
		} else {
			SYSCTL_SYS_CFG_1 &= ~SYSCTL_SYS_CFG_1_TIMERSE0;
		}
	}
}

/**
 * Selects the mode of operation.
 * @param timer Select timer @ref timer_select
 * @param mode The mode of operation @ref timer_operation_modes
 */
void timer_operation_mode(uint32_t timer, enum timer_operation_modes mode)
{
	uint32_t reg = TIMER_CTRL(timer) & ~(TIMER_CTRL_OUTMOD_MASK << TIMER_CTRL_OUTMOD_SHIFT);
	TIMER_CTRL(timer) = reg | (mode << TIMER_CTRL_OUTMOD_SHIFT);
}

/**
 * Selects the output mode.
 * Only used in counter mode.
 * When done counting, the pin can be set to no output,
 * to invert the current pin level, to set the pin high,
 * or to set the pin low.
 * @note Be sure to set the alternate functions of the timer pins
 *	with @ref syscon_sel_af() and disable SWD on those pins
 *	with @ref syscon_sel_swd() as needed.
 * @param timer Select timer @ref timer_select
 * @param mode The output mode @ref timer_output_modes
 */
void timer_output_mode(uint32_t timer, enum timer_output_modes mode)
{
	uint32_t reg = TIMER_CTRL(timer) & ~(TIMER_CTRL_WMOD_MASK << TIMER_CTRL_WMOD_SHIFT);
	TIMER_CTRL(timer) = reg | (mode << TIMER_CTRL_WMOD_SHIFT);
}

/**
 * Selects the initial output level.
 * Only used in counter and PWM modes.
 * @param timer Select timer @ref timer_select
 * @param level The initial output level @ref timer_level
 */
void timer_output_level(uint32_t timer, enum timer_level level)
{
	TIMER_OUTPVAL(timer) = level;
}

/**
 * Selects the edge mode.
 * @param timer Select timer @ref timer_select
 * @param mode The edge mode @ref timer_edge_modes
 */
void timer_edge_mode(uint32_t timer, enum timer_edge_modes mode)
{
	if (mode) {
		TIMER_CTRL(timer) |= TIMER_CTRL_TMOD;
	} else {
		TIMER_CTRL(timer) &= ~TIMER_CTRL_TMOD;
	}
}

/**
 * Selects the loop mode.
 * This has no use in PWM mode.
 * In loop mode with counter mode, the counter will constantly loop.
 * In loop mode with the capture modes, the values will be captured
 * again and again. In single mode, these operations happen only once.
 * @param timer Select timer @ref timer_select
 * @param mode The loop mode @ref timer_loop_modes
 */
void timer_loop_mode(uint32_t timer, enum timer_loop_modes mode)
{
	if (mode) {
		TIMER_CTRL(timer) |= TIMER_CTRL_LMOD;
	} else {
		TIMER_CTRL(timer) &= ~TIMER_CTRL_LMOD;
	}
}

/**
 * Selects the clock source for the timer.
 * @note Be sure to set the alternate functions of the timer pins
 *	with @ref syscon_sel_af() and disable SWD on those pins
 *	with @ref syscon_sel_swd() as needed.
 * @note If not using the internal clock, you can disable it
 *	with @ref timer_clock_enable() for power savings.
 * @param timer Select timer @ref timer_select
 * @param src Select the internal or external clock source @ref timer_clk_src
 */
void timer_clock_source(uint32_t timer, enum timer_clk_src src)
{
	if (src) {
		TIMER_CTRL(timer) |= TIMER_CTRL_OSCMOD;
	} else {
		TIMER_CTRL(timer) &= ~TIMER_CTRL_OSCMOD;
	}
}

/**
 * Sets the target values for counter mode.
 * @param timer Select timer @ref timer_select
 * @param target The value to count up to
 */
void timer_counter_target_value(uint32_t timer, uint32_t target)
{
	TIMER_TARVAL(timer) = target;
}

/**
 * Sets the target values for PWM mode.
 * @param timer Select timer @ref timer_select
 * @param period0 length of period 0 in clock cycles. Whether
 *	it is high or low is set in @ref timer_output_level()
 * @param period1 length of period 1
 */
void timer_pwm_target_value(uint32_t timer, uint16_t period0, uint16_t period1)
{
	timer_counter_target_value(timer, (period1 << 16) | period0);
}

/**
 * Enable or disable the interrupt.
 * In counter mode, when the count has been completed,
 * an interrupt is generated.
 * In PWM mode, on a level change, an interupt is generated.
 * In either capture mode, when a capture is complete,
 * an interrupt is generated.
 * @note If interrupts are enabled here, the interrupt should also be enabled
 *	using the NVIC before enabling the timer.
 * @param timer Select timer @ref timer_select
 * @param en Enable or disable the interrupt
 */
void timer_int_enable(uint32_t timer, bool en)
{
	if (en) {
		TIMER_INTCTL(timer) |= TIMER_INTCTL_INTEN;
	} else {
		TIMER_INTCTL(timer) &= ~TIMER_INTCTL_INTEN;
	}
}

/**
 * Sets the interrupt mask.
 * @param timer Select timer @ref timer_select
 * @param masked Whether or not to mask the interrupt @ref timer_int_masked
 */
void timer_int_mask(uint32_t timer, enum timer_int_masked masked)
{
	if (masked) {
		TIMER_INTCTL(timer) &= ~TIMER_INTCTL_INTMSK;
	} else {
		TIMER_INTCTL(timer) |= TIMER_INTCTL_INTMSK;
	}
}

/**
 * Gets the current counter value, and clears the interrupt/interrupt overflow.
 * If in PWM mode, this is only used for clearing the interrupt.
 * @param timer Select timer @ref timer_select
 * @return The current counter value
 */
uint32_t timer_get_current_value(uint32_t timer)
{
	return TIMER_CURVAL(timer);
}

/**
 * Gets the cycle width.
 * Only used in duty cycle capture mode.
 * @note See the datasheet for more concise diagrams.
 * @param timer Select timer @ref timer_select
 * @return The cycle width
 */
uint32_t timer_get_cycle_width(uint32_t timer)
{
	return TIMER_CAPW(timer);
}

/**
 * Gets the pulse width in pulse capture mode,
 * or gets the period width in duty cycle capture mode.
 * @note See the datasheet for more concise diagrams.
 * @param timer Select timer @ref timer_select
 * @return The pulse width
 */
uint32_t timer_get_pulse_width(uint32_t timer)
{
	return TIMER_CAPLH(timer);
}

/**
 * Gets the current output period in PWM mode.
 * @param timer Select timer @ref timer_select
 * @return The current output period @ref timer_pwm_period
 */
enum timer_pwm_period timer_get_pwm_period(uint32_t timer)
{
	return TIMER_MOD2LF(timer) & 0x1;
}

/**
 * Gets the interrupt status after masking.
 * @param timer Select timer @ref timer_select
 * @return The interrupt status after masking
 */
bool timer_int_status(uint32_t timer)
{
	return TIMER_INTMSKSTAT(timer) & 0x1;
}

/**
 * Gets the interrupt status before masking.
 * @param timer Select timer @ref timer_select
 * @return The interrupt status before masking
 */
bool timer_int_raw_status(uint32_t timer)
{
	return TIMER_INTSTAT(timer) & 0x1;
}

/**
 * Gets the interrupt overflow status.
 * Overflow will occur if the interrupt has not been cleared when a second
 * interrupt happens.
 * @param timer Select timer @ref timer_select
 * @return The interrupt overflow status
 */
bool timer_int_overflow_status(uint32_t timer)
{
	return TIMER_INTFLAG(timer) & 0x1;
}

/**@}*/
