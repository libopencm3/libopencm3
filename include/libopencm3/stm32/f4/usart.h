/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
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

#ifndef LIBOPENCM3_USART_F4_H
#define LIBOPENCM3_USART_F4_H

#include <libopencm3/stm32/usart.h>

/* --- Convenience macros -------------------------------------------------- */

#define USART6				USART6_BASE

/* --- USART registers ----------------------------------------------------- */

/* Status register (USARTx_SR) */
#define USART6_SR			USART_SR(USART6_BASE)

/* Data register (USARTx_DR) */
#define USART6_DR			USART_DR(USART6_BASE)

/* Baud rate register (USARTx_BRR) */
#define USART6_BRR			USART_BRR(USART6_BASE)

/* Control register 1 (USARTx_CR1) */
#define USART6_CR1			USART_CR1(USART6_BASE)

/* Control register 2 (USARTx_CR2) */
#define USART6_CR2			USART_CR2(USART6_BASE)

/* Control register 3 (USARTx_CR3) */
#define USART6_CR3			USART_CR3(USART6_BASE)

/* Guard time and prescaler register (USARTx_GTPR) */
#define USART6_GTPR			USART_GTPR(USART6_BASE)

/* --- USART_CR1 values ---------------------------------------------------- */

/* OVER8: Oversampling mode */
#define USART_CR1_OVER8			(1 << 15)

/* --- USART_CR3 values ---------------------------------------------------- */

/* ONEBIT: One sample bit method enable */
#define USART_CR3_ONEBIT		(1 << 11)

#endif
