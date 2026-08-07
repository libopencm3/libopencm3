/** @defgroup spi_defines SPI Defines
@brief <b>Defined Constants and Types for the STM32H7xx SPI</b>
@ingroup STM32H7xx_defines
@version 1.0.0
LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_SPI_H
#define LIBOPENCM3_SPI_H

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup spi_reg_base SPI Register base address
@ingroup spi_defines

@{*/
#define SPI1				SPI1_BASE
#define SPI2				SPI2_BASE
#define SPI3				SPI3_BASE
#define SPI4				SPI4_BASE
#define SPI5				SPI5_BASE
#define SPI6				SPI6_BASE
/**@}*/

/* --- SPI registers ------------------------------------------------------- */

#define SPI_CR1(spi_base)			MMIO32((spi_base) + 0x00)
#define SPI_CR2(spi_base)			MMIO32((spi_base) + 0x04)
#define SPI_CFG1(spi_base)			MMIO32((spi_base) + 0x08)
#define SPI_CFG2(spi_base)			MMIO32((spi_base) + 0x0C)
#define SPI_IER(spi_base)			MMIO32((spi_base) + 0x10)
#define SPI_SR(spi_base)			MMIO32((spi_base) + 0x14)
#define SPI_IFCR(spi_base)			MMIO32((spi_base) + 0x18)
#define SPI_TXDR(spi_base)			MMIO32((spi_base) + 0x20)

#define SPI_TXDR8(spi_base)			MMIO8((spi_base) + 0x20)
#define SPI_TXDR16(spi_base)		MMIO16((spi_base) + 0x20)

#define SPI_RXDR(spi_base)			MMIO32((spi_base) + 0x30)

#define SPI_RXDR8(spi_base)			MMIO8((spi_base) + 0x30)
#define SPI_RXDR16(spi_base)		MMIO16((spi_base) + 0x30)

#define SPI_CRCPOLY(spi_base)			MMIO32((spi_base) + 0x40)
#define SPI_TXCRC(spi_base)			MMIO32((spi_base) + 0x44)
#define SPI_RXCRC(spi_base)			MMIO32((spi_base) + 0x48)
#define SPI_UDRDR(spi_base)			MMIO32((spi_base) + 0x4C)
#define SPI_I2SCFGR(spi_base)			MMIO32((spi_base) + 0x50)

/* --- SPI_CR1 values ------------------------------------------------------- */

#define SPI_CR1_IOLOCK						(1 << 16)
#define SPI_CR1_TCRCINI						(1 << 15)
#define SPI_CR1_RCRCINI						(1 << 14)
#define SPI_CR1_CRC33_17						(1 << 13)
#define SPI_CR1_SSI						(1 << 12)
#define SPI_CR1_HDDIR						(1 << 11)
#define SPI_CR1_CSUSP						(1 << 10)
#define SPI_CR1_CSTART						(1 << 9)
#define SPI_CR1_MASRX						(1 << 8)
#define SPI_CR1_SPE						(1 << 0)

/* --- SPI_CR2 values ------------------------------------------------------- */

#define SPI_CR2_TSER_MASK						0xFFFF
#define SPI_CR2_TSER_SHIFT						16

#define SPI_CR2_TSIZE_MASK						0xFFFF
#define SPI_CR2_TSIZE_SHIFT						0

/* --- SPI_CFG1 values ------------------------------------------------------ */

#define SPI_CFG1_MBR_MASK						0x7
#define SPI_CFG1_MBR_SHIFT						28

/****************************************************************************/
/** @defgroup spi_br_pre SPI peripheral baud rate prescale values
@ingroup spi_defines

@{*/
#define SPI_CFG1_MBR_CLK_DIV_2		0x0
#define SPI_CFG1_MBR_CLK_DIV_4		0x1
#define SPI_CFG1_MBR_CLK_DIV_8		0x2
#define SPI_CFG1_MBR_CLK_DIV_16		0x3
#define SPI_CFG1_MBR_CLK_DIV_32		0x4
#define SPI_CFG1_MBR_CLK_DIV_64		0x5
#define SPI_CFG1_MBR_CLK_DIV_128	0x6
#define SPI_CFG1_MBR_CLK_DIV_256	0x7
/**@}*/

#define SPI_CFG1_CRCEN						(1 << 22)
#define SPI_CFG1_CRCSIZE_MASK						0x1F
#define SPI_CFG1_CRCSIZE_SHIFT						16

#define SPI_CFG1_CRCSIZE_4BIT			0x3
#define SPI_CFG1_CRCSIZE_5BIT			0x4
#define SPI_CFG1_CRCSIZE_6BIT			0x5
#define SPI_CFG1_CRCSIZE_7BIT			0x6
#define SPI_CFG1_CRCSIZE_8BIT			0x7
#define SPI_CFG1_CRCSIZE_9BIT			0x8
#define SPI_CFG1_CRCSIZE_10BIT			0x9
#define SPI_CFG1_CRCSIZE_11BIT			0xA
#define SPI_CFG1_CRCSIZE_12BIT			0xB
#define SPI_CFG1_CRCSIZE_13BIT			0xC
#define SPI_CFG1_CRCSIZE_14BIT			0xD
#define SPI_CFG1_CRCSIZE_15BIT			0xE
#define SPI_CFG1_CRCSIZE_16BIT			0xF

