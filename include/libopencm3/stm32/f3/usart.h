/** @defgroup usart_defines USART Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F3xx USART</b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 5 December 2012
 *
 * LGPL License Terms @ref lgpl_license
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
#include <libopencm3/stm32/common/usart_common_v2.h>

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

/* Receiver timeout register (USART_RTOR) */
#define USART_RTOR(usart_base)		MMIO32((usart_base) + 0x14)
#define USART1_RTOR			USART_RTOR(USART1_BASE)
#define USART2_RTOR			USART_RTOR(USART2_BASE)
#define USART3_RTOR			USART_RTOR(USART3_BASE)
#define UART4_RTOR			USART_RTOR(UART4_BASE)
#define UART5_RTOR			USART_RTOR(UART5_BASE)

/* Request register (USART_RQR) */
#define USART_RQR(usart_base)		MMIO32((usart_base) + 0x18)
#define USART1_RQR			USART_RQR(USART1_BASE)
#define USART2_RQR			USART_RQR(USART2_BASE)
#define USART3_RQR			USART_RQR(USART3_BASE)
#define UART4_RQR			USART_RQR(UART4_BASE)
#define UART5_RQR			USART_RQR(UART5_BASE)

/* Interrupt & status register (USART_ISR) */
#define USART_ISR(usart_base)		MMIO32((usart_base) + 0x1C)
#define USART1_ISR			USART_ISR(USART1_BASE)
#define USART2_ISR			USART_ISR(USART2_BASE)
#define USART3_ISR			USART_ISR(USART3_BASE)
#define UART4_ISR			USART_ISR(UART4_BASE)
#define UART5_ISR			USART_ISR(UART5_BASE)

/* Interrupt flag clear register (USART_ICR) */
#define USART_ICR(usart_base)		MMIO32((usart_base) + 0x20)
#define USART1_ICR			USART_ICR(USART1_BASE)
#define USART2_ICR			USART_ICR(USART2_BASE)
#define USART3_ICR			USART_ICR(USART3_BASE)
#define UART4_ICR			USART_ICR(UART4_BASE)
#define UART5_ICR			USART_ICR(UART5_BASE)

/* Receive data register (USART_RDR) */
#define USART_RDR(usart_base)		MMIO32((usart_base) + 0x24)
#define USART1_RDR			USART_RDR(USART1_BASE)
#define USART2_RDR			USART_RDR(USART2_BASE)
#define USART3_RDR			USART_RDR(USART3_BASE)
#define UART4_RDR			USART_RDR(UART4_BASE)
#define UART5_RDR			USART_RDR(UART5_BASE)

/* Transmit data register (USART_TDR) */
#define USART_TDR(usart_base)		MMIO32((usart_base) + 0x28)
#define USART1_TDR			USART_TDR(USART1_BASE)
#define USART2_TDR			USART_TDR(USART2_BASE)
#define USART3_TDR			USART_TDR(USART3_BASE)
#define UART4_TDR			USART_TDR(UART4_BASE)
#define UART5_TDR			USART_TDR(UART5_BASE)


/* --- USART_CR1 values ---------------------------------------------------- */

/* EOBIE: End of Block interrupt enable */
#define USART_CR1_EOBIE			(1 << 27)

/* RTOIE: Receiver timeout interrupt enable */
#define USART_CR1_RTOIE			(1 << 26)

/* DEAT[4:0]: Driver Enable assertion time */

/* DEDT[4:0]: Driver Enable deassertion time */

/* OVER8: Oversampling mode */
#define USART_CR1_OVER8			(1 << 15)

/* CMIE: Character match interrupt enable */
#define USART_CR1_CMIE			(1 << 14)

/* MME: Mute mode enable */
#define USART_CR1_MME			(1 << 13)

/* M: Word length */
#define USART_CR1_M			(1 << 12)

/* WAKE: Receiver wakeup method */
#define USART_CR1_WAKE			(1 << 11)

/* PCE: Parity control enable */
#define USART_CR1_PCE			(1 << 10)

/* PS: Parity selection */
#define USART_CR1_PS			(1 << 9)

/* PEIE: PE interrupt enable */
#define USART_CR1_PEIE			(1 << 8)

/* TXEIE: Interrupt enable */
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

/* UESM: USART enable in Stop mode */
#define USART_CR1_UESM			(1 << 1)

/* UE: USART enable */
#define USART_CR1_UE			(1 << 0)


/* --- USART_CR2 values ---------------------------------------------------- */

/* ADD[7:4]: Address of the USART node (31,28) */
#define USART_CR2_ADD1_MASK              (0xF << 28)

