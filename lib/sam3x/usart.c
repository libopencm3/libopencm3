/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Gareth McMullin <gareth@blacksphere.co.nz>
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

#include <libopencm3/sam3x/usart.h>
#include <libopencm3/sam3x/pmc.h>

void usart_set_baudrate(u32 usart, u32 baud)
{
	USART_BRGR(usart) = pmc_mck_frequency / (16 * baud);
}

void usart_set_databits(u32 usart, int bits)
{
	USART_MR(usart) = (USART_MR(usart) & ~USART_MR_CHRL_MASK) |
			((bits - 5) << 6);
}

void usart_set_stopbits(u32 usart, enum usart_stopbits sb)
{
	USART_MR(usart) = (USART_MR(usart) & ~USART_MR_NBSTOP_MASK) |
			(sb << 12);
}

void usart_set_parity(u32 usart, enum usart_parity par)
{
	USART_MR(usart) = (USART_MR(usart) & ~USART_MR_PAR_MASK) | (par << 9);
}

void usart_set_mode(u32 usart, enum usart_mode mode)
{
	USART_CR(usart) =
		(mode & USART_MODE_RX) ? USART_CR_RXEN : USART_CR_RXDIS;
	USART_CR(usart) =
		(mode & USART_MODE_TX) ? USART_CR_TXEN : USART_CR_TXDIS;
}

void usart_set_flow_control(u32 usart, enum usart_flowcontrol fc)
{
	USART_MR(usart) = (USART_MR(usart) & ~USART_MR_MODE_MASK) |
			(fc ? USART_MR_MODE_HW_HANDSHAKING : 0);
}

void usart_enable(u32 usart)
{
}

void usart_disable(u32 usart)
{
}

void usart_send(u32 usart, u16 data)
{
	USART_THR(usart) = data;
}

u16 usart_recv(u32 usart)
{
	return USART_RHR(usart) & 0x1f;
}

void usart_wait_send_ready(u32 usart)
{
	while ((USART_CSR(usart) & USART_CSR_TXRDY) == 0);
}

void usart_wait_recv_ready(u32 usart)
{
	while ((USART_CSR(usart) & USART_CSR_RXRDY) == 0);
}

void usart_send_blocking(u32 usart, u16 data)
{
	usart_wait_send_ready(usart);
	usart_send(usart, data);
}

u16 usart_recv_blocking(u32 usart)
{
	usart_wait_recv_ready(usart);

	return usart_recv(usart);
}

void usart_enable_rx_interrupt(u32 usart)
{
	USART_IER(usart) = USART_CSR_RXRDY;
}

void usart_disable_rx_interrupt(u32 usart)
{
	USART_IDR(usart) = USART_CSR_RXRDY;
}

