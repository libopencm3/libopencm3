/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_TIMER_F4_H
#define LIBOPENCM3_TIMER_F4_H

#include <libopencm3/stm32/timer.h>

/*
 * TIM2 and TIM5 are now 32bit and the following registers are now 32-bit wide:
 * CNT, ARR, CCR1, CCR2, CCR3, CCR4
 */

/* Timer 2/5 option register (TIMx_OR) */
#define TIM_OR(tim_base)		MMIO32(tim_base + 0x50)
#define TIM2_OR				TIM_OR(TIM2)
#define TIM5_OR				TIM_OR(TIM5)

/* --- TIM2_OR values ---------------------------------------------------- */

/* MOE: Main output enable */
#define TIM2_OR_ITR1_RMP_TIM8_TRGOU	(0x0 << 10)
#define TIM2_OR_ITR1_RMP_PTP		(0x1 << 10)
#define TIM2_OR_ITR1_RMP_OTG_FS_SOF	(0x2 << 10)
#define TIM2_OR_ITR1_RMP_OTG_HS_SOF	(0x3 << 10)
#define TIM2_OR_ITR1_RMP_MASK		(0x3 << 10)

/* --- TIM5_OR values ---------------------------------------------------- */

/* MOE: Main output enable */
#define TIM5_OR_TI4_RMP_GPIO		(0x0 << 6)
#define TIM5_OR_TI4_RMP_LSI		(0x1 << 6)
#define TIM5_OR_TI4_RMP_LSE		(0x2 << 6)
#define TIM5_OR_TI4_RMP_RTC		(0x3 << 6)
#define TIM5_OR_TI4_RMP_MASK		(0x3 << 6)

/* --- Function prototypes ------------------------------------------------- */

void timer_set_option(u32 timer_peripheral, u32 option);

#endif
