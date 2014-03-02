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

void lcd_enable(void)
{
	LCD_CR |= LCD_CR_LCDEN;
	while ((LCD_SR & LCD_SR_ENS) == 0);
}

void lcd_wait_step_up_ready(void)
{
	while ((LCD_SR & LCD_SR_RDY) == 0);
}

void lcd_wait_for_update_ready(void)
{
	while ((LCD_SR & LCD_SR_UDR) != 0);
}

void lcd_update(void)
{
  LCD_SR |= LCD_SR_UDR;
}

