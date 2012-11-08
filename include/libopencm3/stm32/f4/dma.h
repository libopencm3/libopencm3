/** @defgroup STM32F4xx_dma_defines DMA Defines

@ingroup STM32F4xx_defines

@brief Defined Constants and Types for the STM32F4xx DMA Controller

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Ken Sarkies <ksarkies@internode.on.net>

@date 18 October 2012

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Ken Sarkies <ksarkies@internode.on.net>
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

/**@{*/

#ifndef LIBOPENCM3_DMA_H
#define LIBOPENCM3_DMA_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- Convenience macros -------------------------------------------------- */

/* DMA register base adresses (for convenience) */
#define DMA1				DMA1_BASE
#define DMA2				DMA2_BASE

/* --- DMA registers ------------------------------------------------------- */

/* DMA low interrupt status register (DMAx_ISR) */
#define DMA_LISR(dma_base)		MMIO32(dma_base + 0x00)
#define DMA1_LISR			DMA_ISR(DMA1)
#define DMA2_LISR			DMA_ISR(DMA2)

/* DMA high interrupt status register (DMAx_ISR) */
#define DMA_HISR(dma_base)		MMIO32(dma_base + 0x04)
#define DMA1_HISR			DMA_ISR(DMA1)
#define DMA2_HISR			DMA_ISR(DMA2)

/* DMA low interrupt flag clear register (DMAx_IFCR) */
#define DMA_LIFCR(dma_base)		MMIO32(dma_base + 0x08)
#define DMA1_LIFCR			DMA_IFCR(DMA1)
#define DMA2_LIFCR			DMA_IFCR(DMA2)

/* DMA high interrupt flag clear register (DMAx_IFCR) */
#define DMA_HIFCR(dma_base)		MMIO32(dma_base + 0x0C)
#define DMA1_HIFCR			DMA_IFCR(DMA1)
#define DMA2_HIFCR			DMA_IFCR(DMA2)

/* DMA stream configuration register (DMAx_SyCR) */
#define DMA_SCR(dma_base, stream)	MMIO32(dma_base + 0x10 + \
					       (0x18 * (stream)))

#define DMA1_SCR(stream)		DMA_SCR(DMA1, stream)
#define DMA1_S0CR			DMA1_SCR(DMA_STREAM0)
#define DMA1_S1CR			DMA1_SCR(DMA_STREAM1)
#define DMA1_S2CR			DMA1_SCR(DMA_STREAM2)
#define DMA1_S3CR			DMA1_SCR(DMA_STREAM3)
#define DMA1_S4CR			DMA1_SCR(DMA_STREAM4)
#define DMA1_S5CR			DMA1_SCR(DMA_STREAM5)
#define DMA1_S6CR			DMA1_SCR(DMA_STREAM6)
#define DMA1_S7CR			DMA1_SCR(DMA_STREAM7)

#define DMA2_SCR(stream)		DMA_SCR(DMA2, stream)
#define DMA2_S0CR			DMA2_SCR(DMA_STREAM0)
#define DMA2_S1CR			DMA2_SCR(DMA_STREAM1)
#define DMA2_S2CR			DMA2_SCR(DMA_STREAM2)
#define DMA2_S3CR			DMA2_SCR(DMA_STREAM3)
#define DMA2_S4CR			DMA2_SCR(DMA_STREAM4)
#define DMA2_S5CR			DMA2_SCR(DMA_STREAM5)
#define DMA2_S6CR			DMA2_SCR(DMA_STREAM6)
#define DMA2_S7CR			DMA2_SCR(DMA_STREAM7)

/* DMA number of data register (DMAx_SyNDTR) */
#define DMA_SNDTR(dma_base, stream)	MMIO32(dma_base + 0x14 + \
					       (0x18 * (stream)))

#define DMA1_SNDTR(stream)		DMA_SNDTR(DMA1, stream)
#define DMA1_S0NDTR			DMA1_SNDTR(DMA_STREAM0)
#define DMA1_S1NDTR			DMA1_SNDTR(DMA_STREAM1)
#define DMA1_S2NDTR			DMA1_SNDTR(DMA_STREAM2)
#define DMA1_S3NDTR			DMA1_SNDTR(DMA_STREAM3)
#define DMA1_S4NDTR			DMA1_SNDTR(DMA_STREAM4)
#define DMA1_S5NDTR			DMA1_SNDTR(DMA_STREAM5)
#define DMA1_S6NDTR			DMA1_SNDTR(DMA_STREAM6)
#define DMA1_S7NDTR			DMA1_SNDTR(DMA_STREAM7)

