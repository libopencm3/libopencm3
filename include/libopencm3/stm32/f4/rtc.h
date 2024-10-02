/** @defgroup rtc_defines RTC Defines

@brief <b>Defined Constants and Types for the STM32F4xx RTC</b>

@ingroup STM32F4xx_defines

@version 1.0.0

@date 5 December 2012

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

#include <libopencm3/stm32/common/rtc_common_l1f024.h>

BEGIN_DECLS

struct time_s
{
  uint8_t  hour;     /* hour : 0-23 */
  uint8_t  minute;   /* minute : 0-59 */
  uint8_t  second;   /* second : 0-59 */
  uint16_t year;     /* year (no limit of definition) */
  uint8_t  month;    /* month : January = 1 ... December = 12 */
  uint8_t  day;      /* day of the month : 1-31 */
  uint8_t  week_day; /* day of the week : Monday = 1 ... Sunday = 7 */
};

void rtc_enable_wakeup_timer(void);
void rtc_disable_wakeup_timer(void);
void rtc_enable_wakeup_timer_interrupt(void);
void rtc_disable_wakeup_timer_interrupt(void);
void rtc_calendar_config(void);
void rtc_calendar_set(struct time_s time);
struct time_s rtc_calendar_get(void);

END_DECLS

#endif
