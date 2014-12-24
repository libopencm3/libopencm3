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

#ifndef SAM3X_UART_H
#define SAM3X_UART_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* --- The UART base addresses aren't named consistently between chips ---- */
#ifdef UART1_BASE
#define UART0	UART0_BASE
#define UART1	UART1_BASE
#else
#define UART0	UART_BASE
#endif

/* --- Universal Asynchronous Receiver Transmitter (UART) registers ------- */
#define UART_CR(x)			MMIO32((x) + 0x0000)
#define UART_MR(x)			MMIO32((x) + 0x0004)
#define UART_IER(x)				MMIO32((x) + 0x0008)
#define UART_IDR(x)				MMIO32((x) + 0x000C)
#define UART_IMR(x)				MMIO32((x) + 0x0010)
#define UART_SR(x)			MMIO32((x) + 0x0014)
#define UART_RHR(x)				MMIO32((x) + 0x0018)
#define UART_THR(x)				MMIO32((x) + 0x001C)
#define UART_BRGR(x)			MMIO32((x) + 0x0020)
/* 0x0024:0x003C - Reserved */
/* 0x004C:0x00FC - Reserved */
/* 0x0100:0x0124 - PDC Area */


/* UART Control Register (UART_CR) */
/* Bits [31:9] - Reserved */
#define UART_CR_RSTSTA			(0x01 << 8)
#define UART_CR_TXDIS			(0x01 << 7)
#define UART_CR_TXEN			(0x01 << 6)
#define UART_CR_RXDIS			(0x01 << 5)
#define UART_CR_RXEN			(0x01 << 4)
#define UART_CR_RSTTX			(0x01 << 3)
#define UART_CR_RSTRX			(0x01 << 2)
/* Bit [1:0] - Reserved */

/* UART Mode Register (UART_MR) */
/* Bits [31:16] - Reserved */
#define UART_MR_CHMODE_MASK		(0x03 << 14)
#define UART_MR_CHMODE_NORMAL		(0x00 << 14)
#define UART_MR_CHMODE_AUTOMATIC	(0x01 << 14)
#define UART_MR_CHMODE_LOCAL_LOOPBACK	(0x02 << 14)
#define UART_MR_CHMODE_REMOTE_LOOPBACK	(0x03 << 14)
/* Bits [13:12] - Reserved */
#define UART_MR_PAR_MASK		(0x07 << 9)
#define UART_MR_PAR_EVEN		(0x00 << 9)
#define UART_MR_PAR_ODD			(0x01 << 9)
#define UART_MR_PAR_SPACE		(0x02 << 9)
#define UART_MR_PAR_MARK		(0x03 << 9)
#define UART_MR_PAR_NO			(0x04 << 9)
/* Bits [8:0] - Reserved */

/* UART Status Register (UART_SR) */
/* Bits [31:13] - Reserved */
#define UART_SR_RXBUFF			(0x01 << 12)
#define UART_SR_TXBUFF			(0x01 << 11)
/* Bit [10] - Reserved */
#define UART_SR_TXEMPTY			(0x01 << 9)
/* Bit [8] - Reserved */
#define UART_SR_PARE			(0x01 << 7)
#define UART_SR_FRAME			(0x01 << 6)
#define UART_SR_OVRE			(0x01 << 5)
#define UART_SR_ENDTX			(0x01 << 4)
#define UART_SR_ENDRX			(0x01 << 3)
/* Bit [2] - Reserved */
#define UART_SR_TXRDY			(0x01 << 1)
#define UART_SR_RXRDY			(0x01 << 0)

/*********************************************************************
* UART enum
**********************************************************************/

/*
* UART Parity type definitions
*/
enum uart_parity {
	/* No parity */
	UART_PARITY_NONE = UART_MR_PAR_NO,
	/* Odd parity */
	UART_PARITY_ODD = UART_MR_PAR_ODD,
	/* Even parity */
	UART_PARITY_EVEN = UART_MR_PAR_EVEN,
	/* Forced 1 stick parity */
	UART_PARITY_SP_1 = UART_MR_PAR_MARK,
	/* Forced 0 stick parity */
	UART_PARITY_SP_0  = UART_MR_PAR_SPACE
};

/* UART mode definitions */
enum uart_mode {
	UART_MODE_DISABLED,
	UART_MODE_RX,
	UART_MODE_TX,
	UART_MODE_TX_RX,
};

BEGIN_DECLS


void uart_set_baudrate(uint32_t uart, uint32_t baud);
void uart_set_parity(uint32_t uart, enum uart_parity par);
void uart_set_mode(uint32_t uart, enum uart_mode mode);
void uart_enable(uint32_t uart);
void uart_disable(uint32_t uart);
void uart_send(uint32_t uart, uint8_t data);
void uart_send_blocking(uint32_t uart, uint8_t data);
uint8_t uart_recv(uint32_t uart);
uint8_t uart_recv_blocking(uint32_t uart);
void uart_enable_rx_interrupt(uint32_t uart);
void uart_disable_rx_interrupt(uint32_t uart);

END_DECLS


#endif

