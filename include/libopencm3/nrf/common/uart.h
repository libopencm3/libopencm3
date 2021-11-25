/** @addtogroup uart_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Maxim Sloyko <maxims@google.com>
 * @author @htmlonly &copy; @endhtmlonly 2021 Eduard Drusa <ventyl86 at netkosice dot sk>
 *
 **/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017-2018 Unicore MX project<dev(at)lists(dot)unicore-mx(dot)org>
 * Copyright (C) 2021 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
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

#include <libopencm3/cm3/common.h>
#include <libopencm3/nrf/memorymap.h>
#include <libopencm3/nrf/periph.h>

/**@{*/

/* Universal Asynchronous Receiver/Transmitter */

/** @addtogroup uart_block UART instance
 * @{
 */
#define UART0     UART0_BASE

/**@}*/

/* Tasks */

#define UART_TASK_STARTRX(uart)  MMIO32((uart) + 0x000)
#define UART_TASK_STOPRX(uart)   MMIO32((uart) + 0x004)
#define UART_TASK_STARTTX(uart)  MMIO32((uart) + 0x008)
#define UART_TASK_STOPTX(uart)   MMIO32((uart) + 0x00C)
#define UART_TASK_SUSPEND(uart)  MMIO32((uart) + 0x01C)

/* Events */

#define UART_EVENT_CTS(uart)     MMIO32((uart) + 0x100)
#define UART_EVENT_NCTS(uart)    MMIO32((uart) + 0x104)
#define UART_EVENT_RXDRDY(uart)  MMIO32((uart) + 0x108)
#define UART_EVENT_TXDRDY(uart)  MMIO32((uart) + 0x11C)
#define UART_EVENT_ERROR(uart)   MMIO32((uart) + 0x124)
#define UART_EVENT_RXTO(uart)    MMIO32((uart) + 0x144)

/* Registers */

#define UART_INTEN(uart)         _PERIPH_INTEN(uart)
#define UART_INTENSET(uart)      _PERIPH_INTENSET(uart)
#define UART_INTENCLR(uart)      _PERIPH_INTENCLR(uart)
#define UART_ERRORSRC(uart)      MMIO32((uart) + 0x480)
#define UART_ENABLE(uart)        MMIO32((uart) + 0x500)
#define UART_PSELRTS(uart)       MMIO32((uart) + 0x508)
#define UART_PSELTXD(uart)       MMIO32((uart) + 0x50C)
#define UART_PSELCTS(uart)       MMIO32((uart) + 0x510)
#define UART_PSELRXD(uart)       MMIO32((uart) + 0x514)
#define UART_RXD(uart)           MMIO32((uart) + 0x518)
#define UART_TXD(uart)           MMIO32((uart) + 0x51C)
#define UART_BAUDRATE(uart)      MMIO32((uart) + 0x524)
#define UART_CONFIG(uart)        MMIO32((uart) + 0x56C)

/* Register Contents */

/** @addtogroup uart_inten UART interrupt sources
 * @{
 */
#define UART_INTEN_CTS           (1 << 0)
#define UART_INTEN_NCTS          (1 << 1)
#define UART_INTEN_RXDRDY        (1 << 2)
#define UART_INTEN_TXDRDY        (1 << 7)
#define UART_INTEN_ERROR         (1 << 9)
#define UART_INTEN_RXTO          (1 << 17)

/**@}*/

#define UART_ERRORSRC_OVERRUN    (1 << 0)
#define UART_ERRORSRC_PARITY     (1 << 1)
#define UART_ERRORSRC_FRAMING    (1 << 2)
#define UART_ERRORSRC_BREAK      (1 << 3)

#define UART_ENABLE_ENABLED      (4)
#define UART_ENABLE_DISABLED     (0)
#define UART_CONFIG_HWFC         (1)
#define UART_CONFIG_PARITY       (7 << 1)

#define UART_PSEL_OFF            (0xff)
#define UART_MAX_PIN             (31)
#define UART_PSEL_VAL(p)         (p <= UART_MAX_PIN ? (uint32_t) p : 0xffffffff)


enum uart_baud {
	UART_BAUD_1200 = 0x0004F000,
	UART_BAUD_2400 = 0x0009D000,
	UART_BAUD_4800 = 0x0013B000,
	UART_BAUD_9600 = 0x00275000,
	UART_BAUD_14400 = 0x003B0000,
	UART_BAUD_19200 = 0x004EA000,
	UART_BAUD_28800 = 0x0075F000,
	UART_BAUD_38400 = 0x009D5000,
	UART_BAUD_57600 = 0x00EBF000,
	UART_BAUD_76800 = 0x013A9000,
	UART_BAUD_115200 = 0x01D7E000,
	UART_BAUD_230400 = 0x03AFB000,
	UART_BAUD_250000 = 0x04000000,
	UART_BAUD_460800 = 0x075F7000,
	UART_BAUD_921600 = 0x0EBEDFA4,
	UART_BAUD_1M = 0x10000000,
};


BEGIN_DECLS

void uart_enable(uint32_t uart);
void uart_disable(uint32_t uart);
void uart_configure(uint32_t uart,
uint32_t txd, uint32_t rxd, uint32_t rts, uint32_t cts,
enum uart_baud br, bool enable_parity);
void uart_set_baudrate(uint32_t uart, enum uart_baud br);
void uart_set_parity(uint32_t uart, int parity);
void uart_set_flow_control(uint32_t uart, int flow);
void uart_send_stop(uint32_t uart);

void uart_start_tx(uint32_t uart);
void uart_stop_tx(uint32_t uart);
void uart_send(uint32_t uart, uint16_t byte);
void uart_start_rx(uint32_t uart);
void uart_stop_rx(uint32_t uart);
uint16_t uart_recv(uint32_t uart);
void uart_set_pins(uint32_t uart, uint32_t rx, uint32_t tx, uint32_t cts, uint32_t rts);

END_DECLS

/**@}*/

