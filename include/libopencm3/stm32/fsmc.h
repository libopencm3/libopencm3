/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
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

#ifndef LIBOPENCM3_FSMC_H
#define LIBOPENCM3_FSMC_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>

#if   defined(STM32F4)
#       include <libopencm3/stm32/f4/fmc.h>
#elif defined(STM32F7)
#       include <libopencm3/stm32/f7/fmc.h>
#elif defined(STM32H7)
#       include <libopencm3/stm32/h7/fmc.h>
#endif

/* --- Convenience macros -------------------------------------------------- */
#define FSMC_BANK1_BASE			0x60000000U /* NOR / PSRAM */
#define FSMC_BANK2_BASE			0x70000000U /* NAND flash (reserved in F7) */
#define FSMC_BANK3_BASE			0x80000000U /* NAND flash */
#define FSMC_BANK4_BASE			0x90000000U /* PC card (reserved in F7) */

/* --- FSMC registers ------------------------------------------------------ */

/* SRAM/NOR-Flash chip-select control registers 1..4 (FSMC_BCRx) */
#define FSMC_BCR(x)			MMIO32(FSMC_BASE + 0x00 + 8 * (x))
#define FSMC_BCR1			FSMC_BCR(0)
#define FSMC_BCR2			FSMC_BCR(1)
#define FSMC_BCR3			FSMC_BCR(2)
#define FSMC_BCR4			FSMC_BCR(3)

/* SRAM/NOR-Flash chip-select timing registers 1..4 (FSMC_BTRx) */
#define FSMC_BTR(x)			MMIO32(FSMC_BASE + 0x04 + 8 * (x))
#define FSMC_BTR1			FSMC_BTR(0)
#define FSMC_BTR2			FSMC_BTR(1)
#define FSMC_BTR3			FSMC_BTR(2)
#define FSMC_BTR4			FSMC_BTR(3)

/* SRAM/NOR-Flash write timing registers 1..4 (FSMC_BWTRx) */
#define FSMC_BWTR(x)			MMIO32(FSMC_BASE + 0x104 + 8 * (x))
#define FSMC_BWTR1			FSMC_BWTR(0)
#define FSMC_BWTR2			FSMC_BWTR(1)
#define FSMC_BWTR3			FSMC_BWTR(2)
#define FSMC_BWTR4			FSMC_BWTR(3)

/* PC Card/NAND Flash control registers 2..4 (FSMC_PCRx) */
#define FSMC_PCR(x)			MMIO32(FSMC_BASE + 0x40 + 0x20 * (x))
#define FSMC_PCR2			FSMC_PCR(1)
#define FSMC_PCR3			FSMC_PCR(2)
#define FSMC_PCR4			FSMC_PCR(3)

/* FIFO status and interrupt registers 2..4 (FSMC_SRx) */
#define FSMC_SR(x)			MMIO32(FSMC_BASE + 0x44 + 0x20 * (x))
#define FSMC_SR2			FSMC_SR(1)
#define FSMC_SR3			FSMC_SR(2)
#define FSMC_SR4			FSMC_SR(3)

/* Common memory space timing registers 2..4 (FSMC_PMEMx) */
#define FSMC_PMEM(x)			MMIO32(FSMC_BASE + 0x48 + 0x20 * (x))
#define FSMC_PMEM2			FSMC_PMEM(1)
#define FSMC_PMEM3			FSMC_PMEM(2)
#define FSMC_PMEM4			FSMC_PMEM(3)

/* Attribute memory space timing registers 2..4 (FSMC_PATTx) */
#define FSMC_PATT(x)			MMIO32(FSMC_BASE + 0x4c + 0x20 * (x))
#define FSMC_PATT2			FSMC_PATT(1)
#define FSMC_PATT3			FSMC_PATT(2)
#define FSMC_PATT4			FSMC_PATT(3)

/* I/O space timing register 4 (FSMC_PIO4) */
#define FSMC_PIO4			MMIO32(FSMC_BASE + 0xb0)

