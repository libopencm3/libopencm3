/** @defgroup gpio_defines
 *
 * #ingroup SAMD_defines
 *
 * @brief Defined Constants and Types for the SAMD Port controler
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Karl Palsson <karlp@tweak.net.au>
 * Copyright (C) 2020 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>
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

#pragma once

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/d/memorymap.h>

/* --- Convenience macros ------------------------------------------------ */

#define PORTA				(PORT_BASE + 0)
#define PORTB				(PORT_BASE + 0x80)

/* GPIO number definitions (for convenience) */
/** @defgroup gpio_pin_id GPIO Pin Identifiers
@ingroup gpio_defines
@{*/
#define GPIO0			(1 << 0)
#define GPIO1			(1 << 1)
#define GPIO2			(1 << 2)
#define GPIO3			(1 << 3)
#define GPIO4			(1 << 4)
#define GPIO5			(1 << 5)
#define GPIO6			(1 << 6)
#define GPIO7			(1 << 7)
#define GPIO8			(1 << 8)
#define GPIO9			(1 << 9)
#define GPIO10			(1 << 10)
#define GPIO11			(1 << 11)
#define GPIO12			(1 << 12)
#define GPIO13			(1 << 13)
#define GPIO14			(1 << 14)
#define GPIO15			(1 << 15)
#define GPIO16			(1 << 16)
#define GPIO17			(1 << 17)
#define GPIO18			(1 << 18)
#define GPIO19			(1 << 19)
#define GPIO20			(1 << 20)
#define GPIO21			(1 << 21)
#define GPIO22			(1 << 22)
#define GPIO23			(1 << 23)
#define GPIO24			(1 << 24)
#define GPIO25			(1 << 25)
#define GPIO26			(1 << 26)
#define GPIO27			(1 << 27)
#define GPIO28			(1 << 28)
#define GPIO29			(1 << 29)
#define GPIO30			(1 << 30)
#define GPIO31			(1 << 31)
#define GPIO_ALL		0xffff
/**@}*/

/* GPIO mux definitions (for convenience) */
/** @defgroup gpio_mux GPIO mux configuration
@ingroup gpio_mux
@{*/
enum port_mux {
	PORT_PMUX_FUN_A = 0,
	PORT_PMUX_FUN_B,
	PORT_PMUX_FUN_C,
	PORT_PMUX_FUN_D,
	PORT_PMUX_FUN_E,
	PORT_PMUX_FUN_F,
	PORT_PMUX_FUN_G,
	PORT_PMUX_FUN_H,
	PORT_PMUX_FUN_I
};
/**@}*/

/* --- PORT registers ----------------------------------------------------- */

/* Direction register */
#define PORT_DIR(port)			MMIO32((port) + 0x0000)

/* Direction clear register */
#define PORT_DIRCLR(port)		MMIO32((port) + 0x0004)

/* Direction set register */
#define PORT_DIRSET(port)		MMIO32((port) + 0x0008)

/* Direction toggle register */
#define PORT_DIRTGL(port)		MMIO32((port) + 0x000c)

/* output register */
#define PORT_OUT(port)			MMIO32((port) + 0x0010)

/* output clear register */
#define PORT_OUTCLR(port)		MMIO32((port) + 0x0014)

/* output set register */
#define PORT_OUTSET(port)		MMIO32((port) + 0x0018)

/* output toggle register */
#define PORT_OUTTGL(port)		MMIO32((port) + 0x001c)

/* input register */
#define PORT_IN(port)			MMIO32((port) + 0x0020)

/* Control register */
#define PORT_CTRL(port)			MMIO32((port) + 0x0024)

/* Write configuration register */
#define PORT_WRCONFIG(port)		MMIO32((port) + 0x0028)

/* Peripheral multiplexing registers */
#define PORT_PMUX(port, n)		MMIO8((port) + 0x0030 + (n))

/* Pin configuration registers */
#define PORT_PINCFG(port, n)		MMIO8((port) + 0x0040 + (n))

