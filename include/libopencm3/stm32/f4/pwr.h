/** @defgroup pwr_defines PWR Defines

@brief <b>Defined Constants and Types for the STM32F4xx Power Control</b>

@ingroup STM32F4xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2011 Stephen Caudle <scaudle@doceme.com>

@date 4 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
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

/*
 * This file extends the common STM32 version with definitions only
 * applicable to the STM32F4 series of devices.
 */
/** @addtogroup pwr_defines
 * @{*/

/* --- PWR_CR values ------------------------------------------------------- */

/** UDEN[19:18]: Under-drive enable in stop mode */
#define PWR_CR_UDEN_LSB			18
/** @defgroup pwr_uden Under-drive enable in stop mode
@ingroup STM32F_pwr_defines

@{*/
#define PWR_CR_UDEN_DISABLED		(0x0 << PWR_CR1_UDEN_LSB)
#define PWR_CR_UDEN_ENABLED		(0x3 << PWR_CR1_UDEN_LSB)
/**@}*/
#define PWR_CR_UDEN_MASK		(0x3 << PWR_CR1_UDEN_LSB)

/** ODSWEN: Over-drive switching enabled */
#define PWR_CR_ODSWEN			(1 << 17)

/** ODEN: Over-drive enable */
#define PWR_CR_ODEN			(1 << 16)

/** VOS: Regulator voltage scaling output selection */
#define PWR_CR_VOS_SHIFT			14
#define PWR_CR_VOS_MASK			0x3

/** ADCDC1: Masks extra flash accesses by prefetch (see AN4073) */
#define PWR_CR_ADCDC1			(1 << 13)

/** MRLVDS/MRUDS: Main regulator Low Voltage / Under drive in Deep Sleep */
#define PWR_CR_MRLVDS			(1 << 11)
#define PWR_CR_MRUDS			PWR_CR_MRLVDS

/** LPLVDS/LPUDS: Low-power regulator Low Voltage / Under drive in Deep Sleep */
#define PWR_CR_LPLVDS			(1 << 10)
#define PWR_CR_LPUDS			PWR_CR_LPLVDS

/** FPDS: Flash power down in stop mode */
#define PWR_CR_FPDS			(1 << 9)

/* --- PWR_CSR values ------------------------------------------------------ */

/** ODSWRDY: Over-drive mode switching ready */
#define PWR_CSR_ODSWRDY			(1 << 17)

/** ODRDY: Over-drive mode ready */
#define PWR_CSR_ODRDY			(1 << 16)

/** VOSRDY: Regulator voltage scaling output selection ready bit */
#define PWR_CSR_VOSRDY			(1 << 14)

/** BRE: Backup regulator enable */
#define PWR_CSR_BRE			(1 << 9)

/** BRR: Backup regulator ready */
#define PWR_CSR_BRR			(1 << 3)

/* --- Function prototypes ------------------------------------------------- */

enum pwr_vos_scale {
	PWR_SCALE1 = 0x3,
	PWR_SCALE2 = 0x2,
	PWR_SCALE3 = 0x1,
};

BEGIN_DECLS

void pwr_set_vos_scale(enum pwr_vos_scale scale);
void pwr_enable_overdrive(void);
void pwr_disable_overdrive(void);

END_DECLS

/**@}*/

#endif
