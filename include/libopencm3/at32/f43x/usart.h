/** @defgroup usart_defines USART Defines

@brief <b>Defined Constants and Types for the AT32F43x USART</b>

@ingroup AT32F43x_defines

@version 1.0.0

@date 16 November 2024

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

#ifndef LIBOPENCM3_USART_H
#define LIBOPENCM3_USART_H

#include <libopencm3/stm32/common/usart_common_f24.h>

/* --- USART_CR1 (USART_CTRL1) values -------------------------------------- */
#undef USART_CR1_OVER8

/* --- USART_CR2 (USART_CTRL2) values -------------------------------------- */
#define USART_CR2_SWAP		(1 << 14)		/* TRPSWAP */

/* --- USART_CR3 (USART_CTRL3) values -------------------------------------- */
#define USART_CR3_DEP		(1 << 15)		/* DEP */
#define USART_CR3_DEM		(1 << 14)		/* RS485EN */
#undef  USART_CR3_ONEBIT

#endif
