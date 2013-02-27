/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2013 Stephen Dwyer <scdwyer@ualberta.ca>
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

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/dma.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/spi.h>
#include <stdio.h>
#include <errno.h>

#ifndef USE_16BIT_TRANSFERS
#define USE_16BIT_TRANSFERS 1
#endif

/* This is for the counter state flag */
typedef enum {
	TX_UP_RX_HOLD = 0,
	TX_HOLD_RX_UP,
	TX_DOWN_RX_DOWN
} cnt_state;

/* This is a global spi state flag */
typedef enum {
	NONE = 0,
	ONE,
	DONE
} trans_status;

volatile trans_status transceive_status;

int _write(int file, char *ptr, int len);

static void clock_setup(void)
{
	rcc_clock_setup_in_hse_12mhz_out_72mhz();

	/* Enable GPIOA, GPIOB, GPIOC clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR,
				    RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN |
				    RCC_APB2ENR_IOPCEN);

	/* Enable clocks for GPIO port A (for GPIO_USART2_TX) and USART2. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN |
				    RCC_APB2ENR_AFIOEN);
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);

	/* Enable SPI1 Periph and gpio clocks */
	rcc_peripheral_enable_clock(&RCC_APB2ENR,
				    RCC_APB2ENR_SPI1EN);

	/* Enable DMA1 clock */
	rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_DMA1EN);
}

static void spi_setup(void) {

	/* Configure GPIOs: SS=PA4, SCK=PA5, MISO=PA6 and MOSI=PA7
	 * For now ignore the SS pin so we can use it to time the ISRs
	 */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
            GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, /* GPIO4 | */
            								GPIO5 |
                                            GPIO7 );

	gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT,
			GPIO6);

	/* Reset SPI, SPI_CR1 register cleared, SPI is disabled */
	spi_reset(SPI1);

	/* Explicitly disable I2S in favour of SPI operation */
	SPI1_I2SCFGR = 0;

	/* Set up SPI in Master mode with:
	 * Clock baud rate: 1/64 of peripheral clock frequency
	 * Clock polarity: Idle High
	 * Clock phase: Data valid on 2nd clock pulse
	 * Data frame format: 8-bit or 16-bit
	 * Frame format: MSB First
	 */
#if USE_16BIT_TRANSFERS
	spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_64, SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE,
			SPI_CR1_CPHA_CLK_TRANSITION_2, SPI_CR1_DFF_16BIT, SPI_CR1_MSBFIRST);
#else
	spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_64, SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE,
			SPI_CR1_CPHA_CLK_TRANSITION_2, SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);
#endif

	/*
	 * Set NSS management to software.
	 *
	 * Note:
	 * Setting nss high is very important, even if we are controlling the GPIO
	 * ourselves this bit needs to be at least set to 1, otherwise the spi
	 * peripheral will not send any data out.
	 */
	spi_enable_software_slave_management(SPI1);
	spi_set_nss_high(SPI1);

	/* Enable SPI1 periph. */
	spi_enable(SPI1);
}

static void dma_int_enable(void) {
	/* SPI1 RX on DMA1 Channel 2 */
 	nvic_set_priority(NVIC_DMA1_CHANNEL2_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL2_IRQ);
	/* SPI1 TX on DMA1 Channel 3 */
	nvic_set_priority(NVIC_DMA1_CHANNEL3_IRQ, 0);
	nvic_enable_irq(NVIC_DMA1_CHANNEL3_IRQ);
}

/* Not used in this example
static void dma_int_disable(void) {
 	nvic_disable_irq(NVIC_DMA1_CHANNEL2_IRQ);
 	nvic_disable_irq(NVIC_DMA1_CHANNEL3_IRQ);
}
*/

static void dma_setup(void)
{
	dma_int_enable();	
}

