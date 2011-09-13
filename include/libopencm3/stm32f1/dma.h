/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#ifndef LIBOPENCM3_DMA_H
#define LIBOPENCM3_DMA_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Convenience macros -------------------------------------------------- */

/* DMA register base adresses (for convenience) */
#define DMA1                            DMA1_BASE
#define DMA2                            DMA2_BASE

/* --- DMA registers ------------------------------------------------------- */

/* DMA interrupt status register (DMAx_ISR) */
#define DMA_ISR(dma_base)               MMIO32(dma_base + 0x00)
#define DMA1_ISR                        DMA_ISR(DMA1)
#define DMA2_ISR                        DMA_ISR(DMA2)

/* DMA interrupt flag clear register (DMAx_IFCR) */
#define DMA_IFCR(dma_base)              MMIO32(dma_base + 0x04)
#define DMA1_IFCR                       DMA_IFCR(DMA1)
#define DMA2_IFCR                       DMA_IFCR(DMA2)

/* DMA channel 1 configuration register (DMAx_CCR1) */
#define DMA_CCR1(dma_base)              MMIO32(dma_base + 0x08 + 0x14 * 0)
#define DMA1_CCR1                       DMA_CCR1(DMA1)
#define DMA2_CCR1                       DMA_CCR1(DMA2)

/* DMA channel 2 configuration register (DMAx_CCR2) */
#define DMA_CCR2(dma_base)              MMIO32(dma_base + 0x08 + 0x14 * 1)
#define DMA1_CCR2                       DMA_CCR2(DMA1)
#define DMA2_CCR2                       DMA_CCR2(DMA2)

/* DMA channel 3 configuration register (DMAx_CCR3) */
#define DMA_CCR3(dma_base)              MMIO32(dma_base + 0x08 + 0x14 * 2)
#define DMA1_CCR3                       DMA_CCR3(DMA1)
#define DMA2_CCR3                       DMA_CCR3(DMA2)

/* DMA channel 4 configuration register (DMAx_CCR4) */
#define DMA_CCR4(dma_base)              MMIO32(dma_base + 0x08 + 0x14 * 3)
#define DMA1_CCR4                       DMA_CCR4(DMA1)
#define DMA2_CCR4                       DMA_CCR4(DMA2)

/* DMA channel 5 configuration register (DMAx_CCR5) */
#define DMA_CCR5(dma_base)              MMIO32(dma_base + 0x08 + 0x14 * 4)
#define DMA1_CCR5                       DMA_CCR5(DMA1)
#define DMA2_CCR5                       DMA_CCR5(DMA2)

/* DMA channel 6 configuration register (DMAx_CCR6) */
#define DMA_CCR6(dma_base)              MMIO32(dma_base + 0x08 + 0x14 * 5)
#define DMA1_CCR6                       DMA_CCR6(DMA1)

/* DMA channel 7 configuration register (DMAx_CCR7) */
#define DMA_CCR7(dma_base)              MMIO32(dma_base + 0x08 + 0x14 * 6)
#define DMA1_CCR7                       DMA_CCR7(DMA1)

/* DMA channel 1 number of data register (DMAx_CNDTR1) */
#define DMA_CNDTR1(dma_base)            MMIO32(dma_base + 0x0C + 0x14 * 0)
#define DMA1_CNDTR1                     DMA_CNDTR1(DMA1)
#define DMA2_CNDTR1                     DMA_CNDTR1(DMA2)

/* DMA channel 2 number of data register (DMAx_CNDTR2) */
#define DMA_CNDTR2(dma_base)            MMIO32(dma_base + 0x0C + 0x14 * 1)
#define DMA1_CNDTR2                     DMA_CNDTR2(DMA1)
#define DMA2_CNDTR2                     DMA_CNDTR2(DMA2)

/* DMA channel 3 number of data register (DMAx_CNDTR3) */
#define DMA_CNDTR3(dma_base)            MMIO32(dma_base + 0x0C + 0x14 * 2)
#define DMA1_CNDTR3                     DMA_CNDTR3(DMA1)
#define DMA2_CNDTR3                     DMA_CNDTR3(DMA2)

