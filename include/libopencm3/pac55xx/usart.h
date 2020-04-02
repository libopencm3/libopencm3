/**
 * @brief USART definitions for the Qorvo PAC55xx series of microcontrollers
 *
 * @addtogroup PAC55xx_usart USART
 * @ingroup PAC55xx_defines
 * @author Kevin Stefanik <kevin@allocor.tech>
 * LGPL License Terms @ref lgpl_license
 * @date 25 Feb 2020
 *
 * Definitions in this file come from the PAC55XX Family User Guide Rev 1.23
 * by Active-Semi dated November 19, 2019. TX and RX hardware buffer sizes
 * are both 16 bytes.
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Kevin Stefanik <kevin@allocor.tech>
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
#ifndef LIBOPENCM3_PAC55XX_USART_H_
#define LIBOPENCM3_PAC55XX_USART_H_

#include <libopencm3/pac55xx/memorymap.h>
#include <libopencm3/cm3/common.h>

/**@{*/

/** @defgroup usart_registers Registers
@{*/
/** Receive Buffer Register RO, only bits 7:0 used */
#define USART_RBR(usart_base)   MMIO32((usart_base) + 0x0000)
/** Transmit Holding Register WO, only bits 7:0 used */
#define USART_THR(usart_base)   MMIO32((usart_base) + 0x0004)
/** Divisor Latch Register RW, default 0000 0001h, only bits 15:0 used.*/
#define USART_DLR(usart_base)   MMIO32((usart_base) + 0x0008)
/** Interrupt Enable Register RW, default 0000 0000h */
#define USART_IER(usart_base)   MMIO32((usart_base) + 0x000C)
/** Interrupt Identification Register RO, default 0000 0001h */
#define USART_IIR(usart_base)   MMIO32((usart_base) + 0x0010)
/** FIFO Control Register RW, default 0000 0000h */
#define USART_FCR(usart_base)   MMIO32((usart_base) + 0x0014)
/** Line control Register RW, default 0000 0000h */
#define USART_LCR(usart_base)   MMIO32((usart_base) + 0x0018)
/** Line Status Register RO, default 0000 0060h */
#define USART_LSR(usart_base)   MMIO32((usart_base) + 0x0020)
/** Scratch Pad Register RW, only bits 7:0 used */
#define USART_SCR(usart_base)   MMIO32((usart_base) + 0x0028)
/** Enhanced Mode Register RW, default 0000 000h */
#define USART_EFR(usart_base)   MMIO32((usart_base) + 0x002C)
/**@}*/

/** @defgroup usart_ier_bits Interrupt Enable Register bits
@{*/
/** Enable RX line status interrupt */
#define USART_IER_RLSIE         BIT2
/** Enable the TX Holding Empty interrupt */
#define USART_IER_THRIE         BIT1
/** Enable the RX Buffer Register Interrupt */
#define USART_IER_RBRIE         BIT0
/**@}*/

/** @defgroup usart_iir_bits Interrupt ID Register bits
@{*/
/** This bit is active low to indicate an interrupt is pending */
#define USART_IIR_INTSTATUS     BIT0
/** TX Holding Register Empty */
#define USART_IIR_TXEMPTY       (0x02)
/** Receive Data Available */
#define USART_IIR_RXAVAIL       (0x04)
/** Receive Line Status */
#define USART_IIR_RXLINESTAT    (0x06)
/** Receive FIFO Character Time-out */
#define USART_IIR_RXTIMEOUT     (0x0C)
/**@}*/

/** @defgroup usart_fcr_bits FIFO Control Register bits
@{*/
/** Enable both UART RX and TX FIFOs, must be set before writing rest of FCR */
#define USART_FCR_FIFOEN        BIT0
/** RX FIFO Reset. Write 1 to clear. This bit is self-clearing. */
#define USART_FCR_RXFIFORST     BIT1
/** TX FIFO Reset. Write 1 to clear. This bit is self-clearing. */
#define USART_FCR_TXFIFORST     BIT2
#define USART_FCR_TXTL_MASK     (3)
#define USART_FCR_TXTL_SHIFT    4
/** TX Trigger Level */
#define USART_FCR_TXTL(txtl)    (((txtl) & USART_FCR_TXTL_MASK) << USART_FCR_TXTL_SHIFT)
#define USART_FCR_RXTL_MASK     (3)
#define USART_FCR_RXTL_SHIFT    6
/** RX Trigger Level */
#define USART_FCR_RXTL(rxtl)    (((rxtl) & USART_FCR_RXTL_MASK) << USART_FCR_RXTL_SHIFT)
#define USART_FIFO_TRIG_1CHAR   (0)
#define USART_FIFO_TRIG_4CHAR   (1)
#define USART_FIFO_TRIG_8CHAR   (2)
#define USART_FIFO_TRIG_14CHAR  (3)
/**@}*/

