/** @addtogroup usart_defines

 @author @htmlonly &copy; @endhtmlonly 2016 Cem Basoglu <cem.basoglu@web.de>

 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Cem Basoglu <cem.basoglu@web.de>
 * Copyright (C) 2026 Rachel Mant <git@dragonmux.network>
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

#include <stdint.h>
#include <stdbool.h>

/** @defgroup usart_registers USART Registers
@ingroup usart_defines
@{*/

/** Control register 1 (USARTx_CR1) */
#define USART_CR1(usart_base) MMIO32((usart_base) + 0x00U)
#define USART1_CR1            USART_CR1(USART1_BASE)
#define USART2_CR1            USART_CR1(USART2_BASE)
#define USART3_CR1            USART_CR1(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_CR1 USART_CR1(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_CR1 USART_CR1(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_CR1 USART_CR1(UART5_BASE)
#endif

/** Control register 2 (USARTx_CR2) */
#define USART_CR2(usart_base) MMIO32((usart_base) + 0x04U)
#define USART1_CR2            USART_CR2(USART1_BASE)
#define USART2_CR2            USART_CR2(USART2_BASE)
#define USART3_CR2            USART_CR2(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_CR2 USART_CR2(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_CR2 USART_CR2(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_CR2 USART_CR2(UART5_BASE)
#endif

/** Control register 3 (USARTx_CR3) */
#define USART_CR3(usart_base) MMIO32((usart_base) + 0x08U)
#define USART1_CR3            USART_CR3(USART1_BASE)
#define USART2_CR3            USART_CR3(USART2_BASE)
#define USART3_CR3            USART_CR3(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_CR3 USART_CR3(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_CR3 USART_CR3(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_CR3 USART_CR3(UART5_BASE)
#endif

/** Baud rate register (USARTx_BRR) */
#define USART_BRR(usart_base) MMIO32((usart_base) + 0x0CU)
#define USART1_BRR            USART_BRR(USART1_BASE)
#define USART2_BRR            USART_BRR(USART2_BASE)
#define USART3_BRR            USART_BRR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_BRR USART_BRR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_BRR USART_BRR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_BRR USART_BRR(UART5_BASE)
#endif

/** Guard time and prescaler register (USARTx_GTPR) */
#define USART_GTPR(usart_base) MMIO32((usart_base) + 0x10U)
#define USART1_GTPR            USART_GTPR(USART1_BASE)
#define USART2_GTPR            USART_GTPR(USART2_BASE)
#define USART3_GTPR            USART_GTPR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_GTPR USART_GTPR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_GTPR USART_GTPR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_GTPR USART_GTPR(UART5_BASE)
#endif

/** Receiver timeout register (USART_RTOR) */
#define USART_RTOR(usart_base) MMIO32((usart_base) + 0x14U)
#define USART1_RTOR            USART_RTOR(USART1_BASE)
#define USART2_RTOR            USART_RTOR(USART2_BASE)
#define USART3_RTOR            USART_RTOR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_RTOR USART_RTOR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_RTOR USART_RTOR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_RTOR USART_RTOR(UART5_BASE)
#endif

/** Request register (USART_RQR) */
#define USART_RQR(usart_base) MMIO32((usart_base) + 0x18U)
#define USART1_RQR            USART_RQR(USART1_BASE)
#define USART2_RQR            USART_RQR(USART2_BASE)
#define USART3_RQR            USART_RQR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_RQR USART_RQR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_RQR USART_RQR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_RQR USART_RQR(UART5_BASE)
#endif

/** Interrupt & status register (USART_ISR) */
#define USART_ISR(usart_base) MMIO32((usart_base) + 0x1CU)
#define USART1_ISR            USART_ISR(USART1_BASE)
#define USART2_ISR            USART_ISR(USART2_BASE)
#define USART3_ISR            USART_ISR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_ISR USART_ISR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_ISR USART_ISR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_ISR USART_ISR(UART5_BASE)
#endif

/** Interrupt flag clear register (USART_ICR) */
#define USART_ICR(usart_base) MMIO32((usart_base) + 0x20U)
#define USART1_ICR            USART_ICR(USART1_BASE)
#define USART2_ICR            USART_ICR(USART2_BASE)
#define USART3_ICR            USART_ICR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_ICR USART_ICR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_ICR USART_ICR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_ICR USART_ICR(UART5_BASE)
#endif

