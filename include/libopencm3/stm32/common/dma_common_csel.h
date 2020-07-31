/** @addtogroup dma_defines
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA DMA.H
The order of header inclusion is important. dma.h includes the device
specific memorymap.h header before including this header file.*/

/**@{*/

/** @cond */
#ifdef LIBOPENCM3_DMA_H
/** @endcond */
#pragma once


/* DMA channel selection register (DMAx_CSELR) */
#define DMA_CSELR(dma_base)		MMIO32((dma_base) + 0xA8)
#define DMA1_CSELR			DMA_CSELR(DMA1)
#define DMA2_CSELR			DMA_CSELR(DMA2)

/* --- DMA_CSELR values -------------------------------------------- */

#define DMA_CSELR_CxS_SHIFT(channel)	(4 * ((channel) - 1))
#define DMA_CSELR_CxS_MASK				(0x0f)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dma_set_channel_request(uint32_t dma, uint8_t channel, uint8_t request);

END_DECLS

/** @cond */
#else
#warning "dma_common_csel.h should not be included explicitly, only via dma.h"
#endif
/** @endcond */

/**@}*/
