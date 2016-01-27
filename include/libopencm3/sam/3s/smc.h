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

#ifndef LIBOPENCM3_SMC_H
#define LIBOPENCM3_SMC_H

#include <libopencm3/sam/memorymap.h>


/* Chip Select Defines */
#define SMC_CS_0			0
#define SMC_CS_1			1
#define SMC_CS_2			2
#define SMC_CS_3			3


/* --- Static Memory Controller (SMC) registers ---------------------------- */

/* Setup Register */
#define SMC_SETUP(CS_number)		MMIO32(SMC_BASE + 0x10*(CS_number) \
						+ 0x00)

/* Pulse Register */
#define SMC_PULSE(CS_number)		MMIO32(SMC_BASE + 0x10*(CS_number) \
						+ 0x04)

/* Cycle Register */
#define SMC_CYCLE(CS_number)		MMIO32(SMC_BASE + 0x10*(CS_number) \
						+ 0x08)

/* Mode Register */
#define SMC_MODE(CS_number)		MMIO32(SMC_BASE + 0x10*(CS_number) \
						+ 0x0C)

/* Off Chip Memory Scrambling Mode Register */
#define SMC_OCMS			MMIO32(SMC_BASE + 0x80)

/* Off Chip Memory Scrambling KEY1 Register */
#define SMC_KEY1			MMIO32(SMC_BASE + 0x84)

/* Off Chip Memory Scrambling KEY2 Register */
#define SMC_KEY2			MMIO32(SMC_BASE + 0x88)

/* Write Protect Mode Register */
#define SMC_WPMR			MMIO32(SMC_BASE + 0xE4)

/* Write Protect Status Register */
#define SMC_WPSR			MMIO32(SMC_BASE + 0xE8)


/* --- Register contents --------------------------------------------------- */


/* --- SMC Setup Register (SMC_SETUPx) ------------------------------------- */

/* NCS Setup length in Read access */
#define SMC_SETUP_NCS_RD_SETUP_SHIFT	24
#define SMC_SETUP_NCS_RD_SETUP_MASK	(0x3F << SMC_SETUP_NCS_RD_SETUP_SHIFT)

/* NRD Setup length */
#define SMC_SETUP_NRD_SETUP_SHIFT	16
#define SMC_SETUP_NRD_SETUP_MASK	(0x3F << SMC_SETUP_NRD_SETUP_SHIFT)

/* NCS Setup length in Write access */
#define SMC_SETUP_NCS_WR_SETUP_SHIFT	8
#define SMC_SETUP_NCS_WR_SETUP_MASK	(0x3F << SMC_SETUP_NCS_WR_SETUP_SHIFT)

/* NWE Setup Length */
#define SMC_SETUP_NWE_SETUP_SHIFT	0
#define SMC_SETUP_NWE_SETUP_MASK	(0x3F << SMC_SETUP_NWE_SETUP_SHIFT)


/* --- SMC Pulse Register (SMC_PULSEx) ------------------------------------- */

/* NCS Pulse Length in READ Access */
#define SMC_PULSE_NCS_RD_PULSE_SHIFT	24
#define SMC_PULSE_NCS_RD_PULSE_MASK	(0x7F << SMC_PULSE_NCS_RD_PULSE_SHIFT)

/* NRD Pulse Length */
#define SMC_PULSE_NRD_PULSE_SHIFT	16
#define SMC_PULSE_NRD_PULSE_MASK	(0x7F << SMC_PULSE_NRD_PULSE_SHIFT)

/* NCS Pulse Length in WRITE Access */
#define SMC_PULSE_NCS_WR_PULSE_SHIFT	8
#define SMC_PULSE_NCS_WR_PULSE_MASK	(0x7F << SMC_PULSE_NCS_WR_PULSE_SHIFT)

/* NWE Pulse Length */
#define SMC_PULSE_NWE_PULSE_SHIFT	0
#define SMC_PULSE_NWE_PULSE_MASK	(0x7F << SMC_PULSE_NWE_PULSE_SHIFT)


/* --- SMC Cycle Register (SMC_CYCLEx) ------------------------------------- */

/* Total Read Cycle Length */
#define SMC_CYCLE_NRD_CYCLE_SHIFT	16
#define SMC_CYCLE_NRD_CYCLE_MASK	(0x1FF << SMC_CYCLE_NRD_CYCLE_SHIFT)

