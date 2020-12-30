/** @addtogroup i2c_file I2C peripheral API
 * @ingroup peripheral_apis

@author @htmlonly &copy; @endhtmlonly 2010
Thomas Otto <tommi@viadmin.org>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

Devices can have up to three I2C peripherals. The peripherals support SMBus and
PMBus variants.

A peripheral begins after reset in Slave mode. To become a Master a start
condition must be generated. The peripheral will remain in Master mode unless
a multimaster contention is lost or a stop condition is generated.

@todo all sorts of lovely stuff like DMA, Interrupts, SMBus variant, Status
register access, Error conditions

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
#include <libopencm3/stm32/rcc.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief I2C Reset.

The I2C peripheral and all its associated configuration registers are placed in
the reset condition. The reset is effected via the RCC peripheral reset system.

@param[in] i2c Unsigned int32. I2C peripheral identifier @ref i2c_reg_base.
*/

void i2c_reset(uint32_t i2c)
{
	switch (i2c) {
	case I2C1:
		rcc_periph_reset_pulse(RST_I2C1);
		break;
#if defined(I2C2_BASE)
	case I2C2:
		rcc_periph_reset_pulse(RST_I2C2);
		break;
#endif
#if defined(I2C3_BASE)
	case I2C3:
		rcc_periph_reset_pulse(RST_I2C3);
		break;
#endif
#if defined(I2C4_BASE)
	case I2C4:
		rcc_periph_reset_pulse(RST_I2C4);
		break;
#endif
	default:
		break;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Peripheral Enable.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_peripheral_enable(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_PE;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Peripheral Disable.

This must not be reset while in Master mode until a communication has finished.
In Slave mode, the peripheral is disabled only after communication has ended.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_peripheral_disable(uint32_t i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_PE;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Send Start Condition.

If in Master mode this will cause a restart condition to occur at the end of the
current transmission. If in Slave mode, this will initiate a start condition
when the current bus activity is completed.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_send_start(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_START;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Send Stop Condition.

After the current byte transfer this will initiate a stop condition if in Master
mode, or simply release the bus if in Slave mode.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_send_stop(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_STOP;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Clear Stop Flag.

Clear the "Send Stop" flag in the I2C config register

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
void i2c_clear_stop(uint32_t i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_STOP;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set the 7 bit Slave Address for the Peripheral.

This sets an address for Slave mode operation, in 7 bit form.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] slave Unsigned int8. Slave address 0...127.
*/

void i2c_set_own_7bit_slave_address(uint32_t i2c, uint8_t slave)
{
	uint16_t val = (uint16_t)(slave << 1);
	/* Datasheet: always keep 1 by software. */
	val |= (1 << 14);
	I2C_OAR1(i2c) = val;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set the 10 bit Slave Address for the Peripheral.

This sets an address for Slave mode operation, in 10 bit form.

@todo add "I2C_OAR1(i2c) |= (1 << 14);" as above

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] slave Unsigned int16. Slave address 0...1023.
*/

void i2c_set_own_10bit_slave_address(uint32_t i2c, uint16_t slave)
{
	I2C_OAR1(i2c) = (uint16_t)(I2C_OAR1_ADDMODE | slave);
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set the secondary 7 bit Slave Address for the Peripheral.

This sets a secondary address for Slave mode operation, in 7 bit form.


@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] slave Unsigned int8. Slave address 0...127.
*/

void i2c_set_own_7bit_slave_address_two(uint32_t i2c, uint8_t slave)
{
	uint16_t val = (uint16_t)(slave << 1);
	I2C_OAR2(i2c) = val;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Enable dual addressing mode for the Peripheral.

Both OAR1 and OAR2 are recognised in 7-bit addressing mode.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_enable_dual_addressing_mode(uint32_t i2c)
{
	I2C_OAR2(i2c) |= I2C_OAR2_ENDUAL;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Disable dual addressing mode for the Peripheral.

Only OAR1 is recognised in 7-bit addressing mode.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_disable_dual_addressing_mode(uint32_t i2c)
{
	I2C_OAR2(i2c) &= ~(I2C_OAR2_ENDUAL);
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set Peripheral Clock Frequency.

Set the peripheral clock frequency: 2MHz to 36MHz (the APB frequency). Note
that this is <b> not </b> the I2C bus clock. This is set in conjunction with
the Clock Control register to generate the Master bus clock, see @ref
i2c_set_ccr

@param[in] i2c I2C register base address @ref i2c_reg_base
@param[in] freq Clock Frequency Setting in MHz, valid range depends on part,+
  normally 2Mhz->Max APB speed.
*/

void i2c_set_clock_frequency(uint32_t i2c, uint8_t freq)
{
	uint16_t reg16;
	reg16 = I2C_CR2(i2c) & 0xffc0; /* Clear bits [5:0]. */
	reg16 |= freq;
	I2C_CR2(i2c) = reg16;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Send Data.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] data Unsigned int8. Byte to send.
*/

void i2c_send_data(uint32_t i2c, uint8_t data)
{
	I2C_DR(i2c) = data;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set Fast Mode.

Set the clock frequency to the high clock rate mode (up to 400kHz). The actual
clock frequency must be set with @ref i2c_set_clock_frequency

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_set_fast_mode(uint32_t i2c)
{
	I2C_CCR(i2c) |= I2C_CCR_FS;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set Standard Mode.

Set the clock frequency to the standard clock rate mode (up to 100kHz). The
actual clock frequency must be set with @ref i2c_set_clock_frequency

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/

void i2c_set_standard_mode(uint32_t i2c)
{
	I2C_CCR(i2c) &= ~I2C_CCR_FS;
}

/*---------------------------------------------------------------------------*/
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

void i2c_set_ccr(uint32_t i2c, uint16_t freq)
{
	uint16_t reg16;
	reg16 = I2C_CCR(i2c) & 0xf000; /* Clear bits [11:0]. */
	reg16 |= freq;
	I2C_CCR(i2c) = reg16;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set the Rise Time.

Set the maximum rise time on the bus according to the I2C specification, as 1
more than the specified rise time in peripheral clock cycles. This is a 6 bit
number.

@todo provide additional APIP assistance.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] trise Unsigned int16. Rise Time Setting 0...63.
*/

void i2c_set_trise(uint32_t i2c, uint16_t trise)
{
	I2C_TRISE(i2c) = trise;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Send the 7-bit Slave Address.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] slave Unsigned int16. Slave address 0...1023.
@param[in] readwrite Unsigned int8. Single bit to instruct slave to receive or
send @ref i2c_rw.
*/

void i2c_send_7bit_address(uint32_t i2c, uint8_t slave, uint8_t readwrite)
{
	I2C_DR(i2c) = (uint8_t)((slave << 1) | readwrite);
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Get Data.

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
uint8_t i2c_get_data(uint32_t i2c)
{
	return I2C_DR(i2c) & 0xff;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Enable Interrupt

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] interrupt Unsigned int32. Interrupt to enable.
*/
void i2c_enable_interrupt(uint32_t i2c, uint32_t interrupt)
{
	I2C_CR2(i2c) |= interrupt;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Disable Interrupt

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] interrupt Unsigned int32. Interrupt to disable.
*/
void i2c_disable_interrupt(uint32_t i2c, uint32_t interrupt)
{
	I2C_CR2(i2c) &= ~interrupt;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Enable ACK

Enables acking of own 7/10 bit address
@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
void i2c_enable_ack(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_ACK;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Disable ACK

Disables acking of own 7/10 bit address
@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
void i2c_disable_ack(uint32_t i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_ACK;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C NACK Next Byte

Causes the I2C controller to NACK the reception of the next byte
@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
void i2c_nack_next(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_POS;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C NACK Next Byte

Causes the I2C controller to NACK the reception of the current byte

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
void i2c_nack_current(uint32_t i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_POS;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set clock duty cycle

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
@param[in] dutycycle Unsigned int32. I2C duty cycle @ref i2c_duty_cycle.
*/
void i2c_set_dutycycle(uint32_t i2c, uint32_t dutycycle)
{
	if (dutycycle == I2C_CCR_DUTY_DIV2) {
		I2C_CCR(i2c) &= ~I2C_CCR_DUTY;
	} else {
		I2C_CCR(i2c) |= I2C_CCR_DUTY;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Enable DMA

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
void i2c_enable_dma(uint32_t i2c)
{
	I2C_CR2(i2c) |= I2C_CR2_DMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Disable DMA

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
void i2c_disable_dma(uint32_t i2c)
{
	I2C_CR2(i2c) &= ~I2C_CR2_DMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set DMA last transfer

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
void i2c_set_dma_last_transfer(uint32_t i2c)
{
	I2C_CR2(i2c) |= I2C_CR2_LAST;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Clear DMA last transfer

@param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
*/
void i2c_clear_dma_last_transfer(uint32_t i2c)
{
	I2C_CR2(i2c) &= ~I2C_CR2_LAST;
}

static void i2c_write7_v1(uint32_t i2c, int addr, const uint8_t *data, size_t n)
{
	while ((I2C_SR2(i2c) & I2C_SR2_BUSY)) {
	}

	i2c_send_start(i2c);

	/* Wait for the end of the start condition, master mode selected, and BUSY bit set */
	while ( !( (I2C_SR1(i2c) & I2C_SR1_SB)
		&& (I2C_SR2(i2c) & I2C_SR2_MSL)
		&& (I2C_SR2(i2c) & I2C_SR2_BUSY) ));

	i2c_send_7bit_address(i2c, addr, I2C_WRITE);

	/* Waiting for address is transferred. */
	while (!(I2C_SR1(i2c) & I2C_SR1_ADDR));

	/* Clearing ADDR condition sequence. */
	(void)I2C_SR2(i2c);

	for (size_t i = 0; i < n; i++) {
		i2c_send_data(i2c, data[i]);
		while (!(I2C_SR1(i2c) & (I2C_SR1_BTF)));
	}
}

static void i2c_read7_v1(uint32_t i2c, int addr, uint8_t *res, size_t n)
{
	i2c_send_start(i2c);
	i2c_enable_ack(i2c);

	/* Wait for the end of the start condition, master mode selected, and BUSY bit set */
	while ( !( (I2C_SR1(i2c) & I2C_SR1_SB)
		&& (I2C_SR2(i2c) & I2C_SR2_MSL)
		&& (I2C_SR2(i2c) & I2C_SR2_BUSY) ));

	i2c_send_7bit_address(i2c, addr, I2C_READ);

	/* Waiting for address is transferred. */
	while (!(I2C_SR1(i2c) & I2C_SR1_ADDR));
	/* Clearing ADDR condition sequence. */
	(void)I2C_SR2(i2c);

	for (size_t i = 0; i < n; ++i) {
		if (i == n - 1) {
			i2c_disable_ack(i2c);
		}
		while (!(I2C_SR1(i2c) & I2C_SR1_RxNE));
		res[i] = i2c_get_data(i2c);
	}
	i2c_send_stop(i2c);

	return;
}

/**
 * Run a write/read transaction to a given 7bit i2c address
 * If both write & read are provided, the read will use repeated start.
 * Both write and read are optional
 * There are likely still issues with repeated start/stop condtions!
 * @param i2c peripheral of choice, eg I2C1
 * @param addr 7 bit i2c device address
 * @param w buffer of data to write
 * @param wn length of w
 * @param r destination buffer to read into
 * @param rn number of bytes to read (r should be at least this long)
 */
void i2c_transfer7(uint32_t i2c, uint8_t addr, const uint8_t *w, size_t wn, uint8_t *r, size_t rn) {
	if (wn) {
		i2c_write7_v1(i2c, addr, w, wn);
	}
	if (rn) {
		i2c_read7_v1(i2c, addr, r, rn);
	} else {
		i2c_send_stop(i2c);
	}
}

/**
 * Set the i2c communication speed.
 * @param i2c peripheral, eg I2C1
 * @param speed one of the listed speed modes @ref i2c_speeds
 * @param clock_megahz i2c peripheral clock speed in MHz. Usually, rcc_apb1_frequency / 1e6
 */
void i2c_set_speed(uint32_t i2c, enum i2c_speeds speed, uint32_t clock_megahz)
{
	i2c_set_clock_frequency(i2c, clock_megahz);
	switch(speed) {
	case i2c_speed_fm_400k:
		i2c_set_fast_mode(i2c);
		i2c_set_ccr(i2c, clock_megahz * 5 / 6);
		i2c_set_trise(i2c, clock_megahz + 1);
		break;
	default:
		/* fall back to standard mode */
	case i2c_speed_sm_100k:
		i2c_set_standard_mode(i2c);
		/* x Mhz / (100kHz * 2) */
		i2c_set_ccr(i2c, clock_megahz * 5);
		/* Sm mode, (100kHz) freqMhz + 1 */
		i2c_set_trise(i2c, clock_megahz + 1);
		break;
	}
}


/**@}*/
