/** @addtogroup spi_file SPI peripheral API
 * @ingroup peripheral_apis
 *
 * @author @htmlonly &copy; @endhtmlonly 2025
 * Rachel Mant <git@dragonmux.network>
 *
 * Devices can have up to three SPI peripherals. The common 4-wire full-duplex
 * mode of operation is supported, along with 3-wire variants using unidirectional
 * communication modes or half-duplex bidirectional communication. A variety of
 * options allows many of the SPI variants to be supported. Multimaster operation
 * is also supported. A CRC can be generated and checked in hardware.
 *
 * Example: Clk/4, positive clock polarity, leading edge trigger, 8-bit words,
 * LSB first.
 * @code
 * 	spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_4, SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE,
 * 			SPI_CR1_CPHA_CLK_TRANSITION_1, SPI_CR1_DFF_8BIT, SPI_CR1_LSBFIRST);
 * 	spi_write(SPI1, 0x55);		// 8-bit write
 * 	spi_write(SPI1, 0xaa88);	// 16-bit write
 * 	reg8 = spi_read(SPI1);		// 8-bit read
 * 	reg16 = spi_read(SPI1);		// 16-bit read
 * @endcode
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2025 Rachel Mant <git@dragonmux.network>
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

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable.
 *
 * The SPI peripheral is enabled.
 *
 * @param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
 */

void spi_enable(const uintptr_t spi)
{
	SPI_CR1(spi) |= SPI_CR1_SPE; /* Enable SPI. */
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable.
 *
 * The SPI peripheral is disabled.
 *
 * @param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
 */

void spi_disable(const uintptr_t spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_SPE; /* Disable SPI. */
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write.

Data is written to the SPI interface.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 8, 16 or 32-bit data to be written.
*/

void spi_write(const uintptr_t spi, const uint32_t data)
{
	/* Write data (8, 16 or 32-bits, depending on DFF) into TXDR. */
	SPI_TXDR(spi) = data;
	SPI_CR1(spi) |= SPI_CR1_CSTART;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write with Blocking.

Data is written to the SPI interface after the previous write transfer has
finished.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 8, 16 or 32-bit data to be written.
*/

void spi_send(const uintptr_t spi, const uint32_t data)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_TXC))
		continue;

	/* Write the requested data out, starting the transfer */
	spi_write(spi, data);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Read.

Data is read from the SPI interface after the incoming transfer has finished.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int32. 8, 16 or 32-bit data.
*/

uint32_t spi_read(const uintptr_t spi)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXP))
		continue;

	/* Read the data (8, 16 or 32-bits, depending on DFF bit) from RXDR. */
	return SPI_RXDR(spi);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write and Read Exchange.

Data is written to the SPI interface, then a read is done after the incoming
transfer has finished.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 8, 16 or 32-bit data to be written.
@returns data Unsigned int32. 8, 16 or 32-bit data.
*/

uint32_t spi_xfer(const uintptr_t spi, const uint32_t data)
{
	spi_write(spi, data);
	return spi_read(spi);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI 8-bit Data Write.

Data is written to the SPI interface.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int8. 8-bit data to be written.
*/

void spi_write8(const uintptr_t spi, const uint8_t data)
{
	/* Write data (8-bits) into TXDR. */
	SPI_TXDR(spi) = data;
	SPI_CR1(spi) |= SPI_CR1_CSTART;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI 8-bit Data Read.

Data is read from the SPI interface after the incoming transfer has finished.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int8. 8-bit data.
*/

uint8_t spi_read8(const uintptr_t spi)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXP))
		continue;

	/* Read the data (8-bits) from RXDR. */
	return SPI_RXDR(spi);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI 8-bit Data Write and Read Exchange.

Data is written to the SPI interface, then a read is done after the incoming
transfer has finished.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int8. 8-bit data to be written.
@returns data Unsigned int8. 8-bit data.
*/

