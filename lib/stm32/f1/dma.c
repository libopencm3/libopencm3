/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
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

#include <libopencm3/stm32/f1/dma.h>

void dma_channel_reset(u32 dma, u8 channel)
{
	/* Disable channel. */
	DMA_CCR(dma, channel) &= ~DMA_CCR_EN;
	/* Reset config bits. */
	DMA_CCR(dma, channel) = 0;
	/* Reset data transfer number. */
	DMA_CNDTR(dma, channel) = 0;
	/* Reset peripheral address. */
	DMA_CPAR(dma, channel) = 0;
	/* Reset memory address. */
	DMA_CMAR(dma, channel) = 0;
	/* Reset interrupt flags. */
	DMA_IFCR(dma) |= DMA_IFCR_CIF(channel);
}

void dma_enable_mem2mem_mode(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_MEM2MEM;
	DMA_CCR(dma, channel) &= ~DMA_CCR_CIRC;
}

void dma_set_priority(u32 dma, u8 channel, u32 prio)
{
	DMA_CCR(dma, channel) &= ~(DMA_CCR_PL_MASK);
	DMA_CCR(dma, channel) |= prio;
}

void dma_set_memory_size(u32 dma, u8 channel, u32 mem_size)
{

	DMA_CCR(dma, channel) &= ~(DMA_CCR_MSIZE_MASK);
	DMA_CCR(dma, channel) |= mem_size;
}

void dma_set_peripheral_size(u32 dma, u8 channel, u32 peripheral_size)
{
	DMA_CCR(dma, channel) &= ~(DMA_CCR_PSIZE_MASK);
	DMA_CCR(dma, channel) |= peripheral_size;
}

void dma_enable_memory_increment_mode(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_MINC;
}

void dma_enable_peripheral_increment_mode(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_PINC;
}

void dma_enable_circular_mode(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_CIRC;
	DMA_CCR(dma, channel) &= ~DMA_CCR_MEM2MEM;
}

void dma_set_read_from_peripheral(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_DIR;
}

void dma_set_read_from_memory(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_DIR;
}

void dma_enable_transfer_error_interrupt(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_TEIE;
}

void dma_disable_transfer_error_interrupt(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_TEIE;
}

void dma_enable_half_transfer_interrupt(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_HTIE;
}

void dma_disable_half_transfer_interrupt(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_HTIE;
}

void dma_enable_transfer_complete_interrupt(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_TCIE;
}

void dma_disable_transfer_complete_interrupt(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_TCIE;
}

void dma_enable_channel(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) |= DMA_CCR_EN;
}

void dma_disable_channel(u32 dma, u8 channel)
{
	DMA_CCR(dma, channel) &= ~DMA_CCR_EN;
}

void dma_set_peripheral_address(u32 dma, u8 channel, u32 address)
{
	DMA_CPAR(dma, channel) = (u32) address;
}

void dma_set_memory_address(u32 dma, u8 channel, u32 address)
{
	DMA_CMAR(dma, channel) = (u32) address;
}

void dma_set_number_of_data(u32 dma, u8 channel, u16 number)
{
	DMA_CNDTR(dma, channel) = number;
}
