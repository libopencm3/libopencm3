/** @defgroup syscon_file SYSCON peripheral API
 * @ingroup peripheral_apis
 * @brief SWM050 SYSCON API.
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
#include <libopencm3/swm050/syscon.h>
#include <libopencm3/swm050/gpio.h>

/*---------------------------------------------------------------------------*/
/** @brief Select the alternative function of a Group of Pins

Select the alternative function of one or more pins of GPIO.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
@param[in] af_en Whether alternative function is selected
*/
void syscon_sel_af(uint16_t gpios, bool af_en)
{
	uint32_t masked_reg32;

	if (gpios & GPIO0) {
		masked_reg32 = SYSCON_PORTA_SEL & (~0x3);
		SYSCON_PORTA_SEL = masked_reg32 | (af_en ? 0x1 : 0x0);
	}
	if (gpios & GPIO1) {
		masked_reg32 = SYSCON_PORTA_SEL & (~0xc);
		SYSCON_PORTA_SEL = masked_reg32 | (af_en ? 0x4 : 0x0);
	}
	if (gpios & GPIO2) {
		masked_reg32 = SYSCON_PORTA_SEL & (~0x30);
		SYSCON_PORTA_SEL = masked_reg32 | (af_en ? 0x10 : 0x0);
	}
	if (gpios & GPIO7) {
		masked_reg32 = SYSCON_PORTA_SEL & (~0xc000);
		SYSCON_PORTA_SEL = masked_reg32 | (af_en ? 0x4000 : 0x0);
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the internal pull-up of a Group of Pins

Enable or disable the internal pull-up of one or more pins of GPIO.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
@param[in] en True to enable pull-up, false to disable.
*/
void syscon_pullup(uint16_t gpios, bool en)
{
	if (en) {
		SYSCON_PORTA_PULLUP |= gpios;
	} else {
		SYSCON_PORTA_PULLUP &= ~gpios;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Enable the input function of a Group of Pins

Enable or disable the input function of one or more pins of GPIO. Disabling
the input function of pins decreases the power usage of the MCU.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
@param[in] en True to enable input function.
*/
void syscon_input_enable(uint16_t gpios, bool en)
{
	if (en) {
		SYSCON_PORTA_INEN &= ~gpios;
	} else {
		SYSCON_PORTA_INEN |= gpios;
	}
}

/*---------------------------------------------------------------------------*/
/** @brief Select the SWD function of GPIO 1/2

Enable or disable the SWD debugging port at GPIO 1/2. When SWD debugging port
is enabled, GPIO and AF of the SWD pins will be both unavailable.

@param[in] en True to enable SWD.
*/
void syscon_sel_swd(bool en)
{
	SYSCON_SWD_SEL = en;
}
/**@}*/
