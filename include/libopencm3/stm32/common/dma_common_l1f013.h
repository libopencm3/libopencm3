/** @addtogroup dma_defines

@author @htmlonly &copy; @endhtmlonly 2010
Thomas Otto <tommi@viadmin.org>
@author @htmlonly &copy; @endhtmlonly 2012
Piotr Esden-Tempski <piotr@esden.net>

*/

/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 * Copyright (C) 2012 Piotr Esden-Tempski <piotr@esden.net>
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

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA DMA.H
The order of header inclusion is important. dma.h includes the device
specific memorymap.h header before including this header file.*/

/** @cond */
#ifdef LIBOPENCM3_DMA_H
/** @endcond */
#ifndef LIBOPENCM3_DMA_COMMON_F13_H
#define LIBOPENCM3_DMA_COMMON_F13_H

/* --- Convenience macros -------------------------------------------------- */

/* DMA register base adresses (for convenience) */
#define DMA1				DMA1_BASE
#define DMA2				DMA2_BASE

/* --- DMA registers ------------------------------------------------------- */

/* DMA interrupt status register (DMAx_ISR) */
#define DMA_ISR(dma_base)		MMIO32((dma_base) + 0x00)
#define DMA1_ISR			DMA_ISR(DMA1)
#define DMA2_ISR			DMA_ISR(DMA2)

/* DMA interrupt flag clear register (DMAx_IFCR) */
#define DMA_IFCR(dma_base)		MMIO32((dma_base) + 0x04)
#define DMA1_IFCR			DMA_IFCR(DMA1)
#define DMA2_IFCR			DMA_IFCR(DMA2)

/* DMA channel configuration register (DMAx_CCRy) */
#define DMA_CCR(dma_base, channel)	MMIO32((dma_base) + 0x08 + \
					       (0x14 * ((channel) - 1)))

#define DMA1_CCR(channel)		DMA_CCR(DMA1, channel)
#define DMA1_CCR1			DMA1_CCR(DMA_CHANNEL1)
#define DMA1_CCR2			DMA1_CCR(DMA_CHANNEL2)
#define DMA1_CCR3			DMA1_CCR(DMA_CHANNEL3)
#define DMA1_CCR4			DMA1_CCR(DMA_CHANNEL4)
#define DMA1_CCR5			DMA1_CCR(DMA_CHANNEL5)
#define DMA1_CCR6			DMA1_CCR(DMA_CHANNEL6)
#define DMA1_CCR7			DMA1_CCR(DMA_CHANNEL7)

#define DMA2_CCR(channel)		DMA_CCR(DMA2, channel)
#define DMA2_CCR1			DMA2_CCR(DMA_CHANNEL1)
#define DMA2_CCR2			DMA2_CCR(DMA_CHANNEL2)
#define DMA2_CCR3			DMA2_CCR(DMA_CHANNEL3)
#define DMA2_CCR4			DMA2_CCR(DMA_CHANNEL4)
#define DMA2_CCR5			DMA2_CCR(DMA_CHANNEL5)

/* DMA number of data register (DMAx_CNDTRy) */
#define DMA_CNDTR(dma_base, channel)	MMIO32((dma_base) + 0x0C + \
					       (0x14 * ((channel) - 1)))

#define DMA1_CNDTR(channel)		DMA_CNDTR(DMA1, channel)
#define DMA1_CNDTR1			DMA1_CNDTR(DMA_CHANNEL1)
#define DMA1_CNDTR2			DMA1_CNDTR(DMA_CHANNEL2)
#define DMA1_CNDTR3			DMA1_CNDTR(DMA_CHANNEL3)
#define DMA1_CNDTR4			DMA1_CNDTR(DMA_CHANNEL4)
#define DMA1_CNDTR5			DMA1_CNDTR(DMA_CHANNEL5)
#define DMA1_CNDTR6			DMA1_CNDTR(DMA_CHANNEL6)
#define DMA1_CNDTR7			DMA1_CNDTR(DMA_CHANNEL7)

#define DMA2_CNDTR(channel)		DMA_CNDTR(DMA2, channel)
#define DMA2_CNDTR1			DMA2_CNDTR(DMA_CHANNEL1)
#define DMA2_CNDTR2			DMA2_CNDTR(DMA_CHANNEL2)
#define DMA2_CNDTR3			DMA2_CNDTR(DMA_CHANNEL3)
#define DMA2_CNDTR4			DMA2_CNDTR(DMA_CHANNEL4)
#define DMA2_CNDTR5			DMA2_CNDTR(DMA_CHANNEL5)