#if USE_16BIT_TRANSFERS
static int spi_dma_transceive(u16 *tx_buf, int tx_len, u16 *rx_buf, int rx_len)
#else
static int spi_dma_transceive(u8 *tx_buf, int tx_len, u8 *rx_buf, int rx_len)
#endif
{
	/* Check for 0 length in both tx and rx */
	if ((rx_len < 1) && (tx_len < 1)) {
		/* return -1 as error */
		return -1;
	}

	/* Reset DMA channels*/
	dma_channel_reset(DMA1, DMA_CHANNEL2);
	dma_channel_reset(DMA1, DMA_CHANNEL3);

	/* Reset SPI data and status registers.
	 * Here we assume that the SPI peripheral is NOT
	 * busy any longer, i.e. the last activity was verified
	 * complete elsewhere in the program.
	 */
	volatile u8 temp_data __attribute__ ((unused));
	while (SPI_SR(SPI1) & (SPI_SR_RXNE | SPI_SR_OVR)) {
		temp_data = SPI_DR(SPI1);
	}

	/* Reset status flag appropriately (both 0 case caught above) */
	transceive_status = NONE;
	if (rx_len < 1) {
		transceive_status = ONE;
	}
	if (tx_len < 1) {
		transceive_status = ONE;
	}

	/* Set up rx dma, note it has higher priority to avoid overrun */
	if (rx_len > 0) {
		dma_set_peripheral_address(DMA1, DMA_CHANNEL2, (u32)&SPI1_DR);
		dma_set_memory_address(DMA1, DMA_CHANNEL2, (u32)rx_buf);
		dma_set_number_of_data(DMA1, DMA_CHANNEL2, rx_len);
		dma_set_read_from_peripheral(DMA1, DMA_CHANNEL2);
		dma_enable_memory_increment_mode(DMA1, DMA_CHANNEL2);
#if USE_16BIT_TRANSFERS
		dma_set_peripheral_size(DMA1, DMA_CHANNEL2, DMA_CCR_PSIZE_16BIT);
		dma_set_memory_size(DMA1, DMA_CHANNEL2, DMA_CCR_MSIZE_16BIT);
#else
		dma_set_peripheral_size(DMA1, DMA_CHANNEL2, DMA_CCR_PSIZE_8BIT);
		dma_set_memory_size(DMA1, DMA_CHANNEL2, DMA_CCR_MSIZE_8BIT);
#endif
		dma_set_priority(DMA1, DMA_CHANNEL2, DMA_CCR_PL_VERY_HIGH);
	}

	/* Set up tx dma */
	if (tx_len > 0) {
		dma_set_peripheral_address(DMA1, DMA_CHANNEL3, (u32)&SPI1_DR);
		dma_set_memory_address(DMA1, DMA_CHANNEL3, (u32)tx_buf);
		dma_set_number_of_data(DMA1, DMA_CHANNEL3, tx_len);
		dma_set_read_from_memory(DMA1, DMA_CHANNEL3);
		dma_enable_memory_increment_mode(DMA1, DMA_CHANNEL3);
#if USE_16BIT_TRANSFERS
		dma_set_peripheral_size(DMA1, DMA_CHANNEL3, DMA_CCR_PSIZE_16BIT);
		dma_set_memory_size(DMA1, DMA_CHANNEL3, DMA_CCR_MSIZE_16BIT);
#else
		dma_set_peripheral_size(DMA1, DMA_CHANNEL3, DMA_CCR_PSIZE_8BIT);
		dma_set_memory_size(DMA1, DMA_CHANNEL3, DMA_CCR_MSIZE_8BIT);
#endif
		dma_set_priority(DMA1, DMA_CHANNEL3, DMA_CCR_PL_HIGH);
	}

	/* Enable dma transfer complete interrupts */
	if (rx_len > 0) {
		dma_enable_transfer_complete_interrupt(DMA1, DMA_CHANNEL2);
	}
	if (tx_len > 0) {
		dma_enable_transfer_complete_interrupt(DMA1, DMA_CHANNEL3);
	}

	/* Activate dma channels */
	if (rx_len > 0) {
		dma_enable_channel(DMA1, DMA_CHANNEL2);
	}
	if (tx_len > 0) {
		dma_enable_channel(DMA1, DMA_CHANNEL3);
	}

	/* Enable the spi transfer via dma
	 * This will immediately start the transmission,
	 * after which when the receive is complete, the
	 * receive dma will activate
	 */
	if (rx_len > 0) {
    	spi_enable_rx_dma(SPI1);
    }
    if (tx_len > 0) {
    	spi_enable_tx_dma(SPI1);
    }

    return 0;
}

/* SPI receive completed with DMA */
void dma1_channel2_isr(void)
{
	gpio_set(GPIOA,GPIO4);
	if ((DMA1_ISR &DMA_ISR_TCIF2) != 0) {
		DMA1_IFCR |= DMA_IFCR_CTCIF2;
	}

	dma_disable_transfer_complete_interrupt(DMA1, DMA_CHANNEL2);

	spi_disable_rx_dma(SPI1);

	dma_disable_channel(DMA1, DMA_CHANNEL2);

	/* Increment the status to indicate one of the transfers is complete */
	transceive_status++;
	gpio_clear(GPIOA,GPIO4);
}

