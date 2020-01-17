/** @addtogroup usart_defines
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Brian Viele <vielster@allocor.tech>
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
#ifndef LIBOPENCM3_STM32_COMMON_USART_COMMON_FIFOS_H_
#define LIBOPENCM3_STM32_COMMON_USART_COMMON_FIFOS_H_

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/common/usart_common_all.h>
#include <libopencm3/stm32/common/usart_common_v2.h>

/** @addtogroup usart_registers
@{*/
#define USART_PRESC(usart_base) MMIO32((usart_base) + 0x2C)
/**@}*/

/** @addtogroup usart_cr1_values
@{*/
/** RX FIFO Full Interrupt Enable. */
#define USART_CR1_RXFFIE BIT31
/** TX FIFO Empty Interrupt Enable. */
#define USART_CR1_TXFEIE BIT30
/** FIFO Enable bit. */
#define USART_CR1_FIFOEN BIT29
/**@}*/

/** @addtogroup usart_cr3_values
@{*/
/** FIFO Threshold definitions. */
typedef enum {
  USART_FIFO_THRESH_EIGTH = 0x0,
  USART_FIFO_THRESH_QUARTER = 0x1,
  USART_FIFO_THRESH_HALF = 0x2,
  USART_FIFO_THRESH_THREEQTR = 0x3,
  USART_FIFO_THRESH_SEVENEIGTH = 0x4,
  USART_FIFO_THRESH_TX_EMPTY = 0x5,
  USART_FIFO_THRESH_RX_FULL = 0x5,
  USART_FIFO_THRESH_MASK = 0x7
} usart_fifo_threshold_t;

/** TX FIFO Threshold Configuration bits. */
#define USART_CR3_TXFTCFG_SHIFT 29
/** RX FIFO THreshold Interrupt Enable. */
#define USART_CR3_RXFTIE BIT28
/** RX FIFO Threshold Configuration bits. */
#define USART_CR3_RXFTCFG_SHIFT 25
/** Transmission Complete Before Guard Time Enable bit. */
#define USART_CR3_TCBGTIE BIT24
/** TX FIFO THreshold Interrupt Enable. */
#define USART_CR3_TXFTIE BIT23
/**@}*/

/** @addtogroup usart_isr_values
@{*/
/** TX FIFO Threshold Interrupt Flag. */
#define USART_ISR_TXFT BIT27
/** RX FIFO Threshold Interrupt Flag. */
#define USART_ISR_RXFT BIT26
/** Transmission Complete before Guard Time Interrupt Flag. */
#define USART_ISR_TCBGT BIT25
/** RX FIFO Full Flag. */
#define USART_ISR_RXFF BIT24
/** TX FIFO Empty Flag. */
#define USART_ISR_TXFE BIT23
/** SPI Slave Underrun Flag. */
#define USART_ISR_UDR BIT13
/**@}*/

/** @addtogroup usart_icr_values
@{*/
/** SPI Slave Underrun Clear Flag. */
#define USART_ICR_UDR BIT13
/** TX FIFO Empty Clear Flag. */
#define USART_ICR_TXFECF BIT5
/**@}*/

BEGIN_DECLS

/** @addtogroup usart_file
@{*/
/**
 * Enable FIFOs on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFOs.
 */
void usart_enable_fifos(uint32_t usart);
/**
 * Disable FIFOs on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFOs.
 */
void usart_disable_fifos(uint32_t usart);
/**
 * Enable TX FIFO empty interrupt on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFO interrupt.
 */
void usart_enable_tx_fifo_empty_interrupt(uint32_t usart);
/**
 * Disable TX FIFO empty interrupt on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFO interrupt.
 */
void usart_disable_tx_fifo_empty_interrupt(uint32_t usart);
/**
 * Enable TX FIFO empty interrupt on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFO interrupt.
 */
void usart_enable_tx_fifo_threshold_interrupt(uint32_t usart);
/**
 * Disable TX FIFO empty interrupt on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFO interrupt.
 */
void usart_disable_tx_fifo_threshold_interrupt(uint32_t usart);
/**
 * Configure TX FIFO threshold on specified UART.
 * @param[in] usart  Base address of USART to configure FIFO.
 * @param[in] threshold  Threshold value to set for TX FIFO.
 */
void usart_set_tx_fifo_threshold(uint32_t usart,
         usart_fifo_threshold_t threshold);
/**
 * Enable RX FIFO full interrupt on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFO interrupt.
 */
void usart_enable_rx_fifo_full_interrupt(uint32_t usart);
/**
 * Disable RX FIFO full interrupt on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFO interrupt.
 */
void usart_disable_rx_fifo_full_interrupt(uint32_t usart);
/**
 * Enable RX FIFO threshold interrupt on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFO interrupt.
 */
void usart_enable_rx_fifo_threshold_interrupt(uint32_t usart);
/**
 * Disable RX FIFO threshold interrupt on the specified USART.
 * @param[in] usart  Base address of USART to configure FIFO interrupt.
 */
void usart_disable_rx_fifo_threshold_interrupt(uint32_t usart);
/**
 * Configure RX FIFO threshold on specified UART.
 * @param[in] usart  Base address of USART to configure FIFO.
 * @param[in] threshold  Threshold value to set for RX FIFO.
 */
void usart_set_rx_fifo_threshold(uint32_t usart,
         usart_fifo_threshold_t threshold);
/**@}*/
END_DECLS

#endif  /* LIBOPENCM3_STM32_COMMON_USART_COMMON_FIFOS_H_ */
