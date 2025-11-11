/** @addtogroup dma_defines

@author @htmlonly &copy; @endhtmlonly 2011
Fergus Noble <fergusnoble@gmail.com>
@author @htmlonly &copy; @endhtmlonly 2012
Ken Sarkies <ksarkies@internode.on.net>

*/
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2011 Fergus Noble <fergusnoble@gmail.com>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA DMA.H
The order of header inclusion is important. dma.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_DMA_H
/** @endcond */
#ifndef LIBOPENCM3_DMA_COMMON_F24_H
#define LIBOPENCM3_DMA_COMMON_F24_H

/**@{*/

/* --- Convenience macros -------------------------------------------------- */

/* DMA controller base addresses (for convenience) */
#define DMA1				DMA1_BASE
#define DMA2				DMA2_BASE

/* DMA stream base addresses (for API parameters) */
/** @defgroup dma_st_number DMA Stream Number
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_STREAM0			0U
#define DMA_STREAM1			1U
#define DMA_STREAM2			2U
#define DMA_STREAM3			3U
#define DMA_STREAM4			4U
#define DMA_STREAM5			5U
#define DMA_STREAM6			6U
#define DMA_STREAM7			7U
/**@}*/

#define DMA_STREAM(port, n)		((port) + 0x10U + (24U * (n)))
#define DMA1_STREAM(n)			DMA_STREAM(DMA1, (n))
#define DMA2_STREAM(n)			DMA_STREAM(DMA2, (n))

#define DMA1_STREAM0			DMA1_STREAM(0U)
#define DMA1_STREAM1			DMA1_STREAM(1U)
#define DMA1_STREAM2			DMA1_STREAM(2U)
#define DMA1_STREAM3			DMA1_STREAM(3U)
#define DMA1_STREAM4			DMA1_STREAM(4U)
#define DMA1_STREAM5			DMA1_STREAM(5U)
#define DMA1_STREAM6			DMA1_STREAM(6U)
#define DMA1_STREAM7			DMA1_STREAM(7U)

#define DMA2_STREAM0			DMA2_STREAM(0U)
#define DMA2_STREAM1			DMA2_STREAM(1U)
#define DMA2_STREAM2			DMA2_STREAM(2U)
#define DMA2_STREAM3			DMA2_STREAM(3U)
#define DMA2_STREAM4			DMA2_STREAM(4U)
#define DMA2_STREAM5			DMA2_STREAM(5U)
#define DMA2_STREAM6			DMA2_STREAM(6U)
#define DMA2_STREAM7			DMA2_STREAM(7U)

/* --- DMA controller registers -------------------------------------------- */

/* DMA low interrupt status register (DMAx_LISR) */
#define DMA_LISR(port)			MMIO32((port) + 0x00U)
#define DMA1_LISR			DMA_LISR(DMA1)
#define DMA2_LISR			DMA_LISR(DMA2)

/* DMA high interrupt status register (DMAx_HISR) */
#define DMA_HISR(port)			MMIO32((port) + 0x04U)
#define DMA1_HISR			DMA_HISR(DMA1)
#define DMA2_HISR			DMA_HISR(DMA2)

/* DMA low interrupt flag clear register (DMAx_LIFCR) */
#define DMA_LIFCR(port)			MMIO32((port) + 0x08U)
#define DMA1_LIFCR			DMA_LIFCR(DMA1)
#define DMA2_LIFCR			DMA_LIFCR(DMA2)

/* DMA high interrupt flag clear register (DMAx_HIFCR) */
#define DMA_HIFCR(port)			MMIO32((port) + 0x0CU)
#define DMA1_HIFCR			DMA_HIFCR(DMA1)
#define DMA2_HIFCR			DMA_HIFCR(DMA2)

/* --- DMA stream registers ------------------------------------------------ */

