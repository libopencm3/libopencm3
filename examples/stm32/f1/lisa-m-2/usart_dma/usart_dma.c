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

#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/f1/dma.h>
#include <libopencm3/cm3/nvic.h>

void clock_setup(void)
{
	rcc_clock_setup_in_hse_12mhz_out_72mhz();

	/* Enable GPIOA, GPIOB, GPIOC clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR,
				    RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN |
				    RCC_APB2ENR_IOPCEN);

	/* Enable clocks for GPIO port B (for GPIO_USART3_TX) and USART3. */
	rcc_peripheral_enable_clock(&RCC_APB1ENR,
				    RCC_APB1ENR_USART2EN);

	/* Enable DMA1 clock */
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_DMA1EN);
}

void usart_setup(void)
{
	/* Setup GPIO pin GPIO_USART2_TX and GPIO_USART2_RX. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART2_TX);
	gpio_set_mode(GPIOA, GPIO_MODE_INPUT,
		      GPIO_CNF_INPUT_FLOAT, GPIO_USART2_RX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART2, 38400);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX_RX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART2);

	nvic_set_priority(NVIC_DMA1_CHANNEL7_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL7_IRQ);

	nvic_set_priority(NVIC_DMA1_CHANNEL6_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL6_IRQ);

}

void dma_write(char *data, int size)
{
	/*
	 * Using channel 7 for USART2_TX
	 */

	/* Reset DMA channel*/
	dma_channel_reset(DMA1, DMA_CHANNEL7);

	dma_set_peripheral_address(DMA1, DMA_CHANNEL7, (u32)&USART2_DR);
	dma_set_memory_address(DMA1, DMA_CHANNEL7, (u32)data);
	dma_set_number_of_data(DMA1, DMA_CHANNEL7, size);
	dma_set_read_from_memory(DMA1, DMA_CHANNEL7);
	dma_enable_memory_increment_mode(DMA1, DMA_CHANNEL7);
	dma_set_peripheral_size(DMA1, DMA_CHANNEL7, DMA_CCR_PSIZE_8BIT);
	dma_set_memory_size(DMA1, DMA_CHANNEL7, DMA_CCR_MSIZE_8BIT);
	dma_set_priority(DMA1, DMA_CHANNEL7, DMA_CCR_PL_VERY_HIGH);

	dma_enable_transfer_complete_interrupt(DMA1, DMA_CHANNEL7);

	dma_enable_channel(DMA1, DMA_CHANNEL7);

        usart_enable_tx_dma(USART2);
}

volatile int transfered = 0;

void dma1_channel7_isr(void)
{
	if ((DMA1_ISR &DMA_ISR_TCIF7) != 0) {
		DMA1_IFCR |= DMA_IFCR_CTCIF7;

		transfered = 1;
	}

	dma_disable_transfer_complete_interrupt(DMA1, DMA_CHANNEL7);

	usart_disable_tx_dma(USART2);

	dma_disable_channel(DMA1, DMA_CHANNEL7);
}

void dma_read(char *data, int size)
{
	/*
	 * Using channel 6 for USART2_RX
	 */

	/* Reset DMA channel*/
	dma_channel_reset(DMA1, DMA_CHANNEL6);

	dma_set_peripheral_address(DMA1, DMA_CHANNEL6, (u32)&USART2_DR);
	dma_set_memory_address(DMA1, DMA_CHANNEL6, (u32)data);
	dma_set_number_of_data(DMA1, DMA_CHANNEL6, size);
	dma_set_read_from_peripheral(DMA1, DMA_CHANNEL6);
	dma_enable_memory_increment_mode(DMA1, DMA_CHANNEL6);
	dma_set_peripheral_size(DMA1, DMA_CHANNEL6, DMA_CCR_PSIZE_8BIT);
	dma_set_memory_size(DMA1, DMA_CHANNEL6, DMA_CCR_MSIZE_8BIT);
	dma_set_priority(DMA1, DMA_CHANNEL6, DMA_CCR_PL_HIGH);

	dma_enable_transfer_complete_interrupt(DMA1, DMA_CHANNEL6);

	dma_enable_channel(DMA1, DMA_CHANNEL6);

        usart_enable_rx_dma(USART2);
}

volatile int received = 0;

void dma1_channel6_isr(void)
{
	if ((DMA1_ISR &DMA_ISR_TCIF6) != 0) {
		DMA1_IFCR |= DMA_IFCR_CTCIF6;

		received = 1;
	}

	dma_disable_transfer_complete_interrupt(DMA1, DMA_CHANNEL6);

	usart_disable_rx_dma(USART2);

	dma_disable_channel(DMA1, DMA_CHANNEL6);
}

void gpio_setup(void)
{
	/* Set GPIO8 (in GPIO port A) to 'output push-pull'. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);
}

int main(void)
{
	char tx[10] = "abcdefg\r\n";
	int tx_len = 10;
	char rx[7] = "bcdefg";
	int rx_len = 6;

	clock_setup();
	gpio_setup();
	usart_setup();

	transfered = 0;
	dma_write(tx, tx_len);
	received = 0;
	dma_read(rx, rx_len);

	/* Blink the LED (PA8) on the board with every transmitted byte. */
	while (1) {
		gpio_toggle(GPIOA, GPIO8);	/* LED on/off */
		while ( transfered != 1) {
			if (received == 1) {
				tx[1] = rx[0];
				tx[2] = rx[1];
				tx[3] = rx[2];
				tx[4] = rx[3];
				tx[5] = rx[4];
				tx[6] = rx[5];
				received = 0;
				dma_read(rx, rx_len);
			}
		}
		tx[0]++;
		if (tx[0] > 'z') tx[0] = 'a';
		transfered = 0;
		dma_write(tx, tx_len);
	}

	return 0;
}
