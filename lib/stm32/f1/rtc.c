/** @defgroup rtc_file RTC
 *
 * @ingroup STM32F1xx
 *
 * @brief <b>libopencm3 STM32F1xx RTC</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2010 Uwe Hermann <uwe@hermann-uwe.de>
 * @author @htmlonly &copy; @endhtmlonly 2010 Lord James <lordjames@y7mail.com>
 *
 * @version 1.0.0
 *
 * @date 4 March 2013
 *
 * The Real Time Clock peripheral consists of a set of 16 bit control, status,
 * prescaler, counter and alarm registers. Before the latter three can be
 * written the RTC must be placed in configuration mode by a call to
 * @ref rtc_enter_config_mode(). The functions below handle this implictly.
 *
 * The RTC is completely reset by performing a Backup Domain reset. Note
 * that this can affect unrelated user data contained in the Backup Domain
 * registers. Other forms of reset will not affect the RTC registers as they
 * are contained within the backup domain.
 *
 * The RTC clock source to be used is selected by calling
 * @ref rcc_set_rtc_clock_source().
 *
 * The LSE clock source normally comes from a 32.768kHz external crystal
 * This clock is in the backup domain and so continues to run when only the
 * V_BAT supply is present. A prescaler value of 7FFF will give a 1 second
 * count quantum.
 *
 * The LSI clock source is a low accuracy internal clock of about 40kHz
 * frequency, and the HSE clock source is the external high speed clock
 * divided by 128.
 *
 * Initial configuration of the RTC consists of:
 *
 * @li perform a Backup Domain reset if appropriate;
 * @li select the clock to be used;
 * @li set the prescaler, counter and configuration values;
 * @li enable the RTC.
 *
 * @note reading the RTC registers may result in a corrupted value being
 * returned in certain cases. Refer to the STM32F1xx Reference Manual.
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2010 Lord James <lordjames@y7mail.com>
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


#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/rtc.h>
#include <libopencm3/stm32/pwr.h>

/*---------------------------------------------------------------------------*/
/** @brief RTC Set Operational from the Off state.

Power up the backup domain clocks, enable write access to the backup domain,
select the clock source and enable the RTC.

After calling this function all counter and control settings must be
established.

@note The Backup Domain is reset by this function and will therefore result in
the loss of any unrelated user data stored there.

@param[in] clock_source ::rcc_osc. RTC clock source. Only HSE/128, LSE and LSI.
*/

