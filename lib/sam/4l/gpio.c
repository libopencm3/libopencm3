/** @addtogroup gpio_defines
 *
 * @brief <b>Access functions for the SAM4 I/O Controller</b>
 * @ingroup SAM4_defines
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2016
 * Maxim Sloyko <maxims@google.com>
 *
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2014 Felix Held <felix-libopencm3@felixheld.de>
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

#include <libopencm3/sam/gpio.h>

/** @brief Atomic set output
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_set(uint32_t gpioport, uint32_t gpios)
{
	GPIO_OVRS(gpioport) = gpios;
}

/** @brief Atomic clear output
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_clear(uint32_t gpioport, uint32_t gpios)
{
	GPIO_OVRC(gpioport) = gpios;
}

/** @brief Atomic toggle output
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_toggle(uint32_t gpioport, uint32_t gpios)
{
	GPIO_OVRT(gpioport) = gpios;
}

/** @brief Enable output pins.
 *
 * Onlyc the ones where bits are set to "1" are touched, everything else
 * remains in the old state.
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 * @param[in] mode enum gpio_mode GPIO mode. IN, OUT or peripheral function.
 */
void gpio_enable(uint32_t gpioport, uint32_t gpios, enum gpio_mode mode)
{
	if (mode < GPIO_MODE_IN) {
		GPIO_GPERC(gpioport) = gpios;
		uint8_t i = 0;
		for (; i < 3; ++i, mode >>= 1) {
			GPIO_PMR_SETVAL(gpioport, i, mode & 1) = gpios;
		}
	} else if (mode == GPIO_MODE_OUT) {
		GPIO_GPERS(gpioport) = gpios;
		GPIO_ODERS(gpioport) = gpios;
	} else if (mode == GPIO_MODE_IN) {
		GPIO_GPERS(gpioport) = gpios;
		GPIO_ODERC(gpioport) = gpios;
	}
}

/** @brief Disable output pins.
 *
 * Onlyc the ones where bits are set to "1" are touched, everything else
 * remains in the old state.
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_disable(uint32_t gpioport, uint32_t gpios)
{
	GPIO_GPERC(gpioport) = gpios;
}
