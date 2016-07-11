/*
 * This file is part of the libopencm3 project.
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

#ifndef LIBOPENCM3_PM_H
#define LIBOPENCM3_PM_H

#include <libopencm3/sam/memorymap.h>

/* --- Power Manager (PM) registers ----------------------- */

/* Main Clock Control MCCTRL Read/Write */
#define PM_MCCTRL			MMIO32(PM_BASE + 0x000)
#define PM_MCCTRL_KEY		(PM_UNLOCK_KEY)

/* CPU & PBx Clock Select, Read/Write */
#define PM_CKSEL(I)			MMIO32(PM_BASE + 0x004 + (0x004 * (I)))
#define PM_CKSEL_KEY(I)		(PM_UNLOCK_KEY | (0x004 + (0x004 * (I))))

#define PM_MASK(I)			MMIO32(PM_BASE + 0x020 + (0x004) * (I))
#define PM_MASK_KEY(I)		(PM_UNLOCK_KEY | (0x020 + (0x004) * (I)))

/* CPU Mask CPUMASK Read/Write */
#define PM_CPUMASK			MMIO32(PM_BASE + 0x020)

/* HSB Mask HSBMASK Read/Write */
#define PM_HSBMASK			MMIO32(PM_BASE + 0x024)

/* PBA Mask PBAMASK Read/Write */
#define PM_PBAMASK			MMIO32(PM_BASE + 0x028)
#define PM_PBAMASK_KEY		(PM_UNLOCK_KEY | 0x028)

/* PBB Mask PBBMASK Read/Write */
#define PM_PBBMASK			MMIO32(PM_BASE + 0x02C)

/* PBC Mask PBCMASK Read/Write */
#define PM_PBCMASK			MMIO32(PM_BASE + 0x030)

/* PBD Mask PBDMASK Read/Write */
#define PM_PBDMASK			MMIO32(PM_BASE + 0x034)

/* PBA Divided Mask PBADIVMASK Read/Write */
#define PM_PBADIVMASK			MMIO32(PM_BASE + 0x040)
#define PM_PBADIVMASK_KEY	(PM_UNLOCK_KEY | 0x040)

/* Clock Failure Detector Control CFDCTRL Read/Write */
#define PM_CFDCTRL			MMIO32(PM_BASE + 0x054)

/* Unlock Register UNLOCK Write-only */
#define PM_UNLOCK			MMIO32(PM_BASE + 0x058)
#define PM_UNLOCK_KEY		(0xAA << 24)

/* Interrupt Enable Register IER Write-only */
#define PM_IER				MMIO32(PM_BASE + 0x0C0)

/* Interrupt Disable Register IDR Write-only */
#define PM_IDR				MMIO32(PM_BASE + 0x0C4)

/* Interrupt Mask Register IMR Read-only */
#define PM_IMR				MMIO32(PM_BASE + 0x0C8)

/* Interrupt Status Register ISR Read-only */
#define PM_ISR				MMIO32(PM_BASE + 0x0CC)

/* Interrupt Clear Register ICR Write-only */
#define PM_ICR				MMIO32(PM_BASE + 0x0D0)

/* Status Register SR Read-only */
#define PM_SR				MMIO32(PM_BASE + 0x0D4)

/* Peripheral Power Control Register PPCR Read/Write */
#define PM_PPCR				MMIO32(PM_BASE + 0x160)

/* Reset Cause Register RCAUSE Read-only */
#define PM_RCAUSE			MMIO32(PM_BASE + 0x180)

/* Wake Cause Register WCAUSE Read-only */
#define PM_WCAUSE			MMIO32(PM_BASE + 0x184)

/* Asynchronous Wake Enable AWEN Read/Write */
#define PM_AWEN				MMIO32(PM_BASE + 0x188)

/* Protection Control Register PROTCTRL Read/Write */
#define PM_PROTCTRL			MMIO32(PM_BASE + 0x18C)

/* Fast Sleep Register FASTSLEEP Read/Write */
#define PM_FASTSLEEP			MMIO32(PM_BASE + 0x194)

/* Configuration Register CONFIG Read-only */
#define PM_CONFIG			MMIO32(PM_BASE + 0x3F8)

