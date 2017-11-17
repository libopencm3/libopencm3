/** @defgroup flash_defines FLASH Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L0xx Flash memory</b>
 *
 * @ingroup STM32L0xx_defines
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/stm32/common/flash_common_l01.h>

/* --- FLASH registers ----------------------------------------------------- */
/* L0 has some alternative names for the same registers */
#define FLASH_OPTR			FLASH_OBR
#define FLASH_WRPROT1			FLASH_WRPR1
#define FLASH_WRPROT2			FLASH_WRPR2

/* --- FLASH_ACR values ---------------------------------------------------- */
#define FLASH_ACR_PRE_READ		(1 << 6)
#define FLASH_ACR_DISAB_BUF		(1 << 5)

/* --- FLASH_PECR values ---------------------------------------------------- */
#define FLASH_PECR_NZDISABLE		(1 << 23)

/* --- FLASH_SR values ----------------------------------------------------- */
#define FLASH_SR_RDERR			(1 << 13)
#define FLASH_SR_NOTZEROERR		(1 << 16)
#define FLASH_SR_FWWERR			(1 << 17)

/* --- FLASH_OPTR values ----------------------------------------------------- */
#define FLASH_OPTR_NBOOT1		(1 << 31)

BEGIN_DECLS

END_DECLS
/**@}*/

#endif
