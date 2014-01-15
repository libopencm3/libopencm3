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
#ifndef LIBOPENCM3_GPIO_COMMON_F234_H
#define LIBOPENCM3_GPIO_COMMON_F234_H

/**@{*/

#include <libopencm3/stm32/common/gpio_common_all.h>

/* GPIO port base addresses (for convenience) */
/** @defgroup gpio_port_id GPIO Port IDs
@ingroup gpio_defines

@{*/
#define GPIOA				GPIO_PORT_A_BASE
#define GPIOB				GPIO_PORT_B_BASE
#define GPIOC				GPIO_PORT_C_BASE
#define GPIOD				GPIO_PORT_D_BASE
#define GPIOE				GPIO_PORT_E_BASE
#define GPIOF				GPIO_PORT_F_BASE

/**@}*/

/* --- GPIO registers for STM32F2, STM32F3 and STM32F4 --------------------- */

/* Port mode register (GPIOx_MODER) */
#define GPIO_MODER(port)		MMIO32(port + 0x00)
#define GPIOA_MODER			GPIO_MODER(GPIOA)
#define GPIOB_MODER			GPIO_MODER(GPIOB)
#define GPIOC_MODER			GPIO_MODER(GPIOC)
#define GPIOD_MODER			GPIO_MODER(GPIOD)
#define GPIOE_MODER			GPIO_MODER(GPIOE)
#define GPIOF_MODER			GPIO_MODER(GPIOF)

/* Port output type register (GPIOx_OTYPER) */
#define GPIO_OTYPER(port)		MMIO32(port + 0x04)
#define GPIOA_OTYPER			GPIO_OTYPER(GPIOA)
#define GPIOB_OTYPER			GPIO_OTYPER(GPIOB)
#define GPIOC_OTYPER			GPIO_OTYPER(GPIOC)
#define GPIOD_OTYPER			GPIO_OTYPER(GPIOD)
#define GPIOE_OTYPER			GPIO_OTYPER(GPIOE)
#define GPIOF_OTYPER			GPIO_OTYPER(GPIOF)

/* Port output speed register (GPIOx_OSPEEDR) */
#define GPIO_OSPEEDR(port)		MMIO32(port + 0x08)
#define GPIOA_OSPEEDR			GPIO_OSPEEDR(GPIOA)
#define GPIOB_OSPEEDR			GPIO_OSPEEDR(GPIOB)
#define GPIOC_OSPEEDR			GPIO_OSPEEDR(GPIOC)
#define GPIOD_OSPEEDR			GPIO_OSPEEDR(GPIOD)
#define GPIOE_OSPEEDR			GPIO_OSPEEDR(GPIOE)
#define GPIOF_OSPEEDR			GPIO_OSPEEDR(GPIOF)

/* Port pull-up/pull-down register (GPIOx_PUPDR) */
#define GPIO_PUPDR(port)		MMIO32(port + 0x0c)
#define GPIOA_PUPDR			GPIO_PUPDR(GPIOA)
#define GPIOB_PUPDR			GPIO_PUPDR(GPIOB)
#define GPIOC_PUPDR			GPIO_PUPDR(GPIOC)
#define GPIOD_PUPDR			GPIO_PUPDR(GPIOD)
#define GPIOE_PUPDR			GPIO_PUPDR(GPIOE)
#define GPIOF_PUPDR			GPIO_PUPDR(GPIOF)

/* Port input data register (GPIOx_IDR) */
#define GPIO_IDR(port)			MMIO32(port + 0x10)
#define GPIOA_IDR			GPIO_IDR(GPIOA)
#define GPIOB_IDR			GPIO_IDR(GPIOB)
#define GPIOC_IDR			GPIO_IDR(GPIOC)
#define GPIOD_IDR			GPIO_IDR(GPIOD)
#define GPIOE_IDR			GPIO_IDR(GPIOE)
#define GPIOF_IDR			GPIO_IDR(GPIOF)

