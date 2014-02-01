/** @addtogroup spi_file

@author @htmlonly &copy; @endhtmlonly 2009
Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

Devices can have up to three SPI peripherals. The common 4-wire full-duplex
mode of operation is supported, along with 3-wire variants using unidirectional
communication modes or half-duplex bidirectional communication. A variety of
options allows many of the SPI variants to be supported. Multimaster operation
is also supported. A CRC can be generated and checked in hardware.

@note Some JTAG pins need to be remapped if SPI is to be used.

@note The I2S protocol shares the SPI hardware so the two protocols cannot be
used at the same time on the same peripheral.

Example: 1Mbps, positive clock polarity, leading edge trigger, 8-bit words,
LSB first.
@code
	spi_init_master(SPI1, 1000000, SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE,
			SPI_CR1_CPHA_CLK_TRANSITION_1, SPI_CR1_CRCL_8BIT,
			SPI_CR1_LSBFIRST);
	spi_write(SPI1, 0x55);		// 8-bit write
	spi_write(SPI1, 0xaa88);	// 16-bit write
	reg8 = spi_read(SPI1);		// 8-bit read
	reg16 = spi_read(SPI1);		// 16-bit read
@endcode

@todo need additional functions to aid ISRs in retrieving status

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

/*
 * SPI and I2S code.
 *
 * Examples:
 *  spi_init_master(SPI1, 1000000, SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE,
 *                  SPI_CR1_CPHA_CLK_TRANSITION_1, SPI_CR1_CRCL_8BIT,
 *                  SPI_CR1_LSBFIRST);
 *  spi_write(SPI1, 0x55);		// 8-bit write
 *  spi_write(SPI1, 0xaa88);		// 16-bit write
 *  reg8 = spi_read(SPI1);		// 8-bit read
 *  reg16 = spi_read(SPI1);		// 16-bit read
 */

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Configure the SPI as Master.

The SPI peripheral is configured as a master with communication parameters
baudrate, crc length 8/16 bits, frame format lsb/msb first, clock polarity
and phase. The SPI enable, CRC enable and CRC next controls are not affected.
These must be controlled separately.

@todo NSS pin handling.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] br Unsigned int32. Baudrate @ref spi_baudrate.
@param[in] cpol Unsigned int32. Clock polarity @ref spi_cpol.
@param[in] cpha Unsigned int32. Clock Phase @ref spi_cpha.
@param[in] crcl Unsigned int32. CRC length 8/16 bits @ref spi_crcl.
@param[in] lsbfirst Unsigned int32. Frame format lsb/msb first @ref
spi_lsbfirst.
@returns int. Error code.
*/

int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha,
		    uint32_t crcl, uint32_t lsbfirst)
{
	uint32_t reg32 = SPI_CR1(spi);

	/* Reset all bits omitting SPE, CRCEN and CRCNEXT bits. */
	reg32 &= SPI_CR1_SPE | SPI_CR1_CRCEN | SPI_CR1_CRCNEXT;

	reg32 |= SPI_CR1_MSTR;	/* Configure SPI as master. */

	reg32 |= br;		/* Set baud rate bits. */
	reg32 |= cpol;		/* Set CPOL value. */
	reg32 |= cpha;		/* Set CPHA value. */
	reg32 |= crcl;		/* Set crc length (8 or 16 bits). */
	reg32 |= lsbfirst;	/* Set frame format (LSB- or MSB-first). */

	/* TODO: NSS pin handling. */

	SPI_CR1(spi) = reg32;

	return 0; /* TODO */
}

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

/*---------------------------------------------------------------------------*/
/** @brief SPI Set CRC length to 8 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_crcl_8bit(uint32_t spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_CRCL;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set CRC length to 16 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_crcl_16bit(uint32_t spi)
{
	SPI_CR1(spi) |= SPI_CR1_CRCL;
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


/**@}*/
