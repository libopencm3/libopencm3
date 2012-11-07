/** @defgroup STM32F1xx_usart_file USART

@ingroup STM32F_files

@brief <b>libopencm3 STM32F USART</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>

@date 30 August 2012

This library supports the USART/UART in the STM32F series
of ARM Cortex Microcontrollers by ST Microelectronics.

Devices can have up to 3 USARTs and 2 UARTs.

LGPL License Terms @ref lgpl_license
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

#if defined(STM32F1)
#	include <libopencm3/stm32/f1/rcc.h>
#elif defined(STM32F2)
#	include <libopencm3/stm32/f2/rcc.h>
#elif defined(STM32F4)
#	include <libopencm3/stm32/f4/rcc.h>
#elif defined(STM32L1)
#	include <libopencm3/stm32/l1/rcc.h>
#else
#	error "stm32 family not defined."
#endif

/*-----------------------------------------------------------------------------*/
/** @brief USART Set Baudrate.

The baud rate is computed from the APB high-speed prescaler clock (for USART1)
or the APB low-speed prescaler clock (for other USARTs). These values must
be correctly set before calling this function (refer to the rcc_clock_setup-*
functions in RCC).

@todo Add support for USART6 and oversampling in F2/F4

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] baud unsigned 32 bit. Baud rate specified in Hz.
*/

void usart_set_baudrate(u32 usart, u32 baud)
{
	u32 clock = rcc_ppre1_frequency;

//#ifdef STM32F1
	if (usart == USART1) {
		clock = rcc_ppre2_frequency;
	}
/* This has to be added for F2 when it get's support for USART6 */
/*
#else
	if ((usart == USART1) ||
	    (usart == USART6)) {
		clock = rcc_ppre2_frequency;
	}
#endif
*/

	/*
	 * Yes it is as simple as that. The reference manual is
	 * talking about fractional calculation but it seems to be only
	 * marketting babble to sound awesome. It is nothing else but a
	 * simple divider to generate the correct baudrate.
	 *
	 * Note: We round() the value rather than floor()ing it, for more
	 * accurate divisor selection.
	 */
	USART_BRR(usart) = ((2 * clock) + baud) / (2 * baud);
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Set Word Length.

The word length is set to 8 or 9 bits. Note that the last bit will be a parity bit
if parity is enabled, in which case the data length will be 7 or 8 bits respectively.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] bits unsigned 32 bit. Word length in bits 8 or 9.
*/

void usart_set_databits(u32 usart, u32 bits)
{
	if (bits == 8)
		USART_CR1(usart) &= ~USART_CR1_M; /* 8 data bits */
	else
		USART_CR1(usart) |= USART_CR1_M;  /* 9 data bits */
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Set Stop Bit(s).

The stop bits are specified as 0.5, 1, 1.5 or 2.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] stopbits unsigned 32 bit. Stop bits @ref usart_cr2_stopbits.
*/

void usart_set_stopbits(u32 usart, u32 stopbits)
{
	u32 reg32;

	reg32 = USART_CR2(usart);
	reg32 = (reg32 & ~USART_CR2_STOPBITS_MASK) | stopbits;
	USART_CR2(usart) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Set Parity.

The parity bit can be selected as none, even or odd.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] parity unsigned 32 bit. Parity @ref usart_cr1_parity.
*/

void usart_set_parity(u32 usart, u32 parity)
{
	u32 reg32;

	reg32 = USART_CR1(usart);
	reg32 = (reg32 & ~USART_PARITY_MASK) | parity;
	USART_CR1(usart) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Set Rx/Tx Mode.

The mode can be selected as Rx only, Tx only or Rx+Tx.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] mode unsigned 32 bit. Mode @ref usart_cr1_mode.
*/

void usart_set_mode(u32 usart, u32 mode)
{
	u32 reg32;

	reg32 = USART_CR1(usart);
	reg32 = (reg32 & ~USART_MODE_MASK) | mode;
	USART_CR1(usart) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Set Hardware Flow Control.

The flow control bit can be selected as none, RTS, CTS or RTS+CTS.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] flowcontrol unsigned 32 bit. Flowcontrol @ref usart_cr3_flowcontrol.
*/

