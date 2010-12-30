/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <stm32/usart.h>

void usart_set_baudrate(u32 usart, u32 baud)
{
	u32 clock = 72000000; /* FIXME: Don't hardcode this clock! */

	/* TODO: Document and explain calculation. */
	USART_BRR(usart) = (u16)((clock << 4) / (baud * 16));
}

void usart_set_databits(u32 usart, u32 bits)
{
	if (bits == 8)
		USART_CR1(usart) &= ~USART_CR1_M; /* 8 data bits */
	else
		USART_CR1(usart) |= USART_CR1_M;  /* 9 data bits */
}

void usart_set_stopbits(u32 usart, u32 stopbits)
{
	u32 reg32;

	reg32 = USART_CR2(usart);
	reg32 = (reg32 & ~USART_CR2_STOPBITS_MASK) | stopbits;
	USART_CR2(usart) = reg32;
}

void usart_set_parity(u32 usart, u32 parity)
{
	u32 reg32;

	reg32 = USART_CR1(usart);
	reg32 = (reg32 & ~USART_PARITY_MASK) | parity;
	USART_CR1(usart) = reg32;
}

void usart_set_mode(u32 usart, u32 mode)
{
	u32 reg32;

	reg32 = USART_CR1(usart);
	reg32 = (reg32 & ~USART_MODE_MASK) | mode;
	USART_CR1(usart) = reg32;
}

void usart_set_flow_control(u32 usart, u32 flowcontrol)
{
	u32 reg32;

	reg32 = USART_CR3(usart);
	reg32 = (reg32 & ~USART_FLOWCONTROL_MASK) | flowcontrol;
	USART_CR3(usart) = reg32;
}

void usart_enable(u32 usart)
{
	USART_CR1(usart) |= USART_CR1_UE;
}

void usart_disable(u32 usart)
{
	USART_CR1(usart) &= ~USART_CR1_UE;
}

void usart_send(u32 usart, u16 data)
{
	/* Send data. */
	USART_DR(usart) = (data & USART_DR_MASK);
}

u16 usart_recv(u32 usart)
{
	/* Receive data. */
	return USART_DR(usart) & USART_DR_MASK;
}

void usart_wait_send_ready(u32 usart)
{
	/* Wait until the data has been transferred into the shift register. */
	while ((USART_SR(usart) & USART_SR_TXE) == 0);
}

void usart_wait_recv_ready(u32 usart)
{
	/* Wait until the data is ready to be received. */
	while ((USART_SR(usart) & USART_SR_RXNE) == 0);
}

void usart_send_blocking(u32 usart, u16 data)
{
	usart_send(usart, data);

	usart_wait_send_ready(usart);
}

u16 usart_recv_blocking(u32 usart)
{
	usart_wait_recv_ready(usart);

	return usart_recv(usart);
}
