/** @defgroup gpio_defines
 *
 * @ingroup SAMD
 *
 * @brief <b>Access functions for the SAMD I/O Controller</b>
 *
 * @date 10 April 2020
 *
 * LGPL License Terms @ref lgpl_license
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>
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

#include <libopencm3/sam/d/port.h>

/** @brief Initialize GPIO pins
 *
 * Configure a group of Pins for the given port.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] mode configuration mode @ref gpio_mode
 * @param[in] gpios Any combinaison of pins may be
 * 			specified by OR'ing then together.
 */

void gpio_mode_setup(uint32_t gpioport, enum gpio_mode mode, uint32_t gpios)
{
	uint32_t reg = PORT_WRCONFIG_WRPINCFG;
	/* enable pull */
	if (mode == GPIO_MODE_INPUT_PULLDOWN || mode == GPIO_MODE_INPUT_PULLUP)
		reg |= PORT_WRCONFIG_PULLEN;
	/* enable input buffer */
	if (mode != GPIO_MODE_OUTPUT)
		reg |= PORT_WRCONFIG_INEN;
	/* set pmuxen */
	if (mode == GPIO_MODE_AF)
		reg |= PORT_WRCONFIG_PMUXEN;

	/* PORTx_WRCONFIG allows to configure pins [31:16] or [15:0] */
	/* write low pins */
	PORT_WRCONFIG(gpioport) = reg | PORT_WRCONFIG_PINMASK(gpios);
	/* write high pins */
	PORT_WRCONFIG(gpioport) = reg | PORT_WRCONFIG_HWSEL |
		PORT_WRCONFIG_PINMASK(gpios >> 16);

	/* configure port direction for selected gpios */
	switch (mode) {
		case GPIO_MODE_INOUT:
		case GPIO_MODE_OUTPUT:
			PORT_DIRSET(gpioport) = gpios;
			break;
		case GPIO_MODE_INPUT_PULLDOWN:
		case GPIO_MODE_INPUT_PULLUP:
		case GPIO_MODE_INPUT_FLOAT:
			PORT_DIRCLR(gpioport) = gpios;
			break;
	}

	/* PULL UP/DOWN is configured through OUT */
	if (mode == GPIO_MODE_INPUT_PULLDOWN)
		PORT_OUTCLR(gpioport) = gpios;
	else if (mode == GPIO_MODE_INPUT_PULLUP)
		PORT_OUTSET(gpioport) = gpios;
}

/** @brief Alternate function GPIO pins
 *
 * Configure a group of Pins in alternate function.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] af pmux configuration @ref gpio_mux
 * @param[in] gpios Any combinaison of pins may be
 * 			specified by OR'ing then together.
 */
void gpio_set_af(uint32_t gpioport, uint8_t af, uint32_t gpios)
{
	uint32_t reg = PORT_WRCONFIG_WRPINCFG |
		PORT_WRCONFIG_WRPMUX | PORT_WRCONFIG_PMUX(af) |
		PORT_WRCONFIG_PMUXEN;

	/* write gpios[15:0] */
	PORT_WRCONFIG(gpioport) = reg | PORT_WRCONFIG_PINMASK(gpios);

	/* write gpios[31:16] */
	PORT_WRCONFIG(gpioport) = reg | PORT_WRCONFIG_HWSEL | 
		PORT_WRCONFIG_PINMASK(gpios >> 16);
}

/**@}*/
