/** @defgroup usart_defines USART Defines
 *
 * @brief <b>Defined Constants and Types Common between the STM32F0/STM32L0 USART</b>
 *
 * @ingroup STM32F0xx_defines
 * @ingroup STM32L0xx_defines
 *
 * @version 1.1.0
 *
 * @date 1 Jan 2015
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

/** @cond */
#ifdef LIBOPENCM3_USART_H
/** @endcond */

#ifndef LIBOPENCM3_USART_FL_0_H
#define LIBOPENCM3_USART_FL_0_H

/*****************************************************************************/
/* Register definitions                                                      */
/* Common to both L0 and F0 variants                                         */
/*****************************************************************************/

#define USART_CR1(usart_base)		MMIO32(usart_base + 0x00)
#define USART_CR2(usart_base)		MMIO32(usart_base + 0x04)
#define USART_CR3(usart_base)		MMIO32(usart_base + 0x08)
#define USART_BRR(usart_base)		MMIO32(usart_base + 0x0c)
#define USART_GTPR(usart_base)		MMIO32(usart_base + 0x10)
#define USART_RTOR(usart_base)		MMIO32(usart_base + 0x14)
#define USART_RQR(usart_base)		MMIO32(usart_base + 0x18)
#define USART_ISR(usart_base)		MMIO32(usart_base + 0x1c)
#define USART_ICR(usart_base)		MMIO32(usart_base + 0x20)
#define USART_RDR(usart_base)		MMIO16(usart_base + 0x24)
#define USART_TDR(usart_base)		MMIO16(usart_base + 0x28)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* USART_CR1 Values ---------------------------------------------------------*/

#define USART_CR1_M1			(1 << 28) /* F07x/L0 */
#define USART_CR1_EOBIE			(1 << 27)
#define USART_CR1_RTOIE			(1 << 26)

#define USART_CR1_DEAT_SHIFT		21
#define USART_CR1_DEAT_MASK		0x1f

#define USART_CR1_DEDT_SHIFT		16
#define USART_CR1_DEDT_MASK		0x1f

#define USART_CR1_OVER8			(1 << 15)
#define USART_CR1_CMIE			(1 << 14)
#define USART_CR1_MME			(1 << 13)
#define USART_CR1_M			(1 << 12) /* Obsolete, please use M0 */
#define USART_CR1_M0			(1 << 12)
#define USART_CR1_WAKE			(1 << 11)
#define USART_CR1_PCE			(1 << 10)
#define USART_CR1_PS			(1 << 9)
#define USART_CR1_PEIE			(1 << 8)
#define USART_CR1_TXEIE			(1 << 7)
#define USART_CR1_TCIE			(1 << 6)
#define USART_CR1_RXNEIE		(1 << 5)
#define USART_CR1_IDLEIE		(1 << 4)
#define USART_CR1_TE			(1 << 3)
#define USART_CR1_RE			(1 << 2)
#define USART_CR1_UESM			(1 << 1)
#define USART_CR1_UE			(1 << 0)

/* USART_CR2 Values ---------------------------------------------------------*/

#define USART_CR2_ADD_SHIFT		24
#define USART_CR2_ADD			(0xFF << USART_CR2_ADD_SHIFT)
#define USART_CR2_ADD_VAL(x)		((x) << USART_CR2_ADD_SHIFT)

#define USART_CR2_RTOEN			(1 << 23)

#define USART_CR2_ABRMOD_SHIFT		21
#define USART_CR2_ABRMOD_MASK		0x3
#define USART_CR2_ABRMOD_STARTBIT	(0 << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FALLTOFALL	(1 << USART_CR2_ABRMOD_SHIFT)

#define USART_CR2_ABREN			(1 << 20)
#define USART_CR2_MSBFIRST		(1 << 19)
#define USART_CR2_DATAINV		(1 << 18)
#define USART_CR2_TXINV			(1 << 17)
#define USART_CR2_RXINV			(1 << 16)
#define USART_CR2_SWAP			(1 << 15)
#define USART_CR2_LINEN			(1 << 14)