/* Total Write Cycle Length */
#define SMC_CYCLE_NWE_CYCLE_SHIFT	0
#define SMC_CYCLE_NWE_CYCLE_MASK	(0x1FF << SMC_CYCLE_NWE_CYCLE_SHIFT)


/* --- SMC MODE Register (SMC_MODEx) --------------------------------------- */

/* Page Size */
#define SMC_MODE_PS_SHIFT		28
#define SMC_MODE_PS_MASK		(0x03 << SMC_MODE_PS_SHIFT)

/* Page Size Values */
#define SMC_MODE_PS_4_BYTE		(0x00 << SMC_MODE_PS_SHIFT)
#define SMC_MODE_PS_8_BYTE		(0x01 << SMC_MODE_PS_SHIFT)
#define SMC_MODE_PS_16_BYTE		(0x02 << SMC_MODE_PS_SHIFT)
#define SMC_MODE_PS_32_BYTE		(0x03 << SMC_MODE_PS_SHIFT)

/* Page Mode Enabled */
#define SMC_MODE_PMEN			(1 << 24)

/* TDF Optimization */
#define SMC_MODE_TDF_MODE		(1 << 20)

/* Data Float Time */
#define SMC_MODE_TDF_CYCLES_SHIFT	16
#define SMC_MODE_TDF_CYCLES_MASK	(0x0F << SMC_MODE_TDF_CYCLES_SHIFT)

/* Data Bus Width */
#define SMC_MODE_DBW_SHIFT		12
#define SMC_MODE_DBW_MASK		(0x03 << SMC_MODE_DBW_SHIFT)

/* Data Bus Width Values */
#define SMC_MODE_DBW_8_BIT		(0x00 << SMC_MODE_DBW_SHIFT)
#define SMC_MODE_DBW_16_BIT		(0x01 << SMC_MODE_DBW_SHIFT)
#define SMC_MODE_DBW_32_BIT		(0x02 << SMC_MODE_DBW_SHIFT)

/* NWAIT Mode */
#define SMC_MODE_EXNW_MODE_SHIFT	4
#define SMC_MODE_EXNW_MODE_MASK		(0x03 << SMC_MODE_EXNW_MODE_SHIFT)

/* NWAIT Mode Values */
#define SMC_MODE_EXNW_MODE_DISABLED	(0x00 << SMC_MODE_EXNW_MODE_SHIFT)
#define SMC_MODE_EXNW_MODE_FROZEN	(0x02 << SMC_MODE_EXNW_MODE_SHIFT)
#define SMC_MODE_EXNW_MODE_READY	(0x03 << SMC_MODE_EXNW_MODE_SHIFT)

/* Write Mode */
#define SMC_MODE_WRITE_MODE		(1 << 1)

/* Read Mode */
#define SMC_MODE_READ_MODE		(1 << 0)


/* --- SMC OCMS Mode Register (SMC_OCMS) ----------------------------------- */

/* Chip Select 3 Scrambling Enable */
#define SMC_OCMS_CS3SE			(1 << 19)

/* Chip Select 2 Scrambling Enable */
#define SMC_OCMS_CS2SE			(1 << 18)

/* Chip Select 1 Scrambling Enable */
#define SMC_OCMS_CS1SE			(1 << 17)

/* Chip Select 0 Scrambling Enable */
#define SMC_OCMS_CS0SE			(1 << 16)

/* Static Memory Controller Scrambling Enable */
#define SMC_OCMS_SMSE			(1 << 0)


/* --- SMC Write Protect Mode Register (SMC_WPMR) -------------------------- */

/* Write Protect Key */
#define SMC_WPMR_WPKEY_SHIFT		8
#define SMC_WPMR_WPKEY_KEY		(0x534D43 << SMC_WPMR_WPKEY_SHIFT)

/* Write Protect Enable */
#define SMC_WPMR_WPEN			(1 << 0)


/* --- SMC Write Protect Status Register (SMC_WPSR) ------------------------ */

/* Write Protection Violation Source */
#define SMC_WPSR_WP_VSRC_SHIFT		8
#define SMC_WPSR_WP_VSRC_MASK		(0xFFFF << SMC_WPSR_WP_VSRC_SHIFT)

/* Write Protect Enable */
#define SMC_WPSR_WPVS			(1 << 0)


#endif
