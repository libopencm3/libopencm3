/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Icenowy Zheng <icenowy@aosc.io>
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

#ifndef LIBOPENCM3_GPIO_H
#define LIBOPENCM3_GPIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/swm050/memorymap.h>

/* GPIO number definitions (for convenience) */
/** @defgroup gpio_pin_id GPIO Pin Identifiers
@ingroup gpio_defines

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
@ingroup gpio_defines
@{*/
#define GPIO_INPUT			0x0
#define GPIO_OUTPUT			0x1
/**@}*/

#define GPIO_DATA			MMIO32(GPIO_BASE + 0x0)
#define GPIO_DIR			MMIO32(GPIO_BASE + 0x4)
#define GPIO_EXT			MMIO32(GPIO_BASE + 0x4c)

#define GPIO_INTEN			MMIO32(GPIO_BASE + 0x30)
#define GPIO_INTMASK			MMIO32(GPIO_BASE + 0x34)
#define GPIO_INTLEVEL			MMIO32(GPIO_BASE + 0x38)
#define GPIO_INTPOLARITY		MMIO32(GPIO_BASE + 0x3c)
#define GPIO_INTSTATUS			MMIO32(GPIO_BASE + 0x40)
#define GPIO_INTRAWSTATUS		MMIO32(GPIO_BASE + 0x44)
#define GPIO_INTEOI			MMIO32(GPIO_BASE + 0x48)

#define SWD_SEL				MMIO32(SYSTEM_CON_BASE + 0x30)
#define GPIO_SEL			MMIO32(SYSTEM_CON_BASE + 0x80)
#define GPIO_PULLUP			MMIO32(SYSTEM_CON_BASE + 0x90)
#define GPIO_INEN			MMIO32(SYSTEM_CON_BASE + 0xe0)

BEGIN_DECLS

void gpio_set(uint16_t gpios);
void gpio_clear(uint16_t gpios);
uint16_t gpio_get(uint16_t gpios);
void gpio_toggle(uint16_t gpios);

void gpio_input(uint16_t gpios);
void gpio_output(uint16_t gpios);
void gpio_sel_af(uint16_t gpios, bool af_en);
void gpio_pullup(uint16_t gpios, bool en);
void gpio_in_en(uint16_t gpios, bool en);

void gpio_sel_swd(bool en);

END_DECLS

#endif