#define DMA2_SNDTR(stream)		DMA_CNDTR(DMA2, stream)
#define DMA2_S0NDTR			DMA2_SNDTR(DMA_STREAM0)
#define DMA2_S1NDTR			DMA2_SNDTR(DMA_STREAM1)
#define DMA2_S2NDTR			DMA2_SNDTR(DMA_STREAM2)
#define DMA2_S3NDTR			DMA2_SNDTR(DMA_STREAM3)
#define DMA2_S4NDTR			DMA2_SNDTR(DMA_STREAM4)
#define DMA2_S5NDTR			DMA2_SNDTR(DMA_STREAM5)
#define DMA2_S6NDTR			DMA2_SNDTR(DMA_STREAM6)
#define DMA2_S7NDTR			DMA2_SNDTR(DMA_STREAM7)

/* DMA peripheral address register (DMAx_SyPAR) */
#define DMA_SPAR(dma_base, stream)	MMIO32(dma_base + 0x18 + \
					       (0x18 * (stream)))

#define DMA1_SPAR(stream)		DMA_SPAR(DMA1, stream)
#define DMA1_S0PAR			DMA1_SPAR(DMA_STREAM0)
#define DMA1_S1PAR			DMA1_SPAR(DMA_STREAM1)
#define DMA1_S2PAR			DMA1_SPAR(DMA_STREAM2)
#define DMA1_S3PAR			DMA1_SPAR(DMA_STREAM3)
#define DMA1_S4PAR			DMA1_SPAR(DMA_STREAM4)
#define DMA1_S5PAR			DMA1_SPAR(DMA_STREAM5)
#define DMA1_S6PAR			DMA1_SPAR(DMA_STREAM6)
#define DMA1_S7PAR			DMA1_SPAR(DMA_STREAM7)

#define DMA2_SPAR(stream)		DMA_SPAR(DMA2, stream)
#define DMA2_S0PAR			DMA2_SPAR(DMA_STREAM0)
#define DMA2_S1PAR			DMA2_SPAR(DMA_STREAM1)
#define DMA2_S2PAR			DMA2_SPAR(DMA_STREAM2)
#define DMA2_S3PAR			DMA2_SPAR(DMA_STREAM3)
#define DMA2_S4PAR			DMA2_SPAR(DMA_STREAM4)
#define DMA2_S5PAR			DMA2_SPAR(DMA_STREAM5)
#define DMA2_S6PAR			DMA2_SPAR(DMA_STREAM6)
#define DMA2_S7PAR			DMA2_SPAR(DMA_STREAM7)

/* DMA memory 0 address register (DMAx_SyM0AR) */

#define DMA_SM0AR(dma_base, stream)	MMIO32(dma_base + 0x1C + \
					       (0x18 * (stream)))

#define DMA1_SM0AR(stream)		DMA_SM0AR(DMA1, stream)
#define DMA1_S0M0AR			DMA1_SM0AR(DMA_STREAM0)
#define DMA1_S1M0AR			DMA1_SM0AR(DMA_STREAM1)
#define DMA1_S2M0AR			DMA1_SM0AR(DMA_STREAM2)
#define DMA1_S3M0AR			DMA1_SM0AR(DMA_STREAM3)
#define DMA1_S4M0AR			DMA1_SM0AR(DMA_STREAM4)
#define DMA1_S5M0AR			DMA1_SM0AR(DMA_STREAM5)
#define DMA1_S6M0AR			DMA1_SM0AR(DMA_STREAM6)
#define DMA1_S7M0AR			DMA1_SM0AR(DMA_STREAM7)

#define DMA2_SM0AR(stream)		DMA_CM0AR(DMA2, stream)
#define DMA2_S0M0AR			DMA2_SM0AR(DMA_STREAM0)
#define DMA2_S1M0AR			DMA2_SM0AR(DMA_STREAM1)
#define DMA2_S2M0AR			DMA2_SM0AR(DMA_STREAM2)
#define DMA2_S3M0AR			DMA2_SM0AR(DMA_STREAM3)
#define DMA2_S4M0AR			DMA2_SM0AR(DMA_STREAM4)
#define DMA2_S5M0AR			DMA2_SM0AR(DMA_STREAM5)
#define DMA2_S6M0AR			DMA2_SM0AR(DMA_STREAM6)
#define DMA2_S7M0AR			DMA2_SM0AR(DMA_STREAM7)

/* DMA memory 1 address register (DMAx_SyM1AR) */

#define DMA_SM1AR(dma_base, stream)	MMIO32(dma_base + 0x20 + \
					       (0x18 * (stream)))

#define DMA1_SM1AR(stream)		DMA_SM1AR(DMA1, stream)
#define DMA1_S0M1AR			DMA1_SM1AR(DMA_STREAM0)
#define DMA1_S1M1AR			DMA1_SM1AR(DMA_STREAM1)
#define DMA1_S2M1AR			DMA1_SM1AR(DMA_STREAM2)
#define DMA1_S3M1AR			DMA1_SM1AR(DMA_STREAM3)
#define DMA1_S4M1AR			DMA1_SM1AR(DMA_STREAM4)
#define DMA1_S5M1AR			DMA1_SM1AR(DMA_STREAM5)
#define DMA1_S6M1AR			DMA1_SM1AR(DMA_STREAM6)
#define DMA1_S7M1AR			DMA1_SM1AR(DMA_STREAM7)

