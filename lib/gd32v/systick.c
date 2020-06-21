/*
 * This file is part of the libopencm3 project.
 *
 * Copyright 2020 Lubomir Rintel <lkundrak@v3.sk>
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

#include <libopencm3/gd32v/systick.h>
#include <libopencm3/gd32v/eclic.h>

void systick_set_reload(uint64_t value)
{
	SYSTICK_TIME_CMP = value;
}

uint64_t systick_get_reload(void)
{
	return SYSTICK_TIME_CMP;
}

void systick_set_value(uint64_t value)
{
	SYSTICK_TIME = value;
}

uint64_t systick_get_value(void)
{
	return SYSTICK_TIME;
}

void systick_interrupt_enable(void)
{
	eclic_enable_irq(ECLIC_SYSTICK_IRQ);
}

void systick_interrupt_disable(void)
{
	eclic_disable_irq(ECLIC_SYSTICK_IRQ);
}