/* ECC result registers 2/3 (FSMC_ECCRx) */
#define FSMC_ECCR(x)			MMIO32(FSMC_BASE + 0x54 + 0x20 * (x))
#define FSMC_ECCR2			FSMC_ECCR(1)
#define FSMC_ECCR3			FSMC_ECCR(2)

/* --- FSMC_BCRx values ---------------------------------------------------- */

/* Bits [31:20]: Reserved. */

/* CBURSTRW: Write burst enable */
#define FSMC_BCR_CBURSTRW		(1 << 19)

/* Bits [18:16]: Reserved. */

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

/* MWID[5:4]: Memory data bus width */
#define FSMC_BCR_MWID			(1 << 4)

/* MTYP[3:2]: Memory type */
#define FSMC_BCR_MTYP			(1 << 2)

/* MUXEN: Address/data multiplexing enable bit */
#define FSMC_BCR_MUXEN			(1 << 1)

/* MBKEN: Memory bank enable bit */
#define FSMC_BCR_MBKEN			(1 << 0)

/* --- FSMC_BTRx values ---------------------------------------------------- */

/* Bits [31:30]: Reserved. */

/* Same for read and write */
#define FSMC_BTx_ACCMOD_A		(0)
#define FSMC_BTx_ACCMOD_B		(1)
#define FSMC_BTx_ACCMOD_C		(2)
#define FSMC_BTx_ACCMOD_D		(3)

/* ACCMOD[29:28]: Access mode */
#define FSMC_BTR_ACCMOD			(1 << 28)
#define FSMC_BTR_ACCMODx(x)		(((x) & 0x03) << 28)

/* DATLAT[27:24]: Data latency (for synchronous burst NOR flash) */
#define FSMC_BTR_DATLAT			(1 << 24)
#define FSMC_BTR_DATLATx(x)		(((x) & 0x0f) << 24)

/* CLKDIV[23:20]: Clock divide ratio (for CLK signal) */
#define FSMC_BTR_CLKDIV			(1 << 20)
#define FSMC_BTR_CLKDIVx(x)		(((x) & 0x0f) << 20)

/* BUSTURN[19:16]: Bus turnaround phase duration */
#define FSMC_BTR_BUSTURN		(1 << 16)
#define FSMC_BTR_BUSTURNx(x)		(((x) & 0x0f) << 16)

/* DATAST[15:8]: Data-phase duration */
#define FSMC_BTR_DATAST			(1 << 8)
#define FSMC_BTR_DATASTx(x)		(((x) & 0xff) << 8)

/* ADDHLD[7:4]: Address-hold phase duration */
#define FSMC_BTR_ADDHLD			(1 << 4)
#define FSMC_BTR_ADDHLDx(x)		(((x) & 0x0f) << 4)

/* ADDSET[3:0]: Address setup phase duration */
#define FSMC_BTR_ADDSET			(1 << 0)
#define FSMC_BTR_ADDSETx(x)		(((x) & 0x0f) << 0)

/* --- FSMC_BWTRx values --------------------------------------------------- */

/* Bits [31:30]: Reserved. */

/* ACCMOD[29:28]: Access mode */
#define FSMC_BWTR_ACCMOD		(1 << 28)

/* DATLAT[27:24]: Data latency (for synchronous burst NOR Flash) */
#define FSMC_BWTR_DATLAT		(1 << 24)

/* CLKDIV[23:20]: Clock divide ratio (for CLK signal) */
#define FSMC_BWTR_CLKDIV		(1 << 20)

/* Bits [19..16]: Reserved. */

/* DATAST[15:8]: Data-phase duration */
#define FSMC_BWTR_DATAST		(1 << 8)

/* ADDHLD[7:4]: Address-hold phase duration */
#define FSMC_BWTR_ADDHLD		(1 << 4)

/* ADDSET[3:0]: Address setup phase duration */
#define FSMC_BWTR_ADDSET		(1 << 0)