#define DMA2_SM1AR(stream)		DMA_CM1AR(DMA2, stream)
#define DMA2_S0M1AR			DMA2_SM1AR(DMA_STREAM0)
#define DMA2_S1M1AR			DMA2_SM1AR(DMA_STREAM1)
#define DMA2_S2M1AR			DMA2_SM1AR(DMA_STREAM2)
#define DMA2_S3M1AR			DMA2_SM1AR(DMA_STREAM3)
#define DMA2_S4M1AR			DMA2_SM1AR(DMA_STREAM4)
#define DMA2_S5M1AR			DMA2_SM1AR(DMA_STREAM5)
#define DMA2_S6M1AR			DMA2_SM1AR(DMA_STREAM6)
#define DMA2_S7M1AR			DMA2_SM1AR(DMA_STREAM7)

/* DMA FIFO Control Register register (DMAx_SyFCR) */

#define DMA_SFCR(dma_base, stream)	MMIO32(dma_base + 0x24 + \
					       (0x18 * (stream)))

#define DMA1_SFCR(stream)		DMA_SFCR(DMA1, stream)
#define DMA1_S0FCR			DMA1_SFCR(DMA_STREAM0)
#define DMA1_S1FCR			DMA1_SFCR(DMA_STREAM1)
#define DMA1_S2FCR			DMA1_SFCR(DMA_STREAM2)
#define DMA1_S3FCR			DMA1_SFCR(DMA_STREAM3)
#define DMA1_S4FCR			DMA1_SFCR(DMA_STREAM4)
#define DMA1_S5FCR			DMA1_SFCR(DMA_STREAM5)
#define DMA1_S6FCR			DMA1_SFCR(DMA_STREAM6)
#define DMA1_S7FCR			DMA1_SFCR(DMA_STREAM7)

#define DMA2_SFCR(stream)		DMA_CFCR(DMA2, stream)
#define DMA2_S0FCR			DMA2_SFCR(DMA_STREAM0)
#define DMA2_S1FCR			DMA2_SFCR(DMA_STREAM1)
#define DMA2_S2FCR			DMA2_SFCR(DMA_STREAM2)
#define DMA2_S3FCR			DMA2_SFCR(DMA_STREAM3)
#define DMA2_S4FCR			DMA2_SFCR(DMA_STREAM4)
#define DMA2_S5FCR			DMA2_SFCR(DMA_STREAM5)
#define DMA2_S6FCR			DMA2_SFCR(DMA_STREAM6)
#define DMA2_S7FCR			DMA2_SFCR(DMA_STREAM7)

/* --- DMA Interrupt Flag offset values ------------------------------------- */
/* These are based on every interrupt flag and flag clear being at the same relative location */
/** @defgroup dma_if_offset DMA Interrupt Flag Offsets within stream flag group.
@ingroup STM32F4xx_dma_defines

@{*/
/** Transfer Complete Interrupt Flag */
#define DMA_ISR_TCIF       		(1 << 5)
/** Half Transfer Interrupt Flag */
#define DMA_ISR_HTIF       		(1 << 4)
/** Transfer Error Interrupt Flag */
#define DMA_ISR_TEIF       		(1 << 3)
/** Direct Mode Error Interrupt Flag */
#define DMA_ISR_DMEIF       	(1 << 2)
/** FIFO Error Interrupt Flag */
#define DMA_ISR_FEIF       		(1 << 0)
/**@}*/

/* Offset within interrupt status register to start of stream interrupt flag field */
#define DMA_ISR_OFFSET(stream)		(6*(stream & 0x01)+16*((stream & 0x02) >> 1))
#define DMA_ISR_FLAGS			(DMA_ISR_TCIF | DMA_ISR_HTIF | DMA_ISR_TEIF | DMA_ISR_DMEIF | DMA_ISR_FEIF)
#define DMA_ISR_MASK(stream)		DMA_ISR_FLAGS << DMA_ISR_OFFSET(stream)

/* --- DMA_LISR values ------------------------------------------------------ */

/* TCIF: Transfer complete interrupt flag, streams 0-3 only */
#define DMA_LISR_TCIF_BIT       		DMA_ISR_TCIF
#define DMA_LISR_TCIF(stream)		(DMA_LISR_TCIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LISR_TCIF0			DMA_LISR_TCIF(DMA_STREAM0)
#define DMA_LISR_TCIF1			DMA_LISR_TCIF(DMA_STREAM1)
#define DMA_LISR_TCIF2			DMA_LISR_TCIF(DMA_STREAM2)
#define DMA_LISR_TCIF3			DMA_LISR_TCIF(DMA_STREAM3)

