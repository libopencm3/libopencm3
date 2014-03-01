/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Felix Held <felix-libopencm3@felixheld.de>
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

#ifndef LIBOPENCM3_PIO_H
#define LIBOPENCM3_PIO_H

#include <libopencm3/sam/memorymap.h>
#include <libopencm3/sam/common/pio_common_3n3s.h>

/* --- PIO registers ----------------------------------------------------- */

/* Parallel Capture Mode Register */
#define PIO_PCMR(port)			MMIO32((port) + 0x0150)

/* Parallel Capture Interrupt Enable Register */
#define PIO_PCIER(port)			MMIO32((port) + 0x0154)

/* Parallel Capture Interrupt Disable Register */
#define PIO_PCIDR(port)			MMIO32((port) + 0x0158)

/* Parallel Capture Interrupt Mask Register */
#define PIO_PCIMR(port)			MMIO32((port) + 0x015C)

/* Parallel Capture Interrupt Status Register */
#define PIO_PCISR(port)			MMIO32((port) + 0x0160)

/* Parallel Capture Reception Holding Register */
#define PIO_PCRHR(port)			MMIO32((port) + 0x0164)


#endif
