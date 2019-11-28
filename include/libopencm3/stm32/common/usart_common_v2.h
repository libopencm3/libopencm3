/** @addtogroup usart_defines

 @author @htmlonly &copy; @endhtmlonly 2016 Cem Basoglu <cem.basoglu@web.de>

 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Cem Basoglu <cem.basoglu@web.de>
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

#pragma once

/** @defgroup usart_registers USART Registers
@ingroup usart_defines
@{*/

/** Control register 1 (USARTx_CR1) */
#define USART_CR1(usart_base)		MMIO32((usart_base) + 0x00)
#define USART1_CR1			USART_CR1(USART1_BASE)
#define USART2_CR1			USART_CR1(USART2_BASE)
#define USART3_CR1			USART_CR1(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_CR1			USART_CR1(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_CR1			USART_CR1(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_CR1			USART_CR1(UART5_BASE)
#endif

/** Control register 2 (USARTx_CR2) */
#define USART_CR2(usart_base)		MMIO32((usart_base) + 0x04)
#define USART1_CR2			USART_CR2(USART1_BASE)
#define USART2_CR2			USART_CR2(USART2_BASE)
#define USART3_CR2			USART_CR2(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_CR2			USART_CR2(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_CR2			USART_CR2(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_CR2			USART_CR2(UART5_BASE)
#endif

/** Control register 3 (USARTx_CR3) */
#define USART_CR3(usart_base)		MMIO32((usart_base) + 0x08)
#define USART1_CR3			USART_CR3(USART1_BASE)
#define USART2_CR3			USART_CR3(USART2_BASE)
#define USART3_CR3			USART_CR3(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_CR3			USART_CR3(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_CR3			USART_CR3(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_CR3			USART_CR3(UART5_BASE)
#endif

/** Baud rate register (USARTx_BRR) */
#define USART_BRR(usart_base)		MMIO32((usart_base) + 0x0C)
#define USART1_BRR			USART_BRR(USART1_BASE)
#define USART2_BRR			USART_BRR(USART2_BASE)
#define USART3_BRR			USART_BRR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_BRR			USART_BRR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_BRR			USART_BRR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_BRR			USART_BRR(UART5_BASE)
#endif

/** Guard time and prescaler register (USARTx_GTPR) */
#define USART_GTPR(usart_base)		MMIO32((usart_base) + 0x10)
#define USART1_GTPR			USART_GTPR(USART1_BASE)
#define USART2_GTPR			USART_GTPR(USART2_BASE)
#define USART3_GTPR			USART_GTPR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_GTPR			USART_GTPR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_GTPR			USART_GTPR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_GTPR			USART_GTPR(UART5_BASE)
#endif

/** Receiver timeout register (USART_RTOR) */
#define USART_RTOR(usart_base)		MMIO32((usart_base) + 0x14)
#define USART1_RTOR			USART_RTOR(USART1_BASE)
#define USART2_RTOR			USART_RTOR(USART2_BASE)
#define USART3_RTOR			USART_RTOR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_RTOR			USART_RTOR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_RTOR			USART_RTOR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_RTOR			USART_RTOR(UART5_BASE)
#endif

/** Request register (USART_RQR) */
#define USART_RQR(usart_base)		MMIO32((usart_base) + 0x18)
#define USART1_RQR			USART_RQR(USART1_BASE)
#define USART2_RQR			USART_RQR(USART2_BASE)
#define USART3_RQR			USART_RQR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_RQR			USART_RQR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_RQR			USART_RQR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_RQR			USART_RQR(UART5_BASE)
#endif

/** Interrupt & status register (USART_ISR) */
#define USART_ISR(usart_base)		MMIO32((usart_base) + 0x1C)
#define USART1_ISR			USART_ISR(USART1_BASE)
#define USART2_ISR			USART_ISR(USART2_BASE)
#define USART3_ISR			USART_ISR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_ISR			USART_ISR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_ISR			USART_ISR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_ISR			USART_ISR(UART5_BASE)
#endif

