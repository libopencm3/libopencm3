/** @addtogroup usart_file USART peripheral API
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

#include <libopencm3/gd32/usart.h>
#include <libopencm3/gd32/rcc.h>

/*---------------------------------------------------------------------------*/
/** @brief USART Set Baudrate.

The baud rate is computed from the APB high-speed prescaler clock (for
USART0) or the APB low-speed prescaler clock (for USART1). These values
must be correctly set before calling this function (refer to the
rcc_clock_setup-* functions in RCC).

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] baud unsigned 32 bit. Baud rate specified in Hz.
*/

void usart_set_baudrate(uint32_t usart, uint32_t baud)
{
	uint32_t clock = rcc_apb1_frequency;

#if defined USART0
	if ((usart == USART0)) {
		clock = rcc_apb2_frequency;
	}
#endif

	USART_BAUD(usart) = (clock + baud / 2) / baud;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Set Word Length.

The word length is set to 8 or 9 bits. Note that the last bit will be a parity
bit if parity is enabled, in which case the data length will be 7 or 8 bits
respectively.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] bits unsigned 32 bit. Word length in bits 8 or 9.
*/

void usart_set_databits(uint32_t usart, uint32_t bits)
{
	if (bits == 8) {
		USART_CTL0(usart) &= ~USART_CTL0_WL; /* 8 data bits */
	} else {
		USART_CTL0(usart) |= USART_CTL0_WL;  /* 9 data bits */
	}
}

/*---------------------------------------------------------------------------*/
/** @brief USART Set Stop Bit(s).

The stop bits are specified as 0.5, 1, 1.5 or 2.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] stopbits unsigned 32 bit. Stop bits @ref usart_ctl1_stopbits.
*/

void usart_set_stopbits(uint32_t usart, uint32_t stopbits)
{
	uint32_t reg32;

	reg32 = USART_CTL1(usart);
	reg32 = (reg32 & ~USART_CTL1_STOPBITS_MASK) | stopbits;
	USART_CTL1(usart) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Set Parity.

The parity bit can be selected as none, even or odd.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] parity unsigned 32 bit. Parity @ref usart_ctl0_parity.
*/

void usart_set_parity(uint32_t usart, uint32_t parity)
{
	uint32_t reg32;

	reg32 = USART_CTL0(usart);
	reg32 = (reg32 & ~USART_PARITY_MASK) | parity;
	USART_CTL0(usart) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Set Rx/Tx Mode.

The mode can be selected as Rx only, Tx only or Rx+Tx.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] mode unsigned 32 bit. Mode @ref usart_ctl0_mode.
*/

void usart_set_mode(uint32_t usart, uint32_t mode)
{
	uint32_t reg32;

	reg32 = USART_CTL0(usart);
	reg32 = (reg32 & ~USART_MODE_MASK) | mode;
	USART_CTL0(usart) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Set Hardware Flow Control.

The flow control bit can be selected as none, RTS, CTS or RTS+CTS.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] flowcontrol unsigned 32 bit. Flowcontrol @ref usart_cr3_flowcontrol.
*/

void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol)
{
	uint32_t reg32;

	reg32 = USART_CTL2(usart);
	reg32 = (reg32 & ~USART_FLOWCONTROL_MASK) | flowcontrol;
	USART_CTL2(usart) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Enable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_enable(uint32_t usart)
{
	USART_CTL0(usart) |= USART_CTL0_UEN;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Disable.

At the end of the current frame, the USART is disabled to reduce power.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_disable(uint32_t usart)
{
	USART_CTL0(usart) &= ~USART_CTL0_UEN;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Send Data Word with Blocking

Blocks until the transmit data buffer becomes empty then writes the next data
word for transmission.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] data unsigned 16 bit.
*/

void usart_send_blocking(uint32_t usart, uint16_t data)
{
	usart_wait_send_ready(usart);
	usart_send(usart, data);
}

/*---------------------------------------------------------------------------*/
/** @brief USART Read a Received Data Word with Blocking.

Wait until a data word has been received then return the word.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@returns unsigned 16 bit data word.
*/

uint16_t usart_recv_blocking(uint32_t usart)
{
	usart_wait_recv_ready(usart);
	return usart_recv(usart);
}

/*---------------------------------------------------------------------------*/
/** @brief USART Receiver DMA Enable.

DMA is available on:
@li USART0 Rx DMA1 channel 2
@li USART1 Rx DMA1 channel 4.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_enable_rx_dma(uint32_t usart)
{
	USART_CTL2(usart) |= USART_CTL2_DENR;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Receiver DMA Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_disable_rx_dma(uint32_t usart)
{
	USART_CTL2(usart) &= ~USART_CTL2_DENR;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Transmitter DMA Enable.

DMA is available on:
@li USART0 Tx DMA1 channel 1.
@li USART1 Tx DMA1 channel 3.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_enable_tx_dma(uint32_t usart)
{
	USART_CTL2(usart) |= USART_CTL2_DENT;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Transmitter DMA Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_disable_tx_dma(uint32_t usart)
{
	USART_CTL2(usart) &= ~USART_CTL2_DENT;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Receiver Interrupt Enable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_enable_rx_interrupt(uint32_t usart)
{
	USART_CTL0(usart) |= USART_CTL0_RBNEIE;
}


/*---------------------------------------------------------------------------*/
/** @brief USART Receiver Interrupt Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_disable_rx_interrupt(uint32_t usart)
{
	USART_CTL0(usart) &= ~USART_CTL0_RBNEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Transmitter Interrupt Enable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_enable_tx_interrupt(uint32_t usart)
{
	USART_CTL0(usart) |= USART_CTL0_TBEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Transmitter Interrupt Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_disable_tx_interrupt(uint32_t usart)
{
	USART_CTL0(usart) &= ~USART_CTL0_TBEIE;
}

/*---------------------------------------------------------------------------*/
/**
 * @brief USART Transmission Complete Interrupt Enable
 * 
 * @param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
 */

void usart_enable_tx_complete_interrupt(uint32_t usart)
{
	USART_CTL0(usart) |= USART_CTL0_TCIE;
}

/*---------------------------------------------------------------------------*/
/**
 * @brief USART Transmission Complete Interrupt Disable
 * 
 * @param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
 */

void usart_disable_tx_complete_interrupt(uint32_t usart)
{
	USART_CTL0(usart) &= ~USART_CTL0_TCIE;
}

/** @brief USART Idle Interrupt Enable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_enable_idle_interrupt(uint32_t usart)
{
	USART_CTL0(usart) |= USART_CTL0_IDLEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Idle Interrupt Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_disable_idle_interrupt(uint32_t usart)
{
	USART_CTL0(usart) &= ~USART_CTL0_IDLEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Error Interrupt Enable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_enable_error_interrupt(uint32_t usart)
{
	USART_CTL2(usart) |= USART_CTL2_ERRIE;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Error Interrupt Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
*/

void usart_disable_error_interrupt(uint32_t usart)
{
	USART_CTL2(usart) &= ~USART_CTL2_ERRIE;
}

/**@}*/

