/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Modified by 2013 Fernando Cortes <fernando.corcam@gmail.com> (stm32f3)
 * Modified by 2013 Guillermo Rivera <memogrg@gmail.com> (stm32f3)
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

#ifndef LIBOPENCM3_PWR_F3_H
#define LIBOPENCM3_PWR_F3_H

#include <libopencm3/stm32/pwr.h>

/* --- PWR_CR values ------------------------------------------------------- */

/* Bits [31:10]: Reserved */
#define PWR_CR_DBP			(1 << 8)
/* Bits [7:5]: Reserved  PLS: PVD level selection. (Power Voltage Detector) */
#define PWR_CR_PVDE			(1 << 4)
#define PWR_CR_CSBF			(1 << 3)
#define PWR_CR_CWUF			(1 << 2)
#define PWR_CR_PDDS			(1 << 1)
#define PWR_CR_LPDS			(1 << 0)


/* --- PWR_CSR values ------------------------------------------------------ */

/* Bits [31:10]: Reserved */
#define PWR_CSR_EWUP2			(1 << 9)
#define PWR_CSR_EWUP1			(1 << 8)
/* Bits [7:3]: Reserved */
#define PWR_CSR_PVDO			(1 << 2)
#define PWR_CSR_SBF			(1 << 1)
#define PWR_CSR_WUF			(1 << 0)


#endif
