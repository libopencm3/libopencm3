/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_PWR_F2_H
#define LIBOPENCM3_PWR_F2_H

#include <libopencm3/stm32_common/pwr.h>
#include <libopencm3/cm3/common.h>


/*
 * This file extends the version in stm_common with definitions only
 * applicable to the STM32F2 series of devices.
 */

/* --- PWR_CR values ------------------------------------------------------- */

/* FPDS: Flash power down in stop mode, only available in F2 family devices. */
#define PWR_CR_FPDS			(1 << 9)

/* --- PWR_CSR values ------------------------------------------------------ */

/* BRE: Backup regulator enable */
#define PWR_CSR_BRE			(1 << 9)

#endif
