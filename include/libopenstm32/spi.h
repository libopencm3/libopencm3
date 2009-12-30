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

#ifndef LIBOPENSTM32_SPI_H
#define LIBOPENSTM32_SPI_H

#include <libopenstm32.h>

/* Registers can be accessed as 16bit or 32bit values. */

/* --- Convenience macros -------------------------------------------------- */

#define SPI1				SPI1_BASE
#define SPI2				SPI2_I2S_BASE
#define SPI3				SPI3_I2S_BASE

/* --- SPI registers ------------------------------------------------------- */

/* Control register 1 (SPIx_CR1) */
#define SPI_CR1(spi_base)		MMIO32(spi_base + 0x00)
#define SPI1_CR1			SPI_CR1(SPI1_BASE)
#define SPI2_CR1			SPI_CR1(SPI2_I2S_BASE)
#define SPI3_CR1			SPI_CR1(SPI3_I2S_BASE)

/* Control register 2 (SPIx_CR2) */
#define SPI_CR2(spi_base)		MMIO32(spi_base + 0x04)
#define SPI1_CR2			SPI_CR2(SPI1_BASE)
#define SPI2_CR2			SPI_CR2(SPI2_I2S_BASE)
#define SPI3_CR2			SPI_CR2(SPI3_I2S_BASE)

/* Status register (SPIx_SR) */
#define SPI_SR(spi_base)		MMIO32(spi_base + 0x08)
#define SPI1_SR				SPI_SR(SPI1_BASE)
#define SPI2_SR				SPI_SR(SPI2_I2S_BASE)
#define SPI3_SR				SPI_SR(SPI3_I2S_BASE)

/* Data register (SPIx_DR) */
#define SPI_DR(spi_base)		MMIO32(spi_base + 0x0c)
#define SPI1_DR				SPI_DR(SPI1_BASE)
#define SPI2_DR				SPI_DR(SPI2_I2S_BASE)
#define SPI3_DR				SPI_DR(SPI3_I2S_BASE)

/* CRC polynomial register (SPIx_CRCPR) */
/* Note: Not used in I2S mode. */
#define SPI_CRCPR(spi_base)		MMIO32(spi_base + 0x10)
#define SPI1_CRCPR			SPI_CRCPR(SPI1_BASE)
#define SPI2_CRCPR			SPI_CRCPR(SPI2_I2S_BASE)
#define SPI3_CRCPR			SPI_CRCPR(SPI3_I2S_BASE)

/* RX CRC register (SPIx_RXCRCR) */
/* Note: Not used in I2S mode. */
#define SPI_RXCRCR(spi_base)		MMIO32(spi_base + 0x14)
#define SPI1_RXCRCR			SPI_RXCRCR(SPI1_BASE)
#define SPI2_RXCRCR			SPI_RXCRCR(SPI2_I2S_BASE)
#define SPI3_RXCRCR			SPI_RXCRCR(SPI3_I2S_BASE)

/* TX CRC register (SPIx_RXCRCR) */
/* Note: Not used in I2S mode. */
#define SPI_TXCRCR(spi_base)		MMIO32(spi_base + 0x18)
#define SPI1_TXCRCR			SPI_TXCRCR(SPI1_BASE)
#define SPI2_TXCRCR			SPI_TXCRCR(SPI2_I2S_BASE)
#define SPI3_TXCRCR			SPI_TXCRCR(SPI3_I2S_BASE)

/* I2S configuration register (SPIx_I2SCFGR) */
#define SPI_I2SCFGR(spi_base)		MMIO32(spi_base + 0x1c)
#define SPI1_I2SCFGR			SPI_I2SCFGR(SPI1_BASE)
#define SPI2_I2SCFGR			SPI_I2SCFGR(SPI2_I2S_BASE)
#define SPI3_I2SCFGR			SPI_I2SCFGR(SPI3_I2S_BASE)

/* I2S prescaler register (SPIx_I2SPR) */
#define SPI_I2SPR(spi_base)		MMIO32(spi_base + 0x20)
#define SPI1_I2SPR			SPI_I2SPR(SPI1_BASE)
#define SPI2_I2SPR			SPI_I2SPR(SPI2_I2S_BASE)
#define SPI3_I2SPR			SPI_I2SPR(SPI3_I2S_BASE)

/* --- SPI_CR1 values ------------------------------------------------------ */

/* Note: None of the CR1 bits are used in I2S mode. */

/* BIDIMODE: Bidirectional data mode enable */
#define SPI_CR1_BIDIMODE_2LINE_UNIDIR	(0 << 15)
#define SPI_CR1_BIDIMODE_1LINE_BIDIR	(1 << 15)

/* BIDIOE: Output enable in bidirectional mode */
#define SPI_CR1_BIDIOE			(1 << 14)

/* CRCEN: Hardware CRC calculation enable */
#define SPI_CR1_CRCEN			(1 << 13)

/* CRCNEXT: Transmit CRC next */
#define SPI_CR1_CRCNEXT			(1 << 12)

/* DFF: Data frame format */
#define SPI_CR1_DFF_8BIT		(0 << 11)
#define SPI_CR1_DFF_16BIT		(1 << 11)

/* RXONLY: Receive only */
#define SPI_CR1_RXONLY			(1 << 10)

/* SSM: Software slave management */
#define SPI_CR1_SSM			(1 << 9)

/* SSI: Internal slave select */
#define SPI_CR1_SSI			(1 << 8)

/* LSBFIRST: Frame format */
#define SPI_CR1_MSBFIRST		(0 << 7)
#define SPI_CR1_LSBFIRST		(1 << 7)

/* SPE: SPI enable */
#define SPI_CR1_SPE			(1 << 6)

/* BR[2:0]: Baud rate control */
#define SPI_CR1_BAUDRATE_FPCLK_DIV_2	(0x00 << 3) 
#define SPI_CR1_BAUDRATE_FPCLK_DIV_4	(0x01 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_8	(0x02 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_16	(0x03 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_32	(0x04 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_64	(0x05 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_128	(0x06 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_256	(0x07 << 3)

/* MSTR: Master selection */
#define SPI_CR1_MSTR			(1 << 2)

/* CPOL: Clock polarity */
#define SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE	(0 << 1)
#define SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE	(1 << 1)

/* CPHA: Clock phase */
#define SPI_CR1_CPHA_CLK_TRANSITION_1	(0 << 0)
#define SPI_CR1_CPHA_CLK_TRANSITION_2	(1 << 0)

/* --- Function prototypes ------------------------------------------------- */

int spi_init_master(u32 spi, u32 br, u32 cpol, u32 cpha, u32 dff, u32 lsbfirst);
void spi_write(u32 spi, u16 data);
u16 spi_read(u32 spi);

/* TODO */

#endif
