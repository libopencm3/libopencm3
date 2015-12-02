/** @defgroup can_defines CAN defines

@ingroup STM32F_defines

@brief <b>libopencm3 Defined Constants and Types for STM32 CAN </b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010 Piotr Esden-Tempski <piotr@esden.net>

@date 12 November 2012

LGPL License Terms @ref lgpl_license
*/
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA CAN.H
The order of header inclusion is important. can.h includes the device
specific memorymap.h header before including this header file.*/

#ifndef LIBOPENCM3_CAN_COMMON_F124_H
#define LIBOPENCM3_CAN_COMMON_F124_H

#include <libopencm3/stm32/common/can_common_bxcan.h>

/* --- Convenience macros -------------------------------------------------- */

/* CAN register base addresses (for convenience) */
/*****************************************************************************/
/** @defgroup can_reg_base CAN register base address
@ingroup can_defines

@{*/
#define CAN1				BX_CAN1_BASE
#define CAN2				BX_CAN2_BASE
/**@}*/

/* --- CAN_FMR values ------------------------------------------------------- */

/*
 * CAN2SB[5:0]: CAN2 start bank
 * (only on connectivity line devices otherwise reserved)
 */
#define CAN_FMR_CAN2SB_MASK		(0x3F << 8)
#define CAN_FMR_CAN2SB_SHIFT		15

#endif
