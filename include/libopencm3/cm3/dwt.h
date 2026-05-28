/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
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

#ifndef LIBOPENCM3_CM3_DWT_H
#define LIBOPENCM3_CM3_DWT_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/cm3/memorymap.h>

/**
 * @defgroup cm_dwt Cortex-M Data Watch and Trace unit.
 * @ingroup CM3_defines
 * System Control Space (SCS) =>  Data Watchpoint and Trace (DWT).
 * See "ARMv7-M Architecture Reference Manual"
 * and "ARMv6-M Architecture Reference Manual"
 * The DWT is an optional debug unit that provides watchpoints, data tracing,
 * and system profiling for the processor.
 * @{
 */

/*****************************************************************************/
/* Register definitions                                                      */
/*****************************************************************************/

/** DWT Control register
 * Purpose Provides configuration and status information for the DWT block, and
 * used to control features of the block
 * Usage constraints: There are no usage constraints.
 * Configurations Always implemented.
 */
#define DWT_CTRL			MMIO32(DWT_BASE + 0x00U)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || defined(__ARM_ARCH_8M_MAIN__)

/**
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
#define DWT_CYCCNT			MMIO32(DWT_BASE + 0x04U)

/** DWT_CPICNT register
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
#define DWT_CPICNT			MMIO32(DWT_BASE + 0x08U)
#define DWT_EXCCNT			MMIO32(DWT_BASE + 0x0cU)
#define DWT_SLEEPCNT			MMIO32(DWT_BASE + 0x10U)
#define DWT_LSUCNT			MMIO32(DWT_BASE + 0x14U)
#define DWT_FOLDCNT			MMIO32(DWT_BASE + 0x18U)

#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || defined(__ARM_ARCH_8M_MAIN__) */

#define DWT_PCSR			MMIO32(DWT_BASE + 0x1cU)
#define DWT_COMP(n)			MMIO32(DWT_BASE + 0x20U + ((n) * 16U))
#ifndef __ARM_ARCH_8M_MAIN__
#define DWT_MASK(n)			MMIO32(DWT_BASE + 0x24U + ((n) * 16U))
#endif
#define DWT_FUNCTION(n)			MMIO32(DWT_BASE + 0x28U + ((n) * 16U))
#ifdef __ARM_ARCH_8M_MAIN__
#define DWT_VMASK(n)			MMIO32(DWT_BASE + 0x2cU + ((n) * 16U))
#endif

/* CoreSight Lock Status Register for this peripheral */
#define DWT_LSR			MMIO32(DWT_BASE + CORESIGHT_LSR_OFFSET)
/* CoreSight Lock Access Register for this peripheral */
#define DWT_LAR			MMIO32(DWT_BASE + CORESIGHT_LAR_OFFSET)


/*****************************************************************************/
/* Register values                                                           */
/*****************************************************************************/

/* --- DWT_CTRL values ---------------------------------------------------- */

#define DWT_CTRL_NUMCOMP_SHIFT		28U
#define DWT_CTRL_NUMCOMP		(0x0fU << DWT_CTRL_NUMCOMP_SHIFT)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || defined(__ARM_ARCH_8M_MAIN__)

#define DWT_CTRL_NOTRCPKT		(1U << 27U)
#define DWT_CTRL_NOEXTTRIG		(1U << 26U)
#define DWT_CTRL_NOCYCCNT		(1U << 25U)
#define DWT_CTRL_NOPRFCCNT		(1U << 24U)

#define DWT_CTRL_CYCEVTENA		(1U << 22U)
#define DWT_CTRL_FOLDEVTENA		(1U << 21U)
#define DWT_CTRL_LSUEVTENA		(1U << 20U)
#define DWT_CTRL_SLEEPEVTENA		(1U << 19U)
#define DWT_CTRL_EXCEVTENA		(1U << 18U)
#define DWT_CTRL_CPIEVTENA		(1U << 17U)
#define DWT_CTRL_EXCTRCENA		(1U << 16U)
#define DWT_CTRL_PCSAMPLENA		(1U << 12U)

