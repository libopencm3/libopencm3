/*
 * This file is part of the libopencm3 project.
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

#include <libopencm3/stm32/timer.h>

void timer_set_mode(u32 timer_peripheral, u8 clock_div,
		    u8 alignment, u8 direction)
{
	u32 cr1 = TIM_CR1(timer_peripheral);

	cr1 &= ~(TIM_CR1_CKD_CK_INT_MASK |
		 TIM_CR1_CMS_MASK |
		 TIM_CR1_DIR_DOWN);

	cr1 |= clock_div | alignment | direction;

	TIM_CR1(timer_peripheral) = cr1;
}

void timer_set_clock_division(u32 timer_peripheral, u32 clock_div)
{
	clock_div &= TIM_CR1_CKD_CK_INT_MASK;
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_CKD_CK_INT_MASK;
	TIM_CR1(timer_peripheral) |= clock_div;
}

void timer_enable_preload(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) |= TIM_CR1_ARPE;
}

void timer_disable_preload(u32 timer_peripheral)
{
	TIM_CR1(timer_peripheral) &= ~TIM_CR1_ARPE;
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

void timer_set_period(u32 timer_peripheral, u32 period)
{
	TIM_ARR(timer_peripheral) = period;
}

void timer_enable_oc_clear(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1CE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2CE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3CE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4CE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as fast enable only applies to the whole channel. */
		break;
	}
}

void timer_disable_oc_clear(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC1CE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC2CE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC3CE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC4CE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as fast enable only applies to the whole channel. */
		break;
	}
}

void timer_set_oc_fast_mode(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1FE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2FE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3FE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4FE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as fast enable only applies to the whole channel. */
		break;
	}
}

void timer_set_oc_slow_mode(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC1FE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC2FE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC3FE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC4FE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}

void timer_set_oc_mode(u32 timer_peripheral, enum tim_oc_id oc_id, u32 mode)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_CC1S_MASK;
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_CC1S_OUT;
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC1M_MASK;
		TIM_CCMR1(timer_peripheral) |= mode;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_CC2S_MASK;
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_CC2S_OUT;
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC2M_MASK;
		TIM_CCMR1(timer_peripheral) |= mode;
		break;
	case TIM_OC3:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR2_CC3S_MASK;
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR2_CC3S_OUT;
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC3M_MASK;
		TIM_CCMR2(timer_peripheral) |= mode;
		break;
	case TIM_OC4:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR2_CC4S_MASK;
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR2_CC4S_OUT;
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC4M_MASK;
		TIM_CCMR2(timer_peripheral) |= mode;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}

void timer_enable_oc_preload(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC1PE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) |= TIM_CCMR1_OC2PE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC3PE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) |= TIM_CCMR2_OC4PE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}

void timer_disable_oc_preload(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC1PE;
		break;
	case TIM_OC2:
		TIM_CCMR1(timer_peripheral) &= ~TIM_CCMR1_OC2PE;
		break;
	case TIM_OC3:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC3PE;
		break;
	case TIM_OC4:
		TIM_CCMR2(timer_peripheral) &= ~TIM_CCMR2_OC4PE;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}

void timer_set_oc_polarity_high(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC1P;
		break;
	case TIM_OC2:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC2P;
		break;
	case TIM_OC3:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC3P;
		break;
	case TIM_OC4:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC4P;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to TIM1 and TIM8 only. */
		break;
	}

	if ((timer_peripheral == TIM1) ||
	    (timer_peripheral == TIM8)) {
		switch (oc_id) {
		case TIM_OC1N:
			TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC1NP;
			break;
		case TIM_OC2N:
			TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC2NP;
			break;
		case TIM_OC3N:
			TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC3NP;
			break;
		case TIM_OC1:
		case TIM_OC2:
		case TIM_OC3:
		case TIM_OC4:
			/* Ignoring as this option was already set above. */
			break;
		}

	}
}

void timer_set_oc_polarity_low(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC1P;
		break;
	case TIM_OC2:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC2P;
		break;
	case TIM_OC3:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC3P;
		break;
	case TIM_OC4:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC4P;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to TIM1 and TIM8 only. */
		break;
	}

	if ((timer_peripheral == TIM1) ||
	    (timer_peripheral == TIM8)) {
		switch (oc_id) {
		case TIM_OC1N:
			TIM_CCER(timer_peripheral) |= TIM_CCER_CC1NP;
			break;
		case TIM_OC2N:
			TIM_CCER(timer_peripheral) |= TIM_CCER_CC2NP;
			break;
		case TIM_OC3N:
			TIM_CCER(timer_peripheral) |= TIM_CCER_CC3NP;
			break;
		case TIM_OC1:
		case TIM_OC2:
		case TIM_OC3:
		case TIM_OC4:
			/* Ignoring as this option was already set above. */
			break;
		}

	}
}