/* Version Register VERSION Read-only */
#define PM_VERSION			MMIO32(PM_BASE + 0x3FC)


/* --- Register contents --------------------------------------------------- */
#define PM_MCCTRL_MCSEL_SHIFT			0
#define PM_MCCTRL_MCSEL_MASK			3

// Values common for CPUSEL and PBxSEL
#define PM_CKSEL_DIV			(1 << 7)
#define PM_CKSEL_MASK			(3)

#define PM_CPUMASK_OSC			(1 << 0)

#define PM_HSBMASK_PDCA			(1 << 0)
#define PM_HSBMASK_FLASHCALW			(1 << 1)
#define PM_HSBMASK_FLASHCALW_PICO			(1 << 2)
#define PM_HSBMASK_USBC			(1 << 3)
#define PM_HSBMASK_CRCCU			(1 << 4)
#define PM_HSBMASK_APBA			(1 << 5)
#define PM_HSBMASK_APBB			(1 << 6)
#define PM_HSBMASK_APBC			(1 << 7)
#define PM_HSBMASK_APBD			(1 << 8)
#define PM_HSBMASK_AESA			(1 << 9)

#define PM_PBAMASK_IISC			(1 << 0)
#define PM_PBAMASK_SPI			(1 << 1)
#define PM_PBAMASK_TC0			(1 << 2)
#define PM_PBAMASK_TC1			(1 << 3)
#define PM_PBAMASK_TWIM0			(1 << 4)
#define PM_PBAMASK_TWIS0			(1 << 5)
#define PM_PBAMASK_TWIM1			(1 << 6)
#define PM_PBAMASK_TWIS1			(1 << 7)
#define PM_PBAMASK_USART0			(1 << 8)
#define PM_PBAMASK_USART1			(1 << 9)
#define PM_PBAMASK_USART2			(1 << 10)
#define PM_PBAMASK_USART3			(1 << 11)
#define PM_PBAMASK_ADCIFE			(1 << 12)
#define PM_PBAMASK_DACC			(1 << 13)
#define PM_PBAMASK_ACIFC			(1 << 14)
#define PM_PBAMASK_GLOC			(1 << 15)
#define PM_PBAMASK_ABDACB			(1 << 16)
#define PM_PBAMASK_TRNG			(1 << 17)
#define PM_PBAMASK_PARC			(1 << 18)
#define PM_PBAMASK_CATB			(1 << 19)
/* -- */
#define PM_PBAMASK_TWIM2			(1 << 21)
#define PM_PBAMASK_TWIM3			(1 << 22)
#define PM_PBAMASK_LCDCA			(1 << 23)

#define PM_PBBMASK_FLASHCALW			(1 << 0)
#define PM_PBBMASK_HRAMC1			(1 << 1)
#define PM_PBBMASK_HMATRIX			(1 << 2)
#define PM_PBBMASK_PDCA			(1 << 3)
#define PM_PBBMASK_CRCCU			(1 << 4)
#define PM_PBBMASK_USBC			(1 << 5)
#define PM_PBBMASK_PEVC			(1 << 6)

#define PM_PBCMASK_PM			(1 << 0)
#define PM_PBCMASK_CHIPID			(1 << 1)
#define PM_PBCMASK_SCIF			(1 << 2)
#define PM_PBCMASK_FREQM			(1 << 3)
#define PM_PBCMASK_GPIO			(1 << 4)

#define PM_PBDMASK_BPM			(1 << 0)
#define PM_PBDMASK_BSCIF			(1 << 1)
#define PM_PBDMASK_AST			(1 << 2)
#define PM_PBDMASK_WDT			(1 << 3)
#define PM_PBDMASK_EIC			(1 << 4)
#define PM_PBDMASK_PICOUART			(1 << 5)

#define PM_PBADIVMASK_TC2		(1 << 0)
#define PM_PBADIVMASK_USART0	(1 << 2)
#define PM_PBADIVMASK_USART1	(1 << 2)
#define PM_PBADIVMASK_USART2	(1 << 2)
#define PM_PBADIVMASK_USART3	(1 << 2)
#define PM_PBADIVMASK_TC3	(1 << 2)
#define PM_PBADIVMASK_TC4	(1 << 4)
#define PM_PBADIVMASK_TC5	(1 << 6)

