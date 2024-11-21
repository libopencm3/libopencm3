/** @addtogroup spi_file SPI peripheral API
 * @ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2009
Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

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

/**@}*/
