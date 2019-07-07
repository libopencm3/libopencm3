/** @defgroup pwr_defines PWR Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L4Rxx/STM32L4Sxx Power Control</b>
 *
 * @ingroup STM32L4PLUSxx_defines
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA PWR.H
The order of header inclusion is important. pwr.h includes the device
specific memorymap.h header before including this header file.*/

/**@{*/
#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H

/* --- PWR registers ------------------------------------------------------- */

#define PWR_CR5			MMIO32(POWER_CONTROL_BASE + 0x80)

/* --- PWR_CR5 values ------------------------------------------------------- */

#define PWR_CR5_R1MODE		(1 << 8)

enum pwr_vos_scale {
	PWR_SCALE1,
	PWR_SCALE1BOOST,
	PWR_SCALE2,
};

#include <libopencm3/stm32/common/pwr_common_l4.h>

#endif
/**@}*/
