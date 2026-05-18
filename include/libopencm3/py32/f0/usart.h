/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2026 libopencm3 project
 *
 * PY32F0xx USART definitions.
 *
 * The PY32F0xx USART uses the legacy ST USART v1 register layout
 * (SR/DR/BRR/CR1/CR2/CR3/GTPR), the same one used by the STM32F1.
 *
 * Licensed under the GNU LGPL v3 or later.
 */

#ifndef LIBOPENCM3_PY32F0_USART_H
#define LIBOPENCM3_PY32F0_USART_H

#include <libopencm3/py32/memorymap.h>
#include <libopencm3/cm3/common.h>

#define USART1				USART1_BASE
#define USART2				USART2_BASE

/* --- USART registers ---------------------------------------------------- */
#define USART_SR(usart)			MMIO32((usart) + 0x00)
#define USART_DR(usart)			MMIO32((usart) + 0x04)
#define USART_BRR(usart)		MMIO32((usart) + 0x08)
#define USART_CR1(usart)		MMIO32((usart) + 0x0C)
#define USART_CR2(usart)		MMIO32((usart) + 0x10)
#define USART_CR3(usart)		MMIO32((usart) + 0x14)
#define USART_GTPR(usart)		MMIO32((usart) + 0x18)

/* --- USART_SR ----------------------------------------------------------- */
#define USART_SR_PE			(1 << 0)
#define USART_SR_FE			(1 << 1)
#define USART_SR_NE			(1 << 2)
#define USART_SR_ORE			(1 << 3)
#define USART_SR_IDLE			(1 << 4)
#define USART_SR_RXNE			(1 << 5)
#define USART_SR_TC			(1 << 6)
#define USART_SR_TXE			(1 << 7)
#define USART_SR_CTS			(1 << 9)

/* --- USART_CR1 ---------------------------------------------------------- */
#define USART_CR1_SBK			(1 << 0)
#define USART_CR1_RWU			(1 << 1)
#define USART_CR1_RE			(1 << 2)
#define USART_CR1_TE			(1 << 3)
#define USART_CR1_IDLEIE		(1 << 4)
#define USART_CR1_RXNEIE		(1 << 5)
#define USART_CR1_TCIE			(1 << 6)
#define USART_CR1_TXEIE			(1 << 7)
#define USART_CR1_PEIE			(1 << 8)
#define USART_CR1_PS			(1 << 9)
#define USART_CR1_PCE			(1 << 10)
#define USART_CR1_WAKE			(1 << 11)
#define USART_CR1_M			(1 << 12)
#define USART_CR1_UE			(1 << 13)

/* --- USART_CR2 ---------------------------------------------------------- */
#define USART_CR2_STOP_SHIFT		12
#define USART_CR2_STOP_MASK		0x3
#define USART_CR2_STOPBITS_1		0x0
#define USART_CR2_STOPBITS_2		0x2

/* --- Word length (CR1.M) ------------------------------------------------ */
#define USART_DATABITS_8		0
#define USART_DATABITS_9		USART_CR1_M

/* --- Parity (CR1.PCE / PS) ---------------------------------------------- */
#define USART_PARITY_NONE		0
#define USART_PARITY_EVEN		USART_CR1_PCE
#define USART_PARITY_ODD		(USART_CR1_PCE | USART_CR1_PS)

/* --- Mode (CR1.TE / RE) ------------------------------------------------- */
#define USART_MODE_RX			USART_CR1_RE
#define USART_MODE_TX			USART_CR1_TE
#define USART_MODE_TX_RX		(USART_CR1_RE | USART_CR1_TE)

/* --- Flow control (CR3) ------------------------------------------------- */
#define USART_FLOWCONTROL_NONE		0
#define USART_FLOWCONTROL_RTS		(1 << 8)
#define USART_FLOWCONTROL_CTS		(1 << 9)
#define USART_FLOWCONTROL_RTS_CTS	((1 << 8) | (1 << 9))

BEGIN_DECLS

void usart_set_baudrate(uint32_t usart, uint32_t baud);
void usart_set_databits(uint32_t usart, uint32_t bits);
void usart_set_stopbits(uint32_t usart, uint32_t stopbits);
void usart_set_parity(uint32_t usart, uint32_t parity);
void usart_set_mode(uint32_t usart, uint32_t mode);
void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol);
void usart_enable(uint32_t usart);
void usart_disable(uint32_t usart);

void usart_send(uint32_t usart, uint16_t data);
uint16_t usart_recv(uint32_t usart);
void usart_send_blocking(uint32_t usart, uint16_t data);
uint16_t usart_recv_blocking(uint32_t usart);

void usart_enable_rx_interrupt(uint32_t usart);
void usart_disable_rx_interrupt(uint32_t usart);
void usart_enable_tx_interrupt(uint32_t usart);
void usart_disable_tx_interrupt(uint32_t usart);

bool usart_get_flag(uint32_t usart, uint32_t flag);

END_DECLS

#endif
