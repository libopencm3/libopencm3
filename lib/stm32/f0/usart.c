/** @defgroup usart_file USART
 *
 * @ingroup STM32F0xx
 *
 * @brief <b>libopencm3 STM32F0xx Specific USART</b>
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

/*----------------------------------------------------------------------*/
/** @brief Get base clock for specified USART/UART
 *
 * @param [in] usart unsigned 32 bit, base address of USART
 *
 * This function returns the frequency of the clock supplying the
 * baudrate clock for the give USART/UART. It is used by the common
 * baudrate setting function to calculate the divisor for this particular
 * USART.
 */
uint32_t usart_get_clock(uint32_t usart) {
	int	shift;
	switch (usart) {
		case USART1:
			shift = RCC_CFGR3_USART1SW_SHIFT;
			break;
		case USART2:
			shift = RCC_CFGR3_USART2SW_SHIFT;
			break;
		case USART3:
			shift = RCC_CFGR3_USART3SW_SHIFT;
			break;
		default:
			return rcc_apb1_frequency;
	}
	switch ((RCC_CFGR3 >> shift) & RCC_CFGR3_USART_CLK_MASK) {
		default:
		case RCC_CFGR3_USART_CLK_APB:
			return rcc_apb1_frequency;
		case RCC_CFGR3_USART_CLK_SYS:
			return rcc_ahb_frequency;
		case RCC_CFGR3_USART_CLK_HSI:
			return 16000000;
		case RCC_CFGR3_USART_CLK_LSE:
			return rcc_lse_frequency;
	}
}

/**@}*/

