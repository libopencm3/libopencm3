/*
 * This file is part of the libopenstm32 project.
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

#include <libopenstm32.h>

void flash_prefetch_buffer_enable(void)
{
	FLASH_ACR |= PRFTBE;
}

void flash_prefetch_buffer_disable(void)
{
	FLASH_ACR &= ~PRFTBE;
}

void flash_halfcycle_enable(void)
{
	FLASH_ACR |= HLFCYA;
}

void flash_halfcycle_disable(void)
{
	FLASH_ACR &= ~HLFCYA;
}

void flash_set_ws(u32 ws)
{
	u32 reg32;

	reg32 = FLASH_ACR;
	reg32 &= ~((1 << 0) | (1 << 1) | (1 << 2));
	reg32 |= ws;
	FLASH_ACR = reg32;
}
