/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/gpio.h>

#include <libopencm3/stm32/dbgmcu.h>
#include <libopencm3/cm3/scs.h>
#include <libopencm3/cm3/tpiu.h>
#include <libopencm3/cm3/itm.h>

void clock_setup(void)
{
	rcc_clock_setup_in_hse_8mhz_out_72mhz();

	/* Enable GPIOC clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);
}

void trace_setup(void)
{
	/* Enable trace subsystem (we'll use ITM and TPIU). */
	SCS_DEMCR |= SCS_DEMCR_TRCENA;

	/* Use Manchester code for asynchronous transmission. */
	TPIU_SPPR = TPIU_SPPR_ASYNC_MANCHESTER;
	TPIU_ACPR = 7;

	/* Data width is 1 byte. */
	TPIU_CSPSR = TPIU_CSPSR_BYTE;

	/* Formatter and flush control. */
	TPIU_FFCR &= ~TPIU_FFCR_ENFCONT;

	/* Enable TRACESWO pin for async mode. */
	DBGMCU_CR = DBGMCU_CR_TRACE_IOEN | DBGMCU_CR_TRACE_MODE_ASYNC;

	/* Unlock access to ITM registers. */
	/* FIXME: Magic numbers... Is this Cortex-M3 generic? */
	*((volatile u32 *)0xE0000FB0) = 0xC5ACCE55;

	/* Enable ITM with ID = 1. */
	ITM_TCR = (1 << 16) | ITM_TCR_ITMENA;
	/* Enable stimulus port 1. */
	ITM_TER[0] = 1;
}

void gpio_setup(void)
{
	/* Set GPIO12 (in GPIO port C) to 'output push-pull'. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);
}

void trace_send_blocking(char c)
{
	while (!(ITM_STIM[0] & ITM_STIM_FIFOREADY))
		;

	ITM_STIM[0] = c;
}

int main(void)
{
	int i, j = 0, c = 0;

	clock_setup();
	gpio_setup();
	trace_setup();

	/* Blink the LED (PC12) on the board with every transmitted byte. */
	while (1) {
		gpio_toggle(GPIOC, GPIO12);	/* LED on/off */
		trace_send_blocking(c + '0');
		c = (c == 9) ? 0 : c + 1;	/* Increment c. */
		if ((j++ % 80) == 0) {		/* Newline after line full. */
			trace_send_blocking('\r');
			trace_send_blocking('\n');
		}
		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