/* HTIF: Half transfer interrupt flag, streams 0-3 only */
#define DMA_LISR_HTIF_BIT       		DMA_ISR_HTIF
#define DMA_LISR_HTIF(stream)		(DMA_LISR_HTIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LISR_HTIF0			DMA_LISR_HTIF(DMA_STREAM0)
#define DMA_LISR_HTIF1			DMA_LISR_HTIF(DMA_STREAM1)
#define DMA_LISR_HTIF2			DMA_LISR_HTIF(DMA_STREAM2)
#define DMA_LISR_HTIF3			DMA_LISR_HTIF(DMA_STREAM3)

/* TEIF: Transfer error interrupt flag, streams 0-3 only */
#define DMA_LISR_TEIF_BIT       		DMA_ISR_TEIF
#define DMA_LISR_TEIF(stream)		(DMA_LISR_TEIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LISR_TEIF0			DMA_LISR_TEIF(DMA_STREAM0)
#define DMA_LISR_TEIF1			DMA_LISR_TEIF(DMA_STREAM1)
#define DMA_LISR_TEIF2			DMA_LISR_TEIF(DMA_STREAM2)
#define DMA_LISR_TEIF3			DMA_LISR_TEIF(DMA_STREAM3)

/* DMEIF: Direct Mode Error interrupt flag, streams 0-3 only */
#define DMA_LISR_DMEIF_BIT			DMA_ISR_DMEIF
#define DMA_LISR_DMEIF(stream)		(DMA_LISR_DMEIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LISR_DMEIF0			DMA_LISR_DMEIF(DMA_STREAM0)
#define DMA_LISR_DMEIF1			DMA_LISR_DMEIF(DMA_STREAM1)
#define DMA_LISR_DMEIF2			DMA_LISR_DMEIF(DMA_STREAM2)
#define DMA_LISR_DMEIF3			DMA_LISR_DMEIF(DMA_STREAM3)

/* Interrupt #1 is reserved */

/* FEIF: FIFO Error interrupt flag, streams 0-3 only */
#define DMA_LISR_FEIF_BIT			DMA_ISR_FEIF
#define DMA_LISR_FEIF(stream)		(DMA_LISR_FEIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LISR_FEIF0			DMA_LISR_FEIF(DMA_STREAM0)
#define DMA_LISR_FEIF1			DMA_LISR_FEIF(DMA_STREAM1)
#define DMA_LISR_FEIF2			DMA_LISR_FEIF(DMA_STREAM2)
#define DMA_LISR_FEIF3			DMA_LISR_FEIF(DMA_STREAM3)

/* --- DMA_HISR values ------------------------------------------------------ */

/* TCIF: Transfer complete interrupt flag, streams 4-7 only */
#define DMA_HISR_TCIF_BIT       		DMA_ISR_TCIF
#define DMA_HISR_TCIF(stream)		(DMA_HISR_TCIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HISR_TCIF4			DMA_HISR_TCIF(DMA_STREAM4)
#define DMA_HISR_TCIF5			DMA_HISR_TCIF(DMA_STREAM5)
#define DMA_HISR_TCIF6			DMA_HISR_TCIF(DMA_STREAM6)
#define DMA_HISR_TCIF7			DMA_HISR_TCIF(DMA_STREAM7)

/* HTIF: Half transfer interrupt flag, streams 4-7 only */
#define DMA_HISR_HTIF_BIT       		DMA_ISR_HTIF
#define DMA_HISR_HTIF(stream)		(DMA_HISR_HTIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HISR_HTIF4			DMA_HISR_HTIF(DMA_STREAM4)
#define DMA_HISR_HTIF5			DMA_HISR_HTIF(DMA_STREAM5)
#define DMA_HISR_HTIF6			DMA_HISR_HTIF(DMA_STREAM6)
#define DMA_HISR_HTIF7			DMA_HISR_HTIF(DMA_STREAM7)

/* TEIF: Transfer error interrupt flag, streams 4-7 only */
#define DMA_HISR_TEIF_BIT       		DMA_ISR_TEIF
#define DMA_HISR_TEIF(stream)		(DMA_HISR_TEIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HISR_TEIF4			DMA_HISR_TEIF(DMA_STREAM4)
#define DMA_HISR_TEIF5			DMA_HISR_TEIF(DMA_STREAM5)
#define DMA_HISR_TEIF6			DMA_HISR_TEIF(DMA_STREAM6)
#define DMA_HISR_TEIF7			DMA_HISR_TEIF(DMA_STREAM7)

/* DMEIF: Direct Mode Error interrupt flag, streams 4-7 only */
#define DMA_HISR_DMEIF_BIT			DMA_ISR_DMEIF
#define DMA_HISR_DMEIF(stream)		(DMA_HISR_DMEIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HISR_DMEIF4			DMA_HISR_DMEIF(DMA_STREAM4)
#define DMA_HISR_DMEIF5			DMA_HISR_DMEIF(DMA_STREAM5)
#define DMA_HISR_DMEIF6			DMA_HISR_DMEIF(DMA_STREAM6)
#define DMA_HISR_DMEIF7			DMA_HISR_DMEIF(DMA_STREAM7)

