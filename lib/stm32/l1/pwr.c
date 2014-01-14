/** @defgroup pwr_file PWR
 *
 * @ingroup STM32L1xx
 *
 * @brief <b>libopencm3 STM32L1xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@tweak.net.au>
 *
 * @date 4 March 2013
 *
 * This library supports the power control system for the
 * STM32L1 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
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

#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>

void pwr_set_vos_scale(vos_scale_t scale)
{
	/* You are not allowed to write zeros here, don't try and optimize! */
	uint32_t reg = PWR_CR;
	reg &= ~(PWR_CR_VOS_MASK);
	switch (scale) {
	case RANGE1:
		reg |= PWR_CR_VOS_RANGE1;
		break;
	case RANGE2:
		reg |= PWR_CR_VOS_RANGE2;
		break;
	case RANGE3:
		reg |= PWR_CR_VOS_RANGE3;
		break;
	}
	PWR_CR = reg;
}