void timer_enable_oc_output(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC1E;
		break;
	case TIM_OC2:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC2E;
		break;
	case TIM_OC3:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC3E;
		break;
	case TIM_OC4:
		TIM_CCER(timer_peripheral) |= TIM_CCER_CC4E;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to TIM1 and TIM8 only. */
		break;
	}

	if ((timer_peripheral == TIM1) ||
	    (timer_peripheral == TIM8)) {
		switch (oc_id) {
		case TIM_OC1N:
			TIM_CCER(timer_peripheral) |= TIM_CCER_CC1NE;
			break;
		case TIM_OC2N:
			TIM_CCER(timer_peripheral) |= TIM_CCER_CC2NE;
			break;
		case TIM_OC3N:
			TIM_CCER(timer_peripheral) |= TIM_CCER_CC3NE;
			break;
		case TIM_OC1:
		case TIM_OC2:
		case TIM_OC3:
		case TIM_OC4:
			/* Ignoring as this option was already set above. */
			break;
		}

	}
}

void timer_disable_oc_output(u32 timer_peripheral, enum tim_oc_id oc_id)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC1E;
		break;
	case TIM_OC2:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC2E;
		break;
	case TIM_OC3:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC3E;
		break;
	case TIM_OC4:
		TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC4E;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to TIM1 and TIM8 only. */
		break;
	}

	if ((timer_peripheral == TIM1) ||
	    (timer_peripheral == TIM8)) {
		switch (oc_id) {
		case TIM_OC1N:
			TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC1NE;
			break;
		case TIM_OC2N:
			TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC2NE;
			break;
		case TIM_OC3N:
			TIM_CCER(timer_peripheral) &= ~TIM_CCER_CC3NE;
			break;
		case TIM_OC1:
		case TIM_OC2:
		case TIM_OC3:
		case TIM_OC4:
			/* Ignoring as this option was already set above. */
			break;
		}

	}
}

void timer_set_oc_idle_state_set(u32 timer_peripheral, enum tim_oc_id oc_id)
{

	/* Acting for TIM1 and TIM8 only. */
	if ((timer_peripheral == TIM1) ||
	    (timer_peripheral == TIM8)) {
		switch (oc_id) {
		case TIM_OC1:
			TIM_CR2(timer_peripheral) |= TIM_CR2_OIS1;
			break;
		case TIM_OC1N:
			TIM_CR2(timer_peripheral) |= TIM_CR2_OIS1N;
			break;
		case TIM_OC2:
			TIM_CR2(timer_peripheral) |= TIM_CR2_OIS2;
			break;
		case TIM_OC2N:
			TIM_CR2(timer_peripheral) |= TIM_CR2_OIS2N;
			break;
		case TIM_OC3:
			TIM_CR2(timer_peripheral) |= TIM_CR2_OIS3;
			break;
		case TIM_OC3N:
			TIM_CR2(timer_peripheral) |= TIM_CR2_OIS3N;
			break;
		case TIM_OC4:
			TIM_CR2(timer_peripheral) |= TIM_CR2_OIS4;
			break;
		}

	}
}

void timer_set_oc_idle_state_unset(u32 timer_peripheral, enum tim_oc_id oc_id)
{

	/* Acting for TIM1 and TIM8 only. */
	if ((timer_peripheral == TIM1) ||
	    (timer_peripheral == TIM8)) {
		switch (oc_id) {
		case TIM_OC1:
			TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS1;
			break;
		case TIM_OC1N:
			TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS1N;
			break;
		case TIM_OC2:
			TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS2;
			break;
		case TIM_OC2N:
			TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS2N;
			break;
		case TIM_OC3:
			TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS3;
			break;
		case TIM_OC3N:
			TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS3N;
			break;
		case TIM_OC4:
			TIM_CR2(timer_peripheral) &= ~TIM_CR2_OIS4;
			break;
		}

	}
}

void timer_set_oc_value(u32 timer_peripheral, enum tim_oc_id oc_id, u32 value)
{
	switch (oc_id) {
	case TIM_OC1:
		TIM_CCR1(timer_peripheral) = value;
		break;
	case TIM_OC2:
		TIM_CCR2(timer_peripheral) = value;
		break;
	case TIM_OC3:
		TIM_CCR3(timer_peripheral) = value;
		break;
	case TIM_OC4:
		TIM_CCR4(timer_peripheral) = value;
		break;
	case TIM_OC1N:
	case TIM_OC2N:
	case TIM_OC3N:
		/* Ignoring as this option applies to the whole channel. */
		break;
	}
}