#define SPI_CFG1_TXDMAEN						(1 << 15)
#define SPI_CFG1_RXDMAEN						(1 << 14)

#define SPI_CFG1_UDRDET_MASK						0x3
#define SPI_CFG1_UDRDET_SHIFT						11

#define SPI_CFG1_UDRCFG_MASK						0x3
#define SPI_CFG1_UDRCFG_SHIFT						9

#define SPI_CFG1_FTHLV_MASK						0xF
#define SPI_CFG1_FTHLV_SHIFT						5

#define SPI_CFG1_DSIZE_MASK						0x1F
#define SPI_CFG1_DSIZE_SHIFT						0

#define SPI_CFG1_DSIZE_4BIT			0x3
#define SPI_CFG1_DSIZE_5BIT			0x4
#define SPI_CFG1_DSIZE_6BIT			0x5
#define SPI_CFG1_DSIZE_7BIT			0x6
#define SPI_CFG1_DSIZE_8BIT			0x7
#define SPI_CFG1_DSIZE_9BIT			0x8
#define SPI_CFG1_DSIZE_10BIT		0x9
#define SPI_CFG1_DSIZE_11BIT		0xA
#define SPI_CFG1_DSIZE_12BIT		0xB
#define SPI_CFG1_DSIZE_13BIT		0xC
#define SPI_CFG1_DSIZE_14BIT		0xD
#define SPI_CFG1_DSIZE_15BIT		0xE
#define SPI_CFG1_DSIZE_16BIT		0xF

/* --- SPI_CFG2 values ------------------------------------------------------ */

#define SPI_CFG2_AFCNTR						(1 << 31)
#define SPI_CFG2_SSOM						(1 << 30)
#define SPI_CFG2_SSOE						(1 << 29)
#define SPI_CFG2_SSIOP						(1 << 28)

#define SPI_CFG2_SSM						(1 << 26)
#define SPI_CFG2_CPOL						(1 << 25)
#define SPI_CFG2_CPHA						(1 << 24)
#define SPI_CFG2_LSBFRST						(1 << 23)
#define SPI_CFG2_MASTER						(1 << 22)

#define SPI_CFG2_SP_MASK						0x7
#define SPI_CFG2_SP_SHIFT						19

#define SPI_CFG2_COMM_MASK						0x3
#define SPI_CFG2_COMM_SHIFT						17

#define SPI_CFG2_COMM_FULL_DUPLEX				0
#define SPI_CFG2_COMM_SIMPLEX_TX				1
#define SPI_CFG2_COMM_SIMPLEX_RX				2
#define SPI_CFG2_COMM_HALF_DUPLEX				3

#define SPI_CFG2_IOSWP						(1 << 15)

#define SPI_CFG2_MIDI_MASK						0xF
#define SPI_CFG2_MIDI_SHIFT						4

#define SPI_CFG2_MSSI_MASK						0xF
#define SPI_CFG2_MSSI_SHIFT						0

/* --- SPI_IER values ------------------------------------------------------ */

#define SPI_IER_TSERFIE						(1 << 10)
#define SPI_IER_MODFIE						(1 << 9)
#define SPI_IER_TIFREIE						(1 << 8)
#define SPI_IER_CRCEIE						(1 << 7)
#define SPI_IER_OVRIE						(1 << 6)
#define SPI_IER_UDRIE						(1 << 5)
#define SPI_IER_TXTFIE						(1 << 4)
#define SPI_IER_EOTIE						(1 << 3)
#define SPI_IER_DXPIE						(1 << 2)
#define SPI_IER_TXPIE						(1 << 1)
#define SPI_IER_RXPIE						(1 << 0)

/* --- SPI_SR values ------------------------------------------------------- */

#define SPI_SR_CTSIZE_MASK						0xFFFF
#define SPI_SR_CTSIZE_SHIFT						16

#define SPI_SR_RXWNE						(1 << 15)

#define SPI_SR_RXPLVL_MASK						0x3
#define SPI_SR_RXPLVL_SHIFT						13

#define SPI_SR_TXC						(1 << 12)
#define SPI_SR_SUSP						(1 << 11)
#define SPI_SR_TSERF						(1 << 10)
#define SPI_SR_MODF						(1 << 9)
#define SPI_SR_TIFRE						(1 << 8)
#define SPI_SR_CRCE						(1 << 7)
#define SPI_SR_OVR						(1 << 6)
#define SPI_SR_UDR						(1 << 5)
#define SPI_SR_TXTF						(1 << 4)
#define SPI_SR_EOT						(1 << 3)
#define SPI_SR_DXP						(1 << 2)
#define SPI_SR_TXP						(1 << 1)
#define SPI_SR_RXP						(1 << 0)

/* --- SPI_IFCR values ----------------------------------------------------- */