/** Interrupt flag clear register (USART_ICR) */
#define USART_ICR(usart_base)		MMIO32((usart_base) + 0x20)
#define USART1_ICR			USART_ICR(USART1_BASE)
#define USART2_ICR			USART_ICR(USART2_BASE)
#define USART3_ICR			USART_ICR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_ICR			USART_ICR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_ICR			USART_ICR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_ICR			USART_ICR(UART5_BASE)
#endif

/** Receive data register (USART_RDR) */
#define USART_RDR(usart_base)		MMIO32((usart_base) + 0x24)
#define USART1_RDR			USART_RDR(USART1_BASE)
#define USART2_RDR			USART_RDR(USART2_BASE)
#define USART3_RDR			USART_RDR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_RDR			USART_RDR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_RDR			USART_RDR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_RDR			USART_RDR(UART5_BASE)
#endif

/** Transmit data register (USART_TDR) */
#define USART_TDR(usart_base)		MMIO32((usart_base) + 0x28)
#define USART1_TDR			USART_TDR(USART1_BASE)
#define USART2_TDR			USART_TDR(USART2_BASE)
#define USART3_TDR			USART_TDR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_TDR			USART_TDR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_TDR			USART_TDR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_TDR			USART_TDR(UART5_BASE)
#endif

/**@}*/

/** @defgroup usart_convenience_flags U(S)ART convenience Flags
 * @ingroup usart_defines
 * We define the "common" lower flag bits using a standard name,
 * allowing them to be used regardless of which usart peripheral
 * version you have.
 * @{
 */
#define USART_FLAG_PE	USART_ISR_PE
#define USART_FLAG_FE	USART_ISR_FE
#define USART_FLAG_NF	USART_ISR_NF
#define USART_FLAG_ORE	USART_ISR_ORE
#define USART_FLAG_IDLE	USART_ISR_IDLE
#define USART_FLAG_RXNE	USART_ISR_RXNE
#define USART_FLAG_TC	USART_ISR_TC
#define USART_FLAG_TXE	USART_ISR_TXE
/**@}*/


/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/** @defgroup usart_cr1_values USART_CR1 Values
@ingroup usart_defines
@{*/

/** M1: Wordlength. @sa M0 */
#define USART_CR1_M1			(1 << 28) /* F07x */

/** EOBIE: End of Block interrupt enable */
#define USART_CR1_EOBIE			(1 << 27)

/** RTOIE: Receiver timeout interrupt enable */
#define USART_CR1_RTOIE			(1 << 26)

#define USART_CR1_DEAT_SHIFT		21
#define USART_CR1_DEAT			(0x1F << USART_CR1_DEAT_SHIFT)
/** DEAT[4:0]: Driver Enable assertion time */
#define USART_CR1_DEAT_VAL(x)		((x) << USART_CR1_DEAT_SHIFT)

#define USART_CR1_DEDT_SHIFT		16
#define USART_CR1_DEDT			(0x1F << USART_CR1_DEDT_SHIFT)
/** DEDT[4:0]: Driver Enable deassertion time */
#define USART_CR1_DEDT_VAL(x)		((x) << USART_CR1_DEDT_SHIFT)

/** OVER8: Oversampling mode */
#define USART_CR1_OVER8			(1 << 15)

/** CMIE: Character match interrupt enable */
#define USART_CR1_CMIE			(1 << 14)

/** MME: Mute mode enable */
#define USART_CR1_MME			(1 << 13)

/** M0: Word length */
#define USART_CR1_M0			(1 << 12)
/** @deprecated alias for M0.*/
#define USART_CR1_M			USART_CR1_M0

/** WAKE: Receiver wakeup method */
#define USART_CR1_WAKE			(1 << 11)

/** PCE: Parity control enable */
#define USART_CR1_PCE			(1 << 10)

/** PS: Parity selection */
#define USART_CR1_PS			(1 << 9)

/** PEIE: PE interrupt enable */
#define USART_CR1_PEIE			(1 << 8)

/** TXEIE: Interrupt enable */
#define USART_CR1_TXEIE			(1 << 7)

/** TCIE: Transmission complete interrupt enable */
#define USART_CR1_TCIE			(1 << 6)

/** RXNEIE: RXNE interrupt enable */
#define USART_CR1_RXNEIE		(1 << 5)

