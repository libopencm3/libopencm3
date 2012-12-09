/** @addtogroup gpio_defines */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
 * Copyright (C) 2012 Ken Sarkies <ksarkies@internode.on.net>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA GPIO.H */

#ifndef LIBOPENCM3_GPIO_COMMON_ALL_H
#define LIBOPENCM3_GPIO_COMMON_ALL_H

/**@{*/

#include <libopencm3/cm3/common.h>

/* --- Convenience macros -------------------------------------------------- */

/* --- GPIO_LCKR values ---------------------------------------------------- */

#define GPIO_LCKK			(1 << 16)
/* GPIO_LCKR[15:0]: LCKy: Port x lock bit y (y = 0..15) */

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
#define GPIO10				(1 << 10)
#define GPIO11				(1 << 11)
#define GPIO12				(1 << 12)
#define GPIO13				(1 << 13)
#define GPIO14				(1 << 14)
#define GPIO15				(1 << 15)
#define GPIO_ALL			0xffff
/**@}*/

void gpio_set(u32 gpioport, u16 gpios);
void gpio_clear(u32 gpioport, u16 gpios);
u16 gpio_get(u32 gpioport, u16 gpios);
void gpio_toggle(u32 gpioport, u16 gpios);
u16 gpio_port_read(u32 gpioport);
void gpio_port_write(u32 gpioport, u16 data);
void gpio_port_config_lock(u32 gpioport, u16 gpios);

/**@}*/
#endif