/* DMA channel 4 number of data register (DMAx_CNDTR4) */
#define DMA_CNDTR4(dma_base)            MMIO32(dma_base + 0x0C + 0x14 * 3)
#define DMA1_CNDTR4                     DMA_CNDTR4(DMA1)
#define DMA2_CNDTR4                     DMA_CNDTR4(DMA2)

/* DMA channel 5 number of data register (DMAx_CNDTR5) */
#define DMA_CNDTR5(dma_base)            MMIO32(dma_base + 0x0C + 0x14 * 4)
#define DMA1_CNDTR5                     DMA_CNDTR5(DMA1)
#define DMA2_CNDTR5                     DMA_CNDTR5(DMA2)

/* DMA channel 6 number of data register (DMAx_CNDTR6) */
#define DMA_CNDTR6(dma_base)            MMIO32(dma_base + 0x0C + 0x14 * 5)
#define DMA1_CNDTR6                     DMA_CNDTR6(DMA1)

/* DMA channel 7 number of data register (DMAx_CNDTR7) */
#define DMA_CNDTR7(dma_base)            MMIO32(dma_base + 0x0C + 0x14 * 6)
#define DMA1_CNDTR7                     DMA_CNDTR7(DMA1)

/* DMA channel 1 peripheral address register (DMAx_CPAR1) */
#define DMA_CPAR1(dma_base)             MMIO32(dma_base + 0x10 + 0x14 * 0)
#define DMA1_CPAR1                      DMA_CPAR1(DMA1)
#define DMA2_CPAR1                      DMA_CPAR1(DMA2)

/* DMA channel 2 peripheral address register (DMAx_CPAR2) */
#define DMA_CPAR2(dma_base)             MMIO32(dma_base + 0x10 + 0x14 * 1)
#define DMA1_CPAR2                      DMA_CPAR2(DMA1)
#define DMA2_CPAR2                      DMA_CPAR2(DMA2)

/* DMA channel 3 peripheral address register (DMAx_CPAR3) */
#define DMA_CPAR3(dma_base)             MMIO32(dma_base + 0x10 + 0x14 * 2)
#define DMA1_CPAR3                      DMA_CPAR3(DMA1)
#define DMA2_CPAR3                      DMA_CPAR3(DMA2)

/* DMA channel 4 peripheral address register (DMAx_CPAR4) */
#define DMA_CPAR4(dma_base)             MMIO32(dma_base + 0x10 + 0x14 * 3)
#define DMA1_CPAR4                      DMA_CPAR4(DMA1)
#define DMA2_CPAR4                      DMA_CPAR4(DMA2)

/* DMA channel 5 peripheral address register (DMAx_CPAR5) */
#define DMA_CPAR5(dma_base)             MMIO32(dma_base + 0x10 + 0x14 * 4)
#define DMA1_CPAR5                      DMA_CPAR5(DMA1)
#define DMA2_CPAR5                      DMA_CPAR5(DMA2)

/* DMA channel 6 peripheral address register (DMAx_CPAR6) */
#define DMA_CPAR6(dma_base)             MMIO32(dma_base + 0x10 + 0x14 * 5)
#define DMA1_CPAR6                      DMA_CPAR6(DMA1)

/* DMA channel 7 peripheral address register (DMAx_CPAR7) */
#define DMA_CPAR7(dma_base)             MMIO32(dma_base + 0x10 + 0x14 * 6)
#define DMA1_CPAR7                      DMA_CPAR7(DMA1)

/* DMA channel 1 memory address register (DMAx_CMAR1) */
#define DMA_CMAR1(dma_base)             MMIO32(dma_base + 0x14 + 0x14 * 0)
#define DMA1_CMAR1                      DMA_CMAR1(DMA1)
#define DMA2_CMAR1                      DMA_CMAR1(DMA2)

/* DMA channel 2 memory address register (DMAx_CMAR2) */
#define DMA_CMAR2(dma_base)             MMIO32(dma_base + 0x14 + 0x14 * 1)
#define DMA1_CMAR2                      DMA_CMAR2(DMA1)
#define DMA2_CMAR2                      DMA_CMAR2(DMA2)

