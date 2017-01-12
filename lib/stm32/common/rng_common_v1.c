/** @addtogroup rng_file
 *
 * This library supports the random number generator peripheral (RNG) in the
 * STM32F4 series of ARM Cortex Microcontrollers by ST Microelectronics.
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

/** Randomizes a number (non-blocking).
 * Can fail if a clock error or seed error is detected. Consult the Reference
 * Manual, but "try again", potentially after resetting the peripheral
 * @param pointer to a uint32_t that will be randomized.
 * @returns true on success, pointer is only written to on success
 * @sa rng_get_random_blocking
 */
bool rng_get_random(uint32_t *rand_nr)
{
        /* data ready */
        if (!(RNG_SR & RNG_SR_DRDY)) {
                return false;
        }

        /* Check for errors */
        if (RNG_SR & (RNG_SR_CECS | RNG_SR_SECS)) {
                return false;
        }

        *rand_nr = RNG_DR;

        return true;
}


/**
 * Get a random number and block until it works.
 * Unless you have a clock problem, this should always return "promptly"
 * If you have a clock problem, you will wait here forever!
 * @returns a random 32bit number
 */
uint32_t rng_get_random_blocking(void)
{
        uint32_t rv;
        bool done;
        do {
                if (RNG_SR & RNG_SR_SECS) {
                        rng_disable();
                        rng_enable();
                }
                done = rng_get_random(&rv);
        } while (!done);

        return rv;
}


/**@}*/
