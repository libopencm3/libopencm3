/** @defgroup exti_defines EXTI Defines
 *
 * @brief <b>Defined Constants and Types for the STM32G4xx External Interrupts
 * </b>
 *
 * @ingroup STM32G4xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2023
 * Benedikt Spranger <b.spranger@linutronix.de>
 *
 * @version 1.0.0
 *
 * @date 19 February 2023
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2023 Benedikt Spranger <b.spranger@linutronix.de>
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

#ifndef LIBOPENCM3_EXTI_H
#define LIBOPENCM3_EXTI_H
/**@{*/

#include <libopencm3/stm32/common/exti_common_all.h>
#include <libopencm3/stm32/common/exti_common_v1.h>

/* --- EXTI registers ------------------------------------------------------ */
#define EXTI_IMR1			EXTI_IMR
#define EXTI_EMR1			EXTI_EMR
#define EXTI_RTSR1			EXTI_RTSR
#define EXTI_FTSR1			EXTI_FTSR
#define EXTI_SWIER1			EXTI_SWIER
#define EXTI_PR1			EXTI_PR

#define EXTI_IMR2			MMIO32(EXTI_BASE + 0x20)
#define EXTI_EMR2			MMIO32(EXTI_BASE + 0x24)
#define EXTI_RTSR2			MMIO32(EXTI_BASE + 0x28)
#define EXTI_FTSR2			MMIO32(EXTI_BASE + 0x2C)
#define EXTI_SWIER2			MMIO32(EXTI_BASE + 0x30)
#define EXTI_PR2			MMIO32(EXTI_BASE + 0x34)

/**@}*/
#endif
