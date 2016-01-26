/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
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

#include <libopencm3/efm32/gpio.h>

/**
 * Enable GPIO registers lock.
 * @see gpio_disable_lock()
 * @see gpio_get_lock_flag()
 */
void gpio_enable_lock(void)
{
	GPIO_LOCK = GPIO_LOCK_LOCKKEY_LOCK;
}

/**
 * Disable GPIO registers lock.
 * @see gpio_enable_lock()
 * @see gpio_get_lock_flag()
 */
void gpio_disable_lock(void)
{
	GPIO_LOCK = GPIO_LOCK_LOCKKEY_UNLOCK;
}

/**
 * Get GPIO register lock flag
 * @retval true if flag is set
 * @retval false if flag is not set
 * @see gpio_enable_lock()
 * @see gpio_disable_lock()
 */
bool gpio_get_lock_flag(void)
{
	return (GPIO_LOCK & GPIO_LOCK_LOCKKEY_MASK)
	       == GPIO_LOCK_LOCKKEY_LOCKED;
}

/**
 * Set port pins drive strength
 * @param[in] gpio_port GPIO Port (use GPIO* ex. GPIOA, GPIOB, ....)
 * @param[in] drive_stength Driver Stength (use GPIO_STENGTH_*)
 */
void gpio_set_drive_strength(uint32_t gpio_port,
			     enum gpio_drive_strength drive_stength)
{
	GPIO_P_CTRL(gpio_port) = GPIO_P_CTRL_DRIVEMODE(drive_stength);
}

/**
 * Set port pins mode
 * @param[in] gpio_port GPIO Port (use GPIO* ex. GPIOA, GPIOB, ....)
 * @param[in] mode Mode (use GPIO_MODE_*)
 * @param[in] gpios (pins mask (use GPIO* ex . GPIO0, GPIO1 .... GPIO_ALL,
 *                 use bitwise OR '|' to separate)
 */
void gpio_mode_setup(uint32_t gpio_port, enum gpio_mode mode, uint16_t gpios)
{
	unsigned i;

	uint32_t high = GPIO_P_MODEH(gpio_port);
	uint32_t low = GPIO_P_MODEL(gpio_port);

	for (i = 0; i < 8; i++) {
		if (gpios & (1 << i)) {
			low &= ~GPIO_P_MODE_MODEx_MASK(i);
			low |= GPIO_P_MODE_MODEx(i, mode);
		}

		if (gpios & (1 << (i + 8))) {
			high &= ~GPIO_P_MODE_MODEx_MASK(i);
			high |= GPIO_P_MODE_MODEx(i, mode);
		}
	}

	GPIO_P_MODEL(gpio_port) = low;
	GPIO_P_MODEH(gpio_port) = high;
}

/**
 * Set port pins output value (Atomic)
 * @param[in] gpio_port GPIO Port (use GPIO* ex. GPIOA, GPIOB, ....)
 * @param[in] gpios (pins mask (use GPIO* ex . GPIO0, GPIO1 .... GPIO_ALL,
 *                 use bitwise OR '|' to separate)
 */
void gpio_set(uint32_t gpio_port, uint16_t gpios)
{
	GPIO_P_DOUTSET(gpio_port) = gpios;
}

/**
 * Set port pins output value (Atomic)
 * @param[in] gpio_port GPIO Port (use GPIO* ex. GPIOA, GPIOB, ....)
 * @param[in] gpios (pins mask (use GPIO* ex . GPIO0, GPIO1 .... GPIO_ALL,
 *                 use bitwise OR '|' to separate)
 */
void gpio_clear(uint32_t gpio_port, uint16_t gpios)
{
	GPIO_P_DOUTCLR(gpio_port) = gpios;
}

/**
 * Get port pins input value
 * @param[in] gpio_port GPIO Port (use GPIO* ex. GPIOA, GPIOB, ....)
 * @param[in] gpios (pins mask (use GPIO* ex . GPIO0, GPIO1 .... GPIO_ALL,
 *                 use bitwise OR '|' to separate)
 * @return masked pins value (separated by bitwise OR '|')
 */
uint16_t gpio_get(uint32_t gpio_port, uint16_t gpios)
{
	return GPIO_P_DIN(gpio_port) & gpios;
}

/**
 * Toggle port pins output value (Atomic)
 * @param[in] gpio_port GPIO Port (use GPIO* ex. GPIOA, GPIOB, ....)
 * @param[in] gpios (pins mask (use GPIO* ex . GPIO0, GPIO1 .... GPIO_ALL,
 *                 use bitwise OR '|' to separate)
 */
void gpio_toggle(uint32_t gpio_port, uint16_t gpios)
{
	GPIO_P_DOUTTGL(gpio_port) = gpios;
}

/**
 * Get port (all) input value's
 * @param[in] gpio_port GPIO Port (use GPIO* ex. GPIOA, GPIOB, ....)
 * @return all pins input value
 */
uint16_t gpio_port_read(uint32_t gpio_port)
{
	return GPIO_P_DIN(gpio_port);
}

/**
 * Set port (all) output value's
 * @param[in] gpio_port GPIO Port (use GPIO* ex. GPIOA, GPIOB, ....)
 * @param[in] data Data (all pins output value)
 */
void gpio_port_write(uint32_t gpio_port, uint16_t data)
{
	GPIO_P_DOUT(gpio_port) = data;
}

/**
 * @brief Lock the Configuration of a Group of Pins
 *
 * The configuration of one or more pins of the given GPIO port is locked.
 * There is no mechanism to unlock these via software. Unlocking occurs at the
 * next reset.
 *
 * @param[in] gpio_port GPIO Port (use GPIO* ex. GPIOA, GPIOB, ....)
 * @param[in] gpios (pins mask (use GPIO* ex . GPIO0, GPIO1 .... GPIO_ALL,
 *                 use bitwise OR '|' to separate)
*/
void gpio_port_config_lock(uint32_t gpio_port, uint16_t gpios)
{
	GPIO_P_PINLOCKN(gpio_port) = ~gpios;
}
