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

void adc_enable_analog_watchdog_regular(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDEN;
}

void adc_disable_analog_watchdog_regular(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDEN;
}

void adc_enable_analog_watchdog_injected(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JAWDEN;
}

void adc_disable_analog_watchdog_injected(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAWDEN;
}

void adc_enable_discontinous_mode_regular(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_DISCEN;
}

void adc_disable_discontinous_mode_regular(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_DISCEN;
}

void adc_enable_discontinous_mode_injected(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JDISCEN;
}

void adc_disable_discontinous_mode_injected(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JDISCEN;
}

void adc_enable_automatic_injected_group_conversion(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JAUTO;
}

void adc_disable_automatic_injected_group_conversion(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JAUTO;
}

void adc_enable_analog_watchdog_on_all_channels(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDSGL;
}

void adc_enable_analog_watchdog_on_selected_channel(u32 adc, u8 channel)
{
	u32 reg32;

	reg32 = (ADC_CR1(adc) & 0xffffffe0); /* Clear bits [4:0]. */
	if (channel < 18)
		reg32 |= channel;
	ADC_CR1(adc) = reg32;
	ADC_CR1(adc) &= ~ADC_CR1_AWDSGL;
}

void adc_enable_scan_mode(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_SCAN;
}

void adc_disable_scan_mode(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_SCAN;
}

void adc_enable_jeoc_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_JEOCIE;
}

void adc_disable_jeoc_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_JEOCIE;
}

void adc_enable_awd_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_AWDIE;
}

void adc_disable_awd_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_AWDIE;
}

void adc_enable_eoc_interrupt(u32 adc)
{
	ADC_CR1(adc) |= ADC_CR1_EOCIE;
}

void adc_disable_eoc_interrupt(u32 adc)
{
	ADC_CR1(adc) &= ~ADC_CR1_EOCIE;
}