/* ADD[3:0]: Address of the USART node (27,24) */
#define USART_CR2_ADD2_MASK              (0xF << 24)

/* RTOEN: Receiver timeout enable */
#define USART_CR2_RTOEN			(1 << 23)

/* ABRMOD[1:0]: Auto baud rate mode */
#define USART_CR2_ABRMOD_BAUD		(0x0 << 21)
#define USART_CR2_ABRMOD_FALL_EDGE	(0x1 << 21)
#define USART_CR2_ABRMOD_FRAME_0x7F	(0x2 << 21)
#define USART_CR2_ABRMOD_FRAME_0x55	(0x3 << 21)

/* ABREN: Auto baud rate enable */
#define USART_CR2_ABREN			(1 << 20)

/* MSBFIRST: Most significant bit first */
#define USART_CR2_MSBFIRST		(1 << 19)

/* DATAINV: Binary data inversion */
#define USART_CR2_DATAINV		(1 << 18)

/* TXINV: TX pin active level inversion */
#define USART_CR2_TXINV			(1 << 17)

/* RXINV: RX pin active level inversion */
#define USART_CR2_RXINV			(1 << 16)

/* SWAP: Swap TX/RX pins */
#define USART_CR2_SWAP			(1 << 15)

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

/* ADDM7:7-bit Address Detection/4-bit Address Detection */
#define USART_CR2_ADDM7			(1 << 4)

/* ADD[3:0]: Address of the usart node
#define USART_CR2_ADD_MASK              0xF */

/* --- USART_CR3 values ---------------------------------------------------- */

/* WUFIE: Wakeup from Stop mode interrupt enable */
#define USART_CR3_WUFIE			(1 << 22)

/* WUS[1:0]: Wakeup from Stop mode interrupt flag selectio */
#define USART_CR3_WUS_ON		(0x0 << 20)
/* RESERVE #define USART_CR3_WUS	(0x1 << 20) */
#define USART_CR3_WUS_START_BIT		(0x2 << 20)
#define USART_CR3_WUS_RXNE		(0x3 << 20)

/* SCARCNT[2:0]: Smartcard auto-retry count */
#define USART_CR3_SCARCNT_OFF		(0x0 << 17)
/* 0x1 to 0x7: number of automatic retransmission attempts */

/* DEP: Driver enable polarity selection */
#define USART_CR3_DEP			(1 << 15)

/* DEM: Driver enable mode */
#define USART_CR3_DEM			(1 << 14)

/* DDRE: DMA Disable on Reception Error */
#define USART_CR3_DDRE			(1 << 13)

/* OVRDIS: Overrun Disable */
#define USART_CR3_OVRDIS		(1 << 12)

/* ONEBIT: One sample bit method enable */
#define USART_CR3_ONEBIT		(1 << 11)

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

/* --- USART_BRR values ---------------------------------------------------- */

/* DIV_Mantissa[11:0]: mantissa of USARTDIV */
#define USART_BRR_DIV_MANTISSA_MASK     (0xFFF << 4)
/* DIV_Fraction[3:0]: fraction of USARTDIV */
#define USART_BRR_DIV_FRACTION_MASK     0xF

/* --- USART_GTPR values --------------------------------------------------- */

/* GT[7:0]: Guard time value */
/* Note: N/A on UART4 & UART5 */
#define USART_GTPR_GT_MASK              (0xFF << 8)

/* PSC[7:0]: Prescaler value */
/* Note: N/A on UART4/5 */
#define USART_GTPR_PSC_MASK             0xFF


/* --- USART_RQR values --------------------------------------------------- */

/* TXFRQ: Transmit data flush request */
#define USART_RQR_TXFRQ		            (1 << 4)

/* RXFRQ: Receive data flush request */
#define USART_RQR_RXFRQ		            (1 << 3)

/* MMRQ: Mute mode request */
#define USART_RQR_MMRQ		            (1 << 2)

/* SBKRQ: Send break request */
#define USART_RQR_SBKRQ		            (1 << 1)

/* ABRRQ: Auto baud rate request */
#define USART_RQR_ABKRQ		            (1 << 0)

/* --- USART_ISR values --------------------------------------------------- */

/* REACK: Receive enable acknowledge flag */
#define USART_ISR_REACK		            (1 << 22)

/* TEACK: Transmit enable acknowledge flag */
#define USART_ISR_TEACK		            (1 << 21)

/* WUF: Wakeup from Stop mode flag */
#define USART_ISR_WUF		            (1 << 20)

/* RWU: Receiver wakeup from Mute mode */
#define USART_ISR_RWU		            (1 << 19)

