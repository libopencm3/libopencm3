/** @addtogroup spi_defines

@author @htmlonly &copy; @endhtmlonly 2011 Fergus Noble <fergusnoble@gmail.com>

*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA SPI.H
The order of header inclusion is important. spi.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_SPI_H
/** @endcond */
#pragma once

/**@{*/

#include <libopencm3/stm32/common/spi_common_all.h>

/* DFF: Data frame format */
/****************************************************************************/
/** @defgroup spi_dff SPI data frame format
@ingroup spi_defines

@{*/

#define SPI_CR1_DFF_8BIT			(0 << 11)
#define SPI_CR1_DFF_16BIT			(1 << 11)

/**@}*/

#define SPI_CR1_DFF					(1 << 11)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha,
		uint32_t dff, uint32_t lsbfirst);
void spi_set_dff_8bit(uint32_t spi);
void spi_set_dff_16bit(uint32_t spi);

END_DECLS

/** @cond */
#else
#warning "spi_common_v1.h should not be included explicitly, only via spi.h"
#endif
/** @endcond */
/**@}*/

