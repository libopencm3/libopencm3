/*
 * This file is part of the libopencm3 project.
 *
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

/* --- Power Management Controller (PMC) registers ----------------------- */

/* PLLB Register */
#define CKGR_PLLBR			MMIO32(PMC_BASE + 0x002C)

/* Oscillator Calibration Register */
#define PMC_OCR				MMIO32(PMC_BASE + 0x0110)


/* --- Register contents --------------------------------------------------- */


/* --- PMC Clock Generator Main Clock Frequency Register (CKGR_MCFR) ------- */

/* RC Oscillator Frequency Measure (write-only, only on atsam3s8) */
#define CKGR_MCFR_RCMEAS		(0x01 << 20)


/* --- PMC Clock Generator PLLB Register (CKGR_PLLBR) ---------------------- */

/* PLLB Multiplier */
#define CKGR_PLLBR_MULB_SHIFT		16
#define CKGR_PLLBR_MULB_MASK		(0x7FF << CKGR_PLLBR_MULB_SHIFT)

/* PLLA Counter */
#define CKGR_PLLBR_PLLBCOUNT_SHIFT	8
#define CKGR_PLLBR_PLLBCOUNT_MASK	(0x3F << CKGR_PLLBR_PLLBCOUNT_SHIFT)

/* Divider */
#define CKGR_PLLBR_DIVB_SHIFT		0
#define CKGR_PLLBR_DIVB_MASK		(0xFF << CKGR_PLLBR_DIVB_SHIFT)


/* --- PMC Master Clock Register (PMC_MCKR) -------------------------------- */

/* PLLB Divide by 2 */
#define PMC_MCKR_PLLBDIV2		(0x01 << 13)

/* PLLA Divide by 2 */
#define PMC_MCKR_PLLADIV2		(0x01 << 12)

/* Master Clock Source Selection */
#define PMC_MCKR_CSS_PLLB_CLK		(3 << PMC_MCKR_CSS_SHIFT)


/* --- PMC Programmable Clock Register 0 (PMC_PCK0) ------------------------ */

/* Master Clock Source Selection */
#define PMC_PCK0_CSS_PLLB_CLK		(3 << PMC_PCK0_CSS_SHIFT)


/* --- PMC Programmable Clock Register 1 (PMC_PCK1) ------------------------ */

/* Master Clock Source Selection */
#define PMC_PCK1_CSS_PLLB_CLK		(3 << PMC_PCK1_CSS_SHIFT)


/* --- PMC Programmable Clock Register 2 (PMC_PCK2) ------------------------ */

/* Master Clock Source Selection */
#define PMC_PCK2_CSS_PLLB_CLK		(3 << PMC_PCK2_CSS_SHIFT)


/* --- PMC Interrupt Enable Register (PMC_IER) ----------------------------- */

/* PLLB Lock Interrupt Enable */
#define PMC_IER_LOCKB			(0x01 << 2)


/* --- PMC Interrupt Disable Register (PMC_IDR) ---------------------------- */

/* PLLB Lock Interrupt Disable */
#define PMC_IDR_LOCKB			(0x01 << 2)


/* --- PMC Status Register (PMC_SR) ---------------------------------------- */

/* PLLB Lock Status */
#define PMC_SR_LOCKB			(0x01 << 2)


/* --- PMC Interrupt Mask Register (PMC_IDR) ------------------------------- */

/* PLLB Lock Interrupt Mask */
#define PMC_IMR_LOCKB			(0x01 << 2)


/* --- PMC Oscillator Calibration Register (PMC_OCR) ----------------------- */

/* Selection of RC Oscillator Calibration bits for 12 Mhz */
#define PMC_OCR_SEL12			(0x01 << 23)

/* RC Oscillator Calibration bits for 12 Mhz */
#define PMC_OCR_CAL12_SHIFT		16
#define PMC_OCR_CAL12_MASK		(0x7F << PMC_OCR_CAL12_SHIFT)

/* Selection of RC Oscillator Calibration bits for 8 Mhz */
#define PMC_OCR_SEL8			(0x01 << 15)

/* RC Oscillator Calibration bits for 8 Mhz */
#define PMC_OCR_CAL8_SHIFT		8
#define PMC_OCR_CAL8_MASK		(0x7F << PMC_OCR_CAL8_SHIFT)

/* Selection of RC Oscillator Calibration bits for 4 Mhz */
#define PMC_OCR_SEL4			(0x01 << 7)

/* RC Oscillator Calibration bits for 4 Mhz */
#define PMC_OCR_CAL4_SHIFT		0
#define PMC_OCR_CAL4_MASK		(0x7F << PMC_OCR_CAL12_SHIFT)


#endif