/* DMA Stream x configuration register (DMA_SxCR) */
#define DMA_SCR(port, n)		MMIO32(DMA_STREAM((port), (n)) + 0x00U)
#define DMA1_SCR(n)			DMA_SCR(DMA1, (n))
#define DMA2_SCR(n)			DMA_SCR(DMA2, (n))

#define DMA1_S0CR			DMA1_SCR(0U)
#define DMA1_S1CR			DMA1_SCR(1U)
#define DMA1_S2CR			DMA1_SCR(2U)
#define DMA1_S3CR			DMA1_SCR(3U)
#define DMA1_S4CR			DMA1_SCR(4U)
#define DMA1_S5CR			DMA1_SCR(5U)
#define DMA1_S6CR			DMA1_SCR(6U)
#define DMA1_S7CR			DMA1_SCR(7U)

#define DMA2_S0CR			DMA2_SCR(0U)
#define DMA2_S1CR			DMA2_SCR(1U)
#define DMA2_S2CR			DMA2_SCR(2U)
#define DMA2_S3CR			DMA2_SCR(3U)
#define DMA2_S4CR			DMA2_SCR(4U)
#define DMA2_S5CR			DMA2_SCR(5U)
#define DMA2_S6CR			DMA2_SCR(6U)
#define DMA2_S7CR			DMA2_SCR(7U)

/* DMA Stream x number of data register (DMA_SxNDTR) */
#define DMA_SNDTR(port, n)		MMIO32(DMA_STREAM((port), (n)) + 0x04U)
#define DMA1_SNDTR(n)			DMA_SNDTR(DMA1, (n))
#define DMA2_SNDTR(n)			DMA_SNDTR(DMA2, (n))

#define DMA1_S0NDTR			DMA1_SNDTR(0U)
#define DMA1_S1NDTR			DMA1_SNDTR(1U)
#define DMA1_S2NDTR			DMA1_SNDTR(2U)
#define DMA1_S3NDTR			DMA1_SNDTR(3U)
#define DMA1_S4NDTR			DMA1_SNDTR(4U)
#define DMA1_S5NDTR			DMA1_SNDTR(5U)
#define DMA1_S6NDTR			DMA1_SNDTR(6U)
#define DMA1_S7NDTR			DMA1_SNDTR(7U)

#define DMA2_S0NDTR			DMA2_SNDTR(0U)
#define DMA2_S1NDTR			DMA2_SNDTR(1U)
#define DMA2_S2NDTR			DMA2_SNDTR(2U)
#define DMA2_S3NDTR			DMA2_SNDTR(3U)
#define DMA2_S4NDTR			DMA2_SNDTR(4U)
#define DMA2_S5NDTR			DMA2_SNDTR(5U)
#define DMA2_S6NDTR			DMA2_SNDTR(6U)
#define DMA2_S7NDTR			DMA2_SNDTR(7U)

/* DMA Stream x peripheral address register (DMA_SxPAR) */
#define DMA_SPAR(port, n)		(*(volatile void **)\
					 (DMA_STREAM((port), (n)) + 0x08U))
#define DMA1_SPAR(n)			DMA_SPAR(DMA1, (n))
#define DMA2_SPAR(n)			DMA_SPAR(DMA2, (n))

#define DMA1_S0PAR			DMA1_SPAR(0U)
#define DMA1_S1PAR			DMA1_SPAR(1U)
#define DMA1_S2PAR			DMA1_SPAR(2U)
#define DMA1_S3PAR			DMA1_SPAR(3U)
#define DMA1_S4PAR			DMA1_SPAR(4U)
#define DMA1_S5PAR			DMA1_SPAR(5U)
#define DMA1_S6PAR			DMA1_SPAR(6U)
#define DMA1_S7PAR			DMA1_SPAR(7U)

#define DMA2_S0PAR			DMA2_SPAR(0U)
#define DMA2_S1PAR			DMA2_SPAR(1U)
#define DMA2_S2PAR			DMA2_SPAR(2U)
#define DMA2_S3PAR			DMA2_SPAR(3U)
#define DMA2_S4PAR			DMA2_SPAR(4U)
#define DMA2_S5PAR			DMA2_SPAR(5U)
#define DMA2_S6PAR			DMA2_SPAR(6U)
#define DMA2_S7PAR			DMA2_SPAR(7U)

