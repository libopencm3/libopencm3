/** @defgroup timer_defines Timer Defines

@brief <b>libopencm3 Defined Constants and Types for the STM32F1xx Timers</b>

@ingroup STM32F1xx_defines

@version 1.0.0

@date 8 March 2013

@author @htmlonly &copy; @endhtmlonly 2011 Fergus Noble <fergusnoble@gmail.com>

LGPL License Terms @ref lgpl_license
*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

#pragma once

#include <libopencm3/stm32/common/timer_common_all.h>

/** Input Capture input polarity */
enum tim_ic_pol {
	TIM_IC_RISING,
	TIM_IC_FALLING,
};

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void timer_ic_set_polarity(uint32_t timer,
			   enum tim_ic_id ic,
			   enum tim_ic_pol pol);

END_DECLS
