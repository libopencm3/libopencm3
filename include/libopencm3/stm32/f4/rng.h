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

#ifndef LIBOPENCM3_RNG_H
#define LIBOPENCM3_RNG_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Random number generator registers ----------------------------------- */

/* Control register */
#define RNG_CR			MMIO32(RNG_BASE + 0x00) 

/* Status register */
#define RNG_SR			MMIO32(RNG_BASE + 0x04)

/* Data register */
#define RNG_DR			MMIO32(RNG_BASE + 0x08)

/* --- RNG_CR values ------------------------------------------------------- */

/* RNG ENABLE */
#define RNG_CR_EN			(1 << 2)

/* RNG interupt enable */
#define RNG_CR_IE			(1 << 3)

/* --- RNG_SR values ------------------------------------------------------- */

/* Data ready */
#define RNG_SR_DRDY		(1 << 0)

/* Clock error current status */
#define RNG_SR_CECS		(1 << 1)

/* Seed error current status */
#define RNG_SR_SECS		(1 << 2)

/* Clock error interup status */
#define RNG_SR_CEIS		(1 << 5)

/* Seed error interup status */
#define RNG_SR_SEIS		(1 << 6)

#endif
