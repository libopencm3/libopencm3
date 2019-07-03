/** @defgroup lptimer_defines LPTIM Defines
 *
 * @ingroup STM32G0xx_defines
 * 
 * @brief <b>libopencm3 Defined Constants and Types for the STM32G0xx Low Power Timer</b>
 *
 * @version 1.0.0
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Guillaume Revaillot <g.revaillot@gmail.com>
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

#ifndef LIBOPENCM3_LPTIMER_H
#define LIBOPENCM3_LPTIMER_H
/**@{*/

#include <libopencm3/stm32/common/lptimer_common_all.h>

/** @defgroup lptim_reg_base Low Power Timer register base addresses
@{*/
#define LPTIM1				LPTIM1_BASE
#define LPTIM2				LPTIM2_BASE
/**@}*/

/** LPTIM_CFGR2 LPTIM configuration register 2 */
#define LPTIM_CFGR2(tim_base)			MMIO32((tim_base) + 0x24)

/** @addtogroup lptim_cr
@{*/
/** COUNTRST Counter reset **/
#define LPTIM_CR_COUNTRST		(1 << 3)
/** RSTARE Reset after read enable **/
#define LPTIM_CR_RSTARE		(1 << 4)
/**@}*/

/** @defgroup lptim_cfgr2 LPTIM_CFGR2 Configuration Register 2
@{*/

#define LPTIM_CFGR2_IN2SEL_SHIFT	4
#define LPTIM_CFGR2_IN2SEL_MASK		0x03

#define LPTIM_CFGR2_IN1SEL_SHIFT	0
#define LPTIM_CFGR2_IN1SEL_MASK		0x03

/**@}*/


BEGIN_DECLS

END_DECLS

/**@}*/
#endif
