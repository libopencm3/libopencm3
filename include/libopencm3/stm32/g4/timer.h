/** @defgroup timer_defines Timer Defines
 *
 * @brief <b>Defined Constants and Types for the STM32G4xx Timers</b>
 *
 * @ingroup STM32G4xx_defines
 *
 * @version 1.0.0
 *
 * @date 10 Jul 2020
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

#pragma once
#include <libopencm3/stm32/common/timer_common_f24.h>

/* --- TIMx_CR2 values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_x_cr2_ois TIMx_CR2_OIS: Force Output Idle State Control Values
@{*/
/* OIS4N:*//** Output idle state 4 (OC4N output) */
#define TIM_CR2_OIS4N			(1 << 15)

/* OIS5:*//** Output idle state 5 (OC5 output) */
#define TIM_CR2_OIS4N			(1 << 16)

/* OIS6:*//** Output idle state 6 (OC6 output) */
#define TIM_CR2_OIS4N			(1 << 18)
#define TIM_CR2_OIS_MASK		(0xfff << 8)
/**@}*/

/* MMS[3:0]: Master mode selection */
/****************************************************************************/
/** @defgroup tim_mastermode TIMx_CR2 MMS[25:4]: Master Mode Selection
@{*/
#define TIM_CR2_MMS_RESET		(0x0 << 4)
#define TIM_CR2_MMS_ENABLE		(0x1 << 4)
#define TIM_CR2_MMS_UPDATE		(0x2 << 4)
#define TIM_CR2_MMS_COMPARE_PULSE	(0x3 << 4)
#define TIM_CR2_MMS_COMPARE_OC1REF	(0x4 << 4)
#define TIM_CR2_MMS_COMPARE_OC2REF	(0x5 << 4)
#define TIM_CR2_MMS_COMPARE_OC3REF	(0x6 << 4)
#define TIM_CR2_MMS_COMPARE_OC4REF	(0x7 << 4)
#define TIM_CR2_MMS_ENCODER_OUTPUT	(0x200000 << 4)
#define TIM_CR2_MMS_MASK		(0x200007 << 4)
/**@}*/

/* MMS2[3:0]: Master mode selection 2 */
/****************************************************************************/
/** @defgroup tim_mastermode TIMx_CR2 MMS2[23:20]: Master Mode Selection 2
@{*/
#define TIM_CR2_MMS2_RESET		(0x0 << 20)
#define TIM_CR2_MMS2_ENABLE		(0x1 << 20)
#define TIM_CR2_MMS2_UPDATE		(0x2 << 20)
#define TIM_CR2_MMS2_COMPARE_PULSE	(0x3 << 20)
#define TIM_CR2_MMS2_COMPARE_OC1REF	(0x4 << 20)
#define TIM_CR2_MMS2_COMPARE_OC2REF	(0x5 << 20)
#define TIM_CR2_MMS2_COMPARE_OC3REF	(0x6 << 20)
#define TIM_CR2_MMS2_COMPARE_OC4REF	(0x7 << 20)
#define TIM_CR2_MMS_ENCODER_OUTPUT	(0x8 << 20)
#define TIM_CR2_MMS2_MASK		(0xf << 20)
/**@}*/