/** Receive data register (USART_RDR) */
#define USART_RDR(usart_base) MMIO32((usart_base) + 0x24U)
#define USART1_RDR            USART_RDR(USART1_BASE)
#define USART2_RDR            USART_RDR(USART2_BASE)
#define USART3_RDR            USART_RDR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_RDR USART_RDR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_RDR USART_RDR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_RDR USART_RDR(UART5_BASE)
#endif

/** Transmit data register (USART_TDR) */
#define USART_TDR(usart_base) MMIO32((usart_base) + 0x28U)
#define USART1_TDR            USART_TDR(USART1_BASE)
#define USART2_TDR            USART_TDR(USART2_BASE)
#define USART3_TDR            USART_TDR(USART3_BASE)
#if defined(USART4_BASE)
#define USART4_TDR USART_TDR(USART4_BASE)
#endif
#if defined(UART4_BASE)
#define UART4_TDR USART_TDR(UART4_BASE)
#endif
#if defined(UART5_BASE)
#define UART5_TDR USART_TDR(UART5_BASE)
#endif

/**@}*/

/** @defgroup usart_convenience_flags U(S)ART convenience Flags
 * @ingroup usart_defines
 * We define the "common" lower flag bits using a standard name,
 * allowing them to be used regardless of which usart peripheral
 * version you have.
 * @{
 */
#define USART_FLAG_PE   USART_ISR_PE
#define USART_FLAG_FE   USART_ISR_FE
#define USART_FLAG_NF   USART_ISR_NF
#define USART_FLAG_ORE  USART_ISR_ORE
#define USART_FLAG_IDLE USART_ISR_IDLE
#define USART_FLAG_RXNE USART_ISR_RXNE
#define USART_FLAG_TC   USART_ISR_TC
#define USART_FLAG_TXE  USART_ISR_TXE
/**@}*/

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/** @defgroup usart_cr1_values USART_CR1 Values
@ingroup usart_defines
@{*/

/** M1: Wordlength. @sa M0 */
#define USART_CR1_M1 (1 << 28U) /* F07x */

/** EOBIE: End of Block interrupt enable */
#define USART_CR1_EOBIE (1 << 27U)

/** RTOIE: Receiver timeout interrupt enable */
#define USART_CR1_RTOIE (1 << 26U)

#define USART_CR1_DEAT_SHIFT 21U
#define USART_CR1_DEAT       (0x1FU << USART_CR1_DEAT_SHIFT)
/** DEAT[4:0]: Driver Enable assertion time */
#define USART_CR1_DEAT_VAL(x) ((x) << USART_CR1_DEAT_SHIFT)

#define USART_CR1_DEDT_SHIFT 16U
#define USART_CR1_DEDT       (0x1FU << USART_CR1_DEDT_SHIFT)
/** DEDT[4:0]: Driver Enable deassertion time */
#define USART_CR1_DEDT_VAL(x) ((x) << USART_CR1_DEDT_SHIFT)

/** OVER8: Oversampling mode */
#define USART_CR1_OVER8 (1U << 15U)

/** CMIE: Character match interrupt enable */
#define USART_CR1_CMIE (1U << 14U)

/** MME: Mute mode enable */
#define USART_CR1_MME (1U << 13U)

/** M0: Word length */
#define USART_CR1_M0 (1U << 12U)
/** @deprecated alias for M0.*/
#define USART_CR1_M USART_CR1_M0

/** WAKE: Receiver wakeup method */
#define USART_CR1_WAKE (1U << 11U)

/** PCE: Parity control enable */
#define USART_CR1_PCE (1U << 10U)

/** PS: Parity selection */
#define USART_CR1_PS (1U << 9U)

/** PEIE: PE interrupt enable */
#define USART_CR1_PEIE (1U << 8U)

/** TXEIE: Interrupt enable */
#define USART_CR1_TXEIE (1U << 7U)

/** TCIE: Transmission complete interrupt enable */
#define USART_CR1_TCIE (1U << 6U)

/** RXNEIE: RXNE interrupt enable */
#define USART_CR1_RXNEIE (1U << 5U)

/** IDLEIE: IDLE interrupt enable */
#define USART_CR1_IDLEIE (1U << 4U)

/** TE: Transmitter enable */
#define USART_CR1_TE (1U << 3U)

