/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Owen Kirby <osk@exegin.com>
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

#ifndef SAM3X_SPI_H
#define SAM3X_SPI_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* --- The SPI base addresses aren't named consistently between chips ----- */
#ifdef SPI1_BASE
#define SPI0	SPI0_BASE
#define SPI1	SPI1_BASE
#else
#define SPI0	SPI_BASE
#endif

/* --- SPI registers ------------------------------------------------------ */

#define SPI_CR(x)			MMIO32((x) + 0x0000)
#define SPI_MR(x)			MMIO32((x) + 0x0004)
#define SPI_RDR(x)			MMIO32((x) + 0x0008)
#define SPI_TDR(x)			MMIO32((x) + 0x000C)
#define SPI_SR(x)			MMIO32((x) + 0x0010)
#define SPI_IER(x)			MMIO32((x) + 0x0014)
#define SPI_IDR(x)			MMIO32((x) + 0x0018)
#define SPI_IMR(x)			MMIO32((x) + 0x001C)
#define SPI_CSR0(x)			MMIO32((x) + 0x0030)
#define SPI_CSR1(x)			MMIO32((x) + 0x0034)
#define SPI_CSR2(x)			MMIO32((x) + 0x0038)
#define SPI_CSR3(x)			MMIO32((x) + 0x003C)
#define SPI_WPMR(x)			MMIO32((x) + 0x00E4)
#define SPI_WPSR(x)			MMIO32((x) + 0x00E8)
/* TODO: PDC offset */

/* --- SPI_CR values ------------------------------------------------------ */

/* Bits [31:25]: Reserved. */
#define SPI_CR_LASTXFER			(1 << 24)
/* Bits [23:8]: Reserved. */
#define SPI_CR_SWRST			(1 << 8)
/* Bits [6:2]: Reserved. */
#define SPI_CR_SPIDIS			(1 << 1)
#define SPI_CR_SPIEN			(1 << 0)

/* --- SPI_MR values ------------------------------------------------------ */

#define SPI_MR_DLYBCS_MASK		(0xFF << 24)
/* Bits [23:20]: Reserved. */
#define SPI_MR_PCS_MASK			(0xF << 16)
/* Bits [15:8]: Reserved. */
#define SPI_MR_LLB				(1 << 7)
/* Bit 6: Reserved. */
#define SPI_MR_WDRBT			(1 << 5)
#define SPI_MR_MODFDIS			(1 << 4)
/* Bit 3: Reserved. */
#define SPI_MR_PCSDEC			(1 << 2)
#define SPI_MR_PS				(1 << 1)
#define SPI_MR_MSTR				(1 << 0)

/* --- SPI_RDR values ----------------------------------------------------- */

/* Bits [31:20]: Reserved. */
#define SPI_RDR_PCS_MASK		(0xF << 16)
#define SPI_RDR_RD_MASK			(0xFFFF << 0)

/* --- SPI_TDR values ----------------------------------------------------- */

/* Bits [31:25]: Reserved. */
#define SPI_TDR_LASTXFER		(1 << 24)
/* Bits [23:20]: Reserved. */
#define SPI_TDR_PCS_MASK		(0xF << 16)
#define SPI_TDR_TD_MASK			(0xFFFF << 0)

/* --- SPI_SR values ------------------------------------------------------ */

/* Bits [31:17]: Reserved. */
#define SPI_SR_SPIENS			(1 << 16)
/* Bits [15:11]: Reserved. */
#define SPI_SR_UNDES			(1 << 10)
#define SPI_SR_TXEMPTY			(1 << 9)
#define SPI_SR_NSSR				(1 << 8)
#define SPI_SR_TXBUFE			(1 << 7)
#define SPI_SR_RXBUFF			(1 << 6)
#define SPI_SR_ENDTX			(1 << 5)
#define SPI_SR_ENDRX			(1 << 4)
#define SPI_SR_OVRES			(1 << 3)
#define SPI_SR_MODF				(1 << 2)
#define SPI_SR_TDRE				(1 << 1)
#define SPI_SR_RDRF				(1 << 0)

/* --- SPI_IER, SPI_IDR, and SPI_IMR values ------------------------------- */

/* Bits [31:11]: Reserved. */
#define SPI_INT_UNDES			(1 << 10)
#define SPI_INT_TXEMPTY			(1 << 9)
#define SPI_INT_NSSR			(1 << 8)
#define SPI_INT_TXBUFE			(1 << 7)
#define SPI_INT_RXBUFF			(1 << 6)
#define SPI_INT_ENDTX			(1 << 5)
#define SPI_INT_ENDRX			(1 << 4)
#define SPI_INT_OVRES			(1 << 3)
#define SPI_INT_MODF			(1 << 2)
#define SPI_INT_TDRE			(1 << 1)
#define SPI_INT_RDRF			(1 << 0)

/* --- SPI_CSRx values ---------------------------------------------------- */

#define SPI_CSR_DLYBCT_MASK		(0xFF << 24)
#define SPI_CSR_DLYBS_MASK		(0xFF << 16)
#define SPI_CSR_SCBR_MASK		(0xFF << 8)
#define SPI_CSR_BITS_MASK		(0xF << 4)
#define SPI_CSR_BITS(n)			(((n-8) << 4) & SPI_CSR_BITS_MASK)
#define SPI_CSR_CSAAT			(1 << 3)
#define SPI_CSR_CSNAAT			(1 << 2)
#define SPI_CSR_NCPHA			(1 << 1)
#define SPI_CSR_CPHA			(0 << 1)
#define SPI_CSR_CPOL			(1 << 0)

/* --- SPI_WPMR values ---------------------------------------------------- */

#define SPI_WPMR_KEY			(0x535049 << 8)
/* Bits [7:1]: Reserved. */
#define SPI_WPMR_WPIWPEN		(1 << 0)

/* --- SPI_WPSR values ---------------------------------------------------- */

/* Bits [31:16]: Reserved. */
#define SPI_WPSR_SPIWPVSRC_MASK	(0xFF << 8)
/* Bits [7:3]: Reserved. */
#define SPI_WPSR_SPIWPVS_MASK	(0x7 << 0)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void spi_reset(uint32_t spi);
void spi_enable(uint32_t spi);
void spi_disable(uint32_t spi);
void spi_init(uint32_t spi, uint32_t flags, uint8_t dlybcs);
int spi_init_peripheral(uint32_t spi, uint8_t peripheral, uint32_t baudrate,
		    uint32_t flags, uint8_t dlybct, uint8_t dlybs);

int spi_select(uint32_t spi, uint8_t peripheral);
void spi_deselect(uint32_t spi);

void spi_write(uint32_t spi, uint16_t data);
void spi_send(uint32_t spi, uint16_t data);
uint16_t spi_read(uint32_t spi);
uint16_t spi_xfer(uint32_t spi, uint16_t data);
void spi_xfer_dma(uint32_t spi, const void *tx, void *rx, uint32_t len);

END_DECLS

#endif
