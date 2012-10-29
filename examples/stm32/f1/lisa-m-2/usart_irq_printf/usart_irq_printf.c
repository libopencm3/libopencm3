/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>,
 * Copyright (C) 2011 Piotr Esden-Tempski <piotr@esden.net>
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

#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include <stdio.h>
#include <errno.h>

/******************************************************************************
 * Simple ringbuffer implementation from open-bldc's libgovernor that
 * you can find at:
 * https://github.com/open-bldc/open-bldc/tree/master/source/libgovernor
 *****************************************************************************/

typedef s32 ring_size_t;

struct ring {
	u8 *data;
	ring_size_t size;
	u32 begin;
	u32 end;
};

#define RING_SIZE(RING)  ((RING)->size - 1)
#define RING_DATA(RING)  (RING)->data
#define RING_EMPTY(RING) ((RING)->begin == (RING)->end)

void ring_init(struct ring *ring, u8 *buf, ring_size_t size)
{
	ring->data = buf;
	ring->size = size;
	ring->begin = 0;
	ring->end = 0;
}

s32 ring_write_ch(struct ring *ring, u8 ch)
{
	if (((ring->end + 1) % ring->size) != ring->begin) {
		ring->data[ring->end++] = ch;
		ring->end %= ring->size;
		return (u32)ch;
	}

	return -1;
}

s32 ring_write(struct ring *ring, u8 *data, ring_size_t size)
{
	s32 i;

	for (i = 0; i < size; i++) {
		if (ring_write_ch(ring, data[i]) < 0)
			return -i;
	}

	return i;
}

s32 ring_read_ch(struct ring *ring, u8 *ch)
{
	s32 ret = -1;

	if (ring->begin != ring->end) {
		ret = ring->data[ring->begin++];
		ring->begin %= ring->size;
		if (ch)
			*ch = ret;
	}

	return ret;
}

s32 ring_read(struct ring *ring, u8 *data, ring_size_t size)
{
	s32 i;

	for (i = 0; i < size; i++) {
		if (ring_read_ch(ring, data + i) < 0)
			return i;
	}

	return -i;
}

/******************************************************************************
 * The example implementation
 *****************************************************************************/

#define BUFFER_SIZE 1024

struct ring output_ring;
u8 output_ring_buffer[BUFFER_SIZE];

void clock_setup(void)
{
	rcc_clock_setup_in_hse_12mhz_out_72mhz();

	/* Enable GPIOA clock (for LED GPIOs). */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);

	/* Enable clocks for GPIO port A (for GPIO_USART2_TX) and USART2. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN |
				    RCC_APB2ENR_AFIOEN);
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);
}

void usart_setup(void)
{
	/* Initialize output ring buffer. */
	ring_init(&output_ring, output_ring_buffer, BUFFER_SIZE);

	/* Enable the USART2 interrupt. */
	nvic_enable_irq(NVIC_USART2_IRQ);

	/* Setup GPIO pin GPIO_USART2_TX on GPIO port A for transmit. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART2_TX);

	/* Setup GPIO pin GPIO_USART2_RX on GPIO port A for receive. */
	gpio_set_mode(GPIOA, GPIO_MODE_INPUT,
		      GPIO_CNF_INPUT_FLOAT, GPIO_USART2_RX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART2, 230400);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
	usart_set_mode(USART2, USART_MODE_TX_RX);

	/* Enable USART2 Receive interrupt. */
	USART_CR1(USART2) |= USART_CR1_RXNEIE;

	/* Finally enable the USART. */
	usart_enable(USART2);
}

void gpio_setup(void)
{
	gpio_set(GPIOA, GPIO8);

	/* Setup GPIO8 (in GPIO port A) for LED use. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);
}

void usart2_isr(void)
{
	/* Check if we were called because of RXNE. */
	if (((USART_CR1(USART2) & USART_CR1_RXNEIE) != 0) &&
	    ((USART_SR(USART2) & USART_SR_RXNE) != 0)) {

		/* Indicate that we got data. */
		gpio_toggle(GPIOA, GPIO8);

		/* Retrieve the data from the peripheral. */
		ring_write_ch(&output_ring, usart_recv(USART2));

		/* Enable transmit interrupt so it sends back the data. */
		USART_CR1(USART2) |= USART_CR1_TXEIE;
	}

	/* Check if we were called because of TXE. */
	if (((USART_CR1(USART2) & USART_CR1_TXEIE) != 0) &&
	    ((USART_SR(USART2) & USART_SR_TXE) != 0)) {

		s32 data;

		data = ring_read_ch(&output_ring, NULL);

		if (data == -1) {
			/* Disable the TXE interrupt, it's no longer needed. */
			USART_CR1(USART2) &= ~USART_CR1_TXEIE;
		} else {
			/* Put data into the transmit register. */
			usart_send(USART2, data);
		}
	}
}

int _write(int file, char *ptr, int len)
{
	int ret;

	if (file == 1) {
		ret = ring_write(&output_ring, (u8 *)ptr, len);

		if (ret < 0)
			ret = -ret;

		USART_CR1(USART2) |= USART_CR1_TXEIE;

		return ret;
	}

	errno = EIO;
	return -1;
}

void systick_setup(void)
{
	/* 72MHz / 8 => 9000000 counts per second. */
	systick_set_clocksource(STK_CTRL_CLKSOURCE_AHB_DIV8);

	/* 9000000/9000 = 1000 overflows per second - every 1ms one interrupt */
	systick_set_reload(9000);

	systick_interrupt_enable();

	/* Start counting. */
	systick_counter_enable();
}

void sys_tick_handler(void)
{
	static int counter = 0;
	static float fcounter = 0.0;
	static double dcounter = 0.0;
	static u32 temp32 = 0;

	temp32++;

	/*
	 * We call this handler every 1ms so we are sending hello world
	 * every 10ms / 100Hz.
	 */
	if (temp32 == 10) {
		printf("Hello World! %i %f %f\r\n", counter, fcounter,
		       dcounter);
		counter++;
		fcounter += 0.01;
		dcounter += 0.01;

		temp32 = 0;
	}
}

int main(void)
{
	clock_setup();
	gpio_setup();
	usart_setup();
	systick_setup();

	while (1)
		__asm__("nop");

	return 0;
}
