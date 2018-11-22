/** @addtogroup radio_file

@author @htmlonly &copy; @endhtmlonly 2018 
Gerrit Maus <funk@maus.xyz>
Luong Le <novercy@live.com>

This library supports the RADIO in the NRF52 series.

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

#include <libopencm3/nrf5/radio.h>

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set S0 length.

Length on air of S0 field in number of bytes.

@param[in] s0len unsigned 8 bit. S0 length @ref radio_pcnf0
*/

void radio_set_s0(uint8_t s0len)
{
	RADIO_PCNF0 |= RADIO_PCNF0_S0LEN(s0len);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set Data length.

Length on air of LENGTH field in number of bits.

@param[in] lflen unsigned 8 bit. Data length @ref radio_pcnf0
*/

void radio_set_lf(uint8_t lflen)
{
	RADIO_PCNF0 |= RADIO_PCNF0_LFLEN(lflen);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Configurates S1 field.

Length on air of S1 field in number of bits.
Configurates include or exclude S1 field in RAM. s1incl can be selected as 
S1INCL_AUTOMATIC or S1INCL_INCLUDE.

@param[in] s1len unsigned 8 bit. S1 length @ref radio_pcnf0
@param[in] s1incl unsigned 32 bit. S1 including config @ref radio_pcnf0
*/

void radio_set_s1(uint8_t s1len, uint32_t s1incl)
{
	RADIO_PCNF0 |= RADIO_PCNF0_S1LEN(s1len) | s1incl;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set MAXLEN.

Set maximum length for Payload and Add-on fiels in numbers of bytes.
Value of maxlen can be set from 0 to 255 (8 bits). If the packet payload is 
larger than MAXLEN, the RADIO will truncate the payload to MAXLEN.

@param[in] maxlen unsigned 8 bit. Payload and Addon length @ref radio_pcnf1
*/

void radio_set_maxlen(uint8_t maxlen)
{
	RADIO_PCNF1 |= RADIO_PCNF1_MAXLEN(maxlen);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set static length.

Static length of Add-on in number of bytes.
The static length parameter is added to the total length of the payload when 
sending and receiving packets, e.g. if the static length is set to N the 
RADIO will receive or send N bytes more than what is defined in the LENGTH 
field of the packet.

@param[in] statlen unsigned 8 bit. Add-on length @ref radio_pcnf1
*/

void radio_set_statlen(uint8_t statlen)
{
	RADIO_PCNF1 |= RADIO_PCNF1_STATLEN(statlen);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set Bit-endian.

Set on air endianness of packet, this applies to the S0, LENGTH, S1 and 
PAYLOAD fields.
endien can be selected as ENDIAN_LITTLE or ENDIAN_BIG for sending LSB or MSB 
on air first.

@param[in] endian unsigned 32 bit. Bit endian @ref radio_pcnf1
*/

void radio_set_endian(uint32_t endian)
{
	RADIO_PCNF1 |= endian;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Packet configuration.

RADIO packet includes S0, LENGTH, S1, PAYLOAD and ADD-ON fields.

@param[in] s0len unsigned 8 bit. S0 length @ref radio_pcnf0
@param[in] lflen unsigned 8 bit. Data length @ref radio_pcnf0
@param[in] s1len unsigned 8 bit. S1 length @ref radio_pcnf0
@param[in] s1incl unsigned 32 bit. S1 including config @ref radio_pcnf0
@param[in] maxlen unsigned 8 bit. Payload and Addon length @ref radio_pcnf1
@param[in] statlen unsigned 8 bit. Add-on length @ref radio_pcnf1
@param[in] endian unsigned 32 bit. Bit endian @ref radio_pcnf1
*/

void radio_packet_config(uint8_t s0len, uint8_t lflen, uint8_t s1len, 
	uint32_t s1incl, uint8_t maxlen, uint8_t statlen, uint32_t endian)
{
	radio_set_s0(s0len);
	radio_set_lf(lflen);
	radio_set_s1(s1len, s1incl);
	radio_set_maxlen(maxlen);
	radio_set_statlen(statlen);
	radio_set_endian(endian);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set Preamble length.

plen can be selected as PLEN_8BIT or PLEN_16BIT for preamble size.

@param[in] plen unsigned 32 bit. Preamble size @ref radio_pcnf0
*/

void radio_preamble(uint32_t plen)
{
	RADIO_PCNF0 |= plen;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set Address.


Base address length (in number of bytes) can be set from 2 to 4. The base 
address is truncated from LSByte if the BALEN is less than 4.
Prefix address length is 1 byte.
The on-air addresses are defined in the BASEn and PREFIXn registers depends on
which logical address was selected.

@param[in] balen unsigned 8 bit. Base Address length @ref radio_pcnf1
@param[in] logical unsigned 8 bit. Logical Address number
@param[in] base_addr unsigned 32 bit. Base Address @ref radio_registers
@param[in] pre_addr unsigned 8 bit. Prefix Address @ref radio_registers
*/

void radio_address_config(uint8_t balen, uint8_t logical, uint32_t base_addr, 
	uint8_t pre_addr)
{
	RADIO_PCNF1 |= balen << 16;
	if(logical == 0)
	{
		RADIO_BASE0 = base_addr << (4-balen)*8;
		RADIO_PREFIX0 = pre_addr; //PREFIX0.AP0
	}
	else if((logical > 0) && (logical < 4))
	{
		RADIO_BASE1 = base_addr << (4-balen)*8;
		RADIO_PREFIX0 = pre_addr << logical*8;
	}
	else if(logical > 3)
	{
		RADIO_BASE1 = base_addr << (4-balen)*8;
		RADIO_PREFIX1 = pre_addr << (logical-4)*8;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Select Transmit address.

Logical address for transmission.

@param[in] logical unsigned 8 bit. Logical Address number @ref radio_txaddress
*/

void radio_txaddress(uint8_t logical)
{
	RADIO_TXADDRESS = (logical);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Select Receive address.

Logical address for reception.

@param[in] logical unsigned 8 bit. Logical Address number @ref radio_rxaddress
*/

void radio_rxaddress(uint8_t logical)
{
	RADIO_RXADDRESSES |= (1) << logical;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Select mode for data rate and modulation.

mode can be selected as NRF_1MBIT, NRF_2MBIT, NRF_250KBIT, BLE_1MBIT, or 
BLE_2MBIT

@param[in] mode unsigned 32 bit. @ref radio_mode
*/

void radio_mode(uint32_t mode)
{
	RADIO_MODE = mode;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set output power.

Output power can be selected as TXPOWER_POS4DBM,_POS3DBM,_0DBM,_NEG4DBM,
_NEG8DBM,_NEG12DBM,_NEG16DBM,_NEG20DBM,_NEG30DBM, or _NEG40DBM

@param[in] txpower unsigned 32 bit. @ref radio_txpower
*/

void radio_output_power(uint32_t txpower)
{
	RADIO_TXPOWER = txpower;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set frequency.

Set frequency and select map for RADIO.
map can be selected as MAP_DEFAULT or MAP_LOW.
Frequency = 2400 + freq (MHz) for default map.
Frequency = 2360 + freq (MHz) for low map.

@param[in] freq unsigned 8 bit. freq is ranging from 0 to 100
@param[in] map unsigned 32 bit. @ref radio_frequency
*/

void radio_frequency(uint8_t freq, uint32_t map)
{
	RADIO_FREQUENCY |= RADIO_FREQUENCY_FREQUENCY(freq) | map;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Packet Pointer.

Packet address to be used for transmission or reception.
The CPU should reconfigure this pointer every time before the RADIO is 
started.

@param[in] *ptr unsigned 32 bit. Byte aligned ram address.
*/

void radio_packet_ptr(uint32_t *ptr)
{
	RADIO_PACKETPTR = (uint32_t) ptr;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Enable TX mode.

Enable RADIO as transmitter and blockings until RADIO has ramped up and 
is ready to be started.
*/

void radio_tx_enable(void)
{
	RADIO_TASKS_TXEN = 1;
	while(RADIO_EVENTS_READY == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Enable RX mode.

Enable RADIO as receiver and blockings until RADIO has ramped up and 
is ready to be started.
*/

void radio_rx_enable(void)
{
	RADIO_TASKS_RXEN = 1;
	while(RADIO_EVENTS_READY == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Start.

Start RADIO
*/

void radio_start(void)
{
	RADIO_TASKS_START = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Stop.

Stop RADIO
*/

void radio_stop(void)
{
	RADIO_TASKS_STOP = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Disable.

Disable RADIO
*/

void radio_disable(void)
{
	RADIO_TASKS_DISABLE = 1;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Address sent or received status.

Return 1 if Address has been sent or received.

@returns unsigned 32 bit data word.
*/

uint32_t radio_address_completed(void)
{
	return RADIO_EVENTS_ADDRESS;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Packet payload sent or received status.

Return 1 if Payload has been sent or received.

@returns unsigned 32 bit data word.
*/

uint32_t radio_payload_completed(void)
{
	return RADIO_EVENTS_PAYLOAD;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Packet sent or received status.

Return 1 if Packet has been sent or received.

@returns unsigned 32 bit data word.
*/

uint32_t radio_packet_completed(void)
{
	return RADIO_EVENTS_END;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Reset Packet sent or received event.

Clear Packet sent/received event.
*/

void radio_packet_completed_reset(void)
{
	RADIO_EVENTS_END = 0;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Send packet.

Setup address pointer and start RADIO.

@param[in] *ptr unsigned 32 bit. Byte aligned ram address.
*/

void radio_send(uint32_t *ptr)
{
	radio_packet_ptr(ptr);
	radio_start();
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Send packet with Blocking.

Setup address pointer, start RADIO, block until packet has been sent, and 
afterthat clear event to be ready for the next transmission.

@param[in] *ptr unsigned 32 bit. Byte aligned ram address.
*/

void radio_send_waiting(uint32_t *ptr)
{
	radio_packet_ptr(ptr);
	radio_start();
	while(radio_packet_completed() == 0);
	radio_packet_completed_reset();
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Enable interrupt.

The events can be selected as READY, ADDRESS, PAYLOAD, END, DISABLED, DEVMATCH,
DEVMISS, RSSIEND, BCMATCH, CRCOK, and/or CRCERROR.

@param[in] events unsigned 32 bit. predetermined event names @ref 
radio_events_interrupt
*/

void radio_interrupt_enable(uint32_t events)
{
	RADIO_INTENSET |= events;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Disable interrupt.

The events can be selected as READY, ADDRESS, PAYLOAD, END, DISABLED, DEVMATCH,
DEVMISS, RSSIEND, BCMATCH, CRCOK, or CRCERROR.

@param[in] events unsigned 32 bit. predetermined event names @ref 
radio_events_interrupt
*/

void radio_interrupt_disable(uint32_t events)
{
	RADIO_INTENCLR |= events;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Get Events.

The events can be selected as READY, ADDRESS, PAYLOAD, END, DISABLED, DEVMATCH,
DEVMISS, RSSIEND, BCMATCH, CRCOK, or CRCERROR.

@param[in] events unsigned 32 bit. predetermined event names @ref 
radio_events_interrupt
@returns boolean
*/

bool radio_get_event(char event)
{
	if(event & READY){return (RADIO_EVENTS_READY != 0);}
	else if(event & ADDRESS){return (RADIO_EVENTS_ADDRESS != 0);}
	else if(event & PAYLOAD){return (RADIO_EVENTS_PAYLOAD != 0);}
	else if(event & END){return (RADIO_EVENTS_END != 0);}
	else if(event & DISABLED){return (RADIO_EVENTS_DISABLED != 0);}
	else if(event & DEVMATCH){return (RADIO_EVENTS_DEVMATCH != 0);}
	else if(event & DEVMISS){return (RADIO_EVENTS_DEVMISS != 0);}
	else if(event & RSSIEND){return (RADIO_EVENTS_RSSIEND != 0);}
	else if(event & BCMATCH){return (RADIO_EVENTS_BCMATCH != 0);}
	else if(event & CRCOK){return (RADIO_EVENTS_CRCOK != 0);}
	else if(event & CRCERROR){return (RADIO_EVENTS_CRCERROR != 0);}
	else {return false;}
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Enable and configure device address match.

Enable and set base and prefix address match for RADIO.
The RADIO is able to listen for eight different device addresses at the same 
time (logical address).
The Device Address match unit assumes that the 48 first bits of the payload 
is the device address and that bit number 6 in S0 is the TxAdd bit.
The DAB specifies the 32 least significant bits and the DAP specifies the 16 
most significant bits of the device address.

@param[in] logical unsigned 8 bit. Logical address @ref radio_dacnf
@param[in] dab unsigned 32 bit. Device Address Base @ref radio_registers
@param[in] dap unsigned 16 bit. Device Address Prefix @ref radio_registers
*/

void radio_match(uint8_t logical, uint32_t dab, uint16_t dap)
{
	RADIO_DAB[logical] = dab;
	RADIO_DAB[logical] = (uint32_t)dap;
	RADIO_DACNF |= (1 << logical) | RADIO_DACNF_TXADD(logical);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO CRC configuration.

Configurates CRC length (1..3). Set CRC length = 0 means CRC calculation 
disabled.
skipaddr can be selected as SKIPADDR_INCLUDE or SKIPARRD_SKIP to include or 
exclude packet address field out of CRC calculation.

@param[in] len unsigned 8 bit. CRC length @ref radio_crccnf
@param[in] skipaddr unsigned 32 bit. CRC calculation config @ref radio_crccnf
*/

void radio_crc_config(uint8_t len, uint32_t skipaddr)
{
	RADIO_CRCCNF |= RADIO_CRCCNF_LEN(len) | skipaddr;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set CRC polynomial value.

Each term in the CRC polynomial is mapped to a bit in this register which 
index corresponds to the term's exponent. The least significant term/bit is 
hard-wired internally to 1, and bit number 0 of the register content is 
ignored by the hardware.
E.g. For an 8 bit CRC polynomial: x^7+x^5+x^3+x = 10101010 = 0xAA

@param[in] crcpoly unsigned 32 bit. @ref radio_registers
*/

void radio_crc_poly(uint32_t crcpoly)
{
	RADIO_CRCPOLY = crcpoly;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Set CRC initial value.

Set initial value for CRC calculation.

@param[in] crcinit unsigned 32 bit. @ref radio_registers
*/

void radio_crc_init(uint32_t crcinit)
{
	RADIO_CRCINIT = crcinit;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO CRC complete configuration.

Configures CRC length with CRC calculation, set CRC polynomial and initial 
values.

@param[in] len unsigned 8 bit. CRC length @ref radio_crccnf
@param[in] skipaddr unsigned 32 bit. CRC calculation config @ref radio_crccnf
@param[in] crcpoly unsigned 32 bit. @ref radio_registers
@param[in] crcinit unsigned 32 bit. @ref radio_registers
*/

void radio_crc(uint8_t len, uint32_t skipaddr, uint32_t crcpoly, 
	uint32_t crcinit)
{
	radio_crc_config(len, skipaddr);
	radio_crc_poly(crcpoly);
	radio_crc_init(crcinit);
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO CRC check status

Return 1 if packet received with CRC ok
*/

uint32_t radio_crc_ok(void)
{
	return RADIO_EVENTS_CRCOK;
}

/*---------------------------------------------------------------------------*/
/** @brief RADIO Reset CRC check event

Clear CRCOK event and ready to check CRC for the next transmission/reception
*/

void radio_crc_ok_reset(void)
{
	RADIO_EVENTS_CRCOK = 0;
}


/**@}*/