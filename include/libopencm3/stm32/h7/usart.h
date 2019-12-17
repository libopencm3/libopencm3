/** @defgroup usart_defines USART Defines
 *
 * @brief <b>Defined Constants and Types for the STM32H7xx USART</b>
 *
 * @ingroup STM32H7xx_defines
 *
 * @version 1.0.0
 *
 * @date 6 November 2019
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

#include <libopencm3/stm32/common/usart_common_fifos.h>

/**@{*/
/** @defgroup usart_reg_base USART register base addresses
 * Holds all the U(S)ART peripherals supported.
 * @{
 */
#define USART1          USART1_BASE
#define USART2          USART2_BASE
#define USART3          USART3_BASE
#define UART4           UART4_BASE
#define UART5           UART5_BASE
#define USART6          USART6_BASE
#define UART7           UART7_BASE
#define UART8           UART8_BASE
/**@}*/

BEGIN_DECLS

END_DECLS

/**@}*/

#endif

