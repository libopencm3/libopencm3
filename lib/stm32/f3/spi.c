/** @defgroup spi_file SPI
 *
 * @ingroup STM32F3xx
 *
 * @brief <b>libopencm3 STM32F3xx Serial Peripheral Interface</b>
 *
 * @version 1.0.0
 *
 * @date 11 July 2013
 *
 * LGPL License Terms @ref lgpl_license
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
#include <libopencm3/stm32/rcc.h>

void spi_send8(uint32_t spi, uint8_t data)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_TXE));

	/* Write data (8 or 16 bits, depending on DFF) into DR. */
	SPI_DR8(spi) = data;
}

uint8_t spi_read8(uint32_t spi)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXNE));

	/* Read the data (8 or 16 bits, depending on DFF bit) from DR. */
	return SPI_DR8(spi);
}

void spi_set_data_size(uint32_t spi, uint16_t data_s)
{
	SPI_CR2(spi) = (SPI_CR2(spi) & ~SPI_CR2_DS_MASK) |
		       (data_s & SPI_CR2_DS_MASK);
}

void spi_fifo_reception_threshold_8bit(uint32_t spi)
{
	SPI_CR2(spi) |= SPI_CR2_FRXTH;
}

void spi_fifo_reception_threshold_16bit(uint32_t spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_FRXTH;
}

void spi_i2s_mode_spi_mode(uint32_t spi)
{
	SPI_I2SCFGR(spi) &= ~SPI_I2SCFGR_I2SMOD;
}
