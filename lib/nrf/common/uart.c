/** @addtogroup uart_file UART peripheral API
 *
 * @brief <b>Access functions for the UART controller</b>
 *
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
 */

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

#include <libopencm3/nrf/uart.h>
#include <libopencm3/nrf/gpio.h>
/**@{*/

/** @brief Enable the peripheral
 *
 * @param[in] uart uint32_t uart base
 */
void uart_enable(uint32_t uart)
{
	UART_ENABLE(uart) = UART_ENABLE_ENABLED;
}

/** @brief Disable the peripheral
 *
 * @param[in] uart uint32_t uart base
 */
void uart_disable(uint32_t uart)
{
	UART_ENABLE(uart) = UART_ENABLE_DISABLED;
}

/** @brief Configure UART parameters in single call
 *
 * @details Any pin number can be set to 0xff (or any number larger than UART_MAX_PIN)
 *  to disconnect that pin.
 *
 * @param[in] uart uint32_t uart base
 * @param[in] tx_pin uint8_t TX pin number
 * @param[in] rx_pin uint8_t RX pin number
 * @param[in] rts_pin uint8_t RTS pin number
 * @param[in] cts_pin uint8_t CTS pin number
 * @param[in] br enum uart_baud baud rate
 * @param[in] enable_parity bool If true, enable parity bit
 */
void uart_configure(uint32_t uart,
		uint32_t tx_pin, uint32_t rx_pin, uint32_t rts_pin, uint32_t cts_pin,
		enum uart_baud br, bool enable_parity)
{
	uart_set_pins(uart, rx_pin, tx_pin, cts_pin, rts_pin);

	uint32_t reg_config = enable_parity ? UART_CONFIG_PARITY : 0;
	if (rts_pin <= UART_MAX_PIN || cts_pin <= UART_MAX_PIN) {
		reg_config |= UART_CONFIG_HWFC;
	}

	UART_CONFIG(uart) = reg_config;
	uart_set_baudrate(uart, br);
}

/** @brief Select GPIO pins to be used by this peripheral.
 *
 * This needs to be configured while UART peripheral is disabled.
 *
 * @param[in] uart uart peripheral base.
 * @param[in] rx RX pin. Use GPIO defines in @ref gpio_pin_id or GPIO_UNCONNECTED
 * if signal shall not be connected to any pin.
 * @param[in] tx TX pin. Use GPIO defines in @ref gpio_pin_id or GPIO_UNCONNECTED
 * if signal shall not be connected to any pin.
 * @param[in] cts CTS pin. Use GPIO defines in @ref gpio_pin_id or GPIO_UNCONNECTED
 * if signal shall not be connected to any pin.
 * @param[in] rts RTS pin. Use GPIO defines in @ref gpio_pin_id or GPIO_UNCONNECTED
 * if signal shall not be connected to any pin.

 */
void uart_set_pins(uint32_t uart, uint32_t rx, uint32_t tx, uint32_t cts, uint32_t rts)
{
	if (rx != GPIO_UNCONNECTED) {
		UART_PSELRXD(uart) = __GPIO2PIN(rx);
	} else {
		UART_PSELRXD(uart) = rx;
	}

	if (tx != GPIO_UNCONNECTED) {
		UART_PSELTXD(uart) = __GPIO2PIN(tx);
	} else {
		UART_PSELTXD(uart) = tx;
	}

	if (cts != GPIO_UNCONNECTED) {
		UART_PSELCTS(uart) = __GPIO2PIN(cts);
	} else {
		UART_PSELCTS(uart) = cts;
	}

	if (rts != GPIO_UNCONNECTED) {
		UART_PSELRTS(uart) = __GPIO2PIN(rts);
	} else {
		UART_PSELRTS(uart) = rts;
	}
}

#undef _LOG2

void uart_set_baudrate(uint32_t uart, enum uart_baud br)
{
	UART_BAUDRATE(uart) = br;
}

void uart_set_parity(uint32_t uart, int parity)
{
	UART_CONFIG(uart) |= parity ? UART_CONFIG_PARITY : 0;
}

void uart_set_flow_control(uint32_t uart, int flow)
{
	UART_CONFIG(uart) |= flow ? UART_CONFIG_HWFC : 0;
}

void uart_start_tx(uint32_t uart)
{
	PERIPH_TRIGGER_TASK(UART_TASK_STARTTX((uart)));
}

void uart_send(uint32_t uart, uint16_t byte)
{
	UART_TXD((uart)) = byte;
}

void uart_stop_tx(uint32_t uart)
{
	PERIPH_TRIGGER_TASK(UART_TASK_STOPTX((uart)));
}

void uart_start_rx(uint32_t uart)
{
	PERIPH_TRIGGER_TASK(UART_TASK_STARTRX((uart)));
}

uint16_t uart_recv(uint32_t uart)
{
	return UART_RXD(uart);
}

void uart_stop_rx(uint32_t uart)
{
	PERIPH_TRIGGER_TASK(UART_TASK_STOPRX((uart)));
}
/**@}*/

