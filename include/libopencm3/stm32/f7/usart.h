/** @defgroup usart_defines USART Defines

@brief <b>Defined Constants and Types for the STM32F4xx USART</b>

@ingroup STM32F4xx_defines

@version 1.0.0

@date 5 December 2012

LGPL License Terms @ref lgpl_license
 */

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

#ifndef LIBOPENCM3_USART_H
#define LIBOPENCM3_USART_H

#include <libopencm3/stm32/common/usart_common_all.h>

#define USART6				USART6_BASE
#define USART7				USART7_BASE


/* --- USART registers ----------------------------------------------------- */

/* Control register 1 (USARTx_CR1) */
#define USART_CR1(usart_base)		MMIO32((usart_base) + 0x00)
#define USART1_CR1			USART_CR1(USART1_BASE)
#define USART2_CR1			USART_CR1(USART2_BASE)
#define USART3_CR1			USART_CR1(USART3_BASE)
#define UART4_CR1			USART_CR1(UART4_BASE)
#define UART5_CR1			USART_CR1(UART5_BASE)

/* Control register 2 (USARTx_CR2) */
#define USART_CR2(usart_base)		MMIO32((usart_base) + 0x04)
#define USART1_CR2			USART_CR2(USART1_BASE)
#define USART2_CR2			USART_CR2(USART2_BASE)
#define USART3_CR2			USART_CR2(USART3_BASE)
#define UART4_CR2			USART_CR2(UART4_BASE)
#define UART5_CR2			USART_CR2(UART5_BASE)

/* Control register 3 (USARTx_CR3) */
#define USART_CR3(usart_base)		MMIO32((usart_base) + 0x08)
#define USART1_CR3			USART_CR3(USART1_BASE)
#define USART2_CR3			USART_CR3(USART2_BASE)
#define USART3_CR3			USART_CR3(USART3_BASE)
#define UART4_CR3			USART_CR3(UART4_BASE)
#define UART5_CR3			USART_CR3(UART5_BASE)

/* Baud rate register (USARTx_BRR) */
#define USART_BRR(usart_base)		MMIO32((usart_base) + 0x0C)
#define USART1_BRR			USART_BRR(USART1_BASE)
#define USART2_BRR			USART_BRR(USART2_BASE)
#define USART3_BRR			USART_BRR(USART3_BASE)
#define UART4_BRR			USART_BRR(UART4_BASE)
#define UART5_BRR			USART_BRR(UART5_BASE)

/* Guard time and prescaler register (USARTx_GTPR) */
#define USART_GTPR(usart_base)		MMIO32((usart_base) + 0x10)
#define USART1_GTPR			USART_GTPR(USART1_BASE)
#define USART2_GTPR			USART_GTPR(USART2_BASE)
#define USART3_GTPR			USART_GTPR(USART3_BASE)
#define UART4_GTPR			USART_GTPR(UART4_BASE)
#define UART5_GTPR			USART_GTPR(UART5_BASE)

/* Receiver timeout register (USARTx_RTOR) */
#define USART_RTOR(usart_base)		MMIO32((usart_base) + 0x14)
#define USART1_RTOR			USART_RTOR(USART1_BASE)
#define USART2_RTOR			USART_RTOR(USART2_BASE)
#define USART3_RTOR			USART_RTOR(USART3_BASE)
#define UART4_RTOR			USART_RTOR(UART4_BASE)
#define UART5_RTOR			USART_RTOR(UART5_BASE)

/* Request register (USARTx_RQR) */
#define USART_RQR(usart_base)		MMIO32((usart_base) + 0x18)
#define USART1_RQR			USART_RQR(USART1_BASE)
#define USART2_RQR			USART_RQR(USART2_BASE)
#define USART3_RQR			USART_RQR(USART3_BASE)
#define UART4_RQR			USART_RQR(UART4_BASE)
#define UART5_RQR			USART_RQR(UART5_BASE)

/* Interrupt and status register (USARTx_ISR) */
#define USART_ISR(usart_base)		MMIO32((usart_base) + 0x1C)
#define USART1_ISR			USART_ISR(USART1_BASE)
#define USART2_ISR			USART_ISR(USART2_BASE)
#define USART3_ISR			USART_ISR(USART3_BASE)
#define UART4_ISR			USART_ISR(UART4_BASE)
#define UART5_ISR			USART_ISR(UART5_BASE)

/* FOR COMPATABILITY */
/* Interrupt and status register (USARTx_ISR) */
#define USART_SR(usart_base)		MMIO32((usart_base) + 0x1C)
#define USART1_SR			USART_SR(USART1_BASE)
#define USART2_SR			USART_SR(USART2_BASE)
#define USART3_SR			USART_SR(USART3_BASE)
#define UART4_SR			USART_SR(UART4_BASE)
#define UART5_SR			USART_SR(UART5_BASE)