/* DMA peripheral address register (DMAx_CPARy) */
#define DMA_CPAR(dma_base, channel)	MMIO32((dma_base) + 0x10 + \
					       (0x14 * ((channel) - 1)))

#define DMA1_CPAR(channel)		DMA_CPAR(DMA1, channel)
#define DMA1_CPAR1			DMA1_CPAR(DMA_CHANNEL1)
#define DMA1_CPAR2			DMA1_CPAR(DMA_CHANNEL2)
#define DMA1_CPAR3			DMA1_CPAR(DMA_CHANNEL3)
#define DMA1_CPAR4			DMA1_CPAR(DMA_CHANNEL4)
#define DMA1_CPAR5			DMA1_CPAR(DMA_CHANNEL5)
#define DMA1_CPAR6			DMA1_CPAR(DMA_CHANNEL6)
#define DMA1_CPAR7			DMA1_CPAR(DMA_CHANNEL7)

#define DMA2_CPAR(channel)		DMA_CPAR(DMA2, channel)
#define DMA2_CPAR1			DMA2_CPAR(DMA_CHANNEL1)
#define DMA2_CPAR2			DMA2_CPAR(DMA_CHANNEL2)
#define DMA2_CPAR3			DMA2_CPAR(DMA_CHANNEL3)
#define DMA2_CPAR4			DMA2_CPAR(DMA_CHANNEL4)
#define DMA2_CPAR5			DMA2_CPAR(DMA_CHANNEL5)

/* DMA memory address register (DMAx_CMARy) */

#define DMA_CMAR(dma_base, channel)	MMIO32((dma_base) + 0x14 + \
					       (0x14 * ((channel) - 1)))

#define DMA1_CMAR(channel)		DMA_CMAR(DMA1, channel)
#define DMA1_CMAR1			DMA1_CMAR(DMA_CHANNEL1)
#define DMA1_CMAR2			DMA1_CMAR(DMA_CHANNEL2)
#define DMA1_CMAR3			DMA1_CMAR(DMA_CHANNEL3)
#define DMA1_CMAR4			DMA1_CMAR(DMA_CHANNEL4)
#define DMA1_CMAR5			DMA1_CMAR(DMA_CHANNEL5)
#define DMA1_CMAR6			DMA1_CMAR(DMA_CHANNEL6)
#define DMA1_CMAR7			DMA1_CMAR(DMA_CHANNEL7)

#define DMA2_CMAR(channel)		DMA_CMAR(DMA2, channel)
#define DMA2_CMAR1			DMA2_CMAR(DMA_CHANNEL1)
#define DMA2_CMAR2			DMA2_CMAR(DMA_CHANNEL2)
#define DMA2_CMAR3			DMA2_CMAR(DMA_CHANNEL3)
#define DMA2_CMAR4			DMA2_CMAR(DMA_CHANNEL4)
#define DMA2_CMAR5			DMA2_CMAR(DMA_CHANNEL5)

/* --- DMA_ISR values ------------------------------------------------------ */

/* --- DMA Interrupt Flag offset values ------------------------------------- */
/* These are based on every interrupt flag and flag clear being at the same
 * relative location
 */
/** @defgroup dma_if_offset DMA Interrupt Flag Offsets within channel flag
group.
@ingroup dma_defines

@{*/
/** Transfer Error Interrupt Flag */
#define DMA_TEIF		(1 << 3)
/** Half Transfer Interrupt Flag */
#define DMA_HTIF		(1 << 2)
/** Transfer Complete Interrupt Flag */
#define DMA_TCIF		(1 << 1)
/** Global Interrupt Flag */
#define DMA_GIF			(1 << 0)
/**@}*/

/* Offset within interrupt status register to start of channel interrupt flag
 * field
 */
#define DMA_FLAG_OFFSET(channel)	(4*((channel) - 1))
#define DMA_FLAGS			(DMA_TEIF | DMA_TCIF | DMA_HTIF | \
					 DMA_GIF)
#define DMA_ISR_MASK(channel)		(DMA_FLAGS << DMA_FLAG_OFFSET(channel))

