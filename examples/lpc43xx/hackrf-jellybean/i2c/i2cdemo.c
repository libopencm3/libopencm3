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
	I2C0_SCLH = 120;
	I2C0_SCLL = 120;

	/* 100 kHz I2C */
	//I2C0_SCLH = 480;
	//I2C0_SCLL = 480;

	/* clear the control bits */
	I2C0_CONCLR = (I2C_CONCLR_AAC | I2C_CONCLR_SIC
			| I2C_CONCLR_STAC | I2C_CONCLR_I2ENC);

	/* enable I2C0 */
	I2C0_CONSET = I2C_CONSET_I2EN;
}

int main(void)
{
	int i;

	i2c0_init();

	//TODO I2C tx/rx

	return 0;
}
