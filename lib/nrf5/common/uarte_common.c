/** @addtogroup uarte_file

@author @htmlonly &copy; @endhtmlonly 2018 
Gerrit Maus <funk@maus.xyz>
Luong Le <novercy@live.com>

This library supports the UARTE in the NRF52 series.

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Gerrit Maus <funk@maus.xyz>
 * Copyright (C) 2018 Luong Le <novercy@live.com>
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

#include <libopencm3/nrf5/uarte.h>
#include <libopencm3/nrf5/gpio.h>

/*---------------------------------------------------------------------------*/
/** @brief UARTE Set Baudrate.

Accuracy depends on the HFCLK source selected.
"baud" can be set as BAUD1200 (for 1200bps), BAUD2400, BAUD4800, BAUD9600,
BAUD14400, BAUD19200, BAUD28800, BAUD38400, BAUD57600, BAUD76800, BAUD115200, 
BAUD230400, BAUD250000, BAUD460800, 921600, or BAUD1M (for 1Mbps)

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] baud unsigned 32 bit. specified baud rate values based on 
predetermined defines @ref uarte_baudrate
*/

void uarte_set_baudrate(uint32_t uarte, uint32_t baud)
{
	UARTE_BAUDRATE(uarte) = baud;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Set Flow control and Parity bit.

The Hardware flow control can be set as HWFC_DISABLED (or 0) and 
HWFC_ENABLED (or 1).
The Parity bit can be set as PARITY_EXCLUDED or PARITY_INCLUDED.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] flowcontrol unsigned 32 bit. HWFC @ref uarte_config
@param[in] parity unsigned 32 bit. Parity bit @ref uarte_config
*/

