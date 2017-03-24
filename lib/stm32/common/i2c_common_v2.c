/** @addtogroup i2c_file
 *
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
}

/*---------------------------------------------------------------------------*/
/** @brief I2C Set the 10 bit Slave Address for the Peripheral.
 *
 * This sets an address for Slave mode operation, in 10 bit form.
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

bool i2c_is_start(uint32_t i2c)
{
	return (I2C_CR2(i2c) & I2C_CR2_START);
}

void i2c_enable_autoend(uint32_t i2c)
{
	I2C_CR2(i2c) |= I2C_CR2_AUTOEND;
}

void i2c_disable_autoend(uint32_t i2c)
{
	I2C_CR2(i2c) &= ~I2C_CR2_AUTOEND;
}

bool i2c_nack(uint32_t i2c)
{
	return (I2C_ISR(i2c) & I2C_ISR_NACKF);
}

bool i2c_busy(uint32_t i2c)
{
	return (I2C_ISR(i2c) & I2C_ISR_BUSY);
}

bool i2c_transmit_int_status(uint32_t i2c)
{
	return (I2C_ISR(i2c) & I2C_ISR_TXIS);
}

bool i2c_transfer_complete(uint32_t i2c)
{
	return (I2C_ISR(i2c) & I2C_ISR_TC);
}

bool i2c_received_data(uint32_t i2c)
{
	return (I2C_ISR(i2c) & I2C_ISR_RXNE);
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

void i2c_set_speed(uint32_t p, enum i2c_speeds speed, uint32_t clock_megahz)
{
	int prescaler;
	switch(speed) {
	case i2c_speed_fmp_1m:
		/* FIXME - add support for this mode! */
		break;
	case i2c_speed_fm_400k:
		/* target 8Mhz input, so tpresc = 125ns */
		prescaler = clock_megahz / 8 - 1;
		i2c_set_prescaler(p, prescaler);
		i2c_set_scl_low_period(p, 0x9); // 1250ns
		i2c_set_scl_high_period(p, 3); // 500ns
		i2c_set_data_hold_time(p, 2); // 250ns
		i2c_set_data_setup_time(p, 2); // 375ns
		break;
	default:
		/* fall back to standard mode */
	case i2c_speed_sm_100k:
		/* target 2Mhz input, so tpresc = 500ns */
		prescaler = clock_megahz / 4 - 1;
		i2c_set_prescaler(p, prescaler);
		i2c_set_scl_low_period(p, 0xf); // 5usecs
		i2c_set_scl_high_period(p, 0x13); // 4usecs
		i2c_set_data_hold_time(p, 2); // 0.5usecs
		i2c_set_data_setup_time(p, 4); // 1.25usecs
		break;
	}
}

void i2c_transfer7(uint32_t i2c, uint8_t addr, uint8_t *w, size_t wn, uint8_t *r, size_t rn)
{
	/*  waiting for busy is unnecessary. read the RM */
	if (wn) {
		i2c_set_7bit_address(i2c, addr);
		i2c_set_write_transfer_dir(i2c);
		i2c_set_bytes_to_transfer(i2c, wn);
		if (rn) {
			i2c_disable_autoend(i2c);
		} else {
			i2c_enable_autoend(i2c);
		}
		i2c_send_start(i2c);

		while (wn--) {
			bool wait = true;
			while (wait) {
				if (i2c_transmit_int_status(i2c)) {
					wait = false;
				}
				while (i2c_nack(i2c)); /* FIXME Some error */
			}
			i2c_send_data(i2c, *w++);
		}
		/* not entirely sure this is really necessary.
		 * RM implies it will stall until it can write out the later bits
		 */
		if (rn) {
			while (!i2c_transfer_complete(i2c));
		}
	}

	if (rn) {
		/* Setting transfer properties */
		i2c_set_7bit_address(i2c, addr);
		i2c_set_read_transfer_dir(i2c);
		i2c_set_bytes_to_transfer(i2c, rn);
		/* start transfer */
		i2c_send_start(i2c);
		/* important to do it afterwards to do a proper repeated start! */
		i2c_enable_autoend(i2c);

		for (size_t i = 0; i < rn; i++) {
			while (i2c_received_data(i2c) == 0);
			r[i] = i2c_get_data(i2c);
		}
	}
}


/**@}*/
