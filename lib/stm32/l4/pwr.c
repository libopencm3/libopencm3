/** @defgroup pwr_file PWR
 *
 * @ingroup STM32L4xx
 *
 * @brief <b>libopencm3 STM32L4xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Benjamin Levine <benjamin@jesco.karoo.co.uk>
 *
 * @date 4 March 2013
 *
 * This library supports the power control system for the
 * STM32L4 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Benjamin Levine <benjamin@jesco.karoo.co.uk>
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
/**@{*/
#include <libopencm3/stm32/pwr.h>

void pwr_set_vos_scale(enum pwr_vos_scale scale)
{
	uint32_t reg32;

	reg32 = PWR_CR1;
	reg32 &= ~(PWR_CR1_VOS_MASK << PWR_CR1_VOS_SHIFT);
	switch (scale) {
	case PWR_SCALE1:
		reg32 |= (PWR_CR1_VOS_RANGE_1 << PWR_CR1_VOS_SHIFT);
		break;
	case PWR_SCALE2:
		reg32 |= (PWR_CR1_VOS_RANGE_2 << PWR_CR1_VOS_SHIFT);
		break;
	}
	PWR_CR1 = reg32;
}
/**@}*/
