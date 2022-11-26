/** @addtogroup dma_file
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2022 Sergey Bolshakov <beefdeadbeef@gmail.com>
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
/** @brief Enable Flexible DMA Request Mapping Mode

When enabled, DMA request source for each channel can
be programmed.
Note that both DMA controllers must be in same mode,
flexible or fixed.

@param[in] dma DMA controller base address: DMA1 or DMA2
*/

void dma_enable_flex_mode(uint32_t dma)
{
	DMA_CSELR1(dma) |= DMA_CSEL_FLEX_MODE;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable Flexible DMA Request Mapping Mode

Restores fixed mapping of each DMA request source (default).
Note that both DMA controllers must be in same mode,
flexible or fixed.

@param[in] dma DMA controller base address: DMA1 or DMA2
*/

void dma_disable_flex_mode(uint32_t dma)
{
	DMA_CSELR1(dma) &= ~DMA_CSEL_FLEX_MODE;
}

/*---------------------------------------------------------------------------*/
/** @brief DMA Channel Set Request Selection

Set DMA request mapping selection for given channel. Refer to datasheet
for channel request mapping tables.

@param[in] dma DMA controller base address: DMA1 or DMA2
@param[in] channel Channel number:  1-7 for both DMA1 and DMA2
@param[in] request DMA request mapping.
*/

void dma_set_channel_request(uint32_t dma, uint8_t channel,
			     enum dma_request_id request)
{
	uint32_t shift = DMA_CSELR_CxS_SHIFT(channel);
	uint32_t mask = DMA_CSELR_CxS_MASK << shift;
	uint32_t val = request << shift;

	switch(channel) {

	case DMA_CHANNEL1:
	case DMA_CHANNEL2:
	case DMA_CHANNEL3:
	case DMA_CHANNEL4:
		DMA_CSELR0(dma) = (DMA_CSELR0(dma) & mask) | val;
		break;

	case DMA_CHANNEL5:
	case DMA_CHANNEL6:
	case DMA_CHANNEL7:
		DMA_CSELR1(dma) = (DMA_CSELR1(dma) & mask) | val;
		break;
	}
}

/**@}*/
