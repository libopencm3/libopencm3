/** @defgroup dbgmcu_defines DBGMCU Defines

@brief <b>Defined Constants and Types for the STM32F1xx DBGMCU Component</b>

@ingroup STM32F1xx_defines

@version 1.0.0

@date 11 December 2021

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2021 Alexey Ryabov <6006l1k@gmail.com>
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

#ifndef LIBOPENCM3_DBGMCU_H
#define LIBOPENCM3_DBGMCU_H

#include <libopencm3/stm32/common/dbgmcu_common_all.h>

/* --- DBGMCU_CR values ----------------------------------------------------- */

/* Bit 31: Reserved. */

/* Bits [24:22]: Reserved, must be kept cleared. */

/* Bits [4:3]: Reserved. */

/** @addtogroup dbgmcu_cr_values
 * @{*/
/** Debug Sleep mode */
#define DBGMCU_CR_SLEEP			(1 << 0)
/** Debug Stop mode */
#define DBGMCU_CR_STOP			(1 << 1)
/** Debug Standby mode */
#define DBGMCU_CR_STANDBY		(1 << 2)

#define DBGMCU_CR_TRACE_IOEN		(1 << 5)
#define DBGMCU_CR_TRACE_MODE_MASK	0x3
#define DBGMCU_CR_TRACE_MODE_SHIFT	6
#define DBGMCU_CR_TRACE_MODE_ASYNC	(0 << DBGMCU_CR_TRACE_MODE_SHIFT)
#define DBGMCU_CR_TRACE_MODE_SYNC_1	(1 << DBGMCU_CR_TRACE_MODE_SHIFT)
#define DBGMCU_CR_TRACE_MODE_SYNC_2	(2 << DBGMCU_CR_TRACE_MODE_SHIFT)
#define DBGMCU_CR_TRACE_MODE_SYNC_4	(3 << DBGMCU_CR_TRACE_MODE_SHIFT)

/** Debug independent watchdog stopped when core is halted */
#define DBGMCU_CR_IWDG_STOP		(1 << 8)
/** Debug window watchdog stopped when core is halted */
#define DBGMCU_CR_WWDG_STOP		(1 << 9)
/** TIM1 counter stopped when core is halted */
#define DBGMCU_CR_TIM1_STOP		(1 << 10)
/** TIM2 counter stopped when core is halted */
#define DBGMCU_CR_TIM2_STOP		(1 << 11)
/** TIM3 counter stopped when core is halted */
#define DBGMCU_CR_TIM3_STOP		(1 << 12)
/** TIM4 counter stopped when core is halted */
#define DBGMCU_CR_TIM4_STOP		(1 << 13)
/** Debug CAN1 stopped when Core is halted */
#define DBGMCU_CR_CAN1_STOP		(1 << 14)
/** SMBUS timeout mode stopped when Core is halted */
#define DBGMCU_CR_I2C1_SMBUS_TIMEOUT	(1 << 15)
/** SMBUS timeout mode stopped when Core is halted */
#define DBGMCU_CR_I2C2_SMBUS_TIMEOUT	(1 << 16)
/** TIM8 counter stopped when core is halted */
#define DBGMCU_CR_TIM8_STOP		(1 << 17)
/** TIM5 counter stopped when core is halted */
#define DBGMCU_CR_TIM5_STOP		(1 << 18)
/** TIM6 counter stopped when core is halted */
#define DBGMCU_CR_TIM6_STOP		(1 << 19)
/** TIM7 counter stopped when core is halted */
#define DBGMCU_CR_TIM7_STOP		(1 << 20)
/** Debug CAN2 stopped when core is halted */
#define DBGMCU_CR_CAN2_STOP		(1 << 21)
/** TIM12 counter stopped when core is halted */
#define DBG_TIM12_STOP			(1 << 25)
/** TIM13 counter stopped when core is halted */
#define DBG_TIM13_STOP			(1 << 26)
/** TIM14 counter stopped when core is halted */
#define DBG_TIM14_STOP			(1 << 27)
/** TIM9 counter stopped when core is halted */
#define DBG_TIM9_STOP			(1 << 28)
/** TIM10 counter stopped when core is halted */
#define DBG_TIM10_STOP			(1 << 29)
/** TIM11 counter stopped when core is halted */
#define DBG_TIM11_STOP			(1 << 30)
/**@}*/

#endif

/**@}*/
