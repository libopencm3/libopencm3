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
/** @brief Get BCD date.
This returns the current date stored as a BCD value from the RTC.
*/

uint32_t rtc_get_bcd_date(void)
{
    return RTC_DR;
}

/*---------------------------------------------------------------------------*/
/** @brief Get BCD time.
This returns the current time stored as a BCD value from the RTC.
*/

uint32_t rtc_get_bcd_time(void)
{
    return RTC_TR;
}


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

	RTC_ICSR &= ~(RTC_ICSR_RSF);

	while (!(RTC_ICSR & RTC_ICSR_RSF));

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
	RTC_CR &= ~(RTC_CR_WUCLKSEL_MASK << RTC_CR_WUCLKSEL_SHIFT);
	RTC_CR |= (rtc_cr_wucksel << RTC_CR_WUCLKSEL_SHIFT);
	RTC_CR |= RTC_CR_WUTE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Alarm A interrupt

@details This function is enable Alarm A rtc_alarm_isr()
*/
void rtc_enable_alarm_a_interrupt(void)
{
        RTC_CR |= RTC_CR_ALRAIE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Alarm B interrupt

@details This function is enable Alarm B rtc_alarm_isr()
*/
void rtc_enable_alarm_b_interrupt(void)
{
        RTC_CR |= RTC_CR_ALRBIE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable timestamp interrupt

@details This function is enable wakeup timestamp rtc_tamp_css_isr()
*/
void rtc_enable_timestamp_interrupt(void)
{
        RTC_CR |= RTC_CR_TSIE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable wakeup interrupt

@details This function is enable wakeup interrupt rtc_wkup_isr()
*/
void rtc_enable_wakeup_interrupt(void)
{
        RTC_CR |= RTC_CR_WUTIE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Alarm A

@details This function is enable Alarm A
*/
void rtc_enable_alarm_a(void)
{
        RTC_CR |= RTC_CR_ALRAE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable Alarm B

@details This function is enable Alarm B
*/
void rtc_enable_alarm_b(void)
{
        RTC_CR |= RTC_CR_ALRBE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable timestamp timer

@details This function is enable timestamp interrupt rtc_wkup_isr()
*/
void rtc_enable_timestamp(void)
{
        RTC_CR |= RTC_CR_TSE;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable wakeup timer

@details This function is enable wakeup interrupt rtc_wkup_isr()
*/
void rtc_enable_wakeup_timer(void)
{
        RTC_CR |= RTC_CR_WUTE;
}

/**@}*/