/** RE: Receiver enable */
#define USART_CR1_RE (1U << 2U)

/** UESM: USART enable in Stop mode */
#define USART_CR1_UESM (1U << 1U)

/** UE: USART enable */
#define USART_CR1_UE (1U << 0U)
/**@}*/

/* CR1_OVER8 values */
/****************************************************************************/
/** @defgroup usart_cr1_oversampling USART Oversampling Mode Selection
@ingroup STM32F_usart_defines

@{*/
#define USART_OVERSAMPLING_8  USART_CR1_OVER8
#define USART_OVERSAMPLING_16 0U
/**@}*/

/*------------------------------------------------*/
/** @defgroup usart_cr2_values USART_CR2 Values
@ingroup usart_defines
@{*/

/** ADD[7:0]: Address of the USART node. */
#define USART_CR2_ADD_SHIFT  24U
#define USART_CR2_ADD        (0xffU << USART_CR2_ADD_SHIFT)
#define USART_CR2_ADD_VAL(x) ((x) << USART_CR2_ADD_SHIFT)

#define USART_CR2_ABRMOD_MASK  3U
#define USART_CR2_ABRMOD_SHIFT 21U
/** ABRMOD[1:0]: Auto baud rate mode
 * @defgroup usart_cr2_abrmod Auto baud rate mode
 * @ingroup usart_defines
 * @{
 */
#define USART_CR2_ABRMOD_STARTBIT   (0x0U << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FALL_EDGE  (0x1U << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FRAME_0x7F (0x2U << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FRAME_0x55 (0x3U << USART_CR2_ABRMOD_SHIFT)
/**@}*/

/** RTOEN: Receiver timeout enable */
#define USART_CR2_RTOEN (1U << 23U)

/** ABREN: Auto baud rate enable */
#define USART_CR2_ABREN (1U << 20U)

/** MSBFIRST: Most significant bit first */
#define USART_CR2_MSBFIRST (1U << 19U)

/** DATAINV: Binary data inversion */
#define USART_CR2_DATAINV (1U << 18U)

/** TXINV: TX pin active level inversion */
#define USART_CR2_TXINV (1U << 17U)

/** RXINV: RX pin active level inversion */
#define USART_CR2_RXINV (1U << 16U)

/** SWAP: Swap TX/RX pins */
#define USART_CR2_SWAP (1U << 15U)

/** LINEN: LIN mode enable */
#define USART_CR2_LINEN (1U << 14U)

/** CLKEN: Clock enable */
#define USART_CR2_CLKEN (1U << 11U)

/** CPOL: Clock polarity */
#define USART_CR2_CPOL (1U << 10U)

/** CPHA: Clock phase */
#define USART_CR2_CPHA (1U << 9U)

/** LBCL: Last bit clock pulse */
#define USART_CR2_LBCL (1U << 8U)

/** LBDIE: LIN break detection interrupt enable */
#define USART_CR2_LBDIE (1U << 6U)

/** LBDL: LIN break detection length */
#define USART_CR2_LBDL (1U << 5U)

/** ADDM7:7-bit Address Detection/4-bit Address Detection */
#define USART_CR2_ADDM7 (1U << 4U)

/**@}*/

/*------------------------------------------------*/
/** @defgroup usart_cr3_values USART_CR3 Values
@ingroup usart_defines
@{*/
/** WUFIE: Wakeup from Stop mode interrupt enable */
#define USART_CR3_WUFIE (1U << 22U)

/** WUS[1:0]: Wakeup from Stop mode interrupt flag selection */
#define USART_CR3_WUS_ADDRMATCH (0x0U << 20U)
#define USART_CR3_WUS_START_BIT (0x2U << 20U)
#define USART_CR3_WUS_RXNE      (0x3U << 20U)

#define USART_CR3_SCARCNT_SHIFT 17U
#define USART_CR3_SCARCNT_MASK  0x7U
/** SCARCNT[2:0]: Smartcard auto retry count */
#define USART_CR3_SCARCNT_DISABLE (0U << USART_CR3_SCARCNT_SHIFT)
#define USART_CR3_SCARCNT_VAL(x)  ((x) << USART_CR3_SCARCNT_SHIFT)

/** DEP: Driver enable polarity selection */
#define USART_CR3_DEP (1U << 15U)

/** DEM: Driver enable mode */
#define USART_CR3_DEM (1U << 14U)

