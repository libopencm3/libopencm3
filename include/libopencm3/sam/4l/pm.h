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

#ifndef LIBOPENCM3_PM_H
#define LIBOPENCM3_PM_H

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

#define PM_CPUMASK_OSC_SHIFT			0

#define PM_HSBMASK_PDCA_SHIFT			0
#define PM_HSBMASK_FLASHCALW_SHIFT			1
#define PM_HSBMASK_FLASHCALW_PICO_SHIFT			2
#define PM_HSBMASK_USBC_SHIFT			3
#define PM_HSBMASK_CRCCU_SHIFT			4
#define PM_HSBMASK_APBA_SHIFT			5
#define PM_HSBMASK_APBB_SHIFT			6
#define PM_HSBMASK_APBC_SHIFT			7
#define PM_HSBMASK_APBD_SHIFT			8
#define PM_HSBMASK_AESA_SHIFT			9

#define PM_PBAMASK_IISC_SHIFT			0
#define PM_PBAMASK_SPI_SHIFT			1
#define PM_PBAMASK_TC0_SHIFT			2
#define PM_PBAMASK_TC1_SHIFT			3
#define PM_PBAMASK_TWIM0_SHIFT			4
#define PM_PBAMASK_TWIS0_SHIFT			5
#define PM_PBAMASK_TWIM1_SHIFT			6
#define PM_PBAMASK_TWIS1_SHIFT			7
#define PM_PBAMASK_USART0_SHIFT			8
#define PM_PBAMASK_USART1_SHIFT			9
#define PM_PBAMASK_USART2_SHIFT			10
#define PM_PBAMASK_USART3_SHIFT			11
#define PM_PBAMASK_ADCIFE_SHIFT			12
#define PM_PBAMASK_DACC_SHIFT			13
#define PM_PBAMASK_ACIFC_SHIFT			14
#define PM_PBAMASK_GLOC_SHIFT			15
#define PM_PBAMASK_ABDACB_SHIFT			16
#define PM_PBAMASK_TRNG_SHIFT			17
#define PM_PBAMASK_PARC_SHIFT			18
#define PM_PBAMASK_CATB_SHIFT			19
/* -- */
#define PM_PBAMASK_TWIM2_SHIFT			21
#define PM_PBAMASK_TWIM3_SHIFT			22
#define PM_PBAMASK_LCDCA_SHIFT			23

#define PM_PBBMASK_FLASHCALW_SHIFT			0
#define PM_PBBMASK_HRAMC1_SHIFT			1
#define PM_PBBMASK_HMATRIX_SHIFT			2
#define PM_PBBMASK_PDCA_SHIFT			3
#define PM_PBBMASK_CRCCU_SHIFT			4
#define PM_PBBMASK_USBC_SHIFT			5
#define PM_PBBMASK_PEVC_SHIFT			6

#define PM_PBCMASK_PM_SHIFT			0
#define PM_PBCMASK_CHIPID_SHIFT			1
#define PM_PBCMASK_SCIF_SHIFT			2
#define PM_PBCMASK_FREQM_SHIFT			3
#define PM_PBCMASK_GPIO_SHIFT			4

#define PM_PBDMASK_BPM_SHIFT			0
#define PM_PBDMASK_BSCIF_SHIFT			1
#define PM_PBDMASK_AST_SHIFT			2
#define PM_PBDMASK_WDT_SHIFT			3
#define PM_PBDMASK_EIC_SHIFT			4
#define PM_PBDMASK_PICOUART_SHIFT			5

enum mck_src {
	MCK_SRC_RCSYS = 0,
	MCK_SRC_OSC0,
	MCK_SRC_PLL,
	MCK_SRC_DFLL,
	MCK_SRC_RC80M,
	MCK_SRC_RCFAST,
	MCK_SRC_RC1M,
};

#endif
