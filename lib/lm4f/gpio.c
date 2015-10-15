/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2013 Alexandru Gagniuc <mr.nuke.me@gmail.com>
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

/** @defgroup gpio_file GPIO
 *
 *
 * @ingroup LM4Fxx
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Gareth McMullin <gareth@blacksphere.co.nz>
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Alexandru Gagniuc <mr.nuke.me@gmail.com>
 *
 * @date 16 March 2013
 *
 * LGPL License Terms @ref lgpl_license
 *
 * @brief <b>libopencm3 LM4F General Purpose I/O</b>
 *
 * The LM4F GPIO API provides functionality for accessing the GPIO pins of the
 * LM4F.
 *
 * @attention @code  An important aspect to consider is that libopencm3 uses the
 * AHB aperture for accessing the GPIO registers on the LM4F. The AHB must be
 * explicitly enabled with a call to gpio_enable_ahb_aperture() before accessing
 * any GPIO functionality.
 * @endcode
 *
 * Please see the individual GPIO modules for more details. To use the GPIO, the
 * gpio.h header needs to be included:
 * @code{.c}
 *	#include <libopencm3/lm4f/gpio.h>
 * @endcode
 */

/**@{*/

#include <libopencm3/lm4f/gpio.h>
#include <libopencm3/lm4f/systemcontrol.h>

/* Value we need to write to unlock the GPIO commit register */
#define GPIO_LOCK_UNLOCK_CODE		0x4C4F434B


/** @defgroup gpio_config GPIO pin configuration
 * @ingroup gpio_file
 *
 * \brief <b>Enabling and configuring GPIO pins</b>
 *
 * @section gpio_api_enable Enabling GPIO ports
 * @attention
 * Before accessing GPIO functionality through this API, the AHB aperture for
 * GPIO ports must be enabled via a call to @ref gpio_enable_ahb_aperture().
 * Failing to do so will cause a hard fault.
 *
 * @note
 * Once the AHB aperture is enabled, GPIO registers can no longer be accessed
 * via the APB aperture. The two apertures are mutually exclusive.
 *
 * Enabling the AHB aperture only needs to be done once. However, in order to
 * access a certain GPIO port, its clock must also be enabled. Enabling the
 * GPIO clock needs to be done for every port that will be used.
 *
 * For example, to enable GPIOA and GPIOD:
 * @code{.c}
 *	// Make sure we can access the GPIO via the AHB aperture
 *	gpio_enable_ahb_aperture();
 *	...
 *	// Enable GPIO ports A and D
 *	periph_clock_enable(RCC_GPIOA);
 *	periph_clock_enable(RCC_GPIOD);
 * @endcode
 *
 * On reset all ports are configured as digital floating inputs (no pull-up or
 * pull-down), except for special function pins.
 *
 *
 * @section gpio_api_in Configuring pins as inputs
 *
 * Configuring GPIO pins as inputs is done with @ref gpio_mode_setup(), with
 * @ref GPIO_MODE_INPUT for the mode parameter. The direction of the pull-up
 * must be specified with the same call
 *
 * For example, PA2, PA3, and PA4 as inputs, with pull-up on PA4:
 * @code{.c}
 *	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO2 | GPIO3);
 *	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, GPIO4);
 * @endcode
 *
 *
 * @section gpio_api_out Configuring pins as outputs
 *
 * Output pins have more configuration options than input pins. LM4F pins can be
 * configured as either push-pull, or open drain. The drive strength of each pin
 * can be adjusted between 2mA, 4mA, or 8mA. Slew-rate control is available when
 * the pins are configured to drive 8mA. These extra options can be specified
 * with @ref gpio_set_output_config().
 * The default is push-pull configuration with 2mA drive capability.
 *
 * @note
 * @ref gpio_set_output_config() controls different capabilities than the
 * similar sounding gpio_set_output_options() from the STM GPIO API. They are
 * intentionally named differently to prevent confusion between the two. They
 * are API incompatible.
 *
 * For example, to set PA2 to output push-pull with a drive strength of 8mA:
 * @code{.c}
 *	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO2);
 *	gpio_set_output_config(GPIOA, GPIO_OTYPE_PP, GPIO_DRIVE_8MA, GPIO2);
 * @endcode
 *
 *
 * @section gpio_api_analog Configuring pins as analog function
 *
 * Configuring GPIO pins to their analog function is done with
 * @ref gpio_mode_setup(), with @ref GPIO_MODE_ANALOG for the mode parameter.
 *
 * Suppose PD4 and PD5 are the USB pins. To enable their analog functionality
 * (USB D+ and D- in this case), use:
 * @code
 *	// Mux USB pins to their analog function
 *	gpio_mode_setup(GPIOD, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO4 | GPIO5);
 * @endcode
 *
 * @section gpio_api_alf_func Configuring pins as alternate functions
 *
 * Most pins have alternate functions associated with them. When a pin is set to
 * an alternate function, it is multiplexed to one of the dedicated hardware
 * peripheral in the chip. The alternate function mapping can be found in the
 * part's datasheet, and usually varies between arts of the same family.
 *
 * Multiplexing a pin, or group of pins to an alternate function is done with
 * @ref gpio_set_af(). Because AF0 is not used on the LM4F, passing 0 as the
 * alt_func_num parameter will disable the alternate function of the given pins.
 *
 * @code
 *	// Mux PB0 and PB1 to AF1 (UART1 TX/RX in this case)
 *	gpio_set_af(GPIOB, 1, GPIO0 | GPIO1);
 * @endcode
 *
 * @section gpio_api_sfpins Changing configuration of special function pins
 *
 * On the LM4F, the NMI and JTAG/SWD default to their alternate function. These
 * pins cannot normally be committed to GPIO usage. To enable these special
 * function pins to be used as GPIO, they must be unlocked. This may be achieved
 * via @ref gpio_unlock_commit. Once a special function pin is unlocked, its
 * settings may be altered in the usual way.
 *
 * For example, to unlock the PF0 pin (NMI on the LM4F120):
 * @code
 *	// PF0 is an NMI pin, and needs to be unlocked
 *	gpio_unlock_commit(GPIOF, GPIO0);
 *	// Now the pin can be configured
 *	gpio_mode_setup(RGB_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, btnpins);
 * @endcode
 */
