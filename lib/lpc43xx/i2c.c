/*
 * This file is part of the libopencm3 project.
 *
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

/*
 * This is a very minimal I2C driver just to make sure we can get the
 * peripheral working.
 */

#include <libopencm3/lpc43xx/i2c.h>
#include <libopencm3/lpc43xx/scu.h>
#include <libopencm3/lpc43xx/cgu.h>

void i2c0_init(void)
{
	/* enable input on SCL and SDA pins */
	SCU_SFSI2C0 = SCU_I2C0_NOMINAL;

	/* use IRC as clock source for APB1 (including I2C0) */
	CGU_BASE_APB1_CLK = (CGU_SRC_IRC << CGU_BASE_CLK_SEL_SHIFT);

	/* FIXME assuming we're on IRC at 12 MHz */

	/* 400 kHz I2C */
	I2C0_SCLH = 15;
	I2C0_SCLL = 15;

	/* 100 kHz I2C */
	/*
	I2C0_SCLH = 60;
	I2C0_SCLL = 60;
	*/

	/* clear the control bits */
	I2C0_CONCLR = (I2C_CONCLR_AAC | I2C_CONCLR_SIC
			| I2C_CONCLR_STAC | I2C_CONCLR_I2ENC);

	/* enable I2C0 */
	I2C0_CONSET = I2C_CONSET_I2EN;
}

/* transmit start bit */
void i2c0_tx_start(void)
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
u8 i2c0_rx_byte(void)
{
	if (I2C0_CONSET & I2C_CONSET_STA)
		I2C0_CONCLR = I2C_CONCLR_STAC;
	I2C0_CONCLR = I2C_CONCLR_SIC;
	while (!(I2C0_CONSET & I2C_CONSET_SI));
	return I2C0_DAT;
}

/* transmit stop bit */
void i2c0_stop(void)
{
	if (I2C0_CONSET & I2C_CONSET_STA)
		I2C0_CONCLR = I2C_CONCLR_STAC;
	I2C0_CONSET = I2C_CONSET_STO;
	I2C0_CONCLR = I2C_CONCLR_SIC;
}
