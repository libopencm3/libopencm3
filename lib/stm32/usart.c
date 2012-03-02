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

#include <libopencm3/stm32/usart.h>

#if defined(STM32F1)
#	include <libopencm3/stm32/f1/rcc.h>
#elif defined(STM32F2)
#	include <libopencm3/stm32/f2/rcc.h>
#elif defined(STM32F4)
#	include <libopencm3/stm32/f4/rcc.h>
#else
#	error "stm32 family not defined."
#endif

void usart_set_baudrate(u32 usart, u32 baud)
{
	u32 clock = rcc_ppre1_frequency;

//#ifdef STM32F1
	if (usart == USART1) {
		clock = rcc_ppre2_frequency;
	}
/* This has to be added for F2 when it get's support for USART6 */
/*
#else
	if ((usart == USART1) ||
	    (usart == USART6)) {
		clock = rcc_ppre2_frequency;
	}
#endif
*/

	/*
	 * Yes it is as simple as that. The reference manual is
	 * talking about fractional calculation but it seems to be only
	 * marketting babble to sound awesome. It is nothing else but a
	 * simple divider to generate the correct baudrate.
	 *
	 * Note: We round() the value rather than floor()ing it, for more
	 * accurate divisor selection.
	 */
	USART_BRR(usart) = ((2 * clock) + baud) / (2 * baud);
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
	usart_wait_send_ready(usart);
	usart_send(usart, data);
}

u16 usart_recv_blocking(u32 usart)
{
	usart_wait_recv_ready(usart);

	return usart_recv(usart);
}

void usart_enable_rx_dma(u32 usart)
{
	USART_CR3(usart) |= USART_CR3_DMAR;
}

void usart_disable_rx_dma(u32 usart)
{
	USART_CR3(usart) &= ~USART_CR3_DMAR;
}

void usart_enable_tx_dma(u32 usart)
{
	USART_CR3(usart) |= USART_CR3_DMAT;
}

void usart_disable_tx_dma(u32 usart)
{
	USART_CR3(usart) &= ~USART_CR3_DMAT;
}
