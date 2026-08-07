/** @addtogroup spi_file SPI peripheral API
 * @ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2009
Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>
@author @htmlonly &copy; @endhtmlonly 2021
Eduard Drusa <ventyl86 at netkosice dot sk>

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
/** @brief SPI Reset.

The SPI peripheral and all its associated configuration registers are placed in
the reset condition. The reset is effected via the RCC peripheral reset system.

@param[in] spi_peripheral Unsigned int32. SPI peripheral identifier @ref
spi_reg_base.
*/

void spi_reset(uint32_t spi_peripheral)
{	switch (spi_peripheral) {
#if defined(SPI1_BASE)
	case SPI1_BASE:
		rcc_periph_reset_pulse(RST_SPI1);
		break;
#endif
#if defined(SPI2_BASE)
	case SPI2_BASE:
		rcc_periph_reset_pulse(RST_SPI2);
		break;
#endif
#if defined(SPI3_BASE)
	case SPI3_BASE:
		rcc_periph_reset_pulse(RST_SPI3);
		break;
#endif
#if defined(SPI4_BASE)
	case SPI4_BASE:
		rcc_periph_reset_pulse(RST_SPI4);
		break;
#endif
#if defined(SPI5_BASE)
	case SPI5_BASE:
		rcc_periph_reset_pulse(RST_SPI5);
		break;
#endif
#if defined(SPI6_BASE)
	case SPI6_BASE:
		rcc_periph_reset_pulse(RST_SPI6);
		break;
#endif
	default:
		break;
	}
}

/* TODO: Error handling? */
/*---------------------------------------------------------------------------*/
/** @brief SPI Enable.

The SPI peripheral is enabled.

@todo Error handling?

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable(uint32_t spi)
{
	SPI_CR1(spi) |= SPI_CR1_SPE; /* Enable SPI. */
	SPI_CFG1(spi) |= SPI_CFG2_AFCNTR; /* Claim GPIO pins to be used by SPI */
}

/* TODO: Error handling? */
/*---------------------------------------------------------------------------*/
/** @brief SPI Disable.

The SPI peripheral is disabled.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable(uint32_t spi)
{
	uint32_t reg32;

	reg32 = SPI_CR1(spi);
	reg32 &= ~(SPI_CR1_SPE); /* Disable SPI. */
	SPI_CR1(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Clean Disable.

Disable the SPI peripheral according to the procedure in section 23.3.8 of the
reference manual.  This prevents corruption of any ongoing transfers and
prevents the BSY flag from becoming unreliable.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int16. 8 or 16 bit data from final read.
*/

uint16_t spi_clean_disable(uint32_t spi)
{
	/* Wait to receive last data */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	uint16_t data = SPI_RXDR(spi);

	/* Wait to transmit last data */
	while (!(SPI_SR(spi) & SPI_SR_TXC));

	/* Wait until not busy */
	while ((SPI_SR(spi) & SPI_SR_EOT) == 0);

	SPI_CR1(spi) &= ~SPI_CR1_SPE;

	return data;
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
/** @brief SPI Data Write with Blocking.

Data is written to the SPI interface after the previous write transfer has
finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int16. 8 or 16 bit data to be written.
*/

void spi_send(uint32_t spi, uint16_t data)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_TXP));

	/* Write data (8 or 16 bits, depending on DFF) into DR. */
	SPI_TXDR(spi) = data;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Read.

Data is read from the SPI interface after the incoming transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int16. 8 or 16 bit data.
*/

uint16_t spi_read(uint32_t spi)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	/* Read the data (8 or 16 bits, depending on DFF bit) from DR. */
	return SPI_RXDR(spi);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write and Read Exchange.

Data is written to the SPI interface, then a read is done after the incoming
transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int16. 8 or 16 bit data to be written.
@returns data Unsigned int16. 8 or 16 bit data.
*/

uint16_t spi_xfer(uint32_t spi, uint16_t data)
{
	spi_write(spi, data);

	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXP));

	/* Read the data (8 or 16 bits, depending on DFF bit) from DR. */
	return SPI_RXDR(spi);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Bidirectional Simplex Receive Only Mode.

The SPI peripheral is set for bidirectional transfers in two-wire simplex mode
(using a clock wire and a bidirectional data wire), and is placed in a receive
state.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_bidirectional_receive_only_mode(uint32_t spi)
{
	SPI_CFG2(spi) = (SPI_CFG2(spi) & ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT))
		| (SPI_CFG2_COMM_HALF_DUPLEX << SPI_CFG2_COMM_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Bidirectional Simplex Receive Only Mode.

The SPI peripheral is set for bidirectional transfers in two-wire simplex mode
(using a clock wire and a bidirectional data wire), and is placed in a transmit
state.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_bidirectional_transmit_only_mode(uint32_t spi)
{
	SPI_CFG2(spi) = (SPI_CFG2(spi) & ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT))
		| (SPI_CFG2_COMM_HALF_DUPLEX << SPI_CFG2_COMM_SHIFT);
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
 * Sets frame size of next transmission. It may be either transmission or
 * reception. If enabled, then length includes CRC. It is mandatory to set
 * transfer length before CRC is enabled and data transfer is started.
 *
 * @param[in] spi SPI peripheral identifier @ref spi_reg_base.
 * @param[in] size size of next frame. If given as 0xFFFF, then transfer is
 * infinite. Cant be used with CRC enabled.
 */
void spi_set_transfer_size(uint32_t spi, uint16_t size)
{
	/* This code works and I don't have a clue why */
	if (SPI_SR(spi) & SPI_SR_EOT) {
		SPI_IFCR(spi) = SPI_IFCR_EOTC;
	}
	SPI_CR2(spi) = (SPI_CR2(spi) & ~(SPI_CR2_TSIZE_MASK << SPI_CR2_TSIZE_SHIFT))
		| (size << SPI_CR2_TSIZE_SHIFT);

	SPI_CR1(spi) |= SPI_CR1_CSTART;
}

void spi_wait_for_transfer_finished(uint32_t spi)
{
	while ((SPI_SR(spi) & SPI_SR_EOT) == 0);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Full Duplex (3-wire) Mode

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_full_duplex_mode(uint32_t spi)
{
	SPI_CFG2(spi) = (SPI_CFG2(spi) & ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT))
		| (SPI_CFG2_COMM_FULL_DUPLEX << SPI_CFG2_COMM_SHIFT);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set Receive Only Mode for Simplex (2-wire) Unidirectional
Transfers

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_receive_only_mode(uint32_t spi)
{
	SPI_CFG2(spi) = (SPI_CFG2(spi) & ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT))
		| (SPI_CFG2_COMM_SIMPLEX_RX << SPI_CFG2_COMM_SHIFT);
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
	SPI_CFG2(spi) |= SPI_CFG2_SSOE;
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

@todo Why is this specification different to the spi_init_master baudrate
values?

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] baudrate Unsigned int8. Baudrate prescale value @ref spi_br_pre.
*/

void spi_set_baudrate_prescaler(uint32_t spi, uint8_t baudrate)
{
	uint32_t reg32;

	if (baudrate > 7) {
		return;
	}

	reg32 = (SPI_CFG1(spi) & ~(SPI_CFG1_MBR_MASK << SPI_CFG1_MBR_SHIFT));
	reg32 |= (baudrate << SPI_CFG1_MBR_SHIFT);
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
	if (mode > 3) {
		return;
	}

	uint32_t reg32 = SPI_CFG2(spi) & ~(SPI_CFG2_CPOL | SPI_CFG2_CPHA);
	SPI_CFG2(spi) = reg32 | mode;
}

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