/* DMA channel 3 memory address register (DMAx_CMAR3) */
#define DMA_CMAR3(dma_base)             MMIO32(dma_base + 0x14 + 0x14 * 2)
#define DMA1_CMAR3                      DMA_CMAR3(DMA1)
#define DMA2_CMAR3                      DMA_CMAR3(DMA2)

/* DMA channel 4 memory address register (DMAx_CMAR4) */
#define DMA_CMAR4(dma_base)             MMIO32(dma_base + 0x14 + 0x14 * 3)
#define DMA1_CMAR4                      DMA_CMAR4(DMA1)
#define DMA2_CMAR4                      DMA_CMAR4(DMA2)

/* DMA channel 5 memory address register (DMAx_CMAR5) */
#define DMA_CMAR5(dma_base)             MMIO32(dma_base + 0x14 + 0x14 * 4)
#define DMA1_CMAR5                      DMA_CMAR5(DMA1)
#define DMA2_CMAR5                      DMA_CMAR5(DMA2)

/* DMA channel 6 memory address register (DMAx_CMAR6) */
#define DMA_CMAR6(dma_base)             MMIO32(dma_base + 0x14 + 0x14 * 5)
#define DMA1_CMAR6                      DMA_CMAR6(DMA1)

/* DMA channel 7 memory address register (DMAx_CMAR7) */
#define DMA_CMAR7(dma_base)             MMIO32(dma_base + 0x14 + 0x14 * 6)
#define DMA1_CMAR7                      DMA_CMAR7(DMA1)

/* --- DMA_ISR values ------------------------------------------------------ */

/* TEIF7: Channel 7 transfer error flag */
#define DMA_ISR_TEIF7			(1 << 27)
/* HTIF7: Channel 7 half transfer flag */
#define DMA_ISR_HTIF7			(1 << 26)
/* TCIF7: Channel 7 transfer complete flag */
#define DMA_ISR_TCIF7			(1 << 25)
/* GIF7: Channel 7 global interrupt flag */
#define DMA_ISR_GIF7			(1 << 24)
/* TEIF6: Channel 6 transfer error flag */
#define DMA_ISR_TEIF6			(1 << 23)
/* HTIF6: Channel 6 half transfer flag */
#define DMA_ISR_HTIF6			(1 << 22)
/* TCIF6: Channel 6 transfer complete flag */
#define DMA_ISR_TCIF6			(1 << 21)
/* GIF6: Channel 6 global interrupt flag */
#define DMA_ISR_GIF6			(1 << 20)
/* TEIF5: Channel 5 transfer error flag */
#define DMA_ISR_TEIF5			(1 << 19)
/* HTIF5: Channel 5 half transfer flag */
#define DMA_ISR_HTIF5			(1 << 18)
/* TCIF5: Channel 5 transfer complete flag */
#define DMA_ISR_TCIF5			(1 << 17)
/* GIF5: Channel 5 global interrupt flag */
#define DMA_ISR_GIF5			(1 << 16)
/* TEIF4: Channel 4 transfer error flag */
#define DMA_ISR_TEIF4			(1 << 15)
/* HTIF4: Channel 4 half transfer flag */
#define DMA_ISR_HTIF4			(1 << 14)
/* TCIF4: Channel 4 transfer complete flag */
#define DMA_ISR_TCIF4			(1 << 13)
/* GIF4: Channel 4 global interrupt flag */
#define DMA_ISR_GIF4			(1 << 12)
/* TEIF3: Channel 3 transfer error flag */
#define DMA_ISR_TEIF3			(1 << 11)
/* HTIF3: Channel 3 half transfer flag */
#define DMA_ISR_HTIF3			(1 << 10)
/* TCIF3: Channel 3 transfer complete flag */
#define DMA_ISR_TCIF3			(1 << 9)
/* GIF3: Channel 3 global interrupt flag */
#define DMA_ISR_GIF3			(1 << 8)
/* TEIF2: Channel 2 transfer error flag */
#define DMA_ISR_TEIF2			(1 << 7)
/* HTIF2: Channel 23 half transfer flag */
#define DMA_ISR_HTIF2			(1 << 6)
/* TCIF2: Channel 2 transfer complete flag */
#define DMA_ISR_TCIF2			(1 << 5)
/* GIF2: Channel 2 global interrupt flag */
#define DMA_ISR_GIF2			(1 << 4)
/* TEIF1: Channel 1 transfer error flag */
#define DMA_ISR_TEIF1			(1 << 3)
/* HTIF1: Channel 1 half transfer flag */
#define DMA_ISR_HTIF1			(1 << 2)
/* TCIF1: Channel 1 transfer complete flag */
#define DMA_ISR_TCIF1			(1 << 1)
/* GIF1: Channel 1 global interrupt flag */
#define DMA_ISR_GIF1			(1 << 0)

