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

#include <libopencm3/stm32/common/spi_common_v1.h>

/* --- SPI_CR2 values ------------------------------------------------------ */

/* FRF: Frame format */
/* Note: Not used in I2S mode. */
#define SPI_CR2_FRF				(1 << 4)
#define SPI_CR2_FRF_MOTOROLA_MODE	(0 << 4)
#define SPI_CR2_FRF_TI_MODE		(1 << 4)

/* --- SPI_SR values ------------------------------------------------------- */

/* FRE / TIFRFE: TI frame format error */
#define SPI_SR_TIFRFE			(1 << 8) //F2
#define SPI_SR_FRE				(1 << 8) //others

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void spi_set_frf_ti(uint32_t spi);
void spi_set_frf_motorola(uint32_t spi);

END_DECLS

/** @cond */
#else
#warning "spi_common_v1_frf.h should not be included explicitly, only via spi.h"
#endif
/** @endcond */
/**@}*/

