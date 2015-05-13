/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Owen Kirby <oskirby@gmail.com>
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

#include <libopencm3/sam/uart.h>
#include <libopencm3/sam/pmc.h>

void uart_set_baudrate(uint32_t uart, uint32_t baud)
{
	UART_BRGR(uart) = pmc_mck_frequency / (16 * baud);
}

void uart_set_parity(uint32_t uart, enum uart_parity par)
{
	UART_MR(uart) = (UART_MR(uart) & ~UART_MR_PAR_MASK) | (par << 9);
}

void uart_set_mode(uint32_t uart, enum uart_mode mode)
{
	UART_CR(uart) = (mode & UART_MODE_RX) ? UART_CR_RXEN : UART_CR_RXDIS;
	UART_CR(uart) = (mode & UART_MODE_TX) ? UART_CR_TXEN : UART_CR_TXDIS;
}

void uart_enable(uint32_t uart)
{
	(void)uart;
}

void uart_disable(uint32_t uart)
{
	(void)uart;
}

void uart_send(uint32_t uart, uint8_t data)
{
	UART_THR(uart) = data;
}

void uart_send_blocking(uint32_t uart, uint8_t data)
{
	while (!(UART_SR(uart) & UART_SR_TXRDY));
	uart_send(uart, data);
}

uint8_t uart_recv(uint32_t uart)
{
	return UART_RHR(uart) & 0xff;
}

uint8_t uart_recv_blocking(uint32_t uart)
{
	while (!(UART_SR(uart) & UART_SR_RXRDY));
	return uart_recv(uart);
}

void uart_enable_rx_interrupt(uint32_t uart)
{
	UART_IER(uart) = UART_SR_RXRDY;
}

void uart_disable_rx_interrupt(uint32_t uart)
{
	UART_IDR(uart) = UART_SR_RXRDY;
}

