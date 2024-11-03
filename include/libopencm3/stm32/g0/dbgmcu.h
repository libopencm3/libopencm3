/** @defgroup dbgmcu_defines DBGMCU Defines

@brief <b>Defined Constants and Types for the STM32G0xx DBGMCU Component</b>

@ingroup STM32G0xx_defines

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

/** Debug MCU APB freeze register 1
 * @note Only 32-bit access are supported.
 */
#define DBGMCU_APB_FZ1			MMIO32(DBGMCU_BASE + 0x08)

/** Debug MCU APB freeze register 2
 * @note Only 32-bit access are supported.
 */
#define DBGMCU_APB_FZ2			MMIO32(DBGMCU_BASE + 0x0C)
/**@}*/

/* --- DBGMCU_CR values ----------------------------------------------------- */

/* Bits [31:3]: Reserved, must be kept at reset value. */

/** @addtogroup dbgmcu_cr_values
 * @{*/
/** Debug Stop mode */
#define DBGMCU_CR_STOP			(1 << 1)
/** Debug Standby mode */
#define DBGMCU_CR_STANDBY		(1 << 2)
/**@}*/

/* --- DBGMCU_APB_FZ1 values ------------------------------------------------ */

/* Bits [29:23]: Reserved, must be kept at reset value. */

/* Bits [20:13]: Reserved, must be kept at reset value. */

/* Bits [9:6]: Reserved, must be kept at reset value. */

/* Bits 3: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb_fz1_values Debug MCU APB freeze register 1 (DBGMCU_APB_FZ1) values
 * @{*/
/** Clocking of LPTIMER1 counter when the core is halted */
#define DBGMCU_APB_FZ1_LPTIMER_STOP	(1 << 31)
/** Clocking of LPTIMER2 counter when the core is halted */
#define DBGMCU_APB_FZ1_LPTIM2_STOP	(1 << 30)
/** SMBUS timeout when core is halted */
#define DBGMCU_APB_FZ1_I2C2_SMBUS_TIMEOUT	(1 << 22)
/** SMBUS timeout when core is halted */
#define DBGMCU_APB_FZ1_I2C1_SMBUS_TIMEOUT	(1 << 21)
/** Clocking of IWDG counter when the core is halted */
#define DBGMCU_APB_FZ1_IWDG_STOP	(1 << 12)
/** Clocking of WWDG counter when the core is halted */
#define DBGMCU_APB_FZ1_WWDG_STOP	(1 << 11)
/** Clocking of RTC counter when the core is halted */
#define DBGMCU_APB_FZ1_RTC_STOP		(1 << 10)
/** Clocking of TIM7 counter when the core is halted */
#define DBGMCU_APB_FZ1_TIM7_STOP	(1 << 5)
/** Clocking of TIM6 counter when the core is halted */
#define DBGMCU_APB_FZ1_TIM6_STOP	(1 << 4)
/** Clocking of TIM4 counter when the core is halted */
#define DBGMCU_APB_FZ1_TIM4_STOP	(1 << 2)
/** Clocking of TIM3 counter when the core is halted */
#define DBGMCU_APB_FZ1_TIM3_STOP	(1 << 1)
/** Clocking of TIM2 counter when the core is halted */
#define DBGMCU_APB_FZ1_TIM2_STOP	(1 << 0)
/**@}*/

/* --- DBGMCU_APB_FZ2 values ------------------------------------------------ */

/* Bits [31:19]: Reserved, must be kept at reset value. */

/* Bits [14:12]: Reserved, must be kept at reset value. */

/* Bits [10:0]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb_fz2_values Debug MCU APB freeze register 2 (DBGMCU_APB_FZ2) values
 * @{*/
/** Clocking of TIM17 counter when the core is halted */
#define DBGMCU_APB_FZ2_TIM17_STOP	(1 << 18)
/** Clocking of TIM16 counter when the core is halted */
#define DBGMCU_APB_FZ2_TIM16_STOP	(1 << 17)
/** Clocking of TIM15 counter when the core is halted */
#define DBGMCU_APB_FZ2_TIM15_STOP	(1 << 16)
/** Clocking of TIM14 counter when the core is halted */
#define DBGMCU_APB_FZ2_TIM14_STOP	(1 << 15)
/** Clocking of TIM1 counter when the core is halted */
#define DBGMCU_APB_FZ2_TIM1_STOP	(1 << 11)
/**@}*/

#endif

/**@}*/