#define USART_CR2_STOP_SHIFT		12
#define USART_CR2_STOP			(3 << USART_CR2_STOP_SHIFT)
#define USART_CR2_STOP_1_0BIT		(0 << USART_CR2_STOP_SHIFT)
#define USART_CR2_STOP_2_0BIT		(2 << USART_CR2_STOP_SHIFT)
#define USART_CR2_STOP_1_5BIT		(3 << USART_CR2_STOP_SHIFT)

#define USART_CR2_CLKEN			(1 << 11)
#define USART_CR2_CPOL			(1 << 10)
#define USART_CR2_CPHA			(1 << 9)
#define USART_CR2_LBCL			(1 << 8)
#define USART_CR2_LBIDE			(1 << 6)
#define USART_CR2_LBDL			(1 << 5)
#define USART_CR2_ADDM			(1 << 4) /* Obsolete, use ADDM7 */
#define USART_CR2_ADDM7			(1 << 4)

/* USART_CR3 Values ---------------------------------------------------------*/

#define USART_CR3_WUFIE			(1 << 22)

#define USART_CR3_WUS_SHIFT		20
#define USART_CR3_WUS			(3 << USART_CR3_WUS_SHIFT)
#define USART_CR3_WUS_ADDRMATCH		(0 << USART_CR3_WUS_SHIFT)
#define USART_CR3_WUS_STARTBIT		(2 << USART_CR3_WUS_SHIFT)
#define USART_CR3_WUS_RXNE		(3 << USART_CR3_WUS_SHIFT)

#define USART_CR3_SCARCNT_SHIFT		17
#define USART_CR3_SCARCNT		(7 << USART_CR3_SCARCNT_SHIFT)
#define USART_CR3_SCARCNT_DISABLE	(0 << USART_CR3_SCARCNT_SHIFT)
#define USART_CR3_SCARCNT_VAL(x)	((x) << USART_CR3_SCARCNT_SHIFT)

#define USART_CR3_DEP			(1 << 15)
#define USART_CR3_DEM			(1 << 14)
#define USART_CR3_DDRE			(1 << 13)
#define USART_CR3_OVRDIS		(1 << 12)
#define USART_CR3_ONEBIT		(1 << 11)
#define USART_CR3_CTSIE			(1 << 10)
#define USART_CR3_CTSE			(1 << 9)
#define USART_CR3_RTSE			(1 << 8)
#define USART_CR3_DMAT			(1 << 7)
#define USART_CR3_DMAR			(1 << 6)
#define USART_CR3_SCEN			(1 << 5)
#define USART_CR3_NACK			(1 << 4)
#define USART_CR3_HDSEL			(1 << 3)
#define USART_CR3_IRLP			(1 << 2)
#define USART_CR3_IREN			(1 << 1)
#define USART_CR3_EIE			(1 << 0)

/* USART_GTPR Values --------------------------------------------------------*/

#define USART_GTPR_GT_SHIFT		8
#define USART_GTPR_GT_MASK		0xff

#define USART_GTPR_PSC_SHIFT		0
#define USART_GTPR_PSC_MASK		0xff


/* USART_RTOR Values --------------------------------------------------------*/

#define USART_RTOR_BLEN_SHIFT		24
#define USART_RTOR_BLEN_MASK		0xff

#define USART_RTOR_RTO_SHIFT		0
#define USART_RTOR_RTO_MASK		0xff

/* USART_RQR Values ---------------------------------------------------------*/

#define USART_RQR_TXFRQ			(1 << 4)
#define USART_RQR_RXFRQ			(1 << 3)
#define USART_RQR_MMRQ			(1 << 2)
#define USART_RQR_SBKRQ			(1 << 1)
#define USART_RQR_ABRRQ			(1 << 0)

/* USART_ISR Values ---------------------------------------------------------*/

#define USART_ISR_REACK			(1 << 22)
#define USART_ISR_TEACK			(1 << 21)
#define USART_ISR_WUF			(1 << 20)
#define USART_ISR_RWU			(1 << 19)
#define USART_ISR_SBKF			(1 << 18)
#define USART_ISR_CMF			(1 << 17)
#define USART_ISR_BUSY			(1 << 16)
#define USART_ISR_ABRF			(1 << 15)
#define USART_ISR_ABRE			(1 << 14)
#define USART_ISR_EOBF			(1 << 12)
#define USART_ISR_RTOF			(1 << 11)
#define USART_ISR_CTS			(1 << 10)
#define USART_ISR_CTSIF			(1 << 9)
#define USART_ISR_LBDF			(1 << 8)
#define USART_ISR_TXE			(1 << 7)
#define USART_ISR_TC			(1 << 6)
#define USART_ISR_RXNE			(1 << 5)
#define USART_ISR_IDLE			(1 << 4)
#define USART_ISR_ORE			(1 << 3)
#define USART_ISR_NF			(1 << 2)
#define USART_ISR_FE			(1 << 1)
#define USART_ISR_PE			(1 << 0)

