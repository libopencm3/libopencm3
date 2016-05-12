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
/* (PERIPH_PBA_BASE + 0x4000*0) RESERVED */
#define I2SC_BASE			(PERIPH_PBA_BASE + 0x4000*1)
#define SPI_BASE			(PERIPH_PBA_BASE + 0x4000*2)
/* (PERIPH_PBA_BASE + 0x4000*3) RESERVED */
#define TC0_BASE			(PERIPH_PBA_BASE + 0x4000*4)
#define TC1_BASE			(PERIPH_PBA_BASE + 0x4000*5)
#define TWIMS0_BASE			(PERIPH_PBA_BASE + 0x4000*6)
#define TWIMS1_BASE			(PERIPH_PBA_BASE + 0x4000*7)
/* (PERIPH_PBA_BASE + 0x4000*8) RESERVED */
#define USART0_BASE			(PERIPH_PBA_BASE + 0x4000*9)
#define USART1_BASE			(PERIPH_PBA_BASE + 0x4000*10)
#define USART2_BASE			(PERIPH_PBA_BASE + 0x4000*11)
#define USART3_BASE			(PERIPH_PBA_BASE + 0x4000*12)
/* (PERIPH_PBA_BASE + 0x4000*13) RESERVED */
#define ADCIFE_BASE			(PERIPH_PBA_BASE + 0x4000*14)
#define DACC_BASE			(PERIPH_PBA_BASE + 0x4000*15)
#define ACIFC_BASE			(PERIPH_PBA_BASE + 0x4000*16)
/* (PERIPH_PBA_BASE + 0x4000*17) RESERVED */
#define GLOC_BASE			(PERIPH_PBA_BASE + 0x4000*18)
#define ABDACB_BASE			(PERIPH_PBA_BASE + 0x4000*19)
#define TRNG_BASE			(PERIPH_PBA_BASE + 0x4000*20)
#define PARC_BASE			(PERIPH_PBA_BASE + 0x4000*21)
#define CATB_BASE			(PERIPH_PBA_BASE + 0x4000*22)
/* (PERIPH_PBA_BASE + 0x4000*23) RESERVED */
#define TWIM2_BASE			(PERIPH_PBA_BASE + 0x4000*24)
#define TWIM3_BASE			(PERIPH_PBA_BASE + 0x4000*25)
#define LCDCA_BASE			(PERIPH_PBA_BASE + 0x4000*26)

/* --- SAM4L peripheral bridge B -------------------------------------------- */
#define PERIPH_PBB_BASE			(PERIPH_BASE + 0xA0000U)
#define PICOCACHE_BASE			(PERIPH_PBB_BASE + 0x400)
#define FLASHCALW_BASE			(PERIPH_PBB_BASE + 0x1000*0)
#define HMATRIX_BASE			(PERIPH_PBB_BASE + 0x1000*1)
#define PDCA_BASE			(PERIPH_PBB_BASE + 0x1000*2)
#define SMAP_BASE			(PERIPH_PBB_BASE + 0x1000*3)
#define CRCCU_BASE			(PERIPH_PBB_BASE + 0x1000*4)
#define USBC_BASE			(PERIPH_PBB_BASE + 0x1000*5)
#define PEVC_BASE			(PERIPH_PBB_BASE + 0x1000*6)

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
#define BPM_BASE			(PERIPH_PBD_BASE + 0x400*0)
#define BSCIF_BASE			(PERIPH_PBD_BASE + 0x400*1)
#define AST_BASE			(PERIPH_PBD_BASE + 0x400*2)
#define WDT_BASE			(PERIPH_PBD_BASE + 0x400*3)
#define EIC_BASE			(PERIPH_PBD_BASE + 0x400*4)
#define PICOUART_BASE			(PERIPH_PBD_BASE + 0x400*5)

#endif
