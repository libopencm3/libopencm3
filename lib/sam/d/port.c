/** @addtogroup port_file IO Port API
 * @ingroup peripheral_apis
 * @brief <b>Access functions for the SAMD I/O Controller</b>
 * @date 10 April 2020
 * @copyright SPDX: LGPL-3.0-or-later
 * @author 2020 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>
 */

/**@{*/

#include <libopencm3/sam/d/port.h>

/** @brief Initialize GPIO pins
 *
 * Configure a group of Pins for the given port.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] mode direction @ref gpio_direction
 * @param[in] cnf configuration mode @ref gpio_cnf
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins
 *           may be specified by OR'ing then together.
 */
void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t cnf, uint32_t gpios)
{
	uint32_t reg = PORT_WRCONFIG_WRPINCFG;
	/* enable pull */
	if (cnf == GPIO_CNF_PULLDOWN || cnf == GPIO_CNF_PULLUP) {
		reg |= PORT_WRCONFIG_PULLEN;
	}
	/* enable input buffer */
	if (mode != GPIO_MODE_OUTPUT) {
		reg |= PORT_WRCONFIG_INEN;
	}
	/* set pmuxen */
	if (cnf == GPIO_CNF_AF) {
		reg |= PORT_WRCONFIG_PMUXEN;
	}

	/* PORTx_WRCONFIG allows to configure pins [31:16] or [15:0] */
	/* write low pins */
	PORT_WRCONFIG(gpioport) = reg | PORT_WRCONFIG_PINMASK(gpios);
	/* write high pins */
	PORT_WRCONFIG(gpioport) = reg | PORT_WRCONFIG_HWSEL |
		PORT_WRCONFIG_PINMASK(gpios >> 16);

	/* configure port direction for selected gpios */
	/* DIR is always 0 when PULL */
	if (cnf == GPIO_CNF_PULLDOWN || cnf == GPIO_CNF_PULLUP) {
		PORT_DIRCLR(gpioport) = gpios;
	} else if (mode == GPIO_MODE_INPUT) {
		PORT_DIRCLR(gpioport) = gpios;
	} else {
		PORT_DIRSET(gpioport) = gpios;
	}

	/* PULL UP/DOWN is configured through OUT */
	if (cnf == GPIO_CNF_PULLDOWN) {
		PORT_OUTCLR(gpioport) = gpios;
	} else if (cnf == GPIO_CNF_PULLUP) {
		PORT_OUTSET(gpioport) = gpios;
	}
}

/** @brief Alternate function GPIO pins
 *
 * Configure a group of Pins in alternate function.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] af pmux configuration @ref gpio_mux
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins
 *           may be specified by OR'ing then together.
 */
void gpio_set_af(uint32_t gpioport, uint8_t af, uint32_t gpios)
{
	uint32_t reg = PORT_WRCONFIG_WRPINCFG |
		PORT_WRCONFIG_WRPMUX | PORT_WRCONFIG_PMUX(af) |
		PORT_WRCONFIG_PMUXEN;

	/* write gpios[15:0] */
	PORT_WRCONFIG(gpioport) = reg | PORT_WRCONFIG_PINMASK(gpios);

	/* write gpios[31:16] */
	PORT_WRCONFIG(gpioport) = reg | PORT_WRCONFIG_HWSEL | 
		PORT_WRCONFIG_PINMASK(gpios >> 16);
}

/** @brief Set a group of Pins
 *
 * Set a group of Pins for the given port.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be
 *          specified by OR'ing then together.
 */
void gpio_set(uint32_t gpioport, uint32_t gpios)
{
	PORT_OUTSET(gpioport) = gpios;
}

/** @brief Clear a group of Pins
 *
 * Clear a group of Pins for the given port.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be
 *          specified by OR'ing then together.
 */
void gpio_clear(uint32_t gpioport, uint32_t gpios)
{
	PORT_OUTCLR(gpioport) = gpios;
}

/** @brief Read level of a group of Pins
 *
 * Read the level of a group of Pins for the given port.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be
 *          specified by OR'ing then together.
 */
uint32_t gpio_get(uint32_t gpioport, uint32_t gpios)
{
	return PORT_IN(gpioport) & gpios;
}

/** @brief Toggle level of a group of Pins
 *
 * Toggle one or more pins  of the givent port.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] gpios @ref gpio_pin_id. Any combination of pins may be
 *          specified by OR'ing then together.
 */
void gpio_toggle(uint32_t gpioport, uint32_t gpios)
{
	PORT_OUTTGL(gpioport) = gpios;
}

/** @brief Read level for all pins from a port
 *
 * Read the level of all pins of the given port.
 *
 * @param[in] port register address base @ref port_reg_base
 *
 * @return The level of all pins on the port.
 */
uint32_t port_read(uint32_t port)
{
	return PORT_IN(port);
}

/** @brief Set level for all pins from a port
 *
 * Set the level of all pins of the given port.
 *
 * @param[in] port register address base @ref port_reg_base
 * @param[in] data @ref gpio_pin_id. Any combination of pins
 *           may be specified by OR'ing then together.
 */
void port_write(uint32_t port, uint32_t data)
{
	PORT_OUT(port) = data;
}

/**@}*/
