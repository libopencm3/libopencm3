/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#include <libopencm3/stm32/nvic.h>

void nvic_enable_irq(u8 irqn)
{
	if (irqn < 32)
		NVIC_ISER(0) |= (1 << irqn);
	if ((irqn >= 32) & (irqn < 64))
		NVIC_ISER(1) |= (1 << (irqn - 32));
	if ((irqn >= 64) & (irqn < 68))
		NVIC_ISER(2) |= (1 << (irqn - 64));
}

void nvic_disable_irq(u8 irqn)
{
	if (irqn < 32)
		NVIC_ICER(0) |= (1 << irqn);
	if ((irqn >= 32) & (irqn < 64))
		NVIC_ICER(1) |= (1 << (irqn - 32));
	if ((irqn >= 64) & (irqn < 68))
		NVIC_ICER(2) |= (1 << (irqn - 64));
}

u8 nvic_get_pending_irq(u8 irqn)
{
	if (irqn < 32)
		return (NVIC_ISPR(0) & (1 << irqn));
	if ((irqn >= 32) & (irqn < 64))
		return (NVIC_ISPR(1) & (1 << (irqn - 32)));
	if ((irqn >= 64) & (irqn < 68))
		return (NVIC_ISPR(2) & (1 << (irqn - 64)));
	return 0;
}

void nvic_set_pending_irq(u8 irqn)
{
	if (irqn < 32)
		NVIC_ISPR(0) |= (1 << irqn);
	if ((irqn >= 32) & (irqn < 64))
		NVIC_ISPR(1) |= (1 << (irqn - 32));
	if ((irqn >= 64) & (irqn < 68))
		NVIC_ISPR(2) |= (1 << (irqn - 64));
}

void nvic_clear_pending_irq(u8 irqn)
{
	if (irqn < 32)
		NVIC_ICPR(0) |= (1 << irqn);
	if ((irqn >= 32) & (irqn < 64))
		NVIC_ICPR(1) |= (1 << (irqn - 32));
	if ((irqn >= 64) & (irqn < 68))
		NVIC_ICPR(2) |= (1 << (irqn - 64));
}

u8 nvic_get_active_irq(u8 irqn)
{
	if (irqn < 32)
		return (NVIC_IABR(0) & (1 << irqn));
	if ((irqn >= 32) & (irqn < 64))
		return (NVIC_IABR(1) & (1 << (irqn - 32)));
	if ((irqn >= 64) & (irqn < 68))
		return (NVIC_IABR(2) & (1 << (irqn - 64)));
	return 0;
}

u8 nvic_get_irq_enabled(u8 irqn)
{
	if (irqn < 32)
		return (NVIC_ISER(0) & (1 << irqn));
	if ((irqn >= 32) & (irqn < 64))
		return (NVIC_ISER(1) & (1 << (irqn - 32)));
	if ((irqn >= 64) & (irqn < 68))
		return (NVIC_ISER(2) & (1 << (irqn - 64)));
	return 0;
}

void nvic_set_priority(u8 irqn, u8 priority)
{
	NVIC_IPR(irqn / 4) |= (priority << ((irqn % 4) * 8));
}

void nvic_generate_software_interrupt(u8 irqn)
{
	if (irqn <= 239)
		NVIC_STIR |= irqn;
}
