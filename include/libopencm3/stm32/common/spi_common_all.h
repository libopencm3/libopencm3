/** @addtogroup spi_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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
#if defined(LIBOPENCM3_SPI_H)
/** @endcond */
#ifndef LIBOPENCM3_SPI_COMMON_ALL_H
#define LIBOPENCM3_SPI_COMMON_ALL_H

/**@{*/

/* Registers can be accessed as 16bit or 32bit values. */

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup spi_reg_base SPI Register base address
@ingroup spi_defines

@{*/
#define SPI1				SPI1_BASE
#define SPI2				SPI2_BASE
#define SPI3				SPI3_BASE
#define SPI4				SPI4_BASE
#define SPI5				SPI5_BASE
#define SPI6				SPI6_BASE
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void spi_reset(uint32_t spi_peripheral);

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "spi_common_all.h should not be included explicitly, only via spi.h"
#endif
/** @endcond */

