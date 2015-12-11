/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

/**
 * @defgroup uart_file UART
 *
 * @ingroup LM4Fxx
 *
 * @author @htmlonly &copy; @endhtmlonly 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
 *
 * \brief <b>libopencm3 LM4F Universal Asynchronous Receiver Transmitter</b>
 *
 * The LM4F UART API provides functionality for accessing the UART hardware of
 * the LM4F.
 *
 * Please see the individual UART modules for more details. To use the UART, the
 * uart.h header needs to be included:
 * @code{.c}
 *	#include <libopencm3/lm4f/uart.h>
 * @endcode
 *
 * @{
 */

#include <libopencm3/lm4f/uart.h>
#include <libopencm3/lm4f/systemcontrol.h>
#include <libopencm3/lm4f/rcc.h>

/** @defgroup uart_config UART configuration
 * @ingroup uart_file
 *
 * \brief <b>Enabling and configuring the UART</b>
 *
 * Enabling the UART is a two step process. The GPIO on which the UART resides
 * must be enabled, and the UART pins must be configured as alternate function,
 * digital pins. Pins must also be muxed to the appropriate alternate function.
 * This is done with the GPIO API.
 *
 * The second step involves enabling and the UART itself. The UART should be
 * disabled while it is being configured.
 *  -# The UART clock must be enabled with @ref periph_clock_enable().
 *  -# The UART must be disabled with @ref uart_disable().
 *  -# The UART clock source should be chosen before setting the baudrate.
 *  -# Baudrate, data bits, stop bit length, and parity can be configured.
 *  -# If needed, enable CTS or RTS lines via the @ref uart_set_flow_control().
 *  -# The UART can now be enabled with @ref uart_enable().
 *
 * For example, to enable UART1 at 115200 8n1 with hardware flow control:
 * @code{.c}
 *	// Enable the UART clock
 *	periph_clock_enable(RCC_UART1);
 *	// We need a brief delay before we can access UART config registers
 *	__asm__("nop"); __asm__("nop"); __asm__("nop");
 *	// Disable the UART while we mess with its settings
 *	uart_disable(UART1);
 *	// Configure the UART clock source as precision internal oscillator
 *	uart_clock_from_piosc();
 *	// Set communication parameters
 *	uart_set_baudrate(UART1, 115200);
 *	uart_set_databits(UART1, 8);
 *	uart_set_parity(UART1, UART_PARITY_NONE);
 *	uart_set_stopbits(UART1, 1);
 *	// Enable RTC and CTS lines
 *	uart_set_flow_control(UART1, UART_FLOWCTL_HARD_RTS_CTS);
 *	// Now that we're done messing with the settings, enable the UART
 *	uart_enable(UART1);
 * @endcode
 */
/**@{*/
/**
 * \brief Enable the UART
 *
 * Enable the UART. The Rx and Tx lines are also enabled.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_enable(uint32_t uart)
{
	UART_CTL(uart) |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
}

/**
 * \brief Disable the UART
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_disable(uint32_t uart)
{
	UART_CTL(uart) &= ~UART_CTL_UARTEN;
}

/**
 * \brief Set UART baudrate
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] baud Baud rate in bits per second (bps).*
 */
void uart_set_baudrate(uint32_t uart, uint32_t baud)
{
	uint32_t clock;

	/* Are we running off the internal clock or system clock? */
	if (UART_CC(uart) == UART_CC_CS_PIOSC) {
		clock = 16000000;
	} else {
		clock = rcc_get_system_clock_frequency();
	}

	/* Find the baudrate divisor */
	uint32_t div = (((clock * 8) / baud) + 1) / 2;

	/* Set the baudrate divisors */
	UART_IBRD(uart) = div / 64;
	UART_FBRD(uart) = div % 64;
}

/**
 * \brief Set UART databits
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] databits number of data bits per transmission.
 */
void uart_set_databits(uint32_t uart, uint8_t databits)
{
	uint32_t reg32, bitint32_t;

	/* This has the same effect as using UART_LCRH_WLEN_5/6/7/8 directly */
	bitint32_t = (databits - 5) << 5;

	/* TODO: What about 9 data bits? */

	reg32 = UART_LCRH(uart);
	reg32 &= ~UART_LCRH_WLEN_MASK;
	reg32 |= bitint32_t;
	UART_LCRH(uart) = reg32;
}

/**
 * \brief Set UART stopbits
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] bits the requested number of stopbits, either 1 or 2.
 */
