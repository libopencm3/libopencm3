/** @addtogroup timer_defines

@author @htmlonly &copy; @endhtmlonly 2022 Oskar Hieronymus Maier <ohma@posteo.de>
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

#pragma once
#include <libopencm3/stm32/common/timer_common_all.h>

/* --- TIMx_CR2 values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_x_cr2_ois TIMx_CR2_OIS: Force Output Idle State Control Values
@{*/
/* OIS4N:*//** Output idle state 4 (OC4N output) */
#define TIM_CR2_OIS4N			(1 << 15)

/* OIS5:*//** Output idle state 5 (OC5 output) */
#define TIM_CR2_OIS5N			(1 << 16)

/* OIS6:*//** Output idle state 6 (OC6 output) */
#define TIM_CR2_OIS6N			(1 << 18)
#define TIM_CR2_OIS_MASK		(0xfff << 8)
/**@}*/

/* MMS[3:0]: Master mode selection */
/****************************************************************************/
/** @defgroup tim_mastermode TIMx_CR2 MMS and MMS2: Master Mode Selection (2)
@{*/
#define TIM_CR2_MMS_SHIFT               (4)
#define TIM_CR2_MMS_BIT3_SHIFT          (22)
#define TIM_CR2_MMS2_SHIFT              (20)
#define TIM_CR2_MMS_MASK		((0x8 << TIM_CR2_MMS_BIT3_SHIFT) | (0x7 << TIM_CR2_MMS_SHIFT))
#define TIM_CR2_MMS2_MASK		(0xf << TIM_CR2_MMS2_SHIFT)
/**@}*/

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void timer_set_master_mode_2(uint32_t timer_peripheral, uint32_t mode)

END_DECLS

#endif
/** @cond */
#else
#warning "timer_common_v2.h should not be included explicitly, only via timer.h"
#endif
/** @endcond */

/**@}*/
