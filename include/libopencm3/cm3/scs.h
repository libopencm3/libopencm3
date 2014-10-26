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

/*
 * All the definition hereafter are generic for CortexMx ARMv7-M
 * See ARM document "ARMv7-M Architecture Reference Manual" for more details.
 * See also ARM document "ARM Compiler toolchain Developing Software for ARM
 * Processors" for details on System Timer/SysTick.
 */

/*
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
 */

/* System Handler Priority 8 bits Registers, SHPR1/2/3 */
/* Note: 12 8bit Registers */
#define SCS_SHPR(ipr_id)		MMIO8(SCS_BASE + 0xD18 + ipr_id)

/*
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
/* SCS_DHCSR register */
#define SCS_DHCSR		MMIO32(SCS_BASE + 0xDF0)
/*
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
/* SCS_DCRS register */
#define SCS_DCRSR		MMIO32(SCS_BASE + 0xDF4)
/*
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
/* SCS_DCRDR register */
#define SCS_DCRDR		MMIO32(SCS_BASE + 0xDF8)
/*
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
/* SCS_DEMCR register */
#define SCS_DEMCR		MMIO32(SCS_BASE + 0xDFC)

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

/*
 * System Control Space (SCS) => System timer register support in the SCS.
 * To configure SysTick, load the interval required between SysTick events to
 * the SysTick Reload Value register. The timer interrupt, or COUNTFLAG bit in
 * the SysTick Control and Status register, is activated on the transition from
 * 1 to 0, therefore it activates every n+1 clock ticks.  If you require a
 * period of 100, write 99 to the SysTick Reload Value register. The SysTick
 * Reload Value register supports values between 0x1 and 0x00FFFFFF.
 *
 * If you want to use SysTick to generate an event at a timed interval, for
 * example 1ms, you can use the SysTick Calibration Value Register to scale
 * your value for the Reload register. The SysTick Calibration Value Register
 * is a read-only register that contains the number of pulses for a period of
 * 10ms, in the TENMS field, bits[23:0].
 *
 * This register also has a SKEW bit. Bit[30] == 1 indicates that the
 * calibration for 10ms in the TENMS section is not exactly 10ms due to clock
 * frequency. Bit[31] == 1 indicates that the reference clock is not provided.
 */
/*
 * SysTick Control and Status Register (CSR).
 * Purpose Controls the system timer and provides status data.
 * Usage constraints: There are no usage constraints.
 * Configurations Always implemented.
*/
#define SCS_SYST_CSR		MMIO32(SCS_BASE + 0x10)

/* SysTick Reload Value Register (CVR).
 * Purpose Reads or clears the current counter value.
 * Usage constraints:
 * - Any write to the register clears the register to zero.
 * - The counter does not provide read-modify-write protection.
 * - Unsupported bits are read as zero
 * Configurations Always implemented.
 */
#define CM_SCS_SYST_RVR		MMIO32(SCS_BASE + 0x14)

/* SysTick Current Value Register (RVR).
 * Purpose Holds the reload value of the SYST_CVR.
 * Usage constraints There are no usage constraints.
 * Configurations Always implemented.
 */
#define CM_SCS_SYST_CVR		MMIO32(SCS_BASE + 0x18)

/*
 * SysTick Calibration value Register(Read Only) (CALIB)
 * Purpose Reads the calibration value and parameters for SysTick.
 * Usage constraints: There are no usage constraints.
 * Configurations Always implemented.
 */
#define CM_SCS_SYST_CALIB	MMIO32(SCS_BASE + 0x1C)

/* --- SCS_SYST_CSR values ----------------------------------------------- */
/* Counter is operating. */
#define SCS_SYST_CSR_ENABLE			(BIT0)
/* Count to 0 changes the SysTick exception status to pending. */
#define SCS_SYST_CSR_TICKINT		(BIT1)
/* SysTick uses the processor clock. */
#define SCS_SYST_CSR_CLKSOURCE		(BIT2)
/*
 * Indicates whether the counter has counted to 0 since the last read of this
 * register:
 *  0 = Timer has not counted to 0
 *  1 = Timer has counted to 0.
 */
#define SCS_SYST_CSR_COUNTFLAG		(BIT16)

/* --- CM_SCS_SYST_RVR values ---------------------------------------------- */
/* Bit 0 to 23 => RELOAD The value to load into the SYST_CVR when the counter
 * reaches 0.
 */
/* Bit 24 to 31 are Reserved */

/* --- CM_SCS_SYST_CVR values ---------------------------------------------- */
/* Bit0 to 31 => Reads or clears the current counter value. */

/* --- CM_SCS_SYST_CALIB values -------------------------------------------- */
/*
 * Bit0 to 23 => TENMS Optionally, holds a reload value to be used for 10ms
 * (100Hz) timing, subject to system clock skew errors. If this field is zero,
 * the calibration value is not known.
 */
#define SCS_SYST_SYST_CALIB_TENMS_MASK		(BIT24-1)

/*
 * Bit30 => SKEW Indicates whether the 10ms calibration value is exact:
 * 0 = 10ms calibration value is exact.
 * 1 = 10ms calibration value is inexact, because of the clock frequency
 */
