/** @defgroup dcmi_defines DCMI Defines
 *
 * @ingroup STM32F7xx_defines
 *
 * @brief Defined Constants and Macros for the STM32F7xx DCMI Peripheral
 *
 * @version 1.0.0
 *
 * @date 2020-05-15
 *
 * LGPL License Terms @ref lgpl_license
 */


/*
 * Copyright (C) 2020, Smolyaninov Nikolay <smolin35@gmail.org>
 *
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
 *
 */

#ifndef LIBOPENCM3_DCMI_H
#define LIBOPENCM3_DCMI_H

#include <libopencm3/stm32/common/dcmi_common_f47.h>

/**
 * @defgroup dcmi_cr_values DCMI_CR Values
 * @ingroup dcmi_defines
 * @{
 */
#define DCMI_CR_OELS			(1 << 20)
#define DCMI_CR_LSM			(1 << 19)
#define DCMI_CR_OEBS			(1 << 18)
#define DCMI_CR_BSM1			(1 << 17)
#define DCMI_CR_BSM0			(1 << 16)


/**@}*/

#endif
