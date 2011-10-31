/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_PWR_F4_H
#define LIBOPENCM3_PWR_F4_H

#include <libopencm3/stm32/pwr.h>

/*
 * This file extends the version in stm_common with definitions only
 * applicable to the STM32F4 series of devices.
 */

/* --- PWR_CR values ------------------------------------------------------- */

/* VOS: Regulator voltage scaling output selection */
#define PWR_CR_VOS			(1 << 14)

/* FPDS: Flash power down in stop mode, only available in F2 family devices. */
#define PWR_CR_FPDS			(1 << 9)

/* --- PWR_CSR values ------------------------------------------------------ */

/* VOSRDY: Regulator voltage scaling output selection ready */
#define PWR_CSR_VOSRDY			(1 << 14)

/* BRE: Backup regulator enable */
#define PWR_CSR_BRE			(1 << 9)

/* BRR: Backup regulator ready */
#define PWR_CSR_BRR			(1 << 3)

/* --- Function prototypes ------------------------------------------------- */

typedef enum {
	SCALE1, SCALE2
} vos_scale_t;

void pwr_set_vos_scale(vos_scale_t scale);

#endif