/**@{*/

/**
 * \brief Enable access to GPIO registers via the AHB aperture
 *
 * All GPIO registers are accessed in libopencm3 via the AHB aperture. It
 * provides faster control over the older APB aperture. This aperture must be
 * enabled before calling any other gpio_*() function.
 *
 */
void gpio_enable_ahb_aperture(void)
{
	SYSCTL_GPIOHBCTL = 0xffffffff;
}

/**
 * \brief Configure a group of pins
 *
 * Sets the Pin direction, analog/digital mode, and pull-up configuration of
 * or a set of GPIO pins on a given GPIO port.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] mode Pin mode (@ref gpio_mode) \n
 *		   - GPIO_MODE_OUTPUT -- Configure pin as output \n
 *		   - GPIO_MODE_INPUT -- Configure pin as input \n
 *		   - GPIO_MODE_ANALOG -- Configure pin as analog function
 * @param[in] pullup Pin pullup/pulldown configuration (@ref gpio_pullup) \n
 *		     - GPIO_PUPD_NONE -- Do not pull the pin high or low \n
 *		     - GPIO_PUPD_PULLUP -- Pull the pin high \n
 *		     - GPIO_PUPD_PULLDOWN -- Pull the pin low
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together
 */
void gpio_mode_setup(uint32_t gpioport, enum gpio_mode mode,
		     enum gpio_pullup pullup, uint8_t gpios)
{
	switch (mode) {
	case GPIO_MODE_OUTPUT:
		GPIO_DIR(gpioport) |= gpios;
		GPIO_DEN(gpioport) |= gpios;
		GPIO_AMSEL(gpioport) &= ~gpios;
		break;
	case GPIO_MODE_INPUT:
		GPIO_DIR(gpioport) &= ~gpios;
		GPIO_DEN(gpioport) |= gpios;
		GPIO_AMSEL(gpioport) &= ~gpios;
		break;
	case GPIO_MODE_ANALOG:
		GPIO_DEN(gpioport) &= ~gpios;
		GPIO_AMSEL(gpioport) |= gpios;
		break;
	default:
		/* Don't do anything */
		break;
	}

	/*
	 * Setting a bit in the GPIO_PDR register clears the corresponding bit
	 * in the GPIO_PUR register, and vice-versa.
	 */
	switch (pullup) {
	case GPIO_PUPD_PULLUP:
		GPIO_PUR(gpioport) |= gpios;
		break;
	case GPIO_PUPD_PULLDOWN:
		GPIO_PDR(gpioport) |= gpios;
		break;
	case GPIO_PUPD_NONE:	/* Fall through */
	default:
		GPIO_PUR(gpioport) &= ~gpios;
		GPIO_PDR(gpioport) &= ~gpios;
		break;
	}
}

