/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *               2012 chrysn <chrysn@fsfe.org>
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

#include <libopencm3/efm32/tinygecko/gpio.h>
#include <libopencm3/efm32/tinygecko/cmu.h>

int main(void)
{
	// FIXME: As of now, this doesn't work without x being volatile; an issue with linking?
	volatile int x;

	// Before GPIO works, according to d0034_efm32tg_reference_manual.pdf
	// note in section 28.3.7, we'll have to enable GPIO in CMU_HFPERCLKEN0
	
	CMU_HFPERCLKEN0 |= CMU_HFPERCLKEN0_GPIO;

	// The User LED is connected to PD7 to the plus side of the LED
	// according to t0011_efm32_tiny_gecko_stk_user_manual.pdf figures 16.2
	// and 16.3 (called UIF_LED0)
	
	GPIO_PD_MODEL = GPIO_MODE_PUSHPULL<<(7*4);
	GPIO_PD_DOUTSET = 1<<7;

	while(1) {
		for(x = 0; x < 200000; ++x);
		GPIO_PD_DOUTTGL = 1<<7;
	};
}
