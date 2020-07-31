/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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
/** @defgroup CM3_systick_defines Cortex-M SysTick Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the Cortex SysTick </b>
 *
 * @ingroup CM3_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>
 *
 * @date 19 August 2012
 *
 * System Control Space (SCS) => System timer register support in the SCS.
 * To configure SysTick, load the interval required between SysTick events to
 * the SysTick Reload Value register. The timer interrupt, or COUNTFLAG bit in
 * the SysTick Control and Status register, is activated on the transition from
 * 1 to 0, therefore it activates every n+1 clock ticks.  If you require a
 * period of 100, write 99 to the SysTick Reload Value register. The SysTick
 * Reload Value register supports values between 0x1 and 0x00FFFFFF.
 *
 * If you want to use SysTick to generate an event at a timed interval, for
 * example 1ms, you can use the SysTick Calibration Value Register to scale
 * your value for the Reload register. The SysTick Calibration Value Register
 * is a read-only register that contains the number of pulses for a period of
 * 10ms, in the TENMS field, bits[23:0].
 *
 * This register also has a SKEW bit. Bit[30] == 1 indicates that the
 * calibration for 10ms in the TENMS section is not exactly 10ms due to clock
 * frequency. Bit[31] == 1 indicates that the reference clock is not provided.
 *
 * LGPL License Terms @ref lgpl_license
 */

/**@{*/

#ifndef LIBOPENCM3_SYSTICK_H
#define LIBOPENCM3_SYSTICK_H

#include <libopencm3/cm3/memorymap.h>
#include <libopencm3/cm3/common.h>

/** SysTick Control and Status Register (CSR).
 * Controls the system timer and provides status data.
 * Usage constraints: There are no usage constraints.
 * Configurations Always implemented.
 */
#define STK_CSR				MMIO32(SYS_TICK_BASE + 0x00)

/** SysTick Reload Value Register (RVR).
 * Reads or clears the value that will be loaded to the counter.
 * Usage constraints:
 * - Any write to the register clears the register to zero.
 * - The counter does not provide read-modify-write protection.
 * - Unsupported bits are read as zero
 * Configurations Always implemented.
 */
#define STK_RVR				MMIO32(SYS_TICK_BASE + 0x04)

/** SysTick Current Value Register (CVR).
 * Holds the current value of the counter.
 * Usage constraints: There are no usage constraints.
 * Configurations Always implemented.
 */
#define STK_CVR				MMIO32(SYS_TICK_BASE + 0x08)

/** SysTick Calibration Value Register(Read Only) (CALIB)
 * Reads the calibration value and parameters for SysTick.
 * Usage constraints: There are no usage constraints.
 * Configurations Always implemented.
 */
#define STK_CALIB			MMIO32(SYS_TICK_BASE + 0x0C)

/** @defgroup STK_CSR_VALUES STK_CSR Values
 * @{
 */
/** COUNTFLAG
 * Indicates whether the counter has counted to 0 since the last read of this
 * register:
 *  0 = Timer has not counted to 0
 *  1 = Timer has counted to 0.
 */
#define STK_CSR_COUNTFLAG		(1 << 16)

#define STK_CSR_CLKSOURCE_LSB		2
/** CLKSOURCE: Clock source selection
 * for 0, SysTick uses the IMPLEMENTATION DEFINED external reference clock.
 * for 1, SysTick uses the processor clock.
 * If no external clock is provided, this bit reads as 1 and ignores writes.
 */
#define STK_CSR_CLKSOURCE		(1 << STK_CSR_CLKSOURCE_LSB)

/** @defgroup systick_clksource Clock source selection
@ingroup CM3_systick_defines

@{*/
#if defined(__ARM_ARCH_6M__)
#define STK_CSR_CLKSOURCE_EXT		(0 << STK_CSR_CLKSOURCE_LSB)
#define STK_CSR_CLKSOURCE_AHB		(1 << STK_CSR_CLKSOURCE_LSB)
#else
#define STK_CSR_CLKSOURCE_AHB_DIV8	(0 << STK_CSR_CLKSOURCE_LSB)
#define STK_CSR_CLKSOURCE_AHB		(1 << STK_CSR_CLKSOURCE_LSB)
#endif
/**@}*/

/** TICKINT: SysTick exception request enable */
#define STK_CSR_TICKINT			(1 << 1)
/** ENABLE: Counter enable */
#define STK_CSR_ENABLE			(1 << 0)
/**@}*/

/** @defgroup STK_RVR_VALUES STK_RVR Values
 * @{
 */
/** RELOAD[23:0]: RELOAD value */
#define STK_RVR_RELOAD			0x00FFFFFF

/**@}*/


/** @defgroup STK_RVR_VALUES STK_RVR Values
 * @{
 */
/** CURRENT[23:0]: Current counter value */
#define STK_CVR_CURRENT			0x00FFFFFF
/**@}*/


/** @defgroup STK_CALIB_VALUES STK_CALIB Values
 * @{
 */
/** NOREF: NOREF flag
 * Bit31 => NOREF Indicates whether the IMPLEMENTATION DEFINED reference clock
 * is implemented:
 * 0 = The reference clock is implemented.
 * 1 = The reference clock is not implemented.
 * When this bit is 1, the CLKSOURCE bit of the SYST_CSR register is forced to
 * 1 and cannot be cleared to 0.
 */
#define STK_CALIB_NOREF			(1 << 31)

/** SKEW: SKEW flag
 * Bit30 => SKEW Indicates whether the 10ms calibration value is exact:
 * 0 = 10ms calibration value is exact.
 * 1 = 10ms calibration value is inexact, because of the clock frequency
 */
#define STK_CALIB_SKEW			(1 << 30)

/* Bits [29:24] Reserved, must be kept cleared. */
/** TENMS Calibration value for 10ms.
 * Bit0 to 23 => TENMS Optionally, holds a reload value to be used for 10ms
 * (100Hz) timing, subject to system clock skew errors. If this field is zero,
 * the calibration value is not known.
 */
#define STK_CALIB_TENMS			0x00FFFFFF
/**@}*/

/* --- Function Prototypes ------------------------------------------------- */

BEGIN_DECLS

void systick_set_reload(uint32_t value);
bool systick_set_frequency(uint32_t freq, uint32_t ahb);
uint32_t systick_get_reload(void);
uint32_t systick_get_value(void);
void systick_set_clocksource(uint8_t clocksource);
void systick_interrupt_enable(void);
void systick_interrupt_disable(void);
void systick_counter_enable(void);
void systick_counter_disable(void);
uint8_t systick_get_countflag(void);
void systick_clear(void);

uint32_t systick_get_calib(void);

END_DECLS

#endif
/**@}*/

