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

#ifndef LIBOPENCM3_PMC_COMMON_ALL_H
#define LIBOPENCM3_PMC_COMMON_ALL_H

#include <libopencm3/cm3/common.h>

/* --- Power Management Controller (PMC) registers ----------------------- */

/* System Clock Enable Register */
#define PMC_SCER			MMIO32(PMC_BASE + 0x0000)

/* System Clock Disable Register */
#define PMC_SCDR			MMIO32(PMC_BASE + 0x0004)

/* System Clock Status Register */
#define PMC_SCSR			MMIO32(PMC_BASE + 0x0008)

/* Main Oscillator Register */
#define CKGR_MOR			MMIO32(PMC_BASE + 0x0020)

/* Main Clock Frequency Register */
#define CKGR_MCFR			MMIO32(PMC_BASE + 0x0024)

/* PLLA Register */
#define CKGR_PLLAR			MMIO32(PMC_BASE + 0x0028)

/* Master Clock Register */
#define PMC_MCKR			MMIO32(PMC_BASE + 0x0030)

/* Programmable Clock 0 Register */
#define PMC_PCK0			MMIO32(PMC_BASE + 0x0040)

/* Programmable Clock 1 Register */
#define PMC_PCK1			MMIO32(PMC_BASE + 0x0044)

/* Programmable Clock 2 Register */
#define PMC_PCK2			MMIO32(PMC_BASE + 0x0048)

/* Interrupt Enable Register */
#define PMC_IER				MMIO32(PMC_BASE + 0x0060)

/* Interrupt Disable Register */
#define PMC_IDR				MMIO32(PMC_BASE + 0x0064)

/* Status Register */
#define PMC_SR				MMIO32(PMC_BASE + 0x0068)

/* Interrupt Mask Register */
#define PMC_IMR				MMIO32(PMC_BASE + 0x006C)

/* Fast Startup Mode Register */
#define PMC_FSMR			MMIO32(PMC_BASE + 0x0070)

/* Fast Startup Polarity Register */
#define PMC_FSPR			MMIO32(PMC_BASE + 0x0074)

/* Fault Output Clear Register */
#define PMC_FOCR			MMIO32(PMC_BASE + 0x0078)

/* Write Protect Mode Register */
#define PMC_WPMR			MMIO32(PMC_BASE + 0x00E4)

/* Write Protect Status Register */
#define PMC_WPSR			MMIO32(PMC_BASE + 0x00E8)


/* --- Register contents --------------------------------------------------- */


/* --- PMC System Clock Enable Register (PMC_SCER) ------------------------- */

/* Programmable Clock Output Enable */
#define PMC_SCER_PCK0			(0x01 << 8)
#define PMC_SCER_PCK1			(0x01 << 9)
#define PMC_SCER_PCK2			(0x01 << 10)


/* --- PMC System Clock Disable Register (PMC_SCDR) ------------------------ */

/* Programmable Clock Output Disable */
#define PMC_SCDR_PCK0			(0x01 << 8)
#define PMC_SCDR_PCK1			(0x01 << 9)
#define PMC_SCDR_PCK2			(0x01 << 10)


/* --- PMC System Clock Status Register (PMC_SCSR) ------------------------- */

/* Programmable Clock Output Status */
#define PMC_SCSR_PCK0			(0x01 << 8)
#define PMC_SCSR_PCK1			(0x01 << 9)
#define PMC_SCSR_PCK2			(0x01 << 10)


/* for bit definitions for PMC System Clock Enable/Disable/Status Register see
 * periph.h */


/* --- PMC Clock Generator Main Oscillator Register (CKGR_MOR) ------------- */

/* Clock Failure Detector Enable */
#define CKGR_MOR_CFDEN			(0x01 << 25)

/* Main Oscillator Selection */
#define CKGR_MOR_MOSCSEL		(0x01 << 24)

/* Password for changing settings */
#define CKGR_MOR_KEY			(0x37 << 16)

/* Main Crystal Oscillator Start-up Time */
#define CKGR_MOR_MOSCXTST_SHIFT		8
#define CKGR_MOR_MOSCXTST_MASK		(0xFF << 8)

/* Main On-Chip RC Oscillator Frequency Selection */
#define CKGR_MOR_MOSCRCF_SHIFT		4
#define CKGR_MOR_MOSCRCF_MASK		(0x07 << CKGR_MOR_MOSCRCF_SHIFT)