/* --- PORTx_DIR values ---------------------------------------------------- */

/* PORTx_DIR[31:0]: DIRy[31:0]: Port x set bit y direction [y=0..31] */

/* --- PORTx_DIRCLR values ------------------------------------------------- */

/* PORTx_DIRCLR[31:0]: DIRCLRy[31:0]: Port x set bit y as input [y=0..31] */

/* --- PORTx_DIRSET values ------------------------------------------------- */

/* PORTx_DIRSET[31:0]: DIRSETy[31:0]: Port x set bit y as output [y=0..31] */

/* --- PORTx_DIRTGL values ------------------------------------------------- */

/* PORTx_DIRTGL[31:0]: DIRTGLy[31:0]: Port x toggle bit y direction [y=0..31] */

/* --- PORTx_OUT values ---------------------------------------------------- */

/* PORTx_OUT[31:0]: OUTy[31:0]: Port output data [y=0..31] */

/* --- PORTx_OUTCLR values ------------------------------------------------- */

/* PORTx_OUTCLR[31:0]: OUTCLRy[31:0]: Port x reset bit y [y=0..31] */

/* --- PORTx_OUTSET values ------------------------------------------------- */

/* PORTx_OUTSET[31:0]: OUTSETy[31:0]: Port x set bit y [y=0..31] */

/* --- PORTx_OUTTGL values ------------------------------------------------- */

/* PORTx_OUTTGL[31:0]: OUTTGLy[31:0]: Port x toggle bit y [y=0..31] */

/* --- PORTx_IN values ----------------------------------------------------- */

/* PORTx_IN[31:0]: INy[31:0]: Port input data [y=0..31] */

/* --- PORTx_CTRL values --------------------------------------------------- */

/* PORTx_CTRL[31:0]: CTRLy[31:0]: Port input sampling mode [y=0..31] */

/* --- PORTx_WRCONFIG values ----------------------------------------------- */

/* HWSEL: Half word select: 0 [15:0], 1 [31:16] */
#define PORT_WRCONFIG_HWSEL         (1 << 31)

/* WRPINCFG: Write PINCFG: 1 to update pins for selected by PINMASK */
#define PORT_WRCONFIG_WRPINCFG      (1 << 30)

/* Bit 29: Reserved */

/* WRPMUX: Write PMUX: 1 to update pins pmux for selected by PINMASK */
#define PORT_WRCONFIG_WRPMUX        (1 << 28)

/* PMUX: Peripheral Multiplexing: determine pmux for pins selected by PINMASK */
#define PORT_WRCONFIG_PMUX(mux)     ((0xf & (mux)) << 24)

/* Bit 23: Reserved */

/* DRVSTR: Output Driver Strength Selection: determine strength for pins in PINMASK */
#define PORT_WRCONFIG_DRVSTR        (1 << 22)

/* Bit [21:19]: Reserved */

/* PULLEN: Pull Enable: enable PINCFGy.PULLEN for pins in PINMASK */
#define PORT_WRCONFIG_PULLEN        (1 << 18)

/* INEN: Input Enable: enable PINCFGy.INEN for pins in PINMASK */
#define PORT_WRCONFIG_INEN          (1 << 17)

/* PMUXEN: Peripheral Multiplexer Enable: enable PINCFGy.PMUXEN for pins in PINMASK */
#define PORT_WRCONFIG_PMUXEN        (1 << 16)

/* PINMASK: Pin Mask for Multiple Pin Configuration: select pins to be configured
 *          [31:16] if HWSET=1, [15:0] if HWSET=0
 */
#define PORT_WRCONFIG_PINMASK(pins) ((0xffff & (pins)) << 0)

/* --- PORTx_PMUX values --------------------------------------------------- */

/* PMUXO: Peripheral Multiplexing for Odd-Numbered Pin: 2*x+1 pin multiplexing */
#define PORT_PMUX_PMUXO(mux)        ((0xf & (mux)) << 4)

