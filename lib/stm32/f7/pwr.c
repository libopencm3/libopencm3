/** @defgroup pwr_file PWR
 *
 * @ingroup STM32F7xx
 *
 * @brief <b>libopencm3 STM32F7xx Power Control</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2011 Stephen Caudle <scaudle@doceme.com>
 * @author @htmlonly &copy; @endhtmlonly 2017 Matthew Lai <m@matthewlai.ca>
 *
 * @date 12 March 2017
 *
 * This library supports the power control system for the
 * STM32F7 series of ARM Cortex Microcontrollers by ST Microelectronics.
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

void pwr_set_vos_scale(enum pwr_vos_scale scale)
{
	PWR_CR1 &= ~PWR_CR1_VOS_MASK;

	if (scale == PWR_SCALE1) {
		PWR_CR1 |= PWR_CR1_VOS_SCALE_1;
	} else if (scale == PWR_SCALE2) {
		PWR_CR1 |= PWR_CR1_VOS_SCALE_2;
	} else if (scale == PWR_SCALE3) {
		PWR_CR1 |= PWR_CR1_VOS_SCALE_3;
	}
}

void pwr_enable_overdrive(void)
{
	PWR_CR1 |= PWR_CR1_ODEN;
	while (!(PWR_CSR1 & PWR_CSR1_ODRDY));
	PWR_CR1 |= PWR_CR1_ODSWEN;
	while (!(PWR_CSR1 & PWR_CSR1_ODSWRDY));
}

void pwr_disable_overdrive(void)
{
	PWR_CR1 &= ~(PWR_CR1_ODEN | PWR_CR1_ODSWEN);
	while (!(PWR_CSR1 & PWR_CSR1_ODSWRDY));
}
