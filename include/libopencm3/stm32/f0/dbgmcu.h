/** @defgroup dbgmcu_defines DBGMCU Defines

@brief <b>Defined Constants and Types for the STM32F0xx DBGMCU Component</b>

@ingroup STM32F0xx_defines

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

/* --- DBGMCU_CR values ----------------------------------------------------- */

/* Bits [31:3]: Reserved, must be kept cleared. */

/** @addtogroup dbgmcu_cr_values
 * @{*/
/** Debug Stop mode */
#define DBGMCU_CR_STOP			(1 << 1)
/** Debug Standby mode */
#define DBGMCU_CR_STANDBY		(1 << 2)
/**@}*/

/* --- DBGMCU_APB1_FZ values ------------------------------------------------ */

/* Bits [31:26]: Reserved, must be kept at reset value. */

/* Bits [22:24]: Reserved, must be kept at reset value. */

/* Bits [20:13]: Reserved, must be kept at reset value. */

/* Bit 9: Reserved, must be kept at reset value. */

/* Bits [7:6]: Reserved, must be kept at reset value. */

/* Bits [3:2]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb1_fz_values Debug MCU APB1 freeze register (DBGMCU_APB1_FZ) values
 * @{*/
/** CAN stopped when core is halted */
#define DBGMCU_APB1_FZ_CAN_STOP		(1 << 25)
/** SMBUS timeout mode stopped when core is halted */
#define DBGMCU_APB1_FZ_I2C1_SMBUS_TIMEOUT	(1 << 21)
/** Debug independent watchdog stopped when core is halted */
#define DBGMCU_APB1_FZ_IWDG_STOP	(1 << 12)
/** Debug window watchdog stopped when core is halted */
#define DBGMCU_APB1_FZ_WWDG_STOP	(1 << 11)
/** Debug RTC stopped when core is halted */
#define DBGMCU_APB1_FZ_RTC_STOP		(1 << 10)
/** TIM14 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM14_STOP	(1 << 8)
/** TIM7 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM7_STOP	(1 << 5)
/** TIM6 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM6_STOP	(1 << 4)
/** TIM3 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM3_STOP	(1 << 1)
/** TIM2 counter stopped when core is halted */
#define DBGMCU_APB1_FZ_TIM2_STOP	(1 << 0)
/**@}*/

/* --- DBGMCU_APB2_FZ values ------------------------------------------------ */

/* Bits [31:19]: Reserved, must be kept at reset value. */

/* Bits [15:12]: Reserved, must be kept at reset value. */

/* Bits [0:10]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb2_fz_values Debug MCU APB2 freeze register (DBGMCU_APB2_FZ) values
 * @{*/
/** TIM17 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM17_STOP	(1 << 18)
/** TIM16 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM16_STOP	(1 << 17)
/** TIM15 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM15_STOP	(1 << 16)
/** TIM1 counter stopped when core is halted */
#define DBGMCU_APB2_FZ_TIM1_STOP	(1 << 11)
/**@}*/

#endif

/**@}*/