/* Main On-Chip RC Oscillator selectable frequencies */
#define CKGR_MOR_MOSCRCF_4MHZ		(0 << CKGR_MOR_MOSCRCF_SHIFT)
#define CKGR_MOR_MOSCRCF_8MHZ		(1 << CKGR_MOR_MOSCRCF_SHIFT)
#define CKGR_MOR_MOSCRCF_12MHZ		(2 << CKGR_MOR_MOSCRCF_SHIFT)

/* Main On-Chip RC Oscillator Enable */
#define CKGR_MOR_MOSCRCEN		(0x01 << 3)

/* Main Crystal Oscillator Bypass */
#define CKGR_MOR_MOSCXTBY		(0x01 << 1)

/* Main Crystal Oscillator Enable */
#define CKGR_MOR_MOSCXTEN		(0x01 << 0)


/* --- PMC Clock Generator Main Clock Frequency Register (CKGR_MCFR) ------- */

/* Main Clock Ready */
#define CKGR_MCFR_MAINFRDY		(0x01 << 16)

/* Main Clock Frequency */
#define CKGR_MCFR_MAINF_SHIFT		0
#define CKGR_MCFR_MAINF_MASK		(0xFFFF << CKGR_MCFR_MAINF_SHIFT)


/* --- PMC Clock Generator PLLA Register (CKGR_PLLAR) ---------------------- */

/* must be set to program CKGR_PLLAR */
#define CKGR_PLLAR_ONE			(0x01 << 29)

/* PLLA Multiplier */
#define CKGR_PLLAR_MULA_SHIFT		16
#define CKGR_PLLAR_MULA_MASK		(0x7FF << CKGR_PLLAR_MULA_SHIFT)

/* PLLA Counter */
#define CKGR_PLLAR_PLLACOUNT_SHIFT	8
#define CKGR_PLLAR_PLLACOUNT_MASK	(0x3F << CKGR_PLLAR_PLLACOUNT_SHIFT)

/* Divider */
#define CKGR_PLLAR_DIVA_SHIFT		0
#define CKGR_PLLAR_DIVA_MASK		(0xFF << CKGR_PLLAR_DIVA_SHIFT)


/* --- PMC Master Clock Register (PMC_MCKR) -------------------------------- */

/* Processor Clock Prescaler */
#define PMC_MCKR_PRES_SHIFT		4
#define PMC_MCKR_PRES_MASK		(0x07 << PMC_MCKR_PRES_SHIFT)
#define PMC_MCKR_PRES_CLK_1		(0 << PMC_MCKR_PRES_SHIFT)
#define PMC_MCKR_PRES_CLK_2		(1 << PMC_MCKR_PRES_SHIFT)
#define PMC_MCKR_PRES_CLK_4		(2 << PMC_MCKR_PRES_SHIFT)
#define PMC_MCKR_PRES_CLK_8		(3 << PMC_MCKR_PRES_SHIFT)
#define PMC_MCKR_PRES_CLK_16		(4 << PMC_MCKR_PRES_SHIFT)
#define PMC_MCKR_PRES_CLK_32		(5 << PMC_MCKR_PRES_SHIFT)
#define PMC_MCKR_PRES_CLK_64		(6 << PMC_MCKR_PRES_SHIFT)
#define PMC_MCKR_PRES_CLK_3		(7 << PMC_MCKR_PRES_SHIFT)

/* Master Clock Source Selection */
#define PMC_MCKR_CSS_SHIFT		0
#define PMC_MCKR_CSS_MASK		(0x03 << PMC_MCKR_CSS_SHIFT)
#define PMC_MCKR_CSS_SLOW_CLK		(0 << PMC_MCKR_CSS_SHIFT)
#define PMC_MCKR_CSS_MAIN_CLK		(1 << PMC_MCKR_CSS_SHIFT)
#define PMC_MCKR_CSS_PLLA_CLK		(2 << PMC_MCKR_CSS_SHIFT)


/* --- PMC Programmable Clock Register 0 (PMC_PCK0) ------------------------ */

/* Programmable Clock Prescaler */
#define PMC_PCK0_PRES_SHIFT		4
#define PMC_PCK0_PRES_MASK		(0x07 << PMC_PCK0_PRES_SHIFT)
#define PMC_PCK0_PRES_CLK_1		(0 << PMC_PCK0_PRES_SHIFT)
#define PMC_PCK0_PRES_CLK_2		(1 << PMC_PCK0_PRES_SHIFT)
#define PMC_PCK0_PRES_CLK_4		(2 << PMC_PCK0_PRES_SHIFT)
#define PMC_PCK0_PRES_CLK_8		(3 << PMC_PCK0_PRES_SHIFT)
#define PMC_PCK0_PRES_CLK_16		(4 << PMC_PCK0_PRES_SHIFT)
#define PMC_PCK0_PRES_CLK_32		(5 << PMC_PCK0_PRES_SHIFT)
#define PMC_PCK0_PRES_CLK_64		(6 << PMC_PCK0_PRES_SHIFT)

