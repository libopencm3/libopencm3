/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Edward Cheeseman <evbuilder@users.sourceforge.net>
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
 * Basic ADC handling API.
 *
 * Examples:
 *  rcc_peripheral_enable_clock(&RCC_APB2ENR, ADC1EN);
 *  rcc_peripheral_disable_clock(&RCC_APB2ENR, ADC1EN);
 *  rcc_peripheral_reset(&RCC_APB2RSTR, ADC1RST);
 *  rcc_peripheral_clear_reset(&RCC_APB2RSTR, ADC1RST);
 *
 *  rcc_set_adc_clk(ADC_PRE_PLCK2_DIV2);
 *  adc_set_mode(ADC1, TODO);
 *  reg16 = adc_read(ADC1, ADC_CH_0);
 */

#include <libopenstm32/adc.h>

void rcc_set_adc_clk(u32 prescaler)
{  
	/* TODO */

	/* FIXME: QUICK HACK to prevent compiler warnings. */
	prescaler = prescaler;
} 

void adc_set_mode(u32 block, /* TODO */ u8 mode)
{
	/* TODO */

	/* FIXME: QUICK HACK to prevent compiler warnings. */
	block = block;
	mode = mode;
}

void adc_read(u32 block, u32 channel)
{
	/* TODO */

	/* FIXME: QUICK HACK to prevent compiler warnings. */
	block = block;
	channel = channel;
}
