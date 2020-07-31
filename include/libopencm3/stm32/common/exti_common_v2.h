/** @addtogroup exti_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2019 Guillaume Revaillot <g.revaillot@gmail.com>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Guillaume Revaillot <g.revaillot@gmail.com>
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

/** @cond */
#if defined(LIBOPENCM3_EXTI_H)
/** @endcond */
#ifndef LIBOPENCM3_EXTI_COMMON_V2_H
#define LIBOPENCM3_EXTI_COMMON_V2_H

/* --- EXTI registers ------------------------------------------------------ */

/** @defgroup exti_registers EXTI Registers
@{*/
/** EXTI Rising Trigger Selection Register 1 */
#define EXTI_RTSR1			MMIO32(EXTI_BASE + 0x00)
#define EXTI_RTSR			EXTI_RTSR1

/** EXTI Falling Trigger Selection Register 1 */
#define EXTI_FTSR1			MMIO32(EXTI_BASE + 0x04)
#define EXTI_FTSR			EXTI_FTSR1

/** EXTI Software Interrupt Event Register */
#define EXTI_SWIER1			MMIO32(EXTI_BASE + 0x08)

/** EXTI Interrupt Mask Registers 1 */
#define EXTI_IMR1			MMIO32(EXTI_BASE + 0x80)
#define EXTI_IMR			EXTI_IMR1

/** EXTI Event Mask Registers 1 */
#define EXTI_EMR1			MMIO32(EXTI_BASE + 0x84)
#define EXTI_EMR			EXTI_EMR1

/** EXTI Interrupt Mask Registers 2 */
#define EXTI_IMR2			MMIO32(EXTI_BASE + 0x90)
/** EXTI Event Mask Registers 2 */
#define EXTI_EMR2			MMIO32(EXTI_BASE + 0x94)
/**@}*/

/* --- EXTI_EXTICR Values -------------------------------------------------*/

#define EXTI_EXTICR_FIELDSIZE		8
#define EXTI_EXTICR_GPIOA		0
#define EXTI_EXTICR_GPIOB		1
#define EXTI_EXTICR_GPIOC		2
#define EXTI_EXTICR_GPIOD		3
#define EXTI_EXTICR_GPIOE		4
#define EXTI_EXTICR_GPIOF		5
#define EXTI_EXTICR_GPIOG		6
#define EXTI_EXTICR_GPIOH		7

BEGIN_DECLS

uint32_t exti_get_rising_flag_status(uint32_t exti);
uint32_t exti_get_falling_flag_status(uint32_t exti);

void exti_reset_rising_request(uint32_t extis);
void exti_reset_falling_request(uint32_t extis);

END_DECLS

#endif
/** @cond */
#else
#warning "exti_common_v2.h should not be included directly, only via exti.h"
#endif
/** @endcond */

/**@}*/
