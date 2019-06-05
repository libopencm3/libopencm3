/** @addtogroup gpio_file GPIO peripheral API
 * @ingroup peripheral_apis
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
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

#include <libopencm3/swm050/gpio.h>

/**@{*/

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
	GPIO_DATA |= gpios;
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
	GPIO_DATA &= ~gpios;
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
	return GPIO_EXT & gpios;
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
	uint32_t curr_status = GPIO_DATA & gpios;
	GPIO_DATA = (GPIO_DATA & (~gpios)) | (~curr_status);
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
	GPIO_DIR &= ~gpios;
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
	GPIO_DIR |= gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Select the alternative function of a Group of Pins

Select the alternative function of one or more pins of GPIO.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
@param[in] af_en Whether alternative function is selected
*/
void gpio_sel_af(uint16_t gpios, bool af_en)
{
	if (gpios & GPIO0) {
		GPIO_SEL = (GPIO_SEL & (~0x3)) | (af_en ? 0x1 : 0x0);
	}
	if (gpios & GPIO1) {
		GPIO_SEL = (GPIO_SEL & (~0xc)) | (af_en ? 0x4 : 0x0);
	}
	if (gpios & GPIO2) {
		GPIO_SEL = (GPIO_SEL & (~0x30)) | (af_en ? 0x10 : 0x0);
	}
	if (gpios & GPIO7) {
		GPIO_SEL = (GPIO_SEL & (~0xc000)) | (af_en ? 0x4000 : 0x0);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the internal pull-up of a Group of Pins

Enable or disable the internal pull-up of one or more pins of GPIO.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
@param[in] en Bool. Whether pull-up is enabled
*/
void gpio_pullup(uint16_t gpios, bool en)
{
	if (en) {
		GPIO_PULLUP |= gpios;
	} else {
		GPIO_PULLUP &= ~gpios;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the input function of a Group of Pins

Enable or disable the input function of one or more pins of GPIO. Disabling
the input function of pins decreases the power usage of the MCU.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
@param[in] en true to enable input function.
*/
void gpio_in_en(uint16_t gpios, bool en)
{
	if (en) {
		GPIO_INEN &= ~gpios;
	} else {
		GPIO_INEN |= gpios;
	}
}


/*---------------------------------------------------------------------------*/
/** @brief Select the SWD function of GPIO 1/2

Enable or disable the SWD debugging port at GPIO 1/2. When SWD debugging port
is enabled, GPIO and AF of the SWD pins will be both unavailable.

@param[in] en true to enable SWD.
*/
void gpio_sel_swd(bool en)
{
	if (en) {
		SWD_SEL = 1;
	} else {
		SWD_SEL = 0;
	}
}

/**@}*/
