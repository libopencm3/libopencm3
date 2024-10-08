/** @defgroup rcc_defines RCC Defines
 *
 * @ingroup STM32U5xx_defines
 *
 * @brief <b>Defined Constants and Types for the STM32U5xx Reset and Clock
 * Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2015 Karl Palsson <karlp@tweak.net.au>
 *
 * @date 05 October 2024
 *
 * LGPL License Terms @ref lgpl_license
 *  */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2015 Karl Palsson <karlp@tweak.net.au>
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
 *
 */

/**@{*/

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define RCC_CR		MMIO32(RCC_BASE + 0x00)
#define RCC_CFGR	MMIO32(RCC_BASE + 0x1c)
#define RCC_CFGR2	MMIO32(RCC_BASE + 0x20)
#define RCC_CFGR3	MMIO32(RCC_BASE + 0x24)


/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- RCC_CR values ------------------------------------------------------- */

#define RCC_CR_HSEBYP	(1 << 18)

/* --- RCC_CFGR values ----------------------------------------------------- */

#define RCC_CFGR_MCO_SHIFT	24
#define RCC_CFGR_MCO_MASK	0xf

/* --- RCC_BDCR values ----------------------------------------------------- */

#define RCC_BDCR			MMIO32(RCC_BASE + 0xF0)
#define RCC_BDCR_LSEBYP		(1 << 2)

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

enum rcc_osc {
	RCC_PLL,
	RCC_HSE,
	RCC_HSI,
	RCC_HSI16,
	RCC_MSIS,
	RCC_MSIK,
	RCC_LSI,
	RCC_LSE,
	RCC_HSI48,
	RCC_SHSI,
};

#define _REG_BIT(base, bit)		(((base) << 5) + (bit))

enum rcc_periph_rst {
	/* AHB2 peripherals */
	RST_GPIOA	= _REG_BIT(0x64, 0),
	RST_GPIOB	= _REG_BIT(0x64, 1),
	RST_GPIOC	= _REG_BIT(0x64, 2),
	RST_GPIOD	= _REG_BIT(0x64, 3),
	RST_GPIOE	= _REG_BIT(0x64, 4),
	RST_GPIOF	= _REG_BIT(0x64, 5),
	RST_GPIOG	= _REG_BIT(0x64, 6),
	RST_GPIOH	= _REG_BIT(0x64, 7),
};


enum rcc_periph_clken {
	/* AHB2 peripherals */
	RCC_GPIOA	= _REG_BIT(0x8C, 0),
	RCC_GPIOB	= _REG_BIT(0x8C, 1),
	RCC_GPIOC	= _REG_BIT(0x8C, 2),
	RCC_GPIOD	= _REG_BIT(0x8C, 3),
	RCC_GPIOE	= _REG_BIT(0x8C, 4),
	RCC_GPIOF	= _REG_BIT(0x8C, 5),
	RCC_GPIOG	= _REG_BIT(0x8C, 6),
	RCC_GPIOH	= _REG_BIT(0x8C, 7),
};
#undef _REG_BIT

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

#include <libopencm3/stm32/common/rcc_common_all.h>

BEGIN_DECLS

END_DECLS

/**@}*/

#endif
