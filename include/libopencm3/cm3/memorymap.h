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

/* --- ARM Cortex-M3 specific definitions ---------------------------------- */

/* Private peripheral bus - Internal */
#define PPBI_BASE                       0xE0000000
#define ITM_BASE                        (PPBI_BASE + 0x0000)
#define DWT_BASE                        (PPBI_BASE + 0x1000)
#define FPB_BASE                        (PPBI_BASE + 0x2000)
/* PPBI_BASE + 0x3000 (0xE000 3000 - 0xE000 DFFF): Reserved */
#define SCS_BASE                        (PPBI_BASE + 0xE000)
/* PPBI_BASE + 0xF000 (0xE000 F000 - 0xE003 FFFF): Reserved */
#define TPIU_BASE                       (PPBI_BASE + 0x40000)

/* --- ITM: Instrumentation Trace Macrocell --- */
/* TODO */

/* --- DWT: Data Watchpoint and Trace unit --- */
/* TODO */

/* --- FPB: Flash Patch and Breakpoint unit --- */
/* TODO */

/* --- SCS: System Control Space --- */

/* ITR: Interrupt Type Register */
#define ITR_BASE                        (SCS_BASE + 0x0000)
/* SYS_TICK: System Timer */
#define SYS_TICK_BASE                   (SCS_BASE + 0x0010)
/* NVIC: Nested Vector Interrupt Controller */
#define NVIC_BASE                       (SCS_BASE + 0x0100)
/* SCB: System Control Block */
#define SCB_BASE                        (SCS_BASE + 0x0D00)
/* STE: Software Trigger Interrupt Register */
#define STIR_BASE                       (SCS_BASE + 0x0F00)
/* ID: ID space */
#define ID_BASE                         (SCS_BASE + 0x0FD0)

#endif
