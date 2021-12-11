/** @defgroup dbgmcu_defines DBGMCU Defines

@brief <b>libopencm3 Defined Constants and Types for the STM32F1xx DBGMCU
Generator </b>

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
#define DBGMCU_CR_SLEEP			0x00000001
/** Debug Stop mode */
#define DBGMCU_CR_STOP			0x00000002
/** Debug Standby mode */
#define DBGMCU_CR_STANDBY		0x00000004

/** Trace pin assignment control */
#define DBGMCU_CR_TRACE_IOEN		0x00000020
#define DBGMCU_CR_TRACE_MODE_MASK	0x000000C0
#define DBGMCU_CR_TRACE_MODE_ASYNC	0x00000000
#define DBGMCU_CR_TRACE_MODE_SYNC_1	0x00000040
#define DBGMCU_CR_TRACE_MODE_SYNC_2	0x00000080
#define DBGMCU_CR_TRACE_MODE_SYNC_4	0x000000C0

/** Debug independent watchdog stopped when core is halted */
#define DBGMCU_CR_IWDG_STOP		0x00000100
/** Debug window watchdog stopped when core is halted */
#define DBGMCU_CR_WWDG_STOP		0x00000200
/** TIM1 counter stopped when core is halted */
#define DBGMCU_CR_TIM1_STOP		0x00000400
/** TIM2 counter stopped when core is halted */
#define DBGMCU_CR_TIM2_STOP		0x00000800
/** TIM3 counter stopped when core is halted */
#define DBGMCU_CR_TIM3_STOP		0x00001000
/** TIM4 counter stopped when core is halted */
#define DBGMCU_CR_TIM4_STOP		0x00002000
/** Debug CAN1 stopped when Core is halted */
#define DBGMCU_CR_CAN1_STOP		0x00004000
/** SMBUS timeout mode stopped when Core is halted */
#define DBGMCU_CR_I2C1_SMBUS_TIMEOUT	0x00008000
/** SMBUS timeout mode stopped when Core is halted */
#define DBGMCU_CR_I2C2_SMBUS_TIMEOUT	0x00010000
/** TIM8 counter stopped when core is halted */
#define DBGMCU_CR_TIM8_STOP		0x00020000
/** TIM5 counter stopped when core is halted */
#define DBGMCU_CR_TIM5_STOP		0x00040000
/** TIM6 counter stopped when core is halted */
#define DBGMCU_CR_TIM6_STOP		0x00080000
/** TIM7 counter stopped when core is halted */
#define DBGMCU_CR_TIM7_STOP		0x00100000
/** Debug CAN2 stopped when core is halted */
#define DBGMCU_CR_CAN2_STOP		0x00200000
/** TIM12 counter stopped when core is halted */
#define DBG_TIM12_STOP			0x02000000
/** TIM13 counter stopped when core is halted */
#define DBG_TIM13_STOP			0x04000000
/** TIM14 counter stopped when core is halted */
#define DBG_TIM14_STOP			0x08000000
/** TIM9 counter stopped when core is halted */
#define DBG_TIM9_STOP			0x10000000
/** TIM10 counter stopped when core is halted */
#define DBG_TIM10_STOP			0x20000000
/** TIM11 counter stopped when core is halted */
#define DBG_TIM11_STOP			0x40000000
/**@}*/

#endif

/**@}*/