void uart_set_stopbits(uint32_t uart, uint8_t stopbits)
{
	if (stopbits == 2) {
		UART_LCRH(uart) |= UART_LCRH_STP2;
	} else {
		UART_LCRH(uart) &= ~UART_LCRH_STP2;
	}
}

/**
 * \brief Set UART parity
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] bits the requested parity scheme.
 */
void uart_set_parity(uint32_t uart, enum uart_parity parity)
{
	uint32_t reg32;

	reg32 = UART_LCRH(uart);
	reg32 |= UART_LCRH_PEN;
	reg32 &= ~(UART_LCRH_SPS | UART_LCRH_EPS);

	switch (parity) {
	case UART_PARITY_NONE:
		/* Once we disable parity the other bits are meaningless */
		UART_LCRH(uart) &= ~UART_LCRH_PEN;
		return;
	case UART_PARITY_ODD:
		break;
	case UART_PARITY_EVEN:
		reg32 |= UART_LCRH_EPS;
		break;
	case UART_PARITY_STICK_0:
		reg32 |= (UART_LCRH_SPS | UART_LCRH_EPS);
		break;
	case UART_PARITY_STICK_1:
		reg32 |= UART_LCRH_SPS;
		break;
	}

	UART_LCRH(uart) = reg32;
}

/**
 * \brief Set the flow control scheme
 *
 * Set the flow control scheme by enabling or disabling RTS and CTS lines. This
 * will only have effect if the given UART supports the RTS and CTS lines.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] flow The flow control scheme to use (none, RTS, CTS or both) \n
 *                 UART_FLOWCTL_RTS -- enable the RTS line \n
 *                 UART_FLOWCTL_CTS -- enable the CTS line \n
 *                 UART_FLOWCTL_RTS_CTS -- enable both RTS and CTS lines
 */
void uart_set_flow_control(uint32_t uart, enum uart_flowctl flow)
{
	uint32_t reg32 = UART_CTL(uart);

	reg32 &= ~(UART_CTL_RTSEN | UART_CTL_CTSEN);

	if (flow == UART_FLOWCTL_RTS) {
		reg32 |= UART_CTL_RTSEN;
	} else if (flow == UART_FLOWCTL_CTS) {
		reg32 |= UART_CTL_CTSEN;
	} else if (flow == UART_FLOWCTL_RTS_CTS) {
		reg32 |= (UART_CTL_RTSEN | UART_CTL_CTSEN);
	}

	UART_CTL(uart) = reg32;
}

/**
 * \brief Clock the UART module from the internal oscillator
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_clock_from_piosc(uint32_t uart)
{
	UART_CC(uart) = UART_CC_CS_PIOSC;
}

/**
 * \brief Clock the UART module from the system clock
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_clock_from_sysclk(uint32_t uart)
{
	UART_CC(uart) = UART_CC_CS_SYSCLK;
}
/**@}*/

/** @defgroup uart_send_recv UART transmission and reception
 * @ingroup uart_file
 *
 * \brief <b>Sending and receiving data through the UART</b>
 *
 * Primitives for sending and receiving data are provided, @ref uart_send() and
 * @ref uart_recv(). These primitives do not check if data can be transmitted
 * or wait for data. If waiting until data is available or can be transmitted is
 * desired, blocking primitives are also available, @ref uart_send_blocking()
 * and @ref uart_recv_blocking().
 *
 * These primitives only handle one byte at at time, and thus may be unsuited
 * for some applications. You may also consider using @ref uart_dma.
 */
/**@{*/
/**
 * \brief UART Send a Data Word.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] data data to send.
 */
void uart_send(uint32_t uart, uint16_t data)
{
	data &= 0xFF;
	UART_DR(uart) = data;
}

/**
 * \brief UART Read a Received Data Word.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @return data from the Rx FIFO.
 */
uint16_t uart_recv(uint32_t uart)
{
	return UART_DR(uart) & UART_DR_DATA_MASK;
}

/**
 * \brief UART Wait for Transmit Data Buffer Not Full
 *
 * Blocks until the transmit data FIFO is not empty and can accept the next data
 * word.
 * \n
 * Even if the FIFO is not empty, this function will return as long as there is
 * room for at least one more word.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_wait_send_ready(uint32_t uart)
{
	/* Wait until the Tx FIFO is no longer full */
	while (UART_FR(uart) & UART_FR_TXFF);
}

/**
 * \brief UART Wait for Received Data Available
 *
 * Blocks until the receive data FIFO holds a at least valid received data word.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_wait_recv_ready(uint32_t uart)
{
	/* Wait until the Tx FIFO is no longer empty */
	while (UART_FR(uart) & UART_FR_RXFE);
}