/* Master Clock Source Selection */
#define PMC_PCK0_CSS_SHIFT		0
#define PMC_PCK0_CSS_MASK		(0x07 << PMC_PCK0_CSS_SHIFT)
#define PMC_PCK0_CSS_SLOW_CLK		(0 << PMC_PCK0_CSS_SHIFT)
#define PMC_PCK0_CSS_MAIN_CLK		(1 << PMC_PCK0_CSS_SHIFT)
#define PMC_PCK0_CSS_PLLA_CLK		(2 << PMC_PCK0_CSS_SHIFT)
#define PMC_PCK0_CSS_MCK		(4 << PMC_PCK0_CSS_SHIFT)


/* --- PMC Programmable Clock Register 1 (PMC_PCK1) ------------------------ */

/* Programmable Clock Prescaler */
#define PMC_PCK1_PRES_SHIFT		4
#define PMC_PCK1_PRES_MASK		(0x07 << PMC_PCK1_PRES_SHIFT)
#define PMC_PCK1_PRES_CLK_1		(0 << PMC_PCK1_PRES_SHIFT)
#define PMC_PCK1_PRES_CLK_2		(1 << PMC_PCK1_PRES_SHIFT)
#define PMC_PCK1_PRES_CLK_4		(2 << PMC_PCK1_PRES_SHIFT)
#define PMC_PCK1_PRES_CLK_8		(3 << PMC_PCK1_PRES_SHIFT)
#define PMC_PCK1_PRES_CLK_16		(4 << PMC_PCK1_PRES_SHIFT)
#define PMC_PCK1_PRES_CLK_32		(5 << PMC_PCK1_PRES_SHIFT)
#define PMC_PCK1_PRES_CLK_64		(6 << PMC_PCK1_PRES_SHIFT)

/* Master Clock Source Selection */
#define PMC_PCK1_CSS_SHIFT		0
#define PMC_PCK1_CSS_MASK		(0x07 << PMC_PCK1_CSS_SHIFT)
#define PMC_PCK1_CSS_SLOW_CLK		(0 << PMC_PCK1_CSS_SHIFT)
#define PMC_PCK1_CSS_MAIN_CLK		(1 << PMC_PCK1_CSS_SHIFT)
#define PMC_PCK1_CSS_PLLA_CLK		(2 << PMC_PCK1_CSS_SHIFT)
#define PMC_PCK1_CSS_MCK		(4 << PMC_PCK1_CSS_SHIFT)


/* --- PMC Programmable Clock Register 2 (PMC_PCK2) ------------------------ */

/* Programmable Clock Prescaler */
#define PMC_PCK2_PRES_SHIFT		4
#define PMC_PCK2_PRES_MASK		(0x07 << PMC_PCK2_PRES_SHIFT)
#define PMC_PCK2_PRES_CLK_1		(0 << PMC_PCK2_PRES_SHIFT)
#define PMC_PCK2_PRES_CLK_2		(1 << PMC_PCK2_PRES_SHIFT)
#define PMC_PCK2_PRES_CLK_4		(2 << PMC_PCK2_PRES_SHIFT)
#define PMC_PCK2_PRES_CLK_8		(3 << PMC_PCK2_PRES_SHIFT)
#define PMC_PCK2_PRES_CLK_16		(4 << PMC_PCK2_PRES_SHIFT)
#define PMC_PCK2_PRES_CLK_32		(5 << PMC_PCK2_PRES_SHIFT)
#define PMC_PCK2_PRES_CLK_64		(6 << PMC_PCK2_PRES_SHIFT)

/* Master Clock Source Selection */
#define PMC_PCK2_CSS_SHIFT		0
#define PMC_PCK2_CSS_MASK		(0x07 << PMC_PCK2_CSS_SHIFT)
#define PMC_PCK2_CSS_SLOW_CLK		(0 << PMC_PCK2_CSS_SHIFT)
#define PMC_PCK2_CSS_MAIN_CLK		(1 << PMC_PCK2_CSS_SHIFT)
#define PMC_PCK2_CSS_PLLA_CLK		(2 << PMC_PCK2_CSS_SHIFT)
#define PMC_PCK2_CSS_MCK		(4 << PMC_PCK2_CSS_SHIFT)


