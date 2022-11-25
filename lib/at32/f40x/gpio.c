/** @addtogroup gpio_file

@brief <b>libopencm3 AT32F40x General Purpose I/O</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>
@author @htmlonly &copy; @endhtmlonly 2022
Sergey Bolshakov <beefdeadbeef@gmail.com>

@date 19 November 2022

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

Example 1: Push-pull digital output actions on ports C2 and C9

@code
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
		      GPIO_CNF_OUTPUT_PUSHPULL,  GPIO2 | GPIO9);
	gpio_set(GPIOC, GPIO2 | GPIO9);
	gpio_clear(GPIOC, GPIO2);
	gpio_toggle(GPIOC, GPIO2 | GPIO9);
	gpio_port_write(GPIOC, 0x204);
@endcode

Example 2: Digital input on port C12

@code
	gpio_set_mode(GPIOC, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT, GPIO12);
	reg16 = gpio_port_read(GPIOC);
@endcode

Example 3: Select alternate pinmux for TIM2

@code
	gpio_set_mux(AFIO_GMUX_TIM2_A0_B10);
@endcode

LGPL License Terms @ref lgpl_license
*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 Ken Sarkies <ksarkies@internode.on.net>
 * Copyright (C) 2022 Sergey Bolshakov <beefdeadbeef@gmail.com>
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

#include <libopencm3/stm32/gpio.h>

/**@{*/

/*---------------------------------------------------------------------------*/
/** @brief Set GPIO Pin Mode

Sets the mode (input/output) and configuration (analog/digitial and
open drain/push pull), for a set of GPIO pins on a given GPIO port.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] mode Unsigned int8. Pin mode @ref gpio_mode
@param[in] cnf Unsigned int8. Pin configuration @ref gpio_cnf
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be set, use bitwise OR '|' to separate
	     them.
*/

void gpio_set_mode(uint32_t gpioport, uint8_t mode, uint8_t cnf, uint16_t gpios)
{
	uint16_t i, offset = 0;
	uint32_t crl = 0, crh = 0, tmp32 = 0;

	/*
	 * We want to set the config only for the pins mentioned in gpios,
	 * but keeping the others, so read out the actual config first.
	 */
	crl = GPIO_CRL(gpioport);
	crh = GPIO_CRH(gpioport);

	/* Iterate over all bits, use i as the bitnumber. */
	for (i = 0; i < 16; i++) {
		/* Only set the config if the bit is set in gpios. */
		if (!((1 << i) & gpios)) {
			continue;
		}

		/* Calculate bit offset. */
		offset = (i < 8) ? (i * 4) : ((i - 8) * 4);

		/* Use tmp32 to either modify crl or crh. */
		tmp32 = (i < 8) ? crl : crh;

		/* Modify bits are needed. */
		tmp32 &= ~(0xf << offset);	/* Clear the bits first. */
		tmp32 |= (mode << offset) | (cnf << (offset + 2));

		/* Write tmp32 into crl or crh, leave the other unchanged. */
		crl = (i < 8) ? tmp32 : crl;
		crh = (i >= 8) ? tmp32 : crh;
	}

	GPIO_HDRV(gpioport) = mode == GPIO_MODE_OUTPUT_50_MHZ ?
		GPIO_HDRV(gpioport) | gpios :
		GPIO_HDRV(gpioport) & ~gpios;

	GPIO_CRL(gpioport) = crl;
	GPIO_CRH(gpioport) = crh;
}

/*---------------------------------------------------------------------------*/
/** @brief Map the EVENTOUT signal

Enable the EVENTOUT signal and select the port and pin to be used.

@param[in] evoutport Port for EVENTOUT signal @ref afio_evcr_port
@param[in] evoutpin Pin for EVENTOUT signal @ref afio_evcr_pin
*/
void gpio_set_eventout(uint8_t evoutport, uint8_t evoutpin)
{
	AFIO_EVCR = AFIO_EVCR_EVOE | evoutport | evoutpin;
}

/*---------------------------------------------------------------------------*/
/** @brief Map Alternate Function Port Bits

A number of alternate function ports can be remapped to defined alternative
port bits to avoid clashes in cases where multiple alternate functions are
present.  Refer to the datasheets for the particular mapping desired.

@param[in] mux AFIO mux from enum @ref afio_mux
*/

void gpio_set_mux(enum afio_mux mux)
{
	uint8_t offset = (mux & 0xff000000) >> 24;
	uint8_t shift = (mux & 0xff0000) >> 16;
	uint8_t mask = (mux & 0xff00) >> 8;
	uint8_t val = mux & 0xff;

	MMIO32(AFIO_BASE + offset) =
		(MMIO32(AFIO_BASE + offset) & ~(mask << shift)) |
		(val << shift);
}

/**@}*/