/* DMA Stream x memory address 0 register (DMA_SxM0AR) */
#define DMA_SM0AR(port, n)		(*(volatile void **) \
					 (DMA_STREAM((port), (n)) + 0x0cU))
#define DMA1_SM0AR(n)			DMA_SM0AR(DMA1, (n))
#define DMA2_SM0AR(n)			DMA_SM0AR(DMA2, (n))

#define DMA1_S0M0AR			DMA1_SM0AR(0U)
#define DMA1_S1M0AR			DMA1_SM0AR(1U)
#define DMA1_S2M0AR			DMA1_SM0AR(2U)
#define DMA1_S3M0AR			DMA1_SM0AR(3U)
#define DMA1_S4M0AR			DMA1_SM0AR(4U)
#define DMA1_S5M0AR			DMA1_SM0AR(5U)
#define DMA1_S6M0AR			DMA1_SM0AR(6U)
#define DMA1_S7M0AR			DMA1_SM0AR(7U)

#define DMA2_S0M0AR			DMA2_SM0AR(0U)
#define DMA2_S1M0AR			DMA2_SM0AR(1U)
#define DMA2_S2M0AR			DMA2_SM0AR(2U)
#define DMA2_S3M0AR			DMA2_SM0AR(3U)
#define DMA2_S4M0AR			DMA2_SM0AR(4U)
#define DMA2_S5M0AR			DMA2_SM0AR(5U)
#define DMA2_S6M0AR			DMA2_SM0AR(6U)
#define DMA2_S7M0AR			DMA2_SM0AR(7U)

/* DMA Stream x memory address 1 register (DMA_SxM1AR) */
#define DMA_SM1AR(port, n)		(*(volatile void **)\
					 (DMA_STREAM((port), (n)) + 0x10U))
#define DMA1_SM1AR(n)			DMA_SM1AR(DMA1, (n))
#define DMA2_SM1AR(n)			DMA_SM1AR(DMA2, (n))

#define DMA1_S0M1AR			DMA1_SM1AR(0U)
#define DMA1_S1M1AR			DMA1_SM1AR(1U)
#define DMA1_S2M1AR			DMA1_SM1AR(2U)
#define DMA1_S3M1AR			DMA1_SM1AR(3U)
#define DMA1_S4M1AR			DMA1_SM1AR(4U)
#define DMA1_S5M1AR			DMA1_SM1AR(5U)
#define DMA1_S6M1AR			DMA1_SM1AR(6U)
#define DMA1_S7M1AR			DMA1_SM1AR(7U)

#define DMA2_S0M1AR			DMA2_SM1AR(0U)
#define DMA2_S1M1AR			DMA2_SM1AR(1U)
#define DMA2_S2M1AR			DMA2_SM1AR(2U)
#define DMA2_S3M1AR			DMA2_SM1AR(3U)
#define DMA2_S4M1AR			DMA2_SM1AR(4U)
#define DMA2_S5M1AR			DMA2_SM1AR(5U)
#define DMA2_S6M1AR			DMA2_SM1AR(6U)
#define DMA2_S7M1AR			DMA2_SM1AR(7U)

/* DMA Stream x FIFO control register (DMA_SxFCR) */
#define DMA_SFCR(port, n)		MMIO32(DMA_STREAM((port), (n)) + 0x14U)
#define DMA1_SFCR(n)			DMA_SFCR(DMA1, (n))
#define DMA2_SFCR(n)			DMA_SFCR(DMA2, (n))