#define SPI_IFCR_SUSPC						(1 << 11)
#define SPI_IFCR_TSERFC						(1 << 10)
#define SPI_IFCR_MODFC						(1 << 9)
#define SPI_IFCR_TIFREC						(1 << 8)
#define SPI_IFCR_CRCEC						(1 << 7)
#define SPI_IFCR_OVRC						(1 << 6)
#define SPI_IFCR_UDRC						(1 << 5)
#define SPI_IFCR_TXTFC						(1 << 4)
#define SPI_IFCR_EOTC						(1 << 3)

/* --- SPI_I2SCFGR values -------------------------------------------------- */

#define SPI_I2SCFGR_MCKOE						(1 << 25)
#define SPI_I2SCFGR_ODD						(1 << 24)

#define SPI_I2SCFGR_I2SDIV_MASK						0xFF
#define SPI_I2SCFGR_IS2DIV_SHIFT						16

#define SPI_I2SCFGR_DATFMT						(1 << 14)
#define SPI_I2SCFGR_WSINV						(1 << 13)
#define SPI_I2SCFGR_FIXCH						(1 << 12)
#define SPI_I2SCFGR_CKPOL						(1 << 11)
#define SPI_I2SCFGR_CHLEN						(1 << 10)

#define SPI_I2SCFGR_DATLEN_MASK						0x3
#define SPI_I2SCFGR_DATLEN_SHIFT						8

#define SPI_I2SCFGR_PCMSYNC						(1 << 7)

#define SPI_I2SCFGR_I2SSTD_MASK						0x3
#define SPI_I2SCFGR_I2SSTD_SHIFT						4

#define SPI_I2SCFGR_I2SCFG_MASK						0x7
#define SPI_I2SCFGR_I2SCFG_SHIFT						1

#define SPI_I2SCFGR_I2SMOD						(1 << 0)

BEGIN_DECLS

void spi_reset(uint32_t spi_peripheral);
void spi_enable(uint32_t spi);
void spi_disable(uint32_t spi);
uint16_t spi_clean_disable(uint32_t spi);
void spi_write(uint32_t spi, uint16_t data);
void spi_send(uint32_t spi, uint16_t data);
uint16_t spi_read(uint32_t spi);
uint16_t spi_xfer(uint32_t spi, uint16_t data);
void spi_set_bidirectional_mode(uint32_t spi);
void spi_set_unidirectional_mode(uint32_t spi);
void spi_set_bidirectional_receive_only_mode(uint32_t spi);
void spi_set_bidirectional_transmit_only_mode(uint32_t spi);
void spi_enable_crc(uint32_t spi);
void spi_disable_crc(uint32_t spi);
void spi_set_transfer_size(uint32_t spi, uint16_t size);
void spi_set_full_duplex_mode(uint32_t spi);
void spi_set_receive_only_mode(uint32_t spi);
void spi_disable_software_slave_management(uint32_t spi);
void spi_enable_software_slave_management(uint32_t spi);
void spi_set_nss_high(uint32_t spi);
void spi_set_nss_low(uint32_t spi);
void spi_send_lsb_first(uint32_t spi);
void spi_send_msb_first(uint32_t spi);
void spi_set_baudrate_prescaler(uint32_t spi, uint8_t baudrate);
void spi_set_master_mode(uint32_t spi);
void spi_set_slave_mode(uint32_t spi);
void spi_set_clock_polarity_1(uint32_t spi);
void spi_set_clock_polarity_0(uint32_t spi);
void spi_set_clock_phase_1(uint32_t spi);
void spi_set_clock_phase_0(uint32_t spi);
void spi_enable_tx_buffer_empty_interrupt(uint32_t spi);
void spi_disable_tx_buffer_empty_interrupt(uint32_t spi);
void spi_enable_rx_buffer_not_empty_interrupt(uint32_t spi);
void spi_disable_rx_buffer_not_empty_interrupt(uint32_t spi);
void spi_enable_error_interrupt(uint32_t spi);
void spi_disable_error_interrupt(uint32_t spi);
void spi_enable_ss_output(uint32_t spi);
void spi_disable_ss_output(uint32_t spi);
void spi_enable_tx_dma(uint32_t spi);
void spi_disable_tx_dma(uint32_t spi);
void spi_enable_rx_dma(uint32_t spi);
void spi_disable_rx_dma(uint32_t spi);
void spi_set_standard_mode(uint32_t spi, uint8_t mode);
void spi_wait_for_transfer_finished(uint32_t spi);

int spi_init_master(uint32_t spi, uint32_t br, bool cpol, bool cpha,
		bool lsbfirst);
void spi_set_crcl_8bit(uint32_t spi);
void spi_set_crcl_16bit(uint32_t spi);
void spi_set_data_size(uint32_t spi, uint16_t data_s);
void spi_fifo_reception_threshold_8bit(uint32_t spi);
void spi_fifo_reception_threshold_16bit(uint32_t spi);
void spi_i2s_mode_spi_mode(uint32_t spi);
void spi_send8(uint32_t spi, uint8_t data);
uint8_t spi_read8(uint32_t spi);


END_DECLS


#endif