/* Interrupt #1 is reserved */

/* FEIF: FIFO Error interrupt flag, streams 4-7 only */
#define DMA_HISR_FEIF_BIT			DMA_ISR_FEIF
#define DMA_HISR_FEIF(stream)		(DMA_HISR_FEIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HISR_FEIF4			DMA_HISR_FEIF(DMA_STREAM4)
#define DMA_HISR_FEIF5			DMA_HISR_FEIF(DMA_STREAM5)
#define DMA_HISR_FEIF6			DMA_HISR_FEIF(DMA_STREAM6)
#define DMA_HISR_FEIF7			DMA_HISR_FEIF(DMA_STREAM7)

/* --- DMA_LIFCR values ------------------------------------------------------ */

/* TCIF: Transfer complete interrupt flag, streams 0-3 only */
#define DMA_LIFCR_CTCIF_BIT       		DMA_ISR_TCIF
#define DMA_LIFCR_CTCIF(stream)		(DMA_LIFCR_CTCIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LIFCR_CTCIF0			DMA_LIFCR_CTCIF(DMA_STREAM0)
#define DMA_LIFCR_CTCIF1			DMA_LIFCR_CTCIF(DMA_STREAM1)
#define DMA_LIFCR_CTCIF2			DMA_LIFCR_CTCIF(DMA_STREAM2)
#define DMA_LIFCR_CTCIF3			DMA_LIFCR_CTCIF(DMA_STREAM3)

/* HTIF: Half transfer interrupt flag, streams 0-3 only */
#define DMA_LIFCR_CHTIF_BIT       		DMA_ISR_HTIF
#define DMA_LIFCR_CHTIF(stream)		(DMA_LIFCR_CHTIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LIFCR_CHTIF0			DMA_LIFCR_CHTIF(DMA_STREAM0)
#define DMA_LIFCR_CHTIF1			DMA_LIFCR_CHTIF(DMA_STREAM1)
#define DMA_LIFCR_CHTIF2			DMA_LIFCR_CHTIF(DMA_STREAM2)
#define DMA_LIFCR_CHTIF3			DMA_LIFCR_CHTIF(DMA_STREAM3)

/* TEIF: Transfer error interrupt flag, streams 0-3 only */
#define DMA_LIFCR_CTEIF_BIT       		DMA_ISR_TEIF
#define DMA_LIFCR_CTEIF(stream)		(DMA_LIFCR_CTEIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LIFCR_CTEIF0			DMA_LIFCR_CTEIF(DMA_STREAM0)
#define DMA_LIFCR_CTEIF1			DMA_LIFCR_CTEIF(DMA_STREAM1)
#define DMA_LIFCR_CTEIF2			DMA_LIFCR_CTEIF(DMA_STREAM2)
#define DMA_LIFCR_CTEIF3			DMA_LIFCR_CTEIF(DMA_STREAM3)

/* DMEIF: Direct Mode Error interrupt flag, streams 0-3 only */
#define DMA_LIFCR_CDMEIF_BIT			DMA_ISR_DMEIF
#define DMA_LIFCR_CDMEIF(stream)		(DMA_LIFCR_CDMEIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LIFCR_CDMEIF0			DMA_LIFCR_CDMEIF(DMA_STREAM0)
#define DMA_LIFCR_CDMEIF1			DMA_LIFCR_CDMEIF(DMA_STREAM1)
#define DMA_LIFCR_CDMEIF2			DMA_LIFCR_CDMEIF(DMA_STREAM2)
#define DMA_LIFCR_CDMEIF3			DMA_LIFCR_CDMEIF(DMA_STREAM3)

/* Interrupt #1 is reserved */

/* FEIF: FIFO Error interrupt flag, streams 0-3 only */
#define DMA_LIFCR_CFEIF_BIT			DMA_ISR_FEIF
#define DMA_LIFCR_CFEIF(stream)		(DMA_LIFCR_CFEIF_BIT << DMA_ISR_OFFSET(stream))

#define DMA_LIFCR_CFEIF0			DMA_LIFCR_CFEIF(DMA_STREAM0)
#define DMA_LIFCR_CFEIF1			DMA_LIFCR_CFEIF(DMA_STREAM1)
#define DMA_LIFCR_CFEIF2			DMA_LIFCR_CFEIF(DMA_STREAM2)
#define DMA_LIFCR_CFEIF3			DMA_LIFCR_CFEIF(DMA_STREAM3)

/* --- DMA_HIFCR values ------------------------------------------------------ */

