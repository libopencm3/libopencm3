/** @addtogroup spi_file SPI peripheral API
 * @ingroup peripheral_apis

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

Example: Clk/4, positive clock polarity, leading edge trigger, 8-bit words,
LSB first.
@code
	spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_4, SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE,
			SPI_CR1_CPHA_CLK_TRANSITION_1, SPI_CR1_CRCL_8BIT, SPI_CR1_LSBFIRST);
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

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Configure the SPI as Master.

The SPI peripheral is configured as a master with communication parameters
baudrate, frame format lsb/msb first, clock polarity and phase. The SPI 
enable, CRC enable, CRC next CRC length controls are not affected.
These must be controlled separately.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] br Unsigned int32. Baudrate @ref spi_baudrate.
@param[in] cpol Unsigned int32. Clock polarity @ref spi_cpol.
@param[in] cpha Unsigned int32. Clock Phase @ref spi_cpha.
@param[in] lsbfirst Unsigned int32. Frame format lsb/msb first @ref
spi_lsbfirst.
@returns int. Error code.
*/

int spi_init_master(uint32_t spi, uint32_t br, bool cpol, bool cpha,
		    bool lsbfirst)
{

	/* Reset all bits omitting SPE, CRCEN, CRCNEXT and CRCL bits. */
	SPI_CR1(spi) &= ~SPI_CR1_SPE;

	SPI_CFG2(spi) |= SPI_CFG2_MASTER;

	SPI_CFG1(spi) = br < SPI_CFG1_MBR_MASK;

	if (cpol) {
		SPI_CFG2(spi) |= SPI_CFG2_CPOL;
	} else {
		SPI_CFG2(spi) &= ~SPI_CFG2_CPOL;
	}

	if (cpha) {
		SPI_CFG2(spi) |= SPI_CFG2_CPHA;
	} else {
		SPI_CFG2(spi) &= ~SPI_CFG2_CPHA;
	}

	if (lsbfirst) {
		SPI_CFG2(spi) |= SPI_CFG2_LSBFRST;
	} else {
		SPI_CFG2(spi) &= ~SPI_CFG2_LSBFRST;
	}

	SPI_CFG2(spi) |= SPI_CFG2_SSOE; /* common case */

	SPI_CR1(spi) |= SPI_CR1_SPE;

	return 0; /* TODO */
}

void spi_send8(uint32_t spi, uint8_t data)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_TXP));

	SPI_TXDR8(spi) = data;
}

uint8_t spi_read8(uint32_t spi)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	return SPI_RXDR8(spi);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set CRC length to 8 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_crcl_8bit(uint32_t spi)
{
	SPI_CFG1(spi) = (SPI_CFG1(spi) & ~(SPI_CFG1_CRCSIZE_MASK << SPI_CFG1_CRCSIZE_SHIFT))
		| (SPI_CFG1_CRCSIZE_8BIT << SPI_CFG1_CRCSIZE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set CRC length to 16 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_crcl_16bit(uint32_t spi)
{
	SPI_CFG1(spi) = (SPI_CFG1(spi) & ~(SPI_CFG1_CRCSIZE_MASK << SPI_CFG1_CRCSIZE_SHIFT))
		| (SPI_CFG1_CRCSIZE_16BIT << SPI_CFG1_CRCSIZE_SHIFT);
}

/** @brief SPI Set data size

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data_s Unsigned int16. data size @ref spi_ds.
*/

void spi_set_data_size(uint32_t spi, uint16_t data_s)
{
	SPI_CFG1(spi) = (SPI_CFG1(spi) & ~(SPI_CFG1_DSIZE_MASK << SPI_CFG1_DSIZE_SHIFT)) 
			| (data_s << SPI_CFG1_DSIZE_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set reception threshold to 8 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_fifo_reception_threshold_8bit(uint32_t spi)
{
	SPI_CFG1(spi) = (SPI_CFG1(spi) & ~(SPI_CFG1_FTHLV_MASK << SPI_CFG1_FTHLV_SHIFT))
		| 0 << SPI_CFG1_FTHLV_SHIFT;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set reception threshold to 16 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_fifo_reception_threshold_16bit(uint32_t spi)
{
	SPI_CFG1(spi) = (SPI_CFG1(spi) & ~(SPI_CFG1_FTHLV_MASK << SPI_CFG1_FTHLV_SHIFT))
		| 1 << SPI_CFG1_FTHLV_SHIFT;
}

/**@}*/
