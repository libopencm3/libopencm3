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
#define SYSCFG_EXTICR1			MMIO32(SYSCFG_BASE + 0x08)
#define SYSCFG_EXTICR2			MMIO32(SYSCFG_BASE + 0x0C)
#define SYSCFG_EXTICR3			MMIO32(SYSCFG_BASE + 0x10)
#define SYSCFG_EXTICR4			MMIO32(SYSCFG_BASE + 0x14)
#define SYSCFG_CFGR				MMIO32(SYSCFG_BASE + 0x18)
#define SYSCFG_CCSR				MMIO32(SYSCFG_BASE + 0x20)
#define SYSCFG_CCVR				MMIO32(SYSCFG_BASE + 0x24)
#define SYSCFG_CCCR				MMIO32(SYSCFG_BASE + 0x28)
#define SYSCFG_PWRCR			MMIO32(SYSCFG_BASE + 0x2C)
#define SYSCFG_PKGR				MMIO32(SYSCFG_BASE + 0x124)
#define SYSCFG_UR0				MMIO32(SYSCFG_BASE + 0x300)
#define SYSCFG_UR2				MMIO32(SYSCFG_BASE + 0x308)
#define SYSCFG_UR3				MMIO32(SYSCFG_BASE + 0x30C)
#define SYSCFG_UR4				MMIO32(SYSCFG_BASE + 0x310)
#define SYSCFG_UR5				MMIO32(SYSCFG_BASE + 0x314)
#define SYSCFG_UR6				MMIO32(SYSCFG_BASE + 0x318)
#define SYSCFG_UR7				MMIO32(SYSCFG_BASE + 0x31C)
#define SYSCFG_UR8				MMIO32(SYSCFG_BASE + 0x320)
#define SYSCFG_UR9				MMIO32(SYSCFG_BASE + 0x324)
#define SYSCFG_UR10				MMIO32(SYSCFG_BASE + 0x328)
#define SYSCFG_UR11				MMIO32(SYSCFG_BASE + 0x32C)
#define SYSCFG_UR12				MMIO32(SYSCFG_BASE + 0x330)
#define SYSCFG_UR13				MMIO32(SYSCFG_BASE + 0x334)
#define SYSCFG_UR14				MMIO32(SYSCFG_BASE + 0x338)
#define SYSCFG_UR15				MMIO32(SYSCFG_BASE + 0x33C)
#define SYSCFG_UR16				MMIO32(SYSCFG_BASE + 0x340)
#define SYSCFG_UR17				MMIO32(SYSCFG_BASE + 0x344)
/**@}*/

/** @defgroup syscfg_pwrcr PWRCR SYSCFG configuration register
 * @ingroup syscfg_registers
 * @{*/
#define SYSCFG_PWRCR_ODEN		BIT0
/**@}*/


/**@}*/

#endif