/* PMUXE: Peripheral Multiplexing for Even-Numbered Pin: 2*x pin multiplexing */
#define PORT_PMUX_PMUXE(mux)        ((0xf & (mux)) << 0)

/* --- PORTx_PINCFGy values ------------------------------------------------ */

/* Bit 7: Reserved */

/* DRVSTR: Output Driver Strength Selection */
#define PORT_PINCFG_DRVSTR (1 << 6)

/* Bit [5:3]: Reserved */

/* PULLEN: Pull Enable */
#define PORT_PINCFG_PULLEN (1 << 2)

/* INEN: Input Enable */
#define PORT_PINCFG_INEN   (1 << 1)

/* PMUXEN: Peripheral Multiplexer Enable */
#define PORT_PINCFG_PMUXEN (1 << 0)

/* --- Convenience enums --------------------------------------------------- */

/* GPIO mode definitions (for convenience) */
/** @defgroup gpio_mode GPIO mode configuration
@ingroup gpio_mode
@{*/
enum gpio_mode {
	GPIO_MODE_OUTPUT,
	GPIO_MODE_INOUT,
	GPIO_MODE_INPUT_FLOAT,
	GPIO_MODE_INPUT_PULLDOWN,
	GPIO_MODE_INPUT_PULLUP,
	GPIO_MODE_AF
};
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void gpio_mode_setup(uint32_t gpioport, enum gpio_mode mode, uint32_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t af, uint32_t gpios);

/* Let's keep these ones inlined. GPIO control should be fast */
/** @ingroup gpio_control
 * @{ */

/** @brief Set a group of Pins (atomic)
 *
 * Set a group of Pins for the given port. this is an atomic operation.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] gpios @ref gpio_defines. Any combinaison of pins may be
 *          specified by OR'ing then together.
 */
static inline void gpio_set(uint32_t gpioport, uint32_t gpios)
{
	PORT_OUTSET(gpioport) = gpios;
}

/** @brief Clear a group of Pins (atomic)
 *
 * Clear a group of Pins for the given port. this is an atomic operation.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] gpios @ref gpio_defines. Any combinaison of pins may be
 *          specified by OR'ing then together.
 */
static inline void gpio_clear(uint32_t gpioport, uint32_t gpios)
{
	PORT_OUTCLR(gpioport) = gpios;
}

/** @brief Read level of a group of Pins (atomic)
 *
 * Read the level of a group of Pins for the given port. this is an atomic operation.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] gpios @ref gpio_defines. Any combinaison of pins may be
 *          specified by OR'ing then together.
 */
static inline uint32_t gpio_get(uint32_t gpioport, uint32_t gpios)
{
	return PORT_IN(gpioport) & gpios;
}

/** @brief Toggle level of a group of Pins (atomic)
 *
 * Toggle one or more pins  of the givent port. this is an atomic operation.
 *
 * @param[in] gpioport port register address base @ref port_reg_base
 * @param[in] gpios @ref gpio_defines. Any combinaison of pins may be
 *          specified by OR'ing then together.
 */
static inline void gpio_toggle(uint32_t gpioport, uint32_t gpios)
{
	PORT_OUTTGL(gpioport) = gpios;
}

/** @brief Read level for all pins from a port (atomic)
 *
 * Read the level of all pins of the given port. this is an atomic operation.
 *
 * @param[in] port register address base @ref port_reg_base
 *
 * @return The level of all pins on the port.
 */
static inline uint32_t port_read(uint32_t port)
{
	return PORT_IN(port);
}

/*
 * \brief Set level for all pins from a port (atomic)
 *
 * Set the level of all pins of the given port. this is an atomic operation.
 *
 * @param[in] port register address base @ref port_reg_base
 * @param[in] data @ref gpio_defines. Any combinaison of pins
 *           may be specified by OR'ing then together.
 */
static inline void port_write(uint32_t port, uint32_t data)
{
	PORT_OUT(port) = data;
}

END_DECLS

/**@}*/
