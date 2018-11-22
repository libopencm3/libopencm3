/** @addtogroup rng_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2018
 * Gerrit Maus <funk@maus.xyz>, Luong Le <novercy@live.com>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Gerrit Maus <funk@maus.xyz>, Luong Le <novercy@live.com>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA RNG.H
The order of header inclusion is important. rng.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#if defined(LIBOPENCM3_RNG_H)
/** @endcond */
#ifndef LIBOPENCM3_RNG_COMMON_H
#define LIBOPENCM3_RNG_COMMON_H

/**@{*/

/** @defgroup rng_registers RNG Registers
 * @ingroup rng_defines
 * @brief RNG Registers
@{*/

/* --------------------- RNG registers for NRF52 -------------------------- */

/* Registers */
#define RNG_TASKS_START                MMIO32((RNG_BASE) + 0x000)
#define RNG_TASKS_STOP                 MMIO32((RNG_BASE) + 0x004)
#define RNG_EVENTS_VALRDY              MMIO32((RNG_BASE) + 0x100)
#define RNG_SHORTS                     MMIO32((RNG_BASE) + 0x200)
#define RNG_INTENSET                   MMIO32((RNG_BASE) + 0x304)
#define RNG_INTENCLR                   MMIO32((RNG_BASE) + 0x308)
#define RNG_CONFIG                     MMIO32((RNG_BASE) + 0x504)
#define RNG_VALUE                      MMIO32((RNG_BASE) + 0x508)
/**@}*/

/* --- RNG_SHORTS values ------------------------------------------------- */
/** @defgroup rng_shorts Set shortcuts between VALRDY event and STOP task
@ingroup rng_defines
@{*/
#define RNG_SHORTS_VALRDY_STOP_Disabled             (0 << 0)
#define RNG_SHORTS_VALRDY_STOP_DISABLED             (0 << 0)
#define RNG_SHORTS_VALRDY_STOP_Enabled              (1 << 0)
#define RNG_SHORTS_VALRDY_STOP_ENABLED              (1 << 0)
/**@}*/

/* --- RNG_INTENSET values ----------------------------------------------- */
/** @defgroup rng_intenset Enable interrupt sources (atomically)
@ingroup rng_defines
@{*/
#define RNG_INTENSET_VALRDY_Set                     (1 << 0)
#define RNG_INTENSET_VALRDY_SET                     (1 << 0)
#define RNG_INTENSET_VALRDY_Enabled                 (1 << 0)
#define RNG_INTENSET_VALRDY_ENABLED                 (1 << 0)
#define RNG_INTENSET_VALRDY_Disabled                (0 << 0)
#define RNG_INTENSET_VALRDY_DISABLED                (0 << 0)
/**@}*/

/* --- RNG_INTENCLR values ----------------------------------------------- */
/** @defgroup rng_intenclr Disable interrupt sources (atomically)
@ingroup rng_defines
@{*/
#define RNG_INTENCLR_VALRDY_Clear                   (1 << 0)
#define RNG_INTENCLR_VALRDY_CLEAR                   (1 << 0)
#define RNG_INTENCLR_VALRDY_Enabled                 (1 << 0)
#define RNG_INTENCLR_VALRDY_ENABLED                 (1 << 0)
#define RNG_INTENCLR_VALRDY_Disabled                (0 << 0)
#define RNG_INTENCLR_VALRDY_DISABLED                (0 << 0)
/**@}*/

/* --- RNG_CONFIG values ----------------------------------------------- */
/** @defgroup rng_config Enable or disable bias correction
@ingroup rng_defines
@{*/
#define RNG_CONFIG_DERCEN_Enabled                   (1 << 0)
#define RNG_CONFIG_DERCEN_ENABLED                   (1 << 0)
#define RNG_CONFIG_DERCEN_Disabled                  (0 << 0)
#define RNG_CONFIG_DERCEN_DISABLED                  (0 << 0)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS


END_DECLS
/**@}*/
#endif
/** @cond */
#else
#warning "rng_common.h should not be included explicitly, only via rng.h"
#endif
/** @endcond */

