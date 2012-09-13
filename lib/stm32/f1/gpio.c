/** @defgroup STM32F1xx_gpio_file GPIO

@ingroup STM32F1xx

@brief <b>libopencm3 STM32F1xx General Purpose I/O</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies <ksarkies@internode.on.net>

@date 18 August 2012

This library supports the General Purpose I/O System in the STM32F1xx series
of ARM Cortex Microcontrollers by ST Microelectronics.

Each I/O port has 16 individually configurable bits. Many I/O pins share GPIO
functionality with a number of alternate functions and must be configured to the
alternate function mode if these are to be accessed. A feature is available to
remap alternative functions to a limited set of alternative pins in the event
of a clash of requirements.

The data registers associated with each port for input and output are 32 bit with
the upper 16 bits unused. The output buffer must be written as a 32 bit word, but
individual bits may be set or reset separately in atomic operations to avoid race
conditions during interrupts. Bits may also be individually locked to prevent
accidental configuration changes. Once locked the configuration cannot be changed
until after the next reset.

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

/*
 * Basic GPIO handling API.
 *
 * Examples:
 *  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
 *                GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);
 *  gpio_set(GPIOB, GPIO4);
 *  gpio_clear(GPIOG, GPIO2 | GPIO9);
 *  gpio_get(GPIOC, GPIO1);
 *  gpio_toggle(GPIOA, GPIO7 | GPIO8);
 *  reg16 = gpio_port_read(GPIOD);
 *  gpio_port_write(GPIOF, 0xc8fe);
 *
 * TODO:
 *  - GPIO remapping support
 */
/**@{*/

#include <libopencm3/stm32/f1/gpio.h>

/*-----------------------------------------------------------------------------*/
/** @brief Set GPIO Pin Mode

Sets the mode (input/output) and configuration (analog/digitial and
open drain/push pull), for a set of GPIO pins on a given GPIO port.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] mode Unsigned int8. Pin mode @ref gpio_mode
@param[in] cnf Unsigned int8. Pin configuration @ref gpio_cnf
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
             If multiple pins are to be set, use logical OR '|' to separate them.
*/

