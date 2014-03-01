/** @defgroup flash_defines FLASH Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F3xx Flash
 * controller </b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
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
/**@{*/

#include <libopencm3/stm32/common/flash_common_f234.h>

/* --- FLASH registers ----------------------------------------------------- */

#define FLASH_AR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x14)
#define FLASH_OBR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x1C)
#define FLASH_WRPR			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x20)

/* --- FLASH_ACR values ---------------------------------------------------- */

#define FLASH_ACR_PRFTBS		(1 << 5)
#define FLASH_ACR_PRFTBE		(1 << 4)
#define FLASH_ACR_HLFCYA		(1 << 3)

/* --- FLASH_SR values ----------------------------------------------------- */

#define FLASH_SR_BSY			(1 << 0)
#define FLASH_SR_ERLYBSY		(1 << 1)
#define FLASH_SR_PGPERR			(1 << 2)
#define FLASH_SR_WRPRTERR		(1 << 4)
#define FLASH_SR_EOP			(1 << 5)

/* --- FLASH_CR values ----------------------------------------------------- */

#define FLASH_CR_OBL_LAUNCH		(1 << 13)
#define FLASH_CR_EOPIE			(1 << 12)
#define FLASH_CR_ERRIE			(1 << 10)
#define FLASH_CR_OPTWRE			(1 << 9)
#define FLASH_CR_LOCK			(1 << 7)
#define FLASH_CR_STRT			(1 << 6)
#define FLASH_CR_OPTER			(1 << 5)
#define FLASH_CR_OPTPG			(1 << 4)
#define FLASH_CR_MER			(1 << 2)
#define FLASH_CR_PER			(1 << 1)
#define FLASH_CR_PG			(1 << 0)
/**@}*/

#endif

