/** @defgroup flash_defines FLASH Defines
 *
 * @ingroup STM32F7xx_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2017
 * Matthew Lai <m@matthewlai.ca>
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Thomas Otto <tommi@viadmin.org>
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Mark Butler <mbutler@physics.otago.ac.nz>
 *
 * Differences between F7 and F4:
 * 1. 	icache and dcache are now combined into a unified ART cache. The CPU has
 * 	its own d/i-caches, but those are unrelated to this. They are on the
 *	AXIM bus.
 * 4. 	FLASH_SR_PGSERR (programming sequence error) is now FLASH_SR_ERSERR (
 *	erase sequence error).
 * 6. 	There are now two watchdogs - IWDG (independent watchdog) and WWDG (
 * 	window watchdog).
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017 Matthew Lai <m@matthewlai.ca>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2010 Mark Butler <mbutler@physics.otago.ac.nz>
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

/* --- FLASH_ACR values ---------------------------------------------------- */

/** @addtogroup flash_acr_values FLASH_ACR values
 * @ingroup flash_registers
@{*/
#define FLASH_ACR_ARTRST		(1U << 11U)
#define FLASH_ACR_ARTEN			(1U << 9U)
#define FLASH_ACR_PRFTEN		(1U << 8U)
/**@}*/

#define FLASH_SR_ERSERR			(1U << 7U)

/* --- FLASH_OPTCR values -------------------------------------------------- */

#define FLASH_OPTCR_IWDG_STOP		(1U << 31U)
#define FLASH_OPTCR_IWDG_STDBY		(1U << 30U)

#define FLASH_OPTCR_NWRP_SHIFT		16U
#define FLASH_OPTCR_NWRP_MASK		0xffU

#define FLASH_OPTCR_RDP_SHIFT		8U
#define FLASH_OPTCR_RDP_MASK		0xffU

#define FLASH_OPTCR_IWDG_SW		(1U << 5U)
#define FLASH_OPTCR_WWDG_SW		(1U << 4U)

#define FLASH_OPTCR_OPTSTRT		(1U << 1U)
#define FLASH_OPTCR_OPTLOCK		(1U << 0U)

/* --- FLASH_OPTCR1 values ------------------------------------------------- */
#define FLASH_OPTCR1_BOOT_ADD1_MASK	0xffffU
#define FLASH_OPTCR1_BOOT_ADD1_SHIFT	16U
#define FLASH_OPTCR1_BOOT_ADD0_MASK	0xffffU
#define FLASH_OPTCR1_BOOT_ADD0_SHIFT	0U

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void flash_clear_erserr_flag(void);
void flash_art_enable(void);
void flash_art_reset(void);

END_DECLS
/**@}*/

#endif
