/*
 * This file is part of the libopencm3 project.
 *
 * COpyright (C) 2014 Felix Held <felix-libopencm3@felixheld.de>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA PIO.H
The order of header inclusion is important. pio.h includes the device
specific memorymap.h header before including this header file.*/

#if defined(LIBOPENCM3_PIO_H)

#ifndef LIBOPENCM3_PIO_COMMON_3N3S_H
#define LIBOPENCM3_PIO_COMMON_3N3S_H

#include <libopencm3/sam/common/pio_common_all.h>

/* --- PIO registers ----------------------------------------------------- */

/* Peripheral Select Register 1 */
#define PIO_ABCDSR1(port)		MMIO32((port) + 0x0070)

/* Peripheral Select Register 2 */
#define PIO_ABCDSR2(port)		MMIO32((port) + 0x0074)

/* Input Filter Slow Clock Disable Register */
#define PIO_IFSCDR(port)		MMIO32((port) + 0x0080)

/* Input Filter Slow Clock Enable Register */
#define PIO_IFSCER(port)		MMIO32((port) + 0x0084)

/* Input Filter Slow Clock Status Register */
#define PIO_IFSCSR(port)		MMIO32((port) + 0x0088)

/* Pad Pull-down Disable Register */
#define PIO_PPDDR(port)			MMIO32((port) + 0x0090)

/* Pad Pull-down Enable Register */
#define PIO_PPDER(port)			MMIO32((port) + 0x0094)

/* Pad Pull-down Status Register */
#define PIO_PPDSR(port)			MMIO32((port) + 0x0098)

/* Schmitt Trigger Register */
#define PIO_SCHMITT(port)		MMIO32((port) + 0x0100)


#endif

#else
#warning "pio_common_3n3s.h should not be included explicitly, only via pio.h"
#endif
