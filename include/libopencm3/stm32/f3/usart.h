/** @defgroup usart_defines USART Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F3xx USART</b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 5 December 2012
 *
 * LGPL License Terms @ref lgpl_license
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

#include <libopencm3/stm32/common/usart_common_all.h>
#include <libopencm3/stm32/common/usart_common_v2.h>



/* --- USART_CR2 values ---------------------------------------------------- */

/* ADD[7:4]: Address of the USART node (31,28) */
#define USART_CR2_ADD1_MASK              (0xF << 28)

/* ADD[3:0]: Address of the USART node (27,24) */
#define USART_CR2_ADD2_MASK              (0xF << 24)

/* ABRMOD[1:0]: Auto baud rate mode */
#define USART_CR2_ABRMOD_BAUD		(0x0 << 21)
#define USART_CR2_ABRMOD_FALL_EDGE	(0x1 << 21)
#define USART_CR2_ABRMOD_FRAME_0x7F	(0x2 << 21)
#define USART_CR2_ABRMOD_FRAME_0x55	(0x3 << 21)

/* ADD[3:0]: Address of the usart node
#define USART_CR2_ADD_MASK              0xF */

/* --- USART_CR3 values ---------------------------------------------------- */


/* SCARCNT[2:0]: Smartcard auto-retry count */
#define USART_CR3_SCARCNT_OFF		(0x0 << 17)
/* 0x1 to 0x7: number of automatic retransmission attempts */


/* --- USART_BRR values ---------------------------------------------------- */

/* DIV_Mantissa[11:0]: mantissa of USARTDIV */
#define USART_BRR_DIV_MANTISSA_MASK     (0xFFF << 4)
/* DIV_Fraction[3:0]: fraction of USARTDIV */
#define USART_BRR_DIV_FRACTION_MASK     0xF

/* --- USART_GTPR values --------------------------------------------------- */

/* GT[7:0]: Guard time value */
/* Note: N/A on UART4 & UART5 */
#define USART_GTPR_GT_MASK              (0xFF << 8)

/* PSC[7:0]: Prescaler value */
/* Note: N/A on UART4/5 */
#define USART_GTPR_PSC_MASK             0xFF



/* --- USART_RDR values --------------------------------------------------- */

/* RDR[8:0]: Receive data value */
#define USART_RDR_MASK		    (0x1FF << 0)

/* --- USART_TDR values --------------------------------------------------- */

/* TDR[8:0]: Transmit data value */
#define USART_TDR_MASK		    (0x1FF << 0)

#endif

