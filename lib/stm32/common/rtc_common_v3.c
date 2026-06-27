/** @addtogroup rtc_file RTC peripheral API
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@tweak.net.au>
@author @htmlonly &copy; @endhtmlonly 2026 Lionel Choubex <lionel.choubex@proton.me>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
 * Copyright (C) 2026 Lionel Choubex <lionel.choubex@proton.me>
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
#include <libopencm3/cm3/assert.h>

static uint8_t _rtc_dec_to_bcd(uint8_t dec)
{
	return ((dec / 10) << 4) | (dec % 10);
}

/*---------------------------------------------------------------------------*/
/** @brief Set RTC prescalers.

This sets the RTC synchronous and asynchronous prescalers.
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

	RTC_ICSR &= ~(RTC_ICSR_RSF);

	while (!(RTC_ICSR & RTC_ICSR_RSF));

	/* disable write protection again */
	RTC_WPR = 0xff;
}

/*---------------------------------------------------------------------------*/
/** @brief Lock write access to the RTC registers

*/
void rtc_lock(void)
{
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
	/* 2. Poll WUTWF until it is set in RTC_ICSR to make sure the access to
	 *    wakeup auto-reload counter and to WUCKSEL[2:0] bits is allowed.
	 *    It takes around 2 RTCCLK clock cycles (due to clock
	 *    synchronization).
	 */
	while (!((RTC_ICSR) & (RTC_ICSR_WUTWF)));
	/* 3. Program the wakeup auto-reload value WUT[15:0], and the wakeup
	 *    clock selection (WUCKSEL[2:0] bits in RTC_CR).Set WUTE in RTC_CR
	 *    to enable the timer again. The wakeup timer restarts
	 *    down-counting.
	 */
	RTC_WUTR = wkup_time;
	RTC_CR &= ~(RTC_CR_WUCKSEL_MASK << RTC_CR_WUCKSEL_SHIFT);
	RTC_CR |= (rtc_cr_wucksel << RTC_CR_WUCKSEL_SHIFT);
	RTC_CR |= RTC_CR_WUTE;
}

