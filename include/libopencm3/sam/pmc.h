/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef SAM3X_PMC_H
#define SAM3X_PMC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/sam/memorymap.h>

/* --- Power Management Controller (PMC) registers ----------------------- */

#define PMC_SCER			MMIO32(PMC_BASE + 0x0000)
#define PMC_SCDR			MMIO32(PMC_BASE + 0x0004)
#define PMC_SCSR			MMIO32(PMC_BASE + 0x0008)
/* 0x000C - Reserved */
#define PMC_PCER0			MMIO32(PMC_BASE + 0x0010)
#define PMC_PCDR0			MMIO32(PMC_BASE + 0x0014)
#define PMC_PCSR0			MMIO32(PMC_BASE + 0x0018)
#define CKGR_UCKR			MMIO32(PMC_BASE + 0x001C)
#define CKGR_MOR			MMIO32(PMC_BASE + 0x0020)
#define CKGR_MCFR			MMIO32(PMC_BASE + 0x0024)
#define CKGR_PLLAR			MMIO32(PMC_BASE + 0x0028)
/* 0x002C - Reserved */
#define PMC_MCKR			MMIO32(PMC_BASE + 0x0030)
/* 0x0034 - Reserved */
#define PMC_USB				MMIO32(PMC_BASE + 0x0038)
/* 0x003C - Reserved */
#define PMC_PCK0			MMIO32(PMC_BASE + 0x0040)
#define PMC_PCK1			MMIO32(PMC_BASE + 0x0044)
#define PMC_PCK2			MMIO32(PMC_BASE + 0x0048)
/* 0x004C-0x005C - Reserved */
#define PMC_IER				MMIO32(PMC_BASE + 0x0060)
#define PMC_IDR				MMIO32(PMC_BASE + 0x0064)
#define PMC_SR				MMIO32(PMC_BASE + 0x0068)
#define PMC_IMR				MMIO32(PMC_BASE + 0x006C)
#define PMC_FSMR			MMIO32(PMC_BASE + 0x0070)
#define PMC_FSPR			MMIO32(PMC_BASE + 0x0074)
#define PMC_FOCR			MMIO32(PMC_BASE + 0x0078)
/* 0x007C-0x00E0 - Reserved */
#define PMC_WPMR			MMIO32(PMC_BASE + 0x00E4)
#define PMC_WPSR			MMIO32(PMC_BASE + 0x00E8)
/* 0x00EC-0x00FC - Reserved */
#define PMC_PCER1			MMIO32(PMC_BASE + 0x0100)
#define PMC_PCDR1			MMIO32(PMC_BASE + 0x0104)
#define PMC_PCSR1			MMIO32(PMC_BASE + 0x0108)
#define PMC_PCR				MMIO32(PMC_BASE + 0x010C)

/* PMC UTMI Clock Configuration Register (CKGR_UCKR) */
/* Bit [31:22] - Reserved */
#define CKGR_CKGR_UPLLCOUNT_MASK	(0x0F << 20)
/* Bit [19:17] - Reserved */
#define CKGR_CKGR_UPLLEN		(0x01 << 16)
/* Bit [15:0] - Reserved */

/* PMC Clock Generator Main Oscillator Register (CKGR_MOR) */
/* Bit [31:26] - Reserved */
#define CKGR_MOR_CFDEN			(0x01 << 25)
#define CKGR_MOR_MOSCSEL		(0x01 << 24)
#define CKGR_MOR_KEY			(0x37 << 16)
#define CKGR_MOR_MOSCXTST_MASK		(0xFF << 8)
/* Bit 7 - Reserved */
#define CKGR_MOR_MOSCRCF_MASK		(0x07 << 4)
#define CKGR_MOR_MOSCRCEN		(0x01 << 3)
/* Bit 2 - Reserved */
#define CKGR_MOR_MOSCXTBY		(0x01 << 1)
#define CKGR_MOR_MOSCXTEN		(0x01 << 0)

/* PMC Clock Generator PLLA Register (CKGR_PLLAR) */
#define CKGR_PLLAR_ONE			(0x01 << 29)
#define CKGR_PLLAR_MULA_MASK		(0x7FF << 16)
#define CKGR_PLLAR_PLLACOUNT_MASK	(0x3F << 8)
#define CKGR_PLLAR_DIVA_MASK		(0xFF << 0)

/* PMC Master Clock Register (PMC_MCKR) */
/* Bit [31:14] - Reserved */
#define PMC_MCKR_UPLLDIV2		(0x01 << 13)
#define PMC_MCKR_PLLADIV2		(0x01 << 12)
/* Bit [11:7] - Reserved */
#define PMC_MCKR_PRES_MASK		(0x07 << 4)
/* Bit [3:2] - Reserved */
#define PMC_MCKR_CSS_MASK		(0x03 << 0)
#define PMC_MCKR_CSS_SLOW_CLK		(0x00 << 0)
#define PMC_MCKR_CSS_MAIN_CLK		(0x01 << 0)
#define PMC_MCKR_CSS_PLLA_CLK		(0x02 << 0)
#define PMC_MCKR_CSS_UPLL_CLK		(0x03 << 0)

/* PMC USB Clock Register (PMC_USB) */
/* Bit [31:12] - Reserved */
#define PMC_USB_USBDIV_MASK		(0x0F << 8)
/* Bit [7:1] - Reserved */
#define PMC_USB_USBS			(0x01 << 0)

/* PMC Status Register (PMC_SR) */
/* Bits [31:21] - Reserved */
#define PMC_SR_FOS			(0x01 << 20)
#define PMC_SR_CFDS			(0x01 << 19)
#define PMC_SR_CFDEV			(0x01 << 18)
#define PMC_SR_MOSCRCS			(0x01 << 17)
#define PMC_SR_MOSCSELS			(0x01 << 16)
/* Bits [15:11] - Reserved */
#define PMC_SR_PCKRDY2			(0x01 << 10)
#define PMC_SR_PCKRDY1			(0x01 << 9)
#define PMC_SR_PCKRDY0			(0x01 << 8)
#define PMC_SR_OSCSELS			(0x01 << 7)
#define PMC_SR_LOCKU			(0x01 << 6)
/* Bits [5:4] - Reserved */
#define PMC_SR_MCKRDY			(0x01 << 3)
/* Bit [2] - Reserved */
#define PMC_SR_LOCKA			(0x01 << 1)
#define PMC_SR_MOSCXTS			(0x01 << 0)

extern uint32_t pmc_mck_frequency;

enum mck_src {
	MCK_SRC_SLOW = 0,
	MCK_SRC_MAIN = 1,
	MCK_SRC_PLLA = 2,
	MCK_SRC_UPLL = 3,
};

void pmc_mck_set_source(enum mck_src src);
void pmc_xtal_enable(bool en, uint8_t startup_time);
void pmc_plla_config(uint8_t mul, uint8_t div);
void pmc_peripheral_clock_enable(uint8_t pid);
void pmc_peripheral_clock_disable(uint8_t pid);
void pmc_clock_setup_in_xtal_12mhz_out_84mhz(void);
void pmc_clock_setup_in_rc_4mhz_out_84mhz(void);

#endif

