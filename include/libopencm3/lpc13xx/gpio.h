/** @defgroup gpio_defines GPIO Defines

@brief <b>Defined Constants and Types for the LPC13xx General Purpose I/O</b>

@ingroup LPC13xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
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

/**@{*/

#ifndef LPC13XX_GPIO_H
#define LPC13XX_GPIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/lpc13xx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/* GPIO port base addresses (for convenience) */
#define GPIO0				GPIO_PIO0_BASE
#define GPIO1				GPIO_PIO1_BASE
#define GPIO2				GPIO_PIO2_BASE
#define GPIO3				GPIO_PIO3_BASE

/* --- GPIO registers ------------------------------------------------------ */

/* GPIO data register (GPIOn_DATA) */
#define GPIO_DATA(port)			MMIO32(port + 0x3ffc)
#define GPIO0_DATA			GPIO_DATA(GPIO0)
#define GPIO1_DATA			GPIO_DATA(GPIO1)
#define GPIO2_DATA			GPIO_DATA(GPIO2)
#define GPIO3_DATA			GPIO_DATA(GPIO3)

/* GPIO data direction register (GPIOn_DIR) */
#define GPIO_DIR(port)			MMIO32(port + 0x00)
#define GPIO0_DIR			GPIO_DIR(GPIO0)
#define GPIO1_DIR			GPIO_DIR(GPIO1)
#define GPIO2_DIR			GPIO_DIR(GPIO2)
#define GPIO3_DIR			GPIO_DIR(GPIO3)

/* GPIO interrupt sense register (GPIOn_IS) */
#define GPIO_IS(port)			MMIO32(port + 0x04)
#define GPIO0_IS			GPIO_IS(GPIO0)
#define GPIO1_IS			GPIO_IS(GPIO1)
#define GPIO2_IS			GPIO_IS(GPIO2)
#define GPIO3_IS			GPIO_IS(GPIO3)

/* GPIO interrupt both edges sense register (GPIOn_IBE) */
#define GPIO_IBE(port)			MMIO32(port + 0x08)
#define GPIO0_IBE			GPIO_IBE(GPIO0)
#define GPIO1_IBE			GPIO_IBE(GPIO1)
#define GPIO2_IBE			GPIO_IBE(GPIO2)
#define GPIO3_IBE			GPIO_IBE(GPIO3)

/* GPIO interrupt event register (GPIOn_IEV) */
#define GPIO_IEV(port)			MMIO32(port + 0x0c)
#define GPIO0_IEV			GPIO_IEV(GPIO0)
#define GPIO1_IEV			GPIO_IEV(GPIO1)
#define GPIO2_IEV			GPIO_IEV(GPIO2)
#define GPIO3_IEV			GPIO_IEV(GPIO3)

/* GPIO interrupt mask register (GPIOn_IE) */
#define GPIO_IE(port)			MMIO16(port + 0x10)
#define GPIO0_IE			GPIO_IE(GPIO0)
#define GPIO1_IE			GPIO_IE(GPIO1)
#define GPIO2_IE			GPIO_IE(GPIO2)
#define GPIO3_IE			GPIO_IE(GPIO3)

/* FIXME: IRS or RIS? Datasheet is not consistent here. */
/* GPIO raw interrupt status register (GPIOn_IRS) */
#define GPIO_IRS(port)			MMIO16(port + 0x14)
#define GPIO0_IRS			GPIO_IRS(GPIO0)
#define GPIO1_IRS			GPIO_IRS(GPIO1)
#define GPIO2_IRS			GPIO_IRS(GPIO2)
#define GPIO3_IRS			GPIO_IRS(GPIO3)

/* GPIO masked interrupt status register (GPIOn_MIS) */
#define GPIO_MIS(port)			MMIO16(port + 0x18)
#define GPIO0_MIS			GPIO_MIS(GPIO0)
#define GPIO1_MIS			GPIO_MIS(GPIO1)
#define GPIO2_MIS			GPIO_MIS(GPIO2)
#define GPIO3_MIS			GPIO_MIS(GPIO3)

/* GPIO interrupt clear register (GPIOn_IC) */
#define GPIO_IC(port)			MMIO16(port + 0x1c)
#define GPIO0_IC			GPIO_IC(GPIO0)
#define GPIO1_IC			GPIO_IC(GPIO1)
#define GPIO2_IC			GPIO_IC(GPIO2)
#define GPIO3_IC			GPIO_IC(GPIO3)

BEGIN_DECLS

void gpio_set(uint32_t gpioport, uint16_t gpios);

END_DECLS

/**@}*/

#endif