/**
 * \brief UART Send Data Word with Blocking
 *
 * Blocks until the transmit data FIFO can accept the next data word for
 * transmission.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_send_blocking(uint32_t uart, uint16_t data)
{
	uart_wait_send_ready(uart);
	uart_send(uart, data);
}

/**
 * \brief UART Read a Received Data Word with Blocking.
 *
 * Wait until a data word has been received then return the word.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @return data from the Rx FIFO.
 */
uint16_t uart_recv_blocking(uint32_t uart)
{
	uart_wait_recv_ready(uart);
	return uart_recv(uart);
}
/**@}*/

/** @defgroup uart_irq UART Interrupt control
 * @ingroup uart_file
 *
 * \brief <b>Configuring interrupts from the UART</b>
 *
 * To have an event generate an interrupt, its interrupt source must be
 * unmasked. This can be achieved with @ref uart_enable_interrupts(). Interrupts
 * which are no longer needed can be disabled through
 * @ref uart_disable_interrupts().
 *
 * In order for the interrupt to generate an IRQ and a call to the interrupt
 * service routine, the interrupt for the target UART must be routed through the
 * NVIC with @ref nvic_enable_irq(). For this last step, the nvic.h header is
 * needed:
 * @code{.c}
 *	#include <libopencm3/lm4f/nvic.h>
 * @endcode
 *
 * Enabling an interrupt is as simple as unmasking the desired interrupt, and
 * routing the desired UART's interrupt through the NVIC.
 * @code{.c}
 *	// Unmask receive interrupt
 *	uart_enable_rx_interrupt(UART0);
 *	// Make sure the interrupt is routed through the NVIC
 *	nvic_enable_irq(NVIC_UART0_IRQ);
 * @endcode
 *
 * If a more than one interrupt is to be enabled at one time, the interrupts
 * can be enabled by a single call to @ref uart_enable_interrupts().
 * For example:
 * @code{.c}
 *	// Unmask receive, CTS, and RI, interrupts
 *	uart_enable_interrupts(UART0, UART_INT_RX | UART_INT_RI | UART_INT_CTS);
 * @endcode
 *
 * After interrupts are properly enabled and routed through the NVIC, when an
 * event occurs, the appropriate IRQ flag is set by hardware, and execution
 * jumps to the UART ISR. The ISR should query the IRQ flags to determine which
 * event caused the interrupt. For this, use @ref uart_is_interrupt_source(),
 * with the desired UART_INT flag. After one or more interrupt sources are
 * serviced, the IRQ flags must be cleared by the ISR. This can be done with
 * @ref uart_clear_interrupt_flag().
 *
 * A typical UART ISR may look like the following:
 * @code{.c}
 * void uart0_isr(void)
 * {
 *	uint32_t serviced_irqs = 0;
 *
 *	// Process individual IRQs
 *	if (uart_is_interrupt_source(UART0, UART_INT_RX)) {
 *		process_rx_event();
 *		serviced_irq |= UART_INT_RX;
 *	}
 *	if (uart_is_interrupt_source(UART0, UART_INT_CTS)) {
 *		process_cts_event();
 *		serviced_irq |= UART_INT_CTS;
 *	}
 *
 *	// Clear the interrupt flag for the processed IRQs
 *	uart_clear_interrupt_flag(UART0, serviced_irqs);
 * }
 * @endcode
 */
/**@{*/
/**
 * \brief Enable Specific UART Interrupts
 *
 * Enable any combination of interrupts. Interrupts may be OR'ed together to
 * enable them with one call. For example, to enable both the RX and CTS
 * interrupts, pass (UART_INT_RX | UART_INT_CTS)
 *
 * Note that the NVIC must be enabled and properly configured for the interrupt
 * to be routed to the CPU.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] ints Interrupts which to enable. Any combination of interrupts may
 *                 be specified by OR'ing then together
 */
void uart_enable_interrupts(uint32_t uart, enum uart_interrupt_flag ints)
{
	UART_IM(uart) |= ints;
}

/**
 * \brief Enable Specific UART Interrupts
 *
 * Disabe any combination of interrupts. Interrupts may be OR'ed together to
 * disable them with one call. For example, to disable both the RX and CTS
 * interrupts, pass (UART_INT_RX | UART_INT_CTS)
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] ints Interrupts which to disable. Any combination of interrupts
 *		   may be specified by OR'ing then together
 */
void uart_disable_interrupts(uint32_t uart, enum uart_interrupt_flag ints)
{
	UART_IM(uart) &= ~ints;
}

