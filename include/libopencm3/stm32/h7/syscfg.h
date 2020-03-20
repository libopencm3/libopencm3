/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @ingroup STM32H7xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32H7xx System Configuration controller </b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Brian Viele <vielster@allocor.tech>
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

#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H

#include <libopencm3/cm3/common.h>

/**@{*/
/**@defgroup syscfg_registers SYSCFG Registers
￼  @{*/
#define SYSCFG_PMCR				MMIO32(SYSCFG_BASE + 0x04)
#define SYSCFG_EXTICR(i)			MMIO32(SYSCFG_BASE + 0x08 + (i)*4)
#define SYSCFG_EXTICR1			MMIO32(SYSCFG_BASE + 0x08)
#define SYSCFG_EXTICR2			MMIO32(SYSCFG_BASE + 0x0C)
#define SYSCFG_EXTICR3			MMIO32(SYSCFG_BASE + 0x10)
#define SYSCFG_EXTICR4			MMIO32(SYSCFG_BASE + 0x14)
#define SYSCFG_CFGR				MMIO32(SYSCFG_BASE + 0x18)
#define SYSCFG_CCSR				MMIO32(SYSCFG_BASE + 0x20)
#define SYSCFG_CCVR				MMIO32(SYSCFG_BASE + 0x24)
#define SYSCFG_CCCR				MMIO32(SYSCFG_BASE + 0x28)
#define SYSCFG_PWRCR				MMIO32(SYSCFG_BASE + 0x2C)
#define SYSCFG_PKGR				MMIO32(SYSCFG_BASE + 0x124)
#define SYSCFG_UR(n)      MMIO32(SYSCFG_BASE + 0x300 + (4 * (n)))

#define SYSCFG_EXTICR_FIELDSIZE		4
/**@}*/



/** @defgroup syscfg_pwrcr PWRCR SYSCFG configuration register
 * @ingroup syscfg_registers
 * @{*/
#define SYSCFG_PWRCR_ODEN			BIT0
/**@}*/


/**@}*/

#endif