/* --- FSMC_PCRx values ---------------------------------------------------- */

/* Bits [31:20]: Reserved. */

/* ECCPS[19:17]: ECC page size */
#define FSMC_PCR_ECCPS			(1 << 17)

/* TAR[16:13]: ALE to RE delay */
#define FSMC_PCR_TAR			(1 << 13)

/* TCLR[12:9]: CLE to RE delay */
#define FSMC_PCR_TCLR			(1 << 9)

/* Bits [8..7]: Reserved. */

/* ECCEN: ECC computation logic enable bit */
#define FSMC_PCR_ECCEN			(1 << 6)

/* PWID[5:4]: Databus width */
#define FSMC_PCR_PWID			(1 << 4)

/* PTYP: Memory type */
#define FSMC_PCR_PTYP			(1 << 3)

/* PBKEN: PC Card/NAND Flash memory bank enable bit */
#define FSMC_PCR_PBKEN			(1 << 2)

/* PWAITEN: Wait feature enable bit */
#define FSMC_PCR_PWAITEN		(1 << 1)

/* Bit 0: Reserved. */

/* --- FSMC_SRx values ----------------------------------------------------- */

/* Bits [31:7]: Reserved. */

/* FEMPT: FIFO empty */
#define FSMC_SR_FEMPT			(1 << 6)

/* IFEN: Interrupt falling edge detection enable bit */
#define FSMC_SR_IFEN			(1 << 5)

/* ILEN: Interrupt high-level detection enable bit */
#define FSMC_SR_ILEN			(1 << 4)

/* IREN: Interrupt rising edge detection enable bit */
#define FSMC_SR_IREN			(1 << 3)

/* IFS: Interrupt falling edge status */
#define FSMC_SR_IFS			(1 << 2)

/* ILS: Interrupt high-level status */
#define FSMC_SR_ILS			(1 << 1)

/* IRS: Interrupt rising edge status */
#define FSMC_SR_IRS			(1 << 0)

/* --- FSMC_PMEMx values --------------------------------------------------- */

/* MEMHIZx[31:24]: Common memory x databus HiZ time */
#define FSMC_PMEM_MEMHIZX		(1 << 24)

/* MEMHOLDx[23:16]: Common memory x hold time */
#define FSMC_PMEM_MEMHOLDX		(1 << 16)

/* MEMWAITx[15:8]: Common memory x wait time */
#define FSMC_PMEM_MEMWAITX		(1 << 8)

/* MEMSETx[7:0]: Common memory x setup time */
#define FSMC_PMEM_MEMSETX		(1 << 0)

/* --- FSMC_PATTx values --------------------------------------------------- */

/* ATTHIZx[31:24]: Attribute memory x databus HiZ time */
#define FSMC_PATT_ATTHIZX		(1 << 24)

/* ATTHOLDx[23:16]: Attribute memory x hold time */
#define FSMC_PATT_ATTHOLDX		(1 << 16)

/* ATTWAITx[15:8]: Attribute memory x wait time */
#define FSMC_PATT_ATTWAITX		(1 << 8)

/* ATTSETx[7:0]: Attribute memory x setup time */
#define FSMC_PATT_ATTSETX		(1 << 0)

/* --- FSMC_PIO4 values ---------------------------------------------------- */

/* IOHIZx[31:24]: I/O x databus HiZ time */
#define FSMC_PIO4_IOHIZX		(1 << 24)

/* IOHOLDx[23:16]: I/O x hold time */
#define FSMC_PIO4_IOHOLDX		(1 << 16)

/* IOWAITx[15:8]: I/O x wait time */
#define FSMC_PIO4_IOWAITX		(1 << 8)

/* IOSETx[7:0]: I/O x setup time */
#define FSMC_PIO4_IOSETX		(1 << 0)

/* --- FSMC_ECCRx values --------------------------------------------------- */

/* ECCx[31:0]: ECC result */
#define FSMC_ECCR_ECCX			(1 << 0)

#endif
