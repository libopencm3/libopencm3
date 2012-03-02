/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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
#include <libopencm3/stm32/f1/flash.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/i2c.h>
#include "stts75.h"

void usart_setup(void)
{
	/* Enable clocks for GPIO port A (for GPIO_USART1_TX) and USART1. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_USART1EN);

	/* Setup GPIO pin GPIO_USART1_TX/GPIO9 on GPIO port A for transmit. */
	gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
	              GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART1_TX);

	/* Setup UART parameters. */
	usart_set_baudrate(USART1, 115200);
	usart_set_databits(USART1, 8);
	usart_set_stopbits(USART1, USART_STOPBITS_1);
	usart_set_mode(USART1, USART_MODE_TX_RX);
	usart_set_parity(USART1, USART_PARITY_NONE);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART1);
}

void gpio_setup(void)
{
	/* Enable GPIOB clock. */
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);

	/* Set GPIO6/7 (in GPIO port B) to 'output push-pull' for the LEDs. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO6);
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ,
	              GPIO_CNF_OUTPUT_PUSHPULL, GPIO7);
}

void i2c_setup(void)
{
	/* Enable clocks for I2C2 and AFIO. */
	rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_I2C2EN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_AFIOEN);

	/* Set alternate functions for the SCL and SDA pins of I2C2. */
	gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
		      GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN,
		      GPIO_I2C2_SCL | GPIO_I2C2_SDA);

	/* Disable the I2C before changing any configuration. */
	i2c_peripheral_disable(I2C2);

	/* APB1 is running at 36MHz. */
	i2c_set_clock_frequency(I2C2, I2C_CR2_FREQ_36MHZ);

	/* 400KHz - I2C Fast Mode */
	i2c_set_fast_mode(I2C2);

	/*
	 * fclock for I2C is 36MHz APB2 -> cycle time 28ns, low time at 400kHz
	 * incl trise -> Thigh = 1600ns; CCR = tlow/tcycle = 0x1C,9;
	 * Datasheet suggests 0x1e.
	 */
	i2c_set_ccr(I2C2, 0x1e);

	/*
	 * fclock for I2C is 36MHz -> cycle time 28ns, rise time for
	 * 400kHz => 300ns and 100kHz => 1000ns; 300ns/28ns = 10;
	 * Incremented by 1 -> 11.
	 */
	i2c_set_trise(I2C2, 0x0b);

	/*
	 * This is our slave address - needed only if we want to receive from
	 * other masters.
	 */
	i2c_set_own_7bit_slave_address(I2C2, 0x32);

	/* If everything is configured -> enable the peripheral. */
	i2c_peripheral_enable(I2C2);
}

int main(void)
{
	int i = 0;
	u16 temperature;

	rcc_clock_setup_in_hse_16mhz_out_72mhz();
	gpio_setup();
	usart_setup();
	i2c_setup();

	gpio_clear(GPIOB, GPIO7);	/* LED1 on */
	gpio_set(GPIOB, GPIO6);		/* LED2 off */

	/* Send a message on USART1. */
	usart_send(USART1, 's');
	usart_send(USART1, 't');
	usart_send(USART1, 'm');
	usart_send(USART1, '\r');
	usart_send(USART1, '\n');

	stts75_write_config(I2C2, STTS75_SENSOR0);
	stts75_write_temp_os(I2C2, STTS75_SENSOR0, 0x1a00); /* 26 degrees */
	stts75_write_temp_hyst(I2C2, STTS75_SENSOR0, 0x1a00);
	temperature = stts75_read_temperature(I2C2, STTS75_SENSOR0);

	/* Send the temperature as binary over USART1. */
	for (i = 15; i >= 0; i--) {
		if (temperature & (1 << i))
			usart_send(USART1, '1');
		else
			usart_send(USART1, '0');
	}

	usart_send(USART1, '\r');
	usart_send(USART1, '\n');

	gpio_clear(GPIOB, GPIO6); /* LED2 on */

	while (1); /* Halt. */

	return 0;
}