/* USART_ICR Values ---------------------------------------------------------*/

#define USART_ICR_WUCF			(1 << 20)
#define USART_ICR_CMCF			(1 << 17)
#define USART_ICR_EOBCF			(1 << 12)
#define USART_ICR_RTOCF			(1 << 11)
#define USART_ICR_CTSCF			(1 << 9)
#define USART_ICR_LBDCF			(1 << 8)
#define USART_ICR_TCCF			(1 << 6)
#define USART_ICR_IDLECF		(1 << 4)
#define USART_ICR_ORECF			(1 << 3)
#define USART_ICR_NCF			(1 << 2)
#define USART_ICR_FECF			(1 << 1)
#define USART_ICR_PECF			(1 << 0)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

#define USART_PARITY			(USART_CR1_PCE | USART_CR1_PS)
#define USART_PARITY_NONE		(0)
#define USART_PARITY_EVEN		(USART_CR1_PCE)
#define USART_PARITY_ODD		(USART_CR1_PCE | USART_CR1_PS)

#define USART_MODE			(USART_CR1_TE | USART_CR1_RE)
#define USART_MODE_NONE			(0)
#define USART_MODE_RX			(USART_CR1_RE)
#define USART_MODE_TX			(USART_CR1_TE)
#define USART_MODE_TX_RX		(USART_CR1_TE | USART_CR1_RE)

#define USART_FLOWCONTROL		(USART_CR3_RTSE | USART_CR3_CTSE)
#define USART_FLOWCONTROL_NONE		(0)
#define USART_FLOWCONTROL_RTS		(USART_CR3_RTSE)
#define USART_FLOWCONTROL_CTS		(USART_CR3_CTSE)
#define USART_FLOWCONTROL_RTS_CTS	(USART_CR3_RTSE | USART_CR3_CTSE)

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void usart_set_baudrate(uint32_t usart, uint32_t baud);
void usart_set_databits(uint32_t usart, uint32_t bits);
void usart_set_stopbits(uint32_t usart, uint32_t stopbits);
void usart_set_parity(uint32_t usart, uint32_t parity);
void usart_set_mode(uint32_t usart, uint32_t mode);
void usart_set_flow_control(uint32_t usart, uint32_t flowcontrol);
void usart_enable(uint32_t usart);
void usart_disable(uint32_t usart);
void usart_send(uint32_t usart, uint16_t data);
uint16_t usart_recv(uint32_t usart);
void usart_wait_send_ready(uint32_t usart);
void usart_wait_recv_ready(uint32_t usart);
void usart_send_blocking(uint32_t usart, uint16_t data);
uint16_t usart_recv_blocking(uint32_t usart);
void usart_enable_rx_dma(uint32_t usart);
void usart_disable_rx_dma(uint32_t usart);
void usart_enable_tx_dma(uint32_t usart);
void usart_disable_tx_dma(uint32_t usart);
void usart_enable_rx_interrupt(uint32_t usart);
void usart_disable_rx_interrupt(uint32_t usart);
void usart_enable_tx_interrupt(uint32_t usart);
void usart_disable_tx_interrupt(uint32_t usart);
void usart_enable_error_interrupt(uint32_t usart);
void usart_disable_error_interrupt(uint32_t usart);
bool usart_get_flag(uint32_t usart, uint32_t flag);
bool usart_get_interrupt_source(uint32_t usart, uint32_t flag);
uint32_t usart_get_clock(uint32_t usart);
void usart_set_autobaudrate(uint32_t usart, int mode);

END_DECLS

#endif
/** @cond */
#else
#error "usart_common_fl_0.h should not be included directly, only via usart.h"
#endif
/** @endcond */
