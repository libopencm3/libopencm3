/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Daniele Lacamera <root at danielinux dot net>
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

#ifndef LM3S_USART_H
#define LM3S_USART_H

#include <libopencm3/cm3/common.h>



#define USART0_BASE        0x4000C000
#define USART1_BASE        0x4000D000
#define USART2_BASE        0x4000E000

/* --- Universal Synchronous Asynchronous Receiver Transmitter (USART) */
#define USART_DR(x)             MMIO32((x) + 0x0000)
#define USART_IR(x)             MMIO32((x) + 0x0004)
#define USART_FR(x)             MMIO32((x) + 0x0018)
#define USART_ILPR(x)           MMIO32((x) + 0x0020)
#define USART_IBRD(x)           MMIO32((x) + 0x0024)
#define USART_FBRD(x)           MMIO32((x) + 0x0028)
#define USART_LCRH(x)           MMIO32((x) + 0x002c)
#define USART_CTL(x)            MMIO32((x) + 0x0030)
#define USART_IFLS(x)           MMIO32((x) + 0x0034)
#define USART_IM(x)             MMIO32((x) + 0x0038)
#define USART_RIS(x)            MMIO32((x) + 0x003c)
#define USART_MIS(x)            MMIO32((x) + 0x0040)
#define USART_IC(x)             MMIO32((x) + 0x0044)

/* USART Data Register (USART_DR) */
/* Bits [31:12] - Reserved */
#define USART_DR_OE             (0x01 << 11)
#define USART_DR_BE             (0x01 << 10)
#define USART_DR_PE             (0x01 << 9)
#define USART_DR_FE             (0x01 << 8)

/* USART Flags Register (USART_FR) */
/* Bits [31:8] - Reserved */
#define USART_FR_TXFE            (0x01 << 7)
#define USART_FR_RXFF            (0x01 << 6)
#define USART_FR_TXFF            (0x01 << 5)
#define USART_FR_RXFE            (0x01 << 4)
#define USART_FR_BUSY            (0x01 << 3)
/* Bits [2:0] - Reserved */

/* USART Interrupt Mask Register (USART_IM) */
/* Bits [31:11] - Reserved */
#define USART_IM_OE             (0x01 << 10)
#define USART_IM_BE             (0x01 << 9)
#define USART_IM_PE             (0x01 << 8)
#define USART_IM_FE             (0x01 << 7)
#define USART_IM_RT             (0x01 << 6)
#define USART_IM_TX             (0x01 << 5)
#define USART_IM_RX             (0x01 << 4)
/* Bits [3:0] - Reserved */

/* USART Interrupt Clear Register (USART_IC) */
/* Bits [31:11] - Reserved */
#define USART_IC_OE             (0x01 << 10)
#define USART_IC_BE             (0x01 << 9)
#define USART_IC_PE             (0x01 << 8)
#define USART_IC_FE             (0x01 << 7)
#define USART_IC_RT             (0x01 << 6)
#define USART_IC_TX             (0x01 << 5)
#define USART_IC_RX             (0x01 << 4)
/* Bits [3:0] - Reserved */

enum usart_stopbits {
	USART_STOPBITS_1,
	USART_STOPBITS_1_5,
	USART_STOPBITS_2,
};

enum usart_parity {
	USART_PARITY_NONE,
	USART_PARITY_ODD,
	USART_PARITY_EVEN,
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

void usart_send(uint32_t usart, uint16_t data);
uint16_t usart_recv(uint32_t usart);
bool usart_is_send_ready(uint32_t usart);
bool usart_is_recv_ready(uint32_t usart);
void usart_send_blocking(uint32_t usart, uint16_t data);
uint16_t usart_recv_blocking(uint32_t usart);
void usart_enable_rx_interrupt(uint32_t usart);
void usart_disable_rx_interrupt(uint32_t usart);
void usart_clear_rx_interrupt(uint32_t usart);
void usart_enable_tx_interrupt(uint32_t usart);
void usart_disable_tx_interrupt(uint32_t usart);
void usart_clear_tx_interrupt(uint32_t usart);
bool usart_get_interrupt_source(uint32_t usart, uint32_t flag);

#endif

