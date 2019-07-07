/** @defgroup syscfg_defines SYSCFG Defines
 *
 * @brief Defined Constants and Types for the STM32L4Rxx/STM32L4Sxx Sysconfig
 *
 * @ingroup STM32L4PLUSxx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2019 Guillaume Meunier <guillaume.meunier@centraliens.net>
 *
 * @date 2 July 2019
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 Guillaume Meunier <guillaume.meunier@centraliens.net>
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

#ifndef LIBOPENCM3_SYSCFG_H
#define LIBOPENCM3_SYSCFG_H

#include <libopencm3/stm32/common/syscfg_common_l4.h>

/* --- SYSCFG_MEMRMP Values ------------------------------------------------ */

#define SYSCFG_MEMRMP_MEM_MODE_OSPI1	4
#define SYSCFG_MEMRMP_MEM_MODE_OSPI2	5

/* --- SYSCFG_CFGR1 Values ------------------------------------------------- */

#define SYSCFG_CFGR1_I2C4_FMP		(1 << 23)
#define SYSCFG_CFGR1_ANASWVDD		(1 << 9)

/* --- SYSCFG_EXTICR Values -------------------------------------------------*/

#define SYSCFG_EXTICR_GPIOF		5
#define SYSCFG_EXTICR_GPIOG		6
#define SYSCFG_EXTICR_GPIOI		8

#endif
