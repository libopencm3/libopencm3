/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#include <libopenstm32/rcc.h>
#include <libopenstm32/flash.h>
#include <libopenstm32/gpio.h>
#include <libopenstm32/usart.h>
#include <libopenstm32/timer.h>
#include <libopenstm32/nvic.h>
#include <libopenstm32/spi.h>
#include "./dogm128.h"

void gpio_setup(void)
{
	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, IOPBEN);

	/* Set GPIO6/7 (in GPIO port B) to 'output push-pull' for the LEDs. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO6);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO7);

	/* A0 of DOGM128 */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO14);
	/*reset of DOGM128 */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO10);

	/* DOGM128/SPI2 clock and MOSI and NSS(CS1) */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO12);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO13);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO15);
}

void spi_setup()
{
	/* the DOGM128 display is connected to SPI2, so initialise it correctly */

	rcc_peripheral_enable_clock(&RCC_APB1ENR, SPI2EN);

        spi_set_unidirectional_mode(DOGM128_SPI); /* we want to send only */
        spi_disable_crc(DOGM128_SPI); /* no CRC for this slave */
        spi_set_dff_8bit(DOGM128_SPI); /* 8-bit dataword-length */
        spi_set_full_duplex_mode(DOGM128_SPI);  /* not receive-only */
        spi_enable_software_slave_management(DOGM128_SPI); /* we want to handle the CS signal in software */
        spi_set_nss_high(DOGM128_SPI);
        spi_set_baudrate_prescaler(DOGM128_SPI, SPI_CR1_BR_FPCLK_DIV_256); /* PCLOCK/256 as clock */
        spi_set_master_mode(DOGM128_SPI); /* we want to control everything and generate the clock -> master */
        spi_set_clock_polarity_1(DOGM128_SPI); /* sck idle state high */
        spi_set_clock_phase_1(DOGM128_SPI); /* bit is taken on the second (rising edge) of sck */
        spi_enable_ss_output(DOGM128_SPI);
        spi_enable(DOGM128_SPI);
}

int main(void)
{
	rcc_clock_setup_in_hse_16mhz_out_72mhz();
	gpio_setup();
	spi_setup();

	gpio_clear(GPIOB, GPIO7);	/* LED1 on */
	gpio_set(GPIOB, GPIO6);		/* LED2 off */
	
	dogm128_init();
	dogm128_clear();

	dogm128_set_cursor(0, 56);
	dogm128_print_string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	dogm128_set_cursor(0, 48);
	dogm128_print_string("abcdefghijklmnopqrstuvwxyz");
	dogm128_set_cursor(0, 40);
	dogm128_print_string(" !#$%&'()*+,-./0123456789");
	dogm128_set_cursor(0, 32);
	dogm128_print_string(":;<=>?@[\\]^_`{|}~");
	
	dogm128_set_dot(10, 10);
	dogm128_set_dot(20, 10);
	dogm128_set_dot(30, 10);
	dogm128_set_dot(40, 10);
	dogm128_set_dot(50, 10);
	
	dogm128_update_display();

	gpio_set(GPIOB, GPIO7);	/* LED1 off */
	while(1); /* Halt. */

	return 0;
}