void uarte_config(uint32_t uarte, uint32_t flowcontrol, uint32_t parity)
{
	UARTE_CONFIG(uarte) = flowcontrol | parity;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Enable.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
*/

void uarte_enable(uint32_t uarte)
{
	UARTE_ENABLE(uarte) = UARTE_ENABLE_ENABLE_ENABLED;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Disable.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
*/

void uarte_disable(uint32_t uarte)
{
	UARTE_ENABLE(uarte) = UARTE_ENABLE_ENABLE_DISABLED;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Set pin TX.

Pin select for TXD signal.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] pin unsigned int32. Pin identifiers @ref gpio_pin_id
*/

void uarte_tx_pin(uint32_t uarte, int pin)
{
	UARTE_PSEL_TXD(uarte) = UARTE_PSEL_TXD_PIN(pin);
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Set pin RX.

Pin select for RXD signal.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] pin unsigned int32. Pin identifiers @ref gpio_pin_id
*/

void uarte_rx_pin(uint32_t uarte, int pin)
{
	UARTE_PSEL_RXD(uarte) = UARTE_PSEL_RXD_PIN(pin);
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Start transmitter.

The UARTE of NRF5x implements EasyDMA for transmission.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
*/

void uarte_tx_start(uint32_t uarte)
{
	UARTE_TASKS_STARTTX(uarte) = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Start receiver.

The UARTE of NRF5x implements EasyDMA for reception.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
*/

void uarte_rx_start(uint32_t uarte)
{
	UARTE_TASKS_STARTRX(uarte) = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Stop transmitter.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
*/

void uarte_tx_stop(uint32_t uarte)
{
	UARTE_TASKS_STOPTX(uarte) = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Stop receiver.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
*/

void uarte_rx_stop(uint32_t uarte)
{
	UARTE_TASKS_STOPRX(uarte) = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Transmitter initial configuration.

Configures initial conditions for transmitter. Set values of TXDRDY and ENDTX 
Registers to 0 and ready to indicate occurred events in transmission.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
*/

void uarte_tx_init(uint32_t uarte)
{
	UARTE_EVENTS_TXDRDY(uarte) = 0;
	UARTE_EVENTS_ENDTX(uarte) = 0;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Receiver initial configuration.

Configures initial condition for receiver.
Event can be set as RXDRDY, if want to reset event "Data received in RXD", or 
can be set as ENDRX, if want to reset event "Receive buffer is filled up".

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] event unsigned 32 bit. predetermined event names @ref 
uarte_events_interrupt
*/

void uarte_rx_init(uint32_t uarte, char event)
{
	if(event & RXDRDY){UARTE_EVENTS_RXDRDY(uarte) = 0;}
	else if(event & ENDRX){UARTE_EVENTS_ENDRX(uarte) = 0;}
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE data received status.

Return 1 if data received in RXD (but potentially not yet transferred to 
Data RAM).

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@returns unsigned 32 bit data word.
*/

uint32_t uarte_received_rxdrdy(uint32_t uarte)
{
	return UARTE_EVENTS_RXDRDY(uarte);
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE receive buffer status.

Return 1 if receive buffer is filled up.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@returns unsigned 32 bit data word.
*/

uint32_t uarte_received_endrx(uint32_t uarte)
{
	return UARTE_EVENTS_ENDRX(uarte);
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE receive events status.

flexible function incicating that data is received or receive buffer is filled
up (as requested from a given event name).

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] event unsigned 32 bit. predetermined event names @ref 
uarte_events_interrupt
@returns unsigned 32 bit data word.
*/

uint32_t uarte_received(uint32_t uarte, char event)
{
	if(event & RXDRDY){return UARTE_EVENTS_RXDRDY(uarte);}
	else if(event & ENDRX){return UARTE_EVENTS_ENDRX(uarte);}
	else {return false;}
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Set Data Pointer and Length for transmission.

Set initial address pointer and number of bytes in the RAM buffer for DMA 
Transmission.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] *ptr unsigned 8 bit. Address pointer of data which be transmitted
@param[in] maxcnt unsigned 8 bit. Maximum number of bytes in transmit buffer
*/

void uarte_tx_packet(uint32_t uarte, uint8_t *ptr, uint8_t maxcnt)
{
	UARTE_TXD_PTR(uarte) = (uint32_t) ptr;
	UARTE_TXD_MAXCNT(uarte) = (uint32_t) maxcnt;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Data Pointer and Data Length for reception.

Set initial address pointer and number of bytes in the RAM buffer for DMA 
Reception.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] *ptr unsigned 8 bit. Address pointer of data which be received
@param[in] maxcnt unsigned 8 bit. Maximum number of bytes in receive buffer
*/

void uarte_rx_packet(uint32_t uarte, uint8_t *ptr, uint8_t maxcnt)
{
	UARTE_RXD_PTR(uarte) = (uint32_t) ptr;
	UARTE_RXD_MAXCNT(uarte) = (uint32_t) maxcnt;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE pointer of received Data.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@returns unsigned 32 bit data word.
*/

uint32_t uarte_rx_received_ptr(uint32_t uarte)
{
	return UARTE_RXD_PTR(uarte);	
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE length of received Data.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@returns unsigned 32 bit data word
*/

uint32_t uarte_rx_received_maxcnt(uint32_t uarte)
{
	return UARTE_RXD_MAXCNT(uarte);	
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Send Data Word.

Setup Data word, reset events, start transmission.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] *ptr unsigned 8 bit. Address pointer of data which be transmitted
@param[in] maxcnt unsigned 8 bit. Maximum number of bytes in transmit buffer
*/

void uarte_send(uint32_t uarte, uint8_t *ptr, uint8_t maxcnt)
{
	uarte_tx_packet(uarte, ptr, maxcnt);
	uarte_tx_init(uarte);
	uarte_tx_start(uarte);
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Send Data Word with Blocking.

Setup Data word, reset events, start trasmission and block until all bytes
in the TXD buffer transmitted.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] *ptr unsigned 8 bit. Address pointer of data which be transmitted
@param[in] maxcnt unsigned 8 bit. Maximum number of bytes in transmit buffer
*/

void uarte_send_waiting(uint32_t uarte, uint8_t *ptr, uint8_t maxcnt)
{
	uarte_tx_packet(uarte, ptr, maxcnt);
	uarte_tx_init(uarte);
	uarte_tx_start(uarte);
	while(UARTE_EVENTS_ENDTX(uarte) == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE interrupt enable.

The events can be selected as CTS, NCTS, RXDRDY, ENDRX, TXDRDY, ENDTX, ERROR,
RXTO, RXSTARTED, TXSTARTED, and/or TXSTOPPED.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] events unsigned 32 bit. predetermined event names @ref 
uarte_events_interrupt
*/

void uarte_interrupt_enable(uint32_t uarte, uint32_t events)
{
	UARTE_INTENSET(uarte) |= events;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE interrupt disable.

The events can be selected as CTS, NCTS, RXDRDY, ENDRX, TXDRDY, ENDTX, ERROR,
RXTO, RXSTARTED, TXSTARTED, and/or TXSTOPPED.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] events unsigned 32 bit. predetermined event names @ref 
uarte_events_interrupt
*/

void uarte_interrupt_disable(uint32_t uarte, uint32_t events)
{
	UARTE_INTENCLR(uarte) |= events;
}

/*---------------------------------------------------------------------------*/
/** @brief UARTE Get Events.

The events can be selected as CTS, NCTS, RXDRDY, ENDRX, TXDRDY, ENDTX, ERROR,
RXTO, RXSTARTED, TXSTARTED, or TXSTOPPED.

@param[in] uarte unsigned 32 bit. UARTE block register address base @ref
uarte_reg_base
@param[in] event unsigned 32 bit. predetermined event names @ref 
uarte_events_interrupt
@returns boolean
*/

bool uarte_get_event(uint32_t uarte, char event)
{
	if(event & CTS){return (UARTE_EVENTS_CTS(uarte) != 0);}
	else if(event & NCTS){return (UARTE_EVENTS_NCTS(uarte) != 0);}
	else if(event & RXDRDY){return (UARTE_EVENTS_RXDRDY(uarte) != 0);}
	else if(event & ENDRX){return (UARTE_EVENTS_ENDRX(uarte) != 0);}
	else if(event & TXDRDY){return (UARTE_EVENTS_TXDRDY(uarte) != 0);}
	else if(event & ENDTX){return (UARTE_EVENTS_ENDTX(uarte) != 0);}
	else if(event & ERROR){return (UARTE_EVENTS_ERROR(uarte) != 0);}
	else if(event & RXTO){return (UARTE_EVENTS_RXTO(uarte) != 0);}
	else if(event & RXSTARTED){return (UARTE_EVENTS_RXSTARTED(uarte) != 0);}
	else if(event & TXSTARTED){return (UARTE_EVENTS_TXSTARTED(uarte) != 0);}
	else if(event & TXSTOPPED){return (UARTE_EVENTS_TXSTOPPED(uarte) != 0);}
	else {return false;}
}


/**@}*/
