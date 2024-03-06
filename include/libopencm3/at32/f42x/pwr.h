/** @defgroup pwr_defines PWR Defines

@brief <b>Defined Constants and Types for the AT32F42x PWR Control</b>

@ingroup AT32F42x_defines

@version 1.0.0

@date 27 November 2022

LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H

#include <libopencm3/stm32/common/pwr_common_v1.h>

/* --- PWR_CSR values (PWC_CTRLSTS) continued ------------------------------ */
#define PWR_CSR_EWUP7		(1 << 14)		/* SWPEN7 */
#define PWR_CSR_EWUP6		(1 << 13)		/* SWPEN6 */
#define PWR_CSR_EWUP5		(1 << 12)		/* SWPEN5 */
#define PWR_CSR_EWUP4		(1 << 11)		/* SWPEN4 */
#define PWR_CSR_EWUP2		(1 << 9)		/* SWPEN2 */
#define PWR_CSR_EWUP1		(1 << 8)		/* SWPEN1 */

/* --- PWR_CR2 register (PWC_CTRL2) ---------------------------------------- */
#define PWR_CR2			MMIO32(POWER_CONTROL_BASE + 0x20)

/* --- PWR_CR2 values (PWC_CTRL2) ------------------------------------------ */
#define PWR_CR2_ULPDS		(1 << 5)		/* VREXLPEN */

#endif