/** DDRE: DMA Disable on Reception Error */
#define USART_CR3_DDRE (1U << 13U)

/** OVRDIS: Overrun Disable */
#define USART_CR3_OVRDIS (1U << 12U)

/** ONEBIT: One sample bit method enable */
#define USART_CR3_ONEBIT (1U << 11U)

/** CTSIE: CTS interrupt enable. Not on UARTs */
#define USART_CR3_CTSIE (1U << 10U)

/** CTSE: CTS enable. Not on UARTS */
#define USART_CR3_CTSE (1U << 9U)

/** RTSE: RTS enable. Not on UARTs */
#define USART_CR3_RTSE (1U << 8U)

/** DMAT: DMA enable transmitter. Not on UARTs */
#define USART_CR3_DMAT (1U << 7U)

/** DMAR: DMA enable receiver. Not on UARTS */
#define USART_CR3_DMAR (1U << 6U)

/** SCEN: Smartcard mode enable. Not on UARTs */
#define USART_CR3_SCEN (1U << 5U)

/** NACK: Smartcard NACK enable. Not UARTs */
#define USART_CR3_NACK (1U << 4U)

/** HDSEL: Half-duplex selection */
#define USART_CR3_HDSEL (1U << 3U)

/** IRLP: IrDA low-power */
#define USART_CR3_IRLP (1U << 2U)

/** IREN: IrDA mode enable */
#define USART_CR3_IREN (1U << 1U)

/** EIE: Error interrupt enable */
#define USART_CR3_EIE (1U << 0U)

/**@}*/

#define USART_BRR_UPPER_MASK (0x0000fff0U)
#define USART_BRR_LOWER_MASK (0x0000000fU)

/** @defgroup usart_gtpr_values USART_GTPR Values
 * @ingroup usart_defines
 * @{
 */
#define USART_GTPR_GT_SHIFT  8U
#define USART_GTPR_GT        (0xffU << USART_GTPR_GT_SHIFT)
#define USART_GTPR_GT_VAL(x) ((x) << USART_GTPR_GT_SHIFT)

