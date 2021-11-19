/** @addtogroup gpio_file GPIO peripheral API
 *
 * @brief <b>Access functions for the I/O Controller</b>
 *
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
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

/** @{ */

#include <libopencm3/nrf/gpio.h>

/** @brief Atomic set output
 *
 * @param[in] gpioport Port identifier @ref gpio_port_id
 * @param[in] gpios Pin identifiers @ref gpio_pin_id
 */
void gpio_set(uint32_t gpioport, uint32_t gpios)
{
	(void) gpioport;
	GPIO_OUTSET = gpios;
}

/** @brief Atomic clear output
 *
 * @param[in] gpioport Port identifier @ref gpio_port_id
 * @param[in] gpios Pin identifiers @ref gpio_pin_id
 */
void gpio_clear(uint32_t gpioport, uint32_t gpios)
{
	(void) gpioport;
	GPIO_OUTCLR = gpios;
}

/** @brief Toggle output
 *
 * @param[in] gpioport Port identifier @ref gpio_port_id
 * @param[in] gpios Pin identifiers @ref gpio_pin_id
 */
void gpio_toggle(uint32_t gpioport, uint32_t gpios)
{
	(void) gpioport;
	uint32_t reg_val = GPIO_OUT;
	GPIO_OUTCLR = reg_val & gpios;
	GPIO_OUTSET = (~reg_val) & gpios;
}

/** @brief Read GPIO values
 *
 * @param[in] gpioport Port identifier @ref gpio_port_id
 * @param[in] gpios Pin identifiers @ref gpio_pin_id
 */
uint32_t gpio_get(uint32_t gpioport, uint32_t gpios)
{
	(void) gpioport;
	return GPIO_IN & gpios;
}

/** @brief Set GPIO Pin Mode
 *
 * Sets the mode (input/output) and configuration (analog/digitial and
 * open drain/push pull), for a set of GPIO pins on a given GPIO port.
 *
 * @param[in] gpioport Port identifier @ref gpio_port_id
 * @param[in] mode Pin mode @ref gpio_mode
 * @param[in] pull_up_down Pull up / pull down configuration @ref gpio_pupd
 * @param[in] gpios Pin identifiers @ref gpio_pin_id
 *	If multiple pins are to be set, use bitwise OR '|' to separate
 *	them.
 */
void gpio_mode_setup(uint32_t gpioport, uint32_t mode, uint32_t pull_up_down,
		uint32_t gpios)
{
	(void) gpioport;

	uint8_t i = 0;
	while (gpios) {
		if (gpios & 1) {
			GPIO_PIN_CNF(i) = (
					GPIO_PIN_CNF(i) &
					~((GPIO_CNF_MODE_MASK << GPIO_CNF_MODE_SHIFT)
						| (GPIO_CNF_PUPD_MASK << GPIO_CNF_PUPD_SHIFT)
					 )
				) | (mode << GPIO_CNF_MODE_SHIFT)
				| (pull_up_down << GPIO_CNF_PUPD_SHIFT);
		}
		++i;
		gpios >>= 1;
	}
}

/** Configure GPIO pin input and output specifics.
 *
 * Configure drive strength and input sensing for given GPIO port.
 * @param [in] gpioport GPIO port identifier, see @ref gpio_port_id
 * @param [in] drive Drive schema used to drive pin, see @ref gpio_drive
 * @param [in] sense Pin sensing mechanism, see @ref gpio_sense
 * @param[in] gpios Pin identifiers @ref gpio_pin_id
 *	If multiple pins are to be set, use bitwise OR '|' to separate
 *	them.
 */
void gpio_set_options(uint32_t gpioport, uint32_t drive, uint32_t sense,
		uint32_t gpios)
{
	(void) gpioport;

	uint8_t i = 0;
	while (gpios) {
		if (gpios & 1) {
			GPIO_PIN_CNF(i) = (GPIO_PIN_CNF(i) &
					~((GPIO_CNF_DRIVE_MASK << GPIO_CNF_DRIVE_SHIFT)
						| (GPIO_CNF_SENSE_MASK << GPIO_CNF_SENSE_SHIFT)
					 )
				) | (drive << GPIO_CNF_DRIVE_SHIFT)
				| (sense << GPIO_CNF_SENSE_SHIFT);
		}
		++i;
		gpios >>= 1;
	}

}


/** @brief Configure Task in GPIO TE Module
 *
 * @param[in] task_num uint8_t Task number (0-3)
 * @param[in] pin_num uint8_t GPIO Pin number (0-31)
 * @param[in] polarity uint8_t polarity Operation to perform when task is triggered.
 * @param[in] init uint8_t Initial state of the pin, non-zero means initially active,
 * zero means initially inactive
 */
void gpio_configure_task(uint8_t task_num,
		uint8_t pin_num, uint8_t polarity, uint32_t init)
{
	/* any non-zero value means, that pin is active */
	if (init) {
		init = GPIO_TE_CONFIG_OUTINIT;
	}

	GPIO_TE_CONFIG(task_num) = (GPIO_TE_MODE_TASK << GPIO_TE_CONFIG_MODE_SHIFT)
		| (pin_num << GPIO_TE_CONFIG_PSEL_SHIFT)
		| (polarity << GPIO_TE_CONFIG_POLARITY_SHIFT)
		| init;
}

/** @brief Configure Event in GPIO TE Module
 *
 * @param[in] event_num Event number (0-3)
 * @param[in] pin_num GPIO Pin number (0-31)
 * @param[in] polarity Operation to perform when task is triggered.
 */
void gpio_configure_event(uint8_t event_num, uint8_t pin_num, uint8_t polarity)
{
	GPIO_TE_CONFIG(event_num) = (GPIO_TE_MODE_EVENT << GPIO_TE_CONFIG_MODE_SHIFT)
		| (pin_num << GPIO_TE_CONFIG_PSEL_SHIFT)
		| (polarity << GPIO_TE_CONFIG_POLARITY_SHIFT);
}

/** @brief Enable GPIO interrupts
 *
 * @param[in] mask interrupts to enable.
 */
void gpio_enable_interrupts(uint32_t mask)
{
	GPIO_INTENSET = mask;
}

/** @brief Disable GPIO interrupts
 *
 * @param[in] mask interrupts to disable.
 */
void gpio_disable_interrupts(uint32_t mask)
{
	GPIO_INTENCLR = mask;
}

/** @brief Disable all GPIO interrupts
 *
 */
void gpio_clear_interrupts(void)
{
	GPIO_INTENCLR = 0xffffffff;
}

/** @} */
