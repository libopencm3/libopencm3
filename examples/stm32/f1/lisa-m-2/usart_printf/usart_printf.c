/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>,
 * Copyright (C) 2011-2012 Piotr Esden-Tempski <piotr@esden.net>
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
#include <libopencm3/cm3/nvic.h>
#include <stdio.h>
#include <errno.h>

void clock_setup(void)
{
	rcc_clock_setup_in_hse_12mhz_out_72mhz();

	/* Enable GPIOA clock (for LED GPIOs). */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);

	/* Enable clocks for GPIO port A (for GPIO_USART2_TX) and USART2. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN |
				    RCC_APB2ENR_AFIOEN);
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);
}

void usart_setup(void)
{
	/* Setup GPIO pin GPIO_USART2_RE_TX on GPIO port B for transmit. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART2_TX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART2, 230400);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	usart_set_mode(USART2, USART_MODE_TX);

	/* Finally enable the USART. */
	usart_enable(USART2);
}

void gpio_setup(void)
{
	gpio_set(GPIOA, GPIO8);

	/* Setup GPIO8 (in GPIO port A) for LED use. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);
}

int _write(int file, char *ptr, int len)
{
	int i;

	if (file == 1) {
		for (i = 0; i < len; i++)
			usart_send_blocking(USART2, ptr[i]);
		return i;
	}

	errno = EIO;
	return -1;
}

int main(void)
{
	int counter = 0;
	float fcounter = 0.0;
	double dcounter = 0.0;

	clock_setup();
	gpio_setup();
	usart_setup();

	/*
	 * Write Hello World, an integer, float and double all over
	 * again while incrementing the numbers.
	 */
	while (1) {
		gpio_toggle(GPIOA, GPIO8);
		printf("Hello World! %i %f %f\r\n", counter, fcounter,
		       dcounter);
		counter++;
		fcounter += 0.01;
		dcounter += 0.01;
	}

	return 0;
}
