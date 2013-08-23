/*
* This file is part of the libopencm3 project.
*
* Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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

#include <libopencm3/lpc43xx/uart.h>
#include <libopencm3/lpc43xx/cgu.h>

#define UART_SRC_32K             0x00
#define UART_SRC_IRC             0x01
#define UART_SRC_ENET_RX         0x02
#define UART_SRC_ENET_TX         0x03
#define UART_SRC_GP_CLKIN        0x04
#define UART_SRC_XTAL            0x06
#define UART_SRC_PLL0USB         0x07
#define UART_SRC_PLL0AUDIO       0x08
#define UART_SRC_PLL1            0x09
#define UART_SRC_IDIVA           0x0C
#define UART_SRC_IDIVB           0x0D
#define UART_SRC_IDIVC           0x0E
#define UART_SRC_IDIVD           0x0F
#define UART_SRC_IDIVE           0x10

#define UART_CGU_AUTOBLOCK_CLOCK_BIT     11
/* clock source selection (5 bits) */
#define UART_CGU_BASE_CLK_SEL_SHIFT      24

uint32_t dummy_read;

/*
* UART Init function
*/
void uart_init(uart_num_t uart_num, uart_databit_t data_nb_bits,
	    uart_stopbit_t data_nb_stop, uart_parity_t data_parity,
	    uint16_t uart_divisor, uint8_t uart_divaddval, uint8_t uart_mulval)
{
	uint32_t lcr_config;
	uint32_t uart_port;

	uart_port = uart_num;

	switch (uart_num) {
	case UART0_NUM:
		/* use PLL1 as clock source for UART0 */
		CGU_BASE_UART0_CLK = (1<<UART_CGU_AUTOBLOCK_CLOCK_BIT) |
			(CGU_SRC_PLL1<<UART_CGU_BASE_CLK_SEL_SHIFT);
		break;

	case UART1_NUM:
		/* use PLL1 as clock source for UART1 */
		CGU_BASE_UART1_CLK = (1<<UART_CGU_AUTOBLOCK_CLOCK_BIT) |
			(CGU_SRC_PLL1<<UART_CGU_BASE_CLK_SEL_SHIFT);
		break;

	case UART2_NUM:
		/* use PLL1 as clock source for UART2 */
		CGU_BASE_UART2_CLK = (1<<UART_CGU_AUTOBLOCK_CLOCK_BIT) |
			(CGU_SRC_PLL1<<UART_CGU_BASE_CLK_SEL_SHIFT);
		break;

	case UART3_NUM:
		/* use PLL1 as clock source for UART3 */
		CGU_BASE_UART3_CLK = (1<<UART_CGU_AUTOBLOCK_CLOCK_BIT) |
			(CGU_SRC_PLL1<<UART_CGU_BASE_CLK_SEL_SHIFT);
		break;

	default:
		return; /* error */
	}

	/* FIFOs RX/TX Enabled and Reset RX/TX FIFO (DMA Mode is also cleared)*/
	UART_FCR(uart_port) = (UART_FCR_FIFO_EN | UART_FCR_RX_RS |
				UART_FCR_TX_RS);
	/* Disable FIFO */
	UART_FCR(uart_port) = 0;

	/* Dummy read (to clear existing data) */
	while (UART_LSR(uart_port) & UART_LSR_RDR) {
		dummy_read = UART_RBR(uart_port);
	}

	/* Wait end of TX & disable TX */
	UART_TER(uart_port) = UART_TER_TXEN;

	/* Wait for current transmit complete */
	while (!(UART_LSR(uart_port) & UART_LSR_THRE));

	/* Disable Tx */
	UART_TER(uart_port) = 0;

	/* Disable interrupt */
	UART_IER(uart_port) = 0;

	/* Set LCR to default state */
	UART_LCR(uart_port) = 0;

	/* Set ACR to default state */
	UART_ACR(uart_port) = 0;

	/* Dummy Read to Clear Status */
	dummy_read = UART_LSR(uart_port);

	/*
	Table 835. USART Fractional Divider Register:
	UARTbaudrate = PCLK / ( 16* (((256*DLM)+ DLL)*(1+(DivAddVal/MulVal))) )
	The value of MULVAL and DIVADDVAL should comply to the following
	conditions:
	1. 1 <= MULVAL <= 15
	2. 0 <= DIVADDVAL <= 14
	3. DIVADDVAL < MULVAL
	*/

	/* Set DLAB Bit */
	UART_LCR(uart_port) |= UART_LCR_DLAB_EN;
	UART_DLM(uart_port) = UART_LOAD_DLM(uart_divisor);
	UART_DLL(uart_port) = UART_LOAD_DLL(uart_divisor);
	/* Clear DLAB Bit */
	UART_LCR(uart_port) &= (~UART_LCR_DLAB_EN) & UART_LCR_BITMASK;
	UART_FDR(uart_port) = UART_FDR_BITMASK &
	    (UART_FDR_MULVAL(uart_mulval) | UART_FDR_DIVADDVAL(uart_divaddval));

	/* Read LCR config & Force Enable of Divisor Latches Access */
	lcr_config = (UART_LCR(uart_port) & UART_LCR_DLAB_EN) &
			UART_LCR_BITMASK;
	lcr_config |= data_nb_bits; /* Set Nb Data Bits */
	lcr_config |= data_nb_stop; /* Set Nb Stop Bits */
	lcr_config |= data_parity; /* Set Data Parity */

	/* Write LCR (only 8bits) */
	UART_LCR(uart_port) = (lcr_config & UART_LCR_BITMASK);

	/* Enable TX */
	UART_TER(uart_port) = UART_TER_TXEN;
}

