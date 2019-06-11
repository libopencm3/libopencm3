/** @addtogroup dma_file DMA peripheral API
@ingroup peripheral_apis

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Guillaume Revaillot <g.revaillot@gmail.com>
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

/**@{*/

#include <libopencm3/stm32/dma.h>

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Set Request Selection

Set DMA request mapping selection for given channel. Refer to datasheet for channel
request mapping tables.

@param[in] dma DMA controller base address: DMA1 or DMA2
@param[in] channel Channel number:  1-7 for DMA1 or 1-5 for DMA2
@param[in] request DMA request mapping.
*/

void dma_set_channel_request(uint32_t dma, uint8_t channel, uint8_t request)
{
	uint32_t reg32 = DMA_CSELR(dma) & ~(DMA_CSELR_CxS_MASK << DMA_CSELR_CxS_SHIFT(channel));
	DMA_CSELR(dma) = reg32 | ((DMA_CSELR_CxS_MASK & request) << DMA_CSELR_CxS_SHIFT(channel));
}

/**@}*/
