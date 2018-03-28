/** @addtogroup iwdg_defines

 @author @htmlonly &copy; @endhtmlonly 2018 Guillame Revaillot <revaillot@archos.com>

 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Guillaume Revaillot <revaillot@archos.com>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA IWDG.H
The order of header inclusion is important. iwdg.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_IWDG_H
/** @endcond */
#pragma once

/**@{*/

#include <libopencm3/stm32/common/iwdg_common_all.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

/** Window Register (IWDG_WINR) */
#define IWDG_WINR				MMIO32(IWDG_BASE + 0x10)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/** @addtogroup iwdg_sr_values
@{*/
/** WVU: Watchdog counter window value update */
#define IWDG_SR_WVU			(1 << 2)
/**@}*/

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/


BEGIN_DECLS

END_DECLS

/**@}*/

/** @cond */
#else
#warning "iwdg_common_v2.h should not be included explicitly, only via iwdg.h"
#endif
/** @endcond */

