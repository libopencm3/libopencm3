/*
 * This file is part of the libopencm3 project.
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

#include <libopencm3/stm32/usart.h>

void usart_enable_fifos(uint32_t usart) {
	USART_CR1(usart) |= USART_CR1_FIFOEN;
}

void usart_disable_fifos(uint32_t usart) {
	USART_CR1(usart) &= ~USART_CR1_FIFOEN;
}

void usart_enable_tx_fifo_empty_interrupt(uint32_t usart) {
	USART_CR1(usart) |= USART_CR1_TXFEIE;
}

void usart_disable_tx_fifo_empty_interrupt(uint32_t usart) {
	USART_CR1(usart) &= ~USART_CR1_TXFEIE;
}

void usart_enable_tx_fifo_threshold_interrupt(uint32_t usart) {
	USART_CR3(usart) |= USART_CR3_TXFTIE;
}

void usart_disable_tx_fifo_threshold_interrupt(uint32_t usart) {
	USART_CR3(usart) &= ~USART_CR3_TXFTIE;
}

void usart_set_tx_fifo_threshold(uint32_t usart,
				 usart_fifo_threshold_t threshold) {
	uint32_t cr3 = USART_CR3(usart) &
		       ~(USART_FIFO_THRESH_MASK << USART_CR3_TXFTCFG_SHIFT);
	USART_CR3(usart) = cr3 | (threshold << USART_CR3_TXFTCFG_SHIFT);
}

void usart_enable_rx_fifo_full_interrupt(uint32_t usart) {
	USART_CR1(usart) |= USART_CR1_RXFFIE;
}

void usart_disable_rx_fifo_full_interrupt(uint32_t usart) {
	USART_CR1(usart) &= ~USART_CR1_RXFFIE;
}

void usart_enable_rx_fifo_threshold_interrupt(uint32_t usart) {
	USART_CR3(usart) |= USART_CR3_RXFTIE;
}

void usart_disable_rx_fifo_threshold_interrupt(uint32_t usart) {
	USART_CR3(usart) &= ~USART_CR3_RXFTIE;
}

void usart_set_rx_fifo_threshold(uint32_t usart,
				 usart_fifo_threshold_t threshold) {
	uint32_t cr3 = USART_CR3(usart) &
		       ~(USART_FIFO_THRESH_MASK << USART_CR3_RXFTCFG_SHIFT);
	USART_CR3(usart) = cr3 | (threshold << USART_CR3_RXFTCFG_SHIFT);
}
