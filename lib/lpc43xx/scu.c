/** @defgroup scu_file System Control Unit

@ingroup LPC43xx

@brief <b>libopencm3 LPC43xx System Control Unit</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Benjamin Vernoux <titanmkd@gmail.com>

LGPL License Terms @ref lgpl_license
*/

/*
* This file is part of the libopencm3 project.
*
* Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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

#include <libopencm3/lpc43xx/scu.h>

/* For pin_conf_normal value see scu.h define SCU_CONF_XXX or Configuration for
 * different I/O pins types
 */
void scu_pinmux(scu_grp_pin_t group_pin, uint32_t scu_conf)
{
	MMIO32(group_pin) = scu_conf;
}

/* For other special SCU register USB1, I2C0, ADC0/1, DAC, EMC clock delay See
 * scu.h
 */

/* For Pin interrupt select register see scu.h SCU_PINTSEL0 & SCU_PINTSEL1 */

/**@}*/

