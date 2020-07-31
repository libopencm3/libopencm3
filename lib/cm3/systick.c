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
 *
 * @ingroup CM3_files
 *
 * @brief <b>libopencm3 Cortex System Tick Timer</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>
 *
 * @date 19 August 2012
 *
 * This library supports the System Tick timer in ARM Cortex Microcontrollers.
 *
 * The System Tick timer is part of the ARM Cortex core. It is a 24 bit
 * down counter that can be configured with an automatical reload value.
 *
 * LGPL License Terms @ref lgpl_license
 */

/**@{*/
#include <libopencm3/cm3/systick.h>

/*---------------------------------------------------------------------------*/
/** @brief SysTick Set the Automatic Reload Value.
 *
 * The counter is set to the reload value when the counter starts and after it
 * reaches zero.
 *
 * @note The systick counter value might be undefined upon startup. To get
 * predictable behavior, it is a good idea to set or clear the counter after
 * set reload. @sa systick_clear
 *
 * @param[in] value uint32_t. 24 bit reload value.
 */

void systick_set_reload(uint32_t value)
{
	STK_RVR = (value & STK_RVR_RELOAD);
}

/*---------------------------------------------------------------------------*/
/** @brief SysTick Read the Automatic Reload Value.
 *
 * @returns 24 bit reload value as uint32_t.
 */

uint32_t systick_get_reload(void)
{
	return STK_RVR & STK_RVR_RELOAD;
}

/** @brief SysTick Set clock and frequency of overflow
 *
 * This function sets the systick to AHB clock source, and the prescaler to
 * generate interrupts with the desired frequency. The function fails, if
 * the frequency is too low.
 *
 * @param[in] freq uint32_t The desired frequency in Hz
 * @param[in] ahb uint32_t The current AHB frequency in Hz
 * @returns true, if success, false if the desired frequency cannot be set.
 */
bool systick_set_frequency(uint32_t freq, uint32_t ahb)
{
	uint32_t ratio = ahb / freq;

#if defined(__ARM_ARCH_6M__)
	systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);
#else
	if (ratio >= (STK_RVR_RELOAD * 8)) {
		/* This frequency is too slow */
		return false;
	} else if (ratio >= STK_RVR_RELOAD) {
		ratio /= 8;
		systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);
	} else {
		systick_set_clocksource(STK_CSR_CLKSOURCE_AHB);
	}
#endif
	systick_set_reload(ratio - 1);
	return true;
}

/*---------------------------------------------------------------------------*/
/** @brief Get the current SysTick counter value.
 *
 * @returns 24 bit current value as uint32_t.
 */

uint32_t systick_get_value(void)
{
	return STK_CVR & STK_CVR_CURRENT;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the SysTick Clock Source.
 *
 * The clock source can be either the AHB clock or the same clock divided by 8.
 *
 * @param[in] clocksource uint8_t. Clock source from @ref systick_clksource.
 */

void systick_set_clocksource(uint8_t clocksource)
{
	STK_CSR = (STK_CSR & ~STK_CSR_CLKSOURCE) |
		  (clocksource & STK_CSR_CLKSOURCE);
}

/*---------------------------------------------------------------------------*/
/** @brief Enable SysTick Interrupt.
 *
 */

void systick_interrupt_enable(void)
{
	STK_CSR |= STK_CSR_TICKINT;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable SysTick Interrupt.
 *
 */

void systick_interrupt_disable(void)
{
	STK_CSR &= ~STK_CSR_TICKINT;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable SysTick Counter.
 *
 */

void systick_counter_enable(void)
{
	STK_CSR |= STK_CSR_ENABLE;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable SysTick Counter.
 *
 */

void systick_counter_disable(void)
{
	STK_CSR &= ~STK_CSR_ENABLE;
}

/*---------------------------------------------------------------------------*/
/** @brief SysTick Read the Counter Flag.
 *
 * The count flag is set when the timer count becomes zero, and is cleared when
 * the flag is read.
 *
 * @returns Boolean if flag set.
 */

uint8_t systick_get_countflag(void)
{
	return (STK_CSR & STK_CSR_COUNTFLAG) ? 1 : 0;
}

/*---------------------------------------------------------------------------*/
/** @brief SysTick Clear counter Value.
 *
 * The counter value is cleared. Useful for well defined startup.
 */

void systick_clear(void)
{
	STK_CVR = 0;
}

/*---------------------------------------------------------------------------*/
/** @brief SysTick Get Calibration Value
 *
 * @returns Current calibration value
 */
uint32_t systick_get_calib(void)
{
	return STK_CALIB & STK_CALIB_TENMS;
}
/**@}*/

