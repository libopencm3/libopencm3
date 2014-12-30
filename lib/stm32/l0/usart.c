/** @defgroup usart_file USART
 *
 * @ingroup STM32L0xx
 *
 * @brief <b>libopencm3 STM32L0xx USART</b>
 *
 * @version 1.0.0
 *
 * @date 7 Jul 2013
 *
 * LGPL License Terms @ref lgpl_license
 * TODO: 
 *  This, and the F0 USART code (from which it is currently
 * derived. Need to be merged into a common bit of code that
 * handles this "flavor" of ST Micro USART (the one that has
 * separate send and receive registers)
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
/** @brief USART Get Clocksource
 *
 * @param[in] usart unsigned 32 bit, USART block register address base @ref
 */
uint32_t usart_get_clock(uint32_t usart) {
	uint32_t	shift, mask;

	switch (usart) {
		case USART1:
			shift = RCC_CCIPR_USART1SEL_SHIFT;
			mask = RCC_CCIPR_USART1SEL_MASK;
			break;
		case USART2:
			shift = RCC_CCIPR_USART2SEL_SHIFT;
			mask = RCC_CCIPR_USART2SEL_MASK;
			break;
		case LPUART1:
			shift = RCC_CCIPR_LPUART1SEL_SHIFT;
			mask = RCC_CCIPR_LPUART1SEL_MASK;
			break;
		default:
			return rcc_apb1_frequency; // probable answer? 
	}
	switch ((RCC_CCIPR >> shift) & mask) {
		default:
			return rcc_apb1_frequency;
		case RCC_CCIPR_USART1SEL_SYS:
			return rcc_ahb_frequency;
		case RCC_CCIPR_USART1SEL_HSI16:
			return 16000000;
		case RCC_CCIPR_USART1SEL_LSE:
			return rcc_lse_frequency;
	}
}

/**@}*/
