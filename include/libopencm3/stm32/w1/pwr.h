/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- MEM registers ------------------------------------------------------- */

#define PWR_CLKSLEEPCR			MMIO32(PWR_BASE + 0x08)
#define PWR_CLKLSI10KCR			MMIO32(PWR_BASE + 0x0C)
#define PWR_CLKLSI1KCR			MMIO32(PWR_BASE + 0x10)
#define PWR_RSTSR			MMIO32(PWR_BASE + 0x2C)

/* --- PWR_CLKLSI1KCR values ----------------------------------------------- */

#define PWR_CLKLSI1KCR_CLKFRAC		0x7FF
#define PWR_CLKLSI1KCR_CALINT_SHIFT	11
#define PWR_CLKLSI1KCR_CLKFRAC		(0x1F << PWR_CLKLSI1KCR_CALINT_SHIFT) 

/* --- PWR_CLKLSI10KCR values ----------------------------------------------- */

#define PWR_CLKLSI10KCR_TUNE		0x0F

/* --- PWR_CLKSLEEPCR values ----------------------------------------------- */

#define PWR_CLKSLEEPCR_LSI10KEN		(1 << 1)
#define PWR_CLKSLEEPCR_LSEEN		(1 << 0)

/* --- PWR_RSTSR values ---------------------------------------------------- */

#define PWR_RSTSR_LKUP			(1 << 7)
#define PWR_RSTSR_OBFAIL		(1 << 6)
#define PWR_RSTSR_WKUP			(1 << 5)
#define PWR_RSTSR_SWRST			(1 << 4)
#define PWR_RSTSR_WDG			(1 << 3)
#define PWR_RSTSR_PIN			(1 << 2)
#define PWR_RSTSR_PWRLV			(1 << 1)
#define PWR_RSTSR_PWRHV			(1 << 0)


/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS


END_DECLS

#endif
