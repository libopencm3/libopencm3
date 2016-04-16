m4_divert(-1)
m4_dnl Single memory address, defined via
m4_dnl name, base, offset
m4_define(`MEM_NAME', `m4_ifelse(`$1', `RESERVED', `/* ($2 + $3) RESERVED */',
``#'define $1_BASE			($2 + $3)')')
m4_dnl Memory Region: base, step_size, step_num, memory elements
m4_define(`MEM_REGION_HELPER',
	`m4_ifelse(`$#', `4', `MEM_NAME($4, $1, `$2*$3')',
`MEM_NAME($4, $1, $2*$3)
MEM_REGION_HELPER($1, $2, m4_incr($3), m4_shift(m4_shift(m4_shift(m4_shift($@)))))')')
m4_define(`MEM_REGION', `MEM_REGION_HELPER($1, $2, 0, m4_shift(m4_shift($@)))')
m4_divert(0)m4_dnl
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Maxim Sloyko <maxim@sloyko.com>
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

#ifndef SAM4L_MEMORYMAP_H
#define SAM4L_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

#define PERIPH_BASE			(0x40000000U)

/* --- SAM4L peripheral bridge A -------------------------------------------- */
#define PERIPH_PBA_BASE			PERIPH_BASE
MEM_REGION(PERIPH_PBA_BASE, 0x4000,
		RESERVED,
		I2SC,
		SPI,
		RESERVED,
		TC0, TC1,
		TWIMS0, TWIMS1,
		RESERVED,
		USART0, USART1, USART2, USART3,
		RESERVED,
		ADCIFE,
		DACC,
		ACIFC,
		RESERVED,
		GLOC,
		ABDACB,
		TRNG,
		PARC,
		CATB,
		RESERVED,
		TWIM2, TWIM3,
		LCDCA)

/* --- SAM4L peripheral bridge B -------------------------------------------- */
#define PERIPH_PBB_BASE			(PERIPH_BASE + 0xA0000U)
#define PICOCACHE_BASE			(PERIPH_PBB_BASE + 0x400)
MEM_REGION(PERIPH_PBB_BASE, 0x1000,
		FLASHCALW,
		HMATRIX,
		PDCA,
		SMAP,
		CRCCU,
		USBC,
		PEVC)

/* --------- AESA ------------- */
#define AESA_BASE			(PERIPH_BASE + 0xB0000)

/* --- SAM4L peripheral bridge C -------------------------------------------- */
#define PERIPH_PBC_BASE			(PERIPH_BASE + 0xE0000)
#define PM_BASE			(PERIPH_PBC_BASE)
#define CHIPID_BASE			(PERIPH_PBC_BASE + 0x740)
#define SCIF_BASE			(PERIPH_PBC_BASE + 0x800)
#define FREQM_BASE			(PERIPH_PBC_BASE + 0xC00)
#define GPIO_BASE			(PERIPH_PBC_BASE + 0x1000)

/* --- SAM4L peripheral bridge D -------------------------------------------- */
#define PERIPH_PBD_BASE			(PERIPH_BASE + 0xF0000U)
MEM_REGION(PERIPH_PBD_BASE, 0x400,
		BPM,
		BSCIF,
		AST,
		WDT,
		EIC,
		PICOUART)

#endif
