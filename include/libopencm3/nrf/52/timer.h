/** @defgroup timer_defines TIMER Defines
 *
 * @brief <b>Defined Constants and Types for the NRF52xx Timer</b>
 *
 * @ingroup NRF52xx_defines
 *
 * @version 1.0.0
 *
 * @date Nov 2021
 *
 *LGPL License Terms @ref lgpl_license
 */
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
#include <libopencm3/nrf/common/timer.h>

/**@{*/
/* Timer/Counter */
/** @addtogroup timer_block TIMER instances
 * @{
 */
#define TIMER4			TIMER4_BASE
#define TIMER3			TIMER3_BASE

/* Tasks */

#define TIMER4_TASK_START			TIMER_TASK_START(TIMER4)
#define TIMER3_TASK_START			TIMER_TASK_START(TIMER3)

#define TIMER4_TASK_STOP			TIMER_TASK_STOP(TIMER4)
#define TIMER3_TASK_STOP			TIMER_TASK_STOP(TIMER3)

#define TIMER4_TASK_COUNT			TIMER_TASK_COUNT(TIMER4)
#define TIMER3_TASK_COUNT			TIMER_TASK_COUNT(TIMER3)

#define TIMER4_TASK_CLEAR			TIMER_TASK_CLEAR(TIMER4)
#define TIMER3_TASK_CLEAR			TIMER_TASK_CLEAR(TIMER3)

#define TIMER4_TASK_SHUTDOWN			TIMER_TASK_SHUTDOWN(TIMER4)
#define TIMER3_TASK_SHUTDOWN			TIMER_TASK_SHUTDOWN(TIMER3)

#define TIMER4_TASK_CAPTURE(C)			TIMER_TASK_CAPTURE(TIMER4, C)
#define TIMER3_TASK_CAPTURE(C)			TIMER_TASK_CAPTURE(TIMER3, C)

#define TIMER4_TASK_CAPTURE0			TIMER_TASK_CAPTURE(TIMER4, 0)
#define TIMER4_TASK_CAPTURE1			TIMER_TASK_CAPTURE(TIMER4, 1)
#define TIMER4_TASK_CAPTURE2			TIMER_TASK_CAPTURE(TIMER4, 2)
#define TIMER4_TASK_CAPTURE3			TIMER_TASK_CAPTURE(TIMER4, 3)

#define TIMER3_TASK_CAPTURE0			TIMER_TASK_CAPTURE(TIMER3, 0)
#define TIMER3_TASK_CAPTURE1			TIMER_TASK_CAPTURE(TIMER3, 1)
#define TIMER3_TASK_CAPTURE2			TIMER_TASK_CAPTURE(TIMER3, 2)
#define TIMER3_TASK_CAPTURE3			TIMER_TASK_CAPTURE(TIMER3, 3)

/* Events */

#define TIMER4_EVENT_COMPARE(C)			TIMER_EVENT_COMPARE(TIMER4, C)
#define TIMER3_EVENT_COMPARE(C)			TIMER_EVENT_COMPARE(TIMER3, C)

#define TIMER4_EVENT_COMPARE0			TIMER_EVENT_COMPARE(TIMER4, 0)
#define TIMER4_EVENT_COMPARE1			TIMER_EVENT_COMPARE(TIMER4, 1)
#define TIMER4_EVENT_COMPARE2			TIMER_EVENT_COMPARE(TIMER4, 2)
#define TIMER4_EVENT_COMPARE3			TIMER_EVENT_COMPARE(TIMER4, 3)

#define TIMER3_EVENT_COMPARE0			TIMER_EVENT_COMPARE(TIMER3, 0)
#define TIMER3_EVENT_COMPARE1			TIMER_EVENT_COMPARE(TIMER3, 1)
#define TIMER3_EVENT_COMPARE2			TIMER_EVENT_COMPARE(TIMER3, 2)
#define TIMER3_EVENT_COMPARE3			TIMER_EVENT_COMPARE(TIMER3, 3)

/* Registers */

#define TIMER4_SHORTS			TIMER_SHORTS(TIMER4)
#define TIMER3_SHORTS			TIMER_SHORTS(TIMER3)

#define TIMER4_INTENSET			TIMER_INTENSET(TIMER4)
#define TIMER3_INTENSET			TIMER_INTENSET(TIMER3)

#define TIMER4_INTENCLR			TIMER_INTENCLR(TIMER4)
#define TIMER3_INTENCLR			TIMER_INTENCLR(TIMER3)

#define TIMER4_MODE			TIMER_MODE(TIMER4)
#define TIMER3_MODE			TIMER_MODE(TIMER3)

#define TIMER4_BITMODE			TIMER_BITMODE(TIMER4)
#define TIMER3_BITMODE			TIMER_BITMODE(TIMER3)

#define TIMER4_PRESCALER			TIMER_PRESCALER(TIMER4)
#define TIMER3_PRESCALER			TIMER_PRESCALER(TIMER3)

#define TIMER4_CC(C)			TIMER_CC(TIMER4, C)
#define TIMER3_CC(C)			TIMER_CC(TIMER3, C)

#define TIMER4_CC0			TIMER_CC(TIMER4, 0)
#define TIMER4_CC1			TIMER_CC(TIMER4, 1)
#define TIMER4_CC2			TIMER_CC(TIMER4, 2)
#define TIMER4_CC3			TIMER_CC(TIMER4, 3)

#define TIMER3_CC0			TIMER_CC(TIMER3, 0)
#define TIMER3_CC1			TIMER_CC(TIMER3, 1)
#define TIMER3_CC2			TIMER_CC(TIMER3, 2)
#define TIMER3_CC3			TIMER_CC(TIMER3, 3)

/**@}*/

