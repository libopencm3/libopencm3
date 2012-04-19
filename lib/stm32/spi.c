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
void spi_enable(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_SPE; /* Enable SPI. */
}

/* TODO: Error handling? */
void spi_disable(u32 spi)
{
	u32 reg32;

	/* TODO: Follow procedure from section 23.3.8 in the TRM. */
	reg32 = SPI_CR1(spi);
	reg32 &= ~(SPI_CR1_SPE); /* Disable SPI. */
	SPI_CR1(spi) = reg32;
}

void spi_write(u32 spi, u16 data)
{
	/* Write data (8 or 16 bits, depending on DFF) into DR. */
	SPI_DR(spi) = data;
}

void spi_send(u32 spi, u16 data)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_TXE))
		;

	/* Write data (8 or 16 bits, depending on DFF) into DR. */
	SPI_DR(spi) = data;
}

u16 spi_read(u32 spi)
{
	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXNE))
		;

	/* Read the data (8 or 16 bits, depending on DFF bit) from DR. */
	return SPI_DR(spi);
}

u16 spi_xfer(u32 spi, u16 data)
{
	spi_write(spi, data);

	/* Wait for transfer finished. */
	while (!(SPI_SR(spi) & SPI_SR_RXNE))
		;

	/* Read the data (8 or 16 bits, depending on DFF bit) from DR. */
	return SPI_DR(spi);
}

void spi_set_bidirectional_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_BIDIMODE;
}

void spi_set_unidirectional_mode(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_BIDIMODE;
}

void spi_set_bidirectional_receive_only_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_BIDIMODE;
	SPI_CR1(spi) &= ~SPI_CR1_BIDIOE;
}

void spi_set_bidirectional_transmit_only_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_BIDIMODE;
	SPI_CR1(spi) |= SPI_CR1_BIDIOE;
}

void spi_enable_crc(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_CRCEN;
}

void spi_disable_crc(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_CRCEN;
}

void spi_set_next_tx_from_buffer(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_CRCNEXT;
}

void spi_set_next_tx_from_crc(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_CRCNEXT;
}

void spi_set_dff_8bit(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_DFF;
}

void spi_set_dff_16bit(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_DFF;
}

void spi_set_full_duplex_mode(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_RXONLY;
}

void spi_set_receive_only_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_RXONLY;
}

void spi_disable_software_slave_management(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_SSM;
}

void spi_enable_software_slave_management(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_SSM;
}

void spi_set_nss_high(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_SSI;
}

void spi_set_nss_low(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_SSI;
}

void spi_send_lsb_first(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_LSBFIRST;
}

void spi_send_msb_first(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_LSBFIRST;
}

void spi_set_baudrate_prescaler(u32 spi, u8 baudrate)
{
	u32 reg32;

	if (baudrate > 7)
		return;

	reg32 = (SPI_CR1(spi) & 0xffc7); /* Clear bits [5:3]. */
	reg32 |= (baudrate << 3);
	SPI_CR1(spi) = reg32;
}

void spi_set_master_mode(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_MSTR;
}

void spi_set_slave_mode(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_MSTR;
}

void spi_set_clock_polarity_1(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_CPOL;
}

void spi_set_clock_polarity_0(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_CPOL;
}

void spi_set_clock_phase_1(u32 spi)
{
	SPI_CR1(spi) |= SPI_CR1_CPHA;
}

void spi_set_clock_phase_0(u32 spi)
{
	SPI_CR1(spi) &= ~SPI_CR1_CPHA;
}

void spi_enable_tx_buffer_empty_interrupt(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_TXEIE;
}

void spi_disable_tx_buffer_empty_interrupt(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_TXEIE;
}

void spi_enable_rx_buffer_not_empty_interrupt(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_RXNEIE;
}

void spi_disable_rx_buffer_not_empty_interrupt(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_RXNEIE;
}

void spi_enable_error_interrupt(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_ERRIE;
}

void spi_disable_error_interrupt(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_ERRIE;
}

void spi_enable_ss_output(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_SSOE;
}

void spi_disable_ss_output(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_SSOE;
}

void spi_enable_tx_dma(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_TXDMAEN;
}

void spi_disable_tx_dma(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_TXDMAEN;
}

void spi_enable_rx_dma(u32 spi)
{
	SPI_CR2(spi) |= SPI_CR2_RXDMAEN;
}

void spi_disable_rx_dma(u32 spi)
{
	SPI_CR2(spi) &= ~SPI_CR2_RXDMAEN;
}
