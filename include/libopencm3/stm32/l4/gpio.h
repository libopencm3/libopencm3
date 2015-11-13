/** @defgroup gpio_defines GPIO Defines
 *
 * @brief <b>Defined Constants and Types for the STM32L4xx General Purpose I/O</b>
 *
 * @ingroup STM32L4xx_defines
 *
 * @version 1.0.0
 *
 * @date 12 November 2015
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
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

#include <libopencm3/stm32/common/gpio_common_f24.h>

/*****************************************************************************/
/* Module definitions                                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

#define GPIO_BRR(port)			MMIO32((port) + 0x28)
#define GPIOA_BRR			GPIO_BRR(GPIOA)
#define GPIOB_BRR			GPIO_BRR(GPIOB)
#define GPIOC_BRR			GPIO_BRR(GPIOC)
#define GPIOD_BRR			GPIO_BRR(GPIOD)
#define GPIOE_BRR			GPIO_BRR(GPIOE)
#define GPIOF_BRR			GPIO_BRR(GPIOF)
#define GPIOG_BRR			GPIO_BRR(GPIOG)
#define GPIOH_BRR			GPIO_BRR(GPIOH)

#define GPIO_ASC(port)			MMIO32((port) + 0x2c)
#define GPIOA_ASC			GPIO_ASC(GPIOA)
#define GPIOB_ASC			GPIO_ASC(GPIOB)
#define GPIOC_ASC			GPIO_ASC(GPIOC)
#define GPIOD_ASC			GPIO_ASC(GPIOD)
#define GPIOE_ASC			GPIO_ASC(GPIOE)
#define GPIOF_ASC			GPIO_ASC(GPIOF)
#define GPIOG_ASC			GPIO_ASC(GPIOG)
#define GPIOH_ASC			GPIO_ASC(GPIOH)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/** @defgroup gpio_speed GPIO Output Pin Speed
@ingroup gpio_defines
@{*/
#define GPIO_OSPEED_LOW		0x0
#define GPIO_OSPEED_MED		0x1
#define GPIO_OSPEED_FAST	0x2
#define GPIO_OSPEED_HIGH	0x3
/**@}*/

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

END_DECLS

#endif
