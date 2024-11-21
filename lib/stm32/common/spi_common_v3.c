/** @addtogroup spi_file SPI peripheral API
 * @ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2009
Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>
@author @htmlonly &copy; @endhtmlonly 2021
Eduard Drusa <ventyl86 at netkosice dot sk>
@author @htmlonly &copy; @endhtmlonly 2023
Sebastien Lorquet <sebastien at lorquet dot fr>

Devices can have up to six SPI peripherals. The common 4-wire full-duplex
mode of operation is supported, along with 3-wire variants using unidirectional
communication modes or half-duplex bidirectional communication. A variety of
options allows many of the SPI variants to be supported. Multimaster operation
is also supported. A CRC can be generated and checked in hardware.

@note The I2S protocol shares the SPI hardware so the two protocols cannot be
used at the same time on the same peripheral.

Example: Clk/4, positive clock polarity, leading edge trigger, 8-bit words,
LSB first.
@code
	spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_4, SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE,
			SPI_CR1_CPHA_CLK_TRANSITION_1, SPI_CR1_DFF_8BIT, SPI_CR1_LSBFIRST);
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
 * Copyright (C) 2023 Sebastien Lorquet <sebastien@lorquet.fr>
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

/* TODO: Error handling? */
/*---------------------------------------------------------------------------*/
/** @brief SPI Enable.

The SPI peripheral is enabled. This code is similar to spi_common_all, but
the register definitions are different.

@todo Error handling?

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable(uint32_t spi)
{
	SPI_CR1(spi) |= SPI_CR1_SPE; /* Enable SPI. */
}

/* TODO: Error handling? */
/*---------------------------------------------------------------------------*/
/** @brief SPI Disable.

The SPI peripheral is disabled. This code is similar to spi_common_all, but
the register definitions are different.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable(uint32_t spi)
{
	SPI_CR1(spi) &= ~(SPI_CR1_SPE); /* Disable SPI. */
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Clean Disable.

Disable the SPI peripheral according to the procedure in section 23.3.8 of the
reference manual.  This prevents corruption of any ongoing transfers and
prevents the BSY flag from becoming unreliable.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int16. 8 or 16 bit data from final read.
*/

