/** @defgroup usart_file USART
 *
 * @ingroup STM32F0xx
 *
 * @brief <b>libopencm3 STM32F0xx USART</b>
 *
 * @version 1.0.0
 *
 * @date 7 Jul 2013
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
/** @brief USART Receiver DMA Enable.
 *
 * DMA is available on:
 * @li USART1 Rx DMA1 channel 3 or 5.
 * @li USART2 Rx DMA1 channel 5.
 *
 * @param usart USART block register address base @ref usart_reg_base
 */

void usart_enable_rx_dma(uint32_t usart)
{
	USART_CR3(usart) |= USART_CR3_DMAR;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Receiver DMA Disable.
 *
 * @param usart USART block register address base @ref usart_reg_base
 */

void usart_disable_rx_dma(uint32_t usart)
{
	USART_CR3(usart) &= ~USART_CR3_DMAR;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Transmitter DMA Enable.
 *
 * DMA is available on:
 * @li USART1 Tx DMA1 channel 2 or 4.
 * @li USART2 Tx DMA1 channel 4.
 *
 * @param usart USART block register address base @ref usart_reg_base
 */

void usart_enable_tx_dma(uint32_t usart)
{
	USART_CR3(usart) |= USART_CR3_DMAT;
}

/*---------------------------------------------------------------------------*/
/** @brief USART Transmitter DMA Disable.
 *
 * @param usart USART block register address base @ref usart_reg_base
 */

void usart_disable_tx_dma(uint32_t usart)
{
	USART_CR3(usart) &= ~USART_CR3_DMAT;
}


/**@}*/

