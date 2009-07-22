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

#define USART_SR			MMIO32(USART_BASE + 0x00)
#define USART_DR			MMIO32(USART_BASE + 0x04)
#define USART_BRR			MMIO32(USART_BASE + 0x08)
#define USART_CR1			MMIO32(USART_BASE + 0x0c)
#define USART_CR2			MMIO32(USART_BASE + 0x10)
#define USART_CR3			MMIO32(USART_BASE + 0x14)
#define USART_GTPR			MMIO32(USART_BASE + 0x18)

/* --- RCC_SR values ------------------------------------------------------- */

#define SR_CTS				(1 << 9)
#define SR_LBD				(1 << 8)
#define SR_TXE				(1 << 7)
#define SR_TC				(1 << 6)
#define SR_RXNE				(1 << 5)
#define SR_IDLE				(1 << 4)
#define SR_ORE				(1 << 3)
#define SR_NE				(1 << 2)
#define SR_FE				(1 << 1)
#define SR_PE				(1 << 0)

/* --- RCC_DR values ------------------------------------------------------- */

/* DR[8:0]: Data value */

/* --- RCC_BRR values ------------------------------------------------------ */

/* TODO */

/* --- RCC_CR1 values ------------------------------------------------------ */

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

/* --- RCC_CR2 values ------------------------------------------------------ */

/* TODO */

/* --- RCC_CR3 values ------------------------------------------------------ */

/* TODO */

/* --- RCC_GTPR values ----------------------------------------------------- */

/* TODO */

#endif
