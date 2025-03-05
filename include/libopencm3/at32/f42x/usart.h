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

/** @defgroup usart_reg_base USART register base addresses
 * Holds all the U(S)ART peripherals supported.
 * @{
 */
#define USART4			USART4_BASE
/**@}*/

/* --- USART_CR1 (USART_CTRL1) values -------------------------------------- */
#define USART_CR1_M1		(1 << 28)		/* DBN1 */

#define USART_CR1_DEAT_SHIFT	21
#define USART_CR1_DEAT		(0x1F << USART_CR1_DEAT_SHIFT)
/** DEAT[4:0]: Driver Enable assertion time */
#define USART_CR1_DEAT_VAL(x)	((x) << USART_CR1_DEAT_SHIFT)

#define USART_CR1_DEDT_SHIFT	16
#define USART_CR1_DEDT		(0x1F << USART_CR1_DEDT_SHIFT)
/** DEDT[4:0]: Driver Enable deassertion time */
#define USART_CR1_DEDT_VAL(x)	((x) << USART_CR1_DEDT_SHIFT)

#define USART_CR1_M0		(1 << 12)		/* DBN0 */

/* --- USART_CR2 (USART_CTRL2) values -------------------------------------- */
/** ADD[7:4]: Address of the USART node. */
#define USART_CR2_ADD_SHIFT	28

/** SWAP: Swap TX/RX pins */
#define USART_CR2_SWAP		(1 << 15)		/* TRPSWAP */

/** ADDM7:7-bit Address Detection/4-bit Address Detection */
#define USART_CR2_ADDM7		(1 << 4)		/* IDBN */

/* --- USART_CR3 (USART_CTRL3) values -------------------------------------- */
#define USART_CR3_DEP		(1 << 15)		/* DEP */
#define USART_CR3_DEM		(1 << 14)		/* RS485EN */

#endif
