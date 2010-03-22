/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENSTM32_SCB_H
#define LIBOPENSTM32_SCB_H

#include <libopenstm32/memorymap.h>
#include <libopenstm32/common.h>

/* --- SCB: Registers ------------------------------------------------------ */

/* CPUID: CPUID base register */
#define SCB_CPUID                       MMIO32(SCB_BASE + 0x00)

/* ICSR: Interrupt Control State Register */
#define SCB_ICSR                        MMIO32(SCB_BASE + 0x04)

/* VTOR: Vector Table Offset Register */
#define SCB_VTOR                        MMIO32(SCB_BASE + 0x08)

/* AIRCR: Application Interrupt and Reset Control Register */
#define SCB_AIRCR                       MMIO32(SCB_BASE + 0x0C)

/* SCR: System Control Register */
#define SCB_SCR                         MMIO32(SCB_BASE + 0x10)

/* CCR: Configuration Control Register */
#define SCB_CCR                         MMIO32(SCB_BASE + 0x14)

/* SHP: System Handler Priority Registers */
/* Note: 12 8bit registers */
#define SCB_SHPR(shpr_id)               MMIO8(SCB_BASE + 0x18 + shpr_id)

/* SHCSR: System Handler Control and State Register */
#define SCB_SHCSR                       MMIO32(SCB_BASE + 0x24)

/* CFSR: Configurable Fault Status Registers */
#define SCB_CFSR                        MMIO32(SCB_BASE + 0x28)

/* HFSR: Hard Fault Status Register */
#define SCB_HFSR                        MMIO32(SCB_BASE + 0x2C)

/* DFSR: Debug Fault Status Register */
#define SCB_DFSR                        MMIO32(SCB_BASE + 0x30)

/* MMFAR: Memory Manage Fault Address Register */
#define SCB_MMFAR                       MMIO32(SCB_BASE + 0x34)

/* BFAR: Bus Fault Address Register */
#define SCB_BFAR                        MMIO32(SCB_BASE + 0x38)

/* AFSR: Auxiliary Fault Status Register */
#define SCB_AFSR                        MMIO32(SCB_BASE + 0x3C)

/* --- SCB values ---------------------------------------------------------- */

/* --- SCB_CPUID values ---------------------------------------------------- */
/* Implementer[31:24]: Implementer code */
#define SCP_CPUID_IMPLEMENTER_LSB		24
/* Variant[23:20]: Variant number */
#define SCP_CPUID_VARIANT_LSB			20
/* Constant[19:16]: Reads as 0xF */
#define SCP_CPUID_CONSTANT_LSB			16
/* PartNo[15:4]: Part number of the processor */
#define SCP_CPUID_PARTNO_LSB			4
/* Revision[3:0]: Revision number */
#define SCP_CPUID_REVISION_LSB			0

/* --- SCB_ICSR values ----------------------------------------------------- */
/* NMIPENDSET: NMI set-pending bit */
#define SCB_ICSR_NMIPENDSET			(1 << 31)
/* Bits [30:29]: reserved - must be kept cleared */
/* PENDSVSET: PendSV set-pending bit */
#define SCB_ICSR_PENDSVSET			(1 << 28)
/* PENDSVCLR: PendSV clear-pending bit */
#define SCB_ICSR_PENDSVCLR			(1 << 27)
/* PENDSTSET: SysTick exception set-pending bit */
#define SCB_ICSR_PENDSTSET			(1 << 26)
/* PENDSTCLR: SysTick exception clear-pending bit */
#define SCB_ICSR_PENDSTCLR			(1 << 25)
/* Bit 24: reserved - must be kept cleared */
/* Bit 23: reserved for debug - reads as 0 when not in debug mode */
/* ISRPENDING: Interrupt pending flag, excluding NMI and Faults */
#define SCB_ICSR_ISRPENDING			(1 << 22)
/* VECTPENDING[21:12] Pending vector */
#define SCB_ICSR_VECTPENDING_LSB		12
/* RETOBASE: Return to base level */
#define SCB_ICSR_RETOBASE			(1 << 11)
/* Bits [10:9]: reserved - must be kept cleared */
/* VECTACTIVE[8:0] Active vector */
#define SCB_ICSR_VECTACTIVE_LSB			0

/* --- SCB_VTOR values ----------------------------------------------------- */
/* Bits [31:30]: reserved - must be kept cleared */
/* TBLOFF[29:9]: Vector table base offset field */
#define SCB_VTOR_TBLOFF_LSB			9 /* inconsistent datasheet - LSB could be 11 */ 

/* --- SCB_AIRCR values ---------------------------------------------------- */
/* VECTKEYSTAT[31:16]/ VECTKEY[31:16] Register key */
#define SCB_AIRCR_VECTKEYSTAT_LSB		16
/* ENDIANESS Data endianness bit */
#define SCB_AIRCR_ENDIANESS			(1 << 15)
/* Bits [14:11]: reserved - must be kept cleared */
/* PRIGROUP[10:8]: Interrupt priority grouping field */
#define SCB_AIRCR_PRIGROUP_LSB			8
#define SCB_AIRCR_PRIGROUP_GROUP16_NOSUB	0x3
#define SCB_AIRCR_PRIGROUP_GROUP8_SUB2		0x4
#define SCB_AIRCR_PRIGROUP_GROUP4_SUB4		0x5
#define SCB_AIRCR_PRIGROUP_GROUP2_SUB8		0x6
#define SCB_AIRCR_PRIGROUP_NOGROUP_SUB16	0x7
/* Bits [7:3]: reserved - must be kept cleared */
/* SYSRESETREQ System reset request */
#define SCB_AIRCR_SYSRESETREQ			(1 << 2)
/* VECTCLRACTIVE */
#define SCB_AIRCR_VECTCLRACTIVE			(1 << 1)
/* VECTRESET */
#define SCB_AIRCR_VECTRESET			(1 << 0)

/* --- SCB_SCR values ------------------------------------------------------ */
/* Bits [31:5]: reserved - must be kept cleared */
/* SEVEONPEND Send Event on Pending bit */
#define SCB_SCR_SEVEONPEND			(1 << 4)
/* Bit 3: reserved - must be kept cleared */
/* SLEEPDEEP */
#define SCB_SCR_SLEEPDEEP			(1 << 2)
/* SLEEPONEXIT */
#define SCB_SCR_SLEEPONEXIT			(1 << 1)
/* Bit 0: reserved - must be kept cleared */

/* --- SCB_CCR values ------------------------------------------------------ */
/* Bits [31:10]: reserved - must be kept cleared */
/* STKALIGN */
#define SCB_CCR_STKALIGN			(1 << 9)
/* BFHFNMIGN */
#define SCB_CCR_BFHFNMIGN			(1 << 8)
/* Bits [7:5]: reserved - must be kept cleared */
/* DIV_0_TRP */
#define SCB_CCR_DIV_0_TRP			(1 << 4)
/* UNALIGN_TRP */
#define SCB_CCR_UNALIGN_TRP			(1 << 3)
/* Bit 2: reserved - must be kept cleared */
/* USERSETMPEND */
#define SCB_CCR_USERSETMPEND			(1 << 1)
/* NONBASETHRDENA */
#define SCB_CCR_NONBASETHRDENA			(1 << 0)


/* --- SCB functions ------------------------------------------------------- */

#endif
