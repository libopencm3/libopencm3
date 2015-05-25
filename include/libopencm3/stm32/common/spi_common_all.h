/** @addtogroup spi_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
 *
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA SPI.H
The order of header inclusion is important. spi.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#if defined(LIBOPENCM3_SPI_H)
/** @endcond */
#ifndef LIBOPENCM3_SPI_COMMON_ALL_H
#define LIBOPENCM3_SPI_COMMON_ALL_H

/**@{*/

/* Registers can be accessed as 16bit or 32bit values. */

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

/* Control register 1 (SPIx_CR1) */
/* Note: Not used in I2S mode. */
#define SPI_CR1(spi_base)		MMIO32(spi_base + 0x00)
#define SPI1_CR1			SPI_CR1(SPI1_BASE)
#define SPI2_CR1			SPI_CR1(SPI2_BASE)
#define SPI3_CR1			SPI_CR1(SPI3_BASE)

/* Control register 2 (SPIx_CR2) */
#define SPI_CR2(spi_base)		MMIO32(spi_base + 0x04)
#define SPI1_CR2			SPI_CR2(SPI1_BASE)
#define SPI2_CR2			SPI_CR2(SPI2_BASE)
#define SPI3_CR2			SPI_CR2(SPI3_BASE)

/* Status register (SPIx_SR) */
#define SPI_SR(spi_base)		MMIO32(spi_base + 0x08)
#define SPI1_SR				SPI_SR(SPI1_BASE)
#define SPI2_SR				SPI_SR(SPI2_BASE)
#define SPI3_SR				SPI_SR(SPI3_BASE)

/* Data register (SPIx_DR) */
#define SPI_DR(spi_base)		MMIO32(spi_base + 0x0c)
#define SPI1_DR				SPI_DR(SPI1_BASE)
#define SPI2_DR				SPI_DR(SPI2_BASE)
#define SPI3_DR				SPI_DR(SPI3_BASE)

/* CRC polynomial register (SPIx_CRCPR) */
/* Note: Not used in I2S mode. */
#define SPI_CRCPR(spi_base)		MMIO32(spi_base + 0x10)
#define SPI1_CRCPR			SPI_CRCPR(SPI1_BASE)
#define SPI2_CRCPR			SPI_CRCPR(SPI2_BASE)
#define SPI3_CRCPR			SPI_CRCPR(SPI3_BASE)

/* RX CRC register (SPIx_RXCRCR) */
/* Note: Not used in I2S mode. */
#define SPI_RXCRCR(spi_base)		MMIO32(spi_base + 0x14)
#define SPI1_RXCRCR			SPI_RXCRCR(SPI1_BASE)
#define SPI2_RXCRCR			SPI_RXCRCR(SPI2_BASE)
#define SPI3_RXCRCR			SPI_RXCRCR(SPI3_BASE)

/* TX CRC register (SPIx_RXCRCR) */
/* Note: Not used in I2S mode. */
#define SPI_TXCRCR(spi_base)		MMIO32(spi_base + 0x18)
#define SPI1_TXCRCR			SPI_TXCRCR(SPI1_BASE)
#define SPI2_TXCRCR			SPI_TXCRCR(SPI2_BASE)
#define SPI3_TXCRCR			SPI_TXCRCR(SPI3_BASE)

/* I2S configuration register (SPIx_I2SCFGR) */
#define SPI_I2SCFGR(spi_base)		MMIO32(spi_base + 0x1c)
#define SPI1_I2SCFGR			SPI_I2SCFGR(SPI1_BASE)
#define SPI2_I2SCFGR			SPI_I2SCFGR(SPI2_BASE)
#define SPI3_I2SCFGR			SPI_I2SCFGR(SPI3_BASE)

/* I2S prescaler register (SPIx_I2SPR) */
#define SPI_I2SPR(spi_base)		MMIO32(spi_base + 0x20)
#define SPI1_I2SPR			SPI_I2SPR(SPI1_BASE)
#define SPI2_I2SPR			SPI_I2SPR(SPI2_BASE)
#define SPI3_I2SPR			SPI_I2SPR(SPI3_BASE)

/* --- SPI_CR1 values ------------------------------------------------------ */

/* Note: None of the CR1 bits are used in I2S mode. */

/* BIDIMODE: Bidirectional data mode enable */
#define SPI_CR1_BIDIMODE_2LINE_UNIDIR	(0 << 15)
#define SPI_CR1_BIDIMODE_1LINE_BIDIR	(1 << 15)
#define SPI_CR1_BIDIMODE		(1 << 15)

