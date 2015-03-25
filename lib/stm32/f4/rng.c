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
 * This library supports the random number generator peripheral (RNG) in the STM32F4
 * series of ARM Cortex Microcontrollers by ST Microelectronics.
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

/*---------------------------------------------------------------------------*/
/** @brief Returns a random number.
When a number is randomly generated, and there was no errors, the function will return it.
@returns data Unsigned int32.
*/
uint32_t rng_get_random(void)
{
    //Waits while the number is not ready, and/or there was an error.
    while(((RNG_SR & RNG_SR_DRDY) != 1 || (RNG_SR & (RNG_SR_CEIS & RNG_SR_SEIS)) != 0));

    return RNG_DR;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable rng.
The random number generator is disabled.
*/
void rng_disable(void)
{
    //Clear the enable flag in RNG_CR
    RNG_CR &= ~RNG_CR_RNGEN;
}

/*---------------------------------------------------------------------------*/
/** @brief Enable rng.
The random number generator is enabled.
*/
void rng_enable(void)
{
    //Set the enable flag in RNG_CR
    RNG_CR |= RNG_CR_RNGEN;
}

/*---------------------------------------------------------------------------*/
/**@}*/
