/** @addtogroup rtc_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Maxim Sloyko <maxims@google.com>
 * @author @htmlonly &copy; @endhtmlonly 2021 Eduard Drusa <ventyl86 at netkosice dot sk>
 *
 **/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017-2018 Unicore MX project<dev(at)lists(dot)unicore-mx(dot)org>
 * Copyright (C) 2021 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
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

#pragma once

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
#include <libopencm3/nrf/periph.h>
/**@{*/

/* Only two RTCs on this device. */
/** @addtogroup rtc_block RTC instances
 * @{
 */
#define RTC0			RTC0_BASE
#define RTC1			RTC1_BASE

/**@}*/

/* Tasks */
#define RTC_TASK_START(rtc)			MMIO32((rtc) + 0x000)
#define RTC_TASK_STOP(rtc)			MMIO32((rtc) + 0x004)
#define RTC_TASK_CLEAR(rtc)			MMIO32((rtc) + 0x008)
#define RTC_TASK_TRIGOVRFLW(rtc)			MMIO32((rtc) + 0x00C)

/* Events */
#define RTC_EVENT_TICK(rtc)			MMIO32((rtc) + 0x100)
#define RTC_EVENT_OVRFLW(rtc)			MMIO32((rtc) + 0x104)
#define RTC_EVENT_COMPARE(rtc, i)			MMIO32((rtc) + 0x140 + 0x4 * (i))

/* Registers */
#define RTC_INTEN(rtc)				_PERIPH_INTEN(rtc)
#define RTC_INTENSET(rtc)			_PERIPH_INTENSET(rtc)
#define RTC_INTENCLR(rtc)			_PERIPH_INTENCLR(rtc)
#define RTC_EVTEN(rtc)				MMIO32((rtc) + 0x340)
#define RTC_EVTENSET(rtc)			MMIO32((rtc) + 0x344)
#define RTC_EVTENCLR(rtc)			MMIO32((rtc) + 0x348)
#define RTC_COUNTER(rtc)			MMIO32((rtc) + 0x504)
#define RTC_PRESCALER(rtc)			MMIO32((rtc) + 0x508)
#define RTC_CC(rtc, i)		MMIO32((rtc) + 0x540 + 0x4 * (i))

/* Register Contents */
#define RTC_INTEN_TICK			(1 << 0)
#define RTC_INTEN_OVRFLW			(1 << 1)
#define RTC_INTEN_COMPARE(n)			(1 << (16 + (n)))
/**@}*/

BEGIN_DECLS

void rtc_set_prescaler(uint32_t rtc, uint16_t presc);
uint32_t rtc_get_counter(uint32_t rtc);
void rtc_enable_events(uint32_t rtc, uint32_t mask);
void rtc_disable_events(uint32_t rtc, uint32_t mask);
void rtc_start(uint32_t rtc);
void rtc_stop(uint32_t rtc);
void rtc_clear(uint32_t rtc);
void rtc_set_compare(uint32_t rtc, uint8_t cmp, uint32_t value);

END_DECLS