/*
* This Function return if data are received or not received.
*/
uart_rx_data_ready_t uart_rx_data_ready(uart_num_t uart_num)
{
	uint32_t uart_port;
	uint8_t uart_status;
	uart_rx_data_ready_t data_ready;

	uart_port = uart_num;

	uart_status = UART_LSR(uart_port) & 0xFF;

	/* Check Error */
	if ((uart_status & UART_LSR_ERROR_MASK) == 0) {
		/* No errors check if data is ready */
		if ((uart_status & UART_LSR_RDR) == 0) {
			data_ready = UART_RX_NO_DATA;
		} else {
			data_ready = UART_RX_DATA_READY;
		}
	} else {
		/* UART Error */
		data_ready = UART_RX_DATA_ERROR;
	}

	return data_ready;
}

/*
* This Function Wait until Data RX Ready, and return Data Read from UART.
*/
uint8_t uart_read(uart_num_t uart_num)
{
	uint32_t uart_port;
	uint8_t uart_val;

	uart_port = uart_num;

	/* Wait Until Data Received (Rx Data Not Ready) */
	while ((UART_LSR(uart_port) & UART_LSR_RDR) == 0);

	uart_val = (UART_RBR(uart_port) & UART_RBR_MASKBIT);

	return uart_val;
}

/*
* This Function Wait until Data RX Ready, and return Data Read from UART.
*/
uint8_t uart_read_timeout(uart_num_t uart_num, uint32_t rx_timeout_nb_cycles,
			    uart_error_t *error)
{
	uint32_t uart_port;
	uint8_t uart_val;
	uint32_t counter;

	uart_port = uart_num;

	/* Wait Until Data Received (Rx Data Not Ready) */
	counter = 0;
	while ((UART_LSR(uart_port) & UART_LSR_RDR) == 0) {
		if (rx_timeout_nb_cycles > 0) {
			counter++;
			if (counter >= rx_timeout_nb_cycles) {
				*error = UART_TIMEOUT_ERROR;
				return 0;
			}
		}
	}

	uart_val = (UART_RBR(uart_port) & UART_RBR_MASKBIT);

	/* Clear error */
	*error = UART_NO_ERROR;

	return uart_val;
}

/* This Function Wait Data TX Ready, and Write Data to UART
	if rx_timeout_nb_cycles = 0 Infinite wait
*/
void uart_write(uart_num_t uart_num, uint8_t data)
{
	uint32_t uart_port;

	uart_port = uart_num;

	/* Wait Until FIFO not full  */
	while ((UART_LSR(uart_port) & UART_LSR_THRE) == 0);

	UART_THR(uart_port) = data;
}

