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
/** @cond */
#if defined(LIBOPENCM3_USART_H)
/** @endcond */
#ifndef LIBOPENCM3_USART_COMMON_V2_H
#define LIBOPENCM3_USART_COMMON_V2_H

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- USART_RTOR values --------------------------------------------------- */

/* BLEN[7:0]: Block Length */
#define USART_RTOR_BLEN_SHIFT			24
#define USART_RTOR_BLEN_MASK			(0xFF << USART_RTOR_BLEN_SHIFT)
#define USART_RTOR_BLEN_VAL(x)			((x) << USART_RTOR_BLEN_SHIFT)

/* RTO[23:0]: Receiver timeout value */
#define USART_RTOR_RTO_SHIFT			0
#define USART_RTOR_RTO_MASK			(0xFFFFF << USART_RTOR_RTO_SHIFT)
#define USART_RTOR_RTO_VAL(x)			((x) << USART_RTOR_RTO_SHIFT)

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

#endif
/** @cond */
#else
#warning "usart_common_v2.h should not be included directly, only via usart.h"
#endif
/** @endcond */
