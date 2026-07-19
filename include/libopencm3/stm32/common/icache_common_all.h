/** @addtogroup icache_defines
 *
 * @author @htmlonly &copy; @endhtmlonly
 * 2026 ALTracer <11005378+ALTracer@users.noreply.github.com>
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2026 ALTracer <11005378+ALTracer@users.noreply.github.com>
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

/**@{*/

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA ICACHE.H
The order of header inclusion is important. icache.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_ICACHE_H
/** @endcond */
#ifndef LIBOPENCM3_ICACHE_COMMON_H
#define LIBOPENCM3_ICACHE_COMMON_H

/** @defgroup icache_registers ICACHE registers
 * @ingroup icache_defines
@{*/
/** ICACHE control register */
#define ICACHE_CR	MMIO32(ICACHE_BASE + 0x000U)
/** ICACHE status register */
#define ICACHE_SR	MMIO32(ICACHE_BASE + 0x004U)
/**@}*/

/** @defgroup icache_cr CR ICACHE control register
 * @ingroup icache_defines
@{*/
/** EN: enable */
#define ICACHE_CR_EN		(1U << 0U)
/** CACHEINV: cache invalidation */
#define ICACHE_CR_CACHEINV	(1U << 1U)
/** WAYSEL: cache associativity mode selection. Defaults to 1, or 0x4, i.e. 2-way set associative */
#define ICACHE_CR_WAYSEL	(1U << 2U)
/**@}*/

/** @defgroup icache_sr SR ICACHE status register
 * @ingroup icache_defines
@{*/
/** BUSYF: busy flag, high during a CACHEINV operation */
#define ICACHE_SR_BUSYF		(1U << 0U)
/** BUSYENDF: busy-end flag, asserted by hardware after CACHEINV finishes */
#define ICACHE_SR_BUSYENDF	(1U << 1U)
/** ERRF: error flag (cacheable write detected) */
#define ICACHE_SR_ERRF		(1U << 2U)
/**@}*/

BEGIN_DECLS

/** Enable the Instruction Cache */
void icache_enable(void);

/** Disable the Instruction Cache */
void icache_disable(void);

/** Invalidate the Instruction Cache.
 * During invalidation ICACHE is busy and will simply
 * forward any reads to Flash as if non-cacheable.
 */
void icache_reset(void);

END_DECLS

#endif
/** @cond */
#else
#warning "icache_common_all.h should not be included explicitly, only via icache.h"
#endif
/** @endcond */
/**@}*/