/** IDLEIE: IDLE interrupt enable */
#define USART_CR1_IDLEIE		(1 << 4)

/** TE: Transmitter enable */
#define USART_CR1_TE			(1 << 3)

/** RE: Receiver enable */
#define USART_CR1_RE			(1 << 2)

/** UESM: USART enable in Stop mode */
#define USART_CR1_UESM			(1 << 1)

/** UE: USART enable */
#define USART_CR1_UE			(1 << 0)
/**@}*/

/*------------------------------------------------*/
/** @defgroup usart_cr2_values USART_CR2 Values
@ingroup usart_defines
@{*/

/** ADD[7:0]: Address of the USART node. */
#define USART_CR2_ADD_SHIFT		24
#define USART_CR2_ADD			(0xFF << USART_CR2_ADD_SHIFT)
#define USART_CR2_ADD_VAL(x)		((x) << USART_CR2_ADD_SHIFT)

#define USART_CR2_ABRMOD_MASK	3
#define USART_CR2_ABRMOD_SHIFT	21
/** ABRMOD[1:0]: Auto baud rate mode
 * @defgroup usart_cr2_abrmod Auto baud rate mode
 * @ingroup usart_defines
 * @{
 */
#define USART_CR2_ABRMOD_STARTBIT	(0x0 << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FALL_EDGE	(0x1 << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FRAME_0x7F	(0x2 << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FRAME_0x55	(0x3 << USART_CR2_ABRMOD_SHIFT)
/**@}*/

/** RTOEN: Receiver timeout enable */
#define USART_CR2_RTOEN			(1 << 23)

/** ABREN: Auto baud rate enable */
#define USART_CR2_ABREN			(1 << 20)

/** MSBFIRST: Most significant bit first */
#define USART_CR2_MSBFIRST		(1 << 19)

/** DATAINV: Binary data inversion */
#define USART_CR2_DATAINV		(1 << 18)

/** TXINV: TX pin active level inversion */
#define USART_CR2_TXINV			(1 << 17)

/** RXINV: RX pin active level inversion */
#define USART_CR2_RXINV			(1 << 16)

/** SWAP: Swap TX/RX pins */
#define USART_CR2_SWAP			(1 << 15)

/** LINEN: LIN mode enable */
#define USART_CR2_LINEN			(1 << 14)

/** CLKEN: Clock enable */
#define USART_CR2_CLKEN			(1 << 11)

/** CPOL: Clock polarity */
#define USART_CR2_CPOL			(1 << 10)

/** CPHA: Clock phase */
#define USART_CR2_CPHA			(1 << 9)

/** LBCL: Last bit clock pulse */
#define USART_CR2_LBCL			(1 << 8)

/** LBDIE: LIN break detection interrupt enable */
#define USART_CR2_LBDIE			(1 << 6)

/** LBDL: LIN break detection length */
#define USART_CR2_LBDL			(1 << 5)

/** ADDM7:7-bit Address Detection/4-bit Address Detection */
#define USART_CR2_ADDM7			(1 << 4)

/**@}*/

/*------------------------------------------------*/
/** @defgroup usart_cr3_values USART_CR3 Values
@ingroup usart_defines
@{*/
/** WUFIE: Wakeup from Stop mode interrupt enable */
#define USART_CR3_WUFIE			(1 << 22)

/** WUS[1:0]: Wakeup from Stop mode interrupt flag selection */
#define USART_CR3_WUS_ADDRMATCH		(0x0 << 20)
#define USART_CR3_WUS_START_BIT		(0x2 << 20)
#define USART_CR3_WUS_RXNE		(0x3 << 20)

#define USART_CR3_SCARCNT_SHIFT		17
#define USART_CR3_SCARCNT_MASK		0x7
/** SCARCNT[2:0]: Smartcard auto retry count */
#define USART_CR3_SCARCNT_DISABLE	(0 << USART_CR3_SCARCNT_SHIFT)
#define USART_CR3_SCARCNT_VAL(x)	((x) << USART_CR3_SCARCNT_SHIFT)

/** DEP: Driver enable polarity selection */
#define USART_CR3_DEP			(1 << 15)

/** DEM: Driver enable mode */
#define USART_CR3_DEM			(1 << 14)

