/** @defgroup timer_defines Timer Defines
 *
 * @brief <b>Defined Constants and Types for the SWM050 Timer</b>
 *
 * @ingroup SWM050_defines
 *
 * LGPL License Terms @ref lgpl_license
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
#ifndef LIBOPENCM3_TIMER_H
#define LIBOPENCM3_TIMER_H
#include <libopencm3/cm3/common.h>
#include <libopencm3/swm050/memorymap.h>

/** @defgroup timer_select Timer Select
@{*/
#define TIMER_SE0	TIMER_SE0_BASE
#define TIMER_SE1	TIMER_SE1_BASE
/*@}*/

/** Timer Level */
enum timer_level {
	TIMER_LEVEL_LOW,
	TIMER_LEVEL_HIGH
};

/** Timer Edge Modes */
enum timer_edge_modes {
	/** Trigger on rising edge */
	TIMER_EDGE_RISING,
	/** Trigger on falling edge */
	TIMER_EDGE_FALLING
};

/** Timer Operation Modes */
enum timer_operation_modes {
	TIMER_MODE_COUNTER,
	TIMER_MODE_PWM,
	TIMER_MODE_PULSE_CAPTURE,
	TIMER_MODE_DUTY_CYCLE_CAPTURE
};

/** Timer Clock Source */
enum timer_clk_src {
	TIMER_CLK_INTERNAL,
	TIMER_CLK_EXTERNAL
};

/** Timer Interrupt Mask */
enum timer_int_masked {
	TIMER_UNMASKED,
	TIMER_MASKED
};

/** Timer Loop Modes */
enum timer_loop_modes {
	TIMER_LOOP_MODE,
	TIMER_SINGLE_MODE
};

/** Timer Output Modes */
enum timer_output_modes {
	TIMER_OUTPUT_NONE,
	TIMER_OUTPUT_INVERT,
	TIMER_OUTPUT_HIGH,
	TIMER_OUTPUT_LOW
};

/** Timer PWM Periods */
enum timer_pwm_period {
	TIMER_PERIOD_0,
	TIMER_PERIOD_1
};

/** Timer Clock Divider Mask */
#define TIMER_DIV_MASK			(0x3F << 16)

/** @defgroup timer_registers Timer Registers
@{*/
/** Timer control register */
#define TIMER_CTRL(x)			MMIO32(x + 0x0)
/** The target value(s). Treated as uint32_t in counter mode (0), and as 2
    uint16_t values in PWM mode (1) */
#define TIMER_TARVAL(x)			MMIO32(x + 0x4)
/** Current count value in modes 0, 2, and 3 */
#define TIMER_CURVAL(x)			MMIO32(x + 0x8)
/** Cycle width in mode 3 */
#define TIMER_CAPW(x)			MMIO32(x + 0xC)
/** Pulse width in modes 2 and 3 */
#define TIMER_CAPLH(x)			MMIO32(x + 0x10)
/** PWM state in mode 1 */
#define TIMER_MOD2LF(x)			MMIO32(x + 0x14)
/** Timer output pin value */
#define TIMER_OUTPVAL(x)		MMIO32(x + 0x80)
/** Interrupt enable and mask */
#define TIMER_INTCTL(x)			MMIO32(x + 0x84)
/** Interrupt status before masking */
#define TIMER_INTSTAT(x)		MMIO32(x + 0x88)
/** Interrupt status after masking */
#define TIMER_INTMSKSTAT(x)		MMIO32(x + 0x8C)
/** Interrupt overflow; 1 if interrupt occurs again without being cleared */
#define TIMER_INTFLAG(x)		MMIO32(x + 0x90)
/*@}*/

/** @defgroup timer_reg_values Timer Register Values
@{*/
#define TIMER_CTRL_EN		1
/** Clock source selection */
#define TIMER_CTRL_OSCMOD	(1 << 8)
/** Valid edge selection */
#define TIMER_CTRL_TMOD		(1 << 16)
/** Loop mode selection */
#define TIMER_CTRL_LMOD		(1 << 28)
/** Timer Output Mode Mask */
#define TIMER_CTRL_OUTMOD_MASK	0x3
#define TIMER_CTRL_OUTMOD_SHIFT	12
/** Timer Operation Mode Mask */
#define TIMER_CTRL_WMOD_MASK	0x3
#define TIMER_CTRL_WMOD_SHIFT	4
/** Interrupt mask */
#define TIMER_INTCTL_INTMSK	(1 << 1)
/** Interrupt enable */
#define TIMER_INTCTL_INTEN	1
/*@}*/

BEGIN_DECLS

void timer_counter_setup(uint32_t timer,
			 bool timer_int_en,
			 enum timer_edge_modes edge_mode,
			 enum timer_loop_modes loop_mode,
			 enum timer_clk_src clk_src,
			 enum timer_output_modes output_mode,
			 enum timer_level output_level,
			 uint32_t target);

void timer_pwm_setup(uint32_t timer,
		     bool timer_int_en,
		     enum timer_edge_modes edge_mode,
		     enum timer_clk_src clk_src,
		     enum timer_level output_level,
		     uint16_t target1,
		     uint16_t target2);

void timer_pulse_capture_setup(uint32_t timer,
			       bool timer_int_en,
			       enum timer_edge_modes edge_mode,
			       enum timer_loop_modes loop_mode);

void timer_duty_cycle_capture_setup(uint32_t timer,
				    bool timer_int_en,
				    enum timer_edge_modes edge_mode,
				    enum timer_loop_modes loop_mode);

void timer_clock_div(uint8_t div);
void timer_enable(uint32_t timer, bool en);
void timer_clock_enable(uint32_t timer, bool en);
void timer_operation_mode(uint32_t timer, enum timer_operation_modes mode);
void timer_output_mode(uint32_t timer, enum timer_output_modes mode);
void timer_output_level(uint32_t timer, enum timer_level level);
void timer_edge_mode(uint32_t timer, enum timer_edge_modes mode);
void timer_loop_mode(uint32_t timer, enum timer_loop_modes mode);
void timer_clock_source(uint32_t timer, enum timer_clk_src src);
void timer_counter_target_value(uint32_t timer, uint32_t target);
void timer_pwm_target_value(uint32_t timer, uint16_t period0, uint16_t period1);
void timer_int_enable(uint32_t timer, bool en);
void timer_int_mask(uint32_t timer, enum timer_int_masked masked);
uint32_t timer_get_current_value(uint32_t timer);
uint32_t timer_get_cycle_width(uint32_t timer);
uint32_t timer_get_pulse_width(uint32_t timer);
enum timer_pwm_period timer_get_pwm_period(uint32_t timer);
bool timer_int_status(uint32_t timer);
bool timer_int_raw_status(uint32_t timer);
bool timer_int_overflow_status(uint32_t timer);

END_DECLS

#endif
/**@}*/
