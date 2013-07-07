/** @defgroup i2c_file I2C
 *
 * @ingroup STM32F3xx
 *
 * @brief <b>libopencm3 STM32F3xx I2C</b>
 *
 * @version 1.0.0
 *
 * @date 15 October 2012
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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
 *
 * The I2C peripheral and all its associated configuration registers are placed
 * in the reset condition. The reset is effected via the RCC peripheral reset
 * system.
 *
 * @param[in] i2c Unsigned int32. I2C peripheral identifier @ref i2c_reg_base.
 */

void i2c_reset(uint32_t i2c)
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

/*---------------------------------------------------------------------------*/
/** @brief I2C Peripheral Enable.
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */

void i2c_peripheral_enable(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_PE;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Peripheral Disable.
 *
 * This must not be reset while in Master mode until a communication has
 * finished. In Slave mode, the peripheral is disabled only after communication
 * has ended.
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */

void i2c_peripheral_disable(uint32_t i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_PE;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Send Start Condition.
 *
 * If in Master mode this will cause a restart condition to occur at the end of
 * the current transmission. If in Slave mode, this will initiate a start
 * condition when the current bus activity is completed.
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */

void i2c_send_start(uint32_t i2c)
{
	I2C_CR2(i2c) |= I2C_CR2_START;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Send Stop Condition.
 *
 * After the current byte transfer this will initiate a stop condition if in
 * Master mode, or simply release the bus if in Slave mode.
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */

void i2c_send_stop(uint32_t i2c)
{
	I2C_CR2(i2c) |= I2C_CR2_STOP;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Clear Stop Flag.
 *
 * Clear the "Send Stop" flag in the I2C config register
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */
void i2c_clear_stop(uint32_t i2c)
{
	I2C_ICR(i2c) |= I2C_ICR_STOPCF;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set the 7 bit Slave Address for the Peripheral.
 *
 * This sets an address for Slave mode operation, in 7 bit form.
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 * @param[in] slave Unsigned int8. Slave address 0...127.
 */

void i2c_set_own_7bit_slave_address(uint32_t i2c, uint8_t slave)
{
	I2C_OAR1(i2c) = (uint16_t)(slave << 1);
	I2C_OAR1(i2c) &= ~I2C_OAR1_OA1MODE;
	I2C_OAR1(i2c) |= (1 << 14); /* Datasheet: always keep 1 by software. */
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set the 10 bit Slave Address for the Peripheral.
 *
 * This sets an address for Slave mode operation, in 10 bit form.
 *
 * @todo add "I2C_OAR1(i2c) |= (1 << 14);" as above
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 * @param[in] slave Unsigned int16. Slave address 0...1023.
 */

void i2c_set_own_10bit_slave_address(uint32_t i2c, uint16_t slave)
{
	I2C_OAR1(i2c) = (uint16_t)(I2C_OAR1_OA1MODE | slave);
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Send Data.
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 * @param[in] data Unsigned int8. Byte to send.
 */

void i2c_send_data(uint32_t i2c, uint8_t data)
{
	I2C_TXDR(i2c) = data;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Get Data.
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */
uint8_t i2c_get_data(uint32_t i2c)
{
	return I2C_RXDR(i2c) & 0xff;
}

void i2c_enable_analog_filter(uint32_t i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_ANFOFF;
}

void i2c_disable_analog_filter(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_ANFOFF;
}

void i2c_set_digital_filter(uint32_t i2c, uint8_t dnf_setting)
{
	I2C_CR1(i2c) = (I2C_CR1(i2c) & ~I2C_CR1_DNF_MASK) | dnf_setting;
}

/* t_presc= (presc+1)*t_i2cclk */
void i2c_set_prescaler(uint32_t i2c, uint8_t presc)
{
	I2C_TIMINGR(i2c) = (I2C_TIMINGR(i2c) & ~I2C_TIMINGR_PRESC_MASK) |
			   (presc << I2C_TIMINGR_PRESC_SHIFT);
}

void i2c_set_data_setup_time(uint32_t i2c, uint8_t s_time)
{
	I2C_TIMINGR(i2c) = (I2C_TIMINGR(i2c) & ~I2C_TIMINGR_SCLDEL_MASK) |
			   (s_time << I2C_TIMINGR_SCLDEL_SHIFT);
}

void i2c_set_data_hold_time(uint32_t i2c, uint8_t h_time)
{
	I2C_TIMINGR(i2c) = (I2C_TIMINGR(i2c) & ~I2C_TIMINGR_SDADEL_MASK) |
			   (h_time << I2C_TIMINGR_SDADEL_SHIFT);
}

void i2c_set_scl_high_period(uint32_t i2c, uint8_t period)
{
	I2C_TIMINGR(i2c) = (I2C_TIMINGR(i2c) & ~I2C_TIMINGR_SCLH_MASK) |
			   (period << I2C_TIMINGR_SCLH_SHIFT);
}

void i2c_set_scl_low_period(uint32_t i2c, uint8_t period)
{
	I2C_TIMINGR(i2c) = (I2C_TIMINGR(i2c) & ~I2C_TIMINGR_SCLL_MASK) |
			   (period << I2C_TIMINGR_SCLL_SHIFT);
}

void i2c_enable_stretching(uint32_t i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_NOSTRETCH;
}

void i2c_disable_stretching(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_NOSTRETCH;
}

void i2c_100khz_i2cclk8mhz(uint32_t i2c)
{
	i2c_set_prescaler(i2c, 1);
	i2c_set_scl_low_period(i2c, 0x13);
	i2c_set_scl_high_period(i2c, 0xF);
	i2c_set_data_hold_time(i2c, 0x2);
	i2c_set_data_setup_time(i2c, 0x4);
}

void i2c_set_7bit_addr_mode(uint32_t i2c)
{
	I2C_CR2(i2c) &= ~I2C_CR2_ADD10;
}

void i2c_set_10bit_addr_mode(uint32_t i2c)
{
	I2C_CR2(i2c) |= I2C_CR2_ADD10;
}

void i2c_set_7bit_address(uint32_t i2c, uint8_t addr)
{
	I2C_CR2(i2c) = (I2C_CR2(i2c) & ~I2C_CR2_SADD_7BIT_MASK) |
		       ((addr & 0x7F) << I2C_CR2_SADD_7BIT_SHIFT);
}

void i2c_set_10bit_address(uint32_t i2c, uint16_t addr)
{
	I2C_CR2(i2c) = (I2C_CR2(i2c) & ~I2C_CR2_SADD_10BIT_MASK) |
		       ((addr & 0x3FF) << I2C_CR2_SADD_10BIT_SHIFT);
}

void i2c_set_write_transfer_dir(uint32_t i2c)
{
	I2C_CR2(i2c) &= ~I2C_CR2_RD_WRN;
}

void i2c_set_read_transfer_dir(uint32_t i2c)
{
	I2C_CR2(i2c) |= I2C_CR2_RD_WRN;
}

void i2c_set_bytes_to_transfer(uint32_t i2c, uint32_t n_bytes)
{
	I2C_CR2(i2c) = (I2C_CR2(i2c) & ~I2C_CR2_NBYTES_MASK) |
		       (n_bytes << I2C_CR2_NBYTES_SHIFT);
}

uint8_t i2c_is_start(uint32_t i2c)
{
	if ((I2C_CR2(i2c) & I2C_CR2_START) != 0) {
		return 1;
	}

	return 0;
}

void i2c_enable_autoend(uint32_t i2c)
{
	I2C_CR2(i2c) |= I2C_CR2_AUTOEND;
}

void i2c_disable_autoend(uint32_t i2c)
{
	I2C_CR2(i2c) &= ~I2C_CR2_AUTOEND;
}

uint8_t i2c_nack(uint32_t i2c)
{
	if ((I2C_ISR(i2c) & I2C_ISR_NACKF) != 0) {
		return 1;
	}

	return 0;
}

uint8_t i2c_busy(uint32_t i2c)
{
	if ((I2C_ISR(i2c) & I2C_ISR_BUSY) != 0) {
		return 1;
	}

	return 0;
}

uint8_t i2c_transmit_int_status(uint32_t i2c)
{
	if ((I2C_ISR(i2c) & I2C_ISR_TXIS) != 0) {
		return 1;
	}

	return 0;
}

uint8_t i2c_transfer_complete(uint32_t i2c)
{
	if ((I2C_ISR(i2c) & I2C_ISR_TC) != 0) {
		return 1;
	}

	return 0;
}

uint8_t i2c_received_data(uint32_t i2c)
{
	if ((I2C_ISR(i2c) & I2C_ISR_RXNE) != 0) {
		return 1;
	}

	return 0;
}


/*---------------------------------------------------------------------------*/
/** @brief I2C Enable Interrupt
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 * @param[in] interrupt Unsigned int32. Interrupt to enable.
 */
void i2c_enable_interrupt(uint32_t i2c, uint32_t interrupt)
{
	I2C_CR1(i2c) |= interrupt;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Disable Interrupt
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 * @param[in] interrupt Unsigned int32. Interrupt to disable.
 */
void i2c_disable_interrupt(uint32_t i2c, uint32_t interrupt)
{
	I2C_CR1(i2c) &= ~interrupt;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Enable reception DMA
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */
void i2c_enable_rxdma(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_RXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Disable reception DMA
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */
void i2c_disable_rxdma(uint32_t i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_RXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Enable transmission DMA
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */
void i2c_enable_txdma(uint32_t i2c)
{
	I2C_CR1(i2c) |= I2C_CR1_TXDMAEN;
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Disable transmission DMA
 *
 * @param[in] i2c Unsigned int32. I2C register base address @ref i2c_reg_base.
 */
void i2c_disable_txdma(uint32_t i2c)
{
	I2C_CR1(i2c) &= ~I2C_CR1_TXDMAEN;
}

void write_i2c(uint32_t i2c, uint8_t i2c_addr, uint8_t reg, uint8_t size,
	       uint8_t *data)
{
	int wait;
	int i;
	while (i2c_busy(i2c) == 1);
	while (i2c_is_start(i2c) == 1);
	/*Setting transfer properties*/
	i2c_set_bytes_to_transfer(i2c, size + 1);
	i2c_set_7bit_address(i2c, (i2c_addr & 0x7F));
	i2c_set_write_transfer_dir(i2c);
	i2c_enable_autoend(i2c);
	/*start transfer*/
	i2c_send_start(i2c);

	wait = true;
	while (wait) {
		if (i2c_transmit_int_status(i2c)) {
			wait = false;
		}
		while (i2c_nack(i2c));
	}

	i2c_send_data(i2c, reg);
	for (i = 0; i < size; i++) {
		wait = true;
		while (wait) {
			if (i2c_transmit_int_status(i2c)) {
				wait = false;
			}
			while (i2c_nack(i2c));
		}
		i2c_send_data(i2c, data[i]);
	}
}

void read_i2c(uint32_t i2c, uint8_t i2c_addr, uint8_t reg, uint8_t size,
	      uint8_t *data)
{
	int wait;
	int i;
	while (i2c_busy(i2c) == 1);
	while (i2c_is_start(i2c) == 1);
	/*Setting transfer properties*/
	i2c_set_bytes_to_transfer(i2c, 1);
	i2c_set_7bit_address(i2c, i2c_addr);
	i2c_set_write_transfer_dir(i2c);
	i2c_disable_autoend(i2c);
	/*start transfer*/
	i2c_send_start(i2c);

	wait = true;
	while (wait) {
		if (i2c_transmit_int_status(i2c)) {
			wait = false;
		}
		while (i2c_nack(i2c)); /* Some error */
	}
	i2c_send_data(i2c, reg);

	while (i2c_is_start(i2c) == 1);
	/*Setting transfer properties*/
	i2c_set_bytes_to_transfer(i2c, size);
	i2c_set_7bit_address(i2c, i2c_addr);
	i2c_set_read_transfer_dir(i2c);
	i2c_enable_autoend(i2c);
	/*start transfer*/
	i2c_send_start(i2c);

	for (i = 0; i < size; i++) {
		while (i2c_received_data(i2c) == 0);
		data[i] = i2c_get_data(i2c);
	}
}

/**@}*/
