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

#include <stdbool.h>
#include <stdint.h>

#include <libopencm3/cm3/common.h>
#include <libopencm3/cm3/memorymap.h>

/**
 * @defgroup cm_itm Cortex-M Instrumentation Trace Macrocell (ITM)
 * @ingroup CM3_defines
 * @{
 */

/* Those defined only on ARMv7 and above */
#if !defined(__ARM_ARCH_7M__) && !defined(__ARM_ARCH_7EM__)
#error "Instrumentation Trace Macrocell not available in CM0"
#endif

/* --- ITM registers ------------------------------------------------------- */

/* Stimulus Port x (ITM_STIM<sz>(x)) */
#define ITM_STIM8(n)			(MMIO8(ITM_BASE + ((n)*4)))
#define ITM_STIM16(n)			(MMIO16(ITM_BASE + ((n)*4)))
#define ITM_STIM32(n)			(MMIO32(ITM_BASE + ((n)*4)))

/* Trace Enable ports (ITM_TER[x]) */
#define ITM_TER				(&MMIO32(ITM_BASE + 0xE00))

/* Trace Privilege (ITM_TPR) */
#define ITM_TPR				MMIO32(ITM_BASE + 0xE40)

/* Trace Control (ITM_TCR) */
#define ITM_TCR				MMIO32(ITM_BASE + 0xE80)

/* CoreSight Lock Status Register for this peripheral */
#define ITM_LSR			MMIO32(ITM_BASE + 0xFB4)
/* CoreSight Lock Access Register for this peripheral */
#define ITM_LAR			MMIO32(ITM_BASE + 0xFB0)

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

/* --- ITM_LAR values ------------------------------------------------------ */
#define ITM_LAR_WRITE_ENABLE (0xC5ACCE55)

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

/* --- ITM port bitmask values ---------------------------------------------- */
#define ITM_PORT0  (1 << 0)
#define ITM_PORT1  (1 << 1)
#define ITM_PORT2  (1 << 2)
#define ITM_PORT3  (1 << 3)
#define ITM_PORT4  (1 << 4)
#define ITM_PORT5  (1 << 5)
#define ITM_PORT6  (1 << 6)
#define ITM_PORT7  (1 << 7)
#define ITM_PORT8  (1 << 8)
#define ITM_PORT9  (1 << 9)
#define ITM_PORT10 (1 << 10)
#define ITM_PORT11 (1 << 11)
#define ITM_PORT12 (1 << 12)
#define ITM_PORT13 (1 << 13)
#define ITM_PORT14 (1 << 14)
#define ITM_PORT15 (1 << 15)
#define ITM_PORT16 (1 << 16)
#define ITM_PORT17 (1 << 17)
#define ITM_PORT18 (1 << 18)
#define ITM_PORT19 (1 << 19)
#define ITM_PORT20 (1 << 20)
#define ITM_PORT21 (1 << 21)
#define ITM_PORT22 (1 << 22)
#define ITM_PORT23 (1 << 23)
#define ITM_PORT24 (1 << 24)
#define ITM_PORT25 (1 << 25)
#define ITM_PORT26 (1 << 26)
#define ITM_PORT27 (1 << 27)
#define ITM_PORT28 (1 << 28)
#define ITM_PORT29 (1 << 29)
#define ITM_PORT30 (1 << 30)
#define ITM_PORT31 (1 << 31)

/*****************************************************************************/
/* API Functions                                                             */
/*****************************************************************************/

BEGIN_DECLS

void itm_set_write_access_enabled(bool enable);
void itm_set_trace_bus_id(uint8_t id);
void itm_set_enabled(bool enable);
void itm_enable_stimulus_ports(uint32_t ports);
void itm_disable_stimulus_ports(uint32_t ports);
void itm_set_stimulus_port_mask(uint32_t mask);
void itm_send_blocking_u8(uint8_t port, uint8_t datum);
void itm_send_blocking_u16(uint8_t port, uint16_t datum);
void itm_send_blocking_u32(uint8_t port, uint32_t datum);
void itm_send_string(uint8_t port, const char *s);

END_DECLS

/**@}*/

#endif
