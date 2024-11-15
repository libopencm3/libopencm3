/* This provides unification of code over STM32 subfamilies */

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

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

#if defined(STM32F2)
#       include <libopencm3/stm32/f2/hash.h>
#elif defined(STM32F4)
#       include <libopencm3/stm32/f4/hash.h>
#elif defined(STM32L5)
#       include <libopencm3/stm32/l5/hash.h>
#elif defined(STM32L5_SECURE)
#       include <libopencm3/stm32/l5_secure/hash.h>
#else
#       error "hash processor is supported only" \
	"in stm32f21, stm32f41, stm32f43 and stm32l5 families."
#endif
