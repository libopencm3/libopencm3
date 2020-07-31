/** @defgroup flash_defines FLASH Defines
 *
 * @ingroup STM32F2xx_defines
 *
 * @brief Defined Constants and Types for the STM32F2xx FLASH Memory
 *
 * @version 1.0.0
 *
 * @date 14 January 2014
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

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H

#include <libopencm3/stm32/common/flash_common_all.h>
#include <libopencm3/stm32/common/flash_common_f.h>
#include <libopencm3/stm32/common/flash_common_f24.h>

#define FLASH_SR_PGSERR			(1 << 7)
#define FLASH_OPTCR_WDG_SW		(1 << 5)


BEGIN_DECLS

void flash_clear_pgserr_flag(void);

END_DECLS

#endif

