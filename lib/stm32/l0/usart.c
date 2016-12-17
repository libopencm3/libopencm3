/** @defgroup usart_file USART
 *
 * @ingroup STM32L0xx
 *
 * @brief <b>libopencm3 STM32L0xx USART</b>
 *
 * @version 1.0.0
 *
 * @date 1 Jun 2016
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

#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/rcc.h>

/*---------------------------------------------------------------------------*/
/** @brief USART Set Baudrate.
 *
 * @param[in] usart unsigned 32 bit. USART block register address base @ref
 * usart_reg_base
 * @param[in] baud unsigned 32 bit. Baud rate specified in Hz.
 */

void usart_set_baudrate(uint32_t usart, uint32_t baud)
{
	uint32_t clock = rcc_apb2_frequency;

	if (usart == USART1) {
		clock = rcc_apb1_frequency;
		/* TODO selective PCLK, SYSCLK, HSI or LSE */
	}

	/* TODO check oversampling 16 */
	USART_BRR(usart) = ((2 * clock) + baud) / (2 * baud);
}
