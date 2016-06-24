/** @addtogroup gpio_file

@author @htmlonly &copy; @endhtmlonly 2009
Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

Each I/O port has 16 individually configurable bits. Many I/O pins share GPIO
functionality with a number of alternate functions and must be configured to
the alternate function mode if these are to be accessed. A feature is available
to remap alternative functions to a limited set of alternative pins in the
event of a clash of requirements.

The data registers associated with each port for input and output are 32 bit
with the upper 16 bits unused. The output buffer must be written as a 32 bit
word, but individual bits may be set or reset separately in atomic operations
to avoid race conditions during interrupts. Bits may also be individually
locked to prevent accidental configuration changes. Once locked the
configuration cannot be changed until after the next reset.

Each port bit can be configured as analog or digital input, the latter can be
floating or pulled up or down. As outputs they can be configured as either
push-pull or open drain, digital I/O or alternate function, and with maximum
output speeds of 2MHz, 10MHz, or 50MHz.

On reset all ports are configured as digital floating input.

@section gpio_api_ex Basic GPIO Handling API.

Example 1: Push-pull digital output actions with pullup on ports C2 and C9

@code
	gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT,
			GPIO_PUPD_PULLUP,  GPIO2 | GPIO9);
	gpio_set_output_options(GPIOC, GPIO_OTYPE_PP,
			    GPIO_OSPEED_25MHZ,  GPIO2 | GPIO9);
	gpio_set(GPIOC, GPIO2 | GPIO9);
	gpio_clear(GPIOC, GPIO2);
	gpio_toggle(GPIOC, GPIO2 | GPIO9);
	gpio_port_write(GPIOC, 0x204);
@endcode

Example 2: Digital input on port C12 with pullup

@code
	gpio_mode_setup(GPIOC, GPIO_MODE_INPUT,
			GPIO_PUPD_PULLUP, GPIO12);
	reg16 = gpio_port_read(GPIOC);
@endcode

*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#include <libopencm3/stm32/gpio.h>

/*---------------------------------------------------------------------------*/
/** @brief Set GPIO Pin Mode

Sets the Pin Direction and Analog/Digital Mode, and Output Pin Pullup,
for a set of GPIO pins on a given GPIO port.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] mode Unsigned int8. Pin mode @ref gpio_mode
@param[in] pull_up_down Unsigned int8. Pin pullup/pulldown configuration @ref
gpio_pup
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be set, use bitwise OR '|' to separate
	     them.
*/
void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
		     uint16_t gpios)
{
	uint16_t i;
	uint32_t moder, pupd;

	/*
	 * We want to set the config only for the pins mentioned in gpios,
	 * but keeping the others, so read out the actual config first.
	 */
	moder = GPIO_MODER(gpioport);
	pupd = GPIO_PUPDR(gpioport);

	for (i = 0; i < 16; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}

		moder &= ~GPIO_MODE_MASK(i);
		moder |= GPIO_MODE(i, mode);
		pupd &= ~GPIO_PUPD_MASK(i);
		pupd |= GPIO_PUPD(i, pull_up_down);
	}

	/* Set mode and pull up/down control registers. */
	GPIO_MODER(gpioport) = moder;
	GPIO_PUPDR(gpioport) = pupd;
}

/*---------------------------------------------------------------------------*/
/** @brief Set GPIO Output Options

When the pin is set to output mode, this sets the configuration (analog/digital
and open drain/push pull) and speed, for a set of GPIO pins on a given GPIO
port.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] otype Unsigned int8. Pin output type @ref gpio_output_type
@param[in] speed Unsigned int8. Pin speed @ref gpio_speed
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be set, use bitwise OR '|' to separate
	     them.
*/
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
			     uint16_t gpios)
{
	uint16_t i;
	uint32_t ospeedr;

	if (otype == 0x1) {
		GPIO_OTYPER(gpioport) |= gpios;
	} else {
		GPIO_OTYPER(gpioport) &= ~gpios;
	}

	ospeedr = GPIO_OSPEEDR(gpioport);

	for (i = 0; i < 16; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}
		ospeedr &= ~GPIO_OSPEED_MASK(i);
		ospeedr |= GPIO_OSPEED(i, speed);
	}

	GPIO_OSPEEDR(gpioport) = ospeedr;
}

/*---------------------------------------------------------------------------*/
/** @brief Set GPIO Alternate Function Selection

Set the alternate function mapping number for each pin. Most pins have
alternate functions associated with them. When set to AF mode, a pin may be
used for one of its allocated alternate functions selected by the number given
here. To determine the number to be used for the desired function refer to the
individual datasheet for the particular device. A table is given under the Pin
Selection chapter.

Note that a number of pins may be set but only with a single AF number. In
practice this would rarely be useful as each pin is likely to require a
different number.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] alt_func_num Unsigned int8. Pin alternate function number @ref
gpio_af_num
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be set, use bitwise OR '|' to separate
	     them.
*/
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios)
{
	uint16_t i;
	uint32_t afrl, afrh;

	afrl = GPIO_AFRL(gpioport);
	afrh = GPIO_AFRH(gpioport);

	for (i = 0; i < 8; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}
		afrl &= ~GPIO_AFR_MASK(i);
		afrl |= GPIO_AFR(i, alt_func_num);
	}

	for (i = 8; i < 16; i++) {
		if (!((1 << i) & gpios)) {
			continue;
		}
		afrh &= ~GPIO_AFR_MASK(i - 8);
		afrh |= GPIO_AFR(i - 8, alt_func_num);
	}

	GPIO_AFRL(gpioport) = afrl;
	GPIO_AFRH(gpioport) = afrh;
}
/**@}*/

