/** @addtogroup exti_defines */
#pragma once

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

/** @cond */
#if defined(LIBOPENCM3_EXTI_H)
/** @endcond */

/**@{*/

/* --- EXTI registers ------------------------------------------------------ */

/** @defgroup exti_registers EXTI Registers
@{*/
/** EXTI Interrupt Mask Registers */
#define EXTI_IMR1			MMIO32(EXTI_BASE + 0x00)
/** EXTI Event Mask Register */
#define EXTI_EMR1			MMIO32(EXTI_BASE + 0x04)
/** EXTI Rising Trigger Selection Register */
#define EXTI_RTSR1			MMIO32(EXTI_BASE + 0x08)
/** EXTI Falling Triger Selection Register */
#define EXTI_FTSR1			MMIO32(EXTI_BASE + 0x0c)
/** EXTI Software Interrupt Event Register */
#define EXTI_SWIER1			MMIO32(EXTI_BASE + 0x10)
/** EXTI Pending Register */
#define EXTI_PR1			MMIO32(EXTI_BASE + 0x14)
/** EXTI Interrupt Mask Registers */
#define EXTI_IMR2			MMIO32(EXTI_BASE + 0x20)
/** EXTI Event Mask Register */
#define EXTI_EMR2			MMIO32(EXTI_BASE + 0x24)
/** EXTI Rising Trigger Selection Register */
#define EXTI_RTSR2			MMIO32(EXTI_BASE + 0x28)
/** EXTI Falling Triger Selection Register */
#define EXTI_FTSR2			MMIO32(EXTI_BASE + 0x2c)
/** EXTI Software Interrupt Event Register */
#define EXTI_SWIER2			MMIO32(EXTI_BASE + 0x30)
/** EXTI Pending Register */
#define EXTI_PR2			MMIO32(EXTI_BASE + 0x34)
/**@}*/

BEGIN_DECLS

END_DECLS

/**@}*/

/** @cond */
#else
#warning "exti_common_v1.h should not be included directly, only via exti.h"
#endif
/** @endcond */
