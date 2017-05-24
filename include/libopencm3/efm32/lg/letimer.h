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

#ifndef LIBOPENCM3_EFM32_LETIMER_H
#define LIBOPENCM3_EFM32_LETIMER_H

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/cm3/common.h>

#define LETIMER_CTRL(base)		((base) + 0x000)
#define LETIMER_CMD(base)		((base) + 0x004)
#define LETIMER_STATUS(base)		((base) + 0x008)
#define LETIMER_CNT(base)		((base) + 0x00C)
#define LETIMER_COMP0(base)		((base) + 0x010)
#define LETIMER_COMP1(base)		((base) + 0x014)
#define LETIMER_REP0(base)		((base) + 0x018)
#define LETIMER_REP1(base)		((base) + 0x01C)
#define LETIMER_IF(base)		((base) + 0x020)
#define LETIMER_IFS(base)		((base) + 0x024)
#define LETIMER_IFC(base)		((base) + 0x028)
#define LETIMER_IEN(base)		((base) + 0x02C)
#define LETIMER_FREEZE(base)		((base) + 0x030)
#define LETIMER_SYNCBUSY(base)		((base) + 0x034)
#define LETIMER_ROUTE(base)		((base) + 0x040)

/* LETIMER_CTRL */
#define LETIMER_CTRL_DEBUG		(1 << 12)
#define LETIMER_CTRL_RTCC1TEN		(1 << 11)
#define LETIMER_CTRL_RTCC0TEN		(1 << 10)
#define LETIMER_CTRL_COMP0TOP		(1 << 9)
#define LETIMER_CTRL_BUFTOP		(1 << 8)
#define LETIMER_CTRL_OPOL1		(1 << 7)
#define LETIMER_CTRL_OPOL0		(1 << 6)

#define LETIMER_CTRL_UFOA1_SHIFT	(4)
#define LETIMER_CTRL_UFOA1_MASK		(0x3 << LETIMER_CTRL_UFOA1_SHIFT)
#define LETIMER_CTRL_UFOA1(v)		\
	(((v) << LETIMER_CTRL_UFOA1_SHIFT) & LETIMER_CTRL_UFOA1_MASK)
#define LETIMER_CTRL_UFOA1_NONE		0
#define LETIMER_CTRL_UFOA1_TOGGLE	1
#define LETIMER_CTRL_UFOA1_PULSE	2
#define LETIMER_CTRL_UFOA1_PWM		3

#define LETIMER_CTRL_UFOA0_SHIFT	(2)
#define LETIMER_CTRL_UFOA0_MASK		(0x3 << LETIMER_CTRL_UFOA0_SHIFT)
#define LETIMER_CTRL_UFOA0(v)		\
	(((v) << LETIMER_CTRL_UFOA0_SHIFT) & LETIMER_CTRL_UFOA0_MASK)
#define LETIMER_CTRL_UFOA0_NONE		0
#define LETIMER_CTRL_UFOA0_TOGGLE	1
#define LETIMER_CTRL_UFOA0_PULSE	2
#define LETIMER_CTRL_UFOA0_PWM		3

#define LETIMER_CTRL_REPMODE_SHIFT	(2)
#define LETIMER_CTRL_REPMODE_MASK	(0x3 << LETIMER_CTRL_REPMODE_SHIFT)
#define LETIMER_CTRL_REPMODE(v)		\
	(((v) << LETIMER_CTRL_REPMODE_SHIFT) & LETIMER_CTRL_REPMODE_MASK)
#define LETIMER_CTRL_REPMODE_FREE	0
#define LETIMER_CTRL_REPMODE_ONESHOT	1
#define LETIMER_CTRL_REPMODE_BUFFERED	2
#define LETIMER_CTRL_REPMODE_DOUBLE	3
#define LETIMER_CTRL_REPMODE_ONE_SHOT	LETIMER_CTRL_REPMODE_ONESHOT

/* LETIMER_CMD */
#define LETIMER_CMD_CTO1		(1 << 4)
#define LETIMER_CMD_CTO0		(1 << 3)
#define LETIMER_CMD_CLEAR		(1 << 2)
#define LETIMER_CMD_STOP		(1 << 1)
#define LETIMER_CMD_START		(1 << 0)

/* LETIMER_STATUS */
#define LETIMER_STATUS_RUNNING		(1 << 0)

