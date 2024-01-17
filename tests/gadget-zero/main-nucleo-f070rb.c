/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
 * Copyright (C) 2019 Daniel Gröber <dxld@darkboxed.org>
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

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/crs.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/flash.h>

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include "usb-gadget0.h"
#include "trace.h"

#define ER_DEBUG
/* no trace on cm0 #define ER_DEBUG */
#ifdef ER_DEBUG
#define ER_DPRINTF(fmt, ...) \
	do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define ER_DPRINTF(fmt, ...) \
	do { } while (0)
#endif

void trace_send_blocking8(int stimulus_port, char c)
{
	(void)stimulus_port;
	usart_send_blocking(USART2, c);
}

int _write(int file, char *ptr, int len)
{
	int i;

	if (file == STDOUT_FILENO || file == STDERR_FILENO) {
		for (i = 0; i < len; i++) {
			if (ptr[i] == '\n') {
				usart_send_blocking(USART2, '\r');
			}
			usart_send_blocking(USART2, ptr[i]);
		}
		return i;
	}
	errno = EIO;
	return -1;
}

int main(void)
{
	rcc_clock_setup_in_hse_8mhz_out_48mhz();
	rcc_set_usbclk_source(RCC_PLL);

	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_USART2);
	rcc_periph_clock_enable(RCC_USB);

	/* PA0/1 -> USART2_TX/RX AF */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2 | GPIO3);
	gpio_set_af(GPIOA, GPIO_AF1, GPIO2 | GPIO3);

	/* Enable UART connected to ST-Link */
	usart_set_baudrate(USART2, 115200);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX_RX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	usart_enable(USART2);

	/* LED on for boot progress */
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
	gpio_clear(GPIOA, GPIO5);

	usbd_device *usbd_dev = gadget0_init(&st_usbfs_v2_usb_driver,
					     "nucleo-f070rb");

	gpio_set(GPIOA, GPIO5);
	ER_DPRINTF("bootup complete\n");

	while (1) {
		gadget0_run(usbd_dev);
	}

}
