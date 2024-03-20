/** @defgroup dbgmcu_defines DBGMCU Defines

@brief <b>Defined Constants and Types for the STM32L1xx DBGMCU Component</b>

@ingroup STM32L1xx_defines

@version 1.0.0

@date 11 December 2021

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
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

/* --- DBGMCU registers ----------------------------------------------------- */

/**@addtogroup dbgmcu_registers
 @{*/

/** Debug MCU APB1 freeze register
 * @note Only 32-bit access are supported.
 */
#define DBGMCU_APB1_FZ			MMIO32(DBGMCU_BASE + 0x08)

/** Debug MCU APB2 freeze register
 * @note Only 32-bit access are supported.
 */
#define DBGMCU_APB2_FZ			MMIO32(DBGMCU_BASE + 0x0C)
/**@}*/

/* --- DBGMCU_CR values ----------------------------------------------------- */

/* Bits [31:8]: Reserved, must be kept at reset value. */

/* Bits [4:3]: Reserved, must be kept at reset value. */

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
/**@}*/

/* --- DBGMCU_APB1_FZ values ------------------------------------------------ */

/* Bits [31:23]: Reserved, must be kept at reset value. */

/* Bits [20:13]: Reserved, must be kept at reset value. */

/* Bits [9:6]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb1_fz_values Debug MCU APB1 freeze register (DBGMCU_APB1_FZ) values
 * @{*/
/** SMBUS timeout mode stopped when core is halted */
#define DBGMCU_APB1_FZ_I2C2_SMBUS_TIMEOUT	(1 << 22)
/** SMBUS timeout mode stopped when core is halted */
#define DBGMCU_APB1_FZ_I2C1_SMBUS_TIMEOUT	(1 << 21)
/** Debug independent watchdog stopped when core is halted */
#define DBGMCU_APB1_FZ_IWDG_STOP	(1 << 12)
/** Debug window watchdog stopped when core is halted */
#define DBGMCU_APB1_FZ_WWDG_STOP	(1 << 11)
/** Debug RTC stopped when core is halted
 * @note This bit is available only in Cat.2, Cat.3, Cat.4, Cat.5 and Cat.6
 *       devices.
 */
#define DBGMCU_APB1_FZ_RTC_STOP		(1 << 10)
/** TIM7 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM7_STOP	(1 << 5)
/** TIM6 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM6_STOP	(1 << 4)
/** TIM5 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM5_STOP	(1 << 3)
/** TIM4 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM4_STOP	(1 << 2)
/** TIM3 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM3_STOP	(1 << 1)
/** TIM2 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM2_STOP	(1 << 0)
/**@}*/

/* --- DBGMCU_APB2_FZ values ------------------------------------------------ */

/* Bits [31:5]: Reserved, must be kept at reset value. */

/* Bits [1:0]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb2_fz_values Debug MCU APB2 freeze register (DBGMCU_APB2_FZ) values
 * @{*/
/** TIM11 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM11_STOP	(1 << 4)
/** TIM10 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM10_STOP	(1 << 3)
/** TIM9 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM9_STOP	(1 << 2)
/**@}*/

#endif

/**@}*/