#define DMA1_S0FCR			DMA1_SFCR(0U)
#define DMA1_S1FCR			DMA1_SFCR(1U)
#define DMA1_S2FCR			DMA1_SFCR(2U)
#define DMA1_S3FCR			DMA1_SFCR(3U)
#define DMA1_S4FCR			DMA1_SFCR(4U)
#define DMA1_S5FCR			DMA1_SFCR(5U)
#define DMA1_S6FCR			DMA1_SFCR(6U)
#define DMA1_S7FCR			DMA1_SFCR(7U)

#define DMA2_S0FCR			DMA2_SFCR(0U)
#define DMA2_S1FCR			DMA2_SFCR(1U)
#define DMA2_S2FCR			DMA2_SFCR(2U)
#define DMA2_S3FCR			DMA2_SFCR(3U)
#define DMA2_S4FCR			DMA2_SFCR(4U)
#define DMA2_S5FCR			DMA2_SFCR(5U)
#define DMA2_S6FCR			DMA2_SFCR(6U)
#define DMA2_S7FCR			DMA2_SFCR(7U)

/* --- DMA Interrupt Flag offset values ------------------------------------- */

/* For API parameters. These are based on every interrupt flag and flag clear
being at the same relative location */
/** @defgroup dma_if_offset DMA Interrupt Flag Offsets within stream flag group.
@ingroup dma_defines

@{*/
/** Transfer Complete Interrupt Flag */
#define DMA_TCIF		    (1U << 5U)
/** Half Transfer Interrupt Flag */
#define DMA_HTIF		    (1U << 4U)
/** Transfer Error Interrupt Flag */
#define DMA_TEIF		    (1U << 3U)
/** Direct Mode Error Interrupt Flag */
#define DMA_DMEIF		    (1U << 2U)
/** FIFO Error Interrupt Flag */
#define DMA_FEIF		    (1U << 0U)
/**@}*/

/* Offset within interrupt status register to start of stream interrupt flag
 * field
 */
#define DMA_ISR_OFFSET(stream)	(6U*((stream) & 0x01U)+16U*(((stream) & 0x02U) >> 1U))
#define DMA_ISR_FLAGS		(DMA_TCIF | DMA_HTIF | DMA_TEIF | DMA_DMEIF | \
				 DMA_FEIF)
#define DMA_ISR_MASK(stream)	(DMA_ISR_FLAGS << DMA_ISR_OFFSET(stream))

/* --- DMA_LISR values ----------------------------------------------------- */

#define DMA_LISR_FEIF0			(1U << 0U)
#define DMA_LISR_DMEIF0			(1U << 2U)
#define DMA_LISR_TEIF0			(1U << 3U)
#define DMA_LISR_HTIF0			(1U << 4U)
#define DMA_LISR_TCIF0			(1U << 5U)

#define DMA_LISR_FEIF1			(1U << 6U)
#define DMA_LISR_DMEIF1			(1U << 8U)
#define DMA_LISR_TEIF1			(1U << 9U)
#define DMA_LISR_HTIF1			(1U << 10U)
#define DMA_LISR_TCIF1			(1U << 11U)

#define DMA_LISR_FEIF2			(1U << 16U)
#define DMA_LISR_DMEIF2			(1U << 18U)
#define DMA_LISR_TEIF2			(1U << 19U)
#define DMA_LISR_HTIF2			(1U << 20U)
#define DMA_LISR_TCIF2			(1U << 21U)

#define DMA_LISR_FEIF3			(1U << 22U)
#define DMA_LISR_DMEIF3			(1U << 24U)
#define DMA_LISR_TEIF3			(1U << 25U)
#define DMA_LISR_HTIF3			(1U << 26U)
#define DMA_LISR_TCIF3			(1U << 27U)

/* --- DMA_HISR values ----------------------------------------------------- */

#define DMA_HISR_FEIF4			(1U << 0U)
#define DMA_HISR_DMEIF4			(1U << 2U)
#define DMA_HISR_TEIF4			(1U << 3U)
#define DMA_HISR_HTIF4			(1U << 4U)
#define DMA_HISR_TCIF4			(1U << 5U)

