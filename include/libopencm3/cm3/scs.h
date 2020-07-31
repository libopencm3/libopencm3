/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
 * Copyright (C) 2012 Benjamin Vernoux <titanmkd@gmail.com>
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

#ifndef LIBOPENCM3_CM3_SCS_H
#define LIBOPENCM3_CM3_SCS_H

/**
 * @defgroup cm_scs Cortex-M System Control Space
 * @ingroup CM3_defines
 * The System Control Space (SCS) is a memory-mapped 4KB address space that
 * provides 32-bit registers for configuration, status reporting and control.
 * The SCS registers divide into the following groups:
 * - system control and identification
 * - the CPUID processor identification space
 * - system configuration and status
 * - fault reporting
 * - a system timer, SysTick
 * - a Nested Vectored Interrupt Controller (NVIC)
 * - a Protected Memory System Architecture (PMSA)
 * - system debug.
 *
 * Most portions of the SCS are covered by their own header files, eg
 * systick.h, dwt.h, scb.h, itm.h, fpb.h
 * @{
 */

/** @defgroup cm_scs_registers SCS Registers
 * @ingroup cm_scs
 * @{
 */

/**
 * Debug Halting Control and Status Register (DHCSR).
 *
 * Purpose Controls halting debug.
 * Usage constraints: The effect of modifying the C_STEP or C_MASKINTS bit when
 * the system is running with halting debug enabled is UNPREDICTABLE.
 * Halting debug is enabled when C_DEBUGEN is set to 1. The system is running
 * when S_HALT is set to 0.
 * - When C_DEBUGEN is set to 0, the processor ignores the values of all other
 *   bits in this register.
 * - For more information about the use of DHCSR see Debug stepping on page
 *   C1-824.
 * Configurations Always implemented.
 */
#define SCS_DHCSR		MMIO32(SCS_BASE + 0xDF0)
/**
 * Debug Core Register Selector Register (DCRSR).
 *
 * Purpose With the DCRDR, the DCRSR provides debug access to the ARM core
 * registers, special-purpose registers, and Floating-point extension
 * registers. A write to DCRSR specifies the register to transfer, whether the
 * transfer is a read or a write, and starts the transfer.
 * Usage constraints: Only accessible in Debug state.
 * Configurations Always implemented.
 *
 */
#define SCS_DCRSR		MMIO32(SCS_BASE + 0xDF4)
/**
 * Debug Core Register Data Register (DCRDR)
 *
 * Purpose With the DCRSR, see Debug Core Register Selector Register, the DCRDR
 * provides debug access to the ARM core registers, special-purpose registers,
 * and Floating-point extension registers. The DCRDR is the data register for
 * these accesses.
 * - Used on its own, the DCRDR provides a message passing resource between an
 *   external debugger and a debug agent running on the processor.
 * Note:
 * The architecture does not define any handshaking mechanism for this use of
 * DCRDR.
 * Usage constraints: See Use of DCRSR and DCRDR for constraints that apply to
 * particular transfers using the DCRSR and DCRDR.
 * Configurations Always implemented.
 *
 */
#define SCS_DCRDR		MMIO32(SCS_BASE + 0xDF8)
/**
 * Debug Exception and Monitor Control Register (DEMCR).
 *
 * Purpose Manages vector catch behavior and DebugMonitor handling when
 * debugging.
 * Usage constraints:
 * - Bits [23:16] provide DebugMonitor exception control.
 * - Bits [15:0] provide Debug state, halting debug, control.
 * Configurations Always implemented.
 *
 */
#define SCS_DEMCR		MMIO32(SCS_BASE + 0xDFC)

/**@}*/

/* Debug Halting Control and Status Register (DHCSR) */
#define SCS_DHCSR_DBGKEY	0xA05F0000
#define SCS_DHCSR_C_DEBUGEN	0x00000001
#define SCS_DHCSR_C_HALT	0x00000002
#define SCS_DHCSR_C_STEP	0x00000004
#define SCS_DHCSR_C_MASKINTS	0x00000008
#define SCS_DHCSR_C_SNAPSTALL	0x00000020
#define SCS_DHCSR_S_REGRDY	0x00010000
#define SCS_DHCSR_S_HALT	0x00020000
#define SCS_DHCSR_S_SLEEP	0x00040000
#define SCS_DHCSR_S_LOCKUP	0x00080000
#define SCS_DHCSR_S_RETIRE_ST	0x01000000
#define SCS_DHCSR_S_RESET_ST	0x02000000

/* Debug Core Register Selector Register (DCRSR) */
#define SCS_DCRSR_REGSEL_MASK	0x0000001F
#define SCS_DCRSR_REGSEL_XPSR	0x00000010
#define SCS_DCRSR_REGSEL_MSP	0x00000011
#define SCS_DCRSR_REGSEL_PSP	0x00000012

/* Debug Exception and Monitor Control Register (DEMCR) */
/* Bits 31:25 - Reserved */
#define SCS_DEMCR_TRCENA	(1 << 24)
/* Bits 23:20 - Reserved */
#define SCS_DEMCR_MON_REQ	(1 << 19)
#define SCS_DEMCR_MON_STEP	(1 << 18)
#define SCS_DEMCR_VC_MON_PEND	(1 << 17)
#define SCS_DEMCR_VC_MON_EN	(1 << 16)
/* Bits 15:11 - Reserved */
#define SCS_DEMCR_VC_HARDERR	(1 << 10)
#define SCS_DEMCR_VC_INTERR	(1 << 9)
#define SCS_DEMCR_VC_BUSERR	(1 << 8)
#define SCS_DEMCR_VC_STATERR	(1 << 7)
#define SCS_DEMCR_VC_CHKERR	(1 << 6)
#define SCS_DEMCR_VC_NOCPERR	(1 << 5)
#define SCS_DEMCR_VC_MMERR	(1 << 4)
/* Bits 3:1 - Reserved */
#define SCS_DEMCR_VC_CORERESET	(1 << 0)

/* CoreSight Lock Status Register for this peripheral */
#define SCS_DWT_LSR		MMIO32(SCS_DWT_BASE + 0xFB4)
/* CoreSight Lock Access Register for this peripheral */
#define SCS_DWT_LAR		MMIO32(SCS_DWT_BASE + 0xFB0)


/**@}*/
#endif
