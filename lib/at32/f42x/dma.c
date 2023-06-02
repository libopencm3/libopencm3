/** @defgroup dma_file DMA peripheral API
@ingroup peripheral_apis
@brief DMA library for the controller found in AT32F42X parts.

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
#include <libopencm3/stm32/syscfg.h>

/*---------------------------------------------------------------------------*/
/** @brief Set DMA request mapping.

Although AT32F421 DMA controller has only fixed DMA request mapping,
some requests can be redirected on alternate DMA channels via SYSCFG.

@param[in] map DMA request map
*/

void dma_set_request_map(enum dma_request_map map)
{
	SYSCFG_CFGR1 = (SYSCFG_CFGR1 & ~SYSCFG_CFGR1_DMA_MAP_MASK) |
		(map << SYSCFG_CFGR1_DMA_MAP_SHIFT);
}

/**@}*/