#define DMA_HISR_FEIF5			(1U << 6U)
#define DMA_HISR_DMEIF5			(1U << 8U)
#define DMA_HISR_TEIF5			(1U << 9U)
#define DMA_HISR_HTIF5			(1U << 10U)
#define DMA_HISR_TCIF5			(1U << 11U)

#define DMA_HISR_FEIF6			(1U << 16U)
#define DMA_HISR_DMEIF6			(1U << 18U)
#define DMA_HISR_TEIF6			(1U << 19U)
#define DMA_HISR_HTIF6			(1U << 20U)
#define DMA_HISR_TCIF6			(1U << 21U)

#define DMA_HISR_FEIF7			(1U << 22U)
#define DMA_HISR_DMEIF7			(1U << 24U)
#define DMA_HISR_TEIF7			(1U << 25U)
#define DMA_HISR_HTIF7			(1U << 26U)
#define DMA_HISR_TCIF7			(1U << 27U)

/* --- DMA_LIFCR values ----------------------------------------------------- */

#define DMA_LIFCR_CFEIF0		(1U << 0U)
#define DMA_LIFCR_CDMEIF0		(1U << 2U)
#define DMA_LIFCR_CTEIF0		(1U << 3U)
#define DMA_LIFCR_CHTIF0		(1U << 4U)
#define DMA_LIFCR_CTCIF0		(1U << 5U)

#define DMA_LIFCR_CFEIF1		(1U << 6U)
#define DMA_LIFCR_CDMEIF1		(1U << 8U)
#define DMA_LIFCR_CTEIF1		(1U << 9U)
#define DMA_LIFCR_CHTIF1		(1U << 10U)
#define DMA_LIFCR_CTCIF1		(1U << 11U)

#define DMA_LIFCR_CFEIF2		(1U << 16U)
#define DMA_LIFCR_CDMEIF2		(1U << 18U)
#define DMA_LIFCR_CTEIF2		(1U << 19U)
#define DMA_LIFCR_CHTIF2		(1U << 20U)
#define DMA_LIFCR_CTCIF2		(1U << 21U)

#define DMA_LIFCR_CFEIF3		(1U << 22U)
#define DMA_LIFCR_CDMEIF3		(1U << 24U)
#define DMA_LIFCR_CTEIF3		(1U << 25U)
#define DMA_LIFCR_CHTIF3		(1U << 26U)
#define DMA_LIFCR_CTCIF3		(1U << 27U)

/* --- DMA_HIFCR values ----------------------------------------------------- */

#define DMA_HIFCR_CFEIF4		(1U << 0U)
#define DMA_HIFCR_CDMEIF4		(1U << 2U)
#define DMA_HIFCR_CTEIF4		(1U << 3U)
#define DMA_HIFCR_CHTIF4		(1U << 4U)
#define DMA_HIFCR_CTCIF4		(1U << 5U)

#define DMA_HIFCR_CFEIF5		(1U << 6U)
#define DMA_HIFCR_CDMEIF5		(1U << 8U)
#define DMA_HIFCR_CTEIF5		(1U << 9U)
#define DMA_HIFCR_CHTIF5		(1U << 10U)
#define DMA_HIFCR_CTCIF5		(1U << 11U)

#define DMA_HIFCR_CFEIF6		(1U << 16U)
#define DMA_HIFCR_CDMEIF6		(1U << 18U)
#define DMA_HIFCR_CTEIF6		(1U << 19U)
#define DMA_HIFCR_CHTIF6		(1U << 20U)
#define DMA_HIFCR_CTCIF6		(1U << 21U)

#define DMA_HIFCR_CFEIF7		(1U << 22U)
#define DMA_HIFCR_CDMEIF7		(1U << 24U)
#define DMA_HIFCR_CTEIF7		(1U << 25U)
#define DMA_HIFCR_CHTIF7		(1U << 26U)
#define DMA_HIFCR_CTCIF7		(1U << 27U)