/* --- PMC Interrupt Enable Register (PMC_IER) ----------------------------- */

/* Clock Failure Detector Event Interrupt Enable */
#define PMC_IER_CFDEV			(0x01 << 18)

/* Main On-Chip RC Status Interrupt Enable */
#define PMC_IER_MOSCRCS			(0x01 << 17)

/* Main Oscillator Selection Status Interrupt Enable */
#define PMC_IER_MOSCSELS		(0x01 << 16)

/* Programmable Clock Ready 2 Interrupt Enable */
#define PMC_IER_PCKRDY2			(0x01 << 10)

/* Programmable Clock Ready 1 Interrupt Enable */
#define PMC_IER_PCKRDY1			(0x01 << 9)

/* Programmable Clock Ready 0 Interrupt Enable */
#define PMC_IER_PCKRDY0			(0x01 << 8)

/* Master Clock Ready Interrupt Enable */
#define PMC_IER_MCKRDY			(0x01 << 3)

/* PLLA Lock Interrupt Enable */
#define PMC_IER_LOCKA			(0x01 << 1)

/* Main Crystal Oscillator Status Interrupt Enable */
#define PMC_IER_MOSCXTS			(0x01 << 0)


/* --- PMC Interrupt Disable Register (PMC_IDR) ----------------------------- */

/* Clock Failure Detector Event Interrupt Disable */
#define PMC_IDR_CFDEV			(0x01 << 18)

/* Main On-Chip RC Status Interrupt Disable */
#define PMC_IDR_MOSCRCS			(0x01 << 17)

/* Main Oscillator Selection Status Interrupt Disable */
#define PMC_IDR_MOSCSELS		(0x01 << 16)

/* Programmable Clock Ready 2 Interrupt Disable */
#define PMC_IDR_PCKRDY2			(0x01 << 10)

/* Programmable Clock Ready 1 Interrupt Disable */
#define PMC_IDR_PCKRDY1			(0x01 << 9)

/* Programmable Clock Ready 0 Interrupt Disable */
#define PMC_IDR_PCKRDY0			(0x01 << 8)

/* Master Clock Ready Interrupt Disable */
#define PMC_IDR_MCKRDY			(0x01 << 3)

/* PLLA Lock Interrupt Disable */
#define PMC_IDR_LOCKA			(0x01 << 1)

/* Main Crystal Oscillator Status Interrupt Disable */
#define PMC_IDR_MOSCXTS			(0x01 << 0)


/* --- PMC Status Register (PMC_SR) ---------------------------------------- */

/* Clock Failure Detector Fault Output Status */
#define PMC_SR_FOS			(0x01 << 20)

/* Clock Failure Detector Status */
#define PMC_SR_CFDS			(0x01 << 19)

/* Clock Failure Detector Event */
#define PMC_SR_CFDEV			(0x01 << 18)

/* Main On-Chip RC Oscillator Status */
#define PMC_SR_MOSCRCS			(0x01 << 17)

/* Main Oscillator Selection Status */
#define PMC_SR_MOSCSELS			(0x01 << 16)

/* Programmable Clock 2 Ready Status */
#define PMC_SR_PCKRDY2			(0x01 << 10)

/* Programmable Clock 1 Ready Status */
#define PMC_SR_PCKRDY1			(0x01 << 9)

/* Programmable Clock 0 Ready Status */
#define PMC_SR_PCKRDY0			(0x01 << 8)

/* Slow Clock Oscillator Selection */
#define PMC_SR_OSCSELS			(0x01 << 7)

/* Master Clock Status */
#define PMC_SR_MCKRDY			(0x01 << 3)

/* PLLA Lock Status */
#define PMC_SR_LOCKA			(0x01 << 1)

/* Main XTAL Oscillator Status */
#define PMC_SR_MOSCXTS			(0x01 << 0)


/* --- PMC Interrupt Mask Register (PMC_IMR) ------------------------------- */

/* Clock Failure Detector Event Interrupt Mask */
#define PMC_IMR_CFDEV			(0x01 << 18)

/* Main On-Chip RC Status Interrupt Mask */
#define PMC_IMR_MOSCRCS			(0x01 << 17)

/* Main Oscillator Selection Status Interrupt Mask */
#define PMC_IMR_MOSCSELS		(0x01 << 16)

/* Programmable Clock Ready 2 Interrupt Mask */
#define PMC_IMR_PCKRDY2			(0x01 << 10)

