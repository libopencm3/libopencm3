/** @defgroup dbgmcu_defines DBGMCU Defines

@brief <b>Defined Constants and Types for the STM32L4xx DBGMCU Component</b>

@ingroup STM32L4xx_defines

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

/** Debug MCU APB1 freeze register 1
 * @note Only 32-bit access are supported.
 */
#define DBGMCU_APB1FZR1			MMIO32(DBGMCU_BASE + 0x08)

/** Debug MCU APB1 freeze register 2
 * @note Only 32-bit access are supported.
 */
#define DBGMCU_APB1FZR2			MMIO32(DBGMCU_BASE + 0x0C)

/** Debug MCU APB2 freeze register
 * @note Only 32-bit access are supported.
 */
#define DBGMCU_APB2FZR			MMIO32(DBGMCU_BASE + 0x10)
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

/* --- DBGMCU_APB1FZR1 values ----------------------------------------------- */

/* Bits [30:27]: Reserved, must be kept at reset value. */

/* Bits [20:13]: Reserved, must be kept at reset value. */

/* Bits [9:6]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb1fzr1_values Debug MCU APB1 freeze register 1 (DBGMCU_APB1FZR1) values
 * @{*/
/** LPTIM1 counter stopped when core is halted */
#define DBGMCU_APB1FZR1_LPTIM1_STOP	(1 << 31)
/** bxCAN2 stopped when core is halted
 * @note this is bit is reserved on STM32L47x/L48x devices, must be kept at
 *       reset value
 */
#define DBGMCU_APB1FZR1_CAN2_STOP	(1 << 26)
/** bxCAN1 stopped when core is halted */
#define DBGMCU_APB1FZR1_CAN1_STOP	(1 << 25)
/** I2C3 SMBUS timeout counter stopped when core is halted */
#define DBGMCU_APB1FZR1_I2C3_STOP	(1 << 23)
/** I2C2 SMBUS timeout counter stopped when core is halted */
#define DBGMCU_APB1FZR1_I2C2_STOP	(1 << 22)
/** I2C1 SMBUS timeout counter stopped when core is halted */
#define DBGMCU_APB1FZR1_I2C1_STOP	(1 << 21)
/** Debug independent watchdog stopped when core is halted */
#define DBGMCU_APB1FZR1_IWDG_STOP	(1 << 12)
/** Debug window watchdog stopped when core is halted */
#define DBGMCU_APB1FZR1_WWDG_STOP	(1 << 11)
/** Debug RTC stopped when core is halted */
#define DBGMCU_APB1FZR1_RTC_STOP	(1 << 10)
/** TIM7 counter stopped when core is halted */
#define DBGMCU_APB1FZR1_TIM7_STOP	(1 << 5)
/** TIM6 counter stopped when core is halted */
#define DBGMCU_APB1FZR1_TIM6_STOP	(1 << 4)
/** TIM5 counter stopped when core is halted */
#define DBGMCU_APB1FZR1_TIM5_STOP	(1 << 3)
/** TIM4 counter stopped when core is halted */
#define DBGMCU_APB1FZR1_TIM4_STOP	(1 << 2)
/** TIM3 counter stopped when core is halted */
#define DBGMCU_APB1FZR1_TIM3_STOP	(1 << 1)
/** TIM2 counter stopped when core is halted */
#define DBGMCU_APB1FZR1_TIM2_STOP	(1 << 0)
/**@}*/

/* --- DBGMCU_APB1FZR2 values ----------------------------------------------- */

/* Bits [31:6]: Reserved, must be kept at reset value. */

/* Bits [4:2]: Reserved, must be kept at reset value. */

/* Bit 0: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb1fzr2_values Debug MCU APB1 freeze register 2 (DBGMCU_APB1FZR2) values
 * @{*/
/** LPTIM2 counter stopped when core is halted */
#define DBGMCU_APB1FZR2_LPTIM2_STOP	(1 << 5)
/** I2C4 SMBUS timeout counter stopped when core is halted
 * @note this bit is reserved on STM32L47x/L48x devices, must be kept at reset
 *       value
 */
#define DBGMCU_APB1FZR2_I2C4_STOP	(1 << 1)
/**@}*/

/* --- DBGMCU_APB2FZR values ------------------------------------------------ */

/* Bits [31:19]: Reserved, must be kept at reset value. */

/* Bits [15:14]: Reserved, must be kept at reset value. */

/* Bit 12: Reserved, must be kept at reset value. */

/* Bits [10:0]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb2fzr_values Debug MCU APB2 freeze register (DBGMCU_APB2FZR) values
 * @{*/
/** TIM17 counter stopped when core is halted */
#define DBGMCU_APB2FZR_TIM17_STOP	(1 << 18)
/** TIM16 counter stopped when core is halted */
#define DBGMCU_APB2FZR_TIM16_STOP	(1 << 17)
/** TIM15 counter stopped when core is halted */
#define DBGMCU_APB2FZR_TIM15_STOP	(1 << 16)
/** TIM18 counter stopped when core is halted */
#define DBGMCU_APB2FZR_TIM8_STOP	(1 << 13)
/** TIM1 counter stopped when core is halted */
#define DBGMCU_APB2FZR_TIM1_STOP	(1 << 11)
/**@}*/

#endif

/**@}*/
