/** @defgroup VF6xx_gpio GPIO
 *
 * @ingroup VF6xx
 *
 * @section vf6xx_gpio_api_ex GPIO API.
 *
 * @brief <b>VF6xx General-Purpose Input/Output (GPIO)</b>
 *
 * @author @htmlonly &copy; @endhtmlonly 2014 Stefan Agner <stefan@agner.ch>
 *
 * @date 03 July 2014
 *
 * This library supports the GPIO module in the VF6xx SoC of Freescale.
 * Access is provided by GPIO number according to the Pinmux list of the
 * Reference Manual, similar as GPIOs are available on Linux.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

/**@{*/

#include <libopencm3/vf6xx/gpio.h>
#include <libopencm3/vf6xx/ccm.h>

/*---------------------------------------------------------------------------*/
/** @brief Set GPIO

Set GPIO by GPIO number according to MUX list

@param[in] gpio unsigned 32 bit. GPIO number
*/

void gpio_set(uint32_t gpio)
{
	uint32_t port = GPIO(gpio / 32);
	GPIO_PSOR(port) = GPIO_OFFSET(gpio);
}

/*---------------------------------------------------------------------------*/
/** @brief Set GPIO

Clears GPIO by GPIO number according to MUX list

@param[in] gpio unsigned 32 bit. GPIO number
*/

void gpio_clear(uint32_t gpio)
{
	uint32_t port = GPIO(gpio / 32);
	GPIO_PCOR(port) = GPIO_OFFSET(gpio);
}

/*---------------------------------------------------------------------------*/
/** @brief Get GPIOs logic state

Get logic level of GPIO given by GPIO number according to MUX list. Reading
a GPIO value is possible even if the port is not muxed for GPIO.

@param[in] gpio unsigned 32 bit. GPIO number
@returns the logic state of the given GPIO.
*/

bool gpio_get(uint32_t gpio)
{
	uint32_t port = GPIO(gpio / 32);
	return !!(GPIO_PDIR(port) & GPIO_OFFSET(gpio));
}

/*---------------------------------------------------------------------------*/
/** @brief Toggles GPIO

Toggles GPIO by GPIO number according to MUX list

@param[in] gpio unsigned 32 bit. GPIO number
*/

void gpio_toggle(uint32_t gpio)
{
	uint32_t port = GPIO(gpio / 32);
	GPIO_PTOR(port) = GPIO_OFFSET(gpio);
}

/*---------------------------------------------------------------------------*/
/** @brief Read a whole GPIO Port

Gets all 32 GPIOs of a Port.

@param[in] gpioport unsigned 32 bit. GPIO port @ref gpio_reg_base
@returns the logic states of the given GPIO port.
*/

uint32_t gpio_port_read(uint32_t gpioport)
{
	return GPIO_PDIR(gpioport);
}

/*---------------------------------------------------------------------------*/
/** @brief Write a whole GPIO Port

Sets all 32 GPIOs of a Port.

@param[in] gpioport unsigned 32 bit. GPIO port @ref gpio_reg_base
@param[in] gpio unsigned 32 bit. 1 for a logic 1 driven at port, 0 for a logic
0 driven at port.
*/

void gpio_port_write(uint32_t gpioport, uint32_t data)
{
	GPIO_PDOR(gpioport) = data;
}

/**@}*/

