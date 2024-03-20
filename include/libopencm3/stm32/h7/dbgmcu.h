/** @defgroup dbgmcu_defines DBGMCU Defines

@brief <b>Defined Constants and Types for the STM32H7xx DBGMCU Component</b>

@ingroup STM32H7xx_defines

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
/** DBGMCU APB3 peripheral freeze register */
#define DBGMCU_APB3FZ1			MMIO32(DBGMCU_BASE + 0x34)
/** DBGMCU APB1L peripheral freeze register */
#define DBGMCU_APB1LFZ1			MMIO32(DBGMCU_BASE + 0x3C)
/** DBGMCU APB2 peripheral freeze register */
#define DBGMCU_APB2FZ1			MMIO32(DBGMCU_BASE + 0x4C)
/** DBGMCU APB4 peripheral freeze register */
#define DBGMCU_APB4FZ1			MMIO32(DBGMCU_BASE + 0x54)
/**@}*/

/* --- DBGMCU_CR values ----------------------------------------------------- */

/* Bits [31:29]: Reserved, must be kept at reset value. */

/* Bits [27:23]: Reserved, must be kept at reset value. */

/* Bits [19:3]: Reserved, must be kept at reset value. */

/** @addtogroup dbgmcu_cr_values
 * @{*/
/** External trigger output enable */
#define DBGMCU_CR_TRGOEN		(1 << 28)
/** D3 debug clock enable */
#define DBGMCU_CR_D3DBGCKEN		(1 << 22)
/** D1 debug clock enable */
#define DBGMCU_CR_D1DBGCKEN		(1 << 21)
/** Trace port clock enable */
#define DBGMCU_CR_TRACECLKEN		(1 << 20)
/** D1 domain debug in Standby mode enable */
#define DBGMCU_CR_DBGSTBY_D1		(1 << 2)
/** D1 domain debug in Stop mode enable */
#define DBGMCU_CR_DBGSTOP_D1		(1 << 1)
/** D1 domain debug in Sleep mode enable */
#define DBGMCU_CR_DBGSLEEP_D1		(1 << 1)
/**@}*/

/* --- DBGMCU_APB3FZ1 values ------------------------------------------------ */

/* Bits [31:7]: Reserved, must be kept at reset value. */

/* Bits [5:0]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb3fz1_values DBGMCU APB3 peripheral freeze register (DBGMCU_APB3FZ1) values
 * @{*/
/** WWDG1 stop in debug */
#define DBGMCU_APB3FZ1_WWDG1		(1 << 6)
/**@}*/

/* --- DBGMCU_APB1LFZ1 values ----------------------------------------------- */

/* Bits [31:24]: Reserved, must be kept at reset value. */

/* Bits [20:11]: Reserved, must be kept at reset value. */

/* Bit 10: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb1lfz1_values DBGMCU APB1L peripheral freeze register (DBGMCU_APB1LFZ1) values
 * @{*/
/** I2C3 SMBUS timeout stop in debug */
#define DBGMCU_APB1LFZ1_I2C3		(1 << 23)
/** I2C2 SMBUS timeout stop in debug */
#define DBGMCU_APB1LFZ1_I2C2		(1 << 22)
/** I2C1 SMBUS timeout stop in debug */
#define DBGMCU_APB1LFZ1_I2C1		(1 << 21)
/** LPTIM1 stop in debug */
#define DBGMCU_APB1LFZ1_LPTIM1		(1 << 9)
/** TIM14 stop in debug */
#define DBGMCU_APB1LFZ1_TIM14		(1 << 8)
/** TIM13 stop in debug */
#define DBGMCU_APB1LFZ1_TIM13		(1 << 7)
/** TIM12 stop in debug */
#define DBGMCU_APB1LFZ1_TIM12		(1 << 6)
/** TIM7 stop in debug */
#define DBGMCU_APB1LFZ1_TIM7		(1 << 5)
/** TIM6 stop in debug */
#define DBGMCU_APB1LFZ1_TIM6		(1 << 4)
/** TIM5 stop in debug */
#define DBGMCU_APB1LFZ1_TIM5		(1 << 3)
/** TIM4 stop in debug */
#define DBGMCU_APB1LFZ1_TIM4		(1 << 2)
/** TIM3 stop in debug */
#define DBGMCU_APB1LFZ1_TIM3		(1 << 1)
/** TIM2 stop in debug */
#define DBGMCU_APB1LFZ1_TIM2		(1 << 0)
/**@}*/

/* --- DBGMCU_APB2FZ1 values ----------------------------------------------- */

/* Bits [31:30]: Reserved, must be kept at reset value. */

/* Bits [28:18]: Reserved, must be kept at reset value. */

/* Bits [15:2]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb2fz1_values DBGMCU APB2 peripheral freeze register (DBGMCU_APB2FZ1) values
 * @{*/
/** HRTIM stop in debug */
#define DBGMCU_APB2FZ1_HRTIM		(1 << 29)
/** TIM17 stop in debug */
#define DBGMCU_APB2FZ1_TIM17		(1 << 18)
/** TIM16 stop in debug */
#define DBGMCU_APB2FZ1_TIM16		(1 << 17)
/** TIM15 stop in debug */
#define DBGMCU_APB2FZ1_TIM15		(1 << 16)
/** TIM8 stop in debug */
#define DBGMCU_APB2FZ1_TIM8		(1 << 1)
/** TIM1 stop in debug */
#define DBGMCU_APB2FZ1_TIM1		(1 << 0)
/**@}*/

/* --- DBGMCU_APB4FZ1 values ----------------------------------------------- */

/* Bits [31:19]: Reserved, must be kept at reset value. */

/* Bit 17: Reserved, must be kept at reset value. */

/* Bits [15:13]: Reserved, must be kept at reset value. */

/* Bit 8: Reserved, must be kept at reset value. */

/* Bits [6:0]: Reserved, must be kept at reset value. */

/** @defgroup dbgmcu_apb4fz1_values DBGMCU APB4 peripheral freeze register (DBGMCU_APB4FZ1) values
 * @{*/
/** Independent watchdog for D1 stop in debug */
#define DBGMCU_APB4FZ1_IIWDG1		(1 << 18)
/** RTC stop in debug */
#define DBGMCU_APB4FZ1_RTC		(1 << 16)
/** LPTIM5 stop in debug */
#define DBGMCU_APB4FZ1_LPTIM5		(1 << 12)
/** LPTIM4 stop in debug */
#define DBGMCU_APB4FZ1_LPTIM4		(1 << 11)
/** LPTIM2 stop in debug */
#define DBGMCU_APB4FZ1_LPTIM3		(1 << 10)
/** LPTIM2 stop in debug */
#define DBGMCU_APB4FZ1_LPTIM2		(1 << 9)
/** I2C4 SMBUS timeout stop in debug */
#define DBGMCU_APB4FZ1_I2C4		(1 << 7)
/**@}*/

#endif

/**@}*/