/* TCIF: Transfer complete interrupt flag, streams 4-7 only */
#define DMA_HIFCR_CTCIF_BIT       		DMA_ISR_TCIF
#define DMA_HIFCR_CTCIF(stream)		(DMA_HIFCR_CTCIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HIFCR_CTCIF4			DMA_HIFCR_CTCIF(DMA_STREAM4)
#define DMA_HIFCR_CTCIF5			DMA_HIFCR_CTCIF(DMA_STREAM5)
#define DMA_HIFCR_CTCIF6			DMA_HIFCR_CTCIF(DMA_STREAM6)
#define DMA_HIFCR_CTCIF7			DMA_HIFCR_CTCIF(DMA_STREAM7)

/* HTIF: Half transfer interrupt flag, streams 4-7 only */
#define DMA_HIFCR_CHTIF_BIT       		DMA_ISR_HTIF
#define DMA_HIFCR_CHTIF(stream)		(DMA_HIFCR_CHTIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HIFCR_CHTIF4			DMA_HIFCR_CHTIF(DMA_STREAM4)
#define DMA_HIFCR_CHTIF5			DMA_HIFCR_CHTIF(DMA_STREAM5)
#define DMA_HIFCR_CHTIF6			DMA_HIFCR_CHTIF(DMA_STREAM6)
#define DMA_HIFCR_CHTIF7			DMA_HIFCR_CHTIF(DMA_STREAM7)

/* TEIF: Transfer error interrupt flag, streams 4-7 only */
#define DMA_HIFCR_CTEIF_BIT       		DMA_ISR_TEIF
#define DMA_HIFCR_CTEIF(stream)		(DMA_HIFCR_CTEIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HIFCR_CTEIF4			DMA_HIFCR_CTEIF(DMA_STREAM4)
#define DMA_HIFCR_CTEIF5			DMA_HIFCR_CTEIF(DMA_STREAM5)
#define DMA_HIFCR_CTEIF6			DMA_HIFCR_CTEIF(DMA_STREAM6)
#define DMA_HIFCR_CTEIF7			DMA_HIFCR_CTEIF(DMA_STREAM7)

/* DMEIF: Direct Mode Error interrupt flag, streams 4-7 only */
#define DMA_HIFCR_CDMEIF_BIT			DMA_ISR_DMEIF
#define DMA_HIFCR_CDMEIF(stream)		(DMA_HIFCR_CDMEIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HIFCR_CDMEIF4			DMA_HIFCR_CDMEIF(DMA_STREAM4)
#define DMA_HIFCR_CDMEIF5			DMA_HIFCR_CDMEIF(DMA_STREAM5)
#define DMA_HIFCR_CDMEIF6			DMA_HIFCR_CDMEIF(DMA_STREAM6)
#define DMA_HIFCR_CDMEIF7			DMA_HIFCR_CDMEIF(DMA_STREAM7)

/* Interrupt #1 is reserved */

/* FEIF: FIFO Error interrupt flag, streams 4-7 only */
#define DMA_HIFCR_CFEIF_BIT			DMA_ISR_FEIF
#define DMA_HIFCR_CFEIF(stream)		(DMA_HIFCR_CFEIF_BIT << (DMA_ISR_OFFSET(stream - 4))

#define DMA_HIFCR_CFEIF4			DMA_HIFCR_CFEIF(DMA_STREAM4)
#define DMA_HIFCR_CFEIF5			DMA_HIFCR_CFEIF(DMA_STREAM5)
#define DMA_HIFCR_CFEIF6			DMA_HIFCR_CFEIF(DMA_STREAM6)
#define DMA_HIFCR_CFEIF7			DMA_HIFCR_CFEIF(DMA_STREAM7)

/* --- DMA_SxCR generic values --------------------------------------------- */

/* Reserved [31:28] */

/* CHSEL[13:12]: Channel Select */
/** @defgroup dma_ch_sel DMA Channel Select
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SCR_CHSEL_0			(0x0 << 25)
#define DMA_SCR_CHSEL_1			(0x1 << 25)
#define DMA_SCR_CHSEL_2			(0x2 << 25)
#define DMA_SCR_CHSEL_3			(0x3 << 25)
#define DMA_SCR_CHSEL_4			(0x4 << 25)
#define DMA_SCR_CHSEL_5			(0x5 << 25)
#define DMA_SCR_CHSEL_6			(0x6 << 25)
#define DMA_SCR_CHSEL_7			(0x7 << 25)
/**@}*/
#define DMA_SCR_CHSEL_MASK			(0x7 << 25)
#define DMA_SCR_CHSEL_SHIFT		25

/* MBURST[13:12]: Memory Burst Configuration */
/** @defgroup dma_mburst DMA Memory Burst Length
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SCR_MBURST_INCR0			(0x0 << 23)
#define DMA_SCR_MBURST_INCR4			(0x1 << 23)
#define DMA_SCR_MBURST_INCR8			(0x2 << 23)
#define DMA_SCR_MBURST_INCR16			(0x3 << 23)
/**@}*/
#define DMA_SCR_MBURST_MASK			(0x3 << 23)
#define DMA_SCR_MBURST_SHIFT		23

