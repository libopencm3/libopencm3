/** @defgroup VF6xx_gpio_defines GPIO Defines
 *
 * @brief <b>Defined Constants and Types for the VF6xx GPIO Module</b>
 *
 * @ingroup VF6xx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2014
 * Stefan Agner <stefan@agner.ch>
 *
 * @date 03 July 2014
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2014 Stefan Agner <stefan@agner.ch>
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

#ifndef LIBOPENCM3_VF6XX_GPIO_H
#define LIBOPENCM3_VF6XX_GPIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/vf6xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup gpio_reg_base GPIO register base addresses
@ingroup VF6xx_gpio_defines

@{*/
#define GPIO(port)			(GPIO_BASE + (0x040 * (port)))
#define GPIO0				(GPIO_BASE + 0x000)
#define GPIO1				(GPIO_BASE + 0x040)
#define GPIO2				(GPIO_BASE + 0x080)
#define GPIO3				(GPIO_BASE + 0x0C0)
#define GPIO4				(GPIO_BASE + 0x100)

#define GPIO_OFFSET(gpio)		(0x1 << ((gpio) % 32))

/* --- GPIO registers ------------------------------------------------------ */

#define GPIO_PDOR(gpio_base)		MMIO32((gpio_base) + 0x00)
#define GPIO_PSOR(gpio_base)		MMIO32((gpio_base) + 0x04)
#define GPIO_PCOR(gpio_base)		MMIO32((gpio_base) + 0x08)
#define GPIO_PTOR(gpio_base)		MMIO32((gpio_base) + 0x0C)
#define GPIO_PDIR(gpio_base)		MMIO32((gpio_base) + 0x10)

/* --- Function prototypes ------------------------------------------------- */

#include <libopencm3/cm3/common.h>

BEGIN_DECLS

void gpio_set(uint32_t gpio);
void gpio_clear(uint32_t gpio);
bool gpio_get(uint32_t gpio);
void gpio_toggle(uint32_t gpio);
uint32_t gpio_port_read(uint32_t gpioport);
void gpio_port_write(uint32_t gpioport, uint32_t data);

END_DECLS

#endif
