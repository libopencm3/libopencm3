/** @addtogroup spi_file SPI peripheral API
 * @ingroup peripheral_apis
*/

/*
 * This file is part of the libopencm3 project.
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

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable.

The SPI peripheral is enabled.

@todo Error handling?

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_enable(uint32_t spi)
{
	SPI2S_CR1(spi) |= SPI2S_CR1_SPE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable.

The SPI peripheral is disabled.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_disable(uint32_t spi)
{
	SPI2S_CR1(spi) &= ~(SPI2S_CR1_SPE);
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

int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha,
		    uint32_t lsbfirst)
{
	uint32_t reg32;

	reg32 = SPI_CFG1(spi);
	reg32 &= ~(SPI_CFG1_MBR_MASK << SPI_CFG1_MBR_SHIFT);
	reg32 |= br;
	SPI_CFG1(spi) = reg32;

	reg32 = SPI_CFG2(spi);
	reg32 &= ~(SPI_CFG2_CPOL | SPI_CFG2_CKPHA | SPI_CFG2_LSBFRST);
	reg32 |= cpol;
	reg32 |= cpha;
	reg32 |= lsbfirst;
	reg32 |= SPI_CFG2_MASTER;
	reg32 |= SPI_CFG2_SSOE;
	SPI_CFG2(spi) = reg32;

	return 0;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Software NSS Signal High

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_nss_high(uint32_t spi)
{
	SPI2S_CR1(spi) |= SPI2S_CR1_SSI;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the Software NSS Signal Low

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
*/