/** DDRE: DMA Disable on Reception Error */
#define USART_CR3_DDRE			(1 << 13)

/** OVRDIS: Overrun Disable */
#define USART_CR3_OVRDIS		(1 << 12)

/** ONEBIT: One sample bit method enable */
#define USART_CR3_ONEBIT		(1 << 11)

/** CTSIE: CTS interrupt enable. Not on UARTs */
#define USART_CR3_CTSIE			(1 << 10)

/** CTSE: CTS enable. Not on UARTS */
#define USART_CR3_CTSE			(1 << 9)

/** RTSE: RTS enable. Not on UARTs */
#define USART_CR3_RTSE			(1 << 8)

/** DMAT: DMA enable transmitter. Not on UARTs */
#define USART_CR3_DMAT			(1 << 7)

/** DMAR: DMA enable receiver. Not on UARTS */
#define USART_CR3_DMAR			(1 << 6)

/** SCEN: Smartcard mode enable. Not on UARTs */
#define USART_CR3_SCEN			(1 << 5)

/** NACK: Smartcard NACK enable. Not UARTs */
#define USART_CR3_NACK			(1 << 4)

/** HDSEL: Half-duplex selection */
#define USART_CR3_HDSEL			(1 << 3)

/** IRLP: IrDA low-power */
#define USART_CR3_IRLP			(1 << 2)

/** IREN: IrDA mode enable */
#define USART_CR3_IREN			(1 << 1)

/** EIE: Error interrupt enable */
#define USART_CR3_EIE			(1 << 0)

/**@}*/

/** @defgroup usart_gtpr_values USART_GTPR Values
 * @ingroup usart_defines
 * @{
 */
#define USART_GTPR_GT_SHIFT		8
#define USART_GTPR_GT			(0xFF << USART_GTPR_GT_SHIFT)
#define USART_GTPR_GT_VAL(x)		((x) << USART_GTPR_GT_SHIFT)

