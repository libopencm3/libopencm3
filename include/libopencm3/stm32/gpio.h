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

#if defined(STM32F0)
#       include <libopencm3/stm32/f0/gpio.h>
#elif defined(STM32F1)
#       include <libopencm3/stm32/f1/gpio.h>
#elif defined(STM32F2)
#       include <libopencm3/stm32/f2/gpio.h>
#elif defined(STM32F3)
#       include <libopencm3/stm32/f3/gpio.h>
#elif defined(STM32F4)
#       include <libopencm3/stm32/f4/gpio.h>
#elif defined(STM32F7)
#       include <libopencm3/stm32/f7/gpio.h>
#elif defined(STM32L0)
#       include <libopencm3/stm32/l0/gpio.h>
#elif defined(STM32L1)
#       include <libopencm3/stm32/l1/gpio.h>
#elif defined(STM32L4)
#       include <libopencm3/stm32/l4/gpio.h>
#elif defined(STM32G0)
#       include <libopencm3/stm32/g0/gpio.h>
#elif defined(STM32H7)
#       include <libopencm3/stm32/h7/gpio.h>
#elif defined(GD32F1X0)
#       include <libopencm3/gd32/f1x0/gpio.h>
#else
#       error "stm32 family not defined."
#endif