/** @defgroup usart_lcr_bits Line Control Register bits
@{*/
/** LCR:WLS 5-bit character length */
#define USART_DATABITS_5        (0)
/** LCR:WLS 6-bit character length */
#define USART_DATABITS_6        (0x01)
/** LCR:WLS 7-bit character length */
#define USART_DATABITS_7        (0x02)
/** LCR:WLS 8-bit character length */
#define USART_DATABITS_8        (0x03)
/** LCR:PSEL & LCR:PEN Odd parity */
#define USART_PSELPEN_ODD       (0x01)
/** LCR:PSEL & LCR:PEN Even parity */
#define USART_PSELPEN_EVEN      (0x03)
/** LCR:PSEL & LCR:PEN Force 1 stick parity */
#define USART_PSELPEN_FORCE1    (0x05)
/** LCR:PSEL & LCR:PEN Force 0 stick parity */
#define USART_PSELPEN_FORCE0    (0x07)
/** LCR:PSEL & LCR:PEN Disable parity */
#define USART_PARITY_DISABLE    (0)
/** LCR:PSEL & LCR:PEN Odd parity */
#define USART_PARITY_ODD        USART_PSELPEN_ODD
/** LCR:PSEL & LCR:PEN Even parity */
#define USART_PARITY_EVEN       USART_PSELPEN_EVEN
/** LCR:PSEL & LCR:PEN Force 1 stick parity */
#define USART_PARITY_FORCE1     USART_PSELPEN_FORCE1
/** LCR:PSEL & LCR:PEN Force 0 stick parity */
#define USART_PARITY_FORCE0     USART_PSELPEN_FORCE0
/** LCR:SBS Use 1 stop bit */
#define USART_STOPBITS_1        (0)
/** LCR:SBS Use 1.5 stop bit when databits is 5 */
#define USART_STOPBITS_1P5      USART_LCR_SBS
/** LCR:SBS Use 2 stop bits */
#define USART_STOPBITS_2        USART_LCR_SBS
#define USART_LCR_WLS_MASK      (3)
/** Word length select: 5-8 databits */
#define USART_LCR_WLS(wls)      ((wls) & USART_LCR_WLS_MASK)
/** Set LCR:SBS for 1.5 or 2 stop bits, Clear for 1 stop bit */
#define USART_LCR_SBS           BIT2
/** Enable parity checking */
#define USART_LCR_PEN           BIT3
#define USART_LCR_PSELPEN_MASK  (7)
#define USART_LCR_PSELPEN_SHIFT 3
/** LCR:PSEL and LCR:PEN control parity */
#define USART_LCR_PSELPEN(psel) (((psel) & USART_LCR_PSELPEN_MASK) << USART_LCR_PSELPEN_SHIFT)
/** Break Control: Enabling this bit forces TX to logic 0 */
#define USART_LCR_BCON          BIT6
/**@}*/

/** @defgroup usart_lsr_bits Line Status Register bits
@{*/
/** Receiver Data Ready */
#define USART_LSR_RDR           BIT0
/** Overrun Error */
#define USART_LSR_OE            BIT1
/** Parity Error */
#define USART_LSR_PE            BIT2
/** Framing Error */
#define USART_LSR_FE            BIT3
/** Break Interrupt */
#define USART_LSR_BI            BIT4
/** Transmitter Holding Register Empty */
#define USART_LSR_THRE          BIT5
/** Transmitter Empty */
#define USART_LSR_TEMT          BIT6
/** Error in RX FIFO */
#define USART_LSR_RXFE          BIT7
/**@}*/

/** TX FIFO depth */
#define USART_TX_FIFO_DEPTH     (16)
/** RX FIFO depth */
#define USART_RX_FIFO_DETPH     (16)

/** Enable Enhanced Mode to use TX and RX FIFO trigger level interrupts */
#define USART_EFR_ENMODE        BIT4

/**@}*/

BEGIN_DECLS

uint32_t usart_set_baudrate(uint32_t usart, uint32_t baud);
void usart_configure_lcr(uint32_t usart, uint8_t data_bits, uint8_t stop_bits,
				uint8_t parity);
void usart_break_enable(uint32_t usart);
void usart_break_disable(uint32_t usart);
void usart_enhanced_enable(uint32_t usart);
void usart_enhanced_disable(uint32_t usart);
void usart_set_fifo_depth(uint32_t usart, uint8_t tx_depth, uint8_t rx_depth);
void usart_send(uint32_t usart, uint8_t data);
uint8_t usart_recv(uint32_t usart);
void usart_enable_rx_interrupt(uint32_t usart);
void usart_disable_rx_interrupt(uint32_t usart);
void usart_enable_tx_interrupt(uint32_t usart);
void usart_disable_tx_interrupt(uint32_t usart);
void usart_enable_rls_interrupt(uint32_t usart);
void usart_disable_rls_interrupt(uint32_t usart);
void usart_fifo_enable(uint32_t usart);
void usart_fifo_disable(uint32_t usart);
void usart_clear_tx_fifo(uint32_t usart);
void usart_clear_rx_fifo(uint32_t usart);

END_DECLS

#endif /* LIBOPENCM3_PAC55XX_USART_H_ */
