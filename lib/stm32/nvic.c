/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Fergus Noble <fergusnoble@gmail.com>
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

#include <libopencm3/stm32/nvic.h>

void nvic_enable_irq(u8 irqn)
{
	NVIC_ISER(irqn / 32) = (1 << (irqn % 32));
}

void nvic_disable_irq(u8 irqn)
{
	NVIC_ICER(irqn / 32) = (1 << (irqn % 32));
}

u8 nvic_get_pending_irq(u8 irqn)
{
	return NVIC_ISPR(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}

void nvic_set_pending_irq(u8 irqn)
{
	NVIC_ISPR(irqn / 32) = (1 << (irqn % 32));
}

void nvic_clear_pending_irq(u8 irqn)
{
	NVIC_ICPR(irqn / 32) = (1 << (irqn % 32));
}

u8 nvic_get_active_irq(u8 irqn)
{
	return NVIC_IABR(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}

u8 nvic_get_irq_enabled(u8 irqn)
{
	return NVIC_ISER(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
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
