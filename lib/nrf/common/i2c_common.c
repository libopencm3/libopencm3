/** @addtogroup i2c_file I2C peripheral API
 *
 * @brief <b>Access functions for the I2C Controller</b>
 *
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 * @author @htmlonly &copy; @endhtmlonly 2021 - 2022
 * Eduard Drusa <ventyl86(at)netkosice(dot)sk>
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2017-2018 Unicore MX project<dev(at)lists(dot)unicore-mx(dot)org>
 * Copyright (C) 2021 Eduard Drusa <ventyl86(at)netkosice(dot)sk>
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

#include <libopencm3/nrf/i2c.h>

/**@{*/

/** @brief Enable I2C peripheral
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @param[in] mode i2c @ref i2c_mode
 */
void i2c_enable(uint32_t i2c, uint32_t mode)
{
	I2C_ENABLE(i2c) = mode;
}

/** @brief Disable I2C peripheral
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 */
void i2c_disable(uint32_t i2c)
{
	I2C_ENABLE(i2c) = 0;
}

/** @brief Start I2C transmission.
 *
 * Starts STARTTX task, which generates start condition on I2C bus and
 * transmits address previously configured by @ref i2c_set_address.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block.
 */
void i2c_start_tx(uint32_t i2c)
{
	I2C_TASK_STARTTX(i2c) = 1;
}

/** @brief Start I2C reception.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block.
 */
void i2c_start_rx(uint32_t i2c)
{
	I2C_TASK_STARTRX(i2c) = 1;
}

/** @brief Signal stop on I2C line.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block.
 */
void i2c_send_stop(uint32_t i2c)
{
	I2C_TASK_STOP(i2c) = 1;
}

/** @brief Select Fast (400kHz) mode.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block.
 */
void i2c_set_fast_mode(uint32_t i2c)
{
	I2C_FREQUENCY(i2c) = I2C_FREQUENCY_400K;
}

/** @brief Select Standard (100kHz) mode.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block.
 */
void i2c_set_standard_mode(uint32_t i2c)
{
	I2C_FREQUENCY(i2c) = I2C_FREQUENCY_100K;
}

/** @brief Set I2C frequency.
 *
 * In addition to Standard (100kHz) and Fast (400kHz) modes
 * this peripheral also supports 250kHz mode.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @param[in] freq frequency constant. See @ref i2c_freq_const for details
 *	 and note that this is not actually a frequency in Hz or kHz.
 */
void i2c_set_frequency(uint32_t i2c, uint32_t freq)
{
	I2C_FREQUENCY(i2c) = freq;
}

/** @brief Write Data to TXD register to be sent.
 *
 * Writes one byte into transmission buffer. This API is only
 * available if @ref I2C_MODE_LEGACY is activated.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @param[in] data byte to send next.
 */
void i2c_send_data(uint32_t i2c, uint8_t data)
{
	I2C_TXD(i2c) = data;
}

/** @brief Read Data from RXD register.
 *
 * Reads one byte from reception buffer. This API is only
 * available if @ref I2C_MODE_LEGACY is activated.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @returns data from RXD register.
 */
uint8_t i2c_get_data(uint32_t i2c)
{
	return (uint8_t)I2C_RXD(i2c);
}

/** @brief Select GPIO pins to be used by this peripheral.
 *
 * Configures GPIO pins assigned to SCL and SDA signals. These pins are only occupied
 * by I2C peripheral whenever it is enabled using @ref i2c_enable. It is possible to
 * ignore any given signal and not map it to pin by using special value of 
 * @ref GPIO_UNCONNECTED instead of @ref gpio_pin_id values.
 *
 * This needs to be configured when no transaction is in progress.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @param[in] scl_pin GPIO pin used for SCL signal
 * @param[in] sda_pin GPIO pin used for SDA signal
 */
void i2c_select_pins(uint32_t i2c, uint32_t scl_pin, uint32_t sda_pin)
{
	if (scl_pin != GPIO_UNCONNECTED) {
		I2C_PSELSCL(i2c) = __GPIO2PIN(scl_pin);
	} else {
		I2C_PSELSCL(i2c) = scl_pin;
	}

	if (sda_pin != GPIO_UNCONNECTED) {
		I2C_PSELSDA(i2c) = __GPIO2PIN(sda_pin);
	} else {
		I2C_PSELSDA(i2c) = sda_pin;
	}
}

/** @brief Set 7bit I2C address of the device you wish to communicate with.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @param[in] addr device address (7bit).
 */
void i2c_set_address(uint32_t i2c, uint8_t addr)
{
	I2C_ADDRESS(i2c) = addr;
}

/** @brief Resume I2C transaction.
 *
 * This function is unusual, but required to implement
 * i2c exchange with this peripheral.
 *
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 */
void i2c_resume(uint32_t i2c)
{
	PERIPH_TRIGGER_TASK(I2C_TASK_RESUME(i2c));
}

/** Configure event -> task shortcuts
 *
 * Sets new shortcut configuration bitmask for I2C peripheral.
 * 
 * @param[in] i2c i2c peripheral base, see @ref i2c_block
 * @param[in] shorts @ref i2c_shorts activated 
 */
void i2c_set_shorts(uint32_t i2c, uint32_t shorts)
{
	I2C_SHORTS(i2c) = shorts;
}
/**@}*/
