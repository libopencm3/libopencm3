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

#ifndef SAM3X_USART_H
#define SAM3X_USART_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

#define USART0		USART0_BASE
#define USART1		USART1_BASE
#define USART2		USART2_BASE
#define USART3		USART3_BASE

/* --- Universal Synchronous Asynchronous Receiver Transmitter (USART) */
#define USART_CR(x)			MMIO32((x) + 0x0000)
#define USART_MR(x)			MMIO32((x) + 0x0004)
#define USART_IER(x)			MMIO32((x) + 0x0008)
#define USART_IDR(x)			MMIO32((x) + 0x000C)
#define USART_IMR(x)			MMIO32((x) + 0x0010)
#define USART_CSR(x)			MMIO32((x) + 0x0014)
#define USART_RHR(x)			MMIO32((x) + 0x0018)
#define USART_THR(x)			MMIO32((x) + 0x001C)
#define USART_BRGR(x)			MMIO32((x) + 0x0020)
#define USART_RTOR(x)			MMIO32((x) + 0x0024)
#define USART_TTGR(x)			MMIO32((x) + 0x0028)
/* 0x002C:0x003C - Reserved */
#define USART_FIDI(x)			MMIO32((x) + 0x0040)
#define USART_NER(x)			MMIO32((x) + 0x0044)
#define USART_NER(x)			MMIO32((x) + 0x0044)
/* 0x0048 - Reserved */
#define USART_IF(x)			MMIO32((x) + 0x004C)
#define USART_MAN(x)			MMIO32((x) + 0x0050)
#define USART_LINMR(x)			MMIO32((x) + 0x0054)
#define USART_LINIR(x)			MMIO32((x) + 0x0058)
/* 0x005C:0x00E0 - Reserved */
#define USART_WPMR(x)			MMIO32((x) + 0x00E4)
#define USART_WPSR(x)			MMIO32((x) + 0x00E8)
/* 0x00EC:0x00F8 - Reserved */
#define USART_VERSION(x)		MMIO32((x) + 0x00FC)
/* 0x0100:0x0124 - PDC Area */


/* USART Control Register (USART_CR) */
/* Bits [31:22] - Reserved */
#define USART_CR_LINWKUP		(0x01 << 21)
#define USART_CR_LINABT			(0x01 << 20)
#define USART_CR_RTSDIS			(0x01 << 19)
#define USART_CR_RCS			(0x01 << 19)
#define USART_CR_RTSEN			(0x01 << 18)
#define USART_CR_FCS			(0x01 << 18)
/* Bits [17:16] - Reserved */
#define USART_CR_RETTO			(0x01 << 15)
#define USART_CR_RSTNACK		(0x01 << 14)
#define USART_CR_RSTIT			(0x01 << 13)
#define USART_CR_SENDA			(0x01 << 12)
#define USART_CR_STTTO			(0x01 << 11)
#define USART_CR_STPBRK			(0x01 << 10)
#define USART_CR_STTBRK			(0x01 << 9)
#define USART_CR_RSTSTA			(0x01 << 8)
#define USART_CR_TXDIS			(0x01 << 7)
#define USART_CR_TXEN			(0x01 << 6)
#define USART_CR_RXDIS			(0x01 << 5)
#define USART_CR_RXEN			(0x01 << 4)
#define USART_CR_RSTTX			(0x01 << 3)
#define USART_CR_RSTRX			(0x01 << 2)
/* Bits [1:0] - Reserved */