#define USART_GTPR_PSC_SHIFT  0U
#define USART_GTPR_PSC        (0xffU << USART_GTPR_PSC_SHIFT)
#define USART_GTPR_PSC_VAL(x) ((x) << USART_GTPR_PSC_SHIFT)
/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_rtor_values USART_RTOR Values
 * @ingroup usart_defines
 * @{
 */
/** BLEN[7:0]: Block Length */
#define USART_RTOR_BLEN_SHIFT  24U
#define USART_RTOR_BLEN_MASK   (0xffU << USART_RTOR_BLEN_SHIFT)
#define USART_RTOR_BLEN_VAL(x) ((x) << USART_RTOR_BLEN_SHIFT)

/** RTO[23:0]: Receiver timeout value */
#define USART_RTOR_RTO_SHIFT  0U
#define USART_RTOR_RTO_MASK   (0xfffffU << USART_RTOR_RTO_SHIFT)
#define USART_RTOR_RTO_VAL(x) ((x) << USART_RTOR_RTO_SHIFT)

/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_rqr_values USART_RQR Values
 * @ingroup usart_defines
 * @{
 */
/** TXFRQ: Transmit data flush request */
#define USART_RQR_TXFRQ (1U << 4U)

/** RXFRQ: Receive data flush request */
#define USART_RQR_RXFRQ (1U << 3U)

/** MMRQ: Mute mode request */
#define USART_RQR_MMRQ (1U << 2U)

/** SBKRQ: Send break request */
#define USART_RQR_SBKRQ (1U << 1U)

/** ABRRQ: Auto baud rate request */
#define USART_RQR_ABRRQ (1U << 0U)

/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_isr_values USART_ISR Values
 * @ingroup usart_defines
 * @{
 */

/** REACK: Receive enable acknowledge flag */
#define USART_ISR_REACK (1U << 22U)

/** TEACK: Transmit enable acknowledge flag */
#define USART_ISR_TEACK (1U << 21U)

/** WUF: Wakeup from Stop mode flag */
#define USART_ISR_WUF (1U << 20U)

/** RWU: Receiver wakeup from Mute mode */
#define USART_ISR_RWU (1U << 19U)

/** SBKF: Send break flag */
#define USART_ISR_SBKF (1U << 18U)

/** CMF: Character match flag */
#define USART_ISR_CMF (1U << 17U)

/** BUSY: Busy flag */
#define USART_ISR_BUSY (1U << 16U)

/** ABRF: Auto baud rate flag */
#define USART_ISR_ABRF (1U << 15U)

/** ABRE: Auto baud rate error */
#define USART_ISR_ABRE (1U << 14U)

/** EOBF: End of block flag */
#define USART_ISR_EOBF (1U << 12U)

/** RTOF: Receiver timeout */
#define USART_ISR_RTOF (1U << 11U)

/** CTS: CTS flag */
#define USART_ISR_CTS (1U << 10U)

/** CTSIF: CTS interrupt flag */
#define USART_ISR_CTSIF (1U << 9U)

/** LBDF: LIN break detection flag */
#define USART_ISR_LBDF (1U << 8U)

/** TXE: Transmit data register empty */
#define USART_ISR_TXE (1U << 7U)

/** TC: Transmission complete */
#define USART_ISR_TC (1U << 6U)

/** RXNE: Read data register not empty */
#define USART_ISR_RXNE (1U << 5U)

/** IDLE: Idle line detected */
#define USART_ISR_IDLE (1U << 4U)

/** ORE: Overrun error */
#define USART_ISR_ORE (1U << 3U)

/** NF: Noise detected flag */
#define USART_ISR_NF (1U << 2U)

/** FE: Framing error */
#define USART_ISR_FE (1U << 1U)

/** PE: Parity error */
#define USART_ISR_PE (1U << 0U)

/**@}*/

/* ------------------------------------------------------ */
/** @defgroup usart_icr_values USART_ICR Values
 * @ingroup usart_defines
 * @{
 */

/** WUCF: Wakeup from Stop mode clear flag */
#define USART_ICR_WUCF (1U << 20U)

/** CMCF: Character match clear flag */
#define USART_ICR_CMCF (1U << 17U)

/** EOBCF: End of timeout clear flag */
#define USART_ICR_EOBCF (1U << 12U)

/** RTOCF: Receiver timeout clear flag */
#define USART_ICR_RTOCF (1U << 11U)

/** CTSCF: CTS clear flag */
#define USART_ICR_CTSCF (1U << 9U)

/** LBDCF: LIN break detection clear flag */
#define USART_ICR_LBDCF (1U << 8U)

/** TCCF: Transmission complete clear flag */
#define USART_ICR_TCCF (1U << 6U)

/** IDLECF: Idle line detected clear flag */
#define USART_ICR_IDLECF (1U << 4U)

/** ORECF: Overrun error clear flag */
#define USART_ICR_ORECF (1U << 3U)

/** NCF: Noise detected clear flag */
#define USART_ICR_NCF (1U << 2U)

/** FECF: Framing error clear flag */
#define USART_ICR_FECF (1U << 1U)

/** PECF: Parity error clear flag */
#define USART_ICR_PECF (1U << 0U)

/**@}*/

/** @defgroup usart_dr_values USART_RDR/TDR Values
 * @ingroup usart_defines
 * @{
 */
/** RDR[8:0]: Receive data value */
#define USART_RDR_MASK (0x1ffU << 0U)
/** TDR[8:0]: Transmit data value */
#define USART_TDR_MASK (0x1ffU << 0U)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void usart_enable_data_inversion(uintptr_t usart);
void usart_disable_data_inversion(uintptr_t usart);
void usart_enable_tx_inversion(uintptr_t usart);
void usart_disable_tx_inversion(uintptr_t usart);
void usart_enable_rx_inversion(uintptr_t usart);
void usart_disable_rx_inversion(uintptr_t usart);
void usart_enable_halfduplex(uintptr_t usart);
void usart_disable_halfduplex(uintptr_t usart);

void usart_set_rx_timeout_value(uintptr_t usart, uint32_t value);
void usart_enable_rx_timeout(uintptr_t usart);
void usart_disable_rx_timeout(uintptr_t usart);
void usart_enable_rx_timeout_interrupt(uintptr_t usart);
void usart_disable_rx_timeout_interrupt(uintptr_t usart);

void usart_enable_diver_enable(uintptr_t usart, bool invert);
void usart_set_oversampling(uintptr_t usart, uint32_t mode);

void usart_set_swap_tx_rx(uintptr_t usart, bool swapped);

END_DECLS
