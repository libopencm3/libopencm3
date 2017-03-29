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
/** @brief Randomizes a number.
@param[in] pointer to a uint32_t that will be randomized.
@returns uint8_t, 0 on error, 1 on success.
*/
uint8_t rng_get_random(uint32_t *rand_nr)
{
    //wait for data to get ready
    while ((RNG_SR & RNG_SR_DRDY) != 1);

    //check for clock error
    if (RNG_SR & RNG_SR_CECS)
    {
	//return error
	return 0;
    }

    //check for seed error
    if (RNG_SR & RNG_SR_SECS)
    {
	//disable and enable the RNG to reinitialize and restart the RNG
	rng_disable();
	rng_enable();
	//return with no errors
	return 0;
    }

    //set the random value
    *rand_nr = RNG_DR;

    //return with no errors
    return 1;
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
