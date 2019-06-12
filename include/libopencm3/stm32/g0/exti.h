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

/* --- EXTI registers ------------------------------------------------------ */
#define EXTI_RTSR1			MMIO32(EXTI_BASE + 0x00)
#define EXTI_RTSR			EXTI_RTSR1

#define EXTI_FTSR1			MMIO32(EXTI_BASE + 0x04)
#define EXTI_FTSR			EXTI_FTSR1

#define EXTI_SWIER1			MMIO32(EXTI_BASE + 0x08)
#define EXTI_RPR1			MMIO32(EXTI_BASE + 0x0c)
#define EXTI_FPR1			MMIO32(EXTI_BASE + 0x10)

#define EXTI_EXTICR(i)		MMIO32(EXTI_BASE + 0x60 + (i)*4)
#define EXTI_EXTICR1		MMIO32(EXTI_BASE + 0x60)
#define EXTI_EXTICR2		MMIO32(EXTI_BASE + 0x64)
#define EXTI_EXTICR3		MMIO32(EXTI_BASE + 0x68)
#define EXTI_EXTICR4		MMIO32(EXTI_BASE + 0x6c)

#define EXTI_IMR1			MMIO32(EXTI_BASE + 0x80)
#define EXTI_IMR			EXTI_IMR1

#define EXTI_EMR1			MMIO32(EXTI_BASE + 0x84)
#define EXTI_EMR			EXTI_EMR1

#define EXTI_IMR2			MMIO32(EXTI_BASE + 0x90)
#define EXTI_EMR2			MMIO32(EXTI_BASE + 0x94)

/* --- EXTI_EXTICR Values -------------------------------------------------*/

#define EXTI_EXTICR_FIELDSIZE		8
#define EXTI_EXTICR_GPIOA		0
#define EXTI_EXTICR_GPIOB		1
#define EXTI_EXTICR_GPIOC		2
#define EXTI_EXTICR_GPIOD		3
#define EXTI_EXTICR_GPIOF		5

BEGIN_DECLS

uint32_t exti_get_rising_flag_status(uint32_t exti);
uint32_t exti_get_falling_flag_status(uint32_t exti);

void exti_reset_rising_request(uint32_t extis);
void exti_reset_falling_request(uint32_t extis);

END_DECLS

#else
/** @cond */
#warning "exti_common_v1.h should not be included directly, only via exti.h"
#endif
/** @endcond */

/**@}*/
