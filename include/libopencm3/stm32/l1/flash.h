/** @defgroup flash_defines FLASH Defines
 *
 * @ingroup STM32L1xx_defines
 *
 * @brief Defined Constants and Types for the STM32L1xx FLASH Memory
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2012
 * Karl Palsson <karlp@tweak.net.au>
 *
 * @date 14 January 2014
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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

/*
 * All extracted from PM0062 rev2, L15xx and L16xx Flash/EEPROM programming
 * manual.
 */

#ifndef LIBOPENCM3_FLASH_H
#define LIBOPENCM3_FLASH_H
/**@{*/

#include <libopencm3/stm32/common/flash_common_l01.h>

/* --- FLASH registers ----------------------------------------------------- */
#define FLASH_WRPR3			MMIO32(FLASH_MEM_INTERFACE_BASE + 0x84)

/* --- FLASH_ACR values ---------------------------------------------------- */
#define FLASH_ACR_ACC64			(1 << 2)

/* --- FLASH_SR values ----------------------------------------------------- */
#define FLASH_SR_OPTVERRUSR		(1 << 12)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_64bit_enable(void);
void flash_64bit_disable(void);

END_DECLS
/**@}*/

#endif