/* SPI transmit completed with DMA */
void dma1_channel3_isr(void)
{
	gpio_set(GPIOB,GPIO1);
	if ((DMA1_ISR &DMA_ISR_TCIF3) != 0) {
		DMA1_IFCR |= DMA_IFCR_CTCIF3;
	}

	dma_disable_transfer_complete_interrupt(DMA1, DMA_CHANNEL3);

	spi_disable_tx_dma(SPI1);

	dma_disable_channel(DMA1, DMA_CHANNEL3);

	/* Increment the status to indicate one of the transfers is complete */
	transceive_status++;
	gpio_clear(GPIOB,GPIO1);
}

static void usart_setup(void)
{
	/* Setup GPIO pin GPIO_USART2_TX and GPIO_USART2_RX. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART2_TX);
	gpio_set_mode(GPIOA, GPIO_MODE_INPUT,
		      GPIO_CNF_INPUT_FLOAT, GPIO_USART2_RX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART2, 9600);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX_RX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART2);
}

int _write(int file, char *ptr, int len)
{
	int i;

	if (file == 1) {
		for (i = 0; i < len; i++)
			usart_send_blocking(USART2, ptr[i]);
		return i;
	}

	errno = EIO;
	return -1;
}

static void gpio_setup(void)
{
	/* Set GPIO8 (in GPIO port A) to 'output push-pull'. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO8);

	/* Use the extra pins to signal when the ISRs are running */
	/* First, SPI1 - SS pin on Lisa/M v2.0 */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO4);
	/* Then, SPI1 - DRDY pin on Lisa/M v2.0 */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL, GPIO1);

}

int main(void)
{
	int counter_tx = 0;
	int counter_rx = 0;

	cnt_state counter_state = TX_UP_RX_HOLD;

	int i = 0;

	/* Transmit and Receive packets, set transmit to index and receive to known unused value to aid in debugging */
#if USE_16BIT_TRANSFERS
	u16 tx_packet[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	u16 rx_packet[16] = {0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42};
#else
	u8 tx_packet[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	u8 rx_packet[16] = {0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42};
#endif

	transceive_status = DONE;

	clock_setup();
	gpio_setup();
	usart_setup();
	spi_setup();
	dma_setup();

#if USE_16BIT_TRANSFERS
	printf("SPI with DMA Transfer Test using 16bit option (Use loopback)\r\n\r\n");
#else
	printf("SPI with DMA Transfer Test using 8bit option (Use loopback)\r\n\r\n");
#endif

	/* Blink the LED (PA8) on the board with every transmitted byte. */
	while (1) {
		/* LED on/off */
		gpio_toggle(GPIOA, GPIO8);

		/* Print what is going to be sent on the SPI bus */
		printf("Sending  packet (tx len %02i):", counter_tx);
		for (i = 0; i < counter_tx; i++)
		{
			printf(" 0x%02x,", tx_packet[i]);
		}
		printf("\r\n");

		/* Start a transceive */
		if (spi_dma_transceive(tx_packet, counter_tx, rx_packet, counter_rx)) {
			printf("Attempted 0 length tx and rx packets\r\n");
		}

		/* Wait until transceive complete.
		 * This checks the state flag as well as follows the
		 * procedure on the Reference Manual (RM0008 rev 14
		 * Section 25.3.9 page 692, the note.)
		 */
		while (transceive_status != DONE)
			;
		while (!(SPI_SR(SPI1) & SPI_SR_TXE))
			;
		while (SPI_SR(SPI1) & SPI_SR_BSY)
			;

		/* Print what was received on the SPI bus */
		printf("Received Packet (rx len %02i):", counter_rx);
		for (i = 0; i < 16; i++) {
			printf(" 0x%02x,", rx_packet[i]);
		}
		printf("\r\n\r\n");

		/* Update counters
		 * If we use the loopback method, we can not
		 * have a rx length longer than the tx length.
		 * Testing rx lengths longer than tx lengths
		 * requires an actual slave device that will
		 * return data.
		 */
		switch (counter_state) {
			case TX_UP_RX_HOLD:
				counter_tx++;
				if (counter_tx > 15) {
					counter_state = TX_HOLD_RX_UP;
				}
				break;
			case TX_HOLD_RX_UP:
				counter_rx++;
				if (counter_rx > 15) {
					counter_state = TX_DOWN_RX_DOWN;
				}
				break;
			case TX_DOWN_RX_DOWN:
				counter_tx--;
				counter_rx--;
				if (counter_tx < 1) {
					counter_state = TX_UP_RX_HOLD;
				}
				break;
			default:
				;
		}

		/* Reset receive buffer for consistency */
		for (i = 0; i < 16; i++) {
			rx_packet[i] = 0x42;
		}		
	}

	return 0;
}
