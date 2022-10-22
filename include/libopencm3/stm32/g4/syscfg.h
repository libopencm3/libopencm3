/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @ingroup STM32G4xx_defines
 *
 * @brief Defined Constants and Types for the STM32G4xx Sysconfig
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 * @{
 *  
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

#pragma once

/** @defgroup syscfg_registers SYSCFG registers
@{*/

#define SYSCFG_MEMRM			MMIO32(SYSCFG_BASE + 0x00)

#define SYSCFG_PMC			MMIO32(SYSCFG_BASE + 0x04)

/** External interrupt configuration registers [0..3] (SYSCFG_EXTICR[1..4]) */
#define SYSCFG_EXTICR(i)		MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1			SYSCFG_EXTICR(0)
#define SYSCFG_EXTICR2			SYSCFG_EXTICR(1)
#define SYSCFG_EXTICR3			SYSCFG_EXTICR(2)
#define SYSCFG_EXTICR4			SYSCFG_EXTICR(3)

#define SYSCFG_SWPR			MMIO32(SYSCFG_BASE + 0x20)
/**@}*/

#define SYSCFG_EXTICR_FIELDSIZE		4

/**@}*/
