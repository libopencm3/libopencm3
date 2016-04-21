/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Maxim Sloyko <maxim@sloyko.com>
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

#ifndef LIBOPENCM3_SCIF_H
#define LIBOPENCM3_SCIF_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* ------------ SCIF Registers ------------------------------ */

/* 0x0000 Interrupt Enable Register IER Write Only 0x00000000 */
#define SCIF_IER			MMIO32(SCIF_BASE)

/* 0x0004 Interrupt Disable Register IDR Write Only 0x00000000 */
#define SCIF_IDR			MMIO32(SCIF_BASE + 0x0004)

/* 0x0008 Interrupt Mask Register IMR Read Only 0x00000000 */
#define SCIF_IMR			MMIO32(SCIF_BASE + 0x0008)

/* 0x000C Interrupt Status Register ISR Read Only 0x00000000 */
#define SCIF_ISR			MMIO32(SCIF_BASE + 0x000C)

/* 0x0010 Interrupt Clear Register ICR Write Only 0x00000000 */
#define SCIF_ICR			MMIO32(SCIF_BASE + 0x0010)

/* 0x0014 Power and Clocks Status Register PCLKSR Read Only 0x00000000 */
#define SCIF_PCLKSR			MMIO32(SCIF_BASE + 0x0014)

/* 0x0018 Unlock Register UNLOCK Write Only 0x00000000 */
#define SCIF_UNLOCK			MMIO32(SCIF_BASE + 0x0018)
#define SCIF_UNLOCK_KEY		(0xaa << 24)

/* 0x001C Chip Specific Configuration Register CSCR Read/Write 0x00000000 */
#define SCIF_CSCR			MMIO32(SCIF_BASE + 0x001C)

/* 0x0020 Oscillator Control Register OSCCTRL0 Read/Write 0x00000000 */
#define SCIF_OSCCTRL0			MMIO32(SCIF_BASE + 0x0020)
#define SCIF_OSCCTRL0_KEY		(SCIF_UNLOCK_KEY | 0x0020)

/* 0x0024 PLL0 Control Register PLL0 Read/Write 0x00000000 */
#define SCIF_PLL0			MMIO32(SCIF_BASE + 0x0024)

/* 0x0028 DFLL0 Config Register DFLL0CONF Read/Write 0x00000000 */
#define SCIF_DFLL0CONF			MMIO32(SCIF_BASE + 0x0028)

/* 0x002C DFLL Value Register DFLL0VAL Read/Write 0x00000000 */
#define SCIF_DFLL0VAL			MMIO32(SCIF_BASE + 0x002C)

/* 0x0030 DFLL0 Multiplier Register DFLL0MUL Read/Write 0x00000000 */
#define SCIF_DFLL0MUL			MMIO32(SCIF_BASE + 0x0030)

/* 0x0034 DFLL0 Step Register DFLL0STEP Read/Write 0x00000000 */
#define SCIF_DFLL0STEP			MMIO32(SCIF_BASE + 0x0034)

/* 0x0038 DFLL0 Spread Spectrum Generator Control Register DFLL0SSG Read/Write 0x00000000 */
#define SCIF_DFLL0SSG			MMIO32(SCIF_BASE + 0x0038)

/* 0x003C DFLL0 Ratio Register DFLL0RATIO Read Only 0x00000000 */
#define SCIF_DFLL0RATIO			MMIO32(SCIF_BASE + 0x003C)

/* 0x0040 DFLL0 Synchronization Register DFLL0SYNC Write Only 0x00000000 */
#define SCIF_DFLL0SYNC			MMIO32(SCIF_BASE + 0x0040)

/* 0x0044 System RC Oscillator Calibration Register RCCR Read/Write - (2) */
#define SCIF_RCCR			MMIO32(SCIF_BASE + 0x0044)

/* 0x0048 4/8/12MHz RC Oscillator Configuration Register RCFASTCFG Read/Write 0x00000000 */
#define SCIF_RCFASTCFG			MMIO32(SCIF_BASE + 0x0048)

/* 0x004C 4/8/12MHz RC Oscillator Status Register RCFASTSR Read Only 0x00000000 */
#define SCIF_RCFASTSR			MMIO32(SCIF_BASE + 0x004C)

/* 0x0050 80MHz RC Oscillator Register RC80MCR Read/Write 0x00000000 */
#define SCIF_RC80MCR			MMIO32(SCIF_BASE + 0x0050)

/* 0x0064 High Resolution Prescaler Control Register HRPCR Read/Write 0x0068 Fractional Prescaler Control Register FPCR Read/Write 0x006C Fractional Prescaler Multiplier Register FPMUL Read/Write 0x0070 Fractional Prescaler DIVIDER Register FPDIV Read/Write 0x0074 Generic Clock Control0 GCCTRL0 Read/Write 0x00000000 */
#define SCIF_HPPCR			MMIO32(SCIF_BASE + 0x0064)

/* 0x0078 Generic Clock Control1 GCCTRL1 Read/Write 0x00000000 */
#define SCIF_GCCTRL1			MMIO32(SCIF_BASE + 0x0078)

/* 0x007C Generic Clock Control2 GCCTRL2 Read/Write 0x00000000 */
#define SCIF_GCCTRL2			MMIO32(SCIF_BASE + 0x007C)

/* 0x0080 Generic Clock Control3 GCCTRL3 Read/Write 0x00000000 */
#define SCIF_GCCTRL3			MMIO32(SCIF_BASE + 0x0080)