/* TEIF: Transfer error interrupt flag */
#define DMA_ISR_TEIF_BIT		DMA_TEIF
#define DMA_ISR_TEIF(channel)		(DMA_ISR_TEIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_ISR_TEIF1			DMA_ISR_TEIF(DMA_CHANNEL1)
#define DMA_ISR_TEIF2			DMA_ISR_TEIF(DMA_CHANNEL2)
#define DMA_ISR_TEIF3			DMA_ISR_TEIF(DMA_CHANNEL3)
#define DMA_ISR_TEIF4			DMA_ISR_TEIF(DMA_CHANNEL4)
#define DMA_ISR_TEIF5			DMA_ISR_TEIF(DMA_CHANNEL5)
#define DMA_ISR_TEIF6			DMA_ISR_TEIF(DMA_CHANNEL6)
#define DMA_ISR_TEIF7			DMA_ISR_TEIF(DMA_CHANNEL7)

/* HTIF: Half transfer interrupt flag */
#define DMA_ISR_HTIF_BIT		DMA_HTIF
#define DMA_ISR_HTIF(channel)		(DMA_ISR_HTIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_ISR_HTIF1			DMA_ISR_HTIF(DMA_CHANNEL1)
#define DMA_ISR_HTIF2			DMA_ISR_HTIF(DMA_CHANNEL2)
#define DMA_ISR_HTIF3			DMA_ISR_HTIF(DMA_CHANNEL3)
#define DMA_ISR_HTIF4			DMA_ISR_HTIF(DMA_CHANNEL4)
#define DMA_ISR_HTIF5			DMA_ISR_HTIF(DMA_CHANNEL5)
#define DMA_ISR_HTIF6			DMA_ISR_HTIF(DMA_CHANNEL6)
#define DMA_ISR_HTIF7			DMA_ISR_HTIF(DMA_CHANNEL7)

/* TCIF: Transfer complete interrupt flag */
#define DMA_ISR_TCIF_BIT		DMA_TCIF
#define DMA_ISR_TCIF(channel)		(DMA_ISR_TCIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_ISR_TCIF1			DMA_ISR_TCIF(DMA_CHANNEL1)
#define DMA_ISR_TCIF2			DMA_ISR_TCIF(DMA_CHANNEL2)
#define DMA_ISR_TCIF3			DMA_ISR_TCIF(DMA_CHANNEL3)
#define DMA_ISR_TCIF4			DMA_ISR_TCIF(DMA_CHANNEL4)
#define DMA_ISR_TCIF5			DMA_ISR_TCIF(DMA_CHANNEL5)
#define DMA_ISR_TCIF6			DMA_ISR_TCIF(DMA_CHANNEL6)
#define DMA_ISR_TCIF7			DMA_ISR_TCIF(DMA_CHANNEL7)

/* GIF: Global interrupt flag */
#define DMA_ISR_GIF_BIT			DMA_GIF
#define DMA_ISR_GIF(channel)		(DMA_ISR_GIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_ISR_GIF1			DMA_ISR_GIF(DMA_CHANNEL1)
#define DMA_ISR_GIF2			DMA_ISR_GIF(DMA_CHANNEL2)
#define DMA_ISR_GIF3			DMA_ISR_GIF(DMA_CHANNEL3)
#define DMA_ISR_GIF4			DMA_ISR_GIF(DMA_CHANNEL4)
#define DMA_ISR_GIF5			DMA_ISR_GIF(DMA_CHANNEL5)
#define DMA_ISR_GIF6			DMA_ISR_GIF(DMA_CHANNEL6)
#define DMA_ISR_GIF7			DMA_ISR_GIF(DMA_CHANNEL7)

/* --- DMA_IFCR values ----------------------------------------------------- */

/* CTEIF: Transfer error clear */
#define DMA_IFCR_CTEIF_BIT		DMA_TEIF
#define DMA_IFCR_CTEIF(channel)		(DMA_IFCR_CTEIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_IFCR_CTEIF1			DMA_IFCR_CTEIF(DMA_CHANNEL1)
#define DMA_IFCR_CTEIF2			DMA_IFCR_CTEIF(DMA_CHANNEL2)
#define DMA_IFCR_CTEIF3			DMA_IFCR_CTEIF(DMA_CHANNEL3)
#define DMA_IFCR_CTEIF4			DMA_IFCR_CTEIF(DMA_CHANNEL4)
#define DMA_IFCR_CTEIF5			DMA_IFCR_CTEIF(DMA_CHANNEL5)
#define DMA_IFCR_CTEIF6			DMA_IFCR_CTEIF(DMA_CHANNEL6)
#define DMA_IFCR_CTEIF7			DMA_IFCR_CTEIF(DMA_CHANNEL7)