/* PBURST[13:12]: Peripheral Burst Configuration */
/** @defgroup dma_pburst DMA Peripheral Burst Length
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SCR_PBURST_INCR0			(0x0 << 21)
#define DMA_SCR_PBURST_INCR4			(0x1 << 21)
#define DMA_SCR_PBURST_INCR8			(0x2 << 21)
#define DMA_SCR_PBURST_INCR16			(0x3 << 21)
/**@}*/
#define DMA_SCR_PBURST_MASK			(0x3 << 21)
#define DMA_SCR_PBURST_SHIFT		21

/* Bit 20 reserved */

/* CT: Current target (in double buffered mode) */
#define DMA_SCR_CT			(1 << 19)

/* DBM: Double buffered mode */
#define DMA_SCR_DBM			(1 << 18)

/* PL[17:16]: Stream priority level */
/** @defgroup dma_st_pri DMA Stream Priority Levels
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SCR_PL_LOW			(0x0 << 16)
#define DMA_SCR_PL_MEDIUM		(0x1 << 16)
#define DMA_SCR_PL_HIGH			(0x2 << 16)
#define DMA_SCR_PL_VERY_HIGH		(0x3 << 16)
/**@}*/
#define DMA_SCR_PL_MASK			(0x3 << 16)
#define DMA_SCR_PL_SHIFT		16

/* PINCOS: Peripheral increment offset size */
#define DMA_SCR_PINCOS			(1 << 15)

/* MSIZE[14:13]: Memory size */
/** @defgroup dma_st_memwidth DMA Stream Memory Word Width
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SCR_MSIZE_8BIT		(0x0 << 13)
#define DMA_SCR_MSIZE_16BIT		(0x1 << 13)
#define DMA_SCR_MSIZE_32BIT		(0x2 << 13)
/**@}*/
#define DMA_SCR_MSIZE_MASK		(0x3 << 13)
#define DMA_SCR_MSIZE_SHIFT		13

/* PSIZE[12:11]: Peripheral size */
/** @defgroup dma_st_perwidth DMA Stream Peripheral Word Width
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SCR_PSIZE_8BIT		(0x0 << 11)
#define DMA_SCR_PSIZE_16BIT		(0x1 << 11)
#define DMA_SCR_PSIZE_32BIT		(0x2 << 11)
/**@}*/
#define DMA_SCR_PSIZE_MASK		(0x3 << 11)
#define DMA_SCR_PSIZE_SHIFT		11

/* MINC: Memory increment mode */
#define DMA_SCR_MINC			(1 << 10)

/* PINC: Peripheral increment mode */
#define DMA_SCR_PINC			(1 << 9)

/* CIRC: Circular mode */
#define DMA_SCR_CIRC			(1 << 8)

/* DIR[7:6]: Data transfer direction */
/** @defgroup dma_st_dir DMA Stream Data transfer direction
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SCR_DIR_PER2MEM			(0x0 << 6)
#define DMA_SCR_DIR_MEM2PER			(0x1 << 6)
#define DMA_SCR_DIR_MEM2MEM			(0x2 << 6)
/**@}*/
#define DMA_SCR_DIR_MASK			(0x3 << 6)
#define DMA_SCR_DIR_SHIFT			6

/* PFCTRL: Peripheral Flow Controller */
#define DMA_SCR_PFCTRL			(1 << 5)

/* TCIE: Transfer complete interrupt enable */
#define DMA_SCR_TCIE			(1 << 4)

/* HTIE: Half transfer interrupt enable */
#define DMA_SCR_HTIE			(1 << 3)

/* TEIE: Transfer error interrupt enable */
#define DMA_SCR_TEIE			(1 << 2)

/* DMEIE: Direct Mode error interrupt enable */
#define DMA_SCR_DMEIE			(1 << 1)

/* EN: Stream enable */
#define DMA_SCR_EN			(1 << 0)

/* --- DMA_SxNDTR values --------------------------------------------------- */

/* NDT[15:0]: Number of data to transfer */

/* --- DMA_SxPAR values ---------------------------------------------------- */

/* PA[31:0]: Peripheral address */

/* --- DMA_SxM0AR values ---------------------------------------------------- */

/* M0A[31:0]: Memory address */

/* --- DMA_SxM1AR values ---------------------------------------------------- */

/* M1A[31:0]: Memory address */

/* --- DMA_SxFCR generic values --------------------------------------------- */

/* Reserved [31:8] */

/* FEIE: FIFO error interrupt enable */
#define DMA_FCR_FEIE			(1 << 7)

/* Bit 6 reserved */

