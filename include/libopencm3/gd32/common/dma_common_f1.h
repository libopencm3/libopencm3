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
#define DMA0				DMA0_BASE

/* --- DMA registers ------------------------------------------------------- */

/* DMA interrupt status register (DMAx_INTF) */
#define DMA_INTF(dma_base)		MMIO32((dma_base) + 0x00)
#define DMA0_INTF			DMA_INTF(DMA0)

/* DMA interrupt flag clear register (DMAx_INTC) */
#define DMA_INTC(dma_base)		MMIO32((dma_base) + 0x04)
#define DMA0_INTC			DMA_INTC(DMA0)

/* DMA channel configuration register (DMAx_CHyCTL) */
#define DMA_CTL(dma_base, channel)	MMIO32((dma_base) + 0x08 + \
					       (0x14 * (channel)))

#define DMA0_CTL(channel)		DMA_CTL(DMA0, channel)
#define DMA0_CTL1			DMA0_CTL(DMA_CHANNEL1)
#define DMA0_CTL2			DMA0_CTL(DMA_CHANNEL2)
#define DMA0_CTL3			DMA0_CTL(DMA_CHANNEL3)
#define DMA0_CTL4			DMA0_CTL(DMA_CHANNEL4)
#define DMA0_CTL5			DMA0_CTL(DMA_CHANNEL5)
#define DMA0_CTL6			DMA0_CTL(DMA_CHANNEL6)
#define DMA0_CTL7			DMA0_CTL(DMA_CHANNEL7)

/* DMA number of data register (DMAx_CHyCNT) */
#define DMA_CNT(dma_base, channel)	MMIO32((dma_base) + 0x0C + \
					       (0x14 * (channel)))

#define DMA0_CNT(channel)		DMA_CNT(DMA0, channel)
#define DMA0_CNT1			DMA0_CNT(DMA_CHANNEL1)
#define DMA0_CNT2			DMA0_CNT(DMA_CHANNEL2)
#define DMA0_CNT3			DMA0_CNT(DMA_CHANNEL3)
#define DMA0_CNT4			DMA0_CNT(DMA_CHANNEL4)
#define DMA0_CNT5			DMA0_CNT(DMA_CHANNEL5)
#define DMA0_CNT6			DMA0_CNT(DMA_CHANNEL6)
#define DMA0_CNT7			DMA0_CNT(DMA_CHANNEL7)

/* DMA peripheral address register (DMAx_CHyPADDR) */
#define DMA_PADDR(dma_base, channel)	MMIO32((dma_base) + 0x10 + \
					       (0x14 * (channel)))

#define DMA0_PADDR(channel)		DMA_PADDR(DMA0, channel)
#define DMA0_PADDR1			DMA0_PADDR(DMA_CHANNEL1)
#define DMA0_PADDR2			DMA0_PADDR(DMA_CHANNEL2)
#define DMA0_PADDR3			DMA0_PADDR(DMA_CHANNEL3)
#define DMA0_PADDR4			DMA0_PADDR(DMA_CHANNEL4)
#define DMA0_PADDR5			DMA0_PADDR(DMA_CHANNEL5)
#define DMA0_PADDR6			DMA0_PADDR(DMA_CHANNEL6)
#define DMA0_PADDR7			DMA0_PADDR(DMA_CHANNEL7)

/* DMA memory address register (DMAx_CHyMADDR) */
#define DMA_MADDR(dma_base, channel)	MMIO32((dma_base) + 0x14 + \
					       (0x14 * (channel)))

#define DMA0_MADDR(channel)		DMA_MADDR(DMA0, channel)
#define DMA0_MADDR1			DMA0_MADDR(DMA_CHANNEL1)
#define DMA0_MADDR2			DMA0_MADDR(DMA_CHANNEL2)
#define DMA0_MADDR3			DMA0_MADDR(DMA_CHANNEL3)
#define DMA0_MADDR4			DMA0_MADDR(DMA_CHANNEL4)
#define DMA0_MADDR5			DMA0_MADDR(DMA_CHANNEL5)
#define DMA0_MADDR6			DMA0_MADDR(DMA_CHANNEL6)
#define DMA0_MADDR7			DMA0_MADDR(DMA_CHANNEL7)

/* --- DMA_INTF values ------------------------------------------------------ */

/* --- DMA Interrupt Flag offset values ------------------------------------- */
/* These are based on every interrupt flag and flag clear being at the same
 * relative location
 */
