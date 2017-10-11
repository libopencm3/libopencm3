/** @defgroup usart_defines USART Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F0xx USART</b>
 *
 * @ingroup STM32F0xx_defines
 *
 * @version 1.0.0
 *
 * @date 2 July 2013
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

#include <libopencm3/stm32/common/usart_common_v2.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

#define USART1				USART1_BASE
#define USART2				USART2_BASE
#define USART3				USART3_BASE
#define USART4				USART4_BASE

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* USART_CR1 Values ---------------------------------------------------------*/

#define USART_CR1_DEAT_SHIFT		21
#define USART_CR1_DEAT			(0x1F << USART_CR1_DEAT_SHIFT)
#define USART_CR1_DEAT_VAL(x)		((x) << USART_CR1_DEAT_SHIFT)

#define USART_CR1_DEDT_SHIFT		16
#define USART_CR1_DEDT			(0x1F << USART_CR1_DEDT_SHIFT)
#define USART_CR1_DEDT_VAL(x)		((x) << USART_CR1_DEDT_SHIFT)

/* USART_CR2 Values ---------------------------------------------------------*/

#define USART_CR2_ADD_SHIFT		24
#define USART_CR2_ADD			(0xFF << USART_CR2_ADD_SHIFT)
#define USART_CR2_ADD_VAL(x)		((x) << USART_CR2_ADD_SHIFT)

#define USART_CR2_ABRMOD_SHIFT		21
#define USART_CR2_ABRMOD		(3 << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_STARTBIT	(0 << USART_CR2_ABRMOD_SHIFT)
#define USART_CR2_ABRMOD_FALLTOFALL	(1 << USART_CR2_ABRMOD_SHIFT)

#define USART_CR2_STOP_SHIFT		12
#define USART_CR2_STOP			(3 << USART_CR2_STOP_SHIFT)
#define USART_CR2_STOP_1_0BIT		(0 << USART_CR2_STOP_SHIFT)
#define USART_CR2_STOP_2_0BIT		(2 << USART_CR2_STOP_SHIFT)
#define USART_CR2_STOP_1_5BIT		(3 << USART_CR2_STOP_SHIFT)

/* USART_CR3 Values ---------------------------------------------------------*/

#define USART_CR3_SCARCNT_SHIFT		17
#define USART_CR3_SCARCNT		(7 << USART_CR3_SCARCNT_SHIFT)
#define USART_CR3_SCARCNT_DISABLE	(0 << USART_CR3_SCARCNT_SHIFT)
#define USART_CR3_SCARCNT_VAL(x)	((x) << USART_CR3_SCARCNT_SHIFT)

/* USART_GTPR Values --------------------------------------------------------*/

#define USART_GTPR_GT_SHIFT		8
#define USART_GTPR_GT			(0xFF << USART_GTPR_GT_SHIFT)
#define USART_GTPR_GT_VAL(x)		((x) << USART_GTPR_GT_SHIFT)

#define USART_GTPR_PSC_SHIFT		0
#define USART_GTPR_PSC			(0xFF << USART_GTPR_PSC_SHIFT)
#define USART_GTPR_PSC_VAL(x)		((x) << USART_GTPR_PSC_SHIFT)

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

END_DECLS

#endif

