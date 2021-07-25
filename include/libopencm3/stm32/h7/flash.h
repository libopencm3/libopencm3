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
#include <libopencm3/stm32/common/flash_common_f.h>
#include <libopencm3/stm32/common/flash_common_f24.h>

/**@{*/

/** @addtogroup flash_acr_values FLASH_ACR values
 * @ingroup flash_registers
 * @{
 */
#define FLASH_ACR_WRHF_VOS1_70MHZ     (0 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS1_185MHZ    (1 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS1_225MHZ    (2 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS2_55MHZ     (0 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS2_165MHZ    (1 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS2_225MHZ    (2 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS3_45MHZ     (0 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS3_135MHZ    (1 << FLASH_ACR_WRHIGHFREQ_SHIFT)
#define FLASH_ACR_WRHF_VOS3_225MHZ    (2 << FLASH_ACR_WRHIGHFREQ_SHIFT)
/**@}*/
#define FLASH_ACR_WRHIGHFREQ_MASK     (0x3)
#define FLASH_ACR_WRHIGHFREQ_SHIFT    (0x4)

/**@}*/

#endif

