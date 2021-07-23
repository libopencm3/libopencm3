/** @defgroup syscfg_defines ICACHE Defines
 *
 * @ingroup STM32L5xx_defines
 *
 * @brief Defined Constants and Types for the STM32L5xx Icache
 *
 * @version 1.0.0
 *
 * @date 23 July 2021
 *
 * LGPL License Terms @ref lgpl_license
 */

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) Nick Downing <nick@ndcode.org>
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

#ifndef LIBOPENCM3_ICACHE_H
#define LIBOPENCM3_ICACHE_H
/**@{*/

/* --- ICACHE registers ---------------------------------------------------- */

#define ICACHE_CR			MMIO32(ICACHE_BASE + 0x00)
#define ICACHE_SR			MMIO32(ICACHE_BASE + 0x04)
#define ICACHE_IER			MMIO32(ICACHE_BASE + 0x08)
#define ICACHE_FCR			MMIO32(ICACHE_BASE + 0x0C)
#define ICACHE_HMONR			MMIO32(ICACHE_BASE + 0x10)
#define ICACHE_MMONR			MMIO32(ICACHE_BASE + 0x14)
#define ICACHE_CRR(i)			MMIO32(ICACHE_BASE + 0x20 + (i)*4)
#define ICACHE_CRR0			ICACHE_CRR(0)
#define ICACHE_CRR1			ICACHE_CRR(1)
#define ICACHE_CRR2			ICACHE_CRR(2)
#define ICACHE_CRR3			ICACHE_CRR(3)

/* --- ICACHE_CR Values ---------------------------------------------------- */

#define ICACHE_CR_MISSMRST		(1 << 19)
#define ICACHE_CR_HITMRST		(1 << 18)
#define ICACHE_CR_MISSMEN		(1 << 17)
#define ICACHE_CR_HITMEN		(1 << 16)
#define ICACHE_CR_WAYSEL		(1 << 2)
#define ICACHE_CR_CACHEINV		(1 << 1)
#define ICACHE_CR_EN			(1 << 0)

/* --- ICACHE_SR Values ---------------------------------------------------- */

#define ICACHE_SR_ERRF			(1 << 2)
#define ICACHE_SR_BSYENDF		(1 << 1)
#define ICACHE_SR_BUSYF			(1 << 0)

/* --- ICACHE_IER Values ----------------------------------------------------*/

#define ICACHE_IER_ERRIE		(1 << 2)
#define ICACHE_IER_BSYENDIE		(1 << 1)

/* --- ICACHE_FCR Values --------------------------------------------------- */

#define ICACHE_FCR_CERRF		(1 << 2)
#define ICACHE_FCR_CBSYENDF		(1 << 1)

/* --- ICACHE_HMONR Values ------------------------------------------------- */

#define ICACHE_HMONR_HITMON_MASK	0xFFFFFFFF

/* --- ICACHE_MMONR Values ------------------------------------------------- */

#define ICACHE_MMONR_MISSMON_MASK	0xFFFF

/* --- ICACHE_CRRx Values -------------------------------------------------- */

#define ICACHE_CRRx_HBURST		(1 << 31)
#define ICACHE_CRRx_MSTSEL		(1 << 28)
#define ICACHE_CRRx_REMAPADDR_MASK	(0x3FF << 16)
#define ICACHE_CRRx_REMAPADDR_SHIFT	16
#define ICACHE_CRRx_REN			(1 << 15)
#define ICACHE_CRRx_RSIZE_MASK		(7 << 8)
#define ICACHE_CRRx_RSIZE_SHIFT		8
#define ICACHE_CRRx_BASEADDR_MASK	(0xFF << 0)
#define ICACHE_CRRx_BASEADDR_SHIFT	0

/**@}*/

BEGIN_DECLS

/** Enable the Instruction Cache */
void icache_enable(void);

/** Disable the Instruction Cache */
void icache_disable(void);

/** Reset the Instruction Cache.
 * The instruction cache must be disabled for this to have effect.
 */
void icache_reset(void);

#endif
