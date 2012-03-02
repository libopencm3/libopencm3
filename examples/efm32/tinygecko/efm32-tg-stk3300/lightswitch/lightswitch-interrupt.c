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

void interrupt_setup()
{
	// These are the ports the pin interrupts for 8 and 11 are to be
	// configured to, and they should trigger on falling edge.
	
	GPIO_EXTIPSELH = (BUTTON0_PORT_EXTIPSEL << ((BUTTON0_PIN_NUMBER-8)*4)) |
	                 (BUTTON1_PORT_EXTIPSEL << ((BUTTON1_PIN_NUMBER-8)*4));

	GPIO_EXTIFALL = BUTTON0_PIN | BUTTON1_PIN;

	// Enable interrupts on the GPIO side
	
	GPIO_INSENSE = GPIO_INSENSE_INT;
	GPIO_IEN = BUTTON0_PIN | BUTTON1_PIN;

	// Enable GPIO interrupts in NVIC

	ISER0 = (1<<IRQ_GPIO_EVEN) | (1<<IRQ_GPIO_ODD);
}

int main(void)
{
	gpio_setup();
	interrupt_setup();

	while(1) {
		emu_sleep_em1();
	};
}

void gpio_even_isr()
{
	// Clearing the GPIO interrupt pending register. While the NVIC
	// interrupt pending register gets cleared automatically once it jumps
	// here, the pin's pending state has to be cleared explicitly.
	// (Dispatch to different subroutines for different even pins that
	// trigger an interrupt would happen here.)
	GPIO_IFC = BUTTON0_PIN;
	led_on();
}

void gpio_odd_isr()
{
	// See gpio_even_isr.
	GPIO_IFC = BUTTON1_PIN;
	led_off();
}
