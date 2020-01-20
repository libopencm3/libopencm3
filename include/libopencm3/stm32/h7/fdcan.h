/** @defgroup fdcan_defines FDCAN defines
 * @ingroup STM32H7_defines
 * @brief <b>libopencm3 Defined Constants and Types for STM32 FDCAN on the H7</b>
 * @version 1.0.0
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2020 Matt Walker <m@allocor.tech>
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

#ifndef LIBOPENCM3_STM32_FDCAN_H
#define LIBOPENCM3_STM32_FDCAN_H

#include <libopencm3/stm32/common/fdcan_common.h>

/**@{
 * @defgroup fdcan_reg_base CAN register base address
 * @ingroup fdcan_defines
 * @{*/
#define FDCAN1 FDCAN1_BASE
#define FDCAN2 FDCAN2_BASE
/**@}*/

/** Length in words of the shared FDCAN message RAM
 * @ingroup fdcan_defines
 */
#define FDCAN_MESSAGE_RAM_WORDLEN 2560

/** fdcan_bittiming_const structure for CAN2.0 / nominal rate operation
 * @ingroup fdcan_defines
 */
#define FDCAN_NOMINAL_BITTIMING_CONST                             \
	{                                                         \
		.tseg1_min = 1, .tseg1_max = 256, .tseg2_min = 1, \
		.tseg2_max = 128, .sjw_max = 128, .brp_min = 1,   \
		.brp_max = 512, .brp_inc = 1,                     \
	}

/** fdcan_bittiming_const structure for FD rate operation
 * @ingroup fdcan_defines
 */
#define FDCAN_FD_BITTIMING_CONST                                             \
	{                                                                    \
		.tseg1_min = 1, .tseg1_max = 32, .tseg2_min = 1,             \
		.tseg2_max = 16, .sjw_max = 16, .brp_min = 1, .brp_max = 32, \
		.brp_inc = 1,                                                \
	}

#endif
