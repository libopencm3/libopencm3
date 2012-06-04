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
#include <libopencm3/lpc43xx/scu.h>
#include <libopencm3/lpc43xx/cgu.h>
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

	/* Configure SCU I2C0 Peripheral */
	SCU_SFSI2C0 = SCU_I2C0_NOMINAL;

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

//FIXME generalize and move to drivers

#define SCU_SFSI2C0_SCL_EFP (1 << 1)  /* 3 ns glitch filter */
#define SCU_SFSI2C0_SCL_EHD (1 << 2)  /* Fast-mode Plus transmit */
#define SCU_SFSI2C0_SCL_EZI (1 << 3)  /* Enable the input receiver */
#define SCU_SFSI2C0_SCL_ZIF (1 << 7)  /* Disable input glitch filter */
#define SCU_SFSI2C0_SDA_EFP (1 << 8)  /* 3 ns glitch filter */
#define SCU_SFSI2C0_SDA_EHD (1 << 10) /* Fast-mode Plus transmit */
#define SCU_SFSI2C0_SDA_EZI (1 << 11) /* Enable the input receiver */
#define SCU_SFSI2C0_SDA_ZIF (1 << 15) /* Disable input glitch filter */

#define I2C_CONCLR_AAC   (1 << 2) /* Assert acknowledge Clear */
#define I2C_CONCLR_SIC   (1 << 3) /* I2C interrupt Clear */
#define I2C_CONCLR_STAC  (1 << 5) /* START flag Clear */
#define I2C_CONCLR_I2ENC (1 << 6) /* I2C interface Disable bit */

#define I2C_CONSET_AA   (1 << 2) /* Assert acknowledge flag */
#define I2C_CONSET_SI   (1 << 3) /* I2C interrupt flag */
#define I2C_CONSET_STO  (1 << 4) /* STOP flag */
#define I2C_CONSET_STA  (1 << 5) /* START flag */
#define I2C_CONSET_I2EN (1 << 6) /* I2C interface enable */

#define CGU_SRC_32K       0x00
#define CGU_SRC_IRC       0x01
#define CGU_SRC_ENET_RX   0x02
#define CGU_SRC_ENET_TX   0x03
#define CGU_SRC_GP_CLKIN  0x04
#define CGU_SRC_XTAL      0x06
#define CGU_SRC_PLL0USB   0x07
#define CGU_SRC_PLL0AUDIO 0x08
#define CGU_SRC_PLL1      0x09
#define CGU_SRC_IDIVA     0x0C
#define CGU_SRC_IDIVB     0x0D
#define CGU_SRC_IDIVC     0x0E
#define CGU_SRC_IDIVD     0x0F
#define CGU_SRC_IDIVE     0x10

#define CGU_BASE_CLK_PD        (1 << 0)  /* output stage power-down */
#define CGU_BASE_CLK_AUTOBLOCK (1 << 11) /* block clock automatically */
#define CGU_BASE_CLK_SEL_SHIFT 24        /* clock source selection (5 bits) */

void i2c0_init()
{
	/* enable input on SCL and SDA pins */
	SCU_SFSI2C0 = (SCU_SFSI2C0_SCL_EZI | SCU_SFSI2C0_SDA_EZI);

	/* use PLL1 as clock source for APB1 (including I2C0) */
	CGU_BASE_APB1_CLK = (CGU_SRC_PLL1 << CGU_BASE_CLK_SEL_SHIFT);

	//FIXME assuming we're on IRC at 96 MHz

	/* 400 kHz I2C */
	//I2C0_SCLH = 120;
	//I2C0_SCLL = 120;

	/* 100 kHz I2C */
	I2C0_SCLH = 480;
	I2C0_SCLL = 480;
	//FIXME not sure why this appears to run at about 290 kHz

	/* clear the control bits */
	I2C0_CONCLR = (I2C_CONCLR_AAC | I2C_CONCLR_SIC
			| I2C_CONCLR_STAC | I2C_CONCLR_I2ENC);

	/* enable I2C0 */
	I2C0_CONSET = I2C_CONSET_I2EN;
}

/* transmit start bit */
void i2c0_tx_start()
{
	I2C0_CONCLR = I2C_CONCLR_SIC;
	I2C0_CONSET = I2C_CONSET_STA;
	while (!(I2C0_CONSET & I2C_CONSET_SI));
	I2C0_CONCLR = I2C_CONCLR_STAC;
}

/* transmit data byte */
void i2c0_tx_byte(u8 byte)
{
	if (I2C0_CONSET & I2C_CONSET_STA)
		I2C0_CONCLR = I2C_CONCLR_STAC;
	I2C0_DAT = byte;
	I2C0_CONCLR = I2C_CONCLR_SIC;
	while (!(I2C0_CONSET & I2C_CONSET_SI));
}

/* receive data byte */
u8 i2c0_rx_byte()
{
	if (I2C0_CONSET & I2C_CONSET_STA)
		I2C0_CONCLR = I2C_CONCLR_STAC;
	I2C0_CONCLR = I2C_CONCLR_SIC;
	while (!(I2C0_CONSET & I2C_CONSET_SI));
	return I2C0_DAT;
}

/* transmit stop bit */
void i2c0_stop()
{
	if (I2C0_CONSET & I2C_CONSET_STA)
		I2C0_CONCLR = I2C_CONCLR_STAC;
	I2C0_CONSET = I2C_CONSET_STO;
	I2C0_CONCLR = I2C_CONCLR_SIC;
}

#define SI5351C_I2C_ADDR (0x60 << 1)
#define I2C_WRITE        0
#define I2C_READ         1

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
