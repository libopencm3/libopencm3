/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
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

#include <libopencm3/lpc43xx/gpio.h>
#include <libopencm3/lpc43xx/i2c.h>

#include "../jellybean_conf.h"

void gpio_setup(void)
{
	/* Configure SCU Pin Mux as GPIO */
	scu_pinmux(SCU_PINMUX_LED1, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_LED2, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_LED3, SCU_GPIO_FAST);

	scu_pinmux(SCU_PINMUX_EN1V8, SCU_GPIO_FAST);

	scu_pinmux(SCU_PINMUX_BOOT0, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_BOOT1, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_BOOT2, SCU_GPIO_FAST);
	scu_pinmux(SCU_PINMUX_BOOT3, SCU_GPIO_FAST);

	/* Configure all GPIO as Input (safe state) */
	GPIO0_DIR = 0;
	GPIO1_DIR = 0;
	GPIO2_DIR = 0;
	GPIO3_DIR = 0;
	GPIO4_DIR = 0;
	GPIO5_DIR = 0;
	GPIO6_DIR = 0;
	GPIO7_DIR = 0;

	/* Configure GPIO as Output */
	GPIO2_DIR |= (PIN_LED1|PIN_LED2|PIN_LED3); /* Configure GPIO2[1/2/8] (P4_1/2 P6_12) as output. */
	GPIO3_DIR |= PIN_EN1V8; /* GPIO3[6] on P6_10  as output. */
}

#define SI5351C_I2C_ADDR (0x60 << 1)

/* write to single register */
void si5351c_write_reg(uint8_t reg, uint8_t val)
{
	i2c0_tx_start();
	i2c0_tx_byte(SI5351C_I2C_ADDR | I2C_WRITE);
	i2c0_tx_byte(reg);
	i2c0_tx_byte(val);
	i2c0_stop();
}

/* read single register */
uint8_t si5351c_read_reg(uint8_t reg)
{
	uint8_t val;

	/* set register address with write */
	i2c0_tx_start();
	i2c0_tx_byte(SI5351C_I2C_ADDR | I2C_WRITE);
	i2c0_tx_byte(reg);

	/* read the value */
	i2c0_tx_start();
	i2c0_tx_byte(SI5351C_I2C_ADDR | I2C_READ);
	val = i2c0_rx_byte();
	i2c0_stop();

	return val;
}

int main(void)
{
	int i;

	gpio_setup();
	i2c0_init();

	gpio_set(PORT_EN1V8, PIN_EN1V8); /* 1V8 on */

	while (1) {
		if (si5351c_read_reg(0) == 0x10)
			gpio_set(GPIO2, GPIOPIN1); /* LED on */
		else
			gpio_clear(GPIO2, GPIOPIN1); /* LED off */

		for (i = 0; i < 1000; i++)    /* Wait a bit. */
			__asm__("nop");
	}

	return 0;
}
