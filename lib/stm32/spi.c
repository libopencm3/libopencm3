/** @defgroup spi_file SPI

@ingroup STM32F_files

@brief <b>libopencm3 STM32Fxxx SPI</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies <ksarkies@internode.on.net>

@date 15 October 2012

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
	                SPI_CR1_CPHA_CLK_TRANSITION_1, SPI_CR1_DFF_8BIT,
	                SPI_CR1_LSBFIRST);
	spi_write(SPI1, 0x55);		// 8-bit write
	spi_write(SPI1, 0xaa88);	// 16-bit write
	reg8 = spi_read(SPI1);		// 8-bit read
	reg16 = spi_read(SPI1);		// 16-bit read
@endcode

@todo need additional functions to aid ISRs in retrieving status

LGPL License Terms @ref lgpl_license
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
#if defined(STM32F1)
#       include <libopencm3/stm32/f1/rcc.h>
#elif defined(STM32F2)
#       include <libopencm3/stm32/f2/rcc.h>
#elif defined(STM32F4)
#       include <libopencm3/stm32/f4/rcc.h>
#else
#       error "stm32 family not defined."
#endif

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

/**@{*/

/*-----------------------------------------------------------------------------*/
/** @brief SPI Reset.

The SPI peripheral and all its associated configuration registers are placed in the
reset condition. The reset is effected via the RCC peripheral reset system.

@param[in] spi_peripheral Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_reset(u32 spi_peripheral)
{
	switch (spi_peripheral) {
	case SPI1:
		rcc_peripheral_reset(&RCC_APB2RSTR, RCC_APB2RSTR_SPI1RST);
		rcc_peripheral_clear_reset(&RCC_APB2RSTR, RCC_APB2RSTR_SPI1RST);
		break;
	case SPI2:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_SPI2RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_SPI2RST);
		break;
	case SPI3:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_SPI3RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_SPI3RST);
		break;
	}
}

/*-----------------------------------------------------------------------------*/
/** @brief Configure the SPI as Master.

The SPI peripheral is configured as a master with communication parameters
baudrate, data format 8/16 bits, frame format lsb/msb first, clock polarity
and phase. The SPI enable, CRC enable and CRC next controls are not affected.
These must be controlled separately.

@todo NSS pin handling.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] br Unsigned int32. Baudrate @ref spi_baudrate.
@param[in] cpol Unsigned int32. Clock polarity @ref spi_cpol.
@param[in] cpha Unsigned int32. Clock Phase @ref spi_cpha.
@param[in] dff Unsigned int32. Data frame format 8/16 bits @ref spi_dff.
@param[in] lsbfirst Unsigned int32. Frame format lsb/msb first @ref spi_lsbfirst.
@returns int. Error code.
*/

int spi_init_master(u32 spi, u32 br, u32 cpol, u32 cpha, u32 dff, u32 lsbfirst)
{
	u32 reg32 = SPI_CR1(spi);

	/* Reset all bits omitting SPE, CRCEN and CRCNEXT bits. */
	reg32 &= SPI_CR1_SPE | SPI_CR1_CRCEN | SPI_CR1_CRCNEXT;

	reg32 |= SPI_CR1_MSTR;	/* Configure SPI as master. */

	reg32 |= br;		/* Set baud rate bits. */
	reg32 |= cpol;		/* Set CPOL value. */
	reg32 |= cpha;		/* Set CPHA value. */
	reg32 |= dff;		/* Set data format (8 or 16 bits). */
	reg32 |= lsbfirst;	/* Set frame format (LSB- or MSB-first). */

	/* TODO: NSS pin handling. */

	SPI_CR1(spi) = reg32;

	return 0; /* TODO */
}

/* TODO: Error handling? */
/*-----------------------------------------------------------------------------*/
/** @brief SPI Enable.

The SPI peripheral is enabled.

@todo Error handling?

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_SPE; /* Enable SPI. */
}

/* TODO: Error handling? */
/*-----------------------------------------------------------------------------*/
/** @brief SPI Disable.

The SPI peripheral is disabled.

@todo  Follow procedure from section 23.3.8 in the TRM. 
(possibly create a "clean disable" function separately)

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable(u32 spi)
{
	u32 reg32;

	reg32 = SPI_CR1(spi);
	reg32 &= ~(SPI_CR1_SPE); /* Disable SPI. */
	SPI_CR1(spi) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Data Write.

Data is written to the SPI interface.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int16. 8 or 16 bit data to be written.
*/

void spi_write(u32 spi, u16 data)
{
	/* Write data (8 or 16 bits, depending on DFF) into DR. */
	SPI_DR(spi) = data;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Data Write with Blocking.

Data is written to the SPI interface after the previous write transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int16. 8 or 16 bit data to be written.
*/

void spi_send(u32 spi, u16 data)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_TXE))
		;

	/* Write data (8 or 16 bits, depending on DFF) into DR. */
	SPI_DR(spi) = data;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Data Read.

Data is read from the SPI interface after the incoming transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int16. 8 or 16 bit data.
*/

u16 spi_read(u32 spi)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXNE))
		;

	/* Read the data (8 or 16 bits, depending on DFF bit) from DR. */
	return SPI_DR(spi);
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Data Write and Read Exchange.

Data is written to the SPI interface, then a read is done after the incoming transfer
has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int16. 8 or 16 bit data to be written.
@returns data Unsigned int16. 8 or 16 bit data.
*/

u16 spi_xfer(u32 spi, u16 data)
{
	spi_write(spi, data);

	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXNE))
		;

	/* Read the data (8 or 16 bits, depending on DFF bit) from DR. */
	return SPI_DR(spi);
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set Bidirectional Simplex Mode.