void rtc_awake_from_off(enum rcc_osc clock_source)
{
	uint32_t reg32;

	/* Enable power and backup interface clocks. */
	RCC_APB1ENR |= (RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN);

	/* Enable access to the backup registers and the RTC. */
	PWR_CR |= PWR_CR_DBP;

	/*
	 * Reset the backup domain, clears everything RTC related.
	 * If not wanted use the rtc_awake_from_standby() function.
	 */
	rcc_backupdomain_reset();

	switch (clock_source) {
	case LSE:
		/* Turn the LSE on and wait while it stabilises. */
		RCC_BDCR |= RCC_BDCR_LSEON;
		while ((reg32 = (RCC_BDCR & RCC_BDCR_LSERDY)) == 0);

		/* Choose LSE as the RTC clock source. */
		RCC_BDCR &= ~((1 << 8) | (1 << 9));
		RCC_BDCR |= (1 << 8);
		break;
	case LSI:
		/* Turn the LSI on and wait while it stabilises. */
		RCC_CSR |= RCC_CSR_LSION;
		while ((reg32 = (RCC_CSR & RCC_CSR_LSIRDY)) == 0);

		/* Choose LSI as the RTC clock source. */
		RCC_BDCR &= ~((1 << 8) | (1 << 9));
		RCC_BDCR |= (1 << 9);
		break;
	case HSE:
		/* Turn the HSE on and wait while it stabilises. */
		RCC_CR |= RCC_CR_HSEON;
		while ((reg32 = (RCC_CR & RCC_CR_HSERDY)) == 0);

		/* Choose HSE as the RTC clock source. */
		RCC_BDCR &= ~((1 << 8) | (1 << 9));
		RCC_BDCR |= (1 << 9) | (1 << 8);
		break;
	case PLL:
	case PLL2:
	case PLL3:
	case HSI:
		/* Unusable clock source, here to prevent warnings. */
		/* Turn off clock sources to RTC. */
		RCC_BDCR &= ~((1 << 8) | (1 << 9));
		break;
	}

	/* Enable the RTC. */
	RCC_BDCR |= RCC_BDCR_RTCEN;

	/* Wait for the RSF bit in RTC_CRL to be set by hardware. */
	RTC_CRL &= ~RTC_CRL_RSF;
	while ((reg32 = (RTC_CRL & RTC_CRL_RSF)) == 0);

	/* Wait for the last write operation to finish. */
	/* TODO: Necessary? */
	while ((reg32 = (RTC_CRL & RTC_CRL_RTOFF)) == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Enter Configuration Mode.

Prime the RTC for configuration changes by giving access to the prescaler,
and counter and alarm registers.
*/

void rtc_enter_config_mode(void)
{
	uint32_t reg32;

	/* Wait until the RTOFF bit is 1 (no RTC register writes ongoing). */
	while ((reg32 = (RTC_CRL & RTC_CRL_RTOFF)) == 0);

	/* Enter configuration mode. */
	RTC_CRL |= RTC_CRL_CNF;
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Leave Configuration Mode.

Revert the RTC to operational state.
*/

void rtc_exit_config_mode(void)
{
	uint32_t reg32;

	/* Exit configuration mode. */
	RTC_CRL &= ~RTC_CRL_CNF;

	/* Wait until the RTOFF bit is 1 (our RTC register write finished). */
	while ((reg32 = (RTC_CRL & RTC_CRL_RTOFF)) == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Set the Alarm Time.

@param[in] alarm_time uint32_t. time at which the alarm event is triggered.
*/

void rtc_set_alarm_time(uint32_t alarm_time)
{
	rtc_enter_config_mode();
	RTC_ALRL = (alarm_time & 0x0000ffff);
	RTC_ALRH = (alarm_time & 0xffff0000) >> 16;
	rtc_exit_config_mode();
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Enable the Alarm.

*/

void rtc_enable_alarm(void)
{
	rtc_enter_config_mode();
	RTC_CRH |= RTC_CRH_ALRIE;
	rtc_exit_config_mode();
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Disable the Alarm.

*/

void rtc_disable_alarm(void)
{
	rtc_enter_config_mode();
	RTC_CRH &= ~RTC_CRH_ALRIE;
	rtc_exit_config_mode();
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Set the prescaler Value

@param[in] prescale_val uint32_t. 20 bit prescale divider.
*/

void rtc_set_prescale_val(uint32_t prescale_val)
{
	rtc_enter_config_mode();
	RTC_PRLL = prescale_val & 0x0000ffff;         /* PRL[15:0] */
	RTC_PRLH = (prescale_val & 0x000f0000) >> 16; /* PRL[19:16] */
	rtc_exit_config_mode();
}

/*---------------------------------------------------------------------------*/
/** @brief RTC return the Counter Value

@returns uint32_t: the 32 bit counter value.
*/

uint32_t rtc_get_counter_val(void)
{
	return (RTC_CNTH << 16) | RTC_CNTL;
}

/*---------------------------------------------------------------------------*/
/** @brief RTC return the prescaler Value

@returns uint32_t: the 20 bit prescale divider.
*/

uint32_t rtc_get_prescale_div_val(void)
{
	return (RTC_DIVH << 16) | RTC_DIVL;
}

/*---------------------------------------------------------------------------*/
/** @brief RTC return the Alarm Value

@returns uint32_t: the 32 bit alarm value.
*/

uint32_t rtc_get_alarm_val(void)
{
	return (RTC_ALRH << 16) | RTC_ALRL;
}

/*---------------------------------------------------------------------------*/
/** @brief RTC set the Counter

@param[in] uint32_t counter_val: 32 bit time setting for the counter.
*/

void rtc_set_counter_val(uint32_t counter_val)
{
	rtc_enter_config_mode();
	RTC_CNTH = (counter_val & 0xffff0000) >> 16; /* CNT[31:16] */
	RTC_CNTL = counter_val & 0x0000ffff;         /* CNT[15:0] */
	rtc_exit_config_mode();
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Enable Interrupt

@param[in] flag_val ::rtcflag_t: The flag to enable.
*/

void rtc_interrupt_enable(rtcflag_t flag_val)
{
	rtc_enter_config_mode();

	/* Set the correct interrupt enable. */
	switch (flag_val) {
	case RTC_SEC:
		RTC_CRH |= RTC_CRH_SECIE;
		break;
	case RTC_ALR:
		RTC_CRH |= RTC_CRH_ALRIE;
		break;
	case RTC_OW:
		RTC_CRH |= RTC_CRH_OWIE;
		break;
	}

	rtc_exit_config_mode();
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Disable Interrupt

@param[in] flag_val ::rtcflag_t: The flag to disable.
*/

void rtc_interrupt_disable(rtcflag_t flag_val)
{
	rtc_enter_config_mode();

	/* Disable the correct interrupt enable. */
	switch (flag_val) {
	case RTC_SEC:
		RTC_CRH &= ~RTC_CRH_SECIE;
		break;
	case RTC_ALR:
		RTC_CRH &= ~RTC_CRH_ALRIE;
		break;
	case RTC_OW:
		RTC_CRH &= ~RTC_CRH_OWIE;
		break;
	}

	rtc_exit_config_mode();
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Clear an Interrupt Flag

@param[in] flag_val ::rtcflag_t: The flag to clear.
*/

void rtc_clear_flag(rtcflag_t flag_val)
{
	/* Configuration mode not needed. */

	/* Clear the correct flag. */
	switch (flag_val) {
	case RTC_SEC:
		RTC_CRL &= ~RTC_CRL_SECF;
		break;
	case RTC_ALR:
		RTC_CRL &= ~RTC_CRL_ALRF;
		break;
	case RTC_OW:
		RTC_CRL &= ~RTC_CRL_OWF;
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Return a Flag Setting

@param[in] flag_val ::rtcflag_t: The flag to check.
@returns uint32_t: a nonzero value if the flag is set, zero otherwise.
*/

uint32_t rtc_check_flag(rtcflag_t flag_val)
{
	uint32_t reg32;

	/* Read correct flag. */
	switch (flag_val) {
	case RTC_SEC:
		reg32 = RTC_CRL & RTC_CRL_SECF;
		break;
	case RTC_ALR:
		reg32 = RTC_CRL & RTC_CRL_ALRF;
		break;
	case RTC_OW:
		reg32 = RTC_CRL & RTC_CRL_OWF;
		break;
	default:
		reg32 = 0;
		break;
	}

	return reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Start RTC after Standby Mode.

Enable the backup domain clocks, enable write access to the backup
domain and the RTC, and synchronise the RTC register access.
*/

void rtc_awake_from_standby(void)
{
	uint32_t reg32;

	/* Enable power and backup interface clocks. */
	RCC_APB1ENR |= (RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN);

	/* Enable access to the backup registers and the RTC. */
	PWR_CR |= PWR_CR_DBP;

	/* Wait for the RSF bit in RTC_CRL to be set by hardware. */
	RTC_CRL &= ~RTC_CRL_RSF;
	while ((reg32 = (RTC_CRL & RTC_CRL_RSF)) == 0);

	/* Wait for the last write operation to finish. */
	/* TODO: Necessary? */
	while ((reg32 = (RTC_CRL & RTC_CRL_RTOFF)) == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RTC Configuration on Wakeup

Enable the backup domain clocks and write access to the backup domain.
If the RTC has not been enabled, set the clock source and prescaler value.
The parameters are not used if the RTC has already been enabled.

@param[in] clock_source ::rcc_osc. RTC clock source. Only HSE/128, LSE and LSI.
@param[in] prescale_val uint32_t. 20 bit prescale divider.
*/

void rtc_auto_awake(enum rcc_osc clock_source, uint32_t prescale_val)
{
	uint32_t reg32;

	/* Enable power and backup interface clocks. */
	RCC_APB1ENR |= (RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN);

	/* Enable access to the backup registers and the RTC. */
	/* TODO: Not sure if this is necessary to just read the flag. */
	PWR_CR |= PWR_CR_DBP;

	reg32 = RCC_BDCR & RCC_BDCR_RTCEN;

	if (reg32 != 0) {
		rtc_awake_from_standby();
	} else {
		rtc_awake_from_off(clock_source);
		rtc_set_prescale_val(prescale_val);
	}
}
/**@}*/