/** @defgroup dma_if_offset DMA Interrupt Flag Offsets within channel flag
group.
@ingroup dma_defines

@{*/
/** Error Interrupt Flag */
#define DMA_ERRIF		(1 << 3)
/** Half Transfer Interrupt Flag */
#define DMA_HTFIF		(1 << 2)
/** Full Transfer Interrupt Flag */
#define DMA_FTFIF		(1 << 1)
/** Global Interrupt Flag */
#define DMA_GIF			(1 << 0)
/**@}*/

/* Offset within interrupt status register to start of channel interrupt flag
 * field
 */
#define DMA_FLAG_OFFSET(channel)	(4*(channel))
#define DMA_FLAGS			(DMA_ERRIF | DMA_FTFIF | DMA_HTFIF | \
					 DMA_GIF)
#define DMA_ISR_MASK(channel)		(DMA_FLAGS << DMA_FLAG_OFFSET(channel))

/* ERRIF: Error interrupt flag */
#define DMA_INTF_ERRIF_BIT		DMA_ERRIF
#define DMA_INTF_ERRIF(channel)		(DMA_INTF_ERRIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_INTF_ERRIF1			DMA_INTF_ERRIF(DMA_CHANNEL1)
#define DMA_INTF_ERRIF2			DMA_INTF_ERRIF(DMA_CHANNEL2)
#define DMA_INTF_ERRIF3			DMA_INTF_ERRIF(DMA_CHANNEL3)
#define DMA_INTF_ERRIF4			DMA_INTF_ERRIF(DMA_CHANNEL4)
#define DMA_INTF_ERRIF5			DMA_INTF_ERRIF(DMA_CHANNEL5)
#define DMA_INTF_ERRIF6			DMA_INTF_ERRIF(DMA_CHANNEL6)
#define DMA_INTF_ERRIF7			DMA_INTF_ERRIF(DMA_CHANNEL7)

/* HTFIF: Half transfer interrupt flag */
#define DMA_INTF_HTFIF_BIT		DMA_HTFIF
#define DMA_INTF_HTFIF(channel)		(DMA_INTF_HTFIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_INTF_HTFIF1			DMA_INTF_HTFIF(DMA_CHANNEL1)
#define DMA_INTF_HTFIF2			DMA_INTF_HTFIF(DMA_CHANNEL2)
#define DMA_INTF_HTFIF3			DMA_INTF_HTFIF(DMA_CHANNEL3)
#define DMA_INTF_HTFIF4			DMA_INTF_HTFIF(DMA_CHANNEL4)
#define DMA_INTF_HTFIF5			DMA_INTF_HTFIF(DMA_CHANNEL5)
#define DMA_INTF_HTFIF6			DMA_INTF_HTFIF(DMA_CHANNEL6)
#define DMA_INTF_HTFIF7			DMA_INTF_HTFIF(DMA_CHANNEL7)

/* FTFIF: Transfer complete interrupt flag */
#define DMA_INTF_FTFIF_BIT		DMA_FTFIF
#define DMA_INTF_FTFIF(channel)		(DMA_INTF_FTFIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_INTF_FTFIF1			DMA_INTF_FTFIF(DMA_CHANNEL1)
#define DMA_INTF_FTFIF2			DMA_INTF_FTFIF(DMA_CHANNEL2)
#define DMA_INTF_FTFIF3			DMA_INTF_FTFIF(DMA_CHANNEL3)
#define DMA_INTF_FTFIF4			DMA_INTF_FTFIF(DMA_CHANNEL4)
#define DMA_INTF_FTFIF5			DMA_INTF_FTFIF(DMA_CHANNEL5)
#define DMA_INTF_FTFIF6			DMA_INTF_FTFIF(DMA_CHANNEL6)
#define DMA_INTF_FTFIF7			DMA_INTF_FTFIF(DMA_CHANNEL7)

/* GIF: Global interrupt flag */
#define DMA_INTF_GIF_BIT		DMA_GIF
#define DMA_INTF_GIF(channel)		(DMA_INTF_GIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_INTF_GIF1			DMA_INTF_GIF(DMA_CHANNEL1)
#define DMA_INTF_GIF2			DMA_INTF_GIF(DMA_CHANNEL2)
#define DMA_INTF_GIF3			DMA_INTF_GIF(DMA_CHANNEL3)
#define DMA_INTF_GIF4			DMA_INTF_GIF(DMA_CHANNEL4)
#define DMA_INTF_GIF5			DMA_INTF_GIF(DMA_CHANNEL5)
#define DMA_INTF_GIF6			DMA_INTF_GIF(DMA_CHANNEL6)
#define DMA_INTF_GIF7			DMA_INTF_GIF(DMA_CHANNEL7)

