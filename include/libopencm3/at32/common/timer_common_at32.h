/** @addtogroup timer_defines
 *
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

/** @cond */
#ifdef LIBOPENCM3_TIMER_H
/** @endcond */
#ifndef LIBOPENCM3_TIMER_COMMON_AT32_H
#define LIBOPENCM3_TIMER_COMMON_AT32_H

/**@{*/

#include <libopencm3/stm32/common/timer_common_all.h>

/* --- TIMx_CR1 values (continued) ----------------------------------------- */
#define TIM_CR1_PMEN			(1 << 10)

/** Input Capture input polarity */
enum tim_ic_pol {
	TIM_IC_RISING,
	TIM_IC_FALLING,
};

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void timer_enable_plus_mode(uint32_t timer);
void timer_disable_plus_mode(uint32_t timer);
void timer_ic_set_polarity(uint32_t timer,
			   enum tim_ic_id ic,
			   enum tim_ic_pol pol);
END_DECLS

/**@}*/
#endif
/** @cond */
#else
#warning "timer_common_at32.h should not be included explicitly, only via timer.h"
#endif
/** @endcond */
