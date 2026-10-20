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

/* DMA control register (TIMx_DCR) */
#undef TIM_DCR
#define TIM_DCR(tim_base)		MMIO32((tim_base) + 0x3DC)

/* DMA address for full transfer (TIMx_DMAR) */
#undef TIM_DMAR
#define TIM_DMAR(tim_base)		MMIO32((tim_base) + 0x3E0)

/* Timer 20 register definitions */
#define TIM20				TIM20_BASE
#define TIM20_CR1			TIM_CR1(TIM20)
#define TIM20_CR2			TIM_CR2(TIM20)
#define TIM20_SMCR			TIM_SMCR(TIM20)
#define TIM20_DIER			TIM_DIER(TIM20)
#define TIM20_SR			TIM_SR(TIM20)
#define TIM20_EGR			TIM_EGR(TIM20)
#define TIM20_CCMR1			TIM_CCMR1(TIM20)
#define TIM20_CCMR2			TIM_CCMR2(TIM20)
#define TIM20_CCER			TIM_CCER(TIM20)
#define TIM20_CNT			TIM_CNT(TIM20)
#define TIM20_PSC			TIM_PSC(TIM20)
#define TIM20_ARR			TIM_ARR(TIM20)
#define TIM20_RCR			TIM_RCR(TIM20)
#define TIM20_CCR1			TIM_CCR1(TIM20)
#define TIM20_CCR2			TIM_CCR2(TIM20)
#define TIM20_CCR3			TIM_CCR3(TIM20)
#define TIM20_CCR4			TIM_CCR4(TIM20)
#define TIM20_BDTR			TIM_BDTR(TIM20)
#define TIM20_DCR			TIM_DCR(TIM20)
#define TIM20_DMAR			TIM_DMAR(TIM20)
