/** @defgroup VF6xx_uart UART
 *
 * @ingroup VF6xx
 *
 * @section vf6xx_uart_api_ex UART API.
 *
 * @brief <b>VF6xx Universal Asynchronous Receiver/Transmitter (UART)</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2014 Stefan Agner <stefan@agner.ch>
 *
 * @date 03 July 2014
 *
 * This library supports the UART in the VF6xx SoC of Freescale.
 * Devices can have up to 6 UARTs.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

/**@{*/

#include <libopencm3/vf6xx/uart.h>
#include <libopencm3/vf6xx/ccm.h>

/*---------------------------------------------------------------------------*/
/** @brief UART Set Baudrate.

The baud rate is computed from the IPG bus clock. The bus clock must be
calculated by using @ref ccm_calculate_clocks before calling this function.

@param[in] uart unsigned 32 bit. UART block register address base @ref
uart_reg_base
@param[in] baud unsigned 32 bit. Baud rate specified in Hz.
*/

void uart_set_baudrate(uint32_t uart, uint32_t baud)
{
	uint32_t bd_clk = ccm_ipg_bus_clk / baud;
	uint32_t sbr;

	/* Round up if LSB is one... */
	bd_clk /= 8;
	sbr = bd_clk / 2 + (bd_clk & 0x1);

	UART_BDL(uart) = sbr & UART_BDL_SBR_MASK;
	UART_BDH(uart) = (sbr >> 8) & UART_BDH_SBR_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief UART Set Parity.

The parity bit can be selected as none, even or odd.

@param[in] uart unsigned 32 bit. UART block register address base @ref
uart_reg_base
@param[in] parity unsigned 8 bit. Parity @ref uart_parity.
*/

void uart_set_parity(uint32_t uart, uint8_t parity)
{
	uint8_t reg8;

	reg8 = UART_C1(uart);
	reg8 = (reg8 & ~UART_PARITY_MASK) | parity;
	UART_C1(uart) = reg8;
}

/*---------------------------------------------------------------------------*/
/** @brief UART Set Hardware Flow Control.

The flow control bit can be selected as none, RTS, CTS or RTS+CTS.

@param[in] uart unsigned 32 bit. UART block register address base @ref
uart_reg_base
@param[in] flowcontrol unsigned 8 bit. Flowcontrol @ref uart_cr3_flowcontrol.
*/

void uart_set_flow_control(uint32_t uart, uint8_t flowcontrol)
{
	uint8_t reg8;

	reg8 = UART_MODEM(uart);
	reg8 = (reg8 & ~UART_FLOWCONTROL_MASK) | flowcontrol;
	UART_MODEM(uart) = reg8;
}

/*---------------------------------------------------------------------------*/
/** @brief UART Enable.

Enable Tramitter and Receiver

@param[in] uart unsigned 32 bit. UART block register address base @ref
uart_reg_base
*/

void uart_enable(uint32_t uart)
{
	UART_C2(uart) |= (UART_C2_TE | UART_C2_RE);
}

/*---------------------------------------------------------------------------*/
/** @brief UART Disable.

At the end of the current frame, the UART is disabled to reduce power.

@param[in] uart unsigned 32 bit. UART block register address base @ref
uart_reg_base
*/

void uart_disable(uint32_t uart)
{
	UART_C2(uart) &= ~(UART_C2_TE | UART_C2_RE);
}

/*---------------------------------------------------------------------------*/
/** @brief UART Send a Data Word.
 *
 * @param[in] uart unsigned 32 bit. UART block register address base @ref
 * uart_reg_base
 * @param[in] data unsigned 8 bit.
 */

void uart_send(uint32_t uart, uint8_t data)
{
	UART_D(uart) = data;
}

/*---------------------------------------------------------------------------*/
/** @brief UART Wait for Transmit Data Buffer Empty
 *
 * Blocks until the transmit data buffer becomes empty and is ready to accept
 * the next data word.
 *
 * @param[in] uart unsigned 32 bit. UART block register address base @ref
 * uart_reg_base
 */

void uart_wait_send_ready(uint32_t uart)
{
	/* Wait until the data has been transferred into the shift register. */
	while ((UART_S1(uart) & UART_S1_TC) == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief UART Send Data byte blocking
 *
 * Blocks until the transmit data buffer becomes empty before sending the
 * next (given) byte.
 * @param[in] uart unsigned 32 bit. UART block register address base @ref
 * uart_reg_base
 * @param[in] data unsigned 8 bit.
 */

void uart_send_blocking(uint32_t uart, uint8_t data)
{
	uart_wait_send_ready(uart);
	uart_send(uart, data);
}

/*---------------------------------------------------------------------------*/
/** @brief UART Read a Received Data Word.
 *
 * @param[in] uart unsigned 32 bit. UART block register address base @ref
 * uart_reg_base
 * @returns unsigned 8 bit data word.
 */

uint8_t uart_recv(uint32_t uart)
{
	/* Receive data. */
	return UART_D(uart);
}

/*---------------------------------------------------------------------------*/
/** @brief UART Wait for Received Data Available
 *
 * Blocks until the receive data buffer holds a valid received data word.
 *
 * @param[in] uart unsigned 32 bit. UART block register address base @ref
 * uart_reg_base
 */

void uart_wait_recv_ready(uint32_t uart)
{
	/* Wait until the data is ready to be received. */
	while ((UART_S1(uart) & UART_S1_RDRF) == 0);
}


/*---------------------------------------------------------------------------*/
/** @brief UART Read a Received Data Word with Blocking.

Wait until a data word has been received then return the word.

@param[in] uart unsigned 32 bit. UART block register address base @ref
uart_reg_base
@returns unsigned 16 bit data word.
*/

uint8_t uart_recv_blocking(uint32_t uart)
{
	uart_wait_recv_ready(uart);

	return uart_recv(uart);
}

/**@}*/