void usart_set_flow_control(u32 usart, u32 flowcontrol)
{
	u32 reg32;

	reg32 = USART_CR3(usart);
	reg32 = (reg32 & ~USART_FLOWCONTROL_MASK) | flowcontrol;
	USART_CR3(usart) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Enable.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_enable(u32 usart)
{
	USART_CR1(usart) |= USART_CR1_UE;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Disable.

At the end of the current frame, the USART is disabled to reduce power.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_disable(u32 usart)
{
	USART_CR1(usart) &= ~USART_CR1_UE;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Send a Data Word.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] data unsigned 16 bit.
*/

void usart_send(u32 usart, u16 data)
{
	/* Send data. */
	USART_DR(usart) = (data & USART_DR_MASK);
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Read a Received Data Word.

If parity is enabled the MSB (bit 7 or 8 depending on the word length) is the parity bit.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@returns unsigned 16 bit data word.
*/

u16 usart_recv(u32 usart)
{
	/* Receive data. */
	return USART_DR(usart) & USART_DR_MASK;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Wait for Transmit Data Buffer Empty

Blocks until the transmit data buffer becomes empty and is ready to accept the
next data word.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_wait_send_ready(u32 usart)
{
	/* Wait until the data has been transferred into the shift register. */
	while ((USART_SR(usart) & USART_SR_TXE) == 0);
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Wait for Received Data Available

Blocks until the receive data buffer holds a valid received data word.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_wait_recv_ready(u32 usart)
{
	/* Wait until the data is ready to be received. */
	while ((USART_SR(usart) & USART_SR_RXNE) == 0);
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Send Data Word with Blocking

Blocks until the transmit data buffer becomes empty then writes the next data word
for transmission.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] data unsigned 16 bit.
*/

void usart_send_blocking(u32 usart, u16 data)
{
	usart_wait_send_ready(usart);
	usart_send(usart, data);
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Read a Received Data Word with Blocking.

Wait until a data word has been received then return the word.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@returns unsigned 16 bit data word.
*/

u16 usart_recv_blocking(u32 usart)
{
	usart_wait_recv_ready(usart);

	return usart_recv(usart);
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Receiver DMA Enable.

DMA is available on:
@li USART1 Rx DMA1 channel 5.
@li USART2 Rx DMA1 channel 6.
@li USART3 Rx DMA1 channel 3.
@li UART4 Rx DMA2 channel 3.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_enable_rx_dma(u32 usart)
{
	USART_CR3(usart) |= USART_CR3_DMAR;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Receiver DMA Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_disable_rx_dma(u32 usart)
{
	USART_CR3(usart) &= ~USART_CR3_DMAR;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Transmitter DMA Enable.

DMA is available on:
@li USART1 Tx DMA1 channel 4.
@li USART2 Tx DMA1 channel 7.
@li USART3 Tx DMA1 channel 2.
@li UART4 Tx DMA2 channel 5.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_enable_tx_dma(u32 usart)
{
	USART_CR3(usart) |= USART_CR3_DMAT;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Transmitter DMA Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_disable_tx_dma(u32 usart)
{
	USART_CR3(usart) &= ~USART_CR3_DMAT;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Receiver Interrupt Enable.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_enable_rx_interrupt(u32 usart)
{
	USART_CR1(usart) |= USART_CR1_RXNEIE;
}


/*-----------------------------------------------------------------------------*/
/** @brief USART Receiver Interrupt Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_disable_rx_interrupt(u32 usart)
{
	USART_CR1(usart) &= ~USART_CR1_RXNEIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Transmitter Interrupt Enable.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_enable_tx_interrupt(u32 usart)
{
	USART_CR1(usart) |= USART_CR1_TXEIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief USART Transmitter Interrupt Disable.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
*/

void usart_disable_tx_interrupt(u32 usart)
{
	USART_CR1(usart) &= ~USART_CR1_TXEIE;
}


/*---------------------------------------------------------------------------*/
/** @brief USART Read a Status Flag.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] flag Unsigned int32. Status register flag  @ref usart_sr_flags.
@returns boolean: flag set.
*/

bool usart_get_flag(u32 usart, u32 flag)
{
	return ((USART_SR(usart) & flag) != 0);
}

/*---------------------------------------------------------------------------*/
/** @brief USART Return Interrupt Source.

Returns true if the specified interrupt flag (IDLE, RXNE, TC, TXE or OE) was
set and the interrupt was enabled. If the specified flag is not an interrupt
flag, the function returns false.

@todo  These are the most important interrupts likely to be used. Others
relating to LIN break, and error conditions in multibuffer communication, need
to be added for completeness.

@param[in] usart unsigned 32 bit. USART block register address base @ref usart_reg_base
@param[in] flag Unsigned int32. Status register flag  @ref usart_sr_flags.
@returns boolean: flag and interrupt enable both set.
*/

bool usart_get_interrupt_source(u32 usart, u32 flag)
{
u32 flag_set = (USART_SR(usart) & flag);
/* IDLE, RXNE, TC, TXE interrupts */
	if ((flag >= USART_SR_IDLE) && (flag <= USART_SR_TXE))
		return ((flag_set & USART_CR1(usart)) != 0);
/* Overrun error */
	else if (flag == USART_SR_ORE)
		return (flag_set && (USART_CR3(usart) & USART_CR3_CTSIE));
	return (false);
}

/**@}*/

