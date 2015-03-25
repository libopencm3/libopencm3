/** @defgroup rng_file RNG
 *
 * @ingroup STM32F4xx
 *
 * @brief <b>libopencm3 STM32F4xx RNG</b>
 *
 * @version 1.0.0
 *
 * @date 25 March 2015
 *
 * This library supports the random number generator peripheral (RNG) in the
 * STM32F4 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 *LGPL License Terms @ref lgpl_license
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/rng.h>

/**@{*/

/** Disable the Random Number Generator peripheral.
*/
void rng_disable(void)
{
    RNG_CR &= ~RNG_CR_RNGEN;
}

/** Enable the Random Number Generator peripheral.
*/
void rng_enable(void)
{
    RNG_CR |= RNG_CR_RNGEN;
}

/**@}*/
