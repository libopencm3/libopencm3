/*
 * This file is part of the libopencm3 project.
 *
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA RNG.H
The order of header inclusion is important. rng.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_RNG_H
/** @endcond */
#ifndef LIBOPENCM3_RNG_COMMON_F24_H
#define LIBOPENCM3_RNG_COMMON_F24_H

/* --- Random number generator registers ----------------------------------- */

/* Control register */
#define RNG_CR			MMIO32(RNG_BASE + 0x00)

/* Status register */
#define RNG_SR			MMIO32(RNG_BASE + 0x04)

/* Data register */
#define RNG_DR			MMIO32(RNG_BASE + 0x08)

/* --- RNG_CR values ------------------------------------------------------- */

/* RNG ENABLE */
#define RNG_CR_RNGEN		(1 << 2)

/* RNG interrupt enable */
#define RNG_CR_IE			(1 << 3)

/* --- RNG_SR values ------------------------------------------------------- */

/* Data ready */
#define RNG_SR_DRDY		(1 << 0)

/* Clock error current status */
#define RNG_SR_CECS		(1 << 1)

/* Seed error current status */
#define RNG_SR_SECS		(1 << 2)

/* Clock error interrupt status */
#define RNG_SR_CEIS		(1 << 5)

/* Seed error interrupt status */
#define RNG_SR_SEIS		(1 << 6)

#endif
/** @cond */
#else
#warning "rng_common_f24.h should not be included explicitly, only via rng.h"
#endif
/** @endcond */

