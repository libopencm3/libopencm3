/** @defgroup gpio_file GPIO

@ingroup STM32F1xx

@brief <b>libopencm3 STM32F1xx General Purpose I/O</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009
Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

@date 18 August 2012

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

Example 1: Digital input on port C12

@code
	gpio_set_mode(GPIOC, GPIO_MODE_INPUT, GPIO_CNF_INPUT, GPIO12);
	reg16 = gpio_port_read(GPIOC);
@endcode

LGPL License Terms @ref lgpl_license
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
	uint16_t i;
	uint32_t crl_set = 0, crh_set = 0, crl_clear = 0, crh_clear = 0, config;

	/* return if no port pin to be setup or conf invalid or mode invalid */
	if( gpios == 0 || cnf > 0x03 || mode > 0x03 ) {
		return;
	}

	/* build pin configuration nibble in lowest 4 bit of config */
	config = cnf << 2 | mode;
	
	/* loop over all bits in gpios. abort if only unset bits left over */
	for( i=0; gpios != 0; i++, gpios >>=1 ) {

   		/* Only set the config if the bit is set in gpios. */
		if( gpios & 0x01 ) { 
			
			/* if current bit belongs to lower half of gpioport (bits 0..7) */
			if( i < 8 ) {
				/* write new configuration into crl_set */
				crl_set |= config << (4*i);
				/* remember bits that have to be cleared (1=clear, 0=dont change) */
				crl_clear |= 0x0f << (4*i);
			}

			/* if current bit belongs to upper half of gpioport (bits 8..15) */
			else {
				/* write new configuration into crh_set */
				crh_set |= config << (4 * (i-8));
				/* remember bits that have to be cleared (1=clear, 0=dont change) */
				crh_clear |= 0x0f << (4 * (i-8));
			}
		}
	}

	/* read old port config from mem, write back modified config */
	GPIO_CRL(gpioport) = ( GPIO_CRL(gpioport) & ~crl_clear ) | crl_set;
	GPIO_CRH(gpioport) = ( GPIO_CRH(gpioport) & ~crh_clear ) | crh_set;
}

/*---------------------------------------------------------------------------*/
/** @brief Map the EVENTOUT signal

Enable the EVENTOUT signal and select the port and pin to be used.

@param[in] evoutport Unsigned int8. Port for EVENTOUT signal @ref afio_evcr_port
@param[in] evoutpin Unsigned int8. Pin for EVENTOUT signal @ref afio_evcr_pin
*/
void gpio_set_eventout(uint8_t evoutport, uint8_t evoutpin)
{
	AFIO_EVCR = AFIO_EVCR_EVOE | evoutport | evoutpin;
}

/*---------------------------------------------------------------------------*/
/** @brief Map Alternate Function Port Bits (Main Set)

A number of alternate function ports can be remapped to defined alternative
port bits to avoid clashes in cases where multiple alternate functions are
present.  Refer to the datasheets for the particular mapping desired. This
provides the main set of remap functionality. See @ref gpio_secondary_remap for
a number of lesser used remaps.

The AFIO remapping feature is used only with the STM32F10x series.

@note The Serial Wire JTAG disable controls allow certain GPIO ports to become
available in place of some of the SWJ signals. Full SWJ capability is obtained
by setting this to zero. The value of this must be specified for every call to
this function as its current value cannot be ascertained from the hardware.

@param[in] swjdisable Unsigned int8. Disable parts of the SWJ capability @ref
afio_swj_disable.
@param[in] maps Unsigned int32. Bitwise OR of map enable controls from @ref
afio_remap, @ref afio_remap_can1, @ref afio_remap_tim3, @ref afio_remap_tim2,
@ref afio_remap_tim1, @ref afio_remap_usart3. For connectivity line devices
only @ref afio_remap_cld are also available.
*/
void gpio_primary_remap(uint32_t swjdisable, uint32_t maps)
{
	AFIO_MAPR |= (swjdisable & AFIO_MAPR_SWJ_MASK) | (maps & 0x1FFFFF);
}

/*---------------------------------------------------------------------------*/
/** @brief Map Alternate Function Port Bits (Secondary Set)

A number of alternate function ports can be remapped to defined alternative
port bits to avoid clashes in cases where multiple alternate functions are
present.  Refer to the datasheets for the particular mapping desired. This
provides the second smaller and less used set of remap functionality. See @ref
gpio_primary_remap for the main set of remaps.

The AFIO remapping feature is used only with the STM32F10x series.

@param[in] maps Unsigned int32. Bitwise OR of map enable controls from @ref
afio_remap2
*/
void gpio_secondary_remap(uint32_t maps)
{
	AFIO_MAPR2 |= maps;
}

/**@}*/

