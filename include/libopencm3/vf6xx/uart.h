/** @defgroup VF6xx_uart_defines UART Defines
 *
 * @brief <b>Defined Constants and Types for the VF6xx UART Module</b>
 *
 * @ingroup VF6xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Stefan Agner <stefan@agner.ch>
 *
 * @date 01 July 2014
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

#ifndef LIBOPENCM3_VF6XX_UART_H
#define LIBOPENCM3_VF6XX_UART_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/vf6xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup uart_reg_base UART register base addresses
@ingroup VF6xx_uart_defines

@{*/
#define UART0				UART0_BASE
#define UART1				UART1_BASE
#define UART2				UART2_BASE
#define UART3				UART3_BASE
#define UART4				UART4_BASE
#define UART5				UART5_BASE

/* --- UART registers ------------------------------------------------------ */

#define UART_BDH(uart_base)		MMIO8((uart_base) + 0x00)
#define UART_BDL(uart_base)		MMIO8((uart_base) + 0x01)
#define UART_C1(uart_base)		MMIO8((uart_base) + 0x02)
#define UART_C2(uart_base)		MMIO8((uart_base) + 0x03)
#define UART_S1(uart_base)		MMIO8((uart_base) + 0x04)
#define UART_S2(uart_base)		MMIO8((uart_base) + 0x05)
#define UART_C3(uart_base)		MMIO8((uart_base) + 0x06)
#define UART_D(uart_base)		MMIO8((uart_base) + 0x07)
#define UART_MA1(uart_base)		MMIO8((uart_base) + 0x08)
#define UART_MA2(uart_base)		MMIO8((uart_base) + 0x09)
#define UART_C4(uart_base)		MMIO8((uart_base) + 0x0A)
#define UART_C5(uart_base)		MMIO8((uart_base) + 0x0B)
#define UART_ED(uart_base)		MMIO8((uart_base) + 0x0C)
#define UART_MODEM(uart_base)		MMIO8((uart_base) + 0x0D)
/* Incomplete */

/* --- CCM values -....----------------------------------------------------- */

/* BDH: Baud Rate Register High */
#define UART_BDH_LBKDIE				(1 << 7)
#define UART_BDH_RXEDGIE			(1 << 6)
#define UART_BDH_SBR_MASK			0x1f

/* BDL: Baud Rate Register Low */
#define UART_BDL_SBR_MASK			0xff

/* C1: Control register 1 */
#define UART_C1_LOOPS				(1 << 7)
#define UART_C1_RSRC				(1 << 5)
#define UART_C1_M				(1 << 4)
#define UART_C1_WAKE				(1 << 3)
#define UART_C1_ILT				(1 << 2)
#define UART_C1_PE				(1 << 1)
#define UART_C1_PT				(1 << 0)

/* C2: Control register 2 */
#define UART_C2_TIE				(1 << 7)
#define UART_C2_TCIE				(1 << 6)
#define UART_C2_RIE				(1 << 5)
#define UART_C2_ILIE				(1 << 4)
#define UART_C2_TE				(1 << 3)
#define UART_C2_RE				(1 << 2)
#define UART_C2_RWU				(1 << 1)
#define UART_C2_SBK				(1 << 0)

/* S1: Status register 1 */
#define UART_S1_TDRE				(1 << 7)
#define UART_S1_TC				(1 << 6)
#define UART_S1_RDRF				(1 << 5)
#define UART_S1_IDLE				(1 << 4)
#define UART_S1_OR				(1 << 3)
#define UART_S1_NF				(1 << 2)
#define UART_S1_FE				(1 << 1)
#define UART_S1_PF				(1 << 0)

/* S2: Status register 2 */
#define UART_S2_LBKDIF				(1 << 7)
#define UART_S2_RXEDGIF				(1 << 6)
#define UART_S2_MSBF				(1 << 5)
#define UART_S2_RXINV				(1 << 4)
#define UART_S2_RWUID				(1 << 3)
#define UART_S2_BRK13				(1 << 2)
#define UART_S2_LBKDE				(1 << 1)
#define UART_S2_RAF				(1 << 0)

/* C3: Control register 3 */
#define UART_C3_R8				(1 << 7)
#define UART_C3_T8				(1 << 6)
#define UART_C3_TXDIR				(1 << 5)
#define UART_C3_TXINV				(1 << 4)
#define UART_C3_ORIE				(1 << 3)
#define UART_C3_NEIE				(1 << 2)
#define UART_C3_FEIE				(1 << 1)
#define UART_C3_PEIE				(1 << 0)

/* MODEM: Modem configuration register */
#define UART_MODEM_RXRTSE			(1 << 3)
#define UART_MODEM_TXRTSPOL			(1 << 2)
#define UART_MODEM_TXRTSE			(1 << 1)
#define UART_MODEM_TXCTSE			(1 << 0)

/****************************************************************************/
/** @defgroup uart_parity UART Parity Selection
@ingroup VF6xx_uart_defines

@{*/
#define UART_PARITY_NONE		0x00
#define UART_PARITY_EVEN		UART_C1_PE
#define UART_PARITY_ODD			(UART_C1_PE | UART_C1_PT)
/**@}*/
#define UART_PARITY_MASK		0x3

/* CR3_CTSE/CR3_RTSE combined values */
/****************************************************************************/
/** @defgroup usart_cr3_flowcontrol USART Hardware Flow Control Selection
@ingroup STM32F_usart_defines

@{*/
#define UART_FLOWCONTROL_NONE		0x00
#define UART_FLOWCONTROL_RTS		UART_MODEM_RXRTSE
#define UART_FLOWCONTROL_CTS		UART_MODEM_TXCTSE
#define UART_FLOWCONTROL_RTS_CTS	(UART_MODEM_RXRTSE | UART_MODEM_TXCTSE)
/**@}*/
#define UART_FLOWCONTROL_MASK		(UART_MODEM_RXRTSE | UART_MODEM_TXCTSE)

/* --- Function prototypes ------------------------------------------------- */

#include <libopencm3/cm3/common.h>

BEGIN_DECLS

void uart_enable(uint32_t uart);
void uart_disable(uint32_t uart);
void uart_set_baudrate(uint32_t uart, uint32_t baud);
void uart_set_parity(uint32_t uart, uint8_t parity);
void uart_set_flow_control(uint32_t uart, uint8_t flowcontrol);
void uart_send(uint32_t uart, uint8_t data);
void uart_send_blocking(uint32_t usart, uint8_t data);
void uart_wait_send_ready(uint32_t uart);
uint8_t uart_recv(uint32_t uart);
uint8_t uart_recv_blocking(uint32_t uart);
void uart_wait_recv_ready(uint32_t uart);

END_DECLS

#endif
