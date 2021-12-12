/** @defgroup dbgmcu_defines DBGMCU Defines

@brief <b>Defined Constants and Types for the STM32F3xx DBGMCU Component</b>

@ingroup STM32F3xx_defines

@version 1.0.0

@date 12 December 2021

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

/* Bits 31: Reserved, must be kept at reset value. */

/* Bits [24:23]: Reserved, must be kept at reset value. */

/* Bits [20:13]: Reserved, must be kept at reset value. */

/* Bits [9:6]: Reserved, must be kept at reset value. */

/* Bit 3: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb1_fz_values Debug MCU APB1 freeze register (DBGMCU_APB1_FZ) values
 * @{*/

/** SMBUS timeout mode stopped when core is halted */
#define DBGMCU_APB1_FZ_I2C3_SMBUS_TIMEOUT	(1 << 30)
/** Debug CAN stopped when Core is halted */
#define DBGMCU_APB1_FZ_CAN_STOP		(1 << 25)
/** SMBUS timeout mode stopped when core is halted
 * @note Available on STM32F303xB/C and STM32F358xC devices only
 */
#define DBGMCU_APB1_FZ_I2C2_SMBUS_TIMEOUT	(1 << 22)
/** SMBUS timeout mode stopped when core is halted */
#define DBGMCU_APB1_FZ_I2C1_SMBUS_TIMEOUT	(1 << 21)
/** Debug independent watchdog stopped when core is halted */
#define DBGMCU_APB1_FZ_IWDG_STOP	(1 << 12)
/** Debug Window Watchdog stopped when core is halted */
#define DBGMCU_APB1_FZ_WWDG_STOP	(1 << 11)
/** Debug RTC stopped when Core is halted */
#define DBGMCU_APB1_FZ_RTC_STOP		(1 << 10)
/** TIM7 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM7_STOP	(1 << 5)
/** TIM6 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM6_STOP	(1 << 4)
/** TIM4 counter stopped when core is halted
 * @note Available on STM32F303xB/C and STM32F358xC devices only
 */
#define DBGMCU_APB1_FZ_TIM4_STOP	(1 << 2)
/** TIM3 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM3_STOP	(1 << 1)
/** TIM2 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM2_STOP	(1 << 0)
/**@}*/

/* --- DBGMCU_APB2_FZ values ------------------------------------------------ */

/* Bits [31:6]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb2_fz_values Debug MCU APB2 freeze register (DBGMCU_APB2_FZ) values
 * @{*/
/** TIM20 counter stopped when core is halted
 * @note Available only in STM32F303xD/E and STM32F398xE
 */
#define DBGMCU_APB2_FZ_TIM20_STOP	(1 << 5)
/** TIM17 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM17_STOP	(1 << 4)
/** TIM16 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM16_STOP	(1 << 3)
/** TIM15 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM15_STOP	(1 << 2)
/** TIM8 counter stopped when core is halted
 * @note Only in STM32F303xB/C/D/E, STM32F358xC and STM32F398xE devices
 */
#define DBGMCU_APB2_FZ_TIM8_STOP	(1 << 1)
/** TIM1 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM1_STOP	(1 << 0)
/**@}*/

#endif

/**@}*/
