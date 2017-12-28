/** @defgroup exti_defines EXTI Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L4xx External Interrupts
 * </b>
 *
 * @ingroup STM32L4xx_defines
 *
 * @version 1.0.0
 *
 * @date 28 December 2017
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

/* --- EXTI registers ------------------------------------------------------ */

#define EXTI_IMR2			MMIO32(EXTI_BASE + 0x20)
#define EXTI_EMR2			MMIO32(EXTI_BASE + 0x24)
#define EXTI_RTSR2			MMIO32(EXTI_BASE + 0x28)
#define EXTI_FTSR2			MMIO32(EXTI_BASE + 0x2C)
#define EXTI_SWIER2			MMIO32(EXTI_BASE + 0x30)
#define EXTI_PR2			MMIO32(EXTI_BASE + 0x34)

/**@}*/

#endif
