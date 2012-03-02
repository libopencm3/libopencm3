/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#include <libopencm3/stm32/systick.h>

void systick_set_reload(u32 value)
{
	STK_LOAD = (value & 0x00FFFFFF);
}

u32 systick_get_value(void)
{
	return STK_VAL;
}

void systick_set_clocksource(u8 clocksource)
{
	if (clocksource < 2)
		STK_CTRL |= (clocksource << STK_CTRL_CLKSOURCE_LSB);
}

void systick_interrupt_enable(void)
{
	STK_CTRL |= STK_CTRL_TICKINT;
}

void systick_interrupt_disable(void)
{
	STK_CTRL &= ~STK_CTRL_TICKINT;
}

void systick_counter_enable(void)
{
	STK_CTRL |= STK_CTRL_ENABLE;
}

void systick_counter_disable(void)
{
	STK_CTRL &= ~STK_CTRL_ENABLE;
}

u8 systick_get_countflag(void)
{
	if (STK_CTRL & STK_CTRL_COUNTFLAG)
		return 1;
	else
		return 0;
}
