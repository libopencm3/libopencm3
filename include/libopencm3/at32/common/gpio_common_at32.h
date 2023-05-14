/** @addtogroup gpio_defines
 *
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

/** @cond */
#ifdef LIBOPENCM3_GPIO_H
/** @endcond */
#ifndef LIBOPENCM3_GPIO_COMMON_AT32_H
#define LIBOPENCM3_GPIO_COMMON_AT32_H

/**@{*/

#include <libopencm3/stm32/common/gpio_common_f234.h>

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

#define GPIO_HDRV(port)			MMIO32((port) + 0x3c)
#define GPIOA_HDRV			GPIO_HDRV(GPIOA)
#define GPIOB_HDRV			GPIO_HDRV(GPIOB)
#define GPIOC_HDRV			GPIO_HDRV(GPIOC)
#define GPIOD_HDRV			GPIO_HDRV(GPIOD)
#define GPIOE_HDRV			GPIO_HDRV(GPIOE)
#define GPIOF_HDRV			GPIO_HDRV(GPIOF)
#define GPIOG_HDRV			GPIO_HDRV(GPIOG)
#define GPIOH_HDRV			GPIO_HDRV(GPIOH)

/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/** @defgroup gpio_speed GPIO Output Pin Speed
@ingroup gpio_defines
@{*/
#define GPIO_OSPEED_LOW		0
#define GPIO_OSPEED_MED		1
#define GPIO_OSPEED_HIGH	2
#define GPIO_OSPEED_VERYHIGH	3
/**@}*/

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

/** @cond */
#ifndef GPIO_SET_OUTPUT_OPTIONS
#define gpio_set_output_options _gpio_set_output_options
void _gpio_set_output_options(uint32_t, uint8_t, uint8_t, uint16_t);
#endif
/** @endcond */

/**@}*/
#endif
/** @cond */
#else
#warning "gpio_common_at32.h should not be included explicitly, only via gpio.h"
#endif
/** @endcond */
