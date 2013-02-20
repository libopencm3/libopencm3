/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 ARCOS-Lab UCR <arcoslab.org> 
 * Copyright (C) 2012 Fernando Cortes <fernando.corcam@gmail.com>
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


#ifndef LIBOPENCM3_TSC_H
#define LIBOPENCM3_TSC_H

#include <libopencm3/stm32/memorymap.h>

/* --- TSC registers ------------------------------------------------------ */

#define TSC_CR		MMIO32(TSC_BASE + 0x0000)
#define TSC_IER		MMIO32(TSC_BASE + 0x0004)
#define TSC_ICR		MMIO32(TSC_BASE + 0x0008)
#define TSC_ISR		MMIO32(TSC_BASE + 0x000C)
#define TSC_IOHCR	MMIO32(TSC_BASE + 0x0010)
#define TSC_IOASCR	MMIO32(TSC_BASE + 0x0018)
#define TSC_IOSCR	MMIO32(TSC_BASE + 0x0020)
#define TSC_IOCCR	MMIO32(TSC_BASE + 0x0028)
#define TSC_IOGCSR	MMIO32(TSC_BASE + 0x0030)
#define TSC_IOG1CR	MMIO32(TSC_BASE + 0x0034)
#define TSC_IOG2CR	MMIO32(TSC_BASE + 0x0038)
#define TSC_IOG3CR	MMIO32(TSC_BASE + 0x003C)
#define TSC_IOG4CR	MMIO32(TSC_BASE + 0x0040)
#define TSC_IOG5CR	MMIO32(TSC_BASE + 0x0044)
#define TSC_IOG6CR	MMIO32(TSC_BASE + 0x0048)
#define TSC_IOG7CR	MMIO32(TSC_BASE + 0x004C)
#define TSC_IOG8CR	MMIO32(TSC_BASE + 0x0050)


/*------ TSC control register (TSC_CR) values ------*/

/* CTPH[3:0]: Charge transfer pulse high */
#define TSC_CR_CTPH_1_MUL_TPGCLK	(0x0 << 28)
#define TSC_CR_CTPH_2_MUL_TPGCLK	(0x1 << 28)
#define TSC_CR_CTPH_3_MUL_TPGCLK	(0x2 << 28)
#define TSC_CR_CTPH_4_MUL_TPGCLK	(0x3 << 28)
#define TSC_CR_CTPH_5_MUL_TPGCLK	(0x4 << 28)
#define TSC_CR_CTPH_6_MUL_TPGCLK	(0x5 << 28)
#define TSC_CR_CTPH_7_MUL_TPGCLK	(0x6 << 28)
#define TSC_CR_CTPH_8_MUL_TPGCLK	(0x7 << 28)
#define TSC_CR_CTPH_9_MUL_TPGCLK	(0x8 << 28)
#define TSC_CR_CTPH_10_MUL_TPGCLK	(0x9 << 28)
#define TSC_CR_CTPH_11_MUL_TPGCLK	(0xA << 28)
#define TSC_CR_CTPH_12_MUL_TPGCLK	(0xB << 28)
#define TSC_CR_CTPH_13_MUL_TPGCLK	(0xC << 28)
#define TSC_CR_CTPH_14_MUL_TPGCLK	(0xD << 28)
#define TSC_CR_CTPH_15_MUL_TPGCLK	(0xE << 28)
#define TSC_CR_CTPH_16_MUL_TPGCLK	(0xF << 28)

/* CTPL[3:0]: Charge transfer pulse low */
#define TSC_CR_CTPL_1_MUL_TPGCLK	(0x0 << 24)
#define TSC_CR_CTPL_2_MUL_TPGCLK	(0x1 << 24)
#define TSC_CR_CTPL_3_MUL_TPGCLK	(0x2 << 24)
#define TSC_CR_CTPL_4_MUL_TPGCLK	(0x3 << 24)
#define TSC_CR_CTPL_5_MUL_TPGCLK	(0x4 << 24)
#define TSC_CR_CTPL_6_MUL_TPGCLK	(0x5 << 24)
#define TSC_CR_CTPL_7_MUL_TPGCLK	(0x6 << 24)
#define TSC_CR_CTPL_8_MUL_TPGCLK	(0x7 << 24)
#define TSC_CR_CTPL_9_MUL_TPGCLK	(0x8 << 24)
#define TSC_CR_CTPL_10_MUL_TPGCLK	(0x9 << 24)
#define TSC_CR_CTPL_11_MUL_TPGCLK	(0xA << 24)
#define TSC_CR_CTPL_12_MUL_TPGCLK	(0xB << 24)
#define TSC_CR_CTPL_13_MUL_TPGCLK	(0xC << 24)
#define TSC_CR_CTPL_14_MUL_TPGCLK	(0xD << 24)
#define TSC_CR_CTPL_15_MUL_TPGCLK	(0xE << 24)
#define TSC_CR_CTPL_16_MUL_TPGCLK	(0xF << 24)

