/** @addtogroup usart_defines

@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>

*/

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

/**@{*/

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA SPI.H */

#ifndef LIBOPENCM3_USART_COMMON_ALL_H
#define LIBOPENCM3_USART_COMMON_ALL_H

#include <libopencm3/cm3/common.h>

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup usart_reg_base USART register base addresses
@ingroup STM32F_usart_defines

@{*/
#define USART1				USART1_BASE
#define USART2				USART2_BASE
#define USART3				USART3_BASE
/**@}*/
#define UART4				UART4_BASE
#define UART5				UART5_BASE

/* --- USART registers ----------------------------------------------------- */

/* Status register (USARTx_SR) */
#define USART_SR(usart_base)		MMIO32(usart_base + 0x00)
#define USART1_SR			USART_SR(USART1_BASE)
#define USART2_SR			USART_SR(USART2_BASE)
#define USART3_SR			USART_SR(USART3_BASE)
#define UART4_SR			USART_SR(UART4_BASE)
#define UART5_SR			USART_SR(UART5_BASE)

/* Data register (USARTx_DR) */
#define USART_DR(usart_base)		MMIO32(usart_base + 0x04)
#define USART1_DR			USART_DR(USART1_BASE)
#define USART2_DR			USART_DR(USART2_BASE)
#define USART3_DR			USART_DR(USART3_BASE)
#define UART4_DR			USART_DR(UART4_BASE)
#define UART5_DR			USART_DR(UART5_BASE)

/* Baud rate register (USARTx_BRR) */
#define USART_BRR(usart_base)		MMIO32(usart_base + 0x08)
#define USART1_BRR			USART_BRR(USART1_BASE)
#define USART2_BRR			USART_BRR(USART2_BASE)
#define USART3_BRR			USART_BRR(USART3_BASE)
#define UART4_BRR			USART_BRR(UART4_BASE)
#define UART5_BRR			USART_BRR(UART5_BASE)

/* Control register 1 (USARTx_CR1) */
#define USART_CR1(usart_base)		MMIO32(usart_base + 0x0c)
#define USART1_CR1			USART_CR1(USART1_BASE)
#define USART2_CR1			USART_CR1(USART2_BASE)
#define USART3_CR1			USART_CR1(USART3_BASE)
#define UART4_CR1			USART_CR1(UART4_BASE)
#define UART5_CR1			USART_CR1(UART5_BASE)

/* Control register 2 (USARTx_CR2) */
#define USART_CR2(usart_base)		MMIO32(usart_base + 0x10)
#define USART1_CR2			USART_CR2(USART1_BASE)
#define USART2_CR2			USART_CR2(USART2_BASE)
#define USART3_CR2			USART_CR2(USART3_BASE)
#define UART4_CR2			USART_CR2(UART4_BASE)
#define UART5_CR2			USART_CR2(UART5_BASE)

/* Control register 3 (USARTx_CR3) */
#define USART_CR3(usart_base)		MMIO32(usart_base + 0x14)
#define USART1_CR3			USART_CR3(USART1_BASE)
#define USART2_CR3			USART_CR3(USART2_BASE)
#define USART3_CR3			USART_CR3(USART3_BASE)
#define UART4_CR3			USART_CR3(UART4_BASE)
#define UART5_CR3			USART_CR3(UART5_BASE)

/* Guard time and prescaler register (USARTx_GTPR) */
#define USART_GTPR(usart_base)		MMIO32(usart_base + 0x18)
#define USART1_GTPR			USART_GTPR(USART1_BASE)
#define USART2_GTPR			USART_GTPR(USART2_BASE)
#define USART3_GTPR			USART_GTPR(USART3_BASE)
#define UART4_GTPR			USART_GTPR(UART4_BASE)
#define UART5_GTPR			USART_GTPR(UART5_BASE)

/* --- USART_SR values ----------------------------------------------------- */
/****************************************************************************/
/** @defgroup usart_sr_flags USART Status register Flags
@ingroup STM32F_usart_defines

@{*/

/** CTS: CTS flag */
/** @note: undefined on UART4 and UART5 */
#define USART_SR_CTS			(1 << 9)

/** LBD: LIN break detection flag */
#define USART_SR_LBD			(1 << 8)

/** TXE: Transmit data buffer empty */
#define USART_SR_TXE			(1 << 7)

/** TC: Transmission complete */
#define USART_SR_TC			(1 << 6)

/** RXNE: Read data register not empty */
#define USART_SR_RXNE			(1 << 5)

/** IDLE: Idle line detected */
#define USART_SR_IDLE			(1 << 4)

/** ORE: Overrun error */
#define USART_SR_ORE			(1 << 3)

/** NE: Noise error flag */
#define USART_SR_NE			(1 << 2)

/** FE: Framing error */
#define USART_SR_FE			(1 << 1)

/** PE: Parity error */
#define USART_SR_PE			(1 << 0)
/**@}*/

/* --- USART_DR values ----------------------------------------------------- */

/* USART_DR[8:0]: DR[8:0]: Data value */
#define USART_DR_MASK                   0x1FF

/* --- USART_BRR values ---------------------------------------------------- */

/* DIV_Mantissa[11:0]: mantissa of USARTDIV */
#define USART_BRR_DIV_MANTISSA_MASK     (0xFFF << 4)
/* DIV_Fraction[3:0]: fraction of USARTDIV */
#define USART_BRR_DIV_FRACTION_MASK     0xF

/* --- USART_CR1 values ---------------------------------------------------- */

/* UE: USART enable */
#define USART_CR1_UE			(1 << 13)

/* M: Word length */
#define USART_CR1_M			(1 << 12)

/* WAKE: Wakeup method */
#define USART_CR1_WAKE			(1 << 11)

/* PCE: Parity control enable */
#define USART_CR1_PCE			(1 << 10)

/* PS: Parity selection */
#define USART_CR1_PS			(1 << 9)

/* PEIE: PE interrupt enable */
#define USART_CR1_PEIE			(1 << 8)

/* TXEIE: TXE interrupt enable */
#define USART_CR1_TXEIE			(1 << 7)

/* TCIE: Transmission complete interrupt enable */
#define USART_CR1_TCIE			(1 << 6)

/* RXNEIE: RXNE interrupt enable */
#define USART_CR1_RXNEIE		(1 << 5)

/* IDLEIE: IDLE interrupt enable */
#define USART_CR1_IDLEIE		(1 << 4)

/* TE: Transmitter enable */
#define USART_CR1_TE			(1 << 3)

/* RE: Receiver enable */
#define USART_CR1_RE			(1 << 2)

/* RWU: Receiver wakeup */
#define USART_CR1_RWU			(1 << 1)

/* SBK: Send break */
#define USART_CR1_SBK			(1 << 0)

/* --- USART_CR2 values ---------------------------------------------------- */

/* LINEN: LIN mode enable */
#define USART_CR2_LINEN			(1 << 14)

/* STOP[13:12]: STOP bits */
#define USART_CR2_STOPBITS_1		(0x00 << 12)     /* 1 stop bit */
#define USART_CR2_STOPBITS_0_5		(0x01 << 12)     /* 0.5 stop bits */
#define USART_CR2_STOPBITS_2		(0x02 << 12)     /* 2 stop bits */
#define USART_CR2_STOPBITS_1_5		(0x03 << 12)     /* 1.5 stop bits */
#define USART_CR2_STOPBITS_MASK         (0x03 << 12)
#define USART_CR2_STOPBITS_SHIFT        12

/* CLKEN: Clock enable */
#define USART_CR2_CLKEN			(1 << 11)

/* CPOL: Clock polarity */
#define USART_CR2_CPOL			(1 << 10)

/* CPHA: Clock phase */
#define USART_CR2_CPHA			(1 << 9)

/* LBCL: Last bit clock pulse */
#define USART_CR2_LBCL			(1 << 8)

/* LBDIE: LIN break detection interrupt enable */
#define USART_CR2_LBDIE			(1 << 6)

/* LBDL: LIN break detection length */
#define USART_CR2_LBDL			(1 << 5)

/* ADD[3:0]: Addres of the usart node */
#define USART_CR2_ADD_MASK              0xF

/* --- USART_CR3 values ---------------------------------------------------- */

/* CTSIE: CTS interrupt enable */
/* Note: N/A on UART4 & UART5 */
#define USART_CR3_CTSIE			(1 << 10)

/* CTSE: CTS enable */
/* Note: N/A on UART4 & UART5 */
#define USART_CR3_CTSE			(1 << 9)

/* RTSE: RTS enable */
/* Note: N/A on UART4 & UART5 */
#define USART_CR3_RTSE			(1 << 8)

/* DMAT: DMA enable transmitter */
/* Note: N/A on UART5 */
#define USART_CR3_DMAT			(1 << 7)

/* DMAR: DMA enable receiver */
/* Note: N/A on UART5 */
#define USART_CR3_DMAR			(1 << 6)

/* SCEN: Smartcard mode enable */
/* Note: N/A on UART4 & UART5 */
#define USART_CR3_SCEN			(1 << 5)

/* NACK: Smartcard NACK enable */
/* Note: N/A on UART4 & UART5 */
#define USART_CR3_NACK			(1 << 4)

/* HDSEL: Half-duplex selection */
#define USART_CR3_HDSEL			(1 << 3)

/* IRLP: IrDA low-power */
#define USART_CR3_IRLP			(1 << 2)

/* IREN: IrDA mode enable */
#define USART_CR3_IREN			(1 << 1)

/* EIE: Error interrupt enable */
#define USART_CR3_EIE			(1 << 0)

/* --- USART_GTPR values --------------------------------------------------- */

/* GT[7:0]: Guard time value */
/* Note: N/A on UART4 & UART5 */
#define USART_GTPR_GT_MASK              (0xFF << 8)

/* PSC[7:0]: Prescaler value */
/* Note: N/A on UART4/5 */
#define USART_GTPR_PSC_MASK             0xFF

/* TODO */ /* Note to Uwe: what needs to be done here? */

/* --- Convenience defines ------------------------------------------------- */

/* CR1_PCE / CR1_PS combined values */
/****************************************************************************/
/** @defgroup usart_cr1_parity USART Parity Selection
@ingroup STM32F_usart_defines

@{*/
#define USART_PARITY_NONE		0x00
#define USART_PARITY_EVEN		USART_CR1_PCE
#define USART_PARITY_ODD		(USART_CR1_PS | USART_CR1_PCE)
/**@}*/
#define USART_PARITY_MASK		(USART_CR1_PS | USART_CR1_PCE)

/* CR1_TE/CR1_RE combined values */
/****************************************************************************/
/** @defgroup usart_cr1_mode USART Tx/Rx Mode Selection
@ingroup STM32F_usart_defines

@{*/
#define USART_MODE_RX                   USART_CR1_RE
#define USART_MODE_TX		        USART_CR1_TE
#define USART_MODE_TX_RX		(USART_CR1_RE | USART_CR1_TE)
/**@}*/
#define USART_MODE_MASK		        (USART_CR1_RE | USART_CR1_TE)

/****************************************************************************/
/** @defgroup usart_cr2_stopbits USART Stop Bit Selection
@ingroup STM32F_usart_defines

@{*/
#define USART_STOPBITS_1		USART_CR2_STOPBITS_1   /* 1 stop bit */
#define USART_STOPBITS_0_5		USART_CR2_STOPBITS_0_5 /* 0.5 stop bits */
#define USART_STOPBITS_2		USART_CR2_STOPBITS_2   /* 2 stop bits */
#define USART_STOPBITS_1_5		USART_CR2_STOPBITS_1_5 /* 1.5 stop bits */
/**@}*/

/* CR3_CTSE/CR3_RTSE combined values */
/****************************************************************************/
/** @defgroup usart_cr3_flowcontrol USART Hardware Flow Control Selection
@ingroup STM32F_usart_defines

@{*/
#define USART_FLOWCONTROL_NONE	        0x00
#define USART_FLOWCONTROL_RTS	        USART_CR3_RTSE
#define USART_FLOWCONTROL_CTS	        USART_CR3_CTSE
#define USART_FLOWCONTROL_RTS_CTS	(USART_CR3_RTSE | USART_CR3_CTSE)
/**@}*/
#define USART_FLOWCONTROL_MASK	        (USART_CR3_RTSE | USART_CR3_CTSE)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void usart_set_baudrate(u32 usart, u32 baud);
void usart_set_databits(u32 usart, u32 bits);
void usart_set_stopbits(u32 usart, u32 stopbits);
void usart_set_parity(u32 usart, u32 parity);
void usart_set_mode(u32 usart, u32 mode);
void usart_set_flow_control(u32 usart, u32 flowcontrol);
void usart_enable(u32 usart);
void usart_disable(u32 usart);
void usart_send(u32 usart, u16 data);
u16 usart_recv(u32 usart);
void usart_wait_send_ready(u32 usart);
void usart_wait_recv_ready(u32 usart);
void usart_send_blocking(u32 usart, u16 data);
u16 usart_recv_blocking(u32 usart);
void usart_enable_rx_dma(u32 usart);
void usart_disable_rx_dma(u32 usart);
void usart_enable_tx_dma(u32 usart);
void usart_disable_tx_dma(u32 usart);
void usart_enable_rx_interrupt(u32 usart);
void usart_disable_rx_interrupt(u32 usart);
void usart_enable_tx_interrupt(u32 usart);
void usart_disable_tx_interrupt(u32 usart);
void usart_enable_error_interrupt(u32 usart);
void usart_disable_error_interrupt(u32 usart);
bool usart_get_flag(u32 usart, u32 flag);
bool usart_get_interrupt_source(u32 usart, u32 flag);

END_DECLS

#endif
/**@}*/

