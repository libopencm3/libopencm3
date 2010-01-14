/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopenstm32.h>

/*
 * SPI and I2S code.
 *
 * Examples:
 *  spi_init_master(SPI1, 1000000, SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE,
 *                  SPI_CR1_CPHA_CLK_TRANSITION_1, SPI_CR1_DFF_8BIT,
 *                  SPI_CR1_LSBFIRST);
 *  spi_write(SPI1, 0x55);		// 8-bit write
 *  spi_write(SPI1, 0xaa88);		// 16-bit write
 *  reg8 = spi_read(SPI1);		// 8-bit read
 *  reg16 = spi_read(SPI1);		// 16-bit read
 */

int spi_init_master(u32 spi, u32 br, u32 cpol, u32 cpha, u32 dff, u32 lsbfirst)
{
	u32 reg32 = 0;

	reg32 |= SPI_CR1_MSTR;	/* Configure SPI as master. */

	reg32 |= br;		/* Set BAUD rate bits. */
	reg32 |= cpol;		/* Set CPOL value. */
	reg32 |= cpha;		/* Set CPHA value. */
	reg32 |= dff;		/* Set data format (8 or 16 bits). */
	reg32 |= lsbfirst;	/* Set frame format (LSB- or MSB-first). */

	/* TODO: NSS pin handling. */

	SPI_CR1(spi) = reg32;

	return 0; /* TODO */
}

/* TODO: Error handling? */
void spi_enable(u32 spi)
{
	u32 reg32;

	reg32 = SPI_CR1(spi);
	reg32 |= SPI_CR1_SPE;		/* Enable SPI. */
	SPI_CR1(spi) = reg32;
}

/* TODO: Error handling? */
void spi_disable(u32 spi)
{
	u32 reg32;

	/* TODO: Follow procedure from section 23.3.8 in the techref manual. */
	reg32 = SPI_CR1(spi);
	reg32 &= ~(SPI_CR1_SPE);	/* Disable SPI. */
	SPI_CR1(spi) = reg32;
}

void spi_write(u32 spi, u16 data)
{
	/* Write data (8 or 16 bits, depending on DFF) into DR. */
	SPI_DR(spi) = data;
}

u16 spi_read(u32 spi)
{
	/* Read the data (8 or 16 bits, depending on DFF bit) from DR. */
	return SPI_DR(spi);
}
