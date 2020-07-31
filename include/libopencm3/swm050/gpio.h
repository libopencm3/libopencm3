/** @defgroup gpio_defines GPIO Defines
 *
 * @brief <b>Defined Constants and Types for the SWM050 General Purpose I/O</b>
 *
 * @ingroup SWM050_defines
 *
 * LGPL License Terms @ref lgpl_license
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
#ifndef LIBOPENCM3_GPIO_H
#define LIBOPENCM3_GPIO_H
#include <libopencm3/cm3/common.h>
#include <libopencm3/swm050/memorymap.h>

/* GPIO number definitions (for convenience) */
/** @defgroup gpio_pin_id GPIO Pin Identifiers
@{*/
#define GPIO0				(1 << 0)
#define GPIO1				(1 << 1)
#define GPIO2				(1 << 2)
#define GPIO3				(1 << 3)
#define GPIO4				(1 << 4)
#define GPIO5				(1 << 5)
#define GPIO6				(1 << 6)
#define GPIO7				(1 << 7)
#define GPIO8				(1 << 8)
#define GPIO9				(1 << 9)
#define GPIO_ALL			0x3ff
/**@}*/

/* GPIO direction definitions */
/** @defgroup gpio_dir GPIO Pin Direction
@{*/
enum gpio_dir {
	GPIO_INPUT,
	GPIO_OUTPUT
};
/**@}*/

/* GPIO polarity definitions */
/** @defgroup gpio_pol GPIO Polarity
@{*/
enum gpio_pol {
	GPIO_POL_LOW,
	GPIO_POL_HIGH
};
/*@}*/

/* GPIO interrupt trigger definitions */
/** @defgroup gpio_trig_type GPIO Interrupt Trigger Type
@{*/
enum gpio_trig_type {
	GPIO_TRIG_LEVEL,
	GPIO_TRIG_EDGE
};
/*@}*/

/* GPIO interrupt mask definitions */
/** @defgroup gpio_int_masked GPIO Interrupt Mask
@{*/
enum gpio_int_masked {
	GPIO_UNMASKED,
	GPIO_MASKED
};
/*@}*/

/* GPIO Registers */
/** @defgroup gpio_registers GPIO Registers
@{*/
/** Data register */
#define GPIO_ADATA			MMIO32(GPIO_BASE + 0x0)
/** Direction register */
#define GPIO_ADIR			MMIO32(GPIO_BASE + 0x4)
/** Interrupt enable register */
#define GPIO_INTEN_A			MMIO32(GPIO_BASE + 0x30)
/** Interrupt mask register */
#define GPIO_INTMASK_A			MMIO32(GPIO_BASE + 0x34)
/** Interrupt trigger mode register */
#define GPIO_INTLEVEL_A			MMIO32(GPIO_BASE + 0x38)
/** Interrupt polarity register */
#define GPIO_INTPOLARITY_A		MMIO32(GPIO_BASE + 0x3c)
/** Interrupt status after masking */
#define GPIO_INTSTAT_A			MMIO32(GPIO_BASE + 0x40)
/** Interrupt status before masking */
#define GPIO_RAWINTSTAT_A		MMIO32(GPIO_BASE + 0x44)
/** Interrupt clear register */
#define GPIO_INTEOI_A			MMIO32(GPIO_BASE + 0x48)
/** External register (wat) */
#define GPIO_AEXT			MMIO32(GPIO_BASE + 0x4c)
/*@}*/

BEGIN_DECLS

void gpio_set(uint16_t gpios);
void gpio_clear(uint16_t gpios);
uint16_t gpio_get(uint16_t gpios);
void gpio_toggle(uint16_t gpios);

void gpio_input(uint16_t gpios);
void gpio_output(uint16_t gpios);

void gpio_int_enable(uint16_t gpios, bool en);
void gpio_int_mask(uint16_t gpios, enum gpio_int_masked masked);
void gpio_int_type(uint16_t gpios, enum gpio_trig_type type);
void gpio_int_pol(uint16_t gpios, enum gpio_pol pol);
uint16_t gpio_int_status(void);
uint16_t gpio_int_raw_status(void);
void gpio_int_clear(uint16_t gpios);

END_DECLS

#endif
/**@}*/