/* 0x0084 Generic Clock Control4 GCCTRL4 Read/Write 0x00000000 */
#define SCIF_GCCTRL4			MMIO32(SCIF_BASE + 0x0084)

/* 0x0088 Generic Clock Control5 GCCTRL5 Read/Write 0x00000000 */
#define SCIF_GCCTRL5			MMIO32(SCIF_BASE + 0x0088)

/* 0x008C Generic Clock Control6 GCCTRL6 Read/Write 0x00000000 */
#define SCIF_GCCTRL6			MMIO32(SCIF_BASE + 0x008C)

/* 0x0090 Generic Clock Control7 GCCTRL7 Read/Write 0x00000000 */
#define SCIF_GCCTRL7			MMIO32(SCIF_BASE + 0x0090)

/* 0x0094 Generic Clock Control8 GCCTRL8 Read/Write 0x00000000 */
#define SCIF_GCCTRL8			MMIO32(SCIF_BASE + 0x0094)

/* 0x0098 Generic Clock Control9 GCCTRL9 Read/Write 0x00000000 */
#define SCIF_GCCTRL9			MMIO32(SCIF_BASE + 0x0098)

/* 0x009C Generic Clock Control10 GCCTRL10 Read/Write 0x00000000 */
#define SCIF_GCCTRL10			MMIO32(SCIF_BASE + 0x009C)

/* 0x00A0 Generic Clock Control11 GCCTRL11 Read/Write 0x00000000 */
#define SCIF_GCCTRL11			MMIO32(SCIF_BASE + 0x00A0)

/* 0x03D8 4/8/12MHz RC Oscillator Version Register RCFASTVERSION Read-only - (1) */
#define SCIF_RCFASTVERSION			MMIO32(SCIF_BASE + 0x03D8)

/* 0x03DC Generic Clock Prescaler Version Register GCLKPRESCVERSION Read-only - (1) */
#define SCIF_GCLKPRESCVERSION			MMIO32(SCIF_BASE + 0x03DC)

/* 0x03E0 PLL Version Register PLLIFAVERSION Read-only - (1) */
#define SCIF_PLLIFAVERSION			MMIO32(SCIF_BASE + 0x03E0)

/* 0x03E4 Oscillator0 Version Register OSCIFAVERSION Read-only - (1) */
#define SCIF_OSCIFAVERSION			MMIO32(SCIF_BASE + 0x03E4)

/* 0x03E8 DFLL Version Register DFLLIFBVERSION Read-only - (1) */
#define SCIF_DFLLIFBVERSION			MMIO32(SCIF_BASE + 0x03E8)

/* 0x03EC System RC Oscillator Version Register RCOSCIFAVERSION Read-only - (1) */
#define SCIF_RCOSCIFAVERSION			MMIO32(SCIF_BASE + 0x03EC)

/* 0x03F4 80MHz RC Oscillator Version Register RC80MVERSION Read-only - (1) */
#define SCIF_RC80MVERSION			MMIO32(SCIF_BASE + 0x03F4)

/* 0x03F8 Generic Clock Version Register GCLKVERSION Read-only - (1) */
#define SCIF_GCLKVERSION			MMIO32(SCIF_BASE + 0x03F8)

/* 0x03FC SCIF Version Register VERSION Read-only */
#define SCIF_VERSION			MMIO32(SCIF_BASE + 0x03FC)


/* ---------------- SCIF Registers' Contents ------------------- */

/* Interrupt Enable/Disable/Mask/Status/Clear registers and PCLKSR
 * have the same bit configuration */
#define SCIF_OSC0RDY_SHIFT			0
#define SCIF_DFLL0LOCKC_SHIFT			1
#define SCIF_DFLL0LOCKF_SHIFT			2
#define SCIF_DFLL0RDY_SHIFT			3
#define SCIF_DFLL0RCS_SHIFT			4
#define SCIF_PLL0LOCK_SHIFT			6
#define SCIF_PLL0LOCKLOST_SHIFT			7
#define SCIF_RCFASTLOCK_SHIFT			13
#define SCIF_RCFASTLOCKLOST_SHIFT			14

#define SCIF_OSCCTRL_MODE_SHIFT			0
#define SCIF_OSCCTRL_GAIN_SHIFT			1
#define SCIF_OSCCTRL_AGC_SHIFT			3
#define SCIF_OSCCTRL_STARTUP_SHIFT			8
#define SCIF_OSCCTRL_OSCEN_SHIFT			16

enum osc_mode {
	OSC_MODE_XIN = 0,
	OSC_MODE_XIN_XOUT,
};

enum osc_startup {
	OSC_STARTUP_0 = 0,
	OSC_STARTUP_4 = 8,
	OSC_STARTUP_8 = 9,
	OSC_STARTUP_16 = 10,
	OSC_STARTUP_32 = 11,
	OSC_STARTUP_64 = 1,
	OSC_STARTUP_128 = 2,
	OSC_STARTUP_256 = 12,
	OSC_STARTUP_512 = 13,
	OSC_STARTUP_1K = 14,
	OSC_STARTUP_2K = 3,
	OSC_STARTUP_4K = 4,
	OSC_STARTUP_8K = 5,
	OSC_STARTUP_16K = 6,
	OSC_STARTUP_32K = 7,
};

BEGIN_DECLS

int scif_osc_enable(enum osc_mode mode, uint32_t freq, enum osc_startup startup);

END_DECLS


#endif	/* LIBOPENCM3_SCIF_H */
