/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Nikolay Merinov <nikolay.merinov@member.fsf.org>
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

#include <libopencm3/stm32/l1/lcd.h>
#include <libopencm3/stm32/rcc.h>

void lcd_enable(void)
{
	LCD_CR |= LCD_CR_LCDEN;
}

void lcd_update(void)
{
	LCD_SR |= LCD_SR_UDR;
}

void lcd_wait_for_lcd_enabled(void)
{
	while ((LCD_SR & LCD_SR_ENS) == 0);
}

void lcd_wait_for_step_up_ready(void)
{
	while ((LCD_SR & LCD_SR_RDY) == 0);
}

void lcd_wait_for_update_ready(void)
{
	while ((LCD_SR & LCD_SR_UDR) != 0);
}

int lcd_is_enabled(void)
{
	return ((LCD_SR & LCD_SR_ENS) != 0);
}

int lcd_is_step_up_ready(void)
{
	return ((LCD_SR & LCD_SR_RDY) != 0);
}

int lcd_is_for_update_ready(void)
{
	return ((LCD_SR & LCD_SR_UDR) == 0);
}

void lcd_set_contrast(uint8_t contrast)
{
	LCD_FCR &= ~(LCD_FCR_CC_MASK << LCD_FCR_CC_SHIFT);
	LCD_FCR |= contrast << LCD_FCR_CC_SHIFT;
}

void lcd_set_bias(uint8_t bias)
{
	LCD_CR &= ~(LCD_CR_BIAS_MASK << LCD_CR_BIAS_SHIFT);
	LCD_CR |= bias << LCD_CR_BIAS_SHIFT;
}

void lcd_set_duty(uint8_t duty)
{
	LCD_CR &= ~(LCD_CR_DUTY_MASK << LCD_CR_DUTY_SHIFT);
	LCD_CR |= duty << LCD_CR_DUTY_SHIFT;
}

void lcd_set_prescaler(uint8_t ps)
{
	LCD_FCR &= ~(LCD_FCR_PS_MASK << LCD_FCR_PS_SHIFT);
	LCD_FCR |= ps << LCD_FCR_PS_SHIFT;
}

void lcd_set_divider(uint8_t div)
{
	LCD_FCR &= ~(LCD_FCR_DIV_MASK << LCD_FCR_DIV_SHIFT);
	LCD_FCR |= div << LCD_FCR_DIV_SHIFT;
}

void lcd_enable_segment_multiplexing(void)
{
	LCD_CR |= LCD_CR_MUX_SEG;
}

void lcd_disable_segment_multiplexing(void)
{
	LCD_CR &= ~LCD_CR_MUX_SEG;
}

void lcd_set_refresh_frequency(uint32_t frequency)
{
	uint32_t duty, lcd_clock;
	switch ((LCD_CR >> LCD_CR_DUTY_SHIFT) & LCD_CR_DUTY_MASK) {
	case LCD_CR_DUTY_STATIC:
		duty = 1;
		break;
	case LCD_CR_DUTY_1_2:
		duty = 2;
		break;
	case LCD_CR_DUTY_1_3:
		duty = 3;
		break;
	case LCD_CR_DUTY_1_4:
		duty = 4;
		break;
	case LCD_CR_DUTY_1_8:
		duty = 8;
		break;
	default:
		/* Incorrect duty */
		return;
	}

	switch ((RCC_CSR >> RCC_CSR_RTCSEL_SHIFT) & RCC_CSR_RTCSEL_MASK) {
	case RCC_CSR_RTCSEL_LSE:
		lcd_clock = 32786;
		break;
	case RCC_CSR_RTCSEL_LSI:
		lcd_clock = 37000;
		break;
	case RCC_CSR_RTCSEL_HSI:
		lcd_clock = 16000000;
		break;
	default:
		/* RCC Clock not selected */
		return;
	}

	/* PS * DIV = lcd_clock/(duty * freq) */
	uint32_t ps_mul_div = lcd_clock / (duty * frequency);

	int div, ps = 0;
	while (ps_mul_div > 32)	{
		ps_mul_div >>= 1;
		ps++;
	}
	div = ps_mul_div - 16;

	lcd_set_prescaler(ps);
	lcd_set_divider(div);
}
