/** @defgroup dma_file DMA peripheral API
@ingroup peripheral_apis
@brief DMA library for the controller found in AT32F43X parts.

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

/**@{*/

#include <libopencm3/stm32/dma.h>
#include <libopencm3/stm32/memorymap.h>

/*---------------------------------------------------------------------------*/
/** @brief Enable DMAMUX for given DMA controller

@param[in] dma DMA controller base address: DMA1 or DMA2
*/

void dma_enable_dmamux(uint32_t dma)
{
	DMA_MUXSELR(dma) |= DMA_MUXSELR_EN;
}

/*---------------------------------------------------------------------------*/
/** @brief Disable DMAMUX for given DMA controller

@param[in] dma DMA controller base address: DMA1 or DMA2
*/

void dma_disable_dmamux(uint32_t dma)
{
	DMA_MUXSELR(dma) &= ~DMA_MUXSELR_EN;
}

/**@}*/