#define USART_GTPR_PSC_SHIFT		0
#define USART_GTPR_PSC			(0xFF << USART_GTPR_PSC_SHIFT)
#define USART_GTPR_PSC_VAL(x)		((x) << USART_GTPR_PSC_SHIFT)
/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_rtor_values USART_RTOR Values
 * @ingroup usart_defines
 * @{
 */
/** BLEN[7:0]: Block Length */
#define USART_RTOR_BLEN_SHIFT			24
#define USART_RTOR_BLEN_MASK			(0xFF << USART_RTOR_BLEN_SHIFT)
#define USART_RTOR_BLEN_VAL(x)			((x) << USART_RTOR_BLEN_SHIFT)

/** RTO[23:0]: Receiver timeout value */
#define USART_RTOR_RTO_SHIFT			0
#define USART_RTOR_RTO_MASK			(0xFFFFF << USART_RTOR_RTO_SHIFT)
#define USART_RTOR_RTO_VAL(x)			((x) << USART_RTOR_RTO_SHIFT)

/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_rqr_values USART_RQR Values
 * @ingroup usart_defines
 * @{
 */
/** TXFRQ: Transmit data flush request */
#define USART_RQR_TXFRQ		            (1 << 4)

/** RXFRQ: Receive data flush request */
#define USART_RQR_RXFRQ		            (1 << 3)

/** MMRQ: Mute mode request */
#define USART_RQR_MMRQ		            (1 << 2)

/** SBKRQ: Send break request */
#define USART_RQR_SBKRQ		            (1 << 1)

/** ABRRQ: Auto baud rate request */
#define USART_RQR_ABKRQ		            (1 << 0)

/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_isr_values USART_ISR Values
 * @ingroup usart_defines
 * @{
 */

/** REACK: Receive enable acknowledge flag */
#define USART_ISR_REACK		            (1 << 22)

/** TEACK: Transmit enable acknowledge flag */
#define USART_ISR_TEACK		            (1 << 21)

/** WUF: Wakeup from Stop mode flag */
#define USART_ISR_WUF		            (1 << 20)

/** RWU: Receiver wakeup from Mute mode */
#define USART_ISR_RWU		            (1 << 19)

/** SBKF: Send break flag */
#define USART_ISR_SBKF		            (1 << 18)

/** CMF: Character match flag */
#define USART_ISR_CMF		            (1 << 17)

/** BUSY: Busy flag */
#define USART_ISR_BUSY		            (1 << 16)

/** ABRF: Auto baud rate flag */
#define USART_ISR_ABRF		            (1 << 15)

/** ABRE: Auto baud rate error */
#define USART_ISR_ABRE		            (1 << 14)

/** EOBF: End of block flag */
#define USART_ISR_EOBF		            (1 << 12)

/** RTOF: Receiver timeout */
#define USART_ISR_RTOF		            (1 << 11)

/** CTS: CTS flag */
#define USART_ISR_CTS		            (1 << 10)

/** CTSIF: CTS interrupt flag */
#define USART_ISR_CTSIF		            (1 << 9)

/** LBDF: LIN break detection flag */
#define USART_ISR_LBDF		            (1 << 8)

/** TXE: Transmit data register empty */
#define USART_ISR_TXE		            (1 << 7)

/** TC: Transmission complete */
#define USART_ISR_TC		            (1 << 6)

/** RXNE: Read data register not empty */
#define USART_ISR_RXNE		            (1 << 5)

/** IDLE: Idle line detected */
#define USART_ISR_IDLE		            (1 << 4)

/** ORE: Overrun error */
#define USART_ISR_ORE		            (1 << 3)

/** NF: Noise detected flag */
#define USART_ISR_NF		            (1 << 2)

/** FE: Framing error */
#define USART_ISR_FE		            (1 << 1)

/** PE: Parity error */
#define USART_ISR_PE		            (1 << 0)

/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_icr_values USART_ICR Values
 * @ingroup usart_defines
 * @{
 */

/** WUCF: Wakeup from Stop mode clear flag */
#define USART_ICR_WUCF			    (1 << 20)

/** CMCF: Character match clear flag */
#define USART_ICR_CMCF			    (1 << 17)

/** EOBCF: End of timeout clear flag */
#define USART_ICR_EOBCF			    (1 << 12)

/** RTOCF: Receiver timeout clear flag */
#define USART_ICR_RTOCF			    (1 << 11)

/** CTSCF: CTS clear flag */
#define USART_ICR_CTSCF			    (1 << 9)

/** LBDCF: LIN break detection clear flag */
#define USART_ICR_LBDCF			    (1 << 8)

/** TCCF: Transmission complete clear flag */
#define USART_ICR_TCCF			    (1 << 6)

/** IDLECF: Idle line detected clear flag */
#define USART_ICR_IDLECF		    (1 << 4)

/** ORECF: Overrun error clear flag */
#define USART_ICR_ORECF			    (1 << 3)

/** NCF: Noise detected clear flag */
#define USART_ICR_NCF			    (1 << 2)

/** FECF: Framing error clear flag */
#define USART_ICR_FECF			    (1 << 1)

/** PECF: Parity error clear flag */
#define USART_ICR_PECF			    (1 << 0)

/**@}*/

/** @defgroup usart_dr_values USART_RDR/TDR Values
 * @ingroup usart_defines
 * @{
 */
/** RDR[8:0]: Receive data value */
#define USART_RDR_MASK		    (0x1FF << 0)
/** TDR[8:0]: Transmit data value */
#define USART_TDR_MASK		    (0x1FF << 0)
/**@}*/


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void usart_enable_data_inversion(uint32_t usart);
void usart_disable_data_inversion(uint32_t usart);
void usart_enable_tx_inversion(uint32_t usart);
void usart_disable_tx_inversion(uint32_t usart);
void usart_enable_rx_inversion(uint32_t usart);
void usart_disable_rx_inversion(uint32_t usart);
void usart_enable_halfduplex(uint32_t usart);
void usart_disable_halfduplex(uint32_t usart);

void usart_set_rx_timeout_value(uint32_t usart, uint32_t value);
void usart_enable_rx_timeout(uint32_t usart);
void usart_disable_rx_timeout(uint32_t usart);
void usart_enable_rx_timeout_interrupt(uint32_t usart);
void usart_disable_rx_timeout_interrupt(uint32_t usart);

END_DECLS
