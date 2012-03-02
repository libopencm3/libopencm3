/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/spi.h>

void clock_setup(void)
{
	rcc_clock_setup_in_hse_8mhz_out_72mhz();
}

void spi_setup(void)
{
	/* TODO */
}

void gpio_setup(void)
{
	/* TODO */
}

int main(void)
{
	clock_setup();
	gpio_setup();
	spi_setup();

	while (1) {
		spi_write(SPI1, 0xaa);
		spi_write(SPI1, 0x55);
	}

	return 0;
}
