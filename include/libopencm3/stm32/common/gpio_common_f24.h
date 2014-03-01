/** @addtogroup gpio_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2011
 * Fergus Noble <fergusnoble@gmail.com>
 * @author @htmlonly &copy; @endhtmlonly 2012
 * Ken Sarkies <ksarkies@internode.on.net>
 *
 */
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA GPIO.H
The order of header inclusion is important. gpio.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_GPIO_H
/** @endcond */
#ifndef LIBOPENCM3_GPIO_COMMON_F24_H
#define LIBOPENCM3_GPIO_COMMON_F24_H

/**@{*/

#include <libopencm3/stm32/common/gpio_common_f234.h>

/* GPIO port base addresses (for convenience) */
/** @defgroup gpio_port_id GPIO Port IDs
@ingroup gpio_defines

@{*/
#define GPIOG				GPIO_PORT_G_BASE
#define GPIOH				GPIO_PORT_H_BASE
#define GPIOI				GPIO_PORT_I_BASE
/**@}*/

/* --- GPIO registers for STM32F2, STM32F3 and STM32F4 --------------------- */

/* Port mode register (GPIOx_MODER) */
#define GPIOG_MODER			GPIO_MODER(GPIOG)
#define GPIOH_MODER			GPIO_MODER(GPIOH)
#define GPIOI_MODER			GPIO_MODER(GPIOI)

/* Port output type register (GPIOx_OTYPER) */
#define GPIOG_OTYPER			GPIO_OTYPER(GPIOG)
#define GPIOH_OTYPER			GPIO_OTYPER(GPIOH)
#define GPIOI_OTYPER			GPIO_OTYPER(GPIOI)

/* Port output speed register (GPIOx_OSPEEDR) */
#define GPIOG_OSPEEDR			GPIO_OSPEEDR(GPIOG)
#define GPIOH_OSPEEDR			GPIO_OSPEEDR(GPIOH)
#define GPIOI_OSPEEDR			GPIO_OSPEEDR(GPIOI)

/* Port pull-up/pull-down register (GPIOx_PUPDR) */
#define GPIOG_PUPDR			GPIO_PUPDR(GPIOG)
#define GPIOH_PUPDR			GPIO_PUPDR(GPIOH)
#define GPIOI_PUPDR			GPIO_PUPDR(GPIOI)

/* Port input data register (GPIOx_IDR) */
#define GPIOG_IDR			GPIO_IDR(GPIOG)
#define GPIOH_IDR			GPIO_IDR(GPIOH)
#define GPIOI_IDR			GPIO_IDR(GPIOI)

/* Port output data register (GPIOx_ODR) */
#define GPIOG_ODR			GPIO_ODR(GPIOG)
#define GPIOH_ODR			GPIO_ODR(GPIOH)
#define GPIOI_ODR			GPIO_ODR(GPIOI)

/* Port bit set/reset register (GPIOx_BSRR) */
#define GPIOG_BSRR			GPIO_BSRR(GPIOG)
#define GPIOH_BSRR			GPIO_BSRR(GPIOH)
#define GPIOI_BSRR			GPIO_BSRR(GPIOI)

/* Port configuration lock register (GPIOx_LCKR) */
#define GPIOG_LCKR			GPIO_LCKR(GPIOG)
#define GPIOH_LCKR			GPIO_LCKR(GPIOH)
#define GPIOI_LCKR			GPIO_LCKR(GPIOI)

/* Alternate function low register (GPIOx_AFRL) */
#define GPIOG_AFRL			GPIO_AFRL(GPIOG)
#define GPIOH_AFRL			GPIO_AFRL(GPIOH)
#define GPIOI_AFRL			GPIO_AFRL(GPIOI)

/* Alternate function high register (GPIOx_AFRH) */
#define GPIOG_AFRH			GPIO_AFRH(GPIOG)
#define GPIOH_AFRH			GPIO_AFRH(GPIOH)
#define GPIOI_AFRH			GPIO_AFRH(GPIOI)

/**@}*/
#endif
/** @cond */
#else
#warning "gpio_common_f24.h should not be included explicitly, only via gpio.h"
#endif
/** @endcond */