/* Port output data register (GPIOx_ODR) */
#define GPIO_ODR(port)			MMIO32(port + 0x14)
#define GPIOA_ODR			GPIO_ODR(GPIOA)
#define GPIOB_ODR			GPIO_ODR(GPIOB)
#define GPIOC_ODR			GPIO_ODR(GPIOC)
#define GPIOD_ODR			GPIO_ODR(GPIOD)
#define GPIOE_ODR			GPIO_ODR(GPIOE)
#define GPIOF_ODR			GPIO_ODR(GPIOF)

/* Port bit set/reset register (GPIOx_BSRR) */
#define GPIO_BSRR(port)			MMIO32(port + 0x18)
#define GPIOA_BSRR			GPIO_BSRR(GPIOA)
#define GPIOB_BSRR			GPIO_BSRR(GPIOB)
#define GPIOC_BSRR			GPIO_BSRR(GPIOC)
#define GPIOD_BSRR			GPIO_BSRR(GPIOD)
#define GPIOE_BSRR			GPIO_BSRR(GPIOE)
#define GPIOF_BSRR			GPIO_BSRR(GPIOF)

/* Port configuration lock register (GPIOx_LCKR) */
#define GPIO_LCKR(port)			MMIO32(port + 0x1c)
#define GPIOA_LCKR			GPIO_LCKR(GPIOA)
#define GPIOB_LCKR			GPIO_LCKR(GPIOB)
#define GPIOC_LCKR			GPIO_LCKR(GPIOC)
#define GPIOD_LCKR			GPIO_LCKR(GPIOD)
#define GPIOE_LCKR			GPIO_LCKR(GPIOE)
#define GPIOF_LCKR			GPIO_LCKR(GPIOF)

/* Alternate function low register (GPIOx_AFRL) */
#define GPIO_AFRL(port)			MMIO32(port + 0x20)
#define GPIOA_AFRL			GPIO_AFRL(GPIOA)
#define GPIOB_AFRL			GPIO_AFRL(GPIOB)
#define GPIOC_AFRL			GPIO_AFRL(GPIOC)
#define GPIOD_AFRL			GPIO_AFRL(GPIOD)
#define GPIOE_AFRL			GPIO_AFRL(GPIOE)
#define GPIOF_AFRL			GPIO_AFRL(GPIOF)

/* Alternate function high register (GPIOx_AFRH) */
#define GPIO_AFRH(port)			MMIO32(port + 0x24)
#define GPIOA_AFRH			GPIO_AFRH(GPIOA)
#define GPIOB_AFRH			GPIO_AFRH(GPIOB)
#define GPIOC_AFRH			GPIO_AFRH(GPIOC)
#define GPIOD_AFRH			GPIO_AFRH(GPIOD)
#define GPIOE_AFRH			GPIO_AFRH(GPIOE)
#define GPIOF_AFRH			GPIO_AFRH(GPIOF)

/* --- GPIOx_MODER values -------------------------------------------------- */

#define GPIO_MODE(n, mode)		(mode << (2 * (n)))
#define GPIO_MODE_MASK(n)		(0x3 << (2 * (n)))
/** @defgroup gpio_mode GPIO Pin Direction and Analog/Digital Mode
@ingroup gpio_defines
@{*/
#define GPIO_MODE_INPUT			0x0
#define GPIO_MODE_OUTPUT		0x1
#define GPIO_MODE_AF			0x2
#define GPIO_MODE_ANALOG		0x3
/**@}*/

/* --- GPIOx_OTYPER values ------------------------------------------------- */

/** @defgroup gpio_output_type GPIO Output Pin Driver Type
@ingroup gpio_defines
@list Push Pull
@list Open Drain
@{*/
#define GPIO_OTYPE_PP			0x0
#define GPIO_OTYPE_OD			0x1
/**@}*/

/* --- GPIOx_OSPEEDR values ------------------------------------------------ */

