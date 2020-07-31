/** @addtogroup uart_defines
 *
 * @brief UART registers are mostly equivalent to USART registers.
 *
 * USART and UART registers are equivalent except [in UART registers]:
 *
 *  * USART_CTRL: SYNC, CSMA, SMSDELAY, SSSEARLY, CSINV, CPOL and CPHA
 *	(Synchronous operation not available)
 *  * USART_STATUS: MASTEREN (Synchronous operation not available)
 *  * USART_CTRL: MSBF (transmission LSB first only)
 *  * USART_CTRL: AUTOCS (chip-select not available)
 *  * USART_CTRL: SCMODE (SmartCard mode not available)
 *  * USART_FRAME: DATABITS (limited framesize. 8-9 databits only)
 *  * USART_IRCTRL: IREN (IrDA not available)
 *   (except DATABITS, all the above are 0)
 *
 * full text: (p495, "d0183_Rev1.10" EFM32LG-RM)
 *  - "18.3 Functional Description",
 *  - "18.4 Register Description"
 *  - "18.5 Register Map"
 *
 * use USART macro's to manipulate UART registers.
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#pragma once

#include <libopencm3/efm32/memorymap.h>
#include <libopencm3/efm32/usart.h>

/**@{*/

/* UART0 */
#define UART0				UART0_BASE
#define UART0_CTRL			USART_CTRL(UART0)
#define UART0_FRAME			USART_FRAME(UART0)
#define UART0_TRIGCTRL		USART_TRIGCTRL(UART0)
#define UART0_CMD			USART_CMD(UART0)
#define UART0_STATUS		USART_STATUS(UART0)
#define UART0_CLKDIV		USART_CLKDIV(UART0)
#define UART0_RXDATAX		USART_RXDATAX(UART0)
#define UART0_RXDATA		USART_RXDATA(UART0)
#define UART0_RXDOUBLEX		USART_RXDOUBLEX(UART0)
#define UART0_RXDOUBLE		USART_RXDOUBLE(UART0)
#define UART0_RXDATAXP		USART_RXDATAXP(UART0)
#define UART0_RXDOUBLEXP	USART_RXDOUBLEXP(UART0)
#define UART0_TXDATAX		USART_TXDATAX(UART0)
#define UART0_TXDATA		USART_TXDATA(UART0)
#define UART0_TXDOUBLEX		USART_TXDOUBLEX(UART0)
#define UART0_TXDOUBLE		USART_TXDOUBLE(UART0)
#define UART0_IF			USART_IF(UART0)
#define UART0_IFS			USART_IFS(UART0)
#define UART0_IFC			USART_IFC(UART0)
#define UART0_IEN			USART_IEN(UART0)
#define UART0_IRCTRL		USART_IRCTRL(UART0)
#define UART0_ROUTE			USART_ROUTE(UART0)
#define UART0_INPUT			USART_INPUT(UART0)
#define UART0_I2SCTRL		USART_I2SCTRL(UART0)

/* UART1 */
#define UART1				UART1_BASE
#define UART1_CTRL			USART_CTRL(UART1)
#define UART1_FRAME			USART_FRAME(UART1)
#define UART1_TRIGCTRL		USART_TRIGCTRL(UART1)
#define UART1_CMD			USART_CMD(UART1)
#define UART1_STATUS		USART_STATUS(UART1)
#define UART1_CLKDIV		USART_CLKDIV(UART1)
#define UART1_RXDATAX		USART_RXDATAX(UART1)
#define UART1_RXDATA		USART_RXDATA(UART1)
#define UART1_RXDOUBLEX		USART_RXDOUBLEX(UART1)
#define UART1_RXDOUBLE		USART_RXDOUBLE(UART1)
#define UART1_RXDATAXP		USART_RXDATAXP(UART1)
#define UART1_RXDOUBLEXP	USART_RXDOUBLEXP(UART1)
#define UART1_TXDATAX		USART_TXDATAX(UART1)
#define UART1_TXDATA		USART_TXDATA(UART1)
#define UART1_TXDOUBLEX		USART_TXDOUBLEX(UART1)
#define UART1_TXDOUBLE		USART_TXDOUBLE(UART1)
#define UART1_IF			USART_IF(UART1)
#define UART1_IFS			USART_IFS(UART1)
#define UART1_IFC			USART_IFC(UART1)
#define UART1_IEN			USART_IEN(UART1)
#define UART1_IRCTRL		USART_IRCTRL(UART1)
#define UART1_ROUTE			USART_ROUTE(UART1)
#define UART1_INPUT			USART_INPUT(UART1)
#define UART1_I2SCTRL		USART_I2SCTRL(UART1)

/**@}*/