void gpio_set_mode(u32 gpioport, u8 mode, u8 cnf, u16 gpios)
{
	u16 i, offset = 0;
	u32 crl = 0, crh = 0, tmp32 = 0;

	/*
	 * We want to set the config only for the pins mentioned in gpios,
	 * but keeping the others, so read out the actual config first.
	 */
	crl = GPIO_CRL(gpioport);
	crh = GPIO_CRH(gpioport);

	/* Iterate over all bits, use i as the bitnumber. */
	for (i = 0; i < 16; i++) {
		/* Only set the config if the bit is set in gpios. */
		if (!((1 << i) & gpios))
			continue;

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

	GPIO_CRL(gpioport) = crl;
	GPIO_CRH(gpioport) = crh;
}

/*-----------------------------------------------------------------------------*/
/** @brief Set a Group of Pins Atomic

Set one or more pins of the given GPIO port to 1 in an atomic operation.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
             If multiple pins are to be changed, use logical OR '|' to separate them.
*/
void gpio_set(u32 gpioport, u16 gpios)
{
	GPIO_BSRR(gpioport) = gpios;
}

/*-----------------------------------------------------------------------------*/
/** @brief Clear a Group of Pins Atomic

Clear one or more pins of the given GPIO port to 0 in an atomic operation.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
             If multiple pins are to be changed, use logical OR '|' to separate them.
*/
void gpio_clear(u32 gpioport, u16 gpios)
{
	GPIO_BRR(gpioport) = gpios;
}

/*-----------------------------------------------------------------------------*/
/** @brief Read a Group of Pins.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
            If multiple pins are to be read, use logical OR '|' to separate them.
@return Unsigned int16 value of the pin values. The bit position of the pin value
			returned corresponds to the pin number.
*/
u16 gpio_get(u32 gpioport, u16 gpios)
{
	return gpio_port_read(gpioport) & gpios;
}

/*-----------------------------------------------------------------------------*/
/** @brief Toggle a Group of Pins

Toggle one or more pins of the given GPIO port. This is not an atomic operation.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
             If multiple pins are to be changed, use logical OR '|' to separate them.
*/
void gpio_toggle(u32 gpioport, u16 gpios)
{
	GPIO_ODR(gpioport) ^= gpios;
}

/*-----------------------------------------------------------------------------*/
/** @brief Read from a Port

Read the current value of the given GPIO port. Only the lower 16 bits contain
valid pin data.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@return Unsigned int16. The value held in the specified GPIO port.
*/
u16 gpio_port_read(u32 gpioport)
{
	return (u16)GPIO_IDR(gpioport);
}

/*-----------------------------------------------------------------------------*/
/** @brief Write to a Port

Write a value to the given GPIO port.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] data Unsigned int16. The value to be written to the GPIO port.
*/
void gpio_port_write(u32 gpioport, u16 data)
{
	GPIO_ODR(gpioport) = data;
}

/*-----------------------------------------------------------------------------*/
/** @brief Lock the Configuration of a Group of Pins

The configuration of one or more pins of the given GPIO port is locked. There is
no mechanism to unlock these via software. Unlocking occurs at the next reset.

@param[in] gpioport Unsigned int32. Port identifier @ref gpio_port_id
@param[in] gpios Unsigned int16. Pin identifiers @ref gpio_pin_id
             If multiple pins are to be locked, use logical OR '|' to separate them.
*/
void gpio_port_config_lock(u32 gpioport, u16 gpios)
{
	u32 reg32;

	/* Special "Lock Key Writing Sequence", see datasheet. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	GPIO_LCKR(gpioport) = ~GPIO_LCKK & gpios;	/* Clear LCKK. */
	GPIO_LCKR(gpioport) = GPIO_LCKK | gpios;	/* Set LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK. */
	reg32 = GPIO_LCKR(gpioport);			/* Read LCKK again. */

	/* Tell the compiler the variable is actually used. It will get optimized out anyways. */
	reg32 = reg32; 

	/* If (reg32 & GPIO_LCKK) is true, the lock is now active. */
}

/*-----------------------------------------------------------------------------*/
/** @brief Map the EVENTOUT signal

Enable the EVENTOUT signal and select the port and pin to be used.

@param[in] evoutport Unsigned int8. Port for EVENTOUT signal @ref afio_evcr_port
@param[in] evoutpin Unsigned int8. Pin for EVENTOUT signal @ref afio_evcr_pin
*/
void gpio_set_eventout(u8 evoutport, u8 evoutpin)
{
	AFIO_EVCR = AFIO_EVCR_EVOE | evoutport | evoutpin;
}

/*-----------------------------------------------------------------------------*/
/** @brief Map Alternate Function Port Bits (Main Set)

A number of alternate function ports can be remapped to defined alternative
port bits to avoid clashes in cases where multiple alternate functions are present.
Refer to the datasheets for the particular mapping desired. This provides the main
set of remap functionality. See @ref gpio_secondary_remap for a number of lesser used
remaps.

The AFIO remapping feature is used only with the STM32F10x series.

@note The Serial Wire JTAG disable controls allow certain GPIO ports to become available
in place of some of the SWJ signals. Full SWJ capability is obtained by setting this to
zero. The value of this must be specified for every call to this function as its current
value cannot be ascertained from the hardware.

@param[in] swjdisable Unsigned int8. Disable parts of the SWJ capability @ref afio_swj_disable.
@param[in] maps Unsigned int32. Logical OR of map enable controls from @ref afio_remap,
		@ref afio_remap_can1, @ref afio_remap_tim3, @ref afio_remap_tim2, @ref afio_remap_tim1,
		@ref afio_remap_usart3. For connectivity line devices only @ref afio_remap_cld are
        also available.
*/
void gpio_primary_remap(u8 swjdisable, u32 maps)
{
	AFIO_MAPR = swjdisable | (maps & 0x1FFFFF);
}

/*-----------------------------------------------------------------------------*/
/** @brief Map Alternate Function Port Bits (Secondary Set)

A number of alternate function ports can be remapped to defined alternative
port bits to avoid clashes in cases where multiple alternate functions are present.
Refer to the datasheets for the particular mapping desired. This provides the second
smaller and less used set of remap functionality. See @ref gpio_primary_remap for
the main set of remaps.

The AFIO remapping feature is used only with the STM32F10x series.

@param[in] maps Unsigned int32. Logical OR of map enable controls from @ref afio_remap2
*/
void gpio_secondary_remap(u32 maps)
{
	AFIO_MAPR2 = maps;
}

/**@}*/

