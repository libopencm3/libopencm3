/*
 * This file is part of the unicore-mx project.
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

/* Only two RTCs on this device. */
#define RTC0			RTC0_BASE
#define RTC1			RTC1_BASE

/* Tasks */
#define RTC_TASK_START(rtc)			MMIO32((rtc) + 0x000)
#define RTC0_TASK_START			RTC_TASK_START(RTC0)
#define RTC1_TASK_START			RTC_TASK_START(RTC1)

#define RTC_TASK_STOP(rtc)			MMIO32((rtc) + 0x004)
#define RTC0_TASK_STOP			RTC_TASK_STOP(RTC0)
#define RTC1_TASK_STOP			RTC_TASK_STOP(RTC1)

#define RTC_TASK_CLEAR(rtc)			MMIO32((rtc) + 0x008)
#define RTC0_TASK_CLEAR			RTC_TASK_CLEAR(RTC0)
#define RTC1_TASK_CLEAR			RTC_TASK_CLEAR(RTC1)

#define RTC_TASK_TRIGOVRFLW(rtc)			MMIO32((rtc) + 0x00C)
#define RTC0_TASK_TRIGOVRFLW			RTC_TASK_TRIGOVRFLW(RTC0)
#define RTC1_TASK_TRIGOVRFLW			RTC_TASK_TRIGOVRFLW(RTC1)

/* Events */
#define RTC_EVENT_TICK(rtc)			MMIO32((rtc) + 0x100)
#define RTC0_EVENT_TICK			RTC_EVENT_TICK(RTC0)
#define RTC1_EVENT_TICK			RTC_EVENT_TICK(RTC1)

#define RTC_EVENT_OVRFLW(rtc)			MMIO32((rtc) + 0x104)
#define RTC0_EVENT_OVRFLW			RTC_EVENT_OVRFLW(RTC0)
#define RTC1_EVENT_OVRFLW			RTC_EVENT_OVRFLW(RTC1)

#define RTC_EVENT_COMPARE(rtc, i)			MMIO32((rtc) + 0x140 + 0x4 * (i))
#define RTC0_EVENT_COMPARE(i)			RTC_EVENT_COMPARE(RTC0, (i))
#define RTC0_EVENT_COMPARE0			RTC_EVENT_COMPARE(RTC0, 0)
#define RTC0_EVENT_COMPARE1			RTC_EVENT_COMPARE(RTC0, 1)
#define RTC0_EVENT_COMPARE2			RTC_EVENT_COMPARE(RTC0, 2)
#define RTC0_EVENT_COMPARE3			RTC_EVENT_COMPARE(RTC0, 3)

#define RTC1_EVENT_COMPARE(i)			RTC_EVENT_COMPARE(RTC1, (i))
#define RTC1_EVENT_COMPARE1			RTC_EVENT_COMPARE(RTC1, 1)
#define RTC1_EVENT_COMPARE1			RTC_EVENT_COMPARE(RTC1, 1)
#define RTC1_EVENT_COMPARE2			RTC_EVENT_COMPARE(RTC1, 2)
#define RTC1_EVENT_COMPARE3			RTC_EVENT_COMPARE(RTC1, 3)

/* Registers */
#define RTC_INTEN(rtc)			periph_inten(rtc)
#define RTC0_INTEN			RTC_INTEN(RTC0)
#define RTC1_INTEN			RTC_INTEN(RTC1)

#define RTC_INTENSET(rtc)			periph_intenset(rtc)
#define RTC0_INTENSET			RTC_INTENSET(RTC0)
#define RTC1_INTENSET			RTC_INTENSET(RTC1)

#define RTC_INTENCLR(rtc)			periph_intenclr(rtc)
#define RTC0_INTENCLR			RTC_INTENCLR(RTC0)
#define RTC1_INTENCLR			RTC_INTENCLR(RTC1)

#define RTC_EVTEN(rtc)			MMIO32((rtc) + 0x340)
#define RTC0_EVTEN			RTC_EVTEN(RTC0)
#define RTC1_EVTEN			RTC_EVTEN(RTC1)

#define RTC_EVTENSET(rtc)			MMIO32((rtc) + 0x344)
#define RTC0_EVTENSET			RTC_EVTENSET(RTC0)
#define RTC1_EVTENSET			RTC_EVTENSET(RTC1)

#define RTC_EVTENCLR(rtc)			MMIO32((rtc) + 0x348)
#define RTC0_EVTENCLR			RTC_EVTENCLR(RTC0)
#define RTC1_EVTENCLR			RTC_EVTENCLR(RTC1)

#define RTC_COUNTER(rtc)			MMIO32((rtc) + 0x504)
#define RTC0_COUNTER			RTC_COUNTER(RTC0)
#define RTC1_COUNTER			RTC_COUNTER(RTC1)

#define RTC_PRESCALER(rtc)			MMIO32((rtc) + 0x508)
#define RTC0_PRESCALER			RTC_PRESCALER(RTC0)
#define RTC1_PRESCALER			RTC_PRESCALER(RTC1)

#define RTC_CC(rtc, i)		MMIO32((rtc) + 0x540 + 0x4 * (i))
#define RTC_CC0(rtc)			MMIO32((rtc) + 0x540)
#define RTC0_CC0			RTC_CC0(RTC0)
#define RTC1_CC0			RTC_CC0(RTC1)

#define RTC_CC1(rtc)			MMIO32((rtc) + 0x544)
#define RTC0_CC1			RTC_CC1(RTC0)
#define RTC1_CC1			RTC_CC1(RTC1)

#define RTC_CC2(rtc)			MMIO32((rtc) + 0x548)
#define RTC0_CC2			RTC_CC2(RTC0)
#define RTC1_CC2			RTC_CC2(RTC1)

#define RTC_CC3(rtc)			MMIO32((rtc) + 0x54C)
#define RTC0_CC3			RTC_CC3(RTC0)
#define RTC1_CC3			RTC_CC3(RTC1)

/* Register Contents */
#define RTC_INTEN_TICK			(1 << 0)
#define RTC_INTEN_OVRFLW			(1 << 1)
#define RTC_INTEN_COMPARE(n)			(1 << (16 + (n)))
#define RTC_INTEN_COMPARE0			(1 << 16)
#define RTC_INTEN_COMPARE1			(1 << 17)
#define RTC_INTEN_COMPARE2			(1 << 18)
#define RTC_INTEN_COMPARE3			(1 << 19)

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

