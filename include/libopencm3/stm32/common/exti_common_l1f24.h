/** @addtogroup exti_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2010
 * Mark Butler <mbutler@physics.otago.ac.nz>
 */
/*
 * This file is part of the libopencm3 project.
 *
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

/** @cond */
#if defined(LIBOPENCM3_EXTI_H)
/** @endcond */
#ifndef LIBOPENCM3_EXTI_COMMON_F24_H
#define LIBOPENCM3_EXTI_COMMON_F24_H
/**@{*/

#include <libopencm3/stm32/common/exti_common_all.h>

/* EXTI number definitions */
#define EXTI20				(1 << 20)
#define EXTI21				(1 << 21)
#define EXTI22				(1 << 22)
/**@}*/

#endif
/** @cond */
#else
#warning "exti_common_f24.h should not be included directly, only via exti.h"
#endif
/** @endcond */