/* --- DMA_IFCR values ----------------------------------------------------- */

/* CTEIF7: Channel 7 transfer error clear */
#define DMA_IFCR_CTEIF7			(1 << 27)
/* CHTIF7: Channel 7 half transfer clear */
#define DMA_IFCR_CHTIF7			(1 << 26)
/* CTCIF7: Channel 7 transfer complete clear */
#define DMA_IFCR_CTCIF7			(1 << 25)
/* CGIF7: Channel 7 global interrupt clear */
#define DMA_IFCR_CGIF7			(1 << 24)
/* CTEIF6: Channel 6 transfer error clear */
#define DMA_IFCR_CTEIF6			(1 << 23)
/* CHTIF6: Channel 6 half transfer clear */
#define DMA_IFCR_CHTIF6			(1 << 22)
/* CTCIF6: Channel 6 transfer complete clear */
#define DMA_IFCR_CTCIF6			(1 << 21)
/* CGIF6: Channel 6 global interrupt clear */
#define DMA_IFCR_CGIF6			(1 << 20)
/* CTEIF5: Channel 5 transfer error clear */
#define DMA_IFCR_CTEIF5			(1 << 19)
/* CHTIF5: Channel 5 half transfer clear */
#define DMA_IFCR_CHTIF5			(1 << 18)
/* CTCIF5: Channel 5 transfer complete clear */
#define DMA_IFCR_CTCIF5			(1 << 17)
/* CGIF5: Channel 5 global interrupt clear */
#define DMA_IFCR_CGIF5			(1 << 16)
/* CTEIF4: Channel 4 transfer error clear */
#define DMA_IFCR_CTEIF4			(1 << 15)
/* CHTIF4: Channel 4 half transfer clear */
#define DMA_IFCR_CHTIF4			(1 << 14)
/* CTCIF4: Channel 4 transfer complete clear */
#define DMA_IFCR_CTCIF4			(1 << 13)
/* CGIF4: Channel 4 global interrupt clear */
#define DMA_IFCR_CGIF4			(1 << 12)
/* CTEIF3: Channel 3 transfer error clear */
#define DMA_IFCR_CTEIF3			(1 << 11)
/* CHTIF3: Channel 3 half transfer clear */
#define DMA_IFCR_CHTIF3			(1 << 10)
/* CTCIF3: Channel 3 transfer complete clear */
#define DMA_IFCR_CTCIF3			(1 << 9)
/* CGIF3: Channel 3 global interrupt clear */
#define DMA_IFCR_CGIF3			(1 << 8)
/* CTEIF2: Channel 2 transfer error clear */
#define DMA_IFCR_CTEIF2			(1 << 7)
/* CHTIF2: Channel 2 half transfer clear */
#define DMA_IFCR_CHTIF2			(1 << 6)
/* CTCIF2: Channel 2 transfer complete clear */
#define DMA_IFCR_CTCIF2			(1 << 5)
/* CGIF2: Channel 2 global interrupt clear */
#define DMA_IFCR_CGIF2			(1 << 4)
/* CTEIF1: Channel 1 transfer error clear */
#define DMA_IFCR_CTEIF1			(1 << 3)
/* CHTIF1: Channel 1 half transfer clear */
#define DMA_IFCR_CHTIF1			(1 << 2)
/* CTCIF1: Channel 1 transfer complete clear */
#define DMA_IFCR_CTCIF1			(1 << 1)
/* CGIF1: Channel 1 global interrupt clear */
#define DMA_IFCR_CGIF1			(1 << 0)

