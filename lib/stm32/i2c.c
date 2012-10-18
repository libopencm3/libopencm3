/** @defgroup i2c_file I2C

@ingroup STM32F_files

@brief <b>libopencm3 STM32Fxxx I2C</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2010 Thomas Otto <tommi@viadmin.org>
@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies <ksarkies@internode.on.net>

@date 15 October 2012

Devices can have up to two I2C peripherals. The peripherals support SMBus and
PMBus variants.

A peripheral begins after reset in Slave mode. To become a Master a start
condition must be generated. The peripheral will remain in Master mode unless
a multimaster contention is lost or a stop condition is generated.

@todo all sorts of lovely stuff like DMA, Interrupts, SMBus variant, Status
register access, Error conditions

LGPL License Terms @ref lgpl_license
 */
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

/**@{*/

/*-----------------------------------------------------------------------------*/
/** @brief I2C Reset.

The I2C peripheral and all its associated configuration registers are placed in the
reset condition. The reset is effected via the RCC peripheral reset system.

@param[in] i2c Unsigned int32. I2C peripheral identifier @ref i2c_reg_base.
*/

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

/*-----------------------------------------------------------------------------*/
/** @brief I2C Peripheral Enable.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_peripheral_enable(u32 i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_PE;
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Peripheral Disable.

This must not be reset while in Master mode until a communication has finished.
In Slave mode, the peripheral is disabled only after communication has ended.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_peripheral_disable(u32 i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_PE;
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Send Start Condition.

If in Master mode this will cause a restart condition to occur at the end of the
current transmission. If in Slave mode, this will initiate a start condition
when the current bus activity is completed.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_send_start(u32 i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_START;
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Send Stop Condition.

After the current byte transfer this will initiate a stop condition if in Master
mode, or simply release the bus if in Slave mode.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_send_stop(u32 i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_STOP;
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Set the 7 bit Slave Address for the Peripheral.

This sets an address for Slave mode operation, in 7 bit form.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] slave Unsigned int8. Slave address 0...127.
*/

void i2c_set_own_7bit_slave_address(u32 i2c, u8 slave)
{
	I2C_OAR1(i2c) = (u16)(slave << 1);
	I2C_OAR1(i2c) &= ~I2C_OAR1_ADDMODE;
	I2C_OAR1(i2c) |= (1 << 14); /* Datasheet: always keep 1 by software. */
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Set the 10 bit Slave Address for the Peripheral.

This sets an address for Slave mode operation, in 10 bit form.

@todo add "I2C_OAR1(i2c) |= (1 << 14);" as above

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] slave Unsigned int16. Slave address 0...1023.
*/

void i2c_set_own_10bit_slave_address(u32 i2c, u16 slave)
{
	I2C_OAR1(i2c) = (u16)(I2C_OAR1_ADDMODE | slave);
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Set Fast Mode.

Set the clock frequency to the high clock rate mode (up to 400kHz). The actual
clock frequency must be set with @ref i2c_set_clock_frequency

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_set_fast_mode(u32 i2c)
{
	I2C_CCR(i2c) |= I2C_CCR_FS;
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Set Standard Mode.

Set the clock frequency to the standard clock rate mode (up to 100kHz). The actual
clock frequency must be set with @ref i2c_set_clock_frequency

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_set_standard_mode(u32 i2c)
{
	I2C_CCR(i2c) &= ~I2C_CCR_FS;
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Set Peripheral Clock Frequency.

Set the peripheral clock frequency: 2MHz to 36MHz (the APB frequency). Note that
this is <b> not </b> the I2C bus clock. This is set in conjunction with the Clock
Control register to generate the Master bus clock, see @ref i2c_set_ccr

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] freq Unsigned int8. Clock Frequency Setting @ref i2c_clock.
*/

void i2c_set_clock_frequency(u32 i2c, u8 freq)
{
	u16 reg16;
	reg16 = I2C_CR2(i2c) & 0xffc0; /* Clear bits [5:0]. */
	reg16 |= freq;
	I2C_CR2(i2c) = reg16;
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Set Bus Clock Frequency.

Set the bus clock frequency. This is a 12 bit number (0...4095) calculated
from the formulae given in the STM32F1 reference manual in the description
of the CCR field. It is a divisor of the peripheral clock frequency
@ref i2c_set_clock_frequency modified by the fast mode setting
@ref i2c_set_fast_mode

@todo provide additional API assitance to set the clock, eg macros

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] freq Unsigned int16. Bus Clock Frequency Setting 0...4095.
*/

void i2c_set_ccr(u32 i2c, u16 freq)
{
	u16 reg16;
	reg16 = I2C_CCR(i2c) & 0xf000; /* Clear bits [11:0]. */
	reg16 |= freq;
	I2C_CCR(i2c) = reg16;
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Set the Rise Time.

Set the maximum rise time on the bus according to the I2C specification, as 1
more than the specified rise time in peripheral clock cycles. This is a 6 bit
number.

@todo provide additional APIP assistance.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] trise Unsigned int16. Rise Time Setting 0...63.
*/

void i2c_set_trise(u32 i2c, u16 trise)
{
	I2C_TRISE(i2c) = trise;
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Send the 7-bit Slave Address.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] slave Unsigned int16. Slave address 0...1023.
@param[in] readwrite Unsigned int8. Single bit to instruct slave to receive or send @ref i2c_rw.
*/

void i2c_send_7bit_address(u32 i2c, u8 slave, u8 readwrite)
{
	I2C_DR(i2c) = (u8)((slave << 1) | readwrite);
}

/*-----------------------------------------------------------------------------*/
/** @brief I2C Send Data.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] data Unsigned int8. Byte to send.
*/

void i2c_send_data(u32 i2c, u8 data)
{
	I2C_DR(i2c) = data;
}

/**@}*/

