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
#include <libopencm3/cm3/nvic.h>

void clock_setup(void)
{
	rcc_clock_setup_in_hse_12mhz_out_72mhz();

	/* Enable GPIOA clock (for LED GPIOs). */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN);

	/* Enable clocks for GPIO port A (for GPIO_USART2_TX) and USART2. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN |
				    RCC_APB2ENR_AFIOEN);

	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);
}

void usart_setup(void)
{
	/* Enable the USART2 interrupt. */
	nvic_enable_irq(NVIC_USART2_IRQ);

	/* Setup GPIO pin GPIO_USART2_TX on GPIO port A for transmit. */
	gpio_set_mode(GPIO_BANK_USART2_TX, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART2_TX);

	/* Setup GPIO pin GPIO_USART2_RX on GPIO port A for receive. */
	gpio_set_mode(GPIO_BANK_USART2_RX, GPIO_MODE_INPUT,
		      GPIO_CNF_INPUT_FLOAT, GPIO_USART2_RX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART2, 230400);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	usart_set_mode(USART2, USART_MODE_TX_RX);

	/* Enable USART2 Receive interrupt. */
	USART_CR1(USART2) |= USART_CR1_RXNEIE;

	/* Finally enable the USART. */
	usart_enable(USART2);
}

void gpio_setup(void)
{
	gpio_set(GPIOA, GPIO8);

	/* Setup GPIO8 (in GPIO port A) for LED use. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);
	
	gpio_set(GPIOC, GPIO15);

	/* Setup GPIO15 (in GPIO port C) for LED use. */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO15);
}

void usart2_isr(void)
{
	static u8 data = 'A';

	/* Check if we were called because of RXNE. */
	if (((USART_CR1(USART2) & USART_CR1_RXNEIE) != 0) &&
	    ((USART_SR(USART2) & USART_SR_RXNE) != 0)) {

		/* Indicate that we got data. */
		gpio_toggle(GPIOA, GPIO8);

		/* Retrieve the data from the peripheral. */
		data = usart_recv(USART2);

		/* Enable transmit interrupt so it sends back the data. */
		USART_CR1(USART2) |= USART_CR1_TXEIE;
	}

	/* Check if we were called because of TXE. */
	if (((USART_CR1(USART2) & USART_CR1_TXEIE) != 0) &&
	    ((USART_SR(USART2) & USART_SR_TXE) != 0)) {

		/* Indicate that we are sending out data. */
		gpio_toggle(GPIOC, GPIO15);

		/* Put data into the transmit register. */
		usart_send(USART2, data);

		/* Disable the TXE interrupt as we don't need it anymore. */
		USART_CR1(USART2) &= ~USART_CR1_TXEIE;
	}
}

int main(void)
{
	clock_setup();
	gpio_setup();
	usart_setup();

	/* Wait forever and do nothing. */
	while (1)
		__asm__("nop");

	return 0;
}