/* --- DMA_CCR1 values ----------------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CCR1_MEM2MEM		(1 << 14)

/* PL[13:12]: Channel priority level */
#define DMA_CCR1_PL_LSB			12
#define DMA_CCR1_PL_LOW			0x0
#define DMA_CCR1_PL_MEDIUM		0x1
#define DMA_CCR1_PL_HIGH		0x2
#define DMA_CCR1_PL_VERY_HIGH		0x3

/* MSIZE[11:10]: Memory size */
#define DMA_CCR1_MSIZE_LSB		10
#define DMA_CCR1_MSIZE_8BIT		0x0
#define DMA_CCR1_MSIZE_16BIT		0x1
#define DMA_CCR1_MSIZE_32BIT		0x2

/* PSIZE[9:8]: Peripheral size */
#define DMA_CCR1_PSIZE_LSB		8
#define DMA_CCR1_PSIZE_8BIT		0x0
#define DMA_CCR1_PSIZE_16BIT		0x1
#define DMA_CCR1_PSIZE_32BIT		0x2

/* MINC: Memory increment mode */
#define DMA_CCR1_MINC			(1 << 7)

/* PINC: Peripheral increment mode */
#define DMA_CCR1_PINC			(1 << 6)

/* CIRC: Circular mode */
#define DMA_CCR1_CIRC			(1 << 5)

/* DIR: Data transfer direction */
#define DMA_CCR1_DIR			(1 << 4)

/* TEIE: Transfer error interrupt enable */
#define DMA_CCR1_TEIE			(1 << 3)

/* HTIE: Half transfer interrupt enable */
#define DMA_CCR1_HTIE			(1 << 2)

/* TCIE: Transfer complete interrupt enable */
#define DMA_CCR1_TCIE			(1 << 1)

/* EN: Channel enable */
#define DMA_CCR1_EN			(1 << 0)

/* --- DMA_CCR2 values ----------------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CCR2_MEM2MEM		(1 << 14)

/* PL[13:12]: Channel priority level */
#define DMA_CCR2_PL_LSB			12
#define DMA_CCR2_PL_LOW			0x0
#define DMA_CCR2_PL_MEDIUM		0x1
#define DMA_CCR2_PL_HIGH		0x2
#define DMA_CCR2_PL_VERY_HIGH		0x3

/* MSIZE[11:10]: Memory size */
#define DMA_CCR2_MSIZE_LSB		10
#define DMA_CCR2_MSIZE_8BIT		0x0
#define DMA_CCR2_MSIZE_16BIT		0x1
#define DMA_CCR2_MSIZE_32BIT		0x2

/* PSIZE[9:8]: Peripheral size */
#define DMA_CCR2_PSIZE_LSB		8
#define DMA_CCR2_PSIZE_8BIT		0x0
#define DMA_CCR2_PSIZE_16BIT		0x1
#define DMA_CCR2_PSIZE_32BIT		0x2

/* MINC: Memory increment mode */
#define DMA_CCR2_MINC			(1 << 7)

/* PINC: Peripheral increment mode */
#define DMA_CCR2_PINC			(1 << 6)

/* CIRC: Circular mode */
#define DMA_CCR2_CIRC			(1 << 5)

/* DIR: Data transfer direction */
#define DMA_CCR2_DIR			(1 << 4)

/* TEIE: Transfer error interrupt enable */
#define DMA_CCR2_TEIE			(1 << 3)

/* HTIE: Half transfer interrupt enable */
#define DMA_CCR2_HTIE			(1 << 2)

/* TCIE: Transfer complete interrupt enable */
#define DMA_CCR2_TCIE			(1 << 1)

/* EN: Channel enable */
#define DMA_CCR2_EN			(1 << 0)

/* --- DMA_CCR3 values ----------------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CCR3_MEM2MEM		(1 << 14)

/* PL[13:12]: Channel priority level */
#define DMA_CCR3_PL_LSB			12
#define DMA_CCR3_PL_LOW			0x0
#define DMA_CCR3_PL_MEDIUM		0x1
#define DMA_CCR3_PL_HIGH		0x2
#define DMA_CCR3_PL_VERY_HIGH		0x3

/* MSIZE[11:10]: Memory size */
#define DMA_CCR3_MSIZE_LSB		10
#define DMA_CCR3_MSIZE_8BIT		0x0
#define DMA_CCR31_MSIZE_16BIT		0x1
#define DMA_CCR3_MSIZE_32BIT		0x2

