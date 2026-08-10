/** @defgroup iwdg_defines IWDG Defines
 *
 * @brief <b>Defined Constants and Types for the GD32F1x0 Independent Watchdog
 * Timer</b>
 *
 * @ingroup GD32F1x0_defines
 *
 * @version 1.0.0
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

#ifndef LIBOPENCM3_IWDG_H
#define LIBOPENCM3_IWDG_H

/* GD32F1x0 IWDG (vendor name FWDGT) is register-compatible with the STM32F0
 * IWDG including the window-mode register (WINR). Verified empirically by
 * regtrace v0.2 (see decisions/v0.2/IWDG.md in the regtrace repo).
 */
#include <libopencm3/stm32/common/iwdg_common_v2.h>

#endif
