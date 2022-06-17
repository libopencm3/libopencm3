/** @addtogroup spi_defines
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA SPI.H
The order of header inclusion is important. spi.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_SPI_H
/** @endcond */
#pragma once

/**@{*/

#include <libopencm3/gd32/common/spi_common_all.h>

#define SPI_DR8(spi_base)	MMIO8((spi_base) + 0x0c)
#define SPI0_DR8		SPI_DR8(SPI0_BASE)
#define SPI1_DR8		SPI_DR8(SPI1_BASE)
#define SPI2_DR8		SPI_DR8(SPI2_BASE)

/* CRCL: CRC Length */
/****************************************************************************/
/** @defgroup spi_crcl SPI crc length
 * @ingroup spi_defines
 *
 * @{*/

#define SPI_CTL0_FF16_8BIT	(0 << 11)
#define SPI_CTL0_FF16_16BIT	(1 << 11)
/**@}*/
#define SPI_CTL0_FF16		(1 << 11)
/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS
int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha, 
		uint32_t lsbfirst);
void spi_set_crcl_8bit(uint32_t spi);
void spi_set_crcl_16bit(uint32_t spi);
void spi_set_data_size(uint32_t spi, uint16_t data_s);
void spi_i2s_mode_spi_mode(uint32_t spi);
void spi_send8(uint32_t spi, uint8_t data);
uint8_t spi_read8(uint32_t spi);

END_DECLS

/** @cond */
#else
#warning "spi_common_v2.h should not be included explicitly, only via spi.h"
#endif
/** @endcond */
/**@}*/

