/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- PWR registers ------------------------------------------------------- */

/* Power control register (PWR_CR) */
#define PWR_CR				MMIO32(POWER_CONTROL_BASE + 0x00)

/* Power control/status register (PWR_CSR) */
#define PWR_CSR				MMIO32(POWER_CONTROL_BASE + 0x04)

/* --- PWR_CR values ------------------------------------------------------- */

/* DBP: Disable backup domain write protection */
#define PWR_CR_DBP			(1 << 8)

/* PLS[7:5]: PVD level selection */
#define PWR_CR_PLS_LSB			5
#define PWR_CR_PLS_2V2			0x0
#define PWR_CR_PLS_2V3			0x1
#define PWR_CR_PLS_2V4			0x2
#define PWR_CR_PLS_2V5			0x3
#define PWR_CR_PLS_2V6			0x4
#define PWR_CR_PLS_2V7			0x5
#define PWR_CR_PLS_2V8			0x6
#define PWR_CR_PLS_2V9			0x7

/* PVDE: Power voltage detector enable */
#define PWR_CR_PVDE			(1 << 4)

/* CSBF: Clear standby flag */
#define PWR_CR_CSBF			(1 << 3)

/* CWUF: Clear wakeup flag */
#define PWR_CR_CWUF			(1 << 2)

/* PDDS: Power down deepsleep */
#define PWR_CR_PDDS			(1 << 1)

/* LPDS: Low-power deepsleep */
#define PWR_CR_LPDS			(1 << 0)

/* --- PWR_CSR values ------------------------------------------------------ */

/* EWUP: Enable WKUP pin */
#define PWR_CSR_EWUP			(1 << 8)

/* PVDO: PVD output */
#define PWR_CSR_PVDO			(1 << 2)

/* SBF: Standby flag */
#define PWR_CSR_SBF			(1 << 1)

/* WUF: Wakeup flag */
#define PWR_CSR_WUF			(1 << 0)

/* --- PWR function prototypes ------------------------------------------- */

#endif