/* --- DMA_SxCR values ----------------------------------------------------- */

/* EN: Stream enable */
#define DMA_SxCR_EN			(1U << 0U)
/* DMEIE: Direct Mode error interrupt enable */
#define DMA_SxCR_DMEIE			(1U << 1U)
/* TEIE: Transfer error interrupt enable */
#define DMA_SxCR_TEIE			(1U << 2U)
/* HTIE: Half transfer interrupt enable */
#define DMA_SxCR_HTIE			(1U << 3U)
/* TCIE: Transfer complete interrupt enable */
#define DMA_SxCR_TCIE			(1U << 4U)
/* PFCTRL: Peripheral Flow Controller */
#define DMA_SxCR_PFCTRL			(1U << 5U)

/* DIR[7:6]: Data transfer direction */
/** @defgroup dma_st_dir DMA Stream Data transfer direction
@ingroup dma_defines

@{*/
#define DMA_SxCR_DIR_PERIPHERAL_TO_MEM	(0U << 6U)
#define DMA_SxCR_DIR_MEM_TO_PERIPHERAL	(1U << 6U)
#define DMA_SxCR_DIR_MEM_TO_MEM		(2U << 6U)
/**@}*/
#define DMA_SxCR_DIR_SHIFT		6U
#define DMA_SxCR_DIR_MASK		(3U << 6U)

/* CIRC: Circular mode */
#define DMA_SxCR_CIRC			(1U << 8U)
/* PINC: Peripheral increment mode */
#define DMA_SxCR_PINC			(1U << 9U)
/* MINC: Memory increment mode */
#define DMA_SxCR_MINC			(1U << 10U)

/* PSIZE[12:11]: Peripheral size */
/** @defgroup dma_st_perwidth DMA Stream Peripheral Word Width
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SxCR_PSIZE_8BIT		(0U << 11U)
#define DMA_SxCR_PSIZE_16BIT		(1U << 11U)
#define DMA_SxCR_PSIZE_32BIT		(2U << 11U)
/**@}*/
#define DMA_SxCR_PSIZE_SHIFT		11U
#define DMA_SxCR_PSIZE_MASK		(0x3U << 11U)

/* MSIZE[14:13]: Memory size */
/** @defgroup dma_st_memwidth DMA Stream Memory Word Width
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SxCR_MSIZE_8BIT		(0U << 13U)
#define DMA_SxCR_MSIZE_16BIT		(1U << 13U)
#define DMA_SxCR_MSIZE_32BIT		(2U << 13U)
/**@}*/
#define DMA_SxCR_MSIZE_SHIFT		13U
#define DMA_SxCR_MSIZE_MASK		(0x3U << 13U)

/* PINCOS: Peripheral increment offset size */
#define DMA_SxCR_PINCOS			(1U << 15U)

/* PL[17:16]: Stream priority level */
/** @defgroup dma_st_pri DMA Stream Priority Levels
@ingroup dma_defines

@{*/
#define DMA_SxCR_PL_LOW			(0U << 16U)
#define DMA_SxCR_PL_MEDIUM		(1U << 16U)
#define DMA_SxCR_PL_HIGH		(2U << 16U)
#define DMA_SxCR_PL_VERY_HIGH		(3U << 16U)
/**@}*/
#define DMA_SxCR_PL_SHIFT		16U
#define DMA_SxCR_PL_MASK		(0x3U << 16U)

/* DBM: Double buffered mode */
#define DMA_SxCR_DBM			(1U << 18U)
/* CT: Current target (in double buffered mode) */
#define DMA_SxCR_CT			(1U << 19U)

/* Bit 20 reserved */

