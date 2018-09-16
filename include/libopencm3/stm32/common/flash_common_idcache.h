/** @addtogroup flash_defines
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

#include <libopencm3/stm32/flash.h>

/**@{*/
#define FLASH_ACR_DCRST			(1 << 12)
#define FLASH_ACR_ICRST			(1 << 11)
#define FLASH_ACR_DCEN			(1 << 10)
#define FLASH_ACR_ICEN			(1 << 9)


BEGIN_DECLS

/** Enable the data cache */
void flash_dcache_enable(void);

/** Disable the data cache */
void flash_dcache_disable(void);

/** Enable the Instruction Cache */
void flash_icache_enable(void);

/** Disable the Instruction Cache */
void flash_icache_disable(void);

/** Reset the Data Cache.
 * The data cache must be disabled for this to have effect.
 */
void flash_dcache_reset(void);

/** Reset the Instruction Cache.
 * The instruction cache must be disabled for this to have effect.
 */
void flash_icache_reset(void);

END_DECLS
/**@}*/

