/** @addtogroup rtc_file RTC peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@tweak.net.au>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/stm32/rtc.h>

/*---------------------------------------------------------------------------*/
/** @brief Set RTC prescalars.

This sets the RTC synchronous and asynchronous prescalars.
*/

void rtc_set_prescaler(uint32_t sync, uint32_t async)
{
	/*
	 * Even if only one of the two fields needs to be changed,
	 * 2 separate write accesses must be performed to the RTC_PRER register.
	 */
	RTC_PRER = (sync & RTC_PRER_PREDIV_S_MASK);
	RTC_PRER |= (async << RTC_PRER_PREDIV_A_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief Wait for RTC registers to be synchronised with the APB1 bus

 Time and Date are accessed through shadow registers which must be synchronized
*/

void rtc_wait_for_synchro(void)
{
	/* Unlock RTC registers */
	RTC_WPR = 0xca;
	RTC_WPR = 0x53;

	RTC_ISR &= ~(RTC_ISR_RSF);

	while (!(RTC_ISR & RTC_ISR_RSF));

	/* disable write protection again */
	RTC_WPR = 0xff;
}

/*---------------------------------------------------------------------------*/
/** @brief Unlock write access to the RTC registers

*/
void rtc_unlock(void)
{
	RTC_WPR = 0xca;
	RTC_WPR = 0x53;
}

/*---------------------------------------------------------------------------*/
/** @brief Lock write access to the RTC registers

*/
void rtc_lock(void)
{
	RTC_WPR = 0xff;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the wakeup time auto-reload value

*/
void rtc_set_wakeup_time(uint16_t wkup_time, uint8_t rtc_cr_wucksel)
{
	/* FTFM:
	 * The following sequence is required to configure or change the wakeup
	 * timer auto-reload value (WUT[15:0] in RTC_WUTR):
	 * 1. Clear WUTE in RTC_CR to disable the wakeup timer.
	 */
	RTC_CR &= ~RTC_CR_WUTE;
	/* 2. Poll WUTWF until it is set in RTC_ISR to make sure the access to
	 *    wakeup auto-reload counter and to WUCKSEL[2:0] bits is allowed.
	 *    It takes around 2 RTCCLK clock cycles (due to clock
	 *    synchronization).
	 */
	while (!((RTC_ISR) & (RTC_ISR_WUTWF)));
	/* 3. Program the wakeup auto-reload value WUT[15:0], and the wakeup
	 *    clock selection (WUCKSEL[2:0] bits in RTC_CR).Set WUTE in RTC_CR
	 *    to enable the timer again. The wakeup timer restarts
	 *    down-counting.
	 */
	RTC_WUTR = wkup_time;
	RTC_CR &= ~(RTC_CR_WUCLKSEL_MASK << RTC_CR_WUCLKSEL_SHIFT);
	RTC_CR |= (rtc_cr_wucksel << RTC_CR_WUCLKSEL_SHIFT);
	RTC_CR |= RTC_CR_WUTE;
}

/*---------------------------------------------------------------------------*/
/** @brief Clears the wakeup flag

@details This function should be called first in the rtc_wkup_isr()
*/
void rtc_clear_wakeup_flag(void)
{
	RTC_ISR &= ~RTC_ISR_WUTF;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the initialization flag

@details Requires unlocking backup domain write protection (PWR_CR_DBP)
*/
void rtc_set_init_flag(void)
{
	RTC_ISR |= RTC_ISR_INIT;
}

/*---------------------------------------------------------------------------*/
/** @brief Clears (resets) the initialization flag

@details Requires unlocking backup domain write protection (PWR_CR_DBP)
*/
void rtc_clear_init_flag(void)
{
	RTC_ISR &= ~RTC_ISR_INIT;
}

/*---------------------------------------------------------------------------*/
/** @brief Returns if the RTC_ISR init flag RTC_ISR_INITF is set

@details Requires unlocking backup domain write protection (PWR_CR_DBP)
*/
bool rtc_init_flag_is_ready(void)
{
	return (RTC_ISR & RTC_ISR_INITF);
}

/*---------------------------------------------------------------------------*/
/** @brief Waits infinitely for initialization flag to be set in RTC_ISR

@details Requires unlocking backup domain write protection (PWR_CR_DBP)
*/
void rtc_wait_for_init_ready(void)
{
	while (!rtc_init_flag_is_ready());
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the bypass shadow bit in RTC_CR

@details Requires unlocking backup domain write protection (PWR_CR_DBP)
*/
void rtc_enable_bypass_shadow_register(void)
{
	RTC_CR |= RTC_CR_BYPSHAD;
}

/*---------------------------------------------------------------------------*/
/** @brief Clears the bypass shadow bit in RTC_CR

@details Requires unlocking backup domain write protection (PWR_CR_DBP)
*/
void rtc_disable_bypass_shadow_register(void)
{
	RTC_CR &= ~RTC_CR_BYPSHAD;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC hour format (24h or 12h)

@details Requires unlocking backup domain write protection (PWR_CR_DBP)
*/
void rtc_set_hour_format(enum rtc_fmt fmt)
{
	switch (fmt) {
	case RTC_CR_FMT_24H:
		RTC_CR &= ~RTC_CR_FMT;
		break;
	case RTC_CR_FMT_12H:
		RTC_CR |= RTC_CR_FMT;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD calendar year value (tens and ones)

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_calendar_set_year(uint8_t year_tens, uint8_t year_units)
{
	RTC_DR = ((year_tens & RTC_DR_YT_MASK) << RTC_DR_YT_SHIFT) |
		(RTC_DR & ~(RTC_DR_YT_MASK << RTC_DR_YT_SHIFT));
	RTC_DR = ((year_units & RTC_DR_YU_MASK) << RTC_DR_YU_SHIFT) |
		(RTC_DR & ~(RTC_DR_YU_MASK << RTC_DR_YU_SHIFT));
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD calendar weekday

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_calendar_set_weekday(enum rtc_wdu weekday)
{
	RTC_DR = ((weekday & RTC_DR_WDU_MASK) << RTC_DR_WDU_SHIFT) |
		(RTC_DR & ~(RTC_DR_WDU_MASK << RTC_DR_WDU_SHIFT));
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD calendar month value (tens and ones)

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_calendar_set_month(uint8_t month_tens, uint8_t month_units)
{
	RTC_DR = ((month_tens & RTC_DR_MT_MASK) << RTC_DR_MT_SHIFT) |
		(RTC_DR & ~(RTC_DR_MT_MASK << RTC_DR_MT_SHIFT));
	RTC_DR = ((month_units & RTC_DR_MU_MASK) << RTC_DR_MU_SHIFT) |
		(RTC_DR & ~(RTC_DR_MU_MASK << RTC_DR_MU_SHIFT));
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD calendar day value (tens and ones)

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_calendar_set_day(uint8_t day_tens, uint8_t day_units)
{
	RTC_DR = ((day_tens & RTC_DR_DT_MASK) << RTC_DR_DT_SHIFT) |
		(RTC_DR & ~(RTC_DR_DT_MASK << RTC_DR_DT_SHIFT));
	RTC_DR = ((day_units & RTC_DR_DU_MASK) << RTC_DR_DU_SHIFT) |
		(RTC_DR & ~(RTC_DR_DU_MASK << RTC_DR_DU_SHIFT));
}

/*---------------------------------------------------------------------------*/
/** @brief Sets RTC time to use AM or 24-hour format

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_time_set_am_notation(void)
{
	RTC_TR &= ~RTC_TR_PM;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC time to use AM/PM or 12-hour format

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_time_set_pm_notation(void)
{
	RTC_TR |= RTC_TR_PM;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD time hour value (tens and ones)

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_time_set_hour(uint8_t hour_tens, uint8_t hour_units)
{
	RTC_TR = ((hour_tens & RTC_TR_HT_MASK) << RTC_TR_HT_SHIFT) |
		(RTC_TR & ~(RTC_TR_HT_MASK << RTC_TR_HT_SHIFT));
	RTC_TR = ((hour_units & RTC_TR_HU_MASK) << RTC_TR_HU_SHIFT) |
		(RTC_TR & ~(RTC_TR_HU_MASK << RTC_TR_HU_SHIFT));
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD time minute value (tens and ones)

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_time_set_minute(uint8_t min_tens, uint8_t min_units)
{
	RTC_TR = ((min_tens & RTC_TR_MNT_MASK) << RTC_TR_MNT_SHIFT) |
		(RTC_TR & ~(RTC_TR_MNT_MASK << RTC_TR_MNT_SHIFT));
	RTC_TR = ((min_units & RTC_TR_MNU_MASK) << RTC_TR_MNU_SHIFT) |
		(RTC_TR & ~(RTC_TR_MNU_MASK << RTC_TR_MNU_SHIFT));
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD time second value (tens and ones)

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_time_set_second(uint8_t sec_tens, uint8_t sec_units)
{
	RTC_TR = ((sec_tens & RTC_TR_ST_MASK) << RTC_TR_ST_SHIFT) |
		(RTC_TR & ~(RTC_TR_ST_MASK << RTC_TR_ST_SHIFT));
	RTC_TR = ((sec_units & RTC_TR_SU_MASK) << RTC_TR_SU_SHIFT) |
		(RTC_TR & ~(RTC_TR_SU_MASK << RTC_TR_SU_SHIFT));
}
/**@}*/
