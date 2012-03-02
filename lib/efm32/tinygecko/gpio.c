/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
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
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/efm32/tinygecko/gpio.h>

void gpio_set_mode(u32 gpioport, u8 mode, u16 gpios)
{
	u8 i;
	u32 modemaskl = 0, modesetl = 0, modemaskh = 0, modeseth = 0;

	for (i = 0; i < 8; ++i)
	{
		if (gpios & (1<<i)) {
			modemaskl |= GPIO_MODE_MASK << (i*4);
			modesetl |= mode << (i*4);
		}
		if (gpios & (0x100<<i)) {
			modemaskh |= GPIO_MODE_MASK << (i*4);
			modeseth |= mode << (i*4);
		}
	}
	GPIO_Px_MODEL(gpioport) &= ~modemaskl;
	GPIO_Px_MODEL(gpioport) |= modesetl;
	GPIO_Px_MODEH(gpioport) &= ~modemaskh;
	GPIO_Px_MODEH(gpioport) |= modeseth;
}