void spi_set_nss_low(uint32_t spi)
{
	SPI2S_CR1(spi) &= ~SPI2S_CR1_SSI;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Disable Slave Management by Hardware

In slave mode the NSS hardware input is used as a select enable for the slave.
In Master mode the NSS output is handled by the hardware

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
	SPI_CFG2(spi) &= ~SPI_CFG2_SSOE;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write.

Data is written to the SPI interface.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 8, 16 or 32 bit data to be written.
*/

void spi_write(uint32_t spi, uint32_t data)
{
	SPI2S_TXDR(spi) = data;
	SPI2S_CR1(spi) |= SPI2S_CR1_CSTART;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data 8bits Write

8bits data is written to the SPI interface.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int8. 8 bit data to be written.
*/

void spi_write8(uint32_t spi, uint8_t data)
{
	SPI2S_IFCR(spi) = SPI2S_IFCR_TXTFC;
	SPI2S_TXDR8(spi) = data;
	SPI2S_CR1(spi) |= SPI2S_CR1_CSTART;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write with Blocking.

Data is written to the SPI interface after the previous write transfer has
finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 8, 16 or 32 bit data to be written.
*/

void spi_send(uint32_t spi, uint32_t data)
{
	/* Wait for transfer finished. */
	while (!(SPI2S_SR(spi) & SPI2S_SR_TXP));

	spi_write(spi, data);
}

void spi_send8(uint32_t spi, uint8_t data)
{
	/* Wait for transfer finished. */
	while (!(SPI2S_SR(spi) & SPI2S_SR_TXP));

	spi_write8(spi, data);
}
/*---------------------------------------------------------------------------*/
/** @brief SPI Data Read.

Data is read from the SPI interface after the incoming transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@returns data Unsigned int32. 8, 16 or 32 bit data.
*/

uint32_t spi_read(uint32_t spi)
{
	/* Wait for transfer finished. */
	while (!(SPI2S_SR(spi) & SPI2S_SR_RXP));

	return SPI2S_RXDR(spi);
}

uint8_t spi_read8(uint32_t spi)
{
	/* Wait for transfer finished. */
	while (!(SPI2S_SR(spi) & SPI2S_SR_RXP));

	return SPI2S_RXDR8(spi);
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Data Write and Read Exchange.

Data is written to the SPI interface, then a read is done after the incoming
transfer has finished.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data Unsigned int32. 8, 16 or 32 bit data to be written.
@returns data Unsigned int32. 8, 16 or 32 bit data.
*/

uint32_t spi_xfer(uint32_t spi, uint32_t data)
{
	spi_write(spi, data);

	return spi_read(spi);
}
/*---------------------------------------------------------------------------*/
/** @brief SPI Set Data Size

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] data_s Unsigned int16. Number of bits in spi data
*/

void spi_set_data_size(uint32_t spi, uint16_t data_s)
{
	uint32_t reg32 = SPI_CFG1(spi);
	reg32 &= ~(SPI_CFG1_DSIZE_MASK << SPI_CFG1_DSIZE_SHIFT);
	reg32 |= ((data_s & SPI_CFG1_DSIZE_MASK) << SPI_CFG1_DSIZE_SHIFT);
	SPI_CFG1(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Set the number of data transfer

Set the size of the spi data transfer, and the number of data tranfer to be reloaded.
SPI must be disabled while calling this function

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] tsize Unsigned int16. Number of data in spi transfer.
@param[in] tser Unsigned int16. Number of data to be reloaded into tsize once transfer completed.
@returns int. Error code.
*/

int spi_set_transfer_size(uint32_t spi, uint16_t tsize, uint16_t tser)
{
	if (SPI2S_CR1(spi) & SPI2S_CR1_SPE) {
		return -1;
	}
	SPI_CR2(spi) = (((tser & SPI_CR2_TSER_MASK) << SPI_CR2_TSER_SHIFT)
	                | ((tsize & SPI_CR2_TSIZE_MASK) << SPI_CR2_TSIZE_SHIFT));

	return 0;
}

/** @brief SPI Set the number of data frames in a SPI packet for the TxFifo

Set the number of data frames in a single SPI data packet, that number of space must be available in TxFifo for TXP to be set.

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] n Unsigned int8. Number of data in spi transfer.
*/
void spi_set_fifo_thresh_lvl(uint32_t spi, uint8_t n)
{
	uint32_t reg32 = SPI_CFG1(spi);
	reg32 &= ~(SPI_CFG1_FTHLV_MASK << SPI_CFG1_FTHLV_SHIFT);
	reg32 |= (((n - 1) & SPI_CFG1_FTHLV_MASK) << SPI_CFG1_FTHLV_SHIFT);
	SPI_CFG1(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Master Inter-Data Idleness

Set the number clock cycles inserted between two consecutive data frames

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] midi Unsigned int8. Number of idle SPI clock cycle inserted
*/
void spi_set_interdata_idleness(uint32_t spi, uint8_t midi)
{
	uint32_t reg32 = SPI_CFG2(spi);
	reg32 &= ~(SPI_CFG2_MIDI_MASK << SPI_CFG2_MIDI_SHIFT);
	reg32 |= ((midi & SPI_CFG2_MIDI_MASK) << SPI_CFG2_MIDI_SHIFT);
	SPI_CFG2(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Communication Mode

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] comm Unsigned int8. SPI Communication mode @ref spi_cfg2_values.
*/
void spi_set_communication_mode(uint32_t spi, uint8_t comm)
{
	uint32_t reg32 = SPI_CFG2(spi);
	reg32 &= ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT);
	reg32 |= ((comm & SPI_CFG2_COMM_MASK) << SPI_CFG2_COMM_SHIFT);
	SPI_CFG2(spi) = reg32;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Clear Status Flags

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] flag Unsigned int32. Bitwise OR of flags to clear @ref spi2s_ifcr_values
*/
void spi_clear_flags(uint32_t spi, uint32_t flags)
{
	SPI2S_IFCR(spi) = flags;
}

/*---------------------------------------------------------------------------*/
/** @brief SPI Enable interrupts

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] flag Unsigned int32. Bitwise OR of interrupts to enable @ref spi2s_ier_values
*/
void spi_enable_interrupts(uint32_t spi, uint32_t flags)
{
	SPI2S_IER(spi) |= flags;
}
/*---------------------------------------------------------------------------*/
/** @brief SPI Disalbe interrupts

@param[in] spi Unsigned int32. SPI peripheral identifier @ref spi_reg_base.
@param[in] flag Unsigned int32. Bitwise OR of interrupts to disable @ref spi2s_ier_values
*/
void spi_disable_interrupts(uint32_t spi, uint32_t flags)
{
	SPI2S_IER(spi) &= ~flags;
}
/**@}*/
