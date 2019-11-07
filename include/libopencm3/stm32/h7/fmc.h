/** @defgroup fmc_defines FMC Defines
 * @brief <b>Defined Constants and Types for the STM32H7xx Flexible Memory
 * Controller</b>
 * @ingroup STM32H7xx_defines
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
/**@{*/

#ifndef LIBOPENCM3_H7_FMC_H
#define LIBOPENCM3_H7_FMC_H

#ifndef LIBOPENCM3_FSMC_H
#error "This file should not be included directly, it is included with fsmc.h"
#endif

#include <libopencm3/stm32/common/fmc_common_f47.h>

/* --- Convenience macros -------------------------------------------------- */
#define FSMC_BASE				FMC_BASE

#endif

/**@}*/
