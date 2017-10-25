/** @addtogroup usart_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA USART.H
The order of header inclusion is important. usart.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#if defined(LIBOPENCM3_USART_H)
/** @endcond */
#ifndef LIBOPENCM3_USART_COMMON_ALL_H
#define LIBOPENCM3_USART_COMMON_ALL_H


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
#define USART_STOPBITS_0_5		USART_CR2_STOPBITS_0_5 /* .5 stop bit */
#define USART_STOPBITS_2		USART_CR2_STOPBITS_2   /* 2 stop bits */
#define USART_STOPBITS_1_5		USART_CR2_STOPBITS_1_5 /* 1.5 stop bit*/
/**@}*/

/* STOP[13:12]: STOP bits */
#define USART_CR2_STOPBITS_1		(0x00 << 12)     /* 1 stop bit */
#define USART_CR2_STOPBITS_0_5		(0x01 << 12)     /* 0.5 stop bits */
#define USART_CR2_STOPBITS_2		(0x02 << 12)     /* 2 stop bits */
#define USART_CR2_STOPBITS_1_5		(0x03 << 12)     /* 1.5 stop bits */
#define USART_CR2_STOPBITS_MASK		(0x03 << 12)
#define USART_CR2_STOPBITS_SHIFT	12


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
/** @cond */
#else
#warning "usart_common_all.h should not be included directly, only via usart.h"
#endif
/** @endcond */
/**@}*/

