/** @defgroup exti_defines EXTI Defines
 *
 * @ingroup STM32G0xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32G0xx EXTI Control</b>
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 *  */
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

/**@{*/
#ifndef LIBOPENCM3_EXTI_H
#define LIBOPENCM3_EXTI_H

#include <libopencm3/stm32/common/exti_common_all.h>
#include <libopencm3/stm32/common/exti_common_v2.h>

/** EXTI External Interrupt Selection Registers */
#define EXTI_EXTICR(i)    MMIO32(EXTI_BASE + 0x60 + (i)*4)
#define EXTI_EXTICR1    MMIO32(EXTI_BASE + 0x60)
#define EXTI_EXTICR2    MMIO32(EXTI_BASE + 0x64)
#define EXTI_EXTICR3    MMIO32(EXTI_BASE + 0x68)
#define EXTI_EXTICR4    MMIO32(EXTI_BASE + 0x6c)

/** EXTI Rising Edge Pending Register */
#define EXTI_RPR1     MMIO32(EXTI_BASE + 0x0c)
/** EXTI Falling Edge Pending Register */
#define EXTI_FPR1     MMIO32(EXTI_BASE + 0x10)

BEGIN_DECLS

END_DECLS

#else
/** @cond */
#warning "exti_common_v1.h should not be included directly, only via exti.h"
#endif
/** @endcond */

/**@}*/