The SPI peripheral is set for bidirectional transfers in two-wire simplex mode
(using a clock wire and a bidirectional data wire).

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_bidirectional_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_BIDIMODE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set Unidirectional Mode.

The SPI peripheral is set for unidirectional transfers. This is used in full duplex
mode or when the SPI is placed in two-wire simplex mode that uses a clock wire and a
unidirectional data wire.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_unidirectional_mode(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_BIDIMODE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set Bidirectional Simplex Receive Only Mode.

The SPI peripheral is set for bidirectional transfers in two-wire simplex mode
(using a clock wire and a bidirectional data wire), and is placed in a receive state.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_bidirectional_receive_only_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_BIDIMODE;
	SPI_CR1(spi) &= ~SPI_CR1_BIDIOE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set Bidirectional Simplex Receive Only Mode.

The SPI peripheral is set for bidirectional transfers in two-wire simplex mode
(using a clock wire and a bidirectional data wire), and is placed in a transmit state.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_bidirectional_transmit_only_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_BIDIMODE;
	SPI_CR1(spi) |= SPI_CR1_BIDIOE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Enable the CRC.

The SPI peripheral is set to use a CRC field for transmit and receive.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_crc(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_CRCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Disable the CRC.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_crc(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_CRCEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Next Transmit is a Data Word

The next transmission to take place is a data word from the transmit buffer.
This must be called before transmission to distinguish between sending
of a data or CRC word.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_next_tx_from_buffer(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_CRCNEXT;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Next Transmit is a CRC Word

The next transmission to take place is a crc word from the hardware crc unit.
This must be called before transmission to distinguish between sending
of a data or CRC word.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_next_tx_from_crc(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_CRCNEXT;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set Data Frame Format to 8 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_dff_8bit(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_DFF;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set Data Frame Format to 16 bits

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_dff_16bit(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_DFF;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set Full Duplex (3-wire) Mode

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_full_duplex_mode(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_RXONLY;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set Receive Only Mode for Simplex (2-wire) Unidirectional Transfers

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_receive_only_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_RXONLY;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Enable Slave Management by Hardware

In slave mode the NSS hardware input is used as a select enable for the slave.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_software_slave_management(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_SSM;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Enable Slave Management by Software

In slave mode the NSS hardware input is replaced by an internal software
enable/disable of the slave (@ref spi_set_nss_high).

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_software_slave_management(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_SSM;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set the Software NSS Signal High

In slave mode, and only when software slave management is used, this replaces
the NSS signal with a slave select enable signal.

@todo these should perhaps be combined with an SSM enable as it is meaningless otherwise

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_nss_high(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_SSI;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set the Software NSS Signal Low

In slave mode, and only when software slave management is used, this replaces
the NSS signal with a slave select disable signal.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_nss_low(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_SSI;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set to Send LSB First

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_send_lsb_first(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_LSBFIRST;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set to Send MSB First

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_send_msb_first(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_LSBFIRST;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set the Baudrate Prescaler

@todo Why is this specification different to the spi_init_master baudrate values?

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] baudrate Unsigned int8. Baudrate prescale value @ref spi_br_pre.
*/

void spi_set_baudrate_prescaler(u32 spi, u8 baudrate)
{
	u32 reg32;

	if (baudrate > 7)
		return;

	reg32 = (SPI_CR1(spi) & 0xffc7); /* Clear bits [5:3]. */
	reg32 |= (baudrate << 3);
	SPI_CR1(spi) = reg32;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set to Master Mode

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_master_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_MSTR;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set to Slave Mode

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_slave_mode(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_MSTR;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Polarity to High when Idle

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_clock_polarity_1(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_CPOL;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Polarity to Low when Idle

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_clock_polarity_0(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_CPOL;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Phase to Capture on Trailing Edge

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_clock_phase_1(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_CPHA;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set the Clock Phase to Capture on Leading Edge

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_clock_phase_0(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_CPHA;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Enable the Transmit Buffer Empty Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_tx_buffer_empty_interrupt(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_TXEIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Disable the Transmit Buffer Empty Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_tx_buffer_empty_interrupt(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_TXEIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Enable the Receive Buffer Ready Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_rx_buffer_not_empty_interrupt(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_RXNEIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Disable the Receive Buffer Ready Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_rx_buffer_not_empty_interrupt(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_RXNEIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Enable the Error Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_error_interrupt(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_ERRIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Disable the Error Interrupt

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_error_interrupt(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_ERRIE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set the NSS Pin as an Output

Normally used in master mode to allows the master to place all devices on the
SPI bus into slave mode. Multimaster mode is not possible.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_ss_output(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_SSOE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Set the NSS Pin as an Input

In master mode this allows the master to sense the presence of other masters. If
NSS is then pulled low the master is placed into slave mode. In slave mode NSS
becomes a slave enable.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_ss_output(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_SSOE;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Enable Transmit Transfers via DMA

This allows transmissions to proceed unattended using DMA to move data to the
transmit buffer as it becomes available. The DMA channels provided for each
SPI peripheral are given in the Technical Manual DMA section.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_tx_dma(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_TXDMAEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Disable Transmit Transfers via DMA

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_tx_dma(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_TXDMAEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Enable Receive Transfers via DMA

This allows received data streams to proceed unattended using DMA to move data from
the receive buffer as data becomes available. The DMA channels provided for each
SPI peripheral are given in the Technical Manual DMA section.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable_rx_dma(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_RXDMAEN;
}

/*-----------------------------------------------------------------------------*/
/** @brief SPI Disable Receive Transfers via DMA

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable_rx_dma(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_RXDMAEN;
}

/**@}*/