/**
 * \brief Configure output parameters of a group of pins
 *
 * Sets the output configuration and drive strength, of or a set of GPIO pins
 * for a set of GPIO pins in output mode.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] otype Output driver configuration (@ref gpio_output_type) \n
 *		    - GPIO_OTYPE_PP -- Configure pin driver as push-pull \n
 *		    - GPIO_OTYPE_OD -- Configure pin driver as open drain
 * @param[in] drive Pin drive strength (@ref gpio_drive_strength) \n
 *		    - GPIO_DRIVE_2MA -- 2mA drive \n
 *		    - GPIO_DRIVE_4MA -- 4mA drive \n
 *		    - GPIO_DRIVE_8MA -- 8mA drive \n
 *		    - GPIO_DRIVE_8MA_SLEW_CTL -- 8mA drive with slew rate
 *						 control
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together
 */
void gpio_set_output_config(uint32_t gpioport, enum gpio_output_type otype,
			     enum gpio_drive_strength drive, uint8_t gpios)
{
	if (otype == GPIO_OTYPE_OD) {
		GPIO_ODR(gpioport) |= gpios;
	} else {
		GPIO_ODR(gpioport) &= ~gpios;
	}

	/*
	 * Setting a bit in the GPIO_DRxR register clears the corresponding bit
	 * in the other GPIO_DRyR registers, and vice-versa.
	 */
	switch (drive) {
	case GPIO_DRIVE_8MA_SLEW_CTL:
		GPIO_DR8R(gpioport) |= gpios;
		GPIO_SLR(gpioport) |= gpios;
		break;
	case GPIO_DRIVE_8MA:
		GPIO_DR8R(gpioport) |= gpios;
		GPIO_SLR(gpioport) &= ~gpios;
		break;
	case GPIO_DRIVE_4MA:
		GPIO_DR4R(gpioport) |= gpios;
		break;
	case GPIO_DRIVE_2MA:	/* Fall through */
	default:
		GPIO_DR2R(gpioport) |= gpios;
		break;
	}
}

#define PCTL_AF(pin, af)		((af) << ((pin) << 2))
#define PCTL_MASK(pin)			PCTL_AF((pin), 0xf)
/**
 * \brief Multiplex group of pins to the given alternate function
 *
 * Mux the pin or group of pins to the given alternate function. Note that a
 * number of pins may be set but only with a single AF number. This is useful
 * when one or more of a peripheral's pins are assigned to the same alternate
 * function.
 *
 * Because AF0 is not used on the LM4F, passing 0 as the alt_func_num parameter
 * will disable the alternate function of the given pins.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] alt_func_num Pin alternate function number or 0 to disable the
 *			   alternate function multiplexing.
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together
 */
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint8_t gpios)
{
	uint32_t pctl32;
	uint8_t pin_mask;
	int i;

	/* Did we mean to disable the alternate function? */
	if (alt_func_num == 0) {
		GPIO_AFSEL(gpioport) &= ~gpios;
		return;
	}

	/* Enable the alternate function */
	GPIO_AFSEL(gpioport) |= gpios;
	/* Alternate functions are digital */
	GPIO_DEN(gpioport) |= gpios;

	/* Now take care of the actual multiplexing */
	pctl32 = GPIO_PCTL(gpioport);
	for (i = 0; i < 8; i++) {
		pin_mask = (1 << i);

		if (!(gpios & pin_mask)) {
			continue;
		}

		pctl32 &= ~PCTL_MASK(i);
		pctl32 |= PCTL_AF(i, (alt_func_num & 0xf));
	}

	GPIO_PCTL(gpioport) = pctl32;
}

/**
 * \brief Unlock the commit control of a special function pin
 *
 * Unlocks the commit control of the given pin or group of pins. If a pin is a
 * JTAG/SWD or NMI, the pin may then be reconfigured as a GPIO pin. If the pin
 * is not locked by default, this has no effect.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together.
 */
void gpio_unlock_commit(uint32_t gpioport, uint8_t gpios)
{
	/* Unlock the GPIO_CR register */
	GPIO_LOCK(gpioport) = GPIO_LOCK_UNLOCK_CODE;
	/* Enable committing changes */
	GPIO_CR(gpioport) |= gpios;
	/* Lock the GPIO_CR register */
	GPIO_LOCK(gpioport) = ~GPIO_LOCK_UNLOCK_CODE;
}
/**@}*/