/* PBURST[13:12]: Peripheral Burst Configuration */
/** @defgroup dma_pburst DMA Peripheral Burst Length
@ingroup dma_defines

@{*/
#define DMA_SxCR_PBURST_SINGLE		(0U << 21U)
#define DMA_SxCR_PBURST_INCR4		(1U << 21U)
#define DMA_SxCR_PBURST_INCR8		(2U << 21U)
#define DMA_SxCR_PBURST_INCR16		(3U << 21U)
/**@}*/
#define DMA_SxCR_PBURST_SHIFT		21U
#define DMA_SxCR_PBURST_MASK		(0x3U << 21U)

/* MBURST[13:12]: Memory Burst Configuration */
/** @defgroup dma_mburst DMA Memory Burst Length
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SxCR_MBURST_SINGLE		(0U << 23U)
#define DMA_SxCR_MBURST_INCR4		(1U << 23U)
#define DMA_SxCR_MBURST_INCR8		(2U << 23U)
#define DMA_SxCR_MBURST_INCR16		(3U << 23U)
/**@}*/
#define DMA_SxCR_MBURST_SHIFT		23U
#define DMA_SxCR_MBURST_MASK		(0x3U << 23U)

/* CHSEL[25:27]: Channel Select */
/** @defgroup dma_ch_sel DMA Channel Select
@ingroup dma_defines

@{*/
#define DMA_SxCR_CHSEL_0		(0U << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_1		(1U << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_2		(2U << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_3		(3U << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_4		(4U << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_5		(5U << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_6		(6U << DMA_SxCR_CHSEL_SHIFT)
#define DMA_SxCR_CHSEL_7		(7U << DMA_SxCR_CHSEL_SHIFT)
/**@}*/
#define DMA_SxCR_CHSEL_SHIFT		25U
#define DMA_SxCR_CHSEL_MASK		(0x7U << 25U)
#define DMA_SxCR_CHSEL(n)		((n) << DMA_SxCR_CHSEL_SHIFT)

/* Reserved [31:28] */

/* --- DMA_SxNDTR values --------------------------------------------------- */

/* DMA_SxNDTR[15:0]: Number of data register. */

/* --- DMA_SxPAR values ---------------------------------------------------- */

/* DMA_SxPAR[31:0]: Peripheral address register. */

/* --- DMA_SxM0AR values --------------------------------------------------- */

/* DMA_SxM0AR[31:0]: Memory 0 address register. */

/* --- DMA_SxM1AR values --------------------------------------------------- */

/* DMA_SxM1AR[31:0]: Memory 1 address register. */

/* --- DMA_SxFCR values ---------------------------------------------------- */

/* FTH[1:0]: FIFO Threshold selection */
/** @defgroup dma_fifo_thresh FIFO Threshold selection
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SxFCR_FTH_1_4_FULL		(0U << 0U)
#define DMA_SxFCR_FTH_2_4_FULL		(1U << 0U)
#define DMA_SxFCR_FTH_3_4_FULL		(2U << 0U)
#define DMA_SxFCR_FTH_4_4_FULL		(3U << 0U)
/**@}*/
#define DMA_SxFCR_FTH_SHIFT		0U
#define DMA_SxFCR_FTH_MASK		(0x3U << 0U)

/* DMDIS: Direct Mode disable */
#define DMA_SxFCR_DMDIS			(1U << 2U)

/* FS[5:3]: FIFO Status */
/** @defgroup dma_fifo_status FIFO Status
@ingroup STM32F4xx_dma_defines

@{*/
#define DMA_SxFCR_FS_LT_1_4_FULL	(0U << 0U)
#define DMA_SxFCR_FS_LT_2_4_FULL	(1U << 0U)
#define DMA_SxFCR_FS_LT_3_4_FULL	(2U << 0U)
#define DMA_SxFCR_FS_LT_4_4_FULL	(3U << 0U)
#define DMA_SxFCR_FS_FULL		(4U << 3U)
#define DMA_SxFCR_FS_EMPTY		(5U << 3U)
/**@}*/
#define DMA_SxFCR_FS_SHIFT		3U
#define DMA_SxFCR_FS_MASK		(0x7U << 3U)

/* [6]: reserved */