/* USART Mode Register (USART_MR) */
#define USART_MR_ONEBIT			(0x01 << 31)
#define USART_MR_MODSYNC		(0x01 << 30)
#define USART_MR_MAN			(0x01 << 29)
#define USART_MR_FILTER			(0x01 << 28)
/* Bit [27] - Reserved */
#define USART_MR_MAX_ITERATION_MASK	(0x07 << 24)
#define USART_MR_INVDATA		(0x01 << 23)
#define USART_MR_VAR_SYNC		(0x01 << 22)
#define USART_MR_DSNACK			(0x01 << 21)
#define USART_MR_INACK			(0x01 << 20)
#define USART_MR_OVER			(0x01 << 19)
#define USART_MR_CLKO			(0x01 << 18)
#define USART_MR_MODE9			(0x01 << 17)
#define USART_MR_MSBF			(0x01 << 16)
#define USART_MR_CPOL			(0x01 << 16)
#define USART_MR_CHMODE_MASK		(0x03 << 14)
#define USART_MR_CHMODE_NORMAL		(0x00 << 14)
#define USART_MR_CHMODE_AUTOMATIC	(0x01 << 14)
#define USART_MR_CHMODE_LOCAL_LOOPBACK	(0x02 << 14)
#define USART_MR_CHMODE_REMOTE_LOOPBACK	(0x03 << 14)
#define USART_MR_NBSTOP_MASK		(0x03 << 12)
#define USART_MR_NBSTOP_1_BIT		(0x00 << 12)
#define USART_MR_NBSTOP_1_5_BIT		(0x01 << 12)
#define USART_MR_NBSTOP_2_BIT		(0x02 << 12)
/* Bits [13:12] - Reserved */
#define USART_MR_PAR_MASK		(0x07 << 9)
#define USART_MR_PAR_EVEN		(0x00 << 9)
#define USART_MR_PAR_ODD		(0x01 << 9)
#define USART_MR_PAR_SPACE		(0x02 << 9)
#define USART_MR_PAR_MARK		(0x03 << 9)
#define USART_MR_PAR_NO			(0x04 << 9)
/* Bits [8:0] - Reserved */
#define USART_MR_SYNC			(0x01 << 8)
#define USART_MR_CPHA			(0x01 << 8)
#define USART_MR_CHRL_MASK		(0x03 << 6)
#define USART_MR_CHRL_5BIT		(0x00 << 6)
#define USART_MR_CHRL_6BIT		(0x01 << 6)
#define USART_MR_CHRL_7BIT		(0x02 << 6)
#define USART_MR_CHRL_8BIT		(0x03 << 6)
#define USART_MR_USCLKS_MASK		(0x03 << 4)
#define USART_MR_USCLKS_MCK		(0x00 << 4)
#define USART_MR_USCLKS_DIV		(0x01 << 4)
#define USART_MR_USCLKS_SCK		(0x03 << 4)
#define USART_MR_MODE_MASK		(0x0F << 0)
#define USART_MR_MODE_NORMAL		(0x00 << 0)
#define USART_MR_MODE_RS485		(0x01 << 0)
#define USART_MR_MODE_HW_HANDSHAKING	(0x02 << 0)
#define USART_MR_MODE_ISO7816_T_0	(0x03 << 0)
#define USART_MR_MODE_ISO7816_T_1	(0x04 << 0)
#define USART_MR_MODE_IRDA		(0x06 << 0)
#define USART_MR_MODE_LIN_MASTER	(0x0A << 0)
#define USART_MR_MODE_LIN_SLAVE		(0x0B << 0)
#define USART_MR_MODE_SPI_MASTER	(0x0E << 0)
#define USART_MR_MODE_SPI_SLAVE		(0x0F << 0)

/* USART Status Register (USART_CSR) */
/* Bits [31:30] - Reserved */
#define USART_CSR_LINSNRE		(0x01 << 29)
#define USART_CSR_LINCE			(0x01 << 28)
#define USART_CSR_LINIPE		(0x01 << 27)
#define USART_CSR_LINSFE		(0x01 << 26)
#define USART_CSR_LINBE			(0x01 << 25)
#define USART_CSR_MANERR		(0x01 << 24)
#define USART_CSR_CTS			(0x01 << 23)
#define USART_CSR_LINBLS		(0x01 << 23)
/* Bits [22:20] - Reserved */
#define USART_CSR_CTSIC			(0x01 << 19)
/* Bits [18:16] - Reserved */
#define USART_CSR_LINTC			(0x01 << 15)
#define USART_CSR_LINID			(0x01 << 14)
#define USART_CSR_NACK			(0x01 << 13)
#define USART_CSR_LINBK			(0x01 << 13)
#define USART_CSR_RXBUFF		(0x01 << 12)
#define USART_CSR_TXBUFE		(0x01 << 11)
/* Bit [10] - Reserved */
#define USART_CSR_TXEMPTY		(0x01 << 9)
/* Bit [8] - Reserved */
#define USART_CSR_PARE			(0x01 << 7)
#define USART_CSR_FRAME			(0x01 << 6)
#define USART_CSR_OVRE			(0x01 << 5)
#define USART_CSR_ENDTX			(0x01 << 4)
#define USART_CSR_ENDRX			(0x01 << 3)
/* Bit [2] - Reserved */
#define USART_CSR_TXRDY			(0x01 << 1)
#define USART_CSR_RXRDY			(0x01 << 0)

enum usart_stopbits {
	USART_STOPBITS_1,
	USART_STOPBITS_1_5,
	USART_STOPBITS_2,
};

enum usart_parity {
	USART_PARITY_EVEN,
	USART_PARITY_ODD,
	USART_PARITY_SPACE,
	USART_PARITY_MARK,
	USART_PARITY_NONE,
	USART_PARITY_MULTIDROP,
};

enum usart_mode {
	USART_MODE_DISABLED,
	USART_MODE_RX,
	USART_MODE_TX,
	USART_MODE_TX_RX,
};

enum usart_flowcontrol {
	USART_FLOWCONTROL_NONE,
	USART_FLOWCONTROL_RTS_CTS,
};

void usart_set_baudrate(uint32_t usart, uint32_t baud);
void usart_set_databits(uint32_t usart, int bits);
void usart_set_stopbits(uint32_t usart, enum usart_stopbits);
void usart_set_parity(uint32_t usart, enum usart_parity);
void usart_set_mode(uint32_t usart, enum usart_mode);
void usart_set_flow_control(uint32_t usart, enum usart_flowcontrol);
void usart_enable(uint32_t usart);
void usart_disable(uint32_t usart);
void usart_send(uint32_t usart, uint16_t data);
uint16_t usart_recv(uint32_t usart);
void usart_wait_send_ready(uint32_t usart);
void usart_wait_recv_ready(uint32_t usart);
void usart_send_blocking(uint32_t usart, uint16_t data);
uint16_t usart_recv_blocking(uint32_t usart);
void usart_enable_rx_interrupt(uint32_t usart);
void usart_disable_rx_interrupt(uint32_t usart);

#endif

