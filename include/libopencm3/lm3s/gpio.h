/** @defgroup gpio_defines General Purpose I/O Defines

@brief <b>Defined Constants and Types for the LM3S General Purpose I/O</b>

@ingroup LM3Sxx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2011
Gareth McMullin <gareth@blacksphere.co.nz>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef LM3S_GPIO_H
#define LM3S_GPIO_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/lm3s/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* GPIO port base addresses (for convenience) */
#define GPIOA				GPIOA_APB_BASE
#define GPIOB				GPIOB_APB_BASE
#define GPIOC				GPIOC_APB_BASE
#define GPIOD				GPIOD_APB_BASE
#define GPIOE				GPIOE_APB_BASE
#define GPIOF				GPIOF_APB_BASE
#define GPIOG				GPIOG_APB_BASE
#define GPIOH				GPIOH_APB_BASE

/* GPIO number definitions (for convenience) */
#define GPIO0				(1 << 0)
#define GPIO1				(1 << 1)
#define GPIO2				(1 << 2)
#define GPIO3				(1 << 3)
#define GPIO4				(1 << 4)
#define GPIO5				(1 << 5)
#define GPIO6				(1 << 6)
#define GPIO7				(1 << 7)

/* --- GPIO registers ------------------------------------------------------ */

#define GPIO_DATA(port)			(&MMIO32((port) + 0x000))
#define GPIO_DIR(port)			MMIO32((port) + 0x400)
#define GPIO_IS(port)			MMIO32((port) + 0x404)
#define GPIO_IBE(port)			MMIO32((port) + 0x408)
#define GPIO_IEV(port)			MMIO32((port) + 0x40c)
#define GPIO_IM(port)			MMIO32((port) + 0x410)
#define GPIO_RIS(port)			MMIO32((port) + 0x414)
#define GPIO_MIS(port)			MMIO32((port) + 0x418)
#define GPIO_ICR(port)			MMIO32((port) + 0x41c)
#define GPIO_AFSEL(port)		MMIO32((port) + 0x420)
#define GPIO_DR2R(port)			MMIO32((port) + 0x500)
#define GPIO_DR4R(port)			MMIO32((port) + 0x504)
#define GPIO_DR8R(port)			MMIO32((port) + 0x508)
#define GPIO_ODR(port)			MMIO32((port) + 0x50c)
#define GPIO_PUR(port)			MMIO32((port) + 0x510)
#define GPIO_PDR(port)			MMIO32((port) + 0x514)
#define GPIO_SLR(port)			MMIO32((port) + 0x518)
#define GPIO_DEN(port)			MMIO32((port) + 0x51c)
#define GPIO_LOCK(port)			MMIO32((port) + 0x520)
#define GPIO_CR(port)			MMIO32((port) + 0x524)
#define GPIO_AMSEL(port)		MMIO32((port) + 0x528)

BEGIN_DECLS

void gpio_set(uint32_t gpioport, uint8_t gpios);
void gpio_clear(uint32_t gpioport, uint8_t gpios);

END_DECLS

/**@}*/

#endif

