/*
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
 */

#ifndef SAM4L_MEMORYMAP_H
#define SAM4L_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

#define PERIPH_BASE			(0x40000000U)

/* --- SAM4L peripheral bridge A -------------------------------------------- */
#define PERIPH_PBA_BASE			PERIPH_BASE
/* (PERIPH_PBA_BASE + 0x4000) RESERVED */
#define I2SC_BASE			(PERIPH_PBA_BASE + 0x04000)
#define SPI_BASE			(PERIPH_PBA_BASE + 0x08000)
/* (PERIPH_PBA_BASE + 0x0C000) RESERVED */
#define TC0_BASE			(PERIPH_PBA_BASE + 0x10000)
#define TC1_BASE			(PERIPH_PBA_BASE + 0x14000)
#define TWIMS0_BASE			(PERIPH_PBA_BASE + 0x18000)
#define TWIMS1_BASE			(PERIPH_PBA_BASE + 0x1C000)
/* (PERIPH_PBA_BASE + 0x20000) RESERVED */
#define USART0_BASE			(PERIPH_PBA_BASE + 0x24000)
#define USART1_BASE			(PERIPH_PBA_BASE + 0x28000
#define USART2_BASE			(PERIPH_PBA_BASE + 0x2C000)
#define USART3_BASE			(PERIPH_PBA_BASE + 0x30000)
/* (PERIPH_PBA_BASE + 0x34000) RESERVED */
#define ADCIFE_BASE			(PERIPH_PBA_BASE + 0x38000)
#define DACC_BASE			(PERIPH_PBA_BASE + 0x3C000)
#define ACIFC_BASE			(PERIPH_PBA_BASE + 0x40000)
/* (PERIPH_PBA_BASE + 0x44000) to (PERIPH_PBA_BASE + 0x5C000) RESERVED */
#define GLOC_BASE			(PERIPH_PBA_BASE + 0x60000)
#define ABDACB_BASE			(PERIPH_PBA_BASE + 0x64000)
#define TRNG_BASE			(PERIPH_PBA_BASE + 0x68000)
#define PARC_BASE			(PERIPH_PBA_BASE + 0x6C000)
#define CATB_BASE			(PERIPH_PBA_BASE + 0x70000)
/* (PERIPH_PBA_BASE + 0x74000) RESERVED */
#define TWIM2_BASE			(PERIPH_PBA_BASE + 0x78000)
#define TWIM3_BASE			(PERIPH_PBA_BASE + 0x7C000)
#define LCDCA_BASE			(PERIPH_PBA_BASE + 0x80000)

/* --- SAM4L peripheral bridge B -------------------------------------------- */
#define PERIPH_PBB_BASE			(PERIPH_BASE + 0xA0000U)
#define FLASHCALW_BASE			(PERIPH_PBB_BASE)
#define PICOCACHE_BASE			(PERIPH_PBB_BASE + 0x400)
#define HMATRIX_BASE			(PERIPH_PBB_BASE + 0x1000)
#define PDCA_BASE			(PERIPH_PBB_BASE + 0x2000)
#define SMAP_BASE			(PERIPH_PBB_BASE + 0x3000)
#define CRCCU_BASE			(PERIPH_PBB_BASE + 0x4000)
#define USBC_BASE			(PERIPH_PBB_BASE + 0x5000)
#define PEVC_BASE			(PERIPH_PBB_BASE + 0x6000)

/* --------- Advanced Encryption Standard (AESA) ------------- */
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
#define BPM_BASE			(PERIPH_PBD_BASE)
#define BSCIF_BASE			(PERIPH_PBD_BASE + 0x400)
#define AST_BASE			(PERIPH_PBD_BASE + 0x800)
#define WDT_BASE			(PERIPH_PBD_BASE + 0xC00)
#define EIC_BASE			(PERIPH_PBD_BASE + 0x1000)
#define PICOUART_BASE			(PERIPH_PBD_BASE + 0x1400)

#endif
