/*
 * This file is part of the libopenstm32 project.
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

#ifndef LIBOPENSTM32_USART_H
#define LIBOPENSTM32_USART_H

#include <libopenstm32.h>

/* --- USART registers ----------------------------------------------------- */

/* Status register (USARTx_SR) */
#define USART_SR(usart_base)		MMIO32(usart_base + 0x00)
#define USART1_SR			USART_SR(USART1_BASE)
#define USART2_SR			USART_SR(USART2_BASE)
#define USART3_SR			USART_SR(USART3_BASE)
#define UART4_SR			USART_SR(UART4_BASE)
#define UART5_SR			USART_SR(UART5_BASE)

/* Data register (USARTx_DR) */
#define USART_DR(usart_base)		MMIO32(usart_base + 0x04)
#define USART1_DR			USART_DR(USART1_BASE)
#define USART2_DR			USART_DR(USART2_BASE)
#define USART3_DR			USART_DR(USART3_BASE)
#define UART4_DR			USART_DR(UART4_BASE)
#define UART5_DR			USART_DR(UART5_BASE)

/* Baud rate register (USARTx_BRR) */
#define USART_BRR(usart_base)		MMIO32(usart_base + 0x08)
#define USART1_BRR			USART_BRR(USART1_BASE)
#define USART2_BRR			USART_BRR(USART2_BASE)
#define USART3_BRR			USART_BRR(USART3_BASE)
#define UART4_BRR			USART_BRR(UART4_BASE)
#define UART5_BRR			USART_BRR(UART5_BASE)

/* Control register 1 (USARTx_CR1) */
#define USART_CR1(usart_base)		MMIO32(usart_base + 0x0c)
#define USART1_CR1			USART_CR1(USART1_BASE)
#define USART2_CR1			USART_CR1(USART2_BASE)
#define USART3_CR1			USART_CR1(USART3_BASE)
#define UART4_CR1			USART_CR1(UART4_BASE)
#define UART5_CR1			USART_CR1(UART5_BASE)

/* Control register 2 (USARTx_CR2) */
#define USART_CR2(usart_base)		MMIO32(usart_base + 0x10)
#define USART1_CR2			USART_CR2(USART1_BASE)
#define USART2_CR2			USART_CR2(USART2_BASE)
#define USART3_CR2			USART_CR2(USART3_BASE)
#define UART4_CR2			USART_CR2(UART4_BASE)
#define UART5_CR2			USART_CR2(UART5_BASE)

/* Control register 3 (USARTx_CR3) */
#define USART_CR3(usart_base)		MMIO32(usart_base + 0x14)
#define USART1_CR3			USART_CR3(USART1_BASE)
#define USART2_CR3			USART_CR3(USART2_BASE)
#define USART3_CR3			USART_CR3(USART3_BASE)
#define UART4_CR3			USART_CR3(UART4_BASE)
#define UART5_CR3			USART_CR3(UART5_BASE)

/* Guard time and prescaler register (USARTx_GTPR) */
#define USART_GTPR(usart_base)		MMIO32(usart_base + 0x18)
#define USART1_GTPR			USART_GTPR(USART1_BASE)
#define USART2_GTPR			USART_GTPR(USART2_BASE)
#define USART3_GTPR			USART_GTPR(USART3_BASE)
#define UART4_GTPR			USART_GTPR(UART4_BASE)
#define UART5_GTPR			USART_GTPR(UART5_BASE)

/* --- USART_SR values ----------------------------------------------------- */

#define SR_CTS				(1 << 9) /* N/A on UART4/5 */
#define SR_LBD				(1 << 8)
#define SR_TXE				(1 << 7)
#define SR_TC				(1 << 6)
#define SR_RXNE				(1 << 5)
#define SR_IDLE				(1 << 4)
#define SR_ORE				(1 << 3)
#define SR_NE				(1 << 2)
#define SR_FE				(1 << 1)
#define SR_PE				(1 << 0)

/* --- USART_DR values ----------------------------------------------------- */

/* USART_DR[8:0]: DR[8:0]: Data value */

/* --- USART_BRR values ---------------------------------------------------- */

/* USART_BRR[15:4]: DIV_Mantissa[11:0]: mantissa of USARTDIV */
/* USART_BRR[3:0]: DIV_Fraction[3:0]: fraction of USARTDIV */

/* --- USART_CR1 values ---------------------------------------------------- */

#define CR1_UE				(1 << 13)
#define CR1_M				(1 << 12)
#define CR1_WAKE			(1 << 11)
#define CR1_PCE				(1 << 10)
#define CR1_PS				(1 << 9)
#define CR1_PEIE			(1 << 8)
#define CR1_TXEIE			(1 << 7)
#define CR1_TCIE			(1 << 6)
#define CR1_RXNEIE			(1 << 5)
#define CR1_IDLEIE			(1 << 4)
#define CR1_TE				(1 << 3)
#define CR1_RE				(1 << 2)
#define CR1_RWU				(1 << 1)
#define CR1_SBK				(1 << 0)

/* --- USART_CR2 values ---------------------------------------------------- */

#define CR2_LINEN			(1 << 14) /* LIN mode enable */
/* USART_CR2[13:12]: STOP */
#define CR2_CLKEN			(1 << 11) /* Clock enable */
#define CR2_CPOL			(1 << 10) /* Clock polarity */
#define CR2_CPHA			(1 << 9)  /* Clock phase */
#define CR2_LBCL			(1 << 8)  /* Last bit clock pulse */
#define CR2_LBDIE			(1 << 6)  /* LIN break det. int. en. */
#define CR2_LBDL			(1 << 5)  /* LIN break det. length */
/* USART_CR2[3:0]: ADD */

#define CR2_STOPBITS_1			0x00      /* 1 stop bit */
#define CR2_STOPBITS_0_5		0x01      /* 0.5 stop bits */
#define CR2_STOPBITS_2			0x02      /* 2 stop bits */
#define CR2_STOPBITS_1_5		0x03      /* 1.5 stop bits */

/* --- USART_CR3 values ---------------------------------------------------- */

#define CR3_CTSIE			(1 << 10) /* CTS interrupt enable */
#define CR3_CTSE			(1 << 9)  /* CTS enable */
#define CR3_RTSE			(1 << 8)  /* RTS enable */
#define CR3_DMAT			(1 << 7)  /* DMA enable transmitter */
#define CR3_DMAR			(1 << 6)  /* DMA enable receiver */
#define CR3_SCEN			(1 << 5)  /* Smartcard mode enable */
#define CR3_NACK			(1 << 4)  /* Smartcard NACK enable */
#define CR3_HDSEL			(1 << 3)  /* Half-duplex selection */
#define CR3_IRLP			(1 << 2)  /* IrDA low-power */
#define CR3_IREN			(1 << 1)  /* IrDA mode enable */
#define CR3_EIE				(1 << 0)  /* Error interrupt enable */

/* --- USART_GTPR values --------------------------------------------------- */

/* USART_GTPR[15:8]: GT[7:0]: Guard time value */   /* N/A on UART4/5 */
/* USART_GTPR[7:0]: PSC[7:0]: Prescaler value */    /* N/A on UART4/5 */

/* TODO */

#endif
