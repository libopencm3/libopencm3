/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopenstm32/rcc.h>
#include <libopenstm32/rtc.h>

void rtc_init(void)
{
	/* Enable power and backup interface clocks. */
	RCC_APB1ENR |= (PWREN | BKPEN);

	/* Enable access to the backup registers and the RTC. */
	/* TODO: PWR component not yet implemented in libopenstm32. */
	/* PWR_CR |= PWR_CR_DBP; */

	/* TODO: Wait for the RSF bit in RTC_CRL to be set by hardware? */
}

void rtc_enter_config_mode(void)
{
	u32 reg32;

	/* Wait until the RTOFF bit is 1 (no RTC register writes ongoing). */
	while ((reg32 = (RTC_CRL & RTC_CRL_RTOFF)) == 0);

	/* Enter configuration mode. */
	RTC_CRL |= RTC_CRL_CNF;
}

void rtc_exit_config_mode(void)
{
	u32 reg32;

	/* Exit configuration mode. */
	RTC_CRL &= ~RTC_CRL_CNF;

	/* Wait until the RTOFF bit is 1 (our RTC register write finished). */
	while ((reg32 = (RTC_CRL & RTC_CRL_RTOFF)) == 0);
}

void rtc_set_alarm_time(u32 alarm_time)
{
	rtc_enter_config_mode();
	RTC_ALRL = (alarm_time & 0x0000ffff);
	RTC_ALRH = (alarm_time & 0xffff0000) >> 16;
	rtc_exit_config_mode();
}

void rtc_enable_alarm(void)
{
	rtc_enter_config_mode();
	RTC_CRH |= RTC_CRH_ALRIE;
	rtc_exit_config_mode();
}

void rtc_disable_alarm(void)
{
	rtc_enter_config_mode();
	RTC_CRH &= ~RTC_CRH_ALRIE;
	rtc_exit_config_mode();
}

