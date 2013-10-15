/** @defgroup spi_defines SPI Defines
 *
 * @brief <b>Defined Constants and Types for the STM32F3xx SPI</b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 5 December 2012
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

#ifndef LIBOPENCM3_SPI_H
#define LIBOPENCM3_SPI_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/common/spi_common_f03.h>

#define SPI_DR8(spi_base)	MMIO8(spi_base + 0x0c)
#define SPI1_DR8		SPI_DR8(SPI1_BASE)
#define SPI2_DR8		SPI_DR8(SPI2_I2S_BASE)
#define SPI3_DR8		SPI_DR8(SPI3_I2S_BASE)

#endif
