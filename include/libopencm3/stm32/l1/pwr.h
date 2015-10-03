/** @defgroup pwr_defines PWR Defines

@brief <b>Defined Constants and Types for the STM32L1xx Power Control</b>

@ingroup STM32L1xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2011 Stephen Caudle <scaudle@doceme.com>
@author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@tweak.net.au>

@date 1 July 2012

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
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

#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H

#include <libopencm3/stm32/common/pwr_common_l01.h>

/*
 * This file extends the common STM32 version with definitions only
 * applicable to the STM32L1 series of devices.
 */

/* --- PWR_CSR values ------------------------------------------------------- */

/* Bits [31:11]: Reserved */
/* EWUP3: Enable WKUP3 pin */
#define PWR_CSR_EWUP3			(1 << 10)

#endif
