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

#ifndef LIBOPENCM3_TIMER_H
#define LIBOPENCM3_TIMER_H

#include <libopencm3/efm32/common/timer_common_hglg.h>

/* efm32hg specific registers */

/* TIMER_ROUTE */
#define TIMER_ROUTE_LOCATION_LOC6	TIMER_ROUTE_LOCATION_LOCx(6)

/* TIMER_CCx_CTRL */
#define TIMER_CC_CTRL_PRSCONF		(1 << 28)

#define TIMER_CC_CTRL_PRSSEL_SHIFT	(16)
#define TIMER_CC_CTRL_PRSSEL_MASK	(0x7 << TIMER_CC_CTRL_PRSSEL_SHIFT)
#define TIMER_CC_CTRL_PRSSEL(v)		\
	(((v) << TIMER_CC_CTRL_PRSSEL_SHIFT) & TIMER_CC_CTRL_PRSSEL_MASK)
#define TIMER_CC_CTRL_PRSSEL_PRSCHx(x)	TIMER_CC_CTRL_PRSSEL(x)
#define TIMER_CC_CTRL_PRSSEL_PRSCH0	TIMER_CC_CTRL_PRSSEL_PRSCHx(0)
#define TIMER_CC_CTRL_PRSSEL_PRSCH1	TIMER_CC_CTRL_PRSSEL_PRSCHx(1)
#define TIMER_CC_CTRL_PRSSEL_PRSCH2	TIMER_CC_CTRL_PRSSEL_PRSCHx(2)
#define TIMER_CC_CTRL_PRSSEL_PRSCH3	TIMER_CC_CTRL_PRSSEL_PRSCHx(3)
#define TIMER_CC_CTRL_PRSSEL_PRSCH4	TIMER_CC_CTRL_PRSSEL_PRSCHx(4)
#define TIMER_CC_CTRL_PRSSEL_PRSCH5	TIMER_CC_CTRL_PRSSEL_PRSCHx(5)

/* TIMER_DTCTRL */
#define TIMER_DTCTRL_DTPRSSEL_SHIFT	(4)
#define TIMER_DTCTRL_DTPRSSEL_MASK	(0x7 << TIMER_DTCTRL_DTPRSSEL_SHIFT)
#define TIMER_DTCTRL_DTPRSSEL(v)	\
	(((v) << TIMER_DTCTRL_DTPRSSEL_SHIFT) & TIMER_DTCTRL_DTPRSSEL_MASK)
#define TIMER_DTCTRL_DTPRSSEL_PRSCHx(x)	TIMER_DTCTRL_DTPRSSEL(x)
#define TIMER_DTCTRL_DTPRSSEL_PRSCH0	TIMER_DTCTRL_DTPRSSEL_PRSCHx(0)
#define TIMER_DTCTRL_DTPRSSEL_PRSCH1	TIMER_DTCTRL_DTPRSSEL_PRSCHx(1)
#define TIMER_DTCTRL_DTPRSSEL_PRSCH2	TIMER_DTCTRL_DTPRSSEL_PRSCHx(2)
#define TIMER_DTCTRL_DTPRSSEL_PRSCH3	TIMER_DTCTRL_DTPRSSEL_PRSCHx(3)
#define TIMER_DTCTRL_DTPRSSEL_PRSCH4	TIMER_DTCTRL_DTPRSSEL_PRSCHx(4)
#define TIMER_DTCTRL_DTPRSSEL_PRSCH5	TIMER_DTCTRL_DTPRSSEL_PRSCHx(5)

#endif
