/* This provides unification of code over STM32F subfamilies */

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
#       include <libopencm3/stm32/f2/crypto.h>
#elif defined(STM32F4)
#       include <libopencm3/stm32/f4/crypto.h>
#else
#       error "CRYPTO processor is supported only" \
	"in stm32f2xx, stm32f41xx, stm32f42xx and stm32f43xx family."
#endif