/* PSIZE[9:8]: Peripheral size */
#define DMA_CCR3_PSIZE_LSB		8
#define DMA_CCR3_PSIZE_8BIT		0x0
#define DMA_CCR3_PSIZE_16BIT		0x1
#define DMA_CCR3_PSIZE_32BIT		0x2

/* MINC: Memory increment mode */
#define DMA_CCR3_MINC			(1 << 7)

/* PINC: Peripheral increment mode */
#define DMA_CCR3_PINC			(1 << 6)

/* CIRC: Circular mode */
#define DMA_CCR3_CIRC			(1 << 5)

/* DIR: Data transfer direction */
#define DMA_CCR3_DIR			(1 << 4)

/* TEIE: Transfer error interrupt enable */
#define DMA_CCR3_TEIE			(1 << 3)

/* HTIE: Half transfer interrupt enable */
#define DMA_CCR3_HTIE			(1 << 2)

/* TCIE: Transfer complete interrupt enable */
#define DMA_CCR3_TCIE			(1 << 1)

/* EN: Channel enable */
#define DMA_CCR3_EN			(1 << 0)

/* --- DMA_CCR4 values ----------------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CCR4_MEM2MEM		(1 << 14)

/* PL[13:12]: Channel priority level */
#define DMA_CCR4_PL_LSB			12
#define DMA_CCR4_PL_LOW			0x0
#define DMA_CCR4_PL_MEDIUM		0x1
#define DMA_CCR4_PL_HIGH		0x2
#define DMA_CCR4_PL_VERY_HIGH		0x3

/* MSIZE[11:10]: Memory size */
#define DMA_CCR4_MSIZE_LSB		10
#define DMA_CCR4_MSIZE_8BIT		0x0
#define DMA_CCR4_MSIZE_16BIT		0x1
#define DMA_CCR4_MSIZE_32BIT		0x2

/* PSIZE[9:8]: Peripheral size */
#define DMA_CCR4_PSIZE_LSB		8
#define DMA_CCR4_PSIZE_8BIT		0x0
#define DMA_CCR4_PSIZE_16BIT		0x1
#define DMA_CCR4_PSIZE_32BIT		0x2

/* MINC: Memory increment mode */
#define DMA_CCR4_MINC			(1 << 7)

/* PINC: Peripheral increment mode */
#define DMA_CCR4_PINC			(1 << 6)

/* CIRC: Circular mode */
#define DMA_CCR4_CIRC			(1 << 5)

/* DIR: Data transfer direction */
#define DMA_CCR4_DIR			(1 << 4)

/* TEIE: Transfer error interrupt enable */
#define DMA_CCR4_TEIE			(1 << 3)

/* HTIE: Half transfer interrupt enable */
#define DMA_CCR4_HTIE			(1 << 2)

/* TCIE: Transfer complete interrupt enable */
#define DMA_CCR4_TCIE			(1 << 1)

/* EN: Channel enable */
#define DMA_CCR4_EN			(1 << 0)

/* --- DMA_CCR5 values ----------------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CCR5_MEM2MEM		(1 << 14)

/* PL[13:12]: Channel priority level */
#define DMA_CCR5_PL_LSB			12
#define DMA_CCR5_PL_LOW			0x0
#define DMA_CCR5_PL_MEDIUM		0x1
#define DMA_CCR5_PL_HIGH		0x2
#define DMA_CCR5_PL_VERY_HIGH		0x3

/* MSIZE[11:10]: Memory size */
#define DMA_CCR5_MSIZE_LSB		10
#define DMA_CCR5_MSIZE_8BIT		0x0
#define DMA_CCR5_MSIZE_16BIT		0x1
#define DMA_CCR5_MSIZE_32BIT		0x2

/* PSIZE[9:8]: Peripheral size */
#define DMA_CCR5_PSIZE_LSB		8
#define DMA_CCR5_PSIZE_8BIT		0x0
#define DMA_CCR5_PSIZE_16BIT		0x1
#define DMA_CCR5_PSIZE_32BIT		0x2

/* MINC: Memory increment mode */
#define DMA_CCR5_MINC			(1 << 7)