/* Bits 23:17 SSD[6:0]: Spread spectrum deviation */


/* SSE: Spread spectrum enable */
#define TSC_CR_SSE		(1 << 16)

/* SSPSC: Spread spectrum prescaler */
#define TSC_CR_SSPSC		(1 << 15)

/* PGPSC[2:0]: pulse generator prescaler */
#define TSC_CR_PGPSC_FHCLK		(0x0 << 12)
#define TSC_CR_PGPSC_FHCLK_DIV_2	(0x1 << 12)
#define TSC_CR_PGPSC_FHCLK_DIV_4	(0x2 << 12)
#define TSC_CR_PGPSC_FHCLK_DIV_8	(0x3 << 12)
#define TSC_CR_PGPSC_FHCLK_DIV_16	(0x4 << 12)
#define TSC_CR_PGPSC_FHCLK_DIV_32	(0x5 << 12)
#define TSC_CR_PGPSC_FHCLK_DIV_64	(0x6 << 12)
#define TSC_CR_PGPSC_FHCLK_DIV_128	(0x7 << 12)

/* MCV[2:0]: Max count value */
#define TSC_CR_PGPSC_MCV_255		(0x0 << 5)
#define TSC_CR_PGPSC_MCV_511		(0x1 << 5)
#define TSC_CR_PGPSC_MCV_1023		(0x2 << 5)
#define TSC_CR_PGPSC_MCV_2047		(0x3 << 5)
#define TSC_CR_PGPSC_MCV_4095		(0x4 << 5)
#define TSC_CR_PGPSC_MCV_8191		(0x5 << 5)
#define TSC_CR_PGPSC_MCV_16383		(0x6 << 5)
/* MCV 111 reserved */


/* IODEF: I/O Default mode */
#define TSC_CR_IODEF		(1 << 4)

/* SYNCPOL: Synchronization pin polarity */
#define TSC_CR_SYNCPOL		(1 << 3)

/* AM: Acquisition mode */
#define TSC_CR_AM		(1 << 2)

/* START: Start a new acquisition */
#define TSC_CR_START		(1 << 1)

/* TSCE: Touch sensing controller enable */
#define TSC_CR_TSCE		(1 << 0)


/*------ TSC interrupt enable register (TSC_IER) values ------*/

/* MCEIE: Max count error interrupt enable */
#define TSC_IER_MCEIE		(1 << 1)

/* EOAIE: End of acquisition interrupt enable */
#define TSC_IER_EOAIE		(1 << 0)


/*------ TSC interrupt clear register (TSC_ICR) values ------*/

/* MCEIC: Max count error interrupt clear */
#define TSC_ICR_MCEIC		(1 << 1)

/* EOAIC: End of acquisition interrupt clear */
#define TSC_ICR_EOAIC		(1 << 0)


/*------ TSC interrupt status register (TSC_ISR) values ------*/

/* MCEF: Max count error flag */
#define TSC_ISR_MCEF		(1 << 1)

/* EOAF: End of acquisition flag */
#define TSC_ISR_EOAF		(1 << 0)


/*------ TSC I/O hysteresis control register (TSC_IOHCR) values ------*/

/* Bits 31:0 Gx_IOy: Gx_IOy Schmitt trigger hysteresis mode */


/*------ TSC I/O analog switch control register (TSC_IOASCR) values ------*/

/* Bits 31:0 Gx_IOy: Gx_IOy analog switch enable */


/*------ TSC I/O sampling control register (TSC_IOSCR) values ------*/

/* Bits 31:0 Gx_IOy: Gx_IOy sampling mode */


/*------ TSC I/O channel control register (TSC_IOCCR) values ------*/

/* Bits 31:0 Gx_IOy: Gx_IOy channel mode */


/*------ TSC I/O group control status register (TSC_IOGCSR) values ------*/

/* Bits 23:16 GxS: Analog I/O group x status */
/* Bits 7:0 GxE: Analog I/O group x enable */


/*------ TSC I/O group x counter register (TSC_IOGxCR) (x=1..8) values ------*/

/* Bits 13:0 CNT[13:0]: Counter value */


#endif

