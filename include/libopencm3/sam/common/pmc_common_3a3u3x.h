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

#if defined(LIBOPENCM3_PMC_H)

#ifndef LIBOPENCM3_PMC_COMMON_3A3U3X_H
#define LIBOPENCM3_PMC_COMMON_3A3U3X_H


/* --- Power Management Controller (PMC) registers ----------------------- */

/* UTMI Clock Register */
#define CKGR_UCKR			MMIO32(PMC_BASE + 0x001C)


/* --- Register contents --------------------------------------------------- */


/* --- PMC UTMI Clock Configuration Register (CKGR_UCKR) ------------------- */

/* UTMI PLL Start-up Time */
#define CKGR_UCKR_UPLLCOUNT_SHIFT	20
#define CKGR_UCKR_UPLLCOUNT_MASK	(0x0F << CKGR_UCKR_UPLLCOUNT_SHIFT)

/* UTMI PLL Enable */
#define CKGR_UCKR_UPLLEN		(0x01 << 16)

/* --- PMC Master Clock Register (PMC_MCKR) -------------------------------- */

/* UPLL Divide by 2 */
#define PMC_MCKR_UPLLDIV2		(0x01 << 13)

/* Master Clock Source Selection */
#define PMC_MCKR_CSS_UPLL_CLK		(3 << PMC_MCKR_CSS_SHIFT)


/* --- PMC Programmable Clock Register 0 (PMC_PCK0) ------------------------ */

/* Master Clock Source Selection */
#define PMC_PCK0_CSS_UPLL_CLK		(3 << PMC_PCK0_CSS_SHIFT)


/* --- PMC Programmable Clock Register 1 (PMC_PCK1) ------------------------ */

/* Master Clock Source Selection */
#define PMC_PCK1_CSS_UPLL_CLK		(3 << PMC_PCK1_CSS_SHIFT)


/* --- PMC Programmable Clock Register 2 (PMC_PCK2) ------------------------ */

/* Master Clock Source Selection */
#define PMC_PCK2_CSS_UPLL_CLK		(3 << PMC_PCK2_CSS_SHIFT)


/* --- PMC Interrupt Enable Register (PMC_IER) ----------------------------- */

/* UTMI PLL Lock Interrupt Enable */
#define PMC_IER_LOCKU			(0x01 << 6)


/* --- PMC Interrupt Disable Register (PMC_IDR) ----------------------------- */

/* UTMI PLL Lock Interrupt Disable */
#define PMC_IDR_LOCKU			(0x01 << 6)


/* --- PMC Status Register (PMC_SR) ---------------------------------------- */

/* UTMI PLL Lock Status */
#define PMC_SR_LOCKU			(0x01 << 6)


/* --- PMC Interrupt Mask Register (PMC_IMR) ----------------------------- */

/* UTMI PLL Lock Interrupt Mask */
#define PMC_IMR_LOCKU			(0x01 << 6)


#endif

#else
#warning "pmc_common_3a3u3x.h should not be included explicitly, only via pmc.h"
#endif