/* CHTIF: Half transfer clear */
#define DMA_IFCR_CHTIF_BIT		DMA_HTIF
#define DMA_IFCR_CHTIF(channel)		(DMA_IFCR_CHTIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_IFCR_CHTIF1			DMA_IFCR_CHTIF(DMA_CHANNEL1)
#define DMA_IFCR_CHTIF2			DMA_IFCR_CHTIF(DMA_CHANNEL2)
#define DMA_IFCR_CHTIF3			DMA_IFCR_CHTIF(DMA_CHANNEL3)
#define DMA_IFCR_CHTIF4			DMA_IFCR_CHTIF(DMA_CHANNEL4)
#define DMA_IFCR_CHTIF5			DMA_IFCR_CHTIF(DMA_CHANNEL5)
#define DMA_IFCR_CHTIF6			DMA_IFCR_CHTIF(DMA_CHANNEL6)
#define DMA_IFCR_CHTIF7			DMA_IFCR_CHTIF(DMA_CHANNEL7)

/* CTCIF: Transfer complete clear */
#define DMA_IFCR_CTCIF_BIT		DMA_TCIF
#define DMA_IFCR_CTCIF(channel)		(DMA_IFCR_CTCIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_IFCR_CTCIF1			DMA_IFCR_CTCIF(DMA_CHANNEL1)
#define DMA_IFCR_CTCIF2			DMA_IFCR_CTCIF(DMA_CHANNEL2)
#define DMA_IFCR_CTCIF3			DMA_IFCR_CTCIF(DMA_CHANNEL3)
#define DMA_IFCR_CTCIF4			DMA_IFCR_CTCIF(DMA_CHANNEL4)
#define DMA_IFCR_CTCIF5			DMA_IFCR_CTCIF(DMA_CHANNEL5)
#define DMA_IFCR_CTCIF6			DMA_IFCR_CTCIF(DMA_CHANNEL6)
#define DMA_IFCR_CTCIF7			DMA_IFCR_CTCIF(DMA_CHANNEL7)

/* CGIF: Global interrupt clear */
#define DMA_IFCR_CGIF_BIT		DMA_GIF
#define DMA_IFCR_CGIF(channel)		(DMA_IFCR_CGIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_IFCR_CGIF1			DMA_IFCR_CGIF(DMA_CHANNEL1)
#define DMA_IFCR_CGIF2			DMA_IFCR_CGIF(DMA_CHANNEL2)
#define DMA_IFCR_CGIF3			DMA_IFCR_CGIF(DMA_CHANNEL3)
#define DMA_IFCR_CGIF4			DMA_IFCR_CGIF(DMA_CHANNEL4)
#define DMA_IFCR_CGIF5			DMA_IFCR_CGIF(DMA_CHANNEL5)
#define DMA_IFCR_CGIF6			DMA_IFCR_CGIF(DMA_CHANNEL6)
#define DMA_IFCR_CGIF7			DMA_IFCR_CGIF(DMA_CHANNEL7)

/* Clear interrupts mask */
#define DMA_IFCR_CIF_BIT		0xF
#define DMA_IFCR_CIF(channel)		(DMA_IFCR_CIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_IFCR_CIF1			DMA_IFCR_CIF(DMA_CHANNEL1)
#define DMA_IFCR_CIF2			DMA_IFCR_CIF(DMA_CHANNEL2)
#define DMA_IFCR_CIF3			DMA_IFCR_CIF(DMA_CHANNEL3)
#define DMA_IFCR_CIF4			DMA_IFCR_CIF(DMA_CHANNEL4)
#define DMA_IFCR_CIF5			DMA_IFCR_CIF(DMA_CHANNEL5)
#define DMA_IFCR_CIF6			DMA_IFCR_CIF(DMA_CHANNEL6)
#define DMA_IFCR_CIF7			DMA_IFCR_CIF(DMA_CHANNEL7)

