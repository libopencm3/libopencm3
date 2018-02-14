/** @addtogroup usart_file
@ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>

This library supports the USART/UART in the STM32F series
of ARM Cortex Microcontrollers by ST Microelectronics.

Devices can have up to 3 USARTs and 2 UARTs.

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/rcc.h>

/*---------------------------------------------------------------------------*/
/** @brief USART Send a Data Word.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] data unsigned 16 bit.
*/

void usart_send(uint32_t usart, uint16_t data)
{
	/* Send data. */
	USART_DR(usart) = (data & USART_DR_MASK);
}

/*---------------------------------------------------------------------------*/
/** @brief USART Read a Received Data Word.

If parity is enabled the MSB (bit 7 or 8 depending on the word length) is the
parity bit.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@returns unsigned 16 bit data word.
*/

uint16_t usart_recv(uint32_t usart)
{
	/* Receive data. */
	return USART_DR(usart) & USART_DR_MASK;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Wait for Transmit Data Buffer Empty

Blocks until the transmit data buffer becomes empty and is ready to accept the
next data word.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_wait_send_ready(uint32_t usart)
{
	/* Wait until the data has been transferred into the shift register. */
	while ((USART_SR(usart) & USART_SR_TXE) == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief USART Wait for Received Data Available

Blocks until the receive data buffer holds a valid received data word.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_wait_recv_ready(uint32_t usart)
{
	/* Wait until the data is ready to be received. */
	while ((USART_SR(usart) & USART_SR_RXNE) == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief USART Read a Status Flag.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] flag Unsigned int32. Status register flag  @ref usart_sr_flags.
@returns boolean: flag set.
*/

bool usart_get_flag(uint32_t usart, uint32_t flag)
{
	return ((USART_SR(usart) & flag) != 0);
}


/**@}*/