/** @defgroup gpio_control GPIO pin control
 * @ingroup gpio_file
 *
 * \brief <b>Controlling GPIO pins</b>
 *
 * Each I/O port has 8 individually configurable bits. When reading and writing
 * data to the GPIO ports, address bits [9:2] mask the pins to be read or
 * written. This mechanism makes all GPIO port reads and writes on the LM4F
 * atomic operations. The GPIO API takes full advantage of this fact to preserve
 * the atomicity of these operations.
 *
 * Setting or clearing a group of bits can be accomplished with @ref gpio_set()
 * and @ref gpio_clear() respectively. These operation use the masking mechanism
 * described above to only affect the specified pins.
 *
 * Sometimes it is more appropriate to read or set the level of a group of pins
 * on a port, in one atomic operation. Reading the status can be accomplished
 * with @ref gpio_read(). The result is equivalent to reading all the pins, then
 * masking only the desired pins; however, the masking is done in hardware, and
 * does not require an extra hardware operation.
 *
 * Writing a group of pins can be accomplished with @ref gpio_write(). The mask
 * ('gpios' parameter) is applied in hardware, and the masked pins are not
 * affected, regardless of the value of the respective bits written to the GPIO
 * port.
 *
 * Two extra functions are provided, @ref gpio_port_read() and
 * @ref gpio_port_write(). They are functionally identical to
 * @ref gpio_read (port, GPIO_ALL) and @ref gpio_write (port, GPIO_ALL, val)
 * respectively. Hence, they are also atomic.
 *
 * GPIO pins may be toggled with @ref gpio_toggle(). This function does not
 * translate to an atomic operation.
 *
 * @note
 * The @ref gpio_toggle() operation is the only GPIO port operation which is not
 * atomic. It involves a read-modify-write cycle.
 *
 * Suppose PA0, PA1, PA2, and PA3 are to be modified without affecting the other
 * pins on port A. This is common when controlling, for example, a 4-bit bus:
 * @code{.c}
 *	// Pins 4,5,6, and 7 are unaffected, regardless of the bits in val
 *	gpio_write(GPIOA, GPIO0 | GPIO1 | GPIO2 | GPIO3, val);
 *	// Wait a bit then send the other 4 bits
 *	wait_a_bit();
 *	gpio_write(GPIOA, GPIO0 | GPIO1 | GPIO2 | GPIO3, val >> 4);
 * @endcode
 *
 * Suppose a LED is connected to PD4, and we want to flash the LED for a brief
 * period of time:
 * @code
 *	gpio_set(GPIOD, GPIO4);
 *	wait_a_bit();
 *	gpio_set(GPIOD, GPIO4);
 * @endcode
 */
/**@{*/
/**
 * \brief Toggle a Group of Pins
 *
 * Toggle one or more pins of the given GPIO port.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios Pin identifiers. @ref gpio_pin_id
 */
void gpio_toggle(uint32_t gpioport, uint8_t gpios)
{
	/* The mask makes sure we only toggle the GPIOs we want to */
	GPIO_DATA(gpioport)[gpios] ^= GPIO_ALL;
}
/**@}*/


/** @defgroup gpio_irq GPIO Interrupt control
 * @ingroup gpio_file
 *
 * \brief <b>Configuring interrupts from GPIO pins</b>
 *
 * GPIO pins can trigger interrupts on either edges or levels. The type of
 * trigger can be configured with @ref gpio_configure_int_trigger(). To have an
 * event on the given pin generate an interrupt, its interrupt source must be
 * unmasked. This can be achieved with @ref gpio_enable_interrupts(). Interrupts
 * which are no longer needed can be disabled through
 * @ref gpio_disable_interrupts().
 *
 * In order for the interrupt to generate an IRQ and a call to the interrupt
 * service routine, the interrupt for the GPIO port must be routed through the
 * NVIC with @ref nvic_enable_irq(). For this last step, the nvic.h header is
 * needed:
 * @code{.c}
 *	#include <libopencm3/lm4f/nvic.h>
 * @endcode
 *
 * Enabling an interrupt is as simple as configuring the desired trigger,
 * unmasking the desired interrupt, and routing the desired GPIO port's
 * interrupt through the NVIC.
 * @code{.c}
 *	// Trigger interrupt on each rising edge
 *	gpio_configure_trigger(GPIOF, GPIO_TRIG_EDGE_RISE, GPIO0 | GPIO4);
 *	// Unmask the interrupt on those pins
 *	gpio_enable_interrupts(GPIOF, GPIO0 | GPIO4);
 *	// Enable the interrupt in the NVIC as well
 *	nvic_enable_irq(NVIC_GPIOF_IRQ);
 * @endcode
 *
 * After interrupts are properly enabled and routed through the NVIC, when an
 * event occurs, the appropriate IRQ flag is set by hardware, and execution
 * jumps to the GPIO ISR. The ISR should query the IRQ flags to determine which
 * event caused the interrupt. For this, use @ref gpio_is_interrupt_source(),
 * with the desired GPIO flag. After one or more interrupt sources are
 * serviced, the IRQ flags must be cleared by the ISR. This can be done with
 * @ref gpio_clear_interrupt_flag().
 *
 * A typical GPIO ISR may look like the following:
 * @code{.c}
 * void gpiof_isr(void)
 * {
 *	uint8_t serviced_irqs = 0;
 *
 *	// Process individual IRQs
 *	if (gpio_is_interrupt_source(GPIOF, GPIO0)) {
 *		process_gpio0_event();
 *		serviced_irq |= GPIO0;
 *	}
 *	if (gpio_is_interrupt_source(GPIOF, GPIO4)) {
 *		process_gpio4_event();
 *		serviced_irq |= GPIO4;
 *	}
 *
 *	// Clear the interupt flag for the processed IRQs
 *	gpio_clear_interrupt_flag(GPIOF, serviced_irqs);
 * }
 * @endcode
 */
