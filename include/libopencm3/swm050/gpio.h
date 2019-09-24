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
#define GPIO_INPUT			0x0
#define GPIO_OUTPUT			0x1
/**@}*/

/* GPIO polarity definitions */
/** @defgroup gpio_pol GPIO Polarity
@{*/
#define GPIO_POL_LOW			0x0
#define GPIO_POL_HIGH			0x1
/*@}*/

/* GPIO interrupt trigger definitions */
/** @defgroup gpio_trig_type GPIO Interrupt Trigger Type
@{*/
#define GPIO_TRIG_LEVEL			0x0
#define GPIO_TRIG_EDGE			0x1
/*@}*/

/* GPIO interrupt mask definitions */
/** @defgroup gpio_int_masked GPIO Interrupt Mask
@{*/
#define GPIO_UNMASKED			0x0
#define GPIO_MASKED			0x1
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

/* SYSCON Registers */
/** @defgroup syscon_register SYSCON Registers
 * @note These registers are really part of the SYSCON system control space
 * @{*/
/** SWD Enable register */
#define SWD_SEL				MMIO32(SYSTEM_CON_BASE + 0x30)
/** GPIO Alternate function selection register */
#define PORTA_SEL			MMIO32(SYSTEM_CON_BASE + 0x80)
/** GPIO Pull up register */
#define PORTA_PULLUP			MMIO32(SYSTEM_CON_BASE + 0x90)
/** GPIO Input enable register */
#define PORTA_INEN			MMIO32(SYSTEM_CON_BASE + 0xe0)
/*@}*/

BEGIN_DECLS

void gpio_set(uint16_t gpios);
void gpio_clear(uint16_t gpios);
uint16_t gpio_get(uint16_t gpios);
void gpio_toggle(uint16_t gpios);

void gpio_input(uint16_t gpios);
void gpio_output(uint16_t gpios);
void gpio_sel_af(uint16_t gpios, bool af_en);
void gpio_pullup(uint16_t gpios, bool en);
void gpio_input_en(uint16_t gpios, bool en);

void gpio_sel_swd(bool en);

void gpio_int_en(uint16_t gpios);
void gpio_int_mask(uint16_t gpios, bool masked);
void gpio_int_type(uint16_t gpios, bool level);
void gpio_int_pol(uint16_t gpios, bool pol);
uint16_t gpio_int_stat(void);
uint16_t gpio_int_raw_stat(void);
void gpio_int_clear(uint16_t gpios);

END_DECLS

#endif
/**@}*/
