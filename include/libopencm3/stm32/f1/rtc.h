/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LIBOPENCM3_RTC_H
#define LIBOPENCM3_RTC_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/f1/rcc.h>

/* --- RTC registers ------------------------------------------------------- */

/* RTC control register high (RTC_CRH) */
#define RTC_CRH				MMIO32(RTC_BASE + 0x00)

/* RTC control register low (RTC_CRL) */
#define RTC_CRL				MMIO32(RTC_BASE + 0x04)

/* RTC prescaler load register (RTC_PRLH / RTC_PRLL) */
#define RTC_PRLH			MMIO32(RTC_BASE + 0x08)
#define RTC_PRLL			MMIO32(RTC_BASE + 0x0c)

/* RTC prescaler divider register (RTC_DIVH / RTC_DIVL) */
#define RTC_DIVH			MMIO32(RTC_BASE + 0x10)
#define RTC_DIVL			MMIO32(RTC_BASE + 0x14)

/* RTC counter register (RTC_CNTH / RTC_CNTL) */
#define RTC_CNTH			MMIO32(RTC_BASE + 0x18)
#define RTC_CNTL			MMIO32(RTC_BASE + 0x1c)

/* RTC alarm register high (RTC_ALRH / RTC_ALRL) */
#define RTC_ALRH			MMIO32(RTC_BASE + 0x20)
#define RTC_ALRL			MMIO32(RTC_BASE + 0x24)

/* --- RTC_CRH values -------------------------------------------------------*/

/* Note: Bits [15:3] are reserved, and forced to 0 by hardware. */

/* OWIE: Overflow interrupt enable */
#define RTC_CRH_OWIE			(1 << 2)

/* ALRIE: Alarm interrupt enable */
#define RTC_CRH_ALRIE			(1 << 1)

/* SECIE: Second interrupt enable */
#define RTC_CRH_SECIE			(1 << 0)

/* --- RTC_CRL values -------------------------------------------------------*/

/* Note: Bits [15:6] are reserved, and forced to 0 by hardware. */

/* RTOFF: RTC operation OFF */
#define RTC_CRL_RTOFF			(1 << 5)

/* CNF: Configuration flag */
#define RTC_CRL_CNF			(1 << 4)

/* RSF: Registers synchronized flag */
#define RTC_CRL_RSF			(1 << 3)

/* OWF: Overflow flag */
#define RTC_CRL_OWF			(1 << 2)

/* ALRF: Alarm flag */
#define RTC_CRL_ALRF			(1 << 1)

/* SECF: Second flag */
#define RTC_CRL_SECF			(1 << 0)

/* --- RTC_PRLH values ------------------------------------------------------*/

/* Note: Bits [15:4] are reserved, and forced to 0 by hardware. */

/* TODO */

/* --- RTC_PRLL values ------------------------------------------------------*/

/* TODO */

/* --- RTC_DIVH values ------------------------------------------------------*/

/* Bits [15:4] are reserved. */

/* TODO */

/* --- RTC_DIVL values ------------------------------------------------------*/

/* TODO */

/* --- RTC_CNTH values ------------------------------------------------------*/

/* TODO */

/* --- RTC_CNTL values ------------------------------------------------------*/

/* TODO */

/* --- RTC_ALRH values ------------------------------------------------------*/

/* TODO */

/* --- RTC_ALRL values ------------------------------------------------------*/

/* TODO */

/* --- Function prototypes --------------------------------------------------*/

typedef enum {
	RTC_SEC, RTC_ALR, RTC_OW,
} rtcflag_t;

BEGIN_DECLS

void rtc_awake_from_off(osc_t clock_source);
void rtc_enter_config_mode(void);
void rtc_exit_config_mode(void);
void rtc_set_alarm_time(u32 alarm_time);
void rtc_enable_alarm(void);
void rtc_disable_alarm(void);
void rtc_set_prescale_val(u32 prescale_val);
u32 rtc_get_counter_val(void);
u32 rtc_get_prescale_div_val(void);
u32 rtc_get_alarm_val(void);
void rtc_set_counter_val(u32 counter_val);
void rtc_interrupt_enable(rtcflag_t flag_val);
void rtc_interrupt_disable(rtcflag_t flag_val);
void rtc_clear_flag(rtcflag_t flag_val);
u32 rtc_check_flag(rtcflag_t flag_val);
void rtc_awake_from_standby(void);
void rtc_auto_awake(osc_t clock_source, u32 prescale_val);

END_DECLS

#endif
