/** @defgroup dma_defines DMA Defines
 *
 * @brief <b>Defined Constants and Types for the GD32F1x0 DMA Controller</b>
 *
 * @ingroup GD32F1x0_defines
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
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

/* GD32F1x0 DMA is register-compatible with the STM32 L1/F0/F1/F3 DMA
 * controller (the dma_common_l1f013 family). GD numbers channels from 0
 * while libopencm3 numbers from 1; the underlying registers are at the
 * same offsets. Validated by regtrace v0.2 (decisions/v0.2/DMA.md).
 */
#include <libopencm3/stm32/common/dma_common_l1f013.h>

#endif
