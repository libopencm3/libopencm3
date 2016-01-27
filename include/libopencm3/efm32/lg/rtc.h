/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#ifndef LIBOPENCM3_EFM32_RTC_H
#define LIBOPENCM3_EFM32_RTC_H

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

#define RTC_CTRL		(RTC_BASE + 0x000)
#define RTC_CNT			(RTC_BASE + 0x004)
#define RTC_COMP0		(RTC_BASE + 0x008)
#define RTC_COMP1		(RTC_BASE + 0x00C)
#define RTC_IF			(RTC_BASE + 0x010)
#define RTC_IFS			(RTC_BASE + 0x014)
#define RTC_IFC			(RTC_BASE + 0x018)
#define RTC_IEN			(RTC_BASE + 0x01C)
#define RTC_FREEZE		(RTC_BASE + 0x020)
#define RTC_SYNCBUSY	(RTC_BASE + 0x024)

/* RTC_CTRL */
#define RTC_CTRL_COMP0TOP		(1 << 2)
#define RTC_CTRL_DEBUGRUN		(1 << 1)
#define RTC_CTRL_EN				(1 << 0)

/* RTC_IF */
#define RTC_IF_COMP1			(1 << 2)
#define RTC_IF_COMP0			(1 << 1)
#define RTC_IF_OF				(1 << 0)

/* RTC_IFS */
#define RTC_IFS_COMP1			(1 << 2)
#define RTC_IFS_COMP0			(1 << 1)
#define RTC_IFS_OF				(1 << 0)

/* RTC_IFC */
#define RTC_IFC_COMP1			(1 << 2)
#define RTC_IFC_COMP0			(1 << 1)
#define RTC_IFC_OF				(1 << 0)

/* RTC_IFE */
#define RTC_IFE_COMP1			(1 << 2)
#define RTC_IFE_COMP0			(1 << 1)
#define RTC_IFE_OF				(1 << 0)

/* RTC_FREEZE */
#define RTC_FREEZE_REGFREEZE	(1 << 0)

/* RTC_SYNCBUSY */
#define RTC_SYNCBUSY_COMP1		(1 << 2)
#define RTC_SYNCBUSY_COMP0		(1 << 1)
#define RTC_SYNCBUSY_CTRL		(1 << 0)

#endif

