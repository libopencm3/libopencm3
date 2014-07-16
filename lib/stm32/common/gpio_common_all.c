/** @addtogroup gpio_file

@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#define WEAK __attribute__((weak))

#include <libopencm3/stm32/gpio.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Set a Group of Pins Atomic

Set one or more pins of the given GPIO port to 1 in an atomic operation.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use logical OR '|' to separate
	     them.
*/
void gpio_set(uint32_t gpioport, uint16_t gpios)
{
	GPIO_BSRR(gpioport) = gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear a Group of Pins Atomic

Clear one or more pins of the given GPIO port to 0 in an atomic operation.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use logical OR '|' to separate
	     them.
*/
void  gpio_clear(uint32_t gpioport, uint16_t gpios)
{
	GPIO_BSRR(gpioport) = (gpios << 16);
}

/*---------------------------------------------------------------------------*/
/** @brief Read a Group of Pins.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
	    If multiple pins are to be read, use logical OR '|' to separate
	    them.
@return Unsigned int16 value of the pin values. The bit position of the pin
	value returned corresponds to the pin number.
*/
uint16_t gpio_get(uint32_t gpioport, uint16_t gpios)
{
	return gpio_port_read(gpioport) & gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Toggle a Group of Pins

Toggle one or more pins of the given GPIO port. The toggling is not atomic, but
the non-toggled pins are not affected.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use logical OR '|' to separate
	     them.
*/
void gpio_toggle(uint32_t gpioport, uint16_t gpios)
{
	uint32_t port = GPIO_ODR(gpioport);
	GPIO_BSRR(gpioport) = ((port & gpios) << 16) | (~port & gpios);
}

/*---------------------------------------------------------------------------*/
/** @brief Read from a Port

Read the current value of the given GPIO port. Only the lower 16 bits contain
valid pin data.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@return Unsigned int16. The value held in the specified GPIO port.
*/
uint16_t gpio_port_read(uint32_t gpioport)
{
	return (uint16_t)GPIO_IDR(gpioport);
}

/*---------------------------------------------------------------------------*/
/** @brief Write to a Port

Write a value to the given GPIO port.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] data Unsigned int16. The value to be written to the GPIO port.
*/
void gpio_port_write(uint32_t gpioport, uint16_t data)
{
	GPIO_ODR(gpioport) = data;
}

/*---------------------------------------------------------------------------*/
/** @brief Lock the Configuration of a Group of Pins

The configuration of one or more pins of the given GPIO port is locked. There
is no mechanism to unlock these via software. Unlocking occurs at the next
reset.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be locked, use logical OR '|' to separate
	     them.
*/
void gpio_port_config_lock(uint32_t gpioport, uint16_t gpios)
{
	uint32_t reg32;

	/* Special "Lock Key Writing Sequence", see datasheet. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	GPIO_LCKR(gpioport) = ~GPIO_LCKK & gpios;	/* Clear LCKK. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK again. */

	/* Tell the compiler the variable is actually used. It will get
	 * optimized out anyways.
	 */
	reg32 = reg32;

	/* If (reg32 & GPIO_LCKK) is true, the lock is now active. */
}

/**@}*/

