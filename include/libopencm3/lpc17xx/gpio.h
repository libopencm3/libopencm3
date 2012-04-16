/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LPC17XX_GPIO_H
#define LPC17XX_GPIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc17xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* GPIO port base addresses (for convenience) */
#define GPIO0				GPIO_PIO0_BASE
#define GPIO1				GPIO_PIO1_BASE
#define GPIO2				GPIO_PIO2_BASE
#define GPIO3				GPIO_PIO3_BASE
#define GPIO4				GPIO_PIO4_BASE

/* GPIO number definitions (for convenience) */
#define GPIOPIN0                        (1 << 0)

/* --- GPIO registers ------------------------------------------------------ */

/* GPIO data direction register (GPIOn_DIR) */
#define GPIO_DIR(port)			MMIO32(port + 0x00)
#define GPIO0_DIR			GPIO_DIR(GPIO0)
#define GPIO1_DIR			GPIO_DIR(GPIO1)
#define GPIO2_DIR			GPIO_DIR(GPIO2)
#define GPIO3_DIR			GPIO_DIR(GPIO3)
#define GPIO4_DIR			GPIO_DIR(GPIO4)

/* GPIO port pin value register (GPIOn_PIN) */
#define GPIO_PIN(port)			MMIO32(port + 0x14)
#define GPIO0_PIN			GPIO_PIN(GPIO0)
#define GPIO1_PIN			GPIO_PIN(GPIO1)
#define GPIO2_PIN			GPIO_PIN(GPIO2)
#define GPIO3_PIN			GPIO_PIN(GPIO3)
#define GPIO4_PIN			GPIO_PIN(GPIO4)

/* GPIO port output set register (GPIOn_SET) */
#define GPIO_SET(port)			MMIO32(port + 0x18)
#define GPIO0_SET			GPIO_SET(GPIO0)
#define GPIO1_SET			GPIO_SET(GPIO1)
#define GPIO2_SET			GPIO_SET(GPIO2)
#define GPIO3_SET			GPIO_SET(GPIO3)
#define GPIO4_SET			GPIO_SET(GPIO4)

/* GPIO port output clear register (GPIOn_CLR) */
#define GPIO_CLR(port)			MMIO32(port + 0x1C)
#define GPIO0_CLR			GPIO_CLR(GPIO0)
#define GPIO1_CLR			GPIO_CLR(GPIO1)
#define GPIO2_CLR			GPIO_CLR(GPIO2)
#define GPIO3_CLR			GPIO_CLR(GPIO3)
#define GPIO4_CLR			GPIO_CLR(GPIO4)

#endif
