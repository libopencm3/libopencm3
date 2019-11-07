/** @defgroup pwr_file PWR peripheral API
 *
 * @ingroup peripheral_apis
 *
 * @brief <b>libopencm3 STM32H7xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2011 Stephen Caudle <scaudle@doceme.com>
 * @author @htmlonly &copy; @endhtmlonly 2017 Matthew Lai <m@matthewlai.ca>
 *
 * @date 12 March 2017
 *
 * This library supports the power control system for the
 * STM32H7 series of ARM Cortex Microcontrollers by ST Microelectronics.
 *
 * LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 * Copyright (C) 2017 Matthew Lai <m@matthewlai.ca>
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

/**@{*/

void pwr_set_svos_scale(enum pwr_svos_scale scale)
{
	uint32_t pwr_cr1_reg = PWR_CR1;
	pwr_cr1_reg = (pwr_cr1_reg & ~PWR_CR1_SVOS_MASK) | scale;
	PWR_CR1 = pwr_cr1_reg;
}

/**@}*/