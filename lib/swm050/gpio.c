/** @defgroup gpio_file GPIO peripheral API
 * @brief SWM050 GPIO API.
 * @ingroup peripheral_apis
 * LGPL License Terms @ref lgpl_license
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Icenowy Zheng <icenowy@aosc.io>
 * @author @htmlonly &copy; @endhtmlonly 2019
 * Caleb Szalacinski <contact@skiboy.net>
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
 * Copyright (C) 2019 Caleb Szalacinski <contact@skiboy.net>
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
#include <libopencm3/swm050/gpio.h>

/*---------------------------------------------------------------------------*/
/** @brief Set a Group of Pins

Set one or more pins of GPIO to 1. Please note that this chip doesn't support
atomic pin setting.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_set(uint16_t gpios)
{
	GPIO_ADATA |= gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear a Group of Pins

Set one or more pins of GPIO to 0. Please note that this chip doesn't support
atomic pin setting.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_clear(uint16_t gpios)
{
	GPIO_ADATA &= ~gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Read a Group of Pins.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	    If multiple pins are to be read, use bitwise OR '|' to separate
	    them.
@return The pin values as a bitfield. The bit position of the pin
	value returned corresponds to the pin number.
*/
uint16_t gpio_get(uint16_t gpios)
{
	return GPIO_AEXT & gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Toggle a Group of Pins

Toggle one or more pins of GPIO. The non-toggled pins are not affected.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_toggle(uint16_t gpios)
{
	uint32_t curr_status = GPIO_ADATA & gpios;
	GPIO_ADATA = (GPIO_ADATA & (~gpios)) | (~curr_status);
}

/*---------------------------------------------------------------------------*/
/** @brief Set the direction of a Group of Pins to Input

Set the direction of one or more pins of GPIO to input.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_input(uint16_t gpios)
{
	GPIO_ADIR &= ~gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Set the direction of a Group of Pins to Output

Set the direction of one or more pins of GPIO to output.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_output(uint16_t gpios)
{
	GPIO_ADIR |= gpios;
}


/*---------------------------------------------------------------------------*/
/** @brief Sets the pins as external interrupts, rather than normal GPIO

Enable interrupts on the selected pins.  If you want to quickly
switch on and off interrupts, use gpio_int_mask() after calling this.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.

@param[in] en True to enable, false to disable.
*/
void gpio_int_enable(uint16_t gpios, bool en)
{
	if (en) {
		GPIO_INTEN_A |= gpios;
	} else {
		GPIO_INTEN_A &= ~gpios;
	}
}


/*---------------------------------------------------------------------------*/
/** @brief Sets bits in the interrupt mask

When interrupts are masked, it prevents them from being received, which is a
quicker way to turn on and off GPIO interrupts (after calling gpio_int_en()).

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.

@param[in] masked Pin mask selection @ref gpio_int_masked
	     Whether to mask or unmask pins.
*/
void gpio_int_mask(uint16_t gpios, enum gpio_int_masked masked)
{
	if (masked) {
		GPIO_INTMASK_A |= gpios;
	} else {
		GPIO_INTMASK_A &= ~gpios;
	}
}


/*---------------------------------------------------------------------------*/
/** @brief Sets whether the pins are edge triggered or level triggered

Sets whether the pins are edge triggered or level triggered.  Edge-triggered
interrupt bits must be cleared by software.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.

@param[in] type Trigger Type @ref gpio_trig_type
	     Level or edge triggered
*/
void gpio_int_type(uint16_t gpios, enum gpio_trig_type type)
{
	if (type) {
		GPIO_INTLEVEL_A |= gpios;
	} else {
		GPIO_INTLEVEL_A &= ~gpios;
	}
}


/*---------------------------------------------------------------------------*/
/** @brief Sets the interrupt trigger polarity

Sets whether the interrupt is triggered by a high or low level/edge.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.

@param[in] pol Polarity @ref gpio_pol
	     High or low level/edge
*/
void gpio_int_pol(uint16_t gpios, enum gpio_pol pol)
{
	if (pol) {
		GPIO_INTPOLARITY_A |= gpios;
	} else {
		GPIO_INTPOLARITY_A &= ~gpios;
	}
}


/*---------------------------------------------------------------------------*/
/** @brief Gets the masked interrupt status

Returns the pin interrupt status masked with the mask set
in @ref gpio_int_mask().

@return The masked pin interrupt status as a bitfield. The bit position of the
	pin value returned corresponds to the pin number.
*/
uint16_t gpio_int_status(void)
{
	return GPIO_INTSTAT_A;
}


/*---------------------------------------------------------------------------*/
/** @brief Gets the raw unmasked interrupt status

Returns the raw unmasked interrupt status.

@return The unmasked pin interrupt status as a bitfield. The bit position of the
	pin value returned corresponds to the pin number.
*/
uint16_t gpio_int_raw_status(void)
{
	return GPIO_RAWINTSTAT_A;
}


/*---------------------------------------------------------------------------*/
/** @brief Clear the specified pin interrupts

Clears the specified pin interrupts. Edge-triggered interrupts must be cleared
by software.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_int_clear(uint16_t gpios)
{
	GPIO_INTEOI_A |= gpios;
}

/**@}*/