/* LETIMER_IF */
#define LETIMER_IF_REP1			(1 << 4)
#define LETIMER_IF_REP0			(1 << 3)
#define LETIMER_IF_UF			(1 << 2)
#define LETIMER_IF_COMP1		(1 << 1)
#define LETIMER_IF_COMP0		(1 << 0)

/* LETIMER_IFS */
#define LETIMER_IFS_REP1		(1 << 4)
#define LETIMER_IFS_REP0		(1 << 3)
#define LETIMER_IFS_UF			(1 << 2)
#define LETIMER_IFS_COMP1		(1 << 1)
#define LETIMER_IFS_COMP0		(1 << 0)

/* LETIMER_IFC */
#define LETIMER_IFC_REP1		(1 << 4)
#define LETIMER_IFC_REP0		(1 << 3)
#define LETIMER_IFC_UF			(1 << 2)
#define LETIMER_IFC_COMP1		(1 << 1)
#define LETIMER_IFC_COMP0		(1 << 0)

/* LETIMER_IFE */
#define LETIMER_IFE_REP1		(1 << 4)
#define LETIMER_IFE_REP0		(1 << 3)
#define LETIMER_IFE_UF			(1 << 2)
#define LETIMER_IFE_COMP1		(1 << 1)
#define LETIMER_IFE_COMP0		(1 << 0)

/* LETIMER_FREEZE */
#define LETIMER_FREEZE_REGFREEZE	(1 << 0)

/* LETIMER_SYNCBUSY */
#define LETIMER_SYNCBUSY_REP1		(1 << 5)
#define LETIMER_SYNCBUSY_REP0		(1 << 4)
#define LETIMER_SYNCBUSY_COMP1		(1 << 3)
#define LETIMER_SYNCBUSY_COMP0		(1 << 2)
#define LETIMER_SYNCBUSY_CMD		(1 << 1)
#define LETIMER_SYNCBUSY_CTRL		(1 << 0)

/* LETIMER_ROUTE */
#define LETIMER_ROUTE_LOCATION_SHIFT	(8)
#define LETIMER_ROUTE_LOCATION_MASK	(0x7 << LETIMER_ROUTE_LOCATION_SHIFT)
#define LETIMER_ROUTE_LOCATION(v)	\
	(((v) << LETIMER_ROUTE_LOCATION_SHIFT) & LETIMER_ROUTE_LOCATION_MASK)
#define LETIMER_ROUTE_LOCATION_LOCx(x)	LETIMER_ROUTE_LOCATION(x)
#define LETIMER_ROUTE_LOCATION_LOC0	0
#define LETIMER_ROUTE_LOCATION_LOC1	1
#define LETIMER_ROUTE_LOCATION_LOC2	2
#define LETIMER_ROUTE_LOCATION_LOC3	3
#define LETIMER_ROUTE_LOCATION_LOC4	4
#define LETIMER_ROUTE_LOCATION_LOC5	5
#define LETIMER_ROUTE_LOCATION_LOC6	6
#define LETIMER_ROUTE_LOCATION_LOC7	7

#define LETIMER_ROUTE_OUT1PEN		(1 << 1)
#define LETIMER_ROUTE_OUT0PEN		(1 << 0)

/* LETIMER0 */
#define LETIMER0			LETIMER0_BASE
#define LETIMER0_CTRL			LETIMER_CTRL(LETIMER0)
#define LETIMER0_CMD			LETIMER_CMD(LETIMER0)
#define LETIMER0_STATUS			LETIMER_STATUS(LETIMER0)
#define LETIMER0_CNT			LETIMER_CNT(LETIMER0)
#define LETIMER0_COMP0			LETIMER_COMP0(LETIMER0)
#define LETIMER0_COMP1			LETIMER_COMP1(LETIMER0)
#define LETIMER0_REP0			LETIMER_REP0(LETIMER0)
#define LETIMER0_REP1			LETIMER_REP1(LETIMER0)
#define LETIMER0_IF			LETIMER_IF(LETIMER0)
#define LETIMER0_IFS			LETIMER_IFS(LETIMER0)
#define LETIMER0_IFC			LETIMER_IFC(LETIMER0)
#define LETIMER0_IEN			LETIMER_IEN(LETIMER0)
#define LETIMER0_FREEZE			LETIMER_FREEZE(LETIMER0)
#define LETIMER0_SYNCBUSY		LETIMER_SYNCBUSY(LETIMER0)
#define LETIMER0_ROUTE			LETIMER_ROUTE(LETIMER0)

#endif

