/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2015 Daniele Lacamera <root at danielinux.net>
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

#include <libopencm3/lm3s/usart.h>


void usart_set_baudrate(uint32_t usart, uint32_t baud)
{
    /* TODO */
    (void)usart;
    (void)baud;
}

void usart_set_databits(uint32_t usart, int bits)
{
    /* TODO */
    (void)usart;
    (void)bits;
}

void usart_set_stopbits(uint32_t usart, enum usart_stopbits sb)
{
    /* TODO */
    (void)usart;
    (void)sb;
}

void usart_set_parity(uint32_t usart, enum usart_parity par)
{
    /* TODO */
    (void)usart;
    (void)par;
}

void usart_set_mode(uint32_t usart, enum usart_mode mode)
{
    /* TODO */
    (void)usart;
    (void)mode;
}

void usart_set_flow_control(uint32_t usart, enum usart_flowcontrol fc)
{
    /* TODO */
    (void)usart;
    (void)fc;
}

void usart_enable(uint32_t usart)
{
	(void)usart;
}

void usart_disable(uint32_t usart)
{
	(void)usart;
}

void usart_send(uint32_t usart, uint16_t data)
{
	USART_DR(usart) = data;
}

uint16_t usart_recv(uint32_t usart)
{
	return USART_DR(usart) & 0xff;
}

void usart_wait_send_ready(uint32_t usart)
{
	while ((USART_FR(usart) & USART_FR_TXFE) == 0);
}

void usart_wait_recv_ready(uint32_t usart)
{
	while ((USART_FR(usart) & USART_FR_RXFE) != 0);
}

void usart_send_blocking(uint32_t usart, uint16_t data)
{
	usart_wait_send_ready(usart);
	usart_send(usart, data);
}

bool usart_is_recv_ready(uint32_t usart)
{
	return((USART_FR(usart) & USART_FR_RXFE) == 0);
}

bool usart_is_send_ready(uint32_t usart)
{
	return((USART_FR(usart) & USART_FR_TXFE) != 0);
}

uint16_t usart_recv_blocking(uint32_t usart)
{
	usart_wait_recv_ready(usart);
	return usart_recv(usart);
}

void usart_enable_rx_interrupt(uint32_t usart)
{
	USART_IM(usart) |= USART_IM_RX;
}

void usart_enable_tx_interrupt(uint32_t usart)
{
	USART_IM(usart) |= USART_IM_TX;
}

void usart_disable_rx_interrupt(uint32_t usart)
{
	USART_IM(usart) &= (~USART_IM_RX);
}

void usart_disable_tx_interrupt(uint32_t usart)
{
	USART_IM(usart) &= (~USART_IM_TX);
}

void usart_clear_rx_interrupt(uint32_t usart)
{
	USART_IC(usart) |= USART_IC_RX;
}

void usart_clear_tx_interrupt(uint32_t usart)
{
	USART_IC(usart) |= USART_IC_TX;
}
