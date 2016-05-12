/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Daniele Lacamera <root at danielinux dot net>
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

#ifndef LPC17XX_UART_H
#define LPC17XX_UART_H

#include <libopencm3/cm3/common.h>

#define USART_SR_RXNE  USART_IC_RX
#define USART_SR_TXE   USART_IC_TX


bool usart_get_interrupt_source(uint32_t usart, uint32_t flag);


#endif

