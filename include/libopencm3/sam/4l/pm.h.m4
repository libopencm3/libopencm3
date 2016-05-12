m4_divert(-1)
m4_define(`XMASK_HELPER', ``#'define PM_$1_$3_SHIFT			$2')

m4_define(`XMASK_RH', `m4_ifelse(`$#', `3', `XMASK_HELPER($1, $2, $3)',
			`XMASK_HELPER($1, $2, $3)
XMASK_RH($1, m4_incr($2), m4_shift(m4_shift(m4_shift($@))))')')

m4_define(`XMASK', `XMASK_RH($1, 0, m4_shift($@))')
m4_divert(0)m4_dnl
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

#ifndef LIBOPENCM3_PMC_H
#define LIBOPENCM3_PMC_H

#include <libopencm3/sam/memorymap.h>

/* --- Power Manager (PM) registers ----------------------- */

/* Main Clock Control MCCTRL Read/Write */
#define PM_MCCTRL			MMIO32(PM_BASE + 0x000)

/* CPU Clock Select CPUSEL Read/Write */
#define PM_CPUSEL			MMIO32(PM_BASE + 0x004)

/* PBA Clock Select PBASEL Read/Write */
#define PM_PBASEL			MMIO32(PM_BASE + 0x00C)

/* PBB Clock Select PBBSEL Read/Write */

#define PM_PBBSEL			MMIO32(PM_BASE + 0x010)
/* PBC Clock Select PBCSEL Read/Write */

#define PM_PBCSEL			MMIO32(PM_BASE + 0x014)
/* PBD Clock Select PBDSEL Read/Write */

#define PM_PBDSEL			MMIO32(PM_BASE + 0x018)
/* CPU Mask CPUMASK Read/Write */

#define PM_CPUMASK			MMIO32(PM_BASE + 0x020)
/* HSB Mask HSBMASK Read/Write */

#define PM_HSBMASK			MMIO32(PM_BASE + 0x024)
/* PBA Mask PBAMASK Read/Write */

#define PM_PBAMASK			MMIO32(PM_BASE + 0x028)
/* PBB Mask PBBMASK Read/Write */

#define PM_PBBMASK			MMIO32(PM_BASE + 0x02C)
/* PBC Mask PBCMASK Read/Write */

#define PM_PBCMASK			MMIO32(PM_BASE + 0x030)
/* PBD Mask PBDMASK Read/Write */

#define PM_PBDMASK			MMIO32(PM_BASE + 0x034)
/* PBA Divided Mask PBADIVMASK Read/Write */

#define PM_PBADIVMASK			MMIO32(PM_BASE + 0x040)
/* Clock Failure Detector Control CFDCTRL Read/Write */

#define PM_CFDCTRL			MMIO32(PM_BASE + 0x054)
/* Unlock Register UNLOCK Write-only */

#define PM_UNLOCK			MMIO32(PM_BASE + 0x058)
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

#define PM_CPUSEL_CPUDIV_SHIFT			7
#define PM_CPUSEL_CPUSEL_SHIFT			0

#define PM_PBSEL_PBDIV_SHIFT			7
#define PM_PBSEL_PBSEL_SHIFT			0

XMASK(CPUMASK, OSC)

XMASK(HSBMASK, PDCA, FLASHCALW, FLASHCALW_PICO, USBC, CRCCU, APBA, APBB, APBC, APBD, AESA)

XMASK(PBAMASK, IISC, SPI, TC0, TC1, TWIM0, TWIS0, TWIM1, TWIS1,
		USART0, USART1, USART2, USART3,
		ADCIFE, DACC, ACIFC, GLOC, ABDACB, TRNG, PARC, CATB, NOTHING, TWIM2, TWIM3, LCDCA)

XMASK(PBBMASK, FLASHCALW, HRAMC1, HMATRIX, PDCA, CRCCU, USBC, PEVC)

XMASK(PBCMASK, PM, CHIPID, SCIF, FREQM, GPIO)

XMASK(PBDMASK, BPM, BSCIF, AST, WDT, EIC, PICOUART)

#endif