/* Interrupt flag clear register (USARTx_ICR) */
#define USART_ICR(usart_base)		MMIO32((usart_base) + 0x20)
#define USART1_ICR			USART_ICR(USART1_BASE)
#define USART2_ICR			USART_ICR(USART2_BASE)
#define USART3_ICR			USART_ICR(USART3_BASE)
#define UART4_ICR			USART_ICR(UART4_BASE)
#define UART5_ICR			USART_ICR(UART5_BASE)

/* Receive Data register (USARTx_RDR) */
#define USART_RDR(usart_base)		MMIO32((usart_base) + 0x24)
#define USART1_RDR			USART_RDR(USART1_BASE)
#define USART2_RDR			USART_RDR(USART2_BASE)
#define USART3_RDR			USART_RDR(USART3_BASE)
#define UART4_RDR			USART_RDR(UART4_BASE)
#define UART5_RDR			USART_RDR(UART5_BASE)

/* Transmit Data register (USARTx_TDR) */
#define USART_TDR(usart_base)		MMIO32((usart_base) + 0x28)
#define USART1_TDR			USART_TDR(USART1_BASE)
#define USART2_TDR			USART_TDR(USART2_BASE)
#define USART3_TDR			USART_TDR(USART3_BASE)
#define UART4_TDR			USART_TDR(UART4_BASE)
#define UART5_TDR			USART_TDR(UART5_BASE)


/* --- USART_SR values ----------------------------------------------------- */
/****************************************************************************/
/** @defgroup usart_sr_flags USART Status register Flags
@ingroup STM32F_usart_defines

@{*/

/** CTS: CTS flag */
/** @note: undefined on UART4 and UART5 */
#define USART_ISR_CTS			(1 << 9)
#define USART_SR_CTS			USART_ISR_CTS

/** LBD: LIN break detection flag */
#define USART_ISR_LBD			(1 << 8)
#define USART_SR_LBD			USART_ISR_LBD

/** TXE: Transmit data buffer empty */
#define USART_ISR_TXE			(1 << 7)
#define USART_SR_TXE			USART_ISR_TXE

/** TC: Transmission complete */
#define USART_ISR_TC			(1 << 6)
#define USART_SR_TC			    USART_ISR_TC

/** RXNE: Read data register not empty */
#define USART_ISR_RXNE			(1 << 5)
#define USART_SR_RXNE			USART_ISR_RXNE

/** IDLE: Idle line detected */
#define USART_ISR_IDLE			(1 << 4)
#define USART_SR_IDLE			USART_ISR_IDLE

/** ORE: Overrun error */
#define USART_ISR_ORE			(1 << 3)
#define USART_SR_ORE			USART_ISR_ORE

/** NE: Noise error flag */
#define USART_ISR_NE			(1 << 2)
#define USART_SR_NE			    USART_ISR_NE

/** FE: Framing error */
#define USART_ISR_FE			(1 << 1)
#define USART_SR_FE			    USART_ISR_FE

/** PE: Parity error */
#define USART_ISR_PE			(1 << 0)
#define USART_SR_PE			    USART_ISR_PE
/**@}*/

/* --- USART_DR values ----------------------------------------------------- */

/* USART_DR[8:0]: DR[8:0]: Data value */
#define USART_DR_MASK                   0x1FF
#define USART_TDR_MASK                  0x1FF
#define USART_RDR_MASK                  0x1FF

/* --- USART_BRR values ---------------------------------------------------- */

/* DIV_Mantissa[11:0]: mantissa of USARTDIV */
#define USART_BRR_DIV_MANTISSA_MASK     (0xFFF << 4)
/* DIV_Fraction[3:0]: fraction of USARTDIV */
#define USART_BRR_DIV_FRACTION_MASK     0xF

/* --- USART_CR1 values ---------------------------------------------------- */

/* M: Word length */
#define USART_CR1_M			(1 << 28)

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

/* UE: USART enable */
#define USART_CR1_UE			(1 << 0)


/* --- USART_CR2 values ---------------------------------------------------- */

/* LINEN: LIN mode enable */
#define USART_CR2_LINEN			(1 << 14)

/* STOP[13:12]: STOP bits */
#define USART_CR2_STOPBITS_1		(0x00 << 12)     /* 1 stop bit */
#define USART_CR2_STOPBITS_0_5		(0x01 << 12)     /* 0.5 stop bits */
#define USART_CR2_STOPBITS_2		(0x02 << 12)     /* 2 stop bits */
#define USART_CR2_STOPBITS_1_5		(0x03 << 12)     /* 1.5 stop bits */
#define USART_CR2_STOPBITS_MASK     (0x03 << 12)
#define USART_CR2_STOPBITS_SHIFT    12

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

/* ADD[3:0]: Address of the usart node */
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



#endif

