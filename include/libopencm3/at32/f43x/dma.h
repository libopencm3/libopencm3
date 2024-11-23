/** @defgroup dma_defines DMA Defines

@ingroup AT32F43x_defines

@brief Defined Constants and Types for the AT32F43x DMA Controller

@version 1.0.0

@date 16 November 2024

LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_DMA_H
#define LIBOPENCM3_DMA_H

/* AT32F43x RM mentions only common DMA1/DMA2 base,
   actual offsets were taken from firmware library */
#define DMA1_BASE			(DMA12_BASE + 0x0)
#define DMA2_BASE			(DMA12_BASE + 0x200)

#include <libopencm3/stm32/common/dma_common_l1f013.h>

/* --- DMA registers (continued) ------------------------------------------- */
#define DMA_MUXSELR(dma_base)	MMIO32((dma_base) + 0x100)	/* DMA_MUXSEL */

/* --- DMA_MUXSELR values -------------------------------------------------- */
#define DMA_MUXSELR_EN			(1 << 0)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dma_enable_dmamux(uint32_t dma);
void dma_disable_dmamux(uint32_t dma);

END_DECLS

#endif
