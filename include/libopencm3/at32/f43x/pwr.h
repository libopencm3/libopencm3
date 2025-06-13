/** @defgroup pwr_defines PWR Defines

@brief <b>Defined Constants and Types for the AT32F43x PWR Control</b>

@ingroup AT32F43x_defines

@version 1.0.0

@date 16 November 2024

LGPL License Terms @ref lgpl_license
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

#ifndef LIBOPENCM3_PWR_H
#define LIBOPENCM3_PWR_H

#include <libopencm3/stm32/common/pwr_common_v1.h>

/* --- PWR registers (continued) ------------------------------------------- */

/** LDO output voltage select register (PWC_LDOOV) */
#define PWR_LDO		MMIO32(POWER_CONTROL_BASE + 0x10)
/* LDOOVSEL	[ 2: 0] */
#define PWR_LDO_OV	7

#define	PWR_LDO_OV_12V	0
#define	PWR_LDO_OV_13V	1
#define	PWR_LDO_OV_11V	4
#define	PWR_LDO_OV_10V	5


/* --- PWR function prototypes ------------------------------------------- */

enum pwr_vos_scale {
	PWR_SCALE1	= PWR_LDO_OV_11V,
	PWR_SCALE2	= PWR_LDO_OV_12V,
	PWR_SCALE3	= PWR_LDO_OV_13V
};

BEGIN_DECLS

void pwr_set_vos_scale(enum pwr_vos_scale scale);

END_DECLS

#endif
