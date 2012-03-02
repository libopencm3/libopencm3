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

#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/f4/rcc.h>

void i2c_reset(u32 i2c)
{
	switch (i2c) {
	case I2C1:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_I2C1RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_I2C1RST);
		break;
	case I2C2:
		rcc_peripheral_reset(&RCC_APB1RSTR, RCC_APB1RSTR_I2C2RST);
		rcc_peripheral_clear_reset(&RCC_APB1RSTR, RCC_APB1RSTR_I2C2RST);
		break;
	}
}

void i2c_peripheral_enable(u32 i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_PE;
}

void i2c_peripheral_disable(u32 i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_PE;
}

void i2c_send_start(u32 i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_START;
}

void i2c_send_stop(u32 i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_STOP;
}

void i2c_set_own_7bit_slave_address(u32 i2c, u8 slave)
{
	I2C_OAR1(i2c) = (u16)(slave << 1);
	I2C_OAR1(i2c) &= ~I2C_OAR1_ADDMODE;
	I2C_OAR1(i2c) |= (1 << 14); /* Datasheet: always keep 1 by software. */
}

void i2c_set_own_10bit_slave_address(u32 i2c, u16 slave)
{
	I2C_OAR1(i2c) = (u16)(I2C_OAR1_ADDMODE | slave);
}

void i2c_set_fast_mode(u32 i2c)
{
	I2C_CCR(i2c) |= I2C_CCR_FS;
}

void i2c_set_standard_mode(u32 i2c)
{
	I2C_CCR(i2c) &= ~I2C_CCR_FS;
}

void i2c_set_clock_frequency(u32 i2c, u8 freq)
{
	u16 reg16;
	reg16 = I2C_CR2(i2c) & 0xffc0; /* Clear bits [5:0]. */
	reg16 |= freq;
	I2C_CR2(i2c) = reg16;
}

void i2c_set_ccr(u32 i2c, u16 freq)
{
	u16 reg16;
	reg16 = I2C_CCR(i2c) & 0xf000; /* Clear bits [11:0]. */
	reg16 |= freq;
	I2C_CCR(i2c) = reg16;
}

void i2c_set_trise(u32 i2c, u16 trise)
{
	I2C_TRISE(i2c) = trise;
}

void i2c_send_7bit_address(u32 i2c, u8 slave, u8 readwrite)
{
	I2C_DR(i2c) = (u8)((slave << 1) | readwrite);
}

void i2c_send_data(u32 i2c, u8 data)
{
	I2C_DR(i2c) = data;
}
