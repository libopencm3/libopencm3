/** @addtogroup gpio_file

@author @htmlonly &copy; @endhtmlonly 2018 
Gerrit Maus <funk@maus.xyz>
Luong Le <novercy@live.com>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Gerrit Maus <funk@maus.xyz>
 * Copyright (C) 2018 Luong Le <novercy@live.com>
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

#include <libopencm3/nrf5/gpio.h>

/**@{*/
/*---------------------------------------------------------------------------*/
/** @brief Set a Group of Pins

Set one or more pins high

@param[in] gpios Unsigned int32. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_set(uint32_t gpios)
{
	GPIO_OUTSET = gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Clear a Group of Pins

Clear one or more pins low.

@param[in] gpios Unsigned int32. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_clear(uint32_t gpios)
{
	GPIO_OUTCLR = gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Read a Group of Pins

@param[in] gpios Unsigned int32. Pin identifiers @ref gpio_pin_id
		If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
@return Unsigned int32 value of the pin values. The bit position of the pin
	value returned corresponds to the pin number.
*/
uint32_t gpio_read(uint32_t gpios)
{
	return GPIO_IN & gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Direct a Group of Pins output

Set one or more pins as output.

@param[in] gpios Unsigned int32. Pin identifiers @ref gpio_pin_id
		If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_dir_output(uint32_t gpios)
{
	GPIO_DIRSET = gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Direct a Group of Pins input

Set one or more pins as input.

@param[in] gpios Unsigned int32. Pin identifiers @ref gpio_pin_id
		If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_dir_input(uint32_t gpios)
{
	GPIO_DIRCLR = gpios;
}

/*---------------------------------------------------------------------------*/
/** @brief Toggle a Group of Pins

Toggle one or more pins

@param[in] gpios Unsigned int32. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_toggle(uint32_t gpios)
{
	uint32_t i = GPIO_OUT;
	GPIO_OUTSET = gpios & ~i;
	GPIO_OUTCLR = gpios & i;
}

/*---------------------------------------------------------------------------*/
/** @brief Configuration of a Group of Pins

Configurate one or more pins with flexible selections:
"dir" can be set as DIR_INPUT (or 0) or DIR_OUTPUT (or 1).
"input" can be set as INPUT_CONNECT (0) or INPUT_DISCONNECT (1).
"pull" can be set as PULL_DISABLED (0), PULL_DOWN (1), or PULL_UP (3).
"drive" can be set as DRIVE_S0S1, DRIVE_H0S1, DRIVE_S0H1, DRIVE_H0H1, 
DRIVE_D0S1, DRIVE_D0H1, DRIVE_S0D1, or DRIVE_D0D1.
"sense" can be set as SENSE_DISABLED (or 0), SENSE_HIGH (2), or SENSE_LOW (3).

@param[in] pin Unsigned int32. Pin identifiers @ref gpio_pin_id
@param[in] dir Unsigned int32. Pin direction @ref gpio_pin_cnf[n]
@param[in] input Unsigned int32. Input buffer config @ref gpio_pin_cnf[n]
@param[in] pull Unsigned int32. Pull config @ref gpio_pin_cnf[n]
@param[in] drive Unsigned int32. Drive config @ref gpio_pin_cnf[n]
@param[in] sense Unsigned int32. Pin sensing mechanism @ref gpio_pin_cnf[n]
*/
void gpio_config(uint32_t pin, uint32_t dir, uint32_t input, uint32_t pull, 
			uint32_t drive, uint32_t sense)
{
	GPIO_PIN_CNF[pin] = GPIO_PIN_CNF_DIR(dir)     |
	                      GPIO_PIN_CNF_INPUT(input) |
	                      GPIO_PIN_CNF_PULL(pull)   |
	                      GPIO_PIN_CNF_DRIVE(drive) |
	                      GPIO_PIN_CNF_SENSE(sense) ;                      
}

/**@}*/
