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

#include <libopencm3/stm32/common/pwr_common_all.h>

/*
 * This file extends the common STM32 version with definitions only
 * applicable to the STM32L1 series of devices.
 */

/* --- PWR_CR values ------------------------------------------------------- */

/* Bits [31:15]: Reserved */

/* LPRUN: Low power run mode */
#define PWR_CR_LPRUN        (1 << 14)

/* VOS[12:11]: Regulator voltage scaling output selection */
#define PWR_CR_VOS_LSB			11
/** @defgroup pwr_vos Voltage Scaling Output level selection
@ingroup pwr_defines

@{*/
#define PWR_CR_VOS_RANGE1		(0x1 << PWR_CR_VOS_LSB)
#define PWR_CR_VOS_RANGE2		(0x2 << PWR_CR_VOS_LSB)
#define PWR_CR_VOS_RANGE3		(0x3 << PWR_CR_VOS_LSB)
/**@}*/
#define PWR_CR_VOS_MASK			(0x3 << PWR_CR_VOS_LSB)

/* FWU: Fast wakeup */
#define PWR_CR_FWU          (1 << 10)

/* ULP: Ultralow power mode */
#define PWR_CR_ULP          (1 << 9)

/* LPSDSR: Low-power deepsleep/sleep/low power run */
#define PWR_CR_LPSDSR		(1 << 0)  /* masks common PWR_CR_LPDS */

/* --- PWR_CSR values ------------------------------------------------------- */

/* Bits [31:11]: Reserved */
/* EWUP3: Enable WKUP3 pin */
#define PWR_CSR_EWUP3			(1 << 10)

/* EWUP2: Enable WKUP2 pin */
#define PWR_CSR_EWUP2			(1 << 9)

/* EWUP1: Enable WKUP1 pin */
#define PWR_CSR_EWUP1			PWR_CSR_EWUP

/* REGLPF : Regulator LP flag */
#define PWR_CSR_REGLPF          (1 << 5)

/* VOSF: Voltage Scaling select flag */
#define PWR_CSR_VOSF            (1 << 4)

/* VREFINTRDYF: Internal voltage reference (VREFINT) ready flag */
#define PWR_CSR_VREFINTRDYF	(1 << 3)



/* --- Function prototypes ------------------------------------------------- */

typedef enum {
	RANGE1,
	RANGE2,
	RANGE3,
} vos_scale_t;

BEGIN_DECLS

void pwr_set_vos_scale(vos_scale_t scale);

END_DECLS

#endif
