/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LIBOPENSTM32_FSMC_H
#define LIBOPENSTM32_FSMC_H

#include <stm32/memorymap.h>
#include <cm3/common.h>

/* --- Convenience macros -------------------------------------------------- */

/* TODO */

/* --- FMSC registers ------------------------------------------------------ */

/* TODO */

/* SRAM/NOR-Flash chip-select control registers 1..4 (FSMC_BCRx) */

/* SRAM/NOR-Flash chip-select timing registers 1..4 (FSMC_BTRx) */

/* SRAM/NOR-Flash write timing registers 1..4 (FSMC_BWTRx) */

/* PC Card/NAND Flash control registers 2..4 (FSMC_PCRx) */

/* FIFO status and interrupt registers 2..4 (FSMC_SRx) */

/* Common memory space timing registers 2..4 (FSMC_PMEMx) */

/* Attribute memory space timing registers 2..4 (FSMC_PATTx) */

/* I/O space timing register 4 (FSMC_PIO4) */

/* ECC result registers 2/3 (FSMC_ECCRx) */

/* --- FSMC_BCRx values ---------------------------------------------------- */

/* CBURSTRW: Write burst enable */
#define FSMC_BCR_CBURSTRW		(1 << 19)

/* Bits 18..16: Reserved. */

/* ASYNCWAIT: Wait signal during asynchronous transfers */
#define FSMC_BCR_ASYNCWAIT		(1 << 15)

/* EXTMOD: Extended mode enable */
#define FSMC_BCR_EXTMOD			(1 << 14)

/* WAITEN: Wait enable bit */
#define FSMC_BCR_WAITEN			(1 << 13)

/* WREN: Write enable bit */
#define FSMC_BCR_WREN			(1 << 12)

/* WAITCFG: Wait timing configuration */
#define FSMC_BCR_WAITCFG		(1 << 11)

/* WRAPMOD: Wrapped burst mode support */
#define FSMC_BCR_WRAPMOD		(1 << 10)

/* WAITPOL: Wait signal polarity bit */
#define FSMC_BCR_WAITPOL		(1 << 9)

/* BURSTEN: Burst enable bit */
#define FSMC_BCR_BURSTEN		(1 << 8)

/* Bit 7: Reserved. */

/* FACCEN: Flash access enable */
#define FSMC_BCR_FACCEN			(1 << 6)

/* MWID[5:4]: Memory databus width */
#define FSMC_BCR_MWID			(1 << 4)

/* MTYP[3:2]: Memory type */
#define FSMC_BCR_MTYP			(1 << 2)

/* MUXEN: Address/data multiplexing enable bit */
#define FSMC_BCR_MUXEN			(1 << 1)

/* MBKEN: Memory bank enable bit */
#define FSMC_BCR_MBKEN			(1 << 0)

#endif