/* BIDIOE: Output enable in bidirectional mode */
#define SPI_CR1_BIDIOE			(1 << 14)

/* CRCEN: Hardware CRC calculation enable */
#define SPI_CR1_CRCEN			(1 << 13)

/* CRCNEXT: Transmit CRC next */
#define SPI_CR1_CRCNEXT			(1 << 12)

/* RXONLY: Receive only */
#define SPI_CR1_RXONLY			(1 << 10)

/* SSM: Software slave management */
#define SPI_CR1_SSM			(1 << 9)

/* SSI: Internal slave select */
#define SPI_CR1_SSI			(1 << 8)

/* LSBFIRST: Frame format */
/****************************************************************************/
/** @defgroup spi_lsbfirst SPI lsb/msb first
@ingroup spi_defines

@{*/
#define SPI_CR1_MSBFIRST		(0 << 7)
#define SPI_CR1_LSBFIRST		(1 << 7)
/**@}*/

/* SPE: SPI enable */
#define SPI_CR1_SPE			(1 << 6)

/* BR[2:0]: Baud rate control */
/****************************************************************************/
/** @defgroup spi_baudrate SPI peripheral baud rates
@ingroup spi_defines

@{*/
#define SPI_CR1_BAUDRATE_FPCLK_DIV_2	(0x00 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_4	(0x01 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_8	(0x02 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_16	(0x03 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_32	(0x04 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_64	(0x05 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_128	(0x06 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_256	(0x07 << 3)
/**@}*/
/****************************************************************************/
/** @defgroup spi_br_pre SPI peripheral baud rate prescale values
@ingroup spi_defines

@{*/
#define SPI_CR1_BR_FPCLK_DIV_2		0x0
#define SPI_CR1_BR_FPCLK_DIV_4		0x1
#define SPI_CR1_BR_FPCLK_DIV_8		0x2
#define SPI_CR1_BR_FPCLK_DIV_16		0x3
#define SPI_CR1_BR_FPCLK_DIV_32		0x4
#define SPI_CR1_BR_FPCLK_DIV_64		0x5
#define SPI_CR1_BR_FPCLK_DIV_128	0x6
#define SPI_CR1_BR_FPCLK_DIV_256	0x7
/**@}*/

/* MSTR: Master selection */
#define SPI_CR1_MSTR			(1 << 2)

/* CPOL: Clock polarity */
/****************************************************************************/
/** @defgroup spi_cpol SPI clock polarity
@ingroup spi_defines

@{*/
#define SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE	(0 << 1)
#define SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE	(1 << 1)
/**@}*/
#define SPI_CR1_CPOL			(1 << 1)

/* CPHA: Clock phase */
/****************************************************************************/
/** @defgroup spi_cpha SPI clock phase
@ingroup spi_defines

@{*/
#define SPI_CR1_CPHA_CLK_TRANSITION_1	(0 << 0)
#define SPI_CR1_CPHA_CLK_TRANSITION_2	(1 << 0)
/**@}*/
#define SPI_CR1_CPHA			(1 << 0)

/* --- SPI_CR2 values ------------------------------------------------------ */

/* Bits [15:8]: Reserved. Forced to 0 by hardware. Used on F3. */

/* TXEIE: Tx buffer empty interrupt enable */
#define SPI_CR2_TXEIE			(1 << 7)

/* RXNEIE: Rx buffer not empty interrupt enable */
#define SPI_CR2_RXNEIE			(1 << 6)

/* ERRIE: Error interrupt enable */
#define SPI_CR2_ERRIE			(1 << 5)

/* Bits [4:3]: Reserved. Forced to 0 by hardware. */

/* SSOE: SS output enable */
/* Note: Not used in I2S mode. */
#define SPI_CR2_SSOE			(1 << 2)

/* TXDMAEN: Tx buffer DMA enable */
#define SPI_CR2_TXDMAEN			(1 << 1)

/* RXDMAEN: Rx buffer DMA enable */
#define SPI_CR2_RXDMAEN			(1 << 0)

/* --- SPI_SR values ------------------------------------------------------- */

/* Bits [15:8]: Reserved. Forced to 0 by hardware. Used on F3. */

/* BSY: Busy flag */
#define SPI_SR_BSY			(1 << 7)

/* OVR: Overrun flag */
#define SPI_SR_OVR			(1 << 6)

/* MODF: Mode fault */
/* Note: Not used in I2S mode. */
#define SPI_SR_MODF			(1 << 5)

/* CRCERR: CRC error flag */
/* Note: Not used in I2S mode. */
#define SPI_SR_CRCERR			(1 << 4)