/* PINC: Peripheral increment mode */
#define DMA_CCR5_PINC			(1 << 6)

/* CIRC: Circular mode */
#define DMA_CCR5_CIRC			(1 << 5)

/* DIR: Data transfer direction */
#define DMA_CCR5_DIR			(1 << 4)

/* TEIE: Transfer error interrupt enable */
#define DMA_CCR5_TEIE			(1 << 3)

/* HTIE: Half transfer interrupt enable */
#define DMA_CCR5_HTIE			(1 << 2)

/* TCIE: Transfer complete interrupt enable */
#define DMA_CCR5_TCIE			(1 << 1)

/* EN: Channel enable */
#define DMA_CCR5_EN			(1 << 0)

/* --- DMA_CCR6 values ----------------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CCR6_MEM2MEM		(1 << 14)

/* PL[13:12]: Channel priority level */
#define DMA_CCR6_PL_LSB			12
#define DMA_CCR6_PL_LOW			0x0
#define DMA_CCR6_PL_MEDIUM		0x1
#define DMA_CCR6_PL_HIGH		0x2
#define DMA_CCR6_PL_VERY_HIGH		0x3

/* MSIZE[11:10]: Memory size */
#define DMA_CCR6_MSIZE_LSB		10
#define DMA_CCR6_MSIZE_8BIT		0x0
#define DMA_CCR6_MSIZE_16BIT		0x1
#define DMA_CCR6_MSIZE_32BIT		0x2

/* PSIZE[9:8]: Peripheral size */
#define DMA_CCR6_PSIZE_LSB		8
#define DMA_CCR6_PSIZE_8BIT		0x0
#define DMA_CCR6_PSIZE_16BIT		0x1
#define DMA_CCR6_PSIZE_32BIT		0x2

/* MINC: Memory increment mode */
#define DMA_CCR6_MINC			(1 << 7)

/* PINC: Peripheral increment mode */
#define DMA_CCR6_PINC			(1 << 6)

/* CIRC: Circular mode */
#define DMA_CCR6_CIRC			(1 << 5)

/* DIR: Data transfer direction */
#define DMA_CCR6_DIR			(1 << 4)

/* TEIE: Transfer error interrupt enable */
#define DMA_CCR6_TEIE			(1 << 3)

/* HTIE: Half transfer interrupt enable */
#define DMA_CCR6_HTIE			(1 << 2)

/* TCIE: Transfer complete interrupt enable */
#define DMA_CCR6_TCIE			(1 << 1)

/* EN: Channel enable */
#define DMA_CCR6_EN			(1 << 0)

/* --- DMA_CCR7 values ----------------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CCR7_MEM2MEM		(1 << 14)

/* PL[13:12]: Channel priority level */
#define DMA_CCR7_PL_LSB			12
#define DMA_CCR7_PL_LOW			0x0
#define DMA_CCR7_PL_MEDIUM		0x1
#define DMA_CCR7_PL_HIGH		0x2
#define DMA_CCR7_PL_VERY_HIGH		0x3

/* MSIZE[11:10]: Memory size */
#define DMA_CCR7_MSIZE_LSB		10
#define DMA_CCR7_MSIZE_8BIT		0x0
#define DMA_CCR7_MSIZE_16BIT		0x1
#define DMA_CCR7_MSIZE_32BIT		0x2

/* PSIZE[9:8]: Peripheral size */
#define DMA_CCR7_PSIZE_LSB		8
#define DMA_CCR7_PSIZE_8BIT		0x0
#define DMA_CCR7_PSIZE_16BIT		0x1
#define DMA_CCR7_PSIZE_32BIT		0x2

/* MINC: Memory increment mode */
#define DMA_CCR7_MINC			(1 << 7)

/* PINC: Peripheral increment mode */
#define DMA_CCR7_PINC			(1 << 6)

/* CIRC: Circular mode */
#define DMA_CCR7_CIRC			(1 << 5)

/* DIR: Data transfer direction */
#define DMA_CCR7_DIR			(1 << 4)

/* TEIE: Transfer error interrupt enable */
#define DMA_CCR7_TEIE			(1 << 3)

/* HTIE: Half transfer interrupt enable */
#define DMA_CCR7_HTIE			(1 << 2)