#define PM_SR_CFD			(1 << 0)
#define PM_SR_CKRDY			(1 << 5)
#define PM_SR_WAKE			(1 << 8)

enum mck_src {
	MCK_SRC_RCSYS = 0,
	MCK_SRC_OSC0,
	MCK_SRC_PLL,
	MCK_SRC_DFLL,
	MCK_SRC_RC80M,
	MCK_SRC_RCFAST,
	MCK_SRC_RC1M,
};

enum pm_cksel {
	PM_CKSEL_CPU = 0,
	PM_CKSEL_PBA = 2,
	PM_CKSEL_PBB,
	PM_CKSEL_PBC,
	PM_CKSEL_PBD,
};

/*
 * Ids are designed such that
 * PM_MASK(id/32) = (1 << id % 32)
 * would enable the peripheral clock.
 */
enum pm_peripheral {
	PM_PERIPHERAL_OCD = 0,
	PM_PERIPHERAL_PDCA = 32,
	PM_PERIPHERAL_FLASHCALW,
	PM_PERIPHERAL_FLASHCALW_PICORAM,
	PM_PERIPHERAL_USBC,
	PM_PERIPHERAL_CRCCU,
	PM_PERIPHERAL_APBA_BRIDGE,
	PM_PERIPHERAL_APBB_BRIDGE,
	PM_PERIPHERAL_APBC_BRIDGE,
	PM_PERIPHERAL_APBD_BRIDGE,
	PM_PERIPHERAL_AESA,
	PM_PERIPHERAL_IISC = 64,
	PM_PERIPHERAL_SPI,
	PM_PERIPHERAL_TC0,
	PM_PERIPHERAL_TC1,
	PM_PERIPHERAL_TWIM0,
	PM_PERIPHERAL_TWIS0,
	PM_PERIPHERAL_TWIM1,
	PM_PERIPHERAL_TWIS1,
	PM_PERIPHERAL_USART0,
	PM_PERIPHERAL_USART1,
	PM_PERIPHERAL_USART2,
	PM_PERIPHERAL_USART3,
	PM_PERIPHERAL_ADCIFE,
	PM_PERIPHERAL_DACC,
	PM_PERIPHERAL_ACIFC,
	PM_PERIPHERAL_GLOC,
	PM_PERIPHERAL_ABDACB,
	PM_PERIPHERAL_TRNG,
	PM_PERIPHERAL_PARC,
	PM_PERIPHERAL_CATB,
	PM_PERIPHERAL_RESERVED1,
	PM_PERIPHERAL_TWIM2,
	PM_PERIPHERAL_TWIM3,
	PM_PERIPHERAL_LCDCA,
	PM_PERIPHERAL_FLASHCALW_ALT = 96,
	PM_PERIPHERAL_HRAMC1,
	PM_PERIPHERAL_HMATRIX,
	PM_PERIPHERAL_PDCA_ALT,
	PM_PERIPHERAL_CRCCU_ALT,
	PM_PERIPHERAL_USBC_ALT,
	PM_PERIPHERAL_PEVC,
	PM_PERIPHERAL_PM = 128,
	PM_PERIPHERAL_CHIPID,
	PM_PERIPHERAL_SCIF,
	PM_PERIPHERAL_FREQM,
	PM_PERIPHERAL_GPIO,
	PM_PERIPHERAL_BPM = 160,
	PM_PERIPHERAL_BSCIF,
	PM_PERIPHERAL_AST,
	PM_PERIPHERAL_WDT,
	PM_PERIPHERAL_EIC,
	PM_PERIPHERAL_PICOUART,
};

BEGIN_DECLS

void pm_select_main_clock(enum mck_src source_clock);
void pm_enable_clock_div(enum pm_cksel sel_target, uint8_t div);
void pm_set_divmask_clock(uint8_t mask);
void pm_enable_peripheral_clock(enum pm_peripheral periph);
void pm_disable_peripheral_clock(enum pm_peripheral periph);

END_DECLS

#endif