void spi_clean_disable(uint32_t spi)
{
	/* Suspend SPI */
	SPI_CR1(spi) |= SPI_CR1_CSUSP;
	while(!(SPI_SR(spi) & SPI_SR_SUSP));

	SPI_CR1(spi) &= ~SPI_CR1_SPE; /* Disable SPI. */
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write.

Data is written to the SPI interface.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int16. 8 or 16 bit data to be written.
*/

void spi_write(uint32_t spi, uint16_t data)
{
	/* Write data (8 or 16 bits, depending on DFF) into DR. */
	SPI_TXDR(spi) = data;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write (32-bit) with Blocking.

Data is written to the SPI interface after the previous write transfer has
finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 32 bit data to be written.
*/

void spi_send(uint32_t spi, uint32_t data)
{
	/* Start a transaction */
	SPI_CR1(spi) |= SPI_CR1_CSTART;

	/* Wait for room to write in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_TXP));

	/* Write data (depending on data size) into transmit fifo. */
	SPI_TXDR(spi) = data;

}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write (16-bit) with Blocking.

Data is written to the SPI interface after the previous write transfer has
finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int16. 16 bit data to be written.
*/

void spi_send16(uint32_t spi, uint16_t data)
{
	/* Start a transaction */
	SPI_CR1(spi) |= SPI_CR1_CSTART;

	/* Wait for room to write in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_TXP));

	/* Write data (depending on data size) into transmit fifo. */
	SPI_TXDR16(spi) = data;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write (8-bit) with Blocking.

Data is written to the SPI interface after the previous write transfer has
finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int8. 8 bit data to be written.
*/

void spi_send8(uint32_t spi, uint8_t data)
{
	/* Start a transaction */
	SPI_CR1(spi) |= SPI_CR1_CSTART;

	/* Wait for room to write in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_TXP));

	/* Write data (depending on data size) into transmit fifo. */
	SPI_TXDR8(spi) = data;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Read (32 bits).

Data is read from the SPI interface after the incoming transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int32. 32 bit data.
*/

uint32_t spi_read(uint32_t spi)
{
	uint32_t ret;

	/* Start a transaction */
	SPI_CR1(spi) |= SPI_CR1_CSTART;

	/* Wait for data available in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	/* Read the data. */
	ret = SPI_RXDR(spi);

	return ret;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Read (16 bits).

Data is read from the SPI interface after the incoming transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int16. 16 bit data.
*/

uint16_t spi_read16(uint32_t spi)
{
	uint16_t ret;

	/* Start a transaction */
	SPI_CR1(spi) |= SPI_CR1_CSTART;

	/* Wait for data available in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	/* Read the data. */
	ret = SPI_RXDR16(spi);

	return ret;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Read (8 bits).

Data is read from the SPI interface after the incoming transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int8. 8 bit data.
*/

uint8_t spi_read8(uint32_t spi)
{
	uint8_t ret;

	/* Start a transaction */
	SPI_CR1(spi) |= SPI_CR1_CSTART;

	/* Wait for data available in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	/* Read the data. */
	ret = SPI_RXDR8(spi);

	return ret;
}


/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write and Read Exchange (32-bit).

Data is written to the SPI interface, then a read is done after the incoming
transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 32 bit data to be written.
@returns data Unsigned int32. 32 bit data received.
*/

uint32_t spi_xfer(uint32_t spi, uint32_t data)
{
	uint32_t ret;

	/* Start a transaction */
	SPI_CR1(spi) |= SPI_CR1_CSTART;

	/* Wait for room to write in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_TXP));

	SPI_TXDR(spi) = data;

	/* Wait for rx data in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	/* Read the data. */
	ret = SPI_RXDR(spi);

	return ret;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write and Read Exchange (16-bit).

Data is written to the SPI interface, then a read is done after the incoming
transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 16 bit data to be written.
@returns data Unsigned int32. 16 bit data received.
*/

uint16_t spi_xfer16(uint32_t spi, uint16_t data)
{
	uint16_t ret;

	/* Start a transaction */
	SPI_CR1(spi) |= SPI_CR1_CSTART;

	/* Wait for room to write in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_TXP));

	SPI_TXDR16(spi) = data;

	/* Wait for rx data in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	/* Read the data. */
	ret = SPI_RXDR16(spi);

	return ret;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write and Read Exchange (8-bit).

Data is written to the SPI interface, then a read is done after the incoming
transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 8 bit data to be written.
@returns data Unsigned int32. 8 bit data received.
*/

uint8_t spi_xfer8(uint32_t spi, uint8_t data)
{
	uint8_t ret;

	/* make sure data will be transmitted at next fifo write */
	SPI_CR1(spi) |= SPI_CR1_CSTART;

	/* Wait for room to write in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_TXP));

	SPI_TXDR8(spi) = data;

	/* Wait for rx data in fifo. */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	/* Read the data. */
	ret = SPI_RXDR8(spi);

	return ret;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Full Duplex (clock + din + dout) Mode

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_full_duplex_mode(uint32_t spi)
{
	uint32_t reg32 = SPI_CFG2(spi);
	reg32 &= ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT);
	reg32 |=  (SPI_CFG2_COMM_FULL_DUPLEX << SPI_CFG2_COMM_SHIFT);
	SPI_CFG2(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Receive Only Mode (clock + din)

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_receive_only_mode(uint32_t spi)
{
	uint32_t reg32 = SPI_CFG2(spi);
	reg32 &= ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT);
	reg32 |=  (SPI_CFG2_COMM_SIMPLEX_RX << SPI_CFG2_COMM_SHIFT);
	SPI_CFG2(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Transmit Only Mode (clock + dout)

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_transmit_only_mode(uint32_t spi)
{
	uint32_t reg32 = SPI_CFG2(spi);

	reg32 &= ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT);
	reg32 |=  (SPI_CFG2_COMM_SIMPLEX_TX << SPI_CFG2_COMM_SHIFT);

	SPI_CFG2(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Half-Duplex (clock + dio) Mode.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_half_duplex_mode(uint32_t spi)
{
	uint32_t reg32 = SPI_CFG2(spi);

	reg32 &= ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT);
	reg32 |=  (SPI_CFG2_COMM_HALF_DUPLEX << SPI_CFG2_COMM_SHIFT);

	SPI_CFG2(spi) = reg32;
}


/*---------------------------------------------------------------------------*/
/** @brief SPI Enable the CRC.

The SPI peripheral is set to use a CRC field for transmit and receive.
Note that in order to use CRC, you have to configure transfer size before
data transfer actually starts on SPI bus. See @ref spi_set_transfer_size().

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_crc(uint32_t spi)
{
	SPI_CFG1(spi) |= SPI_CFG1_CRCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable the CRC.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_crc(uint32_t spi)
{
	SPI_CFG1(spi) &= ~SPI_CFG1_CRCEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI set length of next transfer
 *
 * Sets frame size (number of N bit groups) of next transaction. It may be
 * either transmission or reception. If enabled, then length includes CRC.
 * It is mandatory to set transfer length before CRC is enabled and data
 * transfer is started.
 *
 * @param[in] spi SPI peripheral identifier @ref spi_reg_base.
 * @param[in] size size of next frame. If given as 0xFFFF, then transfer is
 * infinite. Cant be used with CRC enabled.
 */
void spi_set_transfer_size(uint32_t spi, uint16_t size)
{
	uint32_t reg32;

	reg32 = SPI_CR2(spi);
	reg32 &= ~(SPI_CR2_TSIZE_MASK << SPI_CR2_TSIZE_SHIFT);
	reg32 |=  (size << SPI_CR2_TSIZE_SHIFT);
	SPI_CR2(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
void spi_wait_for_transfer_finished(uint32_t spi)
{
	while ((SPI_SR(spi) & SPI_SR_EOT) == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable Slave Management by Hardware

In slave mode the NSS hardware input is used as a select enable for the slave.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_software_slave_management(uint32_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_SSM;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable Slave Management by Software

In slave mode the NSS hardware input is replaced by an internal software
enable/disable of the slave (@ref spi_set_nss_high).

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_software_slave_management(uint32_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_SSM;
	/* allow slave select to be an input */
	//SPI_CFG2(spi) |= SPI_CFG2_SSOE;
	spi_set_nss_high(spi); //required to allow the master to work
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Software NSS Signal High

In slave mode, and only when software slave management is used, this replaces
the NSS signal with a slave select enable signal.

@todo these should perhaps be combined with an SSM enable as it is meaningless
otherwise

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_nss_high(uint32_t spi)
{
	SPI_CR1(spi) |= SPI_CR1_SSI;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Software NSS Signal Low

In slave mode, and only when software slave management is used, this replaces
the NSS signal with a slave select disable signal.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_nss_low(uint32_t spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_SSI;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set to Send LSB First

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_send_lsb_first(uint32_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_LSBFRST;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set to Send MSB First

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_send_msb_first(uint32_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_LSBFRST;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Baudrate Prescaler

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] baudrate Unsigned int8. Baudrate prescale value @ref spi_br_pre.
*/

void spi_set_baudrate_prescaler(uint32_t spi, uint8_t clkdiv)
{
	uint32_t reg32;

	if (clkdiv > 7) {
		return;
	}

	reg32 = (SPI_CFG1(spi) & ~(SPI_CFG1_MBR_MASK << SPI_CFG1_MBR_SHIFT));
	reg32 |= (clkdiv << SPI_CFG1_MBR_SHIFT);
	SPI_CFG1(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set to Master Mode

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_master_mode(uint32_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_MASTER;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set to Slave Mode

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_slave_mode(uint32_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_MASTER;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Polarity to High when Idle

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@sa spi_set_clock_polarity_0
*/

void spi_set_clock_polarity_1(uint32_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_CPOL;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Polarity to Low when Idle

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@sa spi_set_clock_polarity_1
*/

void spi_set_clock_polarity_0(uint32_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_CPOL;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Phase to Capture on Trailing Edge

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@sa spi_set_clock_phase_0
*/

void spi_set_clock_phase_1(uint32_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_CPHA;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Phase to Capture on Leading Edge

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@sa spi_set_clock_phase_1
*/

void spi_set_clock_phase_0(uint32_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_CPHA;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable the Transmit Buffer Empty Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_tx_buffer_empty_interrupt(uint32_t spi)
{
	SPI_IER(spi) |= SPI_IER_TXPIE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable the Transmit Buffer Empty Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_tx_buffer_empty_interrupt(uint32_t spi)
{
	SPI_IER(spi) &= ~SPI_IER_TXPIE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable the Receive Buffer Ready Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_rx_buffer_not_empty_interrupt(uint32_t spi)
{
	SPI_IER(spi) |= SPI_IER_RXPIE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable the Receive Buffer Ready Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_rx_buffer_not_empty_interrupt(uint32_t spi)
{
	SPI_IER(spi) &= ~SPI_IER_RXPIE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable the Error Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_error_interrupt(uint32_t spi)
{
	SPI_CR2(spi) |= SPI_IER_TIFREIE | SPI_IER_CRCEIE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable the Error Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_error_interrupt(uint32_t spi)
{
	SPI_CR2(spi) &= ~(SPI_IER_TIFREIE | SPI_IER_CRCEIE);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the NSS Pin as an Output

Normally used in master mode to allows the master to place all devices on the
SPI bus into slave mode. Multimaster mode is not possible.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_ss_output(uint32_t spi)
{
	SPI_CFG2(spi) |= SPI_CFG2_SSOE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the NSS Pin as an Input

In master mode this allows the master to sense the presence of other masters. If
NSS is then pulled low the master is placed into slave mode. In slave mode NSS
becomes a slave enable.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_ss_output(uint32_t spi)
{
	SPI_CFG2(spi) &= ~SPI_CFG2_SSOE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable Transmit Transfers via DMA

This allows transmissions to proceed unattended using DMA to move data to the
transmit buffer as it becomes available. The DMA channels provided for each
SPI peripheral are given in the Technical Manual DMA section.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_tx_dma(uint32_t spi)
{
	SPI_CFG1(spi) |= SPI_CFG1_TXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable Transmit Transfers via DMA

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_tx_dma(uint32_t spi)
{
	SPI_CFG1(spi) &= ~SPI_CFG1_TXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable Receive Transfers via DMA

This allows received data streams to proceed unattended using DMA to move data
from the receive buffer as data becomes available. The DMA channels provided
for each SPI peripheral are given in the Technical Manual DMA section.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_rx_dma(uint32_t spi)
{
	SPI_CFG1(spi) |= SPI_CFG1_RXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable Receive Transfers via DMA

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_rx_dma(uint32_t spi)
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
@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] mode Unsigned int8. Standard SPI mode (0, 1, 2, 3)
@sa spi_set_clock_phase_0 spi_set_clock_phase_1
@sa spi_set_clock_polarity_0 spi_set_clock_polarity_1
*/

void spi_set_standard_mode(uint32_t spi, uint8_t mode)
{
	uint32_t reg32;
	if (mode > 3) {
		return;
	}

	reg32 = SPI_CFG2(spi) & ~(SPI_CFG2_CPOL | SPI_CFG2_CPHA);
	if(mode & 1) {
		SPI_CFG2(spi) = reg32 | SPI_CFG2_CPHA;
	}
	if(mode & 2) {
		SPI_CFG2(spi) = reg32 | SPI_CFG2_CPOL;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Configure the SPI as Master.

The SPI peripheral is configured as a master with communication parameters
baudrate, frame format lsb/msb first, clock polarity and phase. The SPI
enable, CRC enable, CRC next CRC length controls are not affected.
These must be controlled separately.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] clkdiv Unsigned int8. Baudrate clock divider 0 (div/2) - 7(div/128).
@param[in] cpol bool. Clock polarity, false for 0, true for 1.
@param[in] cpha bool. Clock Phase, false for 0, true for 1.
@param[in] lsbfirst bool. Frame format lsb/msb first.
@param[in] keepgpio bool. True to keep GPIO controlled by SPI block.
@returns int. Error code.
*/

int spi_init_master(uint32_t spi, uint8_t clkdiv, bool cpol, bool cpha,
		    bool lsbfirst, bool keepgpio)
{

	/* First disable SPI to access regs*/
	SPI_CR1(spi) &= ~SPI_CR1_SPE;


	SPI_CFG2(spi) |= SPI_CFG2_MASTER;

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

	if (keepgpio) {
		SPI_CFG1(spi) |= SPI_CFG2_AFCNTR; /* Keep GPIO control between config changes */
	} else {
		SPI_CFG1(spi) &= ~SPI_CFG2_AFCNTR; /* Release GPIO control between config changes */
	}

	spi_set_baudrate_prescaler(spi, clkdiv);

	SPI_CFG2(spi) |= SPI_CFG2_SSM; /* default to software slave select */

	SPI_CR1(spi) |= SPI_CR1_SPE;

	return 0;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set CRC length to 8 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_crcl_8bit(uint32_t spi)
{
	uint32_t reg32 = SPI_CFG1(spi);
	reg32 &= ~(SPI_CFG1_CRCSIZE_MASK << SPI_CFG1_CRCSIZE_SHIFT);
	reg32 |=  (SPI_CFG1_CRCSIZE_8BIT << SPI_CFG1_CRCSIZE_SHIFT);
	SPI_CFG1(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set CRC length to 16 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_crcl_16bit(uint32_t spi)
{
	uint32_t reg32 = SPI_CFG1(spi);
	reg32 &= ~(SPI_CFG1_CRCSIZE_MASK << SPI_CFG1_CRCSIZE_SHIFT);
	reg32 |=  (SPI_CFG1_CRCSIZE_16BIT << SPI_CFG1_CRCSIZE_SHIFT);
	SPI_CFG1(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set data size in bits.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data_s Unsigned int16. number of bits minus one, range 4-32 @ref spi_ds.
*/

void spi_set_data_size(uint32_t spi, uint16_t data_s)
{
	uint32_t reg32 = SPI_CFG1(spi);
	reg32 &= ~(SPI_CFG1_DSIZE_MASK << SPI_CFG1_DSIZE_SHIFT);
	reg32 |=  ((data_s-1) << SPI_CFG1_DSIZE_SHIFT);
	SPI_CFG1(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set packet size to 1 data frame

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_fifo_packet_size_1data(uint32_t spi)
{
	uint32_t reg32 = SPI_CFG1(spi);
	reg32 &= ~(SPI_CFG1_FTHLV_MASK << SPI_CFG1_FTHLV_SHIFT);
	reg32 |=  (0 << SPI_CFG1_FTHLV_SHIFT);
	SPI_CFG1(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set packet size to 2 data frames

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_fifo_packet_size_2data(uint32_t spi)
{
	uint32_t reg32 = SPI_CFG1(spi);
	reg32 &= ~(SPI_CFG1_FTHLV_MASK << SPI_CFG1_FTHLV_SHIFT);
	reg32 |=  (1 << SPI_CFG1_FTHLV_SHIFT);
	SPI_CFG1(spi) = reg32;
}

/**@}*/
