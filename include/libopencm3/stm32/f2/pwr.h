/** @defgroup pwr_defines PWR Defines

@brief <b>Defined Constants and Types for the STM32F2xx PWR Control</b>

@ingroup STM32F2xx_defines

@version 1.0.0

@date 4 March 2013

LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#ifndef LIBOPENCM3_PWR_F2_H
#define LIBOPENCM3_PWR_F2_H

#include <libopencm3/stm32/common/pwr_common_all.h>

/*
 * This file extends the common STM32 version with definitions only
 * applicable to the STM32F2 series of devices.
 */

/* --- PWR_CR values ------------------------------------------------------- */

/* Bits [31:10]: Reserved, always read as 0. */

/* FPDS: Flash power down in stop mode */
#define PWR_CR_FPDS			(1 << 9)

/* --- PWR_CSR values ------------------------------------------------------ */

/* Bits [31:10]: Reserved, always read as 0. */

/* BRE: Backup regulator enable */
#define PWR_CSR_BRE			(1 << 9)

/* Bits [7:4]: Reserved, always read as 0. */

#endif
