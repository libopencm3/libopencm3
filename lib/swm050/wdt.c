/** @defgroup wdg_file Watchdog peripheral API
 * @brief SWM050 WDT API.
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Caleb Szalacinski <contact@skiboy.net>
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Caleb Szalacinski <contact@skiboy.net>
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
#include <libopencm3/swm050/wdt.h>
#include <libopencm3/swm050/sysctl.h>

/**
 * Sets up the WDT before the call to @ref wdt_enable().
 * This only prepares the watchdog, it will not start counting until
 * it is enabled.
 * @param mode passed to @ref wdt_mode()
 * @param time1 passed to @ref wdt_set_time()
 * @param time2 passed to @ref wdt_set_time()
 */
void wdt_setup(enum wdt_modes mode, uint8_t time1, uint8_t time2)
{
	wdt_clock_enable(1);
	wdt_set_time(time1, time2);
	wdt_mode(mode);
	wdt_reset();
}

/**
 * Enables the WDT.
 * This actually starts the watchdog, you should have already selected
 * modes and set timeouts.
 * If @ref WDT_MODE_INT is used, the interrupt should also be enabled
 * using the NVIC before enabling the WDT.
 * @sa wdt_setup
 * @param en enable
 */
void wdt_enable(bool en)
{
	if (en) {
		WDT_CR |= 0x1;
	} else {
		WDT_CR &= ~0x1;
	}
}

/**
 * Sets the WDT's mode of operation.
 * @param mode The mode of operation @ref wdt_modes
 */
void wdt_mode(enum wdt_modes mode)
{
	if (mode == WDT_MODE_INT) {
		WDT_CR |= (1 << 1);
	} else {
		WDT_CR &= ~(1 << 1);
	}
}

/**
 * Reset the WDT's counter.
 * The "feed the dog" operation.  Must be called periodically to avoid a
 * timeout. Calling this also clears any WDT interrupts.
 */
void wdt_reset(void)
{
	WDT_CRR = 0x76;
}

/**
 * Gets the WDT's interrupt status.
 * @note Only useful with @ref WDT_MODE_INT
 * @return The WDT's interrupt status.  True if an interrupt has not been cleared.
 */
bool wdt_int_status(void)
{
	return WDT_STAT & 0x1;
}

/**
 * Clears the WDT's interrupt.
 * @note Only useful with @ref WDT_MODE_INT
 */
void wdt_clear_int(void)
{
	/* Read register to clear the interrupt */
	uint32_t dummy = WDT_EOI;
	/* Does nothing, but suppresses a -Wunused-variable warning */
	(void)dummy;
}

/**
 * Enables the WDT's clock.
 * This only enables the clock to the peripheral.
 * @sa wdt_setup
 * @param en True to enable, false to disable
 */
void wdt_clock_enable(bool en)
{
	if (en) {
		SYSCTL_SYS_CFG_1 |= SYSCTL_SYS_CFG_1_WDT;
	} else {
		SYSCTL_SYS_CFG_1 &= ~SYSCTL_SYS_CFG_1_WDT;
	}
}

/**
 * Gets the current WDT counter value.
 * The vendor-supplied documentation for the @ref WDT_CCVR register appears to be
 * incorrect, and does not seem to be 1 bit wide, which would make no sense.
 * @return The current WDT counter value
 */
uint32_t wdt_get_value(void)
{
	return WDT_CCVR;
}

/**
 * Sets the WDT's initial counter values.
 * Both time1 and time2 follow the equation 2^(8 + i), where i is a value from
 * 0 to 15, and where the result is in clock cycles.
 * For example:
 * 	time1 = 15
 * 	2^(8 + time1) / 18Mhz = 0.466s
 * The majority of the vendor-supplied documentation appears to be completely
 * incorrect about the equation used for these counters.
 *
 * Only the least significant 4 bits are used for both values, eg 0 to 15.
 *
 * @param time1 The timer value used in both modes.  In @ref WDT_MODE_RESET, this
 * value counts down to 0 and resets the system.  In @ref WDT_MODE_INT, this value
 * counts down to 0, generates a WDT interrupt, loads time2 into the counter,
 * and counts down.
 * @param time2 The timer value used after time1 in mode @ref WDT_MODE_INT.  If
 * this counts down to 0, and the WDT interrupt has not been cleared, the
 * system resets. This has no use in mode @ref WDT_MODE_RESET.
 */
void wdt_set_time(uint8_t time1, uint8_t time2)
{
	WDT_TORR = ((0xF & time1) << 4) | (0xF & time2);
}

/**@}*/
