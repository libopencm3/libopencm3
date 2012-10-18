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
/** @defgroup CM3_systick_file SysTick

@ingroup CM3_files

@brief <b>libopencm3 Cortex System Tick Timer</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>

@date 19 August 2012

This library supports the System Tick timer in ARM Cortex Microcontrollers.

The System Tick timer is part of the ARM Cortex core. It is a 24 bit
down counter that can be configured with an automatical reload value.

LGPL License Terms @ref lgpl_license
 */

/**@{*/
#include <libopencm3/cm3/systick.h>

/*-----------------------------------------------------------------------------*/
/** @brief SysTick Set the Automatic Reload Value.

The counter is set to the reload value when the counter starts and after it
reaches zero.

@param[in] value u32. 24 bit reload value.
*/

void systick_set_reload(u32 value)
{
	STK_LOAD = (value & 0x00FFFFFF);
}

/*-----------------------------------------------------------------------------*/
/** @brief SysTick Read the Automatic Reload Value.

@returns 24 bit reload value as u32.
*/

u32 systick_get_value(void)
{
	return STK_VAL;
}

/*-----------------------------------------------------------------------------*/
/** @brief Set the SysTick Clock Source.

The clock source can be either the AHB clock or the same clock divided by 8.

@param[in] clocksource u8. Clock source from @ref systick_clksource.
*/

void systick_set_clocksource(u8 clocksource)
{
	if (clocksource < 2)
		STK_CTRL |= (clocksource << STK_CTRL_CLKSOURCE_LSB);
}

/*-----------------------------------------------------------------------------*/
/** @brief Enable SysTick Interrupt.

*/

void systick_interrupt_enable(void)
{
	STK_CTRL |= STK_CTRL_TICKINT;
}

/*-----------------------------------------------------------------------------*/
/** @brief Disable SysTick Interrupt.

*/

void systick_interrupt_disable(void)
{
	STK_CTRL &= ~STK_CTRL_TICKINT;
}

/*-----------------------------------------------------------------------------*/
/** @brief Enable SysTick Counter.

*/

void systick_counter_enable(void)
{
	STK_CTRL |= STK_CTRL_ENABLE;
}

/*-----------------------------------------------------------------------------*/
/** @brief Disable SysTick Counter.

*/

void systick_counter_disable(void)
{
	STK_CTRL &= ~STK_CTRL_ENABLE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SysTick Read the Counter Flag.

The count flag is set when the timer count becomes zero, and is cleared when the
flag is read.

@returns Boolean if flag set.
*/

u8 systick_get_countflag(void)
{
	if (STK_CTRL & STK_CTRL_COUNTFLAG)
		return 1;
	else
		return 0;
}

/*-----------------------------------------------------------------------------*/
/** @brief SysTick Get Calibration Value

@returns Current calibration value
*/
u32 systick_get_calib(void)
{
	return (STK_CALIB&0x00FFFFFF);
}
/**@}*/

