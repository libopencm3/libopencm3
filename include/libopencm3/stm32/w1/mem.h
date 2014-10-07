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

#ifndef LIBOPENCM3_MEM_H
#define LIBOPENCM3_MEM_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- MEM registers ------------------------------------------------------- */

#define MEM_RAMPROTR(id)		MMIO32(MEM_BASE + 0x00 + (id)*4)
#define MEM_DMAPROTR1			MMIO32(MEM_BASE + 0x20)
#define MEM_DMAPROTR2			MMIO32(MEM_BASE + 0x24)
#define MEM_RAMCR			MMIO32(MEM_BASE + 0x28)

/* --- MEM_DMAPROTR1 values ---------------------------------------------------- */

#define MEM_DMAPROTR1_ADDRESS_SHIFT	1
#define MEM_DMAPROTR1_ADDRESS		(0xFFF << MEM_DMAPROTR1_ADDRESS_SHIFT) 
#define MEM_DMAPROTR1_OFFSET_SHIFT	13
#define MEM_DMAPROTR1_OFFSET		(0x7FFFF << MEM_DMAPROTR1_OFFSET_SHIFT) 

/* --- MEM_DMAPROTR2 values ---------------------------------------------------- */

#define MEM_DMAPROTR2_CHANNEL		7
#define MEM_DMAPROTR2_CHANNEL_SC1RX	1
#define MEM_DMAPROTR2_CHANNEL_ADC	3
#define MEM_DMAPROTR2_CHANNEL_SC2RX	5


/* --- MEM_RAMCR values ---------------------------------------------------- */

#define MEM_RAMCR_WEN			(1 << 2)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS


END_DECLS

#endif