#define DWT_CTRL_SYNCTAP_SHIFT		10U
#define DWT_CTRL_SYNCTAP		(3U << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_DISABLED	(0U << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT24		(1U << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT26		(2U << DWT_CTRL_SYNCTAP_SHIFT)
#define DWT_CTRL_SYNCTAP_BIT28		(3U << DWT_CTRL_SYNCTAP_SHIFT)

#define DWT_CTRL_CYCTAP			(1U << 9U)

#define DWT_CTRL_POSTCNT_SHIFT		5U
#define DWT_CTRL_POSTCNT		(0x0fU << DWT_CTRL_POSTCNT_SHIFT)

#define DWT_CTRL_POSTPRESET_SHIFT	1U
#define DWT_CTRL_POSTPRESET		(0x0fU << DWT_CTRL_POSTPRESET_SHIFT)

/**
 * CYCCNTENA Enables the Cycle counter.
 * 0 = Disabled, 1 = Enabled
 * This bit is UNK/SBZP if the NOCYCCNT bit is RAO.
 */
#define DWT_CTRL_CYCCNTENA		(1U << 0U)

#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || defined(__ARM_ARCH_8M_MAIN__) */

/* --- DWT_MASK(x) values -------------------------------------------------- */

#define DWT_MASKx_MASK			0x0fU

/* --- DWT_FUNCTION(x) values ---------------------------------------------- */

#define DWT_FUNCTIONx_MATCHED		(1U << 24U)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || defined(__ARM_ARCH_8M_MAIN__)

#define DWT_FUNCTIONx_DATAVADDR1_SHIFT	16U
#define DWT_FUNCTIONx_DATAVADDR1	(15U << DWT_FUNCTIONx_DATAVADDR1_SHIFT)

#define DWT_FUNCTIONx_DATAVADDR0_SHIFT	12U
#define DWT_FUNCTIONx_DATAVADDR0	(15U << DWT_FUNCTIONx_DATAVADDR0_SHIFT)

#define DWT_FUNCTIONx_DATAVSIZE_SHIFT	10U
#define DWT_FUNCTIONx_DATAVSIZE		(3U << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_BYTE	(0U << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_HALF	(1U << DWT_FUNCTIONx_DATAVSIZE_SHIFT)
#define DWT_FUNCTIONx_DATAVSIZE_WORD	(2U << DWT_FUNCTIONx_DATAVSIZE_SHIFT)

#define DWT_FUNCTIONx_LNK1ENA		(1U << 9U)
#define DWT_FUNCTIONx_DATAVMATCH	(1U << 8U)
#define DWT_FUNCTIONx_CYCMATCH		(1U << 7U)
#define DWT_FUNCTIONx_EMITRANGE		(1U << 5U)

#endif /* defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || defined(__ARM_ARCH_8M_MAIN__) */

#define DWT_FUNCTIONx_FUNCTION				15U
#define DWT_FUNCTIONx_FUNCTION_DISABLED			0U

/* Those defined only on ARMv6 */
#if defined(__ARM_ARCH_6M__)

#define DWT_FUNCTIONx_FUNCTION_PCWATCH			4U
#define DWT_FUNCTIONx_FUNCTION_DWATCH_R			5U
#define DWT_FUNCTIONx_FUNCTION_DWATCH_W			6U
#define DWT_FUNCTIONx_FUNCTION_DWATCH_RW		7U

#endif /* defined(__ARM_ARCH_6M__)*/

/*****************************************************************************/
/* API definitions                                                           */
/*****************************************************************************/

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

bool dwt_enable_cycle_counter(void);
uint32_t dwt_read_cycle_counter(void);

END_DECLS

/**@}*/

#endif /* LIBOPENCM3_CM3_DWT_H */
