/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2015 Felix Held <felix-libopencm3@felixheld.de>
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

#ifndef LIBOPENCM3_PMC_H
#define LIBOPENCM3_PMC_H

#include <libopencm3/sam/memorymap.h>
#include <libopencm3/sam/common/pmc_common_all.h>
#include <libopencm3/sam/common/pmc_common_3a3s3x.h>
#include <libopencm3/sam/common/pmc_common_3a3u3x.h>

/* --- Power Management Controller (PMC) registers ----------------------- */

/* Peripheral Control Register */
#define PMC_PCR				MMIO32(PMC_BASE + 0x010C)


/* --- Register contents --------------------------------------------------- */


/* --- PMC Master Clock Register (PMC_MCKR) -------------------------------- */

/* PLLA Divide by 2 */
#define PMC_MCKR_PLLADIV2		(0x01 << 12)


/* --- PMC Peripheral Control Register (PMC_PCR) --------------------------- */

/* Enable */
#define PMC_PCR_EN			(0x01 << 28)

/* Divisor Value */
#define PMC_PCR_DIV_SHIFT		16
#define PMC_PCR_DIV_MASK		(0x03 << PMC_PCR_DIV_SHIFT)
#define PMC_PCR_DIV_PERIPH_DIV_MCK	(0x00 << PMC_PCR_DIV_SHIFT)
#define PMC_PCR_DIV_PERIPH_DIV2_MCK	(0x01 << PMC_PCR_DIV_SHIFT)
#define PMC_PCR_DIV_PERIPH_DIV4_MCK	(0x02 << PMC_PCR_DIV_SHIFT)

/* Command */
#define PMC_PCR_CMD			(0x01 << 12)

/* Peripheral ID */
#define PMC_PCR_PID_SHIFT		0
#define PMC_PCR_PID_MASK		(0x3F << PMC_PCR_PID_SHIFT)


#endif