/* UDR: Underrun flag */
/* Note: Not used in SPI mode. */
#define SPI_SR_UDR			(1 << 3)

/* CHSIDE: Channel side */
/* Note: Not used in SPI mode. No meaning in PCM mode. */
#define SPI_SR_CHSIDE			(1 << 2)

/* TXE: Transmit buffer empty */
#define SPI_SR_TXE			(1 << 1)

/* RXNE: Receive buffer not empty */
#define SPI_SR_RXNE			(1 << 0)

/* --- SPI_DR values ------------------------------------------------------- */

/* SPI_DR[15:0]: Data Register. */

/* --- SPI_CRCPR values ---------------------------------------------------- */

/* Note: Not used in I2S mode. */
/* SPI_CRCPR [15:0]: CRC Polynomial Register. */

/* --- SPI_RXCRCR values --------------------------------------------------- */

/* Note: Not used in I2S mode. */
/* SPI_RXCRCR [15:0]: RX CRC Register. */

/* --- SPI_TXCRCR values --------------------------------------------------- */

/* Note: Not used in I2S mode. */
/* SPI_TXCRCR [15:0]: TX CRC Register. */

/* --- SPI_I2SCFGR values -------------------------------------------------- */

/* Note: None of these bits are used in SPI mode. */

/* Bits [15:12]: Reserved. Forced to 0 by hardware. */

/* I2SMOD: I2S mode selection */
#define SPI_I2SCFGR_I2SMOD			(1 << 11)

/* I2SE: I2S enable */
#define SPI_I2SCFGR_I2SE			(1 << 10)

/* I2SCFG[9:8]: I2S configuration mode */
#define SPI_I2SCFGR_I2SCFG_LSB			8
#define SPI_I2SCFGR_I2SCFG_SLAVE_TRANSMIT	0x0
#define SPI_I2SCFGR_I2SCFG_SLAVE_RECEIVE	0x1
#define SPI_I2SCFGR_I2SCFG_MASTER_TRANSMIT	0x2
#define SPI_I2SCFGR_I2SCFG_MASTER_RECEIVE	0x3

/* PCMSYNC: PCM frame synchronization */
#define SPI_I2SCFGR_PCMSYNC			(1 << 7)

/* Bit 6: Reserved. Forced to 0 by hardware. */

/* I2SSTD[5:4]: I2S standard selection */
#define SPI_I2SCFGR_I2SSTD_LSB			4
#define SPI_I2SCFGR_I2SSTD_I2S_PHILLIPS		0x0
#define SPI_I2SCFGR_I2SSTD_MSB_JUSTIFIED	0x1
#define SPI_I2SCFGR_I2SSTD_LSB_JUSTIFIED	0x2
#define SPI_I2SCFGR_I2SSTD_PCM			0x3

/* CKPOL: Steady state clock polarity */
#define SPI_I2SCFGR_CKPOL			(1 << 3)

/* DATLEN[2:1]: Data length to be transferred */
#define SPI_I2SCFGR_DATLEN_LSB			1
#define SPI_I2SCFGR_DATLEN_16BIT		0x0
#define SPI_I2SCFGR_DATLEN_24BIT		0x1
#define SPI_I2SCFGR_DATLEN_32BIT		0x2

/* CHLEN: Channel length */
#define SPI_I2SCFGR_CHLEN			(1 << 0)

/* --- SPI_I2SPR values ---------------------------------------------------- */

/* Note: None of these bits are used in SPI mode. */

/* Bits [15:10]: Reserved. Forced to 0 by hardware. */

/* MCKOE: Master clock output enable */
#define SPI_I2SPR_MCKOE				(1 << 9)

/* ODD: Odd factor for the prescaler */
#define SPI_I2SPR_ODD				(1 << 8)

/* I2SDIV[7:0]: I2S linear prescaler */
/* 0 and 1 are forbidden values */

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void spi_reset(uint32_t spi_peripheral);
int spi_init_master(uint32_t spi, uint32_t br, uint32_t cpol, uint32_t cpha,
		    uint32_t dff, uint32_t lsbfirst);
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
void spi_set_next_tx_from_buffer(uint32_t spi);
void spi_set_next_tx_from_crc(uint32_t spi);
void spi_set_dff_8bit(uint32_t spi);
void spi_set_dff_16bit(uint32_t spi);
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

END_DECLS

/**@}*/

#endif
/** @cond */
#else
#warning "spi_common_all.h should not be included explicitly, only via spi.h"
#endif
/** @endcond */

