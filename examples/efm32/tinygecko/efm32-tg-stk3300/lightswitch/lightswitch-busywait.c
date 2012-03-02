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

#include <libopencm3/efm32/tinygecko/irq.h>
#include <libopencm3/efm32/tinygecko/emu.h>

#define ISER0 MMIO32(0xE000E100)
#define ICER0 MMIO32(0xE000E180)
#define ISPR0 MMIO32(0XE000E200)
#define ICPR0 MMIO32(0XE000E280)

/** @file Simplest implementation of the lightswitch mechanism. */

int main(void)
{
	gpio_setup();

	while(1) {
		if (pb0_get())
			led_on();
		if (pb1_get())
			led_off();
	};
}