/* TCIE: Transfer complete interrupt enable */
#define DMA_CCR7_TCIE			(1 << 1)

/* EN: Channel enable */
#define DMA_CCR7_EN			(1 << 0)

/* --- DMA_CCRx generic values --------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CCR_MEM2MEM		(1 << 14)

/* PL[13:12]: Channel priority level */
#define DMA_CCR_PL_LSB			12
#define DMA_CCR_PL_LOW			0x0
#define DMA_CCR_PL_MEDIUM		0x1
#define DMA_CCR_PL_HIGH			0x2
#define DMA_CCR_PL_VERY_HIGH		0x3

/* MSIZE[11:10]: Memory size */
#define DMA_CCR_MSIZE_LSB		10
#define DMA_CCR_MSIZE_8BIT		0x0
#define DMA_CCR_MSIZE_16BIT		0x1
#define DMA_CCR_MSIZE_32BIT		0x2

/* PSIZE[9:8]: Peripheral size */
#define DMA_CCR_PSIZE_LSB		8
#define DMA_CCR_PSIZE_8BIT		0x0
#define DMA_CCR_PSIZE_16BIT		0x1
#define DMA_CCR_PSIZE_32BIT		0x2

/* MINC: Memory increment mode */
#define DMA_CCR_MINC			(1 << 7)

/* PINC: Peripheral increment mode */
#define DMA_CCR_PINC			(1 << 6)

/* CIRC: Circular mode */
#define DMA_CCR_CIRC			(1 << 5)

/* DIR: Data transfer direction */
#define DMA_CCR_DIR			(1 << 4)

/* TEIE: Transfer error interrupt enable */
#define DMA_CCR_TEIE			(1 << 3)

/* HTIE: Half transfer interrupt enable */
#define DMA_CCR_HTIE			(1 << 2)

/* TCIE: Transfer complete interrupt enable */
#define DMA_CCR_TCIE			(1 << 1)

/* EN: Channel enable */
#define DMA_CCR_EN			(1 << 0)

/* --- DMA_CNDTRx values --------------------------------------------------- */

/* NDT[15:0]: Number of data to transfer */

/* --- DMA_CPARx values ---------------------------------------------------- */

/* PA[31:0]: Peripheral address */

/* --- DMA_CMARx values ---------------------------------------------------- */

/* MA[31:0]: Memory address */

/* --- Generic values ------------------------------------------------------ */

#define DMA_CHANNEL1			1
#define DMA_CHANNEL2			2
#define DMA_CHANNEL3			3
#define DMA_CHANNEL4			4
#define DMA_CHANNEL5			5
#define DMA_CHANNEL6			6
#define DMA_CHANNEL7			7

/* --- function prototypes ------------------------------------------------- */

void dma_enable_mem2mem_mode(u32 dma, u8 channel);
void dma_set_priority(u32 dma, u8 channel, u8 prio);
void dma_set_memory_size(u32 dma, u8 channel, u8 mem_size);
void dma_set_peripheral_size(u32 dma, u8 channel, u8 peripheral_size);
void dma_enable_memory_increment_mode(u32 dma, u8 channel);
void dma_enable_peripheral_increment_mode(u32 dma, u8 channel);
void dma_enable_circular_mode(u32 dma, u8 channel);
void dma_set_read_from_peripheral(u32 dma, u8 channel);
void dma_set_read_from_memory(u32 dma, u8 channel);
void dma_enable_transfer_error_interrupt(u32 dma, u8 channel);
void dma_disable_transfer_error_interrupt(u32 dma, u8 channel);
void dma_enable_half_transfer_interrupt(u32 dma, u8 channel);
void dma_disable_half_transfer_interrupt(u32 dma, u8 channel);
void dma_enable_transfer_complete_interrupt(u32 dma, u8 channel);
void dma_disable_transfer_complete_interrupt(u32 dma, u8 channel);
void dma_enable_channel(u32 dma, u8 channel);
void dma_disable_channel(u32 dma, u8 channel);
void dma_set_peripheral_address(u32 dma, u8 channel, u32 address);
void dma_set_memory_address(u32 dma, u8 channel, u32 address);
void dma_set_number_of_data(u32 dma, u8 channel, u16 number);

#endif