/*---------------------------------------------------------------------------*/
/** @brief Clears the wakeup flag

@details This function should be called first in the rtc_wkup_isr()
*/
void rtc_clear_wakeup_flag(void)
{
	RTC_SR &= ~RTC_SR_WUTF;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the initialization flag

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_set_init_flag(void)
{
	RTC_ICSR |= RTC_ICSR_INIT;
}

/*---------------------------------------------------------------------------*/
/** @brief Clears (resets) the initialization flag

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_clear_init_flag(void)
{
	RTC_ICSR &= ~RTC_ICSR_INIT;
}

/*---------------------------------------------------------------------------*/
/** @brief Returns if the RTC_ICSR init flag RTC_ICSR_INITF is set

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
bool rtc_init_flag_is_ready(void)
{
	return (RTC_ICSR & RTC_ICSR_INITF);
}

/*---------------------------------------------------------------------------*/
/** @brief Waits infinitely for initialization flag to be set in RTC_ICSR

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_wait_for_init_ready(void)
{
	while (!rtc_init_flag_is_ready());
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the bypass shadow bit in RTC_CR

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_enable_bypass_shadow_register(void)
{
	RTC_CR |= RTC_CR_BYPSHAD;
}

/*---------------------------------------------------------------------------*/
/** @brief Clears the bypass shadow bit in RTC_CR

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_disable_bypass_shadow_register(void)
{
	RTC_CR &= ~RTC_CR_BYPSHAD;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC control register hour format to AM (24h)

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_set_am_format(void)
{
	RTC_CR &= ~RTC_CR_FMT;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC control register hour format to PM (12h)

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_set_pm_format(void)
{
	RTC_CR |= RTC_CR_FMT;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD calendar year value

@details Requires unlocking the RTC write-protection (RTC_WPR)

The year value should only be the abbreviated year tens, meaning if 2021 is
desired pass in only 21.
*/
void rtc_calendar_set_year(uint8_t year)
{
	uint8_t bcd_year = _rtc_dec_to_bcd(year);
	RTC_DR &= ~(RTC_DR_YT_MASK << RTC_DR_YT_SHIFT | RTC_DR_YU_MASK << RTC_DR_YU_SHIFT);
	RTC_DR |= (((bcd_year >> 4) & RTC_DR_YT_MASK) << RTC_DR_YT_SHIFT) |
		((bcd_year & RTC_DR_YU_MASK) << RTC_DR_YU_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD calendar weekday

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_calendar_set_weekday(enum rtc_weekday rtc_dr_wdu)
{
	RTC_DR &= ~(RTC_DR_WDU_MASK << RTC_DR_WDU_SHIFT);
	RTC_DR |= (rtc_dr_wdu << RTC_DR_WDU_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD calendar month value

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_calendar_set_month(uint8_t month)
{
	uint8_t bcd_month = _rtc_dec_to_bcd(month);
	RTC_DR &= ~(RTC_DR_MT_MASK << RTC_DR_MT_SHIFT | RTC_DR_MU_MASK << RTC_DR_MU_SHIFT);
	RTC_DR |= (((bcd_month >> 4) & RTC_DR_MT_MASK) << RTC_DR_MT_SHIFT) |
		((bcd_month & RTC_DR_MU_MASK) << RTC_DR_MU_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD calendar day value

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_calendar_set_day(uint8_t day)
{
	uint8_t bcd_day = _rtc_dec_to_bcd(day);
	RTC_DR &= ~(RTC_DR_DT_MASK << RTC_DR_DT_SHIFT | RTC_DR_DU_MASK << RTC_DR_DU_SHIFT);
	RTC_DR |= (((bcd_day >> 4) & RTC_DR_DT_MASK) << RTC_DR_DT_SHIFT) |
		((bcd_day & RTC_DR_DU_MASK) << RTC_DR_DU_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD calendar value

@details Requires unlocking the RTC write-protection (RTC_WPR)

The year value should only be the abbreviated year tens, meaning if 2021 is
desired pass in only 21.
*/
void rtc_calendar_set_date(uint8_t year, uint8_t month, uint8_t day, enum rtc_weekday rtc_dr_wdu)
{
	rtc_calendar_set_year(year);
	rtc_calendar_set_month(month);
	rtc_calendar_set_weekday(rtc_dr_wdu);
	rtc_calendar_set_day(day);
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD time from arguments in BCD format

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_time_set_time_from_bcd(uint8_t hour_tens, uint8_t hour_units, uint8_t minute_tens, uint8_t minute_units, uint8_t second_tens, uint8_t second_units, bool use_am_notation)
{
	// Instead of rtc_common_l1f024.c, it's not working by performing multiple
	// writing. RTC_TR register shall be written one time to work. Otherwise,
	// only the last writing is effective.

	uint32_t reg = RTC_TR;
	
	reg &= ~(RTC_TR_PM | RTC_TR_HT_MASK << RTC_TR_HT_SHIFT | RTC_TR_HU_MASK << RTC_TR_HU_SHIFT | RTC_TR_MNT_MASK << RTC_TR_MNT_SHIFT | RTC_TR_MNU_MASK << RTC_TR_MNU_SHIFT | RTC_TR_ST_MASK << RTC_TR_ST_SHIFT | RTC_TR_SU_MASK << RTC_TR_SU_SHIFT);

	if (!use_am_notation) {
		reg |= RTC_TR_PM;
	}
	reg |= ((hour_tens    & RTC_TR_HT_MASK)  << RTC_TR_HT_SHIFT) |
	       ((hour_units   & RTC_TR_HU_MASK)  << RTC_TR_HU_SHIFT) |
	       ((minute_tens  & RTC_TR_MNT_MASK) << RTC_TR_MNT_SHIFT) |
	       ((minute_units & RTC_TR_MNU_MASK) << RTC_TR_MNU_SHIFT) |
	       ((second_tens  & RTC_TR_ST_MASK)  << RTC_TR_ST_SHIFT) |
	       ((second_units & RTC_TR_SU_MASK)  << RTC_TR_SU_SHIFT);
	RTC_TR = reg;
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC BCD time

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_time_set_time(uint8_t hour, uint8_t minute, uint8_t second, bool use_am_notation)
{
	// Instead of rtc_common_l1f024.c, it's not working by performing multiple
	// writing. RTC_TR register shall be written one time to work. Otherwise,
	// only the last writing is effective.

	uint8_t bcd_hour = _rtc_dec_to_bcd(hour);
	uint8_t bcd_minute = _rtc_dec_to_bcd(minute);
	uint8_t bcd_second = _rtc_dec_to_bcd(second);
	
	rtc_time_set_time_from_bcd(bcd_hour >> 4, bcd_hour & 15, bcd_minute >> 4, bcd_minute & 15, (bcd_second >> 4), bcd_second & 15, use_am_notation);
}
/**@}*/


/*---------------------------------------------------------------------------*/
/** @brief Gets the RTC BCD time in BCD format

*/
void rtc_time_get_time_in_bcd(uint8_t *hour_tens, uint8_t *hour_units, uint8_t *minute_tens, uint8_t *minute_units, uint8_t *second_tens, uint8_t *second_units) {
	*hour_tens = (RTC_TR >> RTC_TR_HT_SHIFT) & RTC_TR_HT_MASK;
	*hour_units = (RTC_TR >> RTC_TR_HU_SHIFT) & RTC_TR_HU_MASK;
	*minute_tens = (RTC_TR >> RTC_TR_MNT_SHIFT) & RTC_TR_MNT_MASK;
	*minute_units = (RTC_TR >> RTC_TR_MNU_SHIFT) & RTC_TR_MNU_MASK;
	*second_tens = (RTC_TR >> RTC_TR_ST_SHIFT) & RTC_TR_ST_MASK;
	*second_units = (RTC_TR >> RTC_TR_SU_SHIFT) & RTC_TR_SU_MASK;
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Gets the RTC time

*/
void rtc_time_get_time(uint8_t *hour, uint8_t *minute, uint8_t *second) {
	*hour = ((RTC_TR >> RTC_TR_HT_SHIFT) & RTC_TR_HT_MASK) * 10 + ((RTC_TR >> RTC_TR_HU_SHIFT) & RTC_TR_HU_MASK);
	*minute = ((RTC_TR >> RTC_TR_MNT_SHIFT) & RTC_TR_MNT_MASK) * 10 + ((RTC_TR >> RTC_TR_MNU_SHIFT) & RTC_TR_MNU_MASK);
	*second = ((RTC_TR >> RTC_TR_ST_SHIFT) & RTC_TR_ST_MASK) * 10 + ((RTC_TR >> RTC_TR_SU_SHIFT) & RTC_TR_SU_MASK);
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Gets the RTC sub second

*/
uint16_t rtc_time_get_sub_second(void) {
	return (RTC_SSR >> RTC_SSR_SS_SHIFT) & RTC_SSR_SS_MASK;
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Sets the RTC clock calibration

*/
void rtc_set_calib(bool calp, bool calw8, bool calw16, int16_t calm) {
	uint32_t reg = RTC_CALR;
	reg &= ~(RTC_CALR_CALP | RTC_CALR_CALW8 | RTC_CALR_CALW16 | (RTC_CALR_CALM_MASK << RTC_CALR_CALM_SHIFT));
	reg |= calp   ? RTC_CALR_CALP   : 0;
	reg |= calw8  ? RTC_CALR_CALW8  : 0;
	reg |= calw16 ? RTC_CALR_CALW16 : 0;
	reg |= (calm & RTC_CALR_CALM_MASK) << RTC_CALR_CALM_SHIFT;
	RTC_CALR = reg;
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Enables the RTC timestamp

*/
void rtc_enable_timestamp(void) {
	RTC_CR |= RTC_CR_TSE;
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Disables the RTC timestamp

*/
void rtc_disable_timestamp(void) {
	RTC_CR &= ~RTC_CR_TSE;
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Gets RTC timestamp flag

*/
bool rtc_get_timestamp_flag(void) {
	return (RTC_SR & RTC_SR_TSF);
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Clears RTC timestamp flag

*/
void rtc_clear_timestamp_flag(void) {
	RTC_SCR |= RTC_SCR_CTSF;
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Clears RTC timestamp overflow flag

*/
void rtc_clear_timestamp_overflow_flag(void) {
	RTC_SCR |= RTC_SCR_CTSOVF;
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Gets RTC timestamp sub_second field

*/
uint16_t rtc_timestamp_get_sub_second(void) {
	return (RTC_TSSSR & RTC_TSSSR_SS_MASK) >> RTC_TSSSR_SS_SHIFT;
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Enable the RTC alarm whose name is passed by argument

*/
void rtc_enable_alarm(enum rtc_alarm alarm_name) {
	switch (alarm_name) {
		case RTC_ALARM_A:
			RTC_CR |= RTC_CR_ALRAE;
			break;
		case RTC_ALARM_B:
			RTC_CR |= RTC_CR_ALRBE;
			break;
		default:
			cm3_assert_not_reached();
			break;
	}
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Disable the RTC alarm whose name is passed by argument

*/
void rtc_disable_alarm(enum rtc_alarm alarm_name) {
	switch (alarm_name) {
		case RTC_ALARM_A:
			RTC_CR &= ~RTC_CR_ALRAE;
			break;
		case RTC_ALARM_B:
			RTC_CR &= ~RTC_CR_ALRBE;
			break;
		default:
			cm3_assert_not_reached();
			break;
	}
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Return true if the RTC alarm whose name passed by argument is
 * is enabled, or false otherwise

*/
bool rtc_is_alarm_enabled(enum rtc_alarm alarm_name)
{
	switch (alarm_name) {
		case RTC_ALARM_A:
			return (RTC_CR & RTC_CR_ALRAE);
		case RTC_ALARM_B:
			return (RTC_CR & RTC_CR_ALRBE);
		default:
			cm3_assert_not_reached();
			return false;
	}
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Returns if the RTC_ICSR alarm write flag RTC_ICSR_ALRxWF is set

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
bool rtc_alarm_write_flag_is_ready(enum rtc_alarm alarm_name)
{
	switch (alarm_name) {
		case RTC_ALARM_A:
			return (RTC_ICSR & RTC_ICSR_ALRAWF);
		case RTC_ALARM_B:
			return (RTC_ICSR & RTC_ICSR_ALRBWF);
		default:
			cm3_assert_not_reached();
			return 0;
	}
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Waits infinitely for alarm write flag to be set in RTC_ICSR

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_wait_for_alarm_write_ready(enum rtc_alarm alarm_name)
{
	while (!rtc_alarm_write_flag_is_ready(alarm_name));
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Set the day or weekday (according weekday_sel) and the time of the
 * alarm whose name is passed by argument

@details Requires unlocking the RTC write-protection (RTC_WPR)
*/
void rtc_set_alarm_day_and_time(enum rtc_alarm alarm_name, bool day_mask, bool weekday_sel, uint8_t day, enum rtc_weekday rtc_dr_wdu, bool hour_mask, bool use_am_notation, uint8_t hour, bool minute_mask, uint8_t minute, bool second_mask, uint8_t second)
{
	uint32_t reg;
	uint8_t  day_field;
	uint8_t  bcd_hour   = _rtc_dec_to_bcd(hour);
	uint8_t  bcd_minute = _rtc_dec_to_bcd(minute);
	uint8_t  bcd_second = _rtc_dec_to_bcd(second);
	
	if (weekday_sel) {
		day_field = rtc_dr_wdu & RTC_WEEKDAY_MASK;
	} else {
		day_field = _rtc_dec_to_bcd(day);
	}

	reg = (day_mask        ? RTC_ALRMXR_MSK4 : 0) |
	      (weekday_sel     ? RTC_ALRMXR_WDSEL : 0) |
	      (((day_field >> 4) & RTC_ALRMXR_DT_MASK)    << RTC_ALRMXR_DT_SHIFT) |
	      ((day_field        & RTC_ALRMXR_DU_MASK)    << RTC_ALRMXR_DU_SHIFT) |
	      (hour_mask       ? RTC_ALRMXR_MSK3 : 0) |
	      (use_am_notation ? 0 : RTC_ALRMXR_PM) |
	      (((bcd_hour >> 4)  & RTC_ALRMXR_HT_MASK)    << RTC_ALRMXR_HT_SHIFT) |
	      ((bcd_hour         & RTC_ALRMXR_HU_MASK)    << RTC_ALRMXR_HU_SHIFT) |
	      (minute_mask     ? RTC_ALRMXR_MSK2 : 0) |
	      (((bcd_minute >> 4)  & RTC_ALRMXR_MNT_MASK) << RTC_ALRMXR_MNT_SHIFT) |
	      ((bcd_minute         & RTC_ALRMXR_MNU_MASK) << RTC_ALRMXR_MNU_SHIFT) |
	      (second_mask     ? RTC_ALRMXR_MSK1 : 0) |
	      (((bcd_second >> 4)  & RTC_ALRMXR_ST_MASK)  << RTC_ALRMXR_ST_SHIFT) |
	      ((bcd_second         & RTC_ALRMXR_SU_MASK)  << RTC_ALRMXR_SU_SHIFT);
		
	switch (alarm_name) {
		case RTC_ALARM_A:
			RTC_ALRMAR = reg;
			break;
		case RTC_ALARM_B:
			RTC_ALRMBR = reg;
			break;
		default:
			cm3_assert_not_reached();
			break;
	}
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Get the day or weekday (according weekday_sel) and the time of the
 * alarm whose name is passed by argument
)
*/
void rtc_get_alarm_day_and_time(enum rtc_alarm alarm_name, bool *day_mask, bool *weekday_sel, uint8_t *day, enum rtc_weekday *rtc_dr_wdu, bool *hour_mask, bool *use_am_notation, uint8_t *hour, bool *minute_mask, uint8_t *minute, bool *second_mask, uint8_t *second)
{
	uint32_t reg;
	switch (alarm_name) {
		case RTC_ALARM_A:
			reg = RTC_ALRMAR;
			break;
		case RTC_ALARM_B:
			reg = RTC_ALRMBR;
			break;
		default:
			cm3_assert_not_reached();
			break;
	}
	*day_mask        = (reg & RTC_ALRMXR_MSK4)  == 0 ? false : true;
	*weekday_sel     = (reg & RTC_ALRMXR_WDSEL) == 0 ? false : true;
	*hour_mask       = (reg & RTC_ALRMXR_MSK3)  == 0 ? false : true;
	*use_am_notation = (reg & RTC_ALRMXR_PM)    == 0 ? true  : false;
	*minute_mask     = (reg & RTC_ALRMXR_MSK2)  == 0 ? false : true;
	*second_mask     = (reg & RTC_ALRMXR_MSK1)  == 0 ? false : true;
	if (*weekday_sel) {
		*rtc_dr_wdu = (reg >> RTC_ALRMXR_DU_SHIFT) & RTC_WEEKDAY_MASK;
	} else {
		*day = ((reg >> RTC_ALRMXR_DT_SHIFT) & RTC_ALRMXR_DT_MASK) * 10 + ((reg >> RTC_ALRMXR_DU_SHIFT) & RTC_ALRMXR_DU_MASK);
	}
	*hour = ((reg >> RTC_ALRMXR_HT_SHIFT) & RTC_ALRMXR_HT_MASK) * 10 + ((reg >> RTC_ALRMXR_HU_SHIFT) & RTC_ALRMXR_HU_MASK);
	*minute = ((reg >> RTC_ALRMXR_MNT_SHIFT) & RTC_ALRMXR_MNT_MASK) * 10 + ((reg >> RTC_ALRMXR_MNU_SHIFT) & RTC_ALRMXR_MNU_MASK);
	*second = ((reg >> RTC_ALRMXR_ST_SHIFT) & RTC_ALRMXR_ST_MASK) * 10 + ((reg >> RTC_ALRMXR_SU_SHIFT) & RTC_ALRMXR_SU_MASK);
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Enable the interrupt related to the alarm whose name is passed by argument

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_enable_alarm_interrupt(enum rtc_alarm alarm_name)
{
	switch (alarm_name) {
		case RTC_ALARM_A:
			RTC_CR |= RTC_CR_ALRAIE;
			break;
		case RTC_ALARM_B:
			RTC_CR |= RTC_CR_ALRBIE;
			break;
		default:
			cm3_assert_not_reached();
			break;
	}
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Disable the interrupt related to the alarm whose name is passed by
 * argument

@details Requires unlocking backup domain write protection (PWR_CR1_DBP)
*/
void rtc_disable_alarm_interrupt(enum rtc_alarm alarm_name)
{
	switch (alarm_name) {
		case RTC_ALARM_A:
			RTC_CR &= ~RTC_CR_ALRAIE;
			break;
		case RTC_ALARM_B:
			RTC_CR &= ~RTC_CR_ALRBIE;
			break;
		default:
			cm3_assert_not_reached();
			break;
	}
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Return the interrupt flag related to the alarm whose name is passed
 * by argument

@details After clearing the flag, read it until the value 0 is gotten, before leaving the interrupt routine
*/
bool rtc_get_alarm_interrupt_flag(enum rtc_alarm alarm_name)
{
	switch (alarm_name) {
		case RTC_ALARM_A:
			return (RTC_SR & RTC_SR_ALRAF);
		case RTC_ALARM_B:
			return (RTC_SR & RTC_SR_ALRBF);
		default:
			cm3_assert_not_reached();
			return false;
	}
}
/**@}*/

/*---------------------------------------------------------------------------*/
/** @brief Clear the interrupt flag related to the alarm whose name is passed
 * by argument

@details After clearing the flag, read it until the value 0 is gotten, before leaving the interrupt routine
*/
void rtc_clear_alarm_interrupt_flag(enum rtc_alarm alarm_name)
{
	switch (alarm_name) {
		case RTC_ALARM_A:
			RTC_SCR |= RTC_SCR_CALRAF;
			break;
		case RTC_ALARM_B:
			RTC_SCR |= RTC_SCR_CALRBF;
			break;
		default:
			cm3_assert_not_reached();
			break;
	}
}
/**@}*/