/* --- DMA_INTC values ----------------------------------------------------- */

/* ERRIFC: Transfer error clear */
#define DMA_INTC_ERRIFC_BIT		DMA_TEIF
#define DMA_INTC_ERRIFC(channel)		(DMA_INTC_ERRIFC_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_INTC_ERRIFC1		DMA_INTC_ERRIFC(DMA_CHANNEL1)
#define DMA_INTC_ERRIFC2		DMA_INTC_ERRIFC(DMA_CHANNEL2)
#define DMA_INTC_ERRIFC3		DMA_INTC_ERRIFC(DMA_CHANNEL3)
#define DMA_INTC_ERRIFC4		DMA_INTC_ERRIFC(DMA_CHANNEL4)
#define DMA_INTC_ERRIFC5		DMA_INTC_ERRIFC(DMA_CHANNEL5)
#define DMA_INTC_ERRIFC6		DMA_INTC_ERRIFC(DMA_CHANNEL6)
#define DMA_INTC_ERRIFC7		DMA_INTC_ERRIFC(DMA_CHANNEL7)

/* HTFIFC: Half transfer clear */
#define DMA_INTC_HTFIFC_BIT		DMA_HTIF
#define DMA_INTC_HTFIFC(channel)		(DMA_INTC_HTFIFC_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_INTC_HTFIFC1		DMA_INTC_HTFIFC(DMA_CHANNEL1)
#define DMA_INTC_HTFIFC2		DMA_INTC_HTFIFC(DMA_CHANNEL2)
#define DMA_INTC_HTFIFC3		DMA_INTC_HTFIFC(DMA_CHANNEL3)
#define DMA_INTC_HTFIFC4		DMA_INTC_HTFIFC(DMA_CHANNEL4)
#define DMA_INTC_HTFIFC5		DMA_INTC_HTFIFC(DMA_CHANNEL5)
#define DMA_INTC_HTFIFC6		DMA_INTC_HTFIFC(DMA_CHANNEL6)
#define DMA_INTC_HTFIFC7		DMA_INTC_HTFIFC(DMA_CHANNEL7)

/* FTFIFC: Transfer complete clear */
#define DMA_INTC_FTFIFC_BIT		DMA_TCIF
#define DMA_INTC_FTFIFC(channel)		(DMA_INTC_FTFIFC_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_INTC_FTFIFC1		DMA_INTC_FTFIFC(DMA_CHANNEL1)
#define DMA_INTC_FTFIFC2		DMA_INTC_FTFIFC(DMA_CHANNEL2)
#define DMA_INTC_FTFIFC3		DMA_INTC_FTFIFC(DMA_CHANNEL3)
#define DMA_INTC_FTFIFC4		DMA_INTC_FTFIFC(DMA_CHANNEL4)
#define DMA_INTC_FTFIFC5		DMA_INTC_FTFIFC(DMA_CHANNEL5)
#define DMA_INTC_FTFIFC6		DMA_INTC_FTFIFC(DMA_CHANNEL6)
#define DMA_INTC_FTFIFC7		DMA_INTC_FTFIFC(DMA_CHANNEL7)

/* CGIF: Global interrupt clear */
#define DMA_INTC_CGIF_BIT		DMA_GIF
#define DMA_INTC_CGIF(channel)		(DMA_INTC_CGIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_INTC_CGIF1			DMA_INTC_CGIF(DMA_CHANNEL1)
#define DMA_INTC_CGIF2			DMA_INTC_CGIF(DMA_CHANNEL2)
#define DMA_INTC_CGIF3			DMA_INTC_CGIF(DMA_CHANNEL3)
#define DMA_INTC_CGIF4			DMA_INTC_CGIF(DMA_CHANNEL4)
#define DMA_INTC_CGIF5			DMA_INTC_CGIF(DMA_CHANNEL5)
#define DMA_INTC_CGIF6			DMA_INTC_CGIF(DMA_CHANNEL6)
#define DMA_INTC_CGIF7			DMA_INTC_CGIF(DMA_CHANNEL7)

/* Clear interrupts mask */
#define DMA_INTC_CIF_BIT		0xF
#define DMA_INTC_CIF(channel)		(DMA_INTC_CIF_BIT << \
					 (DMA_FLAG_OFFSET(channel)))