/* FS[5:3]: FIFO Status */
/** @defgroup dma_fifo_status FIFO Status
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_FCR_FS_LOW			(0x0 << 3)
#define DMA_FCR_FS_UNDER_HALF	(0x1 << 3)
#define DMA_FCR_FS_MEDIUM		(0x2 << 3)
#define DMA_FCR_FS_HIGH			(0x3 << 3)
#define DMA_FCR_FS_EMPTY		(0x4 << 3)
#define DMA_FCR_FS_FULL			(0x5 << 3)
/**@}*/
#define DMA_FCR_FS_MASK			(0x7 << 3)
#define DMA_FCR_FS_SHIFT		3

/* DMDIS: Direct Mode disable */
#define DMA_FCR_DMDIS			(1 << 2)

/* FTH[1:0]: FIFO Threshold selection */
/** @defgroup dma_fifo_thresh FIFO Threshold selection
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_FCR_FTH_LOW			(0x0 << 0)
#define DMA_FCR_FTH_HALF		(0x1 << 0)
#define DMA_FCR_FTH_MEDIUM		(0x2 << 0)
#define DMA_FCR_FTH_FULL			(0x3 << 0)
/**@}*/
#define DMA_FCR_FTH_MASK			(0x3 << 0)
#define DMA_FCR_FTH_SHIFT		3

/* --- Generic values ------------------------------------------------------ */

/** @defgroup dma_st_number DMA Stream Number
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_STREAM0			0
#define DMA_STREAM1			1
#define DMA_STREAM2			2
#define DMA_STREAM3			3
#define DMA_STREAM4			4
#define DMA_STREAM5			5
#define DMA_STREAM6			6
#define DMA_STREAM7			7
/**@}*/

/* --- function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dma_stream_reset(u32 dma, u8 stream);
void dma_clear_interrupt_flags(u32 dma, u8 stream, u32 interrupts);
bool dma_get_interrupt_flag(u32 dma, u8 stream, u32 interrupt);
void dma_set_transfer_mode(u32 dma, u8 stream, u32 direction);
void dma_set_priority(u32 dma, u8 stream, u32 prio);
void dma_set_memory_size(u32 dma, u8 stream, u32 mem_size);
void dma_set_peripheral_size(u32 dma, u8 stream, u32 peripheral_size);
void dma_enable_memory_increment_mode(u32 dma, u8 stream);
void dma_disable_memory_increment_mode(u32 dma, u8 channel);
void dma_enable_peripheral_increment_mode(u32 dma, u8 stream);
void dma_disable_peripheral_increment_mode(u32 dma, u8 channel);
void dma_enable_fixed_peripheral_increment_mode(u32 dma, u8 stream);
void dma_enable_circular_mode(u32 dma, u8 stream);
void dma_channel_select(u32 dma, u8 stream, u32 channel);
void dma_channel_select(u32 dma, u8 stream, u32 channel);
void dma_set_memory_burst(u32 dma, u8 stream, u32 burst);
void dma_set_peripheral_burst(u32 dma, u8 stream, u32 burst);
void dma_set_initial_target(u32 dma, u8 stream, u8 memory);
u8 dma_get_target(u32 dma, u8 stream);
void dma_enable_double_buffer_mode(u32 dma, u8 stream);
void dma_set_peripheral_flow_control(u32 dma, u8 stream);
void dma_set_dma_flow_control(u32 dma, u8 stream);
void dma_enable_transfer_error_interrupt(u32 dma, u8 stream);
void dma_disable_transfer_error_interrupt(u32 dma, u8 stream);
void dma_enable_half_transfer_interrupt(u32 dma, u8 stream);
void dma_disable_half_transfer_interrupt(u32 dma, u8 stream);
void dma_enable_transfer_complete_interrupt(u32 dma, u8 stream);
void dma_disable_transfer_complete_interrupt(u32 dma, u8 stream);
u32 dma_fifo_status(u32 dma, u8 stream);
void dma_enable_direct_mode_error_interrupt(u32 dma, u8 stream);
void dma_disable_direct_mode_error_interrupt(u32 dma, u8 stream);
void dma_enable_fifo_error_interrupt(u32 dma, u8 stream);
void dma_disable_fifo_error_interrupt(u32 dma, u8 stream);
void dma_enable_direct_mode(u32 dma, u8 stream);
void dma_enable_fifo_mode(u32 dma, u8 stream);
void dma_set_fifo_threshold(u32 dma, u8 stream, u32 threshold);
void dma_enable_stream(u32 dma, u8 stream);
void dma_disable_stream(u32 dma, u8 stream);
void dma_set_peripheral_address(u32 dma, u8 stream, u32 address);
void dma_set_memory_address(u32 dma, u8 stream, u32 address);
void dma_set_memory_address_1(u32 dma, u8 stream, u32 address);
void dma_set_number_of_data(u32 dma, u8 stream, u16 number);

END_DECLS

#endif
/**@}*/