uint8_t spi_xfer8(const uintptr_t spi, const uint8_t data)
{
	spi_write8(spi, data);
	return spi_read8(spi);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI 16-bit Data Write.

Data is written to the SPI interface.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int16. 16-bit data to be written.
*/

void spi_write16(const uintptr_t spi, const uint16_t data)
{
	/* Write data (16-bits) into TXDR. */
	SPI_TXDR(spi) = data;
	SPI_CR1(spi) |= SPI_CR1_CSTART;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI 16-bit Data Read.

Data is read from the SPI interface after the incoming transfer has finished.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int16. 16-bit data.
*/

uint16_t spi_read16(const uintptr_t spi)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXP))
		continue;

	/* Read the data (16-bits) from RXDR. */
	return SPI_RXDR(spi);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable the CRC.

The SPI peripheral is set to use a CRC field for transmit and receive.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_crc(const uintptr_t spi)
{
	SPI_CFG1(spi) |= SPI_CFG1_CRCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable the CRC.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_crc(const uintptr_t spi)
{
	SPI_CFG1(spi) &= ~SPI_CFG1_CRCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable Slave Management by Hardware

In slave mode the NSS hardware input is used as a select enable for the slave.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_software_slave_management(const uintptr_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_SSM;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable Slave Management by Software

In slave mode the NSS hardware input is replaced by an internal software
enable/disable of the slave (@ref spi_set_nss_high).

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_software_slave_management(const uintptr_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_SSM;
	/* allow slave select to be an input */
	SPI_CFG2(spi) &= ~SPI_CFG2_SSOE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Software NSS Signal High

In slave mode, and only when software slave management is used, this replaces
the NSS signal with a slave select enable signal.

@todo these should perhaps be combined with an SSM enable as it is meaningless
otherwise

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_nss_high(const uintptr_t spi)
{
	SPI_CR1(spi) |= SPI_CR1_SSI;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Software NSS Signal Low

In slave mode, and only when software slave management is used, this replaces
the NSS signal with a slave select disable signal.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_nss_low(const uintptr_t spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_SSI;
}

void spi_set_nss_active_high(const uintptr_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_SSIOP;
}

void spi_set_nss_active_low(const uintptr_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_SSIOP;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set to Send LSB First

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_send_lsb_first(const uintptr_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_LSBFIRST;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set to Send MSB First

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_send_msb_first(const uintptr_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_LSBFIRST;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set to Master Mode

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_master_mode(const uintptr_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_MASTER;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set to Slave Mode

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_slave_mode(const uintptr_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_MASTER;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Polarity to High when Idle

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@sa spi_set_clock_polarity_0
*/

void spi_set_clock_polarity_1(const uintptr_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_CPOL;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Polarity to Low when Idle

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@sa spi_set_clock_polarity_1
*/

void spi_set_clock_polarity_0(const uintptr_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_CPOL;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Phase to Capture on Trailing Edge

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@sa spi_set_clock_phase_0
*/

void spi_set_clock_phase_1(const uintptr_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_CPHA;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Phase to Capture on Leading Edge

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@sa spi_set_clock_phase_1
*/

void spi_set_clock_phase_0(const uintptr_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_CPHA;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable Transmit Transfers via DMA

This allows transmissions to proceed unattended using DMA to move data to the
transmit buffer as it becomes available. The DMA channels provided for each
SPI peripheral are given in the Technical Manual DMA section.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_tx_dma(const uintptr_t spi)
{
	SPI_CFG1(spi) |= SPI_CFG1_TXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable Transmit Transfers via DMA

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_tx_dma(const uintptr_t spi)
{
	SPI_CFG1(spi) &= ~SPI_CFG1_TXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable Receive Transfers via DMA

This allows received data streams to proceed unattended using DMA to move data
from the receive buffer as data becomes available. The DMA channels provided
for each SPI peripheral are given in the Technical Manual DMA section.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_rx_dma(const uintptr_t spi)
{
	SPI_CFG1(spi) |= SPI_CFG1_RXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable Receive Transfers via DMA

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_rx_dma(const uintptr_t spi)
{
	SPI_CFG1(spi) &= ~SPI_CFG1_RXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Standard Mode selection
@details Set SPI standard Modes
Mode | CPOL | CPHA
---- | ---- | ----
 0   |  0   |  0
 1   |  0   |  1
 2   |  1   |  0
 3   |  1   |  1
@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] mode Unsigned int8. Standard SPI mode (0, 1, 2, 3)
@sa spi_set_clock_phase_0 spi_set_clock_phase_1
@sa spi_set_clock_polarity_0 spi_set_clock_polarity_1
*/

void spi_set_standard_mode(const uintptr_t spi, const uint8_t mode)
{
	if (mode > 3U) {
		return;
	}

	uint32_t reg32 = SPI_CFG2(spi) & ~(SPI_CFG2_CPOL | SPI_CFG2_CPHA);
	SPI_CFG2(spi) = reg32 | (mode << SPI_CFG2_CPOL_CPHA_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief Configure the SPI as Master.

The SPI peripheral is configured as a master with communication parameters
baudrate, frame format lsb/msb first, clock polarity and phase. The SPI
enable, CRC enable, CRC next CRC length controls are not affected.
These must be controlled separately.

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] baud_rate Unsigned int32. Baudrate @ref spi_baudrate.
@param[in] cpol Unsigned int32. Clock polarity @ref spi_cpol.
@param[in] cpha Unsigned int32. Clock Phase @ref spi_cpha.
@param[in] data_size Unsigned int32. Data size (in bits) @ref spi_dsize.
@param[in] lsbfirst Unsigned int32. Frame format lsb/msb first @ref spi_lsbfirst.
@param[in] protocol Unsigned int32. SPI protocol to use @ref spi_sp.
@returns bool. Success if true.
*/

bool spi_init_master(const uintptr_t spi, const uint32_t baud_rate, const uint32_t cpol, const uint32_t cpha,
	const uint32_t data_size, const uint32_t lsbfirst, const uint32_t protocol)
{
	/* Start by ensuring that the peripheral is not currently enabled as this prevents reconfig */
	if (SPI_CR1(spi) & SPI_CR1_SPE)
		return false;

	/* Clear any pending interrupt flags */
	SPI_IFCR(spi) = UINT32_MAX;

	/* Configure the data size for transfers to run in */
	SPI_CFG1(spi) = (SPI_CFG1(spi) & ~SPI_CFG1_DSIZE_MASK) | data_size;
	/* Set baud rate bits. */
	SPI_CFG1(spi) = (SPI_CFG1(spi) & ~SPI_CFG1_MBR_MASK) | baud_rate;

	/*
	 * Configure the mode, CPOL, CPHA, frame format (LSB- or MSB-first), and protocol bits.
	 * This puts the peripheral into SPI controller mode. Default to multi-controller mode.
	 */
	SPI_CFG2(spi) = (SPI_CFG2(spi) & ~(SPI_CFG2_CPOL | SPI_CFG2_CPHA | SPI_CFG2_LSBFIRST | SPI_CFG2_SP_MASK)) |
		SPI_CFG2_MASTER | cpol | cpha | lsbfirst | protocol | SPI_CFG2_AFCNTR | SPI_CFG2_SSM | SPI_CFG2_SSIOP;

	/* Configure the transfer size in blocks to 0 for now */
	SPI_CR2(spi) &= ~SPI_CR1_TSIZE_MASK;

	return true;
}

/** @brief SPI Set data size

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] data_size Unsigned int8. data size @ref spi_dsize.
*/

void spi_set_data_size(const uintptr_t spi, const uint8_t data_size)
{
	SPI_CFG1(spi) = (SPI_CFG1(spi) & ~SPI_CFG1_DSIZE_MASK) | (data_size & SPI_CFG1_DSIZE_MASK);
}

/** @brief SPI Set data size

@param[in] spi Unsigned intptr. SPI peripheral identifier @ref spi_reg_base.
@param[in] transfer_size Unsigned int16. transfer size in data_size bit blocks @ref spi_tsize.
*/

void spi_set_transfer_size(const uintptr_t spi, const uint16_t transfer_size)
{
	SPI_CR2(spi) = (SPI_CR2(spi) & ~SPI_CR1_TSIZE_MASK) | transfer_size;
}