/**
 * \brief Enable the UART Receive Interrupt.
 *
 * Note that the NVIC must be enabled and properly configured for the interrupt
 * to be routed to the CPU.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_enable_rx_interrupt(uint32_t uart)
{
	uart_enable_interrupts(uart, UART_INT_RX);
}

/**
 * \brief Disable the UART Receive Interrupt.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_disable_rx_interrupt(uint32_t uart)
{
	uart_disable_interrupts(uart, UART_INT_RX);
}

/**
 * \brief Enable the UART Transmit Interrupt.
 *
 * Note that the NVIC must be enabled and properly configured for the interrupt
 * to be routed to the CPU.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_enable_tx_interrupt(uint32_t uart)
{
	uart_enable_interrupts(uart, UART_INT_TX);
}

/**
 * \brief Disable the UART Transmit Interrupt.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_disable_tx_interrupt(uint32_t uart)
{
	uart_disable_interrupts(uart, UART_INT_TX);
}

/**
 * \brief Mark interrupt as serviced
 *
 * After an interrupt is services, its flag must be cleared. If the flag is not
 * cleared, then execution will jump back to the start of the ISR after the ISR
 * returns.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] ints Interrupts which to clear. Any combination of interrupts may
 *                 be specified by OR'ing then together
 */
void uart_clear_interrupt_flag(uint32_t uart, enum uart_interrupt_flag ints)
{
	UART_ICR(uart) |= ints;
}
/**@}*/

/** @defgroup uart_dma UART DMA control
 * @ingroup uart_file
 *
 * \brief <b>Enabling Direct Memory Access transfers for the UART</b>
 *
 */
/**@{*/

/**
 * \brief Enable the UART Receive DMA.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_enable_rx_dma(uint32_t uart)
{
	UART_DMACTL(uart) |= UART_DMACTL_RXDMAE;
}

/**
 * \brief Disable the UART Receive DMA.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_disable_rx_dma(uint32_t uart)
{
	UART_DMACTL(uart) &= ~UART_DMACTL_RXDMAE;
}

/**
 * \brief Enable the UART Transmit DMA.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_enable_tx_dma(uint32_t uart)
{
	UART_DMACTL(uart) |= UART_DMACTL_TXDMAE;
}

/**
 * \brief Disable the UART Transmit DMA.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_disable_tx_dma(uint32_t uart)
{
	UART_DMACTL(uart) &= ~UART_DMACTL_TXDMAE;
}
/**@}*/

/** @defgroup uart_fifo UART FIFO control
 * @ingroup uart_file
 *
 * \brief <b>Enabling and controlling UART FIFO</b>
 *
 * The UART on the LM4F can either be used with a single character TX and RX
 * buffer, or with a 8 character TX and RX FIFO. In order to use the FIFO it
 * must be enabled, this is done with uart_enable_fifo() and can be disabled
 * again with uart_disable_fifo().  On reset the FIFO is disabled, and it must
 * be explicitly be enabled.
 *
 * When enabling the UART FIFOs, RX and TX interrupts are triggered according
 * to the amount of data in the FIFOs. For the RX FIFO the trigger level is
 * defined by how full the FIFO is.  The TX FIFO trigger level is defined by
 * how empty the FIFO is instead.
 *
 * For example, to enable the FIFOs and trigger interrupts for a single
 * received and single transmitted character:
 * @code{.c}
 *	uart_enable_fifo(UART0);
 *	uart_set_fifo_trigger_levels(UART0, UART_FIFO_RX_TRIG_1_8,
 *	                             UART_FIFO_TX_TRIG_7_8);
 * @endcode
 */
/**@{*/

/**
 * \brief Enable FIFO for the UART.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_enable_fifo(uint32_t uart)
{
	UART_LCRH(uart) |= UART_LCRH_FEN;
}

/**
 * \brief Disable FIFO for the UART.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
void uart_disable_fifo(uint32_t uart)
{
	UART_LCRH(uart) &= ~UART_LCRH_FEN;
}

/**
 * \brief Set the FIFO trigger levels.
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] rx_level Trigger level for RX FIFO
 * @param[in] tx_level Trigger level for TX FIFO
 */
void uart_set_fifo_trigger_levels(uint32_t uart,
				  enum uart_fifo_rx_trigger_level rx_level,
				  enum uart_fifo_tx_trigger_level tx_level)
{
	UART_IFLS(uart) = rx_level | tx_level;
}
/**@}*/


/**
 * @}
 */