#define SCS_SYST_SYST_CALIB_VALUE_INEXACT	(BIT30)
/*
 * Bit31 => NOREF Indicates whether the IMPLEMENTATION DEFINED reference clock
 * is implemented:
 * 0 = The reference clock is implemented.
 * 1 = The reference clock is not implemented.
 * When this bit is 1, the CLKSOURCE bit of the SYST_CSR register is forced to
 * 1 and cannot be cleared to 0.
 */
#define SCS_SYST_SYST_CALIB_REF_NOT_IMPLEMENTED	(BIT31)

/*
 * System Control Space (SCS) =>  Data Watchpoint and Trace (DWT).
 * See "ARMv7-M Architecture Reference Manual"
 * (https://github.com/libopencm3/libopencm3-archive/blob/master/arm/
 * ARMv7-M_ARM.pdf)
 * The DWT is an optional debug unit that provides watchpoints, data tracing,
 * and system profiling for the processor.
 */
/*
 * DWT Control register
 * Purpose Provides configuration and status information for the DWT block, and
 * used to control features of the block
 * Usage constraints: There are no usage constraints.
 * Configurations Always implemented.
 */
#define SCS_DWT_CTRL		MMIO32(DWT_BASE + 0x00)
/*
 * DWT_CYCCNT register
 * Cycle Count Register (Shows or sets the value of the processor cycle
 * counter, CYCCNT)
 * When enabled, CYCCNT increments on each processor clock cycle. On overflow,
 * CYCCNT wraps to zero.
 *
 * Purpose Shows or sets the value of the processor cycle counter, CYCCNT.
 * Usage constraints: The DWT unit suspends CYCCNT counting when the processor
 * is in Debug state.
 * Configurations Implemented: only when DWT_CTRL.NOCYCCNT is RAZ, see Control
 * register, DWT_CTRL.
 * When DWT_CTRL.NOCYCCNT is RAO no cycle counter is implemented and this
 * register is UNK/SBZP.
*/
#define SCS_DWT_CYCCNT		MMIO32(DWT_BASE + 0x04)

/* DWT_CPICNT register
 * Purpose Counts additional cycles required to execute multi-cycle
 * instructions and instruction fetch stalls.
 * Usage constraints: The counter initializes to 0 when software enables its
 * counter overflow event by
 * setting the DWT_CTRL.CPIEVTENA bit to 1.
 * Configurations Implemented: only when DWT_CTRL.NOPRFCNT is RAZ, see Control
 * register, DWT_CTRL.
 * If DWT_CTRL.NOPRFCNT is RAO, indicating that the implementation does not
 * include the profiling counters, this register is UNK/SBZP.
 */
#define SCS_DWT_CPICNT		MMIO32(DWT_BASE + 0x08)

/* DWT_EXCCNT register */
#define SCS_DWT_EXCCNT		MMIO32(DWT_BASE + 0x0C)

/* DWT_EXCCNT register */
#define SCS_DWT_SLEEPCNT	MMIO32(DWT_BASE + 0x10)

/* DWT_EXCCNT register */
#define SCS_DWT_LSUCNT		MMIO32(DWT_BASE + 0x14)

/* DWT_EXCCNT register */
#define SCS_DWT_FOLDCNT		MMIO32(DWT_BASE + 0x18)

/* DWT_PCSR register */
#define SCS_DWT_PCSR		MMIO32(DWT_BASE + 0x18)

/* CoreSight Lock Status Register for this peripheral */
#define SCS_DWT_LSR		MMIO32(SCS_DWT_BASE + 0xFB4)
/* CoreSight Lock Access Register for this peripheral */
#define SCS_DWT_LAR		MMIO32(SCS_DWT_BASE + 0xFB0)

/* --- SCS_DWT_CTRL values ------------------------------------------------- */
/*
 * Enables CYCCNT:
 * 0 = Disabled, 1 = Enabled
 * This bit is UNK/SBZP if the NOCYCCNT bit is RAO.
 */
#define SCS_DWT_CTRL_CYCCNTENA	(BIT0)

/* CoreSight Lock Status Register lock status bit */
#define SCS_LSR_SLK		(1<<1)
/* CoreSight Lock Status Register lock availability bit */
#define SCS_LSR_SLI		(1<<0)
/* CoreSight Lock Access key, common for all */
#define SCS_LAR_KEY		0xC5ACCE55

/* TODO bit definition values for other DWT_XXX register */

/* Macro to be called at startup to enable SCS & Cycle Counter */
#define SCS_DWT_CYCLE_COUNTER_ENABLED()	((SCS_DEMCR |= SCS_DEMCR_TRCENA)\
				(SCS_DWT_CTRL |= SCS_DWT_CTRL_CYCCNTENA))

#define SCS_SYSTICK_DISABLED()	(SCS_SYST_CSR = 0)

/* Macro to be called at startup to Enable CortexMx SysTick (but IRQ not
 * enabled)
 */
#define SCS_SYSTICK_ENABLED()	(SCS_SYST_CSR = (SCS_SYST_CSR_ENABLE | \
				 SCS_SYST_CSR_CLKSOURCE))

/* Macro to be called at startup to Enable CortexMx SysTick and IRQ */
#define SCS_SYSTICK_AND_IRQ_ENABLED()  (SCS_SYST_CSR = (SCS_SYST_CSR_ENABLE | \
					SCS_SYST_CSR_CLKSOURCE | \
					SCS_SYST_CSR_TICKINT))

#endif
