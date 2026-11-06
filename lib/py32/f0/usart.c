/*
 * This file is part of the libopencm3 project.
 *
 * PY32F0xx USART implementation (STM32F1-style USART v1 register layout).
 *
 * Licensed under the GNU LGPL v3 or later.
 */

#include <libopencm3/py32/usart.h>
#include <libopencm3/py32/rcc.h>

void usart_set_baudrate(uint32_t usart, uint32_t baud)
{
	/* Both USART1 and USART2 use the APB clock (which equals AHB on PY32F0). */
	uint32_t clock = rcc_apb_frequency;
	/* USARTDIV = fck / baud, written as a 16-bit value with 12-bit mantissa
	 * (bits 15..4) and 4-bit fraction (bits 3..0), oversampling by 16. */
	uint32_t usartdiv = (clock + (baud / 2U)) / baud;
	USART_BRR(usart) = usartdiv;
}

void usart_set_databits(uint32_t usart, uint32_t bits)
{
	if (bits == 9) {
		USART_CR1(usart) |= USART_CR1_M;
	} else {
		USART_CR1(usart) &= ~USART_CR1_M;
	}
}

void usart_set_stopbits(uint32_t usart, uint32_t stopbits)
{
	uint32_t cr2 = USART_CR2(usart);
	cr2 &= ~(USART_CR2_STOP_MASK << USART_CR2_STOP_SHIFT);
	cr2 |= (stopbits & USART_CR2_STOP_MASK) << USART_CR2_STOP_SHIFT;
	USART_CR2(usart) = cr2;
}

void usart_set_parity(uint32_t usart, uint32_t parity)
{
	uint32_t cr1 = USART_CR1(usart);
	cr1 &= ~(USART_CR1_PCE | USART_CR1_PS);
	cr1 |= parity;
	USART_CR1(usart) = cr1;
}

void usart_set_mode(uint32_t usart, uint32_t mode)
{
	uint32_t cr1 = USART_CR1(usart);
	cr1 &= ~(USART_CR1_RE | USART_CR1_TE);
	cr1 |= mode;
	USART_CR1(usart) = cr1;
}

void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol)
{
	uint32_t cr3 = USART_CR3(usart);
	cr3 &= ~((1U << 8) | (1U << 9));
	cr3 |= flowcontrol;
	USART_CR3(usart) = cr3;
}

void usart_enable(uint32_t usart)
{
	USART_CR1(usart) |= USART_CR1_UE;
}

void usart_disable(uint32_t usart)
{
	USART_CR1(usart) &= ~USART_CR1_UE;
}

void usart_send(uint32_t usart, uint16_t data)
{
	USART_DR(usart) = data & 0x1FFU;
}

uint16_t usart_recv(uint32_t usart)
{
	return USART_DR(usart) & 0x1FFU;
}

void usart_send_blocking(uint32_t usart, uint16_t data)
{
	while (!(USART_SR(usart) & USART_SR_TXE)) {
		/* spin */
	}
	usart_send(usart, data);
}

uint16_t usart_recv_blocking(uint32_t usart)
{
	while (!(USART_SR(usart) & USART_SR_RXNE)) {
		/* spin */
	}
	return usart_recv(usart);
}

void usart_enable_rx_interrupt(uint32_t usart)
{
	USART_CR1(usart) |= USART_CR1_RXNEIE;
}

void usart_disable_rx_interrupt(uint32_t usart)
{
	USART_CR1(usart) &= ~USART_CR1_RXNEIE;
}

void usart_enable_tx_interrupt(uint32_t usart)
{
	USART_CR1(usart) |= USART_CR1_TXEIE;
}

void usart_disable_tx_interrupt(uint32_t usart)
{
	USART_CR1(usart) &= ~USART_CR1_TXEIE;
}

bool usart_get_flag(uint32_t usart, uint32_t flag)
{
	return (USART_SR(usart) & flag) != 0;
}