#define GPIO_OSPEED(n, speed)		(speed << (2 * (n)))
#define GPIO_OSPEED_MASK(n)		(0x3 << (2 * (n)))
/** @defgroup gpio_speed GPIO Output Pin Speed
@ingroup gpio_defines
@{*/
#define GPIO_OSPEED_2MHZ		0x0
#define GPIO_OSPEED_25MHZ		0x1
#define GPIO_OSPEED_50MHZ		0x2
#define GPIO_OSPEED_100MHZ		0x3
/**@}*/

/* --- GPIOx_PUPDR values -------------------------------------------------- */

#define GPIO_PUPD(n, pupd)		(pupd << (2 * (n)))
#define GPIO_PUPD_MASK(n)		(0x3 << (2 * (n)))
/** @defgroup gpio_pup GPIO Output Pin Pullup
@ingroup gpio_defines
@{*/
#define GPIO_PUPD_NONE			0x0
#define GPIO_PUPD_PULLUP		0x1
#define GPIO_PUPD_PULLDOWN		0x2
/**@}*/

/* --- GPIOx_IDR values ---------------------------------------------------- */

/* GPIOx_IDR[15:0]: IDRy[15:0]: Port input data (y = 0..15) */

/* --- GPIOx_ODR values ---------------------------------------------------- */

/* GPIOx_ODR[15:0]: ODRy[15:0]: Port output data (y = 0..15) */

/* --- GPIOx_BSRR values --------------------------------------------------- */

/* GPIOx_BSRR[31:16]: BRy: Port x reset bit y (y = 0..15) */
/* GPIOx_BSRR[15:0]: BSy: Port x set bit y (y = 0..15) */

/* --- GPIOx_LCKR values --------------------------------------------------- */

#define GPIO_LCKK			(1 << 16)
/* GPIOx_LCKR[15:0]: LCKy: Port x lock bit y (y = 0..15) */

/* --- GPIOx_AFRL/H values ------------------------------------------------- */

/* Note: AFRL is used for bits 0..7, AFRH is used for 8..15 */
/* See datasheet table 6 (pg. 48) for alternate function mappings. */

#define GPIO_AFR(n, af)			(af << ((n) * 4))
#define GPIO_AFR_MASK(n)		(0xf << ((n) * 4))
/** @defgroup gpio_af_num Alternate Function Pin Selection
@ingroup gpio_defines
@{*/
#define GPIO_AF0			0x0
#define GPIO_AF1			0x1
#define GPIO_AF2			0x2
#define GPIO_AF3			0x3
#define GPIO_AF4			0x4
#define GPIO_AF5			0x5
#define GPIO_AF6			0x6
#define GPIO_AF7			0x7
#define GPIO_AF8			0x8
#define GPIO_AF9			0x9
#define GPIO_AF10			0xa
#define GPIO_AF11			0xb
#define GPIO_AF12			0xc
#define GPIO_AF13			0xd
#define GPIO_AF14			0xe
#define GPIO_AF15			0xf
/**@}*/

/* Note: EXTI source selection is now in the SYSCFG peripheral. */

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

/*
 * Note: The F2 and F4 series have a completely new GPIO peripheral with
 * different configuration options. Here we implement a different API partly to
 * more closely match the peripheral capabilities and also to deliberately
 * break compatibility with old F1 code so there is no confusion with similar
 * sounding functions that have very different functionality.
 */

void gpio_mode_setup(uint32_t gpioport, uint8_t mode, uint8_t pull_up_down,
		     uint16_t gpios);
void gpio_set_output_options(uint32_t gpioport, uint8_t otype, uint8_t speed,
			     uint16_t gpios);
void gpio_set_af(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios);

END_DECLS
/**@}*/
#endif
/** @cond */
#else
#warning "gpio_common_f234.h should not be included explicitly, only via gpio.h"
#endif
/** @endcond */

