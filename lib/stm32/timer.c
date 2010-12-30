/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Edward Cheeseman <evbuilder@users.sourceforge.org>
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

/*
 * Basic TIMER handling API.
 *
 * Examples:
 *  timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT_MUL_2,
 *                 TIM_CR1_CMS_CENTRE_3, TIM_CR1_DIR_UP);
 */

#include <stm32/timer.h>

void timer_set_mode(u32 timer_peripheral, u8 clock_div, u8 alignment,
		    u8 direction)
{
	/* Bad, will reset lots of other stuff. */
	// TIM_CR1(timer_peripheral) = clock_div | alignment | direction;
}

void timer_set_clock_division(u32 timer_peripheral, u32 clock_div)
{
	clock_div &= TIM_CR1_CKD_CK_INT_MASK;
	TIM_CR1(timer_peripheral) &= !TIM_CR1_CKD_CK_INT_MASK;
	TIM_CR1(timer_peripheral) |= clock_div;
}

void timer_enable_preload(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_ARPE;
}

void timer_disable_preload(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= !TIM_CR1_ARPE;
}

void timer_set_alignment(u32 timer_peripheral, u32 alignment)
{
	alignment &= TIM_CR1_CMS_MASK;
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_CMS_MASK;
	TIM_CR1(timer_peripheral) |= alignment;
}

void timer_direction_up(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_DIR_DOWN;
}

void timer_direction_down(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_DIR_DOWN;
}

void timer_one_shot_mode(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_OPM;
}

void timer_continuous_mode(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_OPM;
}

void timer_update_on_any(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_URS;
}

void timer_update_on_overflow(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_URS;
}

void timer_enable_update_event(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_UDIS;
}

void timer_disable_update_event(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_UDIS;
}

void timer_enable_counter(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_CEN;
}

void timer_disable_counter(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_CEN;
}

void timer_set_output_idle_state(u32 timer_peripheral, u32 outputs)
{
	TIM_CR2(timer_peripheral) |= outputs & TIM_CR2_OIS_MASK;
}

void timer_reset_output_idle_state(u32 timer_peripheral, u32 outputs)
{
	TIM_CR2(timer_peripheral) &= ~(outputs & TIM_CR2_OIS_MASK);
}

void timer_set_ti1_ch123_xor(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) |= TIM_CR2_TI1S;
}

void timer_set_ti1_ch1(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) &= ~TIM_CR2_TI1S;
}

void timer_set_master_mode(u32 timer_peripheral, u32 mode)
{
	mode &= mode & TIM_CR2_MASK;
	TIM_CR2(timer_peripheral) &= ~TIM_CR2_MMS_MASK;
	TIM_CR2(timer_peripheral) |= mode;
}

void timer_set_dma_on_compare_event(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) &= ~TIM_CR2_CCDS;
}

void timer_set_dma_on_update_event(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) |= TIM_CR2_CCDS;
}

void timer_enable_compare_control_update_on_trigger(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) |= TIM_CR2_CCUS;
}

void timer_disable_compare_control_update_on_trigger(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) &= ~TIM_CR2_CCUS;
}

void timer_enable_preload_complementry_enable_bits(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) |= TIM_CR2_CCPC;
}

void timer_disable_preload_complementry_enable_bits(u32 timer_peripheral)
{
	TIM_CR2(timer_peripheral) &= ~TIM_CR2_CCPC;
}
