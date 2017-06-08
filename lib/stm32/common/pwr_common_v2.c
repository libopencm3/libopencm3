/** @addtogroup pwr_file
 *
 * @author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@tweak.net.au>
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
/**@{*/

#include <libopencm3/stm32/pwr.h>
#include <libopencm3/stm32/rcc.h>

void pwr_set_vos_scale(enum pwr_vos_scale scale)
{
	/* You are not allowed to write zeros here, don't try and optimize! */
	uint32_t reg = PWR_CR;
	reg &= ~(PWR_CR_VOS_MASK);
	switch (scale) {
	case PWR_SCALE1:
		reg |= PWR_CR_VOS_RANGE1;
		break;
	case PWR_SCALE2:
		reg |= PWR_CR_VOS_RANGE2;
		break;
	case PWR_SCALE3:
		reg |= PWR_CR_VOS_RANGE3;
		break;
	}
	PWR_CR = reg;
}

/**@}*/

