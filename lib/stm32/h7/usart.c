/**
 * @brief <b>libopencm3 STM32H7xx Custom USART functions</b>
 *
 * @version 1.0.0
 *
 * @date 7 February, 2020
 *
 * This source file is to augment some of the standard USART function with special
 * implementations required for use in the STM32H7. This mainly includes elements
 * related to clocks.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Brian Viele <vielster@allocor.tech>
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
/*---------------------------------------------------------------------------*/

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/usart.h>

/** @brief USART Set Baudrate.

For the STM32H7, the clock tree is somewhat complicated. The USART modules
are grouped USART 2/3/4/5/7/8, USART 1/6. the RCC module reports each clock,
but for simplicity, use the first from grooup.

@param[in] usart unsigned 32 bit. USART block register address base @ref
usart_reg_base
@param[in] baud unsigned 32 bit. Baud rate specified in Hz.
*/

void usart_set_baudrate(uint32_t usart, uint32_t baud)
{
	uint32_t clock;
	if (usart == USART1 || usart == USART6) {
	        clock = rcc_get_clock_freq(RCC_USART1CLK);
	} else {
	        clock = rcc_get_clock_freq(RCC_USART2CLK);
	}
	USART_BRR(usart) = (clock + baud / 2) / baud;
}
