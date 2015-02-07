/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Owen Kirby <oskirby@gmail.com>
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
#include <string.h>
#include <libopencm3/sam/pdc.h>
#include <libopencm3/sam/pmc.h>
#include <libopencm3/sam/spi.h>

void spi_reset(uint32_t spi)
{
	SPI_CR(spi) = SPI_CR_SWRST | SPI_CR_SPIDIS;
	/* Resetting the SPI controller doesn't flush SPI_RDR, so if there are
	 * unexpected bytes in there we must read and discard them manually. */
	asm volatile ("" :: "r" SPI_RDR(spi));
}

void spi_enable(uint32_t spi)
{
	SPI_CR(spi) = SPI_CR_SPIEN;
}

void spi_disable(uint32_t spi)
{
	SPI_CR(spi) = SPI_CR_SPIDIS;
}

void
spi_init(uint32_t spi, uint32_t flags, uint8_t dlybcs)
{
	/* Configure the mode register, deselect all peripherals, and set the delay. */
	SPI_MR(spi) = (flags & ~SPI_MR_DLYBCS_MASK) | SPI_MR_PCS_MASK | (dlybcs << 24);
}

int
spi_init_peripheral(uint32_t spi, uint8_t peripheral, uint32_t baudrate,
		    uint32_t flags, uint8_t dlybct, uint8_t dlybs)
{
	uint32_t csr = (dlybct << 24) | (dlybs << 16) | flags;
	
	/* Sanity-check the baud rate. */
	if (baudrate > pmc_mck_frequency) return -1;
	if (baudrate <= (pmc_mck_frequency>>8)) return -1;
	csr |= (pmc_mck_frequency / baudrate) << 8;
	
	/* Set the chip select register. */
	switch ((SPI_MR(spi) & SPI_MR_PCSDEC) ? (peripheral>>2) : peripheral) {
		case 0:
			SPI_CSR0(spi) = csr;
			break;
		case 1:
			SPI_CSR1(spi) = csr;
			break;
		case 2:
			SPI_CSR2(spi) = csr;
			break;
		case 3:
			SPI_CSR3(spi) = csr;
			break;
		default:
			/* Invalid chip select. */
			return -1;
	}
	return 0;
}

int spi_select(uint32_t spi, uint8_t peripheral)
{
	uint32_t mr = SPI_MR(spi) & ~SPI_MR_PCS_MASK;
	if (mr & SPI_MR_PCSDEC) {
		if (peripheral > 14) return -1;
		SPI_MR(spi) = mr | (peripheral << 16);
	} else {
		if (peripheral >= 4) return -1;
		SPI_MR(spi) = mr | ((0xF ^ (1<<peripheral)) << 16);
	}
	SPI_CR(spi) = SPI_CR_SPIEN;
	return 0;
}

void spi_deselect(uint32_t spi)
{
	SPI_CR(spi) = SPI_CR_SPIDIS;
}

uint16_t spi_xfer(uint32_t spi, uint16_t data)
{
    while (!(SPI_SR(spi) & SPI_SR_TDRE));
    /* The PCS field MUST NOT be zero, even in fixed peripheral select mode. */
	SPI_TDR(spi) = data | (SPI_MR(spi) & SPI_TDR_PCS_MASK);
    while (!(SPI_SR(spi) & SPI_SR_RDRF));
	return SPI_RDR(spi);
}

void spi_xfer_dma(uint32_t spi, const void *tx, void *rx, uint32_t len)
{
	PDC_PTCR(spi) = PDC_PTCR_TXTDIS | PDC_PTCR_RXTDIS;
    PDC_TPR(spi) = (uint32_t)(tx ? tx : memset(rx, 0, len));
    PDC_TCR(spi) = len;
    PDC_RPR(spi) = (uint32_t)rx;
    PDC_RCR(spi) = (rx) ? len : 0;
    PDC_PTCR(spi) = PDC_PTCR_TXTEN | (rx ? PDC_PTCR_RXTEN : 0);
	while (!(SPI_SR(SPI0) & SPI_SR_TXEMPTY));
}