/* Programmable Clock Ready 1 Interrupt Mask */
#define PMC_IMR_PCKRDY1			(0x01 << 9)

/* Programmable Clock Ready 0 Interrupt Mask */
#define PMC_IMR_PCKRDY0			(0x01 << 8)

/* Master Clock Ready Interrupt Mask */
#define PMC_IMR_MCKRDY			(0x01 << 3)

/* PLLA Lock Interrupt Mask */
#define PMC_IMR_LOCKA			(0x01 << 1)

/* Main Crystal Oscillator Status Interrupt Mask */
#define PMC_IMR_MOSCXTS			(0x01 << 0)


/* --- PMC Fast Startup Mode Register (PMC_FSMR) --------------------------- */

/* Low Power Mode */
#define PMC_FSMR_LPM			(0x01 << 20)

/* USB Alarm Enable */
#define PMC_FSMR_USBAL			(0x01 << 18)

/* RTC Alarm Enable */
#define PMC_FSMR_RTCAL			(0x01 << 17)

/* RTC Alarm Enable */
#define PMC_FSMR_RTTAL			(0x01 << 16)

/* Fast Startup Input Enable 0 to 15 */
#define PMC_FSMR_FSTT15			(0x01 << 15)
#define PMC_FSMR_FSTT14			(0x01 << 14)
#define PMC_FSMR_FSTT13			(0x01 << 13)
#define PMC_FSMR_FSTT12			(0x01 << 12)
#define PMC_FSMR_FSTT11			(0x01 << 11)
#define PMC_FSMR_FSTT10			(0x01 << 10)
#define PMC_FSMR_FSTT9			(0x01 << 9)
#define PMC_FSMR_FSTT8			(0x01 << 8)
#define PMC_FSMR_FSTT7			(0x01 << 7)
#define PMC_FSMR_FSTT6			(0x01 << 6)
#define PMC_FSMR_FSTT5			(0x01 << 5)
#define PMC_FSMR_FSTT4			(0x01 << 4)
#define PMC_FSMR_FSTT3			(0x01 << 3)
#define PMC_FSMR_FSTT2			(0x01 << 2)
#define PMC_FSMR_FSTT1			(0x01 << 1)
#define PMC_FSMR_FSTT0			(0x01 << 0)


/* --- PMC Fast Startup Polarity Register (PMC_FSPR) ----------------------- */

/* Fast Startup Input Polarity x */
#define PMC_FSPR_FSTP15			(0x01 << 15)
#define PMC_FSPR_FSTP14			(0x01 << 14)
#define PMC_FSPR_FSTP13			(0x01 << 13)
#define PMC_FSPR_FSTP12			(0x01 << 12)
#define PMC_FSPR_FSTP11			(0x01 << 11)
#define PMC_FSPR_FSTP10			(0x01 << 10)
#define PMC_FSPR_FSTP9			(0x01 << 9)
#define PMC_FSPR_FSTP8			(0x01 << 8)
#define PMC_FSPR_FSTP7			(0x01 << 7)
#define PMC_FSPR_FSTP6			(0x01 << 6)
#define PMC_FSPR_FSTP5			(0x01 << 5)
#define PMC_FSPR_FSTP4			(0x01 << 4)
#define PMC_FSPR_FSTP3			(0x01 << 3)
#define PMC_FSPR_FSTP2			(0x01 << 2)
#define PMC_FSPR_FSTP1			(0x01 << 1)
#define PMC_FSPR_FSTP0			(0x01 << 0)


/* --- PMC Fault Output Clear Register (PMC_FOCR) -------------------------- */

/* Fault Output Clear */
#define PMC_FOCR_FOCLR			(0x01 << 0)


/* --- PMC Write Protect Mode Register (PMC_WPMR) -------------------------- */

/* Write Protect Key */
#define PMC_WPMR_WPKEY_SHIFT		8
#define PMC_WPMR_WPKEY			(0x504D43 << PMC_WPMR_WPKEY_SHIFT)

/* Write Protect Enable */
#define PMC_WPMR_WPEN			(0x01 << 0)


/* --- PMC Write Protect Status Register (PMC_WPSR) ------------------------ */

/* Write Protect Violation Source */
#define PMC_WPSR_WPVSRC_SHIFT		8
#define PMC_WPSR_WPVSRC_MASK		(0xFFFF << PMC_WPSR_WPVSRC_SHIFT)

/* Write Protect Violation Status */
#define PMC_WPSR_WPVS			(0x01 << 0)




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

#else
#warning "pmc_common_all.h should not be included explicitly, only via pmc.h"
#endif