/**@{*/
/**
 * \brief Configure the interrupt trigger on the given GPIO pins
 *
 * Sets the Pin direction, analog/digital mode, and pull-up configuration of
 * or a set of GPIO pins on a given GPIO port.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] trigger Trigger configuration (@ref gpio_trigger) \n
 *		      - GPIO_TRIG_LVL_LOW -- Trigger on low level \n
 *		      - GPIO_TRIG_LVL_HIGH -- Trigger on high level \n
 *		      - GPIO_TRIG_EDGE_FALL -- Trigger on falling edges \n
 *		      - GPIO_TRIG_EDGE_RISE -- Trigger on rising edges \n
 *		      - GPIO_TRIG_EDGE_BOTH -- Trigger on all edges
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be specified
 *		    by OR'ing then together
 */
void gpio_configure_trigger(uint32_t gpioport, enum gpio_trigger trigger,
			    uint8_t gpios)
{
	switch (trigger) {
	case GPIO_TRIG_LVL_LOW:
		GPIO_IS(gpioport) |= gpios;
		GPIO_IEV(gpioport) &= ~gpios;
		break;
	case GPIO_TRIG_LVL_HIGH:
		GPIO_IS(gpioport) |= gpios;
		GPIO_IEV(gpioport) |= gpios;
		break;
	case GPIO_TRIG_EDGE_FALL:
		GPIO_IS(gpioport) &= ~gpios;
		GPIO_IBE(gpioport) &= ~gpios;
		GPIO_IEV(gpioport) &= ~gpios;
		break;
	case GPIO_TRIG_EDGE_RISE:
		GPIO_IS(gpioport) &= ~gpios;
		GPIO_IBE(gpioport) &= ~gpios;
		GPIO_IEV(gpioport) |= gpios;
		break;
	case GPIO_TRIG_EDGE_BOTH:
		GPIO_IS(gpioport) &= ~gpios;
		GPIO_IBE(gpioport) |= gpios;
		break;
	default:
		/* Don't do anything */
		break;
	}
}

/**
 * \brief Enable interrupts on specified GPIO pins
 *
 * Enable interrupts on the specified GPIO pins
 *
 * Note that the NVIC must be enabled and properly configured for the interrupt
 * to be routed to the CPU.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Pins whose interrupts to enable. Any
 *		    combination of pins may be specified by OR'ing them
 *		    together.
 */
void gpio_enable_interrupts(uint32_t gpioport, uint8_t gpios)
{
	GPIO_IM(gpioport) |= gpios;
}

/**
 * \brief Disable interrupts on specified GPIO pins
 *
 * Disable interrupts on the specified GPIO pins
 *
 * Note that the NVIC must be enabled and properly configured for the interrupt
 * to be routed to the CPU.
 *
 * @param[in] gpioport GPIO block register address base @ref gpio_reg_base
 * @param[in] gpios @ref gpio_pin_id. Pins whose interrupts to disable. Any
 *		    combination of pins may be specified by OR'ing them
 *		    together.
 */
void gpio_disable_interrupts(uint32_t gpioport, uint8_t gpios)
{
	GPIO_IM(gpioport) |= gpios;
}

/**@}*/

/**@}*/

