/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LIBOPENCM3_CM3_MEMORYMAP_H
#define LIBOPENCM3_CM3_MEMORYMAP_H

/* --- ARM Cortex-M0, M3 and M4 specific definitions ----------------------- */

/* Private peripheral bus - Internal */
#define PPBI_BASE                       (0xE0000000U)

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/* ITM: Instrumentation Trace Macrocell */
#define ITM_BASE                        (PPBI_BASE + 0x0000)

/* DWT: Data Watchpoint and Trace unit */
#define DWT_BASE                        (PPBI_BASE + 0x1000)

/* FPB: Flash Patch and Breakpoint unit */
#define FPB_BASE                        (PPBI_BASE + 0x2000)
#endif

/* PPBI_BASE + 0x3000 (0xE000 3000 - 0xE000 DFFF): Reserved */

#define SCS_BASE                        (PPBI_BASE + 0xE000)

/* PPBI_BASE + 0xF000 (0xE000 F000 - 0xE003 FFFF): Reserved */

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define TPIU_BASE                       (PPBI_BASE + 0x40000)
#endif

/* --- SCS: System Control Space --- */

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/* ITR: Interrupt Type Register */
#define ITR_BASE                        (SCS_BASE + 0x0000)
#endif

/* SYS_TICK: System Timer */
#define SYS_TICK_BASE                   (SCS_BASE + 0x0010)

/* NVIC: Nested Vector Interrupt Controller */
#define NVIC_BASE                       (SCS_BASE + 0x0100)

/* SCB: System Control Block */
#define SCB_BASE                        (SCS_BASE + 0x0D00)

/* MPU: Memory protection unit */
#define MPU_BASE                        (SCS_BASE + 0x0D90)

/* Those defined only on CM0*/
#if defined(__ARM_ARCH_6M__)
/* DEBUG: Debug control and configuration */
#define DEBUG_BASE                      (SCS_BASE + 0x0DF0)
#endif

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
/* STE: Software Trigger Interrupt Register */
#define STIR_BASE                       (SCS_BASE + 0x0F00)
/* ID: ID space */
#define ID_BASE                         (SCS_BASE + 0x0FD0)
#endif

/**
 * @defgroup coresight_registers Coresight Registers
 * @{
 * CoreSight Lock Status Registers and Lock Access Registers are
 * documented for the DWT, ITM, FPB and TPIU peripherals
 */
#define CORESIGHT_LSR_OFFSET	0xfb4
#define CORESIGHT_LAR_OFFSET	0xfb0

/** CoreSight Lock Status Register lock status bit */
#define CORESIGHT_LSR_SLK		(1<<1)
/** CoreSight Lock Status Register lock availability bit */
#define CORESIGHT_LSR_SLI		(1<<0)
/** CoreSight Lock Access key, common for all */
#define CORESIGHT_LAR_KEY		0xC5ACCE55

/**@}*/

#endif
