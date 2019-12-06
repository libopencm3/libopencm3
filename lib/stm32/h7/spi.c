/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Brian Viele <vielster@allocor.tech>
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
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/h7/spi.h>

void spi_reset(uint32_t spi_peripheral) {	
	switch (spi_peripheral) {
	case SPI1_BASE:
		rcc_periph_reset_pulse(RST_SPI1);
		break;
	case SPI2_BASE:
		rcc_periph_reset_pulse(RST_SPI2);
		break;
	case SPI3_BASE:
		rcc_periph_reset_pulse(RST_SPI3);
		break;
	case SPI4_BASE:
		rcc_periph_reset_pulse(RST_SPI4);
		break;
	case SPI5_BASE:
		rcc_periph_reset_pulse(RST_SPI5);
		break;
	case SPI6_BASE:
		rcc_periph_reset_pulse(RST_SPI6);
		break;
	default:
		break;
	}
}

void spi_enable(uint32_t spi) {
	SPI2S_CR1(spi) |= SPI2S_CR1_SPE;
}

void spi_disable(uint32_t spi) {
	SPI2S_CR1(spi) &= ~SPI2S_CR1_SPE;
}

void spi_write(uint32_t spi, uint32_t data) {
	SPI2S_TXDR(spi)	= data;
}

uint32_t spi_read(uint32_t spi) {
	/* TODO: Wait for RX data register ready. */
	return SPI2S_RXDR(spi);
}

void spi_send_lsb_first(uint32_t spi) {
	SPI_CFG2(spi) |= SPI_CFG2_LSBFRST;
}

void spi_send_msb_first(uint32_t spi) {
	SPI_CFG2(spi) &= ~SPI_CFG2_LSBFRST;
}

void spi_set_clock_polarity_1(uint32_t spi) {
	SPI_CFG2(spi) |= SPI_CFG2_CPOL;
}

void spi_set_clock_polarity_0(uint32_t spi) {
	SPI_CFG2(spi) &= ~SPI_CFG2_CPOL;
}

void spi_set_clock_phase_1(uint32_t spi) {
	SPI_CFG2(spi) |= SPI_CFG2_CPHA;
}

void spi_set_clock_phase_0(uint32_t spi) {
	SPI_CFG2(spi) &= ~SPI_CFG2_CPHA;
}

static void spi_set_dirmode(uint32_t spi, uint32_t mode) {
	uint32_t cfgr2 = SPI_CFG2(spi);
	cfgr2 &= ~(SPI_CFG2_COMM_MASK << SPI_CFG2_COMM_SHIFT);
	cfgr2 |= (mode << SPI_CFG2_COMM_SHIFT);	
	SPI_CFG2(spi) = cfgr2;
}

void spi_set_bidirectional_mode(uint32_t spi) {
	spi_set_dirmode(spi, SPI_CFG2_COMM_FULLDUPLEX);
}

void spi_set_halfduplex_mode(uint32_t spi) {
	spi_set_dirmode(spi, SPI_CFG2_COMM_HALFDUPLEX);
}

void spi_set_bidirectional_receive_only_mode(uint32_t spi) {
	spi_set_dirmode(spi, SPI_CFG2_COMM_SIMPLEX_RX);
}

void spi_set_bidirectional_transmit_only_mode(uint32_t spi) {
	spi_set_dirmode(spi, SPI_CFG2_COMM_SIMPLEX_TX);
}

void spi_set_master_mode(uint32_t spi) {
	SPI_CFG2(spi) |= SPI_CFG2_MASTER;
}

void spi_set_slave_mode(uint32_t spi) {
	SPI_CFG2(spi) &= ~SPI_CFG2_MASTER;
}
