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
#define EXTI_IMR			MMIO32(EXTI_BASE + 0x00)
/** EXTI Event Mask Register */
#define EXTI_EMR			MMIO32(EXTI_BASE + 0x04)
/** EXTI Rising Trigger Selection Register */
#define EXTI_RTSR			MMIO32(EXTI_BASE + 0x08)
/** EXTI Falling Triger Selection Register */
#define EXTI_FTSR			MMIO32(EXTI_BASE + 0x0c)
/** EXTI Software Interrupt Event Register */
#define EXTI_SWIER			MMIO32(EXTI_BASE + 0x10)
/** EXTI Pending Register */
#define EXTI_PR				MMIO32(EXTI_BASE + 0x14)
/**@}*/

BEGIN_DECLS

END_DECLS

/**@}*/

/** @cond */
#else
#warning "exti_common_v1.h should not be included directly, only via exti.h"
#endif
/** @endcond */