#define DMA_INTC_CIF1			DMA_INTC_CIF(DMA_CHANNEL1)
#define DMA_INTC_CIF2			DMA_INTC_CIF(DMA_CHANNEL2)
#define DMA_INTC_CIF3			DMA_INTC_CIF(DMA_CHANNEL3)
#define DMA_INTC_CIF4			DMA_INTC_CIF(DMA_CHANNEL4)
#define DMA_INTC_CIF5			DMA_INTC_CIF(DMA_CHANNEL5)
#define DMA_INTC_CIF6			DMA_INTC_CIF(DMA_CHANNEL6)
#define DMA_INTC_CIF7			DMA_INTC_CIF(DMA_CHANNEL7)

/* --- DMA_CTLx generic values --------------------------------------------- */

/* MEM2MEM: Memory to memory mode */
#define DMA_CTL_MEM2MEM			(1 << 14)

/* PRIO[13:12]: Channel priority level */
/** @defgroup dma_ch_pri DMA Channel Priority Levels
@ingroup dma_defines

@{*/
#define DMA_CTL_PRIO_LOW		(0x0 << 12)
#define DMA_CTL_PRIO_MEDIUM		(0x1 << 12)
#define DMA_CTL_PRIO_HIGH		(0x2 << 12)
#define DMA_CTL_PRIO_VERY_HIGH		(0x3 << 12)
/**@}*/
#define DMA_CTL_PRIO_MASK		(0x3 << 12)
#define DMA_CTL_PRIO_SHIFT		12

/* MWIDTH[11:10]: Memory size */
/** @defgroup dma_ch_memwidth DMA Channel Memory Word Width
@ingroup dma_defines

@{*/
#define DMA_CTL_MWIDTH_8BIT		(0x0 << 10)
#define DMA_CTL_MWIDTH_16BIT		(0x1 << 10)
#define DMA_CTL_MWIDTH_32BIT		(0x2 << 10)
/**@}*/
#define DMA_CTL_MWIDTH_MASK		(0x3 << 10)
#define DMA_CTL_MWIDTH_SHIFT		10

/* PWIDTH[9:8]: Peripheral size */
/** @defgroup dma_ch_perwidth DMA Channel Peripheral Word Width
@ingroup dma_defines

@{*/
#define DMA_CTL_PWIDTH_8BIT		(0x0 << 8)
#define DMA_CTL_PWIDTH_16BIT		(0x1 << 8)
#define DMA_CTL_PWIDTH_32BIT		(0x2 << 8)
/**@}*/
#define DMA_CTL_PWIDTH_MASK		(0x3 << 8)
#define DMA_CTL_PWIDTH_SHIFT		8

/* MNAGA: Memory increment mode */
#define DMA_CTL_MNAGA			(1 << 7)

/* PNAGA: Peripheral increment mode */
#define DMA_CTL_PNAGA			(1 << 6)

/* CMEN: Circular mode */
#define DMA_CTL_CMEN			(1 << 5)

/* DIR: Data transfer direction */
#define DMA_CTL_DIR			(1 << 4)

/* ERRIE: Transfer error interrupt enable */
#define DMA_CTL_ERRIE			(1 << 3)

/* HTFIE: Half transfer interrupt enable */
#define DMA_CTL_HTFIE			(1 << 2)

/* FTFIE: Transfer complete interrupt enable */
#define DMA_CTL_FTFIE			(1 << 1)

/* CHEN: Channel enable */
#define DMA_CTL_CHEN			(1 << 0)

/* --- DMA_CHxCNT values --------------------------------------------------- */
/* CNT[15:0]: Number of data to transfer */

/* --- DMA_CHxPADDR values ---------------------------------------------------- */
/* PADDR[31:0]: Peripheral address */

/* --- DMA_CHxMADDR values ---------------------------------------------------- */
/* MADDR[31:0]: Memory address */

/* --- Generic values ------------------------------------------------------ */
/** @defgroup dma_ch DMA Channel Number
@ingroup dma_defines

@{*/
#define DMA_CHANNEL0			0
#define DMA_CHANNEL1			1
#define DMA_CHANNEL2			2
#define DMA_CHANNEL3			3
#define DMA_CHANNEL4			4
#define DMA_CHANNEL5			5
#define DMA_CHANNEL6			6
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
#warning "dma_common_f1.h should not be included explicitly, only via dma.h"
#endif
/** @endcond */

/**@}*/

