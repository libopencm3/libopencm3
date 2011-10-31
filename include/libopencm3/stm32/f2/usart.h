/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#ifndef LIBOPENCM3_USART_F2_H
#define LIBOPENCM3_USART_F2_H

#include <libopencm3/stm32/usart.h>

/* --- USART_CR1 values ---------------------------------------------------- */

/* OVER8: Oversampling mode */
#define USART_CR1_OVER8			(1 << 15)

/* --- USART_CR3 values ---------------------------------------------------- */

/* ONEBIT: One sample bit method enable */
#define USART_CR3_ONEBIT		(1 << 11)

#endif
