/** @defgroup flash_defines FLASH Defines
 * @brief <b>Defined Constants and Types for the STM32H7xx Flash
 * controller</b>
 * @ingroup STM32H7xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Brian Viele <vielster@allocor.tech>
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

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H

#include <libopencm3/stm32/common/flash_common_all.h>

/**@{*/
/** @defgroup flash_registers Flash Registers
 * @ingroup flash_defines
@{*/
/** Flash Access Control register */
#define FLASH_ACR                     MMIO32(FLASH_MEM_INTERFACE_BASE + 0x00)
/** Flash Key register */
#define FLASH_KEYR                    MMIO32(FLASH_MEM_INTERFACE_BASE + 0x04)
/** Flash Option bytes key register */
#define FLASH_OPTKEYR                 MMIO32(FLASH_MEM_INTERFACE_BASE + 0x08)
/*@}*/

/** @defgroup flash_latency FLASH Wait States
@ingroup flash_defines
@{*/
#define FLASH_ACR_LATENCY_SHIFT       0
#define FLASH_ACR_LATENCY_MASK        0x0f
#define FLASH_ACR_WRHIGHFREQ_MASK     0x3
#define FLASH_ACR_WRHIGHFREQ_SHIFT    4
/*@}*/

/** @defgroup flash_acr_values FLASH_ACR values
 * @ingroup flash_registers
 * @brief Access Control register values
 * @{*/
/* The H7 doesn't support prefetch, so set a 0-value to make the prefetch enable/disable a no-op. */
#define FLASH_ACR_PRFTEN              (0)
/**@}*/

/** @defgroup FLASH Key Values.
@ingroup flash_defines
@{*/
#define FLASH_KEYR_KEY1               ((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2               ((uint32_t)0xcdef89ab)
#define FLASH_OPTKEYR_KEY1            ((uint32_t)0x08192a3b)
#define FLASH_OPTKEYR_KEY2            ((uint32_t)0x4c5d6e7f)
/**@}*/
/**@}*/

#endif

