/** @addtogroup gpio_file GPIO peripheral API
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
#include <libopencm3/cm3/nvic.h>

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
	ADATA |= gpios;
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
	ADATA &= ~gpios;
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
	return AEXT & gpios;
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
	uint32_t curr_status = ADATA & gpios;
	ADATA = (ADATA & (~gpios)) | (~curr_status);
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
	ADIR &= ~gpios;
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
	ADIR |= gpios;
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
		PORTA_SEL = (PORTA_SEL & (~0x3)) | (af_en ? 0x1 : 0x0);
	}
	if (gpios & GPIO1) {
		PORTA_SEL = (PORTA_SEL & (~0xc)) | (af_en ? 0x4 : 0x0);
	}
	if (gpios & GPIO2) {
		PORTA_SEL = (PORTA_SEL & (~0x30)) | (af_en ? 0x10 : 0x0);
	}
	if (gpios & GPIO7) {
		PORTA_SEL = (PORTA_SEL & (~0xc000)) | (af_en ? 0x4000 : 0x0);
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
	PORTA_PULLUP = en ? (PORTA_PULLUP | gpios) : (PORTA_PULLUP & ~gpios);
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
void gpio_input_en(uint16_t gpios, bool en)
{
	PORTA_INEN = en ? (PORTA_INEN & ~gpios) : (PORTA_INEN | gpios);
}

/*---------------------------------------------------------------------------*/
/** @brief Select the SWD function of GPIO 1/2

Enable or disable the SWD debugging port at GPIO 1/2. When SWD debugging port
is enabled, GPIO and AF of the SWD pins will be both unavailable.

@param[in] en true to enable SWD.
*/
void gpio_sel_swd(bool en)
{
	SWD_SEL = en;
}

/*---------------------------------------------------------------------------*/
/** @brief Sets the pins as external interrupts, rather than normal GPIO

Enable interrupts on the selected pins.  If you want to quickly
switch on and off interrupts, use gpio_int_mask() after calling this.

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
*/
void gpio_int_en(uint16_t gpios)
{
	for (uint8_t i = 0; 0 <= 9; ++i) {
		if (gpios & (1 << i)) {
			nvic_enable_irq(NVIC_GPIOA0_IRQ + i);
		}
	}
	INTEN_A |= gpios;
	gpio_int_mask(gpios, GPIO_UNMASKED);
}


/*---------------------------------------------------------------------------*/
/** @brief Sets bits in the interrupt mask

When interrupts are masked, it prevents them from being received, which is a
quicker way to turn on and off GPIO interrupts (after calling gpio_int_en()).

@param[in] gpios Pin identifiers @ref gpio_pin_id
	     If multiple pins are to be changed, use bitwise OR '|' to separate
	     them.
	     
@param[in] gpios Pin mask selection @ref gpio_int_masked
	     Whether to mask or unmask pins.
*/
void gpio_int_mask(uint16_t gpios, bool masked)
{
	INTMASK_A = masked ? (INTMASK_A | gpios) : (INTMASK_A & ~gpios);
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
void gpio_int_type(uint16_t gpios, bool type)
{
	INTLEVEL_A = type ? (INTLEVEL_A | gpios) : (INTLEVEL_A & ~gpios);
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
void gpio_int_pol(uint16_t gpios, bool pol)
{
	INTPOLARITY_A = pol ? (INTPOLARITY_A | gpios) : (INTPOLARITY_A & ~gpios);
}


/*---------------------------------------------------------------------------*/
/** @brief Gets the masked interrupt status

Returns the pin interrupt status masked with the mask set
in @ref gpio_int_mask().

@return The masked pin interrupt status as a bitfield. The bit position of the
        pin value returned corresponds to the pin number.
*/
uint16_t gpio_int_stat(void)
{
	return INTSTAT_A;
}


/*---------------------------------------------------------------------------*/
/** @brief Gets the raw unmasked interrupt status

Returns the raw unmasked interrupt status.

@return The unmasked pin interrupt status as a bitfield. The bit position of
        the pin value returned corresponds to the pin number.
*/
uint16_t gpio_int_raw_stat(void)
{
	return RAWINTSTAT_A;
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
	INTEOI_A |= gpios;
}

/**@}*/
