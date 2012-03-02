/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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
#include <libopencm3/stm32/f1/flash.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/stm32/f1/dma.h>
#include <libopencm3/stm32/usart.h>

void usart_setup(void)
{
	/* Enable clocks for GPIO port A (for GPIO_USART1_TX) and USART1. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_USART1EN);

	/* Setup GPIO pin GPIO_USART1_TX/GPIO9 on GPIO port A for transmit. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART1_TX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART1, 115200);
	usart_set_databits(USART1, 8);
	usart_set_stopbits(USART1, USART_STOPBITS_1);
	usart_set_mode(USART1, USART_MODE_TX_RX);
	usart_set_parity(USART1, USART_PARITY_NONE);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART1);
}

void gpio_setup(void)
{
	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);

	/* Set GPIO6/7 (in GPIO port B) to 'output push-pull' for the LEDs. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO6);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO7);
}

void my_usart_print_string(u32 usart, char *s)
{
	while (*s != 0) {
		usart_send(usart, *s);
		s++;
	}
}

int main(void)
{
	/*
	 * Exactly 20 bytes including '\0' at the end.
	 * We want to transfer 32bit * 5 so it should fit.
	 */
	char s1[20] = "Hello STM MEM2MEM\r\n";
	char s2[20];

	rcc_clock_setup_in_hse_16mhz_out_72mhz();
	gpio_setup();
	usart_setup();

	gpio_clear(GPIOB, GPIO7);	/* LED1 on */
	gpio_set(GPIOB, GPIO6);		/* LED2 off */

	my_usart_print_string(USART1, "s1 ");
	my_usart_print_string(USART1, s1);

	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_DMA1EN);

	/* MEM2MEM mode for channel 1. */
	dma_enable_mem2mem_mode(DMA1, DMA_CHANNEL1);

	/* Highest priority. */
	dma_set_priority(DMA1, DMA_CHANNEL1, DMA_CCR_PL_VERY_HIGH);

	/* 32Bit wide transfer for source and destination. */
	dma_set_memory_size(DMA1, DMA_CHANNEL1, DMA_CCR_MSIZE_32BIT);
	dma_set_peripheral_size(DMA1, DMA_CHANNEL1, DMA_CCR_PSIZE_32BIT);

	/*
	 * After every 32bits we have to increase the address because
	 * we use RAM.
	 */
	dma_enable_memory_increment_mode(DMA1, DMA_CHANNEL1);
	dma_enable_peripheral_increment_mode(DMA1, DMA_CHANNEL1);

	/* We define the source as peripheral. */
	dma_set_read_from_peripheral(DMA1, DMA_CHANNEL1);

	/* We want to transfer string s1. */
	dma_set_peripheral_address(DMA1, DMA_CHANNEL1, (u32)&s1);

	/* Destination should be string s2. */
	dma_set_memory_address(DMA1, DMA_CHANNEL1, (u32)&s2);

	/*
	 * Set number of DATA to transfer.
	 * Remember that this means not necessary bytes but MSIZE or PSIZE
	 * depending on your source device.
	 */
	dma_set_number_of_data(DMA1, DMA_CHANNEL1, 5);

	/* Start DMA transfer. */
	dma_enable_channel(DMA1, DMA_CHANNEL1);

	/* TODO: Write a function to get the interrupt flags. */
	while (!(DMA_ISR(DMA1) & 0x0000001))
		;

	dma_disable_channel(DMA1, DMA_CHANNEL1);

	/* String s1 should now already be transferred to s2. */
	my_usart_print_string(USART1, "s2 ");
	my_usart_print_string(USART1, s2);

	gpio_clear(GPIOB, GPIO6);	/* LED2 on */

	while (1); /* Halt. */

	return 0;
}