/* FEIE[7]: FIFO error interrupt enable */
#define DMA_SxFCR_FEIE			(1U << 7U)

/* [31:8]: Reserved */

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

/*
 * Note: The F2 and F4 series have a completely new DMA peripheral with
 * different configuration options.
 */

void dma_stream_reset(uint32_t dma, uint8_t stream);
void dma_clear_interrupt_flags(uint32_t dma, uint8_t stream,
			       uint32_t interrupts);
bool dma_get_interrupt_flag(uint32_t dma, uint8_t stream, uint32_t interrupt);
void dma_set_transfer_mode(uint32_t dma, uint8_t stream, uint32_t direction);
void dma_set_priority(uint32_t dma, uint8_t stream, uint32_t prio);
void dma_set_memory_size(uint32_t dma, uint8_t stream, uint32_t mem_size);
void dma_set_peripheral_size(uint32_t dma, uint8_t stream,
			     uint32_t peripheral_size);
void dma_enable_memory_increment_mode(uint32_t dma, uint8_t stream);
void dma_disable_memory_increment_mode(uint32_t dma, uint8_t stream);
void dma_enable_peripheral_increment_mode(uint32_t dma, uint8_t stream);
void dma_disable_peripheral_increment_mode(uint32_t dma, uint8_t stream);
void dma_enable_fixed_peripheral_increment_mode(uint32_t dma, uint8_t stream);
void dma_enable_circular_mode(uint32_t dma, uint8_t stream);
void dma_channel_select(uint32_t dma, uint8_t stream, uint32_t channel);
void dma_set_memory_burst(uint32_t dma, uint8_t stream, uint32_t burst);
void dma_set_peripheral_burst(uint32_t dma, uint8_t stream, uint32_t burst);
void dma_set_initial_target(uint32_t dma, uint8_t stream, uint8_t memory);
uint8_t dma_get_target(uint32_t dma, uint8_t stream);
void dma_enable_double_buffer_mode(uint32_t dma, uint8_t stream);
void dma_disable_double_buffer_mode(uint32_t dma, uint8_t stream);
void dma_set_peripheral_flow_control(uint32_t dma, uint8_t stream);
void dma_set_dma_flow_control(uint32_t dma, uint8_t stream);
void dma_enable_transfer_error_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_transfer_error_interrupt(uint32_t dma, uint8_t stream);
void dma_enable_half_transfer_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_half_transfer_interrupt(uint32_t dma, uint8_t stream);
void dma_enable_transfer_complete_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_transfer_complete_interrupt(uint32_t dma, uint8_t stream);
uint32_t dma_fifo_status(uint32_t dma, uint8_t stream);
void dma_enable_direct_mode_error_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_direct_mode_error_interrupt(uint32_t dma, uint8_t stream);
void dma_enable_fifo_error_interrupt(uint32_t dma, uint8_t stream);
void dma_disable_fifo_error_interrupt(uint32_t dma, uint8_t stream);
void dma_enable_direct_mode(uint32_t dma, uint8_t stream);
void dma_enable_fifo_mode(uint32_t dma, uint8_t stream);
void dma_set_fifo_threshold(uint32_t dma, uint8_t stream, uint32_t threshold);
void dma_enable_stream(uint32_t dma, uint8_t stream);
void dma_disable_stream(uint32_t dma, uint8_t stream);
void dma_set_peripheral_address(uint32_t dma, uint8_t stream, uint32_t address);
void dma_set_memory_address(uint32_t dma, uint8_t stream, uint32_t address);
void dma_set_memory_address_1(uint32_t dma, uint8_t stream, uint32_t address);
uint16_t dma_get_number_of_data(uint32_t dma, uint8_t stream);
void dma_set_number_of_data(uint32_t dma, uint8_t stream, uint16_t number);

END_DECLS
/**@}*/
#endif
/** @cond */
#else
#warning "dma_common_f24.h should not be included explicitly, only via dma.h"
#endif
/** @endcond */

