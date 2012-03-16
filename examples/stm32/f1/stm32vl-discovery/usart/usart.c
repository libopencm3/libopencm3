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
#include <libopencm3/stm32/usart.h>

void clock_setup(void)
{
	rcc_clock_setup_in_hse_8mhz_out_24mhz();

	/* Enable GPIOC clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);

	/* Enable clocks for GPIO port A (for GPIO_USART1_TX) and USART1. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_USART1EN);
}

void usart_setup(void)
{
	/* Setup GPIO pin GPIO_USART1_TX/GPIO9 on GPIO port A for transmit. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART1_TX);

	/* Setup UART parameters. */
	// usart_set_baudrate(USART1, 38400);
	/* TODO usart_set_baudrate() doesn't support 24MHz clock (yet). */
	/* This is the equivalent: */
	USART_BRR(USART1) = (u16)((24000000 << 4) / (38400 * 16));

	usart_set_databits(USART1, 8);
	usart_set_stopbits(USART1, USART_STOPBITS_1);
	usart_set_mode(USART1, USART_MODE_TX);
	usart_set_parity(USART1, USART_PARITY_NONE);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART1);
}

void gpio_setup(void)
{
	/* Set GPIO9 (in GPIO port C) to 'output push-pull'. [LED] */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO9);
}

int main(void)
{
	int i, j = 0, c = 0;

	clock_setup();
	gpio_setup();
	usart_setup();

	/* Blink the LED (PC9) on the board with every transmitted byte. */
	while (1) {
		gpio_toggle(GPIOC, GPIO9);	/* LED on/off */
		usart_send_blocking(USART1, c + '0'); /* USART1: Send byte. */
		c = (c == 9) ? 0 : c + 1;	/* Increment c. */
		if ((j++ % 80) == 0) {		/* Newline after line full. */
			usart_send_blocking(USART1, '\r');
			usart_send_blocking(USART1, '\n');
		}
		for (i = 0; i < 800000; i++)	/* Wait a bit. */
			__asm__("NOP");
	}

	return 0;
}
