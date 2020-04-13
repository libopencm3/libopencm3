/** @defgroup i2c_defines I2C Defines

@brief <b>Defined Constants and Types for the STM32F4xx I2C </b>

@ingroup STM32F4xx_defines

@version 1.0.0

@date 12 October 2012

LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_I2C_H
#define LIBOPENCM3_I2C_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/common/i2c_common_v1.h>

/**
@addtogroup i2c_defines
@{*/

/** FLTR register (I2Cx_FLTR) (noise filter) */
#define I2C_FLTR(i2c_base)		MMIO32((i2c_base) + 0x24)
#define I2C1_FLTR			I2C_FLTR(I2C1)
#define I2C2_FLTR			I2C_FLTR(I2C2)
#define I2C3_FLTR			I2C_FLTR(I2C3)

/**
 * Bits [3:0] DNF - Digital noise filter
 * These bits configure a digital noise filter on SDA and SCL pins.
 * Value sets minimum pulse width needed to trigger i2c operations.
 * 0 disables, 1 - 15 set minimum width to 'n' * TPCLK1
 */
#define I2C_FLTR_DNF_MASK	0xF
#define I2C_FLTR_DNF_SHIFT	0

/**
 * Bit 4 - Analog Noise filter disable
 * Turns off the built in analog noise filter.
 */
#define I2C_FLTR_ANOFF		(1<<4)

/**@}*/

#endif