/* SBKF: Send break flag */
#define USART_ISR_SBKF		            (1 << 18)

/* CMF: Character match flag */
#define USART_ISR_CMF		            (1 << 17)

/* BUSY: Busy flag */
#define USART_ISR_BUSY		            (1 << 16)

/* ABRF: Auto baud rate flag */
#define USART_ISR_ABRF		            (1 << 15)

/* ABRE: Auto baud rate error */
#define USART_ISR_ABRE		            (1 << 14)

/* EOBF: End of block flag */
#define USART_ISR_EOBF		            (1 << 12)

/* RTOF: Receiver timeout */
#define USART_ISR_RTOF		            (1 << 11)

/* CTS: CTS flag */
#define USART_ISR_CTS		            (1 << 10)

/* CTSIF: CTS interrupt flag */
#define USART_ISR_CTSIF		            (1 << 9)

/* LBDF: LIN break detection flag */
#define USART_ISR_LBDF		            (1 << 8)

/* TXE: Transmit data register empty */
#define USART_ISR_TXE		            (1 << 7)

/* TC: Transmission complete */
#define USART_ISR_TC		            (1 << 6)

/* RXNE: Read data register not empty */
#define USART_ISR_RXNE		            (1 << 5)

/* IDLE: Idle line detected */
#define USART_ISR_IDLE		            (1 << 4)

/* ORE: Overrun error */
#define USART_ISR_ORE		            (1 << 3)

/* NF: Noise detected flag */
#define USART_ISR_NF		            (1 << 2)

/* FE: Framing error */
#define USART_ISR_FE		            (1 << 1)

/* PE: Parity error */
#define USART_ISR_PE		            (1 << 0)

/* --- USART_SR values ----------------------------------------------------- */
/****************************************************************************/
/** @defgroup usart_sr_flags USART Status register Flags
@ingroup STM32F_usart_defines

@{*/

/** CTS: CTS flag */
/** @note: undefined on UART4 and UART5 */
#define USART_SR_CTS            USART_ISR_CTS

/** LBD: LIN break detection flag */
#define USART_SR_LBD            USART_ISR_LBDF

/** TXE: Transmit data buffer empty */
#define USART_SR_TXE            USART_ISR_TXE

/** TC: Transmission complete */
#define USART_SR_TC             USART_ISR_TC

/** RXNE: Read data register not empty */
#define USART_SR_RXNE           USART_ISR_RXNE

/** IDLE: Idle line detected */
#define USART_SR_IDLE           USART_ISR_IDLE

/** ORE: Overrun error */
#define USART_SR_ORE            USART_ISR_ORE

/** NE: Noise error flag */
#define USART_SR_NE             USART_ISR_NF

/** FE: Framing error */
#define USART_SR_FE             USART_ISR_FE

/** PE: Parity error */
#define USART_SR_PE             USART_ISR_PE
/**@}*/

/* --- USART_ICR values --------------------------------------------------- */

/* WUCF: Wakeup from Stop mode clear flag */
#define USART_ICR_WUCF			    (1 << 20)

/* CMCF: Character match clear flag */
#define USART_ICR_CMCF			    (1 << 17)

/* EOBCF: End of timeout clear flag */
#define USART_ICR_EOBCF			    (1 << 12)

/* RTOCF: Receiver timeout clear flag */
#define USART_ICR_RTOCF			    (1 << 11)

/* CTSCF: CTS clear flag */
#define USART_ICR_CTSCF			    (1 << 9)

/* LBDCF: LIN break detection clear flag */
#define USART_ICR_LBDCF			    (1 << 8)

/* TCCF: Transmission complete clear flag */
#define USART_ICR_TCCF			    (1 << 6)

/* IDLECF: Idle line detected clear flag */
#define USART_ICR_IDLECF		    (1 << 4)

/* ORECF: Overrun error clear flag */
#define USART_ICR_ORECF			    (1 << 3)

/* NCF: Noise detected clear flag */
#define USART_ICR_NCF			    (1 << 2)

/* FECF: Framing error clear flag */
#define USART_ICR_FECF			    (1 << 1)

/* PECF: Parity error clear flag */
#define USART_ICR_PECF			    (1 << 0)

/* --- USART_RDR values --------------------------------------------------- */

/* RDR[8:0]: Receive data value */
#define USART_RDR_MASK		    (0x1FF << 0)

/* --- USART_TDR values --------------------------------------------------- */

/* TDR[8:0]: Transmit data value */
#define USART_TDR_MASK		    (0x1FF << 0)

#endif

