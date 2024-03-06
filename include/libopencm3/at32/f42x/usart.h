/** @defgroup usart_defines USART Defines

@brief <b>Defined Constants and Types for the AT32F42x USART</b>

@ingroup AT32F42x_defines

@version 1.0.0

@date 27 November 2022

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

#include <libopencm3/stm32/common/usart_common_f124.h>

/* --- USART_CR3 (USART_CTRL3) values -------------------------------------- */
#define USART_CR3_DEP		(1 << 15)		/* DEP */
#define USART_CR3_RS485E	(1 << 14)		/* RS485EN */

#endif
