/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 ARCOS-Lab UCR <arcoslab.org> 
 * Copyright (C) 2012 Fernando Cortes <fernando.corcam@gmail.com>
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

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/common/iwdg_common_all.h>


/* --- IWDG registers ------------------------------------------------------ */

/* Window register (IWDG_WINR) */
#define IWDG_WINR				MMIO32(IWDG_BASE + 0x10)


/* --- IWDG_SR values ------------------------------------------------------ */

/* WVU: Watchdog counter window value update */
#define IWGD_SR_WVU			(1 << 2)


/* --- IWDG_WIN values ----------------------------------------------------- */

/* Bits 11:0 WIN[11:0]: Watchdog counter window value */


#endif

