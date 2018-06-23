/** @addtogroup spi_file SPI peripheral API
 * @ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2009
Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>
@author @htmlonly &copy; @endhtmlonly 2018
Guillaume Revaillot <revaillot@archos.com>

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

#include <libopencm3/stm32/spi.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Frame Format to TI

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_frf_ti(uint32_t spi)
{
	SPI_CR2(spi) |= SPI_CR2_FRF;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Frame Format to Motorola

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_frf_motorola(uint32_t spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_FRF;
}

#define SPI_CR2_FRF			(1 << 4)
#define SPI_CR2_FRF_MOTOROLA_MODE	(0 << 4)
#define SPI_CR2_FRF_TI_MODE		(1 << 4)

/* --- SPI_SR values ------------------------------------------------------- */

/* FRE / TIFRFE: TI frame format error */
#define SPI_SR_TIFRFE			(1 << 8) //F2
#define SPI_SR_FRE			(1 << 8) //others

/**@}*/
