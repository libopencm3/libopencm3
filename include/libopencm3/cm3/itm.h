/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Gareth McMullin <gareth@blacksphere.co.nz>
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

#ifndef LIBOPENCM3_CM3_ITM_H
#define LIBOPENCM3_CM3_ITM_H

/* Cortex-M3 Instrumentation Trace Macrocell (ITM) */

/* --- ITM registers ------------------------------------------------------- */

/* Stimulus Port x (ITM_STIM[x]) */
#define ITM_STIM			((volatile u32*)(ITM_BASE))

/* Trace Enable ports (ITM_TER[x]) */
#define ITM_TER				((volatile u32*)(ITM_BASE + 0xE00))

/* Trace Privilege (ITM_TPR) */
#define ITM_TPR				MMIO32(ITM_BASE + 0xE40)

/* Trace Control (ITM_TCR) */
#define ITM_TCR				MMIO32(ITM_BASE + 0xE80)

/* TODO: PID, CID */

/* --- ITM_STIM values ----------------------------------------------------- */

/* Bits 31:0 - Write to port FIFO for forwarding as software event packet */
/* Bits 31:1 - RAZ */
#define ITM_STIM_FIFOREADY		(1 << 0)

/* --- ITM_TER values ------------------------------------------------------ */

/* Bits 31:0 - Stimulus port #N is enabled with STIMENA[N] is set */

/* --- ITM_TPR values ------------------------------------------------------ */
/*
 * Bits 31:0 - Bit [N] of PRIVMASK controls stimulus ports 8N to 8N+7
 *             0: User access allowed to stimulus ports
 *             1: Privileged access only to stimulus ports
 */

/* --- ITM_TCR values ------------------------------------------------------ */

/* Bits 31:24 - Reserved */
#define ITM_TCR_BUSY			(1 << 23)
#define ITM_TCR_TRACE_BUS_ID_MASK	(0x3f << 16)
/* Bits 15:10 - Reserved */
#define ITM_TCR_TSPRESCALE_NONE		(0 << 8)
#define ITM_TCR_TSPRESCALE_DIV4		(1 << 8)
#define ITM_TCR_TSPRESCALE_DIV16	(2 << 8)
#define ITM_TCR_TSPRESCALE_DIV64	(3 << 8)
#define ITM_TCR_TSPRESCALE_MASK		(3 << 8)
/* Bits 7:5 - Reserved */
#define ITM_TCR_SWOENA			(1 << 4)
#define ITM_TCR_TXENA			(1 << 3)
#define ITM_TCR_SYNCENA			(1 << 2)
#define ITM_TCR_TSENA			(1 << 1)
#define ITM_TCR_ITMENA			(1 << 0)

#endif
