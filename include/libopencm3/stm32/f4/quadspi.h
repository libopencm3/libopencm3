/*
 * STM32F4 Quad SPI defines
 *
 * Copyright (C) 2016, Chuck McManis <cmcmanis@mcmanis.com>
 *
 * This file is part of the libopencm3 project.
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
 *
 */

#include <libopencm3/stm32/memorymap.h>

/* QUADSPI Control register */
#define QUADSPI_CR			MMIO32(QUADSPI_BASE + 0x0U)

#define QUADSPI_CR_PRESCALE_MASK	0xff
#define QUADSPI_CR_PRESCALE_SHIFT	24
#define QUADSPI_CR_PMM			(1 << 23)
#define QUADSPI_CR_APMS			(1 << 22)
/* bit 21 is reserved */
#define QUADSPI_CR_TOIE			(1 << 20)
#define QUADSPI_CR_SMIE			(1 << 19)
#define QUADSPI_CR_FTIE			(1 << 18)
#define QUADSPI_CR_TCIE			(1 << 17)
#define QUADSPI_CR_TEIE			(1 << 16)

/* bits 15:13 reserved */
#define QUADSPI_CR_FTHRES_MASK		0x1f
#define QUADSPI_CR_FTHRES_SHIFT		8
#define QUADSPI_CR_FSEL			(1 << 7)
#define QUADSPI_CR_DFM			(1 << 6)
/* bit 5 reserved */
#define QUADSPI_CR_SSHIFT		(1 << 4)
#define QUADSPI_CR_TCEN			(1 << 3)
#define QUADSPI_CR_DMAEN		(1 << 2)
#define QUADSPI_CR_ABORT		(1 << 1)
#define QUADSPI_CR_EN			(1 << 0)

/* QUADSPI Device Configuration */
#define QUADSPI_DCR			MMIO32(QUADSPI_BASE + 0x4U)

/* bits 31:21 reserved */
#define QUADSPI_DCR_FSIZE_MASK		0x1f
#define QUADSPI_DCR_FSIZE_SHIFT		16
/* bits 15:11 reserved */
#define QUADSPI_DCR_CSHT_MASK		0x7
#define QUADSPI_DCR_CSHT_SHIFT		8
/* bits 7:1 reserved */
#define QUADSPI_DCR_CKMODE		(1 << 0)

/* QUADSPI Status Register */
#define QUADSPI_SR			MMIO32(QUADSPI_BASE + 0x8U)

/* bits 31:14 reserved */
#define QUADSPI_SR_FLEVEL_MASK		0x3f
#define QUADSPI_SR_FLEVEL_SHIFT		8

/* bits 7:6 reserved */
#define QUADSPI_SR_BUSY			(1 << 5)
#define QUADSPI_SR_TOF			(1 << 4)
#define QUADSPI_SR_SMF			(1 << 3)
#define QUADSPI_SR_FTF			(1 << 2)
#define QUADSPI_SR_TCF			(1 << 1)
#define QUADSPI_SR_TEF			(1 << 0)

/* QUADSPI Flag Clear Register */
#define QUADSPI_FCR			MMIO32(QUADSPI_BASE + 0xCU)

/* bits 31:5 reserved */
#define QUADSPI_FCR_CTOF		(1 << 4)
#define QUADSPI_FCR_CSMF		(1 << 3)
/* bit 2 reserved */
#define QUADSPI_FCR_CTCF		(1 << 1)
#define QUADSPI_FCR_CTEF		(1 << 0)

/* QUADSPI Data Length Register */
#define QUADSPI_DLR			MMIO32(QUADSPI_BASE + 0x10U)

/* QUADSPI Communication Configuration Register */
#define QUADSPI_CCR			MMIO32(QUADSPI_BASE + 0x14U)

#define QUADSPI_CCR_DDRM		(1 << 31)
#define QUADSPI_CCR_DHHC		(1 << 30)
/* bit 29 reserved */
#define QUADSPI_CCR_SIOO		(1 << 28)
#define QUADSPI_CCR_FMODE_MASK		0x3
#define QUADSPI_CCR_FMODE_SHIFT		26
#define QUADSPI_CCR_DMODE_MASK		0x3
#define QUADSPI_CCR_DMODE_SHIFT		24
/* bit 23 reserved */
#define	QUADSPI_CCR_DCYC_MASK		0x1f
#define QUADSPI_CCR_DCYC_SHIFT		18

#define QUADSPI_CCR_ABSIZE_MASK		0x3
#define QUADSPI_CCR_ABSIZE_SHIFT	16

#define QUADSPI_CCR_ABMODE_MASK		0x3
#define QUADSPI_CCR_ABMODE_SHIFT	14

#define QUADSPI_CCR_ADSIZE_MASK		0x3
#define QUADSPI_CCR_ADSIZE_SHIFT	12

#define QUADSPI_CCR_ADMODE_MASK		0x3
#define QUADSPI_CCR_ADMODE_SHIFT	10

#define QUADSPI_CCR_IMODE_MASK		0x3
#define QUADSPI_CCR_IMODE_SHIFT		8

#define QUADSPI_CCR_INST_MASK		0xff
#define QUADSPI_CCR_INST_SHIFT		0

/* MODE values */
#define QUADSPI_CCR_MODE_NONE		0
#define QUADSPI_CCR_MODE_1LINE		1
#define QUADSPI_CCR_MODE_2LINE		2
#define QUADSPI_CCR_MODE_4LINE		3

/* FMODE values */
#define QUADSPI_CCR_FMODE_IWRITE	0
#define QUADSPI_CCR_FMODE_IREAD		1
#define QUADSPI_CCR_FMODE_APOLL		2
#define QUADSPI_CCR_FMODE_MEMMAP	3


/* QUADSPI address register */
#define QUADSPI_AR			MMIO32(QUADSPI_BASE + 0x18U)

/* QUADSPI alternate bytes register */
#define QUADSPI_ABR			MMIO32(QUADSPI_BASE + 0x1CU)

/* QUADSPI data register */
#define QUADSPI_DR			MMIO32(QUADSPI_BASE + 0x20U)
/* BYTE addressable version for fetching bytes from the interface */
#define QUADSPI_BYTE_DR			MMIO8(QUADSPI_BASE + 0x20U)

/* QUADSPI polling status */
#define QUADSPI_PSMKR			MMIO32(QUADSPI_BASE + 0x24U)

/* QUADSPI polling status match */
#define QUADSPI_PSMAR			MMIO32(QUADSPI_BASE + 0x28U)

/* QUADSPI polling interval register */
#define QUADSPI_PIR			MMIO32(QUADSPI_BASE + 0x2CU)

/* QUADSPI low power timeout */
#define QUADSPI_LPTR			MMIO32(QUADSPI_BASE + 0x30U)