/* --- DMA_CCRx generic values --------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CCR_MEM2MEM			(1 << 14)

/* PL[13:12]: Channel priority level */
/** @defgroup dma_ch_pri DMA Channel Priority Levels
@ingroup dma_defines

@{*/
#define DMA_CCR_PL_LOW			(0x0 << 12)
#define DMA_CCR_PL_MEDIUM		(0x1 << 12)
#define DMA_CCR_PL_HIGH			(0x2 << 12)
#define DMA_CCR_PL_VERY_HIGH		(0x3 << 12)
/**@}*/
#define DMA_CCR_PL_MASK			(0x3 << 12)
#define DMA_CCR_PL_SHIFT		12

/* MSIZE[11:10]: Memory size */
/** @defgroup dma_ch_memwidth DMA Channel Memory Word Width
@ingroup dma_defines

@{*/
#define DMA_CCR_MSIZE_8BIT		(0x0 << 10)
#define DMA_CCR_MSIZE_16BIT		(0x1 << 10)
#define DMA_CCR_MSIZE_32BIT		(0x2 << 10)
/**@}*/
#define DMA_CCR_MSIZE_MASK		(0x3 << 10)
#define DMA_CCR_MSIZE_SHIFT		10

/* PSIZE[9:8]: Peripheral size */
/** @defgroup dma_ch_perwidth DMA Channel Peripheral Word Width
@ingroup dma_defines

@{*/
#define DMA_CCR_PSIZE_8BIT		(0x0 << 8)
#define DMA_CCR_PSIZE_16BIT		(0x1 << 8)
#define DMA_CCR_PSIZE_32BIT		(0x2 << 8)
/**@}*/
#define DMA_CCR_PSIZE_MASK		(0x3 << 8)
#define DMA_CCR_PSIZE_SHIFT		8

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

/** @defgroup dma_ch DMA Channel Number
@ingroup dma_defines

@{*/
#define DMA_CHANNEL1			1
#define DMA_CHANNEL2			2
#define DMA_CHANNEL3			3
#define DMA_CHANNEL4			4
#define DMA_CHANNEL5			5
#define DMA_CHANNEL6			6
#define DMA_CHANNEL7			7
/**@}*/

/* --- function prototypes ------------------------------------------------- */

BEGIN_DECLS

void dma_channel_reset(uint32_t dma, uint8_t channel);
void dma_clear_interrupt_flags(uint32_t dma, uint8_t channel,
			       uint32_t interrupts);
bool dma_get_interrupt_flag(uint32_t dma, uint8_t channel, uint32_t interrupts);
void dma_enable_mem2mem_mode(uint32_t dma, uint8_t channel);
void dma_set_priority(uint32_t dma, uint8_t channel, uint32_t prio);
void dma_set_memory_size(uint32_t dma, uint8_t channel, uint32_t mem_size);
void dma_set_peripheral_size(uint32_t dma, uint8_t channel,
			     uint32_t peripheral_size);
void dma_enable_memory_increment_mode(uint32_t dma, uint8_t channel);
void dma_disable_memory_increment_mode(uint32_t dma, uint8_t channel);
void dma_enable_peripheral_increment_mode(uint32_t dma, uint8_t channel);
void dma_disable_peripheral_increment_mode(uint32_t dma, uint8_t channel);
void dma_enable_circular_mode(uint32_t dma, uint8_t channel);
void dma_set_read_from_peripheral(uint32_t dma, uint8_t channel);
void dma_set_read_from_memory(uint32_t dma, uint8_t channel);
void dma_enable_transfer_error_interrupt(uint32_t dma, uint8_t channel);
void dma_disable_transfer_error_interrupt(uint32_t dma, uint8_t channel);
void dma_enable_half_transfer_interrupt(uint32_t dma, uint8_t channel);
void dma_disable_half_transfer_interrupt(uint32_t dma, uint8_t channel);
void dma_enable_transfer_complete_interrupt(uint32_t dma, uint8_t channel);
void dma_disable_transfer_complete_interrupt(uint32_t dma, uint8_t channel);
void dma_enable_channel(uint32_t dma, uint8_t channel);
void dma_disable_channel(uint32_t dma, uint8_t channel);
void dma_set_peripheral_address(uint32_t dma, uint8_t channel,
				uint32_t address);
void dma_set_memory_address(uint32_t dma, uint8_t channel, uint32_t address);
uint16_t dma_get_number_of_data(uint32_t dma, uint8_t channel);
void dma_set_number_of_data(uint32_t dma, uint8_t channel, uint16_t number);

END_DECLS

#endif
/** @cond */
#else
#warning "dma_common_f13.h should not be included explicitly, only via dma.h"
#endif
/** @endcond */

/**@}*/